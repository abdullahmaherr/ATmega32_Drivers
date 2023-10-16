/*============================================================================================
 * Module : Motors
 *
 * File Name : servo_motor.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 Motors Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include <dc_motor.h>
#include "gpio.h"
#include "pwm.h"

/*===============================================================================
 *                              Global Variables                                 *
 ================================================================================*/





/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void HAL_Servo_Init(uint8_t a_OC1x)
{
	/* Initialization Of PWM TIMER1 With Fpwm = 50HZ , Period = 20ms */
	MCAL_TIMER1_PWMInit(PWM_CLK_PRE_64, 2499, a_OC1x);
}


void HAL_Servo_ROT0(uint8_t a_OC1x)
{
	MCAL_TIMER1_PWMSetDuty(125, a_OC1x);
}


void HAL_Servo_ROT90(uint8_t a_OC1x)
{
	MCAL_TIMER1_PWMSetDuty(187, a_OC1x);
}


void HAL_Servo_ROT180(uint8_t a_OC1x)
{
	MCAL_TIMER1_PWMSetDuty(250, a_OC1x);
}
