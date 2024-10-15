/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 21 MAY 2024                                         */
/* Version     : V01                                                 */
/******************************************************************* */
#ifndef MDMA_PRIVATE_H
#define MDMA_PRIVATE_H
#define DMA1_BASE_ADDRESS	0x40026000
#define DMA2_BASE_ADDRESS	0x40026400

typedef struct
{
	vu32 DMA_SCR;
	vu32 DMA_SNDTR;
	vu32 DMA_SPAR;
	vu32 DMA_SM0AR;
	vu32 DMA_SM1AR;
	vu32 DMA_SFCR;
}Stream_MAP_t;
typedef struct MEMORY_MAP
{
	vu32 DMA_LISR;
	vu32 DMA_HISR;
	vu32 DMA_LIFCR;
	vu32 DMA_HIFCR;
	Stream_MAP_t S[8];

}DMA_MemoryMap_t;

#define DMA1_Pointer_Reg ((volatile DMA_MemoryMap_t *) DMA1_BASE_ADDRESS)
#define DMA2_Pointer_Reg ((volatile DMA_MemoryMap_t *) DMA2_BASE_ADDRESS)

#endif
