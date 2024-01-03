/* ****************************************************************** */
/* Author      : Mostafa Emary                                        */
/* Date        : 27 Dec 2023                                          */
/* Version     : V01                                                  */
/* ****************************************************************** */
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define RCC_AHB1		  		0
#define RCC_APB1				1
#define RCC_APB2				2
#define RCC_AHB2		  		3
void MRCC_voidEnableClock(void);
void MRCC_voidInitSysClock(void);
void MRCC_voidEnablePerClock(u8 MCopy_u8BusId, u8 MCopy_u8PerId);
void MRCC_voidDisablePerClock(u8 MCopy_u8BusId, u8 MCopy_u8PerId);


#endif