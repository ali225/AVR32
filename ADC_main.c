/*

 * ADC_main.c
 *
 *  Created on: Jan 18, 2020
 *      Author: Eng Ali Gamal

#include "LIB/std_types.h"
#include "LIB/registers.h"
#include "LIB/bit_math.h"
#include "util/delay.h"
#include "MCAL/DIO/inc/DIO.h"
#include "HAL/LCD/inc/HAL_lcd.h"
#include "MCAL/ADC/ADC.h"


int main()
{
	u16 pot;
	LCD_init();
	ADC_init();

	//char temperature[15] = "Temp=";
	LCD_displayString("temperature");

	while(1)
	{
		ADC_u8StartConversion(0,&pot);
		LCD_setCursorPos(1,1);
		LCD_displayInteger((int)(((u32)(pot*(u32)500))/(u32)1023));

	}

	return 0;
}
*/
