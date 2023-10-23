/*============================================================================================
 * Module : ADC
 *
 * File Name : adc.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 ADC Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "adc.h"


/*===============================================================================
 *                              Global Variables                                 *
 ================================================================================*/


/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void MCAL_ADC_Init(uint8_t a_VoltRef, uint8_t a_Prescale)
{
	/* Select The Vref Source, the result is right adjusted, channel 0 as initialization */
	ADMUX = ((a_VoltRef) & (0xC0));

	/* Select The Desired Prescaler, Enable ADC, Disable Auto Trigger and Interrupt */
	ADCSRA = (a_Prescale) | (1<<ADEN);
}

uint16_t MCAL_ADC_ReadChannel(uint8_t a_channelx)
{
	/* Clear First 5-Bits */
	ADMUX &= 0xE0;
	/* Select The Desired Channel (must to be Single-Ended) */
	ADMUX |= (a_channelx & 0x07);

	/*Start Conversion*/
	ADCSRA |= (1<<ADSC);

	/* Waiting Until The Conversion Is Ended */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	/*Clear The Flag*/
	SET_BIT(ADCSRA,ADCSRA);

	/* Return Data Register Value */
	return ADC;
}

