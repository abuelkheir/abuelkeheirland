#ifndef ATMEGA32REGISTERS_H_
#define ATMEGA32REGISTERS_H_


#define SERG_REG        *((volatile u8*) (0x5f))

// DIOA
#define PORTA_REG		*((volatile u8*) (0x3B))
#define DDRA_REG		*((volatile u8*) (0x3A))
#define PINA_REG		*((volatile u8*) (0x39))

// DIOB
#define PORTB_REG		*((volatile u8*)  (0x38))
#define DDRB_REG		*((volatile u8*)  (0x37))
#define PINB_REG		*((volatile u8*)  (0x36))

// DIOC
#define PORTC_REG		*((volatile u8*)  (0x35))
#define DDRC_REG		*((volatile u8*)  (0x34))
#define PINC_REG		*((volatile u8*)  (0x33))

// DIOD
#define PORTD_REG		*((volatile u8*)  (0x32))
#define DDRD_REG		*((volatile u8*)  (0x31))
#define PIND_REG		*((volatile u8*)  (0x30))



//external interupts
#define MCUCR_REG		*((volatile u8*)  (0x55))
#define GICR_REG		*((volatile u8*)  (0x5B))
#define GIFR_REG		*((volatile u8*)  (0x5A))


#endif /* ATMEGA32REGISTERS_H_ */

