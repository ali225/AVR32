/*
 * ICU.c
 *
 *  Created on: Jan 15, 2020
 *      Author: Eng Ali Gamal
 */
#include "../../LIB/registers.h"
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "ICU.h"
#include "ICU_cfg.h"


void (*ICU_CALLBACK_FUNC) (void);



extern void ICU_init(void)
{
	/* All configurations are done in TIMER 1 */
	/* TIMER 1 should be configured to start the timer */
	/* When the capture event happens the ICU return captured timer value */
}

extern stdReturnType_t ICU_getTimerCaptureVal(u16 * data)
{
	*data = ((u16)ICR1H<<8)| ((u16)ICR1L);
	return SUCCESS;
}

extern stdReturnType_t ICU_isCaptureUpdated(u8 * status)
{
	*status = GET_BIT(TIFR,5);

	return SUCCESS;
}
extern stdReturnType_t ICU_clearCaptureIntFlag(void)
{
	/* clear interrupt flag */
	SET_BIT(TIFR,5);

	return SUCCESS;
}

extern stdReturnType_t ICU_captureIntStatus(u8 status)
{
	/* Clear interrupt enable */
	CLR_BIT(TIMSK,5);
	/* update interrupt status */
	TIMSK |= (status<<5);

	return SUCCESS;
}

extern stdReturnType_t ICU_setEdgeTrigger(EdgeTrigger_t edge)
{
	/* Clear edge trigger */
	CLR_BIT(TCCR1B,6);
	/* update edge trigger status */
	TCCR1B |= (edge<<6);
	/* clear interrupt flag */
	SET_BIT(TIFR,5);

	return SUCCESS;
}

extern void ICU_setCallBack(void (*ptrCpy) (void))
{
  ICU_CALLBACK_FUNC = ptrCpy;
}



void __vector_6 (void) __attribute__ ((signal,used));
void __vector_6 (void)
{
	ICU_CALLBACK_FUNC();
}



