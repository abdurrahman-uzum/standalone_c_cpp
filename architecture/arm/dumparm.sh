#!/bin/bash

arm-none-eabi-gcc --version > arm.dump
sed -i '1!d' arm.dump

PARAMETERS="-std=gnu99 -g3 -O0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -ffunction-sections -fdata-sections --specs=nano.specs -c"
echo "Using: $PARAMETERS" >> arm.dump

arm-none-eabi-gcc $PARAMETERS -w ../main.c -o main.o
arm-none-eabi-objdump -w -S -d main.o >> arm.dump

rm main.o