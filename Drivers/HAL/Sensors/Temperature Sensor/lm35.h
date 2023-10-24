/*============================================================================================
 * Module : LM35 Temperature Sensor
 *
 * File Name : lm35.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of LM35 Temperature Sensor Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_LM35_H_
#define INC_LM35_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"

/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/

/* Select Sensor Channel Temperature ADC_CHx where x = 0 to 7*/
#define LM35_CHANNEL ADC_CH0

/* Select The Voltage Reference Value */
#define LM35_ADC_MAX_RES 		1023
#define LM35_ADC_Vref_Value	 	5
#define LM35_MAX_VOLT 			1.5
#define LM35_MAX_TEMP 			150


/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : HAL_LM35_GetTemp.
 * Brief          : Function To Read Temperature from LM35 Sensor.
 * Parameter (in) : None.
 * Return         : The Measured Temp.
 * Note           : None.																				  */
uint8_t HAL_LM35_GetTemp(void);

#endif /* INC_LM35_H_ */
