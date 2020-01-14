################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/WDG/WDG.c \
../MCAL/WDG/WDG_cfg.c 

OBJS += \
./MCAL/WDG/WDG.o \
./MCAL/WDG/WDG_cfg.o 

C_DEPS += \
./MCAL/WDG/WDG.d \
./MCAL/WDG/WDG_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/WDG/%.o: ../MCAL/WDG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


