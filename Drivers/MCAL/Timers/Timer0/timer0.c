/*============================================================================================
 * Module : Timer0
 *
 * File Name : timer0.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 Timer0 Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "timer0.h"



/*===============================================================================
 *                              Global Variables                                 *
 ================================================================================*/

void (* gp_CallBack)(void);  /* Global Pointer To Assign ISRs */

TIMER0_Config_t g_TIMER0_Config;

/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void MCAL_TIMER0_Init(TIMER0_Config_t *p_TIMER0_Config)
{
	g_TIMER0_Config = *p_TIMER0_Config;

	/* Configure The Mode of Timer0, Frequency of Timer0 */
	TCCR0 |= (p_TIMER0_Config->Timer_Mode) | (p_TIMER0_Config->Timer_Clock);

	/*Configure The Interrupt Mask Enable/Disable*/
	TIMSK |= (p_TIMER0_Config->Timer_IntMask);
	if(p_TIMER0_Config->Timer_IntMask != TIMER0_MASK_DISABLE)
	{
		SEI();
	}

	/* Assign ISR with C function */
	gp_CallBack = p_TIMER0_Config->Timer_ISR;
}


void MCAL_TIMER0_Stop(void)
{
	/* Stop Tomer0 by Clearing Prescaler */
	TCCR0 &= (~(0x07));
}


void MCAL_TIMER0_Resume(void)
{
	/* Resume Tomer0 by Setting Prescaler */
	TCCR0 |= (g_TIMER0_Config.Timer_Clock);
}


void MCAL_TIMER0_SetCompareValue(uint8_t a_TicksNumber)
{
	/* Setting The Compare Value */
	OCR0 = a_TicksNumber;
}


void MCAL_TIMER0_SetCounter(uint8_t a_Counter)
{
	/* Setting The Initial Counter Value */
	TCNT0 = a_Counter;
}


/*===============================================================================
 *                       		 ISR Functions  		                         *
 ================================================================================*/
ISR(TIMER0_OVF_vect)
{
	(*gp_CallBack)();
}


ISR(TIMER0_COMP_vect)
{
	(*gp_CallBack)();
}


