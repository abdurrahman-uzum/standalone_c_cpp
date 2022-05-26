################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cat.cpp \
../src/ClassesAndStuff.cpp \
../src/Person.cpp 

OBJS += \
./src/Cat.o \
./src/ClassesAndStuff.o \
./src/Person.o 

CPP_DEPS += \
./src/Cat.d \
./src/ClassesAndStuff.d \
./src/Person.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


