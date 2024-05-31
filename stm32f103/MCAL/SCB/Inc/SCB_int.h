/*
 * SCB_int.h
 *
 *  Created on: May 27, 2024
 *      Author: user
 */

#ifndef SCB_INT_H_
#define SCB_INT_H_

//Binary point for group priority
typedef enum{
	PRI_GROUP3 = 3,
	PRI_GROUP4 = 4,
	PRI_GROUP5 = 5,
	PRI_GROUP6 = 6,
	PRI_GROUP7 = 7
}SCB_PRIGROUP;

// exceptions
typedef enum{
   MEM_MANAGEMENT_FAULT = 4,
   BUS_FAULT ,
   USAGE_FAULT,
   SVCALL = 11,
   PENDSV = 14,
   SYSTICK_EXC = 15
}SCB_EXCEPTIONS;

//Priority
typedef enum{
	 PRI_0   ,
	 PRI_1  ,
	 PRI_2  ,
	 PRI_3  ,
	 PRI_4  ,
	 PRI_5  ,
	 PRI_6  ,
	 PRI_7  ,
	 PRI_8  ,
	 PRI_9  ,
	 PRI_10  ,
	 PRI_11  ,
	 PRI_12  ,
	 PRI_13  ,
	 PRI_14  ,
	 PRI_15
}SCB_HANDLERS_PRIORITY;


//These fuctions are mainly used for debugging
ES_t SCB_enuSetNMIPendingFlag(void);
ES_t SCB_enuSetSVPendingFlag(void);
ES_t SCB_enuClearSVPendingFlag(void);
ES_t SCB_enuSetSYSTICKPendingFlag(void);
ES_t SCB_enuClearSYSTICKPendingFlag(void);


ES_t SCB_enuReadNMIPendingFlag(u8* Copy_Pu8Value);//A read of this bit by the NMI exception handler returns 1 only if the NMI signal is reasserted while the processor is executing that handler

ES_t SCB_enuReadSVSPendingFlag(u8* Copy_Pu8Value);

ES_t SCB_enuReadSTPendingFlag(u8* Copy_Pu8Value);

ES_t SCB_enuReadInterruptPendingFlag(u8* Copy_pu8Value);// excluding NMI and Faults

ES_t SCB_enuSetInterruptPriorityGroup(SCB_PRIGROUP Copy_enuInterruptGroupPriority );

ES_t SCB_enuSetExceptionsPriority(SCB_EXCEPTIONS Copy_enuException,SCB_HANDLERS_PRIORITY Copy_enuFaultHandlerPriority );


#endif /* SCB_INT_H_ */
