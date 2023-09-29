/*============================================================================================
 * Module : I2C
 *
 * File Name : i2c.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 I2C Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "i2c.h"
#include "gpio.h"

/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void MCAL_I2C_Init(void)
{
	/*
	 * SCL Frequency = ((F_CPU) / (16 + (2 * TWBR * 4 ^ TWPS)))
	 * For F_CPU = 8Mhz We Get Bit Rate 400Khz                 */
	TWBR = 0x02;
	TWSR = 0x00;/* TWPS = 00 */

	/* Addressing The MCU */
	TWAR = ADDRESS_MCU;

	/* Enable The I2C */
	TWCR = (1<<TWEN);
}


void MCAL_I2C_Start(void)
{
	/*Clear Interrupt Flag, Send Start Condition*/
	TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWSTA);

	/* Wait Until The Start Has Been Transmitted */
	while(BIT_IS_CLEAR(TWCR,TWINT));
}


void MCAL_I2C_Stop(void)
{
	/*Clear Interrupt Flag, Send Stop Condition*/
	TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWSTO);
}


void MCAL_I2C_WriteByte(uint8_t a_data)
{
	/* Assign The TWDR with Data Or Address To Be Transmitted */
	TWDR = a_data;

	/* Clear The Interrupt Flag Before Send Data */
	TWCR = (1<<TWEN) | (1<<TWINT);

	/* Wait Until The Data Has Been Transmitted */
	while(BIT_IS_CLEAR(TWCR,TWINT));
}


uint8_t MCAL_I2C_ReadByte(uint8_t a_ack)
{
	switch(a_ack)
	{
	case NACK:
		/* Clear The Interrupt Flag Before Reading Data */
		TWCR = (1<<TWEN) | (1<<TWINT); break;
	case ACK:
		/* Clear The Interrupt Flag Before Reading Data,Enable ACK */
		TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWEA); break;
	}

	/* Wait Until The Has Been Received */
	while(BIT_IS_CLEAR(TWCR,TWINT));

	/*Reading The Data*/
	return TWDR;
}


uint8_t MCAL_I2C_GetStatus(void)
{
	uint8_t status;

	/* Get The Most Significant 5 Bits */
	status = (TWSR & 0xF8);


	return status;

}
