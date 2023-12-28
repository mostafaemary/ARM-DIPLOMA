#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#define DELAY(D)	do{unsigned int i=D*3623;while(i--){asm("nop");}}while(0)
int main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnablePerClock(RCC_AHB1, 0);
	//GPIO_voidConfigurePinDirection(GPIOA,P5,Output_Mode);
	//GPIO_voidConfigureOutputType(GPIOA,P5,Output_Push_Pull);
	//GPIO_voidConfigureOutputSpeed(GPIOA, P5, Output_Low_Speed);
	 Config_parameters_t led_config =
	 {
	.Port_Name = GPIOA,
	.Pin_Num = P5,
	.I_O_A_A_Mode = Output_Mode,
	.OutType = Output_Push_Pull,
	.Out_Speed = Output_Low_Speed,
	.In_Modes = Pull_Down,
};
GPIO_voidConfigurePorting(&led_config);
	while (1)
	{
		GPIO_voidSetPinValue(GPIOA,P5, HIGH);
		DELAY(1000);
		GPIO_voidSetPinValue(GPIOA,P5, LOW);
		DELAY(1000);
	}
return 0;
}
