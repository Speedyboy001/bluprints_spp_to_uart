################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tlkmmi/debug/tlkmmi_dbg.c \
../tlkmmi/debug/tlkmmi_dbgAdapt.c \
../tlkmmi/debug/tlkmmi_dbgMsgInner.c \
../tlkmmi/debug/tlkmmi_dbgMsgOuter.c \
../tlkmmi/debug/tlkmmi_dbgShell.c \
../tlkmmi/debug/tlkmmi_dbgSync.c 

OBJS += \
./tlkmmi/debug/tlkmmi_dbg.o \
./tlkmmi/debug/tlkmmi_dbgAdapt.o \
./tlkmmi/debug/tlkmmi_dbgMsgInner.o \
./tlkmmi/debug/tlkmmi_dbgMsgOuter.o \
./tlkmmi/debug/tlkmmi_dbgShell.o \
./tlkmmi/debug/tlkmmi_dbgSync.o 

C_DEPS += \
./tlkmmi/debug/tlkmmi_dbg.d \
./tlkmmi/debug/tlkmmi_dbgAdapt.d \
./tlkmmi/debug/tlkmmi_dbgMsgInner.d \
./tlkmmi/debug/tlkmmi_dbgMsgOuter.d \
./tlkmmi/debug/tlkmmi_dbgShell.d \
./tlkmmi/debug/tlkmmi_dbgSync.d 


# Each subdirectory must supply rules for building sources it contributes
tlkmmi/debug/%.o: ../tlkmmi/debug/%.c tlkmmi/debug/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-elf-gcc -mcmodel=medium -O2 -fmessage-length=0 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wlogical-op -Warray-bounds -Wlto-type-mismatch -Wimplicit-function-declaration -Wlto-type-mismatch -Wreturn-type  -g3 -DTLKAPP_GENERAL_ENABLE=1 -DMCU_CORE_B91=1 -DMCU_CORE_B92=2 -DMCU_CORE_TYPE=MCU_CORE_B91 -DTLKHW_TYPE_C1T213A83_V5_1=1 -DTLKHW_TYPE_C1T213A20_V1_3=2 -DTLKHW_TYPE=TLKHW_TYPE_C1T213A83_V5_1 -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\core" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\tlkdrv\B91" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/sys-include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include-fixed" -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fno-jump-tables -fshort-wchar -fuse-ld=bfd -mext-dsp -fpack-struct  -fno-delete-null-pointer-checks -Wno-address-of-packed-member -Wno-attribute-alias -fno-fat-lto-objects -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


