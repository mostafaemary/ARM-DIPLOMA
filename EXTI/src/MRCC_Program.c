/* ****************************************************************** */
/* Author      : Mostafa Emary                                        */
/* Date        : 27 Dec 2023                                          */
/* Version     : V01                                                  */
/* ****************************************************************** */
#include "STD_TYPES.h"
#include "BIT_MATH.h"	
#include "MRCC_Interface.h"
#include "MRCC_Config.h"
#include "MRCC_Private.h"
void MRCC_voidEnableClock(void)
{
#if RCC_HSE_CRYSTAL == ENABLE
	SET_BIT(RCC_Pointer_Reg->RCC_CR, 19);
	CLR_BIT(RCC_Pointer_Reg->RCC_CR, 16);
	CLR_BIT(RCC_Pointer_Reg->RCC_CR, 18);
	SET_BIT(RCC_Pointer_Reg->RCC_CR, 16);
#endif
#if RCC_HSE_RC == ENABLE
	SET_BIT(RCC_Pointer_Reg->RCC_CR, 19);
	CLR_BIT(RCC_Pointer_Reg->RCC_CR, 16);
	SET_BIT(RCC_Pointer_Reg->RCC_CR, 18);
	SET_BIT(RCC_Pointer_Reg->RCC_CR, 16);
#endif
#if RCC_HSI == ENABLE
	SET_BIT(RCC_Pointer_Reg->RCC_CR, 0);
#endif
#if RCC_PLL == ENABLE
	SET_BIT(RCC_Pointer_Reg->RCC_CR, 24);
#endif
}
void MRCC_voidInitSysClock(void)
{
	/**/
#if RCC_System_Clock_Source == RCC_HSE_CRYSTAL
	MRCC_voidEnableClock();
	SET_BIT(RCC_Pointer_Reg->RCC_CFGR, 0);
	CLR_BIT(RCC_Pointer_Reg->RCC_CFGR, 1);
#endif
}

void MRCC_voidEnablePerClock(u8 MCopy_u8BusId, u8 MCopy_u8PerId)
{
	if (MCopy_u8PerId <= 31)
	{
		/*Swirching For BUS*/
		switch (MCopy_u8BusId)
		{
			/*AHB1ENR is an Enable Reg HOLDs all pripheral ON AHB1*/
		case RCC_AHB1: SET_BIT(RCC_Pointer_Reg->RCC_AHB1ENR, MCopy_u8PerId); 	break;

			/*AHB1ENR is an Enable Reg HOLDs all pripheral ON AHB1*/
		case RCC_AHB2: SET_BIT(RCC_Pointer_Reg->RCC_AHB2ENR, MCopy_u8PerId); 	break;

			/*APB1ENR is an Enable Reg HOLDs all pripheral ON APB1*/
		case RCC_APB1: SET_BIT(RCC_Pointer_Reg->RCC_APB1ENR, MCopy_u8PerId); 	break;

			/*APB2ENR is an Enable Reg HOLDs all pripheral ON APB2*/
		case RCC_APB2: SET_BIT(RCC_Pointer_Reg->RCC_APB2ENR, MCopy_u8PerId); 	break;
		default:
				break;
		}

	}
	else
	{
		/*return error*/
	}

}
void MRCC_voidDisablePerClock(u8 MCopy_u8BusId, u8 MCopy_u8PerId)
{
	if (MCopy_u8PerId <= 31)
	{
		/*Swirching For BUS*/
		switch (MCopy_u8BusId)
		{
			/*AHB1ENR is an Enable Reg HOLDs all pripheral ON AHB1*/
		case RCC_AHB1: CLR_BIT(RCC_Pointer_Reg->RCC_AHB1ENR, MCopy_u8PerId); break;

			/*AHB1ENR is an Enable Reg HOLDs all pripheral ON AHB1*/
		case RCC_AHB2: CLR_BIT(RCC_Pointer_Reg->RCC_AHB2ENR, MCopy_u8PerId); 	break;

			/*APB1ENR is an Enable Reg HOLDs all pripheral ON APB1*/
		case RCC_APB1: CLR_BIT(RCC_Pointer_Reg->RCC_APB1ENR, MCopy_u8PerId); 	break;

			/*APB2ENR is an Enable Reg HOLDs all pripheral ON APB2*/
		case RCC_APB2: CLR_BIT(RCC_Pointer_Reg->RCC_APB2ENR, MCopy_u8PerId); 	break;
		default:
			break;
		}

	}
	else
	{
		/*return error*/
	}
}
