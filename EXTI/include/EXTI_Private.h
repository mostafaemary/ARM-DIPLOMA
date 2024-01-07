/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 06 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#ifndef EXTI_Private_H
#define EXTI_Private_H




/*#define LINE1		1
	*#define LINE2		2
	*#define LINE3		3
	*#define LINE4		4
	*#define LINE5		5
	*#define LINE6		6
	*#define LINE7		7
	*#define LINE8		8
	*#define LINE9		9
	*#define LINE10		10
	*#define LINE11		11
	*#define LINE12		12
	*#define LINE13		13
	*#define LINE14		14
	*#define LINE15		15
	*#define LINE16		16
*/
/* Register Definitions */
#define EXTI_BASE_ADDRESS		0x40013C00
typedef struct MEMORY_MAP
{
	vu32 EXTI_IMR;
	vu32 EXTI_EMR;
	vu32 EXTI_RTSR;
	vu32 EXTI_FTSR;
	vu32 EXTI_SWIER;
	vu32 EXTI_PR;


}EXTI_MEMORY_MAP_t;
#define EXTI_Pointer_Reg ((volatile EXTI_MEMORY_MAP_t *)EXTI_BASE_ADDRESS)
#endif
