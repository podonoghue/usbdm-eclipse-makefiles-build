/*
 * usbdmError.cpp
 *
 *  Created on: 8 Jun 2016
 *      Author: podonoghue
 */
#include <stdio.h>
#include "hardware.h"

namespace USBDM {

/** Last error set by USBDM code */
ErrorCode errorCode = E_NO_ERROR;

/** Table of error messages indexed by error code */
static const char *messages[] = {
      "No error",
      "General error",
      "Too small",
      "Too large",
      "Illegal parameter",
      "Interrupt handler not installed",
};

/**
 * Get error message from error code or last
 * error if not provided
 *
 * @param  err Error code
 */
const char *getErrorMessage(ErrorCode err) {
   if (err>(sizeof(messages)/sizeof(messages[0]))) {
      return "Unknown error";
   }
   return messages[err];
}

/**
 * Check for error code being set (drastically!)
 * This routine does not return if there is an error
 */
void checkError() {
   while (errorCode != E_NO_ERROR) {
#ifdef DEBUG_BUILD
      const char *msg = getErrorMessage();
      puts(msg);
      __BKPT();
#endif
   }
}

} // end namespace USBDM
