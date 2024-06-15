/**
 * @file    hal_init.c
 * @author  Merlin Kooshmanian
 * @brief   Source file for HAL Initialisation functions
 * @date    29/04/2023
 *
 * @copyright Copyright (c) Merlin Kooshmanian 2024
 */

/******************************* Include Files *******************************/

#include "hal_types.h"

/***************************** Macros Definitions ****************************/

/*************************** Functions Declarations **************************/

/*************************** Variables Definitions ***************************/

/*************************** Functions Definitions ***************************/

/**
 * @fn      InitHal(void)
 * @brief   Function that init the choosen HAL and sysclock
 * @retval  #GEN_HAL_ERROR if cannot init HAL or system clock
 * @retval  #GEN_HAL_SUCCESSFUL else
 *
 * If there is an error it goes to Error Handler
 */
halStatus_t InitHal(void)
{
    // Variable Initialisation
    halStatus_t return_value = GEN_HAL_SUCCESSFUL;

    // Function Core
    HAL_StatusTypeDef status = cmsdk_InitHal();
    if (status != HAL_OK)
    {
        return_value = GEN_HAL_ERROR;
    }

    return return_value;
}
