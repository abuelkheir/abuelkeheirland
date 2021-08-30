/*
 * Keypad_prog.c
 *
 *  Created on: Aug 17, 2021
 *      Author: BASILYJOK3R
 */
#include "STD_TYPES.h"
#include "Keypad_int.h"
#include "DIO_int.h"

#define PORT PORTB_REG
u8 Keypad_Matrix[2][4]=
{
		//created 2d array to make it easier to navigate through rows and columns
		{ROW_1,ROW_2,ROW_3,ROW_4},
		{COL_1,COL_2,COL_3,COL_4}

};

u8 Keypad_Layout[4][4]=
{
		//to make it easier to get the character of a corresponding keypad button
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'#','0','=','+'}
};

void Keypad_vidInit()  //function to initialize keypad
{
	//initializing rows as output
	DIO_vidSetPinDirection(PORT,ROW_1,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORT,ROW_2,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORT,ROW_3,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORT,ROW_4,DIO_u8OUTPUT);

	//initializing columns as input
	DIO_vidSetPinDirection(PORT,COL_1,DIO_u8INPUT);
	DIO_vidSetPinDirection(PORT,COL_2,DIO_u8INPUT);
	DIO_vidSetPinDirection(PORT,COL_3,DIO_u8INPUT);
	DIO_vidSetPinDirection(PORT,COL_4,DIO_u8INPUT);

	//high voltage for output and enabling pull up resistors for input pins
	DIO_vidSetPortVal(PORT,0xFF);
}

u8 Keypad_u8GetKey()   //function to get key from keypad
{
	u8 row;//iterator for row
	u8 col;//iterator for column
	for (row=0;row<4;row++)//looping through row
	{
		DIO_vidSetPinVal(PORT,Keypad_Matrix[0][row],DIO_u8LOW);//sets low voltage for the current row
		for (col=0;col<4;col++)//looping through column
			if (DIO_u8GetPin(PORT,Keypad_Matrix[1][col])==0)//checks if the button is active
			{
				while(DIO_u8GetPin(PORT,Keypad_Matrix[1][col])==0);//waits until the button is released
				return Keypad_Layout[row][col];//returning corresponding keypad character
			}
		DIO_vidSetPinVal(PORT,Keypad_Matrix[0][row],DIO_u8HIGH);//sets the entire row to high voltage after checking the entire row
	}
	return 0;
}
