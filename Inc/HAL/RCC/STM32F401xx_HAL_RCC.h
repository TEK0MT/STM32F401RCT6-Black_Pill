/**
 ********************************************************************************
 * @file           : STM32F401xx_HAL_RCC.h
 * @author         : Mohamed Tarek
 * @brief          : Declaration of Reset and clock contol register
 ********************************************************************************
 **/
#ifndef HAL_RCC_STM32F401XX_HAL_RCC_H_
#define HAL_RCC_STM32F401XX_HAL_RCC_H_

/********************************Includes Start***********************************/
#include "Common/Std_Types.h"
#include "HAL/Common/STM32F401xx_HAL_DEF.h"
#include "Common/Common_Macros.h"
#include "HAL/Common/STM32F401xx_PERIPHERALS_DEF.h"
/********************************Includes End*************************************/


/********************************Macro Declaration Start**************************/

#define CLOCK_SELECTION_POS					(0U)


#define RCC_AHB_PRESCALER_POS				(4U)
#define RCC_AHB_PRESCALER_MASK				(0x0FUL << RCC_AHB_PRESCALER_POS)				//Mask for AHB prescaler

#define RCC_APB_LOWSPEED_PRESCALER_POS		(10U)
#define RCC_APB_LOWSPEED_PRESCALER_MASK		(0x07UL << RCC_APB_LOWSPEED_PRESCALER_POS)		//Mask for APB1 prescaler

#define RCC_APB_HIGHSPEED_PRESCALER_POS		(13U)
#define RCC_APB_HIGHSPEED_PRESCALER_MASK	(0x07UL << RCC_APB_HIGHSPEED_PRESCALER_POS)		//Mask for APB2 prescaler


#define RCC_AHB_PRESCALER_NONE						(0x000000000) 	//AHB prescaler no division
#define RCC_AHB_PRESCALER_DIV2						(0x000000080)	//AHB prescaler division by 2
#define RCC_AHB_PRESCALER_DIV4						(0x000000090)	//AHB prescaler division by 4
#define RCC_AHB_PRESCALER_DIV8						(0x0000000A0)	//AHB prescaler division by 8
#define RCC_AHB_PRESCALER_DIV16						(0x0000000B0)	//AHB prescaler division by 16
#define RCC_AHB_PRESCALER_DIV64						(0x0000000C0)	//AHB prescaler division by 64
#define RCC_AHB_PRESCALER_DIV128					(0x0000000D0)	//AHB prescaler division by 128
#define RCC_AHB_PRESCALER_DIV256					(0x0000000E0)	//AHB prescaler division by 256
#define RCC_AHB_PRESCALER_DIV512					(0x0000000F0)	//AHB prescaler division by 512


#define RCC_APB1_PRESCALER_NONE						(0x000000000)	//APB1 prescaler no division
#define RCC_APB1_PRESCALER_DIV2						(0x000001000)	//APB1 prescaler division by 2
#define RCC_APB1_PRESCALER_DIV4						(0x000001400)	//APB1 prescaler division by 4
#define RCC_APB1_PRESCALER_DIV8						(0x000001800)	//APB1 prescaler division by 8
#define RCC_APB1_PRESCALER_DIV16					(0x000001C00)	//APB1 prescaler division by 16

#define RCC_APB2_PRESCALER_NONE						(0x000000000)	//APB2 prescaler no division
#define RCC_APB2_PRESCALER_DIV2						(0x000008000)	//APB2 prescaler division by 2
#define RCC_APB2_PRESCALER_DIV4						(0x00000A000)	//APB2 prescaler division by 4
#define RCC_APB2_PRESCALER_DIV8						(0x00000E000)	//APB2 prescaler division by 8
#define RCC_APB2_PRESCALER_DIV16					(0x000001C00)	//APB2 prescaler division by 16

#define GPIOA_RCC_BIT_ENABLE_POS			(0U)
#define GPIOA_RCC_BIT_ENABLE_MASK			(1U << GPIOA_RCC_BIT_ENABLE_POS)
#define GPIOB_RCC_BIT_ENABLE_POS			(2U)
#define GPIOB_RCC_BIT_ENABLE_MASK			(1U << GPIOB_RCC_BIT_ENABLE_POS)
#define GPIOC_RCC_BIT_ENABLE_POS			(2U)
#define GPIOC_RCC_BIT_ENABLE_MASK			(1U << GPIOC_RCC_BIT_ENABLE_POS)
#define GPIOD_RCC_BIT_ENABLE_POS			(3U)
#define GPIOD_RCC_BIT_ENABLE_MASK			(1U << GPIOD_RCC_BIT_ENABLE_POS)
#define GPIOE_RCC_BIT_ENABLE_POS			(4U)
#define GPIOE_RCC_BIT_ENABLE_MASK			(1U << GPIOE_RCC_BIT_ENABLE_POS)
#define GPIOH_RCC_BIT_ENABLE_POS			(7U)
#define GPIOH_RCC_BIT_ENABLE_MASK			(1U << GPIOH_RCC_BIT_ENABLE_POS)


#define RCC_OSCILLATORTYPE_NONE				(0x00000000U)
#define RCC_OSCILLATORTYPE_HSE				(0x00000001U)
#define RCC_OSCILLATORTYPE_HSI				(0x00000002U)
#define RCC_OSCILLATORTYPE_LSE				(0x00000004U)
#define RCC_OSCILLATORTYPE_LSI				(0x00000008U)

#define RCC_CFGR_Sw0_POS					(0U)
#define RCC_CFGR_Sw0_MASK					(0x01 << RCC_CFGR_Sw0_POS)

#define RCC_CFGR_Sw1_POS					(1U)
#define RCC_CFGR_Sw1_MASK					(0x01 << RCC_CFGR_Sw1_POS)

#define RCC_CR_HSEON_POS					(16U)
#define RCC_CR_HSEON_MASK					(0x01 << RCC_CR_HSEON_POS)		//Mask for High speed external oscillator

#define RCC_CR_HSION_POS					(0U)
#define RCC_CR_HSION_MASK					(0x01 << RCC_CR_HSION_POS)		//Mask for High speed internal oscillator

#define RCC_BDCR_LSEON_POS					(0U)
#define RCC_BDCR_LSEON_MASK					(0x01 << RCC_BDCR_LSEON_POS)	//Mask for Low speed external oscillator

#define RCC_CSR_LSION_POS					(0U)
#define RCC_CSR_LSION_MASK					(0x01 << RCC_CSR_LSION_POS)		//Mask for Low speed internal oscillator

#define RCC_HSE_OFF							((uint8_t)0x00)					//@defgroup state High speed external on
#define RCC_HSE_ON							((uint8_t)0x01)					//@defgroup state High speed external off

#define RCC_HSI_OFF							((uint8_t)0x00)					//@defgroup state High speed internal on
#define RCC_HSI_ON							((uint8_t)0x01)					//@defgroup state High speed internal off

#define RCC_LSE_OFF							((uint8_t)0x00)					//@defgroup state Low speed external on
#define RCC_LSE_ON							((uint8_t)0x01)					//@defgroup state Low speed external off

#define RCC_LSI_OFF							((uint8_t)0x00)					//@defgroup state Low speed internal on
#define RCC_LSI_ON							((uint8_t)0x01)					//@defgroup state Low speed internal off

/********************************Macro Declaration End****************************/


/********************************Macro Function Declaration Start*****************/
#define RCC_GPIOA_ENABLE()					(RCC->AHB1ENR |= GPIOA_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOB_ENABLE()					(RCC->AHB1ENR |= GPIOB_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOC_ENABLE()					(RCC->AHB1ENR |= GPIOC_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOD_ENABLE()					(RCC->AHB1ENR |= GPIOD_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOE_ENABLE()					(RCC->AHB1ENR |= GPIOE_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOH_ENABLE()					(RCC->AHB1ENR |= GPIOH_RCC_BIT_ENABLE_MASK)


#define RCC_GPIOA_DISABLE()					(RCC->AHB1ENR &= ~GPIOA_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOB_DISABLE()					(RCC->AHB1ENR &= ~GPIOB_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOC_DISABLE()					(RCC->AHB1ENR &= ~GPIOC_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOD_DISABLE()					(RCC->AHB1ENR &= ~GPIOD_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOE_DISABLE()					(RCC->AHB1ENR &= ~GPIOE_RCC_BIT_ENABLE_MASK)
#define RCC_GPIOH_DISABLE()					(RCC->AHB1ENR &= ~GPIOH_RCC_BIT_ENABLE_MASK)
/********************************Macro Function Declaration End*******************/





/********************************Data Type Declaration Start**********************/


typedef struct{
	uint32_t OscillatorType;		//Type of oscillator for application

	uint32_t HSEState;				//High speed external oscillator state @ref state

	uint32_t LSEState;				//Low speed external oscillator state @ref state

	uint32_t HSIState;				//High speed internal oscillator state @ref state

	uint32_t LSIState;				//Low speed internal oscillator state @ref state
}RCC_OscInitTypeDef;


typedef struct{
	uint32_t AHBCLKDivider;			//AHB prescaler devision
	uint32_t APB1CLKDivider;		//APB1 prescaler devision
	uint32_t APB2CLKDivider;		//APB2 prescaler devision
}RCC_ClkInitTypeDef;
/********************************Data Type Declaration End************************/





/********************************Software Interfaces Declarations Start***********/
/*
 * @brief Configure the RCC clock
 * @Param osc of RCC_OscInitTypeDef type
 * */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *osc);
/*
 * @brief Configure the RCC presclares
 * @Param osc of RCC_ClkInitTypeDef type
 * */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *osc);
/********************************Software Interfaces Declarations End*************/



#endif /* HAL_RCC_STM32F401XX_HAL_RCC_H_ */
