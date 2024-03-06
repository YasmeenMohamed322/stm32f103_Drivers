/*
 * stm32f103.h
 *
 *  Created on: Mar 6, 2024
 *      Author: user
 */

#ifndef STM32F103_H_
#define STM32F103_H_

//RCC Registers
typedef struct{
	u8  RCC_CR;
	u8 RCC_CFGR;
	u8 RCC_CIR;
	u8 RCC_APB2RSTR;
	u8 RCC_APB1RSTR;
	u8 RCC_AHBENR;
	u8 RCC_APB2ENR;
	u8 RCC_APB1ENR;
	u8 RCC_BDCR;
	u8 RCC_CSR;
}RCC_REG;

RCC_REG * RCC = (RCC_REG*)(0x40021000);

//RCC_CR Register

#define RCC_PLL_RDY        25
#define RCC_PLL_ON         24
#define RCC_HSE_RDY        17
#define RCC_HSE_ON         16
#define RCC_HSI_RDY         1
#define RCC_HSI_ON          0

//RCC_CFGR register
#define RCC_PLLMUL_21    21
#define RCC_PLLMUL_20    20
#define RCC_PLLMUL_19    19
#define RCC_PLLMUL_18    18
#define RCC_PLLXTPRE     17
#define RCC_PLLSRC       16
#define RCC_SW_1          1
#define RCC_SW_0          0

//RCC_AHBENR register
#define RCC_SDIOEN         10
#define RCC_FSMCEN         8
#define RCC_CRCEN          6
#define RCC_FLITFEN        4
#define RCC_SRAMEN         2
#define RCC_DMA2EN         1
#define RCC_DMA1EN         0

//RCC_APB2ENR
#define RCC_TIM11EN        21
#define RCC_TIM10EN        20
#define RCC_TIM9EN         19
#define RCC_ADC3EN         15
#define RCC_USART1EN       14
#define RCC_TIM8EN         13
#define RCC_SPI1EN         12
#define RCC_TIM1EN         11
#define RCC_ADC2EN         10
#define RCC_ADC1EN         9
#define RCC_IOPGEN         8
#define RCC_IOPFEN         7
#define RCC_IOPEEN         6
#define RCC_IOPDEN         5
#define RCC_IOPCEN         4
#define RCC_IOPBEN         3
#define RCC_IOPAEN         2
#define RCC_AFIOEN         0

//RCC_APB1ENR
#define RCC_DACEN          29
#define RCC_PWREN          28
#define RCC_BKPEN          27
#define RCC_CANEN          25
#define RCC_USBEN          23
#define RCC_I2C2EN         22
#define RCC_I2C1EN         21
#define RCC_UART5EN        20
#define RCC_UART4EN        19
#define RCC_USART3EN       18
#define RCC_USART2EN       17
#define RCC_SPI3EN         15
#define RCC_SPI2EN         14
#define RCC_WWDGEN         11
#define RCC_TIM14EN        8
#define RCC_TIM13EN        7
#define RCC_TIM12EN        6
#define RCC_TIM7EN         5
#define RCC_TIM6EN         4
#define RCC_TIM5EN         3
#define RCC_TIM4EN         2
#define RCC_TIM3EN         1
#define RCC_TIM2EN         0


#endif /* STM32F103_H_ */
