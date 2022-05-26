################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Box_v0.02.cpp \
../src/Object.cpp \
../src/StaticObjects.cpp \
../src/Texture.cpp \
../src/Timer.cpp 

OBJS += \
./src/Box_v0.02.o \
./src/Object.o \
./src/StaticObjects.o \
./src/Texture.o \
./src/Timer.o 

CPP_DEPS += \
./src/Box_v0.02.d \
./src/Object.d \
./src/StaticObjects.d \
./src/Texture.d \
./src/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\mingw\mingw64\include\SDL2" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


