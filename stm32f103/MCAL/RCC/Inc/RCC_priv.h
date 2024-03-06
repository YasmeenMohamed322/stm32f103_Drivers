/*
 * RCC_priv.h
 *
 *  Created on: Feb 14, 2024
 *      Author: user
 */

#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_



//Clock configuration
#define RCC_OFF             0
#define RCC_ON              1

#define RCC_HSI             0
#define RCC_HSE             1
#define RCC_PLL             2
#define RCC_SYSCLK          3
#define RCC_NOCLK           4

// HSE entry
#define HSE_NOT_DIVIDED     1
#define HSE_DIVIDED         2



//PLL sourse
#define HSI_OSC             0
#define HSE_OSC             1


#define RCC_MASKBIT         1

#define RCC_PLL_SHIFT       18


















































#endif /* RCC_PRIV_H_ */
