/*============================================================================================
 * Module : PWM
 *
 * File Name : pwm.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 PWM Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_PWM_H_
#define INC_PWM_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"


/*===============================================================================
 *                            User Type Definitions                              *
 ================================================================================*/


/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/


/**===============================================================================
 * Function Name  : MCAL_TIMER0_PWMInit.
 * Brief          : Function To Initialize The Fast PWM Mode In Timer0.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : Timer0 will be used in FAST PWM with pre-scaler F_CPU/8, Non inverting, F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz. */
void MCAL_TIMER0_PWMInit(void);

/**===============================================================================
 * Function Name  : MCAL_TIMER1_PWMInit.
 * Brief          : Function To Initialize The Fast PWM Mode In Timer1.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : None.
void MCAL_TIMER1_PWMInit(void);*/

/**===============================================================================
 * Function Name  : MCAL_TIMER2_PWMInit.
 * Brief          : Function To Initialize The Fast PWM Mode In Timer2.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : Timer2 will be used in FAST PWM with pre-scaler F_CPU/8, Non inverting, F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz.*/
void MCAL_TIMER2_PWMInit(void);

/**===============================================================================
 * Function Name  : MCAL_TIMER0_PWMInit.
 * Brief          : Function To Initialize The Required Duty Cycle.
 * Parameter (in) : The Required Duty Cycle.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_TIMER0_PWMSetDuty(uint8_t a_duty);

/**===============================================================================
 * Function Name  : MCAL_TIMER1_PWMInit.
 * Brief          : Function To Initialize The Required Duty Cycle.
 * Parameter (in) : The Required Duty Cycle.
 * Return         : None.
 * Note           : None.
void MCAL_TIMER1_PWMSetDuty(uint8_t a_duty);*/

/**===============================================================================
 * Function Name  : MCAL_TIMER2_PWMInit.
 * Brief          : Function To Initialize The Required Duty Cycle.
 * Parameter (in) : The Required Duty Cycle.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_TIMER2_PWMSetDuty(uint8_t a_duty);



#endif /* INC_PWM_H_ */
