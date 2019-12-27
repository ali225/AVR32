/*
 * seven.c
 *
 *  Created on: Oct 9, 2019
 *      Author: Eng Ali Gamal
 */
#include "util/delay.h"
#include "../../../LIB/std_types.h"
#include "../../../MCAL/DIO/inc/DIO.h"
#include "../inc/HAL_Seven.h"
#include "../inc/HAL_Seve_cfg.h"

/*
 * Name:  initSevenSegment
 * brief: used to config. and init given seven segment.
 * params:
 * 			IN: segmentID : the name of the needed seven segments.
 *
 */
stdReturnType_t initSevenSegment(segments_t segmentID)
{
	stdReturnType_t retStatus = ERROR;

	switch(segmentID)
	{
		case SEVEN_SEGMENT0:
			retStatus = DIO_init(SEVEN_SEG0_ENABLE_PORT, SEVEN_SEG0_ENABLE_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG0_PINA_PORT, SEVEN_SEG0_PINA_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG0_PINB_PORT, SEVEN_SEG0_PINB_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG0_PINC_PORT, SEVEN_SEG0_PINC_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG0_PIND_PORT, SEVEN_SEG0_PIND_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG0_DB_PORT, SEVEN_SEG0_DB_PIN, OUTPUT);
			break;

		case SEVEN_SEGMENT1:
			retStatus = DIO_init(SEVEN_SEG1_ENABLE_PORT, SEVEN_SEG1_ENABLE_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG1_PINA_PORT, SEVEN_SEG1_PINA_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG1_PINB_PORT, SEVEN_SEG1_PINB_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG1_PINC_PORT, SEVEN_SEG1_PINC_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG1_PIND_PORT, SEVEN_SEG1_PIND_PIN, OUTPUT);
			retStatus |= DIO_init(SEVEN_SEG1_DB_PORT, SEVEN_SEG1_DB_PIN, OUTPUT);
			break;

		default:
			/* invalid segment ID*/
			retStatus = ERROR;
			break;
	}

	return retStatus;
}

/*
 * Name:  controlSevenSegment
 * brief: used to enable/disable given seven segment.
 * params:
 * 			IN: segmentID : the name of the needed seven segments.
 * 			IN: state : the state of seven segments ENABLED/DISABLED.
 *
 */
stdReturnType_t controlSevenSegment(segments_t segmentID, segmentState_t state)
{
	stdReturnType_t retStatus;

	switch(segmentID)
	{
		case SEVEN_SEGMENT0:
			DIO_write(SEVEN_SEG0_ENABLE_PORT, SEVEN_SEG0_ENABLE_PIN, (pinState_t)state);
			retStatus = SUCCESS;
			break;

		case SEVEN_SEGMENT1:
			DIO_write(SEVEN_SEG1_ENABLE_PORT, SEVEN_SEG1_ENABLE_PIN, (pinState_t)state);
			retStatus = SUCCESS;
			break;

		default:
			retStatus = ERROR;
			break;
	}
	return retStatus;
}

/*
 * Name:  writeToSevenSegment
 * brief: used to write given number to given seven segment.
 * params:
 * 			IN: segmentID : the name of the needed seven segments.
 * 			IN: num : the num to write and should be [0:9].
 *
 */
stdReturnType_t writeToSevenSegment(segments_t segmentID, SegmentNumbers_t num)
{
 stdReturnType_t retStatus = ERROR;

	switch(segmentID)
	{
		case SEVEN_SEGMENT0:
			retStatus  = DIO_write(SEVEN_SEG0_PINA_PORT, SEVEN_SEG0_PINA_PIN, GET_PIN_VAL(num, 0));
			retStatus |= DIO_write(SEVEN_SEG0_PINB_PORT, SEVEN_SEG0_PINB_PIN, GET_PIN_VAL(num, 1));
			retStatus |= DIO_write(SEVEN_SEG0_PINC_PORT, SEVEN_SEG0_PINC_PIN, GET_PIN_VAL(num, 2));
			retStatus |= DIO_write(SEVEN_SEG0_PIND_PORT, SEVEN_SEG0_PIND_PIN, GET_PIN_VAL(num, 3));
			break;

		case SEVEN_SEGMENT1:
			retStatus  = DIO_write(SEVEN_SEG1_PINA_PORT, SEVEN_SEG1_PINA_PIN, GET_PIN_VAL(num, 0));
			retStatus |= DIO_write(SEVEN_SEG1_PINB_PORT, SEVEN_SEG1_PINB_PIN, GET_PIN_VAL(num, 1));
			retStatus |= DIO_write(SEVEN_SEG1_PINC_PORT, SEVEN_SEG1_PINC_PIN, GET_PIN_VAL(num, 2));
			retStatus |= DIO_write(SEVEN_SEG1_PIND_PORT, SEVEN_SEG1_PIND_PIN, GET_PIN_VAL(num, 3));
			break;

		default:
			retStatus = ERROR;
			break;
	}

 return retStatus;
}

/*
 * Name:  writeDecimalPoint
 * brief: used to write given value to given seven segment decimal point.
 * params:
 * 			IN: segmentID : the name of the needed seven segments.
 * 			IN: state : the state of decimal point.
 *
 */
static stdReturnType_t writeDecimalPoint(segments_t segmentID, segmentState_t state)
{
	stdReturnType_t retStatus = ERROR;

		switch(segmentID)
		{
			case SEVEN_SEGMENT0:
				retStatus  = DIO_write(SEVEN_SEG0_DB_PORT, SEVEN_SEG0_DB_PIN, state);
				break;

			case SEVEN_SEGMENT1:
				retStatus  = DIO_write(SEVEN_SEG1_DB_PORT, SEVEN_SEG1_DB_PIN, state);
				break;

			default:
				retStatus = ERROR;
				break;
		}

	 return retStatus;
}

/*
 * Name:  TurnOnDecimalPoint
 * brief: used to turn on seven segment decimal point.
 * params:
 * 			IN: segmentID : the name of the needed seven segments.
 *
 */
stdReturnType_t TurnOnDecimalPoint(segments_t segmentID)
{
	return writeDecimalPoint(segmentID, SEGMENT_ENABLED);
}

/*
 * Name:  TurnOffDecimalPoint
 * brief: used to turn off seven segment decimal point.
 * params:
 * 			IN: segmentID : the name of the needed seven segments.
 *
 */
stdReturnType_t TurnOffDecimalPoint(segments_t segmentID)
{
	return writeDecimalPoint(segmentID, SEGMANT_DISABLED);
}
