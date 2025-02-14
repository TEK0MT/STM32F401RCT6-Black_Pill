/*
 * CortexM4_CORE_Systic.c
 *
 *  Created on: Feb 12, 2025
 *      Author: Mohamed Tarek
 */
#include "CortexM4/CortexM4_CORE_Systic.h"

static ptr_function Systic_Call_Back = 0;
static uint32_t systic_mode = 0;


uint32_t Systic_Init(uint32_t load){
	uint32_t ret = FUNC_RIGHT;
	if(load <= 0 || load > 0xFFFFFF){
		ret = FUNC_ERROR;
	}
	else{
	CLEAR_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_ENABLE_MASK);
	SYSTIC->SYST_CVR = 0;
	SYSTIC->SYST_RVR = load;
#if SYSTIC_CLOCK == SYSTIC_EXTERNAL_CLOCK
	CLEAR_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_CLOCK_SELECT_MASK);
#elif SYSTIC_CLOCK == SYSTIC_CORE_CLOCK
	SET_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_CLOCK_SELECT_MASK);
#else
#error "Invalid clock selection"
#endif
	CLEAR_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_IRQ_MASK);
	}
	return ret;
}

uint32_t Systic_DeInit(void){
	uint32_t ret = FUNC_RIGHT;
	CLEAR_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_ENABLE_POS);
	SYSTIC->SYST_CVR = 0;
	SYSTIC->SYST_RVR = 0;
	CLEAR_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_IRQ_POS);
	return ret;
}

uint32_t Systic_WaitBlocking(uint32_t load){
	uint32_t ret = FUNC_RIGHT;
	if(load <= 0 || load > 0xFFFFFF){
		ret = FUNC_ERROR;
	}
	else{
	SYSTIC->SYST_RVR = load;

	SET_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_ENABLE_MASK);
	while(READ_BIT(SYSTIC->SYST_CSR,SYSTIC_COUNTERFLAG_MASK) == 0);
	CLEAR_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_ENABLE_MASK);
	SYSTIC->SYST_RVR = 0;
	SYSTIC->SYST_CVR = 0;
	}
	return ret;
}


uint32_t Systic_SingleInterval(uint32_t load ,ptr_function *call_back){
	uint32_t ret = FUNC_RIGHT;
	if(call_back == 0 || load <= 0 || load > 0xFFFFFF){
		ret = FUNC_ERROR;
	}
	else{
		SYSTIC->SYST_RVR = load;
		Systic_Call_Back = call_back;
		systic_mode = SYSTIC_SINGLEINTERVAL_MODE;
		SET_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_IRQ_MASK);
		SET_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_ENABLE_MASK);
	}
	return ret;
}

uint32_t Systic_PereodicInterval(uint32_t load ,ptr_function *call_back){
	uint32_t ret = FUNC_RIGHT;
	if(call_back == 0 || load <= 0 || load > 0xFFFFFF){
		ret = FUNC_ERROR;
	}
	else{
		SYSTIC->SYST_RVR = load;
		Systic_Call_Back = call_back;
		systic_mode = SYSTIC_PERIODICINTERVAL_MODE;
		SET_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_IRQ_MASK);
		SET_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_ENABLE_MASK);
	}
	return ret;
}



void SysTick_Handler(void){
	if(Systic_Call_Back){
		if(systic_mode == SYSTIC_SINGLEINTERVAL_MODE){
			CLEAR_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_ENABLE_POS);
			SYSTIC->SYST_CVR = 0;
			SYSTIC->SYST_RVR = 0;
			CLEAR_BIT(SYSTIC->SYST_CSR,SYSTIC_BIT_IRQ_POS);
		}
		Systic_Call_Back();
	}
	else{ /*Nothing*/ }
}
