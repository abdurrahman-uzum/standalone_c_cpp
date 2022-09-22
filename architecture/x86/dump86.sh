#!/bin/bash

gcc --version > x86.dump
sed -i '1!d' x86.dump

PARAMETERS="-std=gnu99 -m32 -g3 -O0 -c"
echo "Using: $PARAMETERS" >> x86.dump

gcc $PARAMETERS -w ../main.c -o main32.o

objdump -M intel -d -S --insn-width=8 main32.o >> x86.dump

rm main32.o