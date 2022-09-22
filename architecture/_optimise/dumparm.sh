#!/bin/bash
arm-none-eabi-gcc "main.c" -mcpu=cortex-m4 -std=gnu11 -c $1 $2 -w -ffunction-sections -fdata-sections --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "main.o"
arm-none-eabi-objdump -w -S -d --insn-width=4 --inlines "main.o" > arm_dumped.s

rm main.o