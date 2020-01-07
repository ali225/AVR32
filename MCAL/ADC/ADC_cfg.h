/*
 * ADC_cfg.h
 *
 *  Created on: Jan 6, 2020
 *      Author: Eng Ali Gamal
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_



/************* Macro Definitions **************/
/**********************************************/
/* ADC conversion mode */
#define ADC_SINGLE_CONVERSION    0
#define ADC_AUTO_TRIGGER         1

/* ADC resolution types*/
#define ADC_8_BIT_MODE     0
#define ADC_10_BIT_MODE    1

/* ADC prescaler values */
#define ADC_u8_PRESCALER_2    2
#define ADC_u8_PRESCALER_4    4
#define ADC_u8_PRESCALER_8    8
#define ADC_u8_PRESCALER_16   16
#define ADC_u8_PRESCALER_32   32
#define ADC_u8_PRESCALER_64   64
#define ADC_u8_PRESCALER_128  128

/* Auto-triggering modes */
#define ADC_FREE_RUNNING_MODE       0
#define ADC_ANALOG_COMPARATOR_MODE  1
#define ADC_EXTI0_MODE              2
#define ADC_TIM0_CM_MODE            3
#define ADC_TIM0_OV_MODE            4
#define ADC_NO_TRIGGER_MODE         5

/* Voltage reference selection */
#define ADC_AREF           0
#define ADC_AVCC           1
#define ADC_INTERNAL_VREF  2


/**************************************************************************/
/************************* Configuration Parameters ***********************/
/**************************************************************************/

/* Either ADC_8_BIT_MODE or ADC_10_BIT_MODE */
#define ADC_u8_RESOLUTION_MODE  ADC_10_BIT_MODE

/* Choose Prescaler value: */
/*  ADC_u8_PRESCALER_2     */
/*  ADC_u8_PRESCALER_4     */
/*  ADC_u8_PRESCALER_8     */
/*  ADC_u8_PRESCALER_16    */
/*  ADC_u8_PRESCALER_32    */
/*  ADC_u8_PRESCALER_64    */
/*  ADC_u8_PRESCALER_128   */
#define ADC_u8_PRESCALER_DIVISION   ADC_u8_PRESCALER_16

/* Choose auto-triggering mode :  */
/*    ADC_FREE_RUNNING_MODE       */
/*    ADC_ANALOG_COMPARATOR_MODE  */
/*    ADC_EXTI0_MODE              */
/*    ADC_TIM0_CM_MODE            */
/*    ADC_TIM0_OV_MODE            */
/*    ADC_NO_TRIGGER_MODE         */
#define ADC_TRIGERRING_MODE   ADC_FREE_RUNNING_MODE

/* Choose reference voltage type: */
/*      ADC_AREF                  */
/*      ADC_AVCC                  */
/*      ADC_INTERNAL_VREF         */
#define ADC_REFERENCE_VOLTAGE   ADC_AVCC

/* Choose conversion mode:        */
/*      ADC_SINGLE_CONVERSION     */
/*      ADC_AUTO_TRIGGER          */
#define ADC_OPERATION_MODE  ADC_AUTO_TRIGGER




#endif /* MCAL_ADC_ADC_CFG_H_ */
