/**
 * @file    timer.h
 * @author  Merlin Kooshmanian
 * @brief   Header file for TIMER functions
 * @date    04/06/2024
 *
 * @copyright Copyright (c) Merlin Kooshmanian 2024
 */

#ifndef TIMER_H
#define TIMER_H

/******************************* Include Files *******************************/

#include "hal_types.h"

/***************************** Macros Definitions ****************************/

/***************************** Types Definitions *****************************/

/*************************** Variables Declarations **************************/

/*************************** Functions Declarations **************************/

extern halStatus_t InitHalTimer(void);
extern void HalDelay(uint32_t delay);
extern uint32_t HalGetTick(void);

#endif /* TIMER_H */