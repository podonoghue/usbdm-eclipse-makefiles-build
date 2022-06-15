/*! \file
   \brief Common BDM Interface Code

   BdmInterfaceCommon.cpp

   \verbatim
   USBDM GDI interface DLL
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
Change History
-==================================================================================================
|  Dec 21 2014 | Fixed Retry in initBdm()                                          - pgo V4.12.1.20
+==================================================================================================
\endverbatim
*/

//#include "wxPlugin.h"
#include "BdmInformation.h"
#include "Names.h"
#include "TargetDefines.h"
#include "Utils.h"
#include "UsbdmWxConstants.h"
#include "WxPluginFactory.h"
#include "BdmInterfaceCommon.h"
#include "PluginHelper.h"

using namespace std;
using namespace UsbdmWxConstants;

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createDefaultPluginInstance(BdmInterfaceCommon *pp) {
   return TcreatePluginInstance<BdmInterfaceCommon>(pp, T_OFF);
}

ModuleInfo BdmInterfaceCommon::moduleInfo;

string BdmInterfaceCommon::getDllVersionString() {
   LOGGING_Q;
   const char *bdmVersion = USBDM_DLLVersionString();
   log.print("USBDM DLL Version = %s\n", bdmVersion);
   return string(bdmVersion);
}

unsigned int BdmInterfaceCommon::getDllVersion() {
   return USBDM_DLLVersion();
}

string BdmInterfaceCommon::getBdmVersionString() {
   LOGGING_Q;
   USBDM_Version_t version;
   USBDM_GetVersion(&version);
   char bdmVersion[200];
   snprintf(bdmVersion, sizeof(bdmVersion), "HW=%X, SW=%X\n", version.bdmHardwareVersion, version.bdmSoftwareVersion);
   bdmVersion[sizeof(bdmVersion)-1] = '\0';
   log.print("BDM Version = %s\n", bdmVersion);
   return string(bdmVersion);
}

USBDM_ErrorCode BdmInterfaceCommon::getBdmInformation(USBDM_bdmInformation_t &information) {
   information.size = sizeof(USBDM_bdmInformation_t);
   return USBDM_GetBdmInformation(&information);
}

const char *BdmInterfaceCommon::getErrorString(USBDM_ErrorCode rc) {
   return USBDM_GetErrorString(rc);
}

void BdmInterfaceCommon::setCallback(Callback callback) {
   callbackPtr = callback;
}

unsigned BdmInterfaceCommon::getConnectionTimeout() {
   return connectionTimeout;
}

void BdmInterfaceCommon::setConnectionTimeout(unsigned value) {
   connectionTimeout = value;
}

bool BdmInterfaceCommon::isMaskISR(void) {
   return bdmOptions.maskInterrupts;
}

void BdmInterfaceCommon::setMaskISR(bool disableInterrupts) {
   bdmOptions.maskInterrupts = disableInterrupts;
}

bool BdmInterfaceCommon::isCatchVLLSx() const {
   return catchVLLSx;
}

void BdmInterfaceCommon::setCatchVLLSx(bool catchVLLSx) {
   this->catchVLLSx = catchVLLSx;
}

USBDM_ExtendedOptions_t& BdmInterfaceCommon::getBdmOptions() {
   return bdmOptions;
}

USBDM_ErrorCode BdmInterfaceCommon::getDefaultBdmOptions(USBDM_ExtendedOptions_t *options) {
   options->size       = sizeof(USBDM_ExtendedOptions_t);
   options->targetType = bdmOptions.targetType;
   return USBDM_GetDefaultExtendedOptions(options);
}

bool BdmInterfaceCommon::isExitOnClose() const {
   return exitOnClose;
}

void BdmInterfaceCommon::setExitOnClose(bool exitOnClose) {
   this->exitOnClose = exitOnClose;
}

int BdmInterfaceCommon::getGdbServerPort() {
   return gdbServerPort;
}

void BdmInterfaceCommon::setGdbServerPort(int port) {
   gdbServerPort = port;
}

int BdmInterfaceCommon::getGdbTtyPort() {
   return ttyServerPort;
}

void BdmInterfaceCommon::setGdbTtyPort(int port) {
   ttyServerPort = port;
}

/*! Sets BDM to use based on serial number
 *
 *   @param serialNumber  BDM serial number to look for
 *   @param matchRequired If true then are particular BDM is required
 *
 *   @note If matchRequired=false then serialNumber is only a preferred BDM.
 */
void BdmInterfaceCommon::setBdmSerialNumber(std::string serialNumber, bool matchRequired) {
   LOGGING_Q;
   log.print("Setting serial #%s\n", (const char *)serialNumber.c_str());
   bdmSerialNumber  = serialNumber;
   bdmMatchRequired = matchRequired && (serialNumber.length() != 0);
}

/*! Get serial number of selected BDM
 *
 *   @return serial number
 */
std::string &BdmInterfaceCommon::getBdmSerialNumber() {
   return bdmSerialNumber;
}

bool BdmInterfaceCommon::getBdmMatchRequired() {
   return bdmMatchRequired;
}

/*! Opens & initialises the currently selected BDM (based on serial number)
 *
 *  Entry - Assumes .bdmInformation contains required information
 *
 *  @return Error code indicating outcome.
 *          The dialogue callback is used on any error
 */
USBDM_ErrorCode BdmInterfaceCommon::initBdm(void) {
   LOGGING;

   log.print("SerialNumber = \'%s\'\n", getBdmSerialNumber().c_str());
   printBdmOptions(&bdmOptions);

   USBDM_ErrorCode rc = BDM_RC_OK;

   // Cycle Vdd on connect is done by Interface instead of BDM H/W
   if ((bdmOptions.targetVdd != BDM_TARGET_VDD_OFF) && bdmOptions.cycleVddOnConnect) {
      initialConnectRetryMode = (BdmInterface::RetryMode)(BdmInterface::retryWithInit|BdmInterface::retryAlways|BdmInterface::retryByReset|BdmInterface::retryByPower|BdmInterface::retryDelayedCheck);
      softConnectRetryMode    = (BdmInterface::RetryMode)(BdmInterface::retryAlways|BdmInterface::retryByPower);
   }
   else {
      initialConnectRetryMode = (BdmInterface::RetryMode)(BdmInterface::retryWithInit|BdmInterface::retryAlways|BdmInterface::retryByReset|BdmInterface::retryDelayedCheck);
      softConnectRetryMode    = (BdmInterface::RetryMode)(BdmInterface::retryAlways);
   }

   int getYesNo = NO;
   do {
      // Initialise the BDM interface before use
      rc = USBDM_Init();
      if (rc != BDM_RC_OK) {
         getYesNo = handleError(rc);
         continue;
      }
      // Open selected BDM
      rc = openBySerialNumber(getBdmSerialNumber(), getBdmMatchRequired());
      if (rc != BDM_RC_OK) {
         getYesNo = handleError(rc);
         continue;
      }
      if (bdmOptions.targetType == T_CFVx) {
         HardwareCapabilities_t capabilities;
         if ((USBDM_GetCapabilities(&capabilities)==BDM_RC_OK) && ((capabilities&BDM_CAP_PST) == 0)) {
            // Don't use PST option if not supported by BDM
            bdmOptions.usePSTSignals = false;
         }
      }
      USBDM_ExtendedOptions_t options = bdmOptions;

      // Tell BDM not to do cycle Vdd as done by interface
      options.cycleVddOnConnect = false;

      rc = USBDM_SetExtendedOptions(&options);
      if (rc != BDM_RC_OK) {
         getYesNo = handleError(rc);
         continue;
      }
      rc = setTargetTypeWithRetry();
      if (rc == BDM_RC_OK) {
         break;
      }
   } while (getYesNo == YES);
   if (rc != BDM_RC_OK) {
      closeBdm();
   }
   return rc;
}

/*! Close BDM
 *
 */
USBDM_ErrorCode BdmInterfaceCommon::closeBdm(void) {
   LOGGING_E;
   return USBDM_Close();
}

#define settingsKey "Shared"

const string bdmSerialNumberKey(         settingsKey ".bdmSerialNumber");

const string powerOffDurationKey(        settingsKey ".powerOffDuration");
const string powerOnRecoveryIntervalKey( settingsKey ".powerOnRecoveryInterval");
const string resetDurationKey(           settingsKey ".resetDuration");
const string resetReleaseIntervalKey(    settingsKey ".resetReleaseInterval");
const string resetRecoveryIntervalKey(   settingsKey ".resetRecoveryInterval");
const string gdbServerPortNumberKey(     settingsKey ".gdbServerPortNumber");
const string gdbTtyPortNumberKey(        settingsKey ".gdbTtyPortNumberKey");
const string catchVLLSxKey(              settingsKey ".catchVLLSx");
const string connectionTimeoutKey(       settingsKey ".connectionTimeout");
//
const string setTargetVddKey(            settingsKey ".setTargetVdd");
const string cycleTargetVddOnResetKey(   settingsKey ".cycleTargetVddOnReset");
const string cycleTargetVddonConnectKey( settingsKey ".cycleTargetVddonConnect");
const string leaveTargetPoweredKey(      settingsKey ".leaveTargetPowered");
const string automaticReconnectKey(      settingsKey ".automaticReconnect");
const string guessSpeedIfNoSYNCKey(      settingsKey ".guessSpeedIfNoSYNC");
const string bdmClockSourceKey(          settingsKey ".bdmClockSource");
const string useResetSignalKey(          settingsKey ".useResetSignal");
const string maskInterruptsKey(          settingsKey ".maskInterrupts");
const string interfaceFrequencyKey(      settingsKey ".interfaceFrequency");
const string usePSTSignalsKey(           settingsKey ".usePSTSignals");

/*!
 *
 */
BdmInterfaceCommon::BdmInterfaceCommon(TargetType_t targetType) {
   LOGGING_Q;

   log.print("Target Type = %s\n", getTargetTypeName(targetType));

   // Set options to default
   connectionTimeout           = 10;
   bdmOptions.maskInterrupts   = true;
   extendedRetry               = false;
   gdbServerPort               = 1234;
   ttyServerPort               = 4321;
   bdmSerialNumber             = "";
   bdmMatchRequired            = false;
   catchVLLSx                  = false;
   exitOnClose                 = false;
   callbackPtr                 = 0;
   serialInterfaceEnabled      = true;

   wxPlugin.reset();

   bdmOptions.size            = sizeof(USBDM_ExtendedOptions_t);
   bdmOptions.targetType      = targetType;

   initialConnectRetryMode = (BdmInterface::RetryMode)(BdmInterface::retryWithInit|BdmInterface::retryAlways);
   softConnectRetryMode    = (BdmInterface::RetryMode)(BdmInterface::retryAlways);

   USBDM_Init();
   USBDM_GetDefaultExtendedOptions(&bdmOptions);
}

BdmInterfaceCommon::~BdmInterfaceCommon() {
   LOGGING_E;
   closeBdm();
   wxPlugin.reset();
}

/*!  Load settings from object
 *
 *  @param  settings Settings object
 */
void BdmInterfaceCommon::loadSettings(const AppSettings &settings) {
   LOGGING_E;

   // Load previously used BDM
   setBdmSerialNumber(settings.getValue(bdmSerialNumberKey,            bdmSerialNumber));

   setConnectionTimeout(     settings.getValue(connectionTimeoutKey,     getConnectionTimeout()));
   setCatchVLLSx(            settings.getValue(catchVLLSxKey,            isCatchVLLSx()));

   setGdbServerPort(settings.getValue(gdbServerPortNumberKey, getGdbServerPort()));
   setGdbTtyPort(settings.getValue(gdbTtyPortNumberKey, getGdbTtyPort()));

   bdmOptions.targetVdd                = (TargetVddSelect_t) settings.getValue(setTargetVddKey,             bdmOptions.targetVdd);
   bdmOptions.cycleVddOnReset          =                     settings.getValue(cycleTargetVddOnResetKey,    bdmOptions.cycleVddOnReset);
   bdmOptions.cycleVddOnConnect        =                     settings.getValue(cycleTargetVddonConnectKey,  bdmOptions.cycleVddOnConnect);
   bdmOptions.leaveTargetPowered       =                     settings.getValue(leaveTargetPoweredKey,       bdmOptions.leaveTargetPowered);
   bdmOptions.autoReconnect            =     (AutoConnect_t) settings.getValue(automaticReconnectKey,       bdmOptions.autoReconnect);
   bdmOptions.guessSpeed               =                     settings.getValue(guessSpeedIfNoSYNCKey,       bdmOptions.guessSpeed);
   bdmOptions.bdmClockSource           =     (ClkSwValues_t) settings.getValue(bdmClockSourceKey,           bdmOptions.bdmClockSource);
   bdmOptions.useResetSignal           =                     settings.getValue(useResetSignalKey,           bdmOptions.useResetSignal);
   bdmOptions.maskInterrupts           =                     settings.getValue(maskInterruptsKey,           bdmOptions.maskInterrupts);
   bdmOptions.interfaceFrequency       =                     settings.getValue(interfaceFrequencyKey,       bdmOptions.interfaceFrequency);
   bdmOptions.usePSTSignals            =                     settings.getValue(usePSTSignalsKey,            bdmOptions.usePSTSignals);

   bdmOptions.powerOffDuration         =                     settings.getValue(powerOffDurationKey,         bdmOptions.powerOffDuration);
   bdmOptions.powerOnRecoveryInterval  =                     settings.getValue(powerOnRecoveryIntervalKey,  bdmOptions.powerOnRecoveryInterval);
   bdmOptions.resetDuration            =                     settings.getValue(resetDurationKey,            bdmOptions.resetDuration);
   bdmOptions.resetReleaseInterval     =                     settings.getValue(resetReleaseIntervalKey,     bdmOptions.resetReleaseInterval);
   bdmOptions.resetRecoveryInterval    =                     settings.getValue(resetRecoveryIntervalKey,    bdmOptions.resetRecoveryInterval);
}

/*!  Save settings to object
 *
 *  @param  settings Settings object
 */
void BdmInterfaceCommon::saveSettings(AppSettings &settings) {
   LOGGING_E;

   settings.addValue(bdmSerialNumberKey,           getBdmSerialNumber());

   settings.addValue(connectionTimeoutKey,         getConnectionTimeout());
   settings.addValue(catchVLLSxKey,                isCatchVLLSx());

   settings.addValue(gdbServerPortNumberKey,       getGdbServerPort());
   settings.addValue(gdbTtyPortNumberKey,          getGdbTtyPort());

   settings.addValue(setTargetVddKey,              bdmOptions.targetVdd);
   settings.addValue(cycleTargetVddOnResetKey,     bdmOptions.cycleVddOnReset);
   settings.addValue(cycleTargetVddonConnectKey,   bdmOptions.cycleVddOnConnect);
   settings.addValue(leaveTargetPoweredKey,        bdmOptions.leaveTargetPowered);
   settings.addValue(automaticReconnectKey,        bdmOptions.autoReconnect);
   settings.addValue(guessSpeedIfNoSYNCKey,        bdmOptions.guessSpeed);
   settings.addValue(bdmClockSourceKey,            bdmOptions.bdmClockSource);
   settings.addValue(useResetSignalKey,            bdmOptions.useResetSignal);
   settings.addValue(maskInterruptsKey,            bdmOptions.maskInterrupts);
   settings.addValue(interfaceFrequencyKey,        bdmOptions.interfaceFrequency);
   settings.addValue(usePSTSignalsKey,             bdmOptions.usePSTSignals);

   settings.addValue(powerOffDurationKey,          bdmOptions.powerOffDuration);
   settings.addValue(powerOnRecoveryIntervalKey,   bdmOptions.powerOnRecoveryInterval);
   settings.addValue(resetDurationKey,             bdmOptions.resetDuration);
   settings.addValue(resetReleaseIntervalKey,      bdmOptions.resetReleaseInterval);
   settings.addValue(resetRecoveryIntervalKey,     bdmOptions.resetRecoveryInterval);
}

//! Gets BDM Status with checks for fatal errors with no recovery option
//!
//! At this time the only fatal errors are:
//!   - USBDM_GetBDMStatus() failed i.e. the BDMs gone away - quietly fails
//!   - Target supply overload - flags error to user & fails
//!
//! @param USBDMStatus status value from BDM
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_ErrorCode BdmInterfaceCommon::getBDMStatus(USBDMStatus_t *USBDMStatus) {
   LOGGING_Q;
   USBDM_ErrorCode rc;

   // USBDM_GetBDMStatus() should always succeed
   rc = USBDM_GetBDMStatus(USBDMStatus);
   if (rc != BDM_RC_OK) {
      log.error("getBDMStatus() - failed, reason = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }

   // Check for Fatal power supply problems
   if (USBDMStatus->power_state == BDM_TARGET_VDD_ERR) {
      callback("Overload of the BDM Target Vdd supply has been detected.  \n"
               "The target supply has been disabled.\n\n"
               "Please restart the debugging session to restore power.",
               "USBDM Interface - Target Power Failure",
               ICON_ERROR|OK);

      log.error("getBDMStatus() - failed, reason = Vdd overload\n");
      return BDM_RC_VDD_NOT_PRESENT;
   }
   return BDM_RC_OK;
}

//! Connect to target with a delayed check
//!
//! @note - The delayed check is to help detect watch-dog timeouts that can cause the
//!         BDM to get a connection but then loose it before anything useful can be done.
//!
//! @return \n
//!     DI_OK                  => OK \n
//!     BDM_RC_BDM_EN_FAILED   => Usually indicates an initial connection that is lost before re-check
//!     other                  => Some other more varied error
//!
USBDM_ErrorCode BdmInterfaceCommon::targetConnectWithDelayedConfirmation(RetryMode retryMode) {
   LOGGING_Q;
   USBDM_ErrorCode rc;

   //=========================================================
   //  Basic connect
   rc = USBDM_Connect();
   if (rc != BDM_RC_OK) {
      return rc;
   }
   static const uint8_t masks[] = {
         HC12_BDMSTS_ENBDM, //  0 - HCS12
         HC08_BDCSCR_ENBDM, //  1 - HCS08
         RS08_BDCSCR_ENBDM, //  2 - RS08
         CFV1_XCSR_ENBDM,   //  3 - CFV1
         0,                 //  4 - CFVx
         0,                 //  5 - JTAG
         0,                 //  6 - EZFLASH
         0,                 //  7 - MC56F80xx
         0,                 //  8 - ARM
         0,                 //  9 - ARM_JTAG
         0,                 // 10 - ARM_SWD
         0,                 // 11 - S12Z
   };
   uint8_t mask = 0;
   if ((bdmOptions.targetType>0) && (bdmOptions.targetType<(sizeof(masks)/sizeof(masks[0])))) {
      mask = masks[bdmOptions.targetType];
   }
   if (mask == 0) {
      // No delayed confirmation
      return rc;
   }

   if (retryMode&retryDelayedCheck) {
      // Check if still connected after a while (WDOG check)
      UsbdmSystem::milliSleep(20);
   }
   unsigned long BDMStatusReg;
   rc = USBDM_ReadStatusReg(&BDMStatusReg);
   if ((rc == BDM_RC_OK) && ((BDMStatusReg&mask) == 0)) {
      rc = BDM_RC_BDM_EN_FAILED;
   }
   if (rc != BDM_RC_OK) {
      log.error("Failed - rc = %s\n", USBDM_GetErrorString(rc));
   }
   return rc;
}

//! Releases reset etc using correct Special Mode sequence and then  retries connection
//!
//! @return \n
//!     DI_OK                  => OK \n
//!     BDM_RC_BDM_EN_FAILED   => Usually indicates an initial connection that is lost before re-check
//!     other                  => Some other more varied error
//!
USBDM_ErrorCode BdmInterfaceCommon::retryConnection(USBDMStatus_t *usbdmStatus) {
   LOGGING;
   USBDMStatus_t status;

   if (bdmOptions.targetType == T_ARM) {
      USBDM_ControlPins(PIN_RESET_LOW);                   // Leave RESET low during connect
   }
   else if (bdmOptions.targetType == T_CFVx) {
      USBDM_ControlPins(PIN_BKPT_LOW|PIN_RESET_3STATE);   // Release RESET (BKPT stays low)
      UsbdmSystem::milliSleep(bdmOptions.resetReleaseInterval);        // Make sure BKPT/BKGD are seen after reset
      USBDM_ControlPins(PIN_RELEASE);                     // Release all pins
      UsbdmSystem::milliSleep(bdmOptions.resetRecoveryInterval);       // Give target time to recover from reset
   }
   else {
      USBDM_ControlPins(PIN_BKGD_LOW|PIN_RESET_3STATE);   // Release RESET (BKGD stays low)
      UsbdmSystem::milliSleep(bdmOptions.resetReleaseInterval);        // Make sure BKPT/BKGD are seen after reset
      USBDM_ControlPins(PIN_RELEASE);                     // Release all pins
      UsbdmSystem::milliSleep(bdmOptions.resetRecoveryInterval);       // Give target time to recover from reset
   }

   // Get status twice to clear spurious reset flag
   getBDMStatus(&status);
   USBDM_ErrorCode rc = getBDMStatus(&status);
   if (usbdmStatus != NULL) {
      *usbdmStatus = status;
   }
   if (rc != BDM_RC_OK) {
      // Fatal error
      log.error("USBDM_GetBDMStatus() failed!\n");
      return rc;
   }
   // Retry connection
   rc = targetConnectWithDelayedConfirmation(retryDelayedCheck);  // Try connect again

   USBDM_ControlPins(PIN_RELEASE);                     // Release all pins
   UsbdmSystem::milliSleep(bdmOptions.resetRecoveryInterval);       // Give target time to recover from reset
   return rc;
}

BdmInterfaceCommon::RetryMode BdmInterfaceCommon::getInitialConnectRetryMode() {
   return initialConnectRetryMode;
}

BdmInterfaceCommon::RetryMode BdmInterfaceCommon::getSoftConnectRetryMode() {
   return softConnectRetryMode;
}

USBDM_ErrorCode BdmInterfaceCommon::targetConnectWithRetry(BdmInterfaceCommon::RetryMode retry) {
   return targetConnectWithRetry((USBDMStatus_t*)0, retry);
}

//! Connects to Target (RS08/HCS08/HCS12/CFV1/CFVx only)
//!
//! @note If there are connection problems, the user may be prompted to cycle
//!       the target power on some targets.
//!
//! @param usbdmStatus Current status of the BDM, may be NULL if not needed.
//! @param retryMode   How hard to retry \n
//!     The following are silent retries: \n
//!       retryNever      - give up after basic attempt, target state not affected \n
//!      +retryByReset    - quietly retry after hardware reset (if supported by target and allows debug entry). May be combined with others. \n
//!       retryNotPartial - give up quietly if device may be secured (BDM_RC_SECURED or BDM_RC_BDM_EN_FAILED) \n
//!     The following is interactive:\n
//!       retryAlways     - retry with dialogue prompt to user \n
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode BdmInterfaceCommon::targetConnectWithRetry(USBDMStatus_t *usbdmStatus, RetryMode retryMode) {
   LOGGING_X;
   log.print("%s\n", getConnectionRetryName(retryMode));

   USBDM_ErrorCode rc;

   USBDMStatus_t status;
   rc = getBDMStatus(&status);
   if (usbdmStatus != NULL) {
      *usbdmStatus = status;
   }
   if (rc != BDM_RC_OK) {
      log.error("getBDMStatus() failed\n");
      return rc; // Fatal error
   }
   //=========================================================
   //  Basic connect
   rc = targetConnectWithDelayedConfirmation(retryMode);
   if (rc == BDM_RC_OK) {
      if (!extendedRetry)
         log.print("Enabling Extended Retry\n");
      extendedRetry = true;
      return rc;
   }
   // Quietly retry once
   rc = targetConnectWithDelayedConfirmation(retryMode);
   if (rc == BDM_RC_OK) {
      if (!extendedRetry)
         log.print("Enabling Extended Retry\n");
      extendedRetry = true;
      return rc;
   }
   //===============================================
   // Connection has at least partially failed

   // Don't retry at all - silently fail
   if ((retryMode&retryMask) == retryNever) {
      log.error("Failed - No retries, rc = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }

   if (bdmOptions.targetType == T_CFVx) {
      // Target may be in low power mode
      // This will only work if an interrupt or similar
      // wakes the target while BKGD is low.
      // BKPT should wake the target but appears not to work if actually in
      // low power mode as opposed to just stopped
      USBDM_ControlPins(PIN_BKPT_LOW); // Assert BKPT
      UsbdmSystem::milliSleep(100);
      USBDM_ControlPins(PIN_RELEASE); // Release BKPT
      rc = USBDM_Connect();
      if (rc == BDM_RC_OK) {
         return rc;
      }
   }

   if ((bdmOptions.targetType == T_RS08) || (bdmOptions.targetType == T_HCS08) || (bdmOptions.targetType == T_CFV1)) {
      if (retryMode & retryByReset) {
         // These targets may suffer from Watchdog problems - try multiple resets
         log.error("Failed - Trying multiple resets, (rc = %s)\n", USBDM_GetErrorString(rc));
         USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
         USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
         rc = targetConnectWithDelayedConfirmation(retryMode);
         if (rc == BDM_RC_OK) {
            log.error("Success - After multiple resets\n");
            return rc;
         }
         USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
         USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
         rc = targetConnectWithDelayedConfirmation(retryMode);
         if (rc == BDM_RC_OK) {
            log.error("Success - After multiple resets\n");
            return rc;
         }
      }
   }
   // Don't retry for 'special cases' - silently fail
   if ((retryMode&retryMask) == retryNotPartial) {
      switch (rc) {
      case BDM_RC_BDM_EN_FAILED:
      case BDM_RC_SECURED:
         log.error("Failed - No retry for special cases, rc = %s\n", USBDM_GetErrorString(rc));
         return rc;
      default:
         break;
      }
   }
   // retryAlways or not a special case

   // Inform user of error and prompt for retry
   if (extendedRetry) {
      // Update target status
      getBDMStatus(&status);
      // Connection failure - retry
      int getYesNo;
      do {
         string message;
         long style = (long)(YES_NO|YES_DEFAULT|ICON_QUESTION);
         log.error("Retry, reason = %s\n", USBDM_GetErrorString(rc));
         if (bdmOptions.targetType == T_CFVx) {
            USBDM_ControlPins(PIN_BKPT_LOW|PIN_RESET_LOW); // Set BKPT & RESET low
         }
         else if (bdmOptions.targetType == T_ARM) {
            USBDM_ControlPins(PIN_RESET_LOW); // Set RESET low
         }
         else {
            USBDM_ControlPins(PIN_BKGD_LOW|PIN_RESET_LOW); // Set BKGD & RESET low
         }
         if (retryMode&retryByPower) {
            // Try power cycle first
            USBDM_SetTargetVdd(BDM_TARGET_VDD_DISABLE);
            UsbdmSystem::milliSleep(bdmOptions.powerOffDuration);
            USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
            UsbdmSystem::milliSleep(bdmOptions.powerOnRecoveryInterval);
            rc = retryConnection(usbdmStatus);
            if (rc == BDM_RC_OK) {
               break;
            }
         }
         // Check for 'interesting cases'
         if (status.power_state == BDM_TARGET_VDD_NONE) {
            message = "Target Vdd supply interrupted.\n\n"
                  "Please restore power to the target.\n\n"
                  "Retry connection?";
         }
         else if (status.reset_recent == RESET_DETECTED) {
            message = "Target RESET detected (watchdog?).\n\n"
                  "Please cycle power to the target.\n\n"
                  "Retry connection?";
         }
         else if (rc == BDM_RC_BDM_EN_FAILED) {
            message = "Enabling BDM interface on target failed.\n"
                  "The target may be secured.\n"
                  "(Use stand-alone programmer to mass erase if necessary)\n\n"
                  "Please cycle power to the target.\n\n"
                  "Retry connection?";
         }
         else if ((bdmOptions.targetType == T_CFVx) || (bdmOptions.targetType == T_HCS12)) {
            // Target supports guaranteed connection after Hardware reset
            // No need to prompt user to cycle power
            message = "Connection with the target has failed.\n\n"
                  "Target reset done.\n\n"
                  "Retry connection?";
         }
         else if (bdmOptions.cycleVddOnConnect) {
            // Target may require power cycle for guaranteed connection
            message = "Connection with the target has failed.\n\n"
                  "Target power has been cycled.\n\n"
                  "Retry connection?";
            }
         else {
            // Prompt user to cycle power as it may be necessary for some targets
            message = "Connection with the target has failed.\n\n"
                  "Please cycle power to the target.\n\n"
                  "Retry connection?";
         }
         getYesNo = callback(message,
               "USBDM - Target Connection Failure",
               style
         );
         rc = retryConnection(usbdmStatus);
      } while ((rc != BDM_RC_OK) && (getYesNo == YES));
   }
   if (rc != BDM_RC_OK) {
      log.error("Failed, (disabling Extended Retry)\n");
   }
   // Only enable re-try if successful to prevent nagging
   extendedRetry = (rc == BDM_RC_OK);
   return rc;
}

//===================================================================
//! Displays a dialogue with suitable error message and prompts
//! to retry
//!
//! @param rc - error code for message look up
//!
//! @return Response from dialogue (Retry = wxNO, wxYES)
//!
int BdmInterfaceCommon::handleError(USBDM_ErrorCode rc) {
   LOGGING_Q;
   int getYesNo;

   log.print("handleError(%d (%s))\n", rc, USBDM_GetErrorString(rc));

   switch (rc) {
      case BDM_RC_UNKNOWN_TARGET:
         getYesNo = callback("USBDM interface does not support target device.\n\n"
               "Change BDM and Retry?",
               "USBDM - BDM Not Suitable",
               YES_NO|YES_DEFAULT|ICON_QUESTION
         );
         break;
      case BDM_RC_NO_USBDM_DEVICE:
         getYesNo = callback("No suitable USBDM interface was found.\n\n"
               "Retry?",
               "USBDM - BDM Not Found",
               YES_NO|YES_DEFAULT|ICON_QUESTION
         );
         break;
      case BDM_RC_VDD_NOT_PRESENT:
         getYesNo = callback("The target appears to have no power.\n\n"
               "Please supply power to the target.\n\n"
               "Retry?",
               "USBDM - No Target Power",
               YES_NO|YES_DEFAULT|ICON_QUESTION
         );
         break;
      case BDM_RC_BDM_EN_FAILED:
         getYesNo = callback("Enabling BDM interface on target failed.\n"
               "The target may be secured.\n\n"
               "Retry?",
               "USBDM - Target Connection Failure",
               YES_NO|YES_DEFAULT|ICON_QUESTION
         );
         break;
      default: {
         std::string s;
         s += "An error occurred while accessing the BDM.\n\n"
               "Reason: ";
         s += USBDM_GetErrorString(rc);
         s += "\n\n"
               "Please cycle power to the target\n\n"
               "Retry?";
         getYesNo = callback(s.c_str(),
               "USBDM - Error",
               YES_NO|YES_DEFAULT|ICON_QUESTION
         );
         break;
      }
   }
   log.print("(%d (%s)) => Retry = %s\n", rc, USBDM_GetErrorString(rc), (getYesNo==YES)?"Yes":"No");
   return getYesNo;
}

//===================================================================
//! Sets target MCU type with retry
//!
//! @param targetType type of target
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
//! @note  The user may be prompted to supply target power.
//! @note  The user is alerted to any problems.
//!
USBDM_ErrorCode BdmInterfaceCommon::setTargetTypeWithRetry() {
   LOGGING_Q;
   USBDM_ErrorCode rc;
   int getYesNo = NO;
   int firstTryFlag = true;

   log.print("%s\n", getTargetTypeName(bdmOptions.targetType));
   do {
      rc  = USBDM_SetTargetType(bdmOptions.targetType);
      if (firstTryFlag && (rc == BDM_RC_VDD_NOT_PRESENT)) {
         // Target power can sometimes take a long while to rise
         // Give it another second to reduce 'noise'
         UsbdmSystem::milliSleep(1000);
         rc = USBDM_SetTargetType(bdmOptions.targetType);
         firstTryFlag = false;
      }
      if (rc == BDM_RC_OK) {
         // Check for target power
         USBDMStatus_t status;
         rc = USBDM_GetBDMStatus(&status);
         if ((rc = BDM_RC_OK) && (status.power_state == BDM_TARGET_VDD_NONE)) {
            rc = BDM_RC_VDD_NOT_PRESENT;
         }
      }
      if (rc != BDM_RC_OK) {
         getYesNo = handleError(rc);
      }
   } while ((rc != BDM_RC_OK) && (getYesNo == YES));

   if (bdmOptions.targetType == T_ARM) {
      // Get status to clear reset flag on possible power-up
      USBDMStatus_t status;
      USBDM_GetBDMStatus(&status);
   }

   // Only enable re-try if successful to stop nagging
   extendedRetry = (rc == BDM_RC_OK);

   return rc;
}

/*!
 * Converts a UTF-16-LE to a UTF-8 C string
 *
 * @param source - the UTF16LE string to convert
 *
 * @return source converted to a C string
 *
 * @note - Uses a static buffer so value should be used immediately
 */
static const char *utf16leToUtf8(const char *source) {
   const  uint8_t  *inPtr  = (const uint8_t*) source;
   static uint8_t  buffer[100];
   uint8_t  *outPtr = buffer;
   uint16_t utf16leValue;

   while ((*inPtr != 0) && (outPtr < (buffer+100))) {
      utf16leValue  = *inPtr++;
      utf16leValue += *inPtr++<<8;
      if (utf16leValue < 0x80) {  // 1-byte
         *outPtr++ = (uint8_t)utf16leValue;
      }
      else if (utf16leValue <0x0800) {   // 2-byte
         *outPtr++ = (uint8_t)(0xC0 + (utf16leValue>>6));
         *outPtr++ = (uint8_t)(0x80 + (utf16leValue&0x3F));
      }
      else {   // 3-byte
         *outPtr++ = (uint8_t)(0xE0 + (utf16leValue>>12));
         *outPtr++ = (uint8_t)(0x80 + ((utf16leValue>>6)&0x3F));
         *outPtr++ = (uint8_t)(0x80 + (utf16leValue&0x3F));
      }
   }
   // Make sure '\0' terminated
   if (outPtr < (buffer+sizeof(buffer)/sizeof(buffer[0])))
      *outPtr = 0;
   buffer[sizeof(buffer)-1] = 0;
   return (const char *)buffer;
}

USBDM_ErrorCode BdmInterfaceCommon::readBDMSerialNumber(string &serialNumber) {
   const char *serialNumberPtr;
   USBDM_ErrorCode rc;

   rc = USBDM_GetBDMSerialNumber(&serialNumberPtr);
   if (rc != BDM_RC_OK)
      return rc;
   serialNumber = string(utf16leToUtf8(serialNumberPtr));
   return BDM_RC_OK;
}

USBDM_ErrorCode BdmInterfaceCommon::readBDMDescription(string &description) {
   const char *descriptionPtr;
   USBDM_ErrorCode rc;

   rc = USBDM_GetBDMDescription(&descriptionPtr);
   if (rc != BDM_RC_OK)
      return rc;
   description = string(utf16leToUtf8(descriptionPtr));
   return BDM_RC_OK;
}

//! Create a list of connected BDMs
//!
USBDM_ErrorCode BdmInterfaceCommon::findBDMs(vector<BdmInformation> &bdmInformation) {
   LOGGING;

   USBDM_Close(); // Close any open devices

   USBDM_Init();

   unsigned int deviceCount;
   USBDM_ErrorCode rc = USBDM_FindDevices(&deviceCount);

   log.print("%d devices located, rc = %s\n", deviceCount, USBDM_GetErrorString(rc));

   bdmInformation.clear();

   if (deviceCount==0) {
      log.print("No devices\n");
      return BDM_RC_NO_USBDM_DEVICE;
   }
   int targetCapabilityMask = 0x0000;
   switch(bdmOptions.targetType) {
      case T_HC12      : targetCapabilityMask =  BDM_CAP_HCS12;     break;
      case T_S12Z      : targetCapabilityMask =  BDM_CAP_S12Z;      break;
      case T_HCS08     : targetCapabilityMask =  BDM_CAP_HCS08;     break;
      case T_RS08      : targetCapabilityMask =  BDM_CAP_RS08;      break;
      case T_MC56F80xx : targetCapabilityMask =  BDM_CAP_DSC ;      break;
      case T_CFV1      : targetCapabilityMask =  BDM_CAP_CFV1;      break;
      case T_CFVx      : targetCapabilityMask =  BDM_CAP_CFVx;      break;
      case T_JTAG      : targetCapabilityMask =  BDM_CAP_JTAG;      break;
      case T_ARM_JTAG  : targetCapabilityMask =  BDM_CAP_ARM_JTAG;  break;
      case T_ARM_SWD   : targetCapabilityMask =  BDM_CAP_ARM_SWD;   break;
      case T_ARM       : targetCapabilityMask =  BDM_CAP_ARM_JTAG|
                                                 BDM_CAP_ARM_SWD;   break;
      default :
         break;
   }
   rc = BDM_RC_NO_USBDM_DEVICE; // Assume no devices

   for (unsigned index=0; index<deviceCount; index++) {
      BdmInformation bdmInfo(index, "Device not responding or busy", "Unknown");
      do {
         USBDM_ErrorCode bdmRc = USBDM_Open(index);
         if (bdmRc != BDM_RC_OK) {
            log.error("USBDM_Open(BDM #%d) failed, rc = %s\n", index, USBDM_GetErrorString(bdmRc));
            bdmInfo.setSuitable(bdmRc);
            break;
         }
         USBDM_bdmInformation_t theBdmInfo = {(unsigned)sizeof(theBdmInfo)};
         bdmRc = USBDM_GetBdmInformation(&theBdmInfo);
         if (bdmRc != BDM_RC_OK) {
            log.error("USBDM_GetBdmInformation(BDM #%d) failed, rc = %s\n", index, USBDM_GetErrorString(bdmRc));
            bdmInfo.setSuitable(bdmRc);
            break;
         }
         bdmInfo.setInfo(theBdmInfo);
         string tempString;
         bdmRc = readBDMDescription(tempString);
         if (bdmRc != BDM_RC_OK) {
            log.error("USBDM_GetBDMDescription(BDM #%d) failed, rc = %s\n", index, USBDM_GetErrorString(bdmRc));
            bdmInfo.setSuitable(bdmRc);
            break;
         }
         bdmInfo.setDescription(tempString);
         // Check capabilities against target needs
         if ((theBdmInfo.capabilities & targetCapabilityMask) == 0) {
            log.print("BDM #%d is not suitable for target\n", index);
            bdmInfo.setSerialNumber("BDM Doesn't support target");
            bdmInfo.setSuitable(BDM_RC_UNKNOWN_TARGET);
            break;
         }
         log.print("USBDM_GetCapabilities(BDM #%d) =>  0x%4.4X \n", index, theBdmInfo.capabilities);
         log.print("USBDM_GetCapabilities() => seeking 0x%4.4X \n", targetCapabilityMask);
         log.print("USBDM_GetCapabilities() => targetType = %d \n", bdmOptions.targetType);

         // Already have capabilities but this is used to check BDM firmware compatibility
         HardwareCapabilities_t bdmCapabilities;
         bdmRc = USBDM_GetCapabilities(&bdmCapabilities);
         if (bdmRc != BDM_RC_OK) {
            log.error("USBDM_GetCapabilities(BDM #%d) failed, rc = %s\n", index, USBDM_GetErrorString(bdmRc));
            if (bdmRc == BDM_RC_WRONG_BDM_REVISION) {
               bdmInfo.setSerialNumber("Wrong Firmware Version");
            }
            bdmInfo.setSuitable(bdmRc);
            break;
         }
         bdmInfo.setSuitable(BDM_RC_OK);
         // At least one suitable device
         rc = BDM_RC_OK;
         // Get serial number
         bdmRc = readBDMSerialNumber(tempString);
         if (bdmRc != BDM_RC_OK) {
            // Log error but ignore
            log.error("USBDM_GetBDMSerialNumber(BDM #%d) failed, rc = %s\n", index, USBDM_GetErrorString(bdmRc));
            break;
         }
         bdmInfo.setSerialNumber(tempString);
      } while (false);
      USBDM_Close();
      if (bdmInfo.getSuitable() == BDM_RC_DEVICE_OPEN_FAILED) {
         //Todo - This is a hack to handle LIBUSB returning phantom devices in Windows 8.1
         log.error("Discarding BDM #%d\n", index);
         continue;
      }
      bdmInformation.push_back(bdmInfo);
   }
   return rc;
}

/*
 * Open a BDM with preference given to a particular device (indicated by serial number)
 *
 * @param targetType    BDM are filtered by support for this target
 * @param serialnumber  Serial number of BDM to open preferentially
 * @param mustMatch     Forces requirement that the serial number match
 *
 * @note - Will open the first suitable BDM if the specified one is not located.
 *
 */
USBDM_ErrorCode BdmInterfaceCommon::openBySerialNumber(const string &serialnumber, bool mustMatch) {
   LOGGING;
   log.print("(Type=%s, SN=%s, mustMatch=%s)\n", getTargetTypeName(bdmOptions.targetType), serialnumber.c_str(), mustMatch?"T":"F");

   // Enumerate all attached BDMs
   vector<BdmInformation> bdmInformation;
   findBDMs(bdmInformation);

   if (bdmInformation.empty()) {
      // No devices at all found
      log.print("No devices found\n");
      return BDM_RC_NO_USBDM_DEVICE;
   }

   // Search for preferred and/or suitable BDM
   vector<BdmInformation>::iterator it                  = bdmInformation.begin();
   vector<BdmInformation>::iterator firstSuitableDevice = bdmInformation.end();

   USBDM_ErrorCode rc = BDM_RC_NO_USBDM_DEVICE;
   while (it != bdmInformation.end()) {
      if (it->getSerialNumber().compare(serialnumber) == 0) {
         // Found preferred device
         log.print("Found preferred BDM #%d, Desc=\'%s\', SN=\'%s\'\n",
               it->getDeviceNumber(), it->getDescription().c_str(), it->getSerialNumber().c_str());
         if (it->isSuitable()) {
            // OK, use this one
            log.print("Opening preferred BDM #%d, Desc=\'%s\', SN=\'%s\'\n",
                  it->getDeviceNumber(), it->getDescription().c_str(), it->getSerialNumber().c_str());
            return USBDM_Open(it->getDeviceNumber());
         }
         if (mustMatch) {
            // Required BDM is not suitable - return reason
            log.print("Rejecting preferred BDM #%d, Desc=\'%s\', SN=\'%s\' as unsuitable, rc = %s\n",
                  it->getDeviceNumber(), it->getDescription().c_str(), it->getSerialNumber().c_str(),
                  USBDM_GetErrorString(it->getSuitable()));
            return it->getSuitable();
         }
         // Keep looking
      }
      if (it->isSuitable()) {
         log.print("First suitable but not preferred BDM found = #%d, Desc=\'%s\', SN=\'%s\'\n",
               it->getDeviceNumber(), it->getDescription().c_str(), it->getSerialNumber().c_str());
         if (firstSuitableDevice == bdmInformation.end())
            // Remember first suitable device found
            firstSuitableDevice = it;
      }
      it++;
   }
   if (mustMatch) {
      // Required BDM not found
      log.error("No matching BDM found\n");
      return BDM_RC_SELECTED_BDM_NOT_FOUND;
   }
   if (firstSuitableDevice == bdmInformation.end()) {
      log.error("No suitable BDM found, first/only found = %s\n", bdmInformation.begin()->getSerialNumber().c_str());
      // Return reason why first device is unsuitable
      return bdmInformation.begin()->getSuitable();
   }
   // Suitable but not preferred device found
   log.print("Opening first suitable BDM #%d, Desc=\'%s\', SN=\'%s\'\n",
         firstSuitableDevice->getDeviceNumber(),
         firstSuitableDevice->getDescription().c_str(),
         firstSuitableDevice->getSerialNumber().c_str());
   rc = USBDM_Open(firstSuitableDevice->getDeviceNumber());
   log.print("rc = %s\n", USBDM_GetErrorString(rc));
   return rc;
}

USBDM_ErrorCode BdmInterfaceCommon::openBySerialNumberWithRetry(const string &serialnumber, bool mustMatch) {
   LOGGING;
   USBDM_ErrorCode rc;
   int getYesNo = NO;
   int attemptCount = 0;
   do {
      log.print("attempt = %d\n", attemptCount++);
      rc = openBySerialNumber(serialnumber, mustMatch);
      if (rc != BDM_RC_OK) {
         getYesNo = handleError(rc);
      }
   } while ((rc != BDM_RC_OK) && (getYesNo == YES));
   return rc;
}

/**
 * Pass options to target BDM (assumed already open)
 */
USBDM_ErrorCode  BdmInterfaceCommon::setOptionsWithRetry(USBDM_ExtendedOptions_t *bdmOptions) {
   LOGGING;
   USBDM_ErrorCode rc;

   // Save copy of options
   this->bdmOptions = *bdmOptions;

   // Power cycle is done by Interface not BDM
   USBDM_ExtendedOptions_t options = *bdmOptions;
   options.cycleVddOnConnect = false;
   int getYesNo = NO;
   do {
      rc = USBDM_SetExtendedOptions(&options);
      if (rc != BDM_RC_OK) {
         getYesNo = handleError(rc);
      }
   } while ((rc != BDM_RC_OK) && (getYesNo == YES));
   return rc;
}

char const *BdmInterfaceCommon::getConnectionRetryName(RetryMode mode) {
   static char buff[150] = "";

   switch (mode & retryMask) {
      case retryAlways     : strcpy(buff,"ALWAYS");      break;
      case retryNever      : strcpy(buff,"NEVER");       break;
      case retryNotPartial : strcpy(buff,"NOTPARTIAL");  break;
      default              : strcpy(buff,"UNKNOWN!!!");  break;
   }
   if (mode & retryWithInit) {
      strcat(buff,"+INIT");
   }
   if (mode & retryByPower) {
      strcat(buff,"+POWER");
   }
   if (mode & retryByReset) {
      strcat(buff,"+RESET");
   }
   if (mode & retryDelayedCheck) {
      strcat(buff,"+DELAYCHECK");
   }
   return buff;
}

long BdmInterfaceCommon::callback(std::string message, std::string  caption, long style) {
   //   LOGGING_Q;

   if ((callbackPtr == 0) && (wxPlugin == 0)) {
      // Create default callback on 1st use
      wxPlugin = WxPluginFactory::createWxPlugin();
   }

   long rc = NO;
   //   UsbdmSystem::Log::print("\n%s\n%s\n", caption.c_str(), message.c_str());
   if (callbackPtr != 0) {
      //      log.print("Using external callback\n");
      rc = (*callbackPtr)(message, caption, style);
   }
   if (wxPlugin != 0) {
      //      log.print("Using wxPlugin\n");
      rc = wxPlugin->display(message, caption, style);
   }
   //   UsbdmSystem::Log::print("rc = 0x%lX\n", rc);
   return rc;
}

/*
 * ====================================================================================================================
 */
USBDM_ErrorCode BdmInterfaceCommon::setTargetVdd(TargetVddSelect_t targetVdd) {
   return USBDM_SetTargetVdd(targetVdd);
}
USBDM_ErrorCode BdmInterfaceCommon::setTargetVpp(TargetVppSelect_t targetVpp) {
   return USBDM_SetTargetVpp(targetVpp);
}
USBDM_ErrorCode BdmInterfaceCommon::controlPins(unsigned int control, unsigned int *status) {
   return USBDM_ControlPins(control, status);
}
USBDM_ErrorCode BdmInterfaceCommon::getCapabilities(HardwareCapabilities_t *capabilities) {
   return USBDM_GetCapabilities(capabilities);
}
USBDM_ErrorCode BdmInterfaceCommon::writeControlReg(unsigned int controlValue) {
   return USBDM_WriteControlReg(controlValue);
}
USBDM_ErrorCode BdmInterfaceCommon::readStatusReg(unsigned long *bdmStatusReg) {
   return USBDM_ReadStatusReg(bdmStatusReg);
}
USBDM_ErrorCode BdmInterfaceCommon::bdmCommand(unsigned txSize, unsigned rxSize, uint8_t data[]) {
   return USBDM_BDMCommand(txSize, rxSize, data);
}
USBDM_ErrorCode BdmInterfaceCommon::connect() {
   return USBDM_Connect();
};
USBDM_ErrorCode BdmInterfaceCommon::basicConnect() {
   return USBDM_BasicConnect();
};
USBDM_ErrorCode BdmInterfaceCommon::reset(TargetMode_t mode=(TargetMode_t)(RESET_DEFAULT|RESET_NORMAL)) {
   return USBDM_TargetReset(mode);
};
USBDM_ErrorCode BdmInterfaceCommon::getSpeedHz(unsigned long int *speed) {
   return USBDM_GetSpeedHz(speed);
};
USBDM_ErrorCode BdmInterfaceCommon::setSpeedHz(unsigned long int speed) {
   return USBDM_SetSpeed(speed);
}
USBDM_ErrorCode BdmInterfaceCommon::halt() {
   return USBDM_TargetHalt();
};
USBDM_ErrorCode BdmInterfaceCommon::go() {
   return USBDM_TargetGo();
};
USBDM_ErrorCode BdmInterfaceCommon::step() {
   return USBDM_TargetStep();
};
USBDM_ErrorCode BdmInterfaceCommon::writeReg(unsigned int reg, unsigned long value) {
   return USBDM_WriteReg(reg, value);
};
USBDM_ErrorCode BdmInterfaceCommon::writeCReg(unsigned int reg, unsigned long value) {
   return USBDM_WriteCReg(reg, value);
};
USBDM_ErrorCode BdmInterfaceCommon::writeDReg(unsigned int reg, unsigned long value) {
   return USBDM_WriteDReg(reg, value);
};
USBDM_ErrorCode BdmInterfaceCommon::readReg(unsigned int reg, unsigned long *value) {
   return USBDM_ReadReg(reg, value);
};
USBDM_ErrorCode BdmInterfaceCommon::readCReg(unsigned int reg, unsigned long *value) {
   return USBDM_ReadCReg(reg, value);
};
USBDM_ErrorCode BdmInterfaceCommon::readDReg(unsigned int reg, unsigned long *value) {
   return USBDM_ReadDReg(reg, value);
};
USBDM_ErrorCode BdmInterfaceCommon::readMemory( unsigned memorySpace, unsigned byteCount, unsigned address, unsigned char *data) {
   return USBDM_ReadMemory(memorySpace, byteCount, address, data);
};
USBDM_ErrorCode BdmInterfaceCommon::writeMemory( unsigned memorySpace, unsigned byteCount, unsigned address, unsigned const char *data) {
   return USBDM_WriteMemory(memorySpace, byteCount, address, data);
};
USBDM_ErrorCode BdmInterfaceCommon::writePC(unsigned long regValue) {
   return BDM_RC_CF_ILLEGAL_COMMAND;
}
USBDM_ErrorCode BdmInterfaceCommon::readPC(unsigned long *regValue) {
   *regValue = 0x0BADF00D;
   return BDM_RC_CF_ILLEGAL_COMMAND;
}

USBDM_ErrorCode BdmInterfaceCommon::jtagExecuteSequence(uint8_t length, const uint8_t *sequence, uint8_t inLength, uint8_t *inBuffer) {
   return USBDM_JTAG_ExecuteSequence(length, sequence, inLength, inBuffer);
}
USBDM_ErrorCode BdmInterfaceCommon::jtagRead( uint8_t bitCount, uint8_t exit, uint8_t *buffer) {
   return USBDM_JTAG_Read(bitCount, exit, buffer);
}
USBDM_ErrorCode BdmInterfaceCommon::jtagReadWrite( uint8_t bitCount, uint8_t exit, const uint8_t *outBuffer, uint8_t *inBuffer) {
   return USBDM_JTAG_ReadWrite(bitCount, exit, outBuffer, inBuffer);
}
USBDM_ErrorCode BdmInterfaceCommon::jtagReset() {
   return USBDM_JTAG_Reset();
}
USBDM_ErrorCode BdmInterfaceCommon::jtagSelectShift(uint8_t mode) {
   return USBDM_JTAG_SelectShift(mode);
}
USBDM_ErrorCode BdmInterfaceCommon::jtagWrite(uint8_t bitCount, uint8_t exit, const uint8_t *buffer) {
   return USBDM_JTAG_Write(bitCount, exit, buffer);
}
USBDM_ErrorCode BdmInterfaceCommon::getIdcode(unsigned int *regValue) {
   *regValue = 0x0BADF00D;
   return BDM_RC_CF_ILLEGAL_COMMAND;
}
USBDM_ErrorCode  BdmInterfaceCommon::getStatus(unsigned int *status) {
   return BDM_RC_CF_ILLEGAL_COMMAND;
}
USBDM_ErrorCode BdmInterfaceCommon::readMultipleRegs(unsigned char regValueBuffer[], unsigned int startRegIndex, unsigned int endRegIndex) {
   return USBDM_ReadMultipleRegs(regValueBuffer, startRegIndex, endRegIndex);
}

USBDM_ErrorCode BdmInterfaceCommon::setProgrammingBdmOptions() {
   // BDM Options to be used with the target when Flash programming
   USBDM_ExtendedOptions_t bdmProgrammingOptions = {
         sizeof(USBDM_ExtendedOptions_t),
         bdmOptions.targetType,
   };

   // Get copy of current BDM options
   USBDM_ExtendedOptions_t bdmOptions = getBdmOptions();

   // Use default options for Flash programming.
   USBDM_GetDefaultExtendedOptions(&bdmProgrammingOptions);

   // Copy some settings
   bdmProgrammingOptions.targetVdd           = bdmOptions.targetVdd;
   bdmProgrammingOptions.interfaceFrequency  = bdmOptions.interfaceFrequency;
   bdmProgrammingOptions.hcs08sbdfrAddress   = bdmOptions.hcs08sbdfrAddress;
   return USBDM_SetExtendedOptions(&bdmProgrammingOptions);
}

USBDM_ErrorCode BdmInterfaceCommon::restoreBdmOptions() {
   return USBDM_SetExtendedOptions(&bdmOptions);
}

USBDM_ErrorCode BdmInterfaceCommon::setProgrammingMode(bool programmingMode) {
   LOGGING;
   log.error("Programming mode = %s\n", programmingMode?"on":"off");
   if (programmingMode) {
      return setProgrammingBdmOptions();
   }
   else {
      return restoreBdmOptions();
   }
}

/**
 * Send miscellaneous commands to BDM interface.
 *
 *  @param size     Size of Tx/Rx data buffer. Must be <= 18.
 *  @param [in/out] usb_data - Command for BDM \n
 *                   Send Format    [command, data...]
 *                   Receive Format [result...]
 *
 *  @return
 *      BDM_RC_OK    => OK \n
 *      other        => Error code - see \ref USBDM_ErrorCode
 */
USBDM_ErrorCode BdmInterfaceCommon::miscellaneousCommand(unsigned size, uint8_t usb_data[]) {
   LOGGING;
   log.error(" %s, 0x%08X\n", getDebugCommandName(usb_data[0]), (size>1)?usb_data[1]:0);

   if (size>18) {
      size = 18;
   }
   uint8_t buffer[20] = {0};
   memcpy(buffer+2, usb_data, size);

   return USBDM_Debug(buffer);
}

/**
 * Enable or disable serial interface on BDM
 *
 * @param enable true to enable
 *
 * @return Previous state off serial interface
 */
bool BdmInterfaceCommon::enableSerialInterface(bool enable) {
   LOGGING;

   log.error("Serial interface mode = %s\n", enable?"on":"off");

   bool old = serialInterfaceEnabled;

   serialInterfaceEnabled = enable;

   if (enable) {
      uint8_t cmd[] = {BDM_DBG_SERIAL_ON};
      miscellaneousCommand(sizeof(cmd), cmd);
   }
   else {
      uint8_t cmd[] = {BDM_DBG_SERIAL_OFF};
      miscellaneousCommand(sizeof(cmd), cmd);
   }
   return old;
}

/*
 * ====================================================================================================================
 */
#if 0
enum {
   creg = 1<<16,
   dreg = 1<<17,
};

static const unsigned int cfv1RegisterMap[] = {
      0,
      CFV1_CRegPC|creg,
      CFV1_RegSP,
      CFV1_CRegSR|creg,
};
static const unsigned int cfvxRegisterMap[] = {
      0,
      CFVx_CRegPC|creg,
      CFVx_RegSP,
      CFVx_CRegSR|creg,
};
static const unsigned int armRegisterMap[] = {
      0,
      ARM_RegPC,
      ARM_RegSP,
      ARM_RegxPSR,
};

USBDM_ErrorCode USBDM_UnifiedReadReg(TargetType_t targetType, unsigned int regNo, unsigned long int *value) {
   if ((regNo==0) || (regNo>=(sizeof(cfv1RegisterMap)/sizeof(cfv1RegisterMap[0])))) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   unsigned int mappedRegno;

   switch (targetType) {
      case T_ARM:
      case T_ARM_JTAG:
      case T_ARM_SWD:
         mappedRegno = armRegisterMap[regNo];
         break;
      case T_CFV1:
         mappedRegno = cfv1RegisterMap[regNo];
         break;
      case T_CFVx:
         mappedRegno = cfvxRegisterMap[regNo];
         break;
      default:
         return BDM_RC_UNKNOWN_TARGET;
   }
   if (mappedRegno&creg) {
      return USBDM_ReadCReg(mappedRegno&~creg, value);
   }
   return USBDM_ReadReg(regNo, value);
}

USBDM_ErrorCode USBDM_UnifiedWriteReg(TargetType_t targetType, unsigned int regNo, unsigned long int value) {
   if ((regNo==0) || (regNo>=(sizeof(cfv1RegisterMap)/sizeof(cfv1RegisterMap[0])))) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   unsigned int mappedRegno;

   switch (targetType) {
      case T_ARM:
      case T_ARM_JTAG:
      case T_ARM_SWD:
         mappedRegno = armRegisterMap[regNo];
         break;
      case T_CFV1:
         mappedRegno = cfv1RegisterMap[regNo];
         break;
      case T_CFVx:
         mappedRegno = cfvxRegisterMap[regNo];
         break;
      default:
         return BDM_RC_UNKNOWN_TARGET;
   }
   if (mappedRegno&creg) {
      return USBDM_WriteCReg(mappedRegno&~creg, value);
   }
   return USBDM_WriteReg(regNo, value);
}
#endif

