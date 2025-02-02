/*
 * CortexM4_CORE_NVIC.c
 *
 *  Created on: Feb 2, 2025
 *      Author: Mohamed Tarek
 */
#include "../../Inc/CortexM4/CortexM4_CORE_NVIC.h"
void EnableIRQ(IRQS_Types irq){

	if(irq > 0){
		NVIC->ISER[(((uint32_t)irq) >> 5)] = (1UL << ((uint32_t)irq & 0x1F));
	}
}


void NVIC_DisableIRQ(IRQS_Types irq){
	if(irq > 0){
			NVIC->ICER[(((uint32_t)irq) >> 5)] = (1UL << ((uint32_t)irq & 0x1F));;
		}
}
