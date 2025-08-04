################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tlkmdi/bt/tlkmdi_bt.c \
../tlkmdi/bt/tlkmdi_btFuncs.c \
../tlkmdi/bt/tlkmdi_bta2dp.c \
../tlkmdi/bt/tlkmdi_btacl.c \
../tlkmdi/bt/tlkmdi_btadapt.c \
../tlkmdi/bt/tlkmdi_btatt.c \
../tlkmdi/bt/tlkmdi_bthfp.c \
../tlkmdi/bt/tlkmdi_bthfpag.c \
../tlkmdi/bt/tlkmdi_bthfphf.c \
../tlkmdi/bt/tlkmdi_bthid.c \
../tlkmdi/bt/tlkmdi_btiap.c \
../tlkmdi/bt/tlkmdi_btinq.c \
../tlkmdi/bt/tlkmdi_btrec.c \
../tlkmdi/bt/tlkmdi_btsco.c 

OBJS += \
./tlkmdi/bt/tlkmdi_bt.o \
./tlkmdi/bt/tlkmdi_btFuncs.o \
./tlkmdi/bt/tlkmdi_bta2dp.o \
./tlkmdi/bt/tlkmdi_btacl.o \
./tlkmdi/bt/tlkmdi_btadapt.o \
./tlkmdi/bt/tlkmdi_btatt.o \
./tlkmdi/bt/tlkmdi_bthfp.o \
./tlkmdi/bt/tlkmdi_bthfpag.o \
./tlkmdi/bt/tlkmdi_bthfphf.o \
./tlkmdi/bt/tlkmdi_bthid.o \
./tlkmdi/bt/tlkmdi_btiap.o \
./tlkmdi/bt/tlkmdi_btinq.o \
./tlkmdi/bt/tlkmdi_btrec.o \
./tlkmdi/bt/tlkmdi_btsco.o 

C_DEPS += \
./tlkmdi/bt/tlkmdi_bt.d \
./tlkmdi/bt/tlkmdi_btFuncs.d \
./tlkmdi/bt/tlkmdi_bta2dp.d \
./tlkmdi/bt/tlkmdi_btacl.d \
./tlkmdi/bt/tlkmdi_btadapt.d \
./tlkmdi/bt/tlkmdi_btatt.d \
./tlkmdi/bt/tlkmdi_bthfp.d \
./tlkmdi/bt/tlkmdi_bthfpag.d \
./tlkmdi/bt/tlkmdi_bthfphf.d \
./tlkmdi/bt/tlkmdi_bthid.d \
./tlkmdi/bt/tlkmdi_btiap.d \
./tlkmdi/bt/tlkmdi_btinq.d \
./tlkmdi/bt/tlkmdi_btrec.d \
./tlkmdi/bt/tlkmdi_btsco.d 


# Each subdirectory must supply rules for building sources it contributes
tlkmdi/bt/%.o: ../tlkmdi/bt/%.c tlkmdi/bt/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-elf-gcc -mcmodel=medium -O2 -fmessage-length=0 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wlogical-op -Warray-bounds -Wlto-type-mismatch -Wimplicit-function-declaration -Wlto-type-mismatch -Wreturn-type  -g3 -DTLKAPP_GENERAL_ENABLE=1 -DMCU_CORE_B91=1 -DMCU_CORE_B92=2 -DMCU_CORE_TYPE=MCU_CORE_B91 -DTLKHW_TYPE_C1T213A83_V5_1=1 -DTLKHW_TYPE_C1T213A20_V1_3=2 -DTLKHW_TYPE=TLKHW_TYPE_C1T213A83_V5_1 -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\core" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\tlkdrv\B91" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/sys-include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include-fixed" -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fno-jump-tables -fshort-wchar -fuse-ld=bfd -mext-dsp -fpack-struct  -fno-delete-null-pointer-checks -Wno-address-of-packed-member -Wno-attribute-alias -fno-fat-lto-objects -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


