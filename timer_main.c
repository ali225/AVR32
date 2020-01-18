/*

 * timer_main.c
 *
 *  Created on: Jan 17, 2020
 *      Author: Eng Ali Gamal

#include "util/delay.h"
#include "LIB/std_types.h"
#include "HAL/LED/inc/HAL_led.h"
#include "HAL/LCD/inc/HAL_lcd.h"
#include "HAL/BUTTON/inc/HAL_BUTTON.h"
#include "MCAL/Timer/TIM0.h"
#include "MCAL/interupts/ins/MCAL_interrupts.h"

#include "avr/io.h"
#include "avr/interrupt.h"

#define Number_of_SECOND 2
u8 g_tick = 0;

void call_back(void) {
	g_tick++;
	if (g_tick == Number_of_SECOND) {
		toogleLed(LED0); // toggle led
		g_tick = 0;       // clear the counter
	}
}

 main() {

	initLed(LED0);
	turnOffLed(LED0);
	//enableGlobalInterrupts();
	SREG  |= (1<<7);
	TIM0_init();
	while (1) {

	}

	return 0;
}

volatile unsigned int count0 = 1;  //to increase the counting range

 //the compare match ISR for the first task in the timer//
 void Call_back(void) {
 //this ISR is used to toggle led0 every .1 sec , led1 every .5 sec and led2 every 1 sec
 stdReturnType_t status = SUCCESS;
 count0++;
 if ((count0 % 100 == 0) && (count0 >= 100)) {
 status |= toogleLed(LED0);
 //count0 = 0;
 }
 if (count0 % 500 == 0 && count0 >= 500) {
 status |= toogleLed(LED1);
 //count0 = 0;
 }
 if (count0 == 1000) {
 toogleLed(LED2);
 //LED_ON(LED2);
 count0 = 1;
 }
 }

 int main() {


 stdReturnType_t status = SUCCESS;

 status |= initLed(LED0);
 status |= initLed(LED1);
 status |= initLed(LED2);
 TIM0_init(); //each over flow = 1 ms
 //TIM0_setOCRO(250);
 TIM0_setCmIntCallback(Call_back);
 //status |= enableGlobalInterrupts();

 while (1) {

 }
 return 0;
 }
*/
