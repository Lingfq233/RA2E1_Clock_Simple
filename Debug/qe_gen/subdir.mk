################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qe_gen/qe_touch_config.c \
../qe_gen/qe_touch_sample.c 

C_DEPS += \
./qe_gen/qe_touch_config.d \
./qe_gen/qe_touch_sample.d 

OBJS += \
./qe_gen/qe_touch_config.o \
./qe_gen/qe_touch_sample.o 

SREC += \
RA2E1_Clock_Simple.srec 

MAP += \
RA2E1_Clock_Simple.map 


# Each subdirectory must supply rules for building sources it contributes
qe_gen/%.o: ../qe_gen/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -DQE_TOUCH_CONFIGURATION -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/src" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra/fsp/inc" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra/fsp/inc/api" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra/fsp/inc/instances" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra_gen" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra_cfg/fsp_cfg/bsp" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/ra_cfg/fsp_cfg" -I"D:/e2_studio/workspace/RA2E1_Clock_Simple/qe_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

