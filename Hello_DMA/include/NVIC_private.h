/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 11 Dec 2023                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
/* Register Definitions */
#define NVIC_BASE 0xE000E100//0xE000E100
#define NVIC_ISER0 *((vu32*)(NVIC_BASE + 0x00))
#define NVIC_ISER1 *((vu32*)(NVIC_BASE + 0x04))
#define NVIC_ISER2 *((vu32*)(NVIC_BASE + 0x08))
#define NVIC_ICER0 *((vu32*)(NVIC_BASE + 0x80))
#define NVIC_ICER1 *((vu32*)(NVIC_BASE + 0x84))
#define NVIC_ICER2 *((vu32*)(NVIC_BASE + 0x88))
#define NVIC_ISPR0 *((vu32*)(NVIC_BASE + 0x100))
#define NVIC_ISPR1 *((vu32*)(NVIC_BASE + 0x104))
#define NVIC_ISPR2 *((vu32*)(NVIC_BASE + 0x108))
#define NVIC_ICPR0 *((vu32*)(NVIC_BASE + 0x180))
#define NVIC_ICPR1 *((vu32*)(NVIC_BASE + 0x184))
#define NVIC_ICPR2 *((vu32*)(NVIC_BASE + 0x188))
#define NVIC_IABR0 *((vu32*)(NVIC_BASE + 0x200))
#define NVIC_IABR1 *((vu32*)(NVIC_BASE + 0x204))
#define NVIC_IABR2 *((vu32*)(NVIC_BASE + 0x208))
#define NVIC_IPR ((vu8*)(NVIC_BASE + 0x300))



/*Priority BITs Configurations*/
#define MNVIC_GROUP_4_SUB_0		0x05FA0300
#define MNVIC_GROUP_3_SUB_1		0x05FA0400
#define MNVIC_GROUP_2_SUB_2		0x05FA0500
#define MNVIC_GROUP_1_SUB_3		0x05FA0600
#define MNVIC_GROUP_0_SUB_4		0x05FA0700


/* private macros */
#endif
