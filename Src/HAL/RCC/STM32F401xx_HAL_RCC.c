/**
 ********************************************************************************
 * @file           : STM32F401xx_HAL_RCC.c
 * @author         : Mohamed Tarek
 * @brief          : Definition of Reset and clock contol register
 ********************************************************************************
 **/
#include "HAL/RCC/STM32F401xx_HAL_RCC.h"
/*
 * @brief Configure the RCC clock
 * @Param osc of RCC_OscInitTypeDef type
 * */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *osc){
	HAL_StatusTypeDef RET = HAL_OK;
	if(NULL == osc){
		RET = HAL_ERROR;
	}
	else{
		if(osc->OscillatorType == RCC_OSCILLATORTYPE_HSE){
			if(osc->HSEState == RCC_HSE_ON){
				SET_BIT(RCC->CFGR,RCC_CFGR_Sw0_POS);
				CLEAR_BIT(RCC->CFGR,RCC_CFGR_Sw1_POS);
				SET_BIT(RCC->CR,RCC_CR_HSEON_MASK);
			}
			else{
				CLEAR_BIT(RCC->CR,RCC_CR_HSEON_MASK);
			}
		}
		else if (osc->OscillatorType == RCC_OSCILLATORTYPE_HSI){
			if(osc->HSIState == RCC_HSI_ON){
				SET_BIT(RCC->CR,RCC_CR_HSION_MASK);
				CLEAR_BIT(RCC->CFGR,RCC_CFGR_Sw0_POS);
				CLEAR_BIT(RCC->CFGR,RCC_CFGR_Sw1_POS);
			}
			else{
				CLEAR_BIT(RCC->CR,RCC_CR_HSION_MASK);
			}
		}
		else if(osc->OscillatorType == RCC_OSCILLATORTYPE_LSE){
			if(osc->LSEState == RCC_LSE_ON){
				SET_BIT(RCC->BDCR,RCC_BDCR_LSEON_MASK);

			}
			else{
				CLEAR_BIT(RCC->BDCR,RCC_BDCR_LSEON_MASK);
			}
		}
		else if(osc->OscillatorType == RCC_OSCILLATORTYPE_LSI){
			if(osc->LSIState == RCC_LSI_ON){
				SET_BIT(RCC->CSR,RCC_CSR_LSION_MASK);

			}
			else{
				CLEAR_BIT(RCC->CSR,RCC_CSR_LSION_MASK);
			}
		}
		else{
			/*Nothing*/
		}
	}
	return RET;
}
/*
 * @brief Configure the RCC presclares
 * @Param osc of RCC_ClkInitTypeDef type
 * */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *osc){
	HAL_StatusTypeDef RET = HAL_OK;
		if(NULL == osc){
			RET = HAL_ERROR;
		}
		else{
			MODIFY_REG(RCC->CFGR,RCC_AHB_PRESCALER_MASK,osc->AHBCLKDivider);
			MODIFY_REG(RCC->CFGR,RCC_APB_LOWSPEED_PRESCALER_MASK,osc->APB1CLKDivider);
			MODIFY_REG(RCC->CFGR,RCC_APB_HIGHSPEED_PRESCALER_MASK,osc->APB2CLKDivider);
		}
		return RET;
}
