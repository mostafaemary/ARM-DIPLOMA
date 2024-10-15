/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 06 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#ifndef EXTI_Interface_H
#define EXTI_Interface_H
#define LINE(X) X
#define RISING_EDGE		0
#define FALLING_EDGE	1
#define ON_CHANGE		2

void MEXTI_voidInit(void);
/* Trigger Manipulation
	* 0 Means Rising Edge
	* 1 Means Falling Edge
	* 2 Means On Change
*/
void MEXTI_voidEnableLineAndSelectTrigger(u8 Copy_u8Triggre, u8 Copy_u8LineNumber);//assumed Portname
void MEXTI_voidEnableLine(u8 Copy_u8LineNumber);
void MEXTI_voidDisableLine(u8 Copy_u8LineNumber);
void MEXTI_voidSetTriggreType(u8 Copy_u8Triggre, u8 Copy_u8LineNumber);
void MEXTI_voidTriggerSWInterrupt(u8 Copy_u8LineNumber);
void MEXTI_voidClearInterruptFlag(u8 Copy_u8LineNumber);


/* Select Which Port Produce The Trigger */
/* If you want to remap the EXTIRQ to another Pin => first you must enable clock for SYSCFG Peripheral */
/* If no need to Remap The Line To another Pin =>it's no need to Access the SYSCFG Reg or enabling it's Clock*/
#define PORTA_MAP	0
#define PORTB_MAP	1
#define PORTC_MAP	2
void MSYSCFG_SelectLineInput(u8 Copy_u8Port, u8 Copy_u8LineNum);


void Set_Callback(u8 line_num, void (*ptr)(void));
#endif



