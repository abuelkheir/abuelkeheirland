

#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO_int.h"
#include "SPI_int.h"


 void SPI_vidMasterlnit (void)
 {
  /* Set MOSI and SCK and SS output,*/
  SET_BIT( DDRB_REG,5) ;
  SET_BIT( DDRB_REG,7) ;
  SET_BIT( DDRB_REG,4) ;
  /*slave select */
  CLR_BIT(PORTB_REG,4);
  /* Enable SPI,select Master Mode*/
  SET_BIT(SPCR_REG ,6);
  SET_BIT(SPCR_REG ,4) ;

 }
 void SPl_vidSlavelnit (void)
{
  /* Set MlSO output 8:*/
  SET_BIT(DDRB_REG ,6) ;
  // Enable SPI
  SET_BIT(SPCR_REG ,6) ;

  // to select sLave MODE
  CLR_BIT(SPCR_REG ,4) ;
}

 void SPl_vidTransfer (u8 data)
 {
 // Loading the data
  SPDR_REG = data ;
  // waiting the flag
  while(((SPSR_REG) & (1<<7)) ==0);
 }

  u8 SPI_u8Recieve (void)
  {
  //waiting the flag
  while (((SPSR_REG) & (1<<7)) ==0 ) ;
  // return data reade/
  return SPDR_REG;
  }
