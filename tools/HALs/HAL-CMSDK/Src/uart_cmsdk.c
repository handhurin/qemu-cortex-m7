/**
 * @file    uart_cmsdk.c
 * @author  Merlin Kooshmanian
 * @brief   Source file for UART CMSDK functions
 * @date    04/06/2024
 * 
 * Largely inspired by the Zephyr driver.
 */

/******************************* Include Files *******************************/

#include "uart_cmsdk.h"

/***************************** Macros Definitions ****************************/

/*************************** Functions Declarations **************************/

/*************************** Variables Definitions ***************************/

extern uint32_t SystemCoreClock;

/*************************** Functions Definitions ***************************/

/**
 * @brief Initialize UART channel
 */
int uart_cmsdk_init(UART_HandleTypeDef *uart)
{
	/* Enable clock for subsystem */
	// ???????

	/* Set baud rate */
	if (uart->baud_rate != 0u)
	{
		uart->instance->BAUDDIV = SystemCoreClock / uart->baud_rate;
	}

	/* Enable receiver and transmitter */
	uart->instance->CTRL = CMSDK_UART_CTRL_TXEN_Msk | CMSDK_UART_CTRL_RXEN_Msk;

	return 0;
}

/**
 * @brief Poll the device for receiving a char.
 */
int uart_cmsdk_rx_char(UART_HandleTypeDef *uart, unsigned char *c)
{
	/* If the receiver is not ready returns -1 */
	if (!(uart->instance->STATE & CMSDK_UART_STATE_RXBF_Msk)) 
	{
		return -1;
	}

	/* Got a character */
	*c = (unsigned char)uart->instance->DATA;

	return 0;
}

/**
 * @brief Poll the device for transmitting a char.
 */
int uart_cmsdk_tx_char(UART_HandleTypeDef *uart, unsigned char c)
{
	/* Wait for transmitter to be ready */
	while (uart->instance->STATE & CMSDK_UART_STATE_TXBF_Msk);

	/* Send a character */
	uart->instance->DATA = (uint32_t)c;

	return 0;
}