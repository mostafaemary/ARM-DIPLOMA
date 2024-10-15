#include "stdio.h"
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "EXTI_Interface.h"
#include "MDMA_Interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

void func(void)
{
	asm("NOP");
}
void main(void)
{
	MRCC_voidInitSysClock();

	vu32 arr1[500];
	vu32 arr2[500];

	vu32 arr3[500];
	vu32 arr4[500];

	u32* src = arr1;
	u32* dest = arr2;

	for (int i = 0; i < 500; i++)
	{
		arr1[i] = i + 1;
		arr3[i] = i + 1;
	}
	MDMA_voidSetStreamCallBack(0, func);
	MRCC_voidEnablePerClock(RCC_AHB1, 22);
	MNVIC_voidEnableInterrupt(56);
	MDMA_voidStreamConfigurations(Channel0Select, (u32*)src, (u32*)dest, u32BitElement, u32BitElement, 500, INCENABLE, INCENABLE, CircularEnable, HighPriority, MtoM);
	MDMA_voidStartStream(0);

	for (int i = 0; i < 500; i++)
	{
		arr4[i] = arr3[i];
	}

	while (1)
	{

	}
}

