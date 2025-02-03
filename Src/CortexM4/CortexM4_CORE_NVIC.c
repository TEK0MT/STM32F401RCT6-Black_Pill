/**
 ******************************************************************************
 * @file           : CortexM4_CORW_NVIC.c
 * @author         : Mohamed Tarek
 * @brief          : Definitions of NVIC software
 ******************************************************************************
 **/
#include "CortexM4/CortexM4_CORE_NVIC.h"

/*
 *@brief Enable interrupt
 *@details Enable specific interrupt in NVIC Controller
 *@Params take one IRQS_Types parameter
 *@note irq must not be negative
 * */
void NVIC_EnableIRQ(IRQS_Types irq){

	if(irq >= 0){
		NVIC->ISER[(((uint32_t)irq) >> NVIC_REGISTER_SELECTION)] = (1UL << ((uint32_t)irq & NVIC_KEY));
	}
}

/*
*@brief Disable interrupt
*@details Disable specific interrupt in NVIC Controller
*@Params take one IRQS_Types parameter
*@note irq must not be negative
* */
void NVIC_DisableIRQ(IRQS_Types irq){
	if(irq >= 0){
			NVIC->ICER[(((uint32_t)irq) >> NVIC_REGISTER_SELECTION)] = (1UL << ((uint32_t)irq & NVIC_KEY));;
		}
}

/*
*@brief SetPending
*@details Set specific interrupt to pending status in NVIC Controller
*@Params take one IRQS_Types parameter
*@note irq must not be negative
* */
void NVIC_SetPending(IRQS_Types irq){
	if(irq >= 0){
			NVIC->ISPR[(((uint32_t)irq) >> NVIC_REGISTER_SELECTION)] = (1UL << ((uint32_t)irq & NVIC_KEY));
		}
}

/*
*@brief SetPending
*@details Clear specific interrupt from pending status in NVIC Controller
*@Params take one IRQS_Types parameter
*@note irq must not be negative
* */
void NVIC_ClearPending(IRQS_Types irq){
	if(irq >= 0){
			NVIC->ICPR[(((uint32_t)irq) >> NVIC_REGISTER_SELECTION)] = (1UL << ((uint32_t)irq & NVIC_KEY));
		}
}

/*
*@brief Get status
*@details Get the status of specific interrupt is it active or not
*@Params take one IRQS_Types parameter
*@note irq must not be negative
*@return 0 is active
*@return 1 is not active
* */
uint32_t NVIC_GetActive(IRQS_Types irq){

	if(irq >= 0){
				return ((NVIC->IABR[(((uint32_t)irq) >> NVIC_REGISTER_SELECTION)] & (1UL << ((uint32_t)irq & NVIC_KEY)) != (uint32_t)0)? 0UL : 1UL);
			}
	else{
	return 0UL;
	}
}

/*
*@brief Set priority
*@details Set the priority of specific interrupt
*@Params take two 1-IRQS_Types parameter 2- uint32_t priority for priority level
*@note irq must not be negative
* */
void NVIC_SetPriority(IRQS_Types irq,uint32_t priority){
	if(irq >= 0){
			NVIC->IP[(uint32_t)irq] =  (uint8_t)((priority << (8 - NVIC_PRIORITY_BITS) & (uint32_t)0xFF));
	}
	else{
		/*Nothing*/
	}
}


/*
*@brief Get priority
*@details Get the priority of specific interrupt
*@note irq must not be negative
* */
uint32_t NVIC_GetPriority(IRQS_Types irq){

			return (NVIC->IP[(uint32_t)irq] >> (8 - NVIC_PRIORITY_BITS));

}

