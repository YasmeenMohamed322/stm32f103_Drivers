/*
 * DMA_prog.c
 *
 *  Created on: Jun 10, 2024
 *      Author: user
 */
#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "../LIB/stm32f103.h"

#include "../Inc/DMA_priv.h"
#include "../Inc/DMA_int.h"

ES_t DMA_enuConfigureChannel(DMA_Config_t* Copy_pstrDMAConfig)
{
	ES_t Local_enuErrorState = ES_NOK;
	switch(Copy_pstrDMAConfig -> Channel){
	case Channel_1:
		//Disable Channel before configuring it
		DMA1->DMA_CCR1 &= ~(MASKING_BIT << EN);

		//COnfiuring priority,memory size and peripheral size,enable or disable increment mode and complete/half transfer interrupt
		DMA1->DMA_CCR1 |= ((Copy_pstrDMAConfig->PriorityLevel) << PL);
		DMA1->DMA_CCR1 |= ((Copy_pstrDMAConfig->MEMDataSize) << MSIZE );
		DMA1->DMA_CCR1 |= ((Copy_pstrDMAConfig->PREDataSize) << PSIZE);
		DMA1->DMA_CCR1 |= ((Copy_pstrDMAConfig->MEMIncrementMode) << MINC);
		DMA1->DMA_CCR1 |= ((Copy_pstrDMAConfig->PREIncrementMode) << PINC);
		DMA1->DMA_CCR1 |= ((Copy_pstrDMAConfig->HalfTransferINT) << HTIE);
		DMA1->DMA_CCR1 |= ((Copy_pstrDMAConfig->CompleteTransferINT) << TCIE);

		if(Copy_pstrDMAConfig->Mode == MEM2ME_MODE)
		{
			//enable mem2mem bit
			DMA1->DMA_CCR1 |= (MASKING_BIT << MEM2MEM);
		}
		else if(Copy_pstrDMAConfig->Mode == PRE2MEM_MODE)
		{
			// make the direction to read from peripheral
			DMA1->DMA_CCR1 &= ~(MASKING_BIT << DIR);
		}
		else if(Copy_pstrDMAConfig->Mode == MEM2PRE_MODE)
		{
			// make the direction to read from memory
			DMA1->DMA_CCR1 |= (MASKING_BIT << DIR);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		//enable the channel again
		DMA1->DMA_CCR1 |= (MASKING_BIT << EN);
		break;
	case Channel_2:
		//Disable Channel before configuring it
		DMA1->DMA_CCR2 &= ~(MASKING_BIT << EN);

		//COnfiuring priority,memory size and peripheral size,enable or disable increment mode and complete/half transfer interrupt
		DMA1->DMA_CCR2 |= ((Copy_pstrDMAConfig->PriorityLevel) << PL);
		DMA1->DMA_CCR2 |= ((Copy_pstrDMAConfig->MEMDataSize) << MSIZE );
		DMA1->DMA_CCR2 |= ((Copy_pstrDMAConfig->PREDataSize) << PSIZE);
		DMA1->DMA_CCR2 |= ((Copy_pstrDMAConfig->MEMIncrementMode) << MINC);
		DMA1->DMA_CCR2 |= ((Copy_pstrDMAConfig->PREIncrementMode) << PINC);
		DMA1->DMA_CCR2 |= ((Copy_pstrDMAConfig->HalfTransferINT) << HTIE);
		DMA1->DMA_CCR2 |= ((Copy_pstrDMAConfig->CompleteTransferINT) << TCIE);

		if(Copy_pstrDMAConfig->Mode == MEM2ME_MODE)
		{
			//enable mem2mem bit
			DMA1->DMA_CCR2 |= (MASKING_BIT << MEM2MEM);
		}
		else if(Copy_pstrDMAConfig->Mode == PRE2MEM_MODE)
		{
			// make the direction to read from peripheral
			DMA1->DMA_CCR2 &= ~(MASKING_BIT << DIR);
		}
		else if(Copy_pstrDMAConfig->Mode == MEM2PRE_MODE)
		{
			// make the direction to read from memory
			DMA1->DMA_CCR2 |= (MASKING_BIT << DIR);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		//enable the channel again
		DMA1->DMA_CCR2 |= (MASKING_BIT << EN);

		break;
	case Channel_3:
		//Disable Channel before configuring it
		DMA1->DMA_CCR3 &= ~(MASKING_BIT << EN);

		//COnfiuring priority,memory size and peripheral size,enable or disable increment mode and complete/half transfer interrupt
		DMA1->DMA_CCR3 |= ((Copy_pstrDMAConfig->PriorityLevel) << PL);
		DMA1->DMA_CCR3 |= ((Copy_pstrDMAConfig->MEMDataSize) << MSIZE );
		DMA1->DMA_CCR3 |= ((Copy_pstrDMAConfig->PREDataSize) << PSIZE);
		DMA1->DMA_CCR3 |= ((Copy_pstrDMAConfig->MEMIncrementMode) << MINC);
		DMA1->DMA_CCR3 |= ((Copy_pstrDMAConfig->PREIncrementMode) << PINC);
		DMA1->DMA_CCR3 |= ((Copy_pstrDMAConfig->HalfTransferINT) << HTIE);
		DMA1->DMA_CCR3 |= ((Copy_pstrDMAConfig->CompleteTransferINT) << TCIE);

		if(Copy_pstrDMAConfig->Mode == MEM2ME_MODE)
		{
			//enable mem2mem bit
			DMA1->DMA_CCR3 |= (MASKING_BIT << MEM2MEM);
		}
		else if(Copy_pstrDMAConfig->Mode == PRE2MEM_MODE)
		{
			// make the direction to read from peripheral
			DMA1->DMA_CCR3 &= ~(MASKING_BIT << DIR);
		}
		else if(Copy_pstrDMAConfig->Mode == MEM2PRE_MODE)
		{
			// make the direction to read from memory
			DMA1->DMA_CCR3 |= (MASKING_BIT << DIR);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		//enable the channel again
		DMA1->DMA_CCR3 |= (MASKING_BIT << EN);

		break;
	case Channel_4:
		//Disable Channel before configuring it
		DMA1->DMA_CCR4 &= ~(MASKING_BIT << EN);

		//COnfiuring priority,memory size and peripheral size,enable or disable increment mode and complete/half transfer interrupt
		DMA1->DMA_CCR4 |= ((Copy_pstrDMAConfig->PriorityLevel) << PL);
		DMA1->DMA_CCR4 |= ((Copy_pstrDMAConfig->MEMDataSize) << MSIZE );
		DMA1->DMA_CCR4 |= ((Copy_pstrDMAConfig->PREDataSize) << PSIZE);
		DMA1->DMA_CCR4 |= ((Copy_pstrDMAConfig->MEMIncrementMode) << MINC);
		DMA1->DMA_CCR4 |= ((Copy_pstrDMAConfig->PREIncrementMode) << PINC);
		DMA1->DMA_CCR4 |= ((Copy_pstrDMAConfig->HalfTransferINT) << HTIE);
		DMA1->DMA_CCR4 |= ((Copy_pstrDMAConfig->CompleteTransferINT) << TCIE);

		if(Copy_pstrDMAConfig->Mode == MEM2ME_MODE)
		{
			//enable mem2mem bit
			DMA1->DMA_CCR4 |= (MASKING_BIT << MEM2MEM);
		}
		else if(Copy_pstrDMAConfig->Mode == PRE2MEM_MODE)
		{
			// make the direction to read from peripheral
			DMA1->DMA_CCR4 &= ~(MASKING_BIT << DIR);
		}
		else if(Copy_pstrDMAConfig->Mode == MEM2PRE_MODE)
		{
			// make the direction to read from memory
			DMA1->DMA_CCR4 |= (MASKING_BIT << DIR);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		//enable the channel again
		DMA1->DMA_CCR4 |= (MASKING_BIT << EN);

		break;
	case Channel_5:
		//Disable Channel before configuring it
		DMA1->DMA_CCR5 &= ~(MASKING_BIT << EN);

		//COnfiuring priority,memory size and peripheral size,enable or disable increment mode and complete/half transfer interrupt
		DMA1->DMA_CCR5 |= ((Copy_pstrDMAConfig->PriorityLevel) << PL);
		DMA1->DMA_CCR5 |= ((Copy_pstrDMAConfig->MEMDataSize) << MSIZE );
		DMA1->DMA_CCR5 |= ((Copy_pstrDMAConfig->PREDataSize) << PSIZE);
		DMA1->DMA_CCR5 |= ((Copy_pstrDMAConfig->MEMIncrementMode) << MINC);
		DMA1->DMA_CCR5 |= ((Copy_pstrDMAConfig->PREIncrementMode) << PINC);
		DMA1->DMA_CCR5 |= ((Copy_pstrDMAConfig->HalfTransferINT) << HTIE);
		DMA1->DMA_CCR5 |= ((Copy_pstrDMAConfig->CompleteTransferINT) << TCIE);

		if(Copy_pstrDMAConfig->Mode == MEM2ME_MODE)
		{
			//enable mem2mem bit
			DMA1->DMA_CCR5 |= (MASKING_BIT << MEM2MEM);
		}
		else if(Copy_pstrDMAConfig->Mode == PRE2MEM_MODE)
		{
			// make the direction to read from peripheral
			DMA1->DMA_CCR5 &= ~(MASKING_BIT << DIR);
		}
		else if(Copy_pstrDMAConfig->Mode == MEM2PRE_MODE)
		{
			// make the direction to read from memory
			DMA1->DMA_CCR5 |= (MASKING_BIT << DIR);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		//enable the channel again
		DMA1->DMA_CCR5 |= (MASKING_BIT << EN);

		break;
	case Channel_6:
		//Disable Channel before configuring it
		DMA1->DMA_CCR6 &= ~(MASKING_BIT << EN);

		//COnfiuring priority,memory size and peripheral size,enable or disable increment mode and complete/half transfer interrupt
		DMA1->DMA_CCR6 |= ((Copy_pstrDMAConfig->PriorityLevel) << PL);
		DMA1->DMA_CCR6 |= ((Copy_pstrDMAConfig->MEMDataSize) << MSIZE );
		DMA1->DMA_CCR6 |= ((Copy_pstrDMAConfig->PREDataSize) << PSIZE);
		DMA1->DMA_CCR6 |= ((Copy_pstrDMAConfig->MEMIncrementMode) << MINC);
		DMA1->DMA_CCR6 |= ((Copy_pstrDMAConfig->PREIncrementMode) << PINC);
		DMA1->DMA_CCR6 |= ((Copy_pstrDMAConfig->HalfTransferINT) << HTIE);
		DMA1->DMA_CCR6 |= ((Copy_pstrDMAConfig->CompleteTransferINT) << TCIE);

		if(Copy_pstrDMAConfig->Mode == MEM2ME_MODE)
		{
			//enable mem2mem bit
			DMA1->DMA_CCR6 |= (MASKING_BIT << MEM2MEM);
		}
		else if(Copy_pstrDMAConfig->Mode == PRE2MEM_MODE)
		{
			// make the direction to read from peripheral
			DMA1->DMA_CCR6 &= ~(MASKING_BIT << DIR);
		}
		else if(Copy_pstrDMAConfig->Mode == MEM2PRE_MODE)
		{
			// make the direction to read from memory
			DMA1->DMA_CCR6 |= (MASKING_BIT << DIR);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		//enable the channel again
		DMA1->DMA_CCR6 |= (MASKING_BIT << EN);

		break;
	case Channel_7:
		//Disable Channel before configuring it
		DMA1->DMA_CCR7 &= ~(MASKING_BIT << EN);

		//COnfiuring priority,memory size and peripheral size,enable or disable increment mode and complete/half transfer interrupt
		DMA1->DMA_CCR7 |= ((Copy_pstrDMAConfig->PriorityLevel) << PL);
		DMA1->DMA_CCR7 |= ((Copy_pstrDMAConfig->MEMDataSize) << MSIZE );
		DMA1->DMA_CCR7 |= ((Copy_pstrDMAConfig->PREDataSize) << PSIZE);
		DMA1->DMA_CCR7 |= ((Copy_pstrDMAConfig->MEMIncrementMode) << MINC);
		DMA1->DMA_CCR7 |= ((Copy_pstrDMAConfig->PREIncrementMode) << PINC);
		DMA1->DMA_CCR7 |= ((Copy_pstrDMAConfig->HalfTransferINT) << HTIE);
		DMA1->DMA_CCR7 |= ((Copy_pstrDMAConfig->CompleteTransferINT) << TCIE);

		if(Copy_pstrDMAConfig->Mode == MEM2ME_MODE)
		{
			//enable mem2mem bit
			DMA1->DMA_CCR7 |= (MASKING_BIT << MEM2MEM);
		}
		else if(Copy_pstrDMAConfig->Mode == PRE2MEM_MODE)
		{
			// make the direction to read from peripheral
			DMA1->DMA_CCR7 &= ~(MASKING_BIT << DIR);
		}
		else if(Copy_pstrDMAConfig->Mode == MEM2PRE_MODE)
		{
			// make the direction to read from memory
			DMA1->DMA_CCR7 |= (MASKING_BIT << DIR);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		//enable the channel again
		DMA1->DMA_CCR7 |= (MASKING_BIT << EN);
		break;
	default: Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t DMA_enuStartTransfer(DMA_Channels Copy_enuChannelNum ,DMA_Mode DMAMode, u32 Copy_u32SrcAddress, u32 Copy_u32DestAddress, u32 Copy_u32Transfersnum )
{
	ES_t Local_enuErrorState = ES_NOK;

	switch(Copy_enuChannelNum)
	{
	case Channel_1:
		DMA1->DMA_CCR1 &= ~ (MASKING_BIT << EN);

		if(Copy_u32Transfersnum >= MIN_DATA_TRANSFERS && Copy_u32Transfersnum <= MAX_DATA_TRANSFERS)
		{
			DMA1->DMA_CNDTR1 = Copy_u32Transfersnum;

			if(DMAMode == MEM2ME_MODE || DMAMode == MEM2PRE_MODE)
			{
				DMA1->DMA_CMAR1 = Copy_u32SrcAddress;
				DMA1->DMA_CPAR1 = Copy_u32DestAddress;
			}
			else if(DMAMode == PRE2MEM_MODE)
			{
				DMA1->DMA_CPAR1 = Copy_u32SrcAddress;
				DMA1->DMA_CMAR1 = Copy_u32DestAddress;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		DMA1->DMA_CCR1 |= (MASKING_BIT << EN);
		break;
	case Channel_2:
		DMA1->DMA_CCR2 &= ~ (MASKING_BIT << EN);

		if(Copy_u32Transfersnum >= MIN_DATA_TRANSFERS && Copy_u32Transfersnum <= MAX_DATA_TRANSFERS)
		{
			DMA1->DMA_CNDTR2 = Copy_u32Transfersnum;

			if(DMAMode == MEM2ME_MODE || DMAMode == MEM2PRE_MODE)
			{
				DMA1->DMA_CMAR2 = Copy_u32SrcAddress;
				DMA1->DMA_CPAR2 = Copy_u32DestAddress;
			}
			else if(DMAMode == PRE2MEM_MODE)
			{
				DMA1->DMA_CPAR2 = Copy_u32SrcAddress;
				DMA1->DMA_CMAR2 = Copy_u32DestAddress;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		DMA1->DMA_CCR2 |= (MASKING_BIT << EN);
		break;
	case Channel_3:
		DMA1->DMA_CCR3 &= ~ (MASKING_BIT << EN);

		if(Copy_u32Transfersnum >= MIN_DATA_TRANSFERS && Copy_u32Transfersnum <= MAX_DATA_TRANSFERS)
		{
			DMA1->DMA_CNDTR3 = Copy_u32Transfersnum;

			if(DMAMode == MEM2ME_MODE || DMAMode == MEM2PRE_MODE)
			{
				DMA1->DMA_CMAR3 = Copy_u32SrcAddress;
				DMA1->DMA_CPAR3 = Copy_u32DestAddress;
			}
			else if(DMAMode == PRE2MEM_MODE)
			{
				DMA1->DMA_CPAR3 = Copy_u32SrcAddress;
				DMA1->DMA_CMAR3 = Copy_u32DestAddress;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		DMA1->DMA_CCR3 |= (MASKING_BIT << EN);
		break;
	case Channel_4:
		DMA1->DMA_CCR4 &= ~ (MASKING_BIT << EN);

		if(Copy_u32Transfersnum >= MIN_DATA_TRANSFERS && Copy_u32Transfersnum <= MAX_DATA_TRANSFERS)
		{
			DMA1->DMA_CNDTR4 = Copy_u32Transfersnum;

			if(DMAMode == MEM2ME_MODE || DMAMode == MEM2PRE_MODE)
			{
				DMA1->DMA_CMAR4 = Copy_u32SrcAddress;
				DMA1->DMA_CPAR4 = Copy_u32DestAddress;
			}
			else if(DMAMode == PRE2MEM_MODE)
			{
				DMA1->DMA_CPAR4 = Copy_u32SrcAddress;
				DMA1->DMA_CMAR4 = Copy_u32DestAddress;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		DMA1->DMA_CCR4 |= (MASKING_BIT << EN);
		break;
	case Channel_5:
		DMA1->DMA_CCR5 &= ~ (MASKING_BIT << EN);

		if(Copy_u32Transfersnum >= MIN_DATA_TRANSFERS && Copy_u32Transfersnum <= MAX_DATA_TRANSFERS)
		{
			DMA1->DMA_CNDTR5 = Copy_u32Transfersnum;

			if(DMAMode == MEM2ME_MODE || DMAMode == MEM2PRE_MODE)
			{
				DMA1->DMA_CMAR5 = Copy_u32SrcAddress;
				DMA1->DMA_CPAR5 = Copy_u32DestAddress;
			}
			else if(DMAMode == PRE2MEM_MODE)
			{
				DMA1->DMA_CPAR5 = Copy_u32SrcAddress;
				DMA1->DMA_CMAR5 = Copy_u32DestAddress;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		DMA1->DMA_CCR5 |= (MASKING_BIT << EN);
		break;
	case Channel_6:
		DMA1->DMA_CCR6 &= ~ (MASKING_BIT << EN);

		if(Copy_u32Transfersnum >= MIN_DATA_TRANSFERS && Copy_u32Transfersnum <= MAX_DATA_TRANSFERS)
		{
			DMA1->DMA_CNDTR6 = Copy_u32Transfersnum;

			if(DMAMode == MEM2ME_MODE || DMAMode == MEM2PRE_MODE)
			{
				DMA1->DMA_CMAR6 = Copy_u32SrcAddress;
				DMA1->DMA_CPAR6 = Copy_u32DestAddress;
			}
			else if(DMAMode == PRE2MEM_MODE)
			{
				DMA1->DMA_CPAR6 = Copy_u32SrcAddress;
				DMA1->DMA_CMAR6 = Copy_u32DestAddress;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		DMA1->DMA_CCR6 |= (MASKING_BIT << EN);
		break;
	case Channel_7:
		DMA1->DMA_CCR7 &= ~ (MASKING_BIT << EN);

		if(Copy_u32Transfersnum >= MIN_DATA_TRANSFERS && Copy_u32Transfersnum <= MAX_DATA_TRANSFERS)
		{
			DMA1->DMA_CNDTR7 = Copy_u32Transfersnum;

			if(DMAMode == MEM2ME_MODE || DMAMode == MEM2PRE_MODE)
			{
				DMA1->DMA_CMAR7 = Copy_u32SrcAddress;
				DMA1->DMA_CPAR7 = Copy_u32DestAddress;
			}
			else if(DMAMode == PRE2MEM_MODE)
			{
				DMA1->DMA_CPAR7 = Copy_u32SrcAddress;
				DMA1->DMA_CMAR7 = Copy_u32DestAddress;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		DMA1->DMA_CCR7 |= (MASKING_BIT << EN);
		break;
	default:
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	//polling till end of transfer
	while((DMA1->DMA_ISR) >> (((Copy_enuChannelNum - 1) * 4) + 1) & 1);

	//clear the flag
	DMA1->DMA_IFCR |= (MASKING_BIT << (((Copy_enuChannelNum - 1) * 4) + 1) );
	return Local_enuErrorState;
}
