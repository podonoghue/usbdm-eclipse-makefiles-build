/*! \file
   \brief Entry points for USBDM library

   GDI_Common.cpp

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
-=====================================================================================================
|  May 30 2014 | Removed optimised ARM memory read/writes                          - pgo V4.10.6.150
|  Nov 09 2013 | Minor changes for security                                        - pgo V4.10.6.80
|  Oct 28 2013 | Added connect with RESET retry to targetConnecvt for ARM          - pgo V4.10.6.40
|  Dec 22 2012 | Improved Secured device handling & mass erase                     - pgo V4.10.4
|  Dec 21 2012 | Fixed Reset PC Hack in HCS08 & CFV1                               - pgo V4.10.4
|  Dec 21 2012 | Removed Mass Erase as separate operation                          - pgo V4.10.4
|  Nov 30 2012 | Changed logging                                                   - pgo V4.10.4
|  Oct  8 2012 | Modified ARM accesses to use maximum aligned sizes                - pgo V4.10.2
|  May  7 2012 | Changed to using RESET_DEFAULT for ARM in DiExecResetChild()      - pgo V4.9.5
|  Mar 30 2012 | Fixed block address error in DIMemoryWrite() when flashing        - pgo V4.9.4
|  Mar 30 2012 | Changed to USBDM_SetExtendedOptions() etc.                        - pgo V4.9.4
|  Mar 24 2012 | Added actions to PROCESS_DETACH (for DSC programmer)              - pgo V4.9.4
|  Jan 14 2012 | Ported to DSC                                                     - pgo V4.9
|  Jul 16 2011 | Extended TargetConnect strategies & Messages HCSxx                - pgo V4.7
|  Jul  3 2011 | Changes to DSC code in DLL                                        - pgo V4.7
|  Jul  3 2011 | Changes related to CFVx recovery from sleeping                    - pgo V4.7
|  Jul  2 2011 | Added halt/connect in DiExecResetChild() - HCS08                  - pgo V4.7
|  Jun 30 2011 | Added checks for WAIT/WFE states                                  - pgo V4.7
|  Jun 30 2011 | Re-arranged connection code to avoid spurious secured error       - pgo V4.7
|  Jun    2011 | Added autoconnect on DiGdiGetStatus                               - pgo
+============================================================================================
\endverbatim
*/

#ifndef LEGACY
//#define USE_MEE  // Experiment - only applicable to Eclipse
#endif

#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#ifdef __unix__
#include <dlfcn.h>
#define WXSTUB_DLL_NAME "libusbdm-wxStub.so"
#endif
#ifdef LEGACY
#include "AppSettings.h"
#include "GdiDialoguePluginFactory.h"
#else
#include "FlashImageFactory.h"
#endif
#include "Common.h"
#include "UsbdmSystem.h"
#include "Version.h"
#include "ArmDebug.h"
#include "USBDM_API.h"
#include "GDI_Common.h"
#include "GDI.h"
#include "Metrowerks.h"
#include "U32c.h"
#include "TargetDefines.h"
#include "DeviceData.h"
#include "MetrowerksInterface.h"
#include "Names.h"
#include "WxPlugin.h"
#include "FindWindow.h"
#include "BdmInterfaceFactory.h"
#include "Utils.h"
#include "WxPluginFactory.h"
#include "UsbdmWxConstants.h"

#if defined(GDI) && !defined(LEGACY)
/*
 * Flash programming is not supported on legacy targets
 * Programming is done by Codewarrior
 */
#define FLASH_PROGRAMMING 1
#endif

#ifdef FLASH_PROGRAMMING
#include "FlashProgrammerFactory.h"
#endif

#if TARGET == CFVx
#include "osbdm_defs/osbdm_cfv234.h"
#elif TARGET == CFV1
#include "osbdm_defs/osbdm_cfv1.h"
#elif TARGET == MC56F80xx
#include "USBDM_DSC_API.h"
//#include "DSC_Utilities.h"
#elif (TARGET == ARM)
#include "ArmDefinitions.h"
#elif !defined(TARGET)
#error "TARGET must be defined"
#endif

#include "MetrowerksInterface.h"

using namespace std;
using namespace UsbdmWxConstants;

// Nasty hack - records the first pc write to use as reset PC on future resets
bool            pcWritten            = false;
uint32_t        pcResetValue         = 0x000000;
bool            programmingSupported = false;
bool            forceMassErase       = false;
BdmInterfacePtr bdmInterface;

//============================================================================
#ifdef FLASH_PROGRAMMING

//!   Description of currently selected device
static DeviceDataPtr deviceData;

//!   Flash image for programming
static FlashImagePtr flashImage;

//!   Flash programmer instance
static FlashProgrammerPtr flashProgrammer;

#endif

// How hard to try to connect initially
BdmInterface::RetryMode initialConnectOptions = (BdmInterface::RetryMode)(BdmInterface::retryAlways|BdmInterface::retryWithInit|BdmInterface::retryByReset);

// How hard to try to connect after initial connection
BdmInterface::RetryMode softConnectOptions    = BdmInterface::retryNever;

#ifdef FLASH_PROGRAMMING
/**
 * Display messageBox
 */
static long displayDialogue(std::string message, std::string caption, long style) {
   WxPluginPtr p = WxPluginFactory::createWxPlugin();
   return p->display(message, caption, style);
}
#endif

/** Error handling */
DiReturnT   currentError       = DI_ERR_STATE; // No functions available until DiGdiInitIO() is called

const char *currentErrorString = "GDI Not opened";

//=====================================================================================
#ifdef LOG
static const char *returnStrings[] = {
   "DI_OK",                 //  = 0,
   "DI_ERR_STATE",          //  = 1,
   "DI_ERR_PARAM",          //  = 2,
   "DI_ERR_COMMUNICATION",  //  = 3,
   "DI_ERR_NOTSUPPORTED",   //  = 4,
   "DI_ERR_NONFATAL",       //  = 5,
   "DI_ERR_CANCEL",         //  = 6,
   "DI_ERR_FATAL",          //  = 7
};

/**
 * Get string describing error code
 *
 * @param returnCode
 */
const char *getGDIErrorString( DiReturnT returnCode) {
const char *errorString = "Unknown";

   if ((returnCode >= 0) &&
       ((unsigned)returnCode < (sizeof(returnStrings)/sizeof(returnStrings[0]))))
      errorString = returnStrings[returnCode];

   return errorString;
}
#else
/**
 * Get string describing error code
 *
 * @param returnCode
 */
const char *getGDIErrorString( DiReturnT returnCode) {
   return "";
}
#endif

/**
 *  Set error state
 *
 *  @param errorCode   - Error code identifying error type
 *  @param errorString - Error message (nullptr => use generic message)
 *
 *  @return errorCode passed as 1st parameter
 */
DiReturnT setErrorState(DiReturnT   errorCode,
                        const char *errorString) {

   currentError       = errorCode;
   currentErrorString = errorString;

   if ((errorString == nullptr) || (errorCode == DI_OK)) {
     // Add default message if specific message not already provided
     switch(errorCode) {
        case DI_OK :
           currentErrorString = ("No error");
           break;
        case DI_ERR_STATE :
           currentErrorString = ("GDI function called with incorrect GDI internal state");
           break;
        case DI_ERR_PARAM :
           currentErrorString = ("Illegal parameter to GDI function");
           break;
        case DI_ERR_COMMUNICATION :
           currentErrorString = ("Communication error in GDI function");
           break;
        case DI_ERR_NOTSUPPORTED  :
           currentErrorString = ("GDI Function not supported");
           break;
        case DI_ERR_NONFATAL :
           currentErrorString = ("Non-fatal error in GDI function");
           break;
        case DI_ERR_CANCEL :
           currentErrorString = ("GDI function cancelled");
           break;
        case DI_ERR_FATAL :
           currentErrorString = ("Fatal error in GDI function");
           break;
     }
   }
   if (errorCode != DI_OK) {
      UsbdmSystem::Log::print("setErrorState(%s (errorCode=%d))\n", currentErrorString, errorCode); \
   }
   return currentError;
}

/**
 *  Set error state
 *
 *  @param errorCode GDI error code identifying error type
 *  @param rc        USBDM error code
 *
 *  @return errorCode passed as 1st parameter
 */
DiReturnT setErrorState(DiReturnT errorCode, USBDM_ErrorCode rc) {

   return setErrorState(errorCode, bdmInterface->getErrorString(rc));
}

/**
 *  Get error string
 *
 *  @return errorCode passed as 1st parameter
 */
static DiStringT getGDIErrorMessage(void) {
   return (DiStringT)currentErrorString;
}

/**
 *   Close connection to target
 *
 *   @return error code, see \ref USBDM_ErrorCode
 */
static DiReturnT closeBDM(void) {
   LOGGING_E;
   DiReturnT rc = DI_OK;

   USBDM_ErrorCode bdmRc = bdmInterface->closeBdm();

   if (bdmRc != BDM_RC_OK) {
      return setErrorState(DI_ERR_FATAL, bdmRc);
   }
   return setErrorState(rc);
}

/**
 *  Does the following:
 *    - Initialises USBDM interface
 *    - Legacy  - Display USBDM Dialogue to obtain settings
 *    - Eclipse - Loads settings from Codewarrior
 *    - Loads device data from database
 *    - Opens BDM
 *    - Sets BDM options
 *    - Sets BDM target type
 *    - Sets up Flash programmer
 *
 *   Displays an error dialogue on failure. \n
 *   May prompt to retry connection for certain errors.
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
static USBDM_ErrorCode initialiseBDMInterface(void) {
   LOGGING;
   USBDM_ErrorCode rc = BDM_RC_OK;

   // Close any existing connection
   bdmInterface->closeBdm();

#if defined(GDI) && defined(LEGACY)

   // Get name from Metrowerks Codewarrior
   string deviceName;
   string projectPath;
   loadNames(deviceName, projectPath);

   log.print("deviceName = %s, projectPath = %s\n", deviceName.c_str(), projectPath.c_str() );

   // Load App settings // TODO use name from CW
   AppSettingsPtr appSettings(new AppSettings("GDI_Legacy", targetType, "GDI Legacy settings"));
   appSettings->load();

   // Display USBDM dialogue to get settings
   GdiDialoguePluginPtr dialogue = GdiDialoguePluginFactory::createPlugin();
   bool forceDisplay = false;

   do {
      rc = dialogue->execute(bdmInterface, appSettings, forceDisplay);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      forceDisplay = true;
      appSettings->save();
      rc = bdmInterface->initBdm();
   } while (rc != BDM_RC_OK);

#else
   // Load the settings from the Eclipse environment
   rc = loadSettings(bdmInterface);
   if (rc != BDM_RC_OK) {
      bdmInterface->closeBdm();
      log.print("loadSettings() failed, reason = %s\n", bdmInterface->getErrorString(rc));
      return rc;
   }
   rc = bdmInterface->initBdm();
#endif

   initialConnectOptions = bdmInterface->getInitialConnectRetryMode();
   softConnectOptions    = bdmInterface->getSoftConnectRetryMode();
   if (rc != BDM_RC_OK) {
      bdmInterface->closeBdm();
      log.print("initBdm() failed, reason = %s\n", bdmInterface->getErrorString(rc));
      return rc;
   }

#ifdef FLASH_PROGRAMMING
   // Set up flash programmer for target

   // Load description of device
   rc = getDeviceData(targetType, deviceData);
   if (rc != BDM_RC_OK) {
      log.error("Failed to get device data, error = %s\n", bdmInterface->getErrorString(rc));
      return rc;
   }
   if (targetType == T_RS08) {
      DeviceData::EraseMethod eraseOptions = deviceData->getEraseMethod();
      if ((eraseOptions == DeviceData::eraseSelective) || (eraseOptions == DeviceData::eraseAll)) {
         // These targets only support mass erase
         deviceData->setEraseMethod(DeviceData::eraseMass);
      }
   }
   if (deviceData->getSecurity() == SEC_SECURED) {
      deviceData->setSecurity(SEC_SMART);
   }
   flashProgrammer = FlashProgrammerFactory::createFlashProgrammer(bdmInterface);
   flashProgrammer->setDeviceData(deviceData);
   programmingSupported = true;
#endif

   return rc;
}

/**
 *  Open GDI
 *
 * @param dnGdiVersionH
 * @param dnGdiVersionL
 * @param dnArgc
 * @param szArgv
 * @param UdProcessEvents
 *
 * @return \n
 *     DI_OK              => OK \n
 *     DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiOpen ( DiUInt32T      dnGdiVersionH,
                      DiUInt32T      dnGdiVersionL,
                      DiUInt32T      dnArgc,
                      DiConstStringT szArgv[],
                      void (*UdProcessEvents)(void) ) {

#if !defined(TEST_APP)
   UsbdmSystem::Log::openLogFile("GDI.log", "Codewarrior GDI Interface");
#endif

   LOGGING;

   log.printq("DiGdiOpen(\n"
         "   dnGdiVersionH=0x%X, dnGdiVersionL=0x%X, \n"
         "   dnArgc=%d, szArgv=0x%p, \n"
         "   UdProcessEvents=0x%p"
         ")\n",
         dnGdiVersionH, dnGdiVersionL, dnArgc, szArgv, UdProcessEvents);
   for (unsigned sub = 0; sub < dnArgc; sub++) {
      log.print("argv[%2i]:\'%s\'\n", sub, szArgv[sub]);
   }

   // No functions available until DiGdiInitIO() is called
   currentError       = DI_ERR_STATE;
   currentErrorString = "GDI Not opened";

#ifdef FLASH_PROGRAMMING
   flashImage.reset();
   flashProgrammer.reset();
#endif

   bdmInterface.reset();
   bdmInterface = BdmInterfaceFactory::createInterface(targetType);

   if (bdmInterface == 0) {
      return setErrorState(DI_ERR_FATAL, BDM_RC_FAIL);
   }
   return setErrorState(DI_OK);
}

/**  Close GDI
 *
 *  @param fClose
 *
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiClose ( DiBoolT fClose ) {
   LOGGING;

   closeBDM();
   setErrorState(DI_ERR_STATE, ("GDI Not open"));

#ifdef FLASH_PROGRAMMING
   flashImage.reset();
   flashProgrammer.reset();
   deviceData.reset();
   log.print("flashImage.use_count()      = %ld\n",  flashImage.use_count());
   log.print("flashProgrammer.use_count() = %ld\n",  flashProgrammer.use_count());
   log.print("deviceData.use_count()      = %ld\n",  deviceData.use_count());
#endif

   log.print("bdmInterface.use_count()    = %ld\n",  bdmInterface.use_count());
   bdmInterface.reset();
   log.print("bdmInterface.use_count()    = %ld\n",  bdmInterface.use_count());

#if defined(LEGACY) && !defined(TEST_APP)
//   UsbdmSystem::Log::closeLogFile();
#endif

   return DI_OK;
}

/**
 *   Get GDI version
 *
 *  @param dnGdiVersion
 *
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiVersion ( DiUInt32T *dnGdiVersion ) {
   LOGGING_E;

   *dnGdiVersion = USBDM_GDI_INTERFACE_VERSION;
   return setErrorState(DI_OK);
}

/**
 *  Get Features Supported by GDI
 *
 *  @param pdfFeatures
 *
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiGetFeatures ( pDiFeaturesT pdfFeatures ) {
   LOGGING_E;

   *pdfFeatures = diFeatures;
   return setErrorState(DI_OK);
}

/**
 * Set GDI Configuration
 *
 *  @param szConfig
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiSetConfig ( DiConstStringT szConfig ) {
   LOGGING_Q;

   log.print("DiGdiSetConfig() - not implemented\n");
   return setErrorState(DI_OK);
}

/**
 *  Does initial target connection with check for secured target.
 *  The user will be prompted to mass erase the target if secured.
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_ErrorCode initialConnect(void) {
   LOGGING;
   USBDM_ErrorCode rc;

   forceMassErase = false;
   pcWritten      = false;

   // Initial connect using all strategies
   rc = bdmInterface->targetConnectWithRetry(initialConnectOptions);

   log.print("After initial connect, rc = %s\n", bdmInterface->getErrorString(rc));

#if (TARGET != ARM) && (TARGET != MC56F80xx)
   // Trying to halt a secured device causes havoc
   bdmInterface->halt();
   bdmInterface->halt();
#endif

   log.print("After halting target, rc = %s\n", bdmInterface->getErrorString(rc));

#if (TARGET == MC56F80xx)
   log.print("Doing bdmInterface->halt()\n");
   rc = bdmInterface->halt();
   if (rc != BDM_RC_OK) {
      if (initialConnectOptions&BdmInterface::retryByReset) {
         bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
      }
      rc = bdmInterface->halt(); // retry
   }
#endif

#ifdef FLASH_PROGRAMMING
   log.print("Flash programming checks\n");

#if (TARGET == HCS08) || (TARGET == CFV1) || (TARGET == RS08)
   if (rc == BDM_RC_OK) {
      log.print("Doing unsecured check\n");
      if (flashProgrammer->checkTargetUnSecured() == PROGRAMMING_RC_ERROR_SECURED) {
         rc = BDM_RC_SECURED;
      }
   }
#endif

   if (rc == BDM_RC_SECURED) {
      log.print("Target is secured\n");
      if (flashProgrammer->getDeviceData()->getEraseMethod() == DeviceData::eraseMass) {
         log.print("Mass erase already selected\n");
         // Mass erase already selected so security isn't a problem
         forceMassErase = true; // So ignore error before mass erase
         // Ignore secured error
         rc = BDM_RC_OK;
      }
      else {
         log.print("Prompting user\n");
         // Prompt user to change erase option to 'mass erase'
         mtwksDisplayLine("targetConnect(): Target is secured\n");
         int getYesNo = displayDialogue(
               "Device appears to be secure and may \n"
               "only be programmed after a mass erase \n"
               "which completely erases the device.\n\n"
               "Mass erase device?",
               "Device is secured",
               YES_NO|YES_DEFAULT|ICON_INFORMATION);
         log.print("Setting forceMassErase = %s\n", (getYesNo == YES)?"True":"False");
         if (getYesNo == YES) {
            rc = flashProgrammer->massEraseTarget();
         }
      }
   }
#endif

   log.print("Complete");
   return rc;
}

/**
 *  Configure I/O System
 *
 *  @param pdcCommSetup unused
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiInitIO( pDiCommSetupT pdcCommSetup ) {
   LOGGING;

   log.print("pdcCommSetup = %p\n", pdcCommSetup);
   if (pdcCommSetup != nullptr) {
      log.print("\n"
            "pdcCommSetup                   = %p\n"
            "pdcCommSetup->dccType          = %d\n"
            "pdcCommSetup->fCheckConnection = %s\n",
            pdcCommSetup,
            pdcCommSetup->dccType,
            pdcCommSetup->fCheckConnection?"True":"False"
            );
   }
   mtwksDisplayLine("\n"
         "=============================================\n"
         "  USBDM GDI Version %s\n"
         "=============================================\n",
         USBDM_VERSION_STRING);

#if !defined(useWxWidgets)
#ifdef _WIN32
   // TODO Set up handle on Eclipse Window once only
   log.print("Setting default window handle\n");
//   setDefaultWindowParent(FindEclipseWindowHwnd());
#endif
#endif

   // Open & Configure BDM
   USBDM_ErrorCode bdmRc = initialiseBDMInterface();
   if (bdmRc != BDM_RC_OK) {
      DiReturnT rc = setErrorState(DI_ERR_COMMUNICATION, bdmRc);
      log.error("Failed - %s\n", currentErrorString);
      return rc;
   }

#ifndef USE_MEE
   // Initial connect is treated differently
   bdmRc = initialConnect();
   if (bdmRc != BDM_RC_OK) {
      DiReturnT rc = setErrorState(DI_ERR_COMMUNICATION, bdmRc);
      log.error("Failed - %s\n", currentErrorString);
      return rc;
   }
#else
   log.print("Doing mtwksSetMEE()\n");
   mtwksSetMEE(1);
#endif
   return setErrorState(DI_OK);
}

/**
 *  Initialise Register Name/Number Map
 *
 *  @param dnEntries
 *  @param pdriRegister
 *  @param dnProgramCounter
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiInitRegisterMap ( DiUInt32T         dnEntries,
                                 DiRegisterInfoT*  pdriRegister,
                                 DiUInt32T         dnProgramCounter ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *  Initialise Memory Space Name/Number Map
 *
 *  @param dnEntries
 *  @param pdmiMemSpace
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiInitMemorySpaceMap ( DiUInt32T            dnEntries,
                                    DiMemorySpaceInfoT*  pdmiMemSpace ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *  2.2.1.9 Add Callback Procedures
 *
 *  @param dcCallbackType
 *  @param Callback
 *
 *  @return \n
 *      DI_OK              => OK \n
 *      DI_ERR_FATAL       => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiAddCallback ( DiCallbackT dcCallbackType,
                             CallbackF   Callback ) {
   LOGGING_Q;
	log.print("(type=%4.4X, address=%p)\n", dcCallbackType, Callback);

   setCallback(dcCallbackType, Callback);

   return setErrorState(DI_OK);
}

/**
 *   2.2.1.10 Cancel GDI Procedure
 *
 *   @return \n
 *       DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiCancel ( void ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *   2.2.1.11 Synchronize UD
 *
 *   @param pfUpdate
 *
 *   @return \n
 *       DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiGdiSynchronize ( DiBoolT *pfUpdate ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

static DiMenuItemT menuItems[] =
{
/* szMenuTitle  szDiCommand    */
 { "Command 1", "cmd1", },
};

/**
 *   2.2.2.1 Add DI Specific Commands to UD Menu
 *
 *   @param pdnNrEntries
 *   @param pdmiMenuItem
 */
USBDM_GDI_DECLSPEC
DiReturnT DiDirectAddMenuItem ( DiUInt32T    *pdnNrEntries,
                                pDiMenuItemT *pdmiMenuItem ) {
   LOGGING_E;

   *pdnNrEntries = sizeof(menuItems)/sizeof(menuItems[0]);
   *pdmiMenuItem = menuItems;
   return setErrorState(DI_OK);
}

//static char directCommandResult[1000] = "";
//static char *directCommandResultPtr   = nullptr;
//
///**
// *  Provides a print function which prints data to DI_DIRECT message buffer
// *
// *  @param format Format and parameters as for printf()
// */
//void setDirectCommandString(const char *format, ...) {
//   va_list list;
//
//   if (format == nullptr) {
//      directCommandResultPtr = nullptr;
//      return;
//   }
//   va_start(list, format);
//   vsnprintf(directCommandResult, sizeof(directCommandResult)-1, format, list);
//   directCommandResultPtr = directCommandResult;
//   va_end(list);
//}

#if TARGET != RS08
/**
 *   2.2.2.2 Send Native Command to DI
 *
 *   @param pszCommand
 *   @param pduiUserInfo
 *
 *   @return \n
 *       DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiDirectCommand ( DiConstStringT  pszCommand,
                            DiUserInfoT     *pduiUserInfo ) {

   LOGGING_Q;
   log.print("(%s, %p) - not supported\n", pszCommand, pduiUserInfo);
   return setErrorState(DI_ERR_NOTSUPPORTED);
}
#endif

/**
 *   2.2.2.3 Read String from DI
 *
 *   @param dnNrToRead
 *   @param pcBuffer
 *   @param dnNrRead
 *
 *   @return \n
 *       DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiDirectReadNoWait ( DiUInt32T  dnNrToRead,
                               char        *pcBuffer,
                               DiUInt32T   *dnNrRead ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   *pcBuffer = '\0';
   *dnNrRead = 0;
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *   2.2.3.1 Retrieve Error Message
 *
 *   @param pszErrorMsg
 */
USBDM_GDI_DECLSPEC
void DiErrorGetMessage ( DiConstStringT *pszErrorMsg ) {
   LOGGING_Q;

   *pszErrorMsg = getGDIErrorMessage();

   if (pszErrorMsg == nullptr) {
      log.print(" => not set\n");
   }
   else {
      log.print(" => %s\n", *pszErrorMsg);
   }
   mtwksDisplayLine("DiErrorGetMessage() => %s\n", getGDIErrorMessage());

   // Clear all errors apart from fatal
   if (currentError != DI_ERR_FATAL) {
      setErrorState(DI_OK);
   }
}

/**
 *   2.2.4.1 Configure Target Memory
 *
 *   @param dmmMap
 *
 *   @return \n
 *       DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMemorySetMap ( DiMemoryMapT dmmMap ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *   2.2.4.2 Retrieve Target Memory Configuration
 *
 *   @param pdmmMap
 *
 *   @return \n
 *       DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryGetMap ( DiMemoryMapT *pdmmMap ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *   2.2.4.3 Configure CPU to Memory Interface
 *
 *   @param dmtcMap
 *
 *   @return \n
 *       DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMemorySetCpuMap ( DiMemoryToCpuT dmtcMap ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *   2.2.4.4 Retrieve CPU to Memory Interface
 *
 *   @param pdmtcMap
 *
 *   @return \n
 *       DI_ERR_NOTSUPPORTED  => Error see \ref currentErrorString
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryGetCpuMap ( DiMemoryToCpuT *pdmtcMap ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

#ifdef FLASH_PROGRAMMING

DiReturnT programTargetFlash(void) {
   LOGGING;
   USBDM_ErrorCode rc;

#if TARGET == MC56F80xx
   rc = bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
#endif

   if (flashProgrammer == nullptr) {
      mtwksDisplayLine("programTargetFlash() - flashProgrammer not created yet!\n");
      return setErrorState(DI_ERR_FATAL, "flashProgrammer not created yet!");
   }
   // Program target
   rc = flashProgrammer->programFlash(flashImage, nullptr, true);

   if (rc != PROGRAMMING_RC_OK) {
      return setErrorState(DI_ERR_FATAL, rc);
   }

   return DI_OK;
}
#endif

/**
 *   2.2.5.1 Download Application
 *
 *   @param fUseAuxiliaryPath
 *   @param ddcDownloadCommand
 *   @param ddfDownloadFormat
 *   @param pchBuffer
 *
 *   @note DSC/CFVx GDI doesn't support flash programming
 */
#ifndef FLASH_PROGRAMMING
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryDownload ( DiBoolT            fUseAuxiliaryPath,
                             DiDownloadCommandT ddcDownloadCommand,
                             DiDownloadFormatT  ddfDownloadFormat,
                             char               *pchBuffer ) {
   LOGGING_Q;
   log.error("- Programming not supported\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}
#else
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryDownload ( DiBoolT            fUseAuxiliaryPath,
                             DiDownloadCommandT ddcDownloadCommand,
                             DiDownloadFormatT  ddfDownloadFormat,
                             char               *pchBuffer ) {
   LOGGING;
   const char *command[] = {"DI_DNLD_INIT","DI_DNLD_WRITE","DI_DNLD_TERMINATE","DI_DNLD_ABORT"};
   U32c address(ddfDownloadFormat.daAddress);
   DiReturnT rc;
   log.print("- aux=%s, comm=%s, format=0x%X, addr=0x%4.4X, size 0x%X\n",
         fUseAuxiliaryPath?"T":"F",
         command[ddcDownloadCommand&0x03],
         ddfDownloadFormat.dafAbsFileFormat,
         (uint32_t)address,
         ddfDownloadFormat.dnBufferSize);

   CHECK_ERROR_STATE();

   if (!programmingSupported) {
      return setErrorState(DI_ERR_NOTSUPPORTED);
   }
   if ((ddfDownloadFormat.dafAbsFileFormat & (DI_ABSF_FILENAME|DI_ABSF_BINARY)) == 0) {
      log.print("- unsupported format %X\n",
            ddfDownloadFormat.dafAbsFileFormat);
      return setErrorState(DI_ERR_NOTSUPPORTED);
   }
   switch (ddcDownloadCommand) {
      case DI_DNLD_INIT:
         mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_INIT - New memory image opened\n");
         log.print("- DI_DNLD_INIT - New memory image opened\n");
         // Create flash image to contain any changes to target memory
         flashImage = FlashImageFactory::createFlashImage(targetType);
         return setErrorState(DI_OK);

      case DI_DNLD_TERMINATE:
         rc = DI_OK;
         if ((flashImage != nullptr) && (!flashImage->isEmpty() || forceMassErase)) {
            mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_TERMINATE - Programming memory image...\n");
            log.print("- DI_DNLD_TERMINATE - Programming memory image\n");
            rc = programTargetFlash();
            mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_TERMINATE - Programming complete, rc = %d\n", rc);
         }
         else {
            mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_TERMINATE - Memory image is empty - Flash programming skipped\n");
            log.print("- DI_DNLD_TERMINATE - Memory image is empty - Flash programming skipped\n");
         }
         flashImage.reset();
         if (rc != DI_OK) {
            return rc;
         }
         // Restore original options
         mtwksDisplayLine("DiMemoryDownload() - DI_DNLD_TERMINATE - Resetting target\n");
         log.print("-  Resetting target\n");
         bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
         // Connect but ignore error which will be discovered on next operation
         bdmInterface->targetConnectWithRetry(softConnectOptions);
         forceMassErase = false;
         return setErrorState(DI_OK);
      case DI_DNLD_WRITE:
         log.print("DI_DNLD_WRITE\n");
         return setErrorState(DI_ERR_NOTSUPPORTED);
      case DI_DNLD_ABORT:
         log.print("DI_DNLD_ABORT\n");
         flashImage.reset();
         break;
   }
   return setErrorState(DI_OK);
}
#endif

// This is largest size memory read/write block passed to USBDM layer
// Larger sizes are subdivided - but this is unlikely to occur.
#define MAX_BLOCK_SIZE (0x1000)
#if (MAX_BLOCK_SIZE % 4) != 0
#error "MAX_BLOCK_SIZE must be a multiple of 4"
#endif

static uint8_t memoryReadWriteBuffer[MAX_BLOCK_SIZE];

#if TARGET == ARM && 0
/**
 *   Write data to target memory
 *   ARM Memory writes are decomposed into a minimal sequence of the largest aligned object writes
 *
 *   @param memorySpace = Size of data elements (1/2/4 bytes)
 *   @param byteCount   = Number of _bytes_ to transfer
 *   @param address     = Memory address
 *   @param buffer      = Ptr to block of data to write
 *
 *   @return error code \n
 *       BDM_RC_OK    => OK \n
 *       other        => Error code - see \ref USBDM_ErrorCode
 */
static USBDM_ErrorCode ARM_WriteMemory(MemorySpace_t memorySpace, int byteCount, int address, uint8_t *buffer) {
   USBDM_ErrorCode rc = BDM_RC_OK;
   int index = 0;
   if ((address&0x01) != 0) {
      // Odd leading byte
      rc = bdmInterface->writeMemory(MS_Byte, 1, address, buffer+index);
      address++;
      index++;
      byteCount--;
   }
   if ((rc == BDM_RC_OK) && ((address&0x02) != 0) && (byteCount >= 2)) {
      // Odd leading word
      rc = bdmInterface->writeMemory(MS_Word, 2, address, buffer+index);
      address      += 2;
      index        += 2;
      byteCount    -= 2;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 4)) {
      // Bulk longwords
      int longWordCount = byteCount&~0x3;
      rc = bdmInterface->writeMemory(MS_Long, longWordCount, address, buffer+index);
      address += longWordCount;
      index        += longWordCount;
      byteCount    -= longWordCount;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 2)) {
      // Odd trailing word
      rc = bdmInterface->writeMemory(MS_Word, 2, address, buffer+index);
      address      += 2;
      index        += 2;
      byteCount    -= 2;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 1)) {
      // Odd trailing byte
      rc = bdmInterface->writeMemory(MS_Byte, 1, address, buffer+index);
      address++;
      index++;
      byteCount--;
   }
   if ((rc == BDM_RC_OK) && (byteCount > 0)) {
      rc = PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   return rc;
}
#endif

/**
 *   2.2.5.2 Write Data to Target Memory
 *
 *   @param daTarget        Target memory address
 *   @param pdmvBuffer      Data to write (LittleEndian on DSC)
 *   @param dnBufferItems   Number of units to write
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryWrite ( DiAddrT       daTarget,
                          DiMemValueT  *pdmvBuffer,
                          DiUInt32T     dnBufferItems ) {
   LOGGING_Q;

   uint32_t        address      = (U32c)daTarget;   // Load address
   MemorySpace_t   memorySpace;                     // Memory space & size
   int             organization;                    // For display
   uint32_t        endAddress;                      // End address
   uint32_t        numBytes;

   CHECK_ERROR_STATE();

   switch(daTarget.dmsMemSpace) {
	   case 0 : // Treat 0 as byte
	   case 1 :
         memorySpace  = MS_Byte;
         organization = UsbdmSystem::BYTE_DISPLAY|UsbdmSystem::BYTE_ADDRESS;
         numBytes     = dnBufferItems;
         endAddress   = address + numBytes - 1;
         break;
      case 2 :
         memorySpace  = MS_Word;
         organization = UsbdmSystem::WORD_DISPLAY|UsbdmSystem::BYTE_ADDRESS;
         numBytes     = 2*dnBufferItems;
         endAddress   = address + numBytes - 1;
         break;
      case 4 :
         memorySpace  = MS_Long;
         organization = UsbdmSystem::LONG_DISPLAY|UsbdmSystem::BYTE_ADDRESS;
         numBytes     = 4*dnBufferItems;
         endAddress   = address + numBytes - 1;
         break;
      case 0x13 : // DSC (cw-e) (byte address, elements=1 bytes)
         memorySpace  = MS_XByte;
         organization = UsbdmSystem::WORD_ADDRESS|UsbdmSystem::BYTE_DISPLAY;
         numBytes     = dnBufferItems;
         endAddress   = address + numBytes - 1;
         break;
      case 0x10 : // DSC (cw)
      case 0x14 : // DSC (cw-e, word address, elements=2 bytes)
         memorySpace  = MS_XWord;
         organization = UsbdmSystem::WORD_ADDRESS|UsbdmSystem::WORD_DISPLAY;
         address     *= 2; // Change to byte address from DSC word address
         numBytes     = 2*dnBufferItems;
         endAddress   = address + numBytes - 1;
         break;
      case 0x15 : // DSC
         memorySpace  = MS_XLong;
         organization = UsbdmSystem::WORD_ADDRESS|UsbdmSystem::LONG_DISPLAY;
         address     *= 2; // Change to byte address from DSC word address
         numBytes     = 4*dnBufferItems;
         endAddress   = address + numBytes - 1;
         break;
      case 0x11 : // DSC (cw-e, word address, elements=2bytes)
      case 0x17 :
         memorySpace  = MS_PWord;
         organization = UsbdmSystem::WORD_ADDRESS|UsbdmSystem::WORD_DISPLAY;
         address     *= 2; // Change to byte address from DSC word address
         numBytes     = 2*dnBufferItems;
         endAddress   = address + numBytes - 1;
         break;
      default :
         log.print("(daTarget.dmsMemSpace=0x%X, address=0x%4.4X, dnBufferItems=%d)\n"
               "Error - Unexpected daTarget.dmsMemSpace value\n",
               daTarget.dmsMemSpace,
               (uint32_t)address,
			      dnBufferItems);
         return setErrorState(DI_ERR_NOTSUPPORTED, "Unknown memory space");
   }
#if TARGET == ARM
   log.print("(daTarget.dmsMemSpace=%2X, dnBufferItems=%3d, [0x%06X...0x%06X], %s)\n",
         daTarget.dmsMemSpace,
         dnBufferItems,
         address,
         endAddress,
         ARM_GetMemoryName(address));
#elif TARGET == MC56F80xx
   log.print("(daTarget.dmsMemSpace=%2X, dnBufferItems=%3d, [w:0x%06X...w:0x%06X])\n",
         daTarget.dmsMemSpace,
         dnBufferItems,
         address/2,
         endAddress/2);
#else
   log.print("(daTarget.dmsMemSpace=%2X, dnBufferItems=%3d, [0x%06X...0x%06X])\n",
         daTarget.dmsMemSpace,
         dnBufferItems,
         address,
         endAddress);
#endif

#if defined(LOG) && 0
   log.print("                                                        0011223344556677\n"
         "daTarget.dmsMemSpace = %X, daTarget.dlaLinAddress.v.val = 0x%02X%02X%02X%02X%02X%02X%02X%02X,"
         " dnBufferItems = %d\n",
         daTarget.dmsMemSpace,
         daTarget.dlaLinAddress.v.val[0],daTarget.dlaLinAddress.v.val[1],
         daTarget.dlaLinAddress.v.val[2],daTarget.dlaLinAddress.v.val[3],
         daTarget.dlaLinAddress.v.val[4],daTarget.dlaLinAddress.v.val[5],
         daTarget.dlaLinAddress.v.val[6],daTarget.dlaLinAddress.v.val[7],
         dnBufferItems);

   for (unsigned t=0; t<dnBufferItems; t++) {
   log.print("                                 0011223344556677\n"
         "pdmvBuffer[%2d].dmValue.val = 0x%02X%02X%02X%02X%02X%02X%02X%02X\n",
         t,
         pdmvBuffer[t].dmValue.val[0],pdmvBuffer[t].dmValue.val[1],
         pdmvBuffer[t].dmValue.val[2],pdmvBuffer[t].dmValue.val[3],
         pdmvBuffer[t].dmValue.val[4],pdmvBuffer[t].dmValue.val[5],
         pdmvBuffer[t].dmValue.val[6],pdmvBuffer[t].dmValue.val[7]
         );
   if (t >= 4)
      break;
   }
#endif
   uint32_t offset = 0;
   while (dnBufferItems>0) {
      // Copy a block of data to memoryReadWriteBuffer
      uint32_t writeAddress = address;

      // Copy until buffer full or complete
      unsigned sub = 0;
      while ((sub<sizeof(memoryReadWriteBuffer)) && (dnBufferItems>0)) {
         U32c value(pdmvBuffer[offset++]);
         dnBufferItems--;
         // Unpack items
         switch (memorySpace&MS_SIZE) {
            case MS_Byte :
               memoryReadWriteBuffer[sub++] = value[3];
               address += 1; // Advance address
               break;
            case MS_Word :
               memoryReadWriteBuffer[sub++] = value[2];
               memoryReadWriteBuffer[sub++] = value[3];
               address += 2; // Advance word address
               break;
            case MS_Long :
               memoryReadWriteBuffer[sub++] = value[0];
               memoryReadWriteBuffer[sub++] = value[1];
               memoryReadWriteBuffer[sub++] = value[2];
               memoryReadWriteBuffer[sub++] = value[3];
               address += 4; // Advance long address
               break;
         }
      }
      log.printDump(memoryReadWriteBuffer, sub, writeAddress, organization);

      bool writeDone = false;
#ifdef FLASH_PROGRAMMING
      if (flashImage != nullptr) {
#if TARGET == RS08
         MemType_t memoryType = deviceData->getMemoryType(writeAddress);
         if ((memoryType != MemEEPROM) && (memoryType != MemFLASH) && (memoryType != MemPROM)) {
            log.print("Warning: unsupported memory write during Flash programming (ty=%s, sp=%s, 0x%06X...0x%06X)\n",
                  MemoryRegion::getMemoryTypeName(memoryType), getMemSpaceName(memorySpace), (uint32_t)writeAddress, (uint32_t)writeAddress+sub-1);
            return setErrorState(DI_ERR_FATAL, "Unsupported memory write during flash programming");
         }
#endif
         // Write data to programming buffer
         log.print("(address=0x%06X, size=0x%04X)\n", writeAddress, sub);
         log.printDump(memoryReadWriteBuffer,sub,writeAddress,memorySpace&MS_SIZE);
         USBDM_ErrorCode rc = flashImage->loadDataBytes(sub, writeAddress, memoryReadWriteBuffer, FlashImage::Overwrite);
         writeDone = true;
         if (rc != BDM_RC_OK) {
            return setErrorState(DI_ERR_FATAL, rc);
         }
      }
#endif
      if (!writeDone) {
         // Write data directly to memory
         USBDM_ErrorCode rc = BDM_RC_OK;
         rc = bdmInterface->writeMemory(memorySpace, sub, writeAddress, memoryReadWriteBuffer);
         if (rc != BDM_RC_OK) {
            return setErrorState(DI_ERR_NONFATAL, rc);
         }
      }
   }
   return setErrorState(DI_OK);
}

#if TARGET == ARM && 0
/**
 *   Read data from target memory
 *   ARM Memory reads are decomposed into a minimal sequence of the largest aligned object reads
 *
 *   @param memorySpace = Size of data (1/2/4 bytes)
 *   @param byteCount   = Number of bytes to transfer
 *   @param address     = Memory address
 *   @param buffer      = Where to place data
 *
 *   @return error code \n
 *       BDM_RC_OK    => OK \n
 *       other        => Error code - see \ref USBDM_ErrorCode
 */
static USBDM_ErrorCode ARM_ReadMemory(MemorySpace_t memorySpace, int byteCount, int address, uint8_t *buffer) {
   USBDM_ErrorCode rc = BDM_RC_OK;
   int index = 0;
   if ((address&0x01) != 0) {
      // Odd leading byte
      rc = bdmInterface->readMemory(MS_Byte, 1, address, buffer+index);
      address++;
      index++;
      byteCount--;
   }
   if ((rc == BDM_RC_OK) && ((address&0x02) != 0) && (byteCount >= 2)) {
      // Odd leading word
      rc = bdmInterface->readMemory(MS_Word, 2, address, buffer+index);
      address   += 2;
      index     += 2;
      byteCount -= 2;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 4)) {
      // Bulk longwords
      int longWordCount = byteCount&~0x3;
      rc = bdmInterface->readMemory(MS_Long, longWordCount, address, buffer+index);
      address   += longWordCount;
      index     += longWordCount;
      byteCount -= longWordCount;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 2)) {
      // Odd trailing word
      rc = bdmInterface->readMemory(MS_Word, 2, address, buffer+index);
      address   += 2;
      index     += 2;
      byteCount -= 2;
   }
   if ((rc == BDM_RC_OK) && (byteCount >= 1)) {
      // Odd trailing byte
      rc = bdmInterface->readMemory(MS_Byte, 1, address, buffer+index);
      address++;
      index++;
      byteCount--;
   }
   if ((rc == BDM_RC_OK) && (byteCount > 0)) {
      rc = PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   return rc;
}
#endif

/**
 *   2.2.5.3 Read Data from Target Memory
 *
 *   @param daTarget
 *   @param pdmvBuffer
 *   @param dnBufferItems
 *
 *   @note On DSC the daTarget is a word address
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryRead ( DiAddrT       daTarget,
                         DiMemValueT   *pdmvBuffer,
                         DiUInt32T     dnBufferItems ) {
   LOGGING_Q;
   uint32_t        address      = (U32c)daTarget;   // Load address
   MemorySpace_t   memorySpace;                     // Memory space & size
   uint32_t        endAddress;                      // End address
   uint32_t        numBytes;                        // Number of bytes to transfer

   switch(daTarget.dmsMemSpace) {
      case 0 : // Treat 0 as byte
      case 1 : // Byte
         memorySpace  = MS_Byte;
//         organization = BYTE_DISPLAY|BYTE_ADDRESS;
         numBytes   = dnBufferItems;
         endAddress = address + numBytes - 1;
         break;
      case 2 : // Word
         memorySpace  = MS_Word;
//         organization = WORD_DISPLAY|BYTE_ADDRESS;
         numBytes   = 2*dnBufferItems;
         endAddress = address + numBytes - 1;
         break;
      case 4 : // Long
         memorySpace  = MS_Long;
//         organization = LONG_DISPLAY|BYTE_ADDRESS;
         numBytes   = 4*dnBufferItems;
         endAddress = address + numBytes - 1;
         break;
      case 0x13 :  // DSC Byte (cw-e, word address, elements=2bytes)
	     // Treat as Word because bytes are written in pairs
         memorySpace  = MS_XWord;
//         organization = BYTE_ADDRESS|BYTE_DISPLAY;
         address   *= 2; // Change to byte address from DSC word address
         numBytes   = 2*dnBufferItems;
         endAddress = address + numBytes - 1;
         break;
      case 0x10 :  // DSC (cw)
      case 0x14 :  // DSC (cw-e, word address, elements=2bytes)
         memorySpace  = MS_XWord;
//         organization = WORD_ADDRESS|WORD_DISPLAY;
         address   *= 2; // Change to byte address from DSC word address
         numBytes   = 2*dnBufferItems;
         endAddress = address + numBytes - 1;
         break;
      case 0x15 :
         memorySpace  = MS_XLong;
//         organization = WORD_ADDRESS|LONG_DISPLAY;
         address   *= 2; // Change to byte address from DSC word address
         numBytes   = 4*dnBufferItems;
         endAddress = address + numBytes - 1;
         break;
      case 0x11 :  // DSC (cw-e, word address, elements=2bytes)
      case 0x17 :
         memorySpace  = MS_PWord;
//         organization = WORD_ADDRESS|WORD_DISPLAY;
         address   *= 2; // Change to byte address from DSC word address
         numBytes   = 2*dnBufferItems;
         endAddress = address + numBytes - 1;
         break;
      default :
         log.print("(daTarget.dmsMemSpace=0x%X, address=0x%4.4X, dnBufferItems=%d)\n"
               "Error - Unexpected daTarget.dmsMemSpace value\n",
               daTarget.dmsMemSpace,
               (uint32_t)address,
               dnBufferItems);
         return setErrorState(DI_ERR_NOTSUPPORTED, "Unknown memory space");
   }
#if TARGET == ARM
   log.print("(daTarget.dmsMemSpace=%X, dnBufferItems=%d, [0x%06X...0x%06X]), (%s,%s)\n",
         daTarget.dmsMemSpace,
         dnBufferItems,
         address,
         endAddress,
         getMemSpaceName(memorySpace),
         ARM_GetMemoryName(address));
#elif TARGET == MC56F80xx
   log.print("(daTarget.dmsMemSpace=%X, dnBufferItems=%d, [w:0x%06X...w:0x%06X])\n",
         daTarget.dmsMemSpace,
         dnBufferItems,
         address/2,
         endAddress/2);
#else
   log.print("(daTarget.dmsMemSpace=%X, dnBufferItems=%d, [0x%06X...0x%06X])\n",
         daTarget.dmsMemSpace,
         dnBufferItems,
         address,
         endAddress);
#endif
   CHECK_ERROR_STATE();

   unsigned offset = 0;
   while (dnBufferItems>0) {
      uint32_t blockSize = numBytes;
      if (blockSize > sizeof(memoryReadWriteBuffer)) {
         blockSize = sizeof(memoryReadWriteBuffer);
      }
      USBDM_ErrorCode rc = bdmInterface->readMemory(memorySpace, blockSize, address, memoryReadWriteBuffer);
      if (rc != BDM_RC_OK) {
         log.print("- Failed, rc= %s\n", bdmInterface->getErrorString(rc));
         return setErrorState(DI_ERR_NONFATAL, rc);
      }
      log.print("- Result\n");
      log.printDump(memoryReadWriteBuffer, blockSize, address);

      // Copy until buffer full or complete
      unsigned sub = 0;
      while (sub<blockSize) {
         uint8_t v1=0,v2=0,v3=0,v4=0;
         switch (memorySpace&MS_SIZE) {
         case MS_Byte :
            v4 = memoryReadWriteBuffer[sub++];
            address += 1; // Increment address
            break;
         case MS_Word :
            v3 = memoryReadWriteBuffer[sub++];
            v4 = memoryReadWriteBuffer[sub++];
            address += 2; // Increment address
            break;
         case MS_Long :
            v1 = memoryReadWriteBuffer[sub++];
            v2 = memoryReadWriteBuffer[sub++];
            v3 = memoryReadWriteBuffer[sub++];
            v4 = memoryReadWriteBuffer[sub++];
            address += 4; // Increment address
            break;
         }
         // Pack item
         pdmvBuffer[offset++] = (U32c)((v1<<24)+(v2<<16)+(v3<<8)+v4);
         dnBufferItems--;
      }
      numBytes -= blockSize;
   }
   assert(numBytes == 0);
   return setErrorState(DI_OK);
}

/**
 *   2.2.6.3 Create Register Class
 *
 *   @param pdnRegClassId
 *   @param pdnRegisterId
 *   @param dnRegisterIdEntries
 */
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterClassCreate ( DiUInt32T *pdnRegClassId,
                                  DiUInt32T *pdnRegisterId,
                                  DiUInt32T dnRegisterIdEntries ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *   2.2.6.4 Delete Register Class
 *
 *   @param dnRegClassId
 */
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterClassDelete ( DiUInt32T dnRegClassId ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *   2.2.6.5 Write Value to Register Class
 *
 *   @param dnRegClassId
 *   @param pdrvClassValue
 */
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterClassWrite ( DiUInt32T         dnRegClassId,
                                  DiRegisterValueT  *pdrvClassValue ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *   2.2.6.6 Read Value from Register Class
 *
 *   @param dnRegClassId
 *   @param pdrvClassValue
 */
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterClassRead ( DiUInt32T          dnRegClassId,
                                 DiRegisterValueT   *pdrvClassValue ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.8.1 Reset
 */
USBDM_GDI_DECLSPEC
DiReturnT DiExecResetChild ( void ) {
   LOGGING_E;
   CHECK_ERROR_STATE();

#if TARGET == MC56F80xx
   USBDM_ErrorCode rc = bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   rc = bdmInterface->targetConnectWithRetry(initialConnectOptions);
#elif TARGET == ARM
   USBDM_ErrorCode rc = bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
   if (rc != BDM_RC_OK) {
      rc = bdmInterface->reset((TargetMode_t)(RESET_HARDWARE|RESET_SPECIAL));
   }
   if (rc == BDM_RC_OK) {
      rc = bdmInterface->targetConnectWithRetry(initialConnectOptions);
   }
#elif (TARGET == CFV1) || (TARGET == HCS08) || (TARGET == RS08) || (TARGET == HCS12) || (TARGET == S12Z)
   bdmInterface->halt(); // Make sure target is awake - may be sleeping due to STOP/WAIT instruction
   bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
   USBDM_ErrorCode rc = bdmInterface->targetConnectWithRetry(initialConnectOptions);
//   setFixedBDMClock(); - despite the manual it doesn't work
#else
   USBDM_ErrorCode rc = bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
   if (rc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   rc = bdmInterface->targetConnectWithRetry(initialConnectOptions);
   // Read status to clear reset flag
   USBDMStatus_t dummy;
   bdmInterface->getBDMStatus(&dummy);
#endif
   if ((rc != BDM_RC_OK) && !forceMassErase) {
      // Ignore errors until mass erase is completed
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   // Reset into special mode doesn't correctly set the PC on these targets - do manually
   if (pcWritten) {
#if (TARGET == MC56F80xx) || (TARGET == CFV1) || (TARGET == HCS08) || (TARGET == S12Z)
      log.print("Fixing initial PC = 0x%08X\n", pcResetValue);
      bdmInterface->writePC(pcResetValue);
#endif
   }
   return setErrorState(DI_OK);
}

/**
 *    2.2.8.3 Continue Execution Until
 *
 *   @param addrUntil
 */
USBDM_GDI_DECLSPEC
DiReturnT DiExecContinueUntil ( DiAddrT addrUntil ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.8.4 Continue Execution
 */
USBDM_GDI_DECLSPEC
DiReturnT DiExecContinue ( void ) {
   LOGGING;

   USBDM_ErrorCode BDMrc;

   CHECK_ERROR_STATE();

#if TARGET == CFV1
   // Catch Address/Illegal instruction errors as BDM halts
   bdmInterface->writeDReg(CFV1_DRegCSR2byte, CFV1_CSR2_COPHR|CFV1_CSR2_IADHR|CFV1_CSR2_IOPHR);
#endif

#if TARGET == CFVx
   // Fix in case actually STOPPED but CW doesn't know it
   bdmInterface->halt();
#endif

#if TARGET == MC56F80xx
   BDMrc = bdmInterface->go();
#else
   BDMrc = bdmInterface->go();
   if (BDMrc != BDM_RC_OK) {
      bdmInterface->targetConnectWithRetry(softConnectOptions);
      BDMrc = bdmInterface->go();
   }
#endif
   // Ignore BDM_RC_CF_ILLEGAL_COMMAND as may occur when in STOP low-power modes
   if ((BDMrc != BDM_RC_OK) && (BDMrc != BDM_RC_CF_ILLEGAL_COMMAND)) {
      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   return setErrorState(DI_OK);
}

/**
 *    2.2.8.5 Continue Execution in Background
 */
USBDM_GDI_DECLSPEC
DiReturnT DiExecContinueBackground ( void ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.8.7 Stop Execution
 */
USBDM_GDI_DECLSPEC
DiReturnT DiExecStop ( void ) {
   LOGGING_E;
   USBDM_ErrorCode BDMrc = BDM_RC_OK;

   CHECK_ERROR_STATE();

#if TARGET == ARM
   bdmInterface->targetConnectWithRetry(softConnectOptions);
   BDMrc = bdmInterface->halt();
#elif TARGET == MC56F80xx
   bdmInterface->targetConnectWithRetry(softConnectOptions);
   BDMrc = bdmInterface->halt();
#elif TARGET == CFVx
   bdmInterface->targetConnectWithRetry(softConnectOptions);
   // Coldfire V2 devices are really broken
   // BKPT should wake a sleeping target but doesn't
   // The following retries in the hope that a target interrupt might occur at a convenient moment!
   int retry =10;
   do {
      bdmInterface->controlPins(PIN_BKPT_LOW);
      UsbdmSystem::milliSleep(100);
      bdmInterface->controlPins(PIN_RELEASE);
      BDMrc = bdmInterface->targetConnectWithRetry(BdmInterface::retryNever);
   } while ((BDMrc != BDM_RC_OK) && (retry-->0));
#else
   BDMrc = bdmInterface->halt();
   if (BDMrc != BDM_RC_OK) {
      bdmInterface->targetConnectWithRetry(softConnectOptions);
      BDMrc = bdmInterface->halt();
   }
#endif
   if (BDMrc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   return setErrorState(DI_OK);
}

/**
 *    2.2.9.1 Switch Trace System On/Off
 *
 *   @param fOn
 */
USBDM_GDI_DECLSPEC
DiReturnT DiTraceSwitchOn ( DiBoolT fOn ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.9.2 Get Instruction Trace
 *
 *   @param dnNrInstr
 *   @param pditInstrTrace
 */
USBDM_GDI_DECLSPEC
DiReturnT DiTraceGetInstructions ( DiUInt32T       dnNrInstr,
                                    pDiInstrTraceT  pditInstrTrace ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.9.3 Get Raw Trace
 *
 *   @param dnNrFrames
 *   @param dttTraceType
 *   @param PrintRawTrace
 */
USBDM_GDI_DECLSPEC
DiReturnT DiTracePrintRawInfo ( DiUInt32T       dnNrFrames,
                                 DiTraceTypeT    dttTraceType,
                                 PrintRawTraceF  PrintRawTrace ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.9.4 Get Number of New Trace Frames
 *
 *   @param dttTraceType
 *   @param dnNrMaxFrames
 *   @param pdnfNewFrames
 */
USBDM_GDI_DECLSPEC
DiReturnT DiTraceGetNrOfNewFrames ( DiTraceTypeT   dttTraceType,
                                     DiUInt32T      dnNrMaxFrames,
                                     pDiNewFramesT  pdnfNewFrames ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.10.1 Switch Coverage On/Off
 *
 *   @param fOn
 */
USBDM_GDI_DECLSPEC
DiReturnT DiCoverageSwitchOn ( DiBoolT fOn ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.10.2 Get Coverage Information
 *
 *   @param daStart
 *   @param dnSize
 *   @param pdcCoverage
 */
USBDM_GDI_DECLSPEC
DiReturnT DiCoverageGetInfo ( DiAddrT     daStart,
                               DiUInt32T   dnSize,
                               DiCoverageT *pdcCoverage ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.11.1 Switch Profiling On/Off
 *
 *   @param fOn
 */
USBDM_GDI_DECLSPEC
DiReturnT DiProfilingSwitchOn ( DiBoolT fOn ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.11.2 Get Profiling Information
 *
 *   @param pdpProfile
 */
USBDM_GDI_DECLSPEC
DiReturnT DiProfileGetInfo ( DiProfileT *pdpProfile ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.12.1 Open a State Resource
 *
 *   @param pdnStateHandle
 *   @param szStateName
 */
USBDM_GDI_DECLSPEC
DiReturnT DiStateOpen ( DiUInt32T      *pdnStateHandle,
                        DiConstStringT  szStateName ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.12.2 Save DI State
 *
 *   @param dnStateHandle
 *   @param dnIndex
 */
USBDM_GDI_DECLSPEC
DiReturnT DiStateSave ( DiUInt32T dnStateHandle,
                         DiUInt32T dnIndex ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.12.3 Restore DI State
 *
 *   @param dnStateHandle
 *   @param dnIndex
 */
USBDM_GDI_DECLSPEC
DiReturnT DiStateRestore ( DiUInt32T dnStateHandle,
                            DiUInt32T dnIndex ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.12.4 Close a State Resource
 *
 *   @param fDelete
 *
 */
USBDM_GDI_DECLSPEC
DiReturnT DiStateClose ( DiBoolT fDelete ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.13 Get Acceptable Communication Settings
 *
 *   @param dccType
 *   @param szAttr
 *   @param pszEntries
 *   @param pReserved
 */
USBDM_GDI_DECLSPEC
DiReturnT DiCommGetAcceptableSettings ( DiCommChannelT   dccType,
                                        DiConstStringT   szAttr,
                                        DiConstStringT   *pszEntries[],
                                        void             *pReserved ) {
   LOGGING_Q;

   static const unsigned int maxUSBDMDevices = 20;
   static const char *options[maxUSBDMDevices+1];
   static const char *const possibleOptions[maxUSBDMDevices+1] = {
      "USBDM #1",
      "USBDM #2",
      "USBDM #3",
      "USBDM #4",
      "USBDM #5",
      "USBDM #6",
      "USBDM #7",
      "USBDM #8",
      "USBDM #9",
      "USBDM #10",
      "USBDM #11",
      "USBDM #12",
      "USBDM #13",
      "USBDM #14",
      "USBDM #15",
      "USBDM #16",
      "USBDM #17",
      "USBDM #18",
      "USBDM #19",
      "USBDM #20",
      nullptr,
   };

//   log.print("dccType = %x\n", dccType);
//   log.print("szAttr = \'%s\'\n", szAttr);

   if (dccType == DI_COMM_PARALLEL) {
      unsigned deviceCount = 1; // Default to a single BDM
      if (bdmInterface != 0) {
         std::vector<BdmInformation> bdms;
         USBDM_ErrorCode BDMrc = bdmInterface->findBDMs(bdms);
         if (BDMrc != BDM_RC_OK) {
            return setErrorState(DI_ERR_COMMUNICATION, ("No USBDM Devices found"));
         }
         deviceCount = bdms.size();
      }
      if (deviceCount>maxUSBDMDevices) {
         deviceCount = maxUSBDMDevices;
      }
      for (unsigned bdmNum=0; bdmNum < deviceCount; bdmNum++) {
         options[bdmNum] = possibleOptions[bdmNum];
      }
      options[deviceCount] = nullptr;
      log.print("(DI_COMM_PARALLEL) => DI_OK\n");
      *pszEntries = options;
      return setErrorState(DI_OK);
   }
   else {
      log.print("(\?\?) => DI_ERR_NONFATAL\n");
      return setErrorState(DI_ERR_NONFATAL);
   }
}

/**
 *    2.2.16.1 Enumerate Execution Environments
 *
 *   @param pdExecEnv
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMeeEnumExecEnv ( DiExecEnvT *pdExecEnv ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.16.2 Connect to Execution Environment
 *
 *   @param dnExecId
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMeeConnect ( DiUInt32T dnExecId ) {
   LOGGING_Q;

#ifdef USE_MEE
   log.print("(%d)\n", dnExecId);

   // Initial connect is treated differently
   USBDM_ErrorCode bdmRc = initialConnect();
   if (bdmRc != BDM_RC_OK) {
      log.print("- Failed - %s\n", currentErrorString);
      return setErrorState(DI_ERR_COMMUNICATION, bdmRc);
   }
   return setErrorState(DI_OK);
#else
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
#endif
}

/**
 *    2.2.16.3 Get Features Supported by Execution Environment
 *
 *   @param dnExecId
 *   @param pdfFeatures
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMeeGetFeatures ( DiUInt32T    dnExecId,
                             pDiFeaturesT pdfFeatures ) {
   LOGGING_Q;

   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.16.4 Configure I/O System to Execution Environment
 *
 *   @param dnExecId
 *   @param pdcCommSetup
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMeeInitIO ( DiUInt32T      dnExecId,
                        pDiCommSetupT  pdcCommSetup ) {
   LOGGING_Q;

   log.print("(%d) - not implemented\n", dnExecId);
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.16.5 Set Current Connection
 *
 *   @param dnExecId
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMeeSelect ( DiUInt32T dnExecId ) {
   LOGGING_Q;

   log.print("(%d) - dummy\n", dnExecId);
   return setErrorState(DI_OK);
}

/**
 *    2.2.16.6 Disconnect from Execution Environment
 *
 *   @param dnExecId
 *   @param fClose
 */
USBDM_GDI_DECLSPEC
DiReturnT DiMeeDisconnect ( DiUInt32T  dnExecId,
                            DiBoolT    fClose ) {
   LOGGING_Q;

   log.print("(%d, %s) - dummy\n", dnExecId, fClose?"T":"F");
   return setErrorState(DI_OK);
}

/**
 *    2.2.16.7 Connect to CPU
 *
 *   @param dnCpuId
 */
USBDM_GDI_DECLSPEC
DiReturnT DiCpuSelect ( DiUInt32T dnCpuId ) {
   LOGGING_Q;

   log.print("() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.16.8 Get Current CPU
 *
 *   @param dnCpuId
 */
USBDM_GDI_DECLSPEC
DiReturnT DiCpuCurrent ( DiUInt32T *dnCpuId ) {
   LOGGING_Q;

   log.print("() - not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/**
 *    2.2.17 Future GDI Extensions
 *
 *   @param information
 */
USBDM_GDI_DECLSPEC
DiReturnT DiProcess ( void *information ) {
   LOGGING_Q;
   log.print("() - not implemented\n");

#if 0
   uint8_t  *info8  = (uint8_t*) information;
   uint32_t *info32 = (uint32_t*)information;

   uint32_t *pData = (uint32_t *)info32[1];

   log.print("- &information = %p \n"
                  "               information = %p \n"
                  "              &DiProcess() = %p \n",
                  &information, information, &DiProcess);

   log.print("information[0] = %p \n"
                  "information[1] = %p \n"
                  "information[2] = %p \n",
                  info32[0],info32[1],info32[2]);

   log.print("- not implemented, data = \n"
             "=================================================================\n");
   UsbdmSystem::Log::Dump(info8, 0x100, (uint32_t)info8);
   log.print("=================================================================\n");

   log.print("- data = \n"
             "=================================================================\n");
   UsbdmSystem::Log::Dump((uint8_t*)pData, 0x100, (uint32_t)pData);
   log.print("=================================================================\n");
#endif
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

/*
 * ==========================================================================================
 * ==========================================================================================
 */

#ifdef __unix__
//TODO Move
#if   TARGET == ARM
#define GDI_DLL_NAME "usbdm-gdi-arm-debug.so"
#elif TARGET == CFV1
#define GDI_DLL_NAME "usbdm-gdi-cfv1-debug.so"
#elif TARGET == CFVx
#define GDI_DLL_NAME "usbdm-gdi-cfvx-debug.so"
#elif TARGET == MC56F80xx
#define GDI_DLL_NAME "usbdm-gdi-dsc-debug.so"
#elif TARGET == HCS08
#define GDI_DLL_NAME "usbdm-gdi-hcs08-debug.so"
#elif TARGET == HCS12
#define GDI_DLL_NAME "usbdm-gdi-hcs12-debug.so"
#elif TARGET == S12Z
#define GDI_DLL_NAME "usbdm-gdi-hcs12z-debug.so"
#elif TARGET == RS08
#define GDI_DLL_NAME "usbdm-gdi-rs08-debug.so"
#endif

extern "C"
void __attribute__ ((constructor)) gdi_dll_initialize(void) {
   static void *libHandle = nullptr;

   // Lock Library in memory!
   if (libHandle == nullptr) {
      libHandle = dlopen(GDI_DLL_NAME, RTLD_NOW|RTLD_NODELETE);
      if (libHandle == nullptr) {
         fprintf(stderr, "gdi_dll_initialize() - Library failed to lock %s\n", dlerror());
         return;
      }
      else
         fprintf(stderr, "gdi_dll_initialize() - Library locked OK\n");
   }
   else
      fprintf(stderr, "gdi_dll_initialize() - Library already locked\n");
   // Load wxWindows Stub
   (void)dlopen(WXSTUB_DLL_NAME, RTLD_NOW|RTLD_NODELETE);
}

extern "C"
void __attribute__ ((destructor)) gdi_dll_uninitialize(void) {
}

#endif

#ifdef _WIN32
// This creates aliases for the the GDI routines with underscores in the names
#include "GDI_underscores.h"
#endif
