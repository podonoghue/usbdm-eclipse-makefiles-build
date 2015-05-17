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

const char *logFilename("FirmwareChanger.log");
const char *configFileName("FirmwareChanger");

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
   FLASH_ERR_OK      = 0,
   FLASH_ERR_FAIL    = 1,
   FLASH_ERR_CANCEL  = 2,
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

#if 0
/*! Convert a single character ('0'-'9', 'a'-'f' or 'A'-'F') into a hex value
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 15
 */
unsigned int hex1ToDecimal(char **ptr) {
   uint8_t data = *(*ptr)++;
   if ((data >= '0') && (data <= '9'))
      return data - '0';
   if ((data >= 'a') && (data <= 'f'))
      return data - 'a' + 10;
   if ((data >= 'A') && (data <= 'F'))
      return data - 'A' + 10;
   return 0;
}

/*! Convert two characters ('0'-'9', 'a'-'f' or 'A'-'F') into a hex value
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 255
 */
unsigned int hex2ToDecimal( char **ptr) {
   int data  = hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   return data;
}

/*! Convert four characters ('0'-'9', 'a'-'f' or 'A'-'F') into a hex value
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 65535
 */
unsigned int hex4ToDecimal( char **ptr) {
   int data  = hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   return data;
}
#endif

//! Parses Filename
//!
const char *File_ParseTitle(char *Filename, char *Title, int MaxTitle) {
   return "A Title";
}

void bootloaderDialogue::dumpFile() {
   LOGGING_Q;

   uint32_t addr;

   for (addr = flashImageDescription.firstAddr; addr < flashImageDescription.lastAddr; addr++) {
      if (((addr & 0x001F) == 0) || (addr == flashImageDescription.firstAddr))
         log.print("%4.4X:", addr);
      log.print("%2.2X", flashImageDescription.flashImage[addr]);
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
void bootloaderDialogue::setSerialNumber(const wxString &serialNumber) {
   LOGGING;

   if (!flashImageDescription.serialNumberPresent)
      return;

   uint8_t  ICP_Offset             = flashImageDescription.flashImage[flashImageDescription.protectAddr-2]; // Offset to end of ICP block
   uint16_t ICP_Address            = flashImageDescription.protectAddr-ICP_Offset-sizeof(ICP_dataType);     // Address of ICP block
   uint16_t SN_Address             = ICP_Address + (intptr_t)&ICP_data.serialNumber - (intptr_t)&ICP_data;
   uint16_t Checksum_Address       = flashImageDescription.protectAddr-1;
   int maxSerialNumberLength  = sizeof(ICP_data.serialNumber);

   // Patch image with serial #
   strncpy((char*)&flashImageDescription.flashImage[SN_Address], serialNumber.ToUTF8(), maxSerialNumberLength);

   // Fix checksum
   uint8_t checkSum = 0;
   for (int addr = ICP_data.flashStart; addr < Checksum_Address; addr++) {
      checkSum += flashImageDescription.flashImage[addr];
   }
   log.print("Serial # address  = 0x%4X\n", SN_Address);
   log.print("Checksum          = 0x%2X\n", checkSum);
   log.print("Original checksum = 0x%2X\n", flashImageDescription.flashImage[Checksum_Address]);

   flashImageDescription.flashImage[Checksum_Address] = checkSum;
   flashImageDescription.serialNumber = serialNumber;
}

//! Runs consistency check on the Flash image file
//!
//! @param protectAddress address of protected area of Flash
//!
//! @return success/fail
//!
bool bootloaderDialogue::consistencyCheck(unsigned int protectAddress) {
   LOGGING;

   uint8_t  ICP_Offset  = flashImageDescription.flashImage[protectAddress-2]; // Offset to end of ICP block
   uint16_t ICP_Address = protectAddress-ICP_Offset-sizeof(ICP_dataType);     // Address of ICP block
   unsigned addr;

   // Copy ICP data from flash image
   memcpy(&ICP_data, flashImageDescription.flashImage+ICP_Address, sizeof(ICP_data));

   // Swap Endian
   ICP_data.flashStart        = (ICP_data.flashStart<<8)        +
                                (ICP_data.flashStart>>8);
   ICP_data.userDetectICP     = (ICP_data.userDetectICP<<8)     +
                                (ICP_data.userDetectICP>>8);

   // No serial # prior to V3.5
   flashImageDescription.serialNumberPresent = ICP_data.softwareVersion >= 0x35;

   if (ICP_data.softwareVersion < 0x35) {
      static const char dummySerialNumber[] = "<\0n\0o\0n\0e\0>\0"; // UTF-16-LE !
      memset((char*)ICP_data.serialNumber, 0, sizeof(ICP_data.serialNumber));
      memcpy((char*)ICP_data.serialNumber, dummySerialNumber, sizeof(dummySerialNumber));
   }
   unsigned char checkSum = 0;
   for (addr = ICP_data.flashStart; addr < protectAddress-1; addr++) {
      checkSum += flashImageDescription.flashImage[addr];
   }
   checkSum -= flashImageDescription.flashImage[protectAddress-1];

   log.print(  "flashStart     = %4.4X\n"
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
bool bootloaderDialogue::getICPData(void) {
// There are two possible image formats (JMxx & UF32) and no way to easily tell them apart!
   const unsigned int JMxxProtectAddress = 0xFC00;  // Start of protected area of JBxx Flash
   const unsigned int UF32ProtectAddress = 0xF800;  // Start of protected area of UF32 Flash

   return consistencyCheck(JMxxProtectAddress) ||
          consistencyCheck(UF32ProtectAddress);
}

//!   Load a Freescale S-record file into the buffer
//!
//! @param filepath    : path to file
//!
int bootloaderDialogue::loadS1S9File(const wxString &filepath) {
   LOGGING;

   FILE *fp = fopen(filepath.To8BitData(), "rt");

   fileLoaded = false;
   if (fp == NULL) {
      log.print("Failed to open input file \"%s\"\n", (const char *)filepath.To8BitData());
      return FLASH_ERR_FAIL;
   }
   log.print("Processing input file \"%s\"\n", (const char *)filepath.To8BitData());
   int rc =  loadS1S9File(fp);
   fclose(fp);
   if (rc == FLASH_ERR_OK) {
      filename = filepath;
   }
   return  rc;
}

//!   Load a Freescale S-record file into the buffer
//!
//!   Minimal error checking (file open etc, no S-record validity checks). \n
//!   A global buffer flashImageDescription is used.
//!   The buffer is cleared to 0xFF before loading \n
//!   flashImageDescription is updated appropriately
//!
//! \brief Load a Freescale S1S9 file into the flash image buffer
//!
//! @param fp : handle of already opened file
//!
int bootloaderDialogue::loadS1S9File(FILE *fp) {
   LOGGING;
   char *ptr;
   unsigned int  addr;
   unsigned int  size;
   unsigned int  data;
   char buffer[200];
   uint16_t  firstAddr = 0xFFFF;
   uint16_t  lastAddr  = 0x0000;
   wxString filename;

   filename   = wxEmptyString;
   fileLoaded = false;

   // Clear File information
   fileInformationStaticTextControl->SetLabel(wxEmptyString);

   memset(flashImageDescription.flashImage, 0xFF, sizeof(flashImageDescription.flashImage));

   while (fgets(buffer, sizeof(buffer)-1, fp) != NULL) {
      //log.print("Input:\"%s\"\n",buffer);
      ptr = buffer;
      if ((*ptr++ != 'S') || (*ptr++ != '1'))
         continue;
      size = hex2ToDecimal( &ptr );
      addr = hex4ToDecimal( &ptr );
      //log.print("(%2.2X)%4.4X:",size,addr);
      size -= 3;
      while (size-->0){
         data = hex2ToDecimal( &ptr );
         //log.print("%2.2X",data);
         //if (addr >= ProtectAddress)
         //   continue;
         if (addr < firstAddr)
            firstAddr = addr;
         if (addr > lastAddr)
            lastAddr = addr;
         flashImageDescription.flashImage[addr++] = data;
      }
      //log.print("\n");
   }
   flashImageDescription.lastAddr        = lastAddr;
   flashImageDescription.firstAddr       = firstAddr;

   // Extract the ICP information from the image
   if (!getICPData()) {
      wxMessageBox(_("Flash Image is invalid.\n"
                     "File is incorrect or corrupt?"),
                   _("Flash File Format Error"),
                   wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER
                   );
      return FLASH_ERR_FAIL;
   }
   wxString hardwareDescription(getBriefHardwareDescription(flashImageDescription.hardwareVersion), wxConvUTF8);

   //   dumpFile(&flashImageDescription);
   wxString fileInformation;
   fileInformation.Printf( (wxFormatString)_(
            "Serial # =\n"
            "  %s\n\n"
            "Hardware Version =\n"
            "  %s\n\n"
            "Software Version = %d.%d\n"
#ifdef LOG
            "Flash Start     \t\t = 0x%4.4X\n"
            "Protect Address   \t = 0x%4.4X\n"
            "Code Start Address\t = 0x%4.4X\n"
            "Code End Address  \t = 0x%4.4X\n"
            "UserDetectICP()   \t = 0x%4.4X\n"
#endif
            ),
            (const char *)flashImageDescription.serialNumber.c_str(),
            (const char *)hardwareDescription.c_str(),  // hardware version of this image (from ICP)
            flashImageDescription.softwareVersion>>4,   // software version of this image (from ICP)
            flashImageDescription.softwareVersion&0x0F
#ifdef LOG
            ,
            flashImageDescription.flashStart,            // start of user flash area (from ICP)
            flashImageDescription.protectAddr,           // deduced start of protected area
            flashImageDescription.firstAddr,             // first non-0xFF address
            flashImageDescription.lastAddr,              // last non-0xFF address
            flashImageDescription.userDetectICP          // address of userDetectICP() routine in flash
#endif
   );
//   fileInformationStaticTextControl->SetLabelText(fileInformation);
   fileInformationStaticTextControl->SetLabel(fileInformation);
   parseSerialNumber(flashImageDescription.serialNumber, serialNumberPrefix);
   fileLoaded = true;
   if (autoSequence && !autoUpdateBdm) {
      serialNumberToTextControl();
   }
   else {
      serialNumberTextControl->ChangeValue(flashImageDescription.serialNumber);
   }
   return FLASH_ERR_OK;
}

//! Open a single USBDM device
//!
//! @return error code
//!
int bootloaderDialogue::openSingleDevice(void) {
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
      errMessage = _("Too many USBDM devices found\n"
            "Only a single device may be connected during update");
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
int bootloaderDialogue::readBdmInformation(USBDM_bdmInformation_t *info) {
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
int bootloaderDialogue::readBdmSerialNumber(const char **bdmSerialNumber) {

   int rc = openSingleDevice();
   if (rc != FLASH_ERR_OK) {
      return rc;
   }
   rc = USBDM_GetBDMSerialNumber(bdmSerialNumber);
   USBDM_Close();
   if (rc != BDM_RC_OK) {
      errMessage = _("Unable to read BDM serial number.\n\n"
                     "Using default value.");
      return FLASH_ERR_FAIL;
   }
   return FLASH_ERR_OK;
}

//! Open BDM with retry
//!
USBDM_ErrorCode reOpenBDM(void) {
   LOGGING;

   int retry;
   unsigned numDevices;
   USBDM_ErrorCode rc = BDM_RC_NO_USBDM_DEVICE;

   bootloaderDialogue::icpPulseCallBack(ICP_RC_OK);
   // Connection is lost so close it.
   USBDM_Close();
   log.print("reOpenBDM(): starting\n");

   retry = 25;
   do {
      // Retry connection to allow for reboot and re-enumeration time
      // Uses USBDM_FindDevices() every time to avoid confusion with stale devices!
      bootloaderDialogue::icpPulseCallBack(ICP_RC_OK);
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

wxProgressDialog *bootloaderDialogue::progressDialogue = NULL;

extern "C"
ICP_ErrorCode_t bootloaderDialogue::icpProgressCallBack(ICP_ErrorCode_t status, unsigned int percent) {
   if (percent >= 100)
      percent = 99;
   if (progressDialogue != NULL) {
      progressDialogue->Update(percent);
   }
   return status;
}

extern "C"
ICP_ErrorCode_t bootloaderDialogue::icpPulseCallBack(ICP_ErrorCode_t status) {
   if (progressDialogue != NULL) {
      progressDialogue->Pulse();
   }
   return status;
}

//! \brief Update / verify Firmware
//!
//! @param flashImage     - The image to program/verify into the flash
//! @param updateFirmware - True to update firmware before verifying
//!
int bootloaderDialogue::doFirmware(int updateFirmware) {
   LOGGING;

   USBDM_Version_t USBDM_Version;
   int  rc;
   USBDM_ErrorCode bdm_rc = BDM_RC_OK;
   ICP_ErrorCode_t icp_rc = ICP_RC_OK;

   rc = openSingleDevice();
   if (rc != FLASH_ERR_OK) {
      return rc;
   }
   bdm_rc = USBDM_GetVersion(&USBDM_Version);
   if (bdm_rc != BDM_RC_OK) {
      errMessage = _("Unable to determine BDM Version\n"
            "Device is not a USBDM?");
      USBDM_Close();
      return FLASH_ERR_FAIL;
   }
   if ((USBDM_Version.bdmHardwareVersion&0xC0)==0) {
      errMessage = _("JB16 USBDMs cannot be updated or verified\n"
            "using this software.\n"
            "Please use the Freescale ICP utility");
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
#endif
   wxProgressDialog pd(_("Accessing BDM"),
         _(""),
         100,
         this,
         wxPD_APP_MODAL|wxPD_ELAPSED_TIME
   );
   progressDialogue = &pd;

   try {
      bdm_rc = BDM_RC_OK;
      if (USBDM_Version.bdmSoftwareVersion != 0xFF) { // Not already in ICP mode
         progressDialogue->Update(0, _("Rebooting to ICP mode..."));
         log.print("doFirmware(): Doing ICP reboot of BDM\n");
         // Cause Target to reboot into ICP mode (ignored if already in ICP mode)
         USBDM_RebootToICP();
         int getYesNo = wxNO;
         do {
            // Try opening (should now be in ICP mode)
            bdm_rc = reOpenBDM();
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
         USBDM_ICP_SetCallback(icpProgressCallBack);
         progressDialogue->Update(0, _("Erasing BDM Firmware..."));
         log.print("doFirmware(): Erasing\n");
         icp_rc = USBDM_ICP_Erase( flashImageDescription.firstAddr,
               flashImageDescription.protectAddr-flashImageDescription.firstAddr );
         if (icp_rc != ICP_RC_OK) {
            log.print("doFirmware(): Erasing failed\n");
            errMessage = _("Failed to erase\r\n");
            throw FLASH_ERR_FAIL;
         }
         //dumpFile(flashImageDescription);
         // Program the new code
         USBDM_ICP_SetCallback(icpProgressCallBack);
         progressDialogue->Update(0, _("Programming BDM Firmware..."));
         log.print("doFirmware(): Programming\n");
         icp_rc = USBDM_ICP_Program( flashImageDescription.firstAddr,
               flashImageDescription.protectAddr-flashImageDescription.firstAddr,
               &flashImageDescription.flashImage[flashImageDescription.firstAddr] );
         if (icp_rc != ICP_RC_OK) {
            log.print("doFirmware(): Programming failed\n");
            errMessage = _("Programming Failed\r\n");
            throw FLASH_ERR_FAIL;
         }
      }
      progressDialogue->Update(0, _("Verifying BDM Firmware..."));
      // Verify the firmware
      log.print("doFirmware(): Verifying\n");
#ifdef DEBUG_VER
      for (int i=0; i<1000; i++) {
         log.print("doFirmware(): Verifying # %d\r\n", i);
#endif
#if !defined(DONT_VERIFY)
         USBDM_ICP_SetCallback(icpProgressCallBack);
         icp_rc = USBDM_ICP_Verify( flashImageDescription.firstAddr,
               flashImageDescription.protectAddr-flashImageDescription.firstAddr,
               &flashImageDescription.flashImage[flashImageDescription.firstAddr] );
         if (icp_rc != ICP_RC_OK) {
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
   progressDialogue->Update(0, _("Doing normal re-boot..."));
   log.print("doFirmware(): Doing Normal reboot (ignore errors)\n");
   USBDM_ICP_Reboot();   // Cause Target to reboot into normal mode
   if (reOpenBDM() != BDM_RC_OK) {
      // Try manual reboot
      wxMessageBox(_("Please manually reboot the BDM by removing it from \n"
                    "the PC and then replacing it after a brief wait.\n\n"
                    "Click OK when ready"),
                   _("Automatic Reboot Failed"),
                   wxOK|wxSTAY_ON_TOP|wxCENTER,
                   this
                   );
   }
   if (reOpenBDM() != BDM_RC_OK) {
      errMessage = _("Failed to re-open after 2nd reboot\r\n");
      statusStaticTextControl->SetLabel(_("Status: Last flash operation failed"));
      return FLASH_ERR_FAIL;
   }
   progressDialogue->Close();
   progressDialogue = NULL;
   log.print("doFirmware() getting serial #\n");

   const char *buffer;
   USBDM_GetBDMSerialNumber(&buffer);
   log.print("Serial #%s\n", (const char *)convertUtfToString(buffer).ToAscii());

   USBDM_Close();

   statusStaticTextControl->SetLabel(_("Status: Last flash operation successful"));
   log.print("doFirmware(): Successful\n");

   return rc;
}

/*
 * bootloaderDialogue type definition
 */
IMPLEMENT_DYNAMIC_CLASS( bootloaderDialogue, wxDialog )

/*
 * bootloaderDialogue event table definition
 */
BEGIN_EVENT_TABLE( bootloaderDialogue, wxDialog )
   EVT_BUTTON( ID_FILE_LOAD_BUTTON,             bootloaderDialogue::OnFileLoadButtonClick )
   EVT_TEXT(   ID_SERIALNUM_TEXTCTRL,           bootloaderDialogue::OnSerialnumTextctrlTextUpdated )
   EVT_TEXT(   ID_AUTO_SEQUENCE_TEXTCTRL,       bootloaderDialogue::OnAutoSequenceTextControlTextUpdated )

//   EVT_TEXT(   ID_AUTO_SEQUENCE_TEXTCTRL,       bootloaderDialogue::OnAutosequenceTextctrlTextUpdated )
   EVT_BUTTON( ID_READ_SERIAL_NUM_BUTTON,       bootloaderDialogue::OnReadSerialNumButtonClick )
   EVT_CHECKBOX( ID_AUTO_SEQUENCE_CHECKBOX,     bootloaderDialogue::OnAutoSequenceCheckboxClick )
   EVT_CHECKBOX( ID_AUTO_SELECT_FILE_CHECKBOX,  bootloaderDialogue::OnAutoUpdateBdmCheckboxClick )

   EVT_BUTTON( ID_PROGRAM_FLASH_BUTTON,         bootloaderDialogue::OnProgramFlashButtonClick )
   EVT_BUTTON( ID_VERIFY_FLASH_BUTTON,          bootloaderDialogue::OnVerifyFlashButtonClick )
   EVT_BUTTON( ID_EXIT_BUTTON,                  bootloaderDialogue::OnExitButtonClick )
END_EVENT_TABLE()

/*
 * bootloaderDialogue constructors
 */
bootloaderDialogue::bootloaderDialogue() {
    Init();
}

bootloaderDialogue::bootloaderDialogue( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style ) {

    Init();
    Create(parent, id, caption, pos, size, style);
}

/*
 * bootloaderDialogue creator
 */
bool bootloaderDialogue::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style ) {
   SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
   wxDialog::Create( parent, id, caption, pos, size, style );
   CreateControls();
   if (GetSizer()) {
      GetSizer()->SetSizeHints(this);
   }
   Centre();
   return true;
}

/*
 * bootloaderDialogue destructor
 */
bootloaderDialogue::~bootloaderDialogue() {
}

/*
 * Member initialisation
 */
void bootloaderDialogue::Init() {
   LOGGING;

   log.print("bootloaderDialogue::Init()\n");

   loadSourceButtonControl          = NULL;
   filenameStaticTextControl        = NULL;
   serialNumberTextControl          = NULL;
   readSerialNumberButtonControl    = NULL;
   fileInformationStaticTextControl = NULL;
   statusStaticTextControl          = NULL;
   programFlashButtonControl        = NULL;
   verifyButtonControl              = NULL;
   exitButtonControl                = NULL;
   autoSequenceControl              = NULL;
   autoSelectFileControl            = NULL;
   autoSequenceTextControl          = NULL;

   serialNumber                     = wxEmptyString;
   serialNumberPrefix               = wxEmptyString;
   autoSequence                     = false;
   autoSequenceNumber               = 1;
   autoUpdateBdm                    = false;
   fileLoaded                       = false;
}

//!
//! @param settings      - Object to load settings from
//!
void bootloaderDialogue::loadSettings(const AppSettings &settings) {
   LOGGING_E;

   autoUpdateBdm      = settings.getValue("autoUpdateBdm",          true);
   autoSequence       = settings.getValue("autoSequence",           false);
   autoSequenceNumber = settings.getValue("autoSequenceNumber",     1);
   serialNumber       = wxString(settings.getValue("serialNumber", "USBDM").c_str(), wxConvUTF8);
   parseSerialNumber(serialNumber, serialNumberPrefix);
}

//! Save setting file
//!
//! @param settings      - Object to save settings to
//!
void bootloaderDialogue::saveSettings(AppSettings &settings) {
   LOGGING_E;

   settings.addValue("autoUpdateBdm",      autoUpdateBdm);
   settings.addValue("autoSequence",       autoSequence);
   settings.addValue("autoSequenceNumber", autoSequenceNumber);
   settings.addValue("serialNumber",       serialNumber.ToAscii());
}

/*
 * Control creation for bootloaderDialogue
 */
void bootloaderDialogue::CreateControls() {
   LOGGING_E;

   bootloaderDialogue* itemDialog1 = this;

   wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
   itemDialog1->SetSizer(itemBoxSizer2);

   //==========================================================================
   wxStaticBox* itemStaticBoxSizer3Static = new wxStaticBox(itemDialog1, wxID_ANY, _("File to Load"));
   wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(itemStaticBoxSizer3Static, wxVERTICAL);
   itemBoxSizer2->Add(itemStaticBoxSizer3, 0, wxGROW|wxALL, 5);

   wxBoxSizer* itemBoxSizer3a = new wxBoxSizer(wxHORIZONTAL);
   itemStaticBoxSizer3->Add(itemBoxSizer3a, 0, wxGROW|wxALL, 5);

   loadSourceButtonControl = new wxButton( itemDialog1, ID_FILE_LOAD_BUTTON, _("&Load Source File"), wxDefaultPosition, wxDefaultSize, 0 );
   itemBoxSizer3a->Add(loadSourceButtonControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

   autoSelectFileControl = new wxCheckBox( itemDialog1, ID_AUTO_SELECT_FILE_CHECKBOX, _("Auto select BDM firmware"), wxDefaultPosition, wxDefaultSize, 0 );
   autoSelectFileControl->SetValue(autoUpdateBdm);
   itemBoxSizer3a->Add(autoSelectFileControl, 0, wxALIGN_LEFT|wxALL|wxALIGN_CENTER_VERTICAL, 5);

   filenameStaticTextControl = new wxStaticText( itemDialog1, wxID_STATIC, _("No file loaded"), wxDefaultPosition, wxDefaultSize, 0 );
   itemStaticBoxSizer3->Add(filenameStaticTextControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

   //==========================================================================
   wxStaticBox* itemStaticBoxSizer6Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Serial Number"));
   wxStaticBoxSizer* itemStaticBoxSizer6 = new wxStaticBoxSizer(itemStaticBoxSizer6Static, wxVERTICAL);
   itemBoxSizer2->Add(itemStaticBoxSizer6, 0, wxGROW|wxALL, 5);

   wxBoxSizer* itemBoxSizer6a = new wxBoxSizer(wxHORIZONTAL);
   itemStaticBoxSizer6->Add(itemBoxSizer6a, 0, wxGROW|wxALL, 5);

   serialNumberTextControl = new wxTextCtrl( itemDialog1, ID_SERIALNUM_TEXTCTRL, serialNumber, wxDefaultPosition, wxDefaultSize, 0 );
   serialNumberTextControl->SetMaxLength(sizeof(ICP_data.serialNumber));
   serialNumberTextControl->SetValue(serialNumber);
   serialNumberTextControl->Enable(!autoSequence);
   itemBoxSizer6a->Add(serialNumberTextControl, 1, wxEXPAND|wxALL, 5);

   autoSequenceTextControl = new NumberTextEditCtrl( itemDialog1, ID_AUTO_SEQUENCE_TEXTCTRL, _(""), wxDefaultPosition, wxDefaultSize, 0 );
   autoSequenceTextControl->SetMaxLength(5);
   autoSequenceTextControl->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
   autoSequenceTextControl->Enable(autoSequence);
   autoSequenceTextControl->SetDecimalValue(autoSequenceNumber);
   itemBoxSizer6a->Add(autoSequenceTextControl, 0, wxALL, 5);

   wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
   itemStaticBoxSizer6->Add(itemBoxSizer6, 0, wxGROW|wxALL, 5);

   readSerialNumberButtonControl = new wxButton( itemDialog1, ID_READ_SERIAL_NUM_BUTTON, _("Read from Device"), wxDefaultPosition, wxDefaultSize, 0 );
   itemBoxSizer6->Add(readSerialNumberButtonControl, 1, wxALIGN_LEFT|wxALL, 5);

   autoSequenceControl = new wxCheckBox( itemDialog1, ID_AUTO_SEQUENCE_CHECKBOX, _("Auto sequence"), wxDefaultPosition, wxDefaultSize, 0 );
   autoSequenceControl->SetValue(autoSequence);
   itemBoxSizer6->Add(autoSequenceControl, 0, wxALIGN_LEFT|wxALL|wxALIGN_CENTER_VERTICAL, 5);

   //==========================================================================
   wxStaticBox* itemStaticBoxSizer5Static = new wxStaticBox(itemDialog1, wxID_ANY, _("File Information"));
   wxStaticBoxSizer* itemStaticBoxSizer5 = new wxStaticBoxSizer(itemStaticBoxSizer5Static, wxHORIZONTAL);
   itemBoxSizer2->Add(itemStaticBoxSizer5, 0, wxGROW|wxALL, 5);

   fileInformationStaticTextControl = new wxStaticText( itemDialog1, wxID_STATIC, _("Information about the loaded file"), wxDefaultPosition, wxSize(300, 200), 0 );
   itemStaticBoxSizer5->Add(fileInformationStaticTextControl, 0, wxGROW|wxALL, 5);

   //==========================================================================
   statusStaticTextControl = new wxStaticText( itemDialog1, wxID_STATIC, _("Status: Idle"), wxDefaultPosition, wxDefaultSize, 0 );
   itemBoxSizer2->Add(statusStaticTextControl, 0, wxGROW|wxALL, 5);

   //==========================================================================
   wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
   itemBoxSizer2->Add(itemBoxSizer8, 0, wxGROW|wxALL, 5);

   programFlashButtonControl = new wxButton( itemDialog1, ID_PROGRAM_FLASH_BUTTON, _("&Program Flash"), wxDefaultPosition, wxDefaultSize, 0 );
   programFlashButtonControl->Enable(false);
   itemBoxSizer8->Add(programFlashButtonControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

   itemBoxSizer8->Add(5, 5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

   verifyButtonControl = new wxButton( itemDialog1, ID_VERIFY_FLASH_BUTTON, _("&Verify Flash"), wxDefaultPosition, wxDefaultSize, 0 );
   verifyButtonControl->Enable(false);
   itemBoxSizer8->Add(verifyButtonControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

   itemBoxSizer8->Add(5, 5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

   exitButtonControl = new wxButton( itemDialog1, ID_EXIT_BUTTON, _("&Exit"), wxDefaultPosition, wxDefaultSize, 0 );
   itemBoxSizer8->Add(exitButtonControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

   if (autoSequence) {
      serialNumberToTextControl();
   }
}

/*
 * Should we show tooltips?
 */
bool bootloaderDialogue::ShowToolTips() {
    return true;
}

/*
 * Get bitmap resources
 */
wxBitmap bootloaderDialogue::GetBitmapResource( const wxString& name ) {

    wxUnusedVar(name);
    return wxNullBitmap;
}

/*
 * Get icon resources
 */
wxIcon bootloaderDialogue::GetIconResource( const wxString& name ) {

    wxUnusedVar(name);
    return wxNullIcon;
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FILE_LOAD_BUTTON
 */
void bootloaderDialogue::OnFileLoadButtonClick( wxCommandEvent& event ) {
   wxString caption = _("Choose a firmware file");
   wxString wildcard = _("Hex files (*.sx,*.s1?)|*.sx;*.s1?|All Files|*");
   wxString defaultDir = wxEmptyString;
   wxString defaultFilename = wxEmptyString;
   wxFileDialog dialog(this, caption, defaultDir, defaultFilename, wildcard, wxFD_OPEN);
   if (dialog.ShowModal() == wxID_OK) {
      loadS1S9File(dialog.GetPath());
      if (fileLoaded) {
         // Update so just the filename
         wxString firmwareFilename = dialog.GetFilename();
         filename = firmwareFilename;
      }
   }
   updateControls();
}

/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL
 */
void bootloaderDialogue::OnSerialnumTextctrlTextUpdated( wxCommandEvent& event ) {
}

/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL
 */
void bootloaderDialogue::OnAutoSequenceTextControlTextUpdated( wxCommandEvent& event ) {
   autoSequenceNumber = autoSequenceTextControl->GetDecimalValue();
   serialNumberToTextControl();
}

int bootloaderDialogue::readSerialNumber(void) {
   const char *bdmDescription;
   int rc = readBdmSerialNumber(&bdmDescription);
   if (rc != FLASH_ERR_OK) {
      wxMessageBox(errMessage,
                   _("Reading serial number failed"),
                   wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                   this
                   );
      return rc;
   }
   serialNumber = convertUtfToString(bdmDescription);
   serialNumberTextControl->ChangeValue(serialNumber);

   textControlToSerialNumber();
   return rc;
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */
void bootloaderDialogue::OnReadSerialNumButtonClick( wxCommandEvent& event ) {
   if ((readSerialNumber() == FLASH_ERR_OK) &&
        autoSequence) {
      serialNumberToTextControl();
   }
}

void bootloaderDialogue::serialNumberToTextControl(void) {
   LOGGING;

   serialNumber  = serialNumberPrefix;
   serialNumber += wxString::Format(_("-%04d"), autoSequenceNumber);
   serialNumberTextControl->SetValue(serialNumber);
   log.print("bootloaderDialogue::serialNumberToTextControl(): s=\'%s\' p=\'%s\'\n",
         (const char *)serialNumber.c_str(),
         (const char *)serialNumberPrefix.c_str()
         );
}

void bootloaderDialogue::parseSerialNumber(const wxString &serialNumber, wxString &serialNumberPrefix) {
   unsigned separatorIndex = serialNumber.length()-1;
   while (isdigit((char)serialNumber.at(separatorIndex))) {
      separatorIndex--;
   }
   if (serialNumber.at(separatorIndex) == '-') {
      separatorIndex--;
   }
   if (separatorIndex>(sizeof(ICP_data.serialNumber)-5)) {
      separatorIndex = sizeof(ICP_data.serialNumber)-5;
   }
   serialNumberPrefix = serialNumber.substr(0,separatorIndex+1);
}

void bootloaderDialogue::textControlToSerialNumber(void) {
   LOGGING_Q;

   parseSerialNumber(serialNumberTextControl->GetValue(), serialNumberPrefix);
   log.print(" s=\'%s\' p=\'%s\'\n",
         (const char *)serialNumber.c_str(),
         (const char *)serialNumberPrefix.c_str()
         );
}

/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_BUTTON
 */
void bootloaderDialogue::OnAutoSequenceCheckboxClick( wxCommandEvent& event ) {
   LOGGING_Q;
   autoSequence = event.IsChecked();
   log.print(", value = %s\n", autoSequence?"True":"False");
   if (autoSequence) {
      // Auto turned on
      // Create serial number from existing text + auto serial number
      textControlToSerialNumber();
   }
   serialNumberToTextControl();
   updateControls();
}

char *firmwareFilepaths[100] = {0};

int bootloaderDialogue::loadUpdateInformation() {
   LOGGING;
   string flashImageListFile("FlashImages/FlashImagesList.txt");
   string path = UsbdmSystem::getApplicationPath(flashImageListFile);
   FILE *fp = fopen(path.c_str(), "rt");
   if (fp == NULL) {
      wxMessageBox(_("Unable to open file image configuration file.\n"
            "Please check that USBDM has been correctly installed."),
            _("Configuration error "),
            wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
            this
      );
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
         wxMessageBox(_("Invalid file image configuration file.\n"
               "Please check that USBDM has been correctly installed."),
               _("Configuration error "),
               wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
               this
         );
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

int bootloaderDialogue::doAutoUpdate() {
   LOGGING;
   USBDM_bdmInformation_t bdmInfo;

   // Assume failure
   autoUpdateBdm = false;
   int rc = readBdmInformation(&bdmInfo);
   if (rc != FLASH_ERR_OK) {
      wxMessageBox(errMessage,
                   _("Reading BDM Information failed"),
                   wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                   this
                   );
      return rc;
   }
   unsigned bdmType = bdmInfo.ICPhardwareVersion & 0x3F;
   // Re-read the update file
   if (loadUpdateInformation() != FLASH_ERR_OK) {
      return FLASH_ERR_FAIL;
   }
   log.print("bootloaderDialogue::autoLoadFile(): ICPhardwareVersion = %d (%s)\n", bdmType, getBriefHardwareDescription(bdmType));
   if (bdmType > (sizeof(firmwareFilepaths)/sizeof(firmwareFilepaths[0])) ||
         (firmwareFilepaths[bdmType] == NULL)) {
      wxMessageBox(_("Unrecognised or unsupported BDM device   \n\n"
                     "Only JMxx or JS16 based USBDM devices \n"
                     "may be updated this way."),
                   _("Device Update Error"),
                   wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                   this
                   );
      return FLASH_ERR_FAIL;
   }
   FILE *fp = UsbdmSystem::openApplicationFile(firmwareFilepaths[bdmType]);
   if (fp == NULL) {
      wxMessageBox(_("The Flash update file cannot be opened.\n\n"
                     "Please check that USBDM has been correctly installed."),
                   _("Flash image error"),
                   wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                   this
                   );
      return FLASH_ERR_FAIL;
   }
   rc = loadS1S9File(fp);
   if (rc == FLASH_ERR_OK) {
      // Get current serial number from device (if possible)
      readSerialNumber();
      autoUpdateBdm = true;
   }
   fclose(fp);
   return rc;
}

void bootloaderDialogue::updateControls(void) {
   autoSelectFileControl->SetValue(autoUpdateBdm);
   loadSourceButtonControl->Enable(!autoUpdateBdm);
   autoSequenceTextControl->Enable(!autoUpdateBdm && autoSequence);
   serialNumberTextControl->Enable(!autoUpdateBdm && !autoSequence);
   readSerialNumberButtonControl->Enable(!autoUpdateBdm);
   autoSequenceControl->Enable(!autoUpdateBdm);
   programFlashButtonControl->Enable(fileLoaded);
   verifyButtonControl->Enable(fileLoaded);
   if (autoUpdateBdm) {
      filenameStaticTextControl->SetLabel(_("Flash image file has been automatically selected"));
   }
   else if (fileLoaded) {
      filenameStaticTextControl->SetLabel(filename);
   }
   else {
      filenameStaticTextControl->SetLabel(_("No file loaded"));
   }
   if (!autoUpdateBdm) {
      if (autoSequence) {
         serialNumberToTextControl();
      }
      else {
         textControlToSerialNumber();
      }
   }
}

//! Enable auto load
//!
void bootloaderDialogue::setAutoLoad(bool value) {
   if (value || autoUpdateBdm) {
      doAutoUpdate();
      updateControls();
   }
}

/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_BUTTON
 */
void bootloaderDialogue::OnAutoUpdateBdmCheckboxClick( wxCommandEvent& event ) {
   LOGGING_Q;

   autoUpdateBdm = event.IsChecked();
   log.print("bootloaderDialogue::OnAutoUpdateBdmCheckboxClick(), value = %s\n", autoUpdateBdm?"True":"False");
   autoUpdateBdm = false;
   if (event.IsChecked()) {
      doAutoUpdate();
   }
   updateControls();
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PROGRAM_FLASH_BUTTON
 */
void bootloaderDialogue::OnProgramFlashButtonClick( wxCommandEvent& event ) {

   // Update in case BDM has changed
   if (autoUpdateBdm && (doAutoUpdate() != FLASH_ERR_OK)) {
      updateControls();
      return;
   }
   setSerialNumber(serialNumberTextControl->GetValue());
   int rc = doFirmware(true);
   statusStaticTextControl->SetLabel(_("Status: Idle"));
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
      wxMessageBox(errMessage,
                   _("Firmware Update Failed"),
                   wxOK|wxICON_ERROR|wxSTAY_ON_TOP|wxCENTER,
                   this
                   );
   }
   if (autoSequence && !autoUpdateBdm) {
      autoSequenceTextControl->SetDecimalValue(++autoSequenceNumber);
      serialNumberToTextControl();
   }
   updateControls();
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_VERIFY_FLASH_BUTTON
 */
void bootloaderDialogue::OnVerifyFlashButtonClick( wxCommandEvent& event ) {
   int rc;

   // Update in case BDM has changed
   if (autoUpdateBdm && (doAutoUpdate() != FLASH_ERR_OK)) {
      updateControls();
      return;
   }
   setSerialNumber(serialNumberTextControl->GetValue());

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
   statusStaticTextControl->SetLabel(_("Status: Idle"));
   if (rc == FLASH_ERR_OK) {
      wxMessageBox(_("The verification of the Firmware has completed successfully.\n\n"
                     "Presss OK to continue."),
                   _("Firmware Verify Completed"),
                   wxOK|wxICON_INFORMATION|wxSTAY_ON_TOP|wxCENTER,
                   this
                   );
   }
   else if (rc == FLASH_ERR_CANCEL) {
      // Just ignore
   }
   else {
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
void bootloaderDialogue::OnExitButtonClick( wxCommandEvent& event ) {
   EndModal(0);
}

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
/*!
 * BootloaderApp class declaration
 */
class BootloaderApp: public wxApp {
    DECLARE_CLASS( BootloaderApp )
    DECLARE_EVENT_TABLE()

private:
    OpenLog openLog;
    bool doAutoLoad;

public:
    // Constructor
    BootloaderApp();

    void Init();

    // Initialises the application
    virtual bool OnInit();

    // Called on exit
    virtual int OnExit();

    virtual void OnInitCmdLine(wxCmdLineParser& parser);
    virtual bool OnCmdLineParsed(wxCmdLineParser& parser);

};

// Implements MyApp& GetApp()
DECLARE_APP(BootloaderApp)

IMPLEMENT_APP( BootloaderApp )

/*
 * BootloaderApp type definition
 */
IMPLEMENT_CLASS( BootloaderApp, wxApp )

/*
 * BootloaderApp event table definition
 */
BEGIN_EVENT_TABLE( BootloaderApp, wxApp )

END_EVENT_TABLE()

/*
 * Constructor for BootloaderApp
 */
BootloaderApp::BootloaderApp() :
   openLog(),
   doAutoLoad(false)
{
    Init();
    (void)wxGetApp(); // To avoid warning
}

/*
 * Member initialisation
 */
void BootloaderApp::Init() {
}

/*
 * Initialisation for BootloaderApp
 */
bool BootloaderApp::OnInit() {

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

   // call default behaviour (mandatory)
   if (!wxApp::OnInit()) {
       return false;
   }
   if (USBDM_Init() != BDM_RC_OK) {
      return false;
   }
   AppSettings settings(configFileName, "Firmware Changer");
   settings.load();

   bootloaderDialogue *dialogue = new bootloaderDialogue();
   dialogue->loadSettings(settings);
   dialogue->Create(NULL);
   dialogue->setAutoLoad(doAutoLoad);
   dialogue->ShowModal();
   dialogue->saveSettings(settings);
   dialogue->Destroy();

   settings.save();
   return true;
}

/*
 * Cleanup for BootloaderApp
 */
int BootloaderApp::OnExit() {

   return wxApp::OnExit();
}

static const wxCmdLineEntryDesc g_cmdLineDesc[] = {
      { wxCMD_LINE_SWITCH, _("auto"),    NULL, _("Auto select & load firmware file") },
      { wxCMD_LINE_NONE }
};

void BootloaderApp::OnInitCmdLine(wxCmdLineParser& parser) {
    parser.SetDesc (g_cmdLineDesc);
    // must refuse '/' as parameter starter or cannot use "/path" style paths
    parser.SetSwitchChars (_("-"));
    parser.SetLogo(_("USBDM Flash Programmer \n"));

#if (wxCHECK_VERSION(2, 9, 0))
    parser.AddUsageText(_(
          "\nExamples:\n"
          "-auto\n"
          "   Auto load and select firmware file"
     ));
#endif
}

//! Process command line arguments
//!
bool BootloaderApp::OnCmdLineParsed(wxCmdLineParser& parser) {
   LOGGING;
   if (parser.Found(_("auto"))) {
      doAutoLoad = true;
   }
   return true;
}
