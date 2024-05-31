/*
 * SCB_priv.h
 *
 *  Created on: May 27, 2024
 *      Author: user
 */

#ifndef SCB_PRIV_H_
#define SCB_PRIV_H_

#define MASKING_BIT                        1

#define VECT_KEY                          0x5FA

//SCB_ICSR

#define NMIPENDSET                         31
#define PENDSVSET                          28
#define PENDSVCLR                          27
#define PENDSTSET                          26
#define PENDSTCLR                          25
#define ISRPENDING                         22

// SCB_AIRCR
#define VECTKEYSTAT0                       16
#define PRIGROUP0                          8

#endif /* SCB_PRIV_H_ */
