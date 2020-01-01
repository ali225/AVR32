/*
 * HAL_KEYOAD.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef HAL_KEYPAD_INC_HAL_KEYPAD_H_
#define HAL_KEYPAD_INC_HAL_KEYPAD_H_


/************* Function declaration section ************/
extern stdReturnType_t initKeypad(void);
extern stdReturnType_t GetPressedKey(u8 *ppressed);


#endif /* HAL_KEYPAD_INC_HAL_KEYPAD_H_ */
