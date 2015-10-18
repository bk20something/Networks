################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ArgHandler.cpp \
../src/Client.cpp \
../src/MesseageMaker.cpp \
../src/client_tcp.cpp 

OBJS += \
./src/ArgHandler.o \
./src/Client.o \
./src/MesseageMaker.o \
./src/client_tcp.o 

CPP_DEPS += \
./src/ArgHandler.d \
./src/Client.d \
./src/MesseageMaker.d \
./src/client_tcp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


