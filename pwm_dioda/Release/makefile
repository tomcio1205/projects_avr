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
pwm_dioda.lss \

FLASH_IMAGE += \
pwm_dioda.hex \

EEPROM_IMAGE += \
pwm_dioda.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: pwm_dioda.elf secondary-outputs

# Tool invocations
pwm_dioda.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,pwm_dioda.map -mmcu=atmega8 -o "pwm_dioda.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

pwm_dioda.lss: pwm_dioda.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S pwm_dioda.elf  >"pwm_dioda.lss"
	@echo 'Finished building: $@'
	@echo ' '

pwm_dioda.hex: pwm_dioda.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex pwm_dioda.elf  "pwm_dioda.hex"
	@echo 'Finished building: $@'
	@echo ' '

pwm_dioda.eep: pwm_dioda.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex pwm_dioda.elf  "pwm_dioda.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: pwm_dioda.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 pwm_dioda.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) pwm_dioda.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
