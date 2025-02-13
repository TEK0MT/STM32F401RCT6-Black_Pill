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
#include "CortexM4/CortexM4_CORE_Systic.h"
void System_Clcok_Config(void);
uint32_t timer = 0;
int main(void)
{
	System_Clcok_Config();

	Systic_Init(1000);

    /* Loop forever */
	while(1){
		Systic_WaitBlocking(1999999);
		timer++;
	}
}
void System_Clcok_Config(void){
	RCC_OscInitTypeDef osc = {.OscillatorType = RCC_OSCILLATORTYPE_HSI,.HSIState=RCC_HSI_ON,.HSEState=RCC_HSE_OFF,.LSEState = RCC_LSE_OFF,.LSIState=RCC_LSI_OFF};
	RCC_ClkInitTypeDef pre = {.AHBCLKDivider=RCC_AHB_PRESCALER_DIV2,.APB1CLKDivider=RCC_APB1_PRESCALER_DIV2,.APB2CLKDivider=RCC_APB2_PRESCALER_DIV2};
	HAL_RCC_OscConfig(&osc);
	HAL_RCC_ClockConfig(&pre);
}
