
#include <avr/delay.h>
#include "../MyLibs/Atmega32Registers.h"
#include "../MyLibs/STD_TYPES.h"
#include "../MyLibs/BIT_MATH.H"
#include "DIO_int.h"

// function used to get pins
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
void DIO_u8SetPinValue(u8 Copy_PortX,u8 Copy_PinX, u8 Copy_Value )
{
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)) \
				&& ((Copy_Value == DIOLOW) || (Copy_Value == DIOHIGH))){
			if(Copy_Value == DIOHIGH)
			{
				switch (Copy_PortX)
				{
					case PORTA:
						SET_BIT(PINA_REG,Copy_PinX);
						break;
					case PORTB:
						SET_BIT(PINB_REG,Copy_PinX);
						break;
					case PORTC:
						SET_BIT(PINC_REG,Copy_PinX);
						break;
					case PORTD:
						SET_BIT(PIND_REG,Copy_PinX);
						break;
		}
			}
			else if(Copy_PortX== DIOLOW){

			switch (Copy_PortX)
			{
				case PORTA:
					CLR_BIT(PINA_REG,Copy_PinX);
					break;
				case PORTB:
					CLR_BIT(PINB_REG,Copy_PinX);
					break;
				case PORTC:
					CLR_BIT(PINC_REG,Copy_PinX);
					break;
				case PORTD:
					CLR_BIT(PIND_REG,Copy_PinX);
					break;
			}
	}
			else{//do nothing
			}
	}
}

// function to set the direction of the certain pins in a port.
void DIO_vidSetPinDirection(u8 Copy_PortX,u8 Copy_PinX, u8 Copy_Direction)
{
	/* this line means that we want to make sure the function user entered ports within our range (from 1-4) & enterd pins from (0-7) and correct direction*/
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)) \
			&& ((Copy_Direction == DIO_u8INPUT) || (Copy_Direction == DIO_u8OUTPUT)))
	{
		if(Copy_Direction == DIO_u8INPUT) //
		{
			switch(Copy_PortX)
			{
			case PORTA:
				CLR_BIT(DDRA_REG,Copy_PinX);
				break;
			case PORTB:
				CLR_BIT(DDRB_REG,Copy_PinX);
				break;
			case PORTC:
				CLR_BIT(DDRC_REG,Copy_PinX);
				break;
			case PORTD:
				CLR_BIT(DDRD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_Direction == DIO_u8OUTPUT)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				SET_BIT(DDRA_REG,Copy_PinX);
				break;
			case PORTB:
				SET_BIT(DDRB_REG,Copy_PinX);
				break;
			case PORTC:
				SET_BIT(DDRC_REG,Copy_PinX);
				break;
			case PORTD:
				SET_BIT(DDRD_REG,Copy_PinX);
				break;
			}
		}
	}
	else
	{}
		/*  DO NOTHING  */
}


// function to set the direction of the whole port (CHECKED)
void DIO_vidSetPortDirection(u8 Copy_PortX, u8 Copy_Direction){
	// checking for valid port A-D and Correct Direction
	if((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD))
		{
			switch (Copy_PortX){
				case PORTA:
					DDRA_REG=Copy_Direction;
					break;
				case PORTB:
					DDRB_REG=Copy_Direction;
					break;
				case PORTC:
					DDRC_REG=Copy_Direction;
					break;
				case PORTD:
					DDRD_REG=Copy_Direction;
					break;
		}
	}
}



void DIO_vidSetPortValue(u8 Copy_PortX, u8 Copy_Value){
	if((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)){
						switch (Copy_PortX)
						{
							case PORTA:
								PORTA_REG= Copy_Value;
								break;
							case PORTB:
								PORTB_REG= Copy_Value;
								break;
							case PORTC:
								PORTC_REG=Copy_Value;
								break;
							case PORTD:
								PORTD_REG=Copy_Value;
								break;
				}
					}

}




 void DIO_vidTogglePinValue(u8 Copy_PortX,u8 Copy_PinX)
{
	if (((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7))){
			switch (Copy_PortX)
			{
				case PORTA:
					TGL_BIT(PORTA_REG, Copy_PinX);
					break;
				case PORTB:
					TGL_BIT(PORTB_REG, Copy_PinX);
					break;
				case PORTC:
					 TGL_BIT(PORTC_REG, Copy_PinX);
					break;
				case PORTD:
					 TGL_BIT(PORTD_REG, Copy_PinX);
					break;
			}

		}
	else{// do nothing
	}
}






