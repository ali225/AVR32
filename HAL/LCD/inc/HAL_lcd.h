/*
 * HAL_lcd.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef HAL_LCD_INC_HAL_LCD_H_
#define HAL_LCD_INC_HAL_LCD_H_

extern stdReturnType_t LCD_init(void);
extern stdReturnType_t LCD_clearScreen(void);
extern stdReturnType_t LCD_turnOnCursor(void);
extern stdReturnType_t LCD_turnOffCursor(void);
extern stdReturnType_t LCD_displayCharacter(u8 data);
extern stdReturnType_t LCD_displayString(const char * data);
extern stdReturnType_t LCD_setCursorPos(u8 row, u8 col);
extern stdReturnType_t LCD_displayString_rowCol(const char * data, u8 row, u8 col);
extern stdReturnType_t LCD_displayInteger(u16 val);
extern stdReturnType_t LCD_writeCustomChar(u8 * pData, u8 index);
extern stdReturnType_t LCD_displayCustomChar(u8 index,u8 row,u8 col);

#endif /* HAL_LCD_INC_HAL_LCD_H_ */
