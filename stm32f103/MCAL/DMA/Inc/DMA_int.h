/*
 * DMA_int.h
 *
 *  Created on: Jun 10, 2024
 *      Author: user
 */

#ifndef DMA_INT_H_
#define DMA_INT_H_



typedef enum{
	Channel_1 ,
	Channel_2 ,
	Channel_3 ,
	Channel_4 ,
	Channel_5 ,
	Channel_6 ,
	Channel_7
}DMA_Channels;


typedef enum{
	MEM2ME_MODE,
	PRE2MEM_MODE,
	MEM2PRE_MODE,
}DMA_Mode;

typedef enum{
	Low,
	Medium,
	High,
	VeryHigh
}DMA_PriorityLevel;

typedef enum{
	MEMBits_8,
	MEMBits_16,
	MEMBits_32
}DMA_MEMDataSize;

typedef enum{
	PREBits_8,
	PREBits_16,
	PREBits_32
}DMA_PREDataSize;

typedef enum{
	MEMDisabled,
	MEMEnabled
}DMA_MEMIncrementMode;

typedef enum{
	PERDisabled,
	PEREnabled
}DMA_PREIncrementMode;

typedef enum{
	HALFDisabled,
	HALFEnabled
}DMA_HalfTransferINT;

typedef enum{
	COMPDisabled,
	COMPEnabled
}DMA_CompleteTransferINT;

typedef struct{
	DMA_Channels Channel;
	DMA_Mode Mode;
	DMA_PriorityLevel PriorityLevel;
	DMA_MEMDataSize MEMDataSize;
	DMA_PREDataSize PREDataSize;
	DMA_MEMIncrementMode MEMIncrementMode;
	DMA_PREIncrementMode PREIncrementMode;
	DMA_HalfTransferINT HalfTransferINT;
	DMA_CompleteTransferINT CompleteTransferINT;
}DMA_Config_t;


ES_t DMA_enuConfigureChannel(DMA_Config_t* Copy_pstrDMAConfig);

ES_t DMA_enuStartTransfer(DMA_Channels Copy_enuChannelNum ,DMA_Mode DMAMode, u32 Copy_u32SrcAddress, u32 Copy_u32DestAddress, u32 Copy_u32Transfersnum );

#endif /* DMA_INT_H_ */
