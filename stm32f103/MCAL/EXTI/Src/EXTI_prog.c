/*
 * EXTI_prog.c
 *
 *  Created on: Jun 6, 2024
 *      Author: user
 */
#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "../LIB/stm32f103.h"

#include "../Inc/EXTI_priv.h"
#include "../Inc/EXTI_int.h"

ES_t EXTI_enuEnableInterruptLine(EXTI_InterruptLine InterruptLine)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(InterruptLine >= EXTI0 && InterruptLine <= EXTI19)
	{
		EXTI ->EXTI_IMR |= (MASKING_BIT << InterruptLine);
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}

ES_t EXTI_enuDisableInterruptLine(EXTI_InterruptLine InterruptLine)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(InterruptLine >= EXTI0 && InterruptLine <= EXTI19)
	{
		EXTI ->EXTI_IMR &= ~ (MASKING_BIT << InterruptLine);
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}

ES_t EXTI_enuEnableTrigger(EXTI_InterruptLineTrigger Trigger , EXTI_InterruptLine InterruptLine)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(InterruptLine >= EXTI0 && InterruptLine <= EXTI19)
	{

		if(Trigger == RISING_EDGE)
		{
			EXTI -> EXTI_RTSR |= (MASKING_BIT << InterruptLine);
		}
		else if(Trigger == FALLING_EDGE)
		{
			EXTI -> EXTI_FTSR |= (MASKING_BIT << InterruptLine);
		}
		else
		{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}

ES_t EXTI_enuDisableTrigger(EXTI_InterruptLineTrigger Trigger , EXTI_InterruptLine InterruptLine )
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(InterruptLine >= EXTI0 && InterruptLine <= EXTI19)
	{

		if(Trigger == RISING_EDGE)
		{
			EXTI -> EXTI_RTSR &= ~ (MASKING_BIT << InterruptLine);
		}
		else if(Trigger == FALLING_EDGE)
		{
			EXTI -> EXTI_FTSR &= ~ (MASKING_BIT << InterruptLine);
		}
		else
		{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}

ES_t EXTI_enuReadPendingFlag(u8 *EXTI_pu8PendingFlagValue, EXTI_InterruptLine InterruptLine)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(InterruptLine >= EXTI0 && InterruptLine <= EXTI19)
	{
		*EXTI_pu8PendingFlagValue = (((EXTI -> EXTI_PR) >> InterruptLine ) & MASKING_BIT);
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}

ES_t EXTI_enuClearPendingFlag(EXTI_InterruptLine InterruptLine)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(InterruptLine >= EXTI0 && InterruptLine <= EXTI19)
	{
		EXTI -> EXTI_PR |= (MASKING_BIT << InterruptLine);
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}
