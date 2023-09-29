/*============================================================================================
 * Module : I2C
 *
 * File Name : i2c.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 I2C Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/


#ifndef INC_I2C_H_
#define INC_I2C_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"


/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/

#define ADDRESS_MCU				0b00000010/* Set MS 7-Bits With The Address Of MCU */


/*===============================================================================
 *                      			Macros    				                     *
 ================================================================================*/

#define ACK 			1U
#define NACK 			0U


/* TWSR reflects the status of the TWI logic and the Two-wire Serial Bus*/

#define I2C_START 					0x08 /* A START condition has been transmitted */
#define I2C_REP_START 				0x10 /* A repeated START condition has been transmitted */
#define I2C_SLA_W_ACK               0x18 /* SLA+W has been transmitted, ACK has been received */
#define I2C_SLA_W_NACK 				0x20 /* SLA+W has been transmitted, NACK has been received */
#define I2C_DATA_TR_ACK 			0x28 /* Data byte has been transmitted, ACK has been received */
#define I2C_DATA_TR_NACK			0x30 /* Data byte has been transmitted, NACK has been received */
#define I2C_ARB_LOST				0x38 /* Arbitration lost */

#define I2C_SLA_R_ACK 				0x40 /* SLA+R has been transmitted, ACK has been received */
#define I2C_SLA_R_NACK 				0x48 /* SLA+R has been transmitted, NACK has been received */
#define I2C_DATA_RE_ACK 			0x50 /* Data byte has been received, ACK has been returned */
#define I2C_DATA_RE_NACK			0x58 /* Data byte has been received, NACK has been returned */


/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MCAL_I2C_Init.
 * Brief          : Function To Initialize The I2C(TWI) Communication Protocol.
 * Parameter (in) : Pin Configuration.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_I2C_Init(void);
/**===============================================================================
 * Function Name  : MCAL_I2C_Start.
 * Brief          : Function To Start The I2C(TWI) Communication.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_I2C_Start(void);
/**===============================================================================
 * Function Name  : MCAL_I2C_Stop.
 * Brief          : Function To Stop The I2C(TWI) Communication.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_I2C_Stop(void);
/**===============================================================================
 * Function Name  : MCAL_I2C_WriteByte.
 * Brief          : Function To Transmit Byte.
 * Parameter (in) : The Byte To Be Transmitted.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_I2C_WriteByte(uint8_t a_data);
/**===============================================================================
 * Function Name  : MCAL_I2C_ReadByte.
 * Brief          : Function To Receive Byte.
 * Parameter (in) : ACK or NACK.
 * Return         : The Received Byte.
 * Note           : None.																	*/
uint8_t MCAL_I2C_ReadByte(uint8_t a_ack);
/**===============================================================================
 * Function Name  : MCAL_I2C_GetStatus.
 * Brief          : Function To Get The Status Of The Communication.
 * Parameter (in) : None.
 * Return         : The Status Of Communication .
 * Note           : None.																	*/
uint8_t MCAL_I2C_GetStatus(void);

#endif /* INC_I2C_H_ */
