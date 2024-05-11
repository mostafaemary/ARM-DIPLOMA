/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 01 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#ifndef SYSTIC_PRIVATE_H
#define SYSTIC_PRIVATE_H
/* Register Definitions */
#define SysTimer_BASE		0xE000E010
#define STK_CTRL			*((vu32*)(SysTimer_BASE+0x00))
#define STK_LOAD			*((vu32*)(SysTimer_BASE+0x04))
#define STK_VAL				*((vu32*)(SysTimer_BASE+0x08))
#define STK_CALIB			*((vu32*)(SysTimer_BASE+0x0C))


#endif
