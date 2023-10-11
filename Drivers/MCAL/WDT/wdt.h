/*============================================================================================
 * Module : Watch Dog Timer
 *
 * File Name : wdt.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 WDT Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_WDT_H_
#define INC_WDT_H_


/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MCAL_WDT_ON.
 * Brief          : Function To Turn WDT ON.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_WDT_ON(void);

/**===============================================================================
 * Function Name  : MCAL_WDT_OFF.
 * Brief          : Function To Turn WDT OFF.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_WDT_OFF(void);

#endif /* INC_WDT_H_ */
