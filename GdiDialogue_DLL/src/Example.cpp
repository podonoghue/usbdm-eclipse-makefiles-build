/*
 * Example.cpp
 *
 *  Created on: 8 Apr 2015
 *      Author: podonoghue
 */

#include "PluginFactory.h"
#include "UsbdmSystem.h"
#include "GdiDialoguePluginFactory.h"

#include "USBDM_API.h"
#include "MetrowerksInterface.h"
#include "DeviceData.h"
#include "FlashProgrammerFactory.h"
#include "AppSettings.h"
#include "BdmInterfaceFactory.h"

using namespace std;

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("ExampleApp.log", "Example Application");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
      UsbdmSystem::Log::closeLogFile();
   }
};

USBDM_ExtendedOptions_t bdmOptions;
FlashProgrammerPtr      flashProgrammer;
DeviceDataPtr           device;
BdmInterface::RetryMode initialConnectOptions   = BdmInterface::retryAlways;
BdmInterface::RetryMode softConnectOptions      = BdmInterface::retryAlways;
TargetType_t            targetType              = T_ARM;

//===================================================================
//! Does the following:
//!   - Initialises USBDM interface
//!   - Legacy  - Display USBDM Dialogue to obtain settings
//!   - Eclipse - Loads settings from Codewarrior
//!   - Loads device data from database
//!   - Opens BDM
//!   - Sets BDM options
//!   - Sets BDM target type
//!   - Sets up Flash programmer
//!
//!  Displays an error dialogue on failure. \n
//!  May prompt to retry connection for certain errors.
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_ErrorCode initialiseBDMInterface(bool forceDisplay) {
   LOGGING;
   USBDM_ErrorCode rc;

   // Load App settings
   AppSettingsPtr appSettings(new AppSettings("TestLegacyGDI.cfg", "Test GDI Legacy settings"));
   appSettings->load();

   BdmInterfacePtr bdmInterface = BdmInterfaceFactory::createInterface(targetType);

   GdiDialoguePluginPtr gdiDialoguePtr = GdiDialoguePluginFactory::createPlugin();

   rc = gdiDialoguePtr->execute(bdmInterface, appSettings, forceDisplay);

   if (rc != BDM_RC_OK) {
      USBDM_Exit();
      log.print("dialogue.execute() failed, reason = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }
   appSettings->save();
   bdmOptions = bdmInterface->getBdmOptions();

   // Cycle Vdd on connect is done by GDI instead of BDM H/W
   if ((bdmOptions.targetVdd != BDM_TARGET_VDD_OFF) && bdmOptions.cycleVddOnConnect) {
      initialConnectOptions = (BdmInterface::RetryMode)(BdmInterface::retryWithInit|BdmInterface::retryAlways|BdmInterface::retryByReset|BdmInterface::retryByPower|BdmInterface::retryDelayedCheck);
      softConnectOptions    = (BdmInterface::RetryMode)(BdmInterface::retryAlways|BdmInterface::retryByPower);
   }
   else {
      initialConnectOptions = (BdmInterface::RetryMode)(BdmInterface::retryWithInit|BdmInterface::retryAlways|BdmInterface::retryByReset|BdmInterface::retryDelayedCheck);
      softConnectOptions    = (BdmInterface::RetryMode)(BdmInterface::retryAlways);
   }
   // Tell BDM not to do it
   bdmOptions.cycleVddOnConnect = false;

   rc = bdmInterface->initBdm();

   if (rc != BDM_RC_OK) {
      USBDM_Exit();
      log.print("USBDM_Init() failed, reason = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }
   return rc;
}

int main(void) {
   OpenLog openLog;
   LOGGING;

   log.print("Result = %s\n", USBDM_GetErrorString(initialiseBDMInterface(false)));
   log.print("Result = %s\n", USBDM_GetErrorString(initialiseBDMInterface(true)));

   return 0;
}

