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
		
#define ALL_LED_OFF       '0'
#define LED0_ON_LED1_OFF   '1'
#define LED1_ON_LED0_OFF   '2'
#define ALL_LED_ON        '3'
#define ALL_LED_TOGGLE         '4'

        //// define orders ////
		
#define OFF_ALL \
LED0_OFF(); \
LED1_OFF();
#define ON_ALL \
LED0_ON(); \
LED1_ON();
#define ON_0_OFF_1 \
LED0_ON(); \
LED1_OFF();
#define OFF_0_ON_1 \
LED0_OFF(); \
LED1_ON();
#define TOGGLE_ALL \
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
			case ALL_LED_OFF:
			OFF_ALL
			break;
			case LED0_ON_LED1_OFF:
			ON_0_OFF_1
			break;
			case LED1_ON_LED0_OFF:
			OFF_0_ON_1
			break;
			case ALL_LED_ON:
			ON_ALL
			break;
			case ALL_LED_TOGGLE:
			TOGGLE_ALL
			break;
		}
	}
}

