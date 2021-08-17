/*
 * LCD_init.h
 *
 *  Created on: Aug 16, 2021
 *      Author: Princ
 */

//#include "../lib/STD_TYPES.h"
//#include "DIO_int.h"


#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_u8CLEAR_DISPLAY 0x01

void LCD_vidWriteData(u8 Copy_Data);

void LCD_vidSendCommand(u8 Copy_Command);

void LCD_vidWriteString(u8 * Copy_String);

void LCD_vidInit();

void LCD_vidGoTo(u8 Copy_Row, u8 Copy_Column);


#endif /* LCD_INT_H_ */
