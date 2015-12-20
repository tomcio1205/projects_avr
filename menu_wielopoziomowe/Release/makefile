################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
menu_wielopoziomowe.lss \

FLASH_IMAGE += \
menu_wielopoziomowe.hex \

EEPROM_IMAGE += \
menu_wielopoziomowe.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: menu_wielopoziomowe.elf secondary-outputs

# Tool invocations
menu_wielopoziomowe.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,menu_wielopoziomowe.map -mmcu=atmega8 -o "menu_wielopoziomowe.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

menu_wielopoziomowe.lss: menu_wielopoziomowe.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S menu_wielopoziomowe.elf  >"menu_wielopoziomowe.lss"
	@echo 'Finished building: $@'
	@echo ' '

menu_wielopoziomowe.hex: menu_wielopoziomowe.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex menu_wielopoziomowe.elf  "menu_wielopoziomowe.hex"
	@echo 'Finished building: $@'
	@echo ' '

menu_wielopoziomowe.eep: menu_wielopoziomowe.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex menu_wielopoziomowe.elf  "menu_wielopoziomowe.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: menu_wielopoziomowe.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 menu_wielopoziomowe.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) menu_wielopoziomowe.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
