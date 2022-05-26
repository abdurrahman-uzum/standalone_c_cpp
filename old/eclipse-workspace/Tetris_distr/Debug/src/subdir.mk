################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game.cpp \
../src/main.cpp \
../src/tetromino.cpp \
../src/texture.cpp 

OBJS += \
./src/game.o \
./src/main.o \
./src/tetromino.o \
./src/texture.o 

CPP_DEPS += \
./src/game.d \
./src/main.d \
./src/tetromino.d \
./src/texture.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\Abdurrahman\eclipse-workspace\Tetris_distr\SDL2\include\SDL2" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


