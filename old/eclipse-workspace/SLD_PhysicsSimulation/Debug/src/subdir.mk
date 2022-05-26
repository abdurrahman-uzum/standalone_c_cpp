################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Objects.cpp \
../src/Physics.cpp \
../src/Screen.cpp \
../src/main.cpp 

OBJS += \
./src/Objects.o \
./src/Physics.o \
./src/Screen.o \
./src/main.o 

CPP_DEPS += \
./src/Objects.d \
./src/Physics.d \
./src/Screen.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\mingw\mingw64\include\SDL2" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


