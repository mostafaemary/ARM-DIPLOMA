void LED0(void)
{
	/* Toggle Pin A0 */
	GPIO_voidConfigurePinDirection(GPIOA, P0,Output_Mode);
	GPIO_voidConfigureOutputType(GPIOA,P0, Output_Push_Pull);
	GPIO_voidConfigureOutputSpeed(GPIOA,P0, Output_Low_Speed);
	TOG_BIT(GPIO_ODR, 0);
}
void LED1(void)
{
	/* Toggle Pin A0 */
	GPIO_voidConfigurePinDirection(GPIOA, P1, Output_Mode);
	GPIO_voidConfigureOutputType(GPIOA, P1, Output_Push_Pull);
	GPIO_voidConfigureOutputSpeed(GPIOA, P1, Output_Low_Speed);
	TOG_BIT(GPIO_ODR, 1);
}
void LED2(void)
{
	/* Toggle Pin A0 */
	GPIO_voidConfigurePinDirection(GPIOA, P2, Output_Mode);
	GPIO_voidConfigureOutputType(GPIOA, P2, Output_Push_Pull);
	GPIO_voidConfigureOutputSpeed(GPIOA, P2, Output_Low_Speed);
	TOG_BIT(GPIO_ODR, 2);
}
void LED3(void)
{
	/* Toggle Pin A0 */
	GPIO_voidConfigurePinDirection(GPIOA, P3, Output_Mode);
	GPIO_voidConfigureOutputType(GPIOA, P3, Output_Push_Pull);
	GPIO_voidConfigureOutputSpeed(GPIOA, P3, Output_Low_Speed);
	TOG_BIT(GPIO_ODR, 3);
}
void LED4(void)
{
	/* Toggle Pin A0 */
	GPIO_voidConfigurePinDirection(GPIOA, P4, Output_Mode);
	GPIO_voidConfigureOutputType(GPIOA, P4, Output_Push_Pull);
	GPIO_voidConfigureOutputSpeed(GPIOA, P4, Output_Low_Speed);
	TOG_BIT(GPIO_ODR, 4);
}
void LED5(void)
{
	/* Toggle Pin A0 */
	GPIO_voidConfigurePinDirection(GPIOA, P5, Output_Mode);
	GPIO_voidConfigureOutputType(GPIOA, P5, Output_Push_Pull);
	GPIO_voidConfigureOutputSpeed(GPIOA, P5, Output_Low_Speed);
	TOG_BIT(GPIO_ODR, 5);
}
void LED6(void)
{
	/* Toggle Pin A0 */
	GPIO_voidConfigurePinDirection(GPIOA, P6, Output_Mode);
	GPIO_voidConfigureOutputType(GPIOA, P6, Output_Push_Pull);
	GPIO_voidConfigureOutputSpeed(GPIOA, P6, Output_Low_Speed);
	TOG_BIT(GPIO_ODR, 6);
}
void LED7(void)
{
	/* Toggle Pin A0 */
	GPIO_voidConfigurePinDirection(GPIOA, P7, Output_Mode);
	GPIO_voidConfigureOutputType(GPIOA, P7, Output_Push_Pull);
	GPIO_voidConfigureOutputSpeed(GPIOA, P7, Output_Low_Speed);
	TOG_BIT(GPIO_ODR, 7);
}

void main(void)
{
	(void)RTOS_CreateTask(LED0, 100, 0, 0);
	(void)RTOS_CreateTask(LED1, 150, 1, 0);
	(void)RTOS_CreateTask(LED2, 200, 2, 0);
	(void)RTOS_CreateTask(LED3, 240, 3, 0);
	(void)RTOS_CreateTask(LED4, 280, 4, 0);
	(void)RTOS_CreateTask(LED5, 320, 5, 0);
	(void)RTOS_CreateTask(LED6, 460, 6, 0);
	(void)RTOS_CreateTask(LED7, 540, 7, 0);
