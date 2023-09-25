/*============================================================================================
 * Module : SPI
 *
 * File Name : spi.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 SPI Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "spi.h"
#include "gpio.h"

/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void MCAL_SPI_InitMaster(void)
{
	/*Configure The Pins of SPI*/
	MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN4, GPIO_PIN_OUTPUT);/*SS*/
	MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN5, GPIO_PIN_OUTPUT);/*MOSI*/
	MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN6, GPIO_PIN_INPUT);/*MISO*/
	MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN7, GPIO_PIN_OUTPUT);/*SCLK*/

	/*Master Enable, No Interrupt, LSB Transmitted First, Sample In Raising, SCLK Low Is Idle, Fcpu/4 */
	SPCR = (1<<SPE) | (1<<MSTR);
	SPSR &= (~(1<<SPI2X));

}

void MCAL_SPI_InitSlave(void)
{
	/*Configure The Pins of SPI*/
	MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN4, GPIO_PIN_INPUT);/*SS*/
	MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN5, GPIO_PIN_INPUT);/*MOSI*/
	MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN6, GPIO_PIN_OUTPUT);/*MISO*/
	MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN7, GPIO_PIN_INPUT);/*SCLK*/

	/* Slave Enable, No Interrupt, LSB Transmitted First, Sample In Raising, SCLK Low Is Idle, Fcpu/4 */
	SPCR = (1<<SPE);
	SPSR &= (~(1<<SPI2X));
}

uint8_t MCAL_SPI_SendReceiveByte(uint8_t a_data)
{
	/*Assign The Data Register With Data To Transmit*/
	SPDR = a_data;

	/*Wait Until When a serial transfer is complete, the SPIF Flag is set*/
	while(BIT_IS_CLEAR(SPSR,SPIF));

	/*return The Received Data*/
	return SPDR;
}

void MCAL_SPI_SendString(const uint8_t* p_str)
{
	uint8_t i = 0;
	uint8_t dum;

	/* Send The String */
	while((p_str[i]) != '\0')
	{
		/* dum Variable is just for the Dummy Data Received */
		dum = MCAL_SPI_SendReceiveByte(p_str[i]);
		i++;
	}
}

void MCAL_SPI_ReceiveString(uint8_t* p_str)
{
	uint8_t i = 0;

	/*Receive First Byte*/
	p_str[i] = MCAL_SPI_SendReceiveByte(DEFAULT_DATA);

	/*Receive The Rest of String*/
	while(p_str[i] != '#')
	{
		i++;
		p_str[i] = MCAL_SPI_SendReceiveByte(DEFAULT_DATA);
	}
	p_str[i] = '\0';
}

void MCAL_SPI_SendNumber(uint32_t a_num)
{
	/* Accessing The Number Byte By Byte*/
	uint8_t *p_temp =(uint8_t*)(&a_num);
	uint8_t dum;

	dum = MCAL_SPI_SendReceiveByte(p_temp[0]);
	dum = MCAL_SPI_SendReceiveByte(p_temp[1]);
	dum = MCAL_SPI_SendReceiveByte(p_temp[2]);
	dum = MCAL_SPI_SendReceiveByte(p_temp[3]);
}

uint32_t MCAL_SPI_ReceiveNumber(void)
{
	uint32_t num;
	/* Accessing The Number Byte By Byte*/
	uint8_t *p_temp =(uint8_t*)(&num);

	p_temp[0] = MCAL_SPI_SendReceiveByte(DEFAULT_DATA);
	p_temp[1] = MCAL_SPI_SendReceiveByte(DEFAULT_DATA);
	p_temp[2] = MCAL_SPI_SendReceiveByte(DEFAULT_DATA);
	p_temp[3] = MCAL_SPI_SendReceiveByte(DEFAULT_DATA);

	return num;
}
