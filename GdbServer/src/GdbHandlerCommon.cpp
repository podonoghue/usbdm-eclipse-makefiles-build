/*
 * GdbHandlerCommon.cpp
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#include <stdarg.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>    // std::find_if

#include "GdbHandlerCommon.h"
#include "FlashImageFactory.h"
#include "UsbdmTclInterpreterFactory.h"
#include "signals.h"
#include "Names.h"

#define THREAD_STOPPED_STRING    "thread:1;"
#define THREAD_INFO_STRING       "m1"
//#define THREAD_STOPPED_STRING    ""
//#define THREAD_INFO_STRING       ""

GdbHandlerCommon *GdbHandlerCommon::This=0;

static const char targetXML[] =
      "<?xml version=\"1.0\"?>\n"
      "<!DOCTYPE target SYSTEM \"gdb-target.dtd\">\n"
      "<target version=\"1.0\">\n"
      "   <xi:include href=\"targetRegs.xml\"/>\n"
      "</target>\n"
      ;

GdbHandlerCommon::GdbHandlerCommon(
      TargetType_t              targetType,
      GdbHandlerOwner          &owner,
      GdbInOut                 *gdbInOut,
      BdmInterfacePtr           bdmInterface,
      DeviceInterfacePtr        deviceInterface,
      GdbBreakpoints           *gdbBreakpoints,
      IGdbTty                  *tty,
      DeviceData::ResetMethod   defaultResetMethod) :
         targetType(targetType),
         owner(owner),
         gdbInOut(gdbInOut),
         bdmInterface(bdmInterface),
         deviceInterface(deviceInterface),
         gdbBreakpoints(gdbBreakpoints),
         tty(tty),
         defaultResetMethod(defaultResetMethod),
         initBreakpointsDone(false),
         programmingDone(false),
         deviceData(deviceInterface->getCurrentDevice()),
         nonStopMode(false),
         haltNotice(nullptr)
{
   LOGGING;

   runState                     = RunState_Halted;
   vStoppedAvailable            = false;
   useFastRegisterRead          = true;
   unsuccessfulPollCount        = 0;
   forceTargetHalt              = false;
   registerBufferSize           = 0;
   targetRegsXMLSize            = 0;
   targetLastRegIndex           = 0;
   targetRegsXMLSize            = 0;

   This = this;

   gdbInOut->setLoggers(errorLogger, 0, 0);

   initRegisterDescription();
}

GdbHandlerCommon::~GdbHandlerCommon() {
   tclInterpreter.reset();
}

USBDM_ErrorCode GdbHandlerCommon::initialise() {
   LOGGING;

   initBreakpointsDone = false;
   programmingDone     = false;

   bdmInterface->enableSerialInterface(false);

   USBDM_ErrorCode rc = bdmInterface->connect();
   if (rc != BDM_RC_OK) {
      // Silent retry
      rc = bdmInterface->connect();
   }
   if (rc != BDM_RC_OK) {
      log.error("Connect failed, rc = %s\n", bdmInterface->getErrorString(rc));
   }
   rc = bdmInterface->halt();
   if (rc == BDM_RC_OK) {
      // Immediately update status
      pollTarget();
   }
   return rc;
}

void GdbHandlerCommon::errorLogger(const char *msg) {
   This->reportGdbPrintf(M_ERROR, "%s\n", msg);
}

/**
 * Extract a 32-bit big value from a byte array
 *
 * @param buff Array containing value
 *
 * @return 32-bit value from 4-bytes of the array
 */
uint32_t GdbHandlerCommon::get32bitBE(uint8_t buff[]) {
   return (buff[0]<<24)+(buff[1]<<16)+(buff[2]<<8)+(buff[3]);
}

/**
 * Extract a 32-bit little-endian value from a byte array
 *
 * @param buff Array containing value
 *
 * @return 32-bit value from 4-bytes of the array
 */
uint32_t GdbHandlerCommon::get32bitLE(uint8_t buff[]) {
   return (buff[0])+(buff[1]<<8)+(buff[2]<<16)+(buff[3]<<24);
}

/**  Writes status message in 'printf' manner
 *
 *   @param level  - Debug level
 *   @param rc     - Error code associated with message
 *   @param format - Print control string
 *   @param ...    - Argument list
 *
 *   @return Modified error code
 *
 *   @note assumes BDM_RC_OK error code (i.e. no error)
 */
USBDM_ErrorCode GdbHandlerCommon::reportGdbPrintf(GdbMessageLevel level, USBDM_ErrorCode rc, const char *format, ...) {
   char buff[200];
   va_list list;
   va_start(list, format);
   vsnprintf(buff, sizeof(buff), format, list);
   return    owner.displayMessage(buff, level, rc);
}

/**  Writes status message in 'printf' manner
 *
 *   @param level  - Debug level
 *   @param format - Print control string
 *   @param ...    - Argument list
 *
 *   @return Modified error code
 *
 *   @note assumes BDM_RC_OK error code (i.e. no error)
 */
USBDM_ErrorCode GdbHandlerCommon::reportGdbPrintf(GdbMessageLevel level, const char *format, ...) {
   char buff[200];
   va_list list;
   va_start(list, format);
   vsnprintf(buff, sizeof(buff), format, list);
   return owner.displayMessage(buff, level, BDM_RC_OK);
}

/**  Writes status message in 'printf' manner
 *
 *   @param format - Print control string
 *   @param ...    - Argument list
 *
 *   @return Modified error code
 *
 *   @note assumes BDM_RC_OK error code (i.e. no error)
 *   @note assumed M_BORINGINFO interest level
 */
USBDM_ErrorCode GdbHandlerCommon::reportGdbPrintf(const char *format, ...) {
   char buff[200];
   va_list list;
   va_start(list, format);
   vsnprintf(buff, sizeof(buff), format, list);
   return owner.displayMessage(buff, M_BORINGINFO, BDM_RC_OK);
   return BDM_RC_OK;
}

/**
 * Convert a ASCII-HEX character to integer
 *
 * @param[in]  ch      Character to convert ('0'-'9', 'a'-'f' or 'A'-'F')
 * @param[out] value   Value in range 0-15
 *
 * @return true  => successful conversion
 * @return false => unsuccessful conversion (invalid character found)
 */
bool GdbHandlerCommon::hexToInt(char ch, int *value) {
   if ((ch >= '0') && (ch <= '9')) {
      *value = (ch - '0');
      return true;
   }
   if ((ch >= 'a') && (ch <= 'f')) {
      *value = (ch - 'a' + 10);
      return true;
   }
   if ((ch >= 'A') && (ch <= 'F')) {
      *value = (ch - 'A' + 10);
      return true;
   }
   return false;
}

/**
 * Convert ASCII-HEX 8-character string to integer
 *
 * @param[in]  ch      Characters to convert ('0'-'9', 'a'-'f' or 'A'-'F')
 * @param[out] value   32-bit value
 *
 * @return true  => successful conversion
 * @return false => unsuccessful conversion (invalid character found)
 */
bool GdbHandlerCommon::hexToInt32(const char *ch, unsigned long *value) {
   *value = 0;
   for (int i=0; i<8; i++) {
      int temp;
      if (!hexToInt(*ch++, &temp))
         return false;
      *value *= 16;
      *value += temp;
   }
   return true;
}

/**
 * Convert ASCII-HEX 4-character string to integer
 *
 * @param[in]  ch      Characters to convert ('0'-'9', 'a'-'f' or 'A'-'F')
 * @param[out] value   16-bit value
 *
 * @return true  => successful conversion
 * @return false => unsuccessful conversion (invalid character found)
 */
bool GdbHandlerCommon::hexToInt16(const char *ch, unsigned long *value) {
   *value = 0;
   for (int i=0; i<4; i++) {
      int temp;
      if (!hexToInt(*ch++, &temp))
         return false;
      *value *= 16;
      *value += temp;
   }
   return true;
}

/**
 * Convert ASCII-HEX 2-character string to integer
 *
 * @param[in]  ch      Characters to convert ('0'-'9', 'a'-'f' or 'A'-'F')
 * @param[out] value   8-bit value
 *
 * @return true  => successful conversion
 * @return false => unsuccessful conversion (invalid character found)
 */
bool GdbHandlerCommon::hexToInt8(const char *ch, unsigned long *value) {
   *value = 0;
   for (int i=0; i<2; i++) {
      int temp;
      if (!hexToInt(*ch++, &temp))
         return false;
      *value *= 16;
      *value += temp;
   }
   return true;
}

/**
 * Report status to GDB ("O...")
 *
 *   @param s    - '\0' terminated string to send encoded
 *   @param size - maximum size of encoded string to send (-1 ignored)
 */
void GdbHandlerCommon::reportStatusToGdb(const char *s, int size) {
   LOGGING_Q;
   gdbInOut->sendGdbHexString("O", s, size);
}

/**
 * Gets the TCL interface.
 * The interface will be created if necessary
 */
UsbdmTclInterperPtr GdbHandlerCommon::getTclInterface() {
   if (tclInterpreter == nullptr) {
      tclInterpreter = UsbdmTclInterperFactory::createUsbdmTclInterpreter(bdmInterface);
      tclInterpreter->setDeviceParameters(deviceData);
   }
   return tclInterpreter;
}

/**
 * Executes a TCL command previously loaded in the TCL interpreter
 *
 * @param command Command to execute
 */
USBDM_ErrorCode GdbHandlerCommon::runTCLCommand(const char *command) {
   LOGGING_Q;
   log.print("Command = '%s'\n", command);

   log.enableLogging(false);
   USBDM_ErrorCode rc = getTclInterface()->evalTclScript(command);
   if (rc != BDM_RC_OK) {
      log.error("Failed - rc = %d (%s)\n", rc, bdmInterface->getErrorString(rc));
   }
   return rc;
}

/**
 * Get reset method to use
 *
 * @return reset method
 */
DeviceData::ResetMethod GdbHandlerCommon::getResetMethod() {
   LOGGING_Q;

   DeviceData::ResetMethod resetMethod = defaultResetMethod;
   if (deviceData == nullptr) {
      log.print("Device not set!\n");
   }
   else {
      resetMethod = deviceData->getResetMethod();
      if ((resetMethod == DeviceData::resetTargetDefault)) {
         ResetMethodsConstPtr resetMethods = deviceData->getResetMethods();
         if (resetMethods == nullptr) {
            log.print("resetMethods not set!\n");
            resetMethod = defaultResetMethod;
         }
         resetMethod = resetMethods->getDefaultMethod();
      }
   }
//   log.print("Reset method = %s\n", DeviceData::getResetMethodName(resetMethod));
   return resetMethod;
}

USBDM_ErrorCode GdbHandlerCommon::resetTarget(DeviceData::ResetMethod resetMethod) {
   LOGGING;

   TargetMode_t targetMode;

   if (resetMethod == DeviceData::resetTargetDefault) {
      resetMethod = getResetMethod();
      log.error("Reset defaulted to method %s\n", DeviceData::getResetMethodName(resetMethod));
   }
   else {
      log.error("Reset method %s\n", DeviceData::getResetMethodName(resetMethod));
   }
   switch (resetMethod) {
      default:
      case DeviceData::resetTargetDefault:
         log.error("Unexpected reset method %s, defaulting to hardware\n", DeviceData::getResetMethodName(resetMethod));
         // no break
      case DeviceData::resetHardware:
         targetMode = (TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE);
         break;
      case DeviceData::resetSoftware:
         targetMode = (TargetMode_t)(RESET_SPECIAL|RESET_SOFTWARE);
         break;
      case DeviceData::resetVendor:
         targetMode = (TargetMode_t)(RESET_SPECIAL|RESET_VENDOR);
         break;
   }

   USBDM_ErrorCode rc = bdmInterface->reset(targetMode);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   runTCLCommand("initTarget");
   readRegs();
   return rc;
}

USBDM_ErrorCode GdbHandlerCommon::haltTarget() {
//   LOGGING;

   return bdmInterface->halt();
}

/**
 * Notify GDB of target status change
 *
 * @return
 */
USBDM_ErrorCode GdbHandlerCommon::notifyGdb() {
   if (runState != RunState_Running) {
      reportHalt('T', TARGET_SIGNAL_INT);
   }
   return BDM_RC_OK;
}

/**
 *    Single step target
 *
 * @param disableInterrupts - true/false -> disable/enable interrupts on step
 */
USBDM_ErrorCode GdbHandlerCommon::stepTarget(bool disableInterrupts) {
   LOGGING_Q;
   maskInterrupts(disableInterrupts);
   unsigned long pc;
   readPC(&pc);
   log.print("step from 0x%lX\n", pc);
   bdmInterface->step();
   runState = RunState_Stepping;
   registerBufferSize = 0;

   return BDM_RC_OK;
}

/**
 *    Continue target
 *
 *    Breakpoints are activated.
 */
USBDM_ErrorCode GdbHandlerCommon::continueTarget(void) {
   LOGGING_Q;
   unsigned long currentPC;
   readPC(&currentPC);
   maskInterrupts(false);
   activateBreakpoints();
   bdmInterface->go();
   runState = RunState_Running;
   log.print("Continue - Now running\n");
   registerBufferSize = 0;

   return BDM_RC_OK;
}

/**
 * Send portion of XML to debugger
 */
void GdbHandlerCommon::sendXML(unsigned size, unsigned offset, const char *buffer, unsigned bufferSize) {
   LOGGING;
   gdbInOut->putGdbPreamble();
   if (offset >= bufferSize) {
      gdbInOut->putGdbString("l");
   }
   else {
      if (size > (bufferSize-offset)) {
         // Remainder fits in this pkt
         size = bufferSize-offset;
         gdbInOut->putGdbChar('l');
      }
      else {
         // More pkts to follow
         gdbInOut->putGdbChar('m');
      }
      gdbInOut->putGdbString(buffer+offset, size);
   }
   gdbInOut->sendGdbBuffer();
}

USBDM_ErrorCode GdbHandlerCommon::doReadCommand(char *command) {
   char           addrModeC;
   uint32_t       addr,length;
   MemorySpace_t  addressMode;

   USBDM_ErrorCode rc = BDM_RC_OK;
   do {
      if (sscanf(command, "read %c %X %X", &addrModeC, &addr, &length) != 3) {
         rc = BDM_RC_ILLEGAL_PARAMS;
         continue;
      }
      switch (addrModeC) {
         case 'b' : addressMode = MS_Byte; break;
         case 'h' : addressMode = MS_Word; break;
         case 'w' : addressMode = MS_Long; break;
         default  : rc = BDM_RC_ILLEGAL_PARAMS; continue;
      }
//      reportGdbPrintf(M_INFO, "Target Read [0x%X..0x%x X].%s\n", addr, addr+length-1, getMemSpaceName(addressMode));
      uint8_t buffer[2000];
      if (length > sizeof(buffer)) {
         rc = BDM_RC_ILLEGAL_PARAMS;
         reportGdbPrintf(M_INFO, "Failed, reason: Length too large\n");
         continue;
      }
      rc = bdmInterface->readMemory(addressMode, length, addr, buffer);
      if (rc != 0) {
         reportGdbPrintf(M_INFO, "Failed, reason:%s\n", bdmInterface->getErrorString(rc));
         continue;
      }
      gdbInOut->sendGdbHexDataString("O", buffer, length);
   }
   while (0);
   if (rc != BDM_RC_OK) {
      gdbInOut->sendGdbHexString("O", bdmInterface->getErrorString(rc), -1);
   }
   gdbInOut->sendGdbString("OK");
   return rc;
}

/*
 * Do monitor commands
 */
USBDM_ErrorCode GdbHandlerCommon::doMonitorCommand(const char *cmd) {
   LOGGING_Q;
   char command[200], *bPtr = command;
   for (const char *cp=cmd+sizeof("qRcmd,")-1; *cp != '\0'; cp += 2) {
      unsigned long value;
      if (!hexToInt8(cp, &value)) {
         break;
      }
      *bPtr++ = (char)value;
   }
   *bPtr = '\0';
   log.print("%s\n", command);
   if (strStartsWith("read", command)) {
      doReadCommand(command);
   }
   else if (strStartsWith("reset", command)) {
      //TODO Handle parameters
      reportGdbPrintf(M_INFO, "User reset of target\n");
      resetTarget();
      gdbInOut->sendGdbHexString("O", "User reset of target\n", -1);
      gdbInOut->sendGdbString("OK");
      if (nonStopMode) {
         reportHalt('T', TARGET_SIGNAL_INT);
      }
      registerBufferSize = 0;
   }
   else if (strStartsWith("run", command)) {
      // ignore any parameters
      reportGdbPrintf(M_INFO, "User run of target\n");
      bdmInterface->go();
      gdbInOut->sendGdbHexString("O", "User run of target\n", -1);
      gdbInOut->sendGdbString("OK");
      registerBufferSize = 0;
   }
   else if (strStartsWith("halt", command)) {
      // ignore any parameters
      reportGdbPrintf(M_INFO, "User halt of target\n");
      bdmInterface->halt();
      gdbInOut->sendGdbHexString("O", "User halt of target\n", -1);
      gdbInOut->sendGdbString("OK");
      registerBufferSize = 0;
   }
   else if (strStartsWith("speed", command)) {
      int speedValue = 1000 * atoi(command+sizeof("speed"));
      bdmInterface->setSpeedHz(speedValue);
      reportGdbPrintf(M_INFO, "Setting speed %d\n", speedValue);
      bdmInterface->setSpeedHz(12000 /* kHz */);
      gdbInOut->sendGdbHexString("O", "Done", -1);
      gdbInOut->sendGdbString("OK");
   }
   else if (strStartsWith("delay", command)) {
      // Ignored
      int delayValue = atoi(command+sizeof("delay"));
      reportGdbPrintf(M_INFO, "Executing delay %d ms\n", delayValue);
      UsbdmSystem::milliSleep(delayValue);
      gdbInOut->sendGdbHexString("O", "Done", -1);
      gdbInOut->sendGdbString("OK");
   }
   else if (strStartsWith("maskisr", command)) {
      char *ptr = command+sizeof("maskisr")-1;
      while (isspace(*ptr)) {
         ptr++;
      }
      if (strStartsWith("1", ptr) ||
            strStartsWith("on", ptr) ||
            strStartsWith("t", ptr)) {
         bdmInterface->setMaskISR(true);
      }
      else if (strStartsWith("0", ptr) ||
            strStartsWith("off", ptr) ||
            strStartsWith("f", ptr)) {
         reportGdbPrintf(M_INFO, "maskisr On\n");
         bdmInterface->setMaskISR(false);
      }
      if (bdmInterface->isMaskISR()) {
         reportGdbPrintf(M_INFO, "maskisr on\n");
         gdbInOut->sendGdbHexString("O", "maskisr on\n", -1);
      }
      else {
         reportGdbPrintf(M_INFO, "maskisr off\n");
         gdbInOut->sendGdbHexString("O", "maskisr off\n", -1);
      }
      gdbInOut->sendGdbString("OK");
      registerBufferSize = 0;
   }
   else if (strStartsWith("help", command)) {
      gdbInOut->sendGdbHexString("O",
                                 "MON commands\n"
                                 "=====================\n"
                                 "maskisr (on|off)\n"
                                 "halt\n"
                                 "reset\n"
                                 "=====================\n",
                                 -1);
      gdbInOut->sendGdbString("OK");
   }
   else {
      log.print("Unrecognised mon command: \'%s\'\n", cmd);
      reportGdbPrintf(M_INFO, "Unrecognised command: \'%s\'\n", cmd);
      gdbInOut->sendGdbHexString("O", "Unrecognised command\n", -1);
      gdbInOut->sendGdbString("OK");
   }
   return BDM_RC_OK;
}

USBDM_ErrorCode GdbHandlerCommon::doQCommands(const GdbPacket *pkt) {
   LOGGING_Q;
   int offset, size;
   const char *cmd = pkt->buffer;

   if (strncmp(cmd, "qSupported", sizeof("qSupported")-1) == 0) {
      log.print("qSupported\n");
      char buff[200];
      char *cptr = buff;
      cptr += sprintf(cptr,
            "QStartNoAckMode+;qXfer:memory-map:read+;PacketSize=%X;qXfer:features:read+;hwbreak+;swbreak+;vContSupported+",
            GdbPacket::MAX_MESSAGE-10);
#if NON_STOP_SUPPORTED
      cptr += sprintf(cptr,";QNonStop+");
#endif
      gdbInOut->sendGdbString(buff);
   }
// This was an experiment - in any case obsolete
//   else if (strStartsWith("qL", cmd)) {
//      //                       qMnne<-----pid------><-----pid------>
//      gdbInOut->sendGdbString("qM01100000000000000000000000000000100");
//   }//qL1200000000000000000
#if THREAD_MODE
   else if (strStartsWith("qC", cmd)) {
      // Return the current thread ID.
      // Empty response indicates use the previously selected thread
      gdbInOut->sendGdbString("");
   }
   else if (strStartsWith("qfThreadInfo", cmd)) {
      log.print("Thread Information - initial\n");
      // All threads are active
      gdbInOut->sendGdbString(THREAD_INFO_STRING);
   }
   else if (strStartsWith("qsThreadInfo", cmd)) {
      log.print("Thread Information - later\n");
      gdbInOut->sendGdbString("l");
   }
   else if (strStartsWith("qThreadExtraInfo", cmd)) {
      log.print("Thread Extra Info\n");
      gdbInOut->sendGdbHexString(NULL, "Runnable");
   }
#endif
#if DUMMY_TRACE_MODE
   else if (strStartsWith("qTStatus", cmd)) {
      // Trace not supported
      // No trace experiment running right now
      gdbInOut->sendGdbString("T0;tnotrun:0");
   }
#endif
#if NON_STOP_SUPPORTED
   else if (strStartsWith("QNonStop", cmd)) {
      nonStopMode = cmd[sizeof("QNonStop")] == '1';
      log.print("QNonStop %s\n", nonStopMode?"On":"Off");
      gdbInOut->sendGdbString("OK");
   }
#endif
   else if (strStartsWith("qSymbol", cmd)) {
      log.print("qSymbol\n");
      // Don't need symbol value
      gdbInOut->sendGdbString("OK");
   }
   else if (strStartsWith("qAttached", cmd)) {
      log.print("qAttached\n");
      // 0 => The remote server created a new process.
      // 1 => The remote server attached to an existing process.
      gdbInOut->sendGdbString("1");
   }
   else if (strStartsWith("QStartNoAckMode", cmd)) {
      log.print("QStartNoAckMode\n");
      gdbInOut->sendGdbString("OK");
      gdbInOut->setAckMode(false);
   }
   else if (strStartsWith("qOffsets", cmd)) {
      log.print("qOffsets\n");
      // No relocation done
      gdbInOut->sendGdbString("Text=0;Data=0;Bss=0");
   }
   else if (strStartsWith("qXfer:memory-map:read::", cmd)) {
      if (sscanf(cmd,"qXfer:memory-map:read::%X,%X",&offset, &size) != 2) {
         log.print("Ill formed:\'%s\'", cmd);
         gdbInOut->sendGdbString("");
      }
      else {
         log.print("memory-map:read::%X:%X\n", offset, size);
         unsigned xmlBufferSize;
         const char *xmlBuffer;
         createMemoryMapXML(&xmlBuffer, &xmlBufferSize);
         sendXML(size, offset, xmlBuffer, xmlBufferSize);
      }
   }
   else if (strStartsWith("qXfer:features:read:target.xml:", cmd)) {
      if (targetRegsXMLSize > 0) {
         reportGdbPrintf(M_INFO, "Sending target description\n");
         if (sscanf(cmd,"qXfer:features:read:target.xml:%X,%X",&offset, &size) != 2) {
            log.print("Ill formed:\'%s\'", cmd);
            gdbInOut->sendGdbString("");
         }
         else {
            log.print("qXfer:features:read:target.xml:%X:%X\n", offset, size);
            sendXML(size, offset, targetXML, sizeof(targetXML));
         }
      }
      else {
         // Target register description not available
         gdbInOut->sendGdbString("");
      }
   }
   else if (strStartsWith("qXfer:features:read:targetRegs.xml:", cmd)) {
      reportGdbPrintf(M_INFO, "Sending register description\n");
      if (targetRegsXMLSize > 0) {
         if (sscanf(cmd,"qXfer:features:read:targetRegs.xml:%X,%X",&offset, &size) != 2) {
            log.print("Ill formed:\'%s\'", cmd);
            gdbInOut->sendGdbString("");
         }
         else {
            log.print("qXfer:features:read:targetRegs.xml:%X:%X\n", offset, size);
            sendXML(size, offset, targetRegsXML, targetRegsXMLSize);
         }
      }
      else {
         // Target register description not available
         gdbInOut->sendGdbString("");
      }
   }
   else if (strStartsWith("qRcmd", cmd)) {
      // Monitor command
      doMonitorCommand(cmd);
   }
   else {
      log.print("Unrecognised command:\'%s\'\n", cmd);
      gdbInOut->sendGdbString("");
   }
   return BDM_RC_OK;
}

/**
 * Handle 'v...' commands
 */
USBDM_ErrorCode GdbHandlerCommon::doVCommands(const GdbPacket *pkt) {
   LOGGING;
   int address, length;
   const char *cmd = pkt->buffer;

   if (strStartsWith("vFlashErase", cmd)) {
      // vFlashErase:addr,length
      if (sscanf(cmd, "vFlashErase:%x,%x", &address, &length) != 2) {
         gdbInOut->sendErrorMessage(0x11);
      }
      else {
         log.print("vFlashErase:0x%X:0x%X\n", address, length);
         reportGdbPrintf(M_INFO, "Erasing flash[%X..%X] - ignored\n", address, address+length-1);
         gdbInOut->sendGdbString("OK");
      }
   }
   else if (strStartsWith("vFlashWrite", cmd)) {
      // vFlashWrite:addr:XX...
      if (sscanf(cmd, "vFlashWrite:%x:", &address) != 1) {
         log.print(" vFlashWrite:error:\n");
         gdbInOut->sendErrorMessage(0x11);
      }
      else {
         log.print("vFlashWrite:0x%X:\n", address);
         if (flashImage == NULL) {
            reportGdbPrintf(M_INFO, "Creating flash image\n");
            flashImage = FlashImageFactory::createFlashImage(targetType);
         }
         reportGdbPrintf(M_INFO, "Writing to flash image[%X..", address);
         const char *vPtr = strchr(pkt->buffer,':');
         vPtr = strchr(++vPtr, ':');
         vPtr++;
         int size=pkt->size-(vPtr-pkt->buffer);
//         bool newLine = true;
         while(size-->0) {
            flashImage->setValue(address, *vPtr);
//            if (newLine)
//               log.printq("\n%8.8X:", address);
//            log.printq("%2.2X", (unsigned char)*vPtr);
            address++;
            vPtr++;
//            newLine = (address & 0x0F) == 0;
         }
         reportGdbPrintf(M_INFO, "%X]\n", address-1);
//         log.printq("\n");
         gdbInOut->sendGdbString("OK");
      }
   }
   else if (strStartsWith("vFlashDone", cmd)) {
      // vFlashDone
      log.print("vFlashDone\n");
      log.enableLogging(false);
      if (flashImage != NULL) {
         reportGdbPrintf(M_INFO, "Programming Target Flash....\n");
         USBDM_ErrorCode rc = programImage(flashImage);
         flashImage.reset();
         if (rc != PROGRAMMING_RC_OK) {
            log.print("vFlashDone: Programming failed, rc=%s\n", bdmInterface->getErrorString(rc));
            reportGdbPrintf(M_FATAL, rc, "Programming Flash Image failed: ");
            gdbInOut->sendErrorMessage(GdbInOut::E_Fatal, "Flash programming failed");
            return rc;
         }
         else {
            reportGdbPrintf(M_INFO, "Programming successful\n");
            log.print("vFlashDone: Programming complete\n");
         }
         resetTarget();
         reportGdbPrintf(M_INFO, "Reset target\n");
         log.print("vFlashDone: Reset target\n");
      }
      else {
         reportGdbPrintf(M_INFO, "Programming Flash Image skipped (empty image)\n");
         log.error("vFlashDone: Memory image empty, programming skipped\n");
      }
      log.enableLogging(true);
      bdmInterface->enableSerialInterface(true);
      gdbInOut->sendGdbString("OK");
   }
   else if (strStartsWith("vCont", cmd)) {
      doVContCommands(pkt);
   }
   else if (strStartsWith("vRun", cmd)) {
      log.print("vRun\n");
      log.print("Target Reset\n");
      reportGdbPrintf(M_INFO, "Resetting target\n");
      resetTarget();
      tty->closeAll();
      gdbInOut->sendGdbString("OK");
   }
   else if (strStartsWith("vKill", cmd)) {
      log.print("vKill\n");
      log.print("Target Reset\n");
      reportGdbPrintf(M_INFO, "Resetting target\n");
      resetTarget();
      tty->closeAll();
      gdbInOut->sendGdbString("OK");
   }
   else if (strStartsWith("vCtrlC", cmd)) {
      log.print("vCtrlC\n");
      reportGdbPrintf(M_INFO, "^C - Halting target\n");
      forceTargetHalt = true;
      if (runState == RunState_Running) {
         haltTarget();
      }
      gdbInOut->sendGdbString("OK");
   }
   else if (strStartsWith("vStopped", cmd)) {
      reportGdbPrintf(M_INFO, "vStopped\n");
      if (vStoppedAvailable && (runState == RunState_Halted)) {
         sendLocation();
      }
      else {
         gdbInOut->sendGdbString("OK");
      }
   }
   else if (strStartsWith("vMustReplyEmpty", cmd)) {
      // Special unknown command which is really known so no error log
      // requited response is that which is usual for an unknown 'v' command
      gdbInOut->sendGdbString("");
   }
   else {
      log.print("Unrecognised command:\'%s\'\n", cmd);
      gdbInOut->sendGdbString("");
   }
   return BDM_RC_OK;
}

USBDM_ErrorCode GdbHandlerCommon::programImage(FlashImagePtr flashImage) {
   LOGGING_F;
//   log.enableLogging(false);
   // Suppress detailed reporting of the programming operation
//   log.setLoggingLevel(0);

   USBDM_ErrorCode rc = BDM_RC_OK;
   do {
      if (deviceData->getEraseMethod() == DeviceData::eraseNone) {
         rc = BDM_RC_ILLEGAL_PARAMS;
         break;
      }
      if (deviceData->getSecurity() == SEC_SECURED) {
         rc = BDM_RC_ILLEGAL_PARAMS;
         break;
      }

      FlashProgrammerPtr flashProgrammer = FlashProgrammerFactory::createFlashProgrammer(bdmInterface);
      flashProgrammer->setDeviceData(deviceData, getTclInterface());
      USBDM_ErrorCode rc = flashProgrammer->setDeviceData(deviceData);
      if (rc == BDM_RC_OK) {
         rc = flashProgrammer->programFlash(flashImage, 0, true);
      }
      if (rc != PROGRAMMING_RC_OK) {
         log.print("programImage() - failed, rc = %s\n", bdmInterface->getErrorString(rc));
         break;
      }
      programmingDone = true;
   } while (0);
   return rc;
}

/**
 * Create XML description of current device memory map in GDB expected format
 *
 * @param buffer     - location to return address of static buffer initialised.
 * @param bufferSize - size of buffer data
 */
void GdbHandlerCommon::createMemoryMapXML(const char **buffer, unsigned *bufferSize) {
   LOGGING_Q;
   // Prefix for memory map XML
   static const char xmlPrefix[] =
      "<?xml version=\"1.0\"?>\n"
      "<!DOCTYPE memory-map\n"
      "   PUBLIC \"+//IDN gnu.org//DTD GDB Memory Map V1.0//EN\"\n"
      "   \"http://sourceware.org/gdb/gdb-memory-map.dtd\">\n"
      "<memory-map version=\"1.0.0\" >\n";
   // Suffix for memory map XML
   static const char xmlSuffix[] =
      "</memory-map>\n";

   static char xmlBuff[2000] = {0};
   char *xmlPtr;

   xmlPtr = xmlBuff;
   *bufferSize = 0;
   strcpy(xmlPtr, xmlPrefix);
   xmlPtr += sizeof(xmlPrefix)-1; // Discard trailing '\0'

   for (int memIndex=0; true; memIndex++) {
      MemoryRegionPtr pMemoryregion(deviceData->getMemoryRegion(memIndex));
      if (!pMemoryregion) {
         break;
      }
      log.print("memory area #%d", memIndex);
      for (unsigned memRange=0; memRange<pMemoryregion->memoryRanges.size(); memRange++) {
         uint32_t start, size;
         const MemoryRegion::MemoryRange *memoryRange = pMemoryregion->getMemoryRange(memRange);
         if (memoryRange == NULL)
            break;
         switch (pMemoryregion->getMemoryType()) {
         case MemXRAM:
         case MemXROM:
         case MemPROM:
         case MemPRAM:
            log.printq(" - XRAM/XROM - Ignored\n");
            break;
         case MemEEPROM:
            log.printq(" - EEPROM - Ignored\n");
            break;
         case MemFlexNVM:
         case MemDFlash:
         case MemPFlash:
         case MemFLASH:
            start = memoryRange->start;
            size  = memoryRange->end - start + 1;
            log.printq(" - FLASH[0x%08X..0x%08X]\n", memoryRange->start, memoryRange->end);
            xmlPtr += sprintf(xmlPtr,
                           "<memory type=\"flash\" start=\"0x%X\" length=\"0x%X\" > \n"
                           "   <property name=\"blocksize\">0x400</property> \n"
                           "</memory>\n",
                           start, size);
            break;
         case MemFlexRAM:// Treat FlexRAM as RAM
         case MemIO:     // Treat I/O as RAM
         case MemRAM:
            start = memoryRange->start;
            size  = memoryRange->end - start + 1;
            log.printq(" - RAM[0x%08X..0x%08X]\n", memoryRange->start, memoryRange->end);
            xmlPtr += sprintf(xmlPtr,
                           "<memory type=\"ram\" start=\"0x%X\" length=\"0x%X\" /> \n",
                           start, size);
            break;
         case MemROM:
            start = memoryRange->start;
            size  = memoryRange->end - start + 1;
            log.printq(" - ROM[0x%08X..0x%08X]\n", memoryRange->start, memoryRange->end);
            xmlPtr += sprintf(xmlPtr,
                           "<memory type=\"rom\" start=\"0x%X\" length=\"0x%X\" /> \n",
                           start, size);
            break;
         case MemInvalid:
            log.printq(" - Invalid\n");
            break;
         }
      }
   }
   strcpy(xmlPtr, xmlSuffix);
   xmlPtr += sizeof(xmlSuffix)-1; // Discard trailing '0'

//   log.print("XML = \n\"%s\"\n", xmlBuff);
   *buffer = xmlBuff;
   *bufferSize = xmlPtr-xmlBuff;
}

// trim from start
static inline std::string &ltrim(std::string &s) {
     s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
     return s;
}

/**
 * Sets up the register description from device XML
 */
bool GdbHandlerCommon::initRegisterDescription(void) {
   LOGGING_E;

   RegisterDescriptionConstPtr registerDescriptionPtr = deviceData->getRegisterDescription();
   if (registerDescriptionPtr == NULL) {
      return false;
   }
   reportGdbPrintf("Loading register description from device database\n");
   targetRegsXMLSize  = registerDescriptionPtr->getDescription().length();
   if (targetRegsXMLSize > sizeof(targetRegsXML)) {
      reportGdbPrintf(M_FATAL, BDM_RC_ILLEGAL_PARAMS, "Internal error, targetRegsXML description is too large: ");
      targetRegsXMLSize = sizeof(targetRegsXML);
   }
   std::string s = registerDescriptionPtr->getDescription();
   strncpy(targetRegsXML, ltrim(s).c_str(), targetRegsXMLSize);
   targetLastRegIndex = registerDescriptionPtr->getLastRegisterIndex();
   return true;
}

/*
 *  Get cached value of PC as a string
 *  Note: Assumes cache valid
 *
 *  @return ptr to static buffer
 */
const char *GdbHandlerCommon::getCachedPcAsString() {
   static char buff[20];

   sprintf(buff, "0x%08X", getCachedPC());
   return buff;
}

void GdbHandlerCommon::sendLocation() {
   LOGGING;

   if (haltNotice==nullptr) {
      // No information available - just send bare stop
      gdbInOut->sendGdbString("S05" THREAD_STOPPED_STRING);
   }
   else {
      gdbInOut->sendGdbString(haltNotice);
   }
   // Prevent repeated vStopped responses
   vStoppedAvailable = false;
}

/**
 * Send notification that the target has stopped.
 * Only applicable if in non-stop mode and the target is actually stopped.
 *
 * Sets stateChanged so response is available when polled by vStopped.
 */
void GdbHandlerCommon::notifyStop() {
   LOGGING;

   if (haltNotice==nullptr) {
      // No information available - just send bare stop notice
      gdbInOut->sendGdbNotification("Stop:S05" THREAD_STOPPED_STRING);
      return;
   }
   else {
      char buff[100];
      snprintf(buff, sizeof(buff), "Stop:%s", haltNotice);
      gdbInOut->sendGdbNotification(buff);
   }
   // Set so vStopped response is available
   vStoppedAvailable = true;
}

/**
 * Report halted.
 * In non-stop mode this will be a notification otherwise assumed to be a response to a expected halt e.g. after 'vCont' etc.
 *
 * @param mode          Indicates the reply mode e.g. S T etc
 * @param signal        Signal value e.g. TARGET_SIGNAL_TRAP TARGET_SIGNAL_INT
 */
void GdbHandlerCommon::reportHalt(char mode, int signal) {
   LOGGING;
   static char buff[100];
   char *cPtr = buff;
   char breakType[20] = "";

   uint32_t address;
   GdbBreakpoints::BreakType watchType;

   if (atBreakpoint(getCachedPC())) {
      strcpy(breakType,"hwbreak:;");
   }
   else if (gdbBreakpoints->findMatchedDataWatchPoint(address, watchType)) {
      snprintf(breakType, sizeof(breakType), "%s:%X;", GdbBreakpoints::getGdbBreakpointName(watchType), address);
   }

   haltNotice = buff;
   cPtr += sprintf(buff, "%c%02X%s%s" THREAD_STOPPED_STRING, mode, signal, breakType, getImportantRegisters());
   *cPtr++ = '\0';

   log.print("\"%s\"\n", buff);
   if (nonStopMode) {
      // Notify for later report
      notifyStop();
   }
   else {
      // Send expected response
      gdbInOut->sendGdbString(haltNotice);
   }
}

/**
 * Read all registers from target into registerBuffer
 * Sets registerBufferSize to number of bytes valid in buffer
 *
 * @note values are written in target byte order
 */
USBDM_ErrorCode GdbHandlerCommon::readRegs(void) {
   LOGGING;

   reportGdbPrintf("Refreshing Register cache\n");

   if (useFastRegisterRead) {
      // Try reading registers using fast method
      USBDM_ErrorCode rc = bdmInterface->readMultipleRegs(registerBuffer, 0, targetLastRegIndex);

      if (rc == BDM_RC_OK) {
         // OK
         registerBufferSize = 4*(targetLastRegIndex+1);
         return BDM_RC_OK;
      }
      switch(rc) {
      case BDM_RC_ILLEGAL_COMMAND:
         // Failed read due to lack of support for fast register read - try the old method
         useFastRegisterRead = false;
         log.print("Switching to old register read method\n");
         break;
      default:
         // Ignore errors until programming complete
         // Prevent GDB aborting due to secured device etc
         if (programmingDone) {
            // Failed read - error response
            reportGdbPrintf("Register read failed, rc = %s\n", bdmInterface->getErrorString(rc));
            log.error("Register read failed, rc = %s\n", bdmInterface->getErrorString(rc));
            return rc;
         }
         // Return dummy register information
         // no break
      case BDM_RC_TARGET_BUSY:
         // Failed due to processor running - ignore so GDB doesn;t abort
         // Return dummy register information
         reportGdbPrintf("Register read failed - ignored, rc = %s\n", bdmInterface->getErrorString(rc));
         log.error("Register read failed - ignored, rc = %s\n", bdmInterface->getErrorString(rc));
         registerBufferSize = 4*(targetLastRegIndex+1);
         memset(registerBuffer, 0, 4*(targetLastRegIndex+1));
         return BDM_RC_OK;
      }
//      if (rc != BDM_RC_ILLEGAL_COMMAND) {
//         // Failed read NOT due to lack of firmware support for fast register read
//         if (rc == BDM_RC_TARGET_BUSY || (!programmingDone)) {
//            // Ignore errors until programming has been done
//            // Return dummy register information
//            reportGdbPrintf("Register read failed - ignored, rc = %s\n", bdmInterface->getErrorString(rc));
//            log.error("Register read failed - ignored, rc = %s\n", bdmInterface->getErrorString(rc));
//            registerBufferSize = 4*(targetLastRegIndex+1);
//            memset(registerBuffer, 0, 4*(targetLastRegIndex+1));
//            return BDM_RC_OK;
//         }
//         // Failed read - error response
//         reportGdbPrintf("Register read failed, rc = %s\n", bdmInterface->getErrorString(rc));
//         log.error("Register read failed, rc = %s\n", bdmInterface->getErrorString(rc));
//         return rc;
//      }
//      // Failed read due to lack of support for fast register read - try the old method
//      useFastRegisterRead = false;
//      log.print("Switching to old register read method\n");
   }
   if (!useFastRegisterRead) {
      unsigned regNo;
      registerBufferSize = 0;
      uint8_t *buffPtr = registerBuffer;
      for (regNo = 0; regNo<=targetLastRegIndex; regNo++) {
         readReg(regNo, buffPtr);
      }
      registerBufferSize = buffPtr-registerBuffer;
   }
   return BDM_RC_OK;
}
/**
 * Report register values to GDB
 * Reads registers from target if necessary
 *
 * @note values are sent to GDB in target byte order
 */
void GdbHandlerCommon::sendRegs(void) {
   LOGGING_E;
   USBDM_ErrorCode rc = BDM_RC_OK;
   if (registerBufferSize == 0) {
      rc = readRegs();
      debug_print_regs();
   }
   if ((rc != BDM_RC_OK) || (registerBufferSize == 0)) {
      log.error("Failed to read regs\n");
      gdbInOut->sendErrorMessage(GdbInOut::E_Fatal, "Register read failed");
      return;
   }
   gdbInOut->sendGdbHex(registerBuffer, registerBufferSize);
}

/**
 * Write target register set from buffer containing ASCII-HEX chars (received from GDB)
 *
 * @param buff Buffer containing register values
 *
 * @note Buffer is in target byte order
 */
void GdbHandlerCommon::writeRegs(const char *buff) {
   LOGGING;
   unsigned long regValue = 0;
   unsigned regNo;

   reportGdbPrintf("Writing Registers\n");
   for (regNo = 0; regNo<=targetLastRegIndex; regNo++) {
      if (!hexToInt32(buff, &regValue))
         break;
      buff += 8;
      regValue = targetToBE32(regValue);
      writeReg(regNo, regValue);
   }
   gdbInOut->sendGdbString("OK");
   registerBufferSize = 0;
}

static MemorySpace_t getAlignment(uint32_t address, uint32_t numBytes) {

   MemorySpace_t align = MS_Long; // Assume 4-byte alignment
   if (((address & 0x3) != 0) || ((numBytes & 0x3) != 0)) {
      align = MS_Word;
   }
   if (((address & 0x1) != 0) || ((numBytes & 0x1) != 0)) {
      align = MS_Byte;
   }
   return align;
}

/**
 * Read bytes from target memory and send to GDB as packet
 *
 * @param address    Memory address to read from
 * @param numBytes   NUmber of bytes to transfer
 */
void GdbHandlerCommon::readMemory(uint32_t address, uint32_t numBytes) {
   LOGGING;
   unsigned char buff[1000] = {0};

   MemorySpace_t align = getAlignment(address, numBytes);
   reportGdbPrintf(GdbHandler::M_BORINGINFO, "Reading Memory[%X..%X], align = %s\n", address, address+numBytes-1, getMemSpaceName(align));
//   log.print("readMemory(addr=%X, size=%X)\n", address, numBytes);
   if (bdmInterface->readMemory(align, numBytes, address, buff) != BDM_RC_OK) {
      // Ignore errors
      memset(buff, 0xAA, numBytes);
   }
   gdbInOut->sendGdbHex(buff, numBytes);
}

/**
 * Convert a hex string into a series of byte values
 *
 * @param[in]  numBytes - number of bytes to convert
 * @param[in]  dataIn   - Pointer to string of ASCII-HEX chars (2 * numBytes) as received from GDB
 * @param[out] dataOut  - Pointer to output buffer (numBytes)
 *
 * @return true => ok conversion\n
 *         false => failed
 */
bool GdbHandlerCommon::convertFromHex(unsigned numBytes, const char *dataIn, uint8_t *dataOut) {
//   log.print("convertFromHex()\n");
   for (unsigned index=0; index<numBytes; index++) {
      unsigned long value;
      if (!hexToInt8(dataIn, &value)) {
         return false;
      }
//      log.print("convertFromHex() %2.2s => %2.2X\n", dataIn, value);
      dataIn += 2;
      *dataOut++ = value;
   }
   return true;
}

/**
 * Convert a series of byte values into a ASCII-HEX string
 *
 * @param[in]  numBytes - number of bytes to convert
 * @param[in]  dataIn   - Pointer to string of byte values (numBytes)
 * @param[out] dataOut  - Pointer to output buffer (2 * numBytes) suitable to send to GDB
 */
void GdbHandlerCommon::convertToHex(unsigned numBytes, const uint8_t *dataIn, char *dataOut) {
   auto convert = [](int value) {
      value &= 0xF;
      if (value>=10) {
         return 'A'+value;
      }
      else {
         return '0'+value;
      }
   };
   //   log.print("convertFromHex()\n");
   for (unsigned index=0; index<numBytes; index++) {
      *dataOut++ = convert(*dataIn++>>4);
      *dataOut++ = convert(*dataIn++);
   }
}

/**
 * Write value to target memory from GDB format buffer
 *
 * @param ccPtr      Values to write (buffer)
 * @param address    Memory address
 * @param numBytes   Number of bytyes to write
 */
void GdbHandlerCommon::writeMemory(const char *ccPtr, uint32_t address, uint32_t numBytes) {
   unsigned char buff[1000];

   MemorySpace_t align = getAlignment(address, numBytes);
   reportGdbPrintf(GdbHandler::M_BORINGINFO, "Writing Memory[%X..%X], align = %s\n", address, address+numBytes-1, getMemSpaceName(align));
//   log.print("writeMemory(addr=%X, size=%X)\n", address, numBytes);
   convertFromHex(numBytes, ccPtr, buff);
   bdmInterface->writeMemory(align, numBytes, address, buff);
   gdbInOut->sendGdbString("OK");
}

//! Handle 'vCont' commands
//!
USBDM_ErrorCode GdbHandlerCommon::doVContCommands(const GdbPacket *pkt) {
   LOGGING;
//   int address, length;
   const char *cmd = pkt->buffer;
   if (strStartsWith("vCont?", cmd)) {
      log.print("vCont?\n");
      gdbInOut->sendGdbString("vCont;c;s;t");
   }
//   else if (strStartsWith("vCont;", cmd)) {
//      bool skip = false;
//      bool sendExtraNotify = false;
//      const char *cPtr = cmd+sizeof("vCont")-1;
//      while (cPtr<(pkt->buffer+pkt->size)) {
//         char ch = *cPtr++;
//         if (ch == ';') {
//            // New command
//            skip = false;
//            continue;
//         }
//         if (skip) {
//            // Skip rest of current command
//            continue;
//         }
//         // Process command
//         switch(ch) {
//            case 'c': // Continue
//               log.print("vCont;c - continue\n");
//               continueTarget();
//               break;
//            case 's': // Step
//               log.print("vCont;s - step\n");
//               stepTarget(bdmInterface->isMaskISR());
//               break;
//            case 't': // Halt
//               log.print("vCont;t - halt\n");
//               if (runState == RunState_Halted) {
//                  // Stopped already
//                  // Notify in case earlier notice missed
//                  sendExtraNotify = true;
//               }
//               haltTarget();
//               break;
//         }
//         // Discard rest of command if any (thread id)
//         skip = true;
//      }
//      gdbInOut->sendGdbString("OK");
//      if (sendExtraNotify) {
//         notifyStop();
//      }
//   }
   else if (strStartsWith("vCont;c", cmd)) {
      log.print("vCont;c - continue\n");
      continueTarget();
      gdbInOut->sendGdbString("OK");
   }
   else if (strStartsWith("vCont;s", cmd)) {
      log.print("vCont;s - step\n");
      stepTarget(bdmInterface->isMaskISR());
      gdbInOut->sendGdbString("OK");
   }
   else if (strStartsWith("vCont;t", cmd)) {
      log.print("vCont;t - halt\n");
      if (runState == RunState_Halted) {
         // Stopped already
         // Notify in case earlier notice missed
         gdbInOut->sendGdbString("OK");
         notifyStop();
      }
      else {
         haltTarget();
         gdbInOut->sendGdbString("OK");
      }
   }
   else {
      log.print("Unrecognised command:\'%s\'\n", cmd);
      gdbInOut->sendGdbString("OK");
   }
   return BDM_RC_OK;
}

USBDM_ErrorCode GdbHandlerCommon::doCommand(const GdbPacket *pkt) {
   LOGGING_Q;
   unsigned address;
   unsigned numBytes;
   const char *ccptr;
   int type;
   unsigned kind;
   int regNo;
   int value;

   if (pkt->isBreak()) {
      // Break command
      log.print("Break\n");
      reportGdbPrintf(M_INFO, "BREAK - Halting target\n");
      forceTargetHalt = true;
      if (runState == RunState_Running) {
         haltTarget();
      }
      return BDM_RC_OK;
   }
   switch (pkt->buffer[0]) {
   case '!' : // Enable extended mode
      log.print("Enable extended mode\n");
      gdbInOut->sendGdbString("OK");
      break;
   case 'R' : // Target reset
      log.print("Target Reset\n");
      reportGdbPrintf(M_INFO, "Resetting target\n");
      resetTarget();
      tty->closeAll();
      break;
   case 'g' : // 'g' - Read general registers.
//   Reply:
//   -  'XX...' Each byte of register data is described by two hex digits. The bytes
//      with the register are transmitted in target byte order. The size of
//      each register and their position within the 'g' packet are determined
//      by the gdb internal gdbarch functions and gdbarch_register_name.
//   -  'E NN' for an error.
      log.print("Read Regs =>\n");
      sendRegs();
      break;
   case 'G' : // 'G XX...' - Write general registers.
//      See [read registers packet] for a description of the XX... data.
//   Reply:
//     - 'OK' for success
//     - 'E NN' for an error
      log.print("Write Regs =>\n");
      writeRegs(pkt->buffer+1);
      break;
   case 'm' : // 'm addr,length' - Read memory
      if (sscanf(pkt->buffer, "m%X,%x:", &address, &numBytes) != 2) {
         log.print("Illegal cmd format\n");
         gdbInOut->sendErrorMessage(0x01);
      }
      else {
         log.print("readMemory [0x%08X..0x%08X]\n", address, address+numBytes-1);
         readMemory(address, numBytes);
      }
//      Read length bytes of memory starting at address addr. Note that addr may
//      not be aligned to any particular boundary.
//      The stub need not use any particular size or alignment when gathering data
//      from memory for the response; even if addr is word-aligned and length is a
//      multiple of the word size, the stub is free to use byte accesses, or not. For
//      this reason, this packet may not be suitable for accessing memory-mapped I/O
//      devices.
//      Reply:
//      'XX...' Memory contents; each byte is transmitted as a two-digit hexadecimal
//      number. The reply may contain fewer bytes than requested if
//      the server was able to read only part of the region of memory.
//      'E NN' NN is errno
      break;
   case 'M' : // 'M addr,length:XX...' - Write memory
      if ((sscanf(pkt->buffer, "M%X,%x:", &address, &numBytes) != 2) ||
          ((ccptr = strchr(pkt->buffer, ':')) == NULL)) {
         log.print("Illegal cmd format\n");
         gdbInOut->sendErrorMessage(0x01);
      }
      else {
         log.print("writeMemory [0x%08X...0x%08X] %2s...\n", address, address+numBytes-1, ccptr+1);
         writeMemory(ccptr+1, address, numBytes);
      }
//      Write length bytes of memory starting at address addr. XX. . . is the data;
//      each byte is transmitted as a two-digit hexadecimal number.
//      Reply:
//      'OK' for success
//      'E NN' for an error (this includes the case where only part of the data was
//      written).
      break;
   case 'c' : // 'c [addr]' - Continue
      //      Continue. addr is address to resume. If addr is omitted, resume at current
      //      address.
      //      Reply: See [Stop Reply Packets] for the reply specification or notification.
      if (sscanf(pkt->buffer, "c%X", &address) == 1) {
         // Set PC to address
         address = targetToBE32(address);
         log.print("Continue @addr=%X\n", address);
         reportGdbPrintf(M_INFO, "Continue @addr=%X\n", address);
         writePC(address);
      }
      else {
         log.print("Continue @PC\n");
         reportGdbPrintf(M_INFO, "Continue @PC\n");
      }
      continueTarget();
      break;
   case 's' :
      // 's' [addr] - Single step.
      //      addr is the address at which to resume. If addr is omitted, resume at same address.
      //      Reply: See [Stop Reply Packets], page for the reply specifications.
      if (sscanf(pkt->buffer, "s%X", &address) > 1) {
         // Set PC to address
         log.print("Single step @addr=%X\n", address);
         reportGdbPrintf(M_INFO, "Single step @addr=%X\n", address);
         writePC(address);
      }
      else {
         log.print("Single step @PC\n");
         reportGdbPrintf(M_INFO, "Single step @PC\n");
      }
      stepTarget(bdmInterface->isMaskISR());
      break;
   case 'Z' :
      // 'z type,addr,kind' - insert/remove breakpoint
      log.print("Z - Insert breakpoint\n");
      if (sscanf(pkt->buffer, "Z%d,%x,%x", &type, &address, &kind) != 3) {
         log.print("Illegal cmd format\n");
         gdbInOut->sendErrorMessage(0x11);
         break;
      }
      if (insertBreakpoint((GdbBreakpoints::BreakType)type, address, kind)) {
         gdbInOut->sendGdbString("OK");
         reportGdbPrintf(M_BORINGINFO, "Set breakpoint @0x%X\n", address);
      }
      else {
         log.print("Failed to set Breakpoint\n");
         reportGdbPrintf(M_ERROR, "Failed to set breakpoint @0x%X\n", address);
         gdbInOut->sendErrorMessage(0x11);
      }
      break;
   case 'z' : // 'z type,addr,kind' - insert/remove breakpoint
      log.print("z - Remove breakpoint\n");
      if (sscanf(pkt->buffer, "z%d,%x,%x", &type, &address, &kind) != 3) {
         gdbInOut->sendErrorMessage(0x11);
         break;
      }
      if (removeBreakpoint((GdbBreakpoints::BreakType)type, address, kind)) {
         reportGdbPrintf(M_BORINGINFO, "Removed breakpoint @0x%X\n", address);
         gdbInOut->sendGdbString("OK");
      }
      else {
         log.print("Failed to remove Breakpoint\n");
         reportGdbPrintf(M_ERROR, "Failed to remove breakpoint @0x%X\n", address);
         gdbInOut->sendErrorMessage(0x11);
      }
      break;
   case 'P' :
      // 'P n...=r...' Write register n... with value r.... The register number n
      // is in hexadecimal,
      if (sscanf(pkt->buffer, "P%x=%x", &regNo, &value) != 2) {
         log.print("Illegal cmd format\n");
         gdbInOut->sendErrorMessage(0x11);
         break;
      }
//      log.print("GDB-P regNo=%x, val=%X\n", regNo, value);
      if (isValidRegister(regNo)) {
         value = targetToBE32(value);
         writeReg(regNo, value);
         gdbInOut->sendGdbString("OK");
         reportGdbPrintf(M_BORINGINFO, "Write register %d <= 0x%X\n", regNo, value);
      }
      else {
         log.print("Illegal register\n");
         gdbInOut->sendErrorMessage(0x11);
         reportGdbPrintf(M_BORINGINFO, "Write register - illegal!\n");
      }
      registerBufferSize = 0;
      break;
   case 'p' : // 'p n...' Read register n...
      if (sscanf(pkt->buffer, "p%x", &regNo) != 1) {
         log.error("Failed to parse register\n");
         gdbInOut->sendErrorMessage(0x11);
         break;
      }
      log.print("Read reg %d\n", regNo);
      {
         unsigned char buff[10];
         unsigned char *tBuff = buff;
         readReg(regNo, tBuff);
         int size = tBuff-buff;
         uint32_t t;
         extractTarget32Bits(buff, t);
         log.print("Read reg %d => %X\n", regNo, t);
         gdbInOut->sendGdbHex(buff, size);
      }
//      if (isValidRegister(regNo)) {
//         readReg(regNo, buff);
//         gdbInOut->sendGdbString(buff);
//      }
//      else {
//         gdbInOut->sendErrorMessage(0x11);
//      }
      break;
#if THREAD_MODE
   case 'H' : // 'H c thread-id' Set thread (e.g. Hg0)
      if (strStartsWith("Hg-1", pkt->buffer)) {
         currentThread = -1;
         log.print("Current thread = All\n");
         gdbInOut->sendGdbString("OK");
         break;
      }
      else if (sscanf(pkt->buffer, "Hg%d", &value) == 1) {
         currentThread = value;
         log.print("Current thread = %X\n", currentThread);
         gdbInOut->sendGdbString("OK");
         break;
      }
      else if (strStartsWith("Hc-1", pkt->buffer)) {
         // Deprecated so ignored
         gdbInOut->sendGdbString("");
         break;
      }
      else if (sscanf(pkt->buffer, "Hc%d", &value) == 1) {
         // Deprecated so ignored
         gdbInOut->sendGdbString("");
         break;
      }
      log.error("Failed to parse threadID\n");
      gdbInOut->sendErrorMessage(0x11);
      break;
   case 'T' : // Thread status
      log.print("Thread Status\n");
      gdbInOut->sendGdbString("OK");
      break;
#endif
   case '?' : // '?' Indicate the reason the target stopped.
      if (runState == RunState_Halted) {
         sendLocation();
         vStoppedAvailable = true;
      }
      else {
         // Not stopped
         gdbInOut->sendGdbString("OK");
      }
      break;
   case 'k' : // Kill
      reportGdbPrintf(M_INFO, "Kill...\n");
      log.print("Kill...\n");
      tty->closeAll();
      gdbInOut->sendGdbString("OK");
      gdbInOut->finish();
      reportGdbPrintf(M_FATAL, "Closed connection\n");
      return BDM_RC_OK;
   case 'D' : // Detach
      reportGdbPrintf(M_INFO, "Detach...\n");
      log.print("Detach...\n");
      tty->closeAll();
      gdbInOut->sendGdbString("OK");
      continueTarget();
      gdbInOut->finish();
      reportGdbPrintf(M_FATAL, "Closed connection\n");
      return BDM_RC_OK;
      break;
   case 'q' : // q commands
   case 'Q' : // Q commands
      doQCommands(pkt);
      break;
   case 'v' : // v commands
      doVCommands(pkt);
      break;
   default : // Unrecognised command
      log.print("Unrecognised command:\'%s\'\n", pkt->buffer);
      gdbInOut->sendGdbString("");
      break;
   }
   return BDM_RC_OK;
}

/**
 * Get the current timeout value
 */
unsigned GdbHandlerCommon::getConnectionTimeout() {
   if (bdmInterface != 0) {
      return bdmInterface->getConnectionTimeout();
   }
   return 10;
}

USBDM_ErrorCode GdbHandlerCommon::initBreakpoints() {
   LOGGING;
   USBDM_ErrorCode rc = gdbBreakpoints->initBreakpoints();
   if (rc != BDM_RC_OK) {
      log.error("gdbBreakpoints->initBreakpoints() failed, rc = %s", bdmInterface->getErrorString(rc));
      reportGdbPrintf(M_INFO, "initBreakpoints() failed, rc = %s\n", bdmInterface->getErrorString(rc));
      resetTarget();
      rc = gdbBreakpoints->initBreakpoints();
   }
   initBreakpointsDone = true;
   log.print("Number of hardware breakpoints = %d\n", gdbBreakpoints->getNumberOfHardwareBreakpoints());
   log.print("Number of hardware watches     = %d\n", gdbBreakpoints->getNumberOfHardwareWatches());
   reportGdbPrintf("Number of hardware breakpoints = %d\n", gdbBreakpoints->getNumberOfHardwareBreakpoints());
   reportGdbPrintf("Number of hardware watches     = %d\n", gdbBreakpoints->getNumberOfHardwareWatches());
   return rc;
};
