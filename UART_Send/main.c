/*
 * main.c
 *
 *  Created on: Aug 29, 2021
 *      Author: Princ
 */

#include "STD_TYPES.h"
#include "ATMEGA32_REGISTERS.h"
//#include "BIT_MATH.h"
#include "UART_int.h"
#include "DIO_int.h"
#include "Keypad_int.h"

int main(){

	Keypad_vidInit();
	UART_vidInit();
	f32 data;
	while(1){
		data = Keypad_u8GetKey();
		if(data != 0)
			UART_vidSendData(data);

	}


	return 0;
}
