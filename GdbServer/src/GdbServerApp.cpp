/*! \file
    \brief Flash Programming App

    GDBServerApp.cpp

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

#include "GdbServerDialogue.h"
#include "GdbServerWindow.h"

#include "UsbdmSystem.h"
#include "Common.h"
#include "DeviceData.h"
#include "BdmInterfaceFactory.h"
#include "DeviceInterface.h"

#include "FlashProgrammerFactory.h"

using namespace std;

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("GDBServer.log", "GDB Server");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
      UsbdmSystem::Log::closeLogFile();
   }
};

// Declare the application class
class GdbServerApp : public wxApp {
   DECLARE_CLASS( GdbServerApp )
   DECLARE_EVENT_TABLE()

private:
   TargetType_t                 targetType;
   std::string                  customSecurityValue;
   bool                         useGUI;
   bool                         verify;
   bool                         program;
   double                       trimFrequency;
   long                         trimNVAddress;
   OpenLog                      openLog;
   BdmInterfacePtr              bdmInterface;
   DeviceInterfacePtr           deviceInterface;
   USBDM_ErrorCode              commandLineRC;

   USBDM_ErrorCode parseCommandLine(wxCmdLineParser& parser);

public:
   GdbServerApp();

   // Called on application startup
   virtual bool OnInit();
   virtual int  OnExit();
   virtual int  OnRun();
   virtual void OnInitCmdLine(wxCmdLineParser& parser);
   virtual void logUsageError(wxCmdLineParser& parser, const wxString& text);
   virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
   virtual ~GdbServerApp();
};

// Implements GDBServerApp& GetApp()
DECLARE_APP(GdbServerApp)
IMPLEMENT_APP(GdbServerApp)

/*
 * GDBServerApp type definition
 */
IMPLEMENT_CLASS(GdbServerApp, wxApp)

/*
 * GDBServerApp event table definition
 */
BEGIN_EVENT_TABLE( GdbServerApp, wxApp )

END_EVENT_TABLE()

GdbServerApp::GdbServerApp() :
   targetType(T_ARM),
   openLog() {
   useGUI         = true;
   trimNVAddress  = 0;
   trimFrequency  = 0;
   verify         = false;
   program        = false;
   commandLineRC  = BDM_RC_OK;
}

USBDM_ErrorCode callBack(USBDM_ErrorCode status, int percent, const char *message) {
   fprintf(stdout, "%d%%: %s", percent, message);
   return status;
}


bool GdbServerApp::OnInit() {
   LOGGING_E;

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

   GdbServerWindow *serverWindow = new GdbServerWindow(bdmInterface, deviceInterface, useGUI);
   serverWindow->SetTitle(_("GDB Server"));
   SetTopWindow(serverWindow);
   serverWindow->execute();

   return true;
}

int GdbServerApp::OnRun(void) {
   LOGGING_Q;

   if (commandLineRC != BDM_RC_OK) {
      return commandLineRC;
   }
   int exitcode = wxApp::OnRun();

   // Everything is done in OnInit()!
   log.print(" - return value = %d\n", exitcode);
   return exitcode;
}

int GdbServerApp::OnExit(void) {
   LOGGING;

   bdmInterface.reset();

   return wxApp::OnExit();
}

GdbServerApp::~GdbServerApp() {
}

static const wxCmdLineEntryDesc g_cmdLineDesc[] = {
      { wxCMD_LINE_OPTION, "auto",          NULL, "Auto-reconnect option (never, status, always)",                  wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "bdm",           NULL, "Serial number of preferred BDM to use",                          wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "requiredBdm",   NULL, "Serial number of required BDM to use",                           wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, "catchvlls",     NULL, "Catch VLLSx resets",                                             wxCMD_LINE_VAL_NONE   },
      { wxCMD_LINE_OPTION, "device",        NULL, "Target device e.g. MCF51CN128",                                  wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "erase",         NULL, "Erase method (Mass, All, Selective, Vendor, None)",              wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, "exitOnClose",   NULL, "Exit Server when connection closed",                             wxCMD_LINE_VAL_NONE   },
      { wxCMD_LINE_OPTION, "flexNVM",       NULL, "FlexNVM parameters (eeprom,partition hex values)",               wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, "masserase",     NULL, "Equivalent to erase=Mass"                                                              },
      { wxCMD_LINE_SWITCH, "maskInterrupts",NULL, "Mask interrupts when stepping"                                                         },
      { wxCMD_LINE_SWITCH, "noerase",       NULL, "Equivalent to erase=None"                                                              },
      { wxCMD_LINE_OPTION, "nvloc",         NULL, "Trim non-volatile memory location (hex)",                        wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "power",         NULL, "Power timing (off,recovery) 100-10000 ms",                       wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "port",          NULL, "Server port # to use for GDB e.g. 1234",                         wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "reset",         NULL, "Reset timing (active,release,recovery) 100-10000 ms",            wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "resetMethod",   NULL, "Reset method (hardware, software, vendor)",                      wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "security",      NULL, "Device security (unsecured, image, smart)",                      wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "securityValue", NULL, "Explicit security value to use (as hex string)",                 wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, "secure",        NULL, "Leave device secure after programming"                                                 },
      { wxCMD_LINE_OPTION, "speed",         NULL, "Interface speed (CFVx/Kinetis/DSC) kHz",                         wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "trim",          NULL, "Trim internal clock to frequency (in kHz) e.g. 32.7",            wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "target",        NULL, "Target type (CFV1, CFVX, ARM)",                                  wxCMD_LINE_VAL_STRING },
#ifdef _UNIX_
      { wxCMD_LINE_SWITCH, "verbose",       NULL, "Print progress messages to stdout"                                                     },
#endif
      { wxCMD_LINE_SWITCH, "useReset",      NULL, "Use hardware reset",                                             wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH, "unsecure",      NULL, "Leave device unsecure after programming"                                               },
      { wxCMD_LINE_OPTION, "timeout",       NULL, "Connection timeout (seconds), 0 indicates indefinite",           wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "tty",           NULL, "Port # to use for semi-hosting TTY e.g. 4321",                   wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_OPTION, "vdd",           NULL, "Supply Vdd to target (3V3 or 5V)",                               wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_NONE }
};

void GdbServerApp::OnInitCmdLine(wxCmdLineParser& parser) {
    parser.SetDesc (g_cmdLineDesc);
    // must refuse '/' as parameter starter or cannot use "/path" style paths
    parser.SetSwitchChars (_("-"));
    parser.SetLogo(_("USBDM GDB Server \n"));

#if (wxCHECK_VERSION(2, 9, 0))
    parser.AddUsageText(_("\n"
          "Notes: \n"
          "  - If a device is given then the opening dialogue is skipped and the server is started immediately.\n"
          "    Also in this case changes to settings are discarded on exit."
          "\nExample:\n"
          "Start server:\n"
          "  GDBServer -target=cfv1 -device=MCF51CN128 -port=1234 -trim=243\n"
          "This will start the server on localhost:1234 for a MCF51CN128 device and\n"
          "trim the internal clock to 243kHz when programming. \n\n"
          ));
#endif
}

void GdbServerApp::logUsageError(wxCmdLineParser& parser, const wxString& text){
   UsbdmSystem::Log::error("%s", (const char *)text.c_str());
#if (wxCHECK_VERSION(2, 9, 0))
   parser.AddUsageText(text);
#endif
}

/**
 * Process command line arguments
 *
 * @return  error code
 *
 * @note commandLineRC is set to error code on failure
 */
bool GdbServerApp::OnCmdLineParsed(wxCmdLineParser& parser) {

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
USBDM_ErrorCode GdbServerApp::parseCommandLine(wxCmdLineParser& parser) {
   LOGGING;
   wxString  sValue;

   useGUI = true;

   // "-target=..." option may always be given
   if (parser.Found(_("target"), &sValue)) {
      if (sValue.CmpNoCase(_("cfv1")) == 0) {
         targetType = T_CFV1;
      }
      else if (sValue.CmpNoCase(_("cfvx")) == 0) {
         targetType = T_CFVx;
      }
      else if (sValue.CmpNoCase(_("arm")) == 0) {
         targetType = T_ARM;
      }
      else {
         logUsageError(parser, _("***** Error: Illegal target type.\n"));
         return(BDM_RC_ILLEGAL_PARAMS);
      }
   }
   else {
      // Determine target from name of program
      wxString argv0(argv[0]);

      if (argv0.Contains(_("CFV1"))) {
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
      else {
         log.print("Setting default target ARM\n");
         targetType = T_ARM;
      }
   }
   bdmInterface = BdmInterfaceFactory::createInterface(targetType);
   deviceInterface.reset(new DeviceInterface(targetType));

   /*
    * If no device is given then server ignores all options and opens in GUI mode
    * It will also load default parameters.
    */
   if (!parser.Found(_("device"), &sValue)) {
      return BDM_RC_OK;
   }

   /*
    *  If a device name is given the server will open without the GUI configuration dialogue
    *  and it will not load default parameters nor save them when finished.
    *  This is to allow use of the server from command line or when launched from another application e.g. Eclipse.
    */
   useGUI = false;

#ifdef _UNIX_
   if (parser.Found(_("verbose"))) {
      verbose = true;
   }
#endif

   // Command line requires at least a device name
   USBDM_ErrorCode rc = deviceInterface->setCurrentDeviceByName((const char *)sValue.c_str());
   if (rc != BDM_RC_OK) {
      log.error("Failed to set device to \'%s\'\n", (const char *)sValue.c_str());
      logUsageError(parser, _("***** Error: Failed to find device.\n"));
      return rc;
   }

   USBDM_ExtendedOptions_t &bdmOptions = bdmInterface->getBdmOptions();
   DeviceDataPtr            deviceData = deviceInterface->getCurrentDevice();

   // Disable clock trim by default
   deviceData->setClockTrimFreq(0);

   bdmInterface->setMaskISR(parser.Found(_("maskInterrupts")));
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

   if (parser.Found(_("nvloc"), &sValue)) {
      unsigned long uValue;
      if (!sValue.ToULong(&uValue, 16)) {
         logUsageError(parser, _("***** Error: Illegal nvloc value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      deviceData->setClockTrimNVAddress(uValue);
   }
   bdmInterface->setExitOnClose(parser.Found(_("exitOnClose")));
   bdmInterface->setCatchVLLSx(parser.Found(_("catchvlls")));

   if (parser.Found(_("auto"), &sValue)) {
      if (sValue.CmpNoCase(_("never")) == 0) {
         bdmOptions.autoReconnect = AUTOCONNECT_NEVER;
      }
      else if (sValue.CmpNoCase(_("status")) == 0) {
         bdmOptions.autoReconnect = AUTOCONNECT_STATUS;
      }
      else if (sValue.CmpNoCase(_("always")) == 0) {
         bdmOptions.autoReconnect = AUTOCONNECT_ALWAYS;
      }
      else {
         logUsageError(parser, _("***** Error: Illegal auto value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
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
   if (parser.Found(_("port"), &sValue)) {
      unsigned long uValue;
      if (!sValue.ToULong(&uValue, 10)) {
         logUsageError(parser, _("***** Error: Illegal GDB port value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      bdmInterface->setGdbServerPort(uValue);
   }
   if (parser.Found(_("tty"), &sValue)) {
      unsigned long uValue;
      if (!sValue.ToULong(&uValue, 10)) {
         logUsageError(parser, _("***** Error: Illegal TTY port value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      bdmInterface->setGdbTtyPort(uValue);
   }
   if (parser.Found(_("timeout"), &sValue)) {
      unsigned long uValue;
      if (!sValue.ToULong(&uValue, 10)) {
         logUsageError(parser, _("***** Error: Illegal timeout value.\n"));
         return BDM_RC_ILLEGAL_PARAMS;
      }
      bdmInterface->setConnectionTimeout(uValue);
   }
   return BDM_RC_OK;
}

