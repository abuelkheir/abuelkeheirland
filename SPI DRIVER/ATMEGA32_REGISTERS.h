/*
 * ATMEGA32_REGISTERS.h
 *
 *  Created on: Aug 21, 2021
 *      Author: Lenovo
 */

#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

typedef union {
	struct{
		u8 BIT_0 : 1;
		u8 BIT_1 : 1;
		u8 BIT_2 : 1;
		u8 BIT_3 : 1;
		u8 BIT_4 : 1;
		u8 BIT_5 : 1;
		u8 BIT_6 : 1;
		u8 BIT_7 : 1;
	}Bits;
	u8 Whole_Register;
}tuniReg;


#define SREG_REG		(*((volatile tuniReg*)(0x5F)))

#define PORTA_REG		*((volatile u8*)(0x3B))
#define DDRA_REG		*((volatile u8*)(0x3A))
#define PINA_REG		*((volatile u8*)(0x39))

#define PORTB_REG		*((volatile u8*)(0x38))
#define DDRB_REG		*((volatile u8*)(0x37))
#define PINB_REG		*((volatile u8*)(0x36))

#define PORTC_REG		*((volatile u8*)(0x35))
#define DDRC_REG		*((volatile u8*)(0x34))
#define PINC_REG		*((volatile u8*)(0x33))

#define PORTD_REG		*((volatile u8*)(0x32))
#define DDRD_REG		*((volatile u8*)(0x31))
#define PIND_REG		*((volatile u8*)(0x30))

#define MCUCR_REG		(*((volatile tuniReg*)(0x55)))
#define GICR_REG		(*((volatile tuniReg*)(0x5B)))
#define GIFR_REG		(*((volatile tuniReg*)(0x5A)))


// ADC Registers
#define ADMUX_REG       (*((volatile tuniReg*)(0x27)))
#define ADCSRA_REG       (*((volatile tuniReg*)(0x26)))
#define ADCH_REG       (*((volatile tuniReg*)(0x25)))
#define ADCL_REG       (*((volatile tuniReg*)(0x24)))

// GPT_TIMER Registers
#define OCR0_REG		(*((volatile tuniReg*)(0x5C))) // OutPut Compare Register
#define TIMSK_REG		(*((volatile tuniReg*)(0x59))) // Timer Interrupt Mask Register
#define TCCR0_REG		(*((volatile tuniReg*)(0x53))) // El register el baba
#define TCNT0_REG		(*((volatile tuniReg*)(0x52))) //  Timer /Counter Control  Register

#define TCCR1A_REG      (*((volatile tuniReg*)(0x4F)))
#define TCCR1B_REG      (*((volatile tuniReg*)(0x4E)))

#define TCNT1_REG      (*((volatile u16*)(0x4C)))
#define OCR1A_REG      (*((volatile u16*)(0x4A)))
#define OCR1B_REG      (*((volatile u16*)(0x48)))
#define ICR1_REG       (*((volatile u16*)(0x46)))


// UART Registers
#define UDR_REG        (*((volatile tuniReg*)(0x2C)))
#define UCSRA_REG      (*((volatile tuniReg*)(0x2B)))  // UART Control and Status register A

#define UCSRB_REG      (*((volatile tuniReg*)(0x2A)))  //  UART Control and Status register B

#define UBRRL_REG      (*((volatile tuniReg*)(0x29)))

// lehom nafs el adress bas bn8yar Bit 3ashan ne3raf ne3mel access lel etneent
#define UCSRC_REG      (*((volatile tuniReg*)(0x40)))
#define UBRRH_REG      (*((volatile tuniReg*)(0x40)))

#endif /* ATMEGA32_REGISTERS_H_ */
