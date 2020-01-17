/*

 * interrupts_main.c
 *
 *  Created on: Jan 5, 2020
 *      Author: Eng Ali Gamal
 */
#include <avr/io.h>
#include "util/delay.h"
#include "stdlib.h"
#include "LIB/std_types.h"
#include "HAL/seven/inc/HAL_Seven.h"
#include "HAL/LED/inc/HAL_led.h"
#include "HAL/BUTTON/inc/HAL_BUTTON.h"
#include "MCAL/interupts/ins/MCAL_interrupts.h"

u8 flag = 0;
//u8 x;
//u8 *pbuttonstate = &x;

/*
void call_back(void) {
	flag = 1;
	//toogleLed(LED2);
}
*/

/*
 main()
{
	stdReturnType_t status = SUCCESS;

	status = initLed(LED2);
	//status |=initButton(BUTTON2);
	status |=initExternalInterrupt(INT_0,RISING_EDGE,call_back);

	turnOnLed(LED2);
	while(1)
	{

	}
	return 0;
}
*/
/*

int main()
{
	stdReturnType_t status = SUCCESS;

	status=initLed(LED2);
	status|=initButton(BUTTON2);
	status|=initExternalInterrupt(INT_0,FALLING_EDGE,call_back);

	while(1)
	  {
		//getButtonState(BUTTON2,pbuttonstate);

	//if (*pbuttonstate == BUTTON_PRESSED)
	  if (flag == 0){
		    _delay_ms(500);
	    status|=turnOnLed(LED2);
	  }
	else if(flag == 1)
	  {

	    status|=turnOffLed(LED2);
	    _delay_ms(500);
	    flag =0;
	  }

	  }
 return 0;
}
*/

/*
int main() {

	stdReturnType_t status = SUCCESS;

	/************** counting on a seven segment using interrupt **********/
/*
	status = initSevenSegment(SEVEN_SEGMENT0);
	status |= controlSevenSegment(SEVEN_SEGMENT0, SEGMENT_ENABLED);
	status |= initButton(BUTTON2);
	status |= initExternalInterrupt(INT_0, RISING_EDGE, call_back);

	int count = 0;
	while (1) {
		if (flag == 1) {
			count++;
			_delay_ms(60);
			flag = 0;
			if (count > 9) {
				count = 0;
			}
		}

		status |= writeToSevenSegment(SEVEN_SEGMENT0, count);

	}
	return 0;

}
*/
//#include <avr/io.h>
//#include <avr/interrupt.h>

// External INT0 Interrupt Service Routine
/*

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


 int main()
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

