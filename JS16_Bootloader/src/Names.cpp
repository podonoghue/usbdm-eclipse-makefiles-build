/*
 * Names.c
 *
 *  Created on: 16/02/2010
 *      Author: podonoghue
 */

/*! \file
    \brief Debugging message file

    This file provides mappings from various code numbers to strings.\n
    It is mostly used for debugging messages.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "UsbdmSystem.h"
#include "Names.h"

//! ICP Error message string from Error #
static const char *const ICPerrorMessages[] = {
    "No error",                      // 0   ICP_RC_OK
    "USB error",                     // 1   ICP_RC_USB_ERROR
    "No JS16 device found",          // 2   ICP_RC_NO_JS16__DEVICE
    "Illegal parameters",            // 3   ICP_RC_ILLEGAL_PARAMS
    "Device not open",               // 4   ICP_RC_DEVICE_NOT_OPEN
    "File not found",                // 5   ICP_RC_FILE_NOT_FOUND
    "ICP command failed on target",  // 6   ICP_RC_COMMAND_FAILED
};

//! \brief Maps an ICP Error Code # to a string
//!
//! @param error Error number
//!
//! @return pointer to static string describing the error
//!
const char *ICP_GetErrorName(ICP_ErrorType error) {
   char const *errorName = NULL;

   if ((unsigned)error < sizeof(ICPerrorMessages)/sizeof(ICPerrorMessages[0]))
      errorName = ICPerrorMessages[error];
   if (errorName == NULL)
      errorName = "UNKNOWN";
   return errorName;
}

