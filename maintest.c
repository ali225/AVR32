/*

 * main.c
 *
 *  Created on: Nov 10, 2019
 *      Author: Eng Ali Gamal
 */

#include "util/delay.h"
#include "LIB/std_types.h"
#include "HAL/LED/inc/HAL_led.h"
#define F_CPU 16000000UL //16 MHZ

int main() {

	initLed(LED1); 
	while (1) {

		_delay_ms(1000);
		turnOnLed(LED1);
		_delay_ms(1000);
		turnOffLed(LED1);
	}
	return 0;
}
