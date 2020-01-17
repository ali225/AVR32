/*
 * LCD_main.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Eng Ali Gamal
 */
/*

#include <avr/io.h>
#include "util/delay.h"
#include "util/delay.h"
#include "LIB/std_types.h"
#include "HAL/LCD/inc/HAL_lcd.h"

 int main() {

	stdReturnType_t status;
while(1){
	char st[] = {'E', 'N','g','/' ,'A', 'i', 'L', '\0' };
	char arr[] = {"Eng Ali gamal aziz "};
	status = LCD_init();
	status |= LCD_displayString_rowCol(arr,0,2);
	//status |=LCD_clearScreen();
	status |=LCD_displayString_rowCol(st,1,2);
	_delay_ms(1000);
	//status |=LCD_clearScreen();
}
	return status;
}
*/
