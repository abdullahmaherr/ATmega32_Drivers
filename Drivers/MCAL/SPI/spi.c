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
#include <avr/interrupt.h>


/*===============================================================================
 *                              Global Variables                                 *
 ================================================================================*/

static volatile void (*gp_CallBack)(void) = NULL_PTR;  /* Global Pointer To Assign ISRs */


/*===============================================================================
 *                       		 ISR Functions  		                         *
 ================================================================================*/
ISR(SPI_STC_vect)
{
	/* Calling Handler of OVF Mode */
	if(gp_CallBack != NULL_PTR)
		(*gp_CallBack)();
}


/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void MCAL_SPI_init(SPI_Config_t *p_SPI_Config)
{
	/*Configure The Pins of SPI*/
	if(p_SPI_Config->SPI_Mode == SPI_MODE_MASTER)
	{
		MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN4, GPIO_PIN_OUTPUT);/*SS*/
		MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN5, GPIO_PIN_OUTPUT);/*MOSI*/
		MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN6, GPIO_PIN_INPUT);/*MISO*/
		MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN7, GPIO_PIN_OUTPUT);/*SCLK*/
	}else if(p_SPI_Config->SPI_Mode == SPI_MODE_SLAVE)
	{
		MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN4, GPIO_PIN_INPUT);/*SS*/
		MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN5, GPIO_PIN_INPUT);/*MOSI*/
		MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN6, GPIO_PIN_OUTPUT);/*MISO*/
		MCAL_GPIO_PinInit(GPIOB_ID, GPIO_PIN7, GPIO_PIN_INPUT);/*SCLK*/
	}

	if(p_SPI_Config->SPI_IRQ == SPI_IRQ_ENABLE)
	{
		gp_CallBack = (p_SPI_Config->p_SPI_ISR);
		SEI();
	}

	/* Disable Double Speed*/
	SPSR &= (~(1<<SPI2X));

	/*Configure SPI*/
	SPCR = (p_SPI_Config->SPI_IRQ) | (p_SPI_Config->SPI_DataOrder) | (p_SPI_Config->SPI_Mode) | (p_SPI_Config->SPI_ClockPolarity) | (p_SPI_Config->SPI_ClockPhase) | (p_SPI_Config->SPI_Prescaler);

}

void MCAL_SPI_deinit(void)
{
	/* Return Registers to Default Value */
	SPCR = (0x00);
	SPSR &= (~(1<<SPI2X));
}

uint8_t MCAL_SPI_sendReceiveByte(uint8_t a_data,uint8_t a_Polling)
{
	/*Assign The Data Register With Data To Transmit*/
	SPDR = a_data;

	if(a_Polling == SPI_POLLING_ENABLE)
	{
		/*Wait Until When a serial transfer is complete, the SPIF Flag is set*/
		while(BIT_IS_CLEAR(SPSR,SPIF));
	}

	/*return The Received Data*/
	return SPDR;
}

void MCAL_SPI_sendString(const uint8_t* p_str)
{
	uint8_t i = 0;
	uint8_t dum;

	/* Send The String */
	while((p_str[i]) != '\0')
	{
		/* dum Variable is just for the Dummy Data Received */
		dum = MCAL_SPI_sendReceiveByte(p_str[i],SPI_POLLING_ENABLE);
		i++;
	}
}

void MCAL_SPI_receiveString(uint8_t* p_str)
{
	uint8_t i = 0;

	/*Receive First Byte*/
	p_str[i] = MCAL_SPI_sendReceiveByte(DEFAULT_DATA,SPI_POLLING_ENABLE);

	/*Receive The Rest of String*/
	while(p_str[i] != '#')
	{
		i++;
		p_str[i] = MCAL_SPI_sendReceiveByte(DEFAULT_DATA,SPI_POLLING_ENABLE);
	}
	p_str[i] = '\0';
}

void MCAL_SPI_sendNumber(uint32_t a_num)
{
	/* Accessing The Number Byte By Byte*/
	uint8_t *p_temp =(uint8_t*)(&a_num);
	uint8_t dum;

	dum = MCAL_SPI_sendReceiveByte(p_temp[0],SPI_POLLING_ENABLE);
	dum = MCAL_SPI_sendReceiveByte(p_temp[1],SPI_POLLING_ENABLE);
	dum = MCAL_SPI_sendReceiveByte(p_temp[2],SPI_POLLING_ENABLE);
	dum = MCAL_SPI_sendReceiveByte(p_temp[3],SPI_POLLING_ENABLE);
}

uint32_t MCAL_SPI_receiveNumber(void)
{
	uint32_t num;
	/* Accessing The Number Byte By Byte*/
	uint8_t *p_temp =(uint8_t*)(&num);

	p_temp[0] = MCAL_SPI_sendReceiveByte(DEFAULT_DATA,SPI_POLLING_ENABLE);
	p_temp[1] = MCAL_SPI_sendReceiveByte(DEFAULT_DATA,SPI_POLLING_ENABLE);
	p_temp[2] = MCAL_SPI_sendReceiveByte(DEFAULT_DATA,SPI_POLLING_ENABLE);
	p_temp[3] = MCAL_SPI_sendReceiveByte(DEFAULT_DATA,SPI_POLLING_ENABLE);

	return num;
}
