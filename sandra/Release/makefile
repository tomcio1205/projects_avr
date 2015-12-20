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
sandra.lss \

FLASH_IMAGE += \
sandra.hex \

EEPROM_IMAGE += \
sandra.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: sandra.elf secondary-outputs

# Tool invocations
sandra.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,sandra.map -L/home/tomek/Pobrane/hd44780_4bit_norw -mmcu=atmega8 -o "sandra.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

sandra.lss: sandra.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S sandra.elf  >"sandra.lss"
	@echo 'Finished building: $@'
	@echo ' '

sandra.hex: sandra.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex sandra.elf  "sandra.hex"
	@echo 'Finished building: $@'
	@echo ' '

sandra.eep: sandra.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex sandra.elf  "sandra.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: sandra.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 sandra.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) sandra.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
