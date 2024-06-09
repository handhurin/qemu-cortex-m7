/**
 * @file    hal_cmsdk_types.h
 * @author  Merlin Kooshmanian
 * @brief   Header file for HAL CMSDK types
 * @date    09/06/2024
 */

#ifndef HAL_CMSDK_TYPES_H
#define HAL_CMSDK_TYPES_H

/******************************* Include Files *******************************/

#include <stdint.h>
#include <stddef.h>
#include "CMSDK_CM7.h"

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
  * @brief  HAL Status structures definition
  */
typedef enum
{
  HAL_OK       = 0x00,
  HAL_ERROR    = 0x01,
  HAL_BUSY     = 0x02,
  HAL_TIMEOUT  = 0x03
} HAL_StatusTypeDef;

#endif /* HAL_CMSDK_TYPES_H */