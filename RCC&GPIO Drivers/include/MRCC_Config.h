/* ****************************************************************** */
/* Author      : Mostafa Emary                                        */
/* Date        : 27 Dec 2023                                          */
/* Version     : V01                                                  */
/* ****************************************************************** */
#ifndef MRCC_Confic_H
#define MRCC_Confic_H
/* System Clock Options:
* RCC_HSE_CRYSTAL
* RCC_HSE_RC
* RCC_PLL
* RCC_HSI */
/* The User Can Configure The following Line as Needed*/


/* Clock Sources ON/OFF */
#define RCC_HSE_CRYSTAL	ENABLE
#define RCC_HSE_RC		DISABLE
#define RCC_HSI			DISABLE
#define RCC_PLL			DISABLE

#define RCC_System_Clock_Source	RCC_HSE_CRYSTAL

#if RCC_System_Clock_Source == RCC_PLL
/* PLL Input Options:
* RCC_HSE_DIV_2
* RCC_HSE
* RCC_HSI_DIV_2	*/
#define RCC_PLL_INPUT	RCC_HSE_DIV_2/*Choose your PLL Input*/
/* Choose Value between 2-->63 */
#define RCC_PLL_MVAL	2/*Choose Your PLL Multiplier*/
#endif
#endif
