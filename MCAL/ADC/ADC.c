/*
 * ADC.c
 *
 *  Created on: Jan 6, 2020
 *      Author: Eng Ali Gamal
 */

/************* Includes **************/
/*************************************/
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "../../LIB/registers.h"
#include "ADC_cfg.h"
#include "ADC.h"


static u16 u16Result;
void (*ADC_CALLBACK_FUNC) (void);



/*************************************/
/* Description : This function is    */
/* used to initialize ADC            */
/*************************************/
extern void ADC_init()
{

  /* Disable interrupt */
  CLR_BIT(ADCSRA,3);
  /* Clear interrupt flag */
  SET_BIT(ADCSRA,4);

  /* Enable ADC */
  ADC_enable();

  /* Configure resolution */
  #if ADC_u8_RESOLUTION_MODE == ADC_8_BIT_MODE
    SET_BIT(ADMUX,5);
  #elif ADC_u8_RESOLUTION_MODE == ADC_10_BIT_MODE
    CLR_BIT(ADMUX,5);
  #endif


  /* Configure prescaler */
  #if ADC_u8_PRESCALER_DIVISION == ADC_u8_PRESCALER_2
    SET_BIT(ADCSRA,0);
    CLR_BIT(ADCSRA,1);
    CLR_BIT(ADCSRA,2);
  #elif ADC_u8_PRESCALER_DIVISION == ADC_u8_PRESCALER_4
    CLR_BIT(ADCSRA,0);
    SET_BIT(ADCSRA,1);
    CLR_BIT(ADCSRA,2);
  #elif ADC_u8_PRESCALER_DIVISION == ADC_u8_PRESCALER_8
    SET_BIT(ADCSRA,0);
    SET_BIT(ADCSRA,1);
    CLR_BIT(ADCSRA,2);
  #elif ADC_u8_PRESCALER_DIVISION == ADC_u8_PRESCALER_16
    CLR_BIT(ADCSRA,0);
    CLR_BIT(ADCSRA,1);
    SET_BIT(ADCSRA,2);
  #elif ADC_u8_PRESCALER_DIVISION == ADC_u8_PRESCALER_32
    SET_BIT(ADCSRA,0);
    CLR_BIT(ADCSRA,1);
    SET_BIT(ADCSRA,2);
  #elif ADC_u8_PRESCALER_DIVISION == ADC_u8_PRESCALER_64
    CLR_BIT(ADCSRA,0);
    SET_BIT(ADCSRA,1);
    SET_BIT(ADCSRA,2);
  #elif ADC_u8_PRESCALER_DIVISION == ADC_u8_PRESCALER_64
    SET_BIT(ADCSRA,0);
    SET_BIT(ADCSRA,1);
    SET_BIT(ADCSRA,2);
  #endif

  /* Configure voltage reference */
  #if ADC_REFERENCE_VOLTAGE == ADC_AREF
    CLR_BIT(ADMUX,7);
    CLR_BIT(ADMUX,6);
  #elif ADC_REFERENCE_VOLTAGE == ADC_AVCC
    CLR_BIT(ADMUX,7);
    SET_BIT(ADMUX,6);
  #elif ADC_REFERENCE_VOLTAGE == ADC_INTERNAL_VREF
    SET_BIT(ADMUX,7);
    SET_BIT(ADMUX,6);
  #endif

  /* Configure operation mode */
  #if ADC_OPERATION_MODE == ADC_SINGLE_CONVERSION
    CLR_BIT(ADCSRA,5);
  #elif ADC_OPERATION_MODE == ADC_AUTO_TRIGGER
    SET_BIT(ADCSRA,5);
  #endif

  /* Configure triggering mode */
  #if ADC_TRIGERRING_MODE == ADC_FREE_RUNNING_MODE
    CLR_BIT(SFIOR,5);
    CLR_BIT(SFIOR,6);
    CLR_BIT(SFIOR,7);
  #elif ADC_TRIGERRING_MODE == ADC_ANALOG_COMPARATOR_MODE
    SET_BIT(SFIOR,5);
    CLR_BIT(SFIOR,6);
    CLR_BIT(SFIOR,7);
  #elif ADC_TRIGERRING_MODE == ADC_EXTI0_MODE
    CLR_BIT(SFIOR,5);
    SET_BIT(SFIOR,6);
    CLR_BIT(SFIOR,7);
  #elif ADC_TRIGERRING_MODE == ADC_TIM0_CM_MODE
    SET_BIT(SFIOR,5);
    SET_BIT(SFIOR,6);
    CLR_BIT(SFIOR,7);
  #elif ADC_TRIGERRING_MODE == ADC_TIM0_OV_MODE
    CLR_BIT(SFIOR,5);
    SET_BIT(SFIOR,6);
    SET_BIT(SFIOR,7);
  #endif

}


/*************************************/
/* Description : This function is    */
/* used to start ADC conversion      */
/*************************************/
extern u8 ADC_u8StartConversion(u8 u8Channel,u16 *u16Val)
{

  /* Select channel */
  ADMUX = (ADMUX & 0b11100000) | u8Channel;

  /* Start conversion */
  SET_BIT(ADCSRA,6);

  /* Check that interrupt is not enabled */
  if(GET_BIT(ADCSRA,3))
  {
    return ADC_NOT_OK;
  }
  else
  {
    /* Wait until conversion completes */
    while(!GET_BIT(ADCSRA,4)){}

    /* Clear interrupt flag */
    SET_BIT(ADCSRA,4);

    /* Read ADC value */
    *u16Val = ADC_u16GetLastValue();
    return ADC_OK;
  }
}


/*************************************/
/* Description : This function is    */
/* used to get last converted value  */
/*************************************/
extern u16 ADC_u16GetLastValue(void)
{
  u16Result = 0;
  u8 left,right;

  #if ADC_u8_RESOLUTION_MODE == ADC_8_BIT_MODE
  u16Result = (u16) ADCH;
  return u16Result;
  #elif ADC_u8_RESOLUTION_MODE == ADC_10_BIT_MODE
  right = ADCL;
  left = ADCH;
  u16Result = (((u16)left)<<8) | ((u16)right);
  return u16Result;
  #endif
}


/*************************************/
/* Description : This function is    */
/* used to enable ADC                */
/*************************************/
extern void ADC_enable(void)
{
  SET_BIT(ADCSRA,7);
}


/*************************************/
/* Description : This function is    */
/* used to disable ADC               */
/*************************************/
extern void ADC_disable(void)
{
  CLR_BIT(ADCSRA,7);
}


/*************************************/
/* Description : This function is    */
/* used to enable ADC interrupt      */
/*************************************/
extern void ADC_enableInterrupt(void)
{
  SET_BIT(ADCSRA,3);
}



/*************************************/
/* Description : This function is    */
/* used to disable ADC interrupt     */
/*************************************/
extern void ADC_disableInterrupt(void)
{
  CLR_BIT(ADCSRA,3);
}


/*************************************/
/* Description : This function is    */
/* used to set ADC ISR callback      */
/*************************************/
extern void ADC_voidSetCallBack(void (*ptrCpy) (void))
{
  ADC_CALLBACK_FUNC = ptrCpy;
}



/*************************************/
/* Description : This function is    */
/* the ISR ADC conversion            */
/*************************************/
void __vector_16 (void) __attribute__((signal,used));
void __vector_16 (void)
{
  ADC_CALLBACK_FUNC();
}

