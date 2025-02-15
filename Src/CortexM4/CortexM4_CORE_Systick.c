/**
 ******************************************************************************
 * @file           : CortexM4_CORE_Systick.c
 * @author         : Mohamed Tarek
 * @brief          : Definition of System Timer
 ******************************************************************************
 **/
#include <CortexM4/CortexM4_CORE_Systick.h>

static ptr_function Systic_Call_Back = 0;
static uint32_t systic_mode = 0;

/*
 * @brief Initializing System Timer
 * @param The load to the system timer
 * */
uint32_t Systick_Init(uint32_t load){
	uint32_t ret = FUNC_RIGHT;
	if(load <= 0 || load > 0xFFFFFF){
		ret = FUNC_ERROR;
	}
	else{
	//Disable Systick
	CLEAR_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_ENABLE_MASK);
	//Clear current ticks
	SYSTICK->SYST_CVR = 0;
	//Load the Systick register
	SYSTICK->SYST_RVR = load;
#if SYSTIC_CLOCK == SYSTIC_EXTERNAL_CLOCK
	CLEAR_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_CLOCK_SELECT_MASK);
#elif SYSTIC_CLOCK == SYSTIC_CORE_CLOCK
	SET_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_CLOCK_SELECT_MASK);
#else
#error "Invalid clock selection"
#endif
	//Disable IRQ exceptions
	CLEAR_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_IRQ_MASK);
	}
	return ret;
}

uint32_t Systick_DeInit(void){
	uint32_t ret = FUNC_RIGHT;
	//Disable Systick
	CLEAR_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_ENABLE_POS);
	//Clear current ticks
	SYSTICK->SYST_CVR = 0;
	//Clear the load register
	SYSTICK->SYST_RVR = 0;
	//Disable IRQ exceptions
	CLEAR_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_IRQ_POS);
	return ret;
}

uint32_t Systick_WaitBlocking(uint32_t load){
	uint32_t ret = FUNC_RIGHT;
	if(load <= 0 || load > 0xFFFFFF){
		ret = FUNC_ERROR;
	}
	else{
	//Load the register
	SYSTICK->SYST_RVR = load;
	//Enable System timer
	SET_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_ENABLE_MASK);
	//Hang the system until ticks runs out
	while(READ_BIT(SYSTICK->SYST_CSR,SYSTICK_COUNTERFLAG_MASK) == 0);
	//Disable system timer
	CLEAR_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_ENABLE_MASK);
	//Reset the load value
	SYSTICK->SYST_RVR = 0;
	//Reset the current value
	SYSTICK->SYST_CVR = 0;
	}
	return ret;
}


uint32_t Systick_SingleInterval(uint32_t load ,ptr_function *call_back){
	uint32_t ret = FUNC_RIGHT;
	if(call_back == 0 || load <= 0 || load > 0xFFFFFF){
		ret = FUNC_ERROR;
	}
	else{
		//Load the register
		SYSTICK->SYST_RVR = load;
		//Assign the exception you need
		Systic_Call_Back = call_back;
		//Assign the timer mode to single interval
		systic_mode = SYSTICK_SINGLEINTERVAL_MODE;
		//Enable IRQ for systick
		SET_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_IRQ_MASK);
		//Enable Systick
		SET_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_ENABLE_MASK);
	}
	return ret;
}

uint32_t Systick_PereodicInterval(uint32_t load ,ptr_function *call_back){
	uint32_t ret = FUNC_RIGHT;
	if(call_back == 0 || load <= 0 || load > 0xFFFFFF){
		ret = FUNC_ERROR;
	}
	else{
		//Load the register
		SYSTICK->SYST_RVR = load;
		//Assign the exception you need
		Systic_Call_Back = call_back;
		//Assign the timer mode to periodic interval
		systic_mode = SYSTICK_PERIODICINTERVAL_MODE;
		//Enable IRQ for systick
		SET_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_IRQ_MASK);
		//Enable Systick
		SET_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_ENABLE_MASK);
	}
	return ret;
}


/*
 * @brief Get the remaining ticks in the System Timer
 * */
uint32_t Systick_GetReminingTicks(void){
	uint32_t val = 0;
	//Get the remaining ticks form the current value and store it to val
	val = SYSTICK->SYST_RVR;
	return val;
}


/*
 * @brief Get the elapsed ticks in the System Timer
 * */
uint32_t Systick_GetElabsedTicks(void){
	uint32_t val = 0;
	//Get the load and subtracts it by the remaining ticks form the current value and store it to val
	val = SYSTICK->SYST_CVR - SYSTICK->SYST_RVR;
	return val;
}


void SysTick_Handler(void){
	if(Systic_Call_Back){
		if(systic_mode == SYSTICK_SINGLEINTERVAL_MODE){
			CLEAR_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_ENABLE_POS);
			SYSTICK->SYST_CVR = 0;
			SYSTICK->SYST_RVR = 0;
			CLEAR_BIT(SYSTICK->SYST_CSR,SYSTICK_BIT_IRQ_POS);
		}
		Systic_Call_Back();
	}
	else{ /*Nothing*/ }
}
