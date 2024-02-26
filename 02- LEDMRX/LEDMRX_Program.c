/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 11 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "MGPIO_Interface.h"
#include "LEDMRX_Interface.h"
#include "LEDMRX_Private.h"
#include "LEDMRX_Config.h"
void HLEDMRX_voidInit(void)
{
	GPIO_voidConfigurePinDirection(ROW0, Output_Mode); GPIO_voidConfigureOutputType(ROW0, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(ROW0, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(ROW1, Output_Mode); GPIO_voidConfigureOutputType(ROW1, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(ROW1, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(ROW2, Output_Mode); GPIO_voidConfigureOutputType(ROW2, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(ROW2, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(ROW3, Output_Mode); GPIO_voidConfigureOutputType(ROW3, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(ROW3, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(ROW4, Output_Mode); GPIO_voidConfigureOutputType(ROW4, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(ROW4, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(ROW5, Output_Mode); GPIO_voidConfigureOutputType(ROW5, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(ROW5, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(ROW6, Output_Mode); GPIO_voidConfigureOutputType(ROW6, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(ROW6, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(ROW7, Output_Mode); GPIO_voidConfigureOutputType(ROW7, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(ROW7, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(COL0, Output_Mode); GPIO_voidConfigureOutputType(COL0, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(COL0, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(COL1, Output_Mode); GPIO_voidConfigureOutputType(COL1, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(COL1, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(COL2, Output_Mode); GPIO_voidConfigureOutputType(COL2, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(COL2, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(COL3, Output_Mode); GPIO_voidConfigureOutputType(COL3, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(COL3, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(COL4, Output_Mode); GPIO_voidConfigureOutputType(COL4, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(COL4, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(COL5, Output_Mode); GPIO_voidConfigureOutputType(COL5, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(COL5, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(COL6, Output_Mode); GPIO_voidConfigureOutputType(COL6, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(COL6, Output_Low_Speed);
	GPIO_voidConfigurePinDirection(COL7, Output_Mode); GPIO_voidConfigureOutputType(COL7, Output_Push_Pull); GPIO_voidConfigureOutputSpeed(COL7, Output_Low_Speed);
}
void HLEDMRX_voidDisplay(u8* Copy_u8Data)
{
	/* Disable all Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Enable Column 0 */
	HLEDMRX_voidSetRowValues(Copy_u8Data[0]);
	GPIO_voidSetPinValue(COL0, LOW);
	MSTK_voidSetBusyWait(5625);
	/* Disable all Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Enable Column 1 */
	HLEDMRX_voidSetRowValues(Copy_u8Data[1]);
	GPIO_voidSetPinValue(COL1, LOW);
	MSTK_voidSetBusyWait(5625);
	/* Disable all Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Enable Column 2 */
	HLEDMRX_voidSetRowValues(Copy_u8Data[2]);
	GPIO_voidSetPinValue(COL2, LOW);
	MSTK_voidSetBusyWait(5625);
	/* Disable all Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Enable Column 3 */
	HLEDMRX_voidSetRowValues(Copy_u8Data[3]);
	GPIO_voidSetPinValue(COL3, LOW);
	MSTK_voidSetBusyWait(5625);
	/* Disable all Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Enable Column 4 */
	HLEDMRX_voidSetRowValues(Copy_u8Data[4]);
	GPIO_voidSetPinValue(COL4, LOW);
	MSTK_voidSetBusyWait(5625);
	/* Disable all Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Enable Column 5 */
	HLEDMRX_voidSetRowValues(Copy_u8Data[5]);
	GPIO_voidSetPinValue(COL5, LOW);
	MSTK_voidSetBusyWait(5625);
	/* Disable all Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Enable Column 6 */
	HLEDMRX_voidSetRowValues(Copy_u8Data[6]);
	GPIO_voidSetPinValue(COL6, LOW);
	MSTK_voidSetBusyWait(5625);
	/* Disable all Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Enable Column 7 */
	HLEDMRX_voidSetRowValues(Copy_u8Data[7]);
	GPIO_voidSetPinValue(COL7, LOW);
	MSTK_voidSetBusyWait(5625);
}
void HLEDMRX_voidDisableAllColumns(void)
{
	GPIO_voidSetPinValue(COL0, HIGH);
	GPIO_voidSetPinValue(COL1, HIGH);
	GPIO_voidSetPinValue(COL2, HIGH);
	GPIO_voidSetPinValue(COL3, HIGH);
	GPIO_voidSetPinValue(COL4, HIGH);
	GPIO_voidSetPinValue(COL5, HIGH);
	GPIO_voidSetPinValue(COL6, HIGH);
	GPIO_voidSetPinValue(COL7, HIGH);
}
void HLEDMRX_voidSetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8BIT;
	Local_u8BIT = GET_BIT(Copy_u8Value, 0);
	GPIO_voidSetPinValue(ROW0, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 1);
	GPIO_voidSetPinValue(ROW1, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 2);
	GPIO_voidSetPinValue(ROW2, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 3);
	GPIO_voidSetPinValue(ROW3, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 4);
	GPIO_voidSetPinValue(ROW4, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 5);
	GPIO_voidSetPinValue(ROW5, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 6);
	GPIO_voidSetPinValue(ROW6, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 7);
	GPIO_voidSetPinValue(ROW7, Local_u8BIT);
}