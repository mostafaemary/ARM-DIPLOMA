/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 12 June 2024                                        */
/* Version     : V01                                                 */
/* ***************************************************************** */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MSPI_Interface.h"
#include "MSPI_Private.h"
#include "MSPI_Config.h"


void MSPI1_voidInit(void)
{
	/* MSB will sent first */
	/* SPI Enabled */
	/* 010 Prescaler -> BaudRate= Fclk/8 */
	/* Master Configuration */
	/* Clk idle Low & Write Then Read */
	MSPI1_Pointer_Reg->SPI_CR1 =0x000002D5;
}

void MSPI_voidSendReceive(u8 Copy_u8DataToSend,u8* Copy_u8_DataToReceive)
{
	/* Clear for Slave Select Pin */
	void GPIO_voidSetOutputConfigurations(SSPIN,LOW,Output_Medium_Speed);

	/* Start Transmition */ 

	/* Master and Slave Send at the same Time */
/* 1- Put Master Data */
	MSPI1_Pointer_Reg->SPI_DR=Copy_u8DataToSend;
	/* Wait while the Data Shifting occurs */
	while(GET_BIT(MSPI1_Pointer_Reg->SPI_SR,7));
/* 2- Get Slave Data */
	*Copy_u8_DataToReceive=	MSPI1_Pointer_Reg->SPI_DR;
	/* Set Slave Select Pin */
	void GPIO_voidSetOutputConfigurations(SSPIN,HIGH,Output_Medium_Speed);
}