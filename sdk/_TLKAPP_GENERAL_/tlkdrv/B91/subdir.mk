################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tlkdrv/B91/analog.c \
../tlkdrv/B91/audio.c \
../tlkdrv/B91/charger.c \
../tlkdrv/B91/clock.c \
../tlkdrv/B91/core.c \
../tlkdrv/B91/flash.c \
../tlkdrv/B91/gpio.c \
../tlkdrv/B91/i2c.c \
../tlkdrv/B91/lpc.c \
../tlkdrv/B91/mdec.c \
../tlkdrv/B91/npe.c \
../tlkdrv/B91/pke.c \
../tlkdrv/B91/plic.c \
../tlkdrv/B91/pwm.c \
../tlkdrv/B91/s7816.c \
../tlkdrv/B91/spi.c \
../tlkdrv/B91/stimer.c \
../tlkdrv/B91/timer.c \
../tlkdrv/B91/uart.c \
../tlkdrv/B91/usbhw.c 

OBJS += \
./tlkdrv/B91/analog.o \
./tlkdrv/B91/audio.o \
./tlkdrv/B91/charger.o \
./tlkdrv/B91/clock.o \
./tlkdrv/B91/core.o \
./tlkdrv/B91/flash.o \
./tlkdrv/B91/gpio.o \
./tlkdrv/B91/i2c.o \
./tlkdrv/B91/lpc.o \
./tlkdrv/B91/mdec.o \
./tlkdrv/B91/npe.o \
./tlkdrv/B91/pke.o \
./tlkdrv/B91/plic.o \
./tlkdrv/B91/pwm.o \
./tlkdrv/B91/s7816.o \
./tlkdrv/B91/spi.o \
./tlkdrv/B91/stimer.o \
./tlkdrv/B91/timer.o \
./tlkdrv/B91/uart.o \
./tlkdrv/B91/usbhw.o 

C_DEPS += \
./tlkdrv/B91/analog.d \
./tlkdrv/B91/audio.d \
./tlkdrv/B91/charger.d \
./tlkdrv/B91/clock.d \
./tlkdrv/B91/core.d \
./tlkdrv/B91/flash.d \
./tlkdrv/B91/gpio.d \
./tlkdrv/B91/i2c.d \
./tlkdrv/B91/lpc.d \
./tlkdrv/B91/mdec.d \
./tlkdrv/B91/npe.d \
./tlkdrv/B91/pke.d \
./tlkdrv/B91/plic.d \
./tlkdrv/B91/pwm.d \
./tlkdrv/B91/s7816.d \
./tlkdrv/B91/spi.d \
./tlkdrv/B91/stimer.d \
./tlkdrv/B91/timer.d \
./tlkdrv/B91/uart.d \
./tlkdrv/B91/usbhw.d 


# Each subdirectory must supply rules for building sources it contributes
tlkdrv/B91/%.o: ../tlkdrv/B91/%.c tlkdrv/B91/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-elf-gcc -mcmodel=medium -O2 -fmessage-length=0 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wlogical-op -Warray-bounds -Wlto-type-mismatch -Wimplicit-function-declaration -Wlto-type-mismatch -Wreturn-type  -g3 -DTLKAPP_GENERAL_ENABLE=1 -DMCU_CORE_B91=1 -DMCU_CORE_B92=2 -DMCU_CORE_TYPE=MCU_CORE_B91 -DTLKHW_TYPE_C1T213A83_V5_1=1 -DTLKHW_TYPE_C1T213A20_V1_3=2 -DTLKHW_TYPE=TLKHW_TYPE_C1T213A83_V5_1 -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\core" -I"E:\scratch_workspace\spp\telink_b91m_btble_dual_mode_general_sdk-5.3.0.0_Patch_0002\sdk\tlkdrv\B91" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/riscv32-elf/sys-include" -isystem"C:\TelinkIoTStudio\/RDS/V5.1.2/toolchains/nds32le-elf-mculib-v5f/lib/gcc/riscv32-elf/10.3.0/include-fixed" -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fno-jump-tables -fshort-wchar -fuse-ld=bfd -mext-dsp -fpack-struct  -fno-delete-null-pointer-checks -Wno-address-of-packed-member -Wno-attribute-alias -fno-fat-lto-objects -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


