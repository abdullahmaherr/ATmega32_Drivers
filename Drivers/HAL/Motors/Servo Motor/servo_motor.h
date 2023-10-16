/*============================================================================================
 * Module : Motors
 *
 * File Name : servo_motor.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 Motors Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_SERVO_MOTOR_H_
#define INC_SERVO_MOTOR_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"


/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/

/* @ref SERVO pin */
#define SERVO_OC1A					PWM_OC1A
#define SERVO_OC1B					PWM_OC1B
#define SERVO_OC1AB					PWM_OC1AB

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : HAL_Servo_Init.
 * Brief          : Function To Initialize The PWM To Work.
 * Parameter (in) : Pin Output @ref SERVO pin.
 * Return         : None.
 * Note           : Fcpu must to equal to 8Mhz.																	*/
void HAL_Servo_Init(uint8_t a_OC1x);

/**===============================================================================
 * Function Name  : HAL_Servo_Init.
 * Brief          : Function To Rotate the Servo To 0 Degree.
 * Parameter (in) : Pin Output @ref SERVO pin.
 * Return         : None.
 * Note           : None.																	*/
void HAL_Servo_ROT0(uint8_t a_OC1x);
/**===============================================================================
 * Function Name  : HAL_Servo_Init.
 * Brief          : Function To Rotate the Servo To 90 Degree.
 * Parameter (in) : Pin Output @ref SERVO pin.
 * Return         : None.
 * Note           : None.																	*/
void HAL_Servo_ROT90(uint8_t a_OC1x);
/**===============================================================================
 * Function Name  : HAL_Servo_Init.
 * Brief          : Function To Rotate the Servo To 180 Degree.
 * Parameter (in) : Pin Output @ref SERVO pin.
 * Return         : None.
 * Note           : None.																	*/
void HAL_Servo_ROT180(uint8_t a_OC1x);

#endif /* INC_SERVO_MOTOR_H_ */
