################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_main.c \
../LED_main.c \
../Seven_main.c \
../interrupts_main.c \
../maintest.c \
../timer2_main.c \
../timer_main.c 

OBJS += \
./LCD_main.o \
./LED_main.o \
./Seven_main.o \
./interrupts_main.o \
./maintest.o \
./timer2_main.o \
./timer_main.o 

C_DEPS += \
./LCD_main.d \
./LED_main.d \
./Seven_main.d \
./interrupts_main.d \
./maintest.d \
./timer2_main.d \
./timer_main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


