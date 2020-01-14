/*

 * interrupts_main.c
 *
 *  Created on: Jan 5, 2020
 *      Author: Eng Ali Gamal

#include <avr/io.h>
//#include "util/delay.h"

#include "stdlib.h"
#include "LIB/std_types.h"
#include "HAL/LED/inc/HAL_led.h"
#include "HAL/BUTTON/inc/HAL_BUTTON.h"
#include "MCAL/interupts/ins/MCAL_interrupts.h"




#include <avr/io.h>
#include <avr/interrupt.h>

/* External INT0 Interrupt Service Routine

#include "avr/interrupt.h"

int main(void)
{
	DDRD = 1<<6; //PD6 as an OUTPUT
	PORTD =1 <<2; // Pull-up activated
	GICR = (1<<INT0); //enable external interrupt 0
	sei ();           // enable interrupts

	while(1);   // wait here

}

ISR(INT0_vect)
{
	PORTD ^= (1<<3);  //toggle PORTD.6
}


#include "avr/interrupt.h"

int main()
{
		DDRD = 1<<6; //PD6 as an OUTPUT
		PORTD =1 <<2; // Pull-up activated
		GICR = (1<<INT0); //enable external interrupt 0
		sei ();           // enable interrupts

		while(1);   // wait here

}

ISR(INT0_vect)
{
   PORTD ^= (1<<3);  //toggle PORTD.6
}




u8 x = 0;
u8 *pbuttonstate = &x;

ISR(INT0_vect)
{
	initButton(BUTTON0);
	getButtonState(BUTTON0,pbuttonstate);

	if(*pbuttonstate == BUTTON_PRESSED){
	toogleLed(LED0); //toggle led state
	}else{
		toogleLed(LED0);
	}
}


main()
{
	initExternalInterrupt(INT_0,RISING_EDGE,ISR);
	initLed(LED0);
	turnOnLed(LED0);
	//PORTD = PORTD | (1<<PD0); // Initialization Led is off at the beginning(Negative Logic)

	while(1)
	{

	}

	return 0;
}


*/
