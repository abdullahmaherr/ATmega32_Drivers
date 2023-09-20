/*============================================================================================
 * Module : KEYPAD
 *
 * File Name : keypad.c
 *
 * Author: Abdullah Maher
 *
 * Description : Source File Of KEYPAD Driver
 *
 * Created on: May 1, 2023
 =============================================================================================*/

#include "keypad.h"
#include"atmega32.h"
#include"gpio.h"


/**===============================================================================
 * Function Name  : delay_ms.
 * Brief          : Function To Make Delay.
 * Parameter (in) : delay time.
 * Return         : None.
 * Note           : None																				*/
static void delay_ms(uint32_t delay);

#ifndef STANDARD_KEYPAD

#if (KEYPAD_NUM_COL == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static uint8_t KEYPAD_4x3_adjustKeyNumber(uint8_t button_number);
#elif (KEYPAD_NUM_COL == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static uint8_t KEYPAD_4x4_adjustKeyNumber(uint8_t button_number);
#endif

#endif /* STANDARD_KEYPAD */




uint8_t HAL_KEYPAD_PressedKey(void)
{
	uint8_t row,col;

	/* Configure 4 pins for ROWS in the port as output pins */
	MCAL_GPIO_PinInit(KEYPAD_ROW_PORT_ID,KEYPAD_ROW_FIRST_PIN_ID, GPIO_PIN_INPUT);
	MCAL_GPIO_PinInit(KEYPAD_ROW_PORT_ID,KEYPAD_ROW_FIRST_PIN_ID+1, GPIO_PIN_INPUT);
	MCAL_GPIO_PinInit(KEYPAD_ROW_PORT_ID,KEYPAD_ROW_FIRST_PIN_ID+2, GPIO_PIN_INPUT);
	MCAL_GPIO_PinInit(KEYPAD_ROW_PORT_ID,KEYPAD_ROW_FIRST_PIN_ID+3, GPIO_PIN_INPUT);

	/* Configure 4 pins for COLUMNS in the port as input pins */
	MCAL_GPIO_PinInit(KEYPAD_COL_PORT_ID,KEYPAD_COL_FIRST_PIN_ID, GPIO_PIN_INPUT);
	MCAL_GPIO_PinInit(KEYPAD_COL_PORT_ID,KEYPAD_COL_FIRST_PIN_ID+1, GPIO_PIN_INPUT);
	MCAL_GPIO_PinInit(KEYPAD_COL_PORT_ID,KEYPAD_COL_FIRST_PIN_ID+2, GPIO_PIN_INPUT);
#if(KEYPAD_NUM_COL == 4)
	MCAL_GPIO_PinInit(KEYPAD_COL_PORT_ID,KEYPAD_COL_FIRST_PIN_ID+3, GPIO_PIN_INPUT);
#endif
	while(1)
	{
		for(row = 0; row < KEYPAD_NUM_ROW; row++)/* loop for rows */
		{
			MCAL_GPIO_PinInit(KEYPAD_ROW_PORT_ID,(KEYPAD_ROW_FIRST_PIN_ID+row), GPIO_PIN_OUTPUT);

			MCAL_GPIO_WritePin(KEYPAD_ROW_PORT_ID, (KEYPAD_ROW_FIRST_PIN_ID+row), LOGIC_LOW);

			for(col = 0; col < KEYPAD_NUM_COL; col++)/* loop for cols */
			{
				if(MCAL_GPIO_ReadPin(KEYPAD_COL_PORT_ID, (KEYPAD_COL_FIRST_PIN_ID+col)) == KEYPAD_BUTTON_PRESSED)
				{
#if (KEYPAD_NUM_COL == 3)
#ifdef STANDARD_KEYPAD
					return ((row*KEYPAD_NUM_COL)+col+1);
#else
					return KEYPAD_4x3_adjustKeyNumber((row*KEYPAD_NUM_COL)+col+1);
#endif
#elif (KEYPAD_NUM_COL == 4)
#ifdef STANDARD_KEYPAD
					return ((row*KEYPAD_NUM_COL)+col+1);
#else
					return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_COL)+col+1);
#endif
#endif
				}
			}
			MCAL_GPIO_PinInit(KEYPAD_ROW_PORT_ID,(KEYPAD_ROW_FIRST_PIN_ID+row), GPIO_PIN_INPUT);
			delay_ms(5);
		}
	}
}

#ifndef STANDARD_KEYPAD

#if (KEYPAD_NUM_COL == 3)

static uint8_t KEYPAD_4x3_adjustKeyNumber(uint8_t button_number)
{
	uint8_t keypad_button = 0;
	switch(button_number)
	{
	case 10: keypad_button = '*'; // ASCII Code of *
	break;
	case 11: keypad_button = 0;
	break;
	case 12: keypad_button = '#'; // ASCII Code of #
	break;
	default: keypad_button = button_number;
	break;
	}
	return keypad_button;
}

#elif (KEYPAD_NUM_COL == 4)

static uint8_t KEYPAD_4x4_adjustKeyNumber(uint8_t button_number)
{
	uint8_t keypad_button = 0;
	switch(button_number)
	{
	case 1: keypad_button = 7;
	break;
	case 2: keypad_button = 8;
	break;
	case 3: keypad_button = 9;
	break;
	case 4: keypad_button = '%'; // ASCII Code of %
	break;
	case 5: keypad_button = 4;
	break;
	case 6: keypad_button = 5;
	break;
	case 7: keypad_button = 6;
	break;
	case 8: keypad_button = '*'; /* ASCII Code of '*' */
	break;
	case 9: keypad_button = 1;
	break;
	case 10: keypad_button = 2;
	break;
	case 11: keypad_button = 3;
	break;
	case 12: keypad_button = '-'; /* ASCII Code of '-' */
	break;
	case 13: keypad_button = 13;  /* ASCII of Enter */
	break;
	case 14: keypad_button = 0;
	break;
	case 15: keypad_button = '='; /* ASCII Code of '=' */
	break;
	case 16: keypad_button = '+'; /* ASCII Code of '+' */
	break;
	default: keypad_button = button_number;
	break;
	}
	return keypad_button;
}

#endif

#endif /* STANDARD_KEYPAD */


static void delay_ms(uint32_t delay)
{
	uint32_t i, j;
	for (i = 0; i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}
}