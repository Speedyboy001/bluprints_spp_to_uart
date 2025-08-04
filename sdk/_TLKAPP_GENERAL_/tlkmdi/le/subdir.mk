################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tlkmdi/le/tlkmdi_le.c \
../tlkmdi/le/tlkmdi_leAcl.c \
../tlkmdi/le/tlkmdi_leFuncs.c \
../tlkmdi/le/tlkmdi_le_command.c \
../tlkmdi/le/tlkmdi_le_common.c \
../tlkmdi/le/tlkmdi_le_custom_pair.c \
../tlkmdi/le/tlkmdi_le_device_manage.c \
../tlkmdi/le/tlkmdi_le_event.c \
../tlkmdi/le/tlkmdi_le_simple_sdp.c \
../tlkmdi/le/tlkmdi_lemgrAtt.c 

OBJS += \
./tlkmdi/le/tlkmdi_le.o \
./tlkmdi/le/tlkmdi_leAcl.o \
./tlkmdi/le/tlkmdi_leFuncs.o \
./tlkmdi/le/tlkmdi_le_command.o \
./tlkmdi/le/tlkmdi_le_common.o \
./tlkmdi/le/tlkmdi_le_custom_pair.o \
./tlkmdi/le/tlkmdi_le_device_manage.o \
./tlkmdi/le/tlkmdi_le_event.o \
./tlkmdi/le/tlkmdi_le_simple_sdp.o \
./tlkmdi/le/tlkmdi_lemgrAtt.o 

C_DEPS += \
./tlkmdi/le/tlkmdi_le.d \
./tlkmdi/le/tlkmdi_leAcl.d \
./tlkmdi/le/tlkmdi_leFuncs.d \
./tlkmdi/le/tlkmdi_le_command.d \
./tlkmdi/le/tlkmdi_le_common.d \
./tlkmdi/le/tlkmdi_le_custom_pair.d \
./tlkmdi/le/tlkmdi_le_device_manage.d \
./tlkmdi/le/tlkmdi_le_event.d \
./tlkmdi/le/tlkmdi_le_simple_sdp.d \
./tlkmdi/le/tlkmdi_lemgrAtt.d 


# Each subdirectory must supply rules for building sources it contributes
tlkmdi/le/%.o: ../tlkmdi/le/%.c tlkmdi/le/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-elf-gcc -mcmodel=medium -O2 -fmessage-length=0 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wlogical-op -Warray-bounds -Wlto-type-mismatch -Wimplicit-function-declaration -Wlto-type-mismatch -Wreturn-type  -g3 -DTLKAPP_GENERAL_ENABLE=1 -DMCU_CORE_B91=1 -DMCU_CORE_B92=2 -DMCU_CORE_TYPE=MCU_CORE_B91 -DTLKHW_TYPE_C1T213A83_V5_1=1 -DTLKHW_TYPE_C1T213A20_V1_3=2 -DTLKHW_TYPE=TLKHW_TYPE_C1T213A83_V5_1 -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\core" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\tlkdrv\B91" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/sys-include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include-fixed" -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fno-jump-tables -fshort-wchar -fuse-ld=bfd -mext-dsp -fpack-struct  -fno-delete-null-pointer-checks -Wno-address-of-packed-member -Wno-attribute-alias -fno-fat-lto-objects -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


