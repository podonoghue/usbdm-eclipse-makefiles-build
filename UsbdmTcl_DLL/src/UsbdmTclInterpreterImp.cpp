/*
 * UsbdmTclInterpreterImp.cpp
 *
 *  Created on: 12 April 2015
 *      Author: podonoghue

\verbatim
Change History
-====================================================================================
| 10 Oct 2015 | Added Tcl_Finalize() to deleteInterpreter()       - pgo - V4.11.1.40
| 21 May 2015 | Removed closing stdio etc as hangs module unload  - pgo - V4.11.1.30
| 21 May 2015 | Changes to module load & unload                   - pgo - V4.11.1.30
| 16 May 2015 | Modified printfs etc go via TCL stdout/stderr     - pgo - V4.11.1.30
| 12 Apr 2015 | Major re-factor                                   - pgo - V4.11.1.10
| 12 Nov 2014 | Minor mod to finding executable - not implemented - pgo - V4.10.6.230
| 14 Sep 2014 | Fixed stdout/stderr in TCL - pgo
+====================================================================================
\endverbatim

 */
#include "UsbdmTclInterpreterImp.h"

#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <unistd.h>
#include <cerrno>
#include <stdarg.h>

#include "ArmDefinitions.h"
#include "tcl.h"
#include "Names.h"
#include "Common.h"
#include "WxPlugin.h"
#include "TargetDefines.h"
#include "WxPluginFactory.h"
#include "BdmInterfaceFactory.h"
#include "DSC_Utilities.h"
#include "PluginHelper.h"

#ifdef _WIN32
#include <io.h>
#endif

using namespace UsbdmWxConstants;

static void printChannel(int ch, const char *format, ...) __attribute__ ((format (printf, 2, 3)));
#define PRINT(format, ...)       printChannel(TCL_STDOUT, format, ##__VA_ARGS__)
#define PRINT_ERROR(format, ...) printChannel(TCL_STDERR, format, ##__VA_ARGS__)

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(void *pp) {
   return TcreatePluginInstance<UsbdmTclInterpreterImp>(pp, true);
}

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createInteractivePluginInstance(void *pp) {
   return TcreatePluginInstance<UsbdmTclInterpreterImp>(pp, false);
}

static WxPluginPtr                 wxPlugin;
static BdmInterfacePtr             bdmInterface;
static MemorySpace_t               defaultMemorySpace   = MS_None;
static USBDM_ErrorCode             lastError            = BDM_RC_OK;
static int                         bigEndian            = true;
static std::vector<BdmInformation> bdmList;

/*
 * ===========================================================
 */

int UsbdmTclInterpreterImp::main(int argc, char *argv[]) {
   Tcl_Main(argc, argv, appInitProc);
   return EXIT_SUCCESS;
};

void UsbdmTclInterpreterImp::deleteInterpreter(Tcl_Interp *interp) {
   LOGGING;
   if (!Tcl_InterpDeleted(interp)) {
      log.print("Tcl_DeleteInterp(@%p)\n", interp);
      Tcl_DeleteInterp(interp);
   }
   log.print("Tcl_Finalize()\n");
   Tcl_Finalize();
}

/**!
 * Create instance of the TCL interpreter
 *
 * @param doInit - Used to suppress initialisation. should be true if used with
 *                 UsbdmTclInterpreterImp::main() for shell as it does its own initialisation
 */
UsbdmTclInterpreterImp::UsbdmTclInterpreterImp(bool doInit) {
   LOGGING;

   tclChannel   = 0;

//#ifdef __unix__
//   // Load wxWindows Stub
//   (void)dlopen(WXSTUB_DLL_NAME, RTLD_NOW|RTLD_NODELETE);
//#endif

   if (doInit) {
      setTCLExecutable();
      interp.reset(Tcl_CreateInterp(), deleteInterpreter);
      Tcl_Init(interp.get());
      log.print("Created interp@%p\n", interp.get());
      registerUSBDMCommands(interp.get());
   }
}

void UsbdmTclInterpreterImp::redirectStdOut() {
   LOGGING;
   FILE *fp = UsbdmSystem::Log::getLogFileHandle();

#ifdef WIN32
   if (fp == NULL) {
      // Create sink
      fp = fopen ("nul", "w");
   }
   if (fp == NULL) {
      log.print("(fp == NULL)\n");
   }
   int fileNo = dup(fileno(fp));

   log.print("createTclInterpreter() fileNo == %d\n", fileNo );
   HANDLE fileHandle = (HANDLE)_get_osfhandle(fileNo);
   log.print("createTclInterpreter() fileHandle == %p\n", fileHandle );
   tclChannel = Tcl_MakeFileChannel(fileHandle, TCL_WRITABLE);
   log.print("createTclInterpreter() tclChannel == %p\n", tclChannel );
#else
   if (fp == NULL) {
      // Create sink
      fp = fopen ("/dev/null", "w");
   }
   if (fp == NULL) {
      PRINT_ERROR("(fp == NULL)\n");
   }
   long fileNo = dup(fileno(fp));
   log.print("createTclInterpreter() fileNo == %ld\n", fileNo );
   tclChannel = Tcl_MakeFileChannel((ClientData)fileNo, TCL_WRITABLE);
   log.print("createTclInterpreter() tclChannel == %p\n", tclChannel );
#endif

   // Register channel
   Tcl_RegisterChannel(interp.get(), tclChannel);
   log.print("createTclInterpreter() Registered channel = %p\n", tclChannel);

   // Redirect stdout/stderr
   log.print("createTclInterpreter() Redirecting stdout\n");
   Tcl_SetStdChannel(tclChannel, TCL_STDOUT);

   log.print("createTclInterpreter() Redirecting stderr\n");
   Tcl_SetStdChannel(tclChannel, TCL_STDERR);

   Tcl_Flush(tclChannel);
}

void UsbdmTclInterpreterImp::setBdmInterface(BdmInterfacePtr bdmInterface, bool doRedirect) {
   LOGGING;
   log.print("doRedirect = %s\n", doRedirect?"TRUE":"FALSE");
   ::bdmInterface = bdmInterface;
   if (bdmInterface == 0) {
      log.error("createTclInterpreter() bdmInterface == 0x%p\n", bdmInterface.get() );
   }
   if (doRedirect) {
      redirectStdOut();
   }
}

UsbdmTclInterpreterImp::~UsbdmTclInterpreterImp() {
   LOGGING;
   wxPlugin.reset();
   log.print("After wxPlugin.reset()\n");
   bdmInterface.reset();
   log.print("After bdmInterface.reset()\n");
// Following crashes on unload???
   Tcl_SetStdChannel(0, TCL_STDOUT);
   Tcl_SetStdChannel(0, TCL_STDERR);
   log.print("After Tcl_SetStdChannel()\n");
   Tcl_UnregisterChannel(interp.get(), tclChannel);
   log.print("After Tcl_UnregisterChannel()\n");
   interp.reset();
   log.print("After interp.reset()\n");
}
#if defined(__linux__)
#include <unistd.h>
#endif

int UsbdmTclInterpreterImp::setTCLExecutable() {
   LOGGING;

#ifdef __WIN32
   // Not necessary in WIN32??
   char executableName[MAX_PATH];
   if (GetModuleFileNameA(NULL, executableName, sizeof(executableName)) > 0) {
      log.print("Doing Tcl_FindExecutable(%s)\n", executableName);
      Tcl_FindExecutable(executableName);
   }
#elif defined(__linux__)
   char executableName[1000];
   int pathLength = readlink("/proc/self/exe", executableName, sizeof(executableName));
   if (pathLength<=0) {
      return BDM_RC_FAIL;
   }
   if (pathLength == sizeof(executableName)) {
      return BDM_RC_FAIL;
   }
   Tcl_FindExecutable(executableName);
#endif
//   log.print("Tcl_GetNameOfExecutable() = \'%s\'\n", Tcl_GetNameOfExecutable());
   return BDM_RC_OK;
}

//
//=============================================================
//
/*! \brief Provides a PRINT function which prints data to TCL stdout
 *
 *  @param format Format and parameters as for PRINT()
 */
static void printChannel(int ch, const char *format, ...)  {
   va_list list;
   if (format == NULL) {
      format = "PRINT() - Error - empty format string!\n";
   }
   va_start(list, format);
   char buff[1000];
   vsnprintf(buff, sizeof(buff), format, list);
   va_end(list);

   // Ensure terminated
   buff[sizeof(buff)-1] = '\0';

   Tcl_Channel channel = Tcl_GetStdChannel(ch);
   if (channel != NULL) {
     Tcl_WriteChars(channel, buff, -1);
     Tcl_Flush(channel);
   }
}

static void listBdms() {
   PRINT("BDM List:\n");
   bdmInterface->findBDMs(bdmList);
   unsigned numDevices = 0;
   for (std::vector<BdmInformation>::iterator it = bdmList.begin(); it != bdmList.end(); ++it) {
      PRINT("%2d - %-20s : %s\n", numDevices, it->getSerialNumber().c_str(), it->getDescription().c_str());
      numDevices++;
   }
   PRINT("Found %d devices\n", numDevices);
}

class MyLock {
public:
   MyLock() {
      Tcl_Preserve(this);
   }
   ~MyLock() {
      Tcl_Release(this);
   }
};

int UsbdmTclInterpreterImp::appInitProc(Tcl_Interp *interp) {
   LOGGING;
   MyLock lock;

   PRINT("USBDMScript incorporating TCL - Copyright(c) 2011\n");
   PRINT("Press ? for help\n");

   registerUSBDMCommands(interp);

   // Set script to run on startup (if it exists)
   Tcl_Eval(interp, "set tcl_rcFileName usbdm_rc.tcl");
   return TCL_OK;
}

USBDM_ErrorCode UsbdmTclInterpreterImp::evalTclScript(const char *script) {
   LOGGING_Q;
   MyLock lock;

   int rcTCL = Tcl_Eval(interp.get(), script);
   const char *result = getTclResult();

   USBDM_ErrorCode rc = BDM_RC_OK;
   if (rcTCL != TCL_OK) {
      // We expect no error
      // Assume anything else is an error
      rc = PROGRAMMING_RC_ERROR_TCL_SCRIPT;
   }
   else {
      // Null result is OK
      if ((result != NULL) && (*result != '\0')) {
         // Return value from TCL script
         // Use as return value if a number
         // We do NOT accept zero
         char *eptr = 0;
         long temp = strtol(result, &eptr, 0);
         if (eptr != result) {
            rc = (USBDM_ErrorCode)temp;
         }
         else {
            log.error("Non-numeric return value = %s\n", result);
            return PROGRAMMING_RC_ERROR_TCL_SCRIPT;
         }
      }
   }
   if (tclChannel != NULL) {
      Tcl_Flush(tclChannel);
      if (rcTCL != TCL_OK) {
         // Try to PRINT TCL stack frame
         Tcl_Obj *options = Tcl_GetReturnOptions(interp.get(), rcTCL);
         Tcl_Obj *key = Tcl_NewStringObj("-errorinfo", -1);
         if ((options != NULL) && (key != NULL)) {
            Tcl_IncrRefCount(key);
            Tcl_Obj *stackTrace;
            Tcl_DictObjGet(NULL, options, key, &stackTrace);
            Tcl_DecrRefCount(key);
            const char *res = Tcl_GetString(stackTrace);
            Tcl_Eval(interp.get(), "flush stdout\n");
            Tcl_Eval(interp.get(), "flush stderr\n");
            if (res != NULL) {
               log.error("TCL Stack Frame = %s\n", res);
            }
         }
      }
   }
   return rc;
}

/*!
 * @param interp Interpreter to get result from
 *
 * @return a point to the result string (a static buffer)
 */
const char *UsbdmTclInterpreterImp::getTclResult() {
   LOGGING_Q;
   MyLock lock;

   static char buff[200];
   const char *res = Tcl_GetStringResult(interp.get());
   memset(buff, 0, sizeof(buff));
   if (res != NULL) {
      strncpy(buff, res, sizeof(buff)-1);
//      log.print("%s\n", res);
   }
//   else {
//      log.print("<null>\n");
//   }
   return buff;
}

#include "UtilsX.h"

#define MAX_JTAG_CHAIN_LENGTH    (20)  //!< Max length of JTAG chain supported
#define MAX_JTAG_IR_CHAIN_LENGTH (100) //!< Max length of JTAG IR chain supported
#define MAX_KNOWN_DEVICES        (100) //!< Max number of know devices

/**
 * Save a USBDM Error code as last error and converts and sets the TCL return value
 */
static int checkUsbdmRC(Tcl_Interp *interp, USBDM_ErrorCode errorCode) {
   if (errorCode != BDM_RC_OK) {
      lastError = errorCode;
      Tcl_SetResult(interp, (char *)bdmInterface->getErrorString(errorCode), TCL_STATIC);
      return TCL_ERROR;
   }
   return TCL_OK;
}

//! Report Target status
static int reportState(Tcl_Interp *interp) {
   USBDMStatus_t usbdmStatus;
   unsigned long speed;

   if (checkUsbdmRC(interp, bdmInterface->getBDMStatus(&usbdmStatus))) {
      return TCL_ERROR;
   }
   PRINT("BDM status => %s\n", getBDMStatusName(&usbdmStatus));
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   if ((targetType != T_CFVx) && (targetType != T_JTAG)) {
      if (checkUsbdmRC(interp, bdmInterface->getSpeedHz(&speed))) {
         return TCL_ERROR;
      }
      else {
         speed = round(speed/1000.0);
         PRINT("Speed = %d kHz (%.0f ticks, sync=%.1f us)\n",
                 (int)speed, (60000.0 * 128)/speed, (1000.0 * 128)/speed);
      }
   }
   Tcl_SetResult(interp, (char*)getBDMStatusName(&usbdmStatus), TCL_VOLATILE);
   return (TCL_OK);
}

//! S12Z Mass erase
static int cmd_massErase(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   // massErase
   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "massErase");
      return TCL_ERROR;
   }
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   if (targetType != T_S12Z) {
      PRINT("Illegal command (wrong target)");
      return TCL_ERROR;
   }
   uint8_t s12ZEraseCommand[] = {0x95};
   bdmInterface->bdmCommand(sizeof(s12ZEraseCommand), 1, s12ZEraseCommand);
   return TCL_OK;
}

//! Set target Vcc - This has no affect until target is set
static int cmd_setVdd(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   // setTargetVdd <0|3|5|on|off>
   bool immediateEffect = false;
   if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "<0|3|5|on|off>");
      return TCL_ERROR;
   }
   const char *arg = Tcl_GetString(argv[1]);

   if (strncasecmp(arg, "?", 1) == 0) {
      PRINT("setTargetVdd <0|3|5|on|off>\n");
   }
   else if (strncasecmp(arg, "0", 1) == 0) {
      bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_OFF;
   }
   else if (strncasecmp(arg, "3", 1) == 0) {
      bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_3V3;
   }
   else if (strncasecmp(arg, "5", 1) == 0) {
      bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_5V;
   }
   else if (strncasecmp(arg, "on", 2) == 0) {
      immediateEffect = true;
      if (checkUsbdmRC(interp, bdmInterface->setTargetVdd(BDM_TARGET_VDD_ENABLE)))
         return TCL_ERROR;
      }
   else if (strncasecmp(arg, "off", 2) == 0) {
      immediateEffect = true;
      if (checkUsbdmRC(interp, bdmInterface->setTargetVdd(BDM_TARGET_VDD_DISABLE)))
         return TCL_ERROR;
   }
   else {
      Tcl_SetResult(interp, (char*)"Illegal target voltage", TCL_STATIC);
   }
   PRINT(":setTargetVdd %s %s\n", arg, immediateEffect?"":"(applied when target set)");
   return TCL_OK;
}

static int cmd_setMemorySpace(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   // setMemorySpace <space>
   if (argc > 1) {
      if (argc != 2) {
         Tcl_WrongNumArgs(interp, 1, argv, "?memorySpace?");
         return TCL_ERROR;
      }
      // memory space value 0,N,X,P
      const char *arg = Tcl_GetString(argv[1]);
      if (strncasecmp(arg, "0", 5) == 0) {
         defaultMemorySpace = MS_None;
      }
      else if (strncasecmp(arg, "N", 5) == 0) {
         defaultMemorySpace = MS_None;
      }
      else if (strncasecmp(arg, "U", 5) == 0) {
         defaultMemorySpace = MS_None;
      }
      else if (strncasecmp(arg, "X", 5) == 0) {
         defaultMemorySpace = MS_Data;
      }
      else if (strncasecmp(arg, "P", 5) == 0) {
         defaultMemorySpace = MS_Program;
      }
      else {
         Tcl_SetResult(interp, (char*)"Unrecognised parameter", TCL_STATIC);
         return TCL_ERROR;
      }
   }
   PRINT("Memory space = %s\n", getMemorySpaceName(defaultMemorySpace));
   Tcl_SetObjResult(interp, Tcl_NewLongObj(defaultMemorySpace));
   return TCL_OK;
}

//! Close BDM
static int cmd_closeBDM(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// cmd_openBDM [<deviceNum>]

   if (argc > 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   bdmInterface->closeBdm();
   return (TCL_OK);
}

//! Open BDM before 1st use
static int cmd_openBDM(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// cmd_openBDM [<deviceNum>]
   int deviceNum;

   if (argc > 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "[<deviceNum>]");
      return TCL_ERROR;
   }
   if (argc == 1) {
      deviceNum = 0;
   }
   else {
      if (Tcl_GetIntFromObj(interp, argv[1], &deviceNum) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "[<deviceNum>]");
         return TCL_ERROR;
      }
   }
   if (deviceNum>=(int)bdmList.size()) {
      PRINT("Illegal BDM number\n");
      return TCL_ERROR;
   }
   PRINT("Opening %s\n", bdmList.at(deviceNum).getSerialNumber().c_str());
   bdmInterface->setBdmSerialNumber(bdmList.at(deviceNum).getSerialNumber().c_str(), true);
   USBDM_ErrorCode rc = bdmInterface->initBdm();
   if (rc != BDM_RC_OK) {
      PRINT("Opening BDM failed, reason = %s\n", bdmInterface->getErrorString(rc));
      return TCL_ERROR;
   }
   PRINT("BDM Version = %s\n", bdmInterface->getBdmVersionString().c_str());

   return TCL_OK;
}

/*!
 * This callback will cause connections etc to fail quietly on error rather
 * than use a WxWidget dialogue
 */
long nullCallback(std::string message, std::string caption, long style) {
   fprintf(stderr, "Failing on error message %s:%s\n", caption.c_str(), message.c_str());
   return UsbdmWxConstants::NO;
}

//! Set target Type
static int cmd_setTarget(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   LOGGING;
   if (argc != 2) {
      Tcl_WrongNumArgs(interp, 2, argv, "<targetNumber>");
      return TCL_ERROR;
   }
   const char *arg = Tcl_GetString(argv[1]);
   bigEndian = true;
   TargetType_t targetType = T_OFF;
   if (strncasecmp(arg, "HCS12", 5) == 0) {
      targetType = T_HC12;
   }
   else if (strncasecmp(arg, "HCS08", 5) == 0) {
      targetType = T_HCS08;
   }
   else if (strncasecmp(arg, "RS08", 4) == 0) {
      targetType = T_RS08;
   }
   else if (strncasecmp(arg, "CFV1", 4) == 0) {
      targetType = T_CFV1;
   }
   else if (strncasecmp(arg, "CFVx", 4) == 0) {
      targetType = T_CFVx;
   }
   else if (strncasecmp(arg, "ARM", 3) == 0) {
      targetType = T_ARM;
      bigEndian = false;
   }
   else if (strncasecmp(arg, "SWD", 3) == 0) {
      targetType = T_ARM;
      bigEndian = false;
   }
   else if (strncasecmp(arg, "KIN", 3) == 0) {
      targetType = T_ARM;
      bigEndian = false;
   }
   else if (strncasecmp(arg, "JTAG", 4) == 0) {
      targetType = T_JTAG;
   }
   else if (strncasecmp(arg, "DSC", 4) == 0) {
      targetType = T_MC56F80xx;
      bigEndian = false;
   }
   else if (strncasecmp(arg, "S12Z", 3) == 0) {
      targetType = T_S12Z;
   }
   else if (strncasecmp(arg, "OFF", 4) == 0) {
      targetType = T_OFF;
   }
   else {
      PRINT("Unrecognised target\n");
      return TCL_ERROR;
   }
   bdmInterface.reset();
   bdmInterface = BdmInterfaceFactory::createInterface(targetType, nullCallback);
   bdmInterface->getBdmOptions().targetVdd = BDM_TARGET_VDD_3V3;
   log.print("%s", printBdmOptions(&bdmInterface->getBdmOptions()));

   PRINT("USBDM DLL Version = %s\n", bdmInterface->getDllVersionString().c_str());

   listBdms();

   PRINT(":setTarget %s\n", getTargetTypeName(targetType));
   return TCL_OK;
}

//! Set target Vpp - This has no affect until target is set
static int cmd_setVpp(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   // setTargetVpp <standby|on|off>
   if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "<standby|on|off>");
      return TCL_ERROR;
   }
   const char *arg = Tcl_GetString(argv[1]);
   if (strncasecmp(arg, "?", 1) == 0) {
      PRINT("setTargetVpp <standby|on|off>\n");
   }
   else if (strncasecmp(arg, "standby", 2) == 0) {
      if (checkUsbdmRC(interp, bdmInterface->setTargetVpp(BDM_TARGET_VPP_STANDBY)))
         return TCL_ERROR;
   }
   else if (strncasecmp(arg, "on", 2) == 0) {
      if (checkUsbdmRC(interp, bdmInterface->setTargetVpp(BDM_TARGET_VPP_ON)))
         return TCL_ERROR;
   }
   else if (strncasecmp(arg, "off", 2) == 0) {
      if (checkUsbdmRC(interp, bdmInterface->setTargetVpp(BDM_TARGET_VPP_OFF)))
         return TCL_ERROR;
   }
   else {
      Tcl_SetResult(interp, (char*)"Illegal target Vpp state", TCL_STATIC);
   }
   PRINT(":setTargetVpp %s\n", arg);
   return TCL_OK;
}

/*
 *  Reset Target to Special Mode
 */
static int cmd_reset(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   TargetMode_t targetMode = (TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT);
   const char *currentToken;

   if (argc > 1) {
      currentToken = Tcl_GetString(argv[1]);
      // Reset method
      if (currentToken != NULL) {
         switch(*currentToken) {
         case 'n':
         case 'N' :
            targetMode = (TargetMode_t)(targetMode & ~RESET_MODE_MASK);
            targetMode = (TargetMode_t)(targetMode | RESET_NORMAL);
            break;
         case 's':
         case 'S' :
            targetMode = (TargetMode_t)(targetMode & ~RESET_MODE_MASK);
            targetMode = (TargetMode_t)(targetMode | RESET_SPECIAL);
            break;
         }
      }
   }
   currentToken++;
   if (argc > 2) {
      currentToken = Tcl_GetString(argv[2]);
   }
   if (argc > 1) {
      if (currentToken != NULL) {
         switch(*currentToken) {
         case 'h':
         case 'H' :
            targetMode = (TargetMode_t)(targetMode & ~RESET_METHOD_MASK);
            targetMode = (TargetMode_t)(targetMode | RESET_HARDWARE);
            break;
         case 's':
         case 'S' :
            targetMode = (TargetMode_t)(targetMode & ~RESET_METHOD_MASK);
            targetMode = (TargetMode_t)(targetMode | RESET_SOFTWARE);
            break;
         case 'a':
         case 'A' :
            targetMode = (TargetMode_t)(targetMode & ~RESET_METHOD_MASK);
            targetMode = (TargetMode_t)(targetMode | RESET_ALL);
            break;
         case 'd':
         case 'D' :
            targetMode = (TargetMode_t)(targetMode & ~RESET_METHOD_MASK);
            targetMode = (TargetMode_t)(targetMode | RESET_DEFAULT);
            break;
         case 'p':
         case 'P' :
            targetMode = (TargetMode_t)(targetMode & ~RESET_METHOD_MASK);
            targetMode = (TargetMode_t)(targetMode | RESET_POWER);
            break;
         }
      }
   }
   if (checkUsbdmRC(interp,  bdmInterface->reset(targetMode)) != BDM_RC_OK) {
      PRINT(":reset %s - Failed\n", getTargetModeName(targetMode));
      return TCL_ERROR;
   }
   PRINT(":reset %s\n", getTargetModeName(targetMode));
   return TCL_OK;
}

//! Connect to target
static int cmd_connect(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   // connect
   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->connect()) != 0) {
      return TCL_ERROR;
   }
   PRINT(":connect\n");

   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   if ((targetType != T_CFVx) && (targetType != T_JTAG) &&
       (targetType != T_ARM) && (targetType != T_MC56F80xx)) {
      reportState(interp);
   }
   return TCL_OK;
}

#if 0
//! Translates values from bitmask to string for printing
static const char *translateBKGDValue( uint16_t value ) {
   switch (value & PIN_BKGD) {
      case PIN_BKGD_LOW    : return "L";
      case PIN_BKGD_HIGH   : return "H";
      case PIN_BKGD_3STATE : return "3-state";
      default              : return "-";
   }
}

//! Translates values from bitmask to string for printing
static const char *translateRESETValue( uint16_t value ) {
   switch (value & PIN_RESET) {
      case PIN_RESET_LOW    : return "L";
      case PIN_RESET_3STATE : return "3-state";
      default               : return "-";
   }
}

//! Translates values from bitmask to string for printing
static const char *translateTRSTValue( uint16_t value ) {
   switch (value & PIN_TRST) {
      case PIN_TRST_LOW    : return "L";
      case PIN_TRST_3STATE : return "3-state";
      default              : return "-";
   }
}

//! Translates values from bitmask to string for printing
static const char *translateTAValue( uint16_t value ) {
   switch (value & PIN_TA) {
      case PIN_TA_LOW    : return "L";
      case PIN_TA_3STATE : return "3-state";
      default            : return "-";
   }
}
#endif

static int getPinControlValue(const char *ch) {
   switch (*ch) {
   case '1' :
   case 'h' :
   case 'H' : return 3;
   case '0' :
   case 'l' :
   case 'L' : return 2;
   case 't' :
   case 'T' :
   case '3' : return 1;
   case '-' : return 0;
   default  : return 0;
   }
}
//! Connect to target
static int cmd_pinSet(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   uint32_t value = 0;

   if (argc == 1) {
      if (checkUsbdmRC(interp, bdmInterface->controlPins(PIN_RELEASE, NULL)))
         return TCL_ERROR;
      PRINT(":pinSet - all released\n");
      return (TCL_OK);
   }
   while (argc-- > 1) {
      const char *arg = Tcl_GetString(argv[argc]);

      if (strncasecmp(arg, "?", 1) == 0) {
         PRINT("pinSet RST|TRST|BKGD|TA|BKPT = 0|L|1|H|3|T\n");
      }
      if (strncasecmp(arg, "RST=", 4) == 0) {
         value |= getPinControlValue(arg+4)<<PIN_RESET_OFFS;
      }
      else if (strncasecmp(arg, "TRST=", 5) == 0) {
         value |= getPinControlValue(arg+5)<<PIN_TRST_OFFS;
      }
      else if (strncasecmp(arg, "BKGD=", 5) == 0) {
         value |= getPinControlValue(arg+5)<<PIN_BKGD_OFFS;
      }
      else if (strncasecmp(arg, "TA=", 3) == 0) {
         value |= getPinControlValue(arg+3)<<PIN_TA_OFFS;
      }
      else if (strncasecmp(arg, "BKPT=", 5) == 0) {
         value |= getPinControlValue(arg+5)<<PIN_BKPT_OFFS;
      }
      else if (strncasecmp(arg, "SWD=", 4) == 0) {
         value |= getPinControlValue(arg+4)<<PIN_SWD_OFFS;
      }
      else {
         Tcl_SetResult(interp, (char*)"Unrecognised parameter", TCL_STATIC);
      }
   }
   if (checkUsbdmRC(interp, bdmInterface->controlPins(value, NULL))) {
      return TCL_ERROR;
   }
   PRINT(":pinSet %s\n", getPinLevelName((PinLevelMasks_t)value));
   return TCL_OK;
}

//! Halt Target
static int cmd_halt(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// halt
   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->halt()) != 0) {
      return TCL_ERROR;
   }
   PRINT(":halt\n");
   return TCL_OK;
}

//! Start Target execution
static int cmd_go(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// go
   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   unsigned long   oldPC=0;
   unsigned        oldInstruction;
   if (checkUsbdmRC(interp,  bdmInterface->readPC(&oldPC)) != 0) {
      return TCL_ERROR;
   }
   bdmInterface->readMemory(1,4,oldPC,(uint8_t*)&oldInstruction);
   swapEndian32(&oldInstruction);
   if (checkUsbdmRC(interp,  bdmInterface->go()) != 0) {
      return TCL_ERROR;
   }
   PRINT(":go, from PC = 0x%08X : 0x%4.4X 0x%4.4X\n",
          (int)oldPC, oldInstruction>>16, oldInstruction&0xFFFF);
   return TCL_OK;
}

//! Step Target
static int cmd_step(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// step
   if (argc > 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   unsigned long   oldPC, nextPC;
   uint32_t   oldInstruction, nextInstruction;
   int   count = 1;
   if (argc > 1) {
      // # steps
      if (Tcl_GetIntFromObj(interp, argv[1], &count) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>1");
         return TCL_ERROR;
      }
   }
   while (count-->0) {
      bdmInterface->readPC(&oldPC);
      bdmInterface->readMemory(1,4,oldPC,(uint8_t*)&oldInstruction);
      swapEndian32(&oldInstruction);
      if (checkUsbdmRC(interp,  bdmInterface->step()) != 0) {
         PRINT(":step - Failed\n");
         return TCL_ERROR;
      }
      bdmInterface->readPC(&nextPC);
      bdmInterface->readMemory(1,4,nextPC,(uint8_t*)&nextInstruction);
      swapEndian32(&nextInstruction);
      PRINT(":step, from PC = 0x%08X : 0x%4.4X 0x%4.4X, to PC = 0x%08X : 0x%4.4X 0x%4.4X, \n",
            (int)oldPC,  oldInstruction>>16,  oldInstruction&0xFFFF,
            (int)nextPC, nextInstruction>>16, nextInstruction&0xFFFF);
   }
   return TCL_OK;
}

//! Read & report Status Value from Target status register
static int cmd_getCapabilities(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   HardwareCapabilities_t bdmCapabilities;

   USBDM_ErrorCode rc = bdmInterface->getCapabilities(&bdmCapabilities);
   if (rc != BDM_RC_OK) {
      PRINT("getCapabilities() Failed, rc = %s\n", bdmInterface->getErrorString(rc));
      return TCL_ERROR;
   }
   PRINT("getcap => %s\n", getCapabilityName(bdmCapabilities));
   Tcl_SetObjResult(interp, Tcl_NewIntObj(bdmCapabilities));
   return TCL_OK;
}

//! Read & report Status Value from Target status register
static int cmd_status(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   unsigned long BDMStatus = 0x00;

   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   if (targetType == T_ARM) {
      uint8_t  value[4];
      uint32_t data;
      unsigned long lValue;

      if (checkUsbdmRC(interp,  bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &lValue)) != BDM_RC_OK) {
         PRINT("MDM-AP.Status  => Failed\n");
      }
      else {
         PRINT("MDM-AP.Status  => 0x%08lX %s\n", lValue, getMDM_APStatusName(lValue));
      }
      if (checkUsbdmRC(interp,  bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &lValue)) != BDM_RC_OK) {
         PRINT("MDM-AP.Control => Failed\n");
      }
      else {
         PRINT("MDM-AP.Control => 0x%08lX %s\n", lValue, getMDM_APControlName(lValue));
      }
      if (checkUsbdmRC(interp,  bdmInterface->readMemory(4,4,DHCSR,value)) != BDM_RC_OK) {
         PRINT("DHCSR          => Failed\n");
      }
      else {
         data = getData32(value);
         PRINT("DHCSR          => 0x%08X %s\n", data, getDHCSRName(data));
      }
      if (checkUsbdmRC(interp,  bdmInterface->readMemory(4,4,DEMCR,value)) != BDM_RC_OK) {
         PRINT("DEMCR          => Failed\n");
      }
      else {
         data = getData32(value);
         PRINT("DEMCR          => 0x%08X %s\n", data, getDEMCRName(data));
      }
      if (checkUsbdmRC(interp,  bdmInterface->readMemory(1,1,MC_SRSH,value)) != BDM_RC_OK) {
         PRINT("MC_SRSH        => Failed\n");
      }
      else {
         data = value[0];
         PRINT("MC_SRSH        => 0x%8.2X %s\n", data, getSRSHName(data));
      }
      if (checkUsbdmRC(interp,  bdmInterface->readMemory(1,1,MC_SRSL,value)) != BDM_RC_OK) {
         PRINT("MC_SRSL        => Failed\n");
      }
      else {
         data = value[0];
         PRINT("MC_SRSL        => 0x%8.2X %s\n", data, getSRSLName(data));
      }
      if (checkUsbdmRC(interp,  bdmInterface->readMemory(2,2,WDOG_RSTCNT,value)) != BDM_RC_OK) {
         PRINT("WDOG_RSTCNT    => Failed\n");
      }
      else {
         data = getData16(value);
         PRINT("WDOG_RSTCNT    => 0x%8.4X\n", data);
      }
      Tcl_SetObjResult(interp, Tcl_NewIntObj(0));
      return TCL_OK;
   }
   else if (targetType == T_MC56F80xx) {
      unsigned status;
      bdmInterface->getStatus(&status);
      PRINT("DSC Target status => %s\n", DSC_GetOnceStatusName((OnceStatus_t)status));
      Tcl_SetObjResult(interp, Tcl_NewIntObj(status));
      return TCL_OK;
   }
   else {
      if (checkUsbdmRC(interp,  bdmInterface->readStatusReg(&BDMStatus)) != BDM_RC_OK) {
         return TCL_ERROR;
      }
      PRINT("Target status reg => %s\n",
             getStatusRegName(targetType, BDMStatus));
      reportState(interp);
      Tcl_SetObjResult(interp, Tcl_NewIntObj(BDMStatus));
      return TCL_OK;
   }
}

//! Get last USBDM error code as number
static int cmd_getLastError(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   Tcl_SetObjResult(interp, Tcl_NewIntObj(lastError));
   lastError = BDM_RC_OK;
   return TCL_OK;
}

//! Get last USBDM error code as message
static int cmd_getErrorMessage(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   if (argc > 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   int error;
   if (argc > 1) {
      // # steps
      if (Tcl_GetIntFromObj(interp, argv[1], &error) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<value>");
         return TCL_ERROR;
      }
   }
   Tcl_SetResult(interp, (char*)bdmInterface->getErrorString((USBDM_ErrorCode)error), TCL_STATIC);
   return TCL_OK;
}

//! Get last USBDM error code as message
static int cmd_getLastErrorMessage(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   Tcl_SetResult(interp, (char*)bdmInterface->getErrorString(lastError), TCL_STATIC);
   lastError = BDM_RC_OK;
   return TCL_OK;
}

//! Read & report Status Value from Target status register - no sync
static int cmd_readStatus(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   uint8_t value[4];
   unsigned long regValue;

   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   switch (targetType) {
   case  T_ARM:
      if (checkUsbdmRC(interp,  bdmInterface->readMemory(1,4,DHCSR,value)) != BDM_RC_OK) {
         return TCL_ERROR;
      }{
      uint32_t data = getData32(value);
      PRINT("DHCSR reg => %s(0x%08X)\n", getDHCSRName(data), data);
      Tcl_SetObjResult(interp, Tcl_NewIntObj(data));
      }
      return TCL_OK;
   case T_CFV1:
      if (checkUsbdmRC(interp,  bdmInterface->readDReg(CFV1_DRegXCSRbyte,&regValue)) != BDM_RC_OK) {
         return TCL_ERROR;
      }
      PRINT("XCSR.byte reg => %s(0x%02X)\n", getCFV1_XCSR_Name(regValue), (unsigned int)regValue);
      Tcl_SetObjResult(interp, Tcl_NewIntObj(regValue));
      return TCL_OK;
   case T_HCS08:
      if (checkUsbdmRC(interp,  bdmInterface->readStatusReg(&regValue)) != BDM_RC_OK) {
         return TCL_ERROR;
      }
      PRINT("BDCSCR reg => %s(0x%02X)\n", getHCS08_BDCSCR_Name(regValue), (unsigned int)regValue);
      Tcl_SetObjResult(interp, Tcl_NewIntObj(regValue));
      return TCL_OK;
   default:
      break;
   }
   return TCL_ERROR;
}

//! Read Registers from Target
static int cmd_registers(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   static const int HCS12regList[] = {HCS12_RegPC, HCS12_RegD, HCS12_RegX, HCS12_RegY, HCS12_RegSP};
   static const int HCS12ZregList[] = {
        S12Z_RegD0, S12Z_RegD1, S12Z_RegD2, S12Z_RegD3, S12Z_RegD4, S12Z_RegD5, S12Z_RegD6, S12Z_RegD7,
        S12Z_RegX, S12Z_RegY, S12Z_RegSP, S12Z_RegPC, S12Z_RegCCR
   };
   static const int HCS12ZregListWidth[] = {
       1, 1, 2, 2, 2, 2, 4, 4, 3, 3, 3, 3, 2
   };
   static const int HCS08regList[] = {HCS08_RegPC, HCS08_RegA, HCS08_RegHX, HCS08_RegSP};
   static const int RS08regList[]  = {RS08_RegCCR_PC, RS08_RegSPC, RS08_RegA};
   static const int DSCregList[]   = {
         DSC_RegA2,   DSC_RegA1,   DSC_RegA0,  -1,
         DSC_RegB2,   DSC_RegB1,   DSC_RegB0,  -1,
         DSC_RegC2,   DSC_RegC1,   DSC_RegC0,  -1,
         DSC_RegD2,   DSC_RegD1,   DSC_RegD0,  -1,
         DSC_RegY1,   DSC_RegY0,   DSC_RegX0,  -1,
         DSC_RegR0,   DSC_RegR1,   DSC_RegR2,  DSC_RegR3,
         DSC_RegR4,   DSC_RegR5,   DSC_RegN,   DSC_RegSP,
         DSC_RegN3,   DSC_RegM01,  DSC_RegOMR, -1,
         DSC_RegPC,   DSC_RegLA,   -1,         -1,
         DSC_RegLC, };
   static const int ARMregList[]   = {
         ARM_RegR0,    ARM_RegR1,   ARM_RegR2,    ARM_RegR3,
         ARM_RegR4,    ARM_RegR5,   ARM_RegR6,    ARM_RegR7,
         ARM_RegR8,    ARM_RegR9,   ARM_RegR10,   ARM_RegR11,
         ARM_RegR12,   ARM_RegSP,   ARM_RegLR,    ARM_RegPC,
         ARM_RegxPSR,  ARM_RegMSP,  ARM_RegPSP,   -1,
         ARM_RegFPSCR, ARM_RegMISC, };
   unsigned regIndex;
   int regNo;
   unsigned long regVal;
   unsigned long oldPC;
   unsigned int oldInstruction;
   int rc = TCL_OK;

   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   PRINT("regs\n");

   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   switch (targetType) {
      case T_HC12 :
         for ( regIndex =0;
               (regIndex<sizeof(HCS12regList)/sizeof(HCS12regList[0])) && (rc == TCL_OK);
               regIndex++) {
            regNo = HCS12regList[regIndex];
            if (checkUsbdmRC(interp,  bdmInterface->readReg(regNo, &regVal))) {
               return TCL_ERROR;
            }
            PRINT("%3s =%4X, ", getHCS12RegName(regNo), (int)regVal);
         }
         PRINT("\n");
         if (checkUsbdmRC(interp,  bdmInterface->readPC(&oldPC))) {
            return TCL_ERROR;
         }
         PRINT("PC = 0x%4.4X : ", (int)oldPC);
         if (bdmInterface->readMemory(1,4,oldPC,(uint8_t*)&oldInstruction) == BDM_RC_OK) {
            swapEndian32(&oldInstruction);
            PRINT("0x%4.4X 0x%4.4X\n", oldInstruction>>16, oldInstruction&0xFFFF);
         }
         else {
            PRINT("<invalid>\n");
         }
         break;
      case T_S12Z :
         for (regIndex =0;
             (regIndex<sizeof(HCS12ZregList)/sizeof(HCS12ZregList[0])) && (rc == TCL_OK);
             regIndex++) {
            regNo = HCS12ZregList[regIndex];
            if (regNo>=0) {
               if (checkUsbdmRC(interp,  bdmInterface->readReg(regNo, &regVal))) {
                  return TCL_ERROR;
               }
               int width = 2*HCS12ZregListWidth[regIndex];
               PRINT("%4s => %.*s%0*X, ", getS12ZRegName(regNo), 8-width, "        ", width, (int)regVal);
            }
            if ((regIndex&0x03)== 0x03)
               PRINT("\n");
         }
         PRINT("\n");
         if (checkUsbdmRC(interp,  bdmInterface->readPC(&oldPC))) {
            return TCL_ERROR;
         }
         PRINT("PC = 0x%06X : ", (int)oldPC);
         if (bdmInterface->readMemory(1,4,oldPC,(uint8_t*)&oldInstruction) == BDM_RC_OK) {
            swapEndian32(&oldInstruction);
            PRINT("0x%4.4X 0x%4.4X\n", oldInstruction>>16, oldInstruction&0xFFFF);
         }
         else {
            PRINT("<invalid>\n");
         }
         break;
      case T_HCS08 :
         for (regIndex =0;
              (regIndex<sizeof(HCS08regList)/sizeof(HCS08regList[0])) && (rc == TCL_OK);
              regIndex++) {
            regNo = HCS08regList[regIndex];
            if (checkUsbdmRC(interp,  bdmInterface->readReg(regNo, &regVal))) {
               return TCL_ERROR;
            }
            PRINT("%3s =%4X, ", getHCS08RegName(regNo), (int)regVal);
         }
         PRINT("\n");
         if (checkUsbdmRC(interp,  bdmInterface->readPC(&oldPC))) {
            return TCL_ERROR;
         }
         PRINT("PC = 0x%4.4X : ", (int)oldPC);
         if (bdmInterface->readMemory(1,4,oldPC,(uint8_t*)&oldInstruction) == BDM_RC_OK) {
            swapEndian32(&oldInstruction);
            PRINT("0x%4.4X 0x%4.4X\n", oldInstruction>>16, oldInstruction&0xFFFF);
         }
         else {
            PRINT("<invalid>\n");
         }
         break;
      case T_RS08 :
         for (regIndex =0;
              (regIndex<sizeof(RS08regList)/sizeof(RS08regList[0])) && (rc == TCL_OK);
              regIndex++) {
            regNo = RS08regList[regIndex];
            if (checkUsbdmRC(interp,  bdmInterface->readReg(regNo, &regVal))) {
               return TCL_ERROR;
            }
            PRINT("%3s =%4X, ", getRS08RegName(regNo), (int)regVal);
         }
         PRINT("\n");
         if (checkUsbdmRC(interp,  bdmInterface->readReg(RS08_RegCCR_PC, &oldPC))) {
            return TCL_ERROR;
         }
         oldPC &= 0x3FFF;
         PRINT("PC = 0x%4.4X : ", (int)oldPC);
         if (bdmInterface->readMemory(1,4,oldPC,(uint8_t*)&oldInstruction) == BDM_RC_OK) {
            swapEndian32(&oldInstruction);
            PRINT("0x%4.4X 0x%4.4X\n", oldInstruction>>16, oldInstruction&0xFFFF);
         }
         else {
            PRINT("<invalid>\n");
         }
         break;
      case T_CFV1 :
         for( regNo = 0; (regNo<=15) && (rc == TCL_OK); regNo++) {  // D0-7, A0-7
            if (checkUsbdmRC(interp,  bdmInterface->readReg(regNo, &regVal))) {
               return TCL_ERROR;
            }
            PRINT("%3s =%08X, ", getCFV1RegName(regNo), (int)regVal);
            if ((regNo&0x03)== 0x03)
               PRINT("\n");
         }
         if (rc != TCL_OK) {
            break;
         }
         if (checkUsbdmRC(interp,  bdmInterface->readPC(&regVal))) { // PC
            return TCL_ERROR;
         }
         PRINT("%3s =%08X, ", getCFV1ControlRegName(CFV1_CRegPC), (int)regVal);
         if (checkUsbdmRC(interp,  bdmInterface->readCReg(CFV1_CRegSR, &regVal))) { // SR
            return TCL_ERROR;
         }
         PRINT("%3s =%C-%C%C-%d---%C%C%C%C%C,          ",
                getCFV1ControlRegName(CFV1_CRegSR),
                (regVal&0x8000)?'T':'-',
                (regVal&0x2000)?'S':'-',
                (regVal&0x1000)?'M':'-',
                (uint8_t)(regVal>>8)&0x7,
                (regVal&0x0010)?'X':'-',
                (regVal&0x0008)?'N':'-',
                (regVal&0x0004)?'Z':'-',
                (regVal&0x0002)?'V':'-',
                (regVal&0x0001)?'C':'-' );
         if (checkUsbdmRC(interp,  bdmInterface->readCReg(CFV1_CRegOTHER_A7, &regVal))) { // Other A7
            return TCL_ERROR;
         }
         PRINT("%3s =%08X, \n", getCFV1ControlRegName(CFV1_CRegOTHER_A7), (int)regVal);
         if (checkUsbdmRC(interp,  bdmInterface->readCReg(CFV1_CRegVBR, &regVal))) { // VBR
            return TCL_ERROR;
         }
         regVal &= 0x00F00000;
         PRINT("%3s =%08X, ", getCFV1ControlRegName(CFV1_CRegVBR), (int)regVal);
         if (checkUsbdmRC(interp, bdmInterface->readCReg(CFV1_CRegCPUCR, &regVal))) { // CPUCR
            return TCL_ERROR;
         }
         PRINT("%3s =%08X\n", getCFV1ControlRegName(CFV1_CRegCPUCR), (int)regVal);
         if (checkUsbdmRC(interp,  bdmInterface->readPC(&oldPC))) {
            return TCL_ERROR;
         }
         PRINT("PC = 0x%08X : ", (int)oldPC);
         if (bdmInterface->readMemory(1,4,oldPC,(uint8_t*)&oldInstruction) == BDM_RC_OK) {
            swapEndian32(&oldInstruction);
            PRINT("0x%4.4X 0x%4.4X\n", oldInstruction>>16, oldInstruction&0xFFFF);
         }
         else {
            PRINT("<invalid>\n");
         }
         break;
      case T_CFVx :
         for( regNo = 0; (regNo<=15) && (rc == TCL_OK); regNo++) { // D0-7, A0-7
            if (checkUsbdmRC(interp,  bdmInterface->readReg(regNo, &regVal))) {
               return TCL_ERROR;
            }
            PRINT("%3s =%08X, ", getCFVxRegName(regNo), (int)regVal);
            if ((regNo&0x03)== 0x03)
               PRINT("\n");
         }
         if (checkUsbdmRC(interp,  bdmInterface->readPC(&regVal))) { // PC
            return TCL_ERROR;
         }
         PRINT("%3s =%08X, ", getCFVxControlRegName(CFVx_CRegPC), (int)regVal);
         if (checkUsbdmRC(interp,  bdmInterface->readCReg(CFVx_CRegSR, &regVal))) { // SR
            return TCL_ERROR;
         }
         PRINT("%3s =%C-%C%C-%d---%C%C%C%C%C,          ",
                getCFVxControlRegName(CFVx_CRegSR),
                (regVal&0x8000)?'T':'-',
                (regVal&0x2000)?'S':'-',
                (regVal&0x1000)?'M':'-',
                (uint8_t)(regVal>>8)&0x7,
                (regVal&0x0010)?'X':'-',
                (regVal&0x0008)?'N':'-',
                (regVal&0x0004)?'Z':'-',
                (regVal&0x0002)?'V':'-',
                (regVal&0x0001)?'C':'-' );
         if (checkUsbdmRC(interp,  bdmInterface->readCReg(CFVx_CRegOTHER_SP, &regVal))) { // Other A7
            return TCL_ERROR;
         }
         PRINT("%3s =%08X\n", getCFVxControlRegName(CFVx_CRegOTHER_SP), (int)regVal);
         if (checkUsbdmRC(interp,  bdmInterface->readCReg(CFVx_CRegVBR, &regVal))) { // VBR
            return TCL_ERROR;
         }
         PRINT("%3s =%08X, ", getCFVxControlRegName(CFVx_CRegVBR), (int)regVal);
         if (checkUsbdmRC(interp,  bdmInterface->readCReg(CFV1_CRegFLASHBAR, &regVal))) {// FLASHBAR
            return TCL_ERROR;
         }
         PRINT("%3s =%08X, ", getCFVxControlRegName(CFV1_CRegFLASHBAR), (int)regVal);
         if (checkUsbdmRC(interp,  bdmInterface->readCReg(CFV1_CRegRAMBAR, &regVal))) { // RAMBAR
            return TCL_ERROR;
         }
         PRINT("%3s =%08X\n", getCFVxControlRegName(CFV1_CRegRAMBAR), (int)regVal);
         if (checkUsbdmRC(interp,  bdmInterface->readPC(&oldPC))) {
            return TCL_ERROR;
         }
         PRINT("PC = 0x%08X : ", (int)oldPC);
         if (bdmInterface->readMemory(1,4,oldPC,(uint8_t*)&oldInstruction) == BDM_RC_OK) {
            swapEndian32(&oldInstruction);
            PRINT("0x%4.4X 0x%4.4X\n", oldInstruction>>16, oldInstruction&0xFFFF);
         }
         else {
            PRINT("<invalid>\n");
         }
         break;
      case T_ARM :
         for (regIndex =0;
             (regIndex<sizeof(ARMregList)/sizeof(ARMregList[0])) && (rc == TCL_OK);
             regIndex++) {
            regNo = ARMregList[regIndex];
            if (regNo>=0) {
               if (checkUsbdmRC(interp,  bdmInterface->readReg(regNo, &regVal))) {
                  return TCL_ERROR;
               }
               PRINT("%4s => %08X, ", getARMRegName(regNo), (int)regVal);
            }
            if ((regIndex&0x03)== 0x03)
               PRINT("\n");
         }
         PRINT("\n");
         if (checkUsbdmRC(interp,  bdmInterface->readPC(&oldPC))) {
            return TCL_ERROR;
         }
         PRINT("PC = 0x%08X : ", (int)oldPC);
         if (bdmInterface->readMemory(1,4,oldPC,(uint8_t*)&oldInstruction) == BDM_RC_OK) {
            swapEndian32(&oldInstruction);
            PRINT("0x%4.4X 0x%4.4X\n", oldInstruction>>16, oldInstruction&0xFFFF);
         }
         else {
            PRINT("<invalid>\n");
         }
         break;
      case T_MC56F80xx:
         DSC_SetLogFile(NULL);
         for (regIndex =0;
              (regIndex<sizeof(DSCregList)/sizeof(DSCregList[0])) && (rc == TCL_OK);
              regIndex++) {
            regNo = DSCregList[regIndex];
            if (regNo >= 0) {
               if (checkUsbdmRC(interp,  bdmInterface->readReg(regNo, &regVal))) {
                  return TCL_ERROR;
               }
               PRINT("%-10s=0x%08lX, ", getDSCRegName(regNo), regVal);
            }
            if ((regIndex%4) == 3) {
               PRINT("\n");
            }
         }
         PRINT("\n");
         break;
      default:
         break;
   }
   return rc;
}

//! Convert string to long integer
//!
//! @param start = ptr to string to convert
//! @param value = value read
//!
//! @return TCL_OK    => OK \n
//!         TCL_ERROR => failed
//!
//! @note Accepts decimal, octal with '0' prefix or hex with '0x' prefix
//!
static int strToULong(const char *start, uint32_t *value) {
   char *end_t;
   unsigned long value_t = strtoul(start, &end_t, 0);

//   PRINT("strToULong() - s=\'%s\', e='%s', val=%ld(0x%lX)\n", start, end_t, value_t, value_t);
   if (end_t == start) { // no String found
      PRINT("strToLong() - No number found\n");
      return TCL_ERROR;
   }
   if ((ULONG_MAX == value_t) && (ERANGE == errno)) { // too large
     PRINT("strToULong() - Number too large\n");
     return TCL_ERROR;
   }
   // If end is not used then check if at end of string
   // Skip trailing spaces
   while (isspace(*end_t)) {
      end_t++;
   }
   if (*end_t != '\0') {
      PRINT("strToULong() - Unexpected chars following number (%s)\n", start);
      return TCL_ERROR;
   }
   *value = value_t;
   return TCL_OK;
}

//! Convert string to address as integer.
//!
//! @param arg         = arg to convert
//! @param value       = value read
//! @param memorySpace = memory space (optional), modified if memory space modifier is used with address.
//!
//! @return TCL_OK    => OK \n
//!         TCL_ERROR => failed
//!
//! @note Accepts decimal, octal with '0' prefix or hex with '0x' prefix.
//! @note May have optional memory space prefix (X: P: G:)
//!
static int getAddress(Tcl_Obj *const arg, uint32_t *value, int *memorySpace) {
   const char *sAddress  = Tcl_GetString(arg);
   uint32_t scale = 1;

   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   if (targetType == T_MC56F80xx) {
      // Check for memory space info
      if (strncasecmp(sAddress, "X:", 2) == 0) {
         if (memorySpace == NULL) {
            PRINT("Illegal address modifier in arg \'%s\'\n", sAddress);
            return TCL_ERROR;
         }
         *memorySpace |= MS_Data;
         sAddress += 2;
      }
      else if (strncasecmp(sAddress, "P:", 2) == 0) {
         if (memorySpace == NULL) {
            PRINT("Illegal address modifier in arg \'%s\'\n", sAddress);
            return TCL_ERROR;
         }
         *memorySpace |= MS_Program;
         sAddress += 2;
      }
      if ((*memorySpace & MS_SIZE)>1) {
         // Scale address from DSC word/long => byte address used by USBDM interface
         scale = 2;
      }
   }
   else if (targetType == T_HC12) {
      if (strncasecmp(sAddress, "G:", 2) == 0) {
         if (memorySpace == NULL) {
            PRINT("Illegal address modifier in arg \'%s\'\n", sAddress);
            return TCL_ERROR;
         }
         *memorySpace |= MS_Global;
         sAddress += 2;
      }
   }
   int rc = strToULong(sAddress, value);
   if (rc != TCL_OK) {
      PRINT("Illegal address in arg \'%s\'\n", sAddress);
   }
   *value *= scale;
   return rc;
}

//! Write a byte to target Memory
static int cmd_writeByte(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// wb <addr> <data>...
   uint32_t address;
   int data;
   int count;
   uint8_t  buff[200];
   int memSpace = MS_Byte;

   if (argc < 3) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>...");
      return TCL_ERROR;
   }
   // # address
   if (getAddress(argv[1], &address, &memSpace) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>...");
      return TCL_ERROR;
   }
   if (argc > 50)
      argc = 50;

   // Data value
   for (count = 0; count < argc-2; count++) {
      // # data
      if (Tcl_GetIntFromObj(interp, argv[count+2], &data) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>1");
         return TCL_ERROR;
      }
      buff[count] = (uint8_t) data;
   }
   if (count <= 0) {
      return TCL_OK;
   }
   if (checkUsbdmRC(interp,  bdmInterface->writeMemory(memSpace, count, address, buff)) != 0) {
      PRINT(":wb Failed\n");
      return TCL_ERROR;
   }
   PRINT(":wb 0x%08X <= 0x%2.2X ...\n", address, data);
   return TCL_OK;
}

//! Write a word to target Memory
static int cmd_writeWord(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// ww <addr> <data>
   uint32_t address;
   int data;
   int count;
   uint8_t  buff[200];
   int memSpace = MS_Word|defaultMemorySpace;

   if (argc < 3) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   // # address
   if (getAddress(argv[1], &address, &memSpace) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>...");
      return TCL_ERROR;
   }
   // # Data values
   for (count = 0; count < argc-2; count++) {
      // # data
      if (Tcl_GetIntFromObj(interp, argv[count+2], &data) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>1");
         return TCL_ERROR;
      }
      const uint8_t *dataPtr = getData2x8(data);
      buff[2*count]   = dataPtr[0];
      buff[2*count+1] = dataPtr[1];
   }
   if (checkUsbdmRC(interp,  bdmInterface->writeMemory(memSpace, 2*count, address, buff)) != 0) {
      PRINT(":ww Failed\n");
      return TCL_ERROR;
   }
   PRINT(":ww 0x%08X <= 0x%4.4X\n", address, data);
   return TCL_OK;
}

//! Write a long word to target Memory
static int cmd_writeLong(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// wl <addr> <data>
   uint32_t address;
   int data;
   int count;
   uint8_t  buff[200];
   int memSpace = MS_Long|defaultMemorySpace;

   if (argc < 3) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   // # address
   if (getAddress(argv[1], &address, &memSpace) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>...");
      return TCL_ERROR;
   }
   // # data
   if (Tcl_GetIntFromObj(interp, argv[2], &data) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>1");
      return TCL_ERROR;
   }
   // # Data values
   for (count = 0; count < argc-2; count++) {
      // # data
      if (Tcl_GetIntFromObj(interp, argv[count+2], &data) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>1");
         return TCL_ERROR;
      }
      const uint8_t *dataPtr = getData4x8(data);
      buff[4*count]   = dataPtr[0];
      buff[4*count+1] = dataPtr[1];
      buff[4*count+2] = dataPtr[2];
      buff[4*count+3] = dataPtr[3];
   }
   if (checkUsbdmRC(interp,  bdmInterface->writeMemory(memSpace, 4*count, address, buff)) != 0) {
      PRINT(":wl Failed\n");
      return TCL_ERROR;
   }
   PRINT(":wl 0x%08X <= 0x%08X\n", address, data);
   return TCL_OK;
}

//! Write to Target PC (HC12, HCS08 & RS08)
static int cmd_writeProgramCounter(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// wpc<addr> <data>
   int  data;

   if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "<pc_value>");
      return TCL_ERROR;
   }
   // # PC value
   if (Tcl_GetIntFromObj(interp, argv[1], &data) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <pc_value>1");
      return TCL_ERROR;
   }
   bdmInterface->writePC(data);
   PRINT(":wpc 0x%X\n", data);
   return TCL_OK;
}

//! Write to Target Core Register
static int cmd_writeReg(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// wreg <addr> <data>
   int  data;
   int  regNo;

   if (argc != 3) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   // Register #
   if (Tcl_GetIntFromObj(interp, argv[1], &regNo) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   // # data
   if (Tcl_GetIntFromObj(interp, argv[2], &data) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->writeReg(regNo, data)) != TCL_OK) {
      PRINT(":wReg Failed\n");
      return TCL_ERROR;
   }
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   PRINT(":wReg r=0x%X(%s)<-0x%08X\n",
          regNo, getRegName( targetType, regNo ), data);
   return TCL_OK;
}

//! Write to Target Core Register
static int cmd_writeDReg(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// wdreg <addr> <data>
   int  data;
   int  regNo;

   if (argc != 3) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   // Register #
   if (Tcl_GetIntFromObj(interp, argv[1], &regNo) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   // # data
   if (Tcl_GetIntFromObj(interp, argv[2], &data) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->writeDReg(regNo, data)) != 0) {
      PRINT(":wDReg Failed\n");
      return TCL_ERROR;
   }
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   switch (targetType) {
      case T_CFV1 :
         PRINT(":wDreg r=0x%X(%s)<-0x%08X\n", regNo, getCFV1DebugRegName(regNo), data);
         break;
      case T_CFVx :
         PRINT(":wDreg r=0x%X(%s)<-0x%08X\n", regNo, getCFVxDebugRegName(regNo), data);
         break;
      case T_HC12 :
         PRINT(":wDreg addr=0x%X(%s)<-0x%08X\n", regNo, getHCS12DebugRegName(regNo), data);
         break;
      case T_ARM :
         PRINT(":wDreg r=0x%X(%s)<-0x%08X\n", regNo, getSWDDebugRegName(regNo), data);
         break;
      default :
         PRINT(":wDreg r=0x%X<-0x%08X\n", regNo, data);
         break;
   }
   return TCL_OK;
}

//! Write to Target Core Register
static int cmd_writeCReg(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// wcreg <addr> <data>
   int data;
   int regNo;
   int rc;

   if (argc != 3) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   // Register #
   rc = Tcl_GetIntFromObj(interp, argv[1], &regNo);
   if (rc != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>1");
      return TCL_ERROR;
   }
   // # data
   rc = Tcl_GetIntFromObj(interp, argv[2], &data);
   if (rc != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>2");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->writeCReg(regNo, data)) != 0) {
      PRINT(":wCReg Failed\n");
      return TCL_ERROR;
   }
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   switch(targetType) {
   case T_CFV1 :
      PRINT(":wCreg r=0x%X(%s)<-0x%08X\n", regNo, getCFV1ControlRegName(regNo), data);
      break;
   case T_CFVx :
      PRINT(":wCreg r=0x%X(%s)<-0x%08X\n", regNo, getCFVxControlRegName(regNo), data);
      break;
   case T_ARM :
      switch (regNo) {
      case ARM_CRegMDM_AP_Status:
         PRINT("reg=MDM-AP.Status(0x%08X)<-%s(0x%08X)\n", regNo, getMDM_APStatusName(data), data);
         break;
      case ARM_CRegMDM_AP_Control:
         PRINT("reg=MDM-AP.Control(0x%08X)<-%s(0x%08X)\n", regNo, getMDM_APControlName(data), data);
         break;
      default:
         PRINT(":rCreg r=0x%08X(%s)<-0x%08X\n", regNo, getARMControlRegName(regNo), (int)data);
         break;
      }
      break;
   default :
      PRINT(":wCreg r=0x%X<-0x%08X\n", regNo, data);
      break;
   }
   return TCL_OK;
}

//! Read from Target Register (Coldfire)
static int cmd_readReg(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// rreg<addr> <data>
   unsigned long data;
   int regNo;

   if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "<regNo>");
      return TCL_ERROR;
   }
   // Register #
   if (Tcl_GetIntFromObj(interp, argv[1], &regNo) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<regNo>");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->readReg(regNo, &data)) != 0) {
      PRINT(":rReg Failed\n");
      return TCL_ERROR;
   }
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   PRINT(":rReg r=0x%X(%s)->0x%08X\n",
          regNo, getRegName( targetType, regNo ), (int)data);
   Tcl_SetObjResult(interp, Tcl_NewIntObj(data));
   return TCL_OK;
}

//! Read from Target Debug Register (Coldfire)
static int cmd_readDReg(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// rdreg <addr>
   const char *currentToken;
   unsigned long data;
   int regNo;

   if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address>");
      return TCL_ERROR;
   }
   // Register #
   currentToken = Tcl_GetString(argv[1]);
   if (sscanf(currentToken,"%i",&regNo) != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address>");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->readDReg(regNo, &data)) != 0) {
      PRINT(":rReg Failed\n");
      return TCL_ERROR;
   }
   Tcl_SetObjResult(interp, Tcl_NewIntObj(data));
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   switch (targetType) {
      case T_CFV1 :
         PRINT(":rDreg r=0x%X(%s)->0x%08X\n", regNo, getCFV1DebugRegName(regNo), (int)data);
         break;
      case T_CFVx :
         PRINT(":rDreg r=0x%X(%s)->0x%08X\n", regNo, getCFVxDebugRegName(regNo), (int)data);
         break;
      case T_HC12 :
         PRINT(":rDreg addr=0x%X(%s)->0x%08X\n", regNo, getHCS12DebugRegName(regNo), (int)data);
         break;
      case T_ARM :
         PRINT(":rDreg r=0x%X(%s)->0x%08X\n", regNo, getSWDDebugRegName(regNo), (int)data);
         break;
      default :
         PRINT(":rDreg r=0x%X->0x%08X\n", regNo, (int)data);
         break;
   }
   return TCL_OK;
}

//! Read from Target Control Register (Coldfire)
static int cmd_readCReg(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// rcreg <addr>
   const char *currentToken;
   unsigned long data;
   int regNo;

   if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address>");
      return TCL_ERROR;
   }
   // Register #
   currentToken = Tcl_GetString(argv[1]);
   if (sscanf(currentToken,"%i",&regNo) != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address>");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->readCReg(regNo, &data)) != 0) {
      PRINT(":rReg Failed\n");
      return TCL_ERROR;
   }
   Tcl_SetObjResult(interp, Tcl_NewIntObj(data));
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   switch (targetType) {
   case T_CFV1 :
      PRINT(":rCreg r=0x%X(%s)->0x%08X\n", regNo, getCFV1ControlRegName(regNo), (int)data);
      break;
   case T_CFVx :
      PRINT(":rCreg r=0x%X(%s)->0x%08X\n", regNo, getCFVxControlRegName(regNo), (int)data);
      break;
   case T_ARM :
      switch (regNo) {
      case ARM_CRegMDM_AP_Status:
         PRINT("reg=MDM-AP.Status(0x%08X)->%s(0x%08X)\n", regNo, getMDM_APStatusName(data), (int)data);
         break;
      case ARM_CRegMDM_AP_Control:
         PRINT("reg=MDM-AP.Control(0x%08X)->%s(0x%08X)\n", regNo, getMDM_APControlName(data), (int)data);
         break;
      case ARM_CRegMDM_AP_Ident:
         PRINT("reg=MDM-AP.IDR(0x%08X)->0x%08X\n", regNo, (int)data);
         break;
      default:
         PRINT(":rCreg r=0x%08X(%s)->0x%08X\n", regNo, getARMControlRegName(regNo), (int)data);
         break;
      }
      break;
   default :
      PRINT(":rCreg r=0x%X->0x%08X\n", regNo, (int)data);
      break;
   }
   return TCL_OK;
}

#if 0
//! Testing
static int cmd_testCReg(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// test
   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>");
      return TCL_ERROR;
   }
   unsigned long dataH, dataL;
   int regNo;
   static const char *names[] = {"_A7","VBR","CPUCR","?","?","?","?","?",
                                "?","?","?","?","?","?","SR","PC",
   };

   for( regNo = 0; regNo<=15; regNo++) {
      bdmInterface->writeCReg(regNo, 0xFFFFFFFF);
      bdmInterface->readCReg(regNo, &dataH);
      bdmInterface->writeCReg(regNo, 0x00000000);
      bdmInterface->readCReg(regNo, &dataL);

      PRINT(":testCreg%d(%5s) 0x00000000->%8X, 0xFFFFFFFF->%8X\n",
               regNo, names[regNo], (int)dataL, (int)dataH);
   }
   return TCL_OK;
}
#endif

//! Write block to Target memory
static int cmd_writeBlock(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// wblock <addr> <number> <start_data>
   unsigned  address;
   int       count;
   int       data;
   int       startData;
   unsigned  char dataBlock[1024];
   int memSpace = MS_Byte;

   if (argc != 4) {
      Tcl_WrongNumArgs(interp, 1, argv, "<addr> <number> <start_data>");
      return TCL_ERROR;
   }
   // # address
   if (getAddress(argv[1], &address, &memSpace) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value> <start_data>");
      return TCL_ERROR;
   }
   // Number of bytes to write
   if (Tcl_GetIntFromObj(interp, argv[2], &count) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<addr> <number> <start_data>");
      return TCL_ERROR;
   }
   // Data value
   if (Tcl_GetIntFromObj(interp, argv[3], &data) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<addr> <number> <start_data>");
      return TCL_ERROR;
   }
   if (((unsigned)count) > sizeof(dataBlock))
      count = sizeof(dataBlock);
   startData = data;
   for (int sub = 0; sub <count; sub++) {
      dataBlock[sub]  = data;
      data++;
   }
   if (checkUsbdmRC(interp,  bdmInterface->writeMemory(memSpace, count, address, dataBlock)) != 0) {
      PRINT(":wblock Failed\n");
      return TCL_ERROR;
   }
   PRINT(":wblock [%4.4X-%4.4X]=%2.2X\n", address, address+count-1, startData);
   return TCL_OK;
}

#define ADDRESS_BYTE   (0<<0)  // Addresses identify a byte in memory
#define ADDRESS_WORD   (1<<0)  // Addresses identify a word in memory
#define ADDRESS_MASK   (1<<0)

#define DISPLAY_BYTE   (0<<3)  // Display as bytes (8-bits)
#define DISPLAY_WORD   (1<<3)  // Display as words (16-bits)
#define DISPLAY_LONG   (2<<3)  // Display as longs (32-bits)
#define DISPLAY_MASK   (3<<3)

static uint32_t printRange(uint32_t address, unsigned size, uint8_t *buff, int attributes) {

   unsigned sub;
   uint32_t data = 0;
   for(sub=0; sub<size;) {
      if ((sub % 16)==0) {
         PRINT("  0x%08X :", address);
      }
      switch(attributes&DISPLAY_MASK) {
      case DISPLAY_BYTE:
         data = buff[sub];
         PRINT(" %02X", data);
         sub     += 1;
         address += 1;
         break;
      case DISPLAY_WORD:
         data = getData16(buff+sub);
         PRINT(" %04X", data);
         sub += 2;
         if ((attributes&ADDRESS_MASK) == ADDRESS_WORD) {
            address += 1;
          }
         else {
            address += 2;
         }
         break;
      case DISPLAY_LONG:
         data = getData32(buff+sub);
         PRINT(" %08X", data);
         sub += 4;
         if ((attributes&ADDRESS_MASK) == ADDRESS_WORD) {
            address += 2;
          }
         else {
            address += 4;
         }
         break;
      }
      if ((sub % 16)==0) {
         PRINT("\n");
      }
   }
   if ((sub % 16)!=0) {
      PRINT("\n");
   }
   return data;
}

//! Read byte from Target memory
static int cmd_readByte(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// rb <addr> [<number>]
   uint32_t  address;
   int       numArgs;
   uint8_t   data = 0;
   uint8_t   buff[2000]={0};
   int       memSpace = MS_Byte;

   if ((argc < 2) || (argc > 3)) {
      Tcl_WrongNumArgs(interp, 1, argv, "<addr> [<number>]");
      return TCL_ERROR;
   }
   // # address
   if (getAddress(argv[1], &address, &memSpace) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>...");
      return TCL_ERROR;
   }
   // Read numArgs
   numArgs = 1;
   if (argc == 3) {
      if (Tcl_GetIntFromObj(interp, argv[2], &numArgs) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<addr> [<number>]");
         return TCL_ERROR;
      }
      if (((unsigned)numArgs)>(sizeof(buff))) {
         PRINT_ERROR("Too many bytes\n");
         return TCL_ERROR;
      }
   }
   if (checkUsbdmRC(interp,  bdmInterface->readMemory(memSpace, numArgs, address, buff)) != 0) {
      PRINT(" Failed\n");
      return TCL_ERROR;
   }
   PRINT(":rb =>\n");
   data = printRange(address, numArgs, buff, ADDRESS_BYTE|DISPLAY_BYTE);
   Tcl_SetObjResult(interp, Tcl_NewIntObj(data));
   return TCL_OK;
}

//! Read word from Target memory
static int cmd_readWord(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// rw <addr> [<number>]
   uint32_t   address;
   int        numArgs;
   uint16_t   data = 0;
   uint8_t    buff[2000]={0};
   int        memSpace = defaultMemorySpace|MS_Word;

   if ((argc < 2) || (argc > 3)) {
      Tcl_WrongNumArgs(interp, 1, argv, "<addr> [<number>]");
      return TCL_ERROR;
   }
   // # address
   if (getAddress(argv[1], &address, &memSpace) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>...");
      return TCL_ERROR;
   }
   // Read numArgs
   numArgs = 1;
   if (argc == 3) {
      if (Tcl_GetIntFromObj(interp, argv[2], &numArgs) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<addr> [<number>]");
         return TCL_ERROR;
      }
      if (((unsigned)numArgs)>(sizeof(buff)/2)) {
         PRINT_ERROR("Too many words\n");
         return TCL_ERROR;
      }
   }
   if (checkUsbdmRC(interp,  bdmInterface->readMemory(memSpace, 2*numArgs, address, buff)) != 0) {
      PRINT(" Failed\n");
      return TCL_ERROR;
   }
   PRINT(":rw =>\n");
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   data = printRange(address, 2*numArgs, buff, ((targetType==T_MC56F80xx)?ADDRESS_WORD:ADDRESS_BYTE)|DISPLAY_WORD);
   Tcl_SetObjResult(interp, Tcl_NewIntObj(data));
   return TCL_OK;
}

//! Read long word from Target memory
static int cmd_readLong(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// rw <addr> [<number>]
   uint32_t  address;
   int       numArgs;
   uint32_t  data = 0;
   uint8_t   buff[2000]={0};
   int       memSpace = defaultMemorySpace|MS_Long;

   if ((argc < 2) || (argc > 3)) {
      Tcl_WrongNumArgs(interp, 1, argv, "<addr> [<number>]");
      return TCL_ERROR;
   }
   // # address
   if (getAddress(argv[1], &address, &memSpace) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<address> <value>...");
      return TCL_ERROR;
   }
   // Read numArgs
   numArgs = 1;
   if (argc == 3) {
      if (Tcl_GetIntFromObj(interp, argv[2], &numArgs) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<addr> [<number>]");
         return TCL_ERROR;
      }
      if (((unsigned)numArgs)>(sizeof(buff)/4)) {
         PRINT_ERROR("Too many longwords\n");
         return TCL_ERROR;
      }
   }
   if (checkUsbdmRC(interp,  bdmInterface->readMemory(memSpace, 4*numArgs, address, buff)) != 0) {
      PRINT(" Failed\n");
      return TCL_ERROR;
   }
   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   PRINT(":rl =>\n");
   data = printRange(address, 4*numArgs, buff, ((targetType==T_MC56F80xx)?ADDRESS_WORD:ADDRESS_BYTE)|DISPLAY_LONG);
   Tcl_SetObjResult(interp, Tcl_NewIntObj(data));
   return TCL_OK;
}

//! Test a block of target memory
static int cmd_testBlock(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// tBlock <addr> <size> <repeatcount>

   int       address;
   int       repeatCount;
   int       maxRepeat = 1;
   int       count;
   int       errorCount = 0;
   uint8_t   dataWriteBlock[40000];
   uint8_t   dataReadBlock[40000];
   time_t    time_start;
   time_t    time_end;

   if (argc < 3) {
      Tcl_WrongNumArgs(interp, 1, argv, "<start-addr> <end-addr> <count>");
      return TCL_ERROR;
   }
   // Start address
   if (Tcl_GetIntFromObj(interp, argv[1], &address) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<start-addr> <end-addr> <count>");
      return TCL_ERROR;
   }
   // Read end address
   if (Tcl_GetIntFromObj(interp, argv[2], &count) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<start-addr> <end-addr> <count>");
      return TCL_ERROR;
   }
   if (argc > 3) {
      // Repeat Count
      if (Tcl_GetIntFromObj(interp, argv[3], &maxRepeat) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<start-addr> <end-addr> <count>");
         return TCL_ERROR;
      }
   }
   if (count < address)
      return TCL_ERROR;

   count -= address;
   count++;

   if (count > (int)sizeof(dataWriteBlock))
      count = sizeof(dataWriteBlock);

   PRINT(":tblock [0x%4.4X-0x%4.4X] (0x%X bytes), %d times\n",
          address, address+count-1, count, maxRepeat);

   if (((address & 0x03)!= 0) || ((count & 0x03)!= 0)) {
      PRINT(":tblock - Alignment error\n");
      return TCL_ERROR;
   }
   time(&time_start);

   for (repeatCount=0;  repeatCount<maxRepeat; repeatCount++) {
      int data = rand()&0xFF;

      if ((repeatCount%20) == 0)
         PRINT("%6.6d:",repeatCount);
      PRINT("%2.2X,", data);
      if (((repeatCount%20) == 19) && (repeatCount<maxRepeat))
         PRINT("\n");

      for (int sub = 0; sub <count; sub++) {
         dataWriteBlock[sub]  = (uint8_t)((255.0 * rand())/(RAND_MAX+1.0));
      }
      bdmInterface->writeMemory(4, count, address, dataWriteBlock);
      bdmInterface->readMemory(4, count, address, dataReadBlock);
      for (int sub = 0; sub <count; sub++)
         if (dataWriteBlock[sub] != dataReadBlock[sub]) {
            PRINT("addr = %4X, wrote 0x%2.2X, read 0x%2.2X\n",
                   address+sub, dataWriteBlock[sub], dataReadBlock[sub]);
            errorCount++;
         }
#if 0
      PRINT(":tblock [%4.4X-%4.4X]\n", address, address+size-1);
      for (sub=0; sub<count; sub++){
         if ((sub&0x0F) == 0)
            PRINT("\n%4.4X:", address+sub);
         PRINT("%2.2X ", dataReadBlock[sub]);
      }
      PRINT("\n");
#endif
   }

   time(&time_end);
   PRINT("\n");
   PRINT("Started:   %s",  asctime(localtime(&time_start)));
   PRINT("Completed: %s\n",  asctime(localtime(&time_end)));

   PRINT("\n:tblock [%4X-%4X], error count = %d\n",
          address, address+count-1, errorCount);
   if (errorCount != 0) {
      PRINT(":tblock Failed\n");
      return TCL_ERROR;
   }
   return TCL_OK;
}

//! Test Target status command
static int cmd_testStatus(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
//testStatus <expected value>
   unsigned long BDMStatus = 0x00;
   USBDM_ErrorCode rc;
   int             value;

   if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "<expected value>");
      return TCL_ERROR;
   }
   // get expected value
   if (Tcl_GetIntFromObj(interp, argv[1], &value) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<expected-value>");
      return TCL_ERROR;
   }
   do {
      rc = bdmInterface->readStatusReg(&BDMStatus); // Read BDMSTS register
   } while ((rc == BDM_RC_OK) && (BDMStatus == (unsigned long)value));

   TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
   PRINT("Target status reg = 0x%X => %s\n",
          (int)BDMStatus, getStatusRegName(targetType, BDMStatus));
   return TCL_OK;
}

#if 0
//! Writes new trim value to target and then measures
//! target speed multiple times to obtain an average
//
static float getAverageTargetSpeed(int addrICSSC, int addrICSTRM, int currentTrimValue) {
float currentSpeed;
int   iteration;
const int maxSamples = 5;
int   currentTrimValueX;
unsigned long temp1;
unsigned char ctemp1, ctemp2;

   // Re-trim target clock (LSB first!)
   ctemp1 = currentTrimValue&0x01;
   ctemp2 = currentTrimValue>>1;
   bdmInterface->writeMemory(1, 1, addrICSSC,  &ctemp1);  //  1-bit (FTRIM)
   bdmInterface->writeMemory(1, 1, addrICSTRM, &ctemp2);  //  8-bits (TRIM)

   // Let target settle
   milliSleep(50);

   // Re-connect in case speed change
   if ((bdmInterface->connect() != 0) && (bdmInterface->connect() != 0)) {
      PRINT_ERROR("getAverageTargetSpeed():Failed to re-connect to Target\n");
      return(0);
   }

   // Some error checking!
   bdmInterface->readMemory(1, 1, addrICSTRM, &ctemp1);     // 8-bits
   bdmInterface->readMemory(1, 1, addrICSSC,  &ctemp2);     // 1-bit
   currentTrimValueX = (ctemp1<<1) + (ctemp2&0x01);

   if (currentTrimValueX != currentTrimValue) {
      PRINT_ERROR("getAverageTargetSpeed(): Error in writing trim value,\n\r"
                      "Wrote 0x%2.2X(%2.2x,%1X), read 0x%2.2X(%2.2x,%1X)\n",
              currentTrimValue,  currentTrimValue>>1,  currentTrimValue&0x01,
              currentTrimValueX, currentTrimValueX>>1, currentTrimValueX&0x01);
   }

   // Measure target speed several times
   currentSpeed = 0.0;
   for (iteration = 0; iteration<maxSamples; iteration++) {
      // Re-connect
      if ((bdmInterface->connect() != 0) && (bdmInterface->connect() != 0)) {
         PRINT_ERROR("Failed to re-connect to Target\n");
         return(0);
      }
      // Get connection speed => target speed
      bdmInterface->getSpeed(&temp1);
      currentSpeed += temp1;
   }

   return currentSpeed/maxSamples/1000.0;
}
#endif
#if 0
//! Trim Target Clock
static int trimCommand(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
//trim <mode=8/9 bit> <ICSTRM> <ICSSC> <NV_ICSTRM> <NV_FTRIM> <Target_Frequency>
   const char *currentToken;
   int mode;
   int addrICSSC, addrICSTRM, addrNV_FTRIM, addrNV_ICSTRM;
   float targetFrequency;
   float currentSpeed;
#define SEARCH_OFFSET (10)
   int len;
   static const char paramString[] = "<mode=8/9 bit> <ICSTRM> <ICSSC> <NV_ICSTRM> <NV_FTRIM> <Target_Frequency>";

   if (argc != 7) {
      Tcl_WrongNumArgs(interp, 1, argv, paramString);
      return TCL_ERROR;
   }
   // <mode=8/9 bit>
   currentToken = Tcl_GetString(argv[1]);
   if (sscanf(currentToken,"%i",&mode) != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, paramString);
      return TCL_ERROR;
   }
   // Read ICSTRIM address
   currentToken = Tcl_GetString(argv[2]);
   if (sscanf(currentToken,"%i",&addrICSTRM) != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, paramString);
      return TCL_ERROR;
   }

   // Read ICSSC address
   currentToken = Tcl_GetString(argv[3]);
   if (sscanf(currentToken,"%i",&addrICSSC) != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, paramString);
      return TCL_ERROR;
   }

   // Read NV_ICSTRM address
   currentToken = Tcl_GetString(argv[4]);
   if (sscanf(currentToken,"%i",&addrNV_ICSTRM) != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, paramString);
      return TCL_ERROR;
   }

   // Read NV_TRIM address
   currentToken = Tcl_GetString(argv[5]);
   if (sscanf(currentToken,"%i",&addrNV_FTRIM) != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, paramString);
      return TCL_ERROR;
   }

   // Read target frequency
   currentToken = Tcl_GetString(argv[6]);
   if (sscanf(currentToken,"%f",&targetFrequency) != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, paramString);
      return TCL_ERROR;
   }

   if (mode != 9) {
      PRINT_ERROR("ERROR: Trim modes other than 9-bit are not supported (yet)\n");
      return 1;
   }

   int currentTrimValue = 0x000; // 9-bit 1/2 way
   int trialBit;

   PRINT("trim <mode=8/9 bit> <ICSTRM> <ICSSC> <NV_ICSTRM> <NV_FTRIM> <Target_Frequency>\n");
   PRINT("         %3s         %5.4X    %5.4X   %5.4X       %5.4X      %7.2f\n",
          mode==8?"8":"9",
          addrICSTRM,
          addrICSSC,
          addrNV_ICSTRM,
          addrNV_FTRIM,
          targetFrequency
          );

   PRINT("1. Binary search\n");
   for (trialBit = 0x100; trialBit > 0x0; trialBit >>= 1){
      // Add in the trial bit, re-sync & check speed
      currentTrimValue |= trialBit;
      currentSpeed = getAverageTargetSpeed(addrICSSC, addrICSTRM, currentTrimValue);

      PRINT(" Trim values 0x%2.2X,%1X, Freq=%5.3f",
             currentTrimValue>>1, currentTrimValue&0x01, currentSpeed);
      PRINT("%s %5.3f\n", (currentSpeed < targetFrequency)?" <":">=", targetFrequency);
      if (currentSpeed < targetFrequency){ // Too slow - remove trial bit
         currentTrimValue &= ~trialBit;
      }
   }

   // Assume binary search value is "best" so far
   int   bestValue      = currentTrimValue;
   int   limitTrimValue = 0;
   float bestFreq       = currentSpeed;
   float bestError      = fabs(targetFrequency-currentSpeed);
   float currentError   = 0;

   // Linear search +/-SEARCH_OFFSET, starting at higher freq (smaller Trim)
   // Range is constrained to [1..254]

   limitTrimValue = currentTrimValue + SEARCH_OFFSET;
   if (limitTrimValue >= 511)
      limitTrimValue = 511;

   currentTrimValue -= SEARCH_OFFSET;
   if (currentTrimValue <= 1)
      currentTrimValue = 1;

   PRINT("2. Linear search [%d .. %d]\n", currentTrimValue, limitTrimValue);

   while (currentTrimValue <= limitTrimValue) {

      // Re-sync & check speed
      currentSpeed = getAverageTargetSpeed(addrICSSC, addrICSTRM, currentTrimValue);

      currentError = fabs(targetFrequency-currentSpeed);

      if (currentError < bestError){ // Better Guess?
         PRINT(" Trim values* 0x%2.2X,%1X, Freq=%5.3f, ", currentTrimValue>>1, currentTrimValue&0x01, currentSpeed);
         PRINT("err= %5.3f\n", currentError);
         bestValue    = currentTrimValue;
         bestFreq     = currentSpeed;
         bestError    = currentError;
      }
      else {
         PRINT(" Trim values  0x%2.2X,%1X, Freq=%5.3f, ", currentTrimValue>>1, currentTrimValue&0x01, currentSpeed);
         PRINT("err= %5.3f\n", currentError);
      }
      currentTrimValue++;
   }

   PRINT("=Trim values ICSTRM=%3d(0x%2.2X), ICSSC=%3d(0x%2.2X), Freq=%5.3f\n",
            bestValue>>1, bestValue>>1, bestValue&0x01, bestValue&0x01, bestFreq);

   return 0;
}
#elif 0
//! Trim Target Clock
static int trimCommand(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
//trim <mode=8/9 bit> <ICSTRM> <ICSSC> <NV_ICSTRM> <NV_FTRIM> <Target_Frequency>
   char *currentToken;
   int rc;
   int mode;
   int addrICSSC, addrICSTRM, addrNV_FTRIM, addrNV_ICSTRM;
   float targetFrequency;
   unsigned int trimValue;
   unsigned int measuredFrequency;

   // Read mode
   currentToken = strtok(NULL, delimiters);
   if ((currentToken==NULL) || (sscanf(currentToken,"%i",&mode) != 1))
      return 0;

   // Read ICSTRIM address
   currentToken = strtok(NULL, delimiters);
   if ((currentToken==NULL) || (sscanf(currentToken,"%i",&addrICSTRM) != 1))
      return 0;

   // Read ICSSC address
   currentToken = strtok(NULL, delimiters);
   if ((currentToken==NULL) || (sscanf(currentToken,"%i",&addrICSSC) != 1))
      return 0;

   // Read NV_ICSTRM address
   currentToken = strtok(NULL, delimiters);
   if ((currentToken==NULL) || (sscanf(currentToken,"%i",&addrNV_ICSTRM) != 1))
      return 0;

   // Read NV_TRIM address
   currentToken = strtok(NULL, delimiters);
   if ((currentToken==NULL) || (sscanf(currentToken,"%i",&addrNV_FTRIM) != 1))
      return 0;

   // Read target frequency
   currentToken = strtok(NULL, delimiters);
   if ((currentToken==NULL) || (sscanf(currentToken,"%f",&targetFrequency) != 1))
      return 0;

   if (mode != 9) {
      PRINT_ERROR("ERROR: Trim modes other than 9-bit are not supported (yet)\n");
      return 1;
   }

   rc = USBDM_TrimTargetClock((long int)(1000*targetFrequency) /*kHz*/,
                              &trimValue, &measuredFrequency);
   if (rc != BDM_RC_OK)
      PRINT("Trim Failed rc=%s\r\n", getErrorName(rc));
   else
         PRINT("Trim value calculated=%2X.%1X, Measured Freq = %d\r\n",
          trimValue>>1,
          trimValue&0x01,
          measuredFrequency);

   return 0;
}
#endif

//! Write Control Register
static int cmd_writeControl(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// wc <control_value>
   int value;

   if (argc != 2) {
      Tcl_WrongNumArgs(interp, 1, argv, "<value>");
      return TCL_ERROR;
   }
   // Control value
   if (Tcl_GetIntFromObj(interp, argv[1], &value) != TCL_OK) {
      Tcl_WrongNumArgs(interp, 1, argv, "<kHz>");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->writeControlReg((uint8_t) value)) != 0) {
      PRINT(":wc Failed\n");
      return TCL_ERROR;
   }
   PRINT(":wc 0x%2.2X\n", value);
   return 0;
}

//! Set communication speed
static int cmd_setSpeed(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// speed <Hz>
   unsigned long freq;

   if (argc > 1) {
      if (argc != 2) {
         Tcl_WrongNumArgs(interp, 1, argv, "?kHz?");
         return TCL_ERROR;
      }
      // Speed value
      double speed;
      if (Tcl_GetDoubleFromObj(interp, argv[1], &speed) != TCL_OK) {
         return TCL_ERROR;
      }
      if (checkUsbdmRC(interp, bdmInterface->setSpeedHz(round(1000UL*speed)))) {
         return TCL_ERROR;
      }
      if (speed == 0) {
         PRINT("Speed = 0 => autospeed detection enabled\n");
      }
      else {
         PRINT("Speed set to %.2f MHz (%.0f ticks, sync=%.1f us)\n",
                speed, (60.0 * 128)/speed, (2 * 128)/speed);
      }
   }
   if (checkUsbdmRC(interp, bdmInterface->getSpeedHz(&freq))) {
      return TCL_ERROR;
   }
   PRINT("Speed = %.3f MHz\n", freq/1000000.0);
   Tcl_SetObjResult(interp, Tcl_NewLongObj(freq));
   return TCL_OK;
}

////! Set Target to re-boot into ICP mode
//static int cmd_setBoot(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
//// setBoot
//   if (argc != 1) {
//      Tcl_WrongNumArgs(interp, 1, argv, "<delay_time>");
//      return TCL_ERROR;
//   }
//   USBDM_RebootToICP();
//
//   PRINT("cmd_setBoot Complete\n");
//   return TCL_OK;
//}

#include <USBDM_API.h>
#include <USBDM_API_Private.h>

//! Send low-level sync command to BDM
static int cmd_sync(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
// sync <control_value>
   static const char *connectionStates[] = {
         "Not Connected", "Sync Speed", "Guess Speed", "Manual Speed"
   };
   USBDMStatus_t  bdm_status;
   unsigned char BDMStatus;
   float speed;
   unsigned int ticks;

   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "<delay_time>");
      return TCL_ERROR;
   }
   unsigned char usb_data[20] = {0};
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_DEBUG;
   usb_data[2] = BDM_DBG_SYNC;
   bdmInterface->bdmCommand(3, sizeof(usb_data), usb_data);

   if (usb_data[0] != BDM_RC_OK) {
      PRINT("sync: Failed\n");
      return TCL_ERROR;
   }

//   PRINT(":sync => 0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//          "%2.2X(%2.2d), 0x%2.2X(%2.2d) \n",
//          usb_data[0], usb_data[0], usb_data[1], usb_data[1],
//          usb_data[2], usb_data[2], usb_data[3], usb_data[3] );

   BDMStatus = usb_data[1];

   bdm_status.ackn_state       = (BDMStatus&S_ACKN)?ACKN:WAIT;
   bdm_status.reset_state      = (BDMStatus&S_RESET_STATE)?RSTO_ACTIVE:RSTO_INACTIVE;
   switch(BDMStatus&S_COMM_MASK) {
      default :
      case S_NOT_CONNECTED : bdm_status.connection_state = SPEED_NO_INFO;       break; //!< No connection with target
      case S_SYNC_DONE     : bdm_status.connection_state = SPEED_SYNC;          break; //!< Target speed determined by BDM SYNC
      case S_GUESS_DONE    : bdm_status.connection_state = SPEED_GUESSED;       break; //!< Target speed guessed
      case S_USER_DONE     : bdm_status.connection_state = SPEED_USER_SUPPLIED; break; //!< Target speed specified by user
   };

   PRINT("status = %s\n", getBDMStatusName(&bdm_status));

   PRINT("sync: Status = %s, %s, %s, %s\r\n", bdm_status.ackn_state?"Ackn":"Wait",
                                               connectionStates[bdm_status.connection_state],
                                               bdm_status.reset_state?"Reset":"No Reset",
                                              (BDMStatus&S_POWER_MASK)?"Power":"No Power" );

   PRINT("%2.2X 0x%2.2X 0x%2.2X 0x%2.2X \n", usb_data[0], usb_data[1], usb_data[2], usb_data[3]);
   PRINT("%2.2X 0x%4.4X \n", *(usb_data+2), *(uint16_t*)(usb_data+2) );

   ticks = (usb_data[2]<<8) + usb_data[3];

   speed =  (60.0 * 128) / ticks;

   PRINT("sync: Speed = %.2f MHz (%d ticks, sync=%.1f us)\n",
          speed, ticks, ticks/60.0);
   return TCL_OK;
}

////! Send debug command to BDM
//static int debugCommand(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
//// debug <control_value>
//   const char *currentToken;
//   int command, arg1 = 0, arg2=0;
//   unsigned char usb_data[20] = {0};
//   unsigned temp;
//
//   if (argc < 2) {
//      Tcl_WrongNumArgs(interp, 1, argv, "<control_value>");
//      return TCL_ERROR;
//   }
//   // Control value
//   currentToken = Tcl_GetString(argv[1]);
//   if (sscanf(currentToken,"%i",&command) != 1) {
//      Tcl_WrongNumArgs(interp, 1, argv, "<control_value>");
//      return TCL_ERROR;
//   }
//
//   if (argc > 2) {
//      // Arg #1
//      currentToken = Tcl_GetString(argv[2]);
//      if (sscanf(currentToken,"%i",&arg1) != 1) {
//         Tcl_WrongNumArgs(interp, 1, argv, "<control_value>");
//         return TCL_ERROR;
//      }
//   }
//   if (argc > 3) {
//      // Arg #1
//      currentToken = Tcl_GetString(argv[3]);
//      if (sscanf(currentToken,"%i",&arg2) != 1) {
//         Tcl_WrongNumArgs(interp, 1, argv, "<control_value>");
//         return TCL_ERROR;
//      }
//   }
//   unsigned char usb_data[20] = {0};
//   usb_data[0] = 0;
//   usb_data[1] = CMD_USBDM_DEBUG;
//   usb_data[2] = command;
//   usb_data[3] = arg1;
//   usb_data[4] = arg2;
//
//   if (checkUsbdmRC(interp,  bdmInterface->bdmCommand(3, sizeof(usb_data), usb_data)) != 0) {
//      PRINT(":debug Failed\n");
//      return TCL_ERROR;
//   }
//
//   switch (command) {
//      case BDM_DBG_STACKSIZE :
//         temp = 256*usb_data[1]+usb_data[2];
//         PRINT(":debug %10s => stacksize = %d (0x%X) bytes\n", getDebugCommandName(command), temp, temp);
//         break;
//      case BDM_DBG_MEASURE_VDD :
//         PRINT(":debug %10s => Vdd = %2.1f V\n", getDebugCommandName(command), 5.0*usb_data[1]/255);
//         break;
//      case BDM_DBG_SWD:
//         PRINT(":debug %10s 0x%2.2X 0x%2.2X =>\n "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "\n"
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "\n"
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "\n",
//                getDebugCommandName(command), arg1, arg2,
//                usb_data[1],  usb_data[1],  usb_data[2],  usb_data[2],
//                usb_data[3],  usb_data[3],  usb_data[4],  usb_data[4],
//                usb_data[5],  usb_data[5],  usb_data[6],  usb_data[6],
//                usb_data[7],  usb_data[7],  usb_data[8],  usb_data[8],
//                usb_data[9],  usb_data[9],  usb_data[10], usb_data[10],
//                usb_data[11], usb_data[11], usb_data[12], usb_data[12],
//                usb_data[13], usb_data[13], usb_data[14], usb_data[14],
//                usb_data[15], usb_data[15], usb_data[16], usb_data[16],
//                usb_data[17], usb_data[17], usb_data[18], usb_data[18]
//                );
//         return BDM_RC_OK;
//      default :
//         PRINT(":debug %10s 0x%2.2X 0x%2.2X => "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "0x%2.2X(%2.2d), 0x%2.2X(%2.2d), "
//               "\n",
//                getDebugCommandName(command), arg1, arg2,
//                usb_data[1], usb_data[1], usb_data[2], usb_data[2],
//                usb_data[3], usb_data[3], usb_data[4], usb_data[4],
//                usb_data[5], usb_data[5], usb_data[6], usb_data[6],
//                usb_data[7], usb_data[7], usb_data[8], usb_data[8]);
//         break;
//   }
//   return reportState(interp);
//}

//! Reset JTAG chain
static int jtagResetCommand(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->jtagReset())) {
      return TCL_ERROR;
   }
   return TCL_OK;
}

//! Shift JTAG chain
static int jtagShiftCommand(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   // jtag-shift exitMode numBits data...
   int exitMode;
   int numBits;
   int data;
   uint8_t  buff[50];
   int argCount = 0;

   if (argc < 4) {
      Tcl_WrongNumArgs(interp, 1, argv, "<exitMode> <numBits> <dataBytes>...");
      return TCL_ERROR;
   }
   // # exitMode
   const char *arg = Tcl_GetString(argv[++argCount]);
   if (strncasecmp(arg, "S", 1) == 0) {
      exitMode = JTAG_STAY_SHIFT;
   }
   else if (strncasecmp(arg, "R", 1) == 0) {
      exitMode = JTAG_EXIT_IDLE; // Run-test/Idle
   }
   else if (strncasecmp(arg, "T", 1) == 0) {
      exitMode = JTAG_EXIT_IDLE; // run-Test/Idle
   }
   else if (strncasecmp(arg, "D", 1) == 0) {
      exitMode = JTAG_EXIT_SHIFT_DR;
   }
   else if (strncasecmp(arg, "I", 1) == 0) {
      exitMode = JTAG_EXIT_SHIFT_IR;
   }
   else {
      PRINT("Illegal argument #%d=<exitMode>\n", argCount);
      return TCL_ERROR;
   }
   // # numBits
   if ((Tcl_GetIntFromObj(interp, argv[++argCount], &numBits) != TCL_OK) || (numBits < 1)) {
      PRINT("Illegal argument #%d=<numBits> : ", argCount);
      return TCL_ERROR;
   }
   if ((argc-3) != (numBits+7)/8) {
      Tcl_WrongNumArgs(interp, 1, argv, "<exitMode> <numBits> <dataBytes>...");
      return TCL_ERROR;
   }
   // Data values
   int bitCount = 0;
   while (bitCount<numBits) {
      if (Tcl_GetIntFromObj(interp, argv[++argCount], &data) != TCL_OK) {
         PRINT("Illegal argument #%d=<dataBytes> : ", argCount);
         return TCL_ERROR;
      }
      buff[bitCount/8] = (uint8_t) data;
      bitCount += 8;
   }
   if (checkUsbdmRC(interp,  bdmInterface->jtagWrite(numBits, exitMode, buff))) {
      return TCL_ERROR;
   }
   return TCL_OK;
}

//! Move JTAG chain to SHIFT-DR state
static int jtagShiftDRCommand(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   // jtag-shift-dr
   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->jtagSelectShift(JTAG_SHIFT_DR)) != 0) {
      return TCL_ERROR;
   }
   return TCL_OK;
}

//! Move JTAG chain to SHIFT-IR state
static int jtagShiftIRCommand(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   // jtag-shift-ir
   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   if (checkUsbdmRC(interp,  bdmInterface->jtagSelectShift(JTAG_SHIFT_IR)) != 0) {
      return TCL_ERROR;
   }
   return TCL_OK;
}

//! Run identify command on JTAG device
static int jtagIdentifyCommand(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   uint32_t buff;
   uint8_t  temp;
   const uint8_t  BYPASSCommand[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
   const uint8_t  Zeroes[]        = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
   const uint8_t  allOnes[] = {0xFFU};
   uint8_t    irReg[MAX_JTAG_IR_CHAIN_LENGTH];
   int device;
   int deviceCount;
   int irLength;
   int sub;

   if (argc != 1) {
      Tcl_WrongNumArgs(interp, 1, argv, "");
      return TCL_ERROR;
   }
   // Find number of JTAG devices
   //===========================================================================
   // Force all devices to bypass mode (Command is all '1's)
   // This assumes the instruction chain length is limited to < 3x80 bits
   bdmInterface->jtagReset();
   bdmInterface->jtagSelectShift(JTAG_SHIFT_IR);
   bdmInterface->jtagWrite(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   bdmInterface->jtagWrite(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   bdmInterface->jtagWrite(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   bdmInterface->jtagWrite(8*sizeof(BYPASSCommand), JTAG_EXIT_IDLE|JTAG_WRITE_1, BYPASSCommand);


   // Fill bypass register chain with 0 - stay in SHIFT-DR
   bdmInterface->jtagSelectShift(JTAG_SHIFT_DR);
   bdmInterface->jtagWrite(8*sizeof(Zeroes), JTAG_STAY_SHIFT|JTAG_WRITE_1, Zeroes);
   bdmInterface->jtagWrite(8*sizeof(Zeroes), JTAG_STAY_SHIFT|JTAG_WRITE_1, Zeroes);
   bdmInterface->jtagWrite(8*sizeof(Zeroes), JTAG_STAY_SHIFT|JTAG_WRITE_1, Zeroes);

   // Write a single one into bypass chain
   bdmInterface->jtagWrite(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, allOnes); // Write a single one into chain

   // Keep reading single bits until we find the '1'
   deviceCount = 0;
   do {
      bdmInterface->jtagRead(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, &temp); // Read a single bit
      deviceCount++;
   } while ((temp == 0) && (deviceCount <= MAX_JTAG_CHAIN_LENGTH));

   PRINT("Number of devices => %d\n", deviceCount);

   // Find total length JTAG IRs
   //===========================================================================
   //
   // Fill IR chain with 1's - stay in SHIFT-IR
   // This assumes the instruction chain length is limited to < 3x80 bits
   bdmInterface->jtagReset();
   bdmInterface->jtagSelectShift(JTAG_SHIFT_IR);
   bdmInterface->jtagWrite(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   bdmInterface->jtagWrite(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   bdmInterface->jtagWrite(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);

   // Write a single 0 into bypass chain
   bdmInterface->jtagWrite(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, Zeroes);

   // Keep reading single bits until we find the '1'
   irLength = 0;
   do {
      temp = 0xAA;
      bdmInterface->jtagRead(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, &temp); // Read a single bit
      irLength++;
   } while ((temp == 1) && (irLength <= MAX_JTAG_IR_CHAIN_LENGTH));

   PRINT("initialiseJTAGChain(): Total length of JTAG IRs => %d bits\n", irLength);

   // Read the JTAG IRs
   //===========================================================================
   //
   bdmInterface->jtagReset();
   bdmInterface->jtagSelectShift(JTAG_SHIFT_IR);
   bdmInterface->jtagRead(irLength, JTAG_STAY_SHIFT|JTAG_WRITE_1, irReg);

   PRINT("initialiseJTAGChain(): JTAG IR chain => \'");
   for (sub=0; sub < (irLength+7)/8; sub++) {
      int bitNum, bitsThisByte;
      if (sub == 0)
         bitsThisByte = (irLength-1)%8+1;
      else
         bitsThisByte = 8;
      //PRINT_ERROR("bitsThisByte=%d, ", bitsThisByte);
      for (bitNum=bitsThisByte-1; bitNum >= 0; bitNum--)
         PRINT("%d", ((irReg[sub])&(1<<bitNum))?1:0);
      PRINT(" ");
   }
   PRINT("\'\n");

   // Get the IDCODE for each device
   // The number of devices should agree with the above!
   bdmInterface->jtagReset();   // Loads IDCODE/BYPASS command into IR
   bdmInterface->jtagSelectShift(JTAG_SHIFT_DR);  // Shifting IDCODE register
   for (device = 0; device < deviceCount; device++) {
      bdmInterface->jtagRead(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, &temp);       // Read a single bit
      //PRINT("Temp = %x\n",temp);
      if (temp == 0) {// In BYPASS - No IDCODE
         PRINT("Device #%2d: JTAG IDCODE instruction not supported\n", device+1);
      }
      else {
         bdmInterface->jtagRead(31, JTAG_STAY_SHIFT|JTAG_WRITE_1, (uint8_t *)&buff); // Read rest of IDCODE
         //PRINT("Buff = %lX\n",buff);
         swapEndian32(&buff);
         buff = (buff<<1) | 0x1;
         PRINT("Device #%2d: JTAG IDCODE = %08X\n", device+1, buff);
         Tcl_SetObjResult(interp, Tcl_NewLongObj(buff));
      }
   }
   bdmInterface->jtagRead(1, JTAG_EXIT_IDLE|JTAG_WRITE_1, &temp);  // Return JTAG to idle state
   return TCL_OK;
}

#if 0
//! Set logging
static int setLogCommand(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   // setTarget <value>
   if (argc > 2) {
      Tcl_WrongNumArgs(interp, 2, argv, "<logging>");
      return TCL_ERROR;
   }
   if (argc == 2) {
      // Read control value to set
      int value;
      if (Tcl_GetIntFromObj(interp, argv[1], &value) != TCL_OK) {
         Tcl_WrongNumArgs(interp, 1, argv, "<logging>");
         return TCL_ERROR;
      }
      logging = value?true:false;
      FILE *fp = logging?stderr:NULL;
      TargetType_t targetType = bdmInterface->getBdmOptions().targetType;
      switch(targetType) {
      case T_MC56F80xx:
         DSC_SetLogFile(fp);
         break;
      default:
         break;
      }
   }
   Tcl_SetObjResult(interp, Tcl_NewIntObj(logging));
   return TCL_OK;
}
#endif

static int cmd_dialogue(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {

#ifdef _WIN32
   static HWND hwnd = 0;

   if (hwnd == 0) {
      //Todo Fix
//      hwnd = GetConsoleHwnd();
//      PRINT_ERROR("HWND=%p\n", hwnd);
//      setDefaultWindowParent(hwnd);
   }
#endif

   if (wxPlugin == 0) {
      wxPlugin = WxPluginFactory::createWxPlugin();
   }

   // dialogue title message options
   if (argc <= 3) {
       Tcl_WrongNumArgs(interp, 1, argv, "title message style");
       return TCL_ERROR;
   }
   // title
   const char *title   = Tcl_GetString(argv[1]);
   const char *message = Tcl_GetString(argv[2]);
   char *sStyle  = Tcl_GetString(argv[3]);
   int style = 0;
   if (sStyle != NULL) {
      char *s = strtok(sStyle, "| \n\t");
      while (s != NULL) {
         if       (strncasecmp(s, "OK",    2)==0)  style |= OK;
         else if  (strncasecmp(s, "YES_NO",3)==0)  style |= YES_NO;
         else if  (strncasecmp(s, "CANCEL",3)==0)  style |= CANCEL;
         else if  (strncasecmp(s, "I_EXC", 5)==0)  style |= ICON_ERROR;
         else if  (strncasecmp(s, "I_ERR", 5)==0)  style |= ICON_ERROR;
         else if  (strncasecmp(s, "I_QUES",6)==0)  style |= ICON_QUESTION;
         else if  (strncasecmp(s, "I_INF", 5)==0)  style |= ICON_INFORMATION;
         //      else if  (stricmp(s, "YES_DEFAULT"))     style |= wxYES_DEFAULT;
         //      else if  (stricmp(s, "NO_DEFAULT"))      style |= wxNO_DEFAULT;
         //      else if  (stricmp(s, "CANCEL_DEFAULT"))  style |= wxCANCEL_DEFAULT;
         //      else if  (stricmp(s, "OK_DEFAULT"))      style |= wxOK_DEFAULT;
//         PRINT_ERROR("s=\'%s\', style = 0x%X\n", s, style);
         s = strtok(NULL, "| \n\t");
      }
   }
//   PRINT_ERROR("style = 0x%X\n", style);
   if (style == 0) {
      style = OK;
   }
  //    4    2    8       0             0x80         0x80000000     0             10
  //  wxOK,wxYES,wxNO,wxYES_DEFAULT,wxNO_DEFAULT,wxCANCEL_DEFAULT,wxOK_DEFAULT,wxCANCEL;

   int rc = wxPlugin->display(message, title, style);
   switch (rc) {
      default:
      case CANCEL:    rc = 0; break;
      case YES:       rc = 1; break;
      case NO:        rc = 2; break;
      case OK:        rc = 3; break;
   }
   Tcl_SetObjResult(interp, Tcl_NewIntObj(rc));
   return TCL_OK;
}

static int cmd_exit(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
    long exitCode = 0;

    bdmInterface->closeBdm();
    bdmInterface.reset();
    bdmInterface = BdmInterfaceFactory::createInterface(T_OFF, nullCallback);

    wxPlugin.reset();

    if (argc > 2) {
        Tcl_WrongNumArgs(interp, 1, argv, "?exitCode?");
    }
    if (argc == 2) {
       Tcl_GetLongFromObj(interp, argv[1], &exitCode);
    }
    Tcl_Exit(exitCode);
    return TCL_ERROR;
}

//! Usage message
static const char usageText[] =
   "connect                      - Connect to target\n"
   "closeBDM                     - Close BDM connection\n"
   "debug <value>                - Debug commands\n"
   "dialogue <title> <body> yes_no|cancel|ok|i_exclaim|i_question|i_info|i_err\n"
   "       returns 0=>cancel, 1=yes, 2=no, 3=ok\n"
   "                             - display dialogue\n"
   "exit                         - Exit program\n"
   "getErrorMessage <rc>         - Get given USBDM rc as String\n"
   "getLastError                 - Get last USBDM rc as number\n"
   "getLastErrorMessage          - Get last USBDM rc as string\n"
   "go                           - Start from current PC\n"
   "getcap                       - Get BDM Capabilities\n"
   "gs                           - Read status register\n"
   "halt                         - Halt the target\n"
   "help                         - Display help\n"
   "jtag-reset                   - Take JTAG TAP to TEST-LOGIC-RESET state\n"
   "jtag-shift <S|R|D|I><#bits><values>  - Shift given values into current chain\n"
   "                               S=stay, R=exit Run-test/Idle, D=shift-DR, I=shiftIR\n"
   "jtag-shift-dr                - Set up for DR chain shift\n"
   "jtag-shift-ir                - Set up for IR chain shift\n"
   "jtag-idcode                  - Read IDCODE from JTAG\n"
   "log 0|1                      - setting ARM loggin OFF/ON\n"
   "memorySpace [<N|X|P>]        - set memory space (DSC)\n"
   "openbdm [<bdmNumber>]        - Open given BDM\n"
   "pinSet <pin=level>           - Control pins, pin=RST|BKGD|TRST|BKPT|TA|SWD,\n"
   "                                level=H|L|3|-\n"
   "regs                         - PRINT out registers\n"
   "reset <N|S><H|S|P|A>         - Reset to bdm mode\n"
   "rblock <addr> <size>         - Read block\n"
   "rb <addr> <count>            - Read byte\n"
   "rw <addr> <count>            - Read word\n"
   "rl <addr> <count>            - Read longword (CFV1 only)\n"
   "rreg <regNo>                 - Read core register\n"
   "rdreg <regNo>                - Read debug register\n"
   "rcreg <regNo>                - Read control register\n"
   "setboot                      - Set USBDM module to ICP mode\n"
   "setbytesex <big|little>      - Set big/little endian target\n"
   "defaultMemorySpace N,X,P     - Set default memory space (N:None,X:Data,P:Program)"
   "settarget <target>           - HCS12/HCS08/RS08/CFV1/DSC/JTAG/ARM\n"
   "settargetvdd <0|3|5|on|off>  - Set target Vdd (only has effect if target set)\n"
   "settargetvpp <standby|on|off>- Set target Vpp\n"
   "speed ?Hz?                   - Set/Get speed \n"
   "step                         - Execute a single instruction\n"
   "sync                         - Execute a low level sync\n"
   "tblock <start> <end> <count> - Random RAM write/read block test\n"
   "testcreg                     - Test control register\n"
   "testStatus                   - Read target status in an infinite loop\n"
   "wc <value>                   - Write control register\n"
   "wpc <value>                  - Write to PC\n"
   "wblock <addr> <size> <data>  - Write block\n"
   "wb <addr> <data>             - Write byte\n"
   "ww <addr><value>             - Write word\n"
   "wl <addr><value>             - Write longword (CFV1 only)\n"
   "wreg <regNo><value>          - Write core register\n"
   "wdreg <regNo><value>         - Write debug register\n"
   "wcreg <regNo><value>         - Write control register\n"
   ;

//! Help command
static int cmd_help(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   fprintf(stderr,"%s",usageText);
   return TCL_OK;
}

static int cmd_setByteSex(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv) {
   if (argc > 2) {
       Tcl_WrongNumArgs(interp, 1, argv, "[<big|little>]");
       return TCL_ERROR;
   }
   if (argc == 1) {
      PRINT("bytesex => %s\n", bigEndian?"Big-endian":"Little-endian");
      Tcl_SetObjResult(interp, Tcl_NewBooleanObj(bigEndian));
      return TCL_OK;
   }
   // Control value
   const char *currentToken = Tcl_GetString(argv[1]);
   if (strncasecmp(currentToken, "big", 3) == 0) {
      bigEndian = true;
      PRINT("bytesex => Big-endian\n");
   }
   else if (strncasecmp(currentToken, "little", 6) == 0) {
      bigEndian = false;
      PRINT("bytesex => Little-endian\n");
   }
   else {
      PRINT("bytesex [<little/big>]\n");
      return TCL_ERROR;
   }
   return TCL_OK;
}

//==========================================================================

typedef int (*TclCommand)(ClientData, Tcl_Interp *interp, int argc, Tcl_Obj *const *argv);

static struct {
   TclCommand command;

const char *name;
} myCommands[] = {
      { cmd_connect,              "connect" },
//    { initialiseCommand,        "initialise" },
      { cmd_pinSet,               "pinSet" },
//    { debugCommand,             "debug"},
      { cmd_go,                   "go"},
      { cmd_status,               "gs"},
      { cmd_getLastError,         "getLastError"},
      { cmd_getErrorMessage,      "getErrorMessage"},
      { cmd_getLastErrorMessage,  "getLastErrorMessage"},
      { cmd_getCapabilities,      "getcap"},
      { cmd_halt,                 "halt"},
      { jtagResetCommand,         "jtag-reset"},
      { jtagShiftCommand,         "jtag-shift"},
      { jtagShiftDRCommand,       "jtag-shift-dr"},
      { jtagShiftIRCommand,       "jtag-shift-ir"},
      { jtagIdentifyCommand,      "jtag-idcode"},
      { cmd_reset,                "reset" },
      { cmd_readByte,             "rblock"},
      { cmd_readByte,             "rb"},
      { cmd_readWord,             "rw"},
      { cmd_readLong,             "rl"},
      { cmd_readReg,              "rreg"},
      { cmd_readStatus,           "rs"},
      { cmd_readDReg,             "rdreg"},
      { cmd_readCReg,             "rcreg"},
//      { cmd_setBoot,              "setboot" },
      { cmd_setSpeed,             "speed" },
      { cmd_sync,                 "sync" },
      { cmd_setMemorySpace,       "defaultMemorySpace" },
      { cmd_setByteSex,           "setbytesex" },
      { cmd_step,                 "step"},
      { cmd_registers,            "regs"},
      { cmd_testStatus,           "testStatus"},
      { cmd_writeBlock,           "wblock"},
      { cmd_writeControl,         "wc"},
      { cmd_writeProgramCounter,  "wpc"},
      { cmd_writeByte,            "wb"},
      { cmd_writeWord,            "ww"},
      { cmd_writeLong,            "wl"},
      { cmd_writeReg,             "wreg"},
      { cmd_writeCReg,            "wcreg"},
      { cmd_writeDReg,            "wdreg"},
      { cmd_setVpp,               "settargetvpp" },
      { cmd_setVdd,               "settargetvcc" },
      { cmd_setVdd,               "settargetvdd" },
      { cmd_massErase,            "massErase"},
//      { setLogCommand,          "log"},
      { cmd_dialogue,             "dialogue"},
      { cmd_openBDM,              "openbdm" },
      { cmd_closeBDM,             "closebdm" },
      { cmd_setTarget,            "settarget" },
      { cmd_exit,                 "exit"},
      { cmd_help,                 "help"},
      { cmd_help,                 "?"},
      { cmd_testBlock,            "tblock"},
//      { cmd_testCReg,           "testcreg"},
      { NULL, NULL }
};

void UsbdmTclInterpreterImp::registerUSBDMCommands(Tcl_Interp *interp) {
   int index;
   /*
    *  Register our TCL commands.
    */
   for (index=0; myCommands[index].command != NULL; index++) {
      Tcl_CreateObjCommand(interp, myCommands[index].name, myCommands[index].command, NULL,  NULL);
   }
}

