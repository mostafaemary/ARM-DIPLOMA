/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 11 Dec 2023                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MVIC_voidInit(void);
void MNVIC_voidSetPrioruty(u8 Copy_u8InID, u8 Copy_u8Priority);
#endif
