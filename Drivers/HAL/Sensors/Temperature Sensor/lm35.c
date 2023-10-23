/*============================================================================================
 * Module : LM35 Temperature Sensor
 *
 * File Name : lm35.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of LM35 Temperature Sensor Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/
/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "lm35.h"
#include "adc.h"

/*===============================================================================
 *                              Global Variables                                 *
 ================================================================================*/





/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

uint8_t HAL_LM35_GetTemp(void)
{
	uint16_t adc_value = 0;
	uint8_t temp = 0;

	adc_value = MCAL_ADC_ReadChannel(LM35_CHANNEL);

	temp = (uint8_t)(((uint32_t)adc_value * LM35_MAX_TEMP * 5)/(1023 * LM35_MAX_VOLT));

	return temp;

}