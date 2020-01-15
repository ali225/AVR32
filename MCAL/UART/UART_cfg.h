/*
 * UART_cfg.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Eng Ali Gamal
 */

#ifndef MCAL_UART_UART_CFG_H_
#define MCAL_UART_UART_CFG_H_
/********* Options ***********/

/* Data size */
#define DATA_SIZE_5 0
#define DATA_SIZE_6 1
#define DATA_SIZE_7 2
#define DATA_SIZE_8 3
#define DATA_SIZE_9 4

/* Uart Mode */
#define SYNCHRONOUS_MODE 0
#define ASYNCHRONOUS_MODE 1

/* Uart Mode */
#define STOP_BIT_1 0
#define STOP_BIT_2 1


/********* Configuration ***********/
#define UART_BAUD_RATE 9600
#define UART_DATA_SIZE DATA_SIZE_8
#define UART_MODE ASYNCHRONOUS_MODE
#define UART_STOP_BITS STOP_BIT_1


#endif /* MCAL_UART_UART_CFG_H_ */
