/*============================================================================================
 * Module : ADC
 *
 * File Name : adc.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 ADC Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_ADC_H_
#define INC_ADC_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"


/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/
/* The Source Of Reference Voltage */
#define ADC_AREF 				(0x00U)
#define ADC_AVCC 				(0x40U)
#define ADC_INTERNAL_Vref 		(0xC0U)

/* The Source Of Analog Channel */
#define ADC_CH0					(0x00U)
#define ADC_CH1 				(0x01U)
#define ADC_CH2					(0x02U)
#define ADC_CH3					(0x03U)
#define ADC_CH4					(0x04U)
#define ADC_CH5					(0x05U)
#define ADC_CH6					(0x06U)
#define ADC_CH7					(0x07U)

/* The Prescaler Division Factor */
#define ADC_PRESCALE_2 			(0x00U)
#define ADC_PRESCALE_4 			(0x02U)
#define ADC_PRESCALE_8 			(0x03U)
#define ADC_PRESCALE_16			(0x04U)
#define ADC_PRESCALE_32 		(0x05U)
#define ADC_PRESCALE_64 		(0x06U)
#define ADC_PRESCALE_128 		(0x07U)

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MCAL_ADC_Init.
 * Brief          : Function To Initialize The ADC.
 * Parameter (in) : The Voltage Reference Vref Source.
 * Parameter (in) : The Input Frequency (F ADC) to The ADC.
 * Return         : None.
 * Note           : F ADC must to be between 50kHz and 200 kHz to get maximum resolution.
 	 	 	 	 	The ADC working in Single-ended, Polling,  */
void MCAL_ADC_Init(uint8_t a_VoltRef, uint8_t a_Prescale);

/**===============================================================================
 * Function Name  : MCAL_ADC_ReadChannel.
 * Brief          : Function To Read Analog Data From Certain Channel.
 * Parameter (in) : Channel Number.
 * Return         : The Desired Data.
 * Note           : None																	*/
uint16_t MCAL_ADC_ReadChannel(uint8_t a_channelx);

#endif /* INC_ADC_H_ */
