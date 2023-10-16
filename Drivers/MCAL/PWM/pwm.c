/*============================================================================================
 * Module : PWM
 *
 * File Name : pwm.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 PWM Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "pwm.h"

/*===============================================================================
 *                              Global Variables                                 *
 ================================================================================*/



/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/
void MCAL_TIMER0_PWMInit(uint8_t a_prescaler)
{
	/* Configure The OC0 Pin as Output */
	SET_BIT(DDRB,3);

	/* Set The Timer Initial Value to 0 */
	TCNT0 = 0;

	/* Configure the FAST PWM,Non inverting Mode, Prescsaler */
	TCCR0 = (0x68) | (a_prescaler);
}


void MCAL_TIMER1_PWMInit(uint8_t a_prescaler,uint8_t a_top, uint8_t a_pin)
{
	/* Set The Timer Initial Value to 0 */
	TCNT1 = 0;

	/*Set TOP Count For Timer1 in ICR1 Register*/
	ICR1 = a_top;

	/* Configure The OC1A/OC1B Pins as Output */
	switch(a_pin)
	{
	case PWM_OC1A:
		SET_BIT(DDRD,5);
		break;

	case PWM_OC1B:
		SET_BIT(DDRD,4);
		break;

	case PWM_OC1AB:
		SET_BIT(DDRD,4);
		SET_BIT(DDRD,5);
		break;
	}

	/* Configure the FAST PWM,Non inverting Mode, Prescsaler */
	TCCR1A = (0x02) | (a_pin);
	TCCR1B = (0x18) | (a_prescaler);
}


void MCAL_TIMER2_PWMInit(uint8_t a_prescaler)
{
	/* Configure The OC2 Pin as Output */
	SET_BIT(DDRD,7);

	/* Set The Timer Initial Value to 0 */
	TCNT2 = 0;

	/* Configure the FAST PWM,Non inverting Mode, /8 Prescsaler */
	TCCR2 = (0x68) | (a_prescaler);
}


void MCAL_TIMER0_PWMSetDuty(uint8_t a_duty)
{
	OCR0 = a_duty;
}


void MCAL_TIMER1_PWMSetDuty(uint8_t a_duty, uint8_t a_pin)
{
	switch(a_pin)
	{
	case PWM_OC1A:
		OCR1A = a_duty; break;
	case PWM_OC1B:
		OCR1B = a_duty; break;
	case PWM_OC1AB:
		OCR1B = a_duty;
		OCR1A = a_duty;
		break;
	}
}


void MCAL_TIMER2_PWMSetDuty(uint8_t a_duty)
{
	OCR2 = a_duty;
}
