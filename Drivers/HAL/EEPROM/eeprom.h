/*============================================================================================
 * Module : External EEPROM
 *
 * File Name : eeprom.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 External EEPROM Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"


/*===============================================================================
 *                      			Macros    				                     *
 ================================================================================*/

#ifndef SUCCEDED
#define SUCCEDED (1u)
#endif

#ifndef FAILED
#define FAILED (0u)
#endif

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MCAL_EEPROM_WriteByte.
 * Brief          : Function To Write Byte on The External EEPROM.
 * Parameter (in) : Address.
 * Parameter (in) : The Byte To Write It.
 * Return         : Status.
 * Note           : None.																	*/
uint8_t MCAL_EEPROM_WriteByte(uint16_t a_address,uint8_t a_data);

/**===============================================================================
 * Function Name  : MCAL_EEPROM_ReadByte.
 * Brief          : Function To Read Byte From The External EEPROM.
 * Parameter (in) : Address.
 * Parameter (in) : Pointer To Buffer.
 * Return         : Status.
 * Note           : None.																	*/
uint8_t MCAL_EEPROM_ReadByte(uint16_t a_address,uint8_t *p_buff);

#endif /* INC_EEPROM_H_ */
