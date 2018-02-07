################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/light/Algorithms.cpp \
../src/light/Constant.cpp \
../src/light/Gradient.cpp \
../src/light/LearningAlgorithm.cpp \
../src/light/LossFunction.cpp \
../src/light/Score.cpp \
../src/light/importData.cpp 

OBJS += \
./src/light/Algorithms.o \
./src/light/Constant.o \
./src/light/Gradient.o \
./src/light/LearningAlgorithm.o \
./src/light/LossFunction.o \
./src/light/Score.o \
./src/light/importData.o 

CPP_DEPS += \
./src/light/Algorithms.d \
./src/light/Constant.d \
./src/light/Gradient.d \
./src/light/LearningAlgorithm.d \
./src/light/LossFunction.d \
./src/light/Score.d \
./src/light/importData.d 


# Each subdirectory must supply rules for building sources it contributes
src/light/%.o: ../src/light/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"E:\HPC\SGD\src\eigen3" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


