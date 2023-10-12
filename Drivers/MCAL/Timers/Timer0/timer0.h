/*============================================================================================
 * Module : TIMER0
 *
 * File Name : timer0.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of ATmega32 TIMER0 Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#ifndef INC_TIMER0_H_
#define INC_TIMER0_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "atmega32.h"


/*===============================================================================
 *                            User Type Definitions                              *
 ================================================================================*/
typedef struct
{
	uint8_t Timer_Mode;			/* Specifies The Timer Mode (Normal,CTC) Regarding to  @ref TIMER0 Mode*/

	uint8_t Timer_Clock;	    /* Specifies The Timer Clock Regarding to  @ref TIMER0 Clock&Prescaler*/

	uint8_t Timer_IntMask;		/* Specifies The Timer Interrupt Mask Regarding to  @ref TIMER0 Enable/Disabled*/

	void (*p_Timer_ISR)(void);	/* SET The Call Back Function That Will Be Called In ISR*/

}TIMER0_Config_t;



/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/

/* @ref TIMER0 Modes */
#define TIMER0_MODE_OVF						((uint8_t)0x80U)
#define TIMER0_MODE_CTC						((uint8_t)0x88U)

/* @ref TIMER0 Clock&Prescaler */
#define TIMER0_CLK_STOP						((uint8_t)0x00U)
#define TIMER0_CLK_PRESCALER_0				((uint8_t)0x01U)
#define TIMER0_CLK_PRESCALER_8				((uint8_t)0x02U)
#define TIMER0_CLK_PRESCALER_64				((uint8_t)0x03U)
#define TIMER0_CLK_PRESCALER_256			((uint8_t)0x04U)
#define TIMER0_CLK_PRESCALER_1024			((uint8_t)0x05U)
#define TIMER0_CLK_EXTERNAL_FAILING			((uint8_t)0x06U)/* To Operate as Counter*/
#define TIMER0_CLK_EXTERNAL_RAISING			((uint8_t)0x07U)/* To Operate as Counter*/

/* @ref TIMER0 Enable/Disabled*/
#define TIMER0_MASK_DISABLE					((uint8_t)0x00)
#define TIMER0_MASK_OVF_ENABLE				((uint8_t)0x01)
#define TIMER0_MASK_CTC_ENABLE				((uint8_t)0x02)

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MCAL_TIMER0_Init.
 * Brief          : Function To Initialize Timer0.
 * Parameter (in) : Timer0 Configuration.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_TIMER0_Init(TIMER0_Config_t *p_TIMER0_Config);

/**===============================================================================
 * Function Name  : MCAL_TIMER0_Stop.
 * Brief          : Function To Stop Timer0 Counter.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_TIMER0_Stop(void);

/**===============================================================================
 * Function Name  : MCAL_TIMER0_Resume.
 * Brief          : Function To Resume Timer0 Counter.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_TIMER0_Resume(void);

/**===============================================================================
 * Function Name  : MCAL_TIMER0_SetCompareValue.
 * Brief          : Function To Set Timer0 Compare Value In CTC Mode.
 * Parameter (in) : Compare Value.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_TIMER0_SetCompareValue(uint8_t a_TicksNumber);

/**===============================================================================
 * Function Name  : MCAL_TIMER0_SetCounter.
 * Brief          : Function To Set Timer0 Counter Initial Value.
 * Parameter (in) : Counter Initial Value.
 * Return         : None.
 * Note           : None.																	*/
void MCAL_TIMER0_SetCounter(uint8_t a_Counter);

#endif /* INC_TIMER0_H_ */
