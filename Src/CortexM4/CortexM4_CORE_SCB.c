/**
 ******************************************************************************
 * @file           : CortexM4_CORW_SCB.c
 * @author         : Mohamed Tarek
 * @brief          : Declaration of System Control Block
 ******************************************************************************
 **/

#include "CortexM4/CortexM4_CORE_SCB.h"


/*
 * @brief Set Priority Grouping
 * @details Set how many groups and sub priority using the required unlock sequence
 * @param priority an uint32_t parameter
 * */
void SCB_SetGroupPriority(uint32_t priority){
	uint32_t Register_Value = 0;

	Register_Value = SCB->AIRCR;

	Register_Value &= ~(((uint32_t)PRIORITY_BITS_MASK << PRIORITY_BITS_POS) | ((uint32_t)VECTKEY_MASK << VECTKEY_POS));

	Register_Value = (((uint32_t)0x05FA << VECTKEY_POS) | (priority << PRIORITY_BITS_POS) | Register_Value);

	SCB->AIRCR = Register_Value;
}

/*
 * @brief Get Priority Grouping
 * @details Get how many groups and sub priority
 * @param priority an uint32_t parameter
 * */
uint32_t SCB_GetPriorityGrouping(void){

	return ((SCB->AIRCR & ((uint32_t)PRIORITY_BITS_MASK << PRIORITY_BITS_POS)) >> PRIORITY_BITS_POS);

}
