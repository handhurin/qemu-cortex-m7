/**
 * @file    cmsdk_uart.c
 * @author  Merlin Kooshmanian
 * @brief   Source file for UART CMSDK functions
 * @date    09/06/2024
 * 
 * Largely inspired by the Zephyr driver and STM32 HAL style.
 */

/******************************* Include Files *******************************/

#include "cmsdk_uart.h"

/***************************** Macros Definitions ****************************/

/*************************** Functions Declarations **************************/

/*************************** Variables Definitions ***************************/

extern uint32_t SystemCoreClock;

/*************************** Functions Definitions ***************************/

/**
 * @brief Initialize UART channel
 */
HAL_StatusTypeDef cmsdk_UartInit(UART_HandleTypeDef *uart)
{
	/* Set baud rate */
	if (uart->baud_rate != 0u)
	{
		uart->instance->BAUDDIV = SystemCoreClock / uart->baud_rate;
	}

	/* Enable receiver and transmitter */
	uart->instance->CTRL = CMSDK_UART_CTRL_TXEN_Msk | CMSDK_UART_CTRL_RXEN_Msk;

	return HAL_OK;
}

/**
 * @brief Poll the device for receiving a char.
 */
HAL_StatusTypeDef cmsdk_UartRxChar(UART_HandleTypeDef *uart, unsigned char *c)
{
	/* If the receiver is not ready returns HAL_BUSY */
	if (!(uart->instance->STATE & CMSDK_UART_STATE_RXBF_Msk)) 
	{
		return HAL_BUSY;
	}

	/* Got a character */
	*c = (unsigned char)uart->instance->DATA;

	return HAL_OK;
}

/**
 * @brief Poll the device for transmitting a char.
 */
HAL_StatusTypeDef cmsdk_UartTxChar(UART_HandleTypeDef *uart, unsigned char c)
{
	/* Wait for transmitter to be ready */
	while (uart->instance->STATE & CMSDK_UART_STATE_TXBF_Msk);

	/* Send a character */
	uart->instance->DATA = (uint32_t)c;

	return HAL_OK;
}