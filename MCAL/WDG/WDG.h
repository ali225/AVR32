/*
 * WDG.h
 *
 *  Created on: Jan 6, 2020
 *      Author: Eng Ali Gamal
 */


#ifndef MCAL_WDG_WDG_H_
#define MCAL_WDG_WDG_H_

typedef enum
{
	TIME_16_3_MS,
	TIME_32_5_MS,
	TIME_65_MS,
	TIME_130_MS,
	TIME_260_MS,
	TIME_620_MS,
	TIME_1000_MS,
	TIME_2100_MS
}TimeConfig_t;


extern stdReturnType_t WDG_Enable(TimeConfig_t timeConfiguration);
extern stdReturnType_t WDG_Disable(void);
extern stdReturnType_t WDG_Refresh(TimeConfig_t );

#endif /* MCAL_WDG_WDG_H_ */

