################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD/src/HAL_KEYPAD.c 

OBJS += \
./HAL/KEYPAD/src/HAL_KEYPAD.o 

C_DEPS += \
./HAL/KEYPAD/src/HAL_KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD/src/%.o: ../HAL/KEYPAD/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


