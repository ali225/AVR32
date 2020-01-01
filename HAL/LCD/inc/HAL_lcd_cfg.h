/*
 * HAL_lcd_cfg.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Eng Ali Gamal
 */

#ifndef HAL_LCD_INC_HAL_LCD_CFG_H_
#define HAL_LCD_INC_HAL_LCD_CFG_H_


/* General  configs */
#define LCD_DATA_BITS_MODE	4U

#define SELECT_DATA_REGISTER	PIN_IS_HIGH
#define SELECT_INSTRUCTION_REGISTER	PIN_IS_LOW

#define READ_DATA	PIN_IS_HIGH
#define WRITE_DATA	PIN_IS_LOW

#define ENABLE_LCD	PIN_IS_HIGH
#define DISABLE_LCD	PIN_IS_LOW

/* LCD control lines */
#define	LCD_CTRL_LINES_PORT	PORT_B

#define	LCD_RS_PIN	PIN1
#define	LCD_RW_PIN	PIN2
#define	LCD_E_PIN	PIN3

/* LCD Data lines */
#define	LCD_DATA_LINES_PORT	PORT_A


#define	LCD_DB0_PIN	PIN0	/* Not used in 4-bit mode */
#define	LCD_DB1_PIN	PIN1	/* Not used in 4-bit mode */
#define	LCD_DB2_PIN	PIN2	/* Not used in 4-bit mode */
#define	LCD_DB3_PIN	PIN3 	/* Not used in 4-bit mode */

#define	LCD_DB4_PIN	PIN4	/* LCD DATA PIN 0 */
#define	LCD_DB5_PIN	PIN5	/* LCD DATA PIN 1 */
#define	LCD_DB6_PIN	PIN6	/* LCD DATA PIN 2 */
#define	LCD_DB7_PIN	PIN7	/* LCD DATA PIN 3 */

/*	LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION_L1_START 0x80
#define SET_CURSOR_LOCATION_L2_START 0xC0
#define CUSTOM_CHAR_RANGE_START	0X40




#endif /* HAL_LCD_INC_HAL_LCD_CFG_H_ */
