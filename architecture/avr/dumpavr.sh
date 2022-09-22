#!/bin/bash

avr-gcc --version > avr.dump
sed -i '1!d' avr.dump

OPTIONS="-mmcu=avr4 -g3 -O0 -c"
echo "Using: $PARAMETERS" >> avr.dump 

avr-gcc $PARAMETERS -w main.c -o main.o
avr-objdump -w -S -d --insn-width=4 main.o >> avr.dump

rm main.o