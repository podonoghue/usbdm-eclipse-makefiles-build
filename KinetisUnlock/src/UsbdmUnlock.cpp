/*
 * Main.cpp
 *
 *  Created on: 21/10/2011
 *      Author: podonoghue
 *
 *  Simple program demonstrating use of USBDM API
 *
 *  This program dumps the contents of a chip to stdout in S19 format.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
#include <memory.h> // linux
#else
#include <mem.h> // win
#endif
#include "USBDM_API.h"

#include "ArmDefinitions.h"
#include "Utils.h"
#include "UsbdmSystem.h"

// Required API
#define USBDM_API_VERSION_REQUIRED (0x40905) // Need V4.9.5

// Static check that correct API (header file) is being used
#if (USBDM_API_VERSION < USBDM_API_VERSION_REQUIRED)
#error "This program requires USBDM version 4.9.5 or later"
#endif

USBDM_ErrorCode openBDM(int deviceNumber) {

   USBDM_ErrorCode rc;

   rc = USBDM_Init();
   if (rc != BDM_RC_OK) {
      return rc;
   }

   unsigned deviceCount;
   USBDM_FindDevices(&deviceCount);
   rc = USBDM_Open(0);
   if (rc != BDM_RC_OK) {
      return rc;
   }

   USBDM_bdmInformation_t bdmInformation = {sizeof(bdmInformation)};
   USBDM_GetBdmInformation(&bdmInformation);
   rc = (bdmInformation.BDMsoftwareVersion < 0x40905)?BDM_RC_WRONG_BDM_REVISION:BDM_RC_OK;
   if (rc != BDM_RC_OK) {
      return rc;
   }

   USBDM_ExtendedOptions_t options = {sizeof(USBDM_ExtendedOptions_t), T_ARM};
   rc = USBDM_GetDefaultExtendedOptions(&options);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   options.resetDuration         = 1000;
   options.resetReleaseInterval  = 500;
   options.resetRecoveryInterval = 1500;
   options.targetVdd             = BDM_TARGET_VDD_3V3;
   options.autoReconnect         = AUTOCONNECT_STATUS;
   options.interfaceFrequency    = 12000;
   rc = USBDM_SetExtendedOptions(&options);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   rc = USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
   if (rc != BDM_RC_OK) {
      return rc;
   }

   rc = USBDM_SetTargetType(T_ARM);
   if (rc != BDM_RC_OK) {
      return rc;
   }
//   rc = USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
//   if (rc != BDM_RC_OK) {
//      return rc;
//   }

   return rc;
}

USBDM_ErrorCode tryUnlock(void) {
   USBDM_ErrorCode rc = BDM_RC_OK;

   USBDM_ControlPins(PIN_RESET_LOW);
   static uint8_t debugCommand[100] = {0,0,20};
   fprintf(stderr, "\n\nDisconnect & re-connect power to target until you see a success/failure message\n\n");
   // Expect this to fail as USB communications is lost - very crude!!!
   USBDM_Debug(debugCommand);
   for (unsigned attempt = 0; attempt<100; attempt++) {
      UsbdmSystem::milliSleep(100);
      rc = openBDM(0);
      if (rc == BDM_RC_OK) {
         break;
      }
   }
   rc = USBDM_Connect();
   USBDM_ControlPins(PIN_RELEASE);

//   rc = USBDM_WriteCReg(ARM_CRegMDM_AP_Control, 0x0C);
//   if (rc != BDM_RC_OK) {
//      return rc;
//   }
//   unsigned long value;
//   rc = USBDM_ReadCReg(ARM_CRegMDM_AP_Control, &value);
//   if (rc != BDM_RC_OK) {
//      return rc;
//   }
//   if ((value &0xFF) != 0x0C) {
//      return BDM_RC_FAIL;
//   }
   return rc;
}

int main(void) {

   openBDM(0);

   fprintf(stderr, "Attempting Unlock\n");

   USBDM_ErrorCode rc = BDM_RC_FAIL;
   for (unsigned attempt = 0; attempt<10000; attempt++) {
      rc = tryUnlock();
      if (rc == BDM_RC_OK) {
         fprintf(stderr, "Success\n");
         break;
      }
      else {
         fprintf(stderr, "Failure - New attempt\n");
      }
   }
   if (rc != BDM_RC_OK) {
      fprintf(stderr, "Giving up\n");
   }
   USBDM_Close();
   USBDM_Exit();
   return 0;
}
