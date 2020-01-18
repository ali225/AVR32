/*

 * watchdogtimermain.c
 *
 *  Created on: Jan 18, 2020
 *      Author: Eng Ali Gamal

#include "LIB/std_types.h"
#include "HAL/LED/inc/HAL_led.h"
#include "MCAL/WDG/WDG.h"

int main() {

	initLed(LED0);
	turnOnLed(LED0);
	WDG_Refresh(TIME_32_5_MS);

	while (1) {
		//status |= WDG_Refresh(TIME_16_3_MS);
	}
	return 0;

}
*/
