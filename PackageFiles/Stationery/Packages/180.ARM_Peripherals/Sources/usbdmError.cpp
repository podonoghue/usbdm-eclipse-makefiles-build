/*
 * usbdmError.cpp
 *
 *  Created on: 8 Jun 2016
 *      Author: podonoghue
 */
#include "hardware.h"

namespace USBDM {

/** Last error set by USBDM code */
ErrorCode errorCode = E_NO_ERROR;

/** Table of error messages indexed by error code */
static const char *messages[] = {
      "No error",
      "Too small",
      "Too large",
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

}
