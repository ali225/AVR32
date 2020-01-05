/*
 * main_Seven.c
 *
 *  Created on: Jan 1, 2020
 *      Author: Eng Ali Gamal
 */
#include "util/delay.h"
#include "LIB/std_types.h"
#include "HAL/BUTTON/inc/HAL_BUTTON.h"
#include "HAL/seven/inc/HAL_Seven.h"

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

/******* lab 3 *******/
/*
 int main() {
 u8 num1 = 0;
 u8 num2 = 0;
 u8 i = 0;
 u8 j = 0;
 u8 k = 0;
 // init Seven segment
 initSevenSegment(SEVEN_SEGMENT0);
 initSevenSegment(SEVEN_SEGMENT1);

 controlSevenSegment(SEVEN_SEGMENT0, SEGMANT_DISABLED);
 controlSevenSegment(SEVEN_SEGMENT1, SEGMANT_DISABLED);

 while (1) {

 for (int i = 0; i < 10; i++) {
 for (int j = 0; j < 10; j++) {
 for (int k = 0; k < 40; k++) {
 controlSevenSegment(SEVEN_SEGMENT0, SEGMENT_ENABLED);
 controlSevenSegment(SEVEN_SEGMENT1, SEGMANT_DISABLED);
 TurnOnDecimalPoint(SEVEN_SEGMENT0);
 writeToSevenSegment(SEVEN_SEGMENT0, num1);
 num1++;
 _delay_ms(100);

 controlSevenSegment(SEVEN_SEGMENT0, SEGMANT_DISABLED);
 controlSevenSegment(SEVEN_SEGMENT1, SEGMENT_ENABLED);
 TurnOnDecimalPoint(SEVEN_SEGMENT1);
 writeToSevenSegment(SEVEN_SEGMENT1, num2);
 num2++;
 _delay_ms(100);

 }
 }
 }
 }
 }
 */

/*
// Challenge2
int  main(void) {
	// Declaration and initial variable using counter
    int num = 0;
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
			_delay_ms(200);

		}
		if ((*pbuttonstate1 == BUTTON_PRESSED)) {
			num--;
			_delay_ms(200);
			writeToSevenSegment(SEVEN_SEGMENT0, num);


		}
		if ((num == 10) && (num == -1)){
			num = 0;
		}

	}

}

*/

/************ Lab1 ***************/
/*
 int main() {
 initSevenSegment(SEVEN_SEGMENT0);
 controlSevenSegment(SEVEN_SEGMENT0, SEGMENT_ENABLED);
 u8 num = 0;
 u8 i = 0;
 while (1) {
 for (i = 0; i <= 9; i++) {
 TurnOnDecimalPoint(SEVEN_SEGMENT0);
 TurnOnDecimalPoint(SEVEN_SEGMENT0);
 writeToSevenSegment(SEVEN_SEGMENT0, num);
 num++;
 _delay_ms(500);
 }
 }

 }
 */
