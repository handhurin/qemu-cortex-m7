/**
 * @file    cmsdk_gpio.c
 * @author  Merlin Kooshmanian
 * @brief   Source file for GPIO CMSDK functions
 * @date    13/06/2024
 *
 * Largely inspired by the Zephyr driver and STM32 HAL style.
 */

/******************************* Include Files *******************************/

#include "cmsdk_hal.h"

/***************************** Macros Definitions ****************************/

/*************************** Functions Declarations **************************/

/*************************** Variables Definitions ***************************/

/*************************** Functions Definitions ***************************/

/**
 * @brief Init Gpio
 */
HAL_StatusTypeDef cmsdk_GpioInit(void)
{

}

/**
 * @brief Write a specific pin from a gpio
 */
void cmsdk_GpioWritePin(GPIO_TypeDef *gpio, uint16_t pin, GPIO_PinState PinState)
{

}

/**
 * @brief Toggles a specific pin from a gpio
 */
void cmsdk_GpioTogglePin(GPIO_TypeDef *gpio, uint16_t pin)
{

}

/**
 * @brief Read a specific pin from a gpio
 */
GPIO_PinState cmsdk_GpioReadPin(GPIO_TypeDef *gpio, uint16_t pin)
{

}