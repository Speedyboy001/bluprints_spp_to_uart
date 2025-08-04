################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tlkdev/sys/tlkdev_battery.c \
../tlkdev/sys/tlkdev_charge.c \
../tlkdev/sys/tlkdev_codec.c \
../tlkdev/sys/tlkdev_gsensor.c \
../tlkdev/sys/tlkdev_heartrate.c \
../tlkdev/sys/tlkdev_key.c \
../tlkdev/sys/tlkdev_keyboard.c \
../tlkdev/sys/tlkdev_lcd.c \
../tlkdev/sys/tlkdev_led.c \
../tlkdev/sys/tlkdev_serial.c \
../tlkdev/sys/tlkdev_sram.c \
../tlkdev/sys/tlkdev_store.c \
../tlkdev/sys/tlkdev_touch.c \
../tlkdev/sys/tlkdev_usb.c 

OBJS += \
./tlkdev/sys/tlkdev_battery.o \
./tlkdev/sys/tlkdev_charge.o \
./tlkdev/sys/tlkdev_codec.o \
./tlkdev/sys/tlkdev_gsensor.o \
./tlkdev/sys/tlkdev_heartrate.o \
./tlkdev/sys/tlkdev_key.o \
./tlkdev/sys/tlkdev_keyboard.o \
./tlkdev/sys/tlkdev_lcd.o \
./tlkdev/sys/tlkdev_led.o \
./tlkdev/sys/tlkdev_serial.o \
./tlkdev/sys/tlkdev_sram.o \
./tlkdev/sys/tlkdev_store.o \
./tlkdev/sys/tlkdev_touch.o \
./tlkdev/sys/tlkdev_usb.o 

C_DEPS += \
./tlkdev/sys/tlkdev_battery.d \
./tlkdev/sys/tlkdev_charge.d \
./tlkdev/sys/tlkdev_codec.d \
./tlkdev/sys/tlkdev_gsensor.d \
./tlkdev/sys/tlkdev_heartrate.d \
./tlkdev/sys/tlkdev_key.d \
./tlkdev/sys/tlkdev_keyboard.d \
./tlkdev/sys/tlkdev_lcd.d \
./tlkdev/sys/tlkdev_led.d \
./tlkdev/sys/tlkdev_serial.d \
./tlkdev/sys/tlkdev_sram.d \
./tlkdev/sys/tlkdev_store.d \
./tlkdev/sys/tlkdev_touch.d \
./tlkdev/sys/tlkdev_usb.d 


# Each subdirectory must supply rules for building sources it contributes
tlkdev/sys/%.o: ../tlkdev/sys/%.c tlkdev/sys/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-elf-gcc -mcmodel=medium -O2 -fmessage-length=0 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wlogical-op -Warray-bounds -Wlto-type-mismatch -Wimplicit-function-declaration -Wlto-type-mismatch -Wreturn-type  -g3 -DTLKAPP_GENERAL_ENABLE=1 -DMCU_CORE_B91=1 -DMCU_CORE_B92=2 -DMCU_CORE_TYPE=MCU_CORE_B91 -DTLKHW_TYPE_C1T213A83_V5_1=1 -DTLKHW_TYPE_C1T213A20_V1_3=2 -DTLKHW_TYPE=TLKHW_TYPE_C1T213A83_V5_1 -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\core" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\tlkdrv\B91" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/sys-include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include-fixed" -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fno-jump-tables -fshort-wchar -fuse-ld=bfd -mext-dsp -fpack-struct  -fno-delete-null-pointer-checks -Wno-address-of-packed-member -Wno-attribute-alias -fno-fat-lto-objects -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


