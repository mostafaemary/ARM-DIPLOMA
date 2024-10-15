/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 12 June 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#ifndef MSPI_Private_H
#define MSPI_Private_H
#define SPI1_BASE_ADDRESS	0x40013000
#define SPI2_BASE_ADDRESS	0x40003800
#define SPI3_BASE_ADDRESS	0x40003C00	/* not used */
#define SPI4_BASE_ADDRESS	0x40013400	/* not used */
typedef struct
{
	vu32 SPI_CR1;
	vu32 SPI_CR2;
	vu32 SPI_SR;
	vu32 SPI_DR;
	vu32 SPI_CRCPR;
	vu32 SPI_RXCRCR;
	vu32 SPI_TXCRCR;
	vu32 SPI_I2SCFGR;
	vu32 SPI_I2SPR;
}MSPI_MemoryMap_t;

#define MSPI1_Pointer_Reg ((volatile MSPI_MemoryMap_t*)(SPI1_BASE_ADDRESS))
#define MSPI2_Pointer_Reg ((volatile MSPI_MemoryMap_t*)(SPI2_BASE_ADDRESS))
#define MSPI3_Pointer_Reg ((volatile MSPI_MemoryMap_t*)(SPI3_BASE_ADDRESS))
#define MSPI4_Pointer_Reg ((volatile MSPI_MemoryMap_t*)(SPI4_BASE_ADDRESS))
#endif
