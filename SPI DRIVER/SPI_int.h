/*
 * SPI_int.h
 *
 *  Created on: Aug 29, 2021
 *      Author: a7med
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_

void SPI_vidMasterInit(void);
void SPI_vidSlaveInit(void);
void SPI_vidTransfer(u8 Data);
u8 SPI_u8Recieve(void);
#endif /* SPI_INT_H_ */
