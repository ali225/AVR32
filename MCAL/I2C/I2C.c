/*
 * I2C.c
 *
 *  Created on: Jan 15, 2020
 *      Author: Eng Ali Gamal
 */


#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include <avr/io.h>
#include "I2C.h"
#include "I2C_cfg.h"

void TWI_Init(void)
{
	// TWI initialization
	// Bit Rate: 400.000 kHz
	TWBR = 72;
	// Two Wire Bus Slave Address: 0x1
	// General Call Recognition: Off
	TWAR = (TWI_MASTER_ADDRESS<<1);
	// Generate Acknowledge Pulse: On
	// TWI Interrupt: Off
	TWCR = 0x44;
	TWSR = 0x00;
	TWSR &= (~((1 << TWPS1) | (1 << TWPS0)));
}

void TWI_Start(void)
{
	// Send Start Condition
	TWCR |= (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	// Wait for TWINT flag set in TWCR Register
	while (!(TWCR & (1 << TWINT)));

}

void TWI_Stop(void)
{
	// Send Stop Condition
	TWCR |= (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void TWI_Write(u8 data)
{
	// Put data On TWI Register

	TWDR = data;
	// Send Data
	TWCR = (TWCR & ~(1<<TWSTA)) | (1 << TWINT) | (1 << TWEN);
	// Wait for TWINT flag set in TWCR Register
	while (!(TWCR & (1 << TWINT)));
}

u8 TWI_ReadACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);    //enable Ack
	// Wait for TWINT flag set in TWCR Register
	while (!(TWCR & (1 << TWINT)));
	// Read Data
	return TWDR;
}

u8 TWI_ReadNACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN);
	// Wait for TWINT flag set in TWCR Register
	while (!(TWCR & (1 << TWINT)));
	// Read Data
	return TWDR;
}

u8 TWI_GetStatus(void)
{
	u8 status;
	status = TWSR & 0xF8;
	return status;
}
