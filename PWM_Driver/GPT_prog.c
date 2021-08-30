#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ATMEGA32_REGISTERS.h"
#include "avr/interrupt.h"
#include "DIO_int.h"
#include "GPT_int.h"

pFunc InternalCBFs[2];


// this function is used to initialize the timer perirpheral
void GPT_vidInit (void)
{
#if GPT_MODE == NORMAL
	TCCR0_REG.Bits.BIT_3 = 0;
	TCCR0_REG.Bits.BIT_6 = 0;
#elif GPT_MODE == CTC          // Clean time on compare mode
	TCCR0_REG.Bits.BIT_3 = 1;
	TCCR0_REG.Bits.BIT_6 = 0;

	TCCR0_REG.Whole_Register &= OC0_MODE_CLEAR_MASK;
	TCCR0_REG.Whole_Register |= OC0_MODE;

	if(OCR0_VALUE <= 255)
	{
		OCR0_REG.Whole_Register = OCR0_VALUE;
	}
#endif
}

// Function to stop the timer
void GPT_vidStopTimer(void)
{
	TCCR0_REG.Whole_Register &= 0xF8;    //0b11111000 Value we got from DataSheet
}

// Function to start the timer
void GPT_vidStartTimer(void)
{
	TCCR0_REG.Whole_Register &= CS_CLEAR_MASK;
	TCCR0_REG.Whole_Register |= CS_MODE;
}

// function to preload the Timer Counter Register to manipulate timing process
void GPT_vidLoadTimer(u8 Copy_u8PreloadValue)
{
	TCNT0_REG.Whole_Register = Copy_u8PreloadValue;
}

void GPT_vidEnableNotification(void)
{
#if GPT_MODE == NORMAL
	TIMSK_REG.Bits.BIT_0 = 1; // enable interrupt of overflow in normal mode
#elif GPT_MODE == CTC
	TIMSK_REG.Bits.BIT_1 = 1; // enable the ORC0 register
#endif
}

// disable interrupt overflow
void GPT_vidDisableNotification(void)
{
#if GPT_MODE == NORMAL
	TIMSK_REG.Bits.BIT_0 = 0;
#elif GPT_MODE == CTC
	TIMSK_REG.Bits.BIT_1 = 0;
#endif
}


void GPT_vidSetCallBack(pFunc CBF , u8 interruptID)
{
	if(CBF)
	{
		InternalCBFs[interruptID] = CBF;
	}
}



ISR(TIMER0_OVF_vect) //ISR for OVF
{
	if(InternalCBFs[0]) //checks if InternalCBF of element 0 is not empty
	{
		InternalCBFs[0](); //calling function
	}
}

ISR(TIMER0_COMP_vect) //ISR for output compare match
{
	if(InternalCBFs[1]) //checks if InternalCBF of element 0 is not empty
	{
		InternalCBFs[1](); //calling function
	}
}
