/*
 * LCD_Pro.c
 *
 *  Created on: Aug 16, 2021
 *      Author: a7med
 */


#include "LCD_int.h"
#include "../../Day 11/MyLibs/Atmega32Registers.h"
#include "../../Day 11/MyLibs/BIT_MATH.h"
#include "../../Day 11/Lab/DIO_Prog.c"
#include "../../Day 11/Lab/DIO_int.h"
#include "avr/delay.h"
#include "LCD_int.h"




void LCD_vidWriteData(u8 DataCpy)
{
	DIO_vidSetPinValue(PORTC,DIO_u8PIN_0,DIOHIGH);
	DIO_vidSetPinValue(PORTC,DIO_u8PIN_1,DIOLOW);
	DIO_vidSetPortValue(PORTD,DataCpy);
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_2,DIOHIGH);
	_delay_ms(1.53);
	DIO_vidSetPinValue(PORTC,DIO_u8PIN_2,DIOLOW);
}
// DIO_u8SetPinValue
void LCD_vidSendCommand(u8 CommandCpy)
{
	DIO_vidSetPinValue(PORTC,DIO_u8PIN_0,DIOLOW);
	DIO_vidSetPinValue(PORTC,DIO_u8PIN_1,DIOLOW);
	DIO_vidSetPortValue(PORTD,CommandCpy);
	DIO_vidSetPinValue(PORTC,DIO_u8PIN_2,DIOHIGH);
	_delay_ms(1.53);
	DIO_vidSetPinValue(PORTC,DIO_u8PIN_2,DIOLOW);
}

void LCD_vidWriteString(u8 * StringCpy)
{

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

void LCD_vidGoTo(u8 Copy_Row, u8 ColumnCpy)
{

}



