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

/***************************** Macros Definitions ****************************/

#define LINE_MAX_SIZE 64

/*************************** Functions Declarations **************************/

static void PrintStackTrace(void);
static _Unwind_Reason_Code UnwindTraceFunction(struct _Unwind_Context *context, void *arg);

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
    PrintStackTrace();
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

    // Function Core

    // Backtrace test
    function_a();

    // Main Looop
    while (1)
    {
        // Print Hello
        UartWrite(&g_uart_inst, (uartMsg_t *)"Hello !\n", sizeof("Hello !\n"));

        // 1s delay
        HalDelay(1000);
    }

    return 0;
}

// Print Stacktrace function
static void PrintStackTrace(void)
{
    UartWrite(&g_uart_inst, (uartMsg_t *)"Stack trace:\n", sizeof("Stack trace:\n"));
    _Unwind_Backtrace(UnwindTraceFunction, NULL);
}

// CallBack Function for __gnu_Unwind_Backtrace
static _Unwind_Reason_Code UnwindTraceFunction(struct _Unwind_Context *context, void *arg)
{
    // Unused Parameter
    (void)(arg);

    // Function Core
    char line[LINE_MAX_SIZE];
    uintptr_t pc = _Unwind_GetIP(context);
    if (pc)
    {
        snprintf(line, LINE_MAX_SIZE, "0x%08x\n", (unsigned int)pc);
        UartWrite(&g_uart_inst, (uartMsg_t *)&line, strlen(line));
    }

    return _URC_NO_REASON;
}
