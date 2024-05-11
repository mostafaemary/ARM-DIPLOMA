#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_Interface.h"
#include "STK_interface.h"
#include "STP_Interface.h"
int main(void)
{

	MRCC_voidInitSysClock();//clock source ==> HSE Crystal
	MRCC_voidEnablePerClock(RCC_AHB1, 0);
	GPIO_voidConfigurePinDirection(GPIOA,P0,Output_Mode);
	GPIO_voidConfigurePinDirection(GPIOA,P1,Output_Mode);
	GPIO_voidConfigurePinDirection(GPIOA,P2,Output_Mode);
	GPIO_voidConfigureOutputType(GPIOA,P0,Output_Push_Pull);
	GPIO_voidConfigureOutputType(GPIOA,P1,Output_Push_Pull);
	GPIO_voidConfigureOutputType(GPIOA,P2,Output_Push_Pull);
	GPIO_voidConfigureOutputSpeed(GPIOA,P0,Output_Low_Speed);
	GPIO_voidConfigureOutputSpeed(GPIOA,P1,Output_Low_Speed);
	GPIO_voidConfigureOutputSpeed(GPIOA,P1,Output_Low_Speed);
	MSTK_voidInit();
	//HSTP_voidSendSynchronous(0xAA);
	int i;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			HSTP_voidSendSynchronous(1<<i);
			MSTK_voidSetBusyWait(500000);
		}
	}

}
