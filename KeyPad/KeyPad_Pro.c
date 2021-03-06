/*
 * KeyPad_Pro.c
 *
 *  Created on: Aug 18, 2021
 *      Author: abuelkheir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Atmega32Registers.h"
#include "DIO_int.h"
#include "KeyPad_int.h"




u8 Keypad_Matrix[2][4]= //Initiallizing the initial postions of rows and columns we are going to manipulate to use the keypad
{
		{
				ROW_1,
				ROW_2,
				ROW_3,
				ROW_4
		},
		{
				COL_1,
				COL_2,
				COL_3,
				COL_4

		}
};
// Initializing positions and keyboard layout we are gonna use
u8 Keypad_Layout[4][4]=
{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'#','0','=','+'},
};

void Keypad_vidInit(){

	// To apply the hardware implementation of keypad we must mimic it in our a micro controller using 4 keys on output mode
	// 4 keys DDRA directions as outputs
	DIO_vidSetPinDirection(PORT,ROW_1,DIO_u8OUTPUT);
    DIO_vidSetPinDirection(PORT,ROW_2,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORT,ROW_3,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORT,ROW_4,DIO_u8OUTPUT);
	// 4 keys on DDR direction as input mode
	DIO_vidSetPinDirection(PORT,COL_1,DIO_u8INPUT);
	DIO_vidSetPinDirection(PORT,COL_2,DIO_u8INPUT);
	DIO_vidSetPinDirection(PORT,COL_3,DIO_u8INPUT);
	DIO_vidSetPinDirection(PORT,COL_4,DIO_u8INPUT);

	// setting pin values to 1
	DIO_vidSetPinVal(PORT,ROW_1,DIO_u8HIGH);
	DIO_vidSetPinVal(PORT,ROW_2,DIO_u8HIGH);
	DIO_vidSetPinVal(PORT,ROW_3,DIO_u8HIGH);
	DIO_vidSetPinVal(PORT,ROW_4,DIO_u8HIGH);

	// activating pull up resistors of the column  buttons
	DIO_vidSetPinVal(PORT,COL_1,DIO_u8HIGH);
	DIO_vidSetPinVal(PORT,COL_2,DIO_u8HIGH);
	DIO_vidSetPinVal(PORT,COL_3,DIO_u8HIGH);
	DIO_vidSetPinVal(PORT,COL_4,DIO_u8HIGH);

}

// This functions is used to get what keys were pressed
u8 Keypad_u8GetKey()
{
	u8 Row_Iterator;
	u8 Col_Iterator;
	// iteratting through the keypad 16 keys , but we need a nested loop to look through both columns
	for(Row_Iterator = 0 ; Row_Iterator <=3 ; Row_Iterator++)
	{
		DIO_vidSetPinVal(PORT,Keypad_Matrix[0][Row_Iterator],DIO_u8LOW);
		for(Col_Iterator = 0 ; Col_Iterator <= 3 ; Col_Iterator++)
		{
			if(DIO_u8GetPin(PORT,Keypad_Matrix[1][Col_Iterator]) == DIO_u8LOW)
			{
				while(DIO_u8GetPin(PORT,Keypad_Matrix[1][Col_Iterator]) == DIO_u8LOW)
				{

				};
				return Keypad_Layout[Row_Iterator][Col_Iterator];
			}
		}
		DIO_vidSetPinVal(PORT,Keypad_Matrix[0][Col_Iterator],DIO_u8HIGH);
	}
	return NOT_PRESSED;
}
