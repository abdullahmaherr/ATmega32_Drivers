/*============================================================================================
 * Module : External EEPROM
 *
 * File Name : eeprom.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 External EEPROM Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "eeprom.h"
#include "i2c.h"


/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

uint8_t MCAL_EEPROM_WriteByte(uint16_t a_address,uint8_t a_data)
{
	/* Starting I2C Communication */
	MCAL_I2C_Start();
	if(MCAL_I2C_GetStatus() != I2C_START)
		return FAILED;

	/* Send The Device Address */
	MCAL_I2C_WriteByte((uint8_t)((0xA0) | ((a_address & 0x0700) >> 7))); /* Sending Most Significant 3-Bits of Byte Address with Device address (Writing)*/
	if(MCAL_I2C_GetStatus() != I2C_SLA_W_ACK)
		return FAILED;

	/* Send The Required Memory Location Address */
	MCAL_I2C_WriteByte((uint8_t)(a_address));
	if(MCAL_I2C_GetStatus() != I2C_DATA_TR_ACK)
		return FAILED;

	/* Send Byte To Store It In The EEPROM */
	MCAL_I2C_WriteByte(a_data);
	if(MCAL_I2C_GetStatus() != I2C_DATA_TR_ACK)
		return FAILED;

	MCAL_I2C_Stop();

	return SUCCEDED;
}


uint8_t MCAL_EEPROM_ReadByte(uint16_t a_address,uint8_t *p_buff)
{
	/* Starting I2C Communication */
	MCAL_I2C_Start();
	if(MCAL_I2C_GetStatus() != I2C_START)
		return FAILED;

	/* Send The Device Address */
	MCAL_I2C_WriteByte((uint8_t)((0xA0) | ((a_address & 0x0700) >> 7))); /* Sending Most Significant 3-Bits of Byte Address with Device address (Writing)*/
	if(MCAL_I2C_GetStatus() != I2C_SLA_W_ACK)
		return FAILED;

	/* Send The Required Memory Location Address */
	MCAL_I2C_WriteByte((uint8_t)(a_address));
	if(MCAL_I2C_GetStatus() != I2C_DATA_TR_ACK)
		return FAILED;

	/* Repeat Starting To Read From EEPROM*/
	MCAL_I2C_Start();
	if(MCAL_I2C_GetStatus() != I2C_REP_START)
		return FAILED;

	/* Send The Device Address */
	MCAL_I2C_WriteByte((uint8_t)((0xA0) | ((a_address & 0x0700) >> 7) | 1)); /* Sending Most Significant 3-Bits of Byte Address with Device address (Reading)*/
	if(MCAL_I2C_GetStatus() != I2C_SLA_R_ACK)
		return FAILED;

	/* Reading The Byte With NACK*/
	*p_buff = MCAL_I2C_ReadByte(NACK);
	if(MCAL_I2C_GetStatus() != I2C_DATA_RE_NACK)
		return FAILED;

	MCAL_I2C_Stop();

	return SUCCEDED;
}

