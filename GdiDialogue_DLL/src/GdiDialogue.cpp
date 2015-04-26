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
   | 15 Mar 2015 | Complete redesign using wxFormBuilder                   - pgo V4.10.6.260
   +=========================================================================================
   \endverbatim
*/
#include "GdiDialogue.h"

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

/*!
 *  This displays the Dialogue to obtain settings from the user.
 *  - Accepts and updates settings object
 *  - Prompts user to select BDM etc.
 *
 *  @param appSettings   Settings object to use
 *  @param forceDisplay  Display dialogue even if appSettings indicates not to
 *
 *  @return BDM_RC_OK - Settings may have been changed and need to be saved
 *                    - Otherwise an error or user has cancelled dialogue
 */
USBDM_ErrorCode GdiDialogue::execute(AppSettingsPtr appSettings, bool forceDisplay) {
   LOGGING;

   loadSettings(*appSettings);

   if (!forceDisplay && dontShowDialogue) {
      // Return immediately - assumes settings are suitable
      return BDM_RC_OK;
   }

   // User must manually choose this option again if force displayed (due to an error usually)
   dontShowDialogue = false;

   hideUnusedControls();
   Init();
   Layout();
   Fit();

   USBDM_ErrorCode result = (USBDM_ErrorCode)ShowModal();
   if (result == BDM_RC_OK) {
      saveSettings(*appSettings);
   }
   else {
      // Restore setting to original values
      loadSettings(*appSettings);
   }
   return result;
}

const string GdiDialogue::settingsKey("ProgrammerDialogue");

//===================================================================================

//! Used to control features in dialogue according to target type
const uint32_t GdiDialogue::targetPropertyFlags[] = {
/*  0 HCS12     */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|HAS_PROBE_SECURED|HAS_CLK_SW|HAS_GUESS_SPEED,
/*  1 HCS08     */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|HAS_PROBE_SECURED|HAS_CLK_SW|HAS_OPTIONAL_RESET|HAS_TRIM|HAS_MASK_INTERRUPTS,
/*  2 RS08      */  HAS_MASS_ERASE|                    HAS_PROBE_SECURED|HAS_CLK_SW|HAS_OPTIONAL_RESET|HAS_TRIM,
/*  3 CFV1      */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|                  HAS_CLK_SW|HAS_OPTIONAL_RESET|HAS_TRIM|HAS_NVM_EEEPROM,
/*  4 CFVx      */  HAS_USE_PST|   HAS_SELECTIVE_ERASE|HAS_PROBE_SECURED|HAS_SELECT_SPEED,
/*  5 JTAG      */  HAS_NONE,
/*  6 EZFLASH   */  HAS_NONE,
/*  7 MC56F80xx */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|HAS_PROBE_SECURED|HAS_SELECT_SPEED,
/*  8 ARM       */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|                  HAS_SELECT_SPEED|HAS_VLLS_RESET_CAPTURE|HAS_NVM_EEEPROM|HAS_MASK_INTERRUPTS,
/*  9 ARM_JTAG  */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|                  HAS_SELECT_SPEED|HAS_VLLS_RESET_CAPTURE|HAS_NVM_EEEPROM|HAS_MASK_INTERRUPTS,
/* 10 ARM_SWD   */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE|                  HAS_SELECT_SPEED|HAS_VLLS_RESET_CAPTURE|HAS_NVM_EEEPROM|HAS_MASK_INTERRUPTS,
/* 11 S12Z      */  HAS_MASS_ERASE|HAS_SELECTIVE_ERASE,
};

/*!
 * Get properties of target type
 *
 * @return Bit-mask describing properties
 *
 */
uint32_t GdiDialogue::getTargetProperties(TargetType_t targetType) {
   LOGGING_E;
   if ((targetType<0) || (targetType>=(sizeof(targetPropertyFlags)/sizeof(targetPropertyFlags[0])))) {
      return 0;
   }
   //TODO consider HAS_MASK_INTERRUPTS
   return (targetPropertyFlags[targetType] | IS_GDI_DIALOGUE) & ~(HAS_VLLS_RESET_CAPTURE|HAS_MASK_INTERRUPTS);
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
const wxString &GdiDialogue::bdmGetDllVersion(void) {
   static wxString versionString;

   versionString = wxString(USBDM_DLLVersionString(), wxConvUTF8);

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

//===================================================================================
//===================================================================================
//===================================================================================

GdiDialogue::GdiDialogue(wxWindow* parent, BdmInterfacePtr bdmInterface) :
   GdiDialogueSkeleton(parent, wxID_ANY, _("USBDM Settings")),
   bdmInterface(bdmInterface) {
   LOGGING_E;

   targetProperties        = 0;
   bdmDeviceNum            = -1;
   bdmCapabilities         = BDM_CAP_NONE;
   dontShowDialogue        = false;
}

GdiDialogue::~GdiDialogue() {
   LOGGING_Q;
}

void GdiDialogue::addValidators() {
   LOGGING_Q;

   // Note: copies are used so original is shared!
   wxTextValidator integerValidator(wxFILTER_DIGITS, 0);
   wxTextValidator hexValidator(wxFILTER_INCLUDE_CHAR_LIST, 0);
   hexValidator.SetCharIncludes("0123456789abcdefABCDEF");
   wxTextValidator numericValidator(wxFILTER_NUMERIC, 0);

   connectionTimeoutTextControl->SetValidator(integerValidator);

   powerOffDurationTextControl->SetValidator(integerValidator);
   powerOnRecoveryIntervalTextControl->SetValidator(integerValidator);
   resetDurationTextControl->SetValidator(integerValidator);
   resetReleaseIntervalTextControl->SetValidator(integerValidator);
   resetRecoveryIntervalTextControl->SetValidator(integerValidator);
}

void GdiDialogue::Init() {
   LOGGING;

   connectedBDMs.clear();
   bdmIdentification          = wxEmptyString;
   bdmDeviceNum               = -1;
   bdmCapabilities            = BDM_CAP_NONE;
   log.print("targetProperties = 0x%X\n", targetProperties);

   populateInterfaceSpeeds();
   populateBDMChoices();
   populateInterfaceSpeeds();

   dllVersionstaticControl->SetLabel(bdmGetDllVersion());
}

std::string GdiDialogue::update() {
   LOGGING;

   log.print("Device# = %d, BDM = \'%s\'\n", bdmDeviceNum, (const char *)bdmIdentification.ToAscii());

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
   if ((targetProperties & IS_PROGRAMMER) == 0) {
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
         bdmInterface->getBdmOptions().useResetSignal = false;
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

   /*
    * ===========================================================================
    * Advanced
    * ===========================================================================
    */
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

/*! Load settings from a settings object
 *
 *  @param appSettings - Object containing settings
 */
void GdiDialogue::loadSettings(const AppSettings &appSettings) {
   LOGGING;

   bdmInterface->loadSettings(appSettings);
   dontShowDialogue = appSettings.getValue(settingsKey+".dontDisplayDialogue", false);
}

/*! Load settings from a settings object
 *
 *  @param appSettings - Object containing settings
 */
void GdiDialogue::saveSettings(AppSettings &appSettings) {
   LOGGING;

   bdmInterface->saveSettings(appSettings);
   appSettings.addValue(settingsKey+".dontDisplayDialogue", dontShowDialogue);
}

/*!
 * Hide unused controls
 *
 * @param flags Flags controlling which controls are present
 *
 */
void GdiDialogue::hideUnusedControls() {
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
   fInterfacePanel->Layout();
   fAdvancedPanel->Layout();
}

//===================================================================================

void GdiDialogue::populateInterfaceSpeeds() {

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

//=======================================================================

//===================================================================
/*
 *  Set the internal dialogue values.
 *
 */
bool GdiDialogue::setDialogueValuesToDefault() {
   LOGGING;

   Init();
   TransferDataToWindow();
   return true;
}

//===================================================================
/*!
 * Update the dialogue from internal state
 */
bool GdiDialogue::TransferDataToWindow() {
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

   update();

   return true;
}

bool GdiDialogue::TransferDataFromWindow() {
   LOGGING;
   return true;
}

/*
 * Update the list of connected BDMs (connectedBDMs)
 */
void GdiDialogue::findBDMs(void) {
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
void GdiDialogue::populateBDMChoices(void) {
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
   for ( it=connectedBDMs.begin(); it < connectedBDMs.end(); it++ ) {
      int index = bdmSelectChoiceControl->Append(wxString::FromUTF8(it->getSerialNumber().c_str()));
      bdmSelectChoiceControl->SetClientData(index, (void*)(intptr_t)it->getDeviceNumber());
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

//===================================================================================
// Event handlers
//===================================================================================

/*! Handler for OnBDMSelectCombo
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnBdmSelectComboSelected( wxCommandEvent& event ) {
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
void GdiDialogue::OnRefreshBDMClick( wxCommandEvent& event ) {
   LOGGING_E;
   populateBDMChoices();
   update();
}

/*! Handler for OnVddSelectBox
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnVddSelectBoxSelected( wxCommandEvent& event ) {
   switch(event.GetSelection()) {
      case 1  :    bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_3V3; break;
      case 2  :    bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_5V;  break;
      case 0  :
      default :    bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_OFF; break;
   }
   update();
}

/*! Handler for OnCycleVddOnResetCheckbox
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnCycleVddOnResetCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().cycleVddOnReset = event.IsChecked();
}

/*! Handler for OnBDMSelectCombo
 *
 *  @param event The event OnCycleTargetVddOnConnectionCheckbox handle
 */
void GdiDialogue::OnCycleTargetVddOnConnectionCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().cycleVddOnConnect = event.IsChecked();
}

/*! Handler for OnLeaveTargetOnCheckbox
 */
void GdiDialogue::OnLeaveTargetOnCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().leaveTargetPowered = event.IsChecked();
}

/*  Handler for OnReconnectCheckbox
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnReconnectCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().autoReconnect = event.IsChecked()?AUTOCONNECT_STATUS:AUTOCONNECT_NEVER;
}

/*! Handler for OnUseResetCheckbox
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnUseResetCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().useResetSignal = event.IsChecked();
}

/*! Handler for OnUseUsePstSignalCheckbox
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnUseUsePstSignalCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().usePSTSignals = event.IsChecked();
}

/*! Handler for OnGuessSpeedCheckbox
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnGuessSpeedCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().guessSpeed = event.IsChecked();
}

/*! Handler for OnMaskInterruptsWhenSteppingCheckbox
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnMaskInterruptsWhenSteppingCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().maskInterrupts = event.IsChecked();
}

/*! Handler for OnCatchVllsResetCheckbox
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnCatchVllsResetCheckboxClick( wxCommandEvent& event ) {
   bdmInterface->setCatchVLLSx(event.IsChecked());
}

/*! Handler for OnConnectionTimeoutTextTextUpdated
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnConnectionTimeoutTextTextUpdated( wxCommandEvent& event ) {
   bdmInterface->setConnectionTimeout(connectionTimeoutTextControl->GetDecimalValue());
}

/*! Handler for OnSpeedSelectCombo
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnInterfaceSpeedSelectComboSelected( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().interfaceFrequency = CFVx_Speeds[event.GetSelection()].value;
//   log.print("sel = %d, f = %d\n", event.GetSelection(), bdmInterface->getBdmOptions().interfaceSpeed);
}

/*! Handler for OnBdmClockSelectRadiobox
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnBdmClockSelectRadioboxSelected( wxCommandEvent& event ) {
   switch(event.GetSelection()) {
      case 1  :    bdmInterface->getBdmOptions().bdmClockSource = CS_NORMAL_CLK; break;
      case 2  :    bdmInterface->getBdmOptions().bdmClockSource = CS_ALT_CLK;    break;
      case 0  :
      default :    bdmInterface->getBdmOptions().bdmClockSource = CS_DEFAULT;    break;
   }
}

/*! Handler for OnPowerOffDurationText
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnPowerOffDurationText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().powerOffDuration = powerOffDurationTextControl->GetDecimalValue();
}
/*! Handler for OnPowerOnDurationText
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnPowerOnDurationText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().powerOnRecoveryInterval = powerOnRecoveryIntervalTextControl->GetDecimalValue();
}
/*! Handler for OnResetDurationText
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnResetDurationText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().resetDuration = resetDurationTextControl->GetDecimalValue();
}
/*! Handler for OnResetReleaseIntervalText
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnResetReleaseIntervalText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().resetReleaseInterval = resetReleaseIntervalTextControl->GetDecimalValue();
}
/*! Handler for OnResetRecoveryIntervalText
 *
 *  @param event The event to handle
 */
void GdiDialogue::OnResetRecoveryIntervalText( wxCommandEvent& event ) {
   bdmInterface->getBdmOptions().resetRecoveryInterval = resetRecoveryIntervalTextControl->GetDecimalValue();
}

void GdiDialogue::OnDontShowAgainControlClick( wxCommandEvent& event ) {
   dontShowDialogue = event.IsChecked();
}

void GdiDialogue::OnOpenBdmClick( wxCommandEvent& event ) {
   EndModal(BDM_RC_OK);
}

void GdiDialogue::OnCancelClick( wxCommandEvent& event ) {
   EndModal(BDM_RC_FAIL);
}

void GdiDialogue::OnClose( wxCloseEvent& event ) {
   LOGGING_E;
   EndModal(BDM_RC_OK);
   Destroy();
}

