################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tlklib/usb/cdc/tlkusb_cdc.c \
../tlklib/usb/cdc/tlkusb_cdcCtrl.c \
../tlklib/usb/cdc/tlkusb_cdcDesc.c 

OBJS += \
./tlklib/usb/cdc/tlkusb_cdc.o \
./tlklib/usb/cdc/tlkusb_cdcCtrl.o \
./tlklib/usb/cdc/tlkusb_cdcDesc.o 

C_DEPS += \
./tlklib/usb/cdc/tlkusb_cdc.d \
./tlklib/usb/cdc/tlkusb_cdcCtrl.d \
./tlklib/usb/cdc/tlkusb_cdcDesc.d 


# Each subdirectory must supply rules for building sources it contributes
tlklib/usb/cdc/%.o: ../tlklib/usb/cdc/%.c tlklib/usb/cdc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-elf-gcc -mcmodel=medium -O2 -fmessage-length=0 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wlogical-op -Warray-bounds -Wlto-type-mismatch -Wimplicit-function-declaration -Wlto-type-mismatch -Wreturn-type  -g3 -DTLKAPP_GENERAL_ENABLE=1 -DMCU_CORE_B91=1 -DMCU_CORE_B92=2 -DMCU_CORE_TYPE=MCU_CORE_B91 -DTLKHW_TYPE_C1T213A83_V5_1=1 -DTLKHW_TYPE_C1T213A20_V1_3=2 -DTLKHW_TYPE=TLKHW_TYPE_C1T213A83_V5_1 -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\core" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\tlkdrv\B91" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/sys-include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include-fixed" -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fno-jump-tables -fshort-wchar -fuse-ld=bfd -mext-dsp -fpack-struct  -fno-delete-null-pointer-checks -Wno-address-of-packed-member -Wno-attribute-alias -fno-fat-lto-objects -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


