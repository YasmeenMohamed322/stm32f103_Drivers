/*
 * RCC_int.h
 *
 *  Created on: Feb 14, 2024
 *      Author: user
 */

#ifndef RCC_INT_H_
#define RCC_INT_H_

//clock Type
typedef enum{
	RCC_HSI,
	RCC_HSE,
	RCC_PLL,
	RCC_SYSCLK,
	RCC_NOCLK
}CLKType_t;

//clock status
typedef enum{
	RCC_OFF,
	RCC_ON
}CLKStatus_t;

//HSE entry
typedef enum {
	HSE_NOT_DIVIDED,
	HSE_DIVIDED
}HSEentry_t;

//PLL multiplication factor
typedef enum{
	MUL_2,
	MUL_3 ,
	MUL_4 ,
	MUL_5 ,
	MUL_6 ,
	MUL_7 ,
	MUL_8 ,
	MUL_9 ,
	MUL_10,
	MUL_11,
	MUL_12,
	MUL_13,
	MUL_14,
	MUL_15,
	MUL_16
}PLLfactor_t;

//PLL source
typedef enum{
	 HSI_OSC,
	 HSE_OSC
}PLLsource_t;

//AHB peripherals
typedef enum{
	SDIO = 10,
	FSMC = 8,
	CRC  = 6,
	FLITF= 4,
	SRAM = 2,
	DMA2 = 1,
	DMA1 = 0
}AHBperipherals_t;

//APB2 Peripherals
typedef enum{
	TIM11 = 21,
	TIM10 = 20,
	TIM9  = 19,
	ADC3  = 15,
	USART1= 14,
	TIM8  = 13,
	SPI1  = 12,
	TIM1  = 11,
	ADC2  = 10,
	ADC1  = 9,
	IOPG  = 8,
	IOPF  = 7,
	IOPE  = 6,
	IOPD  = 5,
	IOPC  = 4,
	IOPB  = 3,
	IOPA  = 2,
	AFIO  = 0
}APB2peripherals_t;

//APB1 Peripherals
typedef enum{
	DAC   =29,
	PWR   =28,
	PKP   =27,
	CAN   =25,
	USB   =23,
	I2C2  =22,
	I2C1  =21,
	UART5 =20,
	UART4 =19,
	USART3=18,
	USART2=17,
	SPI3  =15,
	SPI2  =14,
	WWD   =11,
	TIM14 =8,
	TIM13 =7,
	TIM12 =6,
	TIM7  =5,
	TIM6  =4,
	TIM5  =3,
	TIM4  =2,
	TIM3  =1,
	TIM2  =0
};

ES_t RCC_enuSetClkStatus(u8 copy_u8ClkType,u8 copy_u8ClkStatus);

ES_t RCC_enuSetSysClock(u8 copy_u8ClkType);

ES_t RCC_enuHSEConfig(u8 copy_u8PllEntry);

ES_t RCC_enuPllConfig(u8 copy_u8PllMul,u8 copy_u8PllSource);

ES_t RCC_enuAHB_EnableClock(u8 copy_u8AHBPeripheral);

ES_t RCC_enuAHB_DisableClock(u8 copy_u8AHBPeripheral);

ES_t RCC_enuAPB1_EnableClock(u8 copy_u8APB1Peripheral);

ES_t RCC_enuAPB1_DisableClock(u8 copy_u8APB1Peripheral);

ES_t RCC_enuAPB2_EnableClock(u8 copy_u8APB2Peripheral);

ES_t RCC_enuAPB2_DisableClock(u8 copy_u8APB2Peripheral);



#endif /* RCC_INT_H_ */
