/*! \file
   \brief Bootloader for JS16/JMxx USBDMs

   \verbatim
   USBDM Bootloader
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
+=========================================================================================
| 10 Apr 2012 | Added drivers warnings to dialogues                           - pgo v4.9.5
| 26 Feb 2012 | Added manual reboot prompt on second reboot                   - pgo v4.9.3
| 16 Feb 2012 | Added Tower_CFVx version                                      - pgo v4.9
| 25 Jan 2012 | Added autoupdate option                                       - pgo v4.9
| 11 Aug 2011 | Changed polling sleep length during reboot & updates dialogue - pgo v4.7
| 11 Aug 2011 | Correctly handles device already in ICP mode                  - pgo v4.7
| 11 Aug 2011 | Progress dialogues modified using call-backs                  - pgo v4.7
|  1 Aug 2010 | Rewritten for Linux                                           - pgo
+=========================================================================================
\endverbatim
 */
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/cmdline.h>
#include <wx/stdpaths.h>

#include "AppSettings.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include <stdio.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/strconv.h>
#include <wx/progdlg.h>
#endif

#include <time.h>
#include <string.h>
using namespace std;
#include "USBDM_API.h"
#include "FirmwareChanger.h"
#include "Names.h"
#include "UsbdmSystem.h"
#include "NumberTextEditCtrl.h"
#include "Common.h"
#include "Utils.h"
#include "ProgressDialogueFactory.h"

const char *logFilename("FirmwareChanger.log");
const char *configFileName("FirmwareChanger.cfg");

#ifdef LOG
// Define to cause flash verification to run multiple times in loop
// This only reboots the BDM once and does multiple verifies in ICP mode
//#define DEBUG_VER

// Define to cause the entire verify sequence to run multiple times.
// This involves: reboot-to-ICP, (optional)verify & normal reboot
//#define DEBUG_REBOOT 1000

#ifdef DEBUG_REBOOT
// Define the following to suppress verification code in above debug loop
#define DONT_VERIFY
#endif

#endif

enum {
   FLASH_ERR_OK             = 0,
   CMD_LINE_OK              = 0,
   FLASH_ERR_FAIL           = 1,
   CMD_LINE_ILLEGAL_PARAMS  = 2,
   CMD_LINE_ILLEGAL_COMMAND = 3,
   FLASH_ERR_CANCEL         = 4,
};

/*!
 * Converts a UTF-16-LE to a wxString
 *
 * @param str - the string to convert
 *
 * @return str converted to a wxString
 *
 */
static wxString convertUtfToString(const char *str) {
   wxMBConvUTF16LE converter;
   wchar_t unicodeBuff[200];
   converter.MB2WC(unicodeBuff, str, sizeof(unicodeBuff));
   return wxString(unicodeBuff);
}

/*!
 * Converts a wxString to a UTF-16-LE
 *
 * @param str - the string to convert
 *
 * @return str converted to a UTF-16-LE (in static buffer)
 *
 */
const char *convertStringToUtf(const wxString &str) {
   wxMBConvUTF16LE converter;
   static char utfBuffer[200];
   converter.WC2MB((char*)utfBuffer, (const wchar_t*)str, sizeof(utfBuffer));
   return utfBuffer;
}

//! Parses Filename
//!
const char *File_ParseTitle(char *Filename, char *Title, int MaxTitle) {
   return "A Title";
}

void FirmwareChangerDialogue::dumpFile() {
   LOGGING_Q;

   uint32_t addr;

   for (addr = flashImageDescription.firstAddr; addr < flashImageDescription.lastAddr; addr++) {
      if (((addr & 0x001F) == 0) || (addr == flashImageDescription.firstAddr))
         log.print("%4.4X:", addr);
      log.print("%2.2X", flashImage->getValue(addr));
      if (((addr & 0x001FU) == 0x1FU) && (addr != flashImageDescription.lastAddr-1U))
         log.print("\n");
   }
   log.print("\n");
}

//! Changes serial number in Flash image
//!
//! @param serialNumber - New serial number for device
//!
//!
void FirmwareChangerDialogue::setSerialNumber(const wxString &serialNumber) {
   LOGGING;

   if (!flashImageDescription.serialNumberPresent) {
      return;
   }
   uint8_t  ICP_Offset       = flashImage->getValue(flashImageDescription.protectAddr-2);         // Offset to end of ICP block
   uint16_t ICP_Address      = flashImageDescription.protectAddr-ICP_Offset-sizeof(ICP_dataType); // Address of ICP block
   uint16_t SN_Address       = ICP_Address + (intptr_t)&ICP_data.serialNumber - (intptr_t)&ICP_data;
   uint16_t Checksum_Address = flashImageDescription.protectAddr-1;

   // Patch image with serial #
   uint8_t buff[sizeof(ICP_data.serialNumber)+1];
   strncpy((char*)buff, serialNumber.ToUTF8(), sizeof(ICP_data.serialNumber));
   flashImage->loadData(sizeof(ICP_data.serialNumber), SN_Address, buff);

   // Fix checksum
   uint8_t checkSum = 0;
   for (int addr = ICP_data.flashStart; addr < Checksum_Address; addr++) {
      checkSum += flashImage->getValue(addr);
   }
   log.print("Serial # address  = 0x%4X\n", SN_Address);
   log.print("Checksum          = 0x%2X\n", checkSum);
   log.print("Original checksum = 0x%2X\n", flashImage->getValue(Checksum_Address));

   flashImage->setValue(Checksum_Address, checkSum);
   flashImageDescription.serialNumber = serialNumber;
}

//! Runs consistency check on the Flash image file
//!
//! @param protectAddress address of protected area of Flash
//!
//! @return success/fail
//!
bool FirmwareChangerDialogue::consistencyCheck(unsigned int protectAddress) {
   LOGGING;

   uint8_t  ICP_Offset  = flashImage->getValue(protectAddress-2);         // Offset to end of ICP block
   uint16_t ICP_Address = protectAddress-ICP_Offset-sizeof(ICP_dataType); // Address of ICP block

   // Copy ICP data from flash image

   uint8_t buff[sizeof(ICP_dataType)];
   for (unsigned index=0; index<sizeof(ICP_dataType); index++) {
      buff[index] = flashImage->getValue(ICP_Address+index);
   }
   memcpy(&ICP_data, buff, sizeof(ICP_data));

   // Swap Endian
   ICP_data.flashStart        = ((ICP_data.flashStart<<8) & 0xFF00) +
         ((ICP_data.flashStart>>8) & 0x00FF);
   ICP_data.userDetectICP     = ((ICP_data.userDetectICP<<8) & 0xFF00) +
         ((ICP_data.userDetectICP>>8) & 0x00FF);

   // No serial # prior to V3.5
   flashImageDescription.serialNumberPresent = ICP_data.softwareVersion >= 0x35;

   if (ICP_data.softwareVersion < 0x35) {
      static const char dummySerialNumber[] = "<\0n\0o\0n\0e\0>\0"; // UTF-16-LE !
      memset((char*)ICP_data.serialNumber, 0, sizeof(ICP_data.serialNumber));
      memcpy((char*)ICP_data.serialNumber, dummySerialNumber, sizeof(dummySerialNumber));
   }
   unsigned char checkSum = 0;
   for (unsigned addr = ICP_data.flashStart; addr < protectAddress-1; addr++) {
      checkSum += flashImage->getValue(addr);
   }
   checkSum -= flashImage->getValue(protectAddress-1);

   log.printq(
         "flashStart     = %4.4X\n"
         "userDetectICP  = %4.4X\n"
         "checksum       = %2.2X\n",
         ICP_data.flashStart,
         ICP_data.userDetectICP,
         checkSum
   );

   // Validity checks

   // Invalid checksum
   if (checkSum != 0) {
      log.print("Checksum Failed\n");
      return false;
   }
   // Implausible Flash start address
   if (ICP_data.flashStart > flashImageDescription.firstAddr) {
      log.print("Implausible flashStart address\n ");
      return false;
   }
   // Implausible userDetectICP() address
   if ((ICP_data.userDetectICP < flashImageDescription.firstAddr) ||
         (ICP_data.userDetectICP > protectAddress)) {
      log.print("Implausible userDetectICP() address\n ");
      return false;
   }
   flashImageDescription.protectAddr      = protectAddress;
   flashImageDescription.flashStart       = ICP_data.flashStart;
   flashImageDescription.hardwareVersion  = ICP_data.hardwareVersion;
   flashImageDescription.softwareVersion  = ICP_data.softwareVersion;
   flashImageDescription.userDetectICP    = ICP_data.userDetectICP;
   flashImageDescription.serialNumber     = wxString((const char *)ICP_data.serialNumber, wxConvUTF8);
   return true;
}

//! Returns the ICP data from the flash image
//!
//! @return true - ICP data structure initialised from the Flash image
//!         false - image not valid
//!
bool FirmwareChangerDialogue::getICPData(void) {
   LOGGING;

   flashImageDescription.firstAddr = flashImage->getFirstAllocatedAddress();
   flashImageDescription.lastAddr  = flashImage->getLastAllocatedAddress();

   // There are two possible image formats (JMxx & UF32) and no way to easily tell them apart!
   const unsigned int JMxxProtectAddress = 0xFC00;  // Start of protected area of JBxx Flash
   const unsigned int UF32ProtectAddress = 0xF800;  // Start of protected area of UF32 Flash

   return consistencyCheck(JMxxProtectAddress) ||
         consistencyCheck(UF32ProtectAddress);
}

/*
 *  Load flash image & update display
 *
 *  @param path - Path to file to load
 *
 *  @return BDM_RC_OK on success
 *  On failure a dialogue has already been displayed
 */
bool FirmwareChangerDialogue::loadFlashImageFile(wxString path) {
   LOGGING;

   if(inGUIMode()){
      // Clear File information
      filename   = wxEmptyString;
      filePath   = wxEmptyString;
      fileInformationStaticText->SetLabel(wxEmptyString);
   }

   flashImage.reset();
   flashImage = FlashImageFactory::createFlashImage(T_HCS08);

   bool isOK = (flashImage->loadFile((const char *)path.c_str(), true, false) == BDM_RC_OK) && getICPData();

   // Extract the ICP information from the image
   if (!isOK) {
      log.error("Failed to load \'%s\'\n", (const char *)path.c_str());  
      flashImage.reset();
      if(inGUIMode()){
         wxMessageBox(_("Flash Image is invalid.\n"
               "File is incorrect or corrupt?"),
               _("Flash File Format Error"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER
         );
      }
      else{
         errMessage = "Flash Image is invalid. File is incorrect or corrupt?";
      }
      return false;
   }

   if(inGUIMode()){
      wxString hardwareDescription(getBriefHardwareDescription(flashImageDescription.hardwareVersion), wxConvUTF8);
      wxString fileInformation;
      fileInformationStaticText->Clear();

      fileInformation.Printf("Serial #           = %s\n",      (const char *)flashImageDescription.serialNumber.c_str());
      fileInformationStaticText->AppendText(fileInformation);
      fileInformation.Printf("Hardware Version   = %s\n",      (const char *)hardwareDescription.c_str());
      fileInformationStaticText->AppendText(fileInformation);
      fileInformation.Printf("Software Version   = %d.%d\n",   flashImageDescription.softwareVersion>>4, flashImageDescription.softwareVersion&0x0F);
      fileInformationStaticText->AppendText(fileInformation);
      fileInformation.Printf("Flash Start        = 0x%4.4X\n", flashImageDescription.flashStart);
      fileInformationStaticText->AppendText(fileInformation);
      fileInformation.Printf("Protect Address    = 0x%4.4X\n", flashImageDescription.protectAddr);
      fileInformationStaticText->AppendText(fileInformation);
      fileInformation.Printf("Code Start Address = 0x%4.4X\n", flashImageDescription.firstAddr);
      fileInformationStaticText->AppendText(fileInformation);
      fileInformation.Printf("Code End Address   = 0x%4.4X\n", flashImageDescription.lastAddr);
      fileInformationStaticText->AppendText(fileInformation);
      fileInformation.Printf("UserDetectICP()    = 0x%4.4X\n", flashImageDescription.userDetectICP);
      fileInformationStaticText->AppendText(fileInformation);

      parseSerialNumber(flashImageDescription.serialNumber, serialNumberPrefix);
      if (autoSequenceFlag && !autoUpdateBdm) {
         serialNumberToTextControl();
      }
      else {
         serialNumberText->ChangeValue(flashImageDescription.serialNumber);
      }
   }
   return true;
}

//! Open a single USBDM device
//!
//! @return error code
//!
int FirmwareChangerDialogue::openSingleDevice(void) {
   LOGGING;
   unsigned int numDevices;

   errMessage = wxEmptyString;

   USBDM_Close(); // Close just in case

   (void)USBDM_FindDevices(&numDevices);

   if (numDevices == 0) {
      errMessage = _("No suitable USBDM device found");
      return FLASH_ERR_FAIL;
   }
   if (numDevices > 1) {
      if(inGUIMode()){
         errMessage = _("Too many USBDM devices found\n"
               "Only a single device may be connected during update");
      }
      else{
         errMessage = _("Too many USBDM devices found. "
               "Only a single device may be connected during update");
      }
      return FLASH_ERR_FAIL;
   }
   USBDM_ErrorCode rc = USBDM_Open(0);
   if (rc != BDM_RC_OK) {
      errMessage = wxString(USBDM_GetErrorString(rc), wxConvUTF8);
      return FLASH_ERR_FAIL;
   }
   return FLASH_ERR_OK;
}

//! Read BDM serial number from device
//!
//! @param bdmSerialNumber - where to place the pointer to the UTF-16-LE string read
//!
//! @return error code
//!
int FirmwareChangerDialogue::readBdmInformation(USBDM_bdmInformation_t *info) {
   LOGGING;

   int rc = openSingleDevice();
   if (rc != FLASH_ERR_OK) {
      return rc;
   }
   info->size = sizeof(USBDM_bdmInformation_t);
   USBDM_ErrorCode rc2 = USBDM_GetBdmInformation(info);
   USBDM_Close();
   if (rc2 != BDM_RC_OK) {
      errMessage = wxString(USBDM_GetErrorString(rc2), wxConvUTF8);
      return FLASH_ERR_FAIL;
   }
   return FLASH_ERR_OK;
}

//! Read BDM serial number from device
//!
//! @param bdmSerialNumber - where to place the pointer to the UTF-16-LE string read
//!
//! @return error code
//!
int FirmwareChangerDialogue::readBdmSerialNumber(const char **bdmSerialNumber) {

   int rc = openSingleDevice();
   if (rc != FLASH_ERR_OK) {
      return rc;
   }
   rc = USBDM_GetBDMSerialNumber(bdmSerialNumber);
   USBDM_Close();
   if (rc != BDM_RC_OK) {
      if(inGUIMode()){
         errMessage = _("Unable to read BDM serial number.\n\n"
               "Using default value.");
      }
      else{
         errMessage = _("Unable to read BDM serial number.");
      }
      return FLASH_ERR_FAIL;
   }
   return FLASH_ERR_OK;
}

//! Open BDM with retry
//!
USBDM_ErrorCode FirmwareChangerDialogue::reOpenBDM(void) {
   LOGGING;

   int retry;
   unsigned numDevices;
   USBDM_ErrorCode rc = BDM_RC_NO_USBDM_DEVICE;

   // Connection is lost so close it.
   USBDM_Close();
   log.print("reOpenBDM(): starting\n");

   retry = 25;
   do {
      // Retry connection to allow for reboot and re-enumeration time
      // Uses USBDM_FindDevices() every time to avoid confusion with stale devices!
      wxMilliSleep(100);
      log.print("reOpenBDM(): doing USBDM_FindDevices()\n");
      (void)USBDM_FindDevices(&numDevices);
      if (numDevices > 0) {
         log.print("reOpenBDM(): doing USBDM_Open()\n");
         rc = USBDM_Open(0);
      }
   } while (((numDevices == 0) || (rc != BDM_RC_OK)) && (retry-- >0));
   return rc;
}

USBDM_ErrorCode FirmwareChangerDialogue::doBlockOperation(FlashImagePtr flashImage, uint32_t size, uint32_t startBlock, Operation op) {
   LOGGING;
   uint8_t buffer[1024];
   memset(buffer, 0xFF, sizeof(buffer));
   USBDM_ErrorCode rc = BDM_RC_OK;
   while(size>0) {
      uint32_t blockSize = size;
      if (blockSize > sizeof(buffer)) {
         blockSize = sizeof(buffer);
      }
      log.print("Doing block [0x%04X...0x%04X]\n", startBlock, startBlock+blockSize-1);
      // Copy data to buffer
      for (uint32_t index=0; index<blockSize; index++) {
         buffer[index] = flashImage->getValue(startBlock+index);
      }
      // Program buffer
      rc = op(startBlock, blockSize, buffer);
      if (rc != BDM_RC_OK) {
         log.print("Block [0x%04X...0x%04X] failed\n", startBlock, startBlock+blockSize-1);
         return rc;
      }
      startBlock += blockSize;
      size       -= blockSize;
   }
   return rc;
}

USBDM_ErrorCode FirmwareChangerDialogue::doFlashOperation(Operation op) {
   LOGGING_Q;
   FlashImage::EnumeratorPtr enumerator = flashImage->getEnumerator();
   USBDM_ErrorCode progRc = BDM_RC_OK;
   while (enumerator->isValid()) {
      // Start address of block to program to flash
      uint32_t startBlock = enumerator->getAddress();

      // Find end of block to program
      enumerator->lastValid();
      uint32_t endBlock = enumerator->getAddress();
      if (endBlock >= flashImageDescription.protectAddr) {
         log.print("Limiting address to 0x%08X\n",(uint32_t) flashImageDescription.protectAddr-1);
         endBlock = (uint32_t)flashImageDescription.protectAddr-1;
      }
      if (startBlock > endBlock) {
         // Done
         break;
      }
      uint32_t blockSize = endBlock - startBlock + 1;

      //log.print("Block size = %4.4X (%d)\n", blockSize, blockSize);
      if (blockSize>0) {
         // Program block [startBlock..endBlock]
         progRc = doBlockOperation(flashImage, blockSize, startBlock, op);
         if (progRc != BDM_RC_OK) {
            log.print("loadFile() - operation failed, Reason= %s\n", UsbdmSystem::getErrorString(progRc));
            break;
         }
      }
      // Move to start of next occupied range
      enumerator->nextValid();
   }
   return progRc;
}

//! \brief Update / verify Firmware
//!
//! @param updateFirmware - True to update firmware before verifying
//!
int FirmwareChangerDialogue::doFirmware(int updateFirmware) {
   LOGGING;

   USBDM_Version_t USBDM_Version;
   int  rc;
   USBDM_ErrorCode bdm_rc = BDM_RC_OK;
   USBDM_ErrorCode icp_rc = BDM_RC_OK;

   ProgressDialoguePtr callBack;
   if(inGUIMode()){
      callBack = ProgressDialogueFactory::create("Accessing Target", flashImage->getByteCount());
   }
   else{
      callBack = ProgressDialogueFactory::create(flashImage->getByteCount(), verbose, enableConsole);
   }
   USBDM_ICP_SetCallback(callBack.get());

   rc = openSingleDevice();
   if (rc != FLASH_ERR_OK) {
      return rc;
   }
   bdm_rc = USBDM_GetVersion(&USBDM_Version);
   if (bdm_rc != BDM_RC_OK) {
      if(inGUIMode()){
         errMessage = _("Unable to determine BDM Version\n"
               "Device is not a USBDM?");
      }
      else{
         errMessage = _("Unable to determine BDM Version. Device is not a USBDM?");
      }
      USBDM_Close();
      return FLASH_ERR_FAIL;
   }
   if ((USBDM_Version.bdmHardwareVersion&0xC0)==0) {
      if(inGUIMode()){
         errMessage = _("JB16 USBDMs cannot be updated or verified\n"
               "using this software.\n"
               "Please use the Freescale ICP utility");
      }
      else{
         errMessage = _("JB16 USBDMs cannot be updated or verified using this software. "
               "Please use the Freescale ICP utility");
      }
      USBDM_Close();
      return FLASH_ERR_FAIL;
   }
   if (USBDM_Version.icpHardwareVersion != flashImageDescription.hardwareVersion) { // HW version incorrect
      errMessage = _("Image file does not appear to be for this hardware\r\n");
      log.print("doFirmware(): Image file does not appear to be for this hardware\n");
      USBDM_Close();
      return FLASH_ERR_FAIL;
   }
#if !defined(DEBUG_VER) && !defined(DEBUG_REBOOT)
   if(inGUIMode()){
      int getOkCancel = wxMessageBox(_("The BDM will be re-booted into ICP mode for firmware update.\n\n"
            "The device may then require driver installation.  Please check for\n"
            "and allow this to complete.\n\n"
            "Please remove any equipment connected to the USB hardware. \n\n"
            "Press OK to continue"),
            _("Preparing to verify/update firmware"),
            wxOK|wxCANCEL|wxICON_INFORMATION|wxSTAY_ON_TOP|wxCENTER,
            this
      );
      if (getOkCancel != wxOK) {
         return FLASH_ERR_CANCEL;
      }
   }
#endif

   try {
      bdm_rc = BDM_RC_OK;
      if (USBDM_Version.bdmSoftwareVersion != 0xFF) { // Not already in ICP mode
         log.print("doFirmware(): Doing ICP reboot of BDM\n");
         callBack->update(0, "Rebooting to ICP mode...");
         // Cause Target to reboot into ICP mode (ignored if already in ICP mode)
         USBDM_RebootToICP();
         int getYesNo = wxNO;
         do {
            // Try opening (should now be in ICP mode)
            bdm_rc = reOpenBDM();
            if(inGUIMode()){
               if (bdm_rc != BDM_RC_OK) {
                  getYesNo = wxMessageBox(_("Device failed to re-open after reboot into ICP mode.\n\n"
                        "This may indicate that the drivers have not been installed.\n"
                        "Please check the driver installation before retrying.\n\n"
                        "Retry?"),
                        _("Firmware Update Failed"),
                        wxYES_NO|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                        this
                  );
               }
            }
            else{
               break;
            }
         } while (getYesNo == wxYES);
      }
      if (bdm_rc != BDM_RC_OK) {
         errMessage = wxString(USBDM_GetErrorString(bdm_rc), wxConvUTF8);
         //         errMessage = _("Device failed to re-open after reboot into ICP mode.\n");
         throw FLASH_ERR_FAIL;
      }
      log.print("doFirmware(): Checking in ICP mode\n");
      // Check version & in ICP mode
      bdm_rc = USBDM_GetVersion(&USBDM_Version);
      if (bdm_rc != BDM_RC_OK) {
         errMessage = _("Failed to read BDM Version.\n");
         throw FLASH_ERR_FAIL;
      }
      if (USBDM_Version.bdmSoftwareVersion != 0xFF) {         // Not in ICP mode or
         errMessage = _("Failed to reboot into ICP mode.\n");
         throw FLASH_ERR_FAIL;
      }
      if (updateFirmware) {
         // Erase Flash image area (ICP area is protected)
         callBack->update(0, "Erasing BDM Firmware...");
         log.print("doFirmware(): Erasing\n");
         icp_rc = USBDM_ICP_Erase( flashImageDescription.firstAddr, flashImageDescription.protectAddr-flashImageDescription.firstAddr );
         if (icp_rc != BDM_RC_OK) {
            log.print("doFirmware(): Erasing failed\n");
            errMessage = _("Failed to erase\r\n");
            throw FLASH_ERR_FAIL;
         }
         callBack->update(0, "Programming BDM Firmware...");
         log.print("doFirmware(): Programming\n");
         icp_rc = doFlashOperation(USBDM_ICP_Program);
         if (icp_rc != BDM_RC_OK) {
            log.print("doFirmware(): Programming failed\n");
            errMessage = _("Programming Failed\r\n");
            throw FLASH_ERR_FAIL;
         }
      }
      callBack->update(0, "Verifying BDM Firmware...");
      // Verify the firmware
      log.print("doFirmware(): Verifying\n");
#ifdef DEBUG_VER
      for (int i=0; i<1000; i++) {
         log.print("doFirmware(): Verifying # %d\r\n", i);
#endif
#if !defined(DONT_VERIFY)
         icp_rc = doFlashOperation(USBDM_ICP_Verify);
         if (icp_rc != BDM_RC_OK) {
            log.print("doFirmware(): Verifying failed\n");
            errMessage = _("Flash memory failed to verify. \r\n");
            throw FLASH_ERR_FAIL;
         }
#endif
#ifdef DEBUG_VER
      }
#endif
   }
   catch (...) {
      rc = FLASH_ERR_FAIL;
   }
   callBack->update(0, "Doing normal re-boot...");
   log.print("doFirmware(): Doing Normal reboot (ignore errors)\n");
   USBDM_ICP_Reboot();   // Cause Target to reboot into normal mode
   if (reOpenBDM() != BDM_RC_OK) {
      if(inGUIMode()){
         // Try manual reboot
         wxMessageBox(_("Please manually reboot the BDM by removing it from \n"
               "the PC and then replacing it after a brief wait.\n\n"
               "Click OK when ready"),
               _("Automatic Reboot Failed"),
               wxOK|wxSTAY_ON_TOP|wxCENTER,
               this
         );
      }
      else{
         errMessage = _("Failed to re-open after automatic reboot\r\n");
         return FLASH_ERR_FAIL;
      }
   }
   if(inGUIMode()){
      if (reOpenBDM() != BDM_RC_OK) {
         errMessage = _("Failed to re-open after 2nd reboot\r\n");
         setStatus("Last flash operation failed");
         return FLASH_ERR_FAIL;
      }
   }
   callBack->close();
   log.print("doFirmware() getting serial #\n");
   const char *buffer;
   USBDM_GetBDMSerialNumber(&buffer);
   log.print("Serial #%s\n", (const char *)convertUtfToString(buffer).ToAscii());

   USBDM_Close();
   setStatus("Last flash operation successful");
   log.print("doFirmware(): Successful\n");

   return rc;
}

FirmwareChangerDialogue::FirmwareChangerDialogue( wxWindow* parent)
: FirmwareChangerSkeleton(parent),
  autoSequenceFlag(false),
  autoSequenceNumber(1),
  autoUpdateBdm(false),
  verify(false),
  program(false),
  verbose(false),
  enableAutoLoad(false),
  enableConsole(0),
  activeMode(CMD_LINE_MODE) {
}

/*
 * FirmwareChangerDialogue destructor
 */
FirmwareChangerDialogue::~FirmwareChangerDialogue() {
}

/*
 * Member initialisation
 */
void FirmwareChangerDialogue::Init() {
   LOGGING;

   log.print("serialNumber = '%s'\n", (const char *)serialNumber.c_str());
   autoSelectFirmwareCheckbox->SetValue(autoUpdateBdm);
   serialNumberText->SetMaxLength(sizeof(ICP_data.serialNumber));
   serialNumberText->SetValue(serialNumber);
   serialNumberText->Enable(!autoSequenceFlag);
   autoSequenceText->SetDecimalValue(autoSequenceNumber);
   autoSequenceText->Enable(autoSequenceFlag);
   autoSequenceCheckbox->SetValue(autoSequenceFlag);
   programFlashButton->Enable(flashImage != 0);
   verifyButton->Enable(flashImage != 0);

   if (autoSequenceFlag) {
      serialNumberToTextControl();
   }
}

/**
 * Set status line
 *
 * @param status
 */
void FirmwareChangerDialogue::setStatus(wxString status) {
   if(inGUIMode()) {
      statusStaticText->SetLabel(_("Status: ") + status);
   }
}

//!
//! @param settings      - Object to load settings from
//!
void FirmwareChangerDialogue::loadSettings(const AppSettings &settings) {
   LOGGING;

   autoSequenceFlag   = settings.getValue("autoSequence",           false);
   autoSequenceNumber = settings.getValue("autoSequenceNumber",     1);
   autoUpdateBdm      = settings.getValue("autoUpdateBdm",          true);
   defaultDirectory   = settings.getValue("defaultDirectory",       "");
   serialNumber       = settings.getValue("serialNumber",           "USBDM");
   parseSerialNumber(serialNumber, serialNumberPrefix);
}

//! Save setting file
//!
//! @param settings      - Object to save settings to
//!
void FirmwareChangerDialogue::saveSettings(AppSettings &settings) {
   LOGGING_E;

   settings.addValue("autoUpdateBdm",      autoUpdateBdm);
   settings.addValue("autoSequence",       autoSequenceFlag);
   settings.addValue("autoSequenceNumber", autoSequenceNumber);
   settings.addValue("defaultDirectory",   defaultDirectory);
   settings.addValue("serialNumber",       serialNumber.ToAscii());
}

/*
 * Should we show tooltips?
 */
bool FirmwareChangerDialogue::ShowToolTips() {
   return true;
}

/*
 * Get bitmap resources
 */
wxBitmap FirmwareChangerDialogue::GetBitmapResource( const wxString& name ) {

   wxUnusedVar(name);
   return wxNullBitmap;
}

/*
 * Get icon resources
 */
wxIcon FirmwareChangerDialogue::GetIconResource( const wxString& name ) {

   wxUnusedVar(name);
   return wxNullIcon;
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FILE_LOAD_BUTTON
 */
void FirmwareChangerDialogue::OnLoadFirmwareButtonClick( wxCommandEvent& event ) {
   wxString caption           = _("Choose a firmware file");
   wxString wildcard          = _("Hex files (*.sx,*.s1?)|*.sx;*.s1?|All Files|*");
   wxString defaultDir        = defaultDirectory;
   wxString defaultFilename   = wxEmptyString;
   wxFileDialog dialog(this, caption, defaultDir, defaultFilename, wildcard, wxFD_OPEN);
   if (dialog.ShowModal() == wxID_OK) {
      if (loadFlashImageFile(dialog.GetPath())) {
         filename         = dialog.GetFilename();
         defaultDirectory = dialog.GetDirectory();
      }
   }
   updateControls();
}

/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL
 */
void FirmwareChangerDialogue::OnSerialnumTextctrlTextUpdated( wxCommandEvent& event ) {
   serialNumber = serialNumberText->GetValue();
}

/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL
 */
void FirmwareChangerDialogue::OnAutoSequenceTextControlTextUpdated( wxCommandEvent& event ) {
   autoSequenceNumber = autoSequenceText->GetDecimalValue();
   serialNumberToTextControl();
}

int FirmwareChangerDialogue::readSerialNumber(void) {
   const char *bdmDescription;
   int rc = readBdmSerialNumber(&bdmDescription);
   setStatus();
   if (rc != FLASH_ERR_OK) {
      setStatus("Reading serial number failed");
      if(inGUIMode()){
         wxMessageBox(errMessage,
               _("Reading serial number failed"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this
         );
      }
      return rc;
   }
   serialNumber = convertUtfToString(bdmDescription);
   if(inGUIMode()){
      serialNumberText->ChangeValue(serialNumber);
      textControlToSerialNumber();
   }
   return rc;
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */
void FirmwareChangerDialogue::OnReadSerialNumButtonClick( wxCommandEvent& event ) {
   if ((readSerialNumber() == FLASH_ERR_OK) &&
         autoSequenceFlag) {
      serialNumberToTextControl();
   }
}

void FirmwareChangerDialogue::serialNumberToTextControl(void) {
   LOGGING;

   serialNumber  = serialNumberPrefix;
   serialNumber += wxString::Format(_("-%04d"), autoSequenceNumber);
   serialNumberText->SetValue(serialNumber);
   log.print("FirmwareChangerDialogue::serialNumberToTextControl(): s=\'%s\' p=\'%s\'\n",
         (const char *)serialNumber.c_str(),
         (const char *)serialNumberPrefix.c_str()
   );
}

/**
 * Parse serial number
 *
 * @param[in]  serialNumber
 * @param[out] serialNumberPrefix
 */
void FirmwareChangerDialogue::parseSerialNumber(const wxString &serialNumber, wxString &serialNumberPrefix) {
   LOGGING_Q;

   size_t separatorIndex = serialNumber.length();
   if (separatorIndex == 0) {
      serialNumberPrefix = _("");
      return;
   }
   // Start at end of string
   separatorIndex -= 1;
   while ((separatorIndex>=0) && isdigit((char)serialNumber.at(separatorIndex))) {
      separatorIndex--;
   }
   if (serialNumber.at(separatorIndex) == '-') {
      separatorIndex--;
   }
   if (separatorIndex>(sizeof(ICP_data.serialNumber)-5)) {
      separatorIndex = sizeof(ICP_data.serialNumber)-5;
   }
   serialNumberPrefix = serialNumber.substr(0,separatorIndex+1);
   log.print(" s=\'%s\' p=\'%s\'\n",
         (const char *)serialNumber.c_str(),
         (const char *)serialNumberPrefix.c_str()
   );
}

void FirmwareChangerDialogue::textControlToSerialNumber(void) {
   LOGGING_Q;

   parseSerialNumber(serialNumberText->GetValue(), serialNumberPrefix);
   log.print(" s=\'%s\' p=\'%s\'\n",
         (const char *)serialNumber.c_str(),
         (const char *)serialNumberPrefix.c_str()
   );
}

/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_BUTTON
 */
void FirmwareChangerDialogue::OnAutoSequenceCheckboxClick( wxCommandEvent& event ) {
   LOGGING_Q;
   autoSequenceFlag = event.IsChecked();
   log.print(", value = %s\n", autoSequenceFlag?"True":"False");
   if (autoSequenceFlag) {
      // Auto turned on
      // Create serial number from existing text + auto serial number
      textControlToSerialNumber();
   }
   serialNumberToTextControl();
   updateControls();
}

char *firmwareFilepaths[100] = {0};

int FirmwareChangerDialogue::loadUpdateInformation() {
   LOGGING;
   string flashImageListFile("FlashImages/FlashImagesList.txt");
   string path = UsbdmSystem::getResourcePath(flashImageListFile);
   FILE *fp = fopen(path.c_str(), "rt");
   if (fp == NULL) {
      log.error("Failed to open \'%s\'\n", path.c_str());
      if(inGUIMode()){
         wxMessageBox(_("Unable to open file image configuration file.\n"
               "Please check that USBDM has been correctly installed."),
               _("Configuration error "),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this);
      }
      else{
         errMessage = _("Unable to open file image configuration file. "
               "Please check that USBDM has been correctly installed.");
      }
      return FLASH_ERR_FAIL;
   }
   for (unsigned index=0;
         index<(sizeof(firmwareFilepaths)/sizeof(firmwareFilepaths[0]));
         index++) {
      if (firmwareFilepaths[index] != NULL) {
         free(firmwareFilepaths[index]);
      }
      firmwareFilepaths[index] = NULL;
   }
   char buff[200];
   while (fgets(buff, sizeof(buff), fp) != NULL) {
      //      log.print("loadUpdateInformation(): %s\n", buff);
      unsigned index = 0;
      char lineBuff[200];
      if (sscanf(buff, "%u, %s", &index, lineBuff) != 2) {
         if(inGUIMode()){
            wxMessageBox(_("Invalid file image configuration file.\n"
                  "Please check that USBDM has been correctly installed."),
                  _("Configuration error "),
                  wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                  this
            );
         }
         else{
            errMessage = _("Invalid file image configuration file. "
                  "Please check that USBDM has been correctly installed.");
         }
         return FLASH_ERR_FAIL;
      }
      log.print("loadUpdateInformation(): %2d : \'%s\'\n", index, lineBuff);
      if (strcmp(lineBuff, "-") == 0) {
         firmwareFilepaths[index] = NULL;
      }
      else {
         firmwareFilepaths[index] = strdup(lineBuff);
      }
   }
   return FLASH_ERR_OK;
}

int FirmwareChangerDialogue::doAutoUpdate() {
   LOGGING;
   USBDM_bdmInformation_t bdmInfo;

   setStatus();

   // Assume failure
   autoUpdateBdm = false;
   int rc = readBdmInformation(&bdmInfo);
   if (rc != FLASH_ERR_OK) {
      setStatus("Reading BDM Information failed");
      if(inGUIMode()){
         wxMessageBox(errMessage,
               _("Reading BDM Information failed"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this
         );
      }
      return rc;
   }
   unsigned bdmType = bdmInfo.ICPhardwareVersion & 0x3F;

   // Re-read the update file
   if (loadUpdateInformation() != FLASH_ERR_OK) {
      return FLASH_ERR_FAIL;
   }
   log.print("FirmwareChangerDialogue::autoLoadFile(): ICPhardwareVersion = %d (%s)\n", bdmType, getBriefHardwareDescription(bdmType));
   if (bdmType > (sizeof(firmwareFilepaths)/sizeof(firmwareFilepaths[0])) ||
         (firmwareFilepaths[bdmType] == NULL)) {
      setStatus("Unrecognised or unsupported BDM device");
      if(inGUIMode()){
         wxMessageBox(_("Unrecognised or unsupported BDM device   \n\n"
               "Only JMxx or JS16 based USBDM devices \n"
               "may be updated this way."),
               _("Device Update Error"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this
         );
      }
      else{
         errMessage = _("Unrecognised or unsupported BDM device. "
               "Only JMxx or JS16 based USBDM devices may be updated this way.");
      }
      return FLASH_ERR_FAIL;
   }
   if (!loadFlashImageFile(UsbdmSystem::getResourcePath(firmwareFilepaths[bdmType]))) {
      setStatus("Flash update file cannot be loaded");
      setStatus("Flash update file cannot be loaded");
      if(inGUIMode()){
         wxMessageBox(_("The Flash update file cannot be loaded.\n\n"
               "Please check that USBDM has been correctly installed."),
               _("Flash image error"),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this
         );
      }
      else{
         errMessage = _("The Flash update file cannot be loaded. "
               "Please check that USBDM has been correctly installed.");
      }
      return FLASH_ERR_FAIL;
   }

   filename = firmwareFilepaths[bdmType];

   // Get current serial number from device (if possible) in GUI mode
   int readSerialRC = readSerialNumber();
   // For command line mode return fail if read serial fails
   if(!inGUIMode() && readSerialRC != FLASH_ERR_OK){
      return FLASH_ERR_FAIL;
   }
   autoUpdateBdm = true;

   return rc;
}

void FirmwareChangerDialogue::updateControls(void) {
   autoSelectFirmwareCheckbox->SetValue(autoUpdateBdm);
   loadFirmwareButton->Enable(!autoUpdateBdm);
   autoSequenceText->Enable(!autoUpdateBdm && autoSequenceFlag);
   serialNumberText->Enable(!autoUpdateBdm && !autoSequenceFlag);
   readSerialNumberButton->Enable(!autoUpdateBdm);
   autoSequenceCheckbox->Enable(!autoUpdateBdm);
   programFlashButton->Enable(flashImage != 0);
   verifyButton->Enable(flashImage != 0);
   if (autoUpdateBdm) {
      filenameStaticText->SetLabel(_("Flash image file has been automatically selected"));
   }
   else if (flashImage != 0) {
      filenameStaticText->SetLabel(filename);
   }
   else {
      filenameStaticText->SetLabel(_("No file loaded"));
   }
   if (!autoUpdateBdm) {
      if (autoSequenceFlag) {
         serialNumberToTextControl();
      }
      else {
         textControlToSerialNumber();
      }
   }
}

//! Enable auto load
//!
void FirmwareChangerDialogue::setAutoLoad(bool value) {
   if (value || autoUpdateBdm) {
      doAutoUpdate();
      updateControls();
   }
}

/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_BUTTON
 */
void FirmwareChangerDialogue::OnAutoSelectFirmwareCheckboxClick( wxCommandEvent& event ) {
   LOGGING_Q;

   log.print("FirmwareChangerDialogue::OnAutoUpdateBdmCheckboxClick(), value = %s\n", event.IsChecked()?"True":"False");
   autoUpdateBdm = false;
   if (event.IsChecked()) {
      doAutoUpdate();
   }
   updateControls();
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PROGRAM_FLASH_BUTTON
 */
void FirmwareChangerDialogue::OnProgramFlashButtonClick( wxCommandEvent& event ) {

   // Update in case BDM has changed
   if (autoUpdateBdm && (doAutoUpdate() != FLASH_ERR_OK)) {
      updateControls();
      return;
   }
   setStatus();
   setSerialNumber(serialNumberText->GetValue());
   int rc = doFirmware(true);
   setStatus();
   if (rc == FLASH_ERR_OK) {
      wxMessageBox(_("The update of the Firmware has completed successfully.\n\n"
            "Presss OK to continue."),
            _("Firmware Update Completed"),
            wxOK|wxICON_INFORMATION|wxSTAY_ON_TOP|wxCENTER,
            this
      );
   }
   else if (rc == FLASH_ERR_CANCEL) {
      // Just ignore
   }
   else {
      setStatus("Firmware Update Failed");
      wxMessageBox(errMessage,
            _("Firmware Update Failed"),
            wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
            this
      );
   }
   if (autoSequenceFlag && !autoUpdateBdm) {
      autoSequenceText->SetDecimalValue(++autoSequenceNumber);
      serialNumberToTextControl();
   }
   updateControls();
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_VERIFY_FLASH_BUTTON
 */
void FirmwareChangerDialogue::OnVerifyFlashButtonClick( wxCommandEvent& event ) {
   int rc;

   setStatus();

   // Update in case BDM has changed
   if (autoUpdateBdm && (doAutoUpdate() != FLASH_ERR_OK)) {
      updateControls();
      return;
   }
   setSerialNumber(serialNumberText->GetValue());

#ifdef DEBUG_REBOOT
   for (int i=0; i<DEBUG_REBOOT;i++) {
#endif
      rc = doFirmware(false);
#ifdef DEBUG_REBOOT
      if (rc != 0)
         break;
      log.print("OnVerifyFlashButtonClick() - #%d OK\n", i);
   }
#endif
   setStatus();
   if (rc == FLASH_ERR_OK) {
      wxMessageBox(_("The verification of the Firmware has completed successfully.\n\n"
            "Press OK to continue."),
            _("Firmware Verify Completed"),
            wxOK|wxICON_INFORMATION|wxSTAY_ON_TOP|wxCENTER,
            this
      );
   }
   else if (rc == FLASH_ERR_CANCEL) {
      // Just ignore
   }
   else {
      setStatus("Firmware Verify Failed");
      wxMessageBox(errMessage,
            _("Firmware Verify Failed"),
            wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
            this
      );
   }
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EXIT_BUTTON
 */
void FirmwareChangerDialogue::OnExitButtonClick( wxCommandEvent& event ) {
   EndModal(0);
}

/**
 * Command line parsing
 *
 * @return Error code
 */
int FirmwareChangerDialogue::parseCommandLine(wxCmdLineParser& parser) {
   LOGGING;
   wxString sValue;

   activeMode = CMD_LINE_MODE;

   if (parser.Found(_("auto"))) {
      enableAutoLoad = true;
   }
   if(!parser.Found(_("program")) && !parser.Found(_("verify"))){
      activeMode = GUI_MODE;
      return CMD_LINE_OK;
   }
   if(!enableAutoLoad){
      // The firmware file must be specified
      if(parser.GetParamCount() == 0){
         logUsageError(parser, _("\n****** Error: Firmware file not specified.\n"));
         return CMD_LINE_ILLEGAL_PARAMS;
      }
      filename = parser.GetParam(0);
      if(parser.Found(_("serial"), &sValue)){
         unsigned int maxSerialNumberLength = sizeof(ICP_data.serialNumber)/sizeof(ICP_data.serialNumber[0]);
         if(sValue.length() == 0 || sValue.length() > maxSerialNumberLength){
            logUsageError(parser, _("\n****** Error: Serial number length must be from 1 to " +
                  std::to_string(maxSerialNumberLength)));
            return CMD_LINE_ILLEGAL_PARAMS;
         }
         serialNumber = sValue;
      }
      else{
         serialNumber = _("");
      }
   }

   verbose = parser.Found(_("verbose"));

#ifdef _WIN32
   enableConsole = parser.Found(_("console"));
#else
   enableConsole = true;
#endif

   program = parser.Found(_("program"));
   verify = parser.Found(_("verify"));
   // Programming includes verification
   if(program){
      verify = false;
   }
   return CMD_LINE_OK;
}

/**
 * Command line operation
 *
 * @return Error code
 */
int FirmwareChangerDialogue::doCommandLineProgram() {
   LOGGING;

   int rc = FLASH_ERR_OK;

   if(enableAutoLoad){
      rc = doAutoUpdate();
      if(rc != FLASH_ERR_OK){
         return rc;
      }
   }
   else if(!loadFlashImageFile(filename)){
      return FLASH_ERR_FAIL;
   }

   if(!serialNumber.IsEmpty()){
      setSerialNumber(serialNumber);
   }

   if(program){
      rc = doFirmware(true);
   }
   else{
      rc = doFirmware(false);
   }

   return rc;
}

void FirmwareChangerDialogue::logUsageError(wxCmdLineParser& parser, const wxString& text){
   UsbdmSystem::Log::error("%s", (const char *)text.c_str());
#if (wxCHECK_VERSION(2, 9, 0))
   parser.AddUsageText(text);
#endif
}

std::string FirmwareChangerDialogue::getConsoleMessage(){
   std::string baseMessage = program ? "Firmware update" : "Firmware verification";
   if(errMessage.IsEmpty()){
      return baseMessage + " has completed successfully";
   }
   else{
      errMessage.Replace("\n", "");
      errMessage.Replace("\r", "");
      return std::string(baseMessage + " failed. Error: " + errMessage.mb_str());
   }
}

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile(logFilename, "Firmware Changer");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
      UsbdmSystem::Log::closeLogFile();
   }
};
/*!
 * FirmwareChangerApp class declaration
 */
class FirmwareChangerApp: public wxApp {

   DECLARE_CLASS( FirmwareChangerApp )
   DECLARE_EVENT_TABLE()

private:
   OpenLog openLog;
   AppSettingsPtr               appSettings;
   FirmwareChangerDialogue      *dialogue;
   int                          applicationRC;
   bool                         consoleIsAttached;

   void attachConsole();
   void freeConsole();

public:
   // Constructor
   FirmwareChangerApp();

   void Init();

   // Initialises the application
   virtual bool OnInit();
   // Runs the application
   virtual int OnRun();
   // Called on exit
   virtual int OnExit();
   virtual void OnInitCmdLine(wxCmdLineParser& parser);
   virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
};

// Implements MyApp& GetApp()
DECLARE_APP(FirmwareChangerApp)

IMPLEMENT_APP( FirmwareChangerApp )

/*
 * FirmwareChangerApp type definition
 */
IMPLEMENT_CLASS( FirmwareChangerApp, wxApp )

/*
 * FirmwareChangerApp event table definition
 */
BEGIN_EVENT_TABLE( FirmwareChangerApp, wxApp )

END_EVENT_TABLE()

/*
 * Constructor for FirmwareChangerApp
 */
FirmwareChangerApp::FirmwareChangerApp() :
openLog(),
consoleIsAttached(false)
{
   Init();
   (void)wxGetApp(); // To avoid warning
}

/*
 * Member initialisation
 */
void FirmwareChangerApp::Init() {
}

/*
 * Initialisation for FirmwareChangerApp
 */
bool FirmwareChangerApp::OnInit() {
   LOGGING;

#if wxUSE_XPM
   wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
   wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
   wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
   wxImage::AddHandler(new wxGIFHandler);
#endif

   //#ifndef _WIN32
   //   // Otherwise wxWidgets doesn't look in the correct location
   //   ((wxStandardPaths&)wxStandardPaths::Get()).SetInstallPrefix(_(USBDM_INSTALL_DIRECTORY));
   //#endif

   SetAppName(_("usbdm")); // So application files are kept in the correct directory

   // Create application dialogue. Will first be used to parse the command line
   dialogue = new FirmwareChangerDialogue(NULL);

   // Call for default command parsing behaviour
   if (!wxApp::OnInit()) {
      log.error("Failed OnInit()\n");
      applicationRC = CMD_LINE_ILLEGAL_COMMAND;
   }
   else if(applicationRC == CMD_LINE_OK){
      if (USBDM_Init() == BDM_RC_OK) {
         if(dialogue->inGUIMode()){
            // Create empty app settings
            appSettings.reset(new AppSettings (configFileName, "Firmware Changer"));
            appSettings->load();
            dialogue->loadSettings(*appSettings);
            dialogue->Init();
            dialogue->setAutoLoad(dialogue->doAutoLoad());
            SetTopWindow(dialogue);
            dialogue->ShowModal();
            dialogue->saveSettings(*appSettings);
            appSettings->save();
         }
         else{
            attachConsole();
            applicationRC = dialogue->doCommandLineProgram();
            if(dialogue->consoleIsEnabled()){
               if(applicationRC != FLASH_ERR_OK){
                  fprintf(stderr, "%s\n", dialogue->getConsoleMessage().c_str());
               }
               else{
                  fprintf(stdout, "%s\n", dialogue->getConsoleMessage().c_str());
               }
            }
            freeConsole();
         }
      }
      else{
         log.error("Failed to initialize USB interface");
         if(!dialogue->inGUIMode()){
            attachConsole();
            if(dialogue->consoleIsEnabled()){
               fprintf(stderr, "Failed to initialize USB interface\n");
            }
            freeConsole();
         }
         applicationRC = FLASH_ERR_FAIL;
      }
   }
   dialogue->Destroy();
   return true; // Return true regardless as we want OnRun() to execute
}

/*
 * Run function for FirmwareChangerApp
 */
int FirmwareChangerApp::OnRun(){
   LOGGING;

   // Everything is done in OnInit()
   if(applicationRC != FLASH_ERR_OK){
      log.error("Firmware update failed");
   }
   return applicationRC;
}

/*
 * Cleanup for FirmwareChangerApp
 */
int FirmwareChangerApp::OnExit() {
   LOGGING;
   return wxApp::OnExit();
}

static const std::string returnCodeText = std::string("\nReturn codes:\n") +
      "\t0 = SUCCESS\n" +
      "\t1 = FAILURE\n" +
      "\t2 = INVALID PARAMETER\n"   +
      "\t3 = INVALID COMMAND";
static const wxCmdLineEntryDesc g_cmdLineDesc[] = {
      { wxCMD_LINE_PARAM,      NULL,          NULL, _("Firmware file (including path)"),          wxCMD_LINE_VAL_STRING,  wxCMD_LINE_PARAM_OPTIONAL },
      { wxCMD_LINE_SWITCH,     _("auto"),     NULL, _("Auto select & load firmware file")      },
      { wxCMD_LINE_OPTION,     _("serial"),   NULL, _("Serial number to write to BDM device"),    wxCMD_LINE_VAL_STRING },
      { wxCMD_LINE_SWITCH,     _("program"),  NULL, _("Program and verify flash contents"),    },
      { wxCMD_LINE_SWITCH,     _("verify"),   NULL, _("Verify flash contents")                 },
      { wxCMD_LINE_SWITCH,     _("verbose"),  NULL, _("Print progress messages to stdout")     },
#ifdef _WIN32
      { wxCMD_LINE_SWITCH,     _("console"),  NULL, _("Enable output to stdout and stderr")    },
#endif
      { wxCMD_LINE_SWITCH,     _("help"),     NULL, _("Show this help message"),                   wxCMD_LINE_VAL_NONE,    wxCMD_LINE_OPTION_HELP },
      { wxCMD_LINE_USAGE_TEXT, NULL,          NULL, _(returnCodeText)                          },
      { wxCMD_LINE_NONE }
};

void FirmwareChangerApp::OnInitCmdLine(wxCmdLineParser& parser) {
   parser.SetDesc (g_cmdLineDesc);
   // must refuse '/' as parameter starter or cannot use "/path" style paths
   parser.SetSwitchChars (_("-"));
   parser.SetLogo(_("Firmware Changer \n"));

#if (wxCHECK_VERSION(2, 9, 0))
   parser.AddUsageText(_(
         "\nExamples:\n"
         "-auto -program\n"
         "   Auto-select firmware file and program BDM device\n"
         "-program -serial=USBDM-JS16-SWD_SER-0001 Image.sx\n"
         "   This will program and set the serial number of the BDM "
   ));
#ifdef _WIN32
   parser.AddUsageText(_("\nRecommendation! When running as console, use \"start/wait\" to execute the application."
         " For example:\n\tstart/wait FirmwareChanger -auto -program"));
#endif // _WIN32
#endif
}

//! Process command line arguments
//!
bool FirmwareChangerApp::OnCmdLineParsed(wxCmdLineParser& parser) {

   applicationRC = dialogue->parseCommandLine(parser);
   if (applicationRC != CMD_LINE_OK) {
      parser.Usage();
   }
   return true; // return true regardless to catch unknown/illegal command line option in OnInit()
}

void FirmwareChangerApp::attachConsole(){
   LOGGING;

   if(consoleIsAttached){
      return;
   }

#ifndef linux
   if ((GetConsoleWindow() == NULL) && dialogue->consoleIsEnabled()) {
      if(AttachConsole(ATTACH_PARENT_PROCESS)){
         consoleIsAttached = true;
         log.print("Parent console attached\n");
      }
      else{
         log.print("Unable to attach parent console. Error: %lu\n", GetLastError());
      }
      if(consoleIsAttached){
         freopen("CONOUT$", "w", stdout);
         freopen("CONOUT$", "w", stderr);
      }
      // Set stdout to no buffering; stderr is unbuffered by default
      setvbuf(stdout, NULL, _IONBF, 0);
   }
#else
   consoleIsAttached = true;
#endif
}

void FirmwareChangerApp::freeConsole(){
   LOGGING;

   if(!consoleIsAttached){
      return;
   }
#ifndef linux
   FreeConsole();
   consoleIsAttached = false;
   log.print("Console detached\n");
#else
   consoleIsAttached = false;
#endif
}
