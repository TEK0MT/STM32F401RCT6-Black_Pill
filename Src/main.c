/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Tarek
 * @brief          : Main program body
 ******************************************************************************
 **/



#include "CortexM4/CortexM4_CORE_NVIC.h"
#include "CortexM4/CortexM4_CORE_SCB.h"
#include "HAL/RCC/STM32F401xx_HAL_RCC.h"

RCC_OscInitTypeDef osc = {.OscillatorType = RCC_OSCILLATORTYPE_HSE,.HSIState=RCC_HSI_OFF,.HSEState=RCC_HSE_ON,.LSEState = RCC_LSE_OFF,.LSIState=RCC_LSI_OFF};
	RCC_ClkInitTypeDef pre = {.AHBCLKDivider=RCC_AHB_PRESCALER_DIV2,.APB1CLKDivider=RCC_APB1_PRESCALER_DIV2,.APB2CLKDivider=RCC_APB2_PRESCALER_DIV2};
int main(void)
{

	HAL_RCC_OscConfig(&osc);
	HAL_RCC_ClockConfig(&pre);

    /* Loop forever */
	for(;;);
}
