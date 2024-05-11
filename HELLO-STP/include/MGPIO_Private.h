#ifndef _GPIO_P_H
#define _GPIO_P_H
#define GPIOA_BASE_ADDRESS		0x40020000
#define GPIOB_BASE_ADDRESS		0x40020400
#define GPIOC_BASE_ADDRESS		0x40020800
typedef struct MEMORY_MAP
{
	vu32 GPIO_MODER;
	vu32 GPIO_OTYPER;
	vu32 GPIO_OSPEEDR;
	vu32 GPIO_PUPDR;
	vu32 GPIO_IDR;
	vu32 GPIO_ODR;
	vu32 GPIO_BSRR;
	vu32 GPIO_LCKR;
	vu32 GPIO_AFRL;
	vu32 GPIO_AFRH;
}GPIO_MemoryMap_t;
#define GPIOA_Pointer_Reg	((volatile GPIO_MemoryMap_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB_Pointer_Reg	((volatile GPIO_MemoryMap_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC_Pointer_Reg	((volatile GPIO_MemoryMap_t*)(GPIOC_BASE_ADDRESS))
#endif
