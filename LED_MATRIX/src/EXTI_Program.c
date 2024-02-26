/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 06 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

static void (*EXTI0_Callback_PTR)(void);
static void (*EXTI1_Callback_PTR)(void);
static void (*EXTI2_Callback_PTR)(void);
static void (*EXTI3_Callback_PTR)(void);
static void (*EXTI4_Callback_PTR)(void);
static void (*EXTI5_Callback_PTR)(void);
static void (*EXTI6_Callback_PTR)(void);
static void (*EXTI7_Callback_PTR)(void);
static void (*EXTI8_Callback_PTR)(void);
static void (*EXTI9_Callback_PTR)(void);
static void (*EXTI10_Callback_PTR)(void);
static void (*EXTI11_Callback_PTR)(void);
static void (*EXTI12_Callback_PTR)(void);
static void (*EXTI13_Callback_PTR)(void);
static void (*EXTI14_Callback_PTR)(void);
static void (*EXTI15_Callback_PTR)(void);
void MEXTI_voidInit(void)
{
	/* Mask All Lines */
	EXTI_Pointer_Reg->EXTI_IMR = 0x00000000;
	/* Clear All Flags */
	EXTI_Pointer_Reg->EXTI_PR = 0xffffffff;
}
void MEXTI_voidEnableLineAndSelectTrigger(u8 Copy_u8Triggre, u8 Copy_u8LineNumber)//assumed Portname
{
	if (Copy_u8LineNumber < 16)
	{
		SET_BIT(EXTI_Pointer_Reg->EXTI_IMR, Copy_u8LineNumber);
		switch (Copy_u8Triggre)
		{
		case RISING_EDGE:	SET_BIT(EXTI_Pointer_Reg->EXTI_RTSR, Copy_u8LineNumber); CLR_BIT(EXTI_Pointer_Reg->EXTI_FTSR, Copy_u8LineNumber); break;
		case FALLING_EDGE:	CLR_BIT(EXTI_Pointer_Reg->EXTI_RTSR, Copy_u8LineNumber); SET_BIT(EXTI_Pointer_Reg->EXTI_FTSR, Copy_u8LineNumber); break;
		case ON_CHANGE:		SET_BIT(EXTI_Pointer_Reg->EXTI_RTSR, Copy_u8LineNumber); SET_BIT(EXTI_Pointer_Reg->EXTI_FTSR, Copy_u8LineNumber); break;
		default: /*Return Error*/ break;
		}
	}
}
void MEXTI_voidEnableLine(u8 Copy_u8LineNumber)//assumed Portname
{
	if (Copy_u8LineNumber < 16)
	{
		SET_BIT(EXTI_Pointer_Reg->EXTI_IMR, Copy_u8LineNumber);
	}
}
void MEXTI_voidDisableLine(u8 Copy_u8LineNumber)
{
	if (Copy_u8LineNumber < 16)
	{
		CLR_BIT(EXTI_Pointer_Reg->EXTI_IMR, Copy_u8LineNumber);
	}
}
void MEXTI_voidSetTriggreType(u8 Copy_u8Triggre, u8 Copy_u8LineNumber)
{
	if (Copy_u8LineNumber < 16)
	{
		switch (Copy_u8Triggre)
		{
		case RISING_EDGE:	SET_BIT(EXTI_Pointer_Reg->EXTI_RTSR, Copy_u8LineNumber); CLR_BIT(EXTI_Pointer_Reg->EXTI_FTSR, Copy_u8LineNumber); break;
		case FALLING_EDGE:	CLR_BIT(EXTI_Pointer_Reg->EXTI_RTSR, Copy_u8LineNumber); SET_BIT(EXTI_Pointer_Reg->EXTI_FTSR, Copy_u8LineNumber); break;
		case ON_CHANGE:		SET_BIT(EXTI_Pointer_Reg->EXTI_RTSR, Copy_u8LineNumber); SET_BIT(EXTI_Pointer_Reg->EXTI_FTSR, Copy_u8LineNumber); break;
		default: /*Return Error*/ break;
		}
	}
}
void MEXTI_voidClearInterruptFlag(u8 Copy_u8LineNumber)
{
	SET_BIT(EXTI_Pointer_Reg->EXTI_PR, Copy_u8LineNumber);
}
void MEXTI_voidTriggerSWInterrupt(u8 Copy_u8LineNumber)
{
	EXTI_Pointer_Reg->EXTI_SWIER = 0x0;
	if (Copy_u8LineNumber < 16)
	{
		SET_BIT(EXTI_Pointer_Reg->EXTI_SWIER, Copy_u8LineNumber);
	}
}
void MSYSCFG_SelectLineInput(u8 Copy_u8Port,u8 Copy_u8LineNum)
{
	if(Copy_u8LineNum<16)
	{
		SYSCFG_EXTICR[Copy_u8LineNum / 4] &= ~(0b1111<< (4 * (Copy_u8LineNum % 4)));
		SYSCFG_EXTICR[Copy_u8LineNum / 4] |= ((Copy_u8Port) << (4 * (Copy_u8LineNum % 4)));
	}
}

void Set_Callback(u8 line_num, void (*ptr)(void))
{
	if (line_num<16)
	{
		switch (line_num)
		{
			case 0:  EXTI0_Callback_PTR  = ptr; break;
			case 1:  EXTI1_Callback_PTR  = ptr; break;
			case 2:  EXTI2_Callback_PTR  = ptr; break;
			case 3:  EXTI3_Callback_PTR  = ptr; break;
			case 4:  EXTI4_Callback_PTR  = ptr; break;
			case 5:  EXTI5_Callback_PTR  = ptr; break;
			case 6:  EXTI6_Callback_PTR  = ptr; break;
			case 7:  EXTI7_Callback_PTR  = ptr; break;
			case 8:  EXTI8_Callback_PTR  = ptr; break;
			case 9:	 EXTI9_Callback_PTR  = ptr; break;
			case 10: EXTI10_Callback_PTR = ptr; break;
			case 11: EXTI11_Callback_PTR = ptr; break;
			case 12: EXTI12_Callback_PTR = ptr; break;
			case 13: EXTI13_Callback_PTR = ptr; break;
			case 14: EXTI14_Callback_PTR = ptr; break;
			case 15: EXTI15_Callback_PTR = ptr; break;
		}
	}
}
void EXTI0_IRQHandler(void)/*IRQ for INT request*/
{
	if(EXTI0_Callback_PTR)
		EXTI0_Callback_PTR();
	MEXTI_voidClearInterruptFlag(0);
}
void EXTI1_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI1_Callback_PTR)
		EXTI1_Callback_PTR();
	MEXTI_voidClearInterruptFlag(1);
}
void EXTI2_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI2_Callback_PTR)
		EXTI2_Callback_PTR();
	MEXTI_voidClearInterruptFlag(2);
}
void EXTI3_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI3_Callback_PTR)
		EXTI3_Callback_PTR();
	MEXTI_voidClearInterruptFlag(3);
}
void EXTI4_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI4_Callback_PTR)
		EXTI4_Callback_PTR();
	MEXTI_voidClearInterruptFlag(4);
}
void EXTI5_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI5_Callback_PTR)
		EXTI5_Callback_PTR();
	MEXTI_voidClearInterruptFlag(5);
}
void EXTI6_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI6_Callback_PTR)
		EXTI6_Callback_PTR();
	MEXTI_voidClearInterruptFlag(6);
}
void EXTI7_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI7_Callback_PTR)
		EXTI7_Callback_PTR();
	MEXTI_voidClearInterruptFlag(7);
}
void EXTI8_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI8_Callback_PTR)
		EXTI8_Callback_PTR();
	MEXTI_voidClearInterruptFlag(8);
}
void EXTI9_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI9_Callback_PTR)
		EXTI9_Callback_PTR();
	MEXTI_voidClearInterruptFlag(9);
}
void EXTI10_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI10_Callback_PTR)
		EXTI10_Callback_PTR();
	MEXTI_voidClearInterruptFlag(10);
}
void EXTI11_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI11_Callback_PTR)
		EXTI11_Callback_PTR();
	MEXTI_voidClearInterruptFlag(11);
}
void EXTI12_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI12_Callback_PTR)
		EXTI12_Callback_PTR();
	MEXTI_voidClearInterruptFlag(12);
}
void EXTI13_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI13_Callback_PTR)
		EXTI13_Callback_PTR();
	MEXTI_voidClearInterruptFlag(13);
}
void EXTI14_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI14_Callback_PTR)
		EXTI14_Callback_PTR();
	MEXTI_voidClearInterruptFlag(14);
}
void EXTI15_IRQHandler(void)/* IRQ for INT request */
{
	if (EXTI15_Callback_PTR)
		EXTI15_Callback_PTR();
	MEXTI_voidClearInterruptFlag(15);
}
