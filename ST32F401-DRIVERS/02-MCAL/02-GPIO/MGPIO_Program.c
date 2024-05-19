/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 22 NOV 2023                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_Interface.h"
#include "MGPIO_Private.h"
#include "MGPIO_Config.h"
void GPIO_voidConfigurePinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_PinDirectin)
{
	switch (Copy_u8PortName)
	{
	case GPIOA:
		if (Copy_u8PinNumber <= 15)
		{
			GPIOA_Pointer_Reg->GPIO_MODER &= ~(0b11 << (Copy_u8PinNumber * 2));
			GPIOA_Pointer_Reg->GPIO_MODER |= (Copy_PinDirectin << (Copy_u8PinNumber * 2));
		}
		else {/*Return Error*/ }
		break;
	case GPIOB:
		if (Copy_u8PinNumber <= 15)
		{

			GPIOB_Pointer_Reg->GPIO_MODER &= ~(0b11 << (Copy_u8PinNumber * 2));
			GPIOB_Pointer_Reg->GPIO_MODER |= (Copy_PinDirectin << (Copy_u8PinNumber * 2));
		}
		else {/*Return Error*/ }
		break;
	case GPIOC:
		if ((Copy_u8PinNumber >= 13) && (Copy_u8PinNumber <= 15))
		{
			GPIOC_Pointer_Reg->GPIO_MODER &= ~(0b11 << (Copy_u8PinNumber * 2));
			GPIOC_Pointer_Reg->GPIO_MODER |= (Copy_PinDirectin << (Copy_u8PinNumber * 2));
		}
		else {/*Return Error*/ }
		break;
	}
}

void GPIO_voidConfigureInpytType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8InputType)
{
	switch (Copy_u8PortName)
	{
	case GPIOA:
		if (Copy_u8PinNumber <= 15)
		{

			GPIOA_Pointer_Reg->GPIO_PUPDR &= ~(0b11 << (Copy_u8PinNumber * 2));
			GPIOA_Pointer_Reg->GPIO_PUPDR |= (Copy_u8InputType << (Copy_u8PinNumber * 2));
		}
		else {/*Return Error*/ }
		break;
	case GPIOB:
		if (Copy_u8PinNumber <= 15)
		{

			GPIOB_Pointer_Reg->GPIO_PUPDR &= ~(0b11 << (Copy_u8PinNumber * 2));
			GPIOB_Pointer_Reg->GPIO_PUPDR |= (Copy_u8InputType << (Copy_u8PinNumber * 2));
		}
		else {/*Return Error*/ }
		break;
	case GPIOC:
		if ((Copy_u8PinNumber >= 13) && (Copy_u8PinNumber <= 15))
		{
			GPIOC_Pointer_Reg->GPIO_PUPDR &= ~(0b11 << (Copy_u8PinNumber * 2));
			GPIOC_Pointer_Reg->GPIO_PUPDR |= (Copy_u8InputType << (Copy_u8PinNumber * 2));
		}
		else {/*Return Error*/ }
		break;
	}
}


void GPIO_voidConfigureOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputType)
{
	if (Copy_u8OutputType == Output_Open_Drain)
	{
		switch (Copy_u8PortName)
		{
		case GPIOA:
			if (Copy_u8PinNumber <= 15)
			{
				SET_BIT(GPIOA_Pointer_Reg->GPIO_OTYPER, Copy_u8PinNumber);
			}
			else {/*Return Error*/ }
			break;
		case GPIOB:
			if (Copy_u8PinNumber <= 15)
			{
				SET_BIT(GPIOB_Pointer_Reg->GPIO_OTYPER, Copy_u8PinNumber);
			}
			else {/*Return Error*/ }
			break;
		case GPIOC:
			if ((Copy_u8PinNumber >= 13) && (Copy_u8PinNumber <= 15))
			{
				SET_BIT(GPIOC_Pointer_Reg->GPIO_OTYPER, Copy_u8PinNumber);
			}
			else {/*Return Error*/ }
			break;
		}
	}
	if (Copy_u8OutputType == Output_Push_Pull)
	{
		switch (Copy_u8PortName)
		{
		case GPIOA:
			if (Copy_u8PinNumber <= 15)
			{
				CLR_BIT(GPIOA_Pointer_Reg->GPIO_OTYPER, Copy_u8PinNumber);
			}
			else {/*Return Error*/ }
			break;
		case GPIOB:
			if (Copy_u8PinNumber <= 15)
			{
				CLR_BIT(GPIOB_Pointer_Reg->GPIO_OTYPER, Copy_u8PinNumber);
			}
			else {/*Return Error*/ }
			break;
		case GPIOC:
			if ((Copy_u8PinNumber >= 13) && (Copy_u8PinNumber <= 15))
			{
				CLR_BIT(GPIOC_Pointer_Reg->GPIO_OTYPER, Copy_u8PinNumber);
			}
			else {/*Return Error*/ }
			break;
		}
	}
}
void GPIO_voidConfigureOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed)
{
	switch (Copy_u8PortName)
	{
	case GPIOA:
		if (Copy_u8PinNumber <= 15)
		{
			GPIOA_Pointer_Reg->GPIO_OSPEEDR &= ~(0b11 << (Copy_u8PinNumber * 2));
			GPIOA_Pointer_Reg->GPIO_OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinNumber * 2));
		}
		else {/*Return Error*/ }
		break;
	case GPIOB:
		if (Copy_u8PinNumber <= 15)
		{
			GPIOB_Pointer_Reg->GPIO_OSPEEDR &= ~(0b11 << (Copy_u8PinNumber * 2));
			GPIOB_Pointer_Reg->GPIO_OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinNumber * 2));
		}
		else {/*Return Error*/ }
		break;
	case GPIOC:
		if ((Copy_u8PinNumber >= 13) && (Copy_u8PinNumber <= 15))
		{
			GPIOC_Pointer_Reg->GPIO_OSPEEDR &= ~(0b11 << (Copy_u8PinNumber * 2));
			GPIOC_Pointer_Reg->GPIO_OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinNumber * 2));
		}
		else {/*Return Error*/ }
		break;
	}
}

void GPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_OutputValue)
{
	if (Copy_u8PinNumber <= 15)
	{

		switch (Copy_u8PortName)
		{
		case GPIOA:
			if (Copy_OutputValue == HIGH)
			{
				SET_BIT(GPIOA_Pointer_Reg->GPIO_ODR, Copy_u8PinNumber);
			}
			if (Copy_OutputValue == LOW)
			{
				CLR_BIT(GPIOA_Pointer_Reg->GPIO_ODR, Copy_u8PinNumber);
			}
			break;
		case GPIOB:
			if (Copy_OutputValue == HIGH)
			{
				SET_BIT(GPIOB_Pointer_Reg->GPIO_ODR, Copy_u8PinNumber);
			}
			if (Copy_OutputValue == LOW)
			{
				CLR_BIT(GPIOB_Pointer_Reg->GPIO_ODR, Copy_u8PinNumber);
			}
			break;
		case GPIOC:
			if (Copy_OutputValue == HIGH)
			{
				SET_BIT(GPIOC_Pointer_Reg->GPIO_ODR, Copy_u8PinNumber);
			}
			if (Copy_OutputValue == LOW)
			{
				CLR_BIT(GPIOC_Pointer_Reg->GPIO_ODR, Copy_u8PinNumber);
			}
			break;
		}
	}
	else
	{/*return error*/
	}
}
u8 GPIO_u8ReadPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{

	if (Copy_u8PinNumber <= 15)
	{
		u8 Status = 0;
		switch (Copy_u8PortName)
		{
		case GPIOA:	Status = GET_BIT(GPIOA_Pointer_Reg->GPIO_IDR, Copy_u8PinNumber);	break;
		case GPIOB:	Status = GET_BIT(GPIOB_Pointer_Reg->GPIO_IDR, Copy_u8PinNumber);	break;
		case GPIOC:	Status = GET_BIT(GPIOC_Pointer_Reg->GPIO_IDR, Copy_u8PinNumber);	break;
		}
		return Status;
	}
	return 5;/*5 is an error indecation*/
}

void GPIO_LockPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	switch (Copy_u8PortName)
	{
	case GPIOA:
		if (Copy_u8PinNumber <= 15)
		{
			CLR_BIT(GPIOA_Pointer_Reg->GPIO_LCKR, 16);
			SET_BIT(GPIOA_Pointer_Reg->GPIO_LCKR, Copy_u8PinNumber);
		}
		else {/*Return Error*/ }
		break;
	case GPIOB:
		if (Copy_u8PinNumber <= 15)
		{
			CLR_BIT(GPIOB_Pointer_Reg->GPIO_LCKR, 16);
			SET_BIT(GPIOB_Pointer_Reg->GPIO_LCKR, Copy_u8PinNumber);
		}
		else {/*Return Error*/ }
		break;
	case GPIOC:
		if ((Copy_u8PinNumber >= 13) && (Copy_u8PinNumber <= 15))
		{
			CLR_BIT(GPIOC_Pointer_Reg->GPIO_LCKR, 16);
			SET_BIT(GPIOC_Pointer_Reg->GPIO_LCKR, Copy_u8PinNumber);
		}
		else {/*Return Error*/ }
		break;
	}
}
void GPIO_voidConfigurePorting(Config_parameters_t* Copy_Config_parameters_tPToStruct)
{
	GPIO_voidConfigurePinDirection(Copy_Config_parameters_tPToStruct->Port_Name, Copy_Config_parameters_tPToStruct->Pin_Num, Copy_Config_parameters_tPToStruct->I_O_A_A_Mode);
	GPIO_voidConfigureOutputType(Copy_Config_parameters_tPToStruct->Port_Name, Copy_Config_parameters_tPToStruct->Pin_Num, Copy_Config_parameters_tPToStruct->OutType);
	GPIO_voidConfigureOutputSpeed(Copy_Config_parameters_tPToStruct->Port_Name, Copy_Config_parameters_tPToStruct->Pin_Num, Copy_Config_parameters_tPToStruct->Out_Speed);
}



void GPIO_voidSetInputConfigurations(u8 Copy_u8PortName, u8 Copy_u8PinNumber,u8 Copy_u8InputType)
{
	GPIO_voidConfigurePinDirection(Copy_u8PortName,Copy_u8PinNumber, Input_Mode);
	GPIO_voidConfigureInpytType(Copy_u8PortName,Copy_u8PinNumber, Copy_u8InputType);
}
void GPIO_voidSetOutputConfigurations(u8 Copy_u8PortName, u8 Copy_u8PinNumber,u8 Copy_u8OutputType,u8 Copy_u8OutputSpeed)
{
	GPIO_voidConfigurePinDirection  (Copy_u8PortName, Copy_u8PinNumber, Output_Mode);
	GPIO_voidConfigureOutputType	(Copy_u8PortName, Copy_u8PinNumber, Copy_u8OutputType);
	GPIO_voidConfigureOutputSpeed	(Copy_u8PortName, Copy_u8PinNumber, Copy_u8OutputSpeed);
}
void MGPIO_voidToggle_Pin(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	if (Copy_u8PinNumber <= 15)
	{

		switch (Copy_u8PortName)
		{
		case GPIOA:
			TOG_BIT(GPIOA_Pointer_Reg->GPIO_ODR,Copy_u8PinNumber);
			break;
		case GPIOB:
			TOG_BIT(GPIOB_Pointer_Reg->GPIO_ODR,Copy_u8PinNumber);
			break;
		case GPIOC:
			TOG_BIT(GPIOC_Pointer_Reg->GPIO_ODR,Copy_u8PinNumber);
			break;
		}
	}
	else
	{/*return error*/
	}
}
