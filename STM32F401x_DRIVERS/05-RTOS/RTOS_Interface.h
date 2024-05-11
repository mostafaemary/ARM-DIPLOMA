/*/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 16 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#ifndef RTOS_Interface_H
#define RTOS_Interface_H
typedef enum EN_RTOSError_t
{
	Creation_Done,
	WRONG_Priority, 
	Priority_Reserved,
	Task_Deleted_Successfully,
	Task_Not_Exist,
	Task_Is_Suspended,
	Task_Is_Running
}EN_RTOSError_t;
typedef enum EN_RTOS_Run_Status_t
{
	Suspended,
	Running
}EN_RTOS_Run_Status_t;

EN_terminalError_t RTOS_CreateTask(void(*Copy_Handler)(void), u8 Copy_u8Periodicity, u8 Copy_u8Priority, u8 Copy_u8FirstDelay);
void Scheduler(void);
EN_terminalError_t RTOS_DeleteTask(u8 Copy_u8Priority);
EN_terminalError_t RTOS_SuspendTask(u8 Copy_u8Priority);
EN_terminalError_t RTOS_SuspendTask(u8 Copy_u8Priority);
EN_terminalError_t RTOS_ResumeTask(u8 Copy_u8Priority);
#endif