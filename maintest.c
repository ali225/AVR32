/*
 * main.c
 *
 *  Created on: Nov 10, 2019
 *      Author: Eng Ali Gamal
 */
/*

#include <avr/io.h>
#include "util/delay.h"
#include "LIB/std_types.h"
//#include "HAL/LED/inc/HAL_led.h"
#include "HAL/BUTTON/inc/HAL_BUTTON.h"
#include "HAL/seven/inc/HAL_Seven.h"

#define F_CPU 16000000UL //16 MHZ

// Challenge2
int  main(void) {
	// Declaration and initial variable using counter
	u8 num = 0;
	// Declaration pointer using Button
	u8 x = 0;
	u8 y = 0;
	u8 *pbuttonstate = &x;
	u8 *pbuttonstate1 = &y;
	initButton(BUTTON0); // configure pin 0 in PORTD as input pin
	initButton(BUTTON1); // configure pin 1 in PORTD as input pin

	// initialize the 7-segment
	initSevenSegment(SEVEN_SEGMENT0);
	controlSevenSegment(SEVEN_SEGMENT0, SEGMENT_ENABLED);
	while (1) {
		getButtonState(BUTTON0, pbuttonstate);
		getButtonState(BUTTON1, pbuttonstate1);

		// check if the push button is pressed

		if (*pbuttonstate == BUTTON_PRESSED) {
			TurnOnDecimalPoint(SEVEN_SEGMENT0);
			writeToSevenSegment(SEVEN_SEGMENT0, num);
			// if overflow occurs
			num++;
			_delay_ms(500);

		}
		if ((*pbuttonstate1 == BUTTON_PRESSED)) {
			writeToSevenSegment(SEVEN_SEGMENT0, num);
			num--;
			_delay_ms(500);

		}

	}
}

*/
/*int main() {
 initSevenSegment(SEVEN_SEGMENT0);
 controlSevenSegment(SEVEN_SEGMENT0, SEGMENT_ENABLED);
 u8 num = 0;
 u8 i = 0;
 while (1) {
 for (i = 0; i <= 9; i++) {
 TurnOnDecimalPoint(SEVEN_SEGMENT0);
 writeToSevenSegment(SEVEN_SEGMENT0, num);
 num++;
 _delay_ms(500);
 }
 }

 }*/

/*// Exercise5
 int main(void) {
 u8 num = 0;
 u8 x = 0;
 u8 *pbuttonstate = &x;
 initButton(BUTTON0); // configure pin 4 in PORTD as input pin

 // initialize the 7-segment
 initSevenSegment(SEVEN_SEGMENT0);
 controlSevenSegment(SEVEN_SEGMENT0, SEGMENT_ENABLED);
 while (1) {
 getButtonState(BUTTON0, pbuttonstate);
 // check if the push button is pressed or not

 if (*pbuttonstate == BUTTON_PRESSED) {
 TurnOnDecimalPoint(SEVEN_SEGMENT0);
 _delay_ms(100);
 writeToSevenSegment(SEVEN_SEGMENT0, num);
 // if overflow occurs
 _delay_ms(100);
 num++;
 }else if(num == 10){
 num=0;
 }

 }

 }*/

/*
 // Exercise4

 int main(void) {
 u8 x = 0;
 u8 *Pbuttonstate = &x;
 unsigned char button = 0;
 initButton(BUTTON0);   // configure pin 0 of PORTD to be input pin
 //activate the internal pull up resistor of PB0

 initLed(LED0);  // configure pin 0 of PORTC to be output pin
 turnOnLed(LED0);  // led is off at the beginning

 while (1) {
 getButtonState(BUTTON0, Pbuttonstate);
 // check if the push button is pressed or not

 if (!(*Pbuttonstate == BUTTON_PRESSED)) {
 if (button == 0) {
 toogleLed(LED0); // toggle the led
 button = 1;
 } else {
 button = 0;
 }
 }
 }
 }
 */

/*// Exercise3


 int main()
 {
 // Declaration pointer
 u8 x =0;
 u8 y =0;
 u8 z =0;
 u8 *pbuttonState=&x;
 u8 *pbuttonState2=&y;
 u8 *pbuttonState3=&z;

 ****** Initialization Code ******
 initButton(BUTTON0); // configure pin 0 of PORTD to be input pin
 initButton(BUTTON1); // configure pin 1 of PORTD to be input pin
 initButton(BUTTON2); // configure pin 2 of PORTD to be input pin

 initLed(LED0);    // configure pin 5 of PORTD to be output pin
 initLed(LED1);    // configure pin 6 of PORTD to be output pin
 initLed(LED2);    // configure pin 7 of PORTD to be output pin

 //initialize leds
 turnOffLed(LED0);  // led1 is off at the beginning
 turnOffLed(LED1);  // led2 is off at the beginning
 turnOffLed(LED2);  // led2 is off at the beginning

 while(1)
 {
 ****** Application Code ******
 getButtonState(BUTTON0,pbuttonState);
 getButtonState(BUTTON1,pbuttonState2);
 getButtonState(BUTTON2,pbuttonState3);


 // Check the button status pressed or not
 if(*pbuttonState == BUTTON_PRESSED)
 {
 turnOnLed(LED0); // LED ON
 }
 else
 {
 turnOffLed(LED0); // LED OFF
 }
 if(*pbuttonState2 == BUTTON_PRESSED)
 {
 turnOnLed(LED1); // LED ON

 }
 else
 {
 turnOffLed(LED1); // LED OFF
 }
 if(*pbuttonState3 == BUTTON_PRESSED)
 {
 turnOnLed(LED2); // LED ON
 }else
 {
 turnOffLed(LED2);  // LED OFF
 }
 }
 }*/
/*
 int main(void)
 {
 u8 x = 0;
 u8 y = 0;
 u8 *pbuttonState=&x;
 u8 *pbuttonState2=&y;

 initButton(BUTTON0); // configure pin 0 of PORTB to be input pin
 initButton(BUTTON1); // configure pin 1 of PORTB to be input pin
 initLed(LED0);    // configure pin 0 of PORTC to be output pin
 initLed(LED1);    // configure pin 1 of PORTC to be output pin

 //initialize leds
 turnOffLed(LED0);  // led1 is off at the beginning
 turnOffLed(LED1);  // led2 is off at the beginning

 getButtonState(BUTTON0,pbuttonState);
 getButtonState(BUTTON1,pbuttonState2);

 while(1)
 {
 if(*pbuttonState == BUTTON_PRESSED) // Check if the first switch is pressed
 {
 turnOnLed(LED0); // LED1 ON
 }
 else
 {
 turnOffLed(LED0); // LED1 OFF
 }
 //if(*pbuttonState2 == BUTTON_PRESSED) // Check if the second switch is pressed
 //{
 //	turnOnLed(LED1); // LED2 ON
 //}
 //else
 //{
 //turnOffLed(LED1);// LED2 OFF
 //}
 }
 }
 */

/*

 // Exercise2
 int main(void)
 {
 initLed(LED1); //configure pin 6 in PORTD as output pin
 turnOffLed(LED1); // LED Off
 while(1)
 {
 //		PORTD |=(1<<6); // LED ON
 //		_delay_ms(1000);
 //		PORTD &= ~(1<<6);    // LED OFF
 //		_delay_ms(1000);
 ********** Another Method ***********
 toogleLed(LED1); // Toggle LED
 _delay_ms(100);
 **************************************
 }
 }
 */

/*
 //Exercise1.c

 int main()
 {
 u8 x =0;
 u8 *pbuttonState=&x;


 ****** Initialization Code ******
 initButton(BUTTON0); // configure pin 1 in PORTD as input pin
 initLed(LED0); // configure pin 6 in PORTD as output pin

 turnOffLed(LED0); // LED OFF
 while(1)
 {
 ****** Application Code ******
 getButtonState(BUTTON0,pbuttonState);
 // Check the button status pressed or not
 if(*pbuttonState == BUTTON_PRESSED)
 {
 turnOnLed(LED0); // LED ON
 }
 else if (*pbuttonState == BUTTON_NOT_PRESSED)
 {
 turnOffLed(LED0); // LED OFF
 }
 }
 }*/
/*
 main() {

 //initLed(LED1);
 u8 i=0;
 DDRD = 0xFF;
 while(1){

 while(i<7)
 {
 PORTD =(1<<i);
 _delay_ms(1000);
 i=i+1;
 }
 while(i>0)
 {
 PORTD =(1<<i);
 _delay_ms(1000);
 i=i-1;
 }
 _delay_ms(1000);
 turnOnLed(LED1);
 _delay_ms(1000);
 turnOffLed(LED1);
 }
 return 0;
 }
 */
