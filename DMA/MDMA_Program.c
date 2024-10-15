/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 21 MAY 2024                                         */
/* Version     : V01                                                 */
/******************************************************************* */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDMA_Interface.h"
#include "MDMA_Config.h"
#include "MDMA_Private.h"

static void (*DMA2Stream0_CallBack)(void);
static void (*DMA2Stream1_CallBack)(void);
static void (*DMA2Stream2_CallBack)(void);
static void (*DMA2Stream3_CallBack)(void);
static void (*DMA2Stream4_CallBack)(void);
static void (*DMA2Stream5_CallBack)(void);
static void (*DMA2Stream6_CallBack)(void);
static void (*DMA2Stream7_CallBack)(void);
/*
static void (*DMA1Stream0_CallBack)(void);
static void (*DMA1Stream1_CallBack)(void);
static void (*DMA1Stream2_CallBack)(void);
static void (*DMA1Stream3_CallBack)(void);
static void (*DMA1Stream4_CallBack)(void);
static void (*DMA1Stream5_CallBack)(void);
static void (*DMA1Stream6_CallBack)(void);
static void (*DMA1Stream7_CallBack)(void);
*/
void MDMA_voidInit(void)
{
	asm("NOP");
}
void MDMA_voidStreamConfigurations(u8 Copyu8ChannelID, u32* Copyu32PtrSrc, u32* Copyu32PtrDest, u8 Copyu8PDataSize, u8 Copyu8MDataSize, u32 Copyu32BlockSize, u8 Copyu8PINC, u8 Copyu8MINC, u8 Copyu8Repeat, u8 Copyu8PriorityLevel, u8 Copyu8DataTransferDurection)
{
	/* Disable Stream */

	CLR_BIT(DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR, 0);
	/*channel Select*/
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR &= ~(0b111 << 25);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8ChannelID << 25);
	/*Select Peripheral and Memory Burst  */
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR &= ~(0b1111 << 21);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8PINC << 21);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8MINC << 23);
	/*no Double Buffer Mode*/
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR &= ~(0b11 << 18);
	/*Priority Level*/
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR &= ~(0b11 << 16);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8PriorityLevel << 16);
	/*select The PSIZE Increment(Pointer Increment Size for Peripheral)*/
	/* DMA2_Pointer_Reg->Stream_MAP_t[Copyu8ChannelID % 8].DMA_SCR &= ~(0b1 << 15); */
	CLR_BIT(DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR, 15);
	/* Select Peripheral and Memory Data Size */
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR &= ~(0b11 << 11);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8PDataSize << 11);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8MDataSize << 13);
	/* Select PINC and MINC */
	//DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR &= ~(0b11 << 9);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8MINC << 10);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8PINC << 9);
	/* Circular Mode */
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR &= ~(0b1 << 8);
	//DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8Repeat << 8);
	/* Data transfer direction */
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR &= ~(0b11 << 6);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR |= (Copyu8DataTransferDurection << 6);

	/* Enable TCIE */
	SET_BIT(DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR, 4);
	/* Number of data items to transfer */
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SNDTR = Copyu32BlockSize;

	/* Source address */
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SPAR = (u32*)Copyu32PtrSrc;
	/* Destination address */
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SM0AR = (u32*)Copyu32PtrDest;

	/* Direct Mode Disable */
	SET_BIT(DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SFCR, 2);

	/* Select Full FIFO Mode */
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SFCR &= ~(0b11 << 0);
	DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SFCR |= (0b11 << 0);


}
void MDMA_voidStartStream(u8 Copyu8ChannelID)
{
	/* Disable Stream */
	CLR_BIT(DMA2_Pointer_Reg->S[Copyu8ChannelID % 8].DMA_SCR, 0);
	/* Clear Flags for Stream */
	if (Copyu8ChannelID <= 3)
	{
		DMA2_Pointer_Reg->DMA_LIFCR |= (0b111111 << (Copyu8ChannelID * 8));
	}
	else if (Copyu8ChannelID <= 7)
	{
		DMA2_Pointer_Reg->DMA_HIFCR |= (0b111111 << (Copyu8ChannelID * 8));
	}

	/* Enable Stream */
	SET_BIT(DMA2_Pointer_Reg->S[Copyu8ChannelID].DMA_SCR, 0);

}
void MDMA_voidSetStreamCallBack(u8 Copyu8ChannelID, void(*ptr)(void))
{
	switch (Copyu8ChannelID)
	{
	case 0:	DMA2Stream0_CallBack = ptr;	break;
	case 1:	DMA2Stream1_CallBack = ptr;	break;
	case 2:	DMA2Stream2_CallBack = ptr;	break;
	case 3:	DMA2Stream3_CallBack = ptr;	break;
	case 4:	DMA2Stream4_CallBack = ptr;	break;
	case 5:	DMA2Stream5_CallBack = ptr;	break;
	case 6:	DMA2Stream6_CallBack = ptr;	break;
	case 7:	DMA2Stream7_CallBack = ptr;	break;
	default:	break;
	}
}
void DMA2_Stream0_IRQHandler(void)
{
	DMA2Stream0_CallBack();
	CLR_BIT(DMA2_Pointer_Reg->S[0].DMA_SCR, 0);
	DMA2_Pointer_Reg->DMA_LIFCR |= (0b111111 << 0);
}
void DMA2_Stream1_IRQHandler(void)
{
	DMA2Stream1_CallBack();
}
void DMA2_Stream2_IRQHandler(void)
{
	DMA2Stream2_CallBack();
}
void DMA2_Stream3_IRQHandler(void)
{
	DMA2Stream3_CallBack();
}
void DMA2_Stream4_IRQHandler(void)
{
	DMA2Stream4_CallBack();
}
void DMA2_Stream5_IRQHandler(void)
{
	DMA2Stream5_CallBack();
}
void DMA2_Stream6_IRQHandler(void)
{
	DMA2Stream6_CallBack();
}
void DMA1_Stream7_IRQHandler(void)
{
	DMA2Stream7_CallBack();
}
