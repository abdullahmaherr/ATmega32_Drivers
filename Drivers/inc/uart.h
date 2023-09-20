/*============================================================================================
 * Module : UART
 *
 * File Name : uart.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 UART Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_UART_H_
#define INC_UART_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"


/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MCAL_UART_Init.
 * Brief          : Function To Initialize The UART.
 * Parameter (in) : Pin Configuration.
 * Return         : None.
 * Note           : The Initialization : Synchronous, Double Speed, Without Interrupt, 1-Stop Bit, Without Parity Bit, 8-Bit Data. */
void MCAL_UART_Init(uint32_t a_baudRate);

/**===============================================================================
 * Function Name  : MCAL_UART_TX.
 * Brief          : Function To Transmit The Data .
 * Parameter (in) : Data to Transmit it.
 * Return         : None.
 * Note           : None.																		*/
void MCAL_UART_TX(uint8_t a_data);

/**===============================================================================
 * Function Name  : MCAL_UART_Init.
 * Brief          : Function To Receive The UART.
 * Parameter (in) : None.
 * Return         : The Received Data.
 * Note           : None.																			*/
uint8_t MCAL_UART_RX(void);

/**===============================================================================
 * Function Name  : MCAL_UART_sendString.
 * Brief          : Function To Send String By Using The UART.
 * Parameter (in) : The String To Send It.
 * Return         : None.
 * Note           : At The End Of Your String Add '#' To Inform The Receiver The End Of Your String	*/
void MCAL_UART_sendString(const uint8_t *p_str);

/**===============================================================================
 * Function Name  : MCAL_UART_receiveString.
 * Brief          : Function To Receive String By Using The UART.
 * Parameter (in) : The Pointer To String buffer.
 * Return         : None.
 * Note           : Receiving String With '#' At The End OF The String.								*/
void MCAL_UART_receiveString(uint8_t *p_str);

/**===============================================================================
 * Function Name  : MCAL_UART_sendNumber.
 * Brief          : Function To Send Number By Using The UART.
 * Parameter (in) : The Number To Send It.
 * Return         : None.
 * Note           : None																	*/
void MCAL_UART_sendNumber(uint32_t a_num);

/**===============================================================================
 * Function Name  : MCAL_UART_receiveNumber.
 * Brief          : Function To Receive Number By Using The UART.
 * Parameter (in) : None.
 * Return         : The Received Number.
 * Note           : None.																	*/
uint32_t MCAL_UART_receiveNumber(void);


#endif /* INC_UART_H_ */
