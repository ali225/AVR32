################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
<<<<<<< HEAD
../main_Seven.c \
=======
>>>>>>> fc282a59d59a9fd5ae5bce7849b08bea8739b961
../maintest.c \
../maintestled.c 

OBJS += \
<<<<<<< HEAD
./main_Seven.o \
=======
>>>>>>> fc282a59d59a9fd5ae5bce7849b08bea8739b961
./maintest.o \
./maintestled.o 

C_DEPS += \
<<<<<<< HEAD
./main_Seven.d \
=======
>>>>>>> fc282a59d59a9fd5ae5bce7849b08bea8739b961
./maintest.d \
./maintestled.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


