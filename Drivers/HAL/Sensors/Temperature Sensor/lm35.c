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

void HAL_LM35_ADC_init(void)
{
	ADC_Config_t LM35_config;
	LM35_config.ADC_VoltRef = LM35_ADC_Vref_SOURCE;
	LM35_config.ADC_Prescaler = ADC_PRESCALE_8;
	MCAL_ADC_init(&LM35_config);
}

uint8_t HAL_LM35_getTemp(void)
{
	uint16_t adc_value = 0;
	uint8_t temp = 0;

	adc_value = MCAL_ADC_readChannel(LM35_CHANNEL);

	temp = (uint8_t)(((uint32_t)adc_value * LM35_MAX_TEMP * LM35_ADC_Vref_VALUE)/(LM35_ADC_MAX_RES * LM35_MAX_VOLT));

	return temp;

}
