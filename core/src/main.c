/**
 * @file    main.c
 * @author  Merlin Kooshmanian
 * @brief   Source file for main
 * @date    26/12/2022
 *
 * @copyright Copyright (c) Merlin Kooshmanian 2024
 */

/******************************* Include Files *******************************/

#include <stdio.h>
#include <string.h>
#include <unwind.h>

#include "main.h"
#include "hal_init.h"
#include "hal_uart.h"
#include "hal_timer.h"
#include "stacktrace.h"

/***************************** Macros Definitions ****************************/

/*************************** Functions Declarations **************************/

extern void InitConsole(uartInst_t *uart_inst);

/*************************** Variables Definitions ***************************/

uartInst_t g_uart_inst =
{
    .uart_ref = CMSDK_UART0,
    .drive_type = UART_POLLING_DRIVE,
    .baudrate = 115200,
};

/*************************** Functions Definitions ***************************/

// Test functions
void function_c(void)
{
    // Wont be called
    PrintStackTrace();

    // Enable div by 0 exception
    *((volatile uint32_t *)0xE000ED14) |= (1 << 4);
    // Do the error
    volatile uint32_t zero = 0;
    volatile uint32_t result = 1 / zero;
    (void)result;
}

void function_b(void)
{
    function_c();
}

void function_a(void)
{
    function_b();
}

/**
 * @fn      main(void)
 * @brief   Main function
 * @return  0
 */
int main(void)
{
    // Initialisation
    InitHal();
    UartOpen(&g_uart_inst);
    InitConsole(&g_uart_inst);

    // Function Core

    // Backtrace test
    function_a();

    // Main Looop
    while (1)
    {
        // Print Hello
        printf("Hello\n");

        // 1s delay
        HalDelay(1000);
    }

    return 0;
}

/**
 * @brief Hardfault Handler
 */
void HardFault_Handler(void)
{
    // Warn that we enter in HardFault Handler 
    printf("Error Handler\n");

    // Print StackTrace
    PrintStackTrace();

    // Infinite loop
    while (1) 
    {

    }
}