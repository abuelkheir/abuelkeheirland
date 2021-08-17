#include"../lib/STD_TYPES.h"

#ifndef DIO_INT_H_
#define DIO_INT_H_

// defining if the pin is input then u8input 1 , if the pin is output the value is 1. used with pin functions
#define DIO_u8INPUT 0
#define DIO_u8OUTPUT 1

#define DIO_u8PIN_0 0
#define DIO_u8PIN_1 1
#define DIO_u8PIN_2 2
#define DIO_u8PIN_3 3
#define DIO_u8PIN_4 4
#define DIO_u8PIN_5 5
#define DIO_u8PIN_6 6
#define DIO_u8PIN_7 7

// defining port input is high when 1 , low when 0 used with port functions
#define DIOHIGH 1
#define DIOLOW  0

#define PORTA  1
#define PORTB  2
#define PORTC  3
#define PORTD  4

 // function used to get pins
u8 DI0_u8GetPin(u8 Copy_PortX, u8 Copy_PinX);

void DIO_vidSetPinVal(u8 Copy_PortX, u8 Copy_PinX, u8 Copy_Value);

void DIO_vidSetPinDirection(u8 Copy_PortX,u8 Copy_PinX, u8 Copy_Direction);// function to set the direction of the port


void DIO_vidSetPortDirection(u8 Copy_PortX, u8 Copy_Direction);

void DIO_vidSetPortVal(u8 Copy_PortX, u8 Copy_Value);

void DIO_vidTogglePinVal(u8 Copy_PortX,u8 Copy_PinX);


#endif /* DIO_INT_H_ */
