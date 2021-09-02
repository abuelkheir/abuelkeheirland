/*
 * IIC_int.h
 *
 *  Created on: Aug 30, 2021
 *      Author: a7med
 */

#ifndef IIC_INT_H_
#define IIC_INT_H_


void I2C_vidInit(void);
void I2C_vidSendStart(void);
void I2C_vidSendStop(void);
void I2C_vidSendSLA(u8 Copy_u8SLA);
void I2C_vidSendData(u8 Copy_u8Data);
void I2C_vidRecieveData(u8* Copy_u8DataContainer,u8 Copy_u8AckMode);
u8 I2C_u8CheckStatus(u8 Copy_u8ExpectedStatus);
#endif /* IIC_INT_H_ */
