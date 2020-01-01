/*
 * HAL_KEYPAD.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Eng Ali Gamal
 */

#include "util/delay.h"
#include "../../../LIB/std_types.h"
#include "../../../MCAL/DIO/inc/DIO.h"
#include "../inc/HAL_KEYPAD_cfg.h"
#include "../inc/HAL_KEYPAD.h"

static stdReturnType_t colpins [NUM_OF_COL] = {
		KEYPAD_COL0_PIN,
		KEYPAD_COL1_PIN,
		KEYPAD_COL2_PIN,
		KEYPAD_COL3_PIN,
};

stdReturnType_t initKeypad(void) {

	stdReturnType_t status = ERROR;

	// init column  as input

	status = DIO_init(KEYPAD_PORT, KEYPAD_COL0_PIN, INPUT);

	status |= DIO_init(KEYPAD_PORT, KEYPAD_COL1_PIN, INPUT);
	status |= DIO_init(KEYPAD_PORT, KEYPAD_COL2_PIN, INPUT);
    #if (NUM_OF_COL == 4)
		status |= DIO_init(KEYPAD_PORT, KEYPAD_COL3_PIN, INPUT);
	#endif
	status = SUCCESS;

	//Enable initernal pull up
	DIO_write(KEYPAD_PORT, KEYPAD_COL0_PIN, PIN_IS_HIGH);
	DIO_write(KEYPAD_PORT, KEYPAD_COL1_PIN, PIN_IS_HIGH);
	DIO_write(KEYPAD_PORT, KEYPAD_COL2_PIN, PIN_IS_HIGH);
	#if (NUM_OF_COL == 4)
		DIO_write(KEYPAD_PORT, KEYPAD_COL3_PIN, PIN_IS_HIGH);
	#endif
	status = SUCCESS;
	//init row as INPUT
	status = DIO_init(KEYPAD_PORT,KEYPAD_ROW0_PIN,OUTPUT);

	status |= DIO_init(KEYPAD_PORT,KEYPAD_ROW1_PIN,OUTPUT);
	status |= DIO_init(KEYPAD_PORT,KEYPAD_ROW2_PIN,OUTPUT);
	#if(NUM_OF_ROW == 4)
	status |= DIO_init(KEYPAD_PORT,KEYPAD_ROW3_PIN,OUTPUT);
	#endif
	//Enable initernal pull up
	DIO_write(KEYPAD_PORT, KEYPAD_ROW0_PIN, PIN_IS_HIGH);
	DIO_write(KEYPAD_PORT, KEYPAD_ROW1_PIN, PIN_IS_HIGH);
	DIO_write(KEYPAD_PORT, KEYPAD_ROW2_PIN, PIN_IS_HIGH);
	#if (NUM_OF_ROW == 4)
		DIO_write(KEYPAD_PORT, KEYPAD_ROW3_PIN, PIN_IS_HIGH);
	#endif

	status = SUCCESS;

	return status;
}


stdReturnType_t GetPressedKey(u8 *ppressed)
{
	stdReturnType_t retstatus = ERROR;

	u8 col = 0;
	u8 row = 0;
	pinState_t pinsate;

	*ppressed = 'H';

	for(row = 0; row < NUM_OF_ROW; row++)
	{
		retstatus = DIO_write(KEYPAD_PORT,KEYPAD_ROW0_PIN,( (1<<row) &1)?0:1);

		retstatus |= DIO_write(KEYPAD_PORT,KEYPAD_ROW1_PIN,( (1<<row) &2)?0:1);
		retstatus |= DIO_write(KEYPAD_PORT,KEYPAD_ROW2_PIN,( (1<<row) &4)?0:1);
		retstatus |= DIO_write(KEYPAD_PORT,KEYPAD_ROW3_PIN,( (1<<row) &8)?0:1);

		for (col = 0; col < NUM_OF_COL; col ++)
		{

			retstatus |= DIO_read(KEYPAD_PORT,colpins[col],&pinsate);

			if(PIN_IS_LOW == pinsate)
			{
				#if(NUM_OF_COL == 4)
				//*ppressed = KEyPad_4X4[row][col];
				#elif(NUM_OF_COL == 3)
				//*ppressed = KEyPad_4X3[row][col];
				#endif

				row = NUM_OF_ROW;
				col = NUM_OF_COL;
			}
		}
	}

	return retstatus;

}
/*
stdReturnType_t GetPressedKey(u8 *ppressed){



}
*/

