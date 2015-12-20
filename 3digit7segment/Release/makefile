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
3digit7segment.lss \

FLASH_IMAGE += \
3digit7segment.hex \

EEPROM_IMAGE += \
3digit7segment.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 3digit7segment.elf secondary-outputs

# Tool invocations
3digit7segment.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,3digit7segment.map -mmcu=atmega8 -o "3digit7segment.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

3digit7segment.lss: 3digit7segment.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 3digit7segment.elf  >"3digit7segment.lss"
	@echo 'Finished building: $@'
	@echo ' '

3digit7segment.hex: 3digit7segment.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 3digit7segment.elf  "3digit7segment.hex"
	@echo 'Finished building: $@'
	@echo ' '

3digit7segment.eep: 3digit7segment.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 3digit7segment.elf  "3digit7segment.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 3digit7segment.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 3digit7segment.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) 3digit7segment.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
