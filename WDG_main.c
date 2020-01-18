/*

 * WDG_main.c
 *
 *  Created on: Jan 18, 2020
 *      Author: Eng Ali Gamal



#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR DDRD
#define LED_PORT PORTD

void WDT_ON()
{

	Watchdog timer enables with typical timeout period 2.1
	second.

	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
}

void WDT_OFF()
{

	This function use for disable the watchdog timer.

	WDTCR = (1<<WDTOE)|(1<<WDE);
	WDTCR = 0x00;
}

int main(void)
{
	WDT_ON();		 Enable the watchdog timer
	LED_DDR |= 0xC0;
	LED_PORT |= (1<<6);	 Set PD6 pin to logic high
	_delay_ms(1000);	 Wait for 1 second
	LED_PORT &= ~(1<<6);	 Clear PD6 pin

    while(1);
}
*/
