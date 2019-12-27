/*
 * DIO.h
 *
 *  Created on: Dec 26, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef MCAL_DIO_INC_DIO_H_
#define MCAL_DIO_INC_DIO_H_


/* portX_t data type */
typedef enum
{
	PORT_A,
	PORT_B,
	PORT_D,
	PORT_C
}portX_t;

/* pinX_t data type */

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7

}pinX_t;


/* pinDir_t data type */
typedef enum
{
	INPUT,
	OUTPUT
}pinDir_t;

/* pinState_t data type */

typedef enum
{
	PIN_IS_LOW,
	PIN_IS_HIGH

}pinState_t;

/************ Function declaration section ***********/

extern stdReturnType_t DIO_init(portX_t PortName, pinX_t PinNum, pinDir_t direction);
extern stdReturnType_t DIO_read(portX_t PortName, pinX_t PinNum,pinState_t *ppinstate);
extern stdReturnType_t DIO_write(portX_t PortName, pinX_t PinNum,pinState_t pinstate);


#endif /* MCAL_DIO_INC_DIO_H_ */
