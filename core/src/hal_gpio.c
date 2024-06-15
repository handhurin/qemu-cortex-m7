/**
 * @file    hal_gpio.c
 * @author  Merlin Kooshmanian
 * @brief   Source file for HAL GPIO functions
 * @date    29/04/2023
 *
 * @copyright Copyright (c) Merlin Kooshmanian 2024
 */

/******************************* Include Files *******************************/

#include "hal_gpio.h"

/***************************** Macros Definitions ****************************/

/*************************** Functions Declarations **************************/

/*************************** Variables Definitions ***************************/

/*************************** Functions Definitions ***************************/

/**
 * @fn              GpioOpen(gpioInst_t *gpio_inst)
 * @brief           Function that initialise a GPIO
 * @param[in,out]   gpio_inst Instance that contains GPIOs parameters
 * @retval          #GEN_HAL_SUCCESSFUL if creation succeed
 * @retval          #GEN_HAL_INVALID_PARAM if GPIO port is not available for this board, pin = 0 or one pointer is null
 *
 * Attention : GPIO_PIN_0 != 0, GPIO_PIN_0=0x0001 (cf hal_gpio.h)
 */
halStatus_t IN_GPIO_TEXT_SECTION GpioOpen(gpioInst_t *gpio_inst)
{
    // Variable Initialisation
    halStatus_t return_value = GEN_HAL_SUCCESSFUL;

    // Function Core
    if (gpio_inst != NULL)
    {
        HAL_StatusTypeDef status = cmsdk_GpioInit(gpio_inst->port, gpio_inst->pin, gpio_inst->mode);
        if (status != HAL_OK)
        {
            return_value = GEN_HAL_ERROR;
        }
    }
    else
    {
        return_value = GEN_HAL_INVALID_PARAM;
    }

    return return_value;
}

/**
 * @fn          GpioWrite(gpioInst_t *gpio_inst, gpioValue_t value)
 * @brief       Function that writes into a GPIO pin
 * @param[in]   gpio_inst Instance that contains GPIOs parameters
 * @param[in]   value Value we want to write on the pin
 * @retval      #GEN_HAL_SUCCESSFUL if write succeed
 * @retval      #GEN_HAL_INVALID_PARAM if GPIO is not an output or instance is a null pointer
 */
halStatus_t IN_GPIO_TEXT_SECTION GpioWrite(gpioInst_t *gpio_inst, gpioValue_t value)
{
    // Variable Initialisation
    halStatus_t return_value = GEN_HAL_SUCCESSFUL;

    // Function Core
    if (gpio_inst != NULL)
    {
        HAL_StatusTypeDef status = cmsdk_GpioWritePin(gpio_inst->port, gpio_inst->pin, value);
        if (status != HAL_OK)
        {
            return_value = GEN_HAL_ERROR;
        }
    }
    else
    {
        return_value = GEN_HAL_INVALID_PARAM;
    }

    return return_value;
}

/**
 * @fn          GpioRead(gpioInst_t *gpio_inst, gpioValue_t *value)
 * @brief       Function that reads into a GPIO pin
 * @param[in]   gpio_inst Instance that contains GPIOs parameters
 * @param[out]  value Value we want to write on the pin
 * @retval      #GEN_HAL_SUCCESSFUL if write succeed
 * @retval      #GEN_HAL_INVALID_PARAM if GPIO is not an output or instance is a null pointer
 *
 * Only works in INPUT mode without interrupt
 */
halStatus_t IN_GPIO_TEXT_SECTION GpioRead(gpioInst_t *gpio_inst, gpioValue_t *value)
{
    // Variable Initialisation
    halStatus_t return_value = GEN_HAL_SUCCESSFUL;

    // Function Core
    if (gpio_inst != NULL)
    {
        HAL_StatusTypeDef status = cmsdk_GpioReadPin(gpio_inst->port, gpio_inst->pin, value);
        if (status != HAL_OK)
        {
            return_value = GEN_HAL_ERROR;
        }
    }
    else
    {
        return_value = GEN_HAL_INVALID_PARAM;
    }

    return return_value;
}

/**
 * @fn          GpioToggle(gpioInst_t *gpio_inst)
 * @brief       Function that toggles a GPIO pin
 * @param[in]   gpio_inst Instance that contains GPIOs parameters
 * @retval      #GEN_HAL_SUCCESSFUL if toggle succeed
 * @retval      #GEN_HAL_INVALID_PARAM if GPIO is not an output or instance is a null pointer
 */
halStatus_t IN_GPIO_TEXT_SECTION GpioToggle(gpioInst_t *gpio_inst)
{
    // Variable Initialisation
    halStatus_t return_value = GEN_HAL_SUCCESSFUL;

    // Function Core
    if ((gpio_inst != NULL) && (gpio_inst->mode == GPIO_MODE_OUTPUT))
    {
        HAL_StatusTypeDef status = cmsdk_GpioTogglePin(gpio_inst->port, gpio_inst->pin);
        if (status != HAL_OK)
        {
            return_value = GEN_HAL_ERROR;
        }
    }
    else
    {
        return_value = GEN_HAL_INVALID_PARAM;
    }

    return return_value;
}

/**
 * @fn              GpioIoctl(gpioInst_t *gpio_inst, halIoCtlCmd_t io_cmd)
 * @brief           Function that adds advanced control to the driver
 * @param[in,out]   gpio_inst Instance that contains GPIOs parameters
 * @param[in,out]   io_cmd IO Control command struct (including data)
 * @retval          #GEN_HAL_INVALID_PARAM if instance is a null pointer
 * @retval          #GEN_HAL_BUSY if action cannot be performed because driver is busy
 * @retval          #GEN_HAL_ERROR if io control encountered an error
 * @retval          #GEN_HAL_SUCCESSFUL else
 *
 * @warning This feature is not supported yet so it does nothing
 */
halStatus_t IN_GPIO_TEXT_SECTION GpioIoctl(gpioInst_t *gpio_inst, halIoCtlCmd_t io_cmd)
{
    // Variable Initialisation
    halStatus_t return_value = GEN_HAL_SUCCESSFUL;

    // Function Core
    if (gpio_inst != NULL)
    {
        /* TO DO */
        (void)(gpio_inst);
        (void)(io_cmd);
    }
    else
    {
        return_value = GEN_HAL_INVALID_PARAM;
    }

    return return_value;
}

/**
 * @fn              GpioClose(gpioInst_t *gpio_inst)
 * @brief           Function that desinit the gpio pin and puts defaults parameters
 * @param[in,out]   gpio_inst Instance that contains GPIOs parameters
 * @retval          #GEN_HAL_SUCCESSFUL if changing parameters succeed
 * @retval          #GEN_HAL_INVALID_PARAM if instance is a null pointer
 *
 * This function erase gpio_inst
 */
halStatus_t IN_GPIO_TEXT_SECTION GpioClose(gpioInst_t *gpio_inst)
{
    // Variable Initialisation
    halStatus_t return_value = GEN_HAL_SUCCESSFUL;

    // Function Core
    if (gpio_inst != NULL)
    {
        /* TO DO */
        (void)(gpio_inst);
    }
    else
    {
        return_value = GEN_HAL_INVALID_PARAM;
    }

    return return_value;
}

