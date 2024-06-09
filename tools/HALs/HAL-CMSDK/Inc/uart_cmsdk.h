/**
 * @file    cmsdk_uart.h
 * @author  Merlin Kooshmanian
 * @brief   Header file for CMSDK UART functions
 * @date    04/06/2024
 * 
 * Largely inspired by the Zephyr driver.
 */

#ifndef CMSDK_UART_H
#define CMSDK_UART_H

/******************************* Include Files *******************************/

#include <stdint.h>
#include <stddef.h>

#include "CMSDK_CM7.h"

/***************************** Macros Definitions ****************************/

/***************************** Types Definitions *****************************/

/**
 * @brief  HAL Lock structures definition
 */
typedef enum
{
  HAL_UNLOCKED = 0x00,
  HAL_LOCKED   = 0x01
} HAL_LockTypeDef;

/** 
 * @struct  UART_HandleTypeDef
 * @brief   Struct type definition of a UART instance
 */
typedef struct
{
    CMSDK_UART_TypeDef *instance;
    uint32_t baud_rate; 
    HAL_LockTypeDef lock;
    uint32_t error_code; 
} UART_HandleTypeDef;

/*************************** Variables Declarations **************************/

/*************************** Functions Declarations **************************/

int uart_cmsdk_init(UART_HandleTypeDef *uart);
int uart_cmsdk_rx_char(UART_HandleTypeDef *uart, unsigned char *c);
int uart_cmsdk_tx_char(UART_HandleTypeDef *uart, unsigned char c);

#endif /* CMSDK_UART_H */