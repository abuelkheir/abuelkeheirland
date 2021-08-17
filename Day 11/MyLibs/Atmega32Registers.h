/*
 * Atmega32Registers.h
 *
 *  Created on: Aug 15, 2021
 *      Author: a7med
 */

#ifndef ATMEGA32REGISTERS_H_
#define ATMEGA32REGISTERS_H_
#include "STD_TYPES.H"

// DIOA
#define PORTA_REG        *((volatile u8*) (0x3B))
#define DDRA_REG        *((volatile u8*) (0x3A))
#define PINA_REG         *((volatile u8*) (0x39))

// DIOB
#define PORTB_REG          *((volatile u8*)  (0x38))
#define DDRB_REG           *((volatile u8*)  (0x37))
#define PINB_REG           *((volatile u8*)  (0x36))

// DIOC
#define PORTC_REG          *((volatile u8*)  (0x35))
#define DDRC_REG           *((volatile u8*)  (0x34))
#define PINC_REG           *((volatile u8*)  (0x33))

// DIOD
#define PORTD_REG          *((volatile u8*)  (0x32))
#define DDRD_REG 		   *((volatile u8*)  (0x31))
#define PIND_REG           *((volatile u8*)  (0x30))

#endif /* ATMEGA32REGISTERS_H_ */