/*
* AMIT-GP-SL.c
*
* Created: 1/10/2021 7:55:17 PM
* Author : Areej & yousef
*/
        //// include drivers //////
		
#include "SPI.h"
#include "LED.h"

		//// define LED STATE ////
		
#define ALL_LEDS_OFF      '0'
#define LED0_ON_LED1_OFF  '1'
#define LED1_ON_LED0_OFF  '2'
#define ALL_LEDS_ON       '3'
#define ALL_LEDS_TOGGLE   '4'

        //// define orders ////
		
#define DIM_ALL_LEDS \
LED0_OFF(); \
LED1_OFF();
#define LIGHT_ALL_LEDS \
LED0_ON(); \
LED1_ON();
#define LIGHT_LED0_LONELY \
LED0_ON(); \
LED1_OFF();
#define LIGHT_LED1_LONELY \
LED0_OFF(); \
LED1_ON();
#define INVERT_LEDS_LIGHT \
LED0_TGL(); \
LED1_TGL();

int main(void)
{
	Uint8t LED_STATE = 0;
	SPI_InitSlave();
	LED0_Init();
	LED1_Init();
	while (1)
	{
		LED_STATE = SPI_ReceiveByte();
		switch (LED_STATE)
		{
			case ALL_LEDS_OFF:
			DIM_ALL_LEDS
			break;
			case LED0_ON_LED1_OFF:
			LIGHT_LED0_LONELY
			break;
			case LED1_ON_LED0_OFF:
			LIGHT_LED1_LONELY
			break;
			case ALL_LEDS_ON:
			LIGHT_ALL_LEDS
			break;
			case ALL_LEDS_TOGGLE:
			INVERT_LEDS_LIGHT
			break;
		}
	}
}

