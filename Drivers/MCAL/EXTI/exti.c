/*============================================================================================
 * Module : External Interrupt
 *
 * File Name : exti.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of ATmega32 External Interrupt Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/
/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include "exti.h"
#include <avr/interrupt.h>


/*===============================================================================
 *                              Global Variables                                 *
 ================================================================================*/

static void (*gp_CallBack[3])(void) = {NULL_PTR,NULL_PTR,NULL_PTR};

/*===============================================================================
 *                       		 ISR Functions  		                         *
 ================================================================================*/
ISR(INT0_vect)
{
	if(gp_CallBack[0] != NULL_PTR)
		(*gp_CallBack[0])();
}


ISR(INT1_vect)
{
	if(gp_CallBack[0] != NULL_PTR)
		(*gp_CallBack[1])();
}


ISR(INT2_vect)
{
	if(gp_CallBack[0] != NULL_PTR)
		(*gp_CallBack[2])();
}

/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

void MCAL_EXTI_INT0Init(EXTI_Config_t p_INT0_Config)
{
	/*Configure PORTD PIN2 as Input for INT1*/
	DDRD &= (~(1<<PD2));

	/*Configure Trigger Case if Raising or Failing or Both*/
	MCUCR |= (p_INT0_Config.EXTI_TriggerCase & 0x03);

	/*Assign The CallBack Function With The User's ISR*/
	gp_CallBack[0] = p_INT0_Config.p_EXTI_ISR[0];

	/*Enable/Disable MASK INT1*/
	switch(p_INT0_Config.EXTI_IRQ)
	{
	case EXTI_IRQ_DISABLE:
		CLEAR_BIT(GICR,INT0); break;
	case EXTI_IRQ_ENABLE:
		SET_BIT(GICR,INT0);
		SEI();
		break;
	}
}

void MCAL_EXTI_INT1Init(EXTI_Config_t p_INT1_Config)
{
	/*Configure PORTD PIN3 as Input for INT1*/
	DDRD &= (~(1<<PD3));

	/*Configure Trigger Case if Raising or Failing or Both*/
	MCUCR |= ((p_INT1_Config.EXTI_TriggerCase & 0x03) << 2);

	/*Assign The CallBack Function With The User's ISR*/
	gp_CallBack[1] = p_INT1_Config.p_EXTI_ISR[1];

	/*Enable/Disable MASK INT1*/
	switch(p_INT1_Config.EXTI_IRQ)
	{
	case EXTI_IRQ_DISABLE:
		CLEAR_BIT(GICR,INT1); break;
	case EXTI_IRQ_ENABLE:
		SET_BIT(GICR,INT1);
		SEI();
		break;
	}
}

void MCAL_EXTI_INT2Init(EXTI_Config_t p_INT2_Config)
{
	/*Configure PORTB PIN2 as Input for INT2*/
	DDRB &= (~(1<<PB2));

	/*Configure Trigger Case if Raising or Failing or Both*/
	switch(p_INT2_Config.EXTI_TriggerCase)
	{
	case EXTI_FALLING_TRIG:
		CLEAR_BIT(MCUCSR,ISC2); break;
	case EXTI_RISING_TRIG:
		SET_BIT(MCUCSR,ISC2); break;
	default:
		return;
	}

	/*Assign The CallBack Function With The User's ISR*/
	gp_CallBack[2] = p_INT2_Config.p_EXTI_ISR[2];

	/*Enable/Disable MASK INT2*/
	switch(p_INT2_Config.EXTI_IRQ)
	{
	case EXTI_IRQ_DISABLE:
		CLEAR_BIT(GICR,INT2); break;
	case EXTI_IRQ_ENABLE:
		SET_BIT(GICR,INT2);
		SEI();
		break;
	}
}


