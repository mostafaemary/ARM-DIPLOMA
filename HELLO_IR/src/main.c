/*
 * main.c
 *
 *  Created on: May 15, 2024
 *      Author: MOSTAFA EMARY
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_Interface.h"
vu32 u32FrameData[33]	= {0};
vu8  u8StartFlag		=	0;
vu8  u8EdgeCounter		=	0;

vu8 u8Data=0;


void vioidTakeAction(void)
{
	switch (u8Data)
	{
	case 12:
		MGPIO_voidToggle_Pin(GPIO(A,1));break;
	case 24:
		MGPIO_voidToggle_Pin(GPIO(A,2));break;
	case 94:
		MGPIO_voidToggle_Pin(GPIO(A,3));break;
	}
}
void vioidConvertFrameTo8BitData(void)
{/*asm("NOP");*/
		u8 i;
		u8Data=0;
		for(i=0;i<8;i++)
		{
			if ((u32FrameData[17+i]>=2000) && (u32FrameData[17+i]<=2300))
			{
				SET_BIT(u8Data,i);
			}
			if ((u32FrameData[17+i]>=1000) && (u32FrameData[17+i]<=1200))
			{
				CLR_BIT(u8Data,i);
			}
		}
		vioidTakeAction();
		u8StartFlag		=0;
		u8EdgeCounter	=0;
		/*u32FrameData[0]=0;*/
}

void IR_voidGetIRFrame(void)
{/* asm("NOP"); */

	if (u8StartFlag==0)
	{

		MSTK_voidSetIntervalSingle(15000,vioidConvertFrameTo8BitData);
		u8StartFlag=1;
	}
	else 
	{
		u32FrameData[u8EdgeCounter]= MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(15000,vioidConvertFrameTo8BitData);
		u8EdgeCounter++;

	}
}
void main (void)
{
	MSTK_voidInit();



	MRCC_voidInitSysClock();//clock source ==> HSE Crystal
	MRCC_voidEnablePerClock(RCC_AHB1, 0);/* Enable Clock for GPIOA */

	GPIO_voidSetInputConfigurations(GPIO(A,0),Floating);
	/*GPIO_voidConfigurePinDirection(GPIO(A,0), Input_Mode);
	GPIO_voidConfigureInpytType(GPIO(A,0), Floating);*/


	GPIO_voidSetOutputConfigurations(GPIO(A,1), Output_Push_Pull,Output_Low_Speed);
	/*GPIO_voidConfigurePinDirection(GPIO(A,1), Output_Mode);
	  GPIO_voidConfigureOutputType (GPIO(A,1), Output_Push_Pull);
	  GPIO_voidConfigureOutputSpeed(GPIO(A,1),Output_Low_Speed);*/

	GPIO_voidSetOutputConfigurations(GPIO(A,2), Output_Push_Pull,Output_Low_Speed);
	/*GPIO_voidConfigurePinDirection(GPIO(A,2), Output_Mode);
	  GPIO_voidConfigureOutputType (GPIO(A,2), Output_Push_Pull);
	  GPIO_voidConfigureOutputSpeed(GPIO(A,2), Output_Low_Speed);*/

	GPIO_voidSetOutputConfigurations(GPIO(A,3), Output_Push_Pull,Output_Low_Speed);
	/*GPIO_voidConfigurePinDirection(GPIO(A,3), Output_Mode);
	  GPIO_voidConfigureOutputType(GPIO(A,3), Output_Push_Pull);
	  GPIO_voidConfigureOutputSpeed(GPIO(A,3), Output_Low_Speed);*/

	Set_Callback(0, IR_voidGetIRFrame);
	MEXTI_voidEnableLineAndSelectTrigger(FALLING_EDGE,GPIOA);
	MEXTI_voidInit();
	MVIC_voidInit();
	MNVIC_voidEnableInterrupt(6);
	MEXTI_voidEnableLine(GPIOA);


	GPIO_voidSetPinValue(GPIO(A,1),1);
	GPIO_voidSetPinValue(GPIO(A,2),1);
	GPIO_voidSetPinValue(GPIO(A,3),1);


	while (1)
	{
		//		GPIO_voidSetPinValue(GPIO(A,3),1);
		//		MSTK_voidSetBusyWait(15000000);
		//		GPIO_voidSetPinValue(GPIO(A,3),0);
		//		GPIO_voidSetPinValue(GPIO(A,1),1);
		//		MSTK_voidSetBusyWait(15000000);
		//		GPIO_voidSetPinValue(GPIO(A,1),0);
		//		GPIO_voidSetPinValue(GPIO(A,2),1);
		//		MSTK_voidSetBusyWait(15000000);
		//		GPIO_voidSetPinValue(GPIO(A,2),0);

	}

}

