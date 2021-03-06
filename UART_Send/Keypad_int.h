/*
 * Keypad_int.h
 *
 *  Created on: Aug 17, 2021
 *      Author: BASILYJOK3R
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#define PORT u8PORTB      //defining port flexible to change port

//flexible to change pins
#define ROW_1 DIO_u8PIN_0
#define ROW_2 DIO_u8PIN_1
#define ROW_3 DIO_u8PIN_2
#define ROW_4 DIO_u8PIN_3
#define COL_1 DIO_u8PIN_4
#define COL_2 DIO_u8PIN_5
#define COL_3 DIO_u8PIN_6
#define COL_4 DIO_u8PIN_7


void Keypad_vidInit();  //function to initialize keypad
u8 Keypad_u8GetKey();   //function to get key from keypad

#endif /* KEYPAD_INT_H_ */
