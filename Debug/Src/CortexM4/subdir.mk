################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CortexM4/CortexM4_CORE_NVIC.c \
../Src/CortexM4/CortexM4_CORE_SCB.c \
../Src/CortexM4/CortexM4_CORE_Systick.c 

OBJS += \
./Src/CortexM4/CortexM4_CORE_NVIC.o \
./Src/CortexM4/CortexM4_CORE_SCB.o \
./Src/CortexM4/CortexM4_CORE_Systick.o 

C_DEPS += \
./Src/CortexM4/CortexM4_CORE_NVIC.d \
./Src/CortexM4/CortexM4_CORE_SCB.d \
./Src/CortexM4/CortexM4_CORE_Systick.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CortexM4/CortexM4_CORE_NVIC.o: D:/Embedded\ Systems/STM32F401RCT6-Black_Pill/Src/CortexM4/CortexM4_CORE_NVIC.c Src/CortexM4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/CortexM4/CortexM4_CORE_SCB.o: D:/Embedded\ Systems/STM32F401RCT6-Black_Pill/Src/CortexM4/CortexM4_CORE_SCB.c Src/CortexM4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/CortexM4/CortexM4_CORE_Systick.o: D:/Embedded\ Systems/STM32F401RCT6-Black_Pill/Src/CortexM4/CortexM4_CORE_Systick.c Src/CortexM4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-CortexM4

clean-Src-2f-CortexM4:
	-$(RM) ./Src/CortexM4/CortexM4_CORE_NVIC.cyclo ./Src/CortexM4/CortexM4_CORE_NVIC.d ./Src/CortexM4/CortexM4_CORE_NVIC.o ./Src/CortexM4/CortexM4_CORE_NVIC.su ./Src/CortexM4/CortexM4_CORE_SCB.cyclo ./Src/CortexM4/CortexM4_CORE_SCB.d ./Src/CortexM4/CortexM4_CORE_SCB.o ./Src/CortexM4/CortexM4_CORE_SCB.su ./Src/CortexM4/CortexM4_CORE_Systick.cyclo ./Src/CortexM4/CortexM4_CORE_Systick.d ./Src/CortexM4/CortexM4_CORE_Systick.o ./Src/CortexM4/CortexM4_CORE_Systick.su

.PHONY: clean-Src-2f-CortexM4

