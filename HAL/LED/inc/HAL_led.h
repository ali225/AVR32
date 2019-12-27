/*
 * HAL_led.h
 *
 *  Created on: Dec 26, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef HAL_LED_INC_HAL_LED_H_
#define HAL_LED_INC_HAL_LED_H_

/************* Type def section ************/
typedef enum
{
	LED0,
	LED1,
	LED2,
	MAX_NUM_OF_LEDS
}ledX_t;


/************* Function declaration section ************/
extern stdReturnType_t initLed(ledX_t ledID);
extern stdReturnType_t turnOnLed(ledX_t ledID);
extern stdReturnType_t turnOffLed(ledX_t ledID);
extern stdReturnType_t toogleLed(ledX_t ledID);
/*extern stdReturnType_t TogealLed(ledX_t LedID);*/


#endif /* HAL_LED_INC_HAL_LED_H_ */
