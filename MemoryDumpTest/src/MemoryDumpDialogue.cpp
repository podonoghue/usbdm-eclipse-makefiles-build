/*
 * MemoryDumpDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include <stdio.h>

#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/tokenzr.h>

#include "UsbdmSystem.h"
#include "Names.h"
#include "HexNumberGridEditor.h"
#include "MemoryDumpDialogue.h"
#include "ProgressDialogueFactory.h"
#include "FlashProgrammer.h"

//! Maximum size of a S-record, should be power of 2
const int maxSrecSize = (1<<4);

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

MemoryDumpDialogue::MemoryDumpDialogue(wxWindow* parent, AppSettings &appSettings) :
         MemoryDumpDialogueSkeleton(parent),
         targetType(T_NONE),
//         appSettings(appSettings),
         bdmDeviceNum(-1),
         bdmCapabilities(BDM_CAP_NONE),
         hcs08PPageAddress(0x08),
         hcs12PPageAddress(0x30),
         hcs12EPageAddress(0x17)
{
   LOGGING;
   log.print("Before %p = \n", bdmSelectChoiceControl);
   bdmSelectChoiceControl->SetSelection(0);
   log.print("After %p = \n", bdmSelectChoiceControl);
}

MemoryDumpDialogue::~MemoryDumpDialogue() {
   LOGGING;
   saveSettings();
}

int  MemoryDumpDialogue::ShowModal() {
   MemoryDumpDialogueSkeleton::Show();
   loadSettings();
   MemoryDumpDialogueSkeleton::Hide();
   int rc = MemoryDumpDialogueSkeleton::ShowModal();
   saveSettings();
   return rc;
}

struct MemoryRange {
   uint32_t start;
   uint32_t end;
};

void MemoryDumpDialogue::loadSettings() {
   LOGGING;
//   hcs08PPageAddress = appSettings.getValue("hcs08PPageAddress", 0x08);
//   hcs12PPageAddress = appSettings.getValue("hcs12PPageAddress", 0x30);
//   hcs12EPageAddress = appSettings.getValue("hcs12EPageAddress", 0x17);
//
//   currentDirectory = appSettings.getValue("directory", "");
//   currentFilename  = appSettings.getValue("filename", "");
//
//   setTargetType((TargetType_t)appSettings.getValue("targetType", (int)T_ARM));
   setTargetType(T_HCS12);

//   populateBDMChoices();
   populateInterfaceSpeeds();

//   setInterfaceSpeed(appSettings.getValue("interfaceSpeed", 250));
//   setVdd((TargetVddSelect_t)appSettings.getValue("targetVdd", (int)BDM_TARGET_VDD_OFF));

   update();
}

void MemoryDumpDialogue::saveSettings() {}

/*
 * Update general
 */
void MemoryDumpDialogue::update() {
   LOGGING;

   // BDM related information based on bdmDeviceNum
   if (bdmDeviceNum >= 0) {
      log.print("bdmDeviceNum >= 0\n");
      bdmCapabilities = connectedBDMs[bdmDeviceNum].getInfo().capabilities;
      bdmIdentification = wxString::FromUTF8(connectedBDMs[bdmDeviceNum].getDescription().c_str());
      wxString versionString;
      versionString.Printf(_("BDM Firmware Ver %d.%d.%d"),
            (connectedBDMs[bdmDeviceNum].getInfo().BDMsoftwareVersion>>16)&0xFF,
            (connectedBDMs[bdmDeviceNum].getInfo().BDMsoftwareVersion>>8)&0xFF,
            connectedBDMs[bdmDeviceNum].getInfo().BDMsoftwareVersion&0xFF
      );
      bdmDescriptionStaticControl->SetLabel(bdmIdentification);
      bdmInterface->setBdmSerialNumber(connectedBDMs[bdmDeviceNum].getSerialNumber(), true);
   }
   else {
      log.print("bdmDeviceNum < 0\n");
      bdmCapabilities   = BDM_CAP_NONE;
      bdmIdentification = wxEmptyString;
      bdmDescriptionStaticControl->SetLabel(wxEmptyString);
      log.print("Stage 1\n");

      bdmInterface->setBdmSerialNumber("", false);
      log.print("Stage 2\n");

   }
   // Target Vdd related
   if (!(bdmCapabilities & BDM_CAP_VDDCONTROL)) {
      // BDM interface doesn't have Vdd control - Vdd control options disabled
      bdmInterface->getBdmOptions().targetVdd          = BDM_TARGET_VDD_OFF;
      bdmInterface->getBdmOptions().cycleVddOnReset    = false;
      bdmInterface->getBdmOptions().leaveTargetPowered = false;
      bdmInterface->getBdmOptions().cycleVddOnConnect  = false;
   }
   else {
      log.print("Stage 3\n");
   }
   switch (targetType) {
      case T_ARM:
      case T_CFVx:
         break;
      default:
         break;
   }
   log.print("Stage 4\n");

   populateInterfaceSpeeds();
}

void MemoryDumpDialogue::populateInterfaceSpeeds() {
   LOGGING;
}

/*!
 *  Populate the BDM Choice box
 */
void MemoryDumpDialogue::populateBDMChoices(void) {
   LOGGING;

   log.print("Step 1\n");

   log.print("Stage X1\n");
   bdmSelectChoiceControl->wxTextEntry::Clear();
   log.print("Stage X2\n");
   bdmSelectChoiceControl->wxItemContainer::Clear();
//   bdmSelectChoiceControl->Clear();

   // Enumerate all attached BDMs
   bdmInterface->findBDMs(connectedBDMs);
   log.print("Step 2 connectedBDMs = %p\n", &connectedBDMs);
   int deviceCount = connectedBDMs.size();
   log.print("Step 2a\n");
   log.print("Step 2y bdmSelectChoiceControl = %p\n", bdmSelectChoiceControl);
//   bdmSelectChoiceControl->Clear();
   log.print("Step 2b\n");

   log.print(" bdmIdentification = \'%s\'\n", (const char *)bdmIdentification.ToAscii());
   if (deviceCount==0) {
      // No devices found
      bdmSelectChoiceControl->Append(_("[No devices Found]"));
      bdmSelectChoiceControl->Select(0);
      bdmSelectChoiceControl->SetClientData(0, (void*)-2);
      bdmSelectChoiceControl->Enable(false);
      bdmDeviceNum = -1;
      bdmIdentification = wxEmptyString;
      log.print(" - no BDMs found\n");
      return;
   }
   log.print("Step 3\n");
   if (bdmDeviceNum >= deviceCount) {
      bdmDeviceNum = 0;
   }
   // Add device names to choice box, client data is device number from usb scan
   vector<BdmInformation>::iterator it;
   for ( it=connectedBDMs.begin(); it<connectedBDMs.end(); it++ ) {
      int index = bdmSelectChoiceControl->Append(wxString::FromUTF8(it->getSerialNumber().c_str()));
      bdmSelectChoiceControl->SetClientData(index, (void*)(it-connectedBDMs.begin()));
   }
   log.print("Step 4\n");
   // Try to select previous device
   if (bdmIdentification.empty() || !bdmSelectChoiceControl->SetStringSelection(bdmIdentification)) {
      log.print("Step 4b\n");
      // Select 1st device by default
      bdmSelectChoiceControl->SetSelection(0);
   }
   bdmDeviceNum      = (int)(intptr_t)bdmSelectChoiceControl->GetClientData();
   bdmIdentification = bdmSelectChoiceControl->GetStringSelection();

   log.print("Step 5\n");
   bdmSelectChoiceControl->Enable(deviceCount>1);
   log.print(" - %d BDMs added.\n", deviceCount);
}

void MemoryDumpDialogue::OnBdmSelectComboSelected( wxCommandEvent& event ) {
   LOGGING;
   log.print("event.GetSelection() = %d\n", event.GetSelection());
   bdmDeviceNum = (int)(intptr_t)bdmSelectChoiceControl->GetClientData(event.GetSelection());
   log.print("bdmDeviceNum = %d\n", bdmDeviceNum);
   update();
}

void MemoryDumpDialogue::OnRefreshBDMClick( wxCommandEvent& event ) {
   LOGGING_E;
   populateBDMChoices();
   update();
}

void MemoryDumpDialogue::setVdd(TargetVddSelect_t targetVdd) {
   LOGGING;
}

void MemoryDumpDialogue::setInterfaceSpeed(signed speed) {}

void MemoryDumpDialogue::setTargetType(TargetType_t targetType) {
   LOGGING;
   
   this->targetType = targetType;

   bdmInterface = BdmInterfaceFactory::createInterface(targetType);
}

