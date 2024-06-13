/**
 * @file    hal_timer.h
 * @author  Merlin Kooshmanian
 * @brief   Header file for TIMER functions
 * @date    04/06/2024
 *
 * @copyright Copyright (c) Merlin Kooshmanian 2024
 */

#ifndef HAL_TIMER_H
#define HAL_TIMER_H

/******************************* Include Files *******************************/

#include "hal_types.h"

/***************************** Macros Definitions ****************************/

#define GENERIC_HAL_MAX_DELAY   30u /**< Max delay (in milliseconds) for function that uses HAL timer */

/***************************** Types Definitions *****************************/

/*************************** Variables Declarations **************************/

/*************************** Functions Declarations **************************/

extern void HalDelay(uint32_t delay);
extern uint32_t HalGetTick(void);

#endif /* HAL_TIMER_H */