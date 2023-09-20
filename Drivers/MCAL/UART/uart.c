/*============================================================================================
 * Module : UART
 *
 * File Name : uart.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 UART Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "uart.h"


/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void MCAL_UART_Init(uint32_t a_baudRate)
{
	uint16_t ubrrReg;

	/* Double Mode Speed */
	UCSRA = (1<< U2X) ;

	/* All Interrupt Disabled, TXRX Enabled, Without The Ninth Bit */
	UCSRB = (1<<RXEN) | (1<<TXEN) ;

	/* Asynchronous Operation, Disabled Parity, 1-Stop Bit, 8-Bit Data */
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0) ;

	/* Calculate The UBRR Register Value */
	ubrrReg = (uint16_t)(((F_CPU / (a_baudRate * 8UL))) - 1);

	/*Set Baud Rate*/
	UBRRH = (ubrrReg >> 8);
	UBRRL = (uint8_t)(ubrrReg);
}


void MCAL_UART_TX(uint8_t a_data)
{
	/* Wait Until The Buffer Is Empty */
	while(BIT_IS_CLEAR(UCSRA,UDRE));
	UDR = a_data;
}


uint8_t MCAL_UART_RX(void)
{
	/*Wait Until There Are Unread Data is Received*/
	while(BIT_IS_CLEAR(UCSRA,RXC));
	return UDR;
}


void MCAL_UART_sendString(const uint8_t *p_str)
{
	/*Send The String*/
	while(*p_str != '\0')
	{
		MCAL_UART_TX(*p_str);
		p_str++;
	}
}


void MCAL_UART_receiveString(uint8_t *p_str)
{
	/* Receiving The String */
	do{
		*p_str = MCAL_UART_RX();
		p_str++;
	}while(*p_str != '#');

	/* After Receiving The String Replace The '#' With '\0' */
	*p_str = '\0';
}


void MCAL_UART_sendNumber(uint32_t a_num)
{
	/* Accessing The Number Byte By Byte*/
	uint8_t *p_temp = (uint8_t*)&a_num;

	MCAL_UART_TX(p_temp[0]);
	MCAL_UART_TX(p_temp[1]);
	MCAL_UART_TX(p_temp[2]);
	MCAL_UART_TX(p_temp[3]);
}


uint32_t MCAL_UART_receiveNumber(void)
{
	uint32_t num;
	/* Accessing The Number Byte By Byte*/
	uint8_t *p_temp = (uint8_t*)&num;

	/* Receiving Byte By Byte */
	p_temp[0]= MCAL_UART_RX();
	p_temp[1]= MCAL_UART_RX();
	p_temp[2]= MCAL_UART_RX();
	p_temp[3]= MCAL_UART_RX();


	return num;
}
