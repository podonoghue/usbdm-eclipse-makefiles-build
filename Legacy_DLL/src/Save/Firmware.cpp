/*! \file
   \brief Entry points for USBDM library

   \verbatim
   USBDM interface DLL
   Copyright (C) 2008  Peter O'Donoghue

   Based on
      Opensource BDM  - interface DLL

   which is based on
      TBDML interface DLL by
      Copyright (C) 2005  Daniel Malik

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
+=================================================================================
| 21 May 2010 | Cleaned up some undefined behaviour for zero size JTAG ops   - pgo
| 16 Apr 2010 | Change RS08 flash handling for V3 USBDMithConfig()           - pgo
| 17 Feb 2010 | Added check for T_OFF in SetTargetTypeWithConfig()           - pgo
|  1 Aug 2009 | Change to USBDM + wrappers for TBDML, OSBDM & TBLCF          - pgo
|  1 Jan 2009 | Changed to common file for TBDML, OSBDM & TBLCF dlls         - pgo
| 27 Dec 2008 | Added extendedConnect() to target_sync()                     - pgo
+=================================================================================
\endverbatim
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <wx/wx.h>
#include <wx/progdlg.h>
#include "Log.h"
#include "Version.h"
#include "Common.h"
//#include "ICP.h"
#include "USBDM_API.h"
#include "USBDM_AUX.h"
#include "USBDM_API_Private.h"
#include "low_level_usb.h"
//#include "configure.h"
#include "Names.h"
#include "TargetDefines.h"
#include "ApplicationFiles.h"
#include "CustomMessageBox.h"

#include "Firmware.h"

//! BDM microcontroller types
static const wxChar *BDMCPUTypes[] = { _("JB16"), _("????"), _("JMxx"), _("UF32") };

// Version information available in driver DLL
static U8 availableSoftwareVersion; //!< Firmware version contained in this DLL
static U8 availableHardwareVersion; //!< BMD hardware version that Firmware is intended for

//! Text description of BDM hardware detected
static wxString hardwareDescription = _("Unknown");

#include "FirmwareImage.h" // Contains the BDM Firmware

//============================================================================
//! \brief Update BDM Firmware
//!
//! The BDM interface is re-opened afterwards
//!
//! @param flashImage - The image to program into the BDM flash
//!
//! @return \n
//!         == 0 => sucess \n
//!         != 0 => fail
static USBDM_ErrorCode updateFirmware(FlashImage *flashImage) {
   USBDM_ErrorCode  rc;
   unsigned int  numDevices;
   int  retry;
   USBDM_Version_t USBDM_Version;

   wxMessageBox(_("Please remove any target hardware and then press OK to continue\n"),
                _("Preparing for firmware update"));

   wxProgressDialog dialogue(_("Accessing BDM"),
                             _("Rebooting to ICP mode..."),
                             100,
                             NULL,
                             wxPD_APP_MODAL|wxPD_ELAPSED_TIME|wxPD_AUTO_HIDE
                             );
   dialogue.Update(0, _("Rebooting...."));

   print("updateFirmware: Doing ICP reboot\n");
   // Cause BDM to reboot into ICP mode (ignored if already in ICP mode)
   USBDM_RebootToICP();

   // Connection is lost so close it.
   bdm_usb_close(); // Connection is lost on reboot so close it.

   retry = 10;
   do { // Retry connection to allow for reboot, re-enumeration time
      milliSleep(1000);
      USBDM_FindDevices(&numDevices);
   } while ((numDevices <= 0) && (retry-- > 0));

   rc = USBDM_Open(0);
   if (rc != BDM_RC_OK) {
      print("updateFirmware: Failed to re-open after reboot\n");
      return rc;
   }
   // Check version & in ICP mode
   print("updateFirmware: Checking Version & in ICP mode\n");
   rc = USBDM_GetVersion(&USBDM_Version);
   if (rc != BDM_RC_OK) { // Failed
      print("updateFirmware: Failed to reboot to get SW/HW Version\n");
      return BDM_RC_FAIL;
   }
   if (USBDM_Version.bdmSoftwareVersion != 0xFF) { // Not in ICP mode
      print("updateFirmware: Failed to reboot to ICP mode\n");
      return BDM_RC_FAIL;
   }
   if (USBDM_Version.bdmHardwareVersion != availableHardwareVersion) { // HW version incorrect
      print("updateFirmware: H/W version changed after re-boot, originally 0x%2.2X, now 0x%2.2X!\n",
            availableHardwareVersion, USBDM_Version.bdmHardwareVersion);
      return BDM_RC_FAIL;
   }
   // Erase Flash image area (ICP area is protected)
   dialogue.Update(10, _("Erasing BDM Firmware...."));
   print("updateFirmware: Erasing\n");
   rc = (USBDM_ErrorCode)USBDM_ICP_Erase(flashImage->loadAddr, flashImage->size);
   if (rc != BDM_RC_OK) {
      print("updateFirmware: Failed to erase\n");
      return rc;
   }
   // Program the new code
   dialogue.Update(28, _("Programming BDM Firmware...."));
   print("updateFirmware: Programming\n");
   rc = (USBDM_ErrorCode)USBDM_ICP_Program(flashImage->loadAddr, flashImage->size,
                                           flashImage->data);
   if (rc != BDM_RC_OK) {
      print("updateFirmware: Failed to program\n");
      return rc;
   }
   dialogue.Update(56, _("Verifying BDM Firmware...."));
   // Verify the new code
   print("updateFirmware: Verifying\n");
   rc = (USBDM_ErrorCode)USBDM_ICP_Verify(flashImage->loadAddr, flashImage->size,
                                          flashImage->data);
   if (rc != BDM_RC_OK) {
      print("updateFirmware: Failed to verify\n");
      return rc;
   }
   dialogue.Update(90, _("Doing normal re-boot...."));
   fprintf(stderr, "doFirmware(): Doing Normal reboot (ignore errors)\r\n"); fflush(stderr);
   USBDM_ICP_Reboot();   // Cause Target to reboot into normal mode
   USBDM_Close();        // Connection is lost on reboot so close it.
   retry = 10;
   do { // Retry connection to allow for reboot, re-enumeration time
      milliSleep(1000);
      (void)USBDM_FindDevices(&numDevices);
   } while ((numDevices <= 0) && (retry-- > 0));

   dialogue.Update(100, _("BDM Access Complete"));
   dialogue.Show(false);
   if ((numDevices <= 0) || (USBDM_Open(0) != BDM_RC_OK)) {
      print("updateFirmware: Failed to re-open after 2nd reboot\n");
      return BDM_RC_NO_USBDM_DEVICE;
   }
   print("updateFirmware: Successful\n");

   wxMessageBox(_("The update of the BDM Firmware has completed successfully.\n"),
                _("Firmware Update Completed"));

   return BDM_RC_OK;
}

//============================================================================
//! Checks if firmware is current and prompts to update if necessary
//!
//! - Checks BDM Firmware version against internal copies contained within the DLL
//! - Displays Firmware update Dialogue if out of date
//! - Optionally updates BDM Firmware
//! - Display warning dialogue if DLL & BDM firmware mismatch
//!
//! The BDM interface is re-opened.
//! Update is only done if there is a single device attached since
//! re-enumeration may change the order of devices.
//!
//! @return
//!      - == RDM_RC_OK => success \n
//!      - != BDM_RC_OK => fail, incompatible DLL/BDM firmware or
//!                        Firmware update failed, see \ref USBDM_ErrorCode
//!
USBDM_API USBDM_ErrorCode USBDM_CheckFirmware(void) {
   int getYesNo;
   USBDM_ErrorCode rc;
   unsigned int deviceCount;
   static int recurse = 0;
   FlashImage *flashImage;
   wxString CompatibilityReminderName(_("NoNagCompatibilityV2_0.txt"));
   wxString UpdateReminderName(_("NoNagUpdateV3_5.txt"));

   print("USBDM_CheckFirmware()\n");

   // Check if already updating Flash
   if (recurse) {
      print("USBDM_CheckFirmware(): recursing\n");
      return BDM_RC_OK;
   }
   if ((bdmState.compatibilityMode == C_EarlyUSBDM) &&  // Version < 2.0?
       (checkExistsApplicationFile(CompatibilityReminderName) != BDM_RC_OK)) {

      getYesNo = CustomMessageBoxDLL::DisplayMessageBox(NULL,
                           _("BDM Firmware Mismatch"),
                           _("The USBDM firmware is incompatible\n"
                             "with the interface DLL being used.\n"
                             "Please update the BDM firmware or use\n"
                             "the correct version DLL.\n\n"
                             "The BDM will operate with default\n"
                             "settings and may not be reliable.\n\n"
                             "RS08 targets are not supported.\n"),
                           wxOK,
                           _("Don't Ask again")
                           );
      if (getYesNo == (wxOK|CustomMessageBoxDLL::mbNO_DISPLAY)) {
         FILE *fp = openApplicationFile(CompatibilityReminderName, _("wt"));
         if (fp != NULL) {
            fprintf(fp, "Delete this file to restore compatibility reminders.\n");
            fclose(fp);
         }
      }
      print("USBDM_CheckFirmware(): Failed version check\n");
   }
   // Can't update if >1 device as update requires re-enumeration
   rc = bdm_usb_findDevices(&deviceCount);

   // Release the devices found!
   bdm_usb_releaseDevices();

   if ((rc != BDM_RC_OK) || (deviceCount > 1)) {
      print("USBDM_CheckFirmware(): error or >1 device - no action\n");
      return BDM_RC_OK;
   }
   if ((bdmState.BDMhardwareVersion & 0xC0) == 0) { // ICP not available via driver unless JMxx, UFxx
      print("USBDM_CheckFirmware(): ICP not available - no action\n");
      return BDM_RC_OK;
   }
   if (checkExistsApplicationFile(UpdateReminderName) == BDM_RC_OK) {
      print("USBDM_CheckFirmware(): Update check suppressed - no action\n");
      return BDM_RC_OK;
   }
   if ((bdmState.ICPhardwareVersion != bdmState.BDMhardwareVersion)
         && (bdmState.BDMhardwareVersion != 0xFF)) {
      print("Warning! - conflicting hardware versions reported by ICP and BDM firmware\n"
            " Using BDM Hardware version\n");
   }
   hardwareDescription = wxString(getHardwareDescription(bdmState.BDMhardwareVersion), wxConvUTF8);

   print("Hardware description coming up:\n");
   print("Hardware description: %s\n",
         (const char *)hardwareDescription.ToAscii());

   print("USBDM_CheckFirmware(): BDM S/W version = %1X.%1X, H/W version (from BDM) = %1X.%X\n"
         "                       ICP S/W version = %1X.%1X, H/W version (from ICP) = %1X.%X\n",
         (bdmState.BDMsoftwareVersion >> 4) & 0x0F,
         bdmState.BDMsoftwareVersion & 0x0F,
         (bdmState.BDMhardwareVersion >> 6) & 0x03,
         bdmState.BDMhardwareVersion & 0x3F,
         (bdmState.ICPsoftwareVersion >> 4) & 0x0F,
         bdmState.ICPsoftwareVersion & 0x0F,
         (bdmState.ICPhardwareVersion >> 6) & 0x03,
         bdmState.ICPhardwareVersion & 0x3F
         );

   // Check each available flash image
   for (flashImage = flashImages; flashImage < flashImages
         + sizeof(flashImages) / sizeof(flashImages[0]); flashImage++) {
      availableSoftwareVersion = flashImage->softwareVersion;
      availableHardwareVersion = flashImage->hardwareVersion;

      print("USBDM_CheckFirmware(): New Flash version   = %1X.%1X, Hardware version = %1X.%X\n",
            (availableSoftwareVersion >> 4) & 0x0F, availableSoftwareVersion
                  & 0x0F, (availableHardwareVersion >> 6) & 0x0F,
            availableHardwareVersion & 0x3F);

      if ((bdmState.BDMhardwareVersion == availableHardwareVersion) &&  // Correct H/W version and
           ((bdmState.BDMsoftwareVersion < availableSoftwareVersion) || // Later S/W version or
            (bdmState.BDMsoftwareVersion == 0xFF))) { // Already in ICP mode
         break;
      }
   }
   if (flashImage >= flashImages + sizeof(flashImages) / sizeof(flashImages[0])) {
      // No update found
      print("USBDM_CheckFirmware(): No update available \n");
      return BDM_RC_OK;
   }
   wxString dialogBodyText;
   dialogBodyText.Printf(
           _("There is a new version of the BDM firmware available.\n\n"
             "Hardware Type:  \n") +
             hardwareDescription + _("\n\n"
             "Current Firmware Version:   %4s-%d.%d\n\n"
             "Available Firmware Version: %4s-%d.%d\n\n"
             "Do you wish to update the USBDM Firmware (recommended)?"),
           BDMCPUTypes[(bdmState.ICPhardwareVersion >> 6) & 0x03],
           (bdmState.BDMsoftwareVersion == 0xFF) ?
                 0 : (bdmState.BDMsoftwareVersion >> 4) & 0xF,
           (bdmState.BDMsoftwareVersion == 0xFF) ?
                 0 : bdmState.BDMsoftwareVersion & 0xF,
           BDMCPUTypes[(bdmState.ICPhardwareVersion >> 6) & 0x03],
           (availableSoftwareVersion >> 4) & 0xF,
            availableSoftwareVersion & 0xF);

   getYesNo = CustomMessageBoxDLL::DisplayMessageBox(NULL,
                        _("BDM Firmware Update Recommended"),
                        dialogBodyText,
                        wxYES_NO,
                        _("Don't Ask again")
                        );
   if (getYesNo == (wxNO|CustomMessageBoxDLL::mbNO_DISPLAY)) {
      FILE *fp = openApplicationFile(UpdateReminderName, _("wt"));
      if (fp != NULL) {
         fprintf(fp, "Delete this file to restore update reminders.\n");
         fclose(fp);
      }
   }
   if (getYesNo & wxYES) {
      rc = updateFirmware(flashImage);
      if (rc != BDM_RC_OK) { // Failure!
         wxMessageBox(_("The update of the BDM Firmware failed.\n\n"
                        "Remove & re-insert the BDM to retry\n\n"
                        "Presss OK to continue."),
                      _("Firmware Update Failed"),
                      wxOK|wxICON_ERROR
                      );
         return BDM_RC_OK;
      }
   }
   recurse = 0;

   return BDM_RC_OK;
}
