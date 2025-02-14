/*
 * CortexM4_CORE_Systic.h
 *
 *  Created on: Feb 12, 2025
 *      Author: Mohamed Tarek
 */

#ifndef CORTEXM4_CORTEXM4_CORE_SYSTIC_H_
#define CORTEXM4_CORTEXM4_CORE_SYSTIC_H_
/********************************Includes Start***********************************/
#include "Common/Std_Types.h"
#include "CortexM4_CORE_Systic_CFG.h"
#include "Common/Common_Macros.h"
/********************************Includes End*************************************/


/********************************Macro Declaration Start**************************/
#define SYSTIC_BASE						(0xE000E010)
#define SYSTIC							((Systic_Types *)SYSTIC_BASE)



#define SYSTIC_BIT_ENABLE_POS 			(0U)
#define SYSTIC_BIT_ENABLE_MASK			(0x01 << SYSTIC_BIT_ENABLE_POS)

#define SYSTIC_BIT_IRQ_POS 			(1U)
#define SYSTIC_BIT_IRQ_MASK			(0x01 << SYSTIC_BIT_IRQ_POS)

#define SYSTIC_BIT_CLOCK_SELECT_POS 			(2U)
#define SYSTIC_BIT_CLOCK_SELECT_MASK			(0x01 << SYSTIC_BIT_ENABLE_POS)

#define SYSTIC_COUNTERFLAG_POS					(16U)
#define SYSTIC_COUNTERFLAG_MASK					(1UL << SYSTIC_COUNTERFLAG_POS)

#define SYSTIC_SINGLEINTERVAL_MODE 				0
#define SYSTIC_PERIODICINTERVAL_MODE 			1

/********************************Macro Declaration End****************************/


/********************************Macro Function Declaration Start*****************/

/********************************Macro Function Declaration End*******************/





/********************************Data Type Declaration Start**********************/
typedef struct{
	volatile uint32_t SYST_CSR;
	volatile uint32_t SYST_RVR;
	volatile uint32_t SYST_CVR;
	volatile uint32_t SYST_CALIB;
}Systic_Types;
/********************************Data Type Declaration End************************/





/********************************Software Interfaces Declarations Start***********/
uint32_t Systic_Init(uint32_t load);
uint32_t Systic_DeInit(void);
uint32_t Systic_WaitBlocking(uint32_t load);
uint32_t Systic_SingleInterval(uint32_t load ,ptr_function *call_back);
uint32_t Systic_PereodicInterval(uint32_t load ,ptr_function *call_back);
/********************************Software Interfaces Declarations End*************/


#endif /* CORTEXM4_CORTEXM4_CORE_SYSTIC_H_ */
