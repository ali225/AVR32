/*
 * SPI.c
 *
 *  Created on: Jan 15, 2020
 *      Author: Eng Ali Gamal
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "../../LIB/registers.h"
#include "SPI.h"
#include "SPI_cfg.h"

#define NULL ((void *)0)

static u8 tx_buffer[SPI_TX_BUFFER_SIZE] = {0};
static u8 rx_buffer[SPI_RX_BUFFER_SIZE] = {0};
static u8 tx_counter = 0;
static u8 rx_counter = 0;
static u8 tx_transmit_size = 0;


stdReturnType_t SPI_init (void)
{
   #if(COM_MODE == MASTER_MODE)
	   SET_BIT(SPCR,4);
   #elif(COM_MODE == SLAVE_MODE)
	   CLR_BIT(SPCR,4);
   #endif

   #if(DATA_ORDER == MSB_FIRST)
	   CLR_BIT(SPCR,5);
   #elif(DATA_ORDER == LSB_FIRST)
	   SET_BIT(SPCR,5);
   #endif

   #if(SPI_MODE == SPI_MODE_0)
	   CLR_BIT(SPCR,2);
	   CLR_BIT(SPCR,3);
   #elif(SPI_MODE == SPI_MODE_1)
	   SET_BIT(SPCR,2);
	   CLR_BIT(SPCR,3);
   #elif(SPI_MODE == SPI_MODE_2)
	   CLR_BIT(SPCR,2);
	   SET_BIT(SPCR,3);
   #elif(SPI_MODE == SPI_MODE_3)
	   SET_BIT(SPCR,2);
	   SET_BIT(SPCR,3);
   #endif

   #if(SPI_BAUD_RATE == SPI_BAUD_RATE_4)
	   CLR_BIT(SPCR,0);
	   CLR_BIT(SPCR,1);
   #elif(SPI_BAUD_RATE == SPI_BAUD_RATE_16)
	   SET_BIT(SPCR,0);
	   CLR_BIT(SPCR,1);
   #elif(SPI_BAUD_RATE == SPI_BAUD_RATE_64)
	   CLR_BIT(SPCR,0);
	   SET_BIT(SPCR,1);
   #elif(SPI_BAUD_RATE == SPI_BAUD_RATE_128)
	   SET_BIT(SPCR,0);
	   SET_BIT(SPCR,1);
   #endif

	/* Enable SPI */
	SET_BIT(SPCR,6);

	return SUCCESS;
}


stdReturnType_t SPI_transmit (u8 data)
{
	stdReturnType_t retState = SUCCESS;

	SPDR = data;

	while(GET_BIT(SPSR,7) == 0);

	return retState;
}

stdReturnType_t SPI_recieve (u8 *data)
{
	stdReturnType_t retState = SUCCESS;

	while(GET_BIT(SPSR,7) == 0);

	*data = SPDR;

	return retState;
}


extern stdReturnType_t SPI_transmitAsynchronous(u8 * data, u8 size)
{
	stdReturnType_t returnVal = SUCCESS;


	if( (data != NULL) && (size <= SPI_TX_BUFFER_SIZE) && (tx_counter == 0) )
	{
		tx_transmit_size = size;

		/* Copy data to local buffer */
		for(u8 i = 0;i < size;i++)
		{
			tx_buffer[i] = data[i];
		}

		SPDR = tx_buffer[tx_counter];
	}
	else
	{
		returnVal = ERROR;
	}

	return returnVal;
}


stdReturnType_t SPI_recieveAsynchronous(u8 * data, u8 * size)
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


extern stdReturnType_t SPI_TransferIntStatus(u8 status)
{
	/* Clear TX int enable */
	CLR_BIT(SPCR,7);

	/* update TX int enable status */
	SPCR |= (status<<7);

	return SUCCESS;
}




void __vector_12 (void) __attribute__((signal,used));
void __vector_12 (void)
{
	tx_counter++;

	/* Save recieved byte */
	if(rx_counter < SPI_TX_BUFFER_SIZE)
	{
		rx_buffer[rx_counter] = SPDR;
		rx_counter++;
	}

	if( (tx_counter < tx_transmit_size) && (tx_transmit_size > 0) )
	{
		SPDR = tx_buffer[tx_counter];
	}
	else
	{
		tx_counter = 0;
		tx_transmit_size = 0;
	}
}


