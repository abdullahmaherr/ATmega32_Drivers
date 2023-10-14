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
void MCAL_TIMER0_PWMInit(void)
{
	/* Configure The OC0 Pin as Output */
	SET_BIT(DDRB,3);

	/* Set The Timer Initial Value to 0 */
	TCNT0 = 0;

	/* Configure the FAST PWM,Non inverting Mode, /8 Prescsaler */
	TCCR0 = (0x6A);
}


void MCAL_TIMER2_PWMInit(void)
{
	/* Configure The OC2 Pin as Output */
	SET_BIT(DDRD,7);

	/* Set The Timer Initial Value to 0 */
	TCNT2 = 0;

	/* Configure the FAST PWM,Non inverting Mode, /8 Prescsaler */
	TCCR2 = (0x6A);
}


void MCAL_TIMER0_PWMSetDuty(uint8_t a_duty)
{
	OCR0 = a_duty;
}


void MCAL_TIMER2_PWMSetDuty(uint8_t a_duty)
{
	OCR2 = a_duty;
}
