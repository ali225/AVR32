/*
 * HAL_Seven.h
 *
 *  Created on: Oct 9, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef HAL_SEVEN_HAL_SEVEN_H_
#define HAL_SEVEN_HAL_SEVEN_H_


/************* Type def and macros section ************/
#define	GET_PIN_VAL(num,ID)	(((num) >> (ID)) & (0x01))

/* Segment datatype */
typedef enum
{
	SEVEN_SEGMENT0,
	SEVEN_SEGMENT1,
	MAX_NUM_OF_SEGMENTS
}segments_t;

typedef enum
{
  Number_0,
  Number_1,
  Number_2,
  Number_3,
  Number_4,
  Number_5,
  Number_6,
  Number_7,
  Number_8,
  Number_9,
  MAX_AVAILABLE_NUMBERS
}SegmentNumbers_t;


/* Segment state */
typedef enum
{
	SEGMANT_DISABLED,
	SEGMENT_ENABLED
}segmentState_t;

#define DECIMAL_POINT_ON	1
#define DECIMAL_POINT_OFF	0


/************* Function declaration section ************/
extern stdReturnType_t initSevenSegment(segments_t segmentID);
extern stdReturnType_t controlSevenSegment(segments_t segmentID, segmentState_t state);
extern stdReturnType_t writeToSevenSegment(segments_t segmentID, SegmentNumbers_t num);
extern stdReturnType_t TurnOnDecimalPoint(segments_t segmentID);
extern stdReturnType_t TurnOffDecimalPoint(segments_t segmentID);

#endif /* HAL_SEVEN_HAL_SEVEN_H_*/

