/*! \file
   \brief Error code handling

   \verbatim
   USBDM
   Copyright (C) 2008-12  Peter O'Donoghue

   Based on
      Opensource BDM  - interface DLL

   which is based on
      TBDML interface DLL by
      Copyright (C) 2005  Daniel Malik

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\endverbatim

\verbatim
 Change History
+=============================================================================================
|  3 Jun 2015 | Moved to UsbdmSystem                                           - pgo - V4.11.1
|  4 May 2012 | Unified error code handling                                    - pgo - V4.9.5
+=============================================================================================
\endverbatim
*/
#include "USBDM_API.h"
#include "UsbdmSystem.h"

//! Error message string from Error #
static const char *const errorMessages[] = {
   /**  0 */ "No Error",
   /**  1 */ "Illegal parameters",
   /**  2 */ "General Fail (for compatibility)",
   /**  3 */ "BDM is Busy",
   /**  4 */ "Illegal BDM command",
   /**  5 */ "BDM has no connection to target",
   /**  6 */ "BDM Communication overrun",
   /**  7 */ "Illegal Command Response from target",
   /**  8 */ "BDM Open Failed - Unknown USB error",
   /**  9 */ "BDM Open Failed - Device may be open in another application",
   /** 10 */ "BDM Open Failed - Device driver may be missing or incorrect",
   /** 11 */ "BDM Open Failed - Device may have been removed",
   /** 12 */ "USB Retry OK",
   /** 13 */ "Target reset was detected",
   /** 14 */ "Not ready response (running?)",
   /** 15 */ "Target type is not supported by BDM",
   /** 16 */ "No BDM Tx routine was found",
   /** 17 */ "No BDM Rx routine was found",
   /** 18 */ "Target BDM Enable failed",
   /** 19 */ "Target reset pin timeout (fall)",
   /** 20 */ "Target BKGD pin timeout",
   /** 21 */ "Target SYNC timeout",
   /** 22 */ "Unable to determine target BDM speed",
   /** 23 */ "Wrong Flash programming mode",
   /** 24 */ "BDM Busy Flash Programming",
   /** 25 */ "Target Vdd not removed",
   /** 26 */ "Target Vdd not present",
   /** 27 */ "Vdd not controlled by BDM",
   /** 28 */ "Target reported - Error terminated bus cycle",
   /** 29 */ "USB connection with BDM has failed",
   /** 30 */ "Expected BDM command ACK missing",
   /** 31 */ "BDM Trimming of target clock failed",
   /** 32 */ "Feature not supported by BDM",
   /** 33 */ "Target reset pin timeout (rise)",

   // The following are used by additional USBDM code
   /** 34 */ "BDM Firmware version is incompatible with driver/program",
   /** 35 */ "Program is incompatible with DLL version",
   /** 36 */ "No suitable USBDM debug interface was located",
   /** 37 */ "Unmatched REPEAT-END_REPEAT in JTAG sequence",
   /** 38 */ "Unmatched CALL-RETURN in JTAG sequence",
   /** 39 */ "Unmatched IF-END_IF in JTAG sequence",
   /** 40 */ "Stack error in JTAG sequence",
   /** 41 */ "Illegal JTAG sequence",
   /** 42 */ "Target busy",
   /** 43 */ "Subroutine is too large to cache",
   /** 44 */ "USBDM device is not open",
   /** 45 */ "Unknown or not supported device",
   /** 46 */ "Device database error (device not found/incorrect)",
   /** 47 */ "ARM target failed to power up",
   /** 48 */ "ARM access error (illegal/readonly etc)",
   /** 49 */ "JTAG Chain contains too many devices (or open)",
   /** 50 */ "Device appears secured",
   /** 51 */ "ARM Data Parity error",
   /** 52 */ "ARM transaction Fault",
   /** 53 */ "Unexpected/invalid response from BDM",
   /** 54 */ "Memory access failed due to target in stop or wait state",
   /** 55 */ "Selected BDM not found (removed?)",
   /** 56 */ "Interface not initialised before use",
   /** 57 */ "Operation not supported for this target",
};

//! Error code returned by the various routines
static const char *programmingErrorMessages[] = {
   /** 101 */ "Illegal programming parameters",
   /** 102 */ "Target device does not agree with selected",
   /** 103 */ "Verification of Flash failed",
   /** 104 */ "General BDM error",
   /** 105 */ "Device or region is not blank or failed erase",
   /** 106 */ "No USBDM devices found",
   /** 107 */ "Failed to open USBDM device",
   /** 108 */ "Failed to connect to target",
   /** 109 */ "Failed to set target type",
   /** 110 */ "Failed to write to target",
   /** 111 */ "Failed to read from target",
   /** 112 */ "Failed to reset target",
   /** 113 */ "Trimming target clock failed",
   /** 114 */ "Target is secured",
   /** 115 */ "Flash command failed (Verify, Erase, Blank check or Program)",
   /** 116 */ "Failed to find a valid Flash Clock Divider (FCDIV) value",
   /** 117 */ "S-record has incorrect checksum",
   /** 118 */ "Failed setup of target clock (connection lost)",
   /** 119 */ "Internal program error - please report",
   /** 120 */ "S1S9 File open error",
   /** 121 */ "Access to PPAGE register failed",
   /** 122 */ "Access to EPAGE register failed",
   /** 123 */ "Target does not support SYNC and bus speed cannot be determined accurately",
   /** 124 */ "Unsupported operation or options for this chip",
   /** 125 */ "Execution of TCL script returned an error",
   /** 126 */ "Execution of TCL un-secure script returned an error",
   /** 127 */ "Execution of TCL pre-program script returned an error",
   /** 128 */ "Execution of TCL post-program script returned an error",
   /** 129 */ "Program data not within target Flash Memory",
   /** 130 */ "Illegal Flash Security value (will lock chip forever)",
   /** 130 */ "Failed to program FlexNVM configuration.\n"
              "  Device may already be configured",
};

//! Error code returned by the various routines
static const char *fileLoaderErrorMessages[] = {
   /** 201 */ "S-record checksum error",
   /** 202 */ "S-file unrecognised/unsupported line",
   /** 203 */ "Hex file failed to open",
   /** 204 */ "ELF file format error",
   /** 205 */ "Unknown file type (not ELF or SREC)",
   /** 206 */ "ELF file for wrong target",
};

/**
 * Maps an Error Code # to a string
 *
 * @param error Error number
 *
 * @return pointer to static string describing the error
 */
const char *UsbdmSystem::getErrorString(unsigned errorCode) {
   static const char unknownErrorMessage[] = "Unknown Error";
   const char *errorName = 0;
   errorCode &= ~BDM_RC_ERROR_HANDLED;

   if (errorCode >= SFILE_RC_FIRST_MESSAGE) {
      errorCode -= SFILE_RC_FIRST_MESSAGE;
      if (errorCode < sizeof(fileLoaderErrorMessages)/sizeof(fileLoaderErrorMessages[0])) {
         errorName = fileLoaderErrorMessages[errorCode];
      }
   }
   else if (errorCode >= PROGRAMMING_RC_ERROR_FIRST_MESSAGE) {
      errorCode -= PROGRAMMING_RC_ERROR_FIRST_MESSAGE;
      if (errorCode < sizeof(programmingErrorMessages)/sizeof(programmingErrorMessages[0])) {
         errorName = programmingErrorMessages[errorCode];
      }
   }
   else {
      if (errorCode < sizeof(errorMessages)/sizeof(errorMessages[0])) {
         errorName = errorMessages[errorCode];
      }
   }
   if (errorName == 0) {
      errorName = unknownErrorMessage;
   }
   return errorName;
}
