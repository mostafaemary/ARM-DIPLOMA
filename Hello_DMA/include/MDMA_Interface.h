/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 21 MAY 2024                                         */
/* Version     : V01                                                 */
/******************************************************************* */
#ifndef MDMA_INTERFACE_H
#define MDMA_INTERFACE_H


void MDMA_voidInit(void);
void MDMA_voidStreamConfigurations(u8 Copyu8ChannelID, u32* Copyu32PtrSrc, u32* Copyu32PtrDest, u8 Copyu8PDataSize, u8 Copyu8MDataSize, u32 Copyu32BlockSize, u8 Copyu8PINC, u8 Copyu8MINC, u8 Copyu8Repeat, u8 Copyu8PriorityLevel, u8 Copyu8DataTransferDurection);
void MDMA_voidStartStream(u8 Copyu8ChannelID);
void MDMA_voidSetStreamCallBack (u8 Copyu8ChannelID, void(*ptr)(void));



#define Channel0Select		0b000
#define Channel1Select		0b001
#define Channel2Select		0b010
#define Channel3Select		0b011
#define Channel4Select		0b100
#define Channel5Select		0b101
#define Channel6Select		0b110
#define Channel7Select		0b111


#define SingleTransfer		0b00
#define INCR4				0b01
#define INCR8				0b10
#define INCR16				0b11

#define LowPriority			0b00
#define MediumPriority		0b01
#define HighPriority		0b10
#define VeryHighPriority	0b11

#define u8BitElement		0b00
#define u16BitElement		0b01
#define u32BitElement		0b10

#define INCENABLE			0b1
#define INCFIXED			0b0

#define CircularEnable		0b1
#define CircularDisable		0b0

#define PtoM				0b00
#define MtoP				0b01
#define MtoM				0b10


#endif
