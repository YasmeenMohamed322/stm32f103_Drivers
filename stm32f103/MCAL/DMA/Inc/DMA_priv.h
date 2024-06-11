/*
 * DMA_priv.h
 *
 *  Created on: Jun 10, 2024
 *      Author: user
 */

#ifndef DMA_PRIV_H_
#define DMA_PRIV_H_

#define MASKING_BIT        1

#define MIN_DATA_TRANSFERS 0

#define MAX_DATA_TRANSFERS 65535

//DMA_CCRX
#define MEM2MEM            14
#define PL                 12
#define MSIZE              10
#define PSIZE              8
#define MINC               7
#define PINC               6
#define CIRC               5
#define DIR                4
#define TEIE               3
#define HTIE               2
#define TCIE               1
#define EN                 0


#endif /* DMA_PRIV_H_ */
