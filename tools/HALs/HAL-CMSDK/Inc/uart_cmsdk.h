/**
 * @file    cmsdk_uart.h
 * @author  Merlin Kooshmanian
 * @brief   Header file for CMSDK UART functions
 * @date    09/06/2024
 * 
 * Largely inspired by the Zephyr driver and STM32 HAL style.
 */

#ifndef CMSDK_UART_H
#define CMSDK_UART_H

/******************************* Include Files *******************************/

#include "hal_cmsdk_types.h"

/***************************** Macros Definitions ****************************/

/***************************** Types Definitions *****************************/

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

HAL_StatusTypeDef uart_cmsdk_init(UART_HandleTypeDef *uart);
HAL_StatusTypeDef uart_cmsdk_rx_char(UART_HandleTypeDef *uart, unsigned char *c);
HAL_StatusTypeDef uart_cmsdk_tx_char(UART_HandleTypeDef *uart, unsigned char c);

#endif /* CMSDK_UART_H */