#include "Atmega32Registers.h"
#include "STD_TYPES.h"
#include "BIT_MATH.H"
#include <avr/delay.h>
#include "DIO_int.h"
#include "LCD_int.h"

//#define LCD_u8CLEAR_DISPLAY 0x01
#define port PORTC

void LCD_vidWriteData(u8 Copy_Data)
{
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_0,DIO_u8HIGH);
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_1,DIO_u8LOW);
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_2,DIO_u8HIGH);
	_delay_ms(2);
	DIO_vidSetPortVal(PORTD,Copy_Data);
	_delay_ms(1);
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_2,DIO_u8LOW);
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_0,DIO_u8HIGH);
}

void LCD_vidSendCommand(u8 Copy_Command)
{
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_0,DIOLOW);
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_1,DIOLOW);
	DIO_vidSetPortVal(PORTD,Copy_Command);
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_2,DIOHIGH);
	_delay_ms(1.53);
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_2,DIOLOW);
}

void LCD_vidWriteString(u8 * Copy_String)
{
	for(int i=0; Copy_String[i]!='\0'; i++)
	{
		LCD_vidWriteData(Copy_String[i]);
	}

}

void LCD_vidInit()
{
	DIO_vidSetPinDirection(PORTC,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTC,DIO_u8PIN_1,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTC,DIO_u8PIN_2,DIO_u8OUTPUT);
	DIO_vidSetPortDirection(PORTD,0xFF);

	_delay_ms(40); /* Step_1 */
	LCD_vidSendCommand(0b00111000); /* Step_2 */
	_delay_ms(1); /* Step_3 */
	LCD_vidSendCommand(0b00001111); /* Step_4 */
	_delay_ms(1); /* Step_5 */
	LCD_vidSendCommand(LCD_u8CLEAR_DISPLAY); /* Step_6 */
	_delay_ms(2); /* Step_7 */
	LCD_vidSendCommand(0b00000110); /* Step_8 */
}

void LCD_vidGoTo(u8 Copy_Row, u8 Copy_Column)
{
	if((Copy_Column >=0) && (Copy_Column <16)){
		switch(Copy_Row){
		case 0:
			LCD_vidSendCommand(0b10000000 + Copy_Column);
			break;
		case 1:
			LCD_vidSendCommand(0b11000000 + Copy_Column);
			break;
		}
	}
}
