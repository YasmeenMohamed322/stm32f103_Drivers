/*
 * AFIO_int.h
 *
 *  Created on: Jun 9, 2024
 *      Author: user
 */

#ifndef AFIO_INT_H_
#define AFIO_INT_H_

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
	EXTI15
}InterruptLine;

typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F,
	PORT_G
}PORT_ID;


ES_t AFIO_enuEXTIConfig(InterruptLine Copy_enuInterruptLine, PORT_ID Copy_enuPortID );

#endif /* AFIO_INT_H_ */
