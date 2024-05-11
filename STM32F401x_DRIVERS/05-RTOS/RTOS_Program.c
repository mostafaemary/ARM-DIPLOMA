/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 16 Jan 2024                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#include "STD_TYPES.h"
#include"STD_LIB.h"
#include"STK_interface.h"
#include"RTOS_Interface.h"
#include"RTOS_Config.h"
#include"RTOS_Private.h"


Task SystemTasks[MAX_NUM_OF_TASKS] = { 0 }	;
u8 TaskTiming[MAX_NUM_OF_TASKS]				;	
Task Empty = { 0 }							;
EN_RTOSError_t RTOS_CreateTask(void(*Copy_Handler)(void), u8 Copy_u8Periodicity, u8 Copy_u8Priority,u8 Copy_u8FirstDelay)
{
	/* check if priority is correct? */
	if (Copy_u8Priority < MAX_NUM_OF_TASKS)
	{
		if (SystemTasks[Copy_u8Priority].Task_Handler == 0)/* Free Location? */
		{
			TaskRunState=
			SystemTasks[Copy_u8Priority].Task_Handler = Copy_Handler		;
			SystemTasks[Copy_u8Priority].Periodicity = Copy_u8Periodicity	;
			TaskTiming[Copy_u8Priority] = Copy_u8FirstDelay;
			SystemTasks[Copy_u8Priority].TaskRunState = Running;
			return Creation_Done;
		}
		else
		{
			/* The Requiered Priority Is Reserved */
			return Priority_Reserved;
		}
	}
	else
	{
		WRONG_Priority 
	}
}
void Scheduler(void)
{
	u8 LocalCounter ;
	/* loop for all tasks */
	for (LocalCounter = 0; LocalCounter < MAX_NUM_OF_TASKS; LocalCounter++)
	{
		/* Is there a Registered task?! */
		if (SystemTasks[Copy_u8Priority].Task_Handler != 0)
		{
			/* Check If Task State Is Running */
			if (SystemTasks[Copy_u8Priority].TaskRunState = Running)
			{
				if (TaskTiming[LocalCounter] == 0)
				{
					/* Run Task */
					SystemTasks[LocalCounter].Task_Handler();
					/* Reload Periodicity */
					TaskTiming[LocalCounter] = SystemTasks[LocalCounter].Periodicity;
				}
				else
				{
					TaskTiming[LocalCounter]--;
				}
			}
			
		}
	}
}
EN_terminalError_t RTOS_DeleteTask(u8 Copy_u8Priority)
{
	if (SystemTasks[Copy_u8Priority].Task_Handler == 0)/* Free Location? */
	{
		/* Task Exist */
		/* Task Removal */
		SystemTasks[Copy_u8Priority] = Empty;
		return Task_Deleted_Successfully;
	}
	else
	{
		return Task_Not_Exist;
	}
}
EN_terminalError_t RTOS_SuspendTask(u8 Copy_u8Priority)
{
	if (SystemTasks[Copy_u8Priority].Task_Handler == 0)/* Free Location? */
	{
		/* Task Exist */
		/* Task Removal */
		SystemTasks[Copy_u8Priority].TaskRunState = Suspended;
		return Task_Is_Suspended;
	}
	else
	{
		return Task_Not_Exist;
	}
}
EN_terminalError_t RTOS_ResumeTask(u8 Copy_u8Priority)
{
	if (SystemTasks[Copy_u8Priority].Task_Handler == 0)/* Free Location? */
	{
		/* Task Exist */
		/* Task Removal */
		SystemTasks[Copy_u8Priority].TaskRunState = Running;
		return Task_Is_Running;
	}
	else
	{
		return Task_Not_Exist;
	}
}
void RTOS_voidStartOS(void)
{
	MSTK_voidSetIntervalPeriodic(TickTime, Scheduler);
}





