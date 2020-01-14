################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/interupts/src/subdir.mk
-include MCAL/WDG/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/DIO/src/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/seven/src/subdir.mk
-include HAL/LED/src/subdir.mk
-include HAL/LCD/src/subdir.mk
-include HAL/KEYPAD/src/subdir.mk
-include HAL/BUTTON/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Drivers_AVR_Atmega32.lss \

FLASH_IMAGE += \
Drivers_AVR_Atmega32.hex \

EEPROM_IMAGE += \
Drivers_AVR_Atmega32.eep \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Drivers_AVR_Atmega32.elf secondary-outputs

# Tool invocations
Drivers_AVR_Atmega32.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Drivers_AVR_Atmega32.map -mmcu=atmega32 -o "Drivers_AVR_Atmega32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Drivers_AVR_Atmega32.lss: Drivers_AVR_Atmega32.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Drivers_AVR_Atmega32.elf  >"Drivers_AVR_Atmega32.lss"
	@echo 'Finished building: $@'
	@echo ' '

Drivers_AVR_Atmega32.hex: Drivers_AVR_Atmega32.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Drivers_AVR_Atmega32.elf  "Drivers_AVR_Atmega32.hex"
	@echo 'Finished building: $@'
	@echo ' '

Drivers_AVR_Atmega32.eep: Drivers_AVR_Atmega32.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Drivers_AVR_Atmega32.elf  "Drivers_AVR_Atmega32.eep"
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Drivers_AVR_Atmega32.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Drivers_AVR_Atmega32.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Drivers_AVR_Atmega32.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
