/*
 * ADC.h
 *
 *  Created on: Jan 6, 2020
 *      Author: Eng Ali Gamal
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_



#define ADC_OK      0
#define ADC_NOT_OK  1

/* ADC channels */
#define ADC_u8_CHANNEL_1  0
#define ADC_u8_CHANNEL_2  1
#define ADC_u8_CHANNEL_3  2
#define ADC_u8_CHANNEL_4  3
#define ADC_u8_CHANNEL_5  4
#define ADC_u8_CHANNEL_6  5
#define ADC_u8_CHANNEL_7  6
#define ADC_u8_CHANNEL_8  7


/************* Function prototypes **************/
/************************************************/


/*************************************/
/* Description : This function is    */
/* used to initialize timer          */
/*************************************/
extern void ADC_init();


/*************************************/
/* Description : This function is    */
/* used to start ADC conversion      */
/*************************************/
extern u8 ADC_u8StartConversion(u8 u8Channel,u16 *u16Val);


/*************************************/
/* Description : This function is    */
/* used to get last converted value  */
/*************************************/
extern u16 ADC_u16GetLastValue(void);


/*************************************/
/* Description : This function is    */
/* used to enable ADC                */
/*************************************/
extern void ADC_enable(void);


/*************************************/
/* Description : This function is    */
/* used to disable ADC               */
/*************************************/
extern void ADC_disable(void);


/*************************************/
/* Description : This function is    */
/* used to enable ADC interrupt      */
/*************************************/
extern void ADC_enableInterrupt(void);



/*************************************/
/* Description : This function is    */
/* used to disable ADC interrupt     */
/*************************************/
extern void ADC_disableInterrupt(void);


/*************************************/
/* Description : This function is    */
/* used to set ADC ISR callback      */
/*************************************/
extern void ADC_voidSetCallBack(void (*ptrCpy) (void));



#endif /* MCAL_ADC_ADC_H_ */
