################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include tlksys/subdir.mk
-include tlkstk/bt/lep/subdir.mk
-include tlkstk/bt/leh/subdir.mk
-include tlkstk/bt/btp/sdp/subdir.mk
-include tlkstk/bt/btp/pts/subdir.mk
-include tlkstk/bt/btp/subdir.mk
-include tlkstk/bt/bth/subdir.mk
-include tlkstk/ble/subdir.mk
-include tlkstk/subdir.mk
-include tlkmmi/view/subdir.mk
-include tlkmmi/test/usr/subdir.mk
-include tlkmmi/test/rdt/t005/subdir.mk
-include tlkmmi/test/rdt/t003/subdir.mk
-include tlkmmi/test/rdt/t002/subdir.mk
-include tlkmmi/test/rdt/t001/subdir.mk
-include tlkmmi/test/rdt/le/subdir.mk
-include tlkmmi/test/rdt/bt/subdir.mk
-include tlkmmi/test/rdt/subdir.mk
-include tlkmmi/test/pts/subdir.mk
-include tlkmmi/test/fat/subdir.mk
-include tlkmmi/test/emi/subdir.mk
-include tlkmmi/test/bqb/subdir.mk
-include tlkmmi/test/ats/subdir.mk
-include tlkmmi/test/subdir.mk
-include tlkmmi/system/subdir.mk
-include tlkmmi/stack/subdir.mk
-include tlkmmi/sensor/subdir.mk
-include tlkmmi/phone/subdir.mk
-include tlkmmi/lemgr/subdir.mk
-include tlkmmi/file/subdir.mk
-include tlkmmi/device/subdir.mk
-include tlkmmi/debug/subdir.mk
-include tlkmmi/btmgr/subdir.mk
-include tlkmmi/audio/subdir.mk
-include tlkmdi/misc/subdir.mk
-include tlkmdi/le/subdir.mk
-include tlkmdi/gui/subdir.mk
-include tlkmdi/bt/subdir.mk
-include tlkmdi/aud/subdir.mk
-include tlklib/usb/usr/subdir.mk
-include tlklib/usb/udb/subdir.mk
-include tlklib/usb/uac/subdir.mk
-include tlklib/usb/msc/subdir.mk
-include tlklib/usb/hid/subdir.mk
-include tlklib/usb/cdc/subdir.mk
-include tlklib/usb/subdir.mk
-include tlklib/os/freertos/portable/MemMang/subdir.mk
-include tlklib/os/freertos/portable/GCC/RISC-V/subdir.mk
-include tlklib/os/freertos/subdir.mk
-include tlklib/os/subdir.mk
-include tlklib/mem/subdir.mk
-include tlklib/ios/ios_srvComm/subdir.mk
-include tlklib/ios/ancs/subdir.mk
-include tlklib/ios/ams/subdir.mk
-include tlklib/gui/subdir.mk
-include tlklib/fs/fatfs/subdir.mk
-include tlklib/fs/subdir.mk
-include tlklib/dbg/subdir.mk
-include tlklib/cpc/cpc3/subdir.mk
-include tlklib/cpc/cpc2/subdir.mk
-include tlklib/cpc/cpc1/subdir.mk
-include tlklib/cpc/subdir.mk
-include tlkdrv/usr/subdir.mk
-include tlkdrv/ext/touch/subdir.mk
-include tlkdrv/ext/store/subdir.mk
-include tlkdrv/ext/sram/subdir.mk
-include tlkdrv/ext/serial/subdir.mk
-include tlkdrv/ext/led/subdir.mk
-include tlkdrv/ext/lcd/st77903_data/subdir.mk
-include tlkdrv/ext/lcd/subdir.mk
-include tlkdrv/ext/keyboard/subdir.mk
-include tlkdrv/ext/key/subdir.mk
-include tlkdrv/ext/codec/subdir.mk
-include tlkdrv/ext/charge/subdir.mk
-include tlkdrv/ext/battery/subdir.mk
-include tlkdrv/B91/ext_driver/setting/subdir.mk
-include tlkdrv/B91/ext_driver/calibration/subdir.mk
-include tlkdrv/B91/ext_driver/PA/subdir.mk
-include tlkdrv/B91/ext_driver/EMI/subdir.mk
-include tlkdrv/B91/ext_driver/BT/subdir.mk
-include tlkdrv/B91/ext_driver/BQB/subdir.mk
-include tlkdrv/B91/ext_driver/subdir.mk
-include tlkdrv/B91/subdir.mk
-include tlkdev/usr/subdir.mk
-include tlkdev/sys/subdir.mk
-include tlkdev/ext/subdir.mk
-include tlkdev/subdir.mk
-include tlkapi/subdir.mk
-include tlkalg/audio/resample/subdir.mk
-include tlkalg/audio/eq/subdir.mk
-include tlkalg/audio/ec/subdir.mk
-include core/B91/subdir.mk
-include core/subdir.mk
-include app/tlkapp_general/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := _TLKAPP_GENERAL_
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
_TLKAPP_GENERAL_.bin \

SECONDARY_LIST += \
_TLKAPP_GENERAL_.lst \

SECONDARY_SIZE += \
_TLKAPP_GENERAL_.siz \


# All Target
all: main-build

# Main-build Target
main-build: _TLKAPP_GENERAL_.elf secondary-outputs

# Tool invocations
_TLKAPP_GENERAL_.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU RISC-V Cross C Linker'
	riscv32-elf-gcc -mcmodel=medium -O2 -fmessage-length=0 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wlogical-op -Warray-bounds -Wlto-type-mismatch -Wimplicit-function-declaration -Wlto-type-mismatch -Wreturn-type  -g3 -T "E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\core\B91\B91_S00000.link" -nostartfiles -Xlinker --gc-sections -L"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\tlklib\lib" -Wl,-Map,"_TLKAPP_GENERAL_.map" -mcmodel=medium -g3 -mcpu=d25f -ffunction-sections -fdata-sections -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fno-jump-tables -fshort-wchar -fuse-ld=bfd -mext-dsp -fpack-struct -fno-delete-null-pointer-checks  -O2 -o "_TLKAPP_GENERAL_.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

_TLKAPP_GENERAL_.bin: _TLKAPP_GENERAL_.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv32-elf-objcopy -O binary "_TLKAPP_GENERAL_.elf"  "_TLKAPP_GENERAL_.bin"
	@echo 'Finished building: $@'
	@echo ' '

_TLKAPP_GENERAL_.lst: _TLKAPP_GENERAL_.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Listing'
	riscv32-elf-objdump --source --demangle --syms "_TLKAPP_GENERAL_.elf" > "_TLKAPP_GENERAL_.lst"
	@echo 'Finished building: $@'
	@echo ' '

_TLKAPP_GENERAL_.siz: _TLKAPP_GENERAL_.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv32-elf-size "_TLKAPP_GENERAL_.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) _TLKAPP_GENERAL_.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
