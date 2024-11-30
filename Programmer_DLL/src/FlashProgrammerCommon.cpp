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
#include <assert.h>

#include "UsbdmTclInterpreterFactory.h"
#include "FlashProgrammerCommon.h"
#include "TargetDefines.h"
#include "Utils.h"
#include "Names.h"

bool FlashProgrammerCommon::SetProgrammingMode::currentMode = false;

/**
 * Constructor
 */
FlashProgrammerCommon::FlashProgrammerCommon(DeviceData::EraseMethod defaultEraseMethod, DeviceData::ResetMethod defaultResetMethod) :
   flashReady(false),
   progressTimer(new ProgressTimer()),
   calculatedClockTrimValue(0),
   securityAreaCount(0),
   defaultEraseMethod(defaultEraseMethod),
   defaultResetMethod(defaultResetMethod),
   ramStart(0),
   ramEnd(0),
   securityNeedsSelectiveErase(false) {
   LOGGING_E;

   log.print("defaultResetMethod = %s\n", DeviceData::getResetMethodName(defaultResetMethod));
   log.print("defaultEraseMethod = %s\n", DeviceData::getEraseMethodName(defaultEraseMethod));
}

/**
 * Destructor
 */
FlashProgrammerCommon::~FlashProgrammerCommon() {
   LOGGING_E;
   releaseTCL();
   device.reset();
   bdmInterface.reset();
   currentFlashProgram.reset();
}

/**
 * Sets target interface to use when communicating with BDM
 *
 * @param bdmInterface Interface to use
 */
USBDM_ErrorCode FlashProgrammerCommon::setTargetInterface(BdmInterfacePtr bdmInterface) {
   this->bdmInterface = bdmInterface;
//   initTCL();
   return BDM_RC_OK;
}

/**
 * Sets and initialises the TCL interpreter
 */
USBDM_ErrorCode FlashProgrammerCommon::setTCLInterpreter(UsbdmTclInterperPtr ti) {
   LOGGING;

   releaseTCL();

   tclInterpreter = ti;

   if (tclInterpreter == nullptr) {
      log.error("Error: No TCL interpreter\n");
      return PROGRAMMING_RC_ERROR_TCL_SCRIPT;
   }
   return PROGRAMMING_RC_OK;
}

/**
 * Initialises TCL support for current target
 */
USBDM_ErrorCode FlashProgrammerCommon::initTCL() {
   LOGGING;

   USBDM_ErrorCode rc = BDM_RC_OK;

   // Set up TCL interpreter only once
   if (tclInterpreter == NULL) {
      rc = setTCLInterpreter(UsbdmTclInterperFactory::createUsbdmTclInterpreter(bdmInterface));
   }
   if (rc != BDM_RC_OK) {
      return rc;
   }
   // Set device settings
   rc = tclInterpreter->setDeviceParameters(device);
   return rc;
}

/**
 *  Release the current TCL interpreter
 */
USBDM_ErrorCode FlashProgrammerCommon::releaseTCL(void) {
   LOGGING_E;
   tclInterpreter.reset();
   return PROGRAMMING_RC_OK;
}

///**
// * Executes a TCL script in the current TCL interpreter
// *
// * @param script Script to run
// */
//USBDM_ErrorCode FlashProgrammerCommon::runTCLScript(TclScriptConstPtr script) {
//   LOGGING;
//   if (tclInterpreter == NULL) {
//      log.error("Error: No TCL Interpreter\n");
//      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
//   }
//   int rc = tclInterpreter->evalTclScript(script->getScript().c_str());
//   const char *result = tclInterpreter->getTclResult();
//   if ((result != NULL) && (*result != '\0')) {
//      // Error return
//      log.error("Error: Result = \'%s\'\n", result);
//      return PROGRAMMING_RC_ERROR_TCL_SCRIPT;
//   }
//   if (rc != 0) {
//      // Unexpected failure!
//      log.error("Error: Failed\n");
//      log.error("Error: %s", script->toString().c_str());
//      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
//   }
//   return PROGRAMMING_RC_OK;
//}
/**
 * Executes a TCL command previously loaded in the TCL interpreter
 *
 * @param command Command to execute.  This would usually be the name of a TCL function.
 * @param result  The return code is the result from the TCL command
 *
 * @return Error code on failed execution
 */
USBDM_ErrorCode FlashProgrammerCommon::runTCLCommandWithRc(const char *command, int &result) {
   LOGGING;
   log.print("Command = '%s'\n", command);
   result = 0;
//   log.print("tclInterpreter = %p\n", tclInterpreter.get());
   if (tclInterpreter == NULL) {
      log.error("Error: No TCL Interpreter\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   USBDM_ErrorCode rc = tclInterpreter->evalTclScript(command, result);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Error: Failed - rc = %d (%s)\n", rc, bdmInterface->getErrorString(rc));
   }
   return rc;
}

/**
 * Executes a TCL command previously loaded in the TCL interpreter
 *
 * @param command Command to execute.  This would usually be the name of a TCL function.
 *                A non-zero return code is interpreted as an error and flagged
 *
 * @return  Error code
 */
USBDM_ErrorCode FlashProgrammerCommon::runTCLCommand(const char *command) {
   LOGGING;
   log.print("TCL Command = '%s'\n", command);

//   log.print("tclInterpreter = %p\n", tclInterpreter.get());
   if (tclInterpreter == NULL) {
      log.error("Error: No TCL Interpreter\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   USBDM_ErrorCode rc = tclInterpreter->evalTclScript(command);
   if (rc != PROGRAMMING_RC_OK) {
      USBDM_ErrorCode rcUsbdm = tclInterpreter->getErrorResult();
      if ((rcUsbdm != BDM_RC_OK)&&(rcUsbdm != rc)) {
         log.error("Updating rc - old rc = %d (%s)\n", rc, bdmInterface->getErrorString(rc));
         rc = rcUsbdm;
      }
      log.error("Error: Failed - rc = %d (%s)\n", rc, bdmInterface->getErrorString(rc));
   }
   return rc;
}
/**
 * Release device data
 *
 * @note This will also release the TCL interpreter
 */
USBDM_ErrorCode FlashProgrammerCommon::releaseDeviceData() {

   device.reset();

   return BDM_RC_OK;
}

/**
 * Set device data for flash operations
 *
 * @param theParameters   -   data describing the device
 *
 * @return error code see \ref USBDM_ErrorCode
 *
 * @note This will create a default TCL interpreter
 */
USBDM_ErrorCode FlashProgrammerCommon::setDeviceData(const DeviceDataConstPtr device) {
   LOGGING_Q;

   assert(device != nullptr);

   log.print("Target=%s\n", device->getTargetName().c_str());

   currentFlashProgram.reset();
   this->device = device;
   releaseTCL();
   initTCL();
   return PROGRAMMING_RC_OK;
}

/**
 * Set device data for flash operations
 *
 * @param theParameters   -  data describing the device
 * @param tclInterpreter  -  TCL interpreter to use
 *
 * @return error code see \ref USBDM_ErrorCode
 */
USBDM_ErrorCode FlashProgrammerCommon::setDeviceData(const DeviceDataConstPtr device, UsbdmTclInterperPtr tclInterpreter) {
   LOGGING_Q;

   assert(device != nullptr);

   log.print("Target=%s\n", device->getTargetName().c_str());

   currentFlashProgram.reset();
   this->device = device;
   setTCLInterpreter(tclInterpreter);
   initTCL();
   return PROGRAMMING_RC_OK;
}

DeviceDataConstPtr FlashProgrammerCommon::getDeviceData() {
   return device;
}
/**
 * Clock register write with retry
 *
 * @param addr : clock register address
 * @param data : byte to write
 *
 * @return BDM_RC_OK => success
 *
 * @note writes are retried after a re-connect to cope
 *  with a possible clock speed change.
 */
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
/**
 * Configures the ICSCG target clock
 *
 * @param busFrequency    - Resulting BDM frequency after clock adjustment
 * @param clockParameters - Describes clock settings to use
 *
 * @return error code, see \ref USBDM_ErrorCode
 *
 * @note Assumes that connection with the target has been established so
 *       reports any errors as PROGRAMMING_RC_ERROR_FAILED_CLOCK indicating
 *       a problem programming the target clock.
 */
USBDM_ErrorCode FlashProgrammerCommon::configureICS_Clock(unsigned long         *busFrequency,
                                                          ICS_ClockParameters_t *clockParameters){
   LOGGING_E;

   const uint32_t ICSC1   = device->getClockAddress();
   const uint32_t ICSC2   = device->getClockAddress()+1;
   const uint32_t ICSTRIM = device->getClockAddress()+2;
   const uint32_t ICSSC   = device->getClockAddress()+3;

   unsigned long bdmFrequency;

   log.print("ICS Clock: Ad=0x%08X, C1=0x%02X, C2=0x%02X, SC=0x%02X\n",
           device->getClockAddress(),
           clockParameters->icsC1,
           clockParameters->icsC2,
           clockParameters->icsSC
           );

   flashReady = false; // Not configured for Flash access

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
   UsbdmSystem::milliSleep(100);
   if (USBDM_Connect() != BDM_RC_OK) { // re-connect after possible FLL change
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_GetSpeed(&bdmFrequency) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   bdmFrequency *= 1000; // Convert to Hz
   *busFrequency = bdmFrequency*device->getBDMtoBUSFactor();
   log.print("BDM Speed = %ld kHz, Bus Speed = %ld kHz\n",
         bdmFrequency/1000, *busFrequency/1000);
   return PROGRAMMING_RC_OK;
}

/**
 * Configures the ICGCG target clock
 *
 * @param busFrequency    - Resulting BDM frequency after clock adjustment
 * @param clockParameters - Describes clock settings to use
 *
 * @return error code, see \ref USBDM_ErrorCode
 *
 * @note Assumes that connection with the target has been established so
 *       reports any errors as PROGRAMMING_RC_ERROR_FAILED_CLOCK indicating
 *       a problem programming the target clock.
 */
USBDM_ErrorCode FlashProgrammerCommon::configureICG_Clock(unsigned long         *busFrequency,
                                                    ICG_ClockParameters_t *clockParameters){
   LOGGING_E;

   const uint32_t ICGC1    = device->getClockAddress();
   const uint32_t ICGC2    = device->getClockAddress()+1;
// const uint32_t ICGS1    = parameters.getClockAddress()+2;
// const uint32_t ICGS2    = parameters.getClockAddress()+3;
// const uint32_t ICGFLTU  = parameters.getClockAddress()+4;
// const uint32_t ICGFLTL  = parameters.getClockAddress()+5;
   const uint32_t ICGTRIM  = device->getClockAddress()+6;

   unsigned long bdmFrequency;

   log.print("ICG Clock: Ad=0x%4.4X, C1=0x%02X, C2=0x%02X\n",
           device->getClockAddress(),
           clockParameters->icgC1,
           clockParameters->icgC2
           );
   flashReady = false; // Not configured for Flash access

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
   UsbdmSystem::milliSleep(100);
   if (USBDM_Connect() != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_GetSpeed(&bdmFrequency) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   bdmFrequency *= 1000; // Convert to Hz
   *busFrequency = bdmFrequency*device->getBDMtoBUSFactor();
   log.print("BDM Speed = %ld kHz, Bus Speed = %ld kHz\n",
         bdmFrequency/1000, *busFrequency/1000);
   return PROGRAMMING_RC_OK;
}

/**
 *  Configures the MCGCG target clock
 *
 * @param busFrequency    - Resulting BDM frequency after clock adjustment
 * @param clockParameters - Describes clock settings to use
 *
 * @return error code, see \ref USBDM_ErrorCode
 *
 * @note Assumes that connection with the target has been established so
 *       reports any errors as PROGRAMMING_RC_ERROR_FAILED_CLOCK indicating
 *       a problem programming the target clock.
 */
USBDM_ErrorCode FlashProgrammerCommon::configureMCG_Clock(unsigned long         *busFrequency,
                                                    MCG_ClockParameters_t *clockParameters){
   LOGGING_E;

   const uint32_t MCGC1    = device->getClockAddress();
   const uint32_t MCGC2    = device->getClockAddress()+1;
   const uint32_t MCGTRIM  = device->getClockAddress()+2;
   const uint32_t MCGSC    = device->getClockAddress()+3;
   const uint32_t MCGC3    = device->getClockAddress()+4;
   const uint32_t MCGT     = device->getClockAddress()+5;

   unsigned long bdmFrequency;

   log.print("MCG Clock: Ad=0x%08X, C1=0x%02X, C2=0x%02X, C3=0x%02X, SC=0x%02X, CT/C4=0x%02X\n",
           device->getClockAddress(),
           clockParameters->mcgC1,
           clockParameters->mcgC2,
           clockParameters->mcgC3,
           clockParameters->mcgSC,
           clockParameters->mcgCT
           );

   flashReady = false; // Not configured for Flash access

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
   if ((device->getClockType() != S08MCGV1) &&
       (writeClockRegister(MCGT, clockParameters->mcgCT) != BDM_RC_OK)) {
         return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   UsbdmSystem::milliSleep(100);
   if (USBDM_Connect() != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   if (USBDM_GetSpeed(&bdmFrequency) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_FAILED_CLOCK;
   }
   bdmFrequency *= 1000; // Convert to Hz
   *busFrequency = bdmFrequency*device->getBDMtoBUSFactor();
   log.print("BDM Speed = %ld kHz, Bus Speed = %ld kHz\n",
         bdmFrequency/1000, *busFrequency/1000);
   return PROGRAMMING_RC_OK;
}
/**
 * Configures the External target clock
 *
 * @param busFrequency    - Resulting BDM frequency after clock adjustment (Hz)
 *
 * @return error code, see \ref USBDM_ErrorCode
 */
USBDM_ErrorCode FlashProgrammerCommon::configureExternal_Clock(unsigned long  *busFrequency){
   LOGGING_E;
   unsigned long bdmFrequency;

   flashReady = false; // Not configured for Flash access

   // Just connect at whatever speed
   if (USBDM_Connect() != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   if (USBDM_GetSpeed(&bdmFrequency) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   bdmFrequency *= 1000; // Convert to Hz
   *busFrequency = bdmFrequency*device->getBDMtoBUSFactor();
   log.print("BDM Speed = %ld kHz, Bus Speed = %ld kHz\n",
         bdmFrequency/1000, *busFrequency/1000);
   return PROGRAMMING_RC_OK;

}
/**
 * \brief Configures the target clock appropriately for flash programming
 *        The speed would be the maximum safe value for an untrimmed target
 *
 * @param busFrequency    - Resulting BDM frequency after clock adjustment \n
 *                          For a HCS08/CFV1 with CLKSW=1 this will be the bus frequency
 *
 * @return error code, see \ref USBDM_ErrorCode
 */
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
   ICS_ClockParameters_t   ICSV5_SpeedParameters = ICSV4_FlashSpeedParameters;
   ICG_ClockParameters_t   ICG_SpeedParameters   = ICG_FlashSpeedParameters;
   MCG_ClockParameters_t   MCG_SpeedParameters   = MCG_FlashSpeedParameters;

//   log.print("Configuring Target clock\n");

   switch (device->getClockType()) {
      case MKEICS:
         // not used
         return BDM_RC_OK;

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
      case S08ICSV5:
         // Program clock for approx. 4/8 MHz
         return configureICS_Clock(busFrequency, &ICSV5_SpeedParameters);
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
/**
 *  Determines the trim value for the target internal clock.
 *  The target clock is left trimmed for a bus freq. of targetBusFrequency.
 *
 *     Target clock has been suitably configured.
 *
 *  @param      trimAddress           Address of trim register.
 *  @param      targetBusFrequency    Target Bus Frequency to trim to.
 *  @param      returnTrimValue       Resulting trim value (9-bit number)
 *  @param      measuredBusFrequency  Resulting Bus Frequency
 *  @param      do9BitTrim            True to do 9-bit trim (rather than 8-bit)
 *
 *  @return
 *   == \ref PROGRAMMING_RC_OK  => Success \n
 *   != \ref PROGRAMMING_RC_OK  => Various errors
 */
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
   const unsigned long targetBDMFrequency = targetBusFrequency/device->getBDMtoBUSFactor();
   int numAverage;     // Number of times to repeat measurements

   double sumX          = 0.0;
   double sumY          = 0.0;
   double sumXX         = 0.0;
   double sumYY         = 0.0;
   double sumXY         = 0.0;
   double num           = 0.0;
   double alpha, beta;
   double trimValueF;

   log.print("targetBusFrequency=%2.2f MHz, targetBDMFrequency=%2.2f MHz)\n",
         targetBusFrequency/1000000.0, targetBDMFrequency/1000000.0);

   flashReady = false; // Not configured for Flash access

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

    log.print("Binary search: trimMSB=0x%02X (%d), bdmSpeed=%2.2fMHz %c\n",
            trimMSB, trimMSB, bdmSpeed/1000000.0, (bdmSpeed<targetBDMFrequency)?'-':'+');

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
      //UsbdmSystem::milliSleep(100);
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
      //UsbdmSystem::milliSleep(100);
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
   *measuredBusFrequency = bdmSpeed*device->getBDMtoBUSFactor();
   return rc;
}


/**
 * Trim clock (must be MKEICS)
 *
 * @param clockParameters Describes the clock
 */
USBDM_ErrorCode FlashProgrammerCommon::trimMKEICS_Clock(MKEICS_ClockParameters_t *clockParameters) {
   LOGGING;
   USBDM_ErrorCode rc =BDM_RC_OK;
   return rc;
}


/**
 * Trim clock (must be ICS)
 *
 * @param clockParameters Describes the clock
 */
USBDM_ErrorCode FlashProgrammerCommon::trimICS_Clock(ICS_ClockParameters_t *clockParameters) {
   LOGGING;
   static const ICS_ClockParameters_t ICS_LowSpeedParameters = {
         // 2-bit BDIV /1../8
         /* .icsC1   = */ 0x04, // IREFS
         /* .icsC2   = */ 0xC0, // BDIV=/8
         /* .icsTrim = */ 0x80, // TRIM=default
         /* .icsSC   = */ 0x00, // DRS=0,DMX32=0,FTRIM=0
   };
   static const ICS_ClockParameters_t ICSV4_LowSpeedParameters = {
         // 3-bit BDIV /1../128
         /* .icsC1   = */ 0x04, // IREFS
         /* .icsC2   = */ 0x60, // BDIV=/8
         /* .icsTrim = */ 0x80, // TRIM=default
         /* .icsSC   = */ 0x00, // LOLIE=0, CME=0, SCFTRIM=0
   };
   static const ICS_ClockParameters_t ICSV5_LowSpeedParameters = {
         // 3-bit BDIV /1../128
         /* .icsC1   = */ 0x04, // IREFS
         /* .icsC2   = */ 0x80, // BDIV=/16
         /* .icsTrim = */ 0x80, // TRIM=default
         /* .icsSC   = */ 0x00, // LOLIE=0, CME=0, SCFTRIM=0
   };
   uint32_t        ICSTRIM       = device->getClockAddress()+2;
   unsigned int    clockMultiplier;
   unsigned long   targetBusFrequency;
   unsigned long   originalBusFrequency;
   unsigned long   measuredBusFrequency;
   uint16_t        trimValue;
   USBDM_ErrorCode rc;

   switch (device->getClockType()) {
      case S08ICSV1:
      case S08ICSV3:
      case RS08ICSV1:
      case RS08ICSOSCV1:
      case S08ICSV2x512:
         clockMultiplier = 512/8/2;
         *clockParameters = ICS_LowSpeedParameters;
         break;
      case S08ICSV2:
          clockMultiplier = 1024/8/2;
          *clockParameters = ICS_LowSpeedParameters;
          break;
      case S08ICSV4:
         clockMultiplier = 512/8; // No /2 on bus clock
         *clockParameters = ICSV4_LowSpeedParameters;
         break;
      case S08ICSV5:
         clockMultiplier = 1024/16;// No /2 on bus clock
         *clockParameters = ICSV5_LowSpeedParameters;
         break;
      default:
         return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
   }

   targetBusFrequency = device->getClockTrimFreq()*clockMultiplier;

   log.print("TrimF = %.2f kHz, clock Multiplier=%d => Trim bus Freq=%.2f kHz\n",
         device->getClockTrimFreq()/1000.0, clockMultiplier, targetBusFrequency/1000.0);

   // Program clock for a low speed to improve accuracy of trimming
   rc = configureICS_Clock(&originalBusFrequency, clockParameters);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   log.print("Clock Freq = %4.2f kHz, Bus Freq=%4.2f kHz\n",
         device->getClockTrimFreq()/1000.0, targetBusFrequency/1000.0);

   rc = FlashProgrammerCommon::trimTargetClock(ICSTRIM, targetBusFrequency, &trimValue, &measuredBusFrequency, TRUE);

   log.print("rc=%d, Desired Freq = %.2f kHz,"
         " Meas. Freq=%.2f kHz, Trim=0x%02X/%1.1X\n",
         rc,
         device->getClockTrimFreq()/1000.0,
         (measuredBusFrequency/clockMultiplier)/1000.0,
         trimValue>>1, trimValue&0x01);

   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   // Update trim value
   clockParameters->icsTrim  = trimValue>>1;
   clockParameters->icsSC   |= trimValue&0x01;

   return rc;
}

/**
 * Trim clock (must be MCG)
 *
 * @param clockParameters Describes the clock
 */
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

   uint32_t MCGTRIM                = device->getClockAddress()+2;
   unsigned int  clockMultiplier;
   unsigned long targetBusFrequency;
   unsigned long originalBusFrequency;
   unsigned long measuredBusFrequency;
   uint16_t trimValue;
   USBDM_ErrorCode rc;

   switch (device->getClockType()) {
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

   targetBusFrequency = device->getClockTrimFreq()*(clockMultiplier/8/2);

   *clockParameters = MCG_LowSpeedParameters;

   log.print("TrimF = %.2f kHz, clock Multiplier=%d => Trim bus Freq=%.2f kHz\n",
         device->getClockTrimFreq()/1000.0, (1024/8/2), targetBusFrequency/1000.0);

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
         device->getClockTrimFreq()/1000.0,
         (measuredBusFrequency/(clockMultiplier/16))/1000.0,
         trimValue>>1, trimValue&0x01);

   // Update trim value
   clockParameters->mcgTrim  = trimValue>>1;
   clockParameters->mcgSC   |= trimValue&0x01;

   return rc;
}

/**
 * Trim clock (must be ICG)
 *
 * @param clockParameters Describes the clock
 */
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
   uint32_t ICGTRIM                 = device->getClockAddress()+6;
   unsigned long targetBusFrequency = device->getClockTrimFreq()*4;
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
         device->getClockTrimFreq()/1000.0, 4, targetBusFrequency/1000.0);

   rc = FlashProgrammerCommon::trimTargetClock(ICGTRIM, targetBusFrequency, &trimValue, &measuredBusFrequency, false);

   log.print("Desired Freq = %.1f kHz, Meas. Freq=%.1f kHz, Trim=%02X\n",
         device->getClockTrimFreq()/1000.0,
         (measuredBusFrequency/4)/1000.0,
         trimValue>>1);

   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   // Update trim value (discard LSB)
   clockParameters->icgTrim = trimValue>>1;

   return rc;
}
/**
 * Determines trim values for the target clock. \n
 * The values determined are written to the Flash image for later programming.
 *
 * @param flashImage - Flash image to be updated.
 *
 * @return error code see \ref USBDM_ErrorCode
 *
 * @note If the trim frequency indicated in parameters is zero then no trimming is done.
 *       This is not an error.
 */
USBDM_ErrorCode FlashProgrammerCommon::setFlashTrimValues(FlashImagePtr flashImage) {
   LOGGING;
   ClockParameters clockTrimParameters;
   USBDM_ErrorCode rc;
   uint16_t  ftrimMergeValue;

   // Assume no trim or failure
   calculatedClockTrimValue = 0;

   // No trimming required
   if (device->getClockTrimFreq() == 0) {
      return PROGRAMMING_RC_OK;
   }

#if TARGET == RS08
   uint32_t NVTRIM_address  = device->getClockTrimNVAddress();
   uint32_t NVFTRIM_address = device->getClockTrimNVAddress()+1;
#else
   uint32_t NVFTRIM_address = device->getClockTrimNVAddress();
   uint32_t NVTRIM_address  = device->getClockTrimNVAddress()+1;
#endif

   log.print("NVTRIM_address = 0x%06X, NVFTRIM_address = 0x%06X\n",NVTRIM_address, NVFTRIM_address);

   switch (device->getClockType()) {
      case CLKEXT:
      case CLKINVALID:
         return PROGRAMMING_RC_OK;

      case MKEICS:
         // 9-bit value
         rc = trimICS_Clock(&clockTrimParameters.ics);
         if (rc != PROGRAMMING_RC_OK) {
            return rc;
         }
         calculatedClockTrimValue = ((clockTrimParameters.ics.icsTrim<<1)|(clockTrimParameters.ics.icsSC&0x01));
         flashImage->setValue(NVTRIM_address, clockTrimParameters.ics.icsTrim);
         // The FTRIM bit may be combined with other bits such as DMX32 or DRS
         ftrimMergeValue = flashImage->getValue(device->getClockTrimNVAddress());
         if (((ftrimMergeValue&0xFF) == 0xFF)||(ftrimMergeValue >= 0xFF00U)) {
            // Image location is unused or contains the unprogrammed FLASH value
            // So no value to merge trim with - clear all other bits
            ftrimMergeValue = 0x00;
         }
         log.print("Merging FTRIM with 0x%02X\n", ftrimMergeValue);
         flashImage->setValue(NVFTRIM_address, (ftrimMergeValue&~0x01)|(clockTrimParameters.ics.icsSC&0x01));
         return PROGRAMMING_RC_OK;
      case S08ICGV1:
      case S08ICGV2:
      case S08ICGV3:
      case S08ICGV4:
         // 8-bit value (LSB ignored)
         rc = trimICG_Clock(&clockTrimParameters.icg);
         if (rc != PROGRAMMING_RC_OK)
            return rc;
         calculatedClockTrimValue = (clockTrimParameters.icg.icgTrim<<1);
         flashImage->setValue(device->getClockTrimNVAddress(),
                                         clockTrimParameters.icg.icgTrim);
         return PROGRAMMING_RC_OK;
      case S08ICSV1:
      case S08ICSV2:
      case S08ICSV3:
      case S08ICSV4:
      case S08ICSV5:
      case RS08ICSV1:
      case RS08ICSOSCV1:
      case S08ICSV2x512:
         // 9-bit value
         rc = trimICS_Clock(&clockTrimParameters.ics);
         if (rc != PROGRAMMING_RC_OK) {
            return rc;
         }
         calculatedClockTrimValue = ((clockTrimParameters.ics.icsTrim<<1)|(clockTrimParameters.ics.icsSC&0x01));
         flashImage->setValue(NVTRIM_address, clockTrimParameters.ics.icsTrim);
         // The FTRIM bit may be combined with other bits such as DMX32 or DRS
         ftrimMergeValue = flashImage->getValue(device->getClockTrimNVAddress());
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
         calculatedClockTrimValue = ((clockTrimParameters.mcg.mcgTrim<<1)|(clockTrimParameters.mcg.mcgSC&0x01));
         flashImage->setValue(device->getClockTrimNVAddress()+1,
                                         clockTrimParameters.mcg.mcgTrim);
         flashImage->setValue(device->getClockTrimNVAddress(),
                                         clockTrimParameters.mcg.mcgSC&0x01);
         return PROGRAMMING_RC_OK;
      case MKMCGV1:
         return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
         break;
   }
   return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
}
/**
 * Updates the memory image from the target flash Clock trim location(s)
 *
 * @param flashImage   = Flash image
 */
USBDM_ErrorCode FlashProgrammerCommon::dummyTrimLocations(FlashImagePtr flashImage) {
   LOGGING;
   unsigned size  = 0;
   uint32_t start = 0;

   // Not using trim -> do nothing
   if ((device->getClockTrimNVAddress() == 0) ||
       (device->getClockTrimFreq() == 0)) {
      log.print("Not using trim, no adjustment to image\n");
      return PROGRAMMING_RC_OK;
   }
   switch (device->getClockType()) {
      case MKEICS:
      case S08ICGV1:
      case S08ICGV2:
      case S08ICGV3:
      case S08ICGV4:
      case MKMCGV1:
         start = device->getClockTrimNVAddress();
         size  = 2;
         break;
      case S08ICSV1:
      case S08ICSV2:
      case S08ICSV2x512:
      case S08ICSV3:
      case S08ICSV4:
      case S08ICSV5:
      case S08MCGV1:
      case S08MCGV2:
      case S08MCGV3:
      case RS08ICSOSCV1:
      case RS08ICSV1:
         start = device->getClockTrimNVAddress();
         size  = 2;
         break;
      case CLKEXT:
      case CLKINVALID:
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
/**
 * \brief Maps a Flash action vector to Text
 *
 * @param flashOperation => operation to describe
 *
 * @return pointer to static string buffer describing the flashOperation
 */
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

/**
 * Probe RAM location
 *
 * @param memorySpace - Memory space and size of probe
 * @param address     - Address to probe
 *
 * @return BDM_RC_OK if successful
 */
USBDM_ErrorCode FlashProgrammerCommon::probeMemory(MemorySpace_t memorySpace, uint32_t address) {
   LOGGING_Q;
   static const uint8_t probe1[] = {0xA5, 0xF0,0xA5, 0xF0,};
   static const uint8_t probe2[] = {0x0F, 0x5A,0x0F, 0x5A,};
   uint8_t              probeResult1[sizeof(probe1)];
   uint8_t              probeResult2[sizeof(probe2)];
   uint8_t              savedData[sizeof(probe1)];
   bool                 savedDataValid = false;

//   address &= ~((1<<(memorySpace&MS_SIZE))-1);
   address &= ~((memorySpace&MS_SIZE)-1);
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
         log.error("Error: Memory probe failed\n");
         rc = PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
         break;
      }
   } while (0);

   if (savedDataValid) {
      bdmInterface->writeMemory(memorySpace,memorySpace&MS_SIZE,address,savedData);
   }

   if (rc != BDM_RC_OK) {
      log.error("Error: RAM memory probe failed @%s:0x%08X, rc = %d (%s)\n", getMemSpaceName(memorySpace), address, rc, bdmInterface->getErrorString(rc));
      return rc;
   }
   return PROGRAMMING_RC_OK;
}

/**
 * Checks that there are no modified security areas
 *
 * @return error code if security areas are present
 */
USBDM_ErrorCode FlashProgrammerCommon::checkNoSecurityAreas(void) {
   LOGGING;
   if (securityAreaCount > 0) {
      log.error("Error: Security areas not empty!\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   return BDM_RC_OK;
}

//===========================================================================================================
//! Modifies the Security locations in the flash image according to required security options of flashRegion
//!
//! @param flashImage    Flash contents to be programmed.
//! @param flashRegion   The memory region involved (to determine security area if any)
//!
USBDM_ErrorCode FlashProgrammerCommon::setFlashSecurity(FlashImagePtr flashImage, MemoryRegionConstPtr flashRegion) {
   LOGGING;
   uint32_t securityRegionAddress = flashRegion->getSecurityAddress();
   if (securityRegionAddress == 0) {
      log.print("No security area for %s, not modifying memory region in image\n", flashRegion->getMemoryTypeName());
      return PROGRAMMING_RC_OK;
   }
   log.print("Processing security area for %s, may modify memory region in image\n", flashRegion->getMemoryTypeName());
   auto memoryRange       = flashRegion->getMemoryRangeFor(securityRegionAddress);

   // Get security information and size
   SecurityInfoConstPtr securityInfo;
   SecurityOptions_t securityOption = device->getSecurity();
   switch (securityOption) {
      case SEC_SECURED:
         log.print("Setting image as secured for [0x%08X..0x%08X]\n", memoryRange->start, memoryRange->end);
         securityInfo = flashRegion->getSecureInfo();
         break;
      case SEC_UNSECURED:
         log.print("Setting image as unsecured for [0x%08X..0x%08X]\n", memoryRange->start, memoryRange->end);
         securityInfo = flashRegion->getUnsecureInfo();
         break;
      case SEC_CUSTOM:
         log.print("Setting image security to custom value for [0x%08X..0x%08X]\n", memoryRange->start, memoryRange->end);
         securityInfo = flashRegion->getCustomSecureInfo();
         break;
      case SEC_INTELLIGENT:
         log.print("Setting image as intelligently unsecured for [0x%08X..0x%08X]\n", memoryRange->start, memoryRange->end);
         securityInfo = flashRegion->getUnsecureInfo();
         break;
      case SEC_DEFAULT:
         log.print("Setting image as security unchanged for [0x%08X..0x%08X]\n", memoryRange->start, memoryRange->end);
         securityInfo = flashRegion->getUnsecureInfo();
         break;
      default:
         log.error("Unexpected securityInfo value");
         return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if (securityInfo == NULL) {
      log.error("Error - No settings for security area!\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }

   int securityRegionSize = securityInfo->getSize();

   // SEC_INTELLIGENT becomes SEC_UNSECURED or SEC_DEFAULT
   if (securityOption == SEC_INTELLIGENT) {
      // Default to unsecured info
      securityOption = SEC_UNSECURED;

      // Check for security information within flash image
      for(int index=0; index<securityRegionSize; index++) {
         if (flashImage->isValid(securityRegionAddress+index)) {
            // Use flash info instead
            securityOption = SEC_DEFAULT;
            break;
         }
      }
   }

   bool securityAreaInImageNeedsModification = false;

   // Create security area contents
   uint8_t securityData[securityRegionSize];
   switch (securityOption) {
      case SEC_SECURED:
      case SEC_UNSECURED:
      case SEC_CUSTOM:
         memcpy(securityData, securityInfo->getData(), securityRegionSize);
         securityAreaInImageNeedsModification = true;
         break;
      case SEC_DEFAULT:
      default:
         // Copy security information from flash
         for(int index=0; index<securityRegionSize; index++) {
            securityAreaInImageNeedsModification = securityAreaInImageNeedsModification ||
                  flashImage->isValid(securityRegionAddress+index);
            securityData[index] = flashImage->getValue(securityRegionAddress+index);
         }
         break;
   }

   // Save contents of current security area within Flash image
   recordSecurityArea(flashImage, securityRegionAddress, securityRegionSize);
   if (securityAreaInImageNeedsModification) {
      // Update flash with new security info
      flashImage->loadDataBytes(securityRegionSize, securityRegionAddress, securityData, FlashImage::Overwrite);
   }
#ifdef LOG
   log.print("Flash security region: "
         "              mem[0x%06lX-0x%06lX] = \n", (unsigned long)securityRegionAddress, (unsigned long)(securityRegionAddress+securityRegionSize/sizeof(uint8_t)-1));
   flashImage->dumpRange(securityRegionAddress, securityRegionAddress+securityRegionSize-1);
#endif

   if ((getEraseMethod() == DeviceData::eraseMass) || (getEraseMethod() == DeviceData::eraseNone)) {
      // No further erasing of target memory expected
      // Try to preserve existing security area if suitable

      // Read current security area from target (after mass-erase or unchanged)
      uint8_t memory[securityRegionSize];
      bdmInterface->readMemory(MS_Byte, securityRegionSize, securityRegionAddress, memory);

      // Check if security area in target is blank
      bool securityAreaInTargetIsNonBlank = false;
      for(int index=0; index<securityRegionSize; index++) {
         if (memory[index] != 0xFF) {
            securityAreaInTargetIsNonBlank = true;
            break;
         }
      }
      log.print("Security area in target is %s\n", securityAreaInTargetIsNonBlank?"non-blank":"blank");

      if (memcmp(securityData, memory, securityRegionSize) == 0) {
         // Security area in target memory agrees with desired security
         // Clear security area in image to prevent attempted re-programming of already valid data
         log.print("Removing security area from programming image as equal to current target memory contents and not being erased\n");
         for(int index=0; index<securityRegionSize; index++) {
            flashImage->remove(securityRegionAddress+index);
         }
      }
      else if (securityAreaInTargetIsNonBlank) {
         // Security area conflicts with image
         if (getEraseMethod() == DeviceData::eraseNone) {
            // Can't change security without erase
            return PROGRAMMING_RC_ERROR_NOT_BLANK;
         }
         else {
            // Mass erase left security area non-blank and conflicting
            // Force erase of security area in target before programming
            log.print("Security area in target needs erasing\n");
            securityNeedsSelectiveErase = true;
         }
      }
      // else it is blank and doesn't need erasing in any case
   }
   return PROGRAMMING_RC_OK;
}

//===============================================================================================
//! Modifies the Security locations in the flash image according to required security options
//!
//! @param flashImage  -  Flash image to be modified
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
//! @note: This MUST be done after mass erase (if used) as target memory is checked!
//!
USBDM_ErrorCode FlashProgrammerCommon::setFlashSecurity(FlashImagePtr flashImage) {
   LOGGING;

   // Process each flash region
   USBDM_ErrorCode rc = BDM_RC_OK;

   // Assume security areas not present, or already erased, or will be erased in any case (e.g. eraseSelective)
   securityNeedsSelectiveErase = false;

   // All security areas in image should have been restored before this!
   rc = checkNoSecurityAreas();
   if (rc != BDM_RC_OK) {
      return rc;
   }

   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = device->getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         break;
      }
      rc = setFlashSecurity(flashImage, memoryRegionPtr);
      if (rc != BDM_RC_OK) {
         log.print("Failed to set security @0x%08X for %s, rc = %s\n",
               memoryRegionPtr->getSecurityAddress(), memoryRegionPtr->getMemoryTypeName(), bdmInterface->getErrorString(rc));
         break;
      }
   }
   return rc;
}

/**
 * Record the original contents of a security area for later restoration
 *
 * @param flashImage Flash image being manipulated
 * @param address    Start address of security area
 * @param size       Size of area
 *
 * @return error code see \ref USBDM_ErrorCode.
 */
USBDM_ErrorCode FlashProgrammerCommon::recordSecurityArea(FlashImagePtr flashImage, const uint32_t startAddress, const uint32_t size) {
   LOGGING_Q;
   log.print("[0x%08X...0x%08X] : ", startAddress, startAddress+size-1);
   if (securityAreaCount >= sizeof(securityData)/sizeof(securityData[0])) {
      log.error("Error: Invalid securityAreaCount size");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if (size > MaxSecurityAreaSize) {
      log.error("Error: Invalid security size\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
  securityData[securityAreaCount].address = startAddress;
  securityData[securityAreaCount].size    = size;
  for (uint32_t count=0; count<size; count++) {
     if (!flashImage->isValid(startAddress+count)) {
        securityData[securityAreaCount].data[count] = SecurityDataCache::BLANK;
        log.printq("Blank, ");
     }
     else {
        securityData[securityAreaCount].data[count] = flashImage->getValue(startAddress+count);
        log.printq("%02X ", flashImage->getValue(startAddress+count));
     }
  }
  log.printq("\n");
  flashImage->dumpRange(startAddress, startAddress+size-1);
  securityAreaCount++;
  return PROGRAMMING_RC_OK;
}

/**
 * Restores the contents of the security areas to their saved values
 *
 * @param flashImage    Flash contents to be programmed.
 */
void FlashProgrammerCommon::restoreSecurityAreas(FlashImagePtr flashImage) {
   LOGGING_Q;
   for (unsigned index=0; index<securityAreaCount; index++) {
      log.print("Restoring security area in image [0x%06X...0x%06X] : \n",
            securityData[index].address, securityData[index].address+securityData[index].size-1);
      log.print("  ");
      for (uint32_t count=0; count<securityData[index].size; count++) {
         if (securityData[index].data[count] == SecurityDataCache::BLANK) {
            flashImage->remove(securityData[index].address+count);
            log.printq("Blank ");
         }
         else {
            flashImage->setValue(securityData[index].address+count, (uint8_t)securityData[index].data[count]);
            log.printq("0x%02X ", (uint8_t)securityData[index].data[count]);
         }
      }
      log.printq("\n");
      flashImage->dumpRange(securityData[index].address, securityData[index].address+securityData[index].size-1);
   }
   securityAreaCount = 0;
}

/**
 * Get erase method to use
 *
 * @return erase method
 */
DeviceData::EraseMethod FlashProgrammerCommon::getEraseMethod() {
   LOGGING_Q;

   DeviceData::EraseMethod eraseMethod = defaultEraseMethod;
   if (device == nullptr) {
      log.print("Device not set!\n");
   }
   else {
      eraseMethod = device->getEraseMethod();
      if ((eraseMethod == DeviceData::eraseTargetDefault)) {
         EraseMethodsConstPtr eraseMethods = device->getEraseMethods();
         if (eraseMethods == nullptr) {
            log.print("eraseMethods not set!\n");
            eraseMethod = defaultEraseMethod;
         }
         else {
            eraseMethod = eraseMethods->getDefaultMethod();
         }
      }
   }
   log.print("Erase method = %s\n", DeviceData::getEraseMethodName(eraseMethod));
   return eraseMethod;
}

/**
 * Get reset method to use
 *
 * @return reset method
 */
DeviceData::ResetMethod FlashProgrammerCommon::getResetMethod() {
   LOGGING_Q;

   DeviceData::ResetMethod resetMethod = defaultResetMethod;
   if (device == nullptr) {
      log.print("Device not set!\n");
   }
   else {
      resetMethod = device->getResetMethod();
      if ((resetMethod == DeviceData::resetTargetDefault)) {
         ResetMethodsConstPtr resetMethods = device->getResetMethods();
         if (resetMethods == nullptr) {
            log.print("resetMethods not set!\n");
            resetMethod = defaultResetMethod;
         }
         resetMethod = resetMethods->getDefaultMethod();
      }
   }
   log.print("Reset method = %s\n", DeviceData::getResetMethodName(resetMethod));
   return resetMethod;
}
