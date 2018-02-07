################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/light/test/test_LossFunction.cpp \
../src/light/test/test_Score.cpp 

OBJS += \
./src/light/test/test_LossFunction.o \
./src/light/test/test_Score.o 

CPP_DEPS += \
./src/light/test/test_LossFunction.d \
./src/light/test/test_Score.d 


# Each subdirectory must supply rules for building sources it contributes
src/light/test/%.o: ../src/light/test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"E:\HPC\SGD\src\eigen3" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


