/**
 * @file     usbdmError.cpp
 * @brief    Error handling
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#include <stdio.h>
#include "hardware.h"

namespace USBDM {

/** Last error set by USBDM code */
volatile ErrorCode errorCode = E_NO_ERROR;

/** Table of error messages indexed by error code */
static const char *messages[] = {
      "No error",
      "General error",
      "Too small",
      "Too large",
      "Illegal parameter",
      "Interrupt handler not installed",
      "Flash initialisation failed"
};

/**
 * Get USBDM error code
 *
 * @return  err Error code
 */
ErrorCode getError() {
   return errorCode;
}

/**
 * Get error message from error code or last error if not provided
 *
 * @param  err Error code
 *
 * @return Pointer to static string
 */
const char *getErrorMessage(ErrorCode err) {
   if (err>(sizeof(messages)/sizeof(messages[0]))) {
      return "Unknown error";
   }
   return messages[err];
}

#ifdef DEBUG_BUILD
/**
 * Check for error code being set (drastically!)
 * This routine does not return if there is an error
 */
ErrorCode checkError() {
   while (errorCode != E_NO_ERROR) {
      const char *msg = getErrorMessage();
      puts(msg);
      __BKPT();
   }
   return errorCode;
}
#endif

} // end namespace USBDM
