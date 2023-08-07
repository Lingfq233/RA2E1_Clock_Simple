################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/rm_touch/rm_touch.c 

C_DEPS += \
./ra/fsp/src/rm_touch/rm_touch.d 

OBJS += \
./ra/fsp/src/rm_touch/rm_touch.o 

SREC += \
RA2E1_Clock_Simple.srec 

MAP += \
RA2E1_Clock_Simple.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/rm_touch/%.o: ../ra/fsp/src/rm_touch/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -DQE_TOUCH_CONFIGURATION -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/src" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra/fsp/inc" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra/fsp/inc/api" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra/fsp/inc/instances" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra_gen" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra_cfg/fsp_cfg/bsp" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra_cfg/fsp_cfg" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/qe_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

