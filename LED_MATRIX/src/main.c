#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "NVIC_Interface.h"
#include "STK_interface.h"
#include "EXTI_Interface.h"
#define DELAY(D)	do{unsigned int i=D*3623;while(i--){asm("nop");}}while(0)

int main(void)
{
	//char arr[][8]={0, 255, 1, 2, 2, 1, 255, 0},{255, 1, 2, 2, 1, 255, 0, 0},{1, 2, 2, 1, 255, 0, 0, 255},{2, 2, 1, 255, 0, 0, 255, 1},{2, 1, 255, 0, 0, 255, 1, 2},{1, 255, 0, 0, 255, 1, 2, 2}

	const u8 IMAGES[][8] = {
	{
	  0b00111100,
	  0b00100100,
	  0b00100100,
	  0b00111100,
	  0b00100100,
	  0b00100100,
	  0b00100100,
	  0b00100100
	},{
	  0b01111000,
	  0b01001000,
	  0b01001000,
	  0b01111000,
	  0b01001000,
	  0b01001000,
	  0b01001000,
	  0b01001000
	},{
	  0b11110000,
	  0b10010000,
	  0b10010000,
	  0b11110000,
	  0b10010000,
	  0b10010000,
	  0b10010000,
	  0b10010000
	},{
	  0b11100001,
	  0b00100001,
	  0b00100001,
	  0b11100001,
	  0b00100001,
	  0b00100001,
	  0b00100001,
	  0b00100001
	},{
	  0b11000010,
	  0b01000010,
	  0b01000010,
	  0b11000011,
	  0b01000010,
	  0b01000010,
	  0b01000010,
	  0b01000010
	},{
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000111,
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000100
	},{
	  0b00001001,
	  0b00001001,
	  0b00001001,
	  0b00001111,
	  0b00001001,
	  0b00001001,
	  0b00001001,
	  0b00001001
	},{
	  0b00010010,
	  0b00010010,
	  0b00010010,
	  0b00011110,
	  0b00010010,
	  0b00010010,
	  0b00010010,
	  0b00010010
	},{
	  0b00100100,
	  0b00100100,
	  0b00100100,
	  0b00111100,
	  0b00100100,
	  0b00100100,
	  0b00100100,
	  0b00100100
	},{
	  0b01001000,
	  0b01001000,
	  0b01001000,
	  0b01111000,
	  0b01001000,
	  0b01001000,
	  0b01001000,
	  0b01001000
	},{
	  0b10010000,
	  0b10010000,
	  0b10010000,
	  0b11110000,
	  0b10010000,
	  0b10010000,
	  0b10010000,
	  0b10010000
	},{
	  0b00100000,
	  0b00100000,
	  0b00100000,
	  0b11100000,
	  0b00100000,
	  0b00100000,
	  0b00100000,
	  0b00100000
	},{
	  0b00100001,
	  0b00100001,
	  0b00100001,
	  0b11100001,
	  0b00100001,
	  0b00100001,
	  0b00100001,
	  0b00100001
	},{
	  0b01000010,
	  0b01000010,
	  0b01000010,
	  0b11000010,
	  0b01000010,
	  0b01000010,
	  0b01000010,
	  0b01000011
	},{
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000111
	},{
	  0b00001000,
	  0b00001000,
	  0b00001000,
	  0b00001000,
	  0b00001000,
	  0b00001000,
	  0b00001000,
	  0b00001110
	},{
	  0b00010000,
	  0b00010000,
	  0b00010000,
	  0b00010000,
	  0b00010000,
	  0b00010000,
	  0b00010000,
	  0b00011100
	},{
	  0b00100000,
	  0b00100000,
	  0b00100000,
	  0b00100000,
	  0b00100000,
	  0b00100000,
	  0b00100000,
	  0b00111000
	},{
	  0b01000000,
	  0b01000000,
	  0b01000000,
	  0b01000000,
	  0b01000000,
	  0b01000000,
	  0b01000000,
	  0b01110000
	},{
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b11100000
	},{
	  0b00000001,
	  0b00000001,
	  0b00000001,
	  0b00000001,
	  0b00000001,
	  0b00000001,
	  0b00000001,
	  0b11000001
	},{
	  0b00000011,
	  0b00000010,
	  0b00000010,
	  0b00000011,
	  0b00000010,
	  0b00000010,
	  0b00000010,
	  0b10000010
	},{
	  0b00000111,
	  0b00000100,
	  0b00000100,
	  0b00000111,
	  0b00000100,
	  0b00000100,
	  0b00000100,
	  0b00000100
	},{
	  0b00001111,
	  0b00001001,
	  0b00001001,
	  0b00001111,
	  0b00001001,
	  0b00001001,
	  0b00001001,
	  0b00001001
	},{
	  0b00011110,
	  0b00010010,
	  0b00010010,
	  0b00011110,
	  0b00010010,
	  0b00010010,
	  0b00010010,
	  0b00010010
	},{
	  0b00111100,
	  0b00100100,
	  0b00100100,
	  0b00111100,
	  0b00100100,
	  0b00100100,
	  0b00100100,
	  0b00100100
	},{
	  0b01111000,
	  0b01001000,
	  0b01001000,
	  0b01111000,
	  0b01001000,
	  0b01001000,
	  0b01001000,
	  0b01001000
	},{
	  0b11110000,
	  0b10010000,
	  0b10010000,
	  0b11110000,
	  0b10010000,
	  0b10010000,
	  0b10010000,
	  0b10010000
	},{
	  0b11100001,
	  0b00100001,
	  0b00100001,
	  0b11100001,
	  0b00100001,
	  0b00100001,
	  0b00100001,
	  0b00100001
	},{
	  0b11000010,
	  0b01000011,
	  0b01000010,
	  0b11000010,
	  0b01000010,
	  0b01000010,
	  0b01000010,
	  0b01000010
	},{
	  0b10000100,
	  0b10000110,
	  0b10000101,
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000100
	},{
	  0b00001000,
	  0b00001100,
	  0b00001011,
	  0b00001000,
	  0b00001000,
	  0b00001000,
	  0b00001000,
	  0b00001000
	},{
	  0b00010000,
	  0b00011001,
	  0b00010110,
	  0b00010000,
	  0b00010000,
	  0b00010000,
	  0b00010000,
	  0b00010000
	},{
	  0b00100001,
	  0b00110011,
	  0b00101101,
	  0b00100001,
	  0b00100001,
	  0b00100001,
	  0b00100001,
	  0b00100001
	},{
	  0b00100001,
	  0b00110011,
	  0b00101101,
	  0b00100001,
	  0b00100001,
	  0b00100001,
	  0b00100001,
	  0b00100001
	},{
	  0b01000010,
	  0b01100110,
	  0b01011010,
	  0b01000010,
	  0b01000010,
	  0b01000010,
	  0b01000010,
	  0b01000010
	},{
	  0b10000100,
	  0b11001100,
	  0b10110100,
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000100,
	  0b10000100
	},{
	  0b00001000,
	  0b10011000,
	  0b01101000,
	  0b00001000,
	  0b00001000,
	  0b00001000,
	  0b00001000,
	  0b00001000
	},{
	  0b00010000,
	  0b00110000,
	  0b11010000,
	  0b00010000,
	  0b00010000,
	  0b00010000,
	  0b00010000,
	  0b00010000
	},{
	  0b00100000,
	  0b01100000,
	  0b10100000,
	  0b00100000,
	  0b00100000,
	  0b00100000,
	  0b00100000,
	  0b00100000
	},{
	  0b01000000,
	  0b11000000,
	  0b01000000,
	  0b01000000,
	  0b01000000,
	  0b01000000,
	  0b01000000,
	  0b01000000
	},{
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b10000000,
	  0b10000000
	}};
	const int IMAGES_LEN = sizeof(IMAGES)/8;


//	const int IMAGES_LEN = sizeof(IMAGES)/8;

	MRCC_voidInitSysClock();
	MRCC_voidEnablePerClock(RCC_AHB1, 0);
	MRCC_voidEnablePerClock(RCC_AHB1, 1);
	MRCC_voidEnablePerClock(RCC_APB2, 14);
	HLEDMRX_voidInit();

	while (1)
	{
		for(int i=0;i<IMAGES_LEN;i++)
		{
		HLEDMRX_voidDisplay(&(IMAGES[i]));
		MSTK_voidSetBusyWait(800000);
		//MSTK_voidSetBusyWait(50000);
		//MSTK_voidSetBusyWait(900);
		}
	}
	return 0;
}