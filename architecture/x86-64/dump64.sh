#!/bin/bash

gcc --version > x86-64.dump
sed -i '1!d' x86-64.dump

PARAMETERS="-std=gnu99 -g3 -O0 -c"
echo "Using: $PARAMETERS" >> x86-64.dump

# Compile (do not link)
gcc $PARAMETERS -w ../main.c -o main64.o

# Disassamble 
objdump -M intel -d -S --insn-width=8  main64.o >> x86-64.dump

rm main64.o