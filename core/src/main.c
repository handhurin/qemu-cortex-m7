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

#include "main.h"
#include "uart.h"

/***************************** Macros Definitions ****************************/

/*************************** Functions Declarations **************************/

/*************************** Variables Definitions ***************************/

uartInst_t g_uart_inst =
{
    .uart_ref = CMSDK_UART0,
    .drive_type = UART_POLLING_DRIVE,
    .baudrate = 115200,
};

/*************************** Functions Definitions ***************************/

/**
 * @fn      main(void)
 * @brief   Main function
 * @return  0
 */
int main(void)
{
    // Initialisation
    UartOpen(&g_uart_inst);

    // Function Core

    UartWrite(&g_uart_inst, (uartMsg_t *)"Hello World !\n", sizeof("Hello World !\n"));

    while (1)
    {
        // Do Nothing
    }

    return 0;
}
