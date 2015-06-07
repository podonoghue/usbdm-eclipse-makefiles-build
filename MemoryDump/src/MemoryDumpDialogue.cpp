/*
 * MemoryDumpDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include <stdio.h>

#include <wx/filedlg.h>

#include "UsbdmSystem.h"
#include "Names.h"
#include "HexNumberGridEditor.h"
#include "MemoryDumpDialogue.h"
#include "ProgressDialogueFactory.h"

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

MemoryDumpDialogue::MemoryDumpDialogue(wxWindow* parent, AppSettingsPtr appSettings) :
   MemoryDumpDialogueSkeleton(parent),
   targetType(T_ARM),
   appSettings(appSettings),
   bdmDeviceNum(-1),
   bdmCapabilities(BDM_CAP_NONE)
{
   memoryRangesGrid->SetColFormatNumber(2);
   saveToFileButton->Enable(false);

   wxGridCellAttr *attr;
   attr = new wxGridCellAttr();
   attr->SetEditor((wxGridCellEditor *)new HexNumberGridEditor());
   attr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
   memoryRangesGrid->SetColAttr(0, attr);

   attr = new wxGridCellAttr();
   attr->SetEditor((wxGridCellEditor *)new HexNumberGridEditor());
   attr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
   memoryRangesGrid->SetColAttr(1, attr);

   attr = new wxGridCellAttr();
   attr->SetAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
   memoryRangesGrid->SetColAttr(2, attr);
}

MemoryDumpDialogue::~MemoryDumpDialogue() {
   LOGGING;
   saveSettings();
}

int  MemoryDumpDialogue::ShowModal() {
   loadSettings();
   int rc = MemoryDumpDialogueSkeleton::ShowModal();
   saveSettings();
   return rc;
}

void MemoryDumpDialogue::OnTargetTypeRadioBox( wxCommandEvent& event ) {
   LOGGING;
   setTargetType(getTargetType());
   log.print("Selected target type = %s\n", getTargetTypeName(targetType));
   update();
}

void MemoryDumpDialogue::OnSaveToFileButton( wxCommandEvent& event ) {
   LOGGING;

   if (flashImage == 0) {
      return;
   }
   wxString caption  = _("Select save location for binary file");
   wxString wildcard = _("SREC Hex files (*.s19,*.sx,*.s)|*.s19;*.sx;*.s|"
                         "All Files|*");
   wxFileDialog dialog(this, caption, currentDirectory, currentFilename, wildcard, wxFD_SAVE);
   int getCancelOK = dialog.ShowModal();
   if (getCancelOK != wxID_OK) {
      return;
   }
   currentDirectory = dialog.GetDirectory();
   currentFilename  = dialog.GetFilename();
   string filePath(dialog.GetPath());
   log.print("customPath     = \'%s\'\n", (const char *)filePath.c_str());
   flashImage->saveFile(filePath, !keepEmptySRECsCheckbox->IsChecked());
}

void MemoryDumpDialogue::OnReadMemoryButtonClick( wxCommandEvent& event ) {
   LOGGING;

   clearStatus();

   writeStatus("Creating Empty flash image...\n");
   flashImage = FlashImageFactory::createFlashImage(targetType);

   writeStatus("Changing interface options...\n");
   bdmInterface->getBdmOptions().targetVdd = getVdd();
   bdmInterface->getBdmOptions().interfaceFrequency = getInterfaceSpeed();

   if (targetType == T_ARM) {
      bdmInterface->getBdmOptions().interfaceFrequency = 12000;
   }
   USBDM_ErrorCode rc = BDM_RC_OK;
   do {
      rc = bdmInterface->initBdm();
      if (rc != BDM_RC_OK) {
         break;
      }
      rc = bdmInterface->targetConnectWithRetry();
      if (rc != BDM_RC_OK) {
         break;
      }
      rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
      if (rc != BDM_RC_OK) {
         break;
      }
      rc = bdmInterface->targetConnectWithRetry();
      if (rc != BDM_RC_OK) {
         break;
      }
      rc = readMemoryBlocks(ProgressDialogueFactory::create("Accessing Target", 100, this));
      if (rc != BDM_RC_OK) {
         break;
      }
   } while (0);
   bdmInterface->closeBdm();
   if (rc != BDM_RC_OK) {
      writeStatus("Failed, reason = %s\n", bdmInterface->getErrorString(rc));
      flashImage.reset();
   }
   saveToFileButton->Enable((flashImage != 0) && !flashImage->isEmpty());
   writeStatus("Done\n");
}

void MemoryDumpDialogue::OnKeepEmptySRECsCheckboxClick( wxCommandEvent& event ) {
}

struct MemoryRange {
   uint32_t start;
   uint32_t end;
};

USBDM_ErrorCode MemoryDumpDialogue::readMemoryBlocks(ProgressDialoguePtr progress) {
   LOGGING;
   for (int row = 0; row < memoryRangesGrid->GetRows(); row++) {
      long int start, end, width;
      wxString startValue = memoryRangesGrid->GetCellValue(row,0);
      wxString endValue   = memoryRangesGrid->GetCellValue(row,1);
      wxString widthValue = memoryRangesGrid->GetCellValue(row,2);

      if (startValue.IsEmpty() && endValue.IsEmpty() && widthValue.IsEmpty()) {
         continue;
      }
      if (!widthValue.ToLong(&width) || ((width!=0) && (width!=1) && (width!=2) && (width!=4))) {
         writeStatus("Illegal width (entry #%d), \'%s\'\n", row+1, (const char *)widthValue.c_str());
         return BDM_RC_ILLEGAL_PARAMS;
      }
      if (width == 0) {
         break;
      }
      if (!startValue.ToLong(&start, 16)) {
         writeStatus("Illegal start address (entry #%d), \'%s\'\n", row+1, (const char *)startValue.c_str());
         return BDM_RC_ILLEGAL_PARAMS;
      }
      if (!endValue.ToLong(&end, 16)) {
         writeStatus("Illegal end address (entry #%d), \'%s\'\n", row+1, (const char *)endValue.c_str());
         return BDM_RC_ILLEGAL_PARAMS;
      }
      if (start>end) {
         writeStatus("Illegal range (entry #%d), [0x%06lX, 0x%06lX]\n", row+1, start, end);
         return BDM_RC_ILLEGAL_PARAMS;
      }
      char buff[100];
      snprintf(buff, sizeof(buff), "Doing block [0x%06lX, 0x%06lX]", start, end);
      progress->update(0, buff);
      progress->setRange(end-start);
      while (start <= end) {
         unsigned char data[4096];
         long int size = end-start+1;
         if (size>(long)sizeof(data)) {
            size = sizeof(data);
         }
         writeStatus("Reading memory-block[0x%06lX, 0x%06lX, %ld]...\n", start, start+size-1, width);
         USBDM_ErrorCode rc = bdmInterface->readMemory(width, size, start, data);
         progress->incrementalUpdate(size);
         if (rc != BDM_RC_OK) {
            return rc;
         }
         flashImage->loadData(size, start, data);
         start += size;
      }
   }
   return BDM_RC_OK;
}

void MemoryDumpDialogue::clearStatus() {
   statusText->Clear();
}

void MemoryDumpDialogue::writeStatus(const char *format, ...) {
   va_list list;
   if (statusText == NULL) {
      return;
   }
   if (format == NULL) {
      format = "error() - Error - empty format string!\n";
   }
   va_start(list, format);
   char buffer[1000];
   vsnprintf(buffer, sizeof(buffer), format, list);
   statusText->AppendText(wxString(buffer));
   va_end(list);
}

void MemoryDumpDialogue::loadSettings() {
   LOGGING_E;

   currentDirectory = appSettings->getValue("directory", "");
   currentFilename  = appSettings->getValue("filename", "");
   keepEmptySRECsCheckbox->SetValue(appSettings->getValue("keepEmptySRECs", false));

   for (int row = 0; row < memoryRangesGrid->GetRows(); row++) {
      long int start, end, width;

      char key[100];
      snprintf(key, sizeof(key), "dataWidth%d", row);
      width = appSettings->getValue(key, 0);
      wxString widthValue = wxString::Format("%ld", width);
      memoryRangesGrid->SetCellValue(widthValue, row, 2);
      wxString startValue;
      wxString endValue;
      if (width>0) {
         snprintf(key, sizeof(key), "dataStart%d", row);
         start = appSettings->getValue(key, 0);
         startValue = wxString::Format("%lX", start);

         snprintf(key, sizeof(key), "dataEnd%d", row);
         end = appSettings->getValue(key, 0);
         endValue = wxString::Format("%lX", end);
      }
      memoryRangesGrid->SetCellValue(startValue, row, 0);
      memoryRangesGrid->SetCellValue(endValue,   row, 1);
   }
   bdmInterface = BdmInterfaceFactory::createInterface(targetType);
   populateBDMChoices();
   populateInterfaceSpeeds();

   setTargetType((TargetType_t)appSettings->getValue("targetType", (int)T_ARM));
   setInterfaceSpeed(appSettings->getValue("interfaceSpeed", 250));
   setVdd((TargetVddSelect_t)appSettings->getValue("targetVdd", (int)BDM_TARGET_VDD_OFF));

   update();
}

void MemoryDumpDialogue::saveSettings() {
   LOGGING_E;
   appSettings->addValue("directory", currentDirectory);
   appSettings->addValue("filename", currentFilename);
   appSettings->addValue("keepEmptySRECs", keepEmptySRECsCheckbox->IsChecked());

   appSettings->addValue("targetType",       getTargetType());
   appSettings->addValue("targetVdd",        getVdd());
   appSettings->addValue("interfaceSpeed",   getInterfaceSpeed());

   for (int row = 0; row < memoryRangesGrid->GetRows(); row++) {
      long int start, end, width;
      wxString startValue = memoryRangesGrid->GetCellValue(row, 0);
      wxString endValue   = memoryRangesGrid->GetCellValue(row, 1);
      wxString widthValue = memoryRangesGrid->GetCellValue(row, 2);

      bool valid = true;
      if (startValue.IsEmpty() && endValue.IsEmpty() && widthValue.IsEmpty()) {
         valid = false;
      }
      if (!startValue.ToLong(&start, 16)) {
         valid = false;
      }
      endValue = memoryRangesGrid->GetCellValue(row,1);
      if (!endValue.ToLong(&end, 16)) {
         valid = false;
      }
      widthValue = memoryRangesGrid->GetCellValue(row,2);
      if (!widthValue.ToLong(&width) || ((width!=1) && (width!=2) && (width!=4))) {
         valid = false;
      }
      if (start>end) {
         valid = false;
      }
      char key[100];
      if (valid) {
         snprintf(key, sizeof(key), "dataStart%d", row);
         appSettings->addValue(key, start);
         snprintf(key, sizeof(key), "dataEnd%d", row);
         appSettings->addValue(key, end);
         snprintf(key, sizeof(key), "dataWidth%d", row);
         appSettings->addValue(key, width);
      }
      else {
         snprintf(key, sizeof(key), "dataWidth%d", row);
         appSettings->addValue(key, 0);
      }
   }
}

/*
 * Update general
 */
void MemoryDumpDialogue::update() {
   LOGGING;

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
      bdmDescriptionStaticControl->SetLabel(bdmIdentification);
      bdmInterface->setBdmSerialNumber(connectedBDMs[bdmDeviceNum].getSerialNumber(), true);
   }
   else {
      bdmCapabilities   = BDM_CAP_NONE;
      bdmIdentification = wxEmptyString;
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
   switch (targetType) {
   case T_ARM:
   case T_CFVx:
      interfaceSpeedControl->Enable(true);
      break;
   default:
      interfaceSpeedControl->Enable(false);
      break;
   }
}

void MemoryDumpDialogue::populateInterfaceSpeeds() {

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
//      if (bdmInterface->getBdmOptions().targetType == T_CFVx) {
//         connectionSpeedStaticTextWarning->SetLabel("Speed < Target Clock Frequency/5");
//      }
//      else {
//         connectionSpeedStaticTextWarning->Show(false);
//      }
      interfaceSpeedControl->Select(0);
   }
}

/*!
 *  Populate the BDM Choice box
 */
void MemoryDumpDialogue::populateBDMChoices(void) {
   LOGGING;

   // Enumerate all attached BDMs
   bdmInterface->findBDMs(connectedBDMs);
   if (connectedBDMs.empty()) {
      bdmDeviceNum = -1;
      bdmIdentification = wxEmptyString;
      log.print(" - no BDMs found\n");
   }
   int deviceCount = connectedBDMs.size();
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
   if (bdmDeviceNum >= deviceCount) {
      bdmDeviceNum = 0;
   }
   // Add device names to choice box, client data is device number from usb scan
   vector<BdmInformation>::iterator it;
   for ( it=connectedBDMs.begin(); it<connectedBDMs.end(); it++ ) {
      int index = bdmSelectChoiceControl->Append(wxString::FromUTF8(it->getSerialNumber().c_str()));
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

void MemoryDumpDialogue::OnBdmSelectComboSelected( wxCommandEvent& event ) {
   LOGGING_Q;
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

TargetVddSelect_t MemoryDumpDialogue::getVdd() {
   if (!targetVddControl->IsEnabled()) {
      return BDM_TARGET_VDD_OFF;
   }
   switch(targetVddControl->GetSelection()) {
      case 1  :    return BDM_TARGET_VDD_3V3;
      case 2  :    return BDM_TARGET_VDD_5V;
      case 0  :
      default :    return BDM_TARGET_VDD_OFF;
   }
}

void MemoryDumpDialogue::setVdd(TargetVddSelect_t targetVdd) {
   int selection;
   switch(targetVdd) {
      case BDM_TARGET_VDD_3V3: selection = 1; break;
      case BDM_TARGET_VDD_5V:  selection = 2; break;
      default :                selection = 0; break;
   }
   targetVddControl->SetSelection(selection);
}

unsigned MemoryDumpDialogue::getInterfaceSpeed() {
   return CFVx_Speeds[interfaceSpeedControl->GetSelection()].value;
}

void MemoryDumpDialogue::setInterfaceSpeed(signed speed) {
   int selection = 0;
   // Search the list
   for (int sub = 0; CFVx_Speeds[sub].value != 0; sub++) {
      if (CFVx_Speeds[sub].value == speed) {
         selection = sub;
         break;
      }
   }
   interfaceSpeedControl->SetSelection(selection);
}

void MemoryDumpDialogue::setTargetType(TargetType_t targetType) {

   int selection = 0;
   switch (targetType) {
   case T_RS08 :  selection++;
   //no break
   case T_HC12 :  selection++;
   //no break
   case T_HCS08 : selection++;
   //no break
   case T_CFVx :  selection++;
   //no break
   case T_CFV1 :  selection++;
   //no break
   case T_ARM :
   default: break;
   }
   bdmInterface.reset();
   bdmInterface = BdmInterfaceFactory::createInterface(targetType);
   populateBDMChoices();
   targetTypeRadioBox->SetSelection(selection);
}

TargetType_t MemoryDumpDialogue::getTargetType() {
   static const TargetType_t targetTypes[] = {
      T_ARM, T_CFV1, T_CFVx, T_HCS08, T_HCS12, T_RS08,
   };
   return (targetTypes[targetTypeRadioBox->GetSelection()]);
}

//static int searchDropDown(const DropDownType information[], int value) {
//int sub;
//
//   // Search the list
//   for (sub = 0; information[sub].value != 0; sub++)
//      if (information[sub].value == value)
//         return sub;
//   return -1;
//}


void MemoryDumpDialogue::OnTargetVddControlClick( wxCommandEvent& event ) {
}

/*! Handler for OnSpeedSelectCombo
 *
 *  @param event The event to handle
 */
void MemoryDumpDialogue::OnInterfaceSpeedSelectComboSelected( wxCommandEvent& event ) {
}
