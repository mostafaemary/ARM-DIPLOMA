/********************************************************************/
/* Author      : Mostafa Emary                                      */
/* Date        : 4 OCT 2023                                         */
/* Version     : V01                                                */
/********************************************************************/
#ifndef MUART_INTERFACE_H
#define MUART_INTERFACE_H
void MUART_voidInit(void);
void MUART_voidTransmit8BitData(u8 Copy_u8DataArray[]);
u8 MUART_u8Receive8BitData(void);




#endif