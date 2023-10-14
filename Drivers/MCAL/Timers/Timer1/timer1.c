/*============================================================================================
 * Module : Timer1
 *
 * File Name : timer1.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 Timer1 Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "timer1.h"



/*===============================================================================
 *                              Global Variables                                 *
 ================================================================================*/

void (* gp_CallBack)(void);  /* Global Pointer To Assign ISRs */


TIMER1_Config_t g_TIMER1_Config;


/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void MCAL_TIMER1_Init(TIMER1_Config_t *p_TIMER1_Config)
{
	g_TIMER1_Config = *p_TIMER1_Config;

	/*  Configure The Mode of Timer1, Frequency of Timer1 */
	TCCR1A |= ((uint8_t)p_TIMER1_Config->Timer_Mode);
	TCCR1B |= ((uint8_t)(p_TIMER1_Config->Timer_Mode) >> 8) | ((p_TIMER1_Config->Timer_Clock) & 0x07);

	/*Configure The Interrupt Mask Enable/Disable*/
	TIMSK |= (p_TIMER1_Config->Timer_IntMask);
	if(p_TIMER1_Config->Timer_IntMask != TIMER1_MASK_DISABLE)
	{
		SEI();
	}

	/* Assign ISR with C function */
	gp_CallBack = (p_TIMER1_Config->p_Timer_ISR);
}


void MCAL_TIMER1_Stop(void)
{
	/* Stop Timer1 by Clearing Prescaler */
	TCCR1B &= (~(0x07));
}


void MCAL_TIMER1_Resume(void)
{
	/* Resume Timer1 by Setting Prescaler */
	TCCR1B |= (g_TIMER1_Config.Timer_Clock);
}


void MCAL_TIMER1_SetCompareValue(uint16_t a_TicksNumber)
{
	/* Setting The Compare Value */
	OCR1A = a_TicksNumber;
}


void MCAL_TIMER1_SetCounter(uint16_t a_Counter)
{
	/* Setting The Initial Counter Value */
	TCNT1  = a_Counter;
}


/*===============================================================================
 *                       		 ISR Functions  		                         *
 ================================================================================*/
ISR(TIMER1_OVF_vect)
{
	(*gp_CallBack)();
}


ISR(TIMER1_COMPA_vect)
{
	(*gp_CallBack)();
}

