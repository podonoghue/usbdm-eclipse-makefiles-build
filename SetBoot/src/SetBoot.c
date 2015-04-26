/*! \file
    \brief Minimal program to reboot USBDM into ICP mode

    \verbatim
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

    Change History
   +====================================================================
   |  26 Aug 2010 | Updated for Libusb V1                         - pgo
   |   1 Jan 2009 | Updated for TBLCF                             - pgo
   |  20 Oct 2008 | Fixed size of SET_BOOT command                - pgo
   +====================================================================
    \endverbatim
*/
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Common.h"
#include "USBDM_API.h"

/* the device's vendor and product id */
#define OSBDM_VID (0x15A2) //!< OSBDM Vendor ID
#define OSBDM_PID (0x0021) //!< OSBDM Product ID

#define TBDML_VID (0x0425) //!< TBDML Vendor ID
#define TBDML_PID (0x1000) //!< TBDML Product ID

#define TBLCF_VID (0x0425) //!< Vendor ID for TBLCF
#define TBLCF_PID (0x1001) //!< Product ID for TBLCF

/* the device's endpoints */
#define EP_OUT (0x02)
#define EP_IN  (0x82)

#define TIMEOUT (500)   //!< Timeouts for BDM communications

#define BUF_SIZE (5)

// Identification of BDM hardware
U8 hardwareIdentification;

/*! Check & Report Firmware/Hardware version numbers
 *
 * @return \n
 *   <= 0  => Error or ICP not supported \n
 *   == 1  => V?.? Old version of ICP (re-program flash version) \n
 *   == 2  => V1.0 Old version of ICP (temporary reboot to ICP) \n
 *   == 3  => V1.1 Old version of ICP (temporary reboot to ICP) \n
 *   == 4  => V1.2 Newest! version of ICP (temporary reboot to ICP) \n

This has to handle several different version of the ICP code.  These are
indicated by different responses to the CMD_GET_VER command \n
1. Initial release (JB16 only) - no ICP version # \n
   Version response [8 bytes] \n
   -   [0]      status          = 0C \n
   -   [1]      BDM sw version  = 01 (v0.1) \n
   -   [2]      BDM hw version  = 01 (v0.1) \n
   -   [3..7]   ?,?,?,?,?       = garbage (due to bug in original USB code?) \n
   This uses a hard ICP mode where the flash is re-programmed to permanently
   force ICP on all further resets. \n
   The user is advised to update the entire Flash as the change in the ICP code
   is significant. \n

2. August 08 release (JB16 only) - ICP V1.0 \n
   Version response [6 bytes] \n
   -   [0]      status               = 0C        \n
   -   [1]      BDM sw version       = 10 (v1.0) \n
   -   [2]      BDM hw version       = 13 (v1.3) \n
   -   [3]      ICP sw version       = 10 (v1.0) \n
   -   [4]      ICP hw version       = 00 => JB16, 80 => JMxx \n
   -   [5]      Hardware identifier  = 01 to 06 indicates hardware type \n
   This uses a soft ICP mode where the flash is unchanged but the BDM is
   immediately reset into ICP mode.  This is temporary. \n
   The user is advised to update the entire Flash as the change in the ICP code
   is significant. \n

3. September 08 release (JB16 & JMxx & UF32) - ICP V1.1 \n
   Version response [5 bytes] \n
   -   [0]      status               = 0C        \n
   -   [1]      BDM sw version       = 10 (v1.0) \n
   -   [2]      Hardware identifier  = 01 to 08 indicates hardware type (in BDM code) \n
                                       +80 for JMxx versions \n
                                       +C0 for UF32 versions \n
   -   [3]      ICP sw version       = 11 (v1.1) \n
   -   [4]      Hardware identifier  = 01 to 08 indicates hardware type (in ICP code) \n
                                      +80 for JMxx versions \n
                                      +C0 for UFxx versions \n
   As for version 2 but the hardware identification is kept in the ICP code and
   the BDM code.  These should always match!  This allows the JMxx driver to
   automatically update the BDM flash with the correct version of the Firmware
   even if the BDM flash area is corrupted. \n
   The user is advised to update the entire Flash as the change in the ICP code
   is significant. \n
4. October 08 release (JB16 & JMxx & UF32) - ICP V1.2 \n
   Version response [5 bytes] \n
   -   [0]      status               = 0x0C           \n
   -   [1]      BDM sw version       = 0xWX (ver W.X) \n
   -   [2]      Hardware identifier  = 0x01 to 0x0F indicates hardware type (in BDM code) \n
                                       +0x80 for JMxx versions \n
                                       +0xC0 for UF32 versions \n
   -   [3]      ICP sw version       = 0x12 (v1.2) \n
   -   [4]      Hardware identifier  = 0x01 to 0F indicates hardware type (in ICP code) \n
                                      +0x80 for JMxx versions \n
                                      +0xC0 for UFxx versions \n
   As for version 3 but fixes a bad bug in the JB16 ICP code!
   The user is advised to only update the BDM flash area as the ICP code is current. \n
 */


//=================================================================
//! Obtain a description of the hardware version
//!
//! @return ptr to static string describing the hardware
//!
const char *getHardwareDescription(unsigned int hardwareVersion) {
   //! BDM hardware descriptions
   static const char *hardwareDescriptions[] = {
           "Reserved",                                                                        //  0
           "USBDM-JB16 - BDM for RS08, HCS08, HCS12, CFV1 (JB16DWE)",                         //  1
           "TBDML-JB16 - Minimal BDM for HCS08, HCS12 & CFV1 (JB16)",                         //  2
           "TBDML-JB16 - Minimal TBDML (Internal version)",                                   //  3
           "OSBDM-JB16 - Original OSBDM",                                                     //  4
           "TBDML-WITZ - Witztronics TBDML/OSBDM",                                            //  5
           "OSBDM-JB16+    - Extended OSBDM (RS08 support)",                                  //  6
           "USBDM-JMxx-CLD - BDM for RS08, HCS08, HCS12, CFV1 (JMxxCLD)",                     //  7
           "USBDM-JMxx-CLC - BDM for RS08, HCS08, HCS12, CFV1 (JMxxCLC)",                     //  8
           "USBSPYDER08    - SofTec USBSPYDER08",                                             //  9
           "USBDM_UF32     - BDM for RS08, HCS08, HCS12, CFV1 (UF32PBE)",                     //  10
           "USBDM-CF-JS16  - Minimal BDM for DSC & CFVx (JS16CWJ)",                           //  11
           "USBDM-CF-JMxx  - BDM for RS08, HCS08, HCS12, CFV1 & CFVx (JMxxCLD)",              //  12
           "USBDM-JS16     - Minimal BDM for HCS08, HCS12 & CFV1 (JS16CWJ)",                  //  13
           "USBDM-AXIOM-M56F8006  - Axiom MC56F8006 Demo board",                              //  14
           "Reserved for User created custom hardware",                                       //  15
           "USBDM-CF-SER-JS16 - Minimal BDM for DSC/CFVx/ARM (JS16CWJ) with serial",          //  16
           "USBDM-SER-JS16    - Minimal BDM for HCS08, HCS12 & CFV1 (JS16CWJ) wiuth serial",  //  17
           "USBDM-CF-SER-JMxx - Deluxe BDM for RS08/HCS08/HCS12/DSC/CFVx/ARM (JMxxCLD)",      //  18
           "USBDM_TWR_KINETIS - TWR Kinetis boards",                                          //  19
           "USBDM_TWR_CFV1    - TWR Coldfire V1 boards",                                      //  20
           "USBDM_TWR_HCS08   - TWR HCS08 boards",                                            //  21
         };

   const char *hardwareName = "Unknown";
   hardwareVersion &= 0x3F; // mask out BDM processor type
   if (hardwareVersion < sizeof(hardwareDescriptions)/sizeof(hardwareDescriptions[0]))
      hardwareName = hardwareDescriptions[hardwareVersion];
   return hardwareName;
}

int reportVersion(void){
static const char *BDMCPUTypes[]={"JB16","????","JMxx","UF32"};
USBDM_Version_t version;
U8 bdmVersion;
U8 icpVersion;
U8 hardwareVersion; // Obsolete
USBDM_ErrorCode rc;

   // Get OSBDM S/W version, H/W Type
   rc = USBDM_GetVersion(&version);

   if (rc != BDM_RC_OK) {
      printf("Error: Failed to get BDM version\n");
      return -1;
   }

   bdmVersion      = version.bdmSoftwareVersion;
   hardwareVersion = version.bdmHardwareVersion;

   printf("USBDM Software Version = %d.%d\n",
             (bdmVersion>>4)&0x0F,bdmVersion&0x0F);

   printf("USBDM Hardware Version = %d.%d\n",
          (hardwareVersion>>4)&0x0F,hardwareVersion&0x0F);

   if (bdmVersion < 0x10) { // Early version, maybe old ICP
      printf("No hardware description available\n");
      return 1;
   }

   icpVersion = version.icpSoftwareVersion;

   if (bdmVersion == 0xFF) { // indicates in ICP mode on JMxx
      printf("***\nWarning: BDM appears to be already in ICP mode\n***\n");
      hardwareIdentification = version.icpHardwareVersion;
   }
   else if (icpVersion == 0x10)
      hardwareIdentification = version.icpHardwareVersion;
   else {
      hardwareIdentification = version.bdmHardwareVersion;
      if (hardwareVersion != hardwareIdentification)
         printf("***\nWarning: BDM Software and ICP software don't agree on hardware type!!\n***\n");
   }

   printf("USBDM ICP Version      = %d.%d\n",
          (icpVersion>>4)&0x0F,icpVersion&0x0F);

   printf("USBDM Hardware         = %s - %s\n",
          BDMCPUTypes[(hardwareIdentification>>6)&0x03],
          getHardwareDescription(hardwareIdentification&0x3F));

//  Can't use - UTF-16-LE !
//   const char *deviceDescription;
//   rc = USBDM_GetBDMDescription(&deviceDescription);
//
//   printf("Internal BDM Description = %s\n", deviceDescription);

   if (icpVersion == 0x10)
      return 2;
   if (icpVersion == 0x11)
      return 3;
   // ICP V# > 1.1
   return 4;
}

int main(void) {
   char commandBuffer[100];
   int ICP_Version;
   unsigned devCount;

   puts("\n\n\n\n");

   if ((USBDM_Init() != BDM_RC_OK) ||
       (USBDM_FindDevices(&devCount) != BDM_RC_OK) ||
       (devCount < 1) ||
       (USBDM_Open(0) != BDM_RC_OK)) {
      printf("Error: No USBDM device found!\n");
      puts("Press ENTER to continue\n");
      gets(commandBuffer);
      return 0;
   }

   ICP_Version = reportVersion();

   if (ICP_Version <= 0) {
      puts("Press ENTER to continue\n");
      gets(commandBuffer);
      goto cleanUp;
   }

   if (ICP_Version == 1) {
      puts("\n**********************************************");
      puts("**********************************************");
      puts("******                                  ******");
      puts("******            WARNING               ******");
      puts("******                                  ******");
      puts("******   Setting ICP mode will make     ******");
      puts("******   the BDM unusable until it      ******");
      puts("******     has been re-programmed       ******");
      puts("******     by using the Freescale       ******");
      puts("******          ICP software.           ******");
      puts("******                                  ******");
      puts("******   Remove and replace the BDM     ******");
      puts("******   before trying to program it    ******");
      puts("******     using the Freescale ICP      ******");
      puts("******            software.             ******");
      puts("**********************************************\n");
      puts("**********************************************\n");
      puts("Permanently set ICP mode on USBDM device (yes/No)?");
   }
   else {
      puts("\n**********************************************");
      puts("**********************************************");
      puts("******                                  ******");
      puts("******           ADVICE                 ******");
      puts("******                                  ******");
      puts("******   This will temporarily reboot   ******");
      puts("******      the BDM into ICP mode.      ******");
      puts("******   No permanent changes are made  ******");
      puts("******         to the BDM.              ******");
      puts("******                                  ******");
      puts("******   Do not remove the BDM until    ******");
      puts("******    you have re-programmed it     ******");
      if ((hardwareIdentification&0xC0) == 0x00) { // JB16
         puts("******     using the Freescale ICP      ******");
         puts("******            software.             ******");
      }
      puts("******                                  ******");
      puts("**********************************************");
      puts("**********************************************\n");
      puts("Temporarily reboot USBDM device into ICP mode (yes/No)?");
   }

   gets(commandBuffer);
   if ((commandBuffer[0] == 'y')||(commandBuffer[0] == 'Y')) {
      USBDM_RebootToICP();
      printf("setBootCommand Complete\n");
   }

   if (ICP_Version < 4) {
      puts("\n**********************************************");
      puts("******   Old ICP software was found.    ******");
      puts("******                                  ******");
      puts("******  This ICP version has a BUG!     ******");
      puts("******                                  ******");
      puts("******  You are advised to update ALL   ******");
      puts("******   of the Flash (Bulk erase)      ******");
      puts("******     using the Freescale ICP      ******");
      puts("******            software.             ******");
      puts("******                                  ******");
      puts("**********************************************");
      puts("Press Enter to continue.");
      gets(commandBuffer);
   }
   else {
      puts("Press Enter to continue.");
      gets(commandBuffer);
   }

cleanUp:
  USBDM_Close();
  USBDM_Exit();

  return 0;
}
