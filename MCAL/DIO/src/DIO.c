/*
 * DIO.c
 *
 *  Created on: Dec 26, 2019
 *      Author: Eng Ali Gamal
 */

#include "stdlib.h"
#include "../../../LIB/std_types.h"
#include "../../../LIB/bit_math.h"
#include "../../../LIB/registers.h"
#include "../../DIO/inc/DIO.h"

/*
 * Name:  DIO_init
 * brief: used to config. given pin in a given port as input or output
 * params:
 * 			IN: PortName : the name of the port.
 * 			IN: pinNum : the pin number.
 * 			IN: direction : the direction of the pin INPUT/OUTPUT.
 */
stdReturnType_t DIO_init(portX_t PortName, pinX_t pinNum, pinDir_t direction)
{
	stdReturnType_t status = ERROR;

	/*@TODO: Validation of input */

	switch(PortName)
	{
		case PORT_A:
			if(INPUT == direction)
			{
				CLR_BIT(DDRA, pinNum);
				status = SUCCESS;
			}
			else if (OUTPUT == direction)
			{
				SET_BIT(DDRA, pinNum);
				status = SUCCESS;
			}
			else
			{
				status = ERROR;
			}
			break;

		case PORT_B:
			if(INPUT == direction)
			{
				CLR_BIT(DDRB, pinNum);
				status = SUCCESS;
			}
			else if (OUTPUT == direction)
			{
				SET_BIT(DDRB, pinNum);
				status = SUCCESS;
			}
			else
			{
				status = ERROR;
			}
			break;

		case PORT_C:
			if(INPUT == direction)
			{
				CLR_BIT(DDRC, pinNum);
				status = SUCCESS;
			}
			else if (OUTPUT == direction)
			{
				SET_BIT(DDRC, pinNum);
				status = SUCCESS;
			}
			else
			{
				status = ERROR;
			}
			break;

		case PORT_D:
			if(INPUT == direction)
			{
				CLR_BIT(DDRD, pinNum);
				status = SUCCESS;
			}
			else if (OUTPUT == direction)
			{
				SET_BIT(DDRD, pinNum);
				status = SUCCESS;
			}
			else
			{
				status = ERROR;
			}
			break;

		default:
		status = ERROR;
	}


	return status;

}

/*
 * Name:  DIO_read
 * brief: used to read state of given pin in given port.
 * params:
 * 			IN: PortName : the name of the port.
 * 			IN: pinNum : the pin number.
 * 			OUT: ppinState : pointer to the direction of the pin HIGH/LOW.
 */
stdReturnType_t DIO_read(portX_t PortName, pinX_t pinNum, pinState_t * ppinState)
{
	stdReturnType_t status = ERROR;

    /*@TODO: Validation of input */
	if(NULL != ppinState)
	{

		switch(PortName)
		{
			case PORT_A:
				{
					*ppinState = (pinState_t) GET_BIT(PINA, pinNum);
					status = SUCCESS;
					break;
				}

			case PORT_B:
				{
					*ppinState = (pinState_t) GET_BIT(PINB, pinNum);
					status = SUCCESS;
					break;
				}

			case PORT_C:
				{
					*ppinState = (pinState_t) GET_BIT(PINC, pinNum);
					status = SUCCESS;
					break;
				}
				break;

			case PORT_D:
				{
					*ppinState = (pinState_t) GET_BIT(PIND, pinNum);
					status = SUCCESS;
					break;
				}

			default:
			status = ERROR;
		}
	}
	else
	{
		status = ERROR;
	}


		return status;

}

/*
 * Name:  DIO_write
 * brief: used to write value to given pin in a given port.
 * params:
 * 			IN: PortName : the name of the port.
 * 			IN: pinNum : the pin number.
 * 			IN: pinState : the value of the pin.
 */
stdReturnType_t DIO_write(portX_t portName, pinX_t pinNum, pinState_t pinState)
{
	stdReturnType_t status = ERROR;

	/*@TODO: Validation of input */

	switch(portName)
	{
		case PORT_A:
			if(PIN_IS_LOW == pinState)
			{
				CLR_BIT(PORTA, pinNum);
				status = SUCCESS;
			}
			else if (PIN_IS_HIGH == pinState)
			{
				SET_BIT(PORTA, pinNum);
				status = SUCCESS;
			}
			else
			{
				status = ERROR;
			}
			break;

		case PORT_B:
			if(PIN_IS_LOW == pinState)
			{
				CLR_BIT(PORTB, pinNum);
				status = SUCCESS;
			}
			else if (PIN_IS_HIGH == pinState)
			{
				SET_BIT(PORTB, pinNum);
				status = SUCCESS;
			}
			else
			{
				status = ERROR;
			}
			break;

		case PORT_C:
			if(PIN_IS_LOW == pinState)
			{
				CLR_BIT(PORTC, pinNum);
				status = SUCCESS;
			}
			else if (PIN_IS_HIGH == pinState)
			{
				SET_BIT(PORTC, pinNum);
				status = SUCCESS;
			}
			else
			{
				status = ERROR;
			}
			break;

		case PORT_D:
			if(PIN_IS_LOW == pinState)
			{
				CLR_BIT(PORTD, pinNum);
				status = SUCCESS;
			}
			else if (PIN_IS_HIGH == pinState)
			{
				SET_BIT(PORTD, pinNum);
				status = SUCCESS;
			}
			else
			{
				status = ERROR;
			}
			break;

		default:
		status = ERROR;
	}

return status;

}
