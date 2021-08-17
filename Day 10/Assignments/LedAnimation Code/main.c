#include <avr/io.h>
#include <avr/delay.h>

typedef unsigned int u8;
#define TGL_Bit(Var,BitNo) (Var ^= ((1)<< BitNo))
#define CLR_BIT(Var,BitNo) (Var &= ~((1)<<BitNo))
#define SET_BIT(Var,BitNo) (Var |= ((1)<<BitNo))

#define F_CPU 8000000;

	int main (void)
	{
		DDRA=0xFF;
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);

		// Blinking every 500 ms
		/*
		while(1)
		{
			if((PINC & (0x07)) == 0)
			{
				PORTA = 0xFF;
				_delay_ms(500);
				PORTA = 0x00;
				_delay_ms(500);
			}
			else
				PORTA = 0x00;
				}
				*/
		u8 PortChange; // variable to shift ports every loop;
		//shift up
		/*
		while(1){
			if((PINC & (0x07)) == 0)
			{
				for(int i =0; i<=8;i++){
					SET_BIT(PORTA,i);
					_delay_ms(250);
					CLR_BIT(PORTA,i);
				}
			}
			else
				PORTA=0x00;


		}*/

		//shift down

		/*while(1){
				if((PINC & (0x07)) == 0)
				{
					for(int i =7; i>=0;i--){
						SET_BIT(PORTA,i);
						_delay_ms(250);
						CLR_BIT(PORTA,i);
						}
					}
					else
						PORTA=0x00;


				} */

		// 2 leds convegring
		u8 j=7;
		while(1){
				if((PINC & (0x07)) == 0)
				{
					for(int i =0; i<=3;i++){

						SET_BIT(PORTA,i+j);
						SET_BIT(PORTA,i);
						_delay_ms(250);
						CLR_BIT(PORTA,i);
						CLR_BIT(PORTA,i+j);
						j=j-2;
						if(j<=0){
							j=7;
						}
							}
				}
				else
					PORTA=0x00;


						}

		return 0;
	}



