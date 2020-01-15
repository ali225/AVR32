/*
 * SPI_cfg.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Eng Ali Gamal
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_


/*************** options ***********/

/* Master/Slave */
#define MASTER_MODE 0
#define SLAVE_MODE  1

/* Data order */
#define MSB_FIRST 0
#define LSB_FIRST 1

/* Data transfer mode */
#define SPI_MODE_0  0
#define SPI_MODE_1  1
#define SPI_MODE_2  2
#define SPI_MODE_3  3

/* Baud rate */
#define SPI_BAUD_RATE_4    0
#define SPI_BAUD_RATE_16   1
#define SPI_BAUD_RATE_64   2
#define SPI_BAUD_RATE_128  3


/*** configuration ***/
#define COM_MODE       MASTER_MODE
#define DATA_ORDER     MSB_FIRST
#define SPI_MODE       SPI_MODE_1
#define SPI_BAUD_RATE  SPI_BAUD_RATE_128



#endif /* MCAL_SPI_SPI_CFG_H_ */
