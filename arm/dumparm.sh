#!/bin/bash

# Call the script with -g<A> -O<B> options
# where A can be 1, 2, 3, gdb
# and B can be 0, 1, 2, 3, g, s
# e.g. ./dumparm.sh -g3 -O0

# This is to test assembly output of individual functions
# under various optimisation/debug levels quickly.
# GCC call does not link the object file with anything,
# therefore if a link is necessary, the supposedly linked 
# function implementations will not be visible. (like math.h functions).

# If you wish to link, remove the -c option from compiler
# options, and add the link options **at the end** of the 
# parameters.

# Print compiler information into the dump file
arm-none-eabi-gcc --version > arm.dump
sed -i '1!d' arm.dump

# Print compiler options into the dump file
PARAMETERS="-std=gnu99 $1 $2 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -ffunction-sections -fdata-sections --specs=nano.specs -c"
echo "Using: $PARAMETERS" >> arm.dump

# Explicitly print optimisation/debug levels into the dump file
echo "\nWith optimisations: $1 $2" >> arm.dump

# Compile with above parameters, do not link (-c option).
arm-none-eabi-gcc $PARAMETERS main.c -o main.o

# Disassamble previously assembled object file.
arm-none-eabi-objdump -w -S -d main.o >> arm.dump

# It is possible to get GCC to produce assembly output
# but it looks uglier.

# Delete the object file. Not necessary.
rm main.o