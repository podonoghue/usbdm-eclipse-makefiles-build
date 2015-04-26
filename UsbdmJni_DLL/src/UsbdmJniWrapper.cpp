#include <jni.h>
#include <stdio.h>
#include <string>
#include <UsbdmPaths.h>

#include "net_sourceforge_usbdm_jni_usbdm_Usbdm.h"
#include "USBDM_API.h"

/*
 * This file provides JNI wrappers for the following USBDM entry points:
 *
USBDM_API USBDM_ErrorCode  USBDM_Init(void);
USBDM_API USBDM_ErrorCode  USBDM_Exit(void);
USBDM_API USBDM_ErrorCode  USBDM_Open(unsigned char deviceNo);
USBDM_API USBDM_ErrorCode  USBDM_Close(void);
USBDM_API USBDM_ErrorCode  USBDM_FindDevices(unsigned int *deviceCount);
USBDM_API USBDM_ErrorCode  USBDM_ReleaseDevices(void);
USBDM_API USBDM_ErrorCode  USBDM_GetBDMDescription(const char **deviceDescription);
USBDM_API USBDM_ErrorCode  USBDM_GetBDMSerialNumber(const char **deviceDescription);
*/

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_getUsbdmResourcePath
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL 
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetUsbdmResourcePath(JNIEnv *env, jclass, jbyteArray jString) {
   std::string installationPath;
   if (!getUsbdmResourcePath(installationPath)) {
      return BDM_RC_FAIL;
   }
   jint  jlen    = installationPath.length();
   jbyte jlenMSB = (jbyte)(jlen>>8);
   jbyte jlenLSB = (jbyte)(jlen);
   jint len = env->GetArrayLength(jString);
   if (jlen > len-2) {
      // Buff not big enough
      return BDM_RC_ILLEGAL_PARAMS;
   }
   env->SetByteArrayRegion(jString, 0, 1, &jlenMSB);
   env->SetByteArrayRegion(jString, 1, 1, &jlenLSB);
   env->SetByteArrayRegion(jString, 2, jlen, (const jbyte *)installationPath.c_str());
   return BDM_RC_OK;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_getUsbdmApplicationPath
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetUsbdmApplicationPath(JNIEnv *env, jclass, jbyteArray jString) {
   std::string installationPath;
   if (!getUsbdmApplicationPath(installationPath)) {
      return BDM_RC_FAIL;
   }
   jint  jlen    = installationPath.length();
   jbyte jlenMSB = (jbyte)(jlen>>8);
   jbyte jlenLSB = (jbyte)(jlen);
   jint len = env->GetArrayLength(jString);
   if (jlen > len-2) {
      // Buff not big enough
      return BDM_RC_ILLEGAL_PARAMS;
   }
   env->SetByteArrayRegion(jString, 0, 1, &jlenMSB);
   env->SetByteArrayRegion(jString, 1, 1, &jlenLSB);
   env->SetByteArrayRegion(jString, 2, jlen, (const jbyte *)installationPath.c_str());
   return BDM_RC_OK;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_getUsbdmDataPath
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetUsbdmDataPath(JNIEnv *env, jclass, jbyteArray jString) {
   std::string dataPath;
   if (!getUsbdmDataPath(dataPath)) {
      return BDM_RC_FAIL;
   }
   jint  jlen    = dataPath.length();
   jbyte jlenMSB = (jbyte)(jlen>>8);
   jbyte jlenLSB = (jbyte)(jlen);
   jint len = env->GetArrayLength(jString);
   if (jlen > len-2) {
      // Buff not big enough
      return BDM_RC_ILLEGAL_PARAMS;
   }
   env->SetByteArrayRegion(jString, 0, 1, &jlenMSB);
   env->SetByteArrayRegion(jString, 1, 1, &jlenLSB);
   env->SetByteArrayRegion(jString, 2, jlen, (const jbyte *)dataPath.c_str());
   return BDM_RC_OK;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_init
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmInit(JNIEnv *, jclass) {
//	fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_init()\n");
	return USBDM_Init();
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_exit
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmExit(JNIEnv *, jclass) {
//	fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_exit()\n");
	return USBDM_Exit();
}

const char *bdmInformationNames[] = {
   "BDMsoftwareVersion",   //!< BDM Firmware version
   "BDMhardwareVersion",   //!< Hardware version reported by BDM firmware
   "ICPsoftwareVersion",   //!< ICP Firmware version
   "ICPhardwareVersion",   //!< Hardware version reported by ICP firmware
   "capabilities",         //!< BDM Capabilities
   "commandBufferSize",    //!< Size of BDM Communication buffer
   "jtagBufferSize",       //!< Size of JTAG buffer (if supported)
};

const struct {
   const char *fieldName;
   const char *signature;
} bdmOptionNames[] = {
      // Options passed to the BDM
      { "targetType",             "I"},
      { "targetVdd",              "I"},
      { "cycleVddOnReset",        "Z"},
      { "cycleVddOnConnect",      "Z"},
      { "leaveTargetPowered",     "Z"},
      { "autoReconnect",          "I"},
      { "guessSpeed",             "Z"},
      { "bdmClockSource",         "I"},
      { "useResetSignal",         "Z"},
      { "maskInterrupts",         "Z"},
      { "interfaceFrequency",     "I"},
      { "usePSTSignals",          "Z"},
      { "powerOffDuration",       "I"},
      { "powerOnRecoveryInterval","I"},
      { "resetDuration",          "I"},
      { "resetReleaseInterval",   "I"},
      { "resetRecoveryInterval",  "I"},
   };

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_getBDMFirmwareVersion
 * Signature: (Ledu/swin/mcu/debug/connections/usbdm/Usbdm/BdmInformation;)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMInformation(JNIEnv *env, jclass objClass, jobject jbdmInfo) {
   USBDM_ErrorCode        rc      = BDM_RC_OK;
   USBDM_bdmInformation_t bdmInfo = {sizeof(USBDM_bdmInformation_t)};

   rc = USBDM_GetBdmInformation(&bdmInfo);
   if (rc != BDM_RC_OK) {
      return rc;
   }
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMInformation()\n");
   if (env == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (jbdmInfo == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   jclass cls = env->GetObjectClass(jbdmInfo);
   if (cls == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMInformation() #1\n");
   jint values[] = {bdmInfo.BDMsoftwareVersion,bdmInfo.BDMhardwareVersion,
                    bdmInfo.ICPsoftwareVersion,bdmInfo.ICPhardwareVersion,
                    bdmInfo.capabilities,
              (jint)bdmInfo.commandBufferSize,
              (jint)bdmInfo.jtagBufferSize};
   if (rc == BDM_RC_OK) {
      for (unsigned indx=0; indx < sizeof(bdmInformationNames)/sizeof(bdmInformationNames[0]); indx++) {
//         fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMInformation() indx = %d\n", indx);
         jfieldID fieldID = env->GetFieldID(cls, bdmInformationNames[indx], "I");
//         fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMInformation(): fieldID=%p\n", fieldID);
         if (fieldID == NULL) {
            return BDM_RC_ILLEGAL_PARAMS;
         }
         env->SetIntField(jbdmInfo, fieldID, values[indx]);
      }
   }
   return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_getErrorString
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetErrorString(JNIEnv *env, jclass, jint errorNum) {

   const char *message = USBDM_GetErrorString((USBDM_ErrorCode(errorNum)));

   return env->NewStringUTF(message);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_findDevices
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmFindDevices(JNIEnv *env, jclass, jintArray countOfDevices) {
//	fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_findDevices()\n");
	unsigned int deviceCount;
	USBDM_ErrorCode rc = USBDM_FindDevices(&deviceCount);
	if (rc == BDM_RC_OK) {
		jint jDeviceCount = deviceCount;
		env->SetIntArrayRegion(countOfDevices, 0, 1, &jDeviceCount);
	}
	return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_releaseDevices
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReleaseDevices(JNIEnv *, jclass) {
//	fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_releaseDevices()\n");
	return USBDM_ReleaseDevices();
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_getBDMSerialNumber
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMSerialNumber(JNIEnv *env, jclass, jbyteArray jString) {
   const char *stringUTF16LE;
   USBDM_ErrorCode rc = BDM_RC_OK;
   rc = USBDM_GetBDMSerialNumber(&stringUTF16LE);
   if (rc == BDM_RC_OK) {
      int16_t *p = (int16_t *)stringUTF16LE;
      while (*p != 0) {
         p++;
      }
      jint  jlen    = (char*)p-stringUTF16LE;;
      jbyte jlenMSB = (jbyte)(jlen>>8);
      jbyte jlenLSB = (jbyte)(jlen);
      jint len = env->GetArrayLength(jString);
      if (jlen > len-2) {
         // Buff not big enough
         return BDM_RC_ILLEGAL_PARAMS;
      }
      env->SetByteArrayRegion(jString, 0, 1, &jlenMSB);
      env->SetByteArrayRegion(jString, 1, 1, &jlenLSB);
      env->SetByteArrayRegion(jString, 2, jlen, (const jbyte *)stringUTF16LE);
   }
   return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_getBDMDescription
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMDescription(JNIEnv *env, jclass, jbyteArray jString) {
   const char *stringUTF16LE;
   USBDM_ErrorCode rc = BDM_RC_OK;
   rc = USBDM_GetBDMDescription(&stringUTF16LE);
   if (rc == BDM_RC_OK) {
      int16_t *p = (int16_t *)stringUTF16LE;
      while (*p != 0) {
         p++;
      }
      jint  jlen    = (char*)p-stringUTF16LE;;
      jbyte jlenMSB = (jbyte)(jlen>>8);
      jbyte jlenLSB = (jbyte)(jlen);
      jint len = env->GetArrayLength(jString);
      if (jlen > len-2) {
         // Buff not big enough
         return BDM_RC_ILLEGAL_PARAMS;
      }
      env->SetByteArrayRegion(jString, 0, 1, &jlenMSB);
      env->SetByteArrayRegion(jString, 1, 1, &jlenLSB);
      env->SetByteArrayRegion(jString, 2, jlen, (const jbyte *)stringUTF16LE);
   }
   return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_openBDM
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmOpen(JNIEnv *, jclass, jint deviceNum) {
//	fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_openBDM(%d)\n", (int)deviceNum);
	return USBDM_Open(deviceNum);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdm_closeBDM
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmClose(JNIEnv *, jclass) {
//	fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_closeBDM()\n");
	return USBDM_Close();
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetExtendedOptions
 * Signature: (Lnet/sourceforge/usbdm/connections/usbdm/Usbdm/BdmInformation;)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetDefaultExtendedOptions(JNIEnv *env, jclass objClass, jobject jbdmInfo) {
   USBDM_ErrorCode         rc         = BDM_RC_OK;
   USBDM_ExtendedOptions_t bdmOptions = {sizeof(USBDM_ExtendedOptions_t)};

//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetDefaultExtendedOptions()\n");
   if (env == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (jbdmInfo == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   jclass cls = env->GetObjectClass(jbdmInfo);
   if (cls == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   bdmOptions.targetType         = (TargetType_t) env->GetIntField(jbdmInfo, env->GetFieldID(cls, "targetType",              "I"));
   bdmOptions.interfaceFrequency =                env->GetIntField(jbdmInfo, env->GetFieldID(cls, "interfaceFrequency",      "I"));

   bdmOptions.powerOffDuration = 1234;
   rc = USBDM_GetDefaultExtendedOptions(&bdmOptions);
   if (rc != BDM_RC_OK) {
      return rc;
   }
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetDefaultExtendedOptions() #1\n");
   jint values[] = {bdmOptions.targetType,
                    bdmOptions.targetVdd,
                    bdmOptions.cycleVddOnReset,
                    bdmOptions.cycleVddOnConnect,
                    bdmOptions.leaveTargetPowered,
                    bdmOptions.autoReconnect,
                    bdmOptions.guessSpeed,
                    bdmOptions.bdmClockSource,
                    bdmOptions.useResetSignal,
                    bdmOptions.maskInterrupts,
              (jint)bdmOptions.interfaceFrequency,
                    bdmOptions.usePSTSignals,
              (jint)bdmOptions.powerOffDuration,
              (jint)bdmOptions.powerOnRecoveryInterval,
              (jint)bdmOptions.resetDuration,
              (jint)bdmOptions.resetReleaseInterval,
              (jint)bdmOptions.resetRecoveryInterval,
   };
   if (rc == BDM_RC_OK) {
      for (unsigned indx=0; indx < sizeof(bdmOptionNames)/sizeof(bdmOptionNames[0]); indx++) {
//         fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetDefaultExtendedOptions() indx = %d\n", indx);
         jfieldID fieldID = env->GetFieldID(cls, bdmOptionNames[indx].fieldName, bdmOptionNames[indx].signature);
//         fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetDefaultExtendedOptions(): fieldID=%p\n", fieldID);
         if (fieldID == NULL) {
            return BDM_RC_ILLEGAL_PARAMS;
         }
         env->SetIntField(jbdmInfo, fieldID, values[indx]);
      }
   }
   return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetBDMInformation
 * Signature: (Lnet/sourceforge/usbdm/connections/usbdm/Usbdm/BdmInformation;)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetExtendedOptions(JNIEnv *env, jclass objClass, jobject jbdmInfo) {

//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetExtendedOptions()\n");
   if (env == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (jbdmInfo == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   jclass cls = env->GetObjectClass(jbdmInfo);
   if (cls == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   USBDM_ExtendedOptions_t bdmOptions = {sizeof(USBDM_ExtendedOptions_t)};
   bdmOptions.targetType               = (TargetType_t)     env->GetIntField(jbdmInfo, env->GetFieldID(cls, "targetType",              "I"));
   bdmOptions.targetVdd                = (TargetVddSelect_t)env->GetIntField(jbdmInfo, env->GetFieldID(cls, "targetVdd",               "I"));
   bdmOptions.cycleVddOnReset          =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "cycleVddOnReset",         "Z"));
   bdmOptions.cycleVddOnConnect        =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "cycleVddOnConnect",       "Z"));
   bdmOptions.leaveTargetPowered       =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "leaveTargetPowered",      "Z"));
   bdmOptions.autoReconnect            = (AutoConnect_t)    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "autoReconnect",           "I"));
   bdmOptions.guessSpeed               =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "guessSpeed",              "Z"));
   bdmOptions.bdmClockSource           = (ClkSwValues_t)    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "bdmClockSource",          "I"));
   bdmOptions.useResetSignal           =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "useResetSignal",          "Z"));
   bdmOptions.maskInterrupts           =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "maskInterrupts",          "Z"));
   bdmOptions.interfaceFrequency       =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "interfaceFrequency",      "I"));
   bdmOptions.usePSTSignals            =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "usePSTSignals",           "Z"));
   bdmOptions.powerOffDuration         =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "powerOffDuration",        "I"));
   bdmOptions.powerOnRecoveryInterval  =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "powerOnRecoveryInterval", "I"));
   bdmOptions.resetDuration            =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "resetDuration",           "I"));
   bdmOptions.resetReleaseInterval     =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "resetReleaseInterval",    "I"));
   bdmOptions.resetRecoveryInterval    =                    env->GetIntField(jbdmInfo, env->GetFieldID(cls, "resetRecoveryInterval",   "I"));
   return USBDM_SetExtendedOptions(&bdmOptions);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetExtendedOptions
 * Signature: (Lnet/sourceforge/usbdm/connections/usbdm/Usbdm/BdmInformation;)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetExtendedOptions(JNIEnv *env, jclass objClass, jobject jbdmInfo) {

//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetExtendedOptions()\n");
   if (env == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (jbdmInfo == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   jclass cls = env->GetObjectClass(jbdmInfo);
   if (cls == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   USBDM_ExtendedOptions_t bdmOptions = {sizeof(USBDM_ExtendedOptions_t)};
   bdmOptions.targetType         = (TargetType_t) env->GetIntField(jbdmInfo, env->GetFieldID(cls, "targetType",              "I"));
   bdmOptions.interfaceFrequency =                env->GetIntField(jbdmInfo, env->GetFieldID(cls, "interfaceFrequency",      "I"));
   USBDM_ErrorCode  rc = USBDM_GetExtendedOptions(&bdmOptions);
   if (rc != BDM_RC_OK) {
      return rc;
   }
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetExtendedOptions() #1\n");
   jint values[] = {bdmOptions.targetType,
                    bdmOptions.targetVdd,
                    bdmOptions.cycleVddOnReset,
                    bdmOptions.cycleVddOnConnect,
                    bdmOptions.leaveTargetPowered,
                    bdmOptions.autoReconnect,
                    bdmOptions.guessSpeed,
                    bdmOptions.bdmClockSource,
                    bdmOptions.useResetSignal,
                    bdmOptions.maskInterrupts,
              (jint)bdmOptions.interfaceFrequency,
                    bdmOptions.usePSTSignals,
              (jint)bdmOptions.powerOffDuration,
              (jint)bdmOptions.powerOnRecoveryInterval,
              (jint)bdmOptions.resetDuration,
              (jint)bdmOptions.resetReleaseInterval,
              (jint)bdmOptions.resetRecoveryInterval,
   };
   if (rc == BDM_RC_OK) {
      for (unsigned indx=0; indx < sizeof(bdmOptionNames)/sizeof(bdmOptionNames[0]); indx++) {
//         fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetExtendedOptions() indx = %d\n", indx);
         jfieldID fieldID = env->GetFieldID(cls, bdmOptionNames[indx].fieldName, bdmOptionNames[indx].signature);
//         fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetExtendedOptions(): fieldID=%p\n", fieldID);
         if (fieldID == NULL) {
            return BDM_RC_ILLEGAL_PARAMS;
         }
         env->SetIntField(jbdmInfo, fieldID, values[indx]);
      }
   }
   return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetTargetType
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetTargetType(JNIEnv *, jclass, jint targetType) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetTargetType(%d)\n", (int)targetType);
   return USBDM_SetTargetType((TargetType_t)targetType);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetTargetVdd
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetTargetVdd(JNIEnv *, jclass, jint targetVdd) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetTargetType(%d)\n", (int)targetType);
   return USBDM_SetTargetVdd((TargetVddSelect_t)targetVdd);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetTargetVpp
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetTargetVpp(JNIEnv *, jclass, jint targetVpp) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetTargetType(%d)\n", (int)targetType);
   return USBDM_SetTargetVpp((TargetVppSelect_t)targetVpp);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetReset
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetReset(JNIEnv *, jclass, jint mode) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetReset(%d)\n", (int)mode);
   return USBDM_TargetReset((TargetMode_t)mode);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetGo
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetGo(JNIEnv *, jclass) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetReset(%d)\n", (int)mode);
   return USBDM_TargetGo();
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetStep
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetStep(JNIEnv *, jclass) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetReset(%d)\n", (int)mode);
   return USBDM_TargetStep();
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetHalt
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetHalt(JNIEnv *, jclass) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetReset(%d)\n", (int)mode);
   return USBDM_TargetHalt();
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetConnect
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetConnect(JNIEnv *, jclass) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetConnect()\n");
   return USBDM_Connect();
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmReadMemory
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReadMemory(JNIEnv *env, jclass, jint memorySpace, jint byteCount, jint address, jbyteArray data) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReadMemory()\n");
   unsigned char dataBuff[(unsigned int)byteCount];
   USBDM_ErrorCode rc = USBDM_ReadMemory( (unsigned int)memorySpace,
                                          (unsigned int)byteCount,
                                          (unsigned int)address,
                                          dataBuff);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   env->SetByteArrayRegion(data, 0, (long)byteCount, (const jbyte *)dataBuff);
   return BDM_RC_OK;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmWriteMemory
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteMemory(JNIEnv *env, jclass, jint memorySpace, jint byteCount, jint address, jbyteArray data) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteMemory()\n");
   unsigned char dataBuff[(int)byteCount];
   env->GetByteArrayRegion(data, 0, (long)byteCount, (signed char*)dataBuff);
   return USBDM_WriteMemory((unsigned int)memorySpace,
                            (unsigned int)byteCount,
                            (unsigned int)address,
                            dataBuff);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmReadReg
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReadReg(JNIEnv *env, jclass, jint space, jint regNo, jintArray jRegValue) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteMemory()\n");
   unsigned long ulRegValue;
   int rc;
   switch(space) {
      case 0  : rc = USBDM_ReadReg((unsigned int)regNo,  &ulRegValue); break;
      case 1  : rc = USBDM_ReadCReg((unsigned int)regNo, &ulRegValue); break;
      case 2  : rc = USBDM_ReadDReg((unsigned int)regNo, &ulRegValue); break;
      default : return BDM_RC_ILLEGAL_PARAMS;
   }
   jint lRegValue = ulRegValue;
   env->SetIntArrayRegion(jRegValue, 0, 1, &lRegValue);
   return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmReadReg
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteReg(JNIEnv *env, jclass, jint space, jint regNo, jint jRegValue) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteMemory()\n");
   switch(space) {
      case 0  : return USBDM_WriteReg((unsigned int)regNo, (unsigned long)jRegValue);
      case 1  : return USBDM_WriteCReg((unsigned int)regNo, (unsigned long)jRegValue);
      case 2  : return USBDM_WriteDReg((unsigned int)regNo, (unsigned long)jRegValue);
      default : return BDM_RC_ILLEGAL_PARAMS;
   }
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmReadStatusReg
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReadStatusReg(JNIEnv *env, jclass, jintArray jRegValue) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReadStatusReg()\n");
   unsigned long ulRegValue;
   int rc = USBDM_ReadStatusReg(&ulRegValue);
   jint lRegValue = ulRegValue;
   env->SetIntArrayRegion(jRegValue, 0, 1, &lRegValue);
   return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmWriteControlReg
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteControlReg(JNIEnv *env, jclass, jint space, jint regNo, jint jRegValue) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteMemory()\n");
   return USBDM_WriteControlReg((unsigned long)jRegValue);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    ControlPins
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmControlPins(JNIEnv *env, jclass, jint jValue, jintArray jStatus) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmControlPins()\n");
   unsigned status;
   int rc = USBDM_ControlPins((unsigned long)jValue, &status);
   jint lRegValue = status;
   env->SetIntArrayRegion(jStatus, 0, 1, &lRegValue);
   return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetSpeed
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetSpeed(JNIEnv *env, jclass, jint jSpeed) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteMemory()\n");
   return USBDM_SetSpeed((unsigned long)jSpeed);
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetSpeed
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetSpeed(JNIEnv *env, jclass, jintArray jSpeed) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmControlPins()\n");
   unsigned long speed;
   int rc = USBDM_GetSpeed(&speed);
   jint lRegValue = speed;
   env->SetIntArrayRegion(jSpeed, 0, 1, &lRegValue);
   return rc;
}

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmBDMStatus
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMStatus(JNIEnv *env, jclass objClass, jobject jStatus) {
//   fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmBDMStatus()\n");

   USBDMStatus_t usbdmStatus;
   int rc = USBDM_GetBDMStatus(&usbdmStatus);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   const char *fieldNames[] = {
      "acknState",
      "connectionState",
      "resetState",
      "resetRecent",
      "haltState",
      "powerState",
      "flashState",
   };
   jint values[] = {
       usbdmStatus.ackn_state,        //!< Supports ACKN ?
       usbdmStatus.connection_state,  //!< Connection status & speed determination method
       !usbdmStatus.reset_state,      //!< Current target RST0 state
       usbdmStatus.reset_recent,      //!< Target reset recently?
       usbdmStatus.halt_state,        //!< CFVx halted (from ALLPST)?
       usbdmStatus.power_state,       //!< Target has power?
       usbdmStatus.flash_state,       //!< State of Target Vpp
   };
   if (env == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (jStatus == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   jclass cls = env->GetObjectClass(jStatus);
   if (cls == NULL) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   for (unsigned indx=0; indx < sizeof(fieldNames)/sizeof(fieldNames[0]); indx++) {
//      fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmBDMStatus() indx = %d\n", indx);
      jfieldID fieldID = env->GetFieldID(cls, fieldNames[indx], "I");
//      fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmBDMStatus(): fieldID=%p\n", fieldID);
      if (fieldID == NULL) {
//         fprintf(stderr, "Java_net_sourceforge_usbdm_jni_Usbdm_usbdmBDMStatus(): field \'%s\' not found\n", fieldNames[indx]);
         return BDM_RC_ILLEGAL_PARAMS;
      }
      env->SetIntField(jStatus, fieldID, values[indx]);
   }
   return rc;
}

extern "C"
__attribute__ ((constructor))
void usbdmJni_dll_initialize(void) {
//   fprintf(stderr, "usbdm_dll_initialize()\n");
}

extern "C"
__attribute__ ((destructor))
void usbdmJni_dll_uninitialize(void) {
//   fprintf(stderr, "usbdm_dll_uninitialize()\n");
}
