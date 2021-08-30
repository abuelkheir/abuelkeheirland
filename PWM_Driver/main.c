
#include "STD_TYPES.h"
#include "ADC.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "PWM_int.h"

int main()
{
	LCD_vidInit();
	ADC_vidInit();
	DIO_vidSetPinDirection(PORTD_REG,DIO_u8PIN_5,DIO_u8OUTPUT);
	PWM_vidPwmInit(TIMER_1);
	u16 Analog_Value;
	u16 update;
	u8 angleDegree;
	PWM_StartTimer(TIMER_1);
	while(1)
	{
		Analog_Value=ADC_u16Read(ADC_ACDMUX_CHANNEL_ADC0 );
		Analog_Value=(u16)(((u32)Analog_Value*5000)/1024);
		angleDegree=(u8)(((u32)Analog_Value*180)/5000);
		PWM_vidSetPwmDutyCycle(TIMER_1,(f32)Analog_Value/1000+5);
		if (update!=Analog_Value)
		{
			LCD_vidSendCommand(LCD_u8CLEAR_DISPLAY);
			if ((angleDegree/100)%10)
				LCD_vidWriteData((angleDegree/100)%10+'0');
			if ((angleDegree/10)%10 || (angleDegree/100)%10)
				LCD_vidWriteData((angleDegree/10)%10+'0');
			LCD_vidWriteData(angleDegree%10+'0');
			update=Analog_Value;
		}
	}
	return 0;
}
