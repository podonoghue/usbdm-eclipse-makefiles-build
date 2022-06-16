/*
 * MemoryDumpDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include "MemoryDumpDialogue.h"

#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/tokenzr.h>

#include "ProgressDialogueFactory.h"

#include <stdio.h>

#include "UsbdmSystem.h"
#include "Names.h"
#include "HexNumberGridEditor.h"
#include "FlashProgrammer.h"

using namespace std;

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
         fAppSettings(appSettings),
         bdmDeviceNum(-1),
         bdmCapabilities(BDM_CAP_NONE),
         hcs08PPageAddress(0x08),
         hcs12PPageAddress(0x30),
         hcs12EPageAddress(0x17)
{
   LOGGING;

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
   saveSettings(fAppSettings);
}

int  MemoryDumpDialogue::ShowModal() {
   loadSettings(fAppSettings);
   int rc = MemoryDumpDialogueSkeleton::ShowModal();
   saveSettings(fAppSettings);
   return rc;
}
/**
 * Radiobox for target has changed
 */
void MemoryDumpDialogue::OnTargetTypeRadioBoxSelect( wxCommandEvent& event ) {
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

   bdmInterface->getBdmOptions().targetVdd = getVdd();
   bdmInterface->getBdmOptions().interfaceFrequency = getInterfaceSpeed();

   if (targetType == T_ARM) {
      bdmInterface->getBdmOptions().interfaceFrequency = 12000;
   }
   writeStatus("Interface options: %s, %s, speed = %d\n",
         getTargetTypeName(bdmInterface->getBdmOptions().targetType),
         getVoltageSelectName(bdmInterface->getBdmOptions().targetVdd),
         bdmInterface->getBdmOptions().interfaceFrequency);

   USBDM_ErrorCode rc = BDM_RC_OK;
   do {
      rc = bdmInterface->initBdm();
      if (rc != BDM_RC_OK) {
         break;
      }
      // Disable to read on-chip memory rather than target
      // Requires modified programmer firmware.
#if 1
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
      rc = doTargetInitializationString();
      if (rc != BDM_RC_OK) {
         break;
      }
#endif
      rc = readMemoryBlocks(ProgressDialogueFactory::create("Accessing Target", 100, this));
      if (rc != BDM_RC_OK) {
         break;
      }
   } while (0);
   bdmInterface->closeBdm();
   if (rc != BDM_RC_OK) {
      wxMessageBox(bdmInterface->getErrorString(rc), "Operation Failed", wxICON_ERROR | wxOK, this);
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

/**
 * Processes the target initialization string
 * e.g. (address, data, data...)*
 *
 *
 */
USBDM_ErrorCode MemoryDumpDialogue::doTargetInitializationString() {
   bool doTargetInit = initializationCheckbox->IsEnabled() && initializationCheckbox->GetValue();
   if (!doTargetInit) {
      return BDM_RC_OK;
   }
   writeStatus("Doing custom initialization...\n");

   wxStringTokenizer tokenizer(initialializeTextCntrl->GetValue(), "()", wxTOKEN_STRTOK);

   wxString token = tokenizer.GetNextToken();
   do  {
      wxStringTokenizer subTokenizer(token, ",", wxTOKEN_STRTOK);
      wxString subToken = subTokenizer.GetNextToken();
      long address;
      if ((subToken.IsEmpty()) || !subToken.ToLong(&address, 16)) {
         return BDM_RC_ILLEGAL_PARAMS;
      }
      subToken = subTokenizer.GetNextToken();
      do {
         long lData;
         if (!subToken.ToLong(&lData, 16) || ((lData&~0xFF) != 0)) {
            return BDM_RC_ILLEGAL_PARAMS;
         }
         uint8_t data = (uint8_t)lData;
         writeStatus("  WriteMemory(0x%04lX, 0x%02X)\n", address, data);
         bdmInterface->writeMemory(1, 1, address++, &data);
         subToken = subTokenizer.GetNextToken();
      } while (!subToken.IsEmpty());
      token = tokenizer.GetNextToken();
   } while (!token.IsEmpty());
   return BDM_RC_OK;
}
/**
 * Read memory
 *
 * @param progress Progress dialogue to display
 */
USBDM_ErrorCode MemoryDumpDialogue::readMemoryBlocks(ProgressDialoguePtr progress) {
   LOGGING;

   // HCS12 paging
   constexpr long flashStart       = 0x8000;
   constexpr long flashEnd         = 0xBFFF;

   constexpr long eepromStart      = 0x0800;
   constexpr long eepromEnd        = 0x0BFF;

   static const auto pageNum = [](long address) {
      return (address>>16)&0xFF;
   };

   static const auto pageOffset = [](long address) {
      return address&0xFFFF;
   };

   // Check for paging
   long ppageRegAddress = 0;
   long epageRegAddress = 0;
   bool isFlashPaged    = false;
   bool isEepromPaged   = false;

   if (isPagedDevice()) {
      if (pagedFlashAddressCheckBox->GetValue()){
         isFlashPaged = true;

         // Get current page value
         flashPageTextCntrl->GetValue().ToLong(&ppageRegAddress, 16);
         writeStatus("Using paged flash addresses (PPAGE address=0x%02lx)\n", ppageRegAddress);

      }
      if (pagedEepromAddressCheckBox->GetValue()){
         isEepromPaged = true;

         // Get current page value
         eepromPageTextCntrl->GetValue().ToLong(&epageRegAddress, 16);
         writeStatus("Using paged eeprom addresses (EPAGE address=0x%02lx)\n", epageRegAddress);
      }
   }

   USBDM_ErrorCode final_rc = BDM_RC_OK;

   // Process each row of table [start, end, width]
   for (int row = 0; row < memoryRangesGrid->GetNumberRows(); row++) {

      long int start, end, width;
      wxString startValue = memoryRangesGrid->GetCellValue(row,0);
      wxString endValue   = memoryRangesGrid->GetCellValue(row,1);
      wxString widthValue = memoryRangesGrid->GetCellValue(row,2);

      if (startValue.IsEmpty() && endValue.IsEmpty() && widthValue.IsEmpty()) {
         // Skip empty rows
         continue;
      }
      // Validate width
      if (!widthValue.ToLong(&width) || ((width!=0) && (width!=1) && (width!=2) && (width!=4))) {
         writeStatus("Illegal width (entry #%d), \'%s\'\n", row+1, (const char *)widthValue.c_str());
         return BDM_RC_ILLEGAL_PARAMS;
      }
      if (width == 0) {
         // Skip disabled rows
         continue;
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

      // Check if paged address etc.

      bool rangeIsPagedFlash  = false;
      bool rangeIsPagedEeprom = false;

      USBDM_ErrorCode rc = BDM_RC_OK;
      if (isFlashPaged && (pageOffset(start)<=flashEnd) && (pageOffset(end)>=flashStart)) {
         // Range crosses flash paging window

         // Check range lies within a single page
         if ((pageNum(start) != pageNum(end)) || (pageOffset(start)<flashStart) || (pageOffset(end)>flashEnd)) {
            writeStatus("Illegal paged range (entry #%d), [0x%06lX, 0x%06lX]\n"
                  "Range must lie within a single Flash page\n", row+1, start, end);
            return BDM_RC_ILLEGAL_PARAMS;
         }

         // Write PPAGE register
         unsigned char page = pageNum(start);
         writeStatus("Writing PPAGE(0x%04lX) = 0x%02X\n", ppageRegAddress, page);
         rc = bdmInterface->writeMemory(1, 1, ppageRegAddress, &page);
         rangeIsPagedFlash = true;
      }
      else if (isEepromPaged && (pageOffset(start)<=eepromEnd) && (pageOffset(end)>=eepromStart)) {
         // Range crosses eeprom paging window

         // Check range lies within a single page
         if (((pageNum(start)) != (pageNum(end))) || (pageOffset(start)<eepromStart) || (pageOffset(end)>eepromEnd)) {
            writeStatus("Illegal paged range (entry #%d), [0x%06lX, 0x%06lX]\n"
                  "Range must lie within a single EEPROM page\n", row+1, start, end);
            return BDM_RC_ILLEGAL_PARAMS;
         }

         // Write EPAGE register
         unsigned char page = pageNum(start);
         writeStatus("Writing EPAGE(0x%04lX) = 0x%02X\n", epageRegAddress, page);
         rc = bdmInterface->writeMemory(1, 1, epageRegAddress, &page);
         rangeIsPagedEeprom = true;
      }
      else if (isFlashPaged || isEepromPaged) {
         // Make sure it is not a paged address
         if (pageNum(start) != 0) {
            writeStatus("Illegal paged range (entry #%d), [0x%06lX, 0x%06lX]\n"
                  "Paging must be selected and paged ranges must lie within a paging window\n", row+1, start, end);
            return BDM_RC_ILLEGAL_PARAMS;
         }
      }
      if (rc != BDM_RC_OK) {
         return rc;
      }

      // Process range as series of blocks [start..end]
      while (start <= end) {

         // Buffer for memory block read
         unsigned char data[4096];

         // Calculate size of this block read
         long int size = end-start+1;
         if (size > (long)sizeof(data)) {
            size = sizeof(data);
         }

         if (rangeIsPagedFlash || rangeIsPagedEeprom) {
            // Paged Flash
            int page = pageNum(start);
            long int pagedStart = pageOffset(start);
            long int pagedEnd   = pagedStart+size-1;
            size = pagedEnd-pagedStart+1;
            writeStatus("Reading memory-block[0x%02X:%04lX, 0x%02X:%04lX, %ld]...\n", page, pagedStart, page, pagedStart+size-1, width);
            rc = bdmInterface->readMemory(width, size, pagedStart, data);
         }
         else {
            // Flat memory or non-paged range
            writeStatus("Reading memory-block[0x%06lX, 0x%06lX, %ld]...\n", start, start+size-1, width);
            rc = bdmInterface->readMemory(width, size, start, data);
         }
         progress->incrementalUpdate(size);
         if (rc != BDM_RC_OK) {
            return rc;
         }
         rc = flashImage->loadDataBytes(size, start, data, FlashImage::OverwriteAndReport);
         if ((rc != BDM_RC_OK) && (rc != SFILE_RC_IMAGE_OVERLAPS)) {
            return rc;
         }
         if (rc != BDM_RC_OK) {
            // Record soft error
            final_rc = rc;
         }
         start += size;
      }
   }
   return final_rc;
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

void MemoryDumpDialogue::loadSettings(AppSettings &appSettings) {
   LOGGING;
   hcs08PPageAddress = appSettings.getValue("hcs08PPageAddress", 0x08);
   hcs12PPageAddress = appSettings.getValue("hcs12PPageAddress", 0x30);
   hcs12EPageAddress = appSettings.getValue("hcs12EPageAddress", 0x17);

   currentDirectory = appSettings.getValue("directory", "");
   currentFilename  = appSettings.getValue("filename", "");

   currentSettingsDirectory = appSettings.getValue("settingsDirectory", "");
   currentSettingsFilename  = appSettings.getValue("settingsFilename", "");

   keepEmptySRECsCheckbox->SetValue(         appSettings.getValue("keepEmptySRECs", false));
   pagedFlashAddressCheckBox->SetValue(      appSettings.getValue("pagedFlash", false));
   pagedEepromAddressCheckBox->SetValue(     appSettings.getValue("pagedEeprom", false));

   initializationCheckbox->SetValue(         appSettings.getValue("initializeTarget", false));
   initialializeTextCntrl->SetValue(wxString(appSettings.getValue("initializationString", "")));

   for (int row = 0; row < memoryRangesGrid->GetNumberRows(); row++) {
      long int start, end, width;

      char key[100];
      snprintf(key, sizeof(key), "dataWidth%d", row);
      width = appSettings.getValue(key, 0);
      wxString widthValue = wxString::Format("%ld", width);
      memoryRangesGrid->SetCellValue(row, 2, widthValue);
      wxString startValue;
      wxString endValue;
      if (width>0) {
         snprintf(key, sizeof(key), "dataStart%d", row);
         start = appSettings.getValue(key, 0);
         startValue = wxString::Format("%lX", start);

         snprintf(key, sizeof(key), "dataEnd%d", row);
         end = appSettings.getValue(key, 0);
         endValue = wxString::Format("%lX", end);
      }
      memoryRangesGrid->SetCellValue(row, 0, startValue);
      memoryRangesGrid->SetCellValue(row, 1, endValue);
   }

   setTargetType((TargetType_t)appSettings.getValue("targetType", (int)T_ARM));

   populateBDMChoices();
   populateInterfaceSpeeds();

   setInterfaceSpeed(appSettings.getValue("interfaceSpeed", 250));
   setVdd((TargetVddSelect_t)appSettings.getValue("targetVdd", (int)BDM_TARGET_VDD_OFF));

   update();
}

void MemoryDumpDialogue::saveSettings(AppSettings &appSettings) {
   LOGGING_E;

   appSettings.addValue("pageAddress", flashPageTextCntrl->GetValue());

   appSettings.addValue("directory", currentDirectory);
   appSettings.addValue("filename", currentFilename);

   appSettings.addValue("settingsDirectory", currentSettingsDirectory);
   appSettings.addValue("settingsFilename", currentSettingsFilename);

   appSettings.addValue("keepEmptySRECs", keepEmptySRECsCheckbox->IsChecked());

   appSettings.addValue("targetType",       getTargetType());
   appSettings.addValue("targetVdd",        getVdd());
   appSettings.addValue("interfaceSpeed",   getInterfaceSpeed());
   appSettings.addValue("pagedFlash",       pagedFlashAddressCheckBox->GetValue());
   appSettings.addValue("pagedEeprom",      pagedEepromAddressCheckBox->GetValue());

   for (int row = 0; row < memoryRangesGrid->GetNumberRows(); row++) {
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
         appSettings.addValue(key, start);
         snprintf(key, sizeof(key), "dataEnd%d", row);
         appSettings.addValue(key, end);
         snprintf(key, sizeof(key), "dataWidth%d", row);
         appSettings.addValue(key, width);
      }
      else {
         snprintf(key, sizeof(key), "dataWidth%d", row);
         appSettings.addValue(key, 0);
      }
   }
   // Save current page value
   long currentValue;
   if (flashPageTextCntrl->GetValue().ToLong(&currentValue, 16)) {
      switch(this->targetType) {
         case T_HCS08 :
            hcs08PPageAddress = currentValue;
            break;
         case T_HCS12 :
            hcs12PPageAddress = currentValue;
            break;
         default: break;
      }
   }
   if (eepromPageTextCntrl->GetValue().ToLong(&currentValue, 16)
         && (this->targetType == T_HCS12)) {
      hcs12EPageAddress = currentValue;
   }
   appSettings.addValue("hcs08PPageAddress", hcs08PPageAddress);
   appSettings.addValue("hcs12PPageAddress", hcs12PPageAddress);
   appSettings.addValue("hcs12EPageAddress", hcs12EPageAddress);
   appSettings.addValue("initializeTarget", initializationCheckbox->GetValue());
   appSettings.addValue("initializationString", initialializeTextCntrl->GetValue());
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
   bool pagedFlashAddressMode = isPagedDevice() && pagedFlashAddressCheckBox->GetValue();
   flashPageRegisterStaticText->Enable(pagedFlashAddressMode);
   flashPageTextCntrl->Enable(pagedFlashAddressMode);

   if (targetType == T_HCS12) {
      bool pagedEepromAddressMode = isPagedDevice() && pagedEepromAddressCheckBox->GetValue();
      eepromPageRegisterStaticText->Enable(pagedEepromAddressMode);
      eepromPageTextCntrl->Enable(pagedEepromAddressMode);
   }
   else {
//      pagedEepromAddressCheckBox->Disable();
      eepromPageRegisterStaticText->Disable();
      eepromPageTextCntrl->Disable();
   }

   bool doTargetInit = initializationCheckbox->IsEnabled() && initializationCheckbox->GetValue();
   initialializeTextCntrl->Enable(doTargetInit);

   populateInterfaceSpeeds();
}

void MemoryDumpDialogue::populateInterfaceSpeeds() {
   LOGGING;
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
      log.print(" - no BDMs found\n");
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
      case T_S12Z :  selection++;
      //no break
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
   // Save current page value
   long currentPPageAddress = 0;
   if (flashPageTextCntrl->GetValue().ToLong(&currentPPageAddress, 16)) {
      switch(this->targetType) {
         case T_HCS08 :
            hcs08PPageAddress = currentPPageAddress;
            break;
         case T_HCS12 :
            hcs12PPageAddress = currentPPageAddress;
            break;
         default: break;
      }
   }
   long currentEPageAddress = 0;
   if (eepromPageTextCntrl->GetValue().ToLong(&currentEPageAddress, 16)
         && (this->targetType == T_HCS12)) {
      hcs12EPageAddress = currentEPageAddress;
   }
   this->targetType = targetType;

   // Update page values
   switch(targetType) {
      case T_HCS08 :
         currentPPageAddress = hcs08PPageAddress;
         break;
      case T_HCS12 :
         currentPPageAddress = hcs12PPageAddress;
         currentEPageAddress = hcs12EPageAddress;
         break;
      default: break;
   }
   flashPageTextCntrl->SetValue(wxString::Format("%lX", currentPPageAddress));
   eepromPageTextCntrl->SetValue(wxString::Format("%lX", currentEPageAddress));

   bool enableSpeedControl = (targetType == T_ARM) || (targetType == T_CFVx);
   bdmInterface = BdmInterfaceFactory::createInterface(targetType);
   targetTypeRadioBox->SetSelection(selection);
   pagedFlashAddressCheckBox->Enable(isPagedDevice());
   pagedEepromAddressCheckBox->Enable((targetType == T_HCS12));
   interfaceSpeedControl->Enable(enableSpeedControl);
   populateInterfaceSpeeds();
}

bool MemoryDumpDialogue::isPagedDevice() {
   return (targetType == T_HCS08)||(targetType == T_HCS12);
}

TargetType_t MemoryDumpDialogue::getTargetType() {
   static const TargetType_t targetTypes[] = {
         T_ARM, T_CFV1, T_CFVx, T_HCS08, T_HCS12, T_RS08, T_S12Z,
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

/*! Handler for OnInitializationCheckboxChange Checkbox
 *
 *  @param event The event to handle
 */
void MemoryDumpDialogue::OnInitializationCheckboxChange( wxCommandEvent& event ) {
   update();
}

void MemoryDumpDialogue::OnPagedCheckBoxEvent( wxCommandEvent& event ) {
   update();
}

/*! Handler for OnPageAddressChange
 *
 *  @param event The event to handle
 */
void MemoryDumpDialogue::OnPageAddressChange( wxCommandEvent& event ) {
}

void MemoryDumpDialogue::OnLoadSettingsClick(wxCommandEvent &event) {
   LOGGING;

   wxString caption  = _("Select location for range settings");
   wxString wildcard = _("Settings|*.cfg");
   wxFileDialog dialog(this, caption, currentSettingsDirectory, currentSettingsFilename, wildcard, wxFD_OPEN);
   int getCancelOK = dialog.ShowModal();
   if (getCancelOK != wxID_OK) {
      return;
   }
   string filePath(dialog.GetPath());
   log.print("Custom range settings path     = \'%s\'\n", (const char *)filePath.c_str());

   AppSettings appSettings(filePath, "Range Settings");
   appSettings.load();
   loadSettings(appSettings);

   // Done here in case settings include these values
   currentSettingsDirectory = dialog.GetDirectory();
   currentSettingsFilename  = dialog.GetFilename();
}

void MemoryDumpDialogue::OnSaveSettingsClick(wxCommandEvent &event) {
   LOGGING;

   wxString caption  = _("Select save location for range settings");
   wxString wildcard = _("Settings|*.cfg");
   wxFileDialog dialog(this, caption, currentSettingsDirectory, currentSettingsFilename, wildcard, wxFD_SAVE);
   int getCancelOK = dialog.ShowModal();
   if (getCancelOK != wxID_OK) {
      return;
   }
   currentSettingsDirectory = dialog.GetDirectory();
   currentSettingsFilename  = dialog.GetFilename();
   string filePath(dialog.GetPath());
   log.print("Custom settings path     = \'%s\'\n", (const char *)filePath.c_str());

   AppSettings appSettings(filePath, "Range Settings");
   saveSettings(appSettings);
   appSettings.save();
}
