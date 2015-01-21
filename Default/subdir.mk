################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test_file.cpp \
../test_main.cpp 

OBJS += \
./test_file.o \
./test_main.o 

CPP_DEPS += \
./test_file.d \
./test_main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/torp/dev/lib/gtest-1.7.0/include -I"/home/torp/dev/smallGame/src" -I"/home/torp/dev/smallGame/include" -O2 -g -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


