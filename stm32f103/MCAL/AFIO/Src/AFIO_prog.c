/*
 * AFIO_prog.c
 *
 *  Created on: Jun 9, 2024
 *      Author: user
 */

#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "../LIB/stm32f103.h"

#include "../Inc/AFIO_priv.h"
#include "../Inc/AFIO_int.h"


ES_t AFIO_enuEXTIConfig(InterruptLine Copy_enuInterruptLine, PORT_ID Copy_enuPortID )
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8RegNum = Copy_enuInterruptLine / 4;
	u8 Local_u8BitNum = Copy_enuInterruptLine % 4;

	if (Copy_enuInterruptLine >= EXTI0 && Copy_enuInterruptLine <= EXTI15)
	{
		AFIO -> AFIO_EXTICR[Local_u8RegNum] &= ~ (INT_MASKING << (Local_u8BitNum *4));
		AFIO -> AFIO_EXTICR[Local_u8RegNum] |= (Copy_enuPortID << (Local_u8BitNum *4));
	}

	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}
