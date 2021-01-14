/*
* AMIT-GP.c
*
* Created: 1/8/2021 3:27:09 PM
* Author : Areej & yousef
*/

#include "SPI.h"
#include "USART_RS232_H_file.h"

#define RECEIVE_FROM_USART_SEND_VIA_SPI \
ORDER = USART_RxChar(); \
SPI_SendByte(ORDER);

int main(void)
{
	USART_Init(9600);
	SPI_InitMaster();
	Uint8t ORDER = 0;
	while (1)
	{
		RECEIVE_FROM_USART_SEND_VIA_SPI
	}
}

