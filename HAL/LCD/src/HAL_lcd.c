/*
 * HAL_lcd.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Eng Ali Gamal
 */

#include <stdlib.h>
#include "util/delay.h"
#include "../../../LIB/std_types.h"
#include "../../../LIB/bit_math.h"
#include "../../../MCAL/DIO/inc/DIO.h"
#include "../../LCD/inc/HAL_lcd.h"
#include "../../LCD/inc/HAL_lcd_cfg.h"

static stdReturnType_t LCD_sendCommand(u8 command);
static stdReturnType_t LCD_outToDataLines(u8 val);

static stdReturnType_t LCD_outToDataLines(u8 val)
{
	stdReturnType_t retStatus = ERROR;

	/* write data to LCD so RW=0 */
	retStatus = DIO_write(LCD_CTRL_LINES_PORT, LCD_RW_PIN, WRITE_DATA);
	_delay_ms(1); /* delay for processing Tas = 50ns */
	/* Enable LCD E=1 */
	retStatus |= DIO_write(LCD_CTRL_LINES_PORT, LCD_E_PIN, ENABLE_LCD);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	 #if (LCD_DATA_BITS_MODE == 4)
		/* First output the highest 4 bits of the required command to the data bus D4:D7 */
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB4_PIN, (pinState_t)GET_BIT(val,4));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB5_PIN, (pinState_t)GET_BIT(val,5));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB6_PIN, (pinState_t)GET_BIT(val,6));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB7_PIN, (pinState_t)GET_BIT(val,7));

		_delay_ms(1); /* delay for processing Tdsw = 100ns */

		/* disable LCD E=0 */
		retStatus |= DIO_write(LCD_CTRL_LINES_PORT, LCD_E_PIN, DISABLE_LCD);
		_delay_ms(10); /* delay for processing Th = 13ns */

		retStatus |= DIO_write(LCD_CTRL_LINES_PORT, LCD_E_PIN, ENABLE_LCD); /* Enable LCD E=1 */
		_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

		/* Secondly output the lowest 4 bits of the required command to the data bus D4:D7 */
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB4_PIN, (pinState_t)GET_BIT(val,0));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB5_PIN, (pinState_t)GET_BIT(val,1));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB6_PIN, (pinState_t)GET_BIT(val,2));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB7_PIN, (pinState_t)GET_BIT(val,3));

		_delay_ms(1); /* delay for processing Tdsw = 100ns */

		retStatus |= DIO_write(LCD_CTRL_LINES_PORT, LCD_E_PIN, DISABLE_LCD); /* disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */

	#elif (LCD_DATA_BITS_MODE == 8)
		/* out the required command to the data bus D0 --> D7 */
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB0_PIN, (pinState_t)GET_BIT(val,0));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB1_PIN, (pinState_t)GET_BIT(val,1));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB2_PIN, (pinState_t)GET_BIT(val,2));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB3_PIN, (pinState_t)GET_BIT(val,3));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB4_PIN, (pinState_t)GET_BIT(val,4));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB5_PIN, (pinState_t)GET_BIT(val,5));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB6_PIN, (pinState_t)GET_BIT(val,6));
		retStatus |= DIO_write(LCD_DATA_LINES_PORT, LCD_DB7_PIN, (pinState_t)GET_BIT(val,7));

		_delay_ms(1); /* delay for processing Tdsw = 100ns */

		retStatus |= DIO_write(LCD_CTRL_LINES_PORT, LCD_E_PIN, DISABLE_LCD); /* disable LCD E=0 *//* disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */
	#endif

	return retStatus;
}

static stdReturnType_t LCD_sendCommand(u8 command)
{
	stdReturnType_t retStatus = ERROR;

	/* Sending instruction mode, RS=0 */
	retStatus = DIO_write(LCD_CTRL_LINES_PORT, LCD_RS_PIN, SELECT_INSTRUCTION_REGISTER);

	retStatus |= LCD_outToDataLines(command);

	return retStatus;
}

stdReturnType_t LCD_init(void)
{
	stdReturnType_t retStatus = ERROR;

	/* Configure the control pins(E,RS,RW) as output pins */
	retStatus =  DIO_init(LCD_CTRL_LINES_PORT, LCD_E_PIN, OUTPUT);
	retStatus |= DIO_init(LCD_CTRL_LINES_PORT, LCD_RS_PIN, OUTPUT);
	retStatus |= DIO_init(LCD_CTRL_LINES_PORT, LCD_RW_PIN, OUTPUT);

	/* Configure the highest 4 data lines as output */
	retStatus |= DIO_init(LCD_DATA_LINES_PORT, LCD_DB4_PIN, OUTPUT);
	retStatus |= DIO_init(LCD_DATA_LINES_PORT, LCD_DB5_PIN, OUTPUT);
	retStatus |= DIO_init(LCD_DATA_LINES_PORT, LCD_DB6_PIN, OUTPUT);
	retStatus |= DIO_init(LCD_DATA_LINES_PORT, LCD_DB7_PIN, OUTPUT);

	#if (LCD_DATA_BITS_MODE == 4)
	retStatus |= LCD_sendCommand(FOUR_BITS_DATA_MODE); /* initialize LCD in 4-bit mode */
	retStatus |= LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE); /* use 2-line LCD + 4-bit Data Mode + 5*7 dot display Mode */

	#elif (LCD_DATA_BITS_MODE == 8)
	 /* Configure the lowest 4 data lines as output */
	retStatus |= DIO_init(LCD_DATA_LINES_PORT, LCD_DB0_PIN, OUTPUT);
	retStatus |= DIO_init(LCD_DATA_LINES_PORT, LCD_DB1_PIN, OUTPUT);
	retStatus |= DIO_init(LCD_DATA_LINES_PORT, LCD_DB2_PIN, OUTPUT);
	retStatus |= DIO_init(LCD_DATA_LINES_PORT, LCD_DB3_PIN, OUTPUT);

	/* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	retStatus |= LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
	#endif

	retStatus |= LCD_sendCommand(CURSOR_OFF); /* cursor off */
	retStatus |= LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
	return retStatus;

}

stdReturnType_t LCD_clearScreen(void)
{
	return LCD_sendCommand(CLEAR_COMMAND);
}

stdReturnType_t LCD_turnOnCursor(void)
{
	return LCD_sendCommand(CURSOR_ON);
}

stdReturnType_t LCD_turnOffCursor(void)
{
	return LCD_sendCommand(CURSOR_OFF);
}

stdReturnType_t LCD_displayCharacter(u8 data)
{
	stdReturnType_t retStatus = ERROR;

	/* Sending data mode, RS=1 */
	retStatus  = DIO_write(LCD_CTRL_LINES_PORT, LCD_RS_PIN, SELECT_DATA_REGISTER);

	retStatus |= LCD_outToDataLines(data);

	return retStatus;
}

stdReturnType_t LCD_displayString(const char * data)
{
	stdReturnType_t retStatus = SUCCESS;
//	u8 index = 0;
//
//	while(data[index] != '\0')
//	{
//		retStatus |=  LCD_displayCharacter(data[index]);
//		index++;
//	}

	while( '\0' != (*data) )
		{
			retStatus |= LCD_displayCharacter(*data);
			data++;
		}


	return retStatus;

}

stdReturnType_t  LCD_setCursorPos(u8 row, u8 col)
{
	stdReturnType_t retStatus = ERROR;

	switch (row)
	{
		case 0:
			retStatus = LCD_sendCommand(SET_CURSOR_LOCATION_L1_START + col);
			break;
		case 1:
			retStatus = LCD_sendCommand(SET_CURSOR_LOCATION_L2_START + col);
			break;
		default:
			retStatus = ERROR;
			break;
	}

	return retStatus;
}

stdReturnType_t LCD_displayString_rowCol(const char * data, u8 row, u8 col)
{
	stdReturnType_t retStatus = ERROR;

	retStatus = LCD_setCursorPos(row, col);

	retStatus |= LCD_displayString(data);

	return retStatus;
}

stdReturnType_t LCD_displayInteger(u16 val)
{
	stdReturnType_t retStatus = ERROR;

    char AsciiBuff[16]; /* The ASCII result */
    itoa(val, AsciiBuff,10); /* 10 means base 10 i.e. decimal */
    retStatus = LCD_displayString(AsciiBuff);

/* another method */
//   u32 tempVal;
//   u8 arr[10];
//    u8 i,j;
//    tempVal = val;
//
// while(tempVal != 0)
// {
// 	arr[i]=tempVal%10;
// 	tempVal=tempVal/10;
// 	i++;
// }
//
// for(j = 0;j<i;j++)
// {
// 	LCD_displayCharacter(arr[i-1-j]+'0');
// }

    return retStatus;
}

stdReturnType_t LCD_writeCustomChar(u8 * pData, u8 index)
{
	stdReturnType_t retStatus = ERROR;
	u8 i = 0;

	/* Set address in CGRAM */
	retStatus = LCD_sendCommand(CUSTOM_CHAR_RANGE_START | (index * 8));
	/* Write received bytes in CGRAM */
	for(i = 0;i<8;i++)
	{
		retStatus |= LCD_displayCharacter(*pData);
		pData++;
	}

	return retStatus;
}

stdReturnType_t LCD_displayCustomChar(u8 index,u8 row,u8 col)
{
	stdReturnType_t retStatus = ERROR;

	/* Set address in DDRAM */
	retStatus = LCD_setCursorPos(row, col);
	/* Write custom character on screen */
	retStatus |= LCD_displayCharacter(index);

	return retStatus;
}
