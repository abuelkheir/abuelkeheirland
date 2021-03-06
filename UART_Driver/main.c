#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "ATMEGA32_REGISTERS.H"
#include "DIO_int.h"
#include "LCD_int.h"
#include "UART_int.h"
int  main(){
	u8 data;
	UART_vidInit();

	LCD_vidInit();
	DIO_vidSetPinDirection(PORTA_REG,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_vidSetPinVal(PORTA_REG,DIO_u8PIN_0,DIO_u8LOW);
	LCD_vidWriteString("KEY : ");
	while(1){
		data = UART_u8RecieveData();
		if(data!=0){
			LCD_vidWriteData(data);
		}
	}
	return 0 ;
}
