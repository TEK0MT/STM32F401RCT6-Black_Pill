/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Tarek
 * @brief          : Main program body
 ******************************************************************************
 **/



#include "../Inc/CortexM4/CortexM4_CORE_NVIC.h"

int main(void)
{
	EnableIRQ(RTC_WKUP_IRQ);
	EnableIRQ(Flash_IRQ);
	EnableIRQ(RCC_IRQ);
    /* Loop forever */
	for(;;);
}
