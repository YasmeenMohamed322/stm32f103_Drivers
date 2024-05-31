/*
 * NVIC_prog.c
 *
 *  Created on: May 9, 2024
 *      Author: user
 */
#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "../LIB/stm32f103.h"

#include "../Inc/NVIC_priv.h"

ES_t NVIC_enuSetEnable(u8 copy_u8IntSource)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (copy_u8IntSource < 68 && copy_u8IntSource >= 0 )
	{
		u8 Local_RegisterNum = copy_u8IntSource / 32;
		u8 Local_BitNum = copy_u8IntSource % 32;

		NVIC -> NVIC_ISER[Local_RegisterNum] = 1 << Local_BitNum;

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t NVIC_enuClearEnable(u8 copy_u8IntSource)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (copy_u8IntSource < 68 && copy_u8IntSource >= 0 )
	{
		u8 Local_RegisterNum = copy_u8IntSource / 32;
		u8 Local_BitNum = copy_u8IntSource % 32;

		NVIC -> NVIC_ICER[Local_RegisterNum] = 1 << Local_BitNum;

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}

ES_t NVIC_enuSetPendingFlag(u8 copy_u8IntSource)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (copy_u8IntSource < 68 && copy_u8IntSource >= 0 )
	{
		u8 Local_RegisterNum = copy_u8IntSource / 32;
		u8 Local_BitNum = copy_u8IntSource % 32;

		NVIC -> NVIC_ISPR[Local_RegisterNum] = 1 << Local_BitNum;

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t NVIC_enuClearPendingFlag(u8 copy_u8IntSource)
{
	ES_t Local_enuErrorState = ES_NOK;


	if (copy_u8IntSource < 68 && copy_u8IntSource >= 0 )
	{
		u8 Local_RegisterNum = copy_u8IntSource / 32;
		u8 Local_BitNum = copy_u8IntSource % 32;

		NVIC -> NVIC_ICPR[Local_RegisterNum] = 1 << Local_BitNum;

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t NVIC_enuReadActiveFalg(u8 copy_u8IntSource,u8* copy_u8ActivFlagVal)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (copy_u8IntSource < 68 && copy_u8IntSource >= 0 )
	{
		u8 Local_RegisterNum = copy_u8IntSource / 32;
		u8 Local_BitNum = copy_u8IntSource % 32;

		*copy_u8ActivFlagVal = ( ( NVIC -> NVIC_ICPR[Local_RegisterNum] >> Local_BitNum ) & 1 ) ;

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t NVIC_enuSetPriorityLevel(u8 copy_u8PriorityLevel,u8 copy_u8IntSource)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (copy_u8IntSource < 68 && copy_u8IntSource >= 0 && copy_u8PriorityLevel >= 0 && copy_u8PriorityLevel < 16)
		{
			u8 Local_RegisterNum = copy_u8IntSource / 4;
			u8 Local_ByteNum = copy_u8IntSource % 4;
           // SCB_AIRCR = 0x05FA0500;    //Group 3
            NVIC -> NVIC_ISPR[Local_RegisterNum] &= ~ (0b1111 << ((8 * Local_ByteNum) + 4 ));
            NVIC -> NVIC_ISPR[Local_RegisterNum] |= (copy_u8PriorityLevel << ((8 * Local_ByteNum) + 4 ));


		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}



	return Local_enuErrorState;
}
