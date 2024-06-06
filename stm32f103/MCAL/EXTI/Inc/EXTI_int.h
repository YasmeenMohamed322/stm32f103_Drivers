/*
 * EXTI_int.h
 *
 *  Created on: Jun 6, 2024
 *      Author: user
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_


typedef enum{
    EXTI0 ,
	EXTI1 ,
	EXTI2 ,
	EXTI3 ,
	EXTI4 ,
	EXTI5 ,
	EXTI6 ,
	EXTI7 ,
	EXTI8 ,
	EXTI9 ,
	EXTI10 ,
	EXTI11 ,
	EXTI12 ,
	EXTI13 ,
	EXTI14 ,
	EXTI15 ,
	EXTI16 ,
	EXTI17 ,
	EXTI18 ,
	EXTI19 ,
}EXTI_InterruptLine;

typedef enum{
FALLING_EDGE,
RISING_EDGE
}EXTI_InterruptLineTrigger;

ES_t EXTI_enuEnableInterruptLine(EXTI_InterruptLine InterruptLine);

ES_t EXTI_enuDisableInterruptLine(EXTI_InterruptLine InterruptLine);

ES_t EXTI_enuEnableTrigger(EXTI_InterruptLineTrigger Trigger , EXTI_InterruptLine InterruptLine );

ES_t EXTI_enuDisableTrigger(EXTI_InterruptLineTrigger Trigger , EXTI_InterruptLine InterruptLine );

ES_t EXTI_enuReadPendingFlag(u8 *EXTI_pu8PendingFlagValue , EXTI_InterruptLine InterruptLine);

ES_t EXTI_enuClearPendingFlag(EXTI_InterruptLine InterruptLine);

#endif /* EXTI_INT_H_ */
