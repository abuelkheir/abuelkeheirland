/*
 * PWM_int.h
 *
 *  Created on: Aug 25, 2021
 *      Author: Lenovo
 */

#ifndef PWM_INT_H_
#define PWM_INT_H_


#define TIMER_0          0
#define TIMER_1          1
#define TIMER_2          2


/* Clock Sources Timer 0*/

#define PWM_CS0_STOPED                  0X00
#define PWM_CS0_INT_0                   0x01
#define PWM_CS0_INT_8                   0x02
#define PWM_CS0_INT_64                  0x03
#define PWM_CS0_INT_256                 0x04
#define PWM_CS0_INT_1024                0x05

/* Clock Sources Timer 1*/
#define PWM_CS1_STOPED                  0X00
#define PWM_CS1_INT_0                   0x01
#define PWM_CS1_INT_8                   0x02
#define PWM_CS1_INT_64                  0x03
#define PWM_CS1_INT_256                 0x04
#define PWM_CS1_INT_1024                0x05


#define PWM_CS_CLEAR_MASK              ~(0x07)     //clock source clear mask

#define PWM_CS0_MODE                    PWM_CS0_INT_256 //selecting clock source mode for timer 0
#define PWM_CS1_MODE                    PWM_CS0_INT_64  //selecting clock source mode for timer 1
#define PWM_ICR1_VALUE                  2500            //ICR1 value


void PWM_vidPwmInit(u8 Copy_TimerNo);  //initialization function

void PWM_vidSetPwmDutyCycle(u8 Copy_TimerNo, u32 Copy_DC); //setting duty cycle

void PWM_StartTimer(u8 Copy_TimerNo);  //start timer function

void PWM_StopTimer(u8 Copy_TimerNo);   //stop timer function


#endif /* PWM_INT_H_ */

