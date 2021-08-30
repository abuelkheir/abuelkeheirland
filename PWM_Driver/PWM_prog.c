#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "PWM_int.h"
#include "GPT_int.h"
#include "DIO_int.h"

void PWM_vidPwmInit(u8 Copy_TimerNo)
{
	switch(Copy_TimerNo)
	{
	case TIMER_0: //if timer 0
		/*initializing timer 0  the same way we used it in GPT*/
		TCCR0_REG.Bits.BIT_3=1;
		TCCR0_REG.Bits.BIT_6=1;
		break;
	case TIMER_1: //if timer 1
		/*initializing timer 1 changing some bits to match timer 1 */
		TCCR1A_REG.Bits.BIT_7 = 1;
		TCCR1A_REG.Bits.BIT_6 = 0;
		TCCR1A_REG.Bits.BIT_5 = 0;
		TCCR1A_REG.Bits.BIT_4 = 0;
		/****************************/
		/* selecting fast pwm with ICR1 top*/
		TCCR1A_REG.Bits.BIT_0 = 0;
		TCCR1A_REG.Bits.BIT_1 = 1;

		TCCR1B_REG.Bits.BIT_3 = 1;
		TCCR1B_REG.Bits.BIT_4 = 1;

		ICR1_REG = PWM_ICR1_VALUE; //initializing ICR1_VALUE to ICR1 register
		break;
	}
}

void PWM_vidSetPwmDutyCycle(u8 Copy_TimerNo, u32 Copy_DC)
{
	switch(Copy_TimerNo)
	{
	case TIMER_0: //if timer 0
		OCR0_REG.Whole_Register = (u8)(((f32)Copy_DC *((f32)256))/100); //ocr0=dutyCycle*2^resolution
		break;
	case TIMER_1: //if timer 1
		OCR1A_REG = (u16)(((f32)Copy_DC *((f32)PWM_ICR1_VALUE))/(100)); //ocr1a=dutyCycle*ICR1_VALUE
		break;
	}
}

void PWM_StartTimer(u8 Copy_TimerNo)
{
	switch(Copy_TimerNo)
	{
	case TIMER_0: //if timer 0
		TCCR0_REG.Whole_Register &= PWM_CS_CLEAR_MASK; //clearing bits 0,1 and 2 for timer 0
		TCCR0_REG.Whole_Register |= PWM_CS0_MODE;      //sets bit 0,1 and 2 to the corresponding clock select mode for timer 0
		break;
	case TIMER_1: //if timer 1
		TCCR1B_REG.Whole_Register &= PWM_CS_CLEAR_MASK; //clearing bits 0,1 and 2 for timer 1
		TCCR1B_REG.Whole_Register |= PWM_CS1_MODE;      //sets bit 0,1 and 2 to the corresponding clock select mode for timer 1
		break;
	}
}

void PWM_StopTimer(u8 Copy_TimerNo)
{
	switch(Copy_TimerNo)
	{
	case TIMER_0: //if timer 0
		TCCR0_REG.Whole_Register  &= 0xF8; //clearing bits 0,1 and 2 to select stop clock mode for timer 0
		break;
	case TIMER_1: //if timer 1
		TCCR1B_REG.Whole_Register &= 0xF8; //clearing bits 0,1 and 2 to select stop clock mode for timer 1
		break;
	}
}


