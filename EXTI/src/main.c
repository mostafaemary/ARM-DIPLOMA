#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "NVIC_Interface.h"
#include "STK_interface.h"
#include "EXTI_Interface.h"
#define DELAY(D)	do{unsigned int i=D*3623;while(i--){asm("nop");}}while(0)

void func(void);
int main(void)
{
	Set_Callback(0, func);
	MRCC_voidInitSysClock();
	MRCC_voidEnablePerClock(RCC_AHB1, 0);
	MRCC_voidEnablePerClock(RCC_APB2, 14);


	GPIO_voidConfigurePinDirection(GPIOA,P0,Input_Mode);
	GPIO_voidConfigureInpytType(GPIOA, P0, Pull_Up);

	//GPIO_voidConfigureOutputSpeed(GPIOA, P5, Output_Low_Speed);
	//Config_parameters_t led0_config =
	//{
	//	.Port_Name = GPIOA,
	//	.Pin_Num = P0,
	//	.I_O_A_A_Mode = Input_Mode,
	//	.OutType = Output_Push_Pull,
	//	.Out_Speed = Output_Low_Speed,
	//	.In_Modes = Pull_Up,
	//};
	//GPIO_voidConfigurePorting(&led0_config);

	Config_parameters_t led1_config =
	{
			.Port_Name = GPIOA,
			.Pin_Num = P1,
			.I_O_A_A_Mode = Output_Mode,
			.OutType = Output_Push_Pull,
			.Out_Speed = Output_Low_Speed,
			.In_Modes = Pull_Down,
	};
	GPIO_voidConfigurePorting(&led1_config);
	Config_parameters_t led2_config =
	{
			.Port_Name = GPIOA,
			.Pin_Num = P2,
			.I_O_A_A_Mode = Output_Mode,
			.OutType = Output_Push_Pull,
			.Out_Speed = Output_Low_Speed,
			.In_Modes = Pull_Down,
	};
	GPIO_voidConfigurePorting(&led2_config);


	Config_parameters_t led5_config =
	{
			.Port_Name = GPIOA,
			.Pin_Num = P5,
			.I_O_A_A_Mode = Output_Mode,
			.OutType = Output_Push_Pull,
			.Out_Speed = Output_Low_Speed,
			.In_Modes = Pull_Down,
	};
	GPIO_voidConfigurePorting(&led5_config);
	MVIC_voidInit();
	MSTK_voidInit();


	//MNVIC_voidSetPrioruty(6,0x40);
	//MNVIC_voidSetPrioruty(7,0x30);

	//MNVIC_voidEnableInterrupt(7);
	//MNVIC_voidSetPendingFlag(6);

	//DELAY(1000);
	//MSTK_voidSetIntervalPeriodic(300000, func);
	MEXTI_voidInit();
	MEXTI_voidEnableLine(0);
	MEXTI_voidSetTriggreType(FALLING_EDGE, 0);
	MNVIC_voidEnableInterrupt(6);

	//MEXTI_voidEnableLineAndSelectTrigger(FALLING_EDGE,0);
	//MEXTI_voidTriggerSWInterrupt(0);
	while (1)
	{
		//		GPIO_voidSetPinValue(GPIOA,P0, HIGH);
		//		MSTK_voidSetBusyWait(3000000);
		//		GPIO_voidSetPinValue(GPIOA,P0, LOW);
		//		MSTK_voidSetBusyWait(3000000);

		//DELAY(1000);
		//GPIO_voidSetPinValue(GPIOA,P0, LOW);
		//DELAY(1000);
	}
	return 0;
}
//void EXTI0_IRQHandler(void)/*IRQ for INT request*/
//{
//	//while(1){
//	GPIO_voidSetPinValue(GPIOA,P1,HIGH);
//	MSTK_voidSetBusyWait(3000000);
//	GPIO_voidSetPinValue(GPIOA,P1,LOW);
//	//MSTK_voidSetBusyWait(3000000);}
//	MEXTI_voidClearInterruptFlag(0);
//
//}
//void EXTI1_IRQHandler(void)/* IRQ for INT request */
//{
//	GPIO_voidSetPinValue(GPIOA,P5,HIGH);
//	DELAY(1000);
//	MNVIC_voidSetPendingFlag(6);
//	GPIO_voidSetPinValue(GPIOA,P2,HIGH);
//}
void func(void)
{
	while(1)
	{GPIO_voidSetPinValue(GPIOA,P1, HIGH);
	MSTK_voidSetBusyWait(3000000);
	GPIO_voidSetPinValue(GPIOA,P1, LOW);
	MSTK_voidSetBusyWait(3000000);
	}
}
