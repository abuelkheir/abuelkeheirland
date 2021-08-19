#include "STD_TYPES.h"
#include"Atmega32Registers.h"
#include"BIT_MATH.h"
#include"DIO_int.h"
#include <avr/delay.h>


int main(){

	DIO_vidSetPinDirection(PORTB,0,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTB,1,DIO_u8OUTPUT);
	PORTB_REG=0x00;
		while(1){
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8HIGH);
			_delay_ms(1000);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8LOW);
			_delay_ms(1000);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_1,DIO_u8HIGH);
			_delay_ms(1000);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_1,DIO_u8LOW);

		}
	return 0 ;
}
