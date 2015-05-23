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
#include "signals.h"
#include "Names.h"
#include "Utils.h"

GdbHandlerCommon *GdbHandlerCommon::This=0;

static const char targetXML[] =
      "<?xml version=\"1.0\"?>\n"
      "<!DOCTYPE target SYSTEM \"gdb-target.dtd\">\n"
      "<target version=\"1.0\">\n"
      "   <xi:include href=\"targetRegs.xml\"/>\n"
      "</target>\n"
      ;

GdbHandlerCommon::GdbHandlerCommon(TargetType_t targetType, GdbInOut *gdbInOut, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, GdbBreakpoints *gdbBreakpoints, GdbCallback gdbCallBackPtr) :
   GdbHandler(),
   gdbBreakpoints(gdbBreakpoints),
   targetType(targetType),
   gdbInOut(gdbInOut),
   bdmInterface(bdmInterface),
   deviceInterface(deviceInterface),
   deviceData(*deviceInterface->getCurrentDevice()) {
   LOGGING;

   if (gdbCallBackPtr == 0) {
      this->gdbCallBackPtr      = dummyCallback;
   }
   else {
      this->gdbCallBackPtr      = gdbCallBackPtr;
   }
   runState                     = halted;
   gdbTargetStatus              = T_UNKNOWN;
   useFastRegisterRead          = true;
   runState                     = halted;
   gdbTargetStatus              = T_UNKNOWN;
   unsuccessfulPollCount        = 0;
   targetBreakPending           = false;
   targetBreakPending           = false;
   registerBufferSize           = 0;
   targetRegsXMLSize            = 0;
   targetLastRegIndex           = 0;
   targetRegsXMLSize            = 0;
   lastStoppedPC                = 0;

   This = this;

   gdbInOut->setLoggers(errorLogger, 0, 0);

   initRegisterDescription();
}

GdbHandlerCommon::~GdbHandlerCommon() {
}

USBDM_ErrorCode GdbHandlerCommon::initialise() {
   USBDM_ErrorCode rc = bdmInterface->connect();
   if (rc != BDM_RC_OK) {
      // Silent retry
      rc = bdmInterface->connect();
   }
   return rc;
}


USBDM_ErrorCode GdbHandlerCommon::dummyCallback(const char *msg, GdbMessageLevel level, USBDM_ErrorCode rc) {
   return BDM_RC_FAIL;
}

void GdbHandlerCommon::errorLogger(const char *msg) {
   This->reportGdbPrintf(M_ERROR, "%s\n", msg);
}

uint32_t GdbHandlerCommon::get32bitBE(uint8_t buff[]) {
   return (buff[0]<<24)+(buff[1]<<16)+(buff[2]<<8)+(buff[3]);
}

uint32_t GdbHandlerCommon::get32bitLE(uint8_t buff[]) {
   return (buff[0])+(buff[1]<<8)+(buff[2]<<16)+(buff[3]<<24);
}

/*!  Writes status message in 'printf' manner
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
   if (gdbCallBackPtr != NULL) {
      char buff[200];
      va_list list;
      va_start(list, format);
      vsnprintf(buff, sizeof(buff), format, list);

      return (*gdbCallBackPtr)(buff, level, rc);
   }
   return BDM_RC_OK;
}

/*!  Writes status message in 'printf' manner
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
   if (gdbCallBackPtr != NULL) {
      char buff[200];
      va_list list;
      va_start(list, format);
      vsnprintf(buff, sizeof(buff), format, list);
      return (*gdbCallBackPtr)(buff, level, BDM_RC_OK);
   }
   return BDM_RC_OK;
}

/*!  Writes status message in 'printf' manner
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
   if (gdbCallBackPtr != NULL) {
      char buff[200];
      va_list list;
      va_start(list, format);
      vsnprintf(buff, sizeof(buff), format, list);

      return (*gdbCallBackPtr)(buff, M_BORINGINFO, BDM_RC_OK);
   }
   return BDM_RC_OK;
}

// Note - the following assume bigendian
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

long GdbHandlerCommon::hexToInt16(const char *ch, unsigned long *value) {
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

long GdbHandlerCommon::hexToInt8(const char *ch, unsigned long *value) {
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

/*! Checks if two string are equal
 *  @param s1 first string
 *  @paran s2 second string
 *
 *  @return true if equal, false otherwise
 */
bool GdbHandlerCommon::streq(const char *s1, const char *s2) {
   return strcmp(s1,s2) == 0;
}

/*! Checks if two string are equal
 *
 *  @param s1 first string
 *  @paran s2 second string
 *  @param length number of characters to check
 *
 *  @return true if equal in the first length characters, false otherwise
 */
bool GdbHandlerCommon::strneq(const char *s1, const char *s2, int length) {
   return strncmp(s1,s2,length) == 0;
}

//! Report status to GDB ("O...")
//!
//! @param s          - string describing status
//!
void GdbHandlerCommon::reportStatusToGdb(const char *s, int size) {
   LOGGING_Q;
   gdbInOut->sendGdbHexString("O", s, size);
}

USBDM_ErrorCode GdbHandlerCommon::resetTarget(TargetMode_t mode) {
   LOGGING;

   USBDM_ErrorCode rc = bdmInterface->reset(mode);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   return rc;
}

/*!
 *    Single step target
 *
 * @param disableInterrupts - true/false -> disable/enable interrupts on step
 */
USBDM_ErrorCode GdbHandlerCommon::stepTarget(bool disableInterrupts) {
   maskInterrupts(disableInterrupts);
   return bdmInterface->step();
}

/*!
 *    Continue target
 *
 *    If at a breakpoint then a single step is done (with interrupts masked) before
 *    continuing at full execution.
 *    Breakpoints are activated.
 */
void GdbHandlerCommon::continueTarget(void) {
   LOGGING_Q;
   unsigned long currentPC;
   readPC(&currentPC);
   if (atBreakpoint(currentPC)) {
      // Do 1 step before activating memory breakpoints
      log.print("Continue - stepping one instruction...\n");
      stepTarget(true);
   }
   maskInterrupts(false);
   activateBreakpoints();
   log.print("Continue - executing...\n");
   bdmInterface->go();
   log.print("Continue - Now running\n");
}

//! Send portion of XML to debugger
//!
//!
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

/* Do monitor commands
 *
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
   if (strneq(command, "read", sizeof("read")-1)) {
      doReadCommand(command);
   }
   else if (strneq(command, "reset", sizeof("reset")-1)) {
      //TODO Handle parameters
      reportGdbPrintf(M_INFO, "User reset of target\n");
      resetTarget((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
      gdbInOut->sendGdbHexString("O", "User reset of target\n", -1);
      gdbInOut->sendGdbString("OK");
      registerBufferSize = 0;
   }
   else if (strneq(command, "run", sizeof("run")-1)) {
      // ignore any parameters
      reportGdbPrintf(M_INFO, "User run of target\n");
      bdmInterface->go();
      gdbInOut->sendGdbHexString("O", "User run of target\n", -1);
      gdbInOut->sendGdbString("OK");
      registerBufferSize = 0;
   }
   else if (strneq(command, "halt", sizeof("halt")-1)) {
      // ignore any parameters
      reportGdbPrintf(M_INFO, "User halt of target\n");
      bdmInterface->halt();
      gdbInOut->sendGdbHexString("O", "User halt of target\n", -1);
      gdbInOut->sendGdbString("OK");
      registerBufferSize = 0;
   }
   else if (strneq(command, "speed", sizeof("speed")-1)) {
      int speedValue = 1000 * atoi(command+sizeof("speed"));
      bdmInterface->setSpeedHz(speedValue);
      reportGdbPrintf(M_INFO, "Setting speed %d\n", speedValue);
      bdmInterface->setSpeedHz(12000 /* kHz */);
      gdbInOut->sendGdbHexString("O", "Done", -1);
      gdbInOut->sendGdbString("OK");
   }
   else if (strneq(command, "delay", sizeof("delay")-1)) {
      // Ignored
      int delayValue = atoi(command+sizeof("delay"));
      reportGdbPrintf(M_INFO, "Executing delay %d ms\n", delayValue);
      UsbdmSystem::milliSleep(delayValue);
      gdbInOut->sendGdbHexString("O", "Done", -1);
      gdbInOut->sendGdbString("OK");
   }
   else if (strneq(command, "maskisr", sizeof("maskisr")-1)) {
      char *ptr = command+sizeof("maskisr")-1;
      while (isspace(*ptr)) {
         ptr++;
      }
      if (strneq(ptr, "1",  sizeof("1")-1) ||
            strneq(ptr, "on", sizeof("on")-1) ||
            strneq(ptr, "t",  sizeof("t")-1)) {
         bdmInterface->setMaskISR(true);
      }
      else if (strneq(ptr, "0",   sizeof("1")-1) ||
            strneq(ptr, "off", sizeof("off")-1) ||
            strneq(ptr, "f",   sizeof("f")-1)) {
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
   else if (strneq(command, "help", sizeof("help")-1)) {
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
//   else if (strneq(command, "status", sizeof("status")-1)) {
//      // '?' Indicate the reason the target stopped.
//      reportLocation('T', TARGET_SIGNAL_TRAP);
//   }
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
#if NON_STOP_MODE
      sprintf(buff,"QStartNoAckMode+;qXfer:memory-map:read+;PacketSize=%X;QNonStop+;qXfer:features:read+",GdbPacket::MAX_MESSAGE-10);
#else
      sprintf(buff,"QStartNoAckMode+;qXfer:memory-map:read+;PacketSize=%X;qXfer:features:read+",GdbPacket::MAX_MESSAGE-10);
#endif
      gdbInOut->sendGdbString(buff);
   }
#if THREAD_MODE
   else if (strncmp(cmd, "qC", sizeof("qC")-1) == 0) { // set current thread
      gdbInOut->sendGdbString("QC1");
   }
   else if (strncmp(cmd, "qfThreadInfo", sizeof("qfThreadInfo")-1) == 0) {
      if (getTargetStatus() != T_NOCONNECTION) {
         gdbInOut->sendGdbString("m1");
      }
      else {
         gdbInOut->sendGdbString("l");
      }
   }
   else if (strncmp(cmd, "qsThreadInfo", sizeof("qsThreadInfo")-1) == 0) {
      gdbInOut->sendGdbString("l");
   }
   else if (strncmp(cmd, "qThreadExtraInfo", sizeof("qThreadExtraInfo")-1) == 0) {
      gdbInOut->sendGdbHexString(NULL, "Runnable");
   }
#endif
#if DUMMY_TRACE_MODE
   else if (strncmp(cmd, "qTStatus", sizeof("qTStatus")-1) == 0) {
      // No trace experiment running right now
      gdbInOut->sendGdbString("T0;tnotrun:0");
   }
#endif
#if NON_STOP_MODE
   else if (strncmp(cmd, "QNonStop", sizeof("QNonStop")-1) == 0) {
      log.print("QNonStop\n");
      gdbInOut->sendGdbString("OK");
   }
#endif
   else if (strncmp(cmd, "qAttached", sizeof("qAttached")-1) == 0) {
      log.print("qAttached\n");
      gdbInOut->sendGdbString("1"); // TODO - try this change from 0
   }
   else if (strncmp(cmd, "QStartNoAckMode", sizeof("QStartNoAckMode")-1) == 0) {
      log.print("QStartNoAckMode\n");
      gdbInOut->sendGdbString("OK");
      gdbInOut->setAckMode(false);
   }
   else if (strncmp(cmd, "qOffsets", sizeof("qOffsets")-1) == 0) {
      log.print("qOffsets\n");
      // No relocation done
      gdbInOut->sendGdbString("Text=0;Data=0;Bss=0");
   }
   else if (strncmp(cmd, "qXfer:memory-map:read::", sizeof("qXfer:memory-map:read::")-1) == 0) {
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
   else if (strncmp(cmd, "qXfer:features:read:target.xml:", sizeof("qXfer:features:read:target.xml:")-1) == 0) {
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
   else if (strncmp(cmd, "qXfer:features:read:targetRegs.xml:", sizeof("qXfer:features:read:targetRegs.xml:")-1) == 0) {
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
   else if (strncmp(cmd, "qRcmd,", sizeof("qRcmd,")-1) == 0) {
      // Monitor command
      doMonitorCommand(cmd);
   }
   else {
      log.print("Unrecognized command:\'%s\'\n", cmd);
      gdbInOut->sendGdbString("");
   }
   return BDM_RC_OK;
}

//! Handle 'v...' commands
//!
USBDM_ErrorCode GdbHandlerCommon::doVCommands(const GdbPacket *pkt) {
   LOGGING;
   int address, length;
   const char *cmd = pkt->buffer;

   if (strncmp(cmd, "vFlashErase", 11) == 0) {
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
   else if (strncmp(cmd, "vFlashWrite", 11) == 0) {
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
         bool newLine = true;
         while(size-->0) {
            flashImage->setValue(address, *vPtr);
            if (newLine)
               log.printq("\n%8.8X:", address);
            log.printq("%2.2X", (unsigned char)*vPtr);
            address++;
            vPtr++;
            newLine = (address & 0x0F) == 0;
         }
         reportGdbPrintf(M_INFO, "%X]\n", address-1);
         log.printq("\n");
         gdbInOut->sendGdbString("OK");
      }
   }
   else if (strncmp(cmd, "vFlashDone", 10) == 0) {
      // vFlashDone
      log.print("vFlashDone\n");
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
      }
      else {
         reportGdbPrintf(M_INFO, "Programming Flash Image skipped (empty image)\n");
         log.print("vFlashDone: Memory image empty, programming skipped\n");
      }
      gdbInOut->sendGdbString("OK");
   }
   else if (strncmp(cmd, "vCont", 5) == 0) {
#ifdef VCONT_SUPPORTED
      doVContCommands(pkt);
#else
      // Not yet supported
      gdbInOut->sendGdbString("");
#endif
   }
   else {
      log.print("Unrecognised command:\'%s\'\n", cmd);
      gdbInOut->sendGdbString("");
   }
   return BDM_RC_OK;
}

USBDM_ErrorCode GdbHandlerCommon::programImage(FlashImagePtr flashImage) {
   LOGGING;

   if (deviceData.getEraseOption() == DeviceData::eraseNone) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (deviceData.getSecurity() == SEC_SECURED) {
      return BDM_RC_ILLEGAL_PARAMS;
   }

   FlashProgrammerPtr flashProgrammer = FlashProgrammerFactory::createFlashProgrammer(bdmInterface);
   USBDM_ErrorCode rc = flashProgrammer->setDeviceData(deviceData);
   if (rc == BDM_RC_OK) {
      rc = flashProgrammer->programFlash(flashImage, 0, true);
   }
   if (rc != PROGRAMMING_RC_OK) {
      log.print("programImage() - failed, rc = %s\n", bdmInterface->getErrorString(rc));
   }
   return rc;
}

//!
//! Create XML description of current device memory map in GDB expected format
//!
//! @param buffer     - location to return address of static buffer initialised.
//! @param bufferSize - size of buffer data
//!
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
      MemoryRegionPtr pMemoryregion(deviceData.getMemoryRegion(memIndex));
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
         case MemFlexNVM:
         case MemFlexRAM:
            log.printq(" - FlexNVM/FlexNVM - Ignored\n");
            break;
         case MemEEPROM:
            log.printq(" - EEPROM - Ignored\n");
            break;
         case MemDFlash:
         case MemPFlash:
         case MemFLASH:
            start = memoryRange->start;
            size  = memoryRange->end - start + 1;
            log.printq(" - FLASH[0x%08X..0x%08X]\n", memoryRange->start, memoryRange->end);
            xmlPtr += sprintf(xmlPtr,
                           "   <memory type=\"flash\" start=\"0x%X\" length=\"0x%X\" > \n"
                           "      <property name=\"blocksize\">0x400</property> \n"
                           "   </memory>\n",
                           start, size);
            break;
         case MemIO:  // Treat I/O as RAM
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

/*!  Sets up the register description from device XML
 *
 */
bool GdbHandlerCommon::initRegisterDescription(void) {
   LOGGING_E;

   RegisterDescriptionConstPtr registerDescriptionPtr = deviceData.getRegisterDescription();
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

//! Read all registers from target into registerBuffer
//! Sets registerBufferSize to number of bytes valid in buffer
//!
//! @note values are returned in target byte order
//!
//! ToDo Handle errors
//!
USBDM_ErrorCode GdbHandlerCommon::readRegs(void) {
   LOGGING;

   reportGdbPrintf("Reading Registers\n");

   if (useFastRegisterRead) {
      // Read registers
      USBDM_ErrorCode rc = bdmInterface->readMultipleRegs(registerBuffer, 0, targetLastRegIndex);
      if (rc == BDM_RC_OK) {
         // OK
         registerBufferSize = 4*(targetLastRegIndex+1);
         return BDM_RC_OK;
      }
      if (rc == BDM_RC_TARGET_BUSY) {
         // Target running - dummy response
         registerBufferSize = 4*(targetLastRegIndex+1);
         memset(registerBuffer, 0, 4*(targetLastRegIndex+1));
         return BDM_RC_OK;
      }
      if (rc != BDM_RC_ILLEGAL_COMMAND) {
         // Unknown failure
         registerBufferSize = 0;
         return rc;
      }
      // Try the old method
      useFastRegisterRead = false;
      log.print("Switching to old register read method\n");
   }
   if (!useFastRegisterRead) {
      unsigned regNo;
      registerBufferSize = 0;
      unsigned char *buffPtr = registerBuffer;
      for (regNo = 0; regNo<=targetLastRegIndex; regNo++) {
         buffPtr += readReg(regNo, buffPtr);
      }
      registerBufferSize = buffPtr-registerBuffer;
   }
   return BDM_RC_OK;
}

//! Report register values to GDB
//! Reads registers from target if necessary
//!
//! @note values are returned in target byte order
//!
void GdbHandlerCommon::sendRegs(void) {
   LOGGING_E;
   USBDM_ErrorCode rc = BDM_RC_OK;
   if (registerBufferSize == 0) {
      rc = readRegs();
   }
   if ((rc != BDM_RC_OK) || (registerBufferSize == 0)) {
      log.error("Failed to read regs\n");
      gdbInOut->sendErrorMessage(GdbInOut::E_Fatal, "Register read failed");
      return;
   }
   gdbInOut->sendGdbHex(registerBuffer, registerBufferSize);
   registerBufferSize = 0;
}

//! Write target registers from string buffer containing hex chars
//!
//! @param ccPtr  - ptr to buffer
//!
//! @note characters are written in target byte order
//!
void GdbHandlerCommon::writeRegs(const char *ccPtr) {
   LOGGING;
   unsigned long regValue = 0;
   unsigned regNo;

   reportGdbPrintf("Writing Registers\n");
   for (regNo = 0; regNo<=targetLastRegIndex; regNo++) {
      if (!hexToInt32(ccPtr, &regValue))
         break;
      ccPtr += 8;
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

//! Convert a hex string to a series of byte values
//!
//! @param numBytes - number of bytes to convert
//! @param dataIn   - ptr to string of Hex chars (2 * numBytes)
//! @param dataOut  - ptr to output buffer (numBytes)
//!
//! @return true => ok conversion\n
//!         false => failed
//!
bool GdbHandlerCommon::convertFromHex(unsigned numBytes, const char *dataIn, unsigned char *dataOut) {
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

void GdbHandlerCommon::writeMemory(const char *ccPtr, uint32_t address, uint32_t numBytes) {
   unsigned char buff[1000];

   MemorySpace_t align = getAlignment(address, numBytes);
   reportGdbPrintf(GdbHandler::M_BORINGINFO, "Writing Memory[%X..%X], align = %s\n", address, address+numBytes-1, getMemSpaceName(align));
//   log.print("writeMemory(addr=%X, size=%X)\n", address, numBytes);
   convertFromHex(numBytes, ccPtr, buff);
   bdmInterface->writeMemory(align, numBytes, address, buff);
   gdbInOut->sendGdbString("OK");
}

/*
 *  Get cached value of PC
 *  Note: Assumes cache valid
 *
 *  @return 32-bit value
 */
uint32_t GdbHandlerCommon::getCachedPC() {
   return 0;
}

int GdbHandlerCommon::readReg(unsigned regNo, unsigned char *buffPtr) {
   return 0;
}

void GdbHandlerCommon::writeReg(unsigned regNo, unsigned long regValue) {
}

uint32_t GdbHandlerCommon::targetToNative32(uint32_t data) { return 0; }
uint16_t GdbHandlerCommon::targetToNative16(uint16_t data) { return 0; }
uint32_t GdbHandlerCommon::targetToBE32(uint32_t data)     { return 0; }
uint16_t GdbHandlerCommon::targetToBE16(uint16_t data)     { return 0; }

//! Handle 'vCont' commands
//!
USBDM_ErrorCode GdbHandlerCommon::doVContCommands(const GdbPacket *pkt) {
#ifdef VCONT_SUPPORTED
   LOGGING;
//   int address, length;
   const char *cmd = pkt->buffer;
   if (strncmp(cmd, "vCont?", sizeof("vCont?")) == 0) {
      gdbInOut->sendGdbString("vCont;c;s;t");
   }
   else if (strncmp(cmd, "vCont;c", sizeof("vCont;c")) == 0) {
      log.print("vCont;c - continue", cmd);
      gdbInOut->sendGdbString("OK");
   }
   else if (strncmp(cmd, "vCont;s", sizeof("vCont;s")) == 0) {
      log.print("vCont;s - step", cmd);
      gdbInOut->sendGdbString("OK");
   }
   else if (strncmp(cmd, "vCont;s", sizeof("vCont;t")) == 0) {
      log.print("vCont;t - halt", cmd);
      gdbInOut->sendGdbString("OK");
   }
   else {
      log.print("Unrecognized command:\'%s\'\n", cmd);
      gdbInOut->sendGdbString("OK");
   }
#endif
   return BDM_RC_OK;
}

//#define REPORT_LONG_LOCATION

void GdbHandlerCommon::reportLocation(char mode, int reason) {

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

//   log.print("doGdbCommand()\n");
   if (pkt->isBreak()) {
      if ((runState != running)) {
         log.print("Ignoring Break\n");
         reportGdbPrintf(M_INFO, "Ignoring Break as not running\n");
         return BDM_RC_OK;
      }
      runState = breaking;
      log.print("Breaking...\n");
      reportGdbPrintf(M_INFO, "Breaking...\n");
      targetBreakPending = true;
      USBDM_ErrorCode rc = bdmInterface->connect();
      if (rc != BDM_RC_OK) {
         return rc;
      }
      rc = bdmInterface->halt();
      if (rc != BDM_RC_OK) {
         return rc;
      }
      targetBreakPending = false;
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
      //      Reply: See [Stop Reply Packets] for the reply specifications.
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
      runState = running;
      registerBufferSize = 0;
//      gdbPollTarget();
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
      runState = stepping;
      stepTarget(bdmInterface->isMaskISR());
      registerBufferSize = 0;
//      gdbPollTarget();
      break;
   case 'Z' :
      // 'z type,addr,kind' - insert/remove breakpoint
      log.print("Z - Set breakpoint\n");
      if (sscanf(pkt->buffer, "Z%d,%x,%d", &type, &address, &kind) != 3) {
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
      if (sscanf(pkt->buffer, "z%d,%x,%d", &type, &address, &kind) != 3) {
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
         log.print("Failed to parse register\n");
         gdbInOut->sendErrorMessage(0x11);
         break;
      }
      {
         unsigned char buff[10];
         unsigned size = readReg(regNo, buff);
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
   case 'H' : // 'H c thread-id' Set thread (e.g. Hc0, Hc-1, Hg0)
      // Dummy response
      gdbInOut->sendGdbString("OK");
      break;
   case 'T' : // Thread status
      log.print("Thread Status\n");
      gdbInOut->sendGdbString("OK");
      break;
#endif
   case '?' : // '?' Indicate the reason the target stopped.
      reportLocation('T', TARGET_SIGNAL_TRAP);
      break;
   case 'k' : // Kill
      reportGdbPrintf(M_INFO, "Kill...\n");
      log.print("Kill...\n");
      gdbInOut->sendGdbString("OK");
      gdbInOut->finish();
      return BDM_RC_OK;
   case 'D' : // Detach
      reportGdbPrintf(M_INFO, "Detach...\n");
      log.print("Detach...\n");
      gdbInOut->sendGdbString("OK");
      continueTarget();
      gdbInOut->finish();
      return BDM_RC_OK;
      break;
   case 'q' : // q commands
   case 'Q' : // Q commands
      doQCommands(pkt);
      break;
   case 'v' : // v commands
      doVCommands(pkt);
      break;
   default : // Unrecognized command
      log.print("Unrecognized command:\'%s\'\n", pkt->buffer);
      gdbInOut->sendGdbString("");
      break;
   }
   return BDM_RC_OK;
}

/*
 *   Return target status without polling target
 *
 *   @return Target status
 */
GdbHandler::GdbTargetStatus GdbHandlerCommon::getGdbTargetStatus(void) {
   return gdbTargetStatus;
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

USBDM_ErrorCode GdbHandlerCommon::usbdmResetTarget(bool retry) {
   LOGGING_E;

   bdmInterface->reset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL));
   USBDM_ErrorCode rc = bdmInterface->connect();
   if ((rc != BDM_RC_OK) && retry) {
      log.print("USBDM_Connect() failed - retry\n");
      rc = usbdmResetTarget(false);
   }
   return rc;
}
