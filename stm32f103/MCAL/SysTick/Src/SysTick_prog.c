/*
 * SysTick_prog.c
 *
 *  Created on: May 5, 2024
 *      Author: user
 */
#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "../LIB/stm32f103.h"

#include "../Inc/SysTick_priv.h"


ES_t SYSTICK_enuInit(u8 copy_u8ClkSource)
{
	ES_t Local_enuErrorStates = ES_NOK;

	//Disable The systick

	SYSTICK -> SYST_CSR = 0;

	// check the clock source

	if(copy_u8ClkSource == SYSTICK_AHB_CLOCK_DIVISED_BY_8)
	{
		SYSTICK -> SYST_CSR &= ~ ( SYSTICK_MASK_BIT << CLKSOURCE);
	}

	else if(copy_u8ClkSource == SYSTICK_AHB_CLOCK)
	{
		SYSTICK -> SYST_CSR |= ( SYSTICK_MASK_BIT << CLKSOURCE);
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}


ES_t SYSTICK_enuDisableCounter(void)
{
	ES_t Local_enuErrorStates = ES_NOK;

	SYSTICK -> SYST_CSR &= ~ ( SYSTICK_MASK_BIT << ENABLE);

	return Local_enuErrorStates;

}

ES_t SYSTICK_enuSychDelay(u32 copy_u32Tick)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(copy_u32Tick <= 0x00ffffff)
	{
		//Load The value of ticks to Reload register
		SYSTICK -> SYST_RVR = copy_u32Tick;
		//Start the timer
		SYSTICK -> SYST_CSR |= (SYSTICK_MASK_BIT >> ENABLE );
		//Wait for flag
		while( !( ( ( SYSTICK -> SYST_CSR ) >> COUNTFLAG ) & SYSTICK_MASK_BIT ));

		//Disable timer
		SYSTICK -> SYST_CSR &= ~ (SYSTICK_MASK_BIT >> ENABLE );
		SYSTICK -> SYST_RVR = 0;
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}
