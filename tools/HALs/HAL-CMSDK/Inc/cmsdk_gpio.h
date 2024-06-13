/**
 * @file    cmsdk_gpio.h
 * @author  Merlin Kooshmanian
 * @brief   Header file for CMSDK GPIO functions
 * @date    13/06/2024
 *
 * Largely inspired by the Zephyr driver and STM32 HAL style.
 */

#ifndef CMSDK_GPIO_H
#define CMSDK_GPIO_H

/******************************* Include Files *******************************/

#include "cmsdk_hal_types.h"

/***************************** Macros Definitions ****************************/

/***************************** Types Definitions *****************************/

/**
 * @brief  GPIO port type redefinition
 */
typedef CMSDK_GPIO_TypeDef GPIO_TypeDef;

/**
 * @brief  GPIO Bit SET and Bit RESET enumeration
 */
typedef enum
{
    GPIO_PIN_RESET = 0U,
    GPIO_PIN_SET
} GPIO_PinState;

/*************************** Variables Declarations **************************/

/*************************** Functions Declarations **************************/

HAL_StatusTypeDef cmsdk_GpioInit(void);
void cmsdk_GpioWritePin(GPIO_TypeDef *gpio, uint16_t pin, GPIO_PinState PinState);
void cmsdk_GpioTogglePin(GPIO_TypeDef *gpio, uint16_t pin);
GPIO_PinState cmsdk_GpioReadPin(GPIO_TypeDef *gpio, uint16_t pin);

#endif /* CMSDK_GPIO_H */