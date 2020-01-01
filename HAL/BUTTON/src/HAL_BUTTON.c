/*

 * HAL_BUTTON.c
 *
 *  Created on: Oct 7, 2019
 *      Author: Eng Ali Gamal
 */

#include "util/delay.h"
#include "../../../LIB/std_types.h"
#include "../../../MCAL/DIO/inc/DIO.h"
#include "../inc/HAL_BUTTON.h"
#include "../inc/HAL_BUTTON_cfg.h"


/*
 * Name:  initButton
 * brief: used to config. given pin where the led is connected as input.
 * params:
 * 			IN: buttonID : the name of the needed button.
 *
 */
stdReturnType_t initButton(buttonX_t buttonID)
{
	stdReturnType_t retStatus = ERROR;

	switch(buttonID)
	{
		case BUTTON0:
			retStatus = DIO_init(BUTTON0_PORT, BUTTON0_PIN, INPUT);
			break;

		case BUTTON1:
			retStatus = DIO_init(BUTTON1_PORT, BUTTON1_PIN, INPUT);
			break;

		case BUTTON2:
			retStatus = DIO_init(BUTTON2_PORT, BUTTON2_PIN, INPUT);
			break;

		default:
			/* ERROR given buttonID is not supported */
			retStatus = ERROR;
			break;
	}
	return retStatus;
}

/*
 * Name:  getButtonState
 * brief: used to check state of given button.
 * params:
 * 			IN: buttonID : the name of the needed button.
 * 			OUT: pbuttonState : pointer to the button state BUTTON_PRESSED/BUTTON_NOT_PRESSED.
 */
stdReturnType_t getButtonState(buttonX_t buttonID, buttonState_t * pbuttonState)
{
	stdReturnType_t retStatus = ERROR;
	pinState_t pinState;

	/* Read button pin state */
	switch(buttonID)
	{
		case BUTTON0:
			retStatus = DIO_read(BUTTON0_PORT,BUTTON0,&pinState);
			if(PIN_IS_HIGH == pinState)
			{
				_delay_ms(30);
				retStatus = DIO_read(BUTTON0_PORT,BUTTON0,&pinState);

			}
			else
			{
				/* Do nothing */
			}

			break;

		case BUTTON1:
			retStatus = DIO_read(BUTTON1_PORT, BUTTON1_PIN, &pinState);
			if(PIN_IS_HIGH == pinState)
			{
				_delay_ms(30);
				retStatus = DIO_read(BUTTON1_PORT, BUTTON1_PIN, &pinState);
			}
			else
			{
				/* Do nothing */
			}
			break;

		case BUTTON2:
			retStatus = DIO_read(BUTTON2_PORT, BUTTON2_PIN, &pinState);
			if(PIN_IS_HIGH == pinState)
			{
				_delay_ms(30);
				retStatus = DIO_read(BUTTON2_PORT, BUTTON2_PIN, &pinState);
			}
			else
			{
				/* Do nothing */
			}
			break;

		default:
			/* ERROR given buttonID is not supported */
			retStatus = ERROR;
			break;
	}

	/* Check button state */
	if( (SUCCESS == retStatus) && (PIN_IS_HIGH == pinState))
	{
		*pbuttonState = BUTTON_PRESSED;
		retStatus = SUCCESS;
	}
	else if((SUCCESS == retStatus) && (PIN_IS_LOW == pinState))
	{
		*pbuttonState = BUTTON_NOT_PRESSED;
		retStatus = SUCCESS;
	}
	else
	{
		retStatus = ERROR;
	}

	return retStatus;

}
