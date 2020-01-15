/*
 * I2C.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Eng Ali Gamal
 */

#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_


#define TWI_MT_ARB_LOST        0x38
#define TWI_MR_ARB_LOST        0x38
#define TWI_START              0x08
#define TWI_REP_START          0x10
#define TWI_MT_SLA_ACK         0x18
#define TWI_MT_DATA_ACK        0x28
#define TWI_MR_DATA_NOT_ACK    0x58
#define TWI_MR_SLA_NOT_ACK     0x48
#define TWI_MT_SLA_NOT_ACK     0x20
#define TWI_MT_DATA_NOT_ACK    0x30
#define TWI_MR_DATA_ACK        0x50
#define TWI_MR_SLA_ACK         0x40

extern void TWI_Init(void);
extern void TWI_Start(void);
extern void TWI_Stop(void);
extern void TWI_Write(u8 data);
extern u8 TWI_ReadACK(void);
extern u8 TWI_ReadNACK(void);
extern u8 TWI_GetStatus(void);


#endif /* MCAL_I2C_I2C_H_ */
