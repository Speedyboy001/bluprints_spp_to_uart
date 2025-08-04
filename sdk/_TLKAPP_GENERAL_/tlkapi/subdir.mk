################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tlkapi/tlkapi_char.c \
../tlkapi/tlkapi_chip.c \
../tlkapi/tlkapi_debug.c \
../tlkapi/tlkapi_file.c \
../tlkapi/tlkapi_flash.c \
../tlkapi/tlkapi_list.c \
../tlkapi/tlkapi_os.c \
../tlkapi/tlkapi_stdio.c \
../tlkapi/tlkapi_string.c \
../tlkapi/tlkapi_timer.c \
../tlkapi/tlkapi_tree.c 

OBJS += \
./tlkapi/tlkapi_char.o \
./tlkapi/tlkapi_chip.o \
./tlkapi/tlkapi_debug.o \
./tlkapi/tlkapi_file.o \
./tlkapi/tlkapi_flash.o \
./tlkapi/tlkapi_list.o \
./tlkapi/tlkapi_os.o \
./tlkapi/tlkapi_stdio.o \
./tlkapi/tlkapi_string.o \
./tlkapi/tlkapi_timer.o \
./tlkapi/tlkapi_tree.o 

C_DEPS += \
./tlkapi/tlkapi_char.d \
./tlkapi/tlkapi_chip.d \
./tlkapi/tlkapi_debug.d \
./tlkapi/tlkapi_file.d \
./tlkapi/tlkapi_flash.d \
./tlkapi/tlkapi_list.d \
./tlkapi/tlkapi_os.d \
./tlkapi/tlkapi_stdio.d \
./tlkapi/tlkapi_string.d \
./tlkapi/tlkapi_timer.d \
./tlkapi/tlkapi_tree.d 


# Each subdirectory must supply rules for building sources it contributes
tlkapi/%.o: ../tlkapi/%.c tlkapi/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-elf-gcc -mcmodel=medium -O2 -fmessage-length=0 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wlogical-op -Warray-bounds -Wlto-type-mismatch -Wimplicit-function-declaration -Wlto-type-mismatch -Wreturn-type  -g3 -DTLKAPP_GENERAL_ENABLE=1 -DMCU_CORE_B91=1 -DMCU_CORE_B92=2 -DMCU_CORE_TYPE=MCU_CORE_B91 -DTLKHW_TYPE_C1T213A83_V5_1=1 -DTLKHW_TYPE_C1T213A20_V1_3=2 -DTLKHW_TYPE=TLKHW_TYPE_C1T213A83_V5_1 -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\core" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\tlkdrv\B91" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/sys-include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include-fixed" -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fno-jump-tables -fshort-wchar -fuse-ld=bfd -mext-dsp -fpack-struct  -fno-delete-null-pointer-checks -Wno-address-of-packed-member -Wno-attribute-alias -fno-fat-lto-objects -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


