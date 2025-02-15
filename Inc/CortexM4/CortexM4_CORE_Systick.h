/**
 ******************************************************************************
 * @file           : CortexM4_CORE_Systick.h
 * @author         : Mohamed Tarek
 * @brief          : Declaration of System Timer
 ******************************************************************************
**/
#ifndef CORTEXM4_CORTEXM4_CORE_SYSTICK_H_
#define CORTEXM4_CORTEXM4_CORE_SYSTICK_H_
/********************************Includes Start***********************************/
#include <CortexM4/CortexM4_CORE_Systick_CFG.h>
#include "Common/Std_Types.h"
#include "Common/Common_Macros.h"
/********************************Includes End*************************************/


/********************************Macro Declaration Start**************************/
#define SYSTICK_BASE							(0xE000E010)						//Systick Base address
#define SYSTICK									((Systick_Types *)SYSTICK_BASE)		//Systick pointer



#define SYSTICK_BIT_ENABLE_POS 					(0U)								//Systick enable bit position
#define SYSTICK_BIT_ENABLE_MASK					(0x01 << SYSTICK_BIT_ENABLE_POS)	//Systick enable bit Mask

#define SYSTICK_BIT_IRQ_POS 					(1U)								//Systick IRQ bit position
#define SYSTICK_BIT_IRQ_MASK					(0x01 << SYSTICK_BIT_IRQ_POS)		//Systick IRQ bit Mask

#define SYSTICK_BIT_CLOCK_SELECT_POS 			(2U)								//Systick clock select bit position
#define SYSTICK_BIT_CLOCK_SELECT_MASK			(0x01 << SYSTICK_BIT_ENABLE_POS)	//Systick clock select Mask

#define SYSTICK_COUNTERFLAG_POS					(16U)								//Systick counter flag position
#define SYSTICK_COUNTERFLAG_MASK				(1UL << SYSTICK_COUNTERFLAG_POS)	//Systick counter flag Mask

#define SYSTICK_SINGLEINTERVAL_MODE 			0
#define SYSTICK_PERIODICINTERVAL_MODE 			1

/********************************Macro Declaration End****************************/


/********************************Macro Function Declaration Start*****************/

/********************************Macro Function Declaration End*******************/





/********************************Data Type Declaration Start**********************/
typedef struct{
	volatile uint32_t SYST_CSR; 		//SysTick Control and Status register
	volatile uint32_t SYST_RVR;			//SysTick reload register
	volatile uint32_t SYST_CVR;			//SysTick current value register
	volatile uint32_t SYST_CALIB;		//SysTick calibration regitser
}Systick_Types;
/********************************Data Type Declaration End************************/





/********************************Software Interfaces Declarations Start***********/
/*
 * @brief Initializing System Timer
 * @param The load to the system timer
 * */
uint32_t Systick_Init(uint32_t load);
/*
 * @brief Deinitializing System Timer
 * */
uint32_t Systick_DeInit(void);
/*
 * @brief Hang the system untill the system timer complete the ticks
 * @param The load to the system timer
 * */
uint32_t Systick_WaitBlocking(uint32_t load);
/*
 * @brief Running the systick without hanging the system form one time with exception
 * @param The load to the system timer
 * */
uint32_t Systick_SingleInterval(uint32_t load ,ptr_function *call_back);
/*
 * @brief Running the systick without hanging the system periodically with exception
 * @param The load to the system timer
 * */
uint32_t Systick_PereodicInterval(uint32_t load ,ptr_function *call_back);

/*
 * @brief Get the remaining ticks in the System Timer
 * */
uint32_t Systick_GetReminingTicks(void);

/*
 * @brief Get the elapsed ticks in the System Timer
 * */
uint32_t Systick_GetElabsedTicks(void);
/********************************Software Interfaces Declarations End*************/


#endif /* CORTEXM4_CORTEXM4_CORE_SYSTICK_H_ */
