/*
 * Common_Macros.h
 *
 *  Created on: Feb 9, 2025
 *      Author: Mohamed Tarek
 */

#ifndef COMMON_COMMON_MACROS_H_
#define COMMON_COMMON_MACROS_H_


#define SET_BIT(REG,BIT)				(REG |= BIT)
#define CLEAR_BIT(REG,BIT)				(REG &= ~BIT)
#define TOGGEL_BIT(REG,BIT)				(REG ^= BIT)
#define READ_REG(REG)					((REG))
#define WRITE_REG(REG,VAL)				((REG) = (VAL))
#define MODIFY_REG(REG,MASK,SETMASK)	WRITE_REG((REG),(((READ_REG(REG)) & (~(MASK))) | (SETMASK)))

#endif /* COMMON_COMMON_MACROS_H_ */
