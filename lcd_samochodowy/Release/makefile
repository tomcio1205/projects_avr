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
lcd_samochodowy.lss \

FLASH_IMAGE += \
lcd_samochodowy.hex \

EEPROM_IMAGE += \
lcd_samochodowy.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: lcd_samochodowy.elf secondary-outputs

# Tool invocations
lcd_samochodowy.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lcd_samochodowy.map -mmcu=atmega8 -o "lcd_samochodowy.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lcd_samochodowy.lss: lcd_samochodowy.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lcd_samochodowy.elf  >"lcd_samochodowy.lss"
	@echo 'Finished building: $@'
	@echo ' '

lcd_samochodowy.hex: lcd_samochodowy.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex lcd_samochodowy.elf  "lcd_samochodowy.hex"
	@echo 'Finished building: $@'
	@echo ' '

lcd_samochodowy.eep: lcd_samochodowy.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex lcd_samochodowy.elf  "lcd_samochodowy.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lcd_samochodowy.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 lcd_samochodowy.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) lcd_samochodowy.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
