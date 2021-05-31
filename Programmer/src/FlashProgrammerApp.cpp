/*! \file
    \brief Flash Programming App

    FlashProgrammerApp.cpp

    \verbatim
    USBDM
    Copyright (C) 2009  Peter O'Donoghue

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
   -=========================================================================================
   | 15 Mar 2015 | Complete redesign using wxFormBuilder                   - pgo V4.10.6.260
   +=========================================================================================
   \endverbatim
*/
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/wx.h>
#include <wx/cmdline.h>
#include <wx/stdpaths.h>

#include "ProgrammerDialogue.h"

#include "UsbdmSystem.h"
#include "Common.h"
#include "DeviceData.h"
#include "BdmInterfaceFactory.h"
#include "DeviceInterface.h"

#include "FlashProgrammerFactory.h"
#include "UsbdmWxConstants.h"

using namespace std;

#define CONFIG_FILE_NAME "FlashProgrammer_"

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("Flashprogrammer.log", "Flash Programmer");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
      UsbdmSystem::Log::closeLogFile();
   }
};

// Declare the application class
class FlashProgrammerApp : public wxApp {
   DECLARE_CLASS( FlashProgrammerApp )
   DECLARE_EVENT_TABLE()

private:
   TargetType_t                 targetType;
   std::string                  customSecurityValue;
   bool                         useGUI;
   bool                         verify;
   bool                         program;
   bool                         verbose;
   wxString                     hexFileName;
   double                       trimFrequency;
   long                         trimNVAddress;
   OpenLog                      openLog;
   BdmInterfacePtr              bdmInterface;
   DeviceInterfacePtr           deviceInterface;
   USBDM_ErrorCode              commandLineRC;
   AppSettings                  appSettings;

   USBDM_ErrorCode doCommandLineProgram();
   USBDM_ErrorCode parseCommandLine(wxCmdLineParser& parser);

public:
   FlashProgrammerApp();

   // Called on application startup
   virtual bool OnInit();
   virtual int  OnExit();
   virtual int  OnRun();
   virtual void OnInitCmdLine(wxCmdLineParser& parser);
   virtual void logUsageError(wxCmdLineParser& parser, const wxString& text);
   virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
   virtual ~FlashProgrammerApp();
};

// Implements FlashProgrammerApp& GetApp()
DECLARE_APP(FlashProgrammerApp)
IMPLEMENT_APP(FlashProgrammerApp)

/*
 * FlashProgrammerApp type definition
 */
IMPLEMENT_CLASS(FlashProgrammerApp, wxApp)

/*
 * FlashProgrammerApp event table definition
 */
BEGIN_EVENT_TABLE( FlashProgrammerApp, wxApp )

END_EVENT_TABLE()

FlashProgrammerApp::FlashProgrammerApp() :
   targetType(T_ARM),
   openLog(),
   appSettings(CONFIG_FILE_NAME, targetType, "Programmer settings"){
   useGUI         = true;
   trimNVAddress  = 0;
   verbose        = false;
   trimFrequency  = 0;
   verify         = false;
   program        = false;
//   dialogue       = 0;
   commandLineRC  = BDM_RC_OK;
}

USBDM_ErrorCode programmerCallBack(USBDM_ErrorCode status, int percent, const char *message) {
   fprintf(stdout, "%d%%: %s", percent, message);
   return status;
}

/**
 * Command line operation
 *
 * @return Error code
 */
USBDM_ErrorCode FlashProgrammerApp::doCommandLineProgram() {
   LOGGING;
   FlashImagePtr      flashImage      = FlashImageFactory::createFlashImage(targetType);
   FlashProgrammerPtr flashProgrammer = FlashProgrammerFactory::createFlashProgrammer(bdmInterface);
   USBDM_ErrorCode    returnValue = BDM_RC_OK;

   do {
      // Initialise the BDM
      returnValue = bdmInterface->initBdm();
      if (returnValue != BDM_RC_OK) {
         break;
      }
      if (!hexFileName.IsEmpty()) {
         returnValue = flashImage->loadFile((const char *)hexFileName.c_str(), targetType);
         if (returnValue != BDM_RC_OK) {
            break;
         }
      }
      // Copy device description and change mutable settings
      DeviceDataPtr &deviceData = deviceInterface->getCurrentDevice();
      if (deviceData->getSecurity() == SEC_CUSTOM) {
         deviceData->setCustomSecurity(customSecurityValue);
      }
      returnValue = flashProgrammer->setDeviceData(deviceData);
      if (returnValue != BDM_RC_OK) {
         break;
      }
      if (program) {
         // Program & Verify
         if (verbose) {
            returnValue = flashProgrammer->programFlash(flashImage, programmerCallBack);
         }
         else {
            returnValue = flashProgrammer->programFlash(flashImage, NULL);
         }

      }
      else {
         // Verify only
         if (verbose) {
            returnValue = flashProgrammer->verifyFlash(flashImage, programmerCallBack);
         }
         else{
            returnValue = flashProgrammer->verifyFlash(flashImage);
         }
      }
      if (returnValue != PROGRAMMING_RC_OK) {
         break;
      }
   } while (false);
   if (returnValue != PROGRAMMING_RC_OK) {
      log.error("Failed, rc = %s\n", bdmInterface->getErrorString(returnValue));
   }
   log.print(" Closing BDM\n");
   if (bdmInterface->getBdmOptions().leaveTargetPowered) {
      bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_NORMAL));
   }
   bdmInterface->closeBdm();

#ifdef __unix__
   if (verbose && (returnValue == 0)) {
      fprintf(stdout, "Operation completed successfully\n");
   }
#endif
   return returnValue;
}

bool FlashProgrammerApp::OnInit() {
   LOGGING;

#ifndef _WIN32
   // Otherwise wxWidgets doesn't look in the correct location
   ((wxStandardPaths&)wxStandardPaths::Get()).SetInstallPrefix(_(USBDM_INSTALL_DIRECTORY));
#endif

   SetAppName(_("usbdm")); // So application files are kept in the correct directory

   // Call for default command parsing behaviour
   if (!wxApp::OnInit()) {
      log.error("Failed OnInit()\n");
      return true; // Return true here as we want OnRun() to execute
   }

#if TARGET == MC56F80xx
   DSC_SetLogFile(0);
#endif

   return true;
}

int FlashProgrammerApp::OnRun(void) {
   LOGGING;

   if (commandLineRC != BDM_RC_OK) {
      return commandLineRC;
   }

   USBDM_ErrorCode returnValue = BDM_RC_OK;
   if (useGUI) {

      // Load interactive settings
      appSettings.load();

      // Create the main application window
      ProgrammerDialogue *dialogue = new ProgrammerDialogue(NULL, bdmInterface, deviceInterface, appSettings);

//      SetTopWindow((wxWindow*)dialogue);
      USBDM_ErrorCode rc =  dialogue->execute(hexFileName);
      if (rc == BDM_RC_OK) {
         // Save changed settings
         appSettings.save();
      }
//         wxApp::OnRun();
   }
   else {
      returnValue = doCommandLineProgram();
   }
   if (returnValue != PROGRAMMING_RC_OK) {
      log.error("Failed, rc = %s\n", bdmInterface->getErrorString(returnValue));
#ifdef __unix__
      fprintf(stderr, "Programming failed, rc = %d, %s\n", returnValue, bdmInterface->getErrorString(returnValue));
#endif
   }
   return returnValue;
}

int FlashProgrammerApp::OnExit(void) {
   LOGGING;

   bdmInterface.reset();

   return wxApp::OnExit();
}

FlashProgrammerApp::~FlashProgrammerApp() {
}

static const wxCmdLineEntryDesc g_cmdLineDesc[] = {
      { wxCMD_LINE_PARAM,    NULL,             NULL, _("Name of the S19 Hex file to load"),                               wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
      { wxCMD_LINE_OPTION, _("bdm"),           NULL, _("Serial number of preferred BDM to use"),                          wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, _("requiredBdm"),   NULL, _("Serial number of required BDM to use"),                           wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, _("device"),        NULL, _("Target device e.g. MCF51CN128"),                                  wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, _("erase"),         NULL, _("Erase method (Mass, All, Selective, Vendor, None)"),     wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, _("execute"),       NULL, _("Leave target power on & reset to normal mode at completion"), },
      { wxCMD_LINE_OPTION, _("flexNVM"),       NULL, _("FlexNVM parameters (eeprom,partition hex values)"),               wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, _("masserase"),     NULL, _("Equivalent to erase=Mass") },
      { wxCMD_LINE_SWITCH, _("noerase"),       NULL, _("Equivalent to erase=None") },
      { wxCMD_LINE_OPTION, _("nvloc"),         NULL, _("Trim non-volatile memory location (hex)"),                        wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, _("power"),         NULL, _("Power timing (off,recovery) 100-10000 ms"),                       wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, _("program"),       NULL, _("Program and verify flash contents"), },
      { wxCMD_LINE_OPTION, _("reset"),         NULL, _("Reset timing (active,release,recovery) 100-10000 ms"),            wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, _("resetMethod"),   NULL, _("Reset method (hardware, software, vendor)"),                      wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, _("security"),      NULL, _("Device security (unsecured, image, smart)"),                      wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, _("securityValue"), NULL, _("Explicit security value to use (as hex string)"),                 wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, _("secure"),        NULL, _("Leave device secure after programming") },
      { wxCMD_LINE_OPTION, _("speed"),         NULL, _("Interface speed (CFVx/Kinetis/DSC) kHz"),                         wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, _("trim"),          NULL, _("Trim internal clock to frequency (in kHz) e.g. 32.7"),            wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, _("target"),        NULL, _("Target type (RS08, HCS08, HCS12, S12Z, CFV1, CFVX, ARM, MC56F)"), wxCMD_LINE_VAL_STRING },
#ifdef __unix__
      { wxCMD_LINE_SWITCH, _("verbose"),       NULL, _("Print progress messages to stdout") },
#endif
      { wxCMD_LINE_SWITCH, _("useReset"),      NULL, _("Use hardware reset"),                                             wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, _("unsecure"),      NULL, _("Leave device unsecure after programming") },
      { wxCMD_LINE_OPTION, _("vdd"),           NULL, _("Supply Vdd to target (3V3 or 5V)"),                                wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, _("verify"),        NULL, _("Verify flash contents") },
      { wxCMD_LINE_NONE }
};

void FlashProgrammerApp::OnInitCmdLine(wxCmdLineParser& parser) {
    parser.SetDesc (g_cmdLineDesc);
    // must refuse '/' as parameter starter or cannot use "/path" style paths
    parser.SetSwitchChars (_("-"));
    parser.SetLogo(_("USBDM Flash Programmer \n"));

#if (wxCHECK_VERSION(2, 9, 0))
   parser.AddUsageText(_(
          "\nExamples:\n"
          "Programming an image with clock trimming:\n"
          "  FlashProgrammer -target=hcs08 Image.s19 -device=MC9S08AW16A -trim=243 -program -secure\n"
          "This will program a MC9S08AW16A with the contents of the file Image.s19 and\n"
          "trim the internal clock to 243kHz. The Flash image will be modified so that\n"
          "the device will be secure after programming.\n\n"
          "Programming the clock trim in an already programmed chip:\n"
          "  FlashProgrammer -target=hcs08 -device=MC9S08QG8 -trim=35.25 -erase=None -program \n"
          "This will trim the internal clock of MC9S08QG8 to 35.25kHz without erasing\n"
          "the present flash contents. It is necessary that the clock trim locations \n"
          "in flash are still unprogrammed (0xFF) when using the -trim option. The \n"
          "target must not be secured and cannot be made secured when using -erase=None.\n\n"
          "Programming image with custom security value:\n"
          "  FlashProgrammer -target=arm -device=MKL25Z128M4 -vdd=3v3 -erase=mass -program -securityValue=123456789ABCDEF0FFFFFFFFFEFFFFFF Image.elf"
          ));
#endif
}

void FlashProgrammerApp::logUsageError(wxCmdLineParser& parser, const wxString& text){
   UsbdmSystem::Log::error("%s", (const char *)text.c_str());
#if (wxCHECK_VERSION(2, 9, 0))
   parser.AddUsageText(text);
#endif
}

/*!
 * This callback will cause connections etc to fail quietly on error rather
 * than use a WxWidget dialogue.
 * Used for command line mode
 */
static long connectionNullCallback(std::string message, std::string  caption, long style) {
   return UsbdmWxConstants::NO;
}

/*!
 * This callback will display a WxWidget dialogue
 * Used for GUI mode
 */
static long connectionCallback(std::string message, std::string  caption, long style) {
   return wxMessageBox(message, caption, style);
}

/**
 * Process command line arguments
 *
 * @return  error code
 *
 * @note commandLineRC is set to error code on failure
 */
bool FlashProgrammerApp::OnCmdLineParsed(wxCmdLineParser& parser) {

   commandLineRC  = parseCommandLine(parser);
   if (commandLineRC != BDM_RC_OK) {
      parser.Usage();
      return false;
   }
   return true;
}

/**
 * Process command line arguments
 *
 * @return  true  success
 *          false command line parse failure
 *
 * @note commandLineRC is set to error code on failure
 */
USBDM_ErrorCode FlashProgrammerApp::parseCommandLine(wxCmdLineParser& parser) {
   LOGGING;
   wxString  sValue;

   useGUI             = true;
   verbose            = false;
   USBDM_ErrorCode rc = BDM_RC_OK;

   if (parser.GetParamCount() > 0) {
      // File to load may always be given as only param
      hexFileName = parser.GetParam(0);
   }

   // "-target=..." option may always be given
   if (parser.Found(_("target"), &sValue)) {
      if (sValue.CmpNoCase(_("rs08")) == 0) {
         targetType = T_RS08;
      }
      else if (sValue.CmpNoCase(_("hcs08")) == 0) {
         targetType = T_HCS08;
      }
      else if (sValue.CmpNoCase(_("hcs12")) == 0) {
         targetType = T_HCS12;
      }
      else if (sValue.CmpNoCase(_("cfv1")) == 0) {
         targetType = T_CFV1;
      }
      else if (sValue.CmpNoCase(_("cfvx")) == 0) {
         targetType = T_CFVx;
      }
      else if (sValue.CmpNoCase(_("arm")) == 0) {
         targetType = T_ARM;
      }
      else if (sValue.CmpNoCase(_("mc56f")) == 0) {
         targetType = T_MC56F80xx;
      }
      else if (sValue.CmpNoCase(_("s12z")) == 0) {
         targetType = T_S12Z;
      }
      else if (sValue.CmpNoCase(_("mc56f8")) == 0) {
         targetType = T_MC56F80xx;
      }
      else {
         logUsageError(parser, _("***** Error: Illegal target type.\n"));
         return(BDM_RC_ILLEGAL_PARAMS);
      }
   }
   else {
      // Determine target from name of program
      wxString argv0(argv[0]);
      if (argv0.Contains(_("RS08"))) {
         log.print("Setting target RS08\n");
         targetType = T_RS08;
      }
      else if (argv0.Contains(_("HCS08"))) {
         log.print("Setting target HCS08\n");
         targetType = T_HCS08;
      }
      else if (argv0.Contains(_("HCS12"))) {
         log.print("Setting target HCS12\n");
         targetType = T_HCS12;
      }
      else if (argv0.Contains(_("CFV1"))) {
         log.print("Setting target CFV1\n");
         targetType = T_CFV1;
      }
      else if (argv0.Contains(_("CFVX"))) {
         log.print("Setting target CFVX\n");
         targetType = T_CFVx;
      }
      else if (argv0.Contains(_("ARM"))) {
         log.print("Setting target ARM\n");
         targetType = T_ARM;
      }
      else if (argv0.Contains(_("MC56F"))) {
         log.print("Setting target MC56F\n");
         targetType = T_MC56F80xx;
      }
      else if (argv0.Contains(_("S12Z"))) {
         log.print("Setting target S12Z\n");
         targetType = T_S12Z;
      }
      else if (argv0.Contains(_("MC56F"))) {
         log.print("Setting target T_MC56F80xx\n");
         targetType = T_MC56F80xx;
      }
      else {
         log.print("Setting default target ARM\n");
         targetType = T_ARM;
      }
   }

   // Ignore other options unless "verify" or "program" are given
   if (!parser.Found("verify") && !parser.Found("program")) {
      bdmInterface = BdmInterfaceFactory::createInterface(targetType, connectionCallback);
      deviceInterface.reset(new DeviceInterface(targetType));
      return BDM_RC_OK;
   }

   bdmInterface = BdmInterfaceFactory::createInterface(targetType, connectionNullCallback);
   deviceInterface.reset(new DeviceInterface(targetType));
   useGUI = false;

#ifdef __unix__
   if (parser.Found(_("verbose"))) {
      verbose = true;
   }
#endif

   // Command line requires at least a device name
   if (!parser.Found(_("device"), &sValue)) {
      logUsageError(parser, _("***** Error: Device Option missing.\n"));
      return(BDM_RC_ILLEGAL_PARAMS);
   }

   rc = deviceInterface->setCurrentDeviceByName((const char *)sValue.c_str());
   if (rc != BDM_RC_OK) {
      log.error("Failed to set device to \'%s\'\n", (const char *)sValue.c_str());
      logUsageError(parser, _("***** Error: Failed to find device.\n"));
      return rc;
   }

   USBDM_ExtendedOptions_t &bdmOptions = bdmInterface->getBdmOptions();
   DeviceDataPtr            deviceData = deviceInterface->getCurrentDevice();

   // Disable clock trim by default
   deviceData->setClockTrimFreq(0);

   if (parser.Found(_("masserase"))) {
      deviceData->setEraseMethod(DeviceData::eraseMass);
   }
   if (parser.Found(_("noerase"))) {
      deviceData->setEraseMethod(DeviceData::eraseNone);
   }
   if (parser.Found(_("secure"))) {
      deviceData->setSecurity(SEC_SECURED);
   }
   else if (parser.Found(_("unsecure"))) {
      deviceData->setSecurity(SEC_UNSECURED);
   }
   else {
      deviceData->setSecurity(SEC_DEFAULT);
   }
   if (parser.Found(_("security"), &sValue)) {
      if (sValue.CmpNoCase(_("Smart")) == 0) {
         deviceData->setSecurity(SEC_SMART);
      }
      else if (sValue.CmpNoCase(_("Image")) == 0) {
         deviceData->setSecurity(SEC_DEFAULT);
      }
      else if (sValue.CmpNoCase(_("Unsecured")) == 0) {
         deviceData->setSecurity(SEC_UNSECURED);
      }
      else if (sValue.CmpNoCase(_("Secured")) == 0) {
         deviceData->setSecurity(SEC_SECURED);
      }
      else {
         logUsageError(parser, _("***** Error: Illegal security value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
   }
   if (parser.Found(_("securityValue"), &sValue)) {
      if (deviceData->getSecurity() != SEC_DEFAULT) {
         // Can't use this option with secure/unsecure
         logUsageError(parser, _("***** Error: Conflicting security values.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      else {
         deviceData->setSecurity(SEC_CUSTOM);
         customSecurityValue = std::string(sValue.c_str());
      }
   }
   verify   = parser.Found(_("verify"));
   program  = parser.Found(_("program"));

   if (parser.Found(_("nvloc"), &sValue)) {
      unsigned long uValue;
      if (!sValue.ToULong(&uValue, 16)) {
         logUsageError(parser, _("***** Error: Illegal nvloc value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      deviceData->setClockTrimNVAddress(uValue);
   }
   if (parser.Found(_("erase"), &sValue)) {
      if (sValue.CmpNoCase(_("Mass")) == 0) {
         deviceData->setEraseMethod(DeviceData::eraseMass);
      }
      else if (sValue.CmpNoCase(_("All")) == 0) {
         deviceData->setEraseMethod(DeviceData::eraseAll);
      }
      else if (sValue.CmpNoCase(_("Selective")) == 0) {
         deviceData->setEraseMethod(DeviceData::eraseSelective);
      }
      else if (sValue.CmpNoCase(_("Vendor")) == 0) {
         deviceData->setEraseMethod(DeviceData::eraseTargetDefault);
      }
      else if (sValue.CmpNoCase(_("None")) == 0) {
         deviceData->setEraseMethod(DeviceData::eraseNone);
      }
      else {
         logUsageError(parser, _("***** Error: Illegal erase value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
   }
   if (parser.Found(_("resetMethod"), &sValue)) {
      if (sValue.CmpNoCase(_("Hardware")) == 0) {
         deviceData->setResetMethod(DeviceData::resetHardware);
      }
      else if (sValue.CmpNoCase(_("Software")) == 0) {
         deviceData->setResetMethod(DeviceData::resetSoftware);
      }
      else if (sValue.CmpNoCase(_("Vendor")) == 0) {
         deviceData->setResetMethod(DeviceData::resetVendor);
      }
      else {
         logUsageError(parser, _("***** Error: Illegal erase value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
   }
   if (parser.Found(_("vdd"), &sValue)) {
      if (sValue.CmpNoCase(_("3V3")) == 0) {
         bdmOptions.targetVdd = BDM_TARGET_VDD_3V3;
      }
      else if (sValue.CmpNoCase(_("5V")) == 0) {
         bdmOptions.targetVdd = BDM_TARGET_VDD_5V;
      }
      else {
         logUsageError(parser, _("***** Error: Illegal vdd value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
   }
   if (parser.Found(_("bdm"), &sValue)) {
      bdmInterface->setBdmSerialNumber((const char *)sValue.c_str(), false);
   }
   if (parser.Found(_("requiredBdm"), &sValue)) {
      bdmInterface->setBdmSerialNumber(sValue.ToStdString(), true);
   }
   if (parser.Found(_("trim"), &sValue)) {
      double    dValue;
      if (!sValue.ToDouble(&dValue)) {
         logUsageError(parser, _("***** Error: Illegal trim value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      deviceData->setClockTrimFreq(dValue * 1000);
   }
   else {
      trimFrequency = 0;
   }
   // flexNVM options
   if (parser.Found(_("flexNVM"), &sValue)) {
      DeviceData::FlexNVMParameters flexParameters;
      unsigned long uValue;

      int index1 = 0;
      int index2 = sValue.find(',');
      wxString t = sValue.substr(index1, index2-index1);
      if (!t.ToULong(&uValue, 16)) {
         logUsageError(parser, _("***** Error: Illegal flexNVM value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      flexParameters.eeepromSize = (uint8_t)uValue;
      // Check for truncation
      if (flexParameters.eeepromSize != uValue) {
         logUsageError(parser, _("***** Error: Illegal flexNVM value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      index1 = index2+1;
      index2 = sValue.find(',', index1);
      t = sValue.substr(index1, index2-index1);
      if (!t.ToULong(&uValue, 16)) {
         logUsageError(parser, _("***** Error: Illegal flexNVM value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      flexParameters.partionValue = (uint8_t)uValue;
      // Check for truncation
      if (flexParameters.partionValue != uValue) {
         logUsageError(parser, _("***** Error: Illegal flexNVM value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      flexParameters.partionValue = (uint8_t)uValue;
      deviceData->setFlexNVMParameters(flexParameters);
   }
   // Reset options
   bdmOptions.useResetSignal = parser.Found(_("useReset"));
   if (parser.Found(_("reset"), &sValue)) {
      unsigned long uValue=100000; // invalid so faults later

      int index1 = 0;
      int index2 = sValue.find(',');
      wxString t = sValue.substr(index1, index2-index1);
      if (!t.ToULong(&uValue, 10)) {
         logUsageError(parser, _("***** Error: Illegal reset value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      bdmOptions.resetDuration = uValue;

      index1 = index2+1;
      index2 = sValue.find(',', index1);
      t = sValue.substr(index1, index2-index1);
      if (!t.ToULong(&uValue, 10)) {
         logUsageError(parser, _("***** Error: Illegal reset value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      bdmOptions.resetReleaseInterval = uValue;

      index1 = index2+1;
      index2 = sValue.length();
      t = sValue.substr(index1, index2-index1);
      if (!t.ToULong(&uValue, 10)) {
         logUsageError(parser, _("***** Error: Illegal reset value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      bdmOptions.resetRecoveryInterval = uValue;
   }
   // Power options
   if (parser.Found(_("power"), &sValue)) {
      unsigned long uValue=100000; // invalid so faults later

      int index1 = 0;
      int index2 = sValue.find(',');
      wxString t = sValue.substr(index1, index2-index1);
      if (!t.ToULong(&uValue, 10)) {
         logUsageError(parser, _("***** Error: Illegal power value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      bdmOptions.powerOffDuration = uValue;

      index1 = index2+1;
      index2 = sValue.length();
      t = sValue.substr(index1, index2-index1);
      if (!t.ToULong(&uValue, 10)) {
         logUsageError(parser, _("***** Error: Illegal power value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      bdmOptions.powerOnRecoveryInterval = uValue;
   }
   if (parser.Found(_("speed"), &sValue)) {
      unsigned long uValue;
      if (!sValue.ToULong(&uValue, 10)) {
         logUsageError(parser, _("***** Error: Illegal speed value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      bdmOptions.interfaceFrequency = uValue;
   }
   bdmOptions.leaveTargetPowered = parser.Found(_("execute"));
   // Programming includes verification
   if (program) {
      verify = false;
   }
   return BDM_RC_OK;
}

