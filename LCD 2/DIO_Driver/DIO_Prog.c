#include <avr/delay.h>
#include "DIO_int.h"
#include "../lib/Atmega32Registers.h"
#include "../lib/STD_TYPES.h"
#include "../lib/BIT_MATH.H"

#define bool_port ((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD))
#define bool_pin ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7))
#define bool_state ((Copy_Value == DIOLOW) || (Copy_Value == DIOHIGH))
#define bool_dir ((Copy_Direction == DIO_u8INPUT) || (Copy_Direction == DIO_u8OUTPUT))

#define portX_to_DDR(portX) *((volatile u8*)(0x3A - (portX-1)*0x03))
#define portX_to_PORTREG(portX) *((volatile u8*)(0x3B - (portX-1)*0x03))

// function used to get pins
//u8 DI0_u8GetPin(u8 Copy_PortX, u8 Copy_PinX){
//	u8 Temp=0x00;
//		if ( bool_port && bool_pin )
//			Temp = GET_BIT(portX_to_DDR(Copy_PortX), Copy_PinX);
//	return Temp;
//}

u8 DI0_u8GetPin(u8 Copy_PortX, u8 Copy_PinX){
		u8 Temp;
			if (((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7))){
				switch (Copy_PortX)
		{
					case PORTA:
						Temp=GET_BIT(PINA_REG,Copy_PinX);
						break;
					case PORTB:
						Temp=GET_BIT(PINB_REG,Copy_PinX);
						break;
					case PORTC:
						Temp=GET_BIT(PINC_REG, Copy_PinX);
						break;
					case PORTD:
						Temp=GET_BIT(PIND_REG, Copy_PinX);
						break;
				}
	}
	else{
		// do nothing
	}
	return Temp;

}


// function used to set the value of the port

void DIO_vidSetPinVal(u8 Copy_PortX, u8 Copy_PinX, u8 Copy_Value)
{
	if(bool_port && bool_pin && bool_state){
			if(Copy_Value == DIOHIGH)
				SET_BIT(Copy_PortX,Copy_PinX);
			else
				CLR_BIT(Copy_PortX,Copy_PinX);
	}
}


// function to set the direction of the certain pins in a port.
void DIO_vidSetPinDirection(u8 Copy_PortX,u8 Copy_PinX, u8 Copy_Direction)
{
	/* do checks */
	if(bool_port && bool_pin && bool_dir)
	{
		if(Copy_Direction == DIO_u8INPUT)
			CLR_BIT(Copy_PortX,Copy_PinX);

		else
			SET_BIT(Copy_PortX,Copy_PinX);
	}

}


// set direction of a whole port
void DIO_vidSetPortDirection(u8 Copy_PortX, u8 Copy_Direction){
	// port-dir checks
	if(bool_port && bool_dir)
		portX_to_DDR(Copy_PortX) = Copy_Direction;
}


// set port values to a custom value
void DIO_vidSetPortVal(u8 Copy_PortX, u8 Copy_Value){
	if(bool_port){
		portX_to_PORTREG(Copy_PortX) = Copy_Value;
	}
}




void DIO_vidTogglePinVal(u8 Copy_PortX,u8 Copy_PinX)
{
	if (bool_port && bool_pin){
		TGL_BIT(portX_to_DDR(Copy_PortX), Copy_PinX);
	}
}

//
//int main(){
//
//		return 0;
//}
//

