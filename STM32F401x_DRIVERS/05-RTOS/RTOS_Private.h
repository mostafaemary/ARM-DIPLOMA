/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 16 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#ifndef RTOS_Private_H
#define RTOS_Private_H
typedef struct 
{
	void (*TaskHandler)(void);
	u8 Periodicity;
	u8 FirstDelay;
	u8 TaskRunState;
}Task;


#endif