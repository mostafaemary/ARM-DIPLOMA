/* ****************************************************************** */
/* Author      : Mostafa Emary                                        */
/* Date        : 27 Dec 2023                                          */
/* Version     : V01                                                  */
/* ****************************************************************** */
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_BASE 0x40023800
typedef struct MemoryMap
{
	vu32 RCC_CR;
	vu32 RCC_PLLCFGR;
	vu32 RCC_CFGR;
	vu32 RCC_CIR;
	vu32 RCC_AHB1RSTR;
	vu32 RCC_AHB2RSTR;
	vu32 Reserved;
	vu32 Reserved2;
	vu32 RCC_APB1RSTR;
	vu32 RCC_APB2RSTR;
	vu32 Reserved3;
	vu32 Reserved4;
	vu32 RCC_AHB1ENR;
	vu32 RCC_AHB2ENR;
	vu32 Reserved5;
	vu32 Reserved6;
	vu32 RCC_APB1ENR;
	vu32 RCC_APB2ENR;
	vu32 Reserved7;
	vu32 Reserved8;
	vu32 RCC_APB1LPENR;
	vu32 RCC_APB2LPENR;
	vu32 Reserved9;
	vu32 Reserved10;
	vu32 RCC_BDCR;
	vu32 RCC_CSR;
	vu32 Reserved11;
	vu32 Reserved12;
	vu32 RCC_SSCGR;
	vu32 RCC_PLLI2SCFGR;
	vu32 Reserved13;
	vu32 RCC_DCKCFGR;
}RCC_MemoryMap_t;
#define RCC_Pointer_Reg ((volatile RCC_MemoryMap_t *)(RCC_BASE))


#endif
