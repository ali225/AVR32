/*
 * WDG.c
 *
 *  Created on: Jan 6, 2020
 *      Author: Eng Ali Gamal
 */


#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "../../LIB/registers.h"
#include "WDG.h"

stdReturnType_t WDG_Enable(TimeConfig_t timeConfiguration) {

	stdReturnType_t stats = SUCCESS;

	WDTCR &= ~0x07;
	switch (timeConfiguration) {
	case TIME_16_3_MS:
		WDTCR |= (1 << 3) | TIME_16_3_MS;
		break;

	case TIME_32_5_MS:
		WDTCR |= (1 << 3) | TIME_32_5_MS;
		break;

	case TIME_65_MS:
		WDTCR |= (1 << 3) | TIME_65_MS;
		break;

	case TIME_130_MS:
		WDTCR |= (1 << 3) | TIME_130_MS;
		break;

	case TIME_260_MS:
		WDTCR |= (1 << 3) | TIME_260_MS;
		break;

	case TIME_620_MS:
		WDTCR |= (1 << 3) | TIME_620_MS;
		break;

	case TIME_1000_MS:
		WDTCR |= (1 << 3) | TIME_1000_MS;
		break;
	case TIME_2100_MS:
		WDTCR |= (1 << 3) | TIME_2100_MS;
		break;
	default:
		stats = ERROR;
	}
	return stats;
}
stdReturnType_t WDG_Disable(void){

	WDTCR |=(1<<3) | (1<<4);
	WDTCR =0;

	return SUCCESS;
}
stdReturnType_t WDG_Refresh(TimeConfig_t timeConfiguration){

	stdReturnType_t stats = SUCCESS;
	WDG_Disable();
	 if (SUCCESS != WDG_Enable(timeConfiguration)){
		 return ERROR;
	 }
	 return stats;
}
