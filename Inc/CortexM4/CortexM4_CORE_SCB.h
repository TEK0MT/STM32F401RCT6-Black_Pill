/**
 ******************************************************************************
 * @file           : CortexM4_CORW_SCB.h
 * @author         : Mohamed Tarek
 * @brief          : Declaration of System Control Block
 ******************************************************************************
 **/
#ifndef CORTEXM4_CORTEXM4_CORE_SCB_H_
#define CORTEXM4_CORTEXM4_CORE_SCB_H_
/********************************Includes Start***********************************/
#include "Common/Std_Types.h"
/********************************Includes End*************************************/


/********************************Macro Declaration Start**************************/
#define SCB_BASE		(0xE000ED00)			// base address of SCB registers
#define SCB				((SCB_Types *)SCB_BASE) // pointer to access all SCB registers

/*
 * @brief Define of the possibilities of group and sub priority
 * */
#define SCB_GROUPPRIORITY_0				(0X00000007U)	//!< No gropu-priority - 16 sub-priority
#define SCB_GROUPPRIORITY_1				(0X00000006U)	//!< 2 gropu-priority - 8 sub-priority
#define SCB_GROUPPRIORITY_2				(0X00000005U)	//!< 4 gropu-priority - 4 sub-priority
#define SCB_GROUPPRIORITY_3				(0X00000004U)	//!< 8 gropu-priority - 2 sub-priority
#define SCB_GROUPPRIORITY_4				(0X00000003U)	//!< 16 gropu-priority - No sub-priority


#define VECTKEY_POS 					16U
#define VECTKEY_MASK 					0xFFFFF

#define PRIORITY_BITS_POS				8U
#define PRIORITY_BITS_MASK				7U

/********************************Macro Declaration End****************************/


/********************************Macro Function Declaration Start*****************/

/********************************Macro Function Declaration End*******************/





/********************************Data Type Declaration Start**********************/
typedef struct{
	volatile uint32_t CPUID;	// CUPID base register
	volatile uint32_t ICSR;		// Interrupt control and status register
	volatile uint32_t VTOR;		// Vector table offset register
	volatile uint32_t AIRCR;	// Application interrupt and reset control register
	volatile uint32_t SCR;		// System control register
	volatile uint32_t CCR;		// Configuration and control register
	volatile uint32_t SHPR1;	// System handler priority register
	volatile uint32_t SHPR2;	// System handler priority register
	volatile uint32_t SHPR3;	// System handler priority register
	volatile uint32_t SHCSR;	// System handler control and status register
	volatile uint32_t CFSR;		// Configuration fault status register
	volatile uint32_t MMSR;		// MemManage Fault Status Register
	volatile uint32_t BFSR;		// BusFault Status Register
	volatile uint32_t UFSR;		//  UsageFault Status Register
	volatile uint32_t HFSR;		// Hard fault status register
	volatile uint32_t MMAR;		// Memory management fault register
	volatile uint32_t BFAR;		// Bus fault address register
	volatile uint32_t AFSR;		// Auxiliary fault status register
}SCB_Types;
/********************************Data Type Declaration End************************/





/********************************Software Interfaces Declarations Start***********/

/*
 * @brief Set Priority Grouping
 * @details Set how many groups and sub priority using the required unlock sequence
 * @param priority an uint32_t parameter
 * */
void SCB_SetGroupPriority(uint32_t priority);
/*
 * @brief Get Priority Grouping
 * @details Get how many groups and sub priority
 * @param priority an uint32_t parameter
 * */
uint32_t SCB_GetPriorityGrouping(void);
/********************************Software Interfaces Declarations End*************/



#endif /* CORTEXM4_CORTEXM4_CORE_SCB_H_ */
