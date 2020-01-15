/*
 * UART.c
 *
 *  Created on: Jan 15, 2020
 *      Author: Eng Ali Gamal
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "../../LIB/registers.h"
#include "UART.h"
#include "UART_cfg.h"



#define NULL ((void *)0)


static u8 tx_buffer[TX_BUFFER_SIZE] = {0};
static u8 rx_buffer[RX_BUFFER_SIZE] = {0};

static u8 tx_counter = 0;
static u8 rx_counter = 0;
static u8 tx_transmit_size = 0;



void UART_init(void)
{
	/* Data size */
	/* Stop bits */
	/* Mode      */
	UCSRC |= (1<<7) | (1<<2) | (1<<1);

	/* Baud rate to 9600 with F_CPU = 16M HZ */
	UBRRH = 0;
	UBRRL = 103;

	/* Start transmission and repection */
	UCSRB |= (1<<4) | (1<<3);
}


stdReturnType_t UART_transmitAsynchronous(u8 * data, u8 size)
{
	stdReturnType_t returnVal = SUCCESS;


	if( (data != NULL) && (size <= TX_BUFFER_SIZE) && (tx_counter == 0) )
	{
		tx_transmit_size = size;

		/* Copy data to local buffer */
		for(u8 i = 0;i < size;i++)
		{
			tx_buffer[i] = data[i];
		}

		UDR = tx_buffer[tx_counter];
	}
	else
	{
		returnVal = ERROR;
	}

	return returnVal;
}



stdReturnType_t UART_recieveAsynchronous(u8 * data, u8 * size)
{
	stdReturnType_t returnVal = SUCCESS;


	if( (data != NULL) && (size != NULL) && (rx_counter > 0) )
	{
		for(u8 i = 0;i < rx_counter;i++)
		{
			data[i] = rx_buffer[i];
		}

		*size = rx_counter;
		rx_counter = 0;
	}
	else
	{
		returnVal = ERROR;
	}

	return returnVal;
}


stdReturnType_t UART_transmit(u8 * data, u8 size)
{
	stdReturnType_t returnVal = SUCCESS;


	if(data != NULL)
	{
		/* Copy data to local buffer */
		for(u8 i = 0;i < size;i++)
		{
			/* Wait until transmission Register Empty */
			while((UCSRA & 0x20) == 0x00);
			UDR = data[i];
		}
	}
	else
	{
		returnVal = ERROR;
	}

	return returnVal;
}


stdReturnType_t UART_recieve(u8 * data)
{
	stdReturnType_t returnVal = SUCCESS;

	if(data != NULL)
	{
		/* Wait until Reception Complete */

		while((UCSRA&0x80) == 0x00);

		*data = UDR;

		/* Clear RX Flag */
		SET_BIT(UCSRA,7);
	}
	else
	{
		returnVal = ERROR;
	}

	return returnVal;
}


stdReturnType_t UART_TxIntStatus(u8 status)
{
	/* Clear TX int enable */
	CLR_BIT(UCSRB,6);

	/* update TX int enable status */
	UCSRB |= (status<<6);

	return SUCCESS;
}
stdReturnType_t UART_RxIntStatus(u8 status)
{
	/* Clear RX int enable */
	CLR_BIT(UCSRB,7);

	/* update RX int enable status */
	UCSRB |= (status<<7);

	return SUCCESS;
}



void __vector_14 (void) __attribute__((signal,used));
void __vector_14 (void)
{
	tx_counter++;

	if(tx_counter < tx_transmit_size)
	{
		UDR = tx_buffer[tx_counter];
	}
	else
	{
		tx_counter = 0;
	}
}



void __vector_13 (void) __attribute__((signal,used));
void __vector_13 (void)
{
	if(rx_counter < RX_BUFFER_SIZE)
	{
		rx_buffer[rx_counter] = UDR;
		rx_counter++;
	}
}


