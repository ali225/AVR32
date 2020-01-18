/*
 * TIM0_cfg.h
 *
 *  Created on: Jan 6, 2020
 *      Author: Eng Ali Gamal
 */

#ifndef MCAL_TIMER_TIM0_CFG_H_
#define MCAL_TIMER_TIM0_CFG_H_



//#ifndef TIM0_PRIV_H
#define TIM0_PRIV_H


#define TIM0_NORMAL_MODE  0
#define TIM0_CTC_MODE     1

/* Prescalers */
#define TIM0_NO_CLK_SELECT          0
#define TIM0_NO_PRESCALER_SELECT    1
#define TIM0_8_PRESCALER_SELECT     2
#define TIM0_64_PRESCALER_SELECT    3
#define TIM0_256_PRESCALER_SELECT   4
#define TIM0_1024_PRESCALER_SELECT  5

/* Compare match modes */
#define TIM0_COMPARE_MATCH_NORMAL_MODE   0
#define TIM0_COMPARE_MATCH_TOGGLE_MODE   1
#define TIM0_COMPARE_MATCH_CLEAR_MODE    2
#define TIM0_COMPARE_MATCH_SET_MODE      3






/* Normal or CTC mode select:

        1- TIM0_NORMAL_MODE
        2- TIM0_CTC_MODE
*/
#define TIM0_MODE_SELECT  TIM0_NORMAL_MODE


/* Prescaler select:

      1- TIM0_NO_CLK_SELECT
      2- TIM0_NO_PRESCALER_SELECT
      3- TIM0_8_PRESCALER_SELECT
      4- TIM0_64_PRESCALER_SELECT
      5- TIM0_256_PRESCALER_SELECT
      6- TIM0_1024_PRESCALER_SELECT

*/
#define TIM0_PRESCALER_SELECT  TIM0_1024_PRESCALER_SELECT

/* TCNTO init val (0 ----> 255) */
#define TIM0_TCNT0_INIT     0

/* OCR0 init val (0 ----> 255) */
#define TIM0_OCR0_INIT      250


/* Compare Match Mode Select

          1- TIM0_COMPARE_MATCH_NORMAL_MODE
          2- TIM0_COMPARE_MATCH_TOGGLE_MODE
          3- TIM0_COMPARE_MATCH_CLEAR_MODE
          4- TIM0_COMPARE_MATCH_SET_MODE
*/
#define TIM0_COMPARE_MATCH_MODE_SELECT    TIM0_COMPARE_MATCH_NORMAL_MODE


//#endif



#endif /* MCAL_TIMER_TIM0_CFG_H_ */
