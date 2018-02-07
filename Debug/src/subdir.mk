################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/commonFunctions.cc \
../src/importData.cc \
../src/logisticRegression.cc \
../src/main.cc 

CC_DEPS += \
./src/commonFunctions.d \
./src/importData.d \
./src/logisticRegression.d \
./src/main.d 

OBJS += \
./src/commonFunctions.o \
./src/importData.o \
./src/logisticRegression.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"E:\HPC\SGD\src\eigen3" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


