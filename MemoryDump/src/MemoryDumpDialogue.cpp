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

//! Maximum size of a S-record, should be power of 2
const int maxSrecSize = (1<<4);

MemoryDumpDialogue::MemoryDumpDialogue(wxWindow* parent, AppSettingsPtr appSettings) :
   MemoryDumpDialogueSkeleton(parent),
   targetType(T_ARM),
   appSettings(appSettings)
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

static const TargetType_t targetTypes[] = {
   T_ARM, T_CFV1, T_CFVx, T_HCS08, T_HCS12, T_RS08,
};

void MemoryDumpDialogue::OnTargetTypeRadioBox( wxCommandEvent& event ) {
   LOGGING;

   targetType = targetTypes[targetTypeRadioBox->GetSelection()];
   log.print("Selected target type = %s\n", getTargetTypeName(targetType));
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
   flashImage->saveFile(filePath);
}

void MemoryDumpDialogue::OnReadMemoryButtonClick( wxCommandEvent& event ) {
   LOGGING;

   clearStatus();

   writeStatus("Creating Empty flash image...\n");
   flashImage = FlashImageFactory::createFlashImage(targetType);

   writeStatus("Creating %s BDM interface...\n", getTargetTypeName(targetType));
   bdmInterface.reset();
   bdmInterface = BdmInterfaceFactory::createInterface(targetType);

   writeStatus("Changing interface options...\n");
   USBDM_ExtendedOptions_t &bdmOptions(bdmInterface->getBdmOptions());
   bdmOptions.targetVdd = BDM_TARGET_VDD_3V3;

   USBDM_ErrorCode rc = BDM_RC_OK;
   do {
      rc = bdmInterface->initBdm();
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
      rc = readMemoryBlocks();
      if (rc != BDM_RC_OK) {
         break;
      }
   } while (0);
   if (rc != BDM_RC_OK) {
      writeStatus("Failed, reason = %s\n", bdmInterface->getErrorString(rc));
      flashImage.reset();
   }
   saveToFileButton->Enable((flashImage != 0) && !flashImage->isEmpty());
   bdmInterface.reset();
   writeStatus("Done\n");
}

struct MemoryRange {
   uint32_t start;
   uint32_t end;
};

USBDM_ErrorCode MemoryDumpDialogue::readMemoryBlocks() {
   for (int row = 0; row < memoryRangesGrid->GetRows(); row++) {
      long int start, end, width;
      wxString startValue = memoryRangesGrid->GetCellValue(row,0);
      wxString endValue   = memoryRangesGrid->GetCellValue(row,0);
      wxString widthValue = memoryRangesGrid->GetCellValue(row,0);

      if (startValue.IsEmpty() && endValue.IsEmpty() && widthValue.IsEmpty()) {
         continue;
      }
      if (!startValue.ToLong(&start, 16)) {
         writeStatus("Illegal start address (entry #%d), \'%s\'\n", row+1, (const char *)startValue.c_str());
         return BDM_RC_ILLEGAL_PARAMS;
      }
      endValue = memoryRangesGrid->GetCellValue(row,1);
      if (!endValue.ToLong(&end, 16)) {
         writeStatus("Illegal end address (entry #%d), \'%s\'\n", row+1, (const char *)endValue.c_str());
         return BDM_RC_ILLEGAL_PARAMS;
      }
      widthValue = memoryRangesGrid->GetCellValue(row,2);
      if (!widthValue.ToLong(&width) || ((width!=1) && (width!=2) && (width!=4))) {
         writeStatus("Illegal width (entry #%d), \'%s\'\n", row+1, (const char *)widthValue.c_str());
         return BDM_RC_ILLEGAL_PARAMS;
      }
      if (start>end) {
         writeStatus("Illegal range (entry #%d), [0x%06lX, 0x%06lX]\n", row+1, start, end);
         return BDM_RC_ILLEGAL_PARAMS;
      }
      unsigned int size = end-start+1;
      unsigned char data[size];
      writeStatus("Reading memory[0x%06lX, 0x%06lX, %ld]...\n", start, end, width);
      USBDM_ErrorCode rc = bdmInterface->readMemory(width, size, start, data);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      flashImage->loadData(size, start, data);
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
   int targetSelection = appSettings->getValue("targetType", T_ARM);
   targetTypeRadioBox->SetSelection(targetSelection);
   targetType = targetTypes[targetSelection];
   for (int row = 0; row < memoryRangesGrid->GetRows(); row++) {
      long int start, end, width;

      char key[100];
      snprintf(key, sizeof(key), "dataWidth%d", row);
      width = appSettings->getValue(key, 0);
      wxString widthValue = wxString::Format("%d", width);
      memoryRangesGrid->SetCellValue(widthValue, row, 2);
      wxString startValue;
      wxString endValue;
      if (width>0) {
         snprintf(key, sizeof(key), "dataStart%d", row);
         start = appSettings->getValue(key, 0);
         startValue = wxString::Format("%X", start);

         snprintf(key, sizeof(key), "dataEnd%d", row);
         end = appSettings->getValue(key, 0);
         endValue = wxString::Format("%X", end);
      }
      memoryRangesGrid->SetCellValue(startValue, row, 0);
      memoryRangesGrid->SetCellValue(endValue,   row, 1);
   }
}

void MemoryDumpDialogue::saveSettings() {
   LOGGING_E;
   appSettings->addValue("targetType", targetTypeRadioBox->GetSelection());
   appSettings->addValue("directory", currentDirectory);
   appSettings->addValue("filename", currentFilename);
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


