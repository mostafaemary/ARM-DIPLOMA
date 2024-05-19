/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 06 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#ifndef EXTI_Private_H
#define EXTI_Private_H
/* Register Definitions */
/* System Configuration Registers */
#define SYSCFG_EXTICR_PTR	0x40013808
u32* SYSCFG_EXTICR = (u32*)SYSCFG_EXTICR_PTR;


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
