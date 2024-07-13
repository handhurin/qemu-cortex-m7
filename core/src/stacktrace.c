/**
 * @file    stacktrace.c
 * @author  Merlin Kooshmanian
 * @brief   Source file for stacktrace
 * @date    13/07/2024
 *
 * @copyright Copyright (c) Merlin Kooshmanian 2024
 */

/******************************* Include Files *******************************/

#include <stdio.h>
#include <string.h>
#include <unwind.h>

#include "stacktrace.h"

/***************************** Macros Definitions ****************************/

/*************************** Functions Declarations **************************/

static _Unwind_Reason_Code UnwindTraceFunction(struct _Unwind_Context *context, void *arg);

/*************************** Variables Definitions ***************************/

static int skip;

/*************************** Functions Definitions ***************************/

// Print Stacktrace function
void PrintStackTrace(void)
{
    skip = 1; // Set skip to 1 in order to skip the first adress in UnwindTraceFunction
    printf("Stack trace:\n");
    _Unwind_Backtrace(UnwindTraceFunction, NULL);
}

// CallBack Function for __gnu_Unwind_Backtrace
static _Unwind_Reason_Code UnwindTraceFunction(struct _Unwind_Context *context, void *arg)
{
    // Unused Parameter
    (void)(arg);

    // Function Core
    uintptr_t pc = _Unwind_GetIP(context);
    if (pc)
    {
        if (skip == 1)
        {
            // Drop the adress because it is &PrintStackTrace
            skip = 0;
        }
        else
        {
            printf("0x%08x\n", (unsigned int)pc);
        }
    }

    return _URC_NO_REASON;
}
