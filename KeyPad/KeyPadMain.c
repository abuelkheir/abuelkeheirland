#include "STD_TYPES.h"or
#include"Atmega32Registers.h"
#include"BIT_MATH.h"
#include"LCD_int.h"
#include"DIO_int.h"
#include"Keypad_int.h"
#include <avr/delay.h>



#define delay(x) _delay_ms(x);
int main(void)
{
	/*
	LCD_vidInit();
	Keypad_vidInit();
	u8 KeyVal;
	while(1)
	{
		KeyVal = Keypad_u8GetKey();
		if(KeyVal != NOT_PRESSED)
			LCD_vidWriteData(KeyVal);
	}
	return 0;
	*/
	DIO_vidSetPinDirection(PORTB,0,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTB,1,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTB,2,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTC,0,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTC,1,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTC,2,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTC,3,DIO_u8OUTPUT);

	PORTB_REG=0x00;
		while(1){
			/*
			 motor 3ady
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8HIGH);
			_delay_ms(1000);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8LOW);
			_delay_ms(1000);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_1,DIO_u8HIGH);
			_delay_ms(1000);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_1,DIO_u8LOW);
			*/
			/*
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_2,DIO_u8HIGH);

			_delay_ms(1000);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_2,DIO_u8LOW);
			_delay_ms(1000);
			*/
			for(int i=0;i<8;i++){
				DIO_vidSetPinVal(PORTC,i%4,DIO_u8HIGH);
				delay(200);
				DIO_vidSetPinVal(PORTC,(i+1)%4,DIO_u8HIGH);
				delay(200);
				DIO_vidSetPinVal(PORTC,i%4,DIO_u8HIGH);
				delay(200);

			}
		}



		return 0;
}
