/*
 * gdbMiscellaneous.cpp
 *
 *  Created on: 02/07/2013
 *      Author: Peter
 */

#include "USBDM_API.h"
#include "UsbdmSystem.h"
#include "Names.h"
#include "TargetDefines.h"

//USBDM_ErrorCode usbdmResetTarget(bool retry) {
//   LOGGING_E;
//
//   USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
//   USBDM_ErrorCode rc = USBDM_Connect();
//   if ((rc != BDM_RC_OK) && retry) {
//      log.print("USBDM_Connect() failed - retry\n");
//      rc = usbdmResetTarget(false);
//   }
//   return rc;
//}
//
//USBDM_ErrorCode setBDMClockMode(ClkSwValues_t clockMode) {
//   LOGGING_Q;
//   log.print("Switch to independent clock done\n");
//   USBDM_ExtendedOptions_t localBdmOptions = {sizeof(USBDM_ExtendedOptions_t), T_NONE};
//   USBDM_ErrorCode rc;
//   rc = USBDM_GetExtendedOptions(&localBdmOptions);
//   if (rc != BDM_RC_OK) {
//      return rc;
//   }
//   localBdmOptions.bdmClockSource = clockMode;
//   return USBDM_SetExtendedOptions(&localBdmOptions);
//}

//static USBDM_ErrorCode usbdmInit(TargetType_t targetType, USBDM_ExtendedOptions_t *bdmOptions) {
//   LOGGING_Q;
//   unsigned int deviceCount;
//   unsigned int deviceNum;
//
//   USBDM_ErrorCode rc = USBDM_FindDevices(&deviceCount);
//   log.print( "Usb initialized, found %d device(s)\n", deviceCount);
//   if (rc != BDM_RC_OK) {
//      return rc;
//   }
//   deviceNum  = 0;
//   rc = USBDM_Open(deviceNum);
//   if (rc != BDM_RC_OK) {
//      log.print( "usbdmInit(): Failed to open %s, device #%d\n", getTargetTypeName(targetType), deviceNum);
//      return rc;
//   }
//   log.print("Opened %s, device #%d\n", getTargetTypeName(targetType), deviceNum);
//
//   // Set up sensible default since we can't change this (at the moment)
//   USBDM_ExtendedOptions_t localBdmOptions = {sizeof(USBDM_ExtendedOptions_t), targetType};
//   if (bdmOptions == NULL) {
//      bdmOptions = &localBdmOptions;
//      USBDM_GetDefaultExtendedOptions(&localBdmOptions);
//      localBdmOptions.targetVdd                  = BDM_TARGET_VDD_3V3; // BDM_TARGET_VDD_NONE;
//      localBdmOptions.autoReconnect              = AUTOCONNECT_ALWAYS; // Aggressively auto-connect
//      localBdmOptions.guessSpeed                 = false;
//      localBdmOptions.cycleVddOnConnect          = false;
//      localBdmOptions.cycleVddOnReset            = false;
//      localBdmOptions.leaveTargetPowered         = false;
//      localBdmOptions.bdmClockSource             = CS_DEFAULT;
//      localBdmOptions.useResetSignal             = false;
//      localBdmOptions.usePSTSignals              = false;
//      if (targetType == T_ARM) {
//         localBdmOptions.interfaceFrequency         = 12000; // 12 MHz
//      }
//      else {
//         localBdmOptions.interfaceFrequency         = 1000; // 1 MHz
//      }
//      localBdmOptions.powerOnRecoveryInterval    = 100;
//      localBdmOptions.resetDuration              = 100;
//      localBdmOptions.resetReleaseInterval       = 100;
//      localBdmOptions.resetRecoveryInterval      = 100;
//   }
//   rc = USBDM_SetExtendedOptions(bdmOptions);
//   if (rc != BDM_RC_OK) {
//      log.print("USBDM_SetExtendedOptions() failed\n");
//      return rc;
//   }
//   rc = USBDM_SetTargetType(targetType);
//   if (rc != BDM_RC_OK) {
//      log.print("USBDM_SetTargetType() failed\n");
//      return rc;
//   }
//   rc = usbdmResetTarget();
//   if (rc != BDM_RC_OK) {
//      log.print( "Failed\n");
//   }
//   return BDM_RC_OK;
//}
//
///*! Initialise the BDM with given settings (including target type)
// *
// */
//USBDM_ErrorCode usbdmInit(USBDM_ExtendedOptions_t *bdmOptions) {
//   return usbdmInit(bdmOptions->targetType, bdmOptions);
//}
//
///*! Initialise the BDM for the given target using defaut settings
// *
// */
//USBDM_ErrorCode usbdmInit(TargetType_t targetType) {
//   return usbdmInit(targetType, NULL);
//}
//
///* closes currently open device */
//USBDM_ErrorCode usbdmClose(void) {
//   LOGGING;
//   log.print("Closing the device\n");
//   USBDM_Close();
//   return BDM_RC_OK;
//}
