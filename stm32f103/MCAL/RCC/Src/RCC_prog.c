/*
 * RCC_prog.c
 *
 *  Created on: Feb 14, 2024
 *      Author: user
 */
#include "../LIB/stdTypes.h"
#include "../LIB/stm32f103.h"
#include "../LIB/errorStates.h"

#include "../Inc/RCC_priv.h"


ES_t RCC_enuSetClkStatus(u8 copy_u8ClkType,u8 copy_u8ClkStatus)
{
    ES_t Local_enuErrorState = ES_NOK;

#if copy_u8ClkType == RCC_PLL
#if copy_u8ClkStatus == RCC_ON
    // if pll status is on set the PLLON bit
    RCC -> RCC_CR |= (RCC_MASKBIT << RCC_PLL_ON);
#elif copy_u8ClkStatus == RCC_OFF
    // if pll status is off clear the PLLON bit
	RCC -> RCC_CR &= ~ (RCC_MASKBIT << RCC_PLL_ON);
#endif

#elif copy_u8ClkType == RCC_HSE
#if copy_u8ClkStatus == RCC_ON
	// if HSE status is on set the HSEON bit
    RCC -> RCC_CR |= (RCC_MASKBIT << RCC_HSE_ON);
#elif copy_u8ClkStatus == RCC_OFF
    // if pll status is off clear the HSEON bit
	RCC -> RCC_CR &= ~ (RCC_MASKBIT << RCC_HSE_ON);
#endif

#elif copy_u8ClkType == RCC_HSI
#if copy_u8ClkStatus == RCC_ON
	// if HSE status is on set the HSION bit
    RCC -> RCC_CR |= (RCC_MASKBIT << RCC_HSI_ON);
#elif copy_u8ClkStatus == RCC_OFF
    // if pll status is off clear the HSION bit
	RCC -> RCC_CR &= ~ (RCC_MASKBIT << RCC_HSI_ON);
#endif
#endif

    return Local_enuErrorState;
}

ES_t RCC_enuSetSysClock(u8 copy_u8ClkType)
{
    ES_t Local_enuErrorState = ES_NOK;

    if(copy_u8ClkType == RCC_PLL )
    {
    	// Set PLL on bit
    	 RCC -> RCC_CR |= (RCC_MASKBIT << RCC_PLL_ON);
    	// waiting for the hardware to sit the bit to indicate that PLL is ready
    	while(! ( ( (RCC -> RCC_CR ) >> RCC_PLL_RDY ) & RCC_MASKBIT ) );
    	// setting system clock as pll
    	RCC -> RCC_CFGR |= (RCC_MASKBIT<<RCC_SW_1);
    	RCC -> RCC_CFGR &= ~ (RCC_MASKBIT<<RCC_SW_0);

    }

    else if(copy_u8ClkType == RCC_HSE )
    {
    	// set HSE on bit
    	 RCC -> RCC_CR |= (RCC_MASKBIT << RCC_HSE_ON);
    	// waiting for the hardware to sit the bit to indicate that HSE is ready
    	while(! ( ( (RCC -> RCC_CR ) >> RCC_HSE_RDY ) & RCC_MASKBIT ) );
    	// setting system clock as HSE
    	RCC -> RCC_CFGR &= ~ (RCC_MASKBIT<<RCC_SW_1);
    	RCC -> RCC_CFGR |= (RCC_MASKBIT<<RCC_SW_0);

    }

    else if(copy_u8ClkType == RCC_HSI )
    {
    	// set HSI on bit
    	RCC -> RCC_CR |= (RCC_MASKBIT << RCC_HSI_ON);
    	// waiting for the hardware to sit the bit to indicate that HSI is ready
    	while(! ( ( (RCC -> RCC_CR ) >> RCC_HSI_RDY ) & RCC_MASKBIT ) );
    	// setting system clock as HSI
    	RCC -> RCC_CFGR &= ~ (RCC_MASKBIT<<RCC_SW_1);
    	RCC -> RCC_CFGR &= ~ (RCC_MASKBIT<<RCC_SW_0);

    }


    return Local_enuErrorState;
}

ES_t RCC_enuHSEConfig(u8 copy_u8PllEntry)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(copy_u8PllEntry == HSE_NOT_DIVIDED)
	{
		RCC -> RCC_CFGR &= ~ (RCC_MASKBIT << RCC_PLLXTPRE);
	}

	else if(copy_u8PllEntry == HSE_DIVIDED)
	{
		RCC -> RCC_CFGR |= (RCC_MASKBIT << RCC_PLLXTPRE);
	}
	return Local_enuErrorState;
}

ES_t RCC_enuPllConfig(u8 copy_u8PllMul,u8 copy_u8PllSource)
{
	ES_t Local_enuErrorState = ES_NOK;

//setting pll multiplication factor
RCC->RCC_CFGR = (RCC ->RCC_CFGR & 0xFFC3FFFF )|(copy_u8PllMul << RCC_PLL_SHIFT);

	//choose entry clock source for pll
#if PLL_SOURCE == HSI_OSC
	RCC -> RCC_CFGR &= ~ (RCC_MASKBIT << RCC_PLLSRC);
#elif PLL_SOURCE == HSE_OSC
	RCC -> RCC_CFGR |= (RCC_MASKBIT << RCC_PLLSRC);
#endif
	return Local_enuErrorState;
}

ES_t RCC_enuAHB_EnableClock(u8 copy_u8AHBPeripheral)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_AHBENR |= (RCC_MASKBIT << copy_u8AHBPeripheral);

	return Local_enuErrorState;
}

ES_t RCC_enuAHB_DisableClock(u8 copy_u8AHBPeripheral)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_AHBENR &= ~(RCC_MASKBIT << copy_u8AHBPeripheral);
	return Local_enuErrorState;
}

ES_t RCC_enuAPB1_EnableClock(u8 copy_u8APB1Peripheral)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC -> RCC_APB1ENR |= (RCC_MASKBIT << copy_u8APB1Peripheral);

	return Local_enuErrorState;
}

ES_t RCC_enuAPB1_DisableClock(u8 copy_u8APB1Peripheral)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC -> RCC_APB1ENR &= ~ (RCC_MASKBIT << copy_u8APB1Peripheral);

	return Local_enuErrorState;
}

ES_t RCC_enuAPB2_EnableClock(u8 copy_u8APB2Peripheral)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC -> RCC_APB2ENR |= (RCC_MASKBIT << copy_u8APB2Peripheral);

	return Local_enuErrorState;
}

ES_t RCC_enuAPB2_DisableClock(u8 copy_u8APB2Peripheral)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC -> RCC_APB2ENR &= ~ (RCC_MASKBIT << copy_u8APB2Peripheral);

	return Local_enuErrorState;
}
