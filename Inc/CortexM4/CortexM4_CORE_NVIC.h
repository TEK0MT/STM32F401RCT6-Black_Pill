/**
 ******************************************************************************
 * @file           : CortexM4_CORW_NVIC.h
 * @author         : Mohamed Tarek
 * @brief          : Declaration of NVIC software
 ******************************************************************************
 **/

#ifndef CORTEXM4_CORW_NVIC_H_
#define CORTEXM4_CORW_NVIC_H_

/********************************Includes Start***********************************/
#include "../Common/Std_Types.h"
/********************************Includes End*************************************/

/********************************Macro Declaration Start**************************/


#define NVIC_BASE 	(0xE000E100UL) // The address of the base of Nvic registers
#define NVIC 		((NVIC_Type *)(NVIC_BASE)) //Macro used to access the struct


/********************************Macro Declaration End****************************/

#define NVIC_KEY 				0x1F
#define NVIC_REGISTER_SELECTION 5
/********************************Macro Function Declaration Start*****************/

/********************************Macro Function Declaration End*******************/





/********************************Data Type Declaration Start**********************/

/**
 * \brief Structure type to access Nvic registers
 */

typedef struct{
	volatile uint32_t ISER[8U]; // (R/W) register offset to enable interrupts
	uint32_t Reserved0[24U];
	volatile uint32_t ICER[8U];	// (R/W) register offset to clear interrupts flags
	uint32_t Reserved1[24U];
	volatile uint32_t ISPR[8U];	// (R/W) register offset to set pending interrupt
	uint32_t Reserved2[24U];
	volatile uint32_t ICPR[8U];	// (R/W) register offset to clear pending interrupts
	uint32_t Reserved3[24U];
	volatile uint32_t IABR[8U];	// (R/W)  register offset to active interrupts
	uint32_t Reserved4[56U];
	volatile uint32_t IP[240U];	// (R/W) register offset to put interrupts priority
	uint32_t Reserved5[644U];
	volatile uint32_t STIR;		// ( /W) register offset to trigger interrupts
}NVIC_Type;

/*
 * List of IRQS numbers in one enum
 * positions numbered by stm reference manual (RM0368)
 * */
typedef enum{
	NMI_IRQ								= -14,
	HardFault_IRQ						= -13,
	MemManage_IRQ						= -12,
	BusFault_IRQ						= -11,
	UsageFault_IRQ						= -10,
	SVCall_IRQ							= -5,
	Debug_IRQ							= -4,
	PendSV_IRQ							= -2,
	Systick_IRQ							= -1,
	WWDG_IRQ 							= 0,
	PVD_IRQ  							= 1,
	TAMP_STAMP_IRQ 						= 2,
	RTC_WKUP_IRQ						= 3,
	Flash_IRQ							= 4,
	RCC_IRQ								= 5,
	EXTI0_IRQ							= 6,
	EXTI1_IRQ							= 7,
	EXTI2_IRQ							= 8,
	EXTI3_IRQ							= 9,
	EXTI4_IRQ							= 10,
	DMA1_Stream0_IRQ       				= 11,
	DMA1_Stream1_IRQ					= 12,
	DMA1_Stream2_IRQ					= 13,
	DMA1_Stream3_IRQ					= 14,
	DMA1_Stream4_IRQ					= 15,
	DMA1_Stream5_IRQ					= 16,
	DMA1_Stream6_IRQ 					= 17,
	ADC_IRQ 							= 18,
	EXTI9_5_IRQ							= 23,
	TIM1_BRK_TIM9_IRQ					= 24,
	TIM1_UP_TIM10_IRQ					= 25,
	TIM1_TRG_COM_TIM11_IRQ				= 26,
	TIM1_CC_IRQ							= 27,
	TIM2_IRQ							= 28,
	TIM3_IRQ							= 29,
	TIM4_IRQ							= 30,
	I2C1_EV_IRQ							= 31,
	I2C1_ER_IRQ							= 32,
	I2C2_EV_IRQ							= 33,
	I2C2_ER_IRQ							= 34,
	SPI1_IRQ							= 35,
	SPI2_IRQ							= 36,
	USART1_IRQ							= 37,
	USART2_IRQ							= 38,
	EXTI15_10_IRQ						= 40,
	RTC_Alarm_IRQ						= 41,
	OTG_FS_WKUP_IRQ						= 42,
	DMA1_Stream7_IRQ					= 47,
	SDIO_IRQ							= 49,
	TIM5_IRQ							= 50,
	SPI3_IRQ							= 51,
	DMA2_Stream0_IRQ					= 56,
	DMA2_Stream1_IRQ					= 57,
	DMA2_Stream2_IRQ					= 58,
	DMA2_Stream3_IRQ					= 59,
	DMA2_Stream4_IRQ					= 60,
	OTG_FS_IRQ							= 67,
	DMA2_Stream5_IRQ 					= 68,
	DMA2_Stream6_IRQ					= 69,
	DMA2_Stream7_IRQ					= 70,
	USART6_IRQ							= 71,
	I2C3_EV_IRQ							= 72,
	I2C3_ER_IRQ							= 73,
	FPU_IRQ								= 81,
	SPI4_IRQ							= 84

}IRQS_Types;

/********************************Data Type Declaration End************************/





/********************************Software Interfaces Declarations Start***********/
/*
 *@brief Enable interrupt
 *@details Enable specific interrupt in NVIC Controller
 *@Params take one IRQS_Types parameter
 *@note irq must not be negative
 * */
void NVIC_EnableIRQ(IRQS_Types irq);

/*
*@brief Disable interrupt
*@details Disable specific interrupt in NVIC Controller
*@Params take one IRQS_Types parameter
*@note irq must not be negative
* */
void NVIC_DisableIRQ(IRQS_Types irq);

/*
*@brief SetPending
*@details Set specific interrupt to pending status in NVIC Controller
*@Params take one IRQS_Types parameter
*@note irq must not be negative
* */
void NVIC_SetPending(IRQS_Types irq);

/*
*@brief SetPending
*@details Clear specific interrupt from pending status in NVIC Controller
*@Params take one IRQS_Types parameter
*@note irq must not be negative
* */
void NVIC_ClearPending(IRQS_Types irq);

/*
*@brief Get status
*@details Get the status of specific interrupt is it active or not
*@Params take one IRQS_Types parameter
*@note irq must not be negative
*@return 0 is active
*@return 1 is not active
* */
uint32_t NVIC_GetActive(IRQS_Types irq);
/********************************Software Interfaces Declarations End*************/

#endif/* CORTEXM4_CORW_NVIC_H_*/
