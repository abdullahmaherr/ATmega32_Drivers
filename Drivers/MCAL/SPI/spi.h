/*============================================================================================
 * Module : SPI
 *
 * File Name : spi.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 SPI Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_SPI_H_
#define INC_SPI_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"


/*===============================================================================
 *                     				  Macros 			                         *
 ================================================================================*/

#define DEFAULT_DATA 0xFF

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MCAL_SPI_InitMaster.
 * Brief          : Function To Initialize The SPI as Master.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : No Interrupt, LSB Transmitted First, Sample In Raising, SCLK Low Is Idle */
void MCAL_SPI_InitMaster(void);

/**===============================================================================
 * Function Name  : MCAL_SPI_InitSlave.
 * Brief          : Function To Initialize The SPI as Slave.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : No Interrupt, LSB Transmitted First, Sample In Raising, SCLK Low Is Idle */
void MCAL_SPI_InitSlave(void);

/**===============================================================================
 * Function Name  : MCAL_SPI_SendReceiveByte.
 * Brief          : Function To Send and Receive Byte.
 * Parameter (in) : Data to Send.
 * Return         : Received Data.
 * Note           : None. */
uint8_t MCAL_SPI_SendReceiveByte(uint8_t a_data);

/**===============================================================================
 * Function Name  : MCAL_SPI_SendString.
 * Brief          : Function To Send String.
 * Parameter (in) : The String To Send.
 * Return         : None.
 * Note           : None. */
void MCAL_SPI_SendString(const uint8_t * p_str);

/**===============================================================================
 * Function Name  : MCAL_SPI_ReceiveString.
 * Brief          : Function To Receive String.
 * Parameter (in) : The Buffer Address To Receive String.
 * Return         : None.
 * Note           : None. */
void MCAL_SPI_ReceiveString(uint8_t * p_str);

/**===============================================================================
 * Function Name  : MCAL_SPI_SendNumber.
 * Brief          : Function To Send Number.
 * Parameter (in) : The Number To Send.
 * Return         : None.
 * Note           : None. */
void MCAL_SPI_SendNumber(uint32_t a_num);

/**===============================================================================
 * Function Name  : MCAL_SPI_ReceiveNumber.
 * Brief          : Function To Receive Number.
 * Parameter (in) : None.
 * Return         : The Received Number.
 * Note           : None. */
uint32_t MCAL_SPI_ReceiveNumber(void);

#endif /* INC_SPI_H_ */
