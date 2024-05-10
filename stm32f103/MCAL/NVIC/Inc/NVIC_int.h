/*
 * NVIC_int.h
 *
 *  Created on: May 9, 2024
 *      Author: user
 */


typedef enum {
	WWDG = 0,
	PVD,
	TAMPER,
	RTC,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Channel1,
	DMA1_Channel2,
	DMA1_Channel3,
	DMA1_Channel4,
	DMA1_Channel5,
	DMA1_Channel6,
	DMA1_Channel7
}NVIC_InterruptSources;

typedef enum {
	PLEVEL_0,
	PLEVEL_1 ,
	PLEVEL_2 ,
	PLEVEL_3 ,
	PLEVEL_4 ,
	PLEVEL_5 ,
	PLEVEL_6 ,
	PLEVEL_7 ,
	PLEVEL_8 ,
	PLEVEL_9 ,
	PLEVEL_10 ,
	PLEVEL_11 ,
	PLEVEL_12 ,
	PLEVEL_13 ,
	PLEVEL_14 ,
	PLEVEL_15
}Priority_levels;

#ifndef NVIC_INT_H_
#define NVIC_INT_H_

ES_t NVIC_enuSetEnable(u8 copy_u8IntSource);

ES_t NVIC_enuClearEnable(u8 copy_u8IntSource);

ES_t NVIC_enuSetPendingFlag(u8 copy_u8IntSource);

ES_t NVIC_enuClearPendingFlag(u8 copy_u8IntSource);

ES_t NVIC_enuReadActiveFalg(u8 copy_u8IntSource,u8* copy_u8ActivFlagVal);

ES_t NVIC_enuSetPriorityLevel(u8 copy_u8PriorityLevel,u8 copy_u8IntSource);

#endif /* NVIC_INT_H_ */
