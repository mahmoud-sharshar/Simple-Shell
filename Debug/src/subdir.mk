################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/simple\ shell.cpp 

OBJS += \
./src/simple\ shell.o 

CPP_DEPS += \
./src/simple\ shell.d 


# Each subdirectory must supply rules for building sources it contributes
src/simple\ shell.o: ../src/simple\ shell.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/simple shell.d" -MT"src/simple\ shell.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


