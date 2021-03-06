/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: a7med
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ATMEGA32REGISTERS.h"
#include "DIO_int.h"
#include "ADC.h"




int main(){
	/*
	 * Lab
	ADC_Init();
	u16 AdcRes=0;
	// led Initializing
	DIO_vidSetPinDirection(PORTB,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8LOW);
	// For the ADC inpuit
	DIO_vidSetPinDirection(PORTA,DIO_u8PIN_0,DIO_u8INPUT);

	while(1){
		AdcRes= ADC_Read(ADC_ACDMUX_CHANNEL_ADC0);

		if(AdcRes>100){
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8HIGH);}
		else{
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8LOW);
		}
	}*/

	u16 ADCTempValue=0;
	ADC_vidInit();
	// led
	DIO_vidSetPinDirection(PORTC,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_vidSetPinVal(PORTC,DIO_u8PIN_0,DIO_u8LOW);

	// temperature sensor
	DIO_vidSetPinDirection(PORTA,DIO_u8PIN_0,DIO_u8INPUT);


	// HBridge and moto aka Fan
	DIO_vidSetPinDirection(PORTB,0,DIO_u8OUTPUT);
	while(1){
		ADCTempValue=ADC_Read(ADC_ACDMUX_CHANNEL_ADC0);
		ADCTempValue =(u16)((((u32)ADCTempValue)*5000)/1024);

		if(ADCTempValue<300){
			// fan off
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8LOW);
			DIO_vidSetPinVal(PORTC,DIO_u8PIN_0,DIO_u8LOW);
	}
		else if(ADCTempValue>=300 && ADCTempValue<=600){
			//fan on lED off
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8HIGH);
			DIO_vidSetPinVal(PORTC,DIO_u8PIN_0,DIO_u8LOW);}
		else if (ADCTempValue>600){
			// fan off and led light on
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8LOW);
			DIO_vidSetPinVal(PORTC,DIO_u8PIN_0,DIO_u8HIGH); // red light on

		}

	}


	return 0;
}

