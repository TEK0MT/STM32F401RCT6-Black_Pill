################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/RCC/STM32F401xx_HAL_RCC.c 

OBJS += \
./Src/HAL/RCC/STM32F401xx_HAL_RCC.o 

C_DEPS += \
./Src/HAL/RCC/STM32F401xx_HAL_RCC.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/RCC/%.o Src/HAL/RCC/%.su Src/HAL/RCC/%.cyclo: ../Src/HAL/RCC/%.c Src/HAL/RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-RCC

clean-Src-2f-HAL-2f-RCC:
	-$(RM) ./Src/HAL/RCC/STM32F401xx_HAL_RCC.cyclo ./Src/HAL/RCC/STM32F401xx_HAL_RCC.d ./Src/HAL/RCC/STM32F401xx_HAL_RCC.o ./Src/HAL/RCC/STM32F401xx_HAL_RCC.su

.PHONY: clean-Src-2f-HAL-2f-RCC

