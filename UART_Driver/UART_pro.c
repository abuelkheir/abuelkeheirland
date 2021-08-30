/*
 * UART_pro.c
 *
 *  Created on: Aug 29, 2021
 *      Author: a7med
 */
#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "ATMEGA32_REGISTERS.H"

void UART_vidInit(){

	// set frame format to -> 8 bits
	UCSRC_REG.Bits.BIT_7=1; // 3ashan ne3raf ne3mel access le USRC
	UCSRC_REG.Bits.BIT_2= 1;
	UCSRB_REG.Bits.BIT_1= 1;

	// Disabling parity bits
	UCSRC_REG.Bits.BIT_4= 0;
	UCSRC_REG.Bits.BIT_5= 0;

	// setting frame format to Bit
	UCSRC_REG.Bits.BIT_3= 0;
	UCSRC_REG.Bits.BIT_6= 0;

	//Enable RX and TX
	UCSRB_REG.Bits.BIT_3=1;
	UCSRB_REG.Bits.BIT_4=1;

	//Set BaudRate to 9600 / 8Mhz

	UBRRH_REG.Whole_Register=0;
	UBRRL_REG.Whole_Register=51;


}


void UART_vidSendData(u8 Copy_u8Data){

	while(UCSRA_REG.Bits.BIT_5 == 0 );
	UDR_REG.Whole_Register= Copy_u8Data;
}


u8 UART_u8RecieveData(){
  u8 LocalResult;
  while(UCSRA_REG.Bits.BIT_7==0);
  LocalResult= UDR_REG.Whole_Register;
  UCSRA_REG.Bits.BIT_7=0;
  return LocalResult;
}
