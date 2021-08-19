#include "../lib/Atmega32Registers.h"
#include "../lib/STD_TYPES.h"
#include "../lib/BIT_MATH.H"
#include <avr/delay.h>
#include "../DIO_Driver/DIO_int.h"
#include "LCD_int.h"

int main(){
	/*
	LCD_vidInit();
	u8 s[10]={'H','A','Z','E','M','\0'};
	LCD_vidWriteString(s);
	while(1){}
	return 0;
	*/
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
}
