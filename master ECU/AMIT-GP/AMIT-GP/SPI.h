/*
* SPI.h
*
* Created: 12/19/2020 2:29:00 PM
* Author : Areej & yousef
*/



#ifndef SPI_H_
#define SPI_H_
#include "CPU_CONFIGURATION.h"

void SPI_ReceiveString(Uint8t *str);
void SPI_SendString(Uint8t *str);
Uint8t SPI_ReceiveByte();
void SPI_SendByte(Uint8t data);
void SPI_InitSlave();
void SPI_InitMaster();


#endif /* SPI_H_ */