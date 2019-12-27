/*
 * HAL_led.c
 *
 *  Created on: Oct 6, 2019
 *      Author: Abdelrahman.Elesh
 */

#include "../../../LIB/std_types.h"
#include "../../../MCAL/DIO/inc/DIO.h"
#include "../../LED/inc/HAL_led.h"
#include "../../LED/inc/HAL_les.cfg.h"
#include "util/delay.h"
/*

/*
 * Name:  initLed
 * brief: used to config. given pin where the led is connected as output
 * params:
 * 			IN: ledID : the name of the needed LED.
 *
 */
stdReturnType_t initLed(ledX_t ledID)
{
	stdReturnType_t retStatus = ERROR;

	switch(ledID)
	{
		case LED0:
			retStatus = DIO_init(LED0_PORT, LED0_PIN, OUTPUT);
			break;

		case LED1:
			retStatus = DIO_init(LED1_PORT, LED1_PIN, OUTPUT);
			break;

		case LED2:
			retStatus = DIO_init(LED2_PORT, LED2_PIN, OUTPUT);
			break;

		default:
			/* ERROR given ledID is not supported */
			retStatus = ERROR;
			break;
	}

	return retStatus;
}

/*
 * Name:  changeLedState
 * brief: used to write value to make given LED ON/OFF.
 * params:
 * 			IN: ledID : the name of the needed LED.
 * 			IN: pinState : the value of the pin HIGH/LOW.
 */
static stdReturnType_t changeLedState(ledX_t ledID, pinState_t pinState)
{
	stdReturnType_t retStatus = ERROR;

	/*@TODO : check pinState */

	switch(ledID)
	{
		case LED0:
			retStatus = DIO_write(LED0_PORT, LED0_PIN, pinState);
			break;

		case LED1:
			retStatus = DIO_write(LED1_PORT, LED1_PIN, pinState);
			break;

		case LED2:
			retStatus = DIO_write(LED2_PORT, LED2_PIN, pinState);
			break;

		default:
			/* ERROR given ledID is not supported */
			retStatus = ERROR;
			break;
	}


	return retStatus;
}

/*
 * Name:  changeLedState
 * brief: used to turn given LED ON.
 * params:
 * 			IN: ledID : the name of the needed LED.
 */
stdReturnType_t turnOnLed(ledX_t ledID)
{
	return changeLedState(ledID, PIN_IS_HIGH);
}

/*
 * Name:  changeLedState
 * brief: used to turn given LED OFF.
 * params:
 * 			IN: ledID : the name of the needed LED.
 */
stdReturnType_t turnOffLed(ledX_t ledID)
{
	return changeLedState(ledID, PIN_IS_LOW);
}

stdReturnType_t toogleLed(ledX_t ledID)
{
	stdReturnType_t stats = ERROR;
	_delay_ms(10);
	turnOnLed(ledID);
	_delay_ms(10);
  stats|=	turnOffLed(ledID);
	stats = SUCCESS;
	return stats;
}
/*stdReturnType_t TogealLed(ledX_t LedID){
	stdReturnType_t status = ERROR;
    status = changeLedState(LedID,PIN_IS_HIGH);
    status = SUCCESS;
	status = changeLedState(LedID,PIN_IS_LOW);
	status = SUCCESS;
	return status;
}*/
