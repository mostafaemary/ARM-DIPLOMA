#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "STK_interfac.h"
#include "NVIC_interface.h"
#include "EXTI_Interface.h"
#include "MUART_Interface.h"


void main (void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnablePerClock(RCC_APB2, 4);
	MRCC_voidEnablePerClock(RCC_AHB1, 0);
	GPIO_voidSetInputConfigurations(GPIOA,10,Floating);
	GPIO_voidSetOutputConfigurations(GPIOA, 9,Output_Push_Pulle,Output_VeryHigh_Speed);
	MUART_voidInit();
	GPIO_voidSetOutputConfigurations(GPIOA, 0,Output_Push_Pulle,Output_VeryHigh_Speed);
	int x =0;
	while(1)
	{
		MUART_voidTransmit8BitData("97");
		x= MUART_u8Receive8BitData();
		if (x=='5')
		MGPIO_voidToggle_Pin(GPIOA,0);
		elseif(x=='R')
		MGPIO_voidToggle_Pin(GPIOA,0);
	else
	}
}