/*
 * SysTick_int.h
 *
 *  Created on: May 5, 2024
 *      Author: user
 */

#ifndef SYSTICK_INT_H_
#define SYSTICK_INT_H_

typedef enum{
	AHB_CLOCK_DIVISED_BY_8,
	AHB_CLOCK
}CLKSOURCE;



ES_t SYSTICK_enuInit(u8 copy_u8ClkSource);

ES_t SYSTICK_enuSychDelay(u32 copy_u32Tick);






#endif /* SYSTICK_INT_H_ */
