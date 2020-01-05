/*
 * MCAL_interrupts.c
 *
 *  Created on: Jan 5, 2020
 *      Author: Eng Ali Gamal
 */
#include "stdlib.h"
#include "util/delay.h"
#include "../../../LIB/std_types.h"
#include "../../../LIB/bit_math.h"
#include "../../../LIB/registers.h"
#include "../ins/MCAL_interrupts.h"
#include "avr/interrupt.h"

/* Definition of call back functions */
static void(* INT0_callBackPtr)(void) = NULL;
static void(* INT1_callBackPtr)(void) = NULL;
static void(* INT2_callBackPtr)(void) = NULL;

/* External interrupts service routines */
/* INT0 ISR */
ISR(INT0_vect)
{
	if(NULL != INT0_callBackPtr)
	{
		INT0_callBackPtr();
	}

}

/* INT1 ISR */
ISR(INT1_vect)
{
	if(NULL != INT1_callBackPtr)
		{
			INT1_callBackPtr();
		}
}

/* INT2 ISR */
ISR(INT2_vect)
{
	if(NULL != INT2_callBackPtr)
		{
			INT2_callBackPtr();
		}

}

/*
 * Name:  initExternalInterrupt
 * brief: used to enable and config. given external interrupt.
 * params:
 * 			IN: exIntID : the ID of the external interrupt INT_0,INT_1, etc..
 * 			IN: intSensitivity : the type of sensitivity that trigger the interrupt: FALLING_EDGE, RISING_EDGE, etc...
 * 			IN: callBackPtr : pointer to the upper layer call back function.
 */
stdReturnType_t initExternalInterrupt(extIntX_t exIntID, extIntSensitivity_t intSensitivity, void(* callBackPtr)(void))
{
	stdReturnType_t retStatus = ERROR;

	/* Disable interrupts */
	disableGlobalInterrupts();

	/* Start of initialization */
	switch(exIntID)
	{
	case INT_0:
	{
		/* Enable interrupt 0 in General Interrupt Control Register -GICR- */
		SET_BIT(GICR, INT0);

		/* init call back function pointer */
		INT0_callBackPtr = callBackPtr;
		break;
	}
	case INT_1:
	{
		/* Enable interrupt 1 in General Interrupt Control Register -GICR- */
		SET_BIT(GICR, INT1);

		/* init call back function pointer */
		INT1_callBackPtr = callBackPtr;
		break;
	}
	case INT_2:
	{
		/* Enable interrupt 2 in General Interrupt Control Register -GICR- */
		SET_BIT(GICR, INT2);

		/* init call back function pointer */
		INT2_callBackPtr = callBackPtr;
		break;
	}
	default:
		retStatus = ERROR;
		break;
	}

	/* configure interrupt sensitivity */
	retStatus |= configExternalInterruptSensitivity(exIntID, intSensitivity);

	/* End of initialization */

	/* Enable interrupts */
	enableGlobalInterrupts();

	return retStatus;
}

/*
 * Name:  configExternalInterruptSensitivity
 * brief: used to change/config. sensitivity of external interrupt.
 * params:
 * 			IN: exIntID : the ID of the external interrupt INT_0,INT_1, etc..
 * 			IN: intSensitivity : the type of sensitivity that trigger the interrupt: FALLING_EDGE, RISING_EDGE, etc...
 *
 */
stdReturnType_t configExternalInterruptSensitivity(extIntX_t exIntID, extIntSensitivity_t intSensitivity)
{
	stdReturnType_t retStatus = ERROR;

	/* Start of initialization */
		switch(exIntID)
		{
		case INT_0:
		{
			/* configure interrupt sensitivity */

			if(LOW_LEVEL == intSensitivity)
			{
				CLR_BIT(MCUCR, ISC01);
				CLR_BIT(MCUCR, ISC00);
				retStatus = SUCCESS;
			}
			else if(ANY_LOGICAL_CHANGE == intSensitivity)
			{
				CLR_BIT(MCUCR, ISC01);
				SET_BIT(MCUCR, ISC00);
				retStatus = SUCCESS;
			}
			else if(FALLING_EDGE == intSensitivity)
			{
				SET_BIT(MCUCR, ISC01);
				CLR_BIT(MCUCR, ISC00);
				retStatus = SUCCESS;
			}
			else if(RISING_EDGE == intSensitivity)
			{
				SET_BIT(MCUCR, ISC01);
				SET_BIT(MCUCR, ISC00);
				retStatus = SUCCESS;
			}
			else
			{
				retStatus = ERROR;
			}

			break;
		}
		case INT_1:
		{
			/* configure interrupt sensitivity */

			if(LOW_LEVEL == intSensitivity)
			{
				CLR_BIT(MCUCR, ISC11);
				CLR_BIT(MCUCR, ISC10);
				retStatus = SUCCESS;
			}
			else if(ANY_LOGICAL_CHANGE == intSensitivity)
			{
				CLR_BIT(MCUCR, ISC11);
				SET_BIT(MCUCR, ISC10);
				retStatus = SUCCESS;
			}
			else if(FALLING_EDGE == intSensitivity)
			{
				SET_BIT(MCUCR, ISC11);
				CLR_BIT(MCUCR, ISC10);
				retStatus = SUCCESS;
			}
			else if(RISING_EDGE == intSensitivity)
			{
				SET_BIT(MCUCR, ISC11);
				SET_BIT(MCUCR, ISC10);
				retStatus = SUCCESS;
			}
			else
			{
				retStatus = ERROR;
			}

			break;
		}
		case INT_2:
		{
			/* configure interrupt sensitivity */

			if(FALLING_EDGE == intSensitivity)
			{
				CLR_BIT(MCUCSR, ISC2);
				retStatus = SUCCESS;
			}
			else if(RISING_EDGE == intSensitivity)
			{
				SET_BIT(MCUCSR, ISC2);
				retStatus = SUCCESS;
			}
			else
			{
				retStatus = ERROR;
			}
			break;
		}
		default:
			retStatus = ERROR;
			break;
		}

	return retStatus;
}

/*
 * Name:  disableExternalInterrupt
 * brief: used to disable given external interrupt.
 * params:
 * 			IN: exIntID : the ID of the external interrupt INT_0,INT_1, etc..
 *
 */
stdReturnType_t disableExternalInterrupt(extIntX_t exIntID)
{
	stdReturnType_t retStatus = ERROR;

	switch(exIntID)
	{
	case INT_0:
	{
		/* Enable interrupt 0 in General Interrupt Control Register -GICR- */
		CLR_BIT(GICR, INT0);
		break;
	}
	case INT_1:
	{
		/* Enable interrupt 1 in General Interrupt Control Register -GICR- */
		CLR_BIT(GICR, INT1);
		break;
	}
	case INT_2:
	{
		/* Enable interrupt 2 in General Interrupt Control Register -GICR- */
		CLR_BIT(GICR, INT2);
		break;
	}
	default:
		retStatus = ERROR;
		break;
	}

	return retStatus;
}

/*
 * Name:  disableGlobalInterrupts
 * brief: used to disable all interrupts.
 * params:
 * 			None.
 *
 */
stdReturnType_t disableGlobalInterrupts(void)
{
	stdReturnType_t retStatus = ERROR;

	/* Disable interrupts by clearing global interrupt bit in status register SREG */
	CLR_BIT(SREG, PIN7);

	return retStatus;
}

/*
 * Name:  enableGlobalInterrupts
 * brief: used to enable all interrupts.
 * params:
 * 			None.
 *
 */
stdReturnType_t enableGlobalInterrupts(void)
{
	stdReturnType_t retStatus = ERROR;

	/* Enable interrupts by enabling global interrupt bit in status register SREG */
	SET_BIT(SREG, PIN7);

	return retStatus;
}

