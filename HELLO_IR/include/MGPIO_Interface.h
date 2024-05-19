/* ***************************************************************** */
/* Author      : Mostafa Emary                                       */
/* Date        : 22 NOV 2023                                         */
/* Version     : V01                                                 */
/* ***************************************************************** */

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

typedef struct configuration_parameters
{
	u8 Port_Name;
	u8 Pin_Num;
	u8 I_O_A_A_Mode;/* (Input_Mode/Output_Mode/Alternate_Func_Mode/Analog_Mode) */
	u8 OutType;/*(Output_Push_Pull/Output_Open_Drain)*/
	u8 Out_Speed;/*(Output_Low_Speed/Output_Medium_Speed/Output_High_Speed/Output_VeryHigh_Speed)*/
	u8 In_Modes;/*(Floating/Pull_Up/Pull_Down)*/
}Config_parameters_t;

//void GPIO_voidConfigurePinDirection(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinMode);
void GPIO_voidConfigurePinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_PinDirectin);
void GPIO_voidConfigureOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputType);
void GPIO_voidConfigureOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed);
void GPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_OutputValue);
void GPIO_voidConfigureInpytType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8InputType);
u8 	 GPIO_u8ReadPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
void GPIO_LockPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
void GPIO_voidConfigurePorting(Config_parameters_t* Copy_Config_parameters_tPToStruct);
void GPIO_voidSetOutputConfigurations(u8 Copy_u8PortName, u8 Copy_u8PinNumber,u8 Copy_u8OutputType,u8 Copy_u8OutputSpeed);
void GPIO_voidSetInputConfigurations(u8 Copy_u8PortName, u8 Copy_u8PinNumber,u8 Copy_u8InputType);
void MGPIO_voidToggle_Pin(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
#define GPIOA 	0
#define GPIOB 	1
#define GPIOC 	2
/* ************* */
#define P0		0
#define P1		1
#define P2		2
#define P3		3
#define P4		4
#define P5		5
#define P6		6
#define P7		7
#define P8		8
#define P9		9
#define P10		10
#define P11		11
#define P12		12
#define P13		13
#define P14		14
#define P15		15
#define GPIO(X,Y) GPIO##X,P##Y



/* Configuration Options */


/* Configure Direction Options */
#define Input_Mode				0b00
#define Output_Mode			   	0b01
#define Alternate_Func_Mode		0b10
#define Analog_Mode				0b11

/* Output Push Pull Modes (Output Types) */
#define Output_Push_Pull		0b0
#define Output_Open_Drain		0b1

/* Output Speed */
#define Output_Low_Speed		0b00
#define Output_Medium_Speed		0b01
#define Output_High_Speed		0b10
#define Output_VeryHigh_Speed	0b11

/* Input Modes */
#define Floating		0b00
#define Pull_Up			0b01
#define Pull_Down		0b10








/* Input Modes
#define Analog_Mode				0x0
#define Floating_Input			0x4
#define Input_With_PUP_PDown	0x8
Output Push Pull Modes
*#define Output_PP_10MHZ			0x1
*#define Output_PP_2MHZ			0x2
*#define Output_PP_50MHZ			0x3
Output Open Drain Modes
#define Output_OD_10MHZ		 	0x5
#define Output_OD_2MHZ			0x6
#define Output_OD_50MHZ			0x7
Alternative Function Output Push Pull Modes
#define Output_AF_PP_10MHZ		0x9
#define Output_AF_PP_2MHZ		0xA
#define Output_AF_PP_50MHZ		0xB
Alternative Function Output Open Drain Modes
#define Output_AF_OD_10MHZ		0xD
#define Output_AF_OD_2MHZ		0xE
#define Output_AF_OD_50MHZ		0xF
*/
#define HIGH					1
#define LOW						0
#endif
