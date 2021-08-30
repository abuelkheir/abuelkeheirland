/*
 * UART_int.h
 *
 *  Created on: Aug 29, 2021
 *      Author: a7med
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ATMEGA32_REGISTERS.h"

#ifndef UART_INT_H_
#define UART_INT_H_



void UART_vidInit();
void UART_vidSendData(u8 Data);
u8 UART_u8RecieveData();


#endif /* UART_INT_H_ */
