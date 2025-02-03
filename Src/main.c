/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Tarek
 * @brief          : Main program body
 ******************************************************************************
 **/



#include "CortexM4/CortexM4_CORE_NVIC.h"
#include "CortexM4/CortexM4_CORE_SCB.h"
uint32_t value = 0;
uint32_t value2 = 0;
uint32_t value3 = 0;
void FLASH_IRQHandler(void);
void RCC_IRQHandler(void);
void EXTI22_RTC_WKUP_IRQHandler(void);

int main(void)
{
	SCB_SetGroupPriority(SCB_GROUPPRIORITY_2);


	NVIC_EnableIRQ(RTC_WKUP_IRQ);
	NVIC_EnableIRQ(Flash_IRQ);
	NVIC_EnableIRQ(RCC_IRQ);
	//NVIC_DisableIRQ(Flash_IRQ);
	NVIC_SetPriority(RTC_WKUP_IRQ,8);
	NVIC_SetPriority(Flash_IRQ,4);
	NVIC_SetPriority(RCC_IRQ,5);
	NVIC_SetPending(RTC_WKUP_IRQ);

    /* Loop forever */
	for(;;);
}
void EXTI22_RTC_WKUP_IRQHandler(void){
	value = 1;
	NVIC_SetPending(Flash_IRQ);
	//NVIC_SetPending(RCC_IRQ);
	value = 4;
}

void FLASH_IRQHandler(void){
	value2 = 1;
	NVIC_SetPending(RCC_IRQ);
	value2 = 2;
}

void RCC_IRQHandler(void){
	value3 = 3;
}
