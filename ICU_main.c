/*
 * ICU_main.c
 *
 *  Created on: Jan 18, 2020
 *      Author: Eng Ali Gamal
 */


#include "avr/io.h"
int main ( )
{
	unsigned int t;
	DDRA = 0xFF;
	DDRB = 0xFF;
	PORTD = 0xFF;
	TCCR1A = 0;
	TIFR = (1<<ICF1);		/* clear input capture flag */
	TCCR1B = 0x41;			/* capture on rising edge */

	while ((TIFR&(1<<ICF1)) == 0);  /* monitor for capture*/
	t = ICR1;
	TIFR = (1<<ICF1);		/* clear capture flag */

	while ((TIFR&(1<<ICF1)) == 0);  /* monitor for next rising
					edge capture */

	t = ICR1 - t;  			/* period= recent capture-
					previous capture */
	PORTA = t;  			/* put period count on PORTA & PORTB */
	PORTB = t>>8;

	while (1);
	return 0;
}
