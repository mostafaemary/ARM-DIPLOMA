/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 11 Dec 2023                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		NVIC_ISER2 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/*Return Error*/
	}
}
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		NVIC_ICER2 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/*Return Error*/
	}
}
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		NVIC_ISPR2 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/*Return Error*/
	}
}
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		NVIC_ICPR2 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/*Return Error*/
	}
}
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Active_Result;
	if (Copy_u8IntNumber <= 31)
	{
		Active_Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		Active_Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		Active_Result = GET_BIT(NVIC_IABR2, Copy_u8IntNumber);
	}
	else
	{
		/*Return Error*/
	}
	return Active_Result;
}
void MVIC_voidInit(void)
{
#define SCB_AIRCR *((vu32*)0xE000ED0C)
	SCB_AIRCR = SELECT_PRIORITY_CONFIGS;
}
void MNVIC_voidSetPrioruty(u8 Copy_u8InID, u8 Copy_u8Priority)
{
	if (Copy_u8InID <= 83)
	{
		NVIC_IPR[Copy_u8InID] = Copy_u8Priority;
	}
}