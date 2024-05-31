/*
 * SCB_prog.c
 *
 *  Created on: May 27, 2024
 *      Author: user
 */


#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "../LIB/stm32f103.h"

#include "../Inc/SCB_priv.h"
#include "../Inc/SCB_int.h"

ES_t SCB_enuSetNMIPendingFlag(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SCB -> SCB_ICSR |= (MASKING_BIT << NMIPENDSET);

	return Local_enuErrorState;
}

ES_t SCB_enuSetSVPendingFlag(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SCB -> SCB_ICSR |= (MASKING_BIT << PENDSVSET);

	return Local_enuErrorState;
}
ES_t SCB_enuClearSVPendingFlag(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SCB -> SCB_ICSR |= (MASKING_BIT << PENDSVCLR);

	return Local_enuErrorState;
}
ES_t SCB_enuSetSYSTICKPendingFlag(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SCB -> SCB_ICSR |= (MASKING_BIT << PENDSTSET);

	return Local_enuErrorState;
}
ES_t SCB_enuClearSYSTICKPendingFlag(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SCB -> SCB_ICSR |= (MASKING_BIT << PENDSTCLR);

	return Local_enuErrorState;
}


ES_t SCB_enuReadNMIPendingFlag(u8* Copy_Pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	*Copy_Pu8Value = (((SCB->SCB_ICSR) >> NMIPENDSET ) & 1) ;

	return Local_enuErrorState;
}
ES_t SCB_enuReadSVSPendingFlag(u8* Copy_Pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	*Copy_Pu8Value = (((SCB->SCB_ICSR) >> PENDSVSET ) & 1) ;

	return Local_enuErrorState;
}

ES_t SCB_enuReadSTPendingFlag(u8* Copy_Pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	*Copy_Pu8Value = (((SCB->SCB_ICSR) >> PENDSTSET ) & 1) ;

	return Local_enuErrorState;
}

ES_t SCB_enuReadInterruptPendingFlag(u8* Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	*Copy_pu8Value = (((SCB->SCB_ICSR) >> ISRPENDING ) & 1) ;

	return Local_enuErrorState;
}

ES_t SCB_enuSetInterruptPriorityGroup(SCB_PRIGROUP Copy_enuInterruptGroupPriority )
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_enuInterruptGroupPriority <= PRI_GROUP7 && Copy_enuInterruptGroupPriority >= PRI_GROUP3)
	{
		u32 Local_u32PriGroup = (VECT_KEY << VECTKEYSTAT0);

		Local_u32PriGroup |= (Copy_enuInterruptGroupPriority << PRIGROUP0);

		SCB -> SCB_AIRCR = Local_u32PriGroup ;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t SCB_enuSetExceptionsPriority(SCB_EXCEPTIONS Copy_enuException,SCB_HANDLERS_PRIORITY Copy_enuFaultHandlerPriority )
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_enuException <= SYSTICK_EXC && Copy_enuException >= MEM_MANAGEMENT_FAULT)
	{
			if (Copy_enuFaultHandlerPriority <= PRI_15 && Copy_enuFaultHandlerPriority >= PRI_0)
			{
			u8 Local_u8RegNum = (Copy_enuException / 4) - 1; // index of system handler priority register
			u8 Local_u8ByteNum = Copy_enuException % 4;

			SCB->SCB_SHPR[Local_u8RegNum] &= ~ (0b1111 << ((8 * Local_u8ByteNum) + 4 ));
			SCB->SCB_SHPR[Local_u8RegNum] |=  (Copy_enuFaultHandlerPriority << ((8 * Local_u8ByteNum) + 4 ));
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
