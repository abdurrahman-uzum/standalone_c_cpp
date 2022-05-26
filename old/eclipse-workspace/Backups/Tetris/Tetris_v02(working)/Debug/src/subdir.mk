################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Tetris_main.cpp \
../src/Tetromino.cpp \
../src/Timer.cpp 

OBJS += \
./src/Tetris_main.o \
./src/Tetromino.o \
./src/Timer.o 

CPP_DEPS += \
./src/Tetris_main.d \
./src/Tetromino.d \
./src/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\mingw\mingw64\include\SDL2" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


