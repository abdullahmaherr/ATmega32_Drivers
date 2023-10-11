/*============================================================================================
 * Module : Watch Dog Timer
 *
 * File Name : wdt.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 WDT Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/

#include "wdt.h"


/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void MCAL_WDT_ON(void)
{
	/* WDT Enable, Set WDT To 2.1s Periodic Time*/
	WDTCR |= (0x0F);
}


void MCAL_WDT_OFF(void)
{
	/* Write logical one to WDTOE and WDE */

	WDTCR |= (1<<WDTOE) | (1<<WDE);

	/* Turn off WDT */
	WDTCR = (0x00);
}
