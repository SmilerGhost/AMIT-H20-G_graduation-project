/*
* LED.c
*
* Created: 11/12/2020 8:35:55 PM
* Author : Areej & yousef
*/

/*Source File for function implementations*/
#include "LED.h"

void LED0_Init(void)
{
	DIO_SetPin_Direction(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);
}
void LED0_ON(void)
{
	DIO_SetPin_Value(DIO_PORTC, DIO_PIN2, DIO_PIN_HIGH);
}
void LED0_OFF(void)
{
	DIO_SetPin_Value(DIO_PORTC, DIO_PIN2, DIO_PIN_LOW);
}
void LED0_TGL(void)
{
	DIO_TogglePin(DIO_PORTC, DIO_PIN2);
}


void LED1_Init(void)
{
	DIO_SetPin_Direction(DIO_PORTC, DIO_PIN7, DIO_PIN_OUTPUT);
}
void LED1_ON(void)
{
	DIO_SetPin_Value(DIO_PORTC, DIO_PIN7, DIO_PIN_HIGH);
}
void LED1_OFF(void)
{
	DIO_SetPin_Value(DIO_PORTC, DIO_PIN7, DIO_PIN_LOW);
}
void LED1_TGL(void)
{
	DIO_TogglePin(DIO_PORTC, DIO_PIN7);
}