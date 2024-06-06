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


static  void(*EXTI_pFun[16])(void*) = {NULL} ;
static  void * EXTI_param[16] = {NULL};

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

ES_t EXTI_enuCallBackFunction(void(*Copy_pvoidAppFun)(void*), void * Copy_pvoidAppparam,EXTI_InterruptLine InterruptLine)
{

	ES_t Local_enuErrorStates = ES_NOK;

	if(Copy_pvoidAppFun != NULL)
	{
		EXTI_pFun[InterruptLine] = Copy_pvoidAppFun;
		EXTI_param[InterruptLine] = Copy_pvoidAppparam ;
	}
	else
	{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;

}

void EXTI0_IRQHandler (void)
{
	EXTI_pFun[0](EXTI_param[0]);
}

void EXTI9_5_IRQHandler (void)
{
	if ((((EXTI -> EXTI_PR) >> EXTI5) & MASKING_BIT) == 1)
	{

		EXTI_pFun[5](EXTI_param[5]);

	}
	else if((((EXTI -> EXTI_PR) >> EXTI6) & MASKING_BIT) == 1)
	{
		EXTI_pFun[6](EXTI_param[6]);
	}
	else if((((EXTI -> EXTI_PR) >> EXTI7) & MASKING_BIT) == 1)
	{
		EXTI_pFun[7](EXTI_param[7]);
	}
	else if((((EXTI -> EXTI_PR) >> EXTI8) & MASKING_BIT) == 1)
	{
		EXTI_pFun[8](EXTI_param[8]);
	}
	else if((((EXTI -> EXTI_PR) >> EXTI9) & MASKING_BIT) == 1)
	{
		EXTI_pFun[9](EXTI_param[9]);
	}
}
