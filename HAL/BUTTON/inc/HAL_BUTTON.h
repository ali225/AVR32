/*
 * HAL_BUTTON.h
 *
 *  Created on: Oct 7, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef BUTTON_HAL_BUTTON_H_
#define BUTTON_HAL_BUTTON_H_


/************* Type def section ************/
typedef enum
{
	BUTTON0,
	BUTTON1,
	BUTTON2,
	MAX_NUM_OF_BUTTONS
}buttonX_t;

typedef enum
{
	BUTTON_NOT_PRESSED,
	BUTTON_PRESSED
}buttonState_t;


/************* Function declaration section ************/
extern stdReturnType_t initButton(buttonX_t buttonID);
extern stdReturnType_t getButtonState(buttonX_t buttonID, buttonState_t * pbuttonState);

#endif /* BUTTON_HAL_BUTTON_H_ */
