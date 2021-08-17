
#include"../lib/BIT_MATH.h"
#include"../lib/STD_TYPES.h"
#include"DIO_int.h"
#include"../lib/ATMEGA32REGISTERS.h"


u8 DIO_u8GetPin(u8 Copy_PortID ,u8 Copy_PinID )
{
	u8 PinLevel;
	if(((Copy_PortID >= PORTA)	 && (Copy_PortID <= PORTD)) && ((Copy_PinID >= DIO_u8PIN_0) && (Copy_PinID <= DIO_u8PIN_7)))
	{

		switch(Copy_PortID)
		{
		case PORTA:
			PinLevel = GET_BIT(PINA_REG,Copy_PinID);
			break;
		case PORTB:
			PinLevel = GET_BIT(PINA_REG,Copy_PinID);
			break;
		case PORTC:
			PinLevel = GET_BIT(PINA_REG,Copy_PinID);
			break;
		case PORTD:
			PinLevel = GET_BIT(PINA_REG,Copy_PinID);
			break;
		}
	}

	return PinLevel;
}


void DIO_vidSetPinVal(u8 Copy_PortID ,u8 Copy_PinID,u8 Copy_Value)
{
	if(((Copy_PortID >= PORTA) && (Copy_PortID <= PORTD)) && ((Copy_PinID >= DIO_u8PIN_0) && (Copy_PinID <= DIO_u8PIN_7)) \
			&& ((Copy_Value == DIO_u8HIGH) || (Copy_Value == DIO_u8LOW)))
	{
		if(Copy_Value == DIO_u8HIGH)
		{
			switch(Copy_PortID)
			{
			case PORTA:
				SET_BIT(PINA_REG,Copy_PinID);
				break;
			case PORTB:
				SET_BIT(PINB_REG,Copy_PinID);
				break;
			case PORTC:
				SET_BIT(PINC_REG,Copy_PinID);
				break;
			case PORTD:
				SET_BIT(PIND_REG,Copy_PinID);
				break;
			}
		}
		else if(Copy_Value == DIO_u8LOW)
		{
			switch(Copy_PortID)
			{
			case PORTA:
				CLR_BIT(PINA_REG,Copy_PinID);
				break;
			case PORTB:
				CLR_BIT(PINB_REG,Copy_PinID);
				break;
			case PORTC:
				CLR_BIT(PINC_REG,Copy_PinID);
				break;
			case PORTD:
				CLR_BIT(PIND_REG,Copy_PinID);
				break;

			}
		}
	}
}
void DIO_vidTogglePinVal(u8 Copy_PortID ,u8 Copy_PinID)
{
	if(((Copy_PortID >= PORTA) && (Copy_PortID <= PORTD)) && ((Copy_PinID >= DIO_u8PIN_0) && (Copy_PinID <= DIO_u8PIN_7)))
	{

		switch(Copy_PortID)
		{
		case PORTA:
			TGL_BIT(PINA_REG,DIO_u8LOW);
			break;
		case PORTB:
			TGL_BIT(PINB_REG,DIO_u8HIGH);
			break;
		case PORTC:
			TGL_BIT(PINC_REG,DIO_u8LOW);
			break;
		case PORTD:
			TGL_BIT(PIND_REG,DIO_u8LOW);
			break;
		}
	}


}


void DIO_vidSetPinDirection(u8 Copy_PortID ,u8 Copy_PinID,u8 Copy_Direction)
{
	if(((Copy_PortID >= PORTA) && (Copy_PortID <= PORTD)) && ((Copy_PinID >= DIO_u8PIN_0) && (Copy_PinID <= DIO_u8PIN_7)) \
			&& ((Copy_Direction == DIO_u8INPUT) || (Copy_Direction == DIO_u8OUTPUT)))
	{
		if(Copy_Direction == DIO_u8INPUT)
		{
			switch(Copy_PortID)
			{
			case PORTA:
				CLR_BIT(DDRA_REG,Copy_PinID);
				break;
			case PORTB:
				CLR_BIT(DDRB_REG,Copy_PinID);
				break;
			case PORTC:
				CLR_BIT(DDRC_REG,Copy_PinID);
				break;
			case PORTD:
				CLR_BIT(DDRD_REG,Copy_PinID);
				break;
			}
		}
		else if(Copy_Direction == DIO_u8OUTPUT)
		{
			switch(Copy_PortID)
			{
			case PORTA:
				SET_BIT(DDRA_REG,Copy_PinID);
				break;
			case PORTB:
				SET_BIT(DDRB_REG,Copy_PinID);
				break;
			case PORTC:
				SET_BIT(DDRC_REG,Copy_PinID);
				break;
			case PORTD:
				SET_BIT(DDRD_REG,Copy_PinID);
				break;
			}
		}
	}
	else
	{
		/*  DO NOTHING  */
	}
}


void DIO_vidSetPortDirection(u8 Copy_PortID, u8 Copy_Direction)
{
	if(((Copy_PortID >= PORTA) && (Copy_PortID <= PORTD)))
	{

		switch(Copy_PortID)
		{
		case PORTA:
			DDRA_REG = Copy_Direction;
			break;
		case PORTB:
			DDRB_REG = Copy_Direction;
			break;
		case PORTC:
			DDRC_REG = Copy_Direction;
			break;
		case PORTD:
			DDRD_REG = Copy_Direction;
			break;
		}
	}
}



void DIO_vidSetPortVal(u8 Copy_PortID ,u8 Copy_Value)
{
	if(((Copy_PortID >= PORTA) && (Copy_PortID <= PORTD)))
	{

		switch(Copy_PortID)
		{
		case PORTA:
			PORTA_REG = Copy_Value;
			break;
		case PORTB:
			PORTB_REG = Copy_Value;
			break;
		case PORTC:
			PORTC_REG = Copy_Value;
			break;
		case PORTD:
			PORTD_REG = Copy_Value;
			break;
		}



	}
}


