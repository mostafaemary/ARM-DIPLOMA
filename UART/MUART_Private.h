/********************************************************************/
/* Author      : Mostafa Emary                                      */
/* Date        : 13 June 2024                                       */
/* Version     : V01                                                */
/********************************************************************/
#ifndef MUART_PRIVAYE_H_
#define MUART_PRIVAYE_H_

#define USART1_BASE_ADDRESS		0x40011000

typedef struct 
{
	vu32 SR;
	vu32 DR;
	vu32 BRR;
	vu32 CR1;
	vu32 CR2;
	vu32 CR3;
	vu32 GTPR;

}MUART_MemoryMap_t;

#define MUART_Pointer_Reg	((volatile MUART_MemoryMap_t*)(USART1_BASE_ADDRESS))

#endif