/*! \file
    \brief Implements USBDM Flash Programmer dialogue

    ProgrammerDialogue.cpp

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
   |  7 Aug 2015 | Changed handling of corrupt database                    - pgo V4.12.1.10
   |  1 Jun 2015 | Changed how device choice is handled (bdmDeviceNum)     - pgo V4.11.1.10
   | 15 Mar 2015 | Complete redesign using wxFormBuilder                   - pgo V4.11.1.10
   +=========================================================================================
   \endverbatim
*/
#include "UsbdmDialogue.h"

#include <set>

#include "USBDM_API.h"
#include "UsbdmSystem.h"
#include "NumberTextEditCtrl.h"
#include "SecurityTextEditCtrl.h"
#include "Names.h"

#include <wx/sizer.h>
#include "TimeIntervalValidator.h"
#include "SecurityValidator.h"

#include "FlashProgrammerFactory.h"

using namespace std;

const string UsbdmDialogue::settingsKey("ProgrammerDialogue");
wxProgressDialog *UsbdmDialogue::progressDialogue = NULL;

//===================================================================================

//! Used to control features in dialogue according to target type
const uint32_t UsbdmDialogue::targetPropertyFlags[] = {
/*  0 HCS12     */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|HAS_PROBE_SECURED|HAS_CLK_SW|HAS_GUESS_SPEED,
/*  1 HCS08     */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|HAS_PROBE_SECURED|HAS_CLK_SW|HAS_OPTIONAL_RESET|HAS_TRIM|HAS_MASK_INTERRUPTS,
/*  2 RS08      */  HAS_MASS_ERASE|                    HAS_PROBE_SECURED|HAS_CLK_SW|HAS_OPTIONAL_RESET|HAS_TRIM,
/*  3 CFV1      */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|                  HAS_CLK_SW|HAS_OPTIONAL_RESET|HAS_TRIM|HAS_NVM_EEEPROM,
/*  4 CFVx      */  HAS_USE_PST|   HAS_SELECTIVE_ERASE|HAS_PROBE_SECURED|HAS_SELECT_SPEED,
/*  5 JTAG      */  HAS_NONE,
/*  6 EZFLASH   */  HAS_NONE,
/*  7 MC56F80xx */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|HAS_PROBE_SECURED|HAS_SELECT_SPEED,
/*  8 ARM       */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|                  HAS_SELECT_SPEED|HAS_OPTIONAL_RESET|HAS_VLLS_RESET_CAPTURE|HAS_NVM_EEEPROM|HAS_MASK_INTERRUPTS,
/*  9 ARM_JTAG  */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|                  HAS_SELECT_SPEED|HAS_OPTIONAL_RESET|HAS_VLLS_RESET_CAPTURE|HAS_NVM_EEEPROM|HAS_MASK_INTERRUPTS,
/* 10 ARM_SWD   */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|                  HAS_SELECT_SPEED|HAS_OPTIONAL_RESET|HAS_VLLS_RESET_CAPTURE|HAS_NVM_EEEPROM|HAS_MASK_INTERRUPTS,
/* 11 S12Z      */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE,
};

/*!
 * Get properties of target type
 *
 * @return Bit-mask describing properties
 *
 */
uint32_t UsbdmDialogue::getTargetProperties(TargetType_t targetType) {
   LOGGING_E;
   if ((targetType<0) || (targetType>=(sizeof(targetPropertyFlags)/sizeof(targetPropertyFlags[0])))) {
      return 0;
   }
   return targetPropertyFlags[targetType];
}

//! Maps between a drop-down box 'name' and its value
typedef struct {
   int   value;           //!< Value to use
   const wxString name;   //!< Name to display in DD box
} DropDownType;

//! Mappings for Frequency drop-down box
static const DropDownType CFVx_Speeds[] = {
   {  250, _("250kHz") },
   {  500, _("500kHz") },
   {  750, _("750kHz") },
   { 1000, _("1MHz")   },
   { 1500, _("1.5MHz") },
   { 2000, _("2MHz")   },
   { 3000, _("3MHz")   },
   { 4000, _("4MHz")   },
   { 6000, _("6MHz")   },
   {12000, _("12MHz")  }, // Not supported on JTAG etc
   {  0,   wxEmptyString },
};

char tohex(uint8_t value) {
   const char table[] = "0123456789ABCDEF";
   return table[value&0x0F];
}

/*===================================================================
 *  Obtains the version of the BDM library as a string
 *
 *  @return Version string (reference to static buffer)
 */
const wxString &UsbdmDialogue::bdmGetDllVersion(void) {
   static wxString versionString;

   versionString = wxString(bdmInterface->getDllVersionString().c_str(), wxConvUTF8);

   versionString.Prepend(_("DLL Ver "));

   return versionString; // Software version of USBDM DLL
}

/*===================================================================
 *  Maps a value to a drop-down box index
 *
 *  @param information  Array of data describing the DD box
 *  @param value        Value to locate
 *
 *  @return Drop-down box index, -1 if value not present
 */
static int searchDropDown(const DropDownType information[], int value) {
int sub;

   // Search the list
   for (sub = 0; information[sub].value != 0; sub++)
      if (information[sub].value == value)
         return sub;
   return -1;
}

void UsbdmDialogue::updateFilterDescription() {
   LOGGING_Q;
   if (filterChipIds.empty()) {
      filterByChipIdCheckBoxControl->SetLabel(_("Filter by chip ID (none)"));
      filterByChipIdCheckBoxControl->Enable(false);
      doFilterByChipId = false;
   }
   else {
      // Update displayed Chip IDs
      filterByChipIdCheckBoxControl->Enable(true);
      wxString buff = _("Filter by chip ID (");
      set<uint32_t> recordedSDIDs;
      bool firstElement = true;
      for (map<uint32_t,uint32_t>::const_iterator it = filterChipIds.begin();
            it != filterChipIds.end();
            ++it
            ) {
         uint32_t sdid = it->second;
         if (recordedSDIDs.find(sdid) != recordedSDIDs.end()) {
            continue;
         }
         recordedSDIDs.insert(sdid);
         char sdidBuffer[20];
         sprintf(sdidBuffer, "%04X", sdid);
         if (!firstElement) {
            buff.append(_(","));
         }
         firstElement = false;
         buff.append(wxString(sdidBuffer, wxConvUTF7));
      }
      buff.append(_(")"));
      filterByChipIdCheckBoxControl->SetLabel(buff);
   }
}

//===================================================================================
//===================================================================================
//===================================================================================

UsbdmDialogue::UsbdmDialogue(wxWindow* parent, const wxString& title, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface) :
   UsbdmDialogueSkeleton(parent, wxID_ANY, title),
   bdmInterface(bdmInterface),
   deviceInterface(deviceInterface) {
   LOGGING_E;

   deviceChanged           = true;
   incrementalLoad         = false;
   sound                   = false;
   flashprogrammer         = FlashProgrammerPtr();
   fileLoadTime            = 0;
   lastSecurityOption      = SEC_SMART;
   eeepromSizeChoice       = -1;
   targetProperties        = 0;
   autoFileLoad            = true;
   flexNvmPartitionIndex   = -1;
   bdmDeviceNum            = -1;
   needManualFrequencySet  = false;
   doTrim                  = false;
   fileLoaded              = false;
   doFilterByChipId        = false;
   beep                    = 0;
   bdmCapabilities         = BDM_CAP_NONE;
   customSecurityIndex     = -1;
}

UsbdmDialogue::~UsbdmDialogue() {
   LOGGING_Q;
}

void UsbdmDialogue::addValidators() {
   LOGGING_Q;

   // Note: copies are used so original is bdmInterface!
   wxTextValidator integerValidator(wxFILTER_DIGITS, 0);
   wxTextValidator hexValidator(wxFILTER_INCLUDE_CHAR_LIST, 0);
   hexValidator.SetCharIncludes("0123456789abcdefABCDEF");
   wxTextValidator numericValidator(wxFILTER_NUMERIC, 0);

   connectionTimeoutTextControl->SetValidator(integerValidator);

   trimAddressTextControl->SetValidator(hexValidator);
   trimFrequencyTextControl->SetValidator(numericValidator);
   busFrequencyTextControl->SetValidator(integerValidator);
   gdbServerPortNumberTextControl->SetValidator(integerValidator);

   powerOffDurationTextControl->SetValidator(integerValidator);
   powerOnRecoveryIntervalTextControl->SetValidator(integerValidator);
   resetDurationTextControl->SetValidator(integerValidator);
   resetReleaseIntervalTextControl->SetValidator(integerValidator);
   resetRecoveryIntervalTextControl->SetValidator(integerValidator);
   securityValuesTextControl->SetValidator(SecurityValidator(SecurityInfoPtr()));
}

void UsbdmDialogue::Init() {
   LOGGING;

   connectedBDMs.clear();
   bdmIdentification          = wxEmptyString;
   bdmDeviceNum               = -1;
   deviceChanged              = true;
   doFilterByChipId           = false;
   filterChipIds.clear();
   incrementalLoad            = false;
   autoFileLoad               = false;
   fileLoaded                 = false;
   doTrim                     = false;
   needManualFrequencySet     = false;
   sound                      = false;
   lastFileLoaded             = wxEmptyString;
   bdmCapabilities            = BDM_CAP_NONE;

   flashprogrammer            = FlashProgrammerFactory::createFlashProgrammer(bdmInterface);
   flashImage                 = FlashImageFactory::createFlashImage(bdmInterface->getBdmOptions().targetType);

   beep                       = NULL;
   eeepromSizeChoice          = 0;
   flexNvmPartitionIndex      = 0;

   customSecurityIndex        = 0;
   lastSecurityOption         = SEC_SMART;

   log.print("targetProperties = 0x%X\n", targetProperties);

   populateInterfaceSpeeds();
   populateBDMChoices();
   populateInterfaceSpeeds();
   populateDeviceDropDown();
   populateEraseControl();
   populateSecurityControl();

   dllVersionstaticControl->SetLabel(bdmGetDllVersion());

   updateFilterDescription();
   updateFlashNVM();
   updateSecurity();
}

std::string UsbdmDialogue::update() {
   LOGGING;

   log.print("Device# = %d, BDM = \'%s\'\n", bdmDeviceNum, (const char *)bdmIdentification.ToAscii());
   log.print("CurrentDeviceIndex = %d\n", deviceInterface->getCurrentDeviceIndex());
   log.print("CurrentDevice = %s\n", deviceInterface->getCurrentDevice()->getTargetName().c_str());

   /*
    * ===========================================================
    * Interface
    * ===========================================================
    */
   // BDM related information based on bdmDeviceNum
   if (bdmDeviceNum >= 0) {
      bdmCapabilities = connectedBDMs[bdmDeviceNum].getInfo().capabilities;
      bdmIdentification = wxString::FromUTF8(connectedBDMs[bdmDeviceNum].getDescription().c_str());
      wxString versionString;
      versionString.Printf(_("BDM Firmware Ver %d.%d.%d"),
            (connectedBDMs[bdmDeviceNum].getInfo().BDMsoftwareVersion>>16)&0xFF,
            (connectedBDMs[bdmDeviceNum].getInfo().BDMsoftwareVersion>>8)&0xFF,
            connectedBDMs[bdmDeviceNum].getInfo().BDMsoftwareVersion&0xFF
      );
      firmwareStaticControl->SetLabel(versionString);
      bdmDescriptionStaticControl->SetLabel(bdmIdentification);
      bdmInterface->setBdmSerialNumber(connectedBDMs[bdmDeviceNum].getSerialNumber(), true);
   }
   else {
      bdmCapabilities   = BDM_CAP_NONE;
      bdmIdentification = wxEmptyString;
      firmwareStaticControl->SetLabel(wxEmptyString);
      bdmDescriptionStaticControl->SetLabel(wxEmptyString);
      bdmInterface->setBdmSerialNumber("", false);
   }

   // Target Vdd related
   if (!(bdmCapabilities & BDM_CAP_VDDCONTROL)) {
      // BDM interface doesn't have Vdd control - Vdd control options disabled
      targetVddControl->Enable(false);
      bdmInterface->getBdmOptions().targetVdd          = BDM_TARGET_VDD_OFF;
      bdmInterface->getBdmOptions().cycleVddOnReset    = false;
      bdmInterface->getBdmOptions().leaveTargetPowered = false;
      bdmInterface->getBdmOptions().cycleVddOnConnect  = false;
   }
   else {
      targetVddControl->Enable(true);
   }
   targetVddControl->Select(bdmInterface->getBdmOptions().targetVdd);
   bool checkBoxEnable = (bdmInterface->getBdmOptions().targetVdd != BDM_TARGET_VDD_OFF);
   cycleVddOnResetControl->Enable(checkBoxEnable);
   cycleVddOnConnectionControl->Enable(checkBoxEnable);

   cycleVddOnConnectionControl->SetValue(bdmInterface->getBdmOptions().cycleVddOnConnect);
   cycleVddOnResetControl->SetValue(bdmInterface->getBdmOptions().cycleVddOnReset);
   if ((targetProperties & IS_PROGRAMMER) != 0) {
      log.print("leaveTargetPowered = %d\n", bdmInterface->getBdmOptions().leaveTargetPowered);
      leaveTargetPoweredControl->Enable(checkBoxEnable);
      leaveTargetPoweredControl->SetValue(bdmInterface->getBdmOptions().leaveTargetPowered);
   }
   else {
      bdmInterface->getBdmOptions().leaveTargetPowered = false;
   }
   automaticallyReconnectControl->SetValue(bdmInterface->getBdmOptions().autoReconnect != AUTOCONNECT_NEVER);

   if (targetProperties & HAS_OPTIONAL_RESET) {
      // Reset control present
      if ((bdmCapabilities & BDM_CAP_RST) == 0) {
         // BDM doesn't support reset
         log.print("Disabling reset due to BDM feature missing\n");
         useResetSignalControl->Enable(false);
//         bdmInterface->getBdmOptions().useResetSignal = true;
      }
      else {
         useResetSignalControl->Enable(true);
      }
      useResetSignalControl->SetValue(bdmInterface->getBdmOptions().useResetSignal);
   }
   else {
      // Use reset (may be overridden)
      bdmInterface->getBdmOptions().useResetSignal = true;
   }

   if (targetProperties & HAS_USE_PST) {
      // PST feature utilised
      if (bdmCapabilities & BDM_CAP_PST) {
         // BDM supports PST monitoring
         usePstSignalControl->SetValue(bdmInterface->getBdmOptions().usePSTSignals);
         usePstSignalControl->Enable(true);
      }
      else {
         usePstSignalControl->SetValue(false);
         usePstSignalControl->Enable(false);
         bdmInterface->getBdmOptions().usePSTSignals = false;
      }
   }
   else {
      // PST feature not utilised
      bdmInterface->getBdmOptions().usePSTSignals = false;
   }
   if (targetProperties & HAS_GUESS_SPEED) {
      // Guess speed control is present
      guessTargetSpeedControl->SetValue(bdmInterface->getBdmOptions().guessSpeed);
   }
   else {
      // Control not present and option unused
      bdmInterface->getBdmOptions().guessSpeed = false;
   }
   if (targetProperties & HAS_CLK_SW) {
      // Alternative clock available on this target & present in dialogue
      int index;
      switch (bdmInterface->getBdmOptions().bdmClockSource) {
      default:
      case CS_DEFAULT :      index = 0; break;
      case CS_NORMAL_CLK :   index = 1; break;
      case CS_ALT_CLK :      index = 2; break;
      }
      bdmClockSelectControl->Select(index);
   }
   else {
      // No BDM clock options
      bdmInterface->getBdmOptions().bdmClockSource = CS_DEFAULT;
   }

   if (targetProperties & HAS_SELECT_SPEED) {
      // Clock selection present in dialogue
      int index = searchDropDown(CFVx_Speeds, bdmInterface->getBdmOptions().interfaceFrequency);
      if (index < 0)
         index = 0;
      interfaceSpeedControl->SetSelection(index);
   }

   if (targetProperties & HAS_MASK_INTERRUPTS) {
      // Mask interrupts option
      maskInterruptWhenSteppingControl->SetValue(bdmInterface->getBdmOptions().maskInterrupts);
   }
   else {
      bdmInterface->getBdmOptions().maskInterrupts = false;
   }

   if (targetProperties & IS_GDB_SERVER) {
      connectionTimeoutTextControl->SetDecimalValue(bdmInterface->getConnectionTimeout());
   }

   /*
    * ===========================================================================
    * Target
    * ===========================================================================
    */
   incrementalFileLoadCheckBoxControl->SetValue(incrementalLoad);
   autoFileReloadCheckBoxControl->SetValue(autoFileLoad);

   if (deviceChanged) {
      log.print("Resetting device specific information to defaults\n");
      deviceInterface->getCurrentDevice()->setClockTrimFreq(deviceInterface->getCurrentDevice()->getDefaultClockTrimFreq());
      deviceInterface->getCurrentDevice()->setClockTrimNVAddress(deviceInterface->getCurrentDevice()->getDefaultClockTrimNVAddress());
      populateSecurityControl();
      populateEeepromControl();

      deviceChanged = false;
   }
   bool usingClock = (deviceInterface->getCurrentDevice()->getClockType() != CLKEXT) && (deviceInterface->getCurrentDevice()->getClockType() != CLKINVALID);
   bool trimEnabled = usingClock && doTrim;

   trimFrequencyCheckBoxControl->Enable(usingClock);
   trimFrequencyCheckBoxControl->SetValue(doTrim);

   trimFrequencyStaticControl->Enable(trimEnabled);
   trimFrequencyTextControl->Enable(trimEnabled);
   trimAddressStaticControl->Enable(trimEnabled);
   trimAddressTextControl->Enable(trimEnabled);

   trimFrequencyTextControl->SetDoubleValue(deviceInterface->getCurrentDevice()->getClockTrimFreq()/1000.0);
   trimAddressTextControl->SetHexValue(deviceInterface->getCurrentDevice()->getClockTrimNVAddress());

   log.print("Device security = %s\n", getSecurityName(deviceInterface->getCurrentDevice()->getSecurity()));

   bool hasSecure = (targetProperties&IS_PROGRAMMER);
   if (!hasSecure) {
      // Disallow secure option
      log.print("Disabling securityRadioBoxControl.secure\n");
      if (deviceInterface->getCurrentDevice()->getSecurity() == SEC_SECURED) {
         deviceInterface->getCurrentDevice()->setSecurity(SEC_SMART);
      }
   }

   if (targetProperties & HAS_GUESS_SPEED) {
      busFrequencyTextControl->SetDecimalValue(round(deviceInterface->getCurrentDevice()->getConnectionFreq()/1000));
      busFrequencyTextControl->Enable(needManualFrequencySet);
   }

   bool customSelected = deviceInterface->getCurrentDevice()->getSecurity() == SEC_CUSTOM;
   if (customSelected) {
      securityRadioBoxControl->SetLabel(_("Security - see Advanced tab"));
   }
   else {
      securityRadioBoxControl->SetLabel(_("Security"));
   }
   securityRadioBoxControl->Enable(0, !customSelected);
   securityRadioBoxControl->Enable(1, !customSelected && hasSecure);
   securityRadioBoxControl->Enable(2, !customSelected);
   securityRadioBoxControl->Enable(3, !customSelected);
   switch(deviceInterface->getCurrentDevice()->getSecurity()) {
      case SEC_DEFAULT:   securityRadioBoxControl->SetSelection(0);  break;
      case SEC_SECURED:   securityRadioBoxControl->SetSelection(1);  break;
      case SEC_UNSECURED: securityRadioBoxControl->SetSelection(2);  break;
      case SEC_SMART:     securityRadioBoxControl->SetSelection(3);  break;
      case SEC_CUSTOM:    break;
   }

   if (!eraseChoiceControl->SetStringSelection(wxString(DeviceData::getEraseOptionName(deviceInterface->getCurrentDevice()->getEraseOption()),wxConvUTF7))) {
      // Current erase option not supported - default to 1st item
      eraseChoiceControl->SetSelection(0);
      DeviceData::EraseOptions eraseOption = (DeviceData::EraseOptions)(int)(intptr_t)eraseChoiceControl->GetClientData(0);
      deviceInterface->getCurrentDevice()->setEraseOption(eraseOption);
   }

   enableSoundsCheckBoxControl->SetValue(sound);

   if (targetProperties & HAS_VLLS_RESET_CAPTURE) {
      catchVllsResetControl->SetValue(bdmInterface->isCatchVLLSx());
   }
   if (targetProperties & HAS_MASK_INTERRUPTS) {
      maskInterruptWhenSteppingControl->SetValue(bdmInterface->isMaskISR());
   }
   if (targetProperties & IS_GDB_SERVER) {
      gdbServerPortNumberTextControl->SetDecimalValue(bdmInterface->getGdbServerPort());
      gdbTtyPortNumberTextControl->SetDecimalValue(bdmInterface->getGdbTtyPort());
   }

   bool enableProgramming = ((deviceInterface->getCurrentDeviceIndex() >= 0) &&
         (fileLoaded || (doTrim && (deviceInterface->getCurrentDevice()->getEraseOption() != DeviceData::eraseMass))));
   programFlashButtonControl->Enable(enableProgramming);
   verifyFlashButtonControl->Enable(enableProgramming);
   loadAndGoButtonControl->Enable(enableProgramming);

   /*
    * ===========================================================================
    * Advanced
    * ===========================================================================
    */
   updateFlashNVM();
   updateSecurity();

   powerOffDurationTextControl->SetDecimalValue(bdmInterface->getBdmOptions().powerOffDuration);
   powerOnRecoveryIntervalTextControl->SetDecimalValue(bdmInterface->getBdmOptions().powerOnRecoveryInterval);
   resetDurationTextControl->SetDecimalValue(bdmInterface->getBdmOptions().resetDuration);
   resetReleaseIntervalTextControl->SetDecimalValue(bdmInterface->getBdmOptions().resetReleaseInterval);
   resetRecoveryIntervalTextControl->SetDecimalValue(bdmInterface->getBdmOptions().resetRecoveryInterval);

//#ifdef LOG
//   StatusText->SetLabel("No status");
//#else
//   StatusText->SetLabel(wxEmptyString);
//#endif

   return "";
}

void UsbdmDialogue::populateEraseControl() {
   eraseChoiceControl->Clear();
   eraseChoiceControl->Append(wxString(DeviceData::getEraseOptionName(DeviceData::eraseNone),wxConvUTF7),      (void*)DeviceData::eraseNone);
   if (targetProperties&HAS_SELECTIVE_ERASE) {
      eraseChoiceControl->Append(wxString(DeviceData::getEraseOptionName(DeviceData::eraseSelective),wxConvUTF7), (void*)DeviceData::eraseSelective);
      eraseChoiceControl->Append(wxString(DeviceData::getEraseOptionName(DeviceData::eraseAll),wxConvUTF7),       (void*)DeviceData::eraseAll);
   }
   if (targetProperties&HAS_MASS_ERASE) {
      eraseChoiceControl->Append(wxString(DeviceData::getEraseOptionName(DeviceData::eraseMass),wxConvUTF7),      (void*)DeviceData::eraseMass);
   }
}

/*! Load settings from a settings object
 *
 *  @param appSettings - Object containing settings
 */
void UsbdmDialogue::loadSettings(const AppSettings &appSettings) {
   LOGGING;

   bdmInterface->loadSettings(appSettings);
   deviceInterface->loadSettings(appSettings);

   autoFileLoad        = appSettings.getValue(settingsKey+".autoFileLoad", 0) != 0;
   sound               = appSettings.getValue(settingsKey+".playSounds", 0);

   doTrim = deviceInterface->getCurrentDevice()->getClockTrimFreq() != 0;

   currentDirectory = appSettings.getValue(settingsKey+".currentDirectory", "");
}

/*! Load settings from a settings object
 *
 *  @param appSettings - Object containing settings
 */
void UsbdmDialogue::saveSettings(AppSettings &appSettings) {
   LOGGING;

   bdmInterface->saveSettings(appSettings);
   deviceInterface->saveSettings(appSettings);

   appSettings.addValue(settingsKey+".autoFileLoad",     autoFileLoad?1:0);
   appSettings.addValue(settingsKey+".playSounds",       (int)sound);
   appSettings.addValue(settingsKey+".currentDirectory", currentDirectory);
}

/*!
 * Hide unused controls
 *
 * @param flags Flags controlling which controls are present
 *
 */
void UsbdmDialogue::hideUnusedControls() {
   LOGGING_E;

   targetProperties = getTargetProperties(bdmInterface->getBdmOptions().targetType);

   addValidators();

   // Interface
   if ((targetProperties & HAS_OPTIONAL_RESET) == 0) {
      useResetSignalControl->Show(false);
   }
   if ((targetProperties & HAS_USE_PST) == 0) {
      usePstSignalControl->Show(false);
   }
   if ((targetProperties & HAS_GUESS_SPEED) == 0) {
      guessTargetSpeedControl->Show(false);
   }
   if ((targetProperties & HAS_CLK_SW) == 0) {
      bdmClockSelectControl->Show(false);
   }
   if ((targetProperties & HAS_MASK_INTERRUPTS) == 0) {
      maskInterruptWhenSteppingControl->Show(false);
   }
   if ((targetProperties & HAS_VLLS_RESET_CAPTURE) == 0) {
      catchVllsResetControl->Show(false);
   }
   if ((targetProperties & (IS_PROGRAMMER|IS_GDI_DIALOGUE)) == 0) {
      leaveTargetPoweredControl->Show(false);
   }
   if ((targetProperties & IS_GDB_SERVER) == 0) {
      connectionTimeoutTextControl->Enable(false);
      wxStaticBoxSizer *sz = (wxStaticBoxSizer*)connectionTimeoutTextControl->GetContainingSizer();
      sz->Show(false);
   }
   if ((targetProperties & HAS_SELECT_SPEED) == 0) {
      interfaceSpeedControl->Enable(false);
      connectionSpeedStaticTextWarning->Show(false);
      wxStaticBoxSizer *sz = (wxStaticBoxSizer*)interfaceSpeedControl->GetContainingSizer();
      sz->Show(false);
   }
   // Target
   if ((targetProperties & HAS_TRIM) == 0) {
      trimAddressStaticControl->Enable(false);
      trimAddressTextControl->Enable(false);
      trimAddressStaticControlHex->Enable(false);

      trimFrequencyStaticControl->Enable(false);
      trimFrequencyTextControl->Enable(false);
      trimFrequencyStaticControlkHz->Enable(false);

      trimValueStaticControl->Enable(false);
      wxStaticBoxSizer *sz = (wxStaticBoxSizer*)trimValueStaticControl->GetContainingSizer();
      sz->Show(false);
   }
   if ((targetProperties & HAS_GUESS_SPEED) == 0) {
      busFrequencyStaticControl->Enable(false);
      busFrequencyTextControl->Enable(false);
      busFrequencyStaticControlkHz->Enable(false);
      wxStaticBoxSizer *sz = (wxStaticBoxSizer*)busFrequencyStaticControl->GetContainingSizer();
      sz->Show(false);
   }
   if ((targetProperties & HAS_MASS_ERASE) == 0) {
      eraseNowButtonControl->Enable(false);
      eraseNowButtonControl->Show(false);
   }
   if ((targetProperties & HAS_MASS_ERASE) != 0) {
      unlockButtonControl->Enable(false);
      unlockButtonControl->Show(false);
   }
   if ((targetProperties & HAS_NVM_EEEPROM) == 0) {
      eeepromSizeChoiceControl->Enable(false);
      flexNvmPartitionChoiceControl->Enable(false);
      wxStaticBoxSizer *sz = (wxStaticBoxSizer*)flexNvmDescriptionStaticControl->GetContainingSizer();
      sz->Show(false);
   }
   if ((targetProperties & IS_PROGRAMMER) == 0) {
      // Remove secure option
      securityRadioBoxControl->Enable(false, 1);

      // Remove Close button
      closeButton->Enable(false);
      closeButton->Show(false);

      // Remove custom security options
      customSecurityCheckbox->Enable(false);
      securityMemoryRegionChoice->Enable(false);
      resetCustomButtonControl->Enable(false);
      securityValuesTextControl->Enable(false);
      securityDescriptionStaticText->Enable(false);
      wxStaticBoxSizer *sz = (wxStaticBoxSizer*)securityValuesTextControl->GetContainingSizer();
      sz->Show(false);

      // Remove Load file option
      loadFileButtonControl->Enable(false);
      incrementalFileLoadCheckBoxControl->Enable(false);
      autoFileReloadCheckBoxControl->Enable(false);
      loadedFilenameStaticControl->Enable(false);
      sz = (wxStaticBoxSizer*)loadedFilenameStaticControl->GetContainingSizer();
      sz->Show(false);

      // Remove Device operation buttons
      programFlashButtonControl->Enable(false);
      verifyFlashButtonControl->Enable(false);
      loadAndGoButtonControl->Enable(false);
      sz = (wxStaticBoxSizer*)loadAndGoButtonControl->GetContainingSizer();
      sz->Show(false);
   }
   if ((targetProperties & IS_GDB_SERVER) == 0) {
      gdbServerPortNumberStaticControl->Enable(false);
      gdbServerPortNumberTextControl->Enable(false);
      wxStaticBoxSizer *sz = (wxStaticBoxSizer*)gdbServerPortNumberTextControl->GetContainingSizer();
      sz->Show(false);

      keepChangesButton->Enable(false);
      keepChangesButton->Show(false);
      discardChangesButton->Enable(false);
      discardChangesButton->Show(false);
   }
   StatusText->Show(false);

   // Temporarily hide so dialogue is smaller
   securityDescriptionStaticText->Show(false);
   fInterfacePanel->Layout();
   fTargetPanel->Layout();
   fAdvancedPanel->Layout();
}

//===================================================================================

void UsbdmDialogue::populateInterfaceSpeeds() {

   if (interfaceSpeedControl->IsEnabled()) {
      int maxSpeed;
      switch(bdmInterface->getBdmOptions().targetType) {
      case T_ARM_JTAG : maxSpeed =  6000; break;
      case T_ARM_SWD  : maxSpeed = 12000; break;
      case T_CFVx     : maxSpeed = 12000; break;
      default         : maxSpeed = 12000; break;
      }
      wxArrayString connectionSpeedControlStrings;
      for (int sub=0; CFVx_Speeds[sub].value != 0; sub++) {
         if (CFVx_Speeds[sub].value > maxSpeed) {
            continue;
         }
         connectionSpeedControlStrings.Add(CFVx_Speeds[sub].name);
      }
      interfaceSpeedControl->Set(connectionSpeedControlStrings);
      if (bdmInterface->getBdmOptions().targetType == T_CFVx) {
         connectionSpeedStaticTextWarning->SetLabel("Speed < Target Clock Frequency/5");
      }
      else {
         connectionSpeedStaticTextWarning->Show(false);
      }
      interfaceSpeedControl->Select(0);
   }
}

static struct {
   const wxString name;
   int            length;
} rootNames[] = {{_("MC9S08"),   sizeof("MC9S08")-1 },
                 {_("MC9S12"),   sizeof("MC9S12")-1 },
                 {_("S9S08"),    sizeof("S9S08")-1  },
                 {wxEmptyString, 0},
                };

//! Converts a device name to the form used in the device list combobox
//!
//! @param targetName - name of device e.g. "MC9S08AW16"
//!
//! @return ptr to static buffer containing the converted name e.g. "AW-MC9S08AW16"
//!
const wxString UsbdmDialogue::makeDeviceName(const wxString& targetName) {
int nameIndex;
static wxString buffer;

   if (bdmInterface->getBdmOptions().targetType != T_HCS08) {
      return targetName;
   }
   for (nameIndex = 0; rootNames[nameIndex].length != 0; nameIndex++) {
      if (targetName.compare(0,rootNames[nameIndex].length,rootNames[nameIndex].name) == 0) {
         buffer = targetName[rootNames[nameIndex].length];
         if (isalpha((int)targetName[rootNames[nameIndex].length+1]))
            buffer += targetName[rootNames[nameIndex].length+1];
         if (isalpha((int)targetName[rootNames[nameIndex].length+2]))
            buffer += targetName[rootNames[nameIndex].length+2];
         buffer += '-';
         buffer += targetName;
//         log.print("makeDeviceName(%s), root = %s => %s\n", (const char *)targetName.ToAscii(),
//                (const char *)rootNames[nameIndex].name.ToAscii(), (const char *)buffer.ToAscii());
         return buffer;
      }
   }
//   log.print("makeDeviceName(%s) => %s\n", targetName - unchanged);
   return targetName; // Return unchanged
}

//! Changes selected device
//!
//! @param newDeviceIndex - index of device in deviceDatabase to select (or -1 for default)
//!
void UsbdmDialogue::setDeviceIndex(int newDeviceIndex) {
   LOGGING;

   log.print("newDeviceIndex = %d\n", newDeviceIndex);
   log.print("Trim Freq (before change)= %f kHz\n", deviceInterface->getCurrentDevice()->getClockTrimFreq()/1000.0);

   // Save non-device-specific settings.
   DeviceData savedDevice = *deviceInterface->getCurrentDevice();

   int currentDeviceIndex = deviceInterface->getCurrentDeviceIndex();

   // Set new device
   deviceInterface->setCurrentDeviceByIndex(newDeviceIndex);

   log.print("Device = \n%s\n", (const char *)deviceInterface->getCurrentDevice()->toString().c_str());

   string deviceName = deviceInterface->getCurrentDevice()->getTargetName();
   log.print("Device changed to \'%s\'\n", (const char *)deviceName.c_str());

   if (!deviceTypeChoiceControl->SetStringSelection(makeDeviceName(deviceName))) {
      // Device not found - change to 1st device in combo
      deviceTypeChoiceControl->Select(0);
      deviceName = deviceTypeChoiceControl->GetLabel();
      deviceInterface->setCurrentDeviceByName(deviceName);
      log.print("Device not found (%s), changing to dev #0\n", (const char *)deviceName.c_str());
   }

   newDeviceIndex = deviceInterface->getCurrentDeviceIndex();

   deviceChanged = newDeviceIndex != currentDeviceIndex;

   log.print("Trim Freq (after change)= %f kHz\n", deviceInterface->getCurrentDevice()->getClockTrimFreq()/1000.0);

   // Restore non-device-specific settings.
   deviceInterface->getCurrentDevice()->setSecurity(savedDevice.getSecurity());
   deviceInterface->getCurrentDevice()->setEraseOption(savedDevice.getEraseOption());
   deviceInterface->getCurrentDevice()->setConnectionFreq(savedDevice.getConnectionFreq());
   if (!doTrim) {
      deviceInterface->getCurrentDevice()->setClockTrimFreq(0);
   }
}

//=======================================================================

//===================================================================
/*
 *  Set the internal dialogue values.
 *
 */
bool UsbdmDialogue::setDialogueValuesToDefault() {
   LOGGING;

   Init();
   TransferDataToWindow();
   return true;
}

//===================================================================
/*!
 * Update the dialogue from internal state
 */
bool UsbdmDialogue::TransferDataToWindow() {
   assert(sizeof(int) <= sizeof(intptr_t));
   LOGGING;
   /*
    * ===============================================================================
    * Interface
    * ===============================================================================
    */
   populateBDMChoices();

   bdmIdentification = wxString(bdmInterface->getBdmSerialNumber().c_str(), wxConvUTF8);
   log.print("Initial BDM = \'%s\'\n", (const char *)bdmIdentification.ToAscii());
   // Try to set choice to match BDM identification string
   if (!bdmSelectChoiceControl->SetStringSelection(bdmIdentification)) {
      log.warning("Can't select previous BDM = %s\n", (const char *)bdmIdentification.ToAscii());
      // Failed - select first BDM
      bdmSelectChoiceControl->Select(0);
   }
   int choice = bdmSelectChoiceControl->GetSelection();
   bdmDeviceNum = (int)(intptr_t)bdmSelectChoiceControl->GetClientData(choice);

   /*
    * ===============================================================================
    * Target
    * ===============================================================================
    */
   // Set currently selected device
   wxString deviceName = makeDeviceName(wxString(deviceInterface->getCurrentDevice()->getTargetName().c_str(), wxConvUTF8));
   log.print("Setting device \'%s\'\n", (const char *)deviceName.c_str());

   int deviceIndex = deviceInterface->getCurrentDeviceIndex();
   setDeviceIndex(deviceIndex);
   deviceChanged = true;

   update();

   return true;
}

bool UsbdmDialogue::TransferDataFromWindow() {
   LOGGING;

   if ((targetProperties & IS_PROGRAMMER) || (deviceInterface->getCurrentDevice()->getSecurity() == SEC_CUSTOM)) {
      log.print("SEC_CUSTOM\n");
      // Transfer custom security setting to device
      for(unsigned index=0; index<securityMemoryRegionChoice->GetCount(); index++) {
         int memoryIndex = (int)(intptr_t)securityMemoryRegionChoice->GetClientData(index);
         log.print("memoryIndex = %d\n", memoryIndex);
         if (memoryIndex < 0) {
            // Not a valid region
            continue;
         }
         MemoryRegionPtr memoryRegionPtr = deviceInterface->getCurrentDevice()->getMemoryRegion(memoryIndex);
         if (memoryRegionPtr == NULL) {
            // No matching memory region!
            throw MyException("UsbdmDialogue::TransferDataFromWindow() - No matching memory region");
         }
         SecurityEntryPtr securityEntry = memoryRegionPtr->getSecurityEntry();
         if (securityEntry == NULL) {
            // Memory region has no security region - skip
            continue;
         }
         log.print("Copying Custom[%d] to Device memoryIndex[%d], %s: %s\n", index, memoryIndex, memoryRegionPtr->getMemoryTypeName(), (const char *)customSecurityInfo[index].ptr->toString().c_str());
         securityEntry->setCustomSecureInformation(customSecurityInfo[index].ptr);
      }
   }
   return true;
}

/*
 * Update the list of connected BDMs (connectedBDMs)
 */
void UsbdmDialogue::findBDMs(void) {
   LOGGING;

   bdmDeviceNum = 0;
   // Enumerate all attached BDMs
   bdmInterface->findBDMs(connectedBDMs);
   if (connectedBDMs.empty()) {
      bdmDeviceNum = -1;
      bdmIdentification = wxEmptyString;
      log.print(" - no BDMs found\n");
   }
}

/*!
 *  Populate the BDM Choice box
 */
void UsbdmDialogue::populateBDMChoices(void) {
   LOGGING;

   findBDMs();

   unsigned deviceCount = connectedBDMs.size();
   bdmSelectChoiceControl->Clear();

//   log.print(" bdmIdentification = \'%s\'\n", (const char *)bdmIdentification.ToAscii());
   if (deviceCount==0) {
      // No devices found
      bdmSelectChoiceControl->Append(_("[No devices Found]"));
      bdmSelectChoiceControl->Select(0);
      bdmSelectChoiceControl->SetClientData(0, (void*)-2);
      bdmSelectChoiceControl->Enable(false);
      bdmDeviceNum = -1;
      bdmIdentification = wxEmptyString;
      log.print(" - no devices\n");
      return;
   }
   // Add device names to choice box, client data is device number from usb scan
   vector<BdmInformation>::iterator it;
   for ( it=connectedBDMs.begin(); it<connectedBDMs.end(); it++ ) {
      int index = bdmSelectChoiceControl->Append(wxString::FromUTF8(it->getSerialNumber().c_str()));
//      bdmSelectChoiceControl->SetClientData(index, (void*)(intptr_t)it->getDeviceNumber());
      bdmSelectChoiceControl->SetClientData(index, (void*)(it-connectedBDMs.begin()));
   }
   // Try to select previous device
   if (bdmIdentification.empty() || !bdmSelectChoiceControl->SetStringSelection(bdmIdentification)) {
      // Select 1st device by default
      bdmSelectChoiceControl->Select(0);
   }
   bdmDeviceNum      = (int)(intptr_t)bdmSelectChoiceControl->GetClientData();
   bdmIdentification = bdmSelectChoiceControl->GetStringSelection();

   bdmSelectChoiceControl->Enable(deviceCount>1);
   log.print(" - %d BDMs added.\n", deviceCount);
}

//! Populates the device drop-down box with known devices
//!
//! @note: the list may be filtered by filterChipIds
//!
void UsbdmDialogue::populateDeviceDropDown() {
   LOGGING;

   // Clear device list
   deviceTypeChoiceControl->Clear();

   // Populate the list with filtered items
   int  firstAddedDeviceIndex      = -1;
   bool previousDeviceStillInList  = false;

   int deviceIndex;
   vector<DeviceDataPtr>::const_iterator it;
   for ( it=deviceInterface->getDeviceDatabase()->begin(), deviceIndex=0;
         it < deviceInterface->getDeviceDatabase()->end(); it++, deviceIndex++ ) {
      if (((*it)->getTargetName().length() != 0) &&
            !((*it)->isHidden()) &&
            (!doFilterByChipId || (*it)->isThisDevice(filterChipIds, false))) {
         deviceTypeChoiceControl->Append(makeDeviceName(wxString((*it)->getTargetName().c_str(), wxConvUTF8)), (void *)(intptr_t) deviceIndex);
//         log.print(" - Add device %s @%d, devIndex=%d\n", (*it)->getTargetName().c_str(), controlIndex);
         if (firstAddedDeviceIndex == -1) {
            firstAddedDeviceIndex = deviceIndex;
         }
         if (deviceIndex == deviceInterface->getCurrentDeviceIndex()) {
            // Record the current selected entry in the control
            previousDeviceStillInList = true;
         }
      }
   }
   if (firstAddedDeviceIndex<0) {
      // No devices added
      log.print("No devices\n");
      setDeviceIndex(-1);
      deviceTypeChoiceControl->Append(_("[No matching device]"));
      deviceTypeChoiceControl->SetClientData(0, (void *) -22);
      deviceTypeChoiceControl->SetSelection(0);
      deviceTypeChoiceControl->Enable(false);
   }
   else if (previousDeviceStillInList) {
      // Select originally selected device in re-populated list control if it is still present
      log.print("Selecting previous device #%d\n", deviceInterface->getCurrentDeviceIndex());
      setDeviceIndex(deviceInterface->getCurrentDeviceIndex());
      deviceTypeChoiceControl->Enable(true);
   }
   else {
      // Select 1st added device in list control
      log.print("Selecting 1st added device (firstAddedDeviceIndex = %d)\n", firstAddedDeviceIndex);
      setDeviceIndex(firstAddedDeviceIndex);
      deviceTypeChoiceControl->Enable(true);
   }
}

//! Special handling for HCS12
//!
USBDM_ErrorCode UsbdmDialogue::hcs12Check(void) {
   LOGGING;

   USBDM_ErrorCode rc;
   USBDM_ErrorCode rc_flash;
   unsigned long connectionFrequency;
   USBDMStatus_t usbdmStatus;

   // Assume we can auto-detect connection speed
   needManualFrequencySet = false;
   deviceInterface->getCurrentDevice()->setConnectionFreq(0);
   busFrequencyTextControl->Enable(false);

   flashprogrammer->setDeviceData(deviceInterface->getCurrentDevice());
   rc_flash = flashprogrammer->resetAndConnectTarget();
   if ((rc_flash != PROGRAMMING_RC_OK) && (rc_flash != PROGRAMMING_RC_ERROR_SECURED)) {
      return BDM_RC_FAIL;
   }
   // Get connection speed
   rc = bdmInterface->getSpeedHz(&connectionFrequency);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   rc = bdmInterface->getBDMStatus(&usbdmStatus);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   // Round to 10's kHz
   connectionFrequency = 10000*round(connectionFrequency/10000.0);
   deviceInterface->getCurrentDevice()->setConnectionFreq(connectionFrequency);

   if (flashprogrammer->checkTargetUnSecured() == PROGRAMMING_RC_ERROR_SECURED) {
      if (usbdmStatus.connection_state == SPEED_SYNC) {
         // Assume device secure but connection speed has been determined correctly
         rc = BDM_RC_OK;
      }
      else if (usbdmStatus.connection_state == SPEED_GUESSED) {
         // Target speed has been guessed and may be inaccurate.
         // Device is secured so target timing code cannot be used (later).
         // Warn the user to manually set the speed to allow unsecure
         log.print("Guessed connection speed (Hz) = %ld\n", connectionFrequency);
         needManualFrequencySet = true;
         update();
         wxMessageBox(
               _("The device appears to be secured and does not support SYNC.\n"
                 "The currently set bus frequency is an approximation and\n"
                 "may not be sufficiently accurate for unsecuring the target.\n\n"
                 "Please manually set the bus frequency before programming."),
               _("Programming Error"),
               wxOK|wxICON_INFORMATION|wxSTAY_ON_TOP|wxCENTER,
               this);
      rc = BDM_RC_OK;
      }
   }
   return rc;
}

extern "C"
USBDM_ErrorCode UsbdmDialogue::progressCallBack(USBDM_ErrorCode status, int percent, const char *message) {
   if (progressDialogue == NULL)
      return status;
   if (percent >= 100) {
      percent = 99;
   }
   if (message != NULL) {
      wxString msg(message, wxConvUTF8);
      if (percent < 0) {
         progressDialogue->Pulse(msg);
      }
      else {
         progressDialogue->Update(percent, msg);
      }
   }
   else {
      if (percent < 0) {
         progressDialogue->Pulse();
      }
      else {
         progressDialogue->Update(percent);
      }
   }
   return status;
}

//! Auto detect connected device and connection speed
//!
//! @return various error codes
//!
//! @note Any errors are flagged to the user
//!
USBDM_ErrorCode UsbdmDialogue::autoDetectTargetDevice(void) {
uint32_t targetChipId;
LOGGING;

   if (flashprogrammer == NULL) {
      flashprogrammer = FlashProgrammerFactory::createFlashProgrammer(bdmInterface);
   }
   filterChipIds.clear();
   log.print("BDM Options =>\n");
   printBdmOptions(&bdmInterface->getBdmOptions());

   USBDM_ErrorCode flashRc = bdmInterface->initBdm();
   if (flashRc != BDM_RC_OK) {
      return flashRc;
   }
   if (bdmInterface->getBdmOptions().targetType == T_HCS12) {
      // HCS12 has problems if the target is secured and doesn't support SYNC
      flashRc = hcs12Check();
      if (flashRc != BDM_RC_OK) {
         wxMessageBox(
               _("Failed to connect to target\n\n"
                     "Reason: ") +
                     wxString(bdmInterface->getErrorString(flashRc), wxConvUTF8),
                     _("Programming Error"),
                     wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                     this);
         bdmInterface->closeBdm();
         log.print("Failed to connect to target\n");
         return PROGRAMMING_RC_ERROR_BDM_CONNECT;
      }
   }
#if defined(TARGET) && (TARGET == MC56F80xx)
   else if (targetType == T_MC56F80xx) {
      if (DSC_Initialise() != BDM_RC_OK) {
         bdmInterface->closeBdm();
         return PROGRAMMING_RC_ERROR_BDM_CONNECT;
      }
   }
#endif
   else if (bdmInterface->getBdmOptions().targetType == T_ARM) {
      flashRc = bdmInterface->targetConnectWithRetry((BdmInterface::RetryMode)(BdmInterface::retryByReset|BdmInterface::retryNotPartial));
      if ((flashRc != BDM_RC_OK) && (flashRc != BDM_RC_SECURED)) {
         bdmInterface->closeBdm();
         return flashRc;
      }
   }
   else {
      if (bdmInterface->targetConnectWithRetry((BdmInterface::RetryMode)(BdmInterface::retryAlways|BdmInterface::retryByReset)) != BDM_RC_OK) {
         bdmInterface->closeBdm();
         log.print("Failed to connect\n");
         return PROGRAMMING_RC_ERROR_BDM_CONNECT;
      }
      log.print("Connected...\n");
   }
//   USBDM_TargetHalt();

   if ((targetProperties&HAS_PROBE_SECURED) == 0) {
      // Can't determine the device type of a secured device.
      // Check if secured and prompt user to mass erase

      // Set default device
      flashRc = flashprogrammer->setDeviceData(deviceInterface->getDeviceDatabase()->getDefaultDevice());
      if (flashRc != PROGRAMMING_RC_OK) {
         bdmInterface->closeBdm();
         log.print("setDeviceData() failed\n");
         return flashRc;
      }
      // Check if unsecured
      log.print("setDeviceData() doing checkTargetUnSecured()\n");
      flashRc = flashprogrammer->checkTargetUnSecured();
      log.print("setDeviceData() done checkTargetUnSecured(), rc = %d\n", flashRc);
      if (flashRc == PROGRAMMING_RC_ERROR_SECURED) {
         int getYesNo = wxMessageBox(_("It is not possible to determine the device type \n"
                                       "as it appears to be secured.\n\n"
                                       "It is necessary to unsecure the device to allow the Chip ID\n"
                                       "to be read and the device re-programmed.\n"
                                       "Unsecuring the device will entirely erase its contents.\n\n"
                                       "Unsecure & entirely erase the device ?"),
                                     _("Device is Secured"),
                                     wxYES_NO|wxNO_DEFAULT|wxICON_EXCLAMATION|wxSTAY_ON_TOP|wxCENTER,
                                     this);
         if (getYesNo != wxYES) {
            bdmInterface->closeBdm();
            return flashRc;
         }
         // Do mass erase
         flashRc = flashprogrammer->massEraseTarget();
         if (flashRc != PROGRAMMING_RC_OK) {
            wxMessageBox(_("Unsecuring the device failed.\n"
                           "Reason: ") +
                           wxString(bdmInterface->getErrorString(flashRc), wxConvUTF8),
                         _("Erasing Failed"),
                         wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                         this);
            bdmInterface->closeBdm();
            return flashRc;
         }
      }
   }

   // To reduce time keep a history of probed locations for re-use
   double totalDeviceCount = deviceInterface->getDeviceDatabase()->getNumDevice();
   int deviceCount = 0;
   wxProgressDialog pd(_("Accessing Target"),
                       _("Probing device..."),
                       totalDeviceCount,
                       this,
                       wxPD_APP_MODAL|wxPD_ELAPSED_TIME|wxPD_CAN_ABORT
                       );

   USBDM_ErrorCode lastRc = PROGRAMMING_RC_OK;
   vector<DeviceDataPtr>::const_iterator deviceIterator;

   set<uint32_t> probedLocations;
   bool successfullyProbedALocation = false;
   bool doFirstInit = true;
   for ( deviceIterator = deviceInterface->getDeviceDatabase()->begin();
         deviceIterator < deviceInterface->getDeviceDatabase()->end();
         deviceIterator++, deviceCount++ ) {
      if (!pd.Update(deviceCount)) {
         break;
      }
      log.print("Considering %s (A=0x%08X, M=0x%08X, V=0x%08X)",
                     (*deviceIterator)->getTargetName().c_str(),
                     (*deviceIterator)->getSDIDAddress(), (*deviceIterator)->getSDID(0).mask, (*deviceIterator)->getSDID(0).value);
      DeviceDataPtr probedDevice = *deviceIterator;

      if (probedDevice->getSDID().mask == 0x0000) {
         log.printq("- Discarding wild-card device\n");
         continue; // Skip 'match any probedDevice'
      }
      // Get location to probe
      uint32_t sdidAddress = probedDevice->getSDIDAddress();

      // Check if not already probed location
      if (probedLocations.find(sdidAddress) == probedLocations.end()) {
         // New location
         log.printq("- New location\n");

         // Record probe
         probedLocations.insert(sdidAddress);

         USBDM_ErrorCode probeRc = flashprogrammer->setDeviceData(probedDevice);
         if (probeRc == PROGRAMMING_RC_OK) {
            probeRc = flashprogrammer->readTargetChipId(&targetChipId, doFirstInit);
            doFirstInit = false;
         }
         if (probeRc != PROGRAMMING_RC_OK) {
            // Failed probe - ignore errors as may be accessing illegal memory
            lastRc = probeRc;
            log.print( "- Failed probe, Reason: %s\n", bdmInterface->getErrorString(probeRc));
            // Add dummy entry to prevent re-probing
            continue;
         }
         // Record successful probe address & value
         log.print( "Successful probe, adding probe entry, (A=0x%X,ID=0x%X)\n", sdidAddress, targetChipId);
         successfullyProbedALocation = true;
         filterChipIds.insert (pair<uint32_t,uint32_t>(sdidAddress, targetChipId));
      }
      else {
         log.printq("- Already probed location\n");
      }
   }
   if (deviceCount != totalDeviceCount) {
      // Just in case - to close dialogue
      pd.Update(totalDeviceCount);
   }
   bdmInterface->closeBdm();

   if (!successfullyProbedALocation) {
      // No successful probes
      log.print("Failed to probe target\n");
      flashRc = lastRc;
      if (flashRc == PROGRAMMING_RC_OK) {
         // Change code to default Fail
         flashRc = BDM_RC_FAIL;
      }
      wxMessageBox(
            _("Failed to probe target\n\n"
            "Reason: ") +
            wxString(bdmInterface->getErrorString(flashRc), wxConvUTF8),
            _("Detection error"),
            wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
            this);
   }
   else if (filterChipIds.empty()) {
      // Successful probes but no matching devices
      log.print("Failed to read any matching chip IDs from target\n");
      wxMessageBox(
            _("No matching chip ID"),
            _("Detection error"),
            wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
            this);
      flashRc = BDM_RC_FAIL;
   }
   else {
      log.print("Found %lu chips\n", (unsigned long)filterChipIds.size());
   }
   // Returns OK as errors at end have already been reported
   return BDM_RC_OK;
}

USBDM_ErrorCode UsbdmDialogue::loadHexFile( wxString hexFilename, bool clearBuffer ) {
   LOGGING_Q;
   USBDM_ErrorCode rc;

   log.print("(%s)\n", (const char *)hexFilename.ToAscii());
   loadedFilenameStaticControl->SetLabel(_("Loading File"));
   rc = flashImage->loadFile((const char*)hexFilename.mb_str(wxConvUTF8), clearBuffer);
   if (rc != BDM_RC_OK) {
      wxMessageBox(_("Failed to read S-File.\n") +
                     hexFilename +
                   _("\nReason: ") +
                     wxString(bdmInterface->getErrorString(rc), wxConvUTF8),
                   _("S-File load error - buffer cleared!"),
                   wxOK|wxSTAY_ON_TOP|wxCENTER,
                   this);
      // Buffer image may be corrupted
      fileLoaded = FALSE;
      flashImage->clear();
      loadedFilenameStaticControl->SetLabel(_("No file loaded"));
      return PROGRAMMING_RC_ERROR_FILE_OPEN_FAIL;
   }
   else {
      fileLoaded = TRUE;
      lastFileLoaded = hexFilename;
      fileLoadTime = wxFileModificationTime(hexFilename);
      loadedFilenameStaticControl->SetLabel(wxFileNameFromPath(hexFilename));
   }
   flashImage->printMemoryMap();
   return PROGRAMMING_RC_OK;
}

//! Check if last loaded file has changed on disk.\n
//! If so then prompt to reload.
//!
USBDM_ErrorCode UsbdmDialogue::checkFileChange(void) {
   LOGGING;
   if (!fileLoaded) {
      log.print("No file loaded\n");
      return PROGRAMMING_RC_OK;
   }
   time_t currentFileTime;
   if (!wxFileExists(lastFileLoaded)) {
      log.print("File no longer exists\n");
      currentFileTime = -1;
   }
   else {
      currentFileTime = wxFileModificationTime(lastFileLoaded);
   }
   if ((currentFileTime != -1) && (currentFileTime == fileLoadTime)) {
      // Up-to-date - Continue operation without re-load
      log.print("Loaded file is up-to-date\n");
      return PROGRAMMING_RC_OK;
   }
   if (autoFileLoad) {
      if (currentFileTime == -1) {
         // Original file no longer exists - alert user
         int getYesNo = wxMessageBox(_("Unable to auto-reload file as it is no longer accessible.\n\n"
                                       "Continue operation?"),
                                     _("Cannot Load File"),
                                     wxYES_NO|wxICON_QUESTION|wxYES_DEFAULT,
                                     this
                                    );
         if (getYesNo == wxYES) {
            log.print("Continuing without re-load\n");
            // Continue without re-load
            return PROGRAMMING_RC_OK;
         }
         else {
            // Abort programming/verifying
            log.print("Aborting operation\n");
            return PROGRAMMING_RC_ERROR_FILE_OPEN_FAIL;
         }
      }
      // Auto-reload changed file
      log.print("Auto-reloading file\n");
      return loadHexFile(lastFileLoaded, !incrementalLoad);
   }
   else { // !autoFileLoad
      if (currentFileTime == -1) {
         // Original file no longer exists - Ignore & continue without re-load
         return PROGRAMMING_RC_OK;
      }
      // File changed - alert user
      int getYesNo = wxMessageBox(_("Last loaded file has changed on disk.\n\n"
                                    "Reload file?"),
                                  _("File Changed"),
                                    wxYES_NO|wxICON_QUESTION,
                                    this
                                    );
       if (getYesNo != wxYES) {
          // Continue operation without re-load
          log.print("Continuing without re-load\n");
          return PROGRAMMING_RC_OK;
       }
       // Reload file non user OK
       log.print("Reloading file after user confirmation\n");
       return loadHexFile(lastFileLoaded, !incrementalLoad);
   }
}

USBDM_ErrorCode UsbdmDialogue::programFlash(bool loadAndGo) {
   LOGGING;

   USBDM_ErrorCode rc = PROGRAMMING_RC_OK;

   TransferDataFromWindow();

   wxProgressDialog pd(_("Accessing Target"),
                       _("Initialising..."),
                       100,
                       this,
                       wxPD_APP_MODAL|wxPD_ELAPSED_TIME
                       );
   progressDialogue = &pd;

   if (flashprogrammer == NULL) {
      flashprogrammer = FlashProgrammerFactory::createFlashProgrammer(bdmInterface);
   }
   do {
      // Temporarily change power options for "load & Go"
      bool leaveTargetPowered = bdmInterface->getBdmOptions().leaveTargetPowered;
      bdmInterface->getBdmOptions().leaveTargetPowered = loadAndGo||leaveTargetPowered;
      rc = bdmInterface->initBdm();
      bdmInterface->getBdmOptions().leaveTargetPowered = leaveTargetPowered;
      if (rc != BDM_RC_OK) {
         continue;
      }
#if defined(TARGET) && (TARGET == MC56F80xx)
      rc = DSC_Initialise();
      if (rc != BDM_RC_OK) {
         continue;
      }
#endif
      if (bdmInterface->getBdmOptions().targetType != T_HCS12) {
         rc = bdmInterface->targetConnectWithRetry(BdmInterface::retryNotPartial);
         if ((rc != BDM_RC_OK) && (rc != BDM_RC_BDM_EN_FAILED) && (rc != BDM_RC_SECURED)) {
            continue;
         }
      }
      rc = flashprogrammer->setDeviceData(deviceInterface->getCurrentDevice());
      if (rc != BDM_RC_OK) {
         continue;
      }
      rc = flashprogrammer->programFlash(flashImage, &progressCallBack, true);
      if (rc != BDM_RC_OK) {
         continue;
      }
      if (loadAndGo) {
         bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_NORMAL));
      }
      else {
         bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
      }
      uint16_t trimValue;
      trimValue = flashprogrammer->getCalculatedTrimValue();
      if (trimValue != 0) {
         wxString tmp;
         tmp.Printf(_("Trim Value: 0x%2.2X.%1X"), trimValue>>1, trimValue&0x01);
         trimValueStaticControl->SetLabel(tmp);
      }
      else {
         trimValueStaticControl->SetLabel(_("Trim Value: -"));
      }
   } while (false);

   progressDialogue = NULL;
   bdmInterface->closeBdm();

   // Flag error to user
   reportError(rc);

   return rc;
}

void UsbdmDialogue::reportError(USBDM_ErrorCode rc) {

   // Flag error to user
   failBeep();
   switch(rc) {
      case PROGRAMMING_RC_OK:
         break;
      case PROGRAMMING_RC_ERROR_WRONG_SDID:
         wxMessageBox(
               _("Selected target device does not agree with detected device.   \n"
                 "(Unable to read/confirm CHIP_ID)"),
               _("Programming Failed!"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this);
         break;
      case PROGRAMMING_RC_ERROR_SPEED_APPROX:
         wxMessageBox(
               _("Unable to accurately determine target bus frequency.\n\n"
                 "Please use Detect Chip to calculate an approximate value.  "),
               _("Programming not possible!"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this);
         break;
      case PROGRAMMING_RC_ERROR_TRIM:
         wxMessageBox(
               _("Trimming of target clock before programming failed!\n\n"
                 "Frequency may be out of range or clock choice incorrect.  "),
               _("Clock Trim Failed!"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this);
         break;
      case PROGRAMMING_RC_ERROR_SECURED:
         wxMessageBox(
               _("Target is secured.\n\n"
                 "The Mass Erase option must be selected to program the device.  "),
               _("Programming Failed!"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this);
         break;
      case PROGRAMMING_RC_ERROR_FAILED_VERIFY:
         wxMessageBox(
               _("Readback of the flash contents does not agree with buffer.  "),
               _("Verify after programming failed!"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this);
         break;
      default:
         wxMessageBox(
               _("Programming of the target flash failed!\n\n"
                 "Reason: ") +
                 wxString(bdmInterface->getErrorString(rc), wxConvUTF8),
               _("Programming Error"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this);
         break;
   }
}

/*
 * Verify target flash with user confirmation
 */
USBDM_ErrorCode UsbdmDialogue::verifyFlash(void) {
   LOGGING;
   USBDM_ErrorCode rc = BDM_RC_OK;

   wxProgressDialog pd(_("Accessing Target"),
                       _("Initialising..."),
                       100,
                       this,
                       wxPD_APP_MODAL|wxPD_ELAPSED_TIME
                       );
   progressDialogue = &pd;

   if (flashprogrammer == NULL) {
      flashprogrammer = FlashProgrammerFactory::createFlashProgrammer(bdmInterface);
   }
   do {
      rc = bdmInterface->initBdm();
      if (rc != BDM_RC_OK) {
         continue;
      }
#if defined(TARGET) && (TARGET == MC56F80xx)
      rc = DSC_Initialise();
      if (rc != BDM_RC_OK) {
         continue;
      }
#endif
      if (bdmInterface->getBdmOptions().targetType != T_HCS12) {
         rc = bdmInterface->targetConnectWithRetry(BdmInterface::retryNotPartial);
         if ((rc != BDM_RC_OK) && (rc != BDM_RC_BDM_EN_FAILED) && (rc != BDM_RC_SECURED)) {
            continue;
         }
      }
      rc = flashprogrammer->setDeviceData(deviceInterface->getCurrentDevice());
      if (rc != BDM_RC_OK) {
         continue;
      }
      rc = flashprogrammer->verifyFlash(flashImage, progressCallBack);
   } while(false);

   bdmInterface->closeBdm();
   progressDialogue = NULL;

   // Flag error to user
   failBeep();
   switch (rc) {
      case PROGRAMMING_RC_OK:
         break;
      case PROGRAMMING_RC_ERROR_SECURED:
         wxMessageBox(
                   _("Target is secured.\n\n"
                     "Reading target memory is not possible.  \n"
                     "(Programming flash is still available.)"),
                   _("Verify Failed!"),
                   wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                   this
                   );
         break;
      case PROGRAMMING_RC_ERROR_FAILED_VERIFY:
         wxMessageBox(
               _("Readback of the flash contents does not agree with buffer.  "),
               _("Verify failed!"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this
               );
         break;
      default:
         wxMessageBox(
               _("Verification of the target flash failed!\n\n"
                 "Reason: ")+
                 wxString(bdmInterface->getErrorString(rc), wxConvUTF8),
               _("Verify failed!"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this
               );
         break;
   }
   return rc;
}

void UsbdmDialogue::failBeep() {
   if (sound && (beep != NULL))
      beep->Play(wxSOUND_ASYNC);
}

//! Populates eeepromSizeChoiceControl with EEEPROM sizes
//! Selects 1st entry if reload is necessary (device changed)
//!
void UsbdmDialogue::populateEeepromControl() {
   LOGGING_Q;

   static FlexNVMInfoConstPtr lastFlexNVMInfo;
   if (deviceInterface->getCurrentDevice() == NULL) {
      log.print("ProgrammerDialogue::populateEeepromControl() - currentDevice not set\n");
      lastFlexNVMInfo.reset();
      eeepromSizeChoiceControl->Clear();
      eeepromSizeChoiceControl->Append(_("[No device selected]"));
      eeepromSizeChoiceControl->Select(0);
      eeepromSizeChoiceControl->Enable(false);
      eeepromSizeChoice = 0;
      return;
   }
   FlexNVMInfoConstPtr flexNVMInfo = deviceInterface->getCurrentDevice()->getflexNVMInfo();
   if (flexNVMInfo == NULL) {
      log.print("ProgrammerDialogue::populatePartitionControl() - device has no flexNVMInfo\n");
      lastFlexNVMInfo.reset();
      eeepromSizeChoiceControl->Clear();
      eeepromSizeChoiceControl->Append(_("[EEEPROM not supported]"));
      eeepromSizeChoiceControl->Select(0);
      eeepromSizeChoiceControl->Enable(false);
      eeepromSizeChoice = 0;
      return;
   }
   if (flexNVMInfo.get() == lastFlexNVMInfo.get()) {
      // No device change - no change in list
      log.print("ProgrammerDialogue::populateEeepromControl() - no update as flexNVMInfo unchanged\n");
      return;
   }
   log.print("ProgrammerDialogue::populateEeepromControl()\n");
   lastFlexNVMInfo = flexNVMInfo;
   const vector<FlexNVMInfo::EeepromSizeValue> &list(flexNVMInfo->getEeepromSizeValues());
   vector<FlexNVMInfo::EeepromSizeValue>::const_iterator it;

   eeepromSizeChoiceControl->Clear();
   for ( it=list.begin(); it < list.end(); it++) {
      eeepromSizeChoiceControl->Append(wxString(it->description.c_str(), wxConvUTF8));
   }
   eeepromSizeChoiceControl->Select(0);
   eeepromSizeChoiceControl->Enable(true);
   eeepromSizeChoice = 0;
   flexNvmPartitionIndex = 0; // Previous value is now invalid as partition table may have changed
}

//! Finds table index for given eeeprom size (FlexRAM used as Emulated eeprom)
//!
//! @param eepromSize size to look for
//!
//! @return index into eeepromSizeValues (and eeepromSizeChoiceControl control)
//!
int UsbdmDialogue::findEeepromSizeIndex(unsigned eepromSize) {
   LOGGING_Q;

   if (deviceInterface->getCurrentDevice() == NULL) {
      log.print("ProgrammerDialogue::findEeepromSizeIndex() - currentDevice not set\n");
      return 0;
   }
   FlexNVMInfoConstPtr flexNVMInfo = deviceInterface->getCurrentDevice()->getflexNVMInfo();
   if (flexNVMInfo == NULL) {
      log.print("ProgrammerDialogue::findEeepromSizeIndex() - flexNVMInfo not set\n");
      return 0;
   }
   const vector<FlexNVMInfo::EeepromSizeValue> &list(flexNVMInfo->getEeepromSizeValues());
   vector<FlexNVMInfo::EeepromSizeValue>::const_iterator it;

   int index;
   for ( it=list.begin(), index=0;
         it < list.end();
         it++, index++) {
      if (it->size == eepromSize) {
         return index;
      }
   }
   return 0; // default to 1st entry (zero size)
}

//! Populates flexNvmPartitionChoiceControl with Partition values
//!
//! @note Entries are filtered by minimum size required to satisfy eeepromSizeChoice
//! @note flexNvmPartitionIndex is used to select entry if valid or 1st entry is used
//!
void UsbdmDialogue::populatePartitionControl() {
   LOGGING_Q;

   assert(sizeof(int) <= sizeof(intptr_t));

   int flexNvmPartitionChoice = 0;      // Default to select 1st entry in populated control

   log.print("ProgrammerDialogue::populatePartitionControl()\n");
   flexNvmPartitionChoiceControl->Clear();
   if (deviceInterface->getCurrentDevice() == NULL) {
      log.print("ProgrammerDialogue::populatePartitionControl() - currentDevice not set\n");
      flexNvmPartitionChoiceControl->Append(_("[No device selected]"));
      flexNvmPartitionChoiceControl->Select(0);
      flexNvmPartitionChoiceControl->Enable(false);
      flexNvmPartitionIndex = 0;
      return;
   }
   FlexNVMInfoConstPtr flexNVMInfo = deviceInterface->getCurrentDevice()->getflexNVMInfo();
   if (flexNVMInfo == NULL) {
      log.print("ProgrammerDialogue::populatePartitionControl() - device has no flexNVMInfo\n");
      flexNvmPartitionChoiceControl->Append(_("[EEEPROM not supported]"));
      flexNvmPartitionChoiceControl->Select(0);
      flexNvmPartitionChoiceControl->Enable(false);
      flexNvmPartitionIndex = 0;
      return;
   }
   const vector<FlexNVMInfo::EeepromSizeValue> &eeepromSizeValues(flexNVMInfo->getEeepromSizeValues());
   const vector<FlexNVMInfo::FlexNvmPartitionValue> &flexNvmPartitionValues(flexNVMInfo->getFlexNvmPartitionValues());
   if (eeepromSizeChoice<=0) {
      flexNvmPartitionChoiceControl->Append(_("[All DFlash]"));
      flexNvmPartitionChoiceControl->Enable(false);
      flexNvmPartitionIndex = 0;
   }
   else {
      vector<FlexNVMInfo::FlexNvmPartitionValue>::const_iterator it;

      // Minimum required backing store for currently selected EEEPROM size
      unsigned minimumBackingStore = flexNVMInfo->getBackingRatio()*eeepromSizeValues[eeepromSizeChoice].size;
      int newIndex            = 0;                                            // Default No EEPROM
      int index;
      for ( it=flexNvmPartitionValues.begin(), index = 0; it < flexNvmPartitionValues.end(); it++, index++) {
         if (it->backingStore >= minimumBackingStore) {
            int controlIndex = flexNvmPartitionChoiceControl->Append(wxString(it->description.c_str(), wxConvUTF8));
            // Save index as client data as not all entries may be present in control
            flexNvmPartitionChoiceControl->SetClientData(controlIndex, (void*)(intptr_t)index);
            if (newIndex==0) {
               // Use 1st added choice entry as default
               newIndex = index;
            }
            if (index == flexNvmPartitionIndex) {
               // Previously selected value still available - use it selected entry
               flexNvmPartitionChoice = controlIndex; // record control entry to select
               newIndex               = index;        // record corresponding table entry
            }
         }
      }
      flexNvmPartitionChoiceControl->Enable(true);
      flexNvmPartitionIndex = newIndex;
   }
   flexNvmPartitionChoiceControl->Select(flexNvmPartitionChoice);
   log.print("ProgrammerDialogue::populatePartitionControl(), choice=%d, index=%d => size=%d\n",
          flexNvmPartitionChoice, flexNvmPartitionIndex, flexNvmPartitionValues[flexNvmPartitionIndex].backingStore);
}

//! Finds table index for given backingStoreSize size
//!
//! @param backingStoreSize size to look for
//!
//! @return index into flexNvmPartitionValues
//!
int UsbdmDialogue::findPartitionControlIndex(unsigned backingStoreSize) {
   LOGGING_Q;

   if (deviceInterface->getCurrentDevice() == NULL) {
      log.print("ProgrammerDialogue::findPartitionControlIndex() - currentDevice not set\n");
      return 0;
   }
   FlexNVMInfoConstPtr flexNVMInfo = deviceInterface->getCurrentDevice()->getflexNVMInfo();
   if (flexNVMInfo == NULL) {
      log.print("ProgrammerDialogue::findPartitionControlIndex() - flexNVMInfo not set\n");
      return 0;
   }
   const vector<FlexNVMInfo::FlexNvmPartitionValue> &flexNvmPartitionValues(flexNVMInfo->getFlexNvmPartitionValues());
   vector<FlexNVMInfo::FlexNvmPartitionValue>::const_iterator it;
   int index;
   for ( it=flexNvmPartitionValues.begin(), index = 0; it < flexNvmPartitionValues.end(); it++, index++) {
      if (it->backingStore == backingStoreSize) {
         return index;
         }
      }
   return 0; // default to 1st entry (zero size)
}

//! Updates GUI from internal FlashNVM  state
//!
//! @note values are validated
//!
void UsbdmDialogue::updateFlashNVM() {
   LOGGING_Q;

   if ((targetProperties&HAS_NVM_EEEPROM) == 0) {
      return;
   }

   static const double writeEfficiency = 0.5;     // Assume 16/32-bit writes
   static const double endurance       = 10000.0; // From JU128 specification sheet

   populateEeepromControl();
   eeepromSizeChoiceControl->SetSelection(eeepromSizeChoice);
   populatePartitionControl();

   FlexNVMInfoConstPtr flexNVMInfo;
   if (deviceInterface->getCurrentDevice() == NULL) {
      log.print("CurrentDevice not set\n");
   }
   else {
      flexNVMInfo = deviceInterface->getCurrentDevice()->getflexNVMInfo();
   }
   if (flexNVMInfo == NULL) {
      flexNvmDescriptionStaticControl->SetLabel(_("EEPROM emulation not available"));
      eeepromSizeChoice     = 0;
      flexNvmPartitionIndex = 0;
      eeepromSizeStaticText->SetLabel(_("EEEPROM Size (--)"));
      flexNvmPartitionStaticText->SetLabel(_("FlexNVM Partition (--)"));
      return;
   }
   if (eeepromSizeChoice == 0) {
      flexNvmDescriptionStaticControl->SetLabel(_("EEPROM emulation will be disabled if device is mass-erased"));
      eeepromSizeStaticText->SetLabel(_("EEEPROM Size (FF)"));
      flexNvmPartitionStaticText->SetLabel(_("FlexNVM Partition (FF)"));
      return;
   }
   const vector<FlexNVMInfo::EeepromSizeValue>      &eeepromSizeValues(flexNVMInfo->getEeepromSizeValues());
   const vector<FlexNVMInfo::FlexNvmPartitionValue> &flexNvmPartitionValues(flexNVMInfo->getFlexNvmPartitionValues());
   unsigned eeepromSize = eeepromSizeValues[eeepromSizeChoice].size;
   unsigned eepromSize  = flexNvmPartitionValues[flexNvmPartitionIndex].backingStore;
   double estimatedFlexRamWrites = (writeEfficiency*endurance*(eepromSize-2*eeepromSize))/eeepromSize;
   char buff[100];
   log.print("    eeepromSize=%d, eepromSize=%d, ratio=%.2g, estimatedFlexRamWrites=%.2g\n",
              eeepromSize, eepromSize, (double)eepromSize/eeepromSize, estimatedFlexRamWrites);

   snprintf(buff, sizeof(buff),"EEEPROM Size (%02X)", eeepromSizeValues[eeepromSizeChoice].value);
   eeepromSizeStaticText->SetLabel(wxString(buff, wxConvUTF8));
   snprintf(buff, sizeof(buff),"FlexNVM Partition (%02X)", flexNvmPartitionValues[flexNvmPartitionIndex].value);
   flexNvmPartitionStaticText->SetLabel(wxString(buff, wxConvUTF8));

   snprintf(buff, sizeof(buff),"Estimated 16-bit write cycles (based on JU128 specs) = %.2g", estimatedFlexRamWrites);
   flexNvmDescriptionStaticControl->SetLabel(wxString(buff, wxConvUTF8));
}

//! Populates customSecurityInfoPtr[] with suitable starting values if not already present
//! Populates securityMemoryRegionChoice with memory regions
//! The above are based on the current device
void UsbdmDialogue::populateSecurityControl() {
   LOGGING_Q;

   securityMemoryRegionChoice->Clear();
   if (deviceInterface->getCurrentDevice() == NULL) {
      log.print("CurrentDevice not set\n");
      securityMemoryRegionChoice->Append(_("[No device selected]"));
      securityMemoryRegionChoice->Select(0);
      securityMemoryRegionChoice->SetClientData(0, (void*)-1);
      securityMemoryRegionChoice->Enable(false);
      customSecurityIndex = 0;

      resetCustomButtonControl->Enable(false);
      customSecurityCheckbox->Enable(false);
      return;
   }

   log.print("current device = %s\n", (const char *)deviceInterface->getCurrentDevice()->getTargetName().c_str());
   unsigned  securityRegionsFound = 0;

   for(int index = 0;;index++) {
      MemoryRegionConstPtr memoryRegionPtr = deviceInterface->getCurrentDevice()->getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         // Finished
         break;
      }
//      log.print("memoryRegion[%d] => %s\n", index, memoryRegionPtr->getMemoryTypeName());
      SecurityEntryConstPtr securityEntry = memoryRegionPtr->getSecurityEntry();
      if (securityEntry != NULL) {
//         log.print("securityEntry => %s\n", securityEntry->toString().c_str());
         // Add memory to list as has security area (use first region as description)
         securityRegionsFound++;
         const MemoryRegion::MemoryRange *memoryRange = memoryRegionPtr->getMemoryRange(0);
         if (memoryRange == NULL) {
            throw(MyException("Empty memory range!"));
         }
         wxString descr;
         descr.Printf(_("%s @ %X"), memoryRegionPtr->getMemoryTypeName(), memoryRange->start);
         int itemIndex = securityMemoryRegionChoice->Append(descr, (void*)(intptr_t)index);
//         log.print("Added item[%d] = %s, ClientData = %d\n",
//               itemIndex, (const char *)securityMemoryRegionChoice->GetString(itemIndex).c_str(), index);


//         log.print("Creating resetValue                          = %s\n", securityEntry->getUnsecureInformation()->toString().c_str());

         // Add default memory security custom setting value as unsecured
         customSecurityInfo[itemIndex].resetValue = securityEntry->getUnsecureInformation();
//         log.print("Created  customSecurityInfoPtr[%d].resetValue = %s\n", itemIndex, customSecurityInfo[itemIndex].resetValue->toString().c_str());

         customSecurityInfo[itemIndex].resetToDefault();
//         log.print("Created  customSecurityInfoPtr[%d].ptr        = %s\n", itemIndex, customSecurityInfo[itemIndex].ptr->toString().c_str());
      }
   }
//   log.print("securityRegionsFound = %d\n", securityRegionsFound);

   if (customSecurityIndex >= securityRegionsFound) {
      customSecurityIndex = 0;
   }
   securityMemoryRegionChoice->Enable(securityRegionsFound >= 2);
   if (securityRegionsFound > 0) {
      securityValuesTextControl->setWidth(customSecurityInfo[customSecurityIndex].ptr->getSize());
      customSecurityCheckbox->Enable(true);
      securityMemoryRegionChoice->Select(0);
   }
   else {
//      log.print("No Memory Regions\n");
      securityMemoryRegionChoice->Append(_("[No memory regions]"));
      securityMemoryRegionChoice->Select(0);
      securityMemoryRegionChoice->SetClientData(0, (void*)-1);
      securityMemoryRegionChoice->Enable(false);
   }
}

//! Parse current value
//!
//! @return parsed value as a string
//!
wxString UsbdmDialogue::parseSecurityValue() {
   LOGGING_Q;

   enum {s_text, s_width, s_escape, s_bits} state = s_text;

   SecurityInfoConstPtr ptr;
   switch (deviceInterface->getCurrentDevice()->getSecurity()) {
      case SEC_DEFAULT:
         break;
      case SEC_SECURED:
      case SEC_UNSECURED:
      case SEC_SMART:
         ptr = securityInfoPtr;
         break;
      case SEC_CUSTOM:
         ptr = customSecurityInfo[customSecurityIndex].ptr;
         break;
   }
   if (ptr == 0) {
      log.print("ptr == NULL\n");
      return _("[not applicable]");
   }
   if (securityDescriptionPtr == NULL) {
      log.print("securityDescriptionPtr == NULL\n");
      return _("[no description available]");
   }
//   log.print("parsing...\n");

   //      unsigned       size          = securityInfoPtr->getSize();
   const uint8_t *securityValue = ptr->getData();

   char buffer[500], *b=buffer;
   int securityIndex = 0; // index into security value array
   string s = securityDescriptionPtr->getSecurityDescription();
   unsigned width    = 0;
   unsigned value    = 0;
   unsigned bitMask  = 0;
   unsigned bitCount = 0;
   char bitName[20], *pBitName=bitName;
   for (unsigned index=0; index<s.length(); index++) {
      if (b+2*width+4 >= buffer+sizeof(buffer)) {
         log.print("result too large\n");
         break;
      }
      switch(state) {
      case s_text:
         if (s[index] == '%') {
            state    = s_width;
            width    = 0;
         }
         else if (s[index] == '\\') {
            state = s_escape;
         }
         else {
            *b++ = s[index];
         }
         break;
      case s_escape:
         state = s_text;
         switch(s[index]) {
         case 'n':
            *b++ = '\n';
            break;
         case 'r':
            *b++ = '\r';
            break;
         case 't':
            *b++ = '\t';
            break;
         default:
            *b++ = s[index];
            break;
         }
         break;
         case s_width:
            if (isdigit(s[index])) {
               width *= 10;
               width += s[index]-'0';
            }
            else {
               if (width == 0) {
                  width = 1;
               }
               state = s_text;
               switch(s[index]) {
               case 'x':
               case 'X':
                  bitCount = 0;
                  for(unsigned sub=0; sub < width; sub++) {
                     *b++ = tohex(securityValue[securityIndex]>>4);
                     *b++ = tohex(securityValue[securityIndex++]);
                  }
                  break;
               case 'b':
               case 'B':
                  if (bitCount == 0) {
                     value = securityValue[securityIndex++];
                     bitCount = 8;
                  }
                  if (width > bitCount) {
                     throw MyException("ProgrammerDialogue::parseSecurityValue() - Binary field width crosses byte boundary");
                  }
                  bitCount -= width;
                  bitMask = ((1<<width)-1);
                  sprintf(b,"%X",(value>>bitCount)&bitMask);
                  b += strlen(b);
                  break;
               case '[':
                  bitCount = 0;
                  value = 0;
                  for(unsigned sub=0; sub < width; sub++) {
                     value *= 8;
                     value += securityValue[securityIndex++];
                  }
                  bitMask  = 1<<((width*8)-1);
                  pBitName = bitName;
                  state = s_bits;
                  break;
               case 'd':
                  bitCount = 0;
                  break;
               default:
                  bitCount = 0;
                  *b++ = '*';
                  break;
               }
            }
            break;
         case s_bits:
            if (isalnum(s[index])) {
               *pBitName++ = s[index];
            }
            else if ((s[index] == ',')||(s[index] == '|')||(s[index] == ']')) {
               *pBitName++ = '\0';
               if ((value & bitMask) != 0) {
                  strcpy(b, pBitName);
                  b += strlen(pBitName);
               }
               else {
                  *b++ = '0';
               }
               pBitName = bitName;
               bitMask >>= 1;
               if (s[index] == ']') {
                  state = s_text;
               }
               else {
                  *b++ = s[index];
               }
            }
            else {
               // ignore
            }
            break;
         default:
            break;
      }
      s[index];
   }
   *b = '\0';
   return wxString(buffer, wxConvUTF8);
}

void UsbdmDialogue::updateSecurityDescription() {
   LOGGING_E;
   securityDescriptionStaticText->SetLabel(parseSecurityValue());
//   securityDescriptionStaticText->PostSizeEventToParent();
}

//! Updates the security information display
//!
void UsbdmDialogue::updateSecurity() {
   LOGGING_Q;

   // No security information
   securityDescriptionPtr.reset();

//   log.print("securityMemoryRegionIndex = %d\n", customSecurityIndex);
   int memoryIndex = (int)(intptr_t)securityMemoryRegionChoice->GetClientData(customSecurityIndex);
//   log.print("memoryIndex = %d\n", memoryIndex);
   if (memoryIndex<0) {
      // Invalid - usually means Database is corrupt
      return;
   }
//   log.print("current device = %s\n", (const char *)deviceInterface->getCurrentDevice()->getTargetName().c_str());
   MemoryRegionConstPtr   memoryRegionPtr = deviceInterface->getCurrentDevice()->getMemoryRegion(memoryIndex);
   if (memoryRegionPtr == NULL) {
      throw new MyException("Memory region cannot be NULL");
   }
//   log.print("memoryRegionPtr = %s\n", memoryRegionPtr->getMemoryTypeName());

   // Security information for region
   SecurityEntryConstPtr securityEntry = memoryRegionPtr->getSecurityEntry();
   if (securityEntry == NULL) {
      log.print("No security information for memory region\n");
      log.print("memoryRegionPtr = %s\n", memoryRegionPtr->getMemoryTypeName());
      securityValuesTextControl->SetValue(_("[No security region]"));
      return;
   }

   SecurityValidator *validator = dynamic_cast<SecurityValidator*>(securityValuesTextControl->GetValidator());
   validator->setObject(SecurityInfoPtr());

   SecurityInfoPtr          tCustomSecurityInfoPtr;
   securityDescriptionPtr = securityEntry->getSecurityDescription();

   switch (deviceInterface->getCurrentDevice()->getSecurity()) {
      case SEC_DEFAULT:
         log.print("SEC_DEFAULT\n");
         securityInfoPtr.reset();
         securityValuesTextControl->SetValue(_("[Using values from flash image]"));
         securityValuesTextControl->Enable(false);
         break;
      case SEC_SECURED:
         log.print("SEC_SECURED\n");
         securityInfoPtr  = securityEntry->getSecureInformation();
         securityValuesTextControl->SetValue(securityInfoPtr->getSecurityInfo());
         securityValuesTextControl->Enable(false);
         break;
      case SEC_UNSECURED:
         log.print("SEC_UNSECURED\n");
         securityInfoPtr  = securityEntry->getUnsecureInformation();
         securityValuesTextControl->SetValue(securityInfoPtr->getSecurityInfo());
         securityValuesTextControl->Enable(false);
         break;
      case SEC_SMART:
         log.print("SEC_SMART\n");
         securityInfoPtr  = securityEntry->getUnsecureInformation();
         securityValuesTextControl->SetValue(securityInfoPtr->getSecurityInfo());
         securityValuesTextControl->Enable(false);
         break;
      case SEC_CUSTOM:
         log.print("SEC_CUSTOM\n");
         if (customSecurityInfo[customSecurityIndex].ptr == NULL) {
            // Entries should already be populated
            log.error("securityMemoryRegionIndex = %d", customSecurityIndex);
            throw new MyException("Custom security information cannot be NULL");
         }
         tCustomSecurityInfoPtr = customSecurityInfo[customSecurityIndex].ptr;
         log.print("Setting to Custom[%d] = %s\n", customSecurityIndex, customSecurityInfo[customSecurityIndex].ptr->toString().c_str());
         securityValuesTextControl->SetValue(tCustomSecurityInfoPtr->getSecurityInfo());
         securityValuesTextControl->Enable(true);
         validator->setObject(tCustomSecurityInfoPtr);
         break;
   }
   resetCustomButtonControl->Enable(deviceInterface->getCurrentDevice()->getSecurity() == SEC_CUSTOM);

   if (securityInfoPtr == NULL) {
      log.print("No security information\n");
      validator->enable(false);
      securityValuesTextControl->Enable(false);
   }
   else {
      validator->enable(false);
      securityValuesTextControl->Enable(deviceInterface->getCurrentDevice()->getSecurity() == SEC_CUSTOM);
   }
   customSecurityCheckbox->SetValue(deviceInterface->getCurrentDevice()->getSecurity() == SEC_CUSTOM);
}


USBDM_ErrorCode UsbdmDialogue::massEraseTarget() {
   LOGGING;

   TransferDataFromWindow();

   if (flashprogrammer == NULL) {
      flashprogrammer = FlashProgrammerFactory::createFlashProgrammer(bdmInterface);
   }
   USBDM_ErrorCode flashRc = bdmInterface->initBdm();
   if (flashRc != BDM_RC_OK) {
      return flashRc;
   }
   if (bdmInterface->getBdmOptions().targetType == T_HCS12) {
      // HCS12 has problems if the target is secured and doesn't support SYNC
      flashRc = hcs12Check();
      if (flashRc != BDM_RC_OK) {
         wxMessageBox(
               _("Failed to connect to target\n\n"
                     "Reason: ") +
                     wxString(bdmInterface->getErrorString(flashRc), wxConvUTF8),
                     _("Programming Error"),
                     wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                     this);
         bdmInterface->closeBdm();
         log.print("Failed to connect to target\n");
         return PROGRAMMING_RC_ERROR_BDM_CONNECT;
      }
   }
   else if (bdmInterface->getBdmOptions().targetType == T_MC56F80xx) {
//      if (bdmInterface->initBdm() != BDM_RC_OK) {
//         bdmInterface->closeBdm();
//         return PROGRAMMING_RC_ERROR_BDM_CONNECT;
//      }
   }
   else if (bdmInterface->getBdmOptions().targetType == T_ARM) {
      flashRc = bdmInterface->targetConnectWithRetry((BdmInterface::RetryMode)(BdmInterface::retryByReset|BdmInterface::retryNotPartial));
      if ((flashRc != BDM_RC_OK) && (flashRc != BDM_RC_SECURED)) {
         bdmInterface->closeBdm();
         return flashRc;
      }
   }
   else {
      if (bdmInterface->targetConnectWithRetry((BdmInterface::RetryMode)(BdmInterface::retryAlways|BdmInterface::retryByReset)) != BDM_RC_OK) {
         bdmInterface->closeBdm();
         log.print("Failed to connect\n");
         return PROGRAMMING_RC_ERROR_BDM_CONNECT;
      }
      log.print("Connected...\n");
   }
   // Set default device
   flashRc = flashprogrammer->setDeviceData(deviceInterface->getCurrentDevice());
   if (flashRc != PROGRAMMING_RC_OK) {
      bdmInterface->closeBdm();
      log.print("setDeviceData() failed\n");
      return flashRc;
   }
   // Do mass erase
   flashRc = flashprogrammer->massEraseTarget();
   if (flashRc != PROGRAMMING_RC_OK) {
      wxMessageBox(_("Unsecuring the device failed.\n"
            "Reason: ") +
            wxString(bdmInterface->getErrorString(flashRc), wxConvUTF8),
            _("Erasing Failed"),
            wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
            this);
      bdmInterface->closeBdm();
      return flashRc;
   }
   bdmInterface->closeBdm();
   return BDM_RC_OK;
}

//===================================================================================
// Event handlers
//===================================================================================

/*! Handler for OnBDMSelectCombo
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnBdmSelectComboSelected( wxCommandEvent& event ) {
   LOGGING_Q;
   log.print("event.GetSelection() = %d\n", event.GetSelection());
   bdmDeviceNum = (int)(intptr_t)bdmSelectChoiceControl->GetClientData(event.GetSelection());
   log.print("bdmDeviceNum = %d\n", bdmDeviceNum);
   update();
}

/*! Handler for OnRefreshBDM
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnRefreshBDMClick( wxCommandEvent& event ) {
   LOGGING_E;
   populateBDMChoices();
   update();
}

/*! Handler for OnVddSelectBox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnVddSelectBoxSelected( wxCommandEvent& event ) {
   switch(event.GetSelection()) {
      case 1  :    bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_3V3; break;
      case 2  :    bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_5V;  break;
      case 0  :
      default :    bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_OFF; break;
   }
   update();
}

/*! Handler for cycleVddOnConnect
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnCycleTargetVddOnConnectionCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().cycleVddOnConnect = event.IsChecked();
}

/*! Handler for OnCycleVddOnResetCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnCycleVddOnResetCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().cycleVddOnReset = event.IsChecked();
}

/*! Handler for OnLeaveTargetOnCheckbox
 */
void UsbdmDialogue::OnLeaveTargetOnCheckboxClick( wxCommandEvent& event ) {
   LOGGING;
   UsbdmSystem::Log::print("event.IsChecked() = %s\n", event.IsChecked()?"true":"false");
   bdmInterface->getBdmOptions().leaveTargetPowered = event.IsChecked();
}

/*  Handler for OnReconnectCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnReconnectCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().autoReconnect = event.IsChecked()?AUTOCONNECT_STATUS:AUTOCONNECT_NEVER;
}

/*! Handler for OnUseResetCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnUseResetCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().useResetSignal = event.IsChecked();
}

/*! Handler for OnUseUsePstSignalCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnUseUsePstSignalCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().usePSTSignals = event.IsChecked();
}

/*! Handler for OnGuessSpeedCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnGuessSpeedCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().guessSpeed = event.IsChecked();
}

/*! Handler for OnMaskInterruptsWhenSteppingCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnMaskInterruptsWhenSteppingCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().maskInterrupts = event.IsChecked();
}

/*! Handler for OnCatchVllsResetCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnCatchVllsResetCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->setCatchVLLSx(event.IsChecked());
}

/*! Handler for OnConnectionTimeoutTextTextUpdated
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnConnectionTimeoutTextTextUpdated( wxCommandEvent& event ) {
   bdmInterface->setConnectionTimeout(connectionTimeoutTextControl->GetDecimalValue());
}

/*! Handler for OnSpeedSelectCombo
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnInterfaceSpeedSelectComboSelected( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().interfaceFrequency = CFVx_Speeds[event.GetSelection()].value;
//   log.print("sel = %d, f = %d\n", event.GetSelection(), bdmInterface->getBdmOptions().interfaceSpeed);
}

/*! Handler for OnBdmClockSelectRadiobox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnBdmClockSelectRadioboxSelected( wxCommandEvent& event ) {
   switch(event.GetSelection()) {
      case 1  :    bdmInterface->getBdmOptions().bdmClockSource = CS_NORMAL_CLK; break;
      case 2  :    bdmInterface->getBdmOptions().bdmClockSource = CS_ALT_CLK;    break;
      case 0  :
      default :    bdmInterface->getBdmOptions().bdmClockSource = CS_DEFAULT;    break;
   }
}

/*! Handler for OnLoadFileButton
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnLoadFileButtonClick( wxCommandEvent& event ) {
   LOGGING;

   wxString caption  = _("Select Binary File to Load");
   wxString wildcard = _("Binary Files(*.s19,*.sx,*.s,*.afx,*.axf,*.elf)|*.s19;*.sx;*.s;*.afx;*.axf;*.elf|"
                         "SREC Hex files (*.s19,*.sx,*.s)|*.s19;*.sx;*.s|"
                         "Elf files (*.afx,*.axf,*.elf)|*.afx;*.axf;*.elf|"
                         "All Files|*");
   wxString defaultFilename = wxEmptyString;
   wxFileDialog dialog(this, caption, currentDirectory, defaultFilename, wildcard, wxFD_OPEN);
   int getCancelOK = dialog.ShowModal();
   if (getCancelOK != wxID_OK) {
      return;
   }
   currentDirectory = dialog.GetDirectory();
   loadHexFile(dialog.GetPath(), !incrementalLoad || !fileLoaded);
   update();
}

/*! Handler for OnIncrementalFileLoadCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnIncrementalFileLoadCheckboxClick( wxCommandEvent& event ) {
   incrementalLoad = event.IsChecked();
}

/*! Handler for OnAutoFileReloadCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnAutoFileReloadCheckboxClick( wxCommandEvent& event ) {
   autoFileLoad = event.IsChecked();
}

/*! Handler for OnDeviceTypeChoice
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnDeviceTypeChoiceSelected( wxCommandEvent& event ) {
   LOGGING_Q;

   // Get currently selected device type
   int deviceIndex = (int)(intptr_t) event.GetClientData();
   log.print("- devIndex=%d\n", deviceIndex);
   setDeviceIndex(deviceIndex);
   update();
}

/*! Handler for OnFilterByChipIdCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnFilterByChipIdCheckboxClick( wxCommandEvent& event ) {
   LOGGING_Q;

   doFilterByChipId = event.IsChecked() && !filterChipIds.empty();
   log.print("- currentDeviceIndex=%d\n", deviceInterface->getCurrentDeviceIndex());

   // Re-load the device list
   populateDeviceDropDown();
   update();
}

/*! Handler for OnDetectChipButton
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnDetectChipButtonClick( wxCommandEvent& event ) {
   LOGGING;

   USBDM_ErrorCode rc = autoDetectTargetDevice();
   if (rc != BDM_RC_OK) {
      wxMessageBox(
            _("Failed to probe target\n\n"
            "Reason: ") +
            wxString(bdmInterface->getErrorString(rc), wxConvUTF8),
            _("Detection error"),
            wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
            this);
   }
   // Default to filtered display if valid CHIP_ID
   doFilterByChipId = (rc== BDM_RC_OK) && !filterChipIds.empty();

   // Enable filter control check-box if valid CHIP_ID
   filterByChipIdCheckBoxControl->Set3StateValue(doFilterByChipId?wxCHK_CHECKED:wxCHK_UNCHECKED);
   filterByChipIdCheckBoxControl->Enable(doFilterByChipId);

   // Re-load the device list
   populateDeviceDropDown();
   updateFilterDescription();

   update();
}

/*! Handler for OnNonvolatileAddressText
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnNonvolatileAddressTextTextUpdated( wxCommandEvent& event ) {
   LOGGING_Q;
   deviceInterface->getCurrentDevice()->setClockTrimNVAddress(trimAddressTextControl->GetHexValue());
   log.print("- Trim NV Address = 0x%08X\n", deviceInterface->getCurrentDevice()->getClockTrimNVAddress());
}

/*! Handler for OnTrimFrequencyText
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnTrimFrequencyTextTextUpdated( wxCommandEvent& event ) {
   LOGGING_Q;
   deviceInterface->getCurrentDevice()->setClockTrimFreq((unsigned long int)trunc(trimFrequencyTextControl->GetDoubleValue()*1000));
   log.print("- Trim Frequency = %f kHz\n", deviceInterface->getCurrentDevice()->getClockTrimFreq()/1000.0);
}

/*! Handler for OnTrimFrequencyCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnTrimFrequencyCheckboxClick( wxCommandEvent& event ) {
   LOGGING_Q;
   doTrim = event.IsChecked() &&
            (deviceInterface->getCurrentDevice()->getClockType() != CLKEXT) &&
            (deviceInterface->getCurrentDevice()->getClockType() != CLKINVALID);
   log.print("- doTrim= %s\n", doTrim?"True":"False");
   if (doTrim) {
      // Enabling trim - restore to default value
      deviceInterface->getCurrentDevice()->setClockTrimFreq(deviceInterface->getCurrentDevice()->getDefaultClockTrimFreq());
      deviceInterface->getCurrentDevice()->setClockTrimNVAddress(deviceInterface->getCurrentDevice()->getDefaultClockTrimNVAddress());
   }
   else {
      // Disabling trim
      deviceInterface->getCurrentDevice()->setClockTrimFreq(0);
      deviceInterface->getCurrentDevice()->setClockTrimNVAddress(deviceInterface->getCurrentDevice()->getDefaultClockTrimNVAddress());
   }
   update();
}

/*! Handler for busFrequencyText
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnBusFrequencyTextTextUpdated( wxCommandEvent& event ) {
   bdmInterface->setGdbServerPort(1000*busFrequencyTextControl->GetDecimalValue());
}

/*! Handler for OnSecurityRadiobox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnSecurityRadioboxSelected( wxCommandEvent& event ) {
   switch (event.GetSelection()) {
      default:
      case 0:
         deviceInterface->getCurrentDevice()->setSecurity(SEC_DEFAULT);
         break;
      case 1:
         deviceInterface->getCurrentDevice()->setSecurity(SEC_SECURED);
         break;
      case 2:
         deviceInterface->getCurrentDevice()->setSecurity(SEC_UNSECURED);
         break;
      case 3:
         deviceInterface->getCurrentDevice()->setSecurity(SEC_SMART);
         break;
   }
   updateSecurity();
   updateSecurityDescription();
}

/*! Handler for OnEraseChoice
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnEraseChoiceSelect( wxCommandEvent& event ) {
   int selIndex = event.GetSelection();
   DeviceData::EraseOptions eraseOption = (DeviceData::EraseOptions)(int)(intptr_t)eraseChoiceControl->GetClientData(selIndex);
   deviceInterface->getCurrentDevice()->setEraseOption(eraseOption);
//      log.print("ProgrammerDialogue::OnEraseChoiceSelect(%s)\n", DeviceData::getEraseOptionName(eraseOption));
}

/*! Handler for OnMassEraseButton
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnMassEraseButtonClick( wxCommandEvent& event ) {
   long style1 = wxYES_NO|wxNO_DEFAULT|wxICON_WARNING|wxSTAY_ON_TOP|wxCENTER;
   int getOkCancel = wxMessageBox(
         _("This operation will entirely erase the target.\n\n"
           "Continue?"),
         _("Mass Erase and Unsecure Target"),
         style1,
         this);
   if (getOkCancel != wxYES) {
      return;
   }
   if (massEraseTarget() != BDM_RC_OK) {
      // Error already reported
      return;
   }
   long style2 = wxOK|wxICON_INFORMATION|wxSTAY_ON_TOP|wxCENTER;
   wxMessageBox(
         _("Mass erasing target completed successfully"),
         _("Mass Erase and Unsecure Complete"),
         style2,
         this);
}

/*! Handler for OnMassEraseButton
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnUnlockButtonClick( wxCommandEvent& event ) {
   LOGGING;

   long style1 = wxYES_NO|wxNO_DEFAULT|wxICON_WARNING|wxSTAY_ON_TOP|wxCENTER;
   int getOkCancel = wxMessageBox(
         _("This operation will entirely erase the target\n\n"
           "Switch target interface to JTAG mode\n"
           "(Tie JTAG_EN high, TCLK/PSTCLK=TCLK)\n\n"
           "Continue?"),
         _("Mass Erase and Unlock Target"),
         style1,
         this);
   if (getOkCancel != wxYES) {
      return;
   }
   do {
      FlashProgrammerPtr flashprogrammer(FlashProgrammerFactory::createFlashProgrammer(bdmInterface));

      bdmInterface->initBdm();

      // Set default device
      USBDM_ErrorCode flashRc = flashprogrammer->setDeviceData(deviceInterface->getCurrentDevice());
      if (flashRc != PROGRAMMING_RC_OK) {
         log.print("setDeviceData() failed, flashRc = %s\n", bdmInterface->getErrorString(flashRc));
         reportError(flashRc);
         continue;
      }

      // Mass erase
      flashRc = flashprogrammer->massEraseTarget();
      if (flashRc != PROGRAMMING_RC_OK) {
         log.print("massEraseTarget() failed, flashRc = %s\n", bdmInterface->getErrorString(flashRc));
         reportError(flashRc);
         continue;
      }
      long style2 = wxOK|wxSTAY_ON_TOP|wxCENTER;
      wxMessageBox(
            _("Mass erasing target completed successfully\n\n"
               "Switch target interface back to BDM mode\n"
               "(Tie JTAG_EN low, TCLK/PSTCLK=PSTCLK)"),
               _("Mass Erase and Unlock Complete"),
               style2,
               this);
   } while (0);
   bdmInterface->closeBdm();
}

/*! Handler for OnSoundCheckbox
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnSoundCheckboxClick( wxCommandEvent& event ) {
   sound = event.IsChecked();
}

/*! Handler for OnGdbServerPortNumber
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnGdbServerPortNumberTextUpdated( wxCommandEvent& event ) {
   bdmInterface->setGdbServerPort(gdbServerPortNumberTextControl->GetDecimalValue());
}

/*! Handler for OnGdbTtyPortNumberTextUpdated
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnGdbTtyPortNumberTextUpdated( wxCommandEvent& event ) {
   bdmInterface->setGdbTtyPort(gdbTtyPortNumberTextControl->GetDecimalValue());
}

/*! Handler for OnProgramFlashButton
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnProgramFlashButtonClick( wxCommandEvent& event ) {
   LOGGING;

   int getYesNo;
   long style = wxYES_NO|wxNO_DEFAULT |wxICON_QUESTION|wxSTAY_ON_TOP|wxCENTER;

   do {
      if (checkFileChange() != PROGRAMMING_RC_OK) {
         return;
      }
      if (programFlash() != PROGRAMMING_RC_OK) {
         return;
      }
      getYesNo = wxMessageBox(
                        _("Programming and verification of the    \n"
                          "flash has completed successfully.\n\n"
                          "Program another device?"),
                        _("Programming Completed"),
                        style,
                        this);
      // Change default to yes on subsequent dialogues
      style = wxYES_NO|wxYES_DEFAULT|wxICON_QUESTION|wxSTAY_ON_TOP|wxCENTER;
   } while (getYesNo == wxYES);
}

/*! Handler for OnVerifyFlashButton
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnVerifyFlashButtonClick( wxCommandEvent& event ) {

   int getYesNo;
   long style = wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION|wxSTAY_ON_TOP|wxCENTER;

   do {
      if (checkFileChange() != PROGRAMMING_RC_OK) {
         return;
      }
      if (verifyFlash() != PROGRAMMING_RC_OK) {
         return;
      }
      getYesNo = wxMessageBox(
                        _("Verification of the flash contents      \n"
                          "has completed successfully.\n\n"
                          "Verify another device?"),
                        _("Verify Completed"),
                        style,
                        this);
      // Change default to yes on subsequent dialogues
      style = wxYES_NO|wxYES_DEFAULT|wxICON_QUESTION|wxSTAY_ON_TOP|wxCENTER;
   } while (getYesNo == wxYES);
}

/*! Handler for OnLoadAndGoButton
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnLoadAndGoButtonClick( wxCommandEvent& event ) {

   int getYesNo;
   long style = wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION|wxSTAY_ON_TOP|wxCENTER;
   do {
      if (checkFileChange() != PROGRAMMING_RC_OK) {
         return;
      }
      if (programFlash(true) != PROGRAMMING_RC_OK) {
         return;
      }
      getYesNo = wxMessageBox(
                        _("Programming is complete.             \n"
                          "Target has been reset and is running.\n\n"
                          "Program another device?"),
                        _("Load and Go Completed"),
                        style,
                        this);
      // Change default to yes on subsequent dialogues
      style = wxYES_NO|wxYES_DEFAULT|wxICON_QUESTION|wxSTAY_ON_TOP|wxCENTER;
   } while (getYesNo == wxYES);
}

/*
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DEVICE_TYPE_CHOICE
 */
void UsbdmDialogue::OnEeepromSizeChoiceSelected( wxCommandEvent& event ) {
   LOGGING_Q;

   // Get currently selected eeeprom choice
   eeepromSizeChoice = event.GetSelection();
   log.print("- EEPROM size choice = %d\n", eeepromSizeChoice);
   update();
}

/*
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DEVICE_TYPE_CHOICE
 */
void UsbdmDialogue::OnFlexNvmPartionChoiceSelected( wxCommandEvent& event ) {
   LOGGING_Q;

   // Get currently selected FlexNVM partition choice
   flexNvmPartitionIndex = (int)(intptr_t) event.GetClientData();
   log.print("- Partition value =0x%02X\n", flexNvmPartitionIndex);
   update();
}

void UsbdmDialogue::OnSecurityMemoryRegionChoiceSelected( wxCommandEvent& event ) {
   LOGGING_Q;
   int index = event.GetSelection();
   // Save date for currently selected security memory region choice
   log.print("From = %d\n", customSecurityIndex);
   // Change memory region
   customSecurityIndex = index;
   log.print("To   = %d\n", customSecurityIndex);

   securityValuesTextControl->setWidth(customSecurityInfo[customSecurityIndex].ptr->getSize());
}

//! wxEVT_COMMAND_BUTTON_CLICKED event handler
//!
//! @param event The event to handle
//!
void UsbdmDialogue::OnResetCustomValueClick( wxCommandEvent& event ) {
   LOGGING_E;
   log.print("ProgrammerDialogue::OnResetCustomValueClick()\n");
   customSecurityInfo[customSecurityIndex].resetToDefault();
   updateSecurity();
   updateSecurityDescription();
}

//! wxEVT_COMMAND_BUTTON_CLICKED event handler
//!
//! @param event The event to handle
//!
void UsbdmDialogue::OnSecurityCheckboxClick( wxCommandEvent& event ) {
   LOGGING_E;
   if (event.IsChecked()) {
      // Enabling custom values

      // Save current value to return to if disabled
      lastSecurityOption = deviceInterface->getCurrentDevice()->getSecurity();
      if (lastSecurityOption == SEC_CUSTOM) {
         lastSecurityOption = SEC_UNSECURED;
      }
      // Set custom values
      deviceInterface->getCurrentDevice()->setSecurity(SEC_CUSTOM);
   }
   else {
      // Restore last non-custom value
      deviceInterface->getCurrentDevice()->setSecurity(lastSecurityOption);
   }
   updateSecurity();
   updateSecurityDescription();
   update();
}

void UsbdmDialogue::OnSecurityEditUpdate(wxCommandEvent& event) {
   LOGGING_E;
   if (deviceInterface->getCurrentDevice()->getSecurity() == SEC_CUSTOM) {
      customSecurityInfo[customSecurityIndex].ptr->setSecurityInfo(securityValuesTextControl->getHexValues());
   }
   updateSecurityDescription();
}

/*! Handler for OnPowerOffDurationText
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnPowerOffDurationText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().powerOffDuration = powerOffDurationTextControl->GetDecimalValue();
}
/*! Handler for OnPowerOnDurationText
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnPowerOnDurationText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().powerOnRecoveryInterval = powerOnRecoveryIntervalTextControl->GetDecimalValue();
}
/*! Handler for OnResetDurationText
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnResetDurationText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().resetDuration = resetDurationTextControl->GetDecimalValue();
}
/*! Handler for OnResetReleaseIntervalText
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnResetReleaseIntervalText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().resetReleaseInterval = resetReleaseIntervalTextControl->GetDecimalValue();
}
/*! Handler for OnResetRecoveryIntervalText
 *
 *  @param event The event to handle
 */
void UsbdmDialogue::OnResetRecoveryIntervalText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().resetRecoveryInterval = resetRecoveryIntervalTextControl->GetDecimalValue();
}

//void UsbdmDialogue::OnOkClick( wxCommandEvent& event ) {
//   LOGGING;
//}

//void UsbdmDialogue::OnCloseHandler( wxCloseEvent& event ) {
//   event.Skip();
//}
