/********************************************************************/
/* Author      : Mostafa Emary                                      */
/* Date        : 4 OCT 2023                                         */
/* Version     : V01                                                */
/********************************************************************/
/* including Libraries */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* including System Files */
#include "MUART_Interface.h"
#include "MUART_Config.h"
#include "MUART_Private.h"

void MUART_voidInit(void)
{
	/* 9600 you should make that value Depend On the Baud Rate Equation */
	/* Mantissa Bits = 0x34 */
	/* Fractioal Part = 1 */
	MUART_Pointer_Reg ->BRR = 0x341;
	/* Over Sampling Mode = 16 */
	SET_BIT(MUART_Pointer_Reg->CR1,15);
	/* 8 BIT Data */
	CLR_BIT(MUART_Pointer_Reg->CR1,12);
	/* No Parity */
	CLR_BIT(MUART_Pointer_Reg->CR1,10);
	/* Transmitter Enable */
	SET_BIT(MUART_Pointer_Reg->CR1,3);
	/* Receiver Enable */
	SET_BIT(MUART_Pointer_Reg->CR1,2);
	/* UART ENABLE */
	SET_BIT(MUART_Pointer_Reg->CR1,13);
}
void MUART_voidTransmit8BitData(u8 Copy_u8DataArray[])
{
	int i=0;
	/* Some Checks Then Put data into buffer, sends the data */
	while (Copy_u8DataArray[i]!='\0')
	{
		/* Wait for empty transmitter buffer */
		while (GET_BIT(MUART_Pointer_Reg->SR,7)==0);
		/* Put data into buffer, sends the data */
		MUART_Pointer_Reg->DR=Copy_u8DataArray[i];
		/* Wait For Transmission Complete */
		while (GET_BIT(MUART_Pointer_Reg->SR,6)==0);
		/* Clear TC Flag */
		CLR_BIT(MUART_Pointer_Reg->SR,6);
		i++;
	}
}
u8 MUART_u8Receive8BitData(u8* Copy_u8Data)
{

/*/* the Commented Code was for the wifi lecture */

	//u16 timeout =0;
	//u8 Local_u8ReceiveData=1;
	/* Waiting for Read Data to be Empty -> Transfere Competed */
//	while (GET_BIT(MUART_Pointer_Reg->SR,5)==0);
//	{
//		timeout++;
//		if(timeout == 10000)
//		{
//			/* ASCI CODE RANGE: 0 TO 127 */
//			Local_u8ReceiveData=255;
//			break;
//		}
//	}
//	/* Clear TC Flag */
//	CLR_BIT(MUART_Pointer_Reg->SR,5);
//	/* Get and return received data from buffer */
//	if(Local_u8ReceiveData==0)
//	{
//		Local_u8ReceiveData = MUART_Pointer_Reg->DR;
//	}
//	return Local_u8ReceiveData;

u8 Local_u8Result = 1;
if(GET_BIT(GET_BIT(MUART_Pointer_Reg->SR,5)==1))
{
	*Copy_u8Data=MUART_Pointer_Reg->DR;
}
else 
{
	Local_u8Result=0;
}
return Local_u8Result;
}
