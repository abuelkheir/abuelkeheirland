/*
 * LCD_int.h
 *
 *  Created on: Aug 16, 2021
 *      Author: a7med
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
#include "../../Day 11/MyLibs/STD_TYPES.H"


#define LCD_u8CLEAR_DISPLAY 	0X01
#define LCD_u8RETURN_HOME		0x02
void LCD_vidWriteData(u8 DataCpy);

void LCD_vidSendCommand(u8 CommandCpy);

void LCD_vidWriteString(u8 * StrtingCpy);

void LCD_vidInit();

void LCD_vidGoTo(u8 RowCpy, u8 ColCpy);




#endif /* LCD_INT_H_ */
