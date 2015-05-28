/*
 * MemoryDumpDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include <stdio.h>

#include <wx/filedlg.h>

#include "MemoryDumpDialogue.h"
#include "UsbdmSystem.h"
#include "Names.h"

//! Maximum size of a S-record, should be power of 2
const int maxSrecSize = (1<<4);

MemoryDumpDialogue::MemoryDumpDialogue(wxWindow* parent) :
   MemoryDumpDialogueSkeleton(parent),
   targetType(T_ARM) {
   memoryRangesGrid->SetColFormatNumber(0);
   memoryRangesGrid->SetColFormatNumber(1);
}

MemoryDumpDialogue::~MemoryDumpDialogue() {
   LOGGING;
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

   wxString caption  = _("Select save location for binary file");
   wxString wildcard = _("SREC Hex files (*.s19,*.sx,*.s)|*.s19;*.sx;*.s|"
                         "All Files|*");
   wxString defaultFilename = wxEmptyString;
   wxFileDialog dialog(this, caption, currentDirectory, defaultFilename, wildcard, wxFD_OPEN);
   int getCancelOK = dialog.ShowModal();
   if (getCancelOK != wxID_OK) {
      return;
   }
   currentDirectory = dialog.GetDirectory();

   wxString customPath = dialog.GetPath();
   log.print("customPath     = \'%s\'\n", (const char *)customPath.c_str());
}

void MemoryDumpDialogue::OnReadMemoryButtonClick( wxCommandEvent& event ) {
   LOGGING;

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
      rc = readMemoryBlock(0x0000, 0x1000);
      if (rc != BDM_RC_OK) {
         break;
      }
   } while (0);
   if (rc != BDM_RC_OK) {
      writeStatus("Failed, reason = %s\n", bdmInterface->getErrorString(rc));
   }
}

USBDM_ErrorCode MemoryDumpDialogue::readMemoryBlock(uint32_t address, uint32_t size) {
   unsigned char data[size];

   writeStatus("Reading memory[0x%08X..0x%08X]\n", address, address+size-1);
   USBDM_ErrorCode rc = bdmInterface->readMemory(MS_Byte, size, address, data);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   flashImage->loadData(size, address, data);
   return BDM_RC_OK;
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

//! Dump a single S-record to stdout
//!
//! @param file     file handle for writes
//! @param buffer   location of data to dump
//! @param address  base address of data
//! @param size     number of bytes to dump
//!
//! @note size must be less than or equal to \ref maxSrecSize
//! @note S-records filled with 0xFF are discarded
//!
void MemoryDumpDialogue::dumpSrec(FILE *file, uint8_t *buffer, uint32_t address, unsigned size) {

   // Discard 0xFF filled records (blank Flash)
   bool allFF = true;
   for(unsigned sub=0; sub<size; sub++) {
      if (buffer[sub] != 0xFF ) {
         allFF = false;
         break;
      }
   }
   if ((size == 0) || allFF) {
      return;
   }
   uint8_t *ptr = buffer;
   uint8_t checkSum;
   if ((address) < 0x10000U) {
      fprintf(file, "S1%02X%04X", size+3, address);
      checkSum = size+3;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   else if (address < 0x1000000U) {
      fprintf(file, "S2%02X%06X", size+4, address);
      checkSum = size+4;
      checkSum += (address>>16)&0xFF;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   else {
      fprintf(file, "S3%02X%08X", size+5, address);
      checkSum = size+5;
      checkSum += (address>>24)&0xFF;
      checkSum += (address>>16)&0xFF;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   while (size-->0) {
      checkSum += *ptr;
      fprintf(file, "%02X", *ptr++);
   }
   checkSum = checkSum^0xFF;
   fprintf(file, "%02X\n", checkSum);
}

//! Dump data as S-records to stdout
//!
//! @param file     file handle for writes
//! @param buffer   location of data to dump
//! @param address  base address of data
//! @param size     number of bytes to dump
//!
//! @note Regions filled with 0xFF are discarded
//!
void MemoryDumpDialogue::dump(FILE *file, uint8_t *buffer, uint32_t address, unsigned size) {
   while (size>0) {
      uint8_t oddBytes = address & (maxSrecSize-1);
      uint8_t srecSize = maxSrecSize - oddBytes;
      if (srecSize > size) {
         srecSize = (uint8_t) size;
      }
      dumpSrec(file, buffer, address, srecSize);
      address += srecSize;
      buffer  += srecSize;
      size    -= srecSize;
   }
}
