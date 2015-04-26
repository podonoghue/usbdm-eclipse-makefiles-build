/*! \file
   \brief Common Routines for programming Flash

 * FlashProgrammerCommon.cpp
 *
   \verbatim
   Copyright (C) 2008  Peter O'Donoghue

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
+============================================================================================
| Revision History
+============================================================================================
| 29 Mar 15 | Refactored mostly from Clocktrimming.cpp                        - pgo 4.10.7.10 
+-----------+--------------------------------------------------------------------------------
| 04 Nov 12 | Added writeClockRegister()                                      - pgo 4.10.4 
+============================================================================================
\endverbatim
*/

#include <math.h>

#include "UsbdmTclInterpreterFactory.h"
#include "FlashProgrammerCommon.h"
#include "TargetDefines.h"
#include "Utils.h"
#include "Names.h"

FlashProgrammerCommon::FlashProgrammerCommon() {
   LOGGING_E;
   flashReady = false;
}

FlashProgrammerCommon::~FlashProgrammerCommon() {
   LOGGING_E;
}

USBDM_ErrorCode FlashProgrammerCommon::setTargetInterface(BdmInterfacePtr bdmInterface) {
   this->bdmInterface = bdmInterface;
   return BDM_RC_OK;
}

//=======================================================================
// Initialises TCL support for current target
//
USBDM_ErrorCode FlashProgrammerCommon::initTCL(void) {
   LOGGING;

   // Set up TCL interpreter only once
   if (tclInterpreter != NULL) {
      return PROGRAMMING_RC_OK;
   }
   tclInterpreter = UsbdmTclInterperFactory::createUsbdmTclInterper(bdmInterface);
   if (tclInterpreter == NULL) {
      log.error("No TCL interpreter\n");
      return PROGRAMMING_RC_ERROR_TCL_SCRIPT;
   }
   // Run initial TCL script (loads routines)
   TclScriptConstPtr script = parameters.getFlashScripts();
   if (!script) {
      log.error("No TCL script found\n");
      return PROGRAMMING_RC_ERROR_TCL_SCRIPT;
   }
#if defined(LOG) && 0
   log.print(script->toString().c_str());
#endif
   USBDM_ErrorCode rc = runTCLScript(script);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("runTCLScript() failed\n");
      return rc;
   }
   return PROGRAMMING_RC_OK;
}

//=======================================================================
//  Release the current TCL interpreter
//
USBDM_ErrorCode FlashProgrammerCommon::releaseTCL(void) {
   LOGGING;
   tclInterpreter.reset();
   return PROGRAMMING_RC_OK;
}

//=======================================================================
// Executes a TCL script in the current TCL interpreter
//
USBDM_ErrorCode FlashProgrammerCommon::runTCLScript(TclScriptConstPtr script) {
   LOGGING;
   if (tclInterpreter == NULL) {
      log.error("No TCL Interpreter\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   int rc = tclInterpreter->evalTclScript(script->getScript().c_str());
   const char *result = tclInterpreter->getTclResult();
   if ((result != NULL) && (*result != '\0')) {
      // Error return
      log.error("Result = \'%s\'\n", result);
      return PROGRAMMING_RC_ERROR_TCL_SCRIPT;
   }
   if (rc != 0) {
      // Unexpected failure!
      log.error("Failed\n");
      log.error("%s", script->toString().c_str());
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   return PROGRAMMING_RC_OK;
}

//=======================================================================
// Executes a TCL command previously loaded in the TCL interpreter
//
USBDM_ErrorCode FlashProgrammerCommon::runTCLCommand(const char *command) {
   LOGGING;
   log.print("Command = '%s'\n", command);
   if (tclInterpreter == NULL) {
      log.error("No TCL Interpreter\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   USBDM_ErrorCode rc = tclInterpreter->evalTclScript(command);
   if (rc != BDM_RC_OK) {
      log.error("Failed - rc = %d (%s)\n", rc, USBDM_GetErrorString(rc));
   }
   return rc;
}

//=======================================================================
//! Set device data for flash operations
//!
//! @param theParameters   -   data describing the device
//!
//! @return error code see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammerCommon::setDeviceData(const DeviceData &theParameters) {
   LOGGING_Q;
   currentFlashProgram.reset();
   parameters = theParameters;
   log.print("Target=%s\n", parameters.getTargetName().c_str());
   releaseTCL();
   initTCL();
   return PROGRAMMING_RC_OK;
}

//=======================================================================
//! Get device data for flash operations
//!
//! @return the parameters previously set
//!
DeviceData* FlashProgrammerCommon::getDeviceData() {
   return &parameters;
}

//! Clock register write with retry
//!
//! @param addr : clock register address
//! @param data : byte to write
//!
//! @return BDM_RC_OK => success
//!
//! @note writes are retried after a re-connect to cope
//!  with a possible clock speed change.
//!
USBDM_ErrorCode writeClockRegister(uint32_t addr, uint8_t data) {
   LOGGING_Q;
   USBDM_ErrorCode rc;

   rc = USBDM_WriteMemory(1,1,addr,&data);
   if (rc != BDM_RC_OK) {
      log.print("Failed write 0x%04X <= 0x%02X) - retrying\n", addr, data);
      rc = USBDM_Connect();
      if (rc == BDM_RC_OK) {
         rc = USBDM_WriteMemory(1,1,addr,&data);
         if (rc != BDM_RC_OK) {
         }
      }
   }
   if (rc != BDM_RC_OK) {
      log.print("Failed write 0x%04X <= 0x%02X), rc = %s\n", addr, data, USBDM_GetErrorString(rc));
   }
   return rc;
}

//! Configures the ICSCG target clock
//!
//! @param busFrequency    - Resulting BDM frequency after clock adjustment
//! @param clockParameters - Describes clock settings to use
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note Assumes that connection with the target has been established so
//!       reports any errors as PROGRAMMING_RC_ERROR_FAILED_CLOCK indicating
//!       a problem programming the target clock.
//!
USBDM_ErrorCode FlashProgrammerCommon::configureICS_Clock(unsigned long         *busFrequency,
                                                    ICS_ClockParameters_t *clockParameters){
   LOGGING_E;

   const uint32_t ICSC1   = parameters.getClockAddress();
   const uint32_t ICSC2   = parameters.getClockAddress()+1;
   const uint32_t ICSTRIM = parameters.getClockAddress()+2;
   const uint32_t ICSSC   = parameters.getClockAddress()+3;

   unsigned long bdmFrequency;

   log.print("ICS Clock: Ad=0x%08X, C1=0x%02X, C2=0x%02X, SC=0x%02X\n",
           parameters.getClockAddress(),
           clockParameters->icsC1,
           clockParameters->icsC2,
           clockParameters->icsSC
           );

   flashReady = FALSE; // Not configured for Flash access

   // ToDo - Review order of writes & need for re-connect()
   if (writeClockRegister(ICSTRIM, clockParameters->icsTrim) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_Connect() != BDM_RC_OK) {// re-connect after possible bus speed change
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (writeClockRegister(ICSC1, clockParameters->icsC1) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (writeClockRegister(ICSC2, clockParameters->icsC2) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_Connect() != BDM_RC_OK) { // re-connect after possible bus speed change - no delay
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (writeClockRegister(ICSSC, clockParameters->icsSC) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   milliSleep(100);
   if (USBDM_Connect() != BDM_RC_OK) { // re-connect after possible FLL change
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_GetSpeed(&bdmFrequency) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   bdmFrequency *= 1000; // Convert to Hz
   *busFrequency = bdmFrequency*parameters.getBDMtoBUSFactor();
   log.print("BDM Speed = %ld kHz, Bus Speed = %ld kHz\n",
         bdmFrequency/1000, *busFrequency/1000);
   return PROGRAMMING_RC_OK;
}

//! Configures the ICGCG target clock
//!
//! @param busFrequency    - Resulting BDM frequency after clock adjustment
//! @param clockParameters - Describes clock settings to use
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note Assumes that connection with the target has been established so
//!       reports any errors as PROGRAMMING_RC_ERROR_FAILED_CLOCK indicating
//!       a problem programming the target clock.
//!
USBDM_ErrorCode FlashProgrammerCommon::configureICG_Clock(unsigned long         *busFrequency,
                                                    ICG_ClockParameters_t *clockParameters){
   LOGGING_E;

   const uint32_t ICGC1    = parameters.getClockAddress();
   const uint32_t ICGC2    = parameters.getClockAddress()+1;
// const uint32_t ICGS1    = parameters.getClockAddress()+2;
// const uint32_t ICGS2    = parameters.getClockAddress()+3;
// const uint32_t ICGFLTU  = parameters.getClockAddress()+4;
// const uint32_t ICGFLTL  = parameters.getClockAddress()+5;
   const uint32_t ICGTRIM  = parameters.getClockAddress()+6;

   unsigned long bdmFrequency;

   log.print("ICG Clock: Ad=0x%4.4X, C1=0x%02X, C2=0x%02X\n",
           parameters.getClockAddress(),
           clockParameters->icgC1,
           clockParameters->icgC2
           );
   flashReady = FALSE; // Not configured for Flash access

   // ToDo - Review order of writes & need for re-connect()
   if (writeClockRegister(ICGTRIM, clockParameters->icgTrim) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_Connect() != BDM_RC_OK) { // re-connect after possible bus speed change
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (writeClockRegister(ICGC1, clockParameters->icgC1) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (writeClockRegister(ICGC2, clockParameters->icgC2) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   milliSleep(100);
   if (USBDM_Connect() != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_GetSpeed(&bdmFrequency) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   bdmFrequency *= 1000; // Convert to Hz
   *busFrequency = bdmFrequency*parameters.getBDMtoBUSFactor();
   log.print("BDM Speed = %ld kHz, Bus Speed = %ld kHz\n",
         bdmFrequency/1000, *busFrequency/1000);
   return PROGRAMMING_RC_OK;
}

//! Configures the MCGCG target clock
//!
//! @param busFrequency    - Resulting BDM frequency after clock adjustment
//! @param clockParameters - Describes clock settings to use
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note Assumes that connection with the target has been established so
//!       reports any errors as PROGRAMMING_RC_ERROR_FAILED_CLOCK indicating
//!       a problem programming the target clock.
//!
USBDM_ErrorCode FlashProgrammerCommon::configureMCG_Clock(unsigned long         *busFrequency,
                                                    MCG_ClockParameters_t *clockParameters){
   LOGGING_E;

   const uint32_t MCGC1    = parameters.getClockAddress();
   const uint32_t MCGC2    = parameters.getClockAddress()+1;
   const uint32_t MCGTRIM  = parameters.getClockAddress()+2;
   const uint32_t MCGSC    = parameters.getClockAddress()+3;
   const uint32_t MCGC3    = parameters.getClockAddress()+4;
   const uint32_t MCGT     = parameters.getClockAddress()+5;

   unsigned long bdmFrequency;

   log.print("MCG Clock: Ad=0x%08X, C1=0x%02X, C2=0x%02X, C3=0x%02X, SC=0x%02X, CT/C4=0x%02X\n",
           parameters.getClockAddress(),
           clockParameters->mcgC1,
           clockParameters->mcgC2,
           clockParameters->mcgC3,
           clockParameters->mcgSC,
           clockParameters->mcgCT
           );

   flashReady = FALSE; // Not configured for Flash access

   // ToDo - Review order of writes & need for re-connect()
   if (writeClockRegister(MCGTRIM, clockParameters->mcgTrim) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_Connect() != BDM_RC_OK) { // re-connect after possible bus speed change
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (writeClockRegister(MCGC1, clockParameters->mcgC1) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (writeClockRegister(MCGSC, clockParameters->mcgSC) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (writeClockRegister(MCGC2, clockParameters->mcgC2) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_Connect() != BDM_RC_OK) { // re-connect after possible bus speed change
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (writeClockRegister(MCGC3, clockParameters->mcgC3) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if ((parameters.getClockType() != S08MCGV1) &&
       (writeClockRegister(MCGT, clockParameters->mcgCT) != BDM_RC_OK)) {
         return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   milliSleep(100);
   if (USBDM_Connect() != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_GetSpeed(&bdmFrequency) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   bdmFrequency *= 1000; // Convert to Hz
   *busFrequency = bdmFrequency*parameters.getBDMtoBUSFactor();
   log.print("BDM Speed = %ld kHz, Bus Speed = %ld kHz\n",
         bdmFrequency/1000, *busFrequency/1000);
   return PROGRAMMING_RC_OK;
}

//! Configures the External target clock
//!
//! @param busFrequency    - Resulting BDM frequency after clock adjustment (Hz)
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammerCommon::configureExternal_Clock(unsigned long  *busFrequency){
   LOGGING_E;
   unsigned long bdmFrequency;

   flashReady = FALSE; // Not configured for Flash access

   // Just connect at whatever speed
   if (USBDM_Connect() != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   if (USBDM_GetSpeed(&bdmFrequency) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   bdmFrequency *= 1000; // Convert to Hz
   *busFrequency = bdmFrequency*parameters.getBDMtoBUSFactor();
   log.print("BDM Speed = %ld kHz, Bus Speed = %ld kHz\n",
         bdmFrequency/1000, *busFrequency/1000);
   return PROGRAMMING_RC_OK;

}

//! \brief Configures the target clock appropriately for flash programming
//!        The speed would be the maximum safe value for an untrimmed target
//!
//! @param busFrequency    - Resulting BDM frequency after clock adjustment \n
//!                          For a HCS08/CFV1 with CLKSW=1 this will be the bus frequency
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammerCommon::configureTargetClock(unsigned long  *busFrequency) {
   LOGGING_E;

   //! ICSCG parameters for flash programming (Maximum safe speed untrimmed 4/8MHz)
   static const ICS_ClockParameters_t ICS_FlashSpeedParameters = {
         // bdm clock = reference clock * 512/1024
         /* .icsC1   = */ 0x04, // IREFS
         /* .icsC2   = */ 0x40, // BDIV=/2
         /* .icsTrim = */ 0x80, // TRIM=nominal
         /* .icsSC   = */ 0x00, // DRS=0,DMX32=0,FTRIM=0
   };
   //! ICSCG parameters for flash programming (Maximum safe speed untrimmed 4/8MHz)
   static const ICS_ClockParameters_t ICSV4_FlashSpeedParameters = {
         // bdm clock = reference clock * 512/1024
         /* .icsC1   = */ 0x04, // IREFS
         /* .icsC2   = */ 0x20, // BDIV=/2
         /* .icsTrim = */ 0x80, // TRIM=nominal
         /* .icsSC   = */ 0x00, // DRS=0,DMX32=0,FTRIM=0
   };
   //! ICGCG parameters for flash programming
   static const ICG_ClockParameters_t ICG_FlashSpeedParameters = {
         // bdm clock = 64*MFDt*reference clock/(7*RDFt) = 64*14*refClk/(7*2*2) = 32*refClk
         /* .icgC1     = */ 0x48, // CLKS=01, RANGE=1
         /* .icgC2     = */ 0x51, // MFD=5, RFD=1
         /* .icgFilter = */ 0x00, // Not used
         /* .icgTrim   = */ 0x80, // TRIM=128
   };
   //! ICGCG parameters for flash programming 4/8 MHz
   static const MCG_ClockParameters_t MCG_FlashSpeedParameters = {
         // bdm clock = reference clock * 1024/2
         /* .mcgC1   = */ 0x04, // IREFS
         /* .mcgC2   = */ 0x40, // BDIV=/2
         /* .mcgC3   = */ 0x01, // VDIV=x4 (not used)
         /* .mcgTrim = */ 0x80, // TRIM=nominal
         /* .mcgSC   = */ 0x00, // FTRIM=0
         /* .mcgCT   = */ 0x00, // DMX32=0, DRS=0
   };

   ICS_ClockParameters_t   ICS_SpeedParameters   = ICS_FlashSpeedParameters;
   ICS_ClockParameters_t   ICSV4_SpeedParameters = ICSV4_FlashSpeedParameters;
   ICG_ClockParameters_t   ICG_SpeedParameters   = ICG_FlashSpeedParameters;
   MCG_ClockParameters_t   MCG_SpeedParameters   = MCG_FlashSpeedParameters;

//   log.print("Configuring Target clock\n");

   switch (parameters.getClockType()) {
      case CLKEXT:
      case CLKINVALID:
         return configureExternal_Clock(busFrequency);
      case S08ICGV1:
      case S08ICGV2:
      case S08ICGV3:
      case S08ICGV4:
         // Program clock for approx. 8 MHz
         return configureICG_Clock(busFrequency, &ICG_SpeedParameters);
      case S08ICSV1:
      case S08ICSV2:
      case S08ICSV2x512:
      case S08ICSV3:
      case RS08ICSV1:
      case RS08ICSOSCV1:
         // Program clock for approx. 4/8 MHz
         return configureICS_Clock(busFrequency, &ICS_SpeedParameters);
      case S08ICSV4:
         // Program clock for approx. 4/8 MHz
         return configureICS_Clock(busFrequency, &ICSV4_SpeedParameters);
      case S08MCGV1:
      case S08MCGV3:
         // Program clock for approx. 4/8 MHz
         return configureMCG_Clock(busFrequency, &MCG_SpeedParameters);
         break;
      case S08MCGV2:
         // Program clock for approx. 8 MHz
         MCG_SpeedParameters.mcgCT = 0x01; // DRS = 1
         return configureMCG_Clock(busFrequency, &MCG_SpeedParameters);
         break;
      case MKMCGV1:
         return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
         break;
   }
   return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
}

//!  Determines the trim value for the target internal clock.
//!  The target clock is left trimmed for a bus freq. of targetBusFrequency.
//!
//!     Target clock has been suitably configured.
//!
//!  @param      trimAddress           Address of trim register.
//!  @param      targetBusFrequency    Target Bus Frequency to trim to.
//!  @param      returnTrimValue       Resulting trim value (9-bit number)
//!  @param      measuredBusFrequency  Resulting Bus Frequency
//!  @param      do9BitTrim            True to do 9-bit trim (rather than 8-bit)
//!
//!  @return
//!   == \ref PROGRAMMING_RC_OK  => Success \n
//!   != \ref PROGRAMMING_RC_OK  => Various errors
//!
USBDM_ErrorCode FlashProgrammerCommon::trimTargetClock(uint32_t       trimAddress,
                                                 unsigned long  targetBusFrequency,
                                                 uint16_t      *returnTrimValue,
                                                 unsigned long *measuredBusFrequency,
                                                 int            do9BitTrim){
   LOGGING;
   uint8_t          mask;
   uint8_t          trimMSB, trimLSB, trimCheck;
   int              trimValue;
   int              maxRange;
   int              minRange;
   unsigned         long bdmSpeed;
   int              index;
   USBDM_ErrorCode  rc = PROGRAMMING_RC_OK;

#if TARGET == RS08
   mask = RS08_BDCSCR_CLKSW;
#elif TARGET == HCS08
   mask = HC08_BDCSCR_CLKSW;
#elif TARGET == HCS12
   mask = HC12_BDMSTS_CLKSW;
#elif TARGET == CFV1
   mask = CFV1_XCSR_CLKSW;
#endif

   unsigned long BDMStatusReg;
   rc = USBDM_ReadStatusReg(&BDMStatusReg);
   if ((BDMStatusReg&mask) == 0) {
      log.print("Setting CLKSW\n");
      BDMStatusReg |= mask;
#if TARGET == CFV1
      // Make sure we don't accidently do a mass erase
      mask &= ~CFV1_XCSR_ERASE;
#endif
      rc = USBDM_WriteControlReg(BDMStatusReg);
      rc = USBDM_Connect();
   }
   static const int maxTrim        = 505;   // Maximum acceptable trim value
   static const int minTrim        =   5;   // Minimum acceptable trim value
   static const int SearchOffset   =   8;   // Linear sweep range is +/- this value
   static const unsigned char zero =   0;
   const unsigned long targetBDMFrequency = targetBusFrequency/parameters.getBDMtoBUSFactor();
   int numAverage;     // Number of times to repeat measurements

   double sumX          = 0.0;
   double sumY          = 0.0;
   double sumXX         = 0.0;
   double sumYY         = 0.0;
   double sumXY         = 0.0;
   double num           = 0.0;
   double alpha, beta;
   double trimValueF;

   log.print("targetBusFrequency=%ld, targetBDMFrequency=%ld)\n", targetBusFrequency, targetBDMFrequency);

   flashReady = FALSE; // Not configured for Flash access

   // Set safe defaults
   *returnTrimValue      = 256;
   *measuredBusFrequency = 10000;
   trimMSB               = 0;

   // Set LSB trim value = 0
   if (writeClockRegister(trimAddress+1, zero) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_WRITE;
   }
   // Initial binary search (MSB only)
   for (mask = 0x80; mask > 0x0; mask>>=1) {
      trimMSB |= mask;
      // Set trim value (MSB only)
      if (writeClockRegister(trimAddress, trimMSB) != BDM_RC_OK) {
         return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
      // Check target speed
      if (USBDM_Connect() != BDM_RC_OK) {
         return PROGRAMMING_RC_ERROR_BDM_CONNECT;
      }
      if (USBDM_GetSpeed(&bdmSpeed) != BDM_RC_OK) {
         return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
      bdmSpeed *= 1000; // convert to Hz

    log.print("Binary search: trimMSB=0x%02X (%d), bdmSpeed=%ld%c\n",
            trimMSB, trimMSB, bdmSpeed, (bdmSpeed<targetBDMFrequency)?'-':'+');

      // Adjust trim value
      if (bdmSpeed<targetBDMFrequency) {
         trimMSB &= ~mask; // too slow
      }
      if (trimMSB > maxTrim/2) {
         trimMSB = maxTrim/2;
      }
      if (trimMSB < minTrim/2) {
         trimMSB = minTrim/2;
      }
   }

   // Binary search value is middle of range to sweep

   trimValue = trimMSB<<1;  // Convert to 9-bit value

   // Linear sweep +/-SEARCH_OFFSET, starting at higher freq (smaller Trim)
   // Range is constrained to [minTrim..maxTrim]

   maxRange = trimValue + SearchOffset;
   if (maxRange > maxTrim) {
      maxRange = maxTrim;
   }
   minRange = trimValue - SearchOffset;
   if (minRange < minTrim) {
      minRange = minTrim;
   }
//   log.print("trimTargetClock(): Linear sweep, f=%6ld    \n"
//                   "trimTargetClock():    Trim       frequency \n"
//                   "========================================== \n",
//                   targetBDMFrequency/1000);

   if (do9BitTrim) {
      numAverage = 2;
   }
   else {
      numAverage = 4;
   }
   for(trimValue=maxRange; trimValue>=minRange; trimValue--) {
      trimLSB = trimValue&0x01;
      trimMSB = (uint8_t)(trimValue>>1);
      if (do9BitTrim) {
         // Write trim LSB
         if (writeClockRegister(trimAddress+1, trimLSB) != BDM_RC_OK)
            return PROGRAMMING_RC_ERROR_BDM_WRITE;
         if (USBDM_ReadMemory(1, 1, trimAddress+1,   &trimCheck) != BDM_RC_OK)
            return PROGRAMMING_RC_ERROR_BDM_WRITE;
         if ((trimCheck&0x01) != trimLSB)
            return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
      else if (trimValue&0x01) {
         // skip odd trim values if 8-bit trim
         continue;
      }
      // Write trim MSB
      if (writeClockRegister(trimAddress,  trimMSB) != BDM_RC_OK) {
         return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
      if (USBDM_ReadMemory(1, 1, trimAddress,   &trimCheck) != BDM_RC_OK) {
         return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
      if (trimCheck != trimMSB) {
         return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
      //milliSleep(100);
      // Measure sync multiple times
      for(index=numAverage; index>0; index--) {
         // Check target speed
         if (USBDM_Connect() != BDM_RC_OK)
            return PROGRAMMING_RC_ERROR_BDM_CONNECT;
         if (USBDM_GetSpeedHz(&bdmSpeed) != BDM_RC_OK)
            return PROGRAMMING_RC_ERROR_BDM_CONNECT;
         sumX  += trimValue;
         sumY  += bdmSpeed;
         sumXX += trimValue*trimValue;
         sumYY += bdmSpeed*bdmSpeed;
         sumXY += bdmSpeed*trimValue;
         num   += 1.0;
//         log.print("trimTargetClock(): %6d    %10ld %10ld\n", trimValue, bdmSpeed, targetBDMFrequency-bdmSpeed);
      }
   }
   for(trimValue=minRange; trimValue<=maxRange; trimValue++) {
      trimLSB = trimValue&0x01;
      trimMSB = (uint8_t)(trimValue>>1);
      if (do9BitTrim) {
         // Write trim LSB
         if (writeClockRegister(trimAddress+1, trimLSB) != BDM_RC_OK) {
            return PROGRAMMING_RC_ERROR_BDM_WRITE;
         }
         if (USBDM_ReadMemory(1, 1, trimAddress+1,   &trimCheck) != BDM_RC_OK) {
            return PROGRAMMING_RC_ERROR_BDM_WRITE;
         }
         if ((trimCheck&0x01) != trimLSB) {
            return PROGRAMMING_RC_ERROR_BDM_WRITE;
         }
      }
      else if (trimValue&0x01) {
         // skip odd trim values if 8-bit trim
         continue;
      }
      // Write trim MSB
      if (writeClockRegister(trimAddress, trimMSB) != BDM_RC_OK) {
         return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
      if (USBDM_ReadMemory(1, 1, trimAddress,   &trimCheck) != BDM_RC_OK) {
         return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
      if (trimCheck != trimMSB) {
         return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
      //milliSleep(100);
      // Measure sync multiple times
      for(index=numAverage; index>0; index--) {
         // Check target speed
         if (USBDM_Connect() != BDM_RC_OK) {
            return PROGRAMMING_RC_ERROR_BDM_CONNECT;
         }
         if (USBDM_GetSpeedHz(&bdmSpeed) != BDM_RC_OK) {
            return PROGRAMMING_RC_ERROR_BDM_CONNECT;
         }
         sumX  += trimValue;
         sumY  += bdmSpeed;
         sumXX += trimValue*trimValue;
         sumYY += bdmSpeed*bdmSpeed;
         sumXY += bdmSpeed*trimValue;
         num   += 1.0;
//         log.print("trimTargetClock(): %6d    %10ld %10ld\n", trimValue, bdmSpeed, targetBDMFrequency-bdmSpeed);
      }
   }

//   log.print("N=%f, sumX=%f, sumXX=%f, sumY=%f, sumYY=%f, sumXY=%f\n",
//                    num, sumX, sumXX, sumY, sumYY, sumXY);

   // Calculate linear regression co-efficients
   beta  = (num*sumXY-sumX*sumY)/(num*sumXX-sumX*sumX);
   alpha = (sumY-beta*sumX)/num;

   // Estimate required trim value
   trimValueF = ((targetBDMFrequency-alpha)/beta);

   if ((trimValueF <= 5.0) || (trimValue >= 505.0)) { // resulted in extreme value
      trimValueF = 256.0;                             // replace with 'Safe' trim value
      rc = PROGRAMMING_RC_ERROR_TRIM;
   }
   trimValue = (int)round(trimValueF);
   trimMSB   = trimValue>>1;
   trimLSB   = trimValue&0x01;

//   log.print("alpha= %f, beta= %f, trimF= %f, trimMSB= %d (0x%02X), trimLSB= %d\n",
//           alpha, beta, trimValueF, trimMSB, trimMSB, trimLSB);

//   log.print("trimTargetClock() Result: trim=0x%3.3x (%d), measured bdmSpeed=%ld\n",
//           savedTrimValue, savedTrimValue, bestFrequency);

   *returnTrimValue  = trimValue;

   // Set trim value (LSB first)
   if ((do9BitTrim && (writeClockRegister(trimAddress+1, trimLSB) != BDM_RC_OK)) ||
       (writeClockRegister(trimAddress, trimMSB) != BDM_RC_OK)) {
      return PROGRAMMING_RC_ERROR_BDM_WRITE;
   }
   // Check connection at that speed
   if (USBDM_Connect() != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   if (USBDM_GetSpeedHz(&bdmSpeed) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   *measuredBusFrequency = bdmSpeed*parameters.getBDMtoBUSFactor();
   return rc;
}

USBDM_ErrorCode FlashProgrammerCommon::trimICS_Clock(ICS_ClockParameters_t *clockParameters) {
   LOGGING;
   static const ICS_ClockParameters_t ICS_LowSpeedParameters = {
         // bus clock = reference clock * (512,1024,512)/8/2
         //           = (32,64,32)*refClk
         //           ~ (1,2,1) MHz
         /* .icsC1   = */ 0x04, // IREFS
         /* .icsC2   = */ 0xC0, // BDIV=/8
         /* .icsTrim = */ 0x80, // TRIM=default
         /* .icsSC   = */ 0x00, // DRS=0,DMX32=0,FTRIM=0
   };
   static const ICS_ClockParameters_t ICSV4_LowSpeedParameters = {
         // bus clock = reference clock * (512,1024,512)/8/2
         //           = (32,64,32)*refClk
         //           ~ (1,2,1) MHz
         /* .icsC1   = */ 0x04, // IREFS
         /* .icsC2   = */ 0x60, // BDIV=/8
         /* .icsTrim = */ 0x80, // TRIM=default
         /* .icsSC   = */ 0x00, // LOLIE=0, CME=0, SCFTRIM=0
   };
   uint32_t           ICSTRIM             = parameters.getClockAddress()+2;
   unsigned int  clockMultiplier;
   unsigned long targetBusFrequency;
   unsigned long originalBusFrequency;
   unsigned long measuredBusFrequency;
   uint16_t           trimValue;
   USBDM_ErrorCode rc;

   switch (parameters.getClockType()) {
      case S08ICSV1:
      case S08ICSV3:
      case RS08ICSV1:
      case RS08ICSOSCV1:
      case S08ICSV2x512:
         clockMultiplier = 512;
         *clockParameters = ICS_LowSpeedParameters;
         break;
      case S08ICSV2:
          clockMultiplier = 1024;
          *clockParameters = ICS_LowSpeedParameters;
          break;
      case S08ICSV4:
         clockMultiplier = 1024;
         *clockParameters = ICSV4_LowSpeedParameters;
         break;
      default:
         return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
   }

   targetBusFrequency = parameters.getClockTrimFreq()*(clockMultiplier/8/2);

   log.print("TrimF = %.2f kHz, clock Multiplier=%d => Trim bus Freq=%.2f kHz\n",
         parameters.getClockTrimFreq()/1000.0, clockMultiplier/8/2, targetBusFrequency/1000.0);

   // Program clock for a low speed to improve accuracy of trimming
   rc = configureICS_Clock(&originalBusFrequency, clockParameters);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   log.print("Clock Freq = %4.2f kHz, Bus Freq=%4.2f kHz\n",
         parameters.getClockTrimFreq()/1000.0, targetBusFrequency/1000.0);

   rc = FlashProgrammerCommon::trimTargetClock(ICSTRIM, targetBusFrequency, &trimValue, &measuredBusFrequency, TRUE);

   log.print("rc=%d, Desired Freq = %.2f kHz,"
         " Meas. Freq=%.2f kHz, Trim=0x%02X/%1.1X\n",
         rc,
         parameters.getClockTrimFreq()/1000.0,
         (measuredBusFrequency/(clockMultiplier/16))/1000.0,
         trimValue>>1, trimValue&0x01);

   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   // Update trim value
   clockParameters->icsTrim  = trimValue>>1;
   clockParameters->icsSC   |= trimValue&0x01;

   return rc;
}

USBDM_ErrorCode FlashProgrammerCommon::trimMCG_Clock(MCG_ClockParameters_t *clockParameters) {
   LOGGING_E;

   static const MCG_ClockParameters_t MCG_LowSpeedParameters = {
         // bus clock = reference clock * (512,1024)/8/2
         //           = (32,64)*refClk (~32.5kHz)
         //           ~ (1,2) MHz
         /* .mcgC1   = */ 0x04, // IREFS
         /* .mcgC2   = */ 0xC0, // BDIV=/8
         /* .mcgC3   = */ 0x01, // VDIV=x4 (not used)
         /* .mcgTrim = */ 0x80, // TRIM=default
         /* .mcgSC   = */ 0x00, // FTRIM=0
         /* .mcgCT   = */ 0x00, // DMX32=0, DRS=0
   };

   uint32_t MCGTRIM                = parameters.getClockAddress()+2;
   unsigned int  clockMultiplier;
   unsigned long targetBusFrequency;
   unsigned long originalBusFrequency;
   unsigned long measuredBusFrequency;
   uint16_t trimValue;
   USBDM_ErrorCode rc;

   switch (parameters.getClockType()) {
      case S08MCGV2:
      case S08MCGV3:
         clockMultiplier = 512;
         break;
      case S08MCGV1:
         clockMultiplier = 1024;
         break;
      default:
         return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
   }

   targetBusFrequency = parameters.getClockTrimFreq()*(clockMultiplier/8/2);

   *clockParameters = MCG_LowSpeedParameters;

   log.print("TrimF = %.2f kHz, clock Multiplier=%d => Trim bus Freq=%.2f kHz\n",
         parameters.getClockTrimFreq()/1000.0, (1024/8/2), targetBusFrequency/1000.0);

   // Program clock for a low speed to improve accuracy of trimming
   rc = configureMCG_Clock(&originalBusFrequency, clockParameters);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
//   log.print("trimMGCClock(Clock Freq = %.2f kHz, bus Freq = %.2f kHz)\n",
//           parameters.getClockTrimFreq()/1000.0, bdmFrequency/1000.0);

   rc = FlashProgrammerCommon::trimTargetClock(MCGTRIM, targetBusFrequency, &trimValue, &measuredBusFrequency, TRUE);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   log.print("Desired Freq = %.2f kHz, "
         "Meas. Freq=%.2f kHz, Trim=0x%02X/%1.1X\n",
         parameters.getClockTrimFreq()/1000.0,
         (measuredBusFrequency/(clockMultiplier/16))/1000.0,
         trimValue>>1, trimValue&0x01);

   // Update trim value
   clockParameters->mcgTrim  = trimValue>>1;
   clockParameters->mcgSC   |= trimValue&0x01;

   return rc;
}

USBDM_ErrorCode FlashProgrammerCommon::trimICG_Clock(ICG_ClockParameters_t *clockParameters) {
   LOGGING_E;

   static const ICG_ClockParameters_t ICG_LowSpeedParameters = {
         // bus clock = 64*MFDt*reference clock/(7*RDFt)
         //           = 64*14*refClk/(7*16*2)
         //           = 4*refClk  ~ 1MHz
         /* .icgC1     = */ 0x48, // CLKS=01, RANGE=1
         /* .icgC2     = */ 0x54, // MFD=4, RFD=9
         /* .icgFilter = */ 0x00, // Not used
         /* .icgTrim   = */ 0x80, // TRIM=128
   };
   uint32_t ICGTRIM                 = parameters.getClockAddress()+6;
   unsigned long targetBusFrequency = parameters.getClockTrimFreq()*4;
   unsigned long originalBusFrequency;
   unsigned long measuredBusFrequency;
   uint16_t trimValue;
   USBDM_ErrorCode rc;

   *clockParameters = ICG_LowSpeedParameters;

   // Program clock for a low speed to improve accuracy of trimming
   rc = configureICG_Clock(&originalBusFrequency, clockParameters);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   log.print("TrimF = %.2f kHz, clock Multiplier=%d => Trim bus Freq=%.2f kHz\n",
         parameters.getClockTrimFreq()/1000.0, 4, targetBusFrequency/1000.0);

   rc = FlashProgrammerCommon::trimTargetClock(ICGTRIM, targetBusFrequency, &trimValue, &measuredBusFrequency, FALSE);

   log.print("Desired Freq = %.1f kHz, Meas. Freq=%.1f kHz, Trim=%02X\n",
         parameters.getClockTrimFreq()/1000.0,
         (measuredBusFrequency/4)/1000.0,
         trimValue>>1);

   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   // Update trim value (discard LSB)
   clockParameters->icgTrim = trimValue>>1;

   return rc;
}

//! Determines trim values for the target clock. \n
//! The values determined are written to the Flash image for later programming.
//!
//! @param flashImage - Flash image to be updated.
//!
//! @return error code see \ref USBDM_ErrorCode
//!
//! @note If the trim frequency indicated in parameters is zero then no trimming is done.
//!       This is not an error.
//!
USBDM_ErrorCode FlashProgrammerCommon::setFlashTrimValues(FlashImagePtr flashImage) {
   LOGGING_Q;
   ClockParameters clockTrimParameters;
   USBDM_ErrorCode rc;
   uint16_t  ftrimMergeValue;

   // Assume no trim or failure
   parameters.setClockTrimValue(0);

   // No trimming required
   if (parameters.getClockTrimFreq() == 0) {
      return PROGRAMMING_RC_OK;
   }

#if TARGET == RS08
   uint32_t NVTRIM_address  = parameters.getClockTrimNVAddress();
   uint32_t NVFTRIM_address = parameters.getClockTrimNVAddress()+1;
#else
   uint32_t NVFTRIM_address = parameters.getClockTrimNVAddress();
   uint32_t NVTRIM_address  = parameters.getClockTrimNVAddress()+1;
#endif

   switch (parameters.getClockType()) {
      case CLKEXT:
      case CLKINVALID:
         return PROGRAMMING_RC_OK;
      case S08ICGV1:
      case S08ICGV2:
      case S08ICGV3:
      case S08ICGV4:
         // 8-bit value (LSB ignored)
         rc = trimICG_Clock(&clockTrimParameters.icg);
         if (rc != PROGRAMMING_RC_OK)
            return rc;
         parameters.setClockTrimValue(clockTrimParameters.icg.icgTrim<<1);
         flashImage->setValue(parameters.getClockTrimNVAddress(),
                                         clockTrimParameters.icg.icgTrim);
         return PROGRAMMING_RC_OK;
      case S08ICSV1:
      case S08ICSV2:
      case S08ICSV3:
      case S08ICSV4:
      case RS08ICSV1:
      case RS08ICSOSCV1:
      case S08ICSV2x512:
         // 9-bit value
         rc = trimICS_Clock(&clockTrimParameters.ics);
         if (rc != PROGRAMMING_RC_OK) {
            return rc;
         }
         parameters.setClockTrimValue((clockTrimParameters.ics.icsTrim<<1)|
                                       (clockTrimParameters.ics.icsSC&0x01));
         flashImage->setValue(NVTRIM_address, clockTrimParameters.ics.icsTrim);
         // The FTRIM bit may be combined with other bits such as DMX32 or DRS
         ftrimMergeValue = flashImage->getValue(parameters.getClockTrimNVAddress());
         if (((ftrimMergeValue&0xFF) == 0xFF)||(ftrimMergeValue >= 0xFF00U)) {
            // Image location is unused or contains the unprogrammed FLASH value
            // So no value to merge trim with - clear all other bits
            ftrimMergeValue = 0x00;
         }
         log.print("Merging FTRIM with 0x%02X\n", ftrimMergeValue);
         flashImage->setValue(NVFTRIM_address, (ftrimMergeValue&~0x01)|(clockTrimParameters.ics.icsSC&0x01));
         return PROGRAMMING_RC_OK;
      case S08MCGV1:
      case S08MCGV2:
      case S08MCGV3:
         // 9-bit value
         rc = trimMCG_Clock(&clockTrimParameters.mcg);
         if (rc != PROGRAMMING_RC_OK) {
            return rc;
         }
         parameters.setClockTrimValue((clockTrimParameters.mcg.mcgTrim<<1)|
                                      (clockTrimParameters.mcg.mcgSC&0x01));
         flashImage->setValue(parameters.getClockTrimNVAddress()+1,
                                         clockTrimParameters.mcg.mcgTrim);
         flashImage->setValue(parameters.getClockTrimNVAddress(),
                                         clockTrimParameters.mcg.mcgSC&0x01);
         return PROGRAMMING_RC_OK;
      case MKMCGV1:
         return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
         break;
   }
   return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
}

//=======================================================================
//! Updates the memory image from the target flash Clock trim location(s)
//!
//! @param flashImage   = Flash image
//!
USBDM_ErrorCode FlashProgrammerCommon::dummyTrimLocations(FlashImagePtr flashImage) {
   LOGGING_Q;
   unsigned size  = 0;
   uint32_t start = 0;

   // Not using trim -> do nothing
   if ((parameters.getClockTrimNVAddress() == 0) ||
       (parameters.getClockTrimFreq() == 0)) {
      log.print("Not using trim, no adjustment to image\n");
      return PROGRAMMING_RC_OK;
   }
   switch (parameters.getClockType()) {
      case S08ICGV1:
      case S08ICGV2:
      case S08ICGV3:
      case S08ICGV4:
         start = parameters.getClockTrimNVAddress();
         size  = 2;
         break;
      case S08ICSV1:
      case S08ICSV2:
      case S08ICSV2x512:
      case S08ICSV3:
      case S08ICSV4:
      case S08MCGV1:
      case S08MCGV2:
      case S08MCGV3:
      case RS08ICSOSCV1:
      case RS08ICSV1:
         start = parameters.getClockTrimNVAddress();
         size  = 2;
         break;
      case CLKEXT:
      default:
         break;
   }
   if (size == 0) {
      return PROGRAMMING_RC_OK;
   }
   // Read existing trim information from target
   uint8_t data[10];
   USBDM_ErrorCode rc = USBDM_ReadMemory(1,size,start,data);
   if (rc != BDM_RC_OK) {
      log.print("Trim location read failed\n");
      return PROGRAMMING_RC_ERROR_BDM_READ;
   }
   log.print("Modifying image[0x%06X..0x%06X]\n",
         start, start+size-1);
   // Update image
   for(uint32_t index=0; index < size; index++ ) {
      flashImage->setValue(start+index, data[index]);
   }
   return PROGRAMMING_RC_OK;
}

//! \brief Maps a Flash action vector to Text
//!
//! @param flashOperation => operation to describe
//!
//! @return pointer to static string buffer describing the flashOperation
//!
const char *FlashProgrammerCommon::getFlashOperationName(FlashOperation flashOperation) {
   switch (flashOperation) {
   case OpNone                             : return "OpNone";
   case OpSelectiveErase                   : return "OpSelectiveErase";
   case OpBlockErase                       : return "OpBlockErase";
   case OpBlankCheck                       : return "OpBlankCheck";
   case OpProgram                          : return "OpProgram";
   case OpVerify                           : return "OpVerify";
   case OpWriteRam                         : return "OpWriteRam";
   case OpPartitionFlexNVM                 : return "OpPartitionFlexNVM";
   case OpTiming                           : return "OpTiming";
   default: break;
   }
   return "Op???";
}


//! Probe RAM location
//!
//! @param memorySpace - Memory space and size of probe
//! @param address     - Address to probe
//!
//! @return BDM_RC_OK if successful
//!
USBDM_ErrorCode FlashProgrammerCommon::probeMemory(MemorySpace_t memorySpace, uint32_t address) {
   LOGGING_Q;
   static const uint8_t probe1[] = {0xA5, 0xF0,0xA5, 0xF0,};
   static const uint8_t probe2[] = {0x0F, 0x5A,0x0F, 0x5A,};
   uint8_t              probeResult1[sizeof(probe1)];
   uint8_t              probeResult2[sizeof(probe2)];
   uint8_t              savedData[sizeof(probe1)];
   bool                 savedDataValid = false;

   address &= ~((1<<(memorySpace&MS_SIZE))-1);
   USBDM_ErrorCode rc = BDM_RC_OK;
   do {
      if (bdmInterface->readMemory(memorySpace,memorySpace&MS_SIZE,address,savedData) != BDM_RC_OK) {
         rc = PROGRAMMING_RC_ERROR_BDM_READ;
         break;
      }
      savedDataValid = true;
      if (bdmInterface->writeMemory(memorySpace,memorySpace&MS_SIZE,address,probe1) != BDM_RC_OK) {
         rc = PROGRAMMING_RC_ERROR_BDM_WRITE;
         break;
      }
      if (bdmInterface->readMemory(memorySpace,memorySpace&MS_SIZE,address,probeResult1) != BDM_RC_OK) {
         rc = PROGRAMMING_RC_ERROR_BDM_READ;
         break;
      }
      if (bdmInterface->writeMemory(memorySpace,memorySpace&MS_SIZE,address,probe2) != BDM_RC_OK) {
         rc = PROGRAMMING_RC_ERROR_BDM_WRITE;
         break;
      }
      if (bdmInterface->readMemory(memorySpace,memorySpace&MS_SIZE,address,probeResult2) != BDM_RC_OK) {
         rc = PROGRAMMING_RC_ERROR_BDM_READ;
         break;
      }
      if ((memcmp(probe1, probeResult1, memorySpace&MS_SIZE) != 0) ||
          (memcmp(probe2, probeResult2, memorySpace&MS_SIZE) != 0)) {
         rc = PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
         break;
      }
   } while (0);

   if (savedDataValid) {
      bdmInterface->writeMemory(memorySpace,memorySpace&MS_SIZE,address,savedData);
   }

   if (rc != BDM_RC_OK) {
      log.error("RAM memory probe failed @%s:0x%08X, rc = %d (%s)\n", getMemSpaceName(memorySpace), address, rc, bdmInterface->getErrorString(rc));
      return rc;
   }
   return PROGRAMMING_RC_OK;
}

