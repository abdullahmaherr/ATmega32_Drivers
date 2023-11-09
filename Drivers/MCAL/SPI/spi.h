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
#include "std_types.h"

/*===============================================================================
 *                            User Type Definitions                              *
 ================================================================================*/

typedef struct
{
	uint8_t SPI_Mode;			/* Specifies The SPI Mode (Master,Slave) Regarding to @ref SPI Mode*/

	uint8_t SPI_DataOrder;		/* Specifies The SPI DataOrder Regarding to @ref DataOrder */

	uint8_t SPI_ClockPolarity;	/* Specifies The SPI ClockPolarity Regarding to @ref ClockPolarity */

	uint8_t SPI_ClockPhase;		/* Specifies The SPI ClockPhase Regarding to @ref ClockPhase */

	uint8_t SPI_Prescaler;		/* Specifies The SPI Prescaler Regarding to @ref Prescaler */

	uint8_t SPI_IRQ;			/* Specifies The SPI Interrupt Mask Regarding to  @ref SPI Interrupt Enable/Disable */

	void(*p_SPI_ISR)(void);		/* SET The Call Back Function That Will Be Called In ISR */

}SPI_Config_t;


/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/
/*@ref SPI Mode*/
#define SPI_MODE_MASTER					(0x50U)
#define SPI_MODE_SLAVE					(0x40U)

/*@ref DataOrder */
#define SPI_DATA_ORDER_LSB				(0x20U)
#define SPI_DATA_ORDER_MSB				(0x00U)

/* @ref ClockPolarity */
#define SPI_CLK_POLARITY_HIGH			(0x08U)/* CLK Idle Is High */
#define SPI_CLK_POLARITY_LOW			(0x00U)/* CLK Idle Is Low */

/* @ref ClockPhase */
#define SPI_CLK_PHASE_LEAD				(0x00U)/* Sampling at Leading */
#define SPI_CLK_PHASE_LAST				(0x04U)/* Sampling at Trailing */

/* @ref Prescaler */
#define SPI_CLK_PRESCALER_4				(0x00U)
#define SPI_CLK_PRESCALER_16			(0x01U)
#define SPI_CLK_PRESCALER_64			(0x02U)
#define SPI_CLK_PRESCALER_128			(0x03U)

/* @ref SPI Interrupt Enable/Disable */
#define SPI_IRQ_ENABLE					(0x80U)
#define SPI_IRQ_DISABLE					(0x00U)

typedef enum
{
	SPI_POLLING_DISABLE,
	SPI_POLLING_ENABLE
}SPI_Polling_Mecanism;
/*===============================================================================
 *                     				  Macros 			                         *
 ================================================================================*/

#define DEFAULT_DATA 0xFF

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MCAL_SPI_Init.
 * Brief          : Function To Initialize The SPI.
 * Parameter (in) : Pointer to SPI Configuration.
 * Return         : None.
 * Note           : Normal Speed 																		*/
void MCAL_SPI_init(SPI_Config_t *p_SPI_Config);

/**===============================================================================
 * Function Name  : MCAL_SPI_Deinit.
 * Brief          : Function To Uninitialize The SPI.
 * Parameter (in) : None.
 * Return         : None.
 * Note           : None.																				 */
void MCAL_SPI_deinit(void);

/**===============================================================================
 * Function Name  : MCAL_SPI_SendReceiveByte.
 * Brief          : Function To Send and Receive Byte.
 * Parameter (in) : Data to Send.
 * Return         : Received Data.
 * Note           : None. */
uint8_t MCAL_SPI_sendReceiveByte(uint8_t a_data,uint8_t a_Polling);

/**===============================================================================
 * Function Name  : MCAL_SPI_SendString.
 * Brief          : Function To Send String.
 * Parameter (in) : The String To Send.
 * Return         : None.
 * Note           : None. */
void MCAL_SPI_sendString(const uint8_t * p_str);

/**===============================================================================
 * Function Name  : MCAL_SPI_ReceiveString.
 * Brief          : Function To Receive String.
 * Parameter (in) : The Buffer Address To Receive String.
 * Return         : None.
 * Note           : None. */
void MCAL_SPI_receiveString(uint8_t * p_str);

/**===============================================================================
 * Function Name  : MCAL_SPI_SendNumber.
 * Brief          : Function To Send Number.
 * Parameter (in) : The Number To Send.
 * Return         : None.
 * Note           : None. */
void MCAL_SPI_sendNumber(uint32_t a_num);

/**===============================================================================
 * Function Name  : MCAL_SPI_ReceiveNumber.
 * Brief          : Function To Receive Number.
 * Parameter (in) : None.
 * Return         : The Received Number.
 * Note           : None. */
uint32_t MCAL_SPI_receiveNumber(void);

#endif /* INC_SPI_H_ */
