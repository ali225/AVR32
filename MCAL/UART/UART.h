/*
 * UART.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Eng Ali Gamal
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#define TX_BUFFER_SIZE 100
#define RX_BUFFER_SIZE 100

extern void UART_init(void);
extern stdReturnType_t UART_transmitAsynchronous(u8 * data, u8 size);
extern stdReturnType_t UART_recieveAsynchronous(u8 * data, u8 * size);
extern stdReturnType_t UART_transmit(u8 * data, u8 size);
extern stdReturnType_t UART_recieve(u8 * data);
extern stdReturnType_t UART_TxIntStatus(u8 status);
extern stdReturnType_t UART_RxIntStatus(u8 status);


#endif /* MCAL_UART_UART_H_ */
