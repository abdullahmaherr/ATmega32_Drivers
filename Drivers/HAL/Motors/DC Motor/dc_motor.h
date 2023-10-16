/*============================================================================================
 * Module : Motors
 *
 * File Name : dc_motor.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 Motors Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_DC_MOTOR_H_
#define INC_DC_MOTOR_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"


/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/


/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : HAL_DCMotor_GPIO_Init.
 * Brief          : Function To Initialize The Pins of DC Motor as Output in PORTx.
 * Parameter (in) : Pins Configuration.
 * Return         : None.
 * Note           : None.																	*/
void HAL_DCMotor_GPIO_Init(uint8_t a_Port,uint8_t a_Pin);

/**===============================================================================
 * Function Name  : HAL_DCMotor_Start.
 * Brief          : Function To Run The Motor.
 * Parameter (in) : Pins Configuration.
 * Return         : None.
 * Note           : None.																	*/
void HAL_DCMotor_Start(uint8_t a_Port,uint8_t a_Pin);

/**===============================================================================
 * Function Name  : HAL_DCMotor_Stop.
 * Brief          : Function To Stop Run The Motor.
 * Parameter (in) : Pins Configuration.
 * Return         : None.
 * Note           : None.																	*/
void HAL_DCMotor_Stop(uint8_t a_Port,uint8_t a_Pin);

/**===============================================================================
 * Function Name  : HAL_DCMotor_Stop.
 * Brief          : Function To Stop Run The Motor.
 * Parameter (in) : Pins Configuration.
 * Return         : None.
 * Note           : None.																	*/
void HAL_DCMotor_Speed(uint8_t a_pwmx,uint8_t a_speed);



#endif /* INC_DC_MOTOR_H_ */
