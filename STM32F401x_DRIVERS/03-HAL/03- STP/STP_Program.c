/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 11 May 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "MGPIO_Interface.h"
#include "STP_Interface.h"
#include "STP_Private.h"
#include "STP_Config.h"
void HSTP_voidSendSynchronous(u8 Copy_u8DataToSend)
{
	/* Send bit by bit starting from MSB */
	s8 Local_s8Counter;
	u8 Localu8Data;
	for (Local_s8Counter =7;Local_s8Counter>=0;Local_s8Counter--)
	{
		/* I Need to get the 7th Bit in the variable Copy_u8DataToSend */
		Localu8Data = GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		GPIO_voidSetPinValue(HSTP_SERIAL_DATA, Localu8Data);
		/* Produce Pulse (High - delay - low) in the HSTP_SHIFT_CLOCK So ShiftReg can shiftingLeft itself and read the serial line */
		GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, HIGH);
		MSTK_voidSetBusyWait(10);
		GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, LOW);
		MSTK_voidSetBusyWait(10);
	}
	/* Produce Pulse (High - delay - low) in the HSTP_STORAGE_CLOCK So Data will copied to Storage Reg and Transfered to the Parallel Pins */
			GPIO_voidSetPinValue(HSTP_STORAGE_CLOCK, HIGH);
			MSTK_voidSetBusyWait(10);
			GPIO_voidSetPinValue(HSTP_STORAGE_CLOCK, LOW);
			MSTK_voidSetBusyWait(10);
}
