/*
 * STM32F401xx_PERIPHERALS_DEF.h
 *
 *  Created on: Feb 9, 2025
 *      Author: Mohamed Tarek
 */

#ifndef HAL_COMMON_STM32F401XX_PERIPHERALS_DEF_H_
#define HAL_COMMON_STM32F401XX_PERIPHERALS_DEF_H_
/********************************Includes Start***********************************/

/********************************Includes End*************************************/


/********************************Macro Declaration Start**************************/
#define PERIPHERALS_BASE					(0x40000000) 					//Peripherals Base Address
#define AHB1_BASE							(PERIPHERALS_BASE + 0x020000) 	//AHB1 Base address
#define RCC_BASE							(AHB1_BASE + 0x03800)			// RCC Base address
#define RCC									((RCC_Types *)RCC_BASE)



/********************************Macro Declaration End****************************/


/********************************Macro Function Declaration Start*****************/

/********************************Macro Function Declaration End*******************/

/********************************Data Type Declaration Start**********************/
typedef struct{
	volatile uint32_t CR; 			// RCC_CR register
	volatile uint32_t PLLCFGR;		// RCC_PLLCFGR register
	volatile uint32_t CFGR;			// RCC_CFGR register
	volatile uint32_t CIR;			// RCC_CIR register
	volatile uint32_t AHB1RSTR;		// RCC_AHB1RSTR register
	volatile uint32_t AHB2RSTR;		// RCC_AHB2RSTR register
	uint32_t Reserved0[2];
	volatile uint32_t APB1RSTR;		// RCC_APB1RSTR register
	volatile uint32_t APB2RSTR;		// RCC_APB2RSTR register
	uint32_t Reserved1[2];
	volatile uint32_t AHB1ENR;		// RCC_AHB1ENR register
	volatile uint32_t AHB2ENR;		// RCC_AHB2ENR register
	uint32_t Reserved2[2];
	volatile uint32_t APB1ENR;		// RCC_APB1ENR register
	volatile uint32_t APB2ENR;		// RCC_APB2ENR register
	uint32_t Reserved3[2];
	volatile uint32_t AHB1LPENR;	// RCC_AHB1LPENR register
	volatile uint32_t AHB2LPENR;	// RCC_AHB2LPENR register
	uint32_t Reserved4[2];
	volatile uint32_t APB1LPENR;	// RCC_APB1LPENR register
	volatile uint32_t APB2LPENR;	// RCC_APB2LPENR register
	uint32_t Reserved5[2];
	volatile uint32_t BDCR;			// RCC_BDCR register
	volatile uint32_t CSR;			// RCC_CSR register
	uint32_t Reserved6[2];
	volatile uint32_t SSCGR;		// RCC_SSCGR register
	volatile uint32_t PLLI2SCFGR;	// RCC_PLLI2SCFGR register
	volatile uint32_t DCKCFGR;		// RCC_DCKCFGR register
}RCC_Types; //RCC REGISTERS

/********************************Data Type Declaration End************************/

/********************************Software Interfaces Declarations Start***********/

/********************************Software Interfaces Declarations End*************/



#endif /* HAL_COMMON_STM32F401XX_PERIPHERALS_DEF_H_ */
