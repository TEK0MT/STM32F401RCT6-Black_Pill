/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Tarek
 * @brief          : Main program body
 ******************************************************************************
 **/



#include "../Inc/CortexM4/CortexM4_CORE_NVIC.h"
uint32_t value = 0;
void EXTI22_RTC_WKUP_IRQHandler(void);
int main(void)
{
	EnableIRQ(RTC_WKUP_IRQ);
	EnableIRQ(Flash_IRQ);
	EnableIRQ(RCC_IRQ);
	NVIC_DisableIRQ(Flash_IRQ);
	NVIC_SetPending(RTC_WKUP_IRQ);
    /* Loop forever */
	for(;;);
}
void EXTI22_RTC_WKUP_IRQHandler(void){
	value = 4;
}
