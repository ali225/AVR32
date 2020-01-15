/*
 * ICU.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Eng Ali Gamal
 */

#ifndef MCAL_ICU_ICU_H_
#define MCAL_ICU_ICU_H_


typedef enum
{
	ICU_FALLING_EDGE = 0,
	ICU_RISING_EDGE = 1

}EdgeTrigger_t;


extern void ICU_init(void);
extern stdReturnType_t ICU_getTimerCaptureVal(u16 * data);
extern stdReturnType_t ICU_isCaptureUpdated(u8 * status);
extern stdReturnType_t ICU_clearCaptureIntFlag(void);
extern stdReturnType_t ICU_captureIntStatus(u8 status);
extern stdReturnType_t ICU_setEdgeTrigger(EdgeTrigger_t edge);
extern void ICU_setCallBack(void (*ptrCpy) (void));


#endif /* MCAL_ICU_ICU_H_ */
