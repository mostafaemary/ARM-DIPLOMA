/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 01 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
static void (*CallBack)(void);
static u8 Single_flag;
void MSTK_voidInit(void)
{
	/* SELECT AHB / 8 as Clock Source
	*DISABLE UnderFlow Interrupt
	*DISABLE systick
	*/
	CLR_BIT(STK_CTRL, 2);
	CLR_BIT(STK_CTRL, 1);
	CLR_BIT(STK_CTRL, 0);
}
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	STK_VAL = 0;
	STK_LOAD = Copy_u32Ticks;
	//SET_BIT(STK_CTRL, 1);//ENABLE UnderFlow Interrupt
	SET_BIT(STK_CTRL, 0);//ENABLE systick
	while (GET_BIT(STK_CTRL, 16) != 1);
	CLR_BIT(STK_CTRL, 0);//DISABLE UnderFlow Interrupt
}
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	Single_flag = 1;
	CallBack = Copy_ptr;
	STK_VAL = 0;
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, 1);//ENABLE UnderFlow Interrupt
	SET_BIT(STK_CTRL, 0);//ENABLE systick


}
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	Single_flag = 0;
	CallBack = Copy_ptr;
	STK_VAL = 0;
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, 1);//ENABLE UnderFlow Interrupt
	SET_BIT(STK_CTRL, 0);//ENABLE systick
}
u32  MSTK_u32GetElapsedTime(void)
{
	u32 Elapsed = STK_LOAD - STK_VAL;
	return Elapsed;
}
u32  MSTK_u32GetRemainingTime(void)
{
	u32 Remaining = STK_LOAD - STK_VAL;
	return Remaining;
}
void SysTick_Handler(void)
{
	//u8 result;
	if (CallBack)
	{
		CallBack();
	}
	if (Single_flag == 1)
	{
		Single_flag = 0;
		CLR_BIT(STK_CTRL, 0);
	}
	//result=GET_BIT(STK_CTRL, 16);//clear STK Interrupt flag
}
