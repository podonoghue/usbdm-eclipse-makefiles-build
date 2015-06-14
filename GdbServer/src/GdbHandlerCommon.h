/*
 * GdbHandlerCommon.h
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBHANDLERCOMMON_H_
#define SRC_GDBHANDLERCOMMON_H_

#include <stdint.h>
#include "GdbHandler.h"
#include "FlashProgrammerFactory.h"
#include "GdbBreakpoints.h"
#include "DeviceInterface.h"

class GdbHandlerCommon: public GdbHandler {

public:
   GdbHandlerCommon(TargetType_t targetType, GdbInOut *gdbInOut, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, GdbBreakpoints *gdbBreakpoints, GdbCallback gdbCallBackPtr);
   virtual ~GdbHandlerCommon();

   virtual USBDM_ErrorCode      initialise();
   virtual USBDM_ErrorCode      doCommand(const GdbPacket *pkt);
   virtual GdbTargetStatus      getGdbTargetStatus(void);
   virtual GdbTargetStatus      pollTarget(void) = 0;
   virtual USBDM_ErrorCode      updateTarget() = 0;

protected:
   GdbBreakpoints             *gdbBreakpoints;

   USBDM_ErrorCode           (*gdbCallBackPtr)(const char *msg, GdbMessageLevel level, USBDM_ErrorCode rc);

   TargetType_t                targetType;
   GdbInOut                   *gdbInOut;
   BdmInterfacePtr             bdmInterface;
   DeviceInterfacePtr          deviceInterface;
   DeviceDataPtr        const &deviceData;
   bool                        useFastRegisterRead;
   RunState                    runState;
   GdbTargetStatus             gdbTargetStatus;
   DeviceData                  deviceOptions;          //!< Description of currently selected device
   FlashImagePtr               flashImage;             //!< Flash image for programming
   unsigned                    unsuccessfulPollCount;  //!< Count of unsuccessful polls of target
   bool                        targetBreakPending;
   uint32_t                    lastStoppedPC;

   static GdbHandlerCommon    *This;
   static void                errorLogger(const char *msg);

   void               clearAllBreakpoints(void)            { gdbBreakpoints->clearAllBreakpoints(); };
   void               checkAndAdjustBreakpointHalt(void)   { gdbBreakpoints->checkAndAdjustBreakpointHalt(); };
   void               notifyBreakpointsCleared()           { gdbBreakpoints->notifyBreakpointsCleared(); };
   void               activateBreakpoints()                { gdbBreakpoints->activateBreakpoints(); };
   void               deactivateBreakpoints()              { gdbBreakpoints->deactivateBreakpoints(); };
   bool               atBreakpoint(uint32_t address)       { return gdbBreakpoints->atBreakpoint(address); };
   USBDM_ErrorCode    initBreakpoints();
   int                insertBreakpoint(GdbBreakpoints::BreakType type, uint32_t address, unsigned size) {
      return gdbBreakpoints->insertBreakpoint(type, address, size);
   }
   int                removeBreakpoint(GdbBreakpoints::BreakType type, uint32_t address, unsigned size) {
      return gdbBreakpoints->removeBreakpoint(type, address, size);
   }
   virtual USBDM_ErrorCode    usbdmResetTarget(bool retry);

   virtual USBDM_ErrorCode    resetTarget(TargetMode_t mode = (TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
   virtual USBDM_ErrorCode    stepTarget(bool disableInterrupts);
   virtual void               continueTarget(void);
   virtual USBDM_ErrorCode    programImage(FlashImagePtr flashImage);
   virtual void               maskInterrupts(bool disableInterrupts) = 0;
   virtual uint32_t           getCachedPC();
   virtual const char        *getCachedPcAsString();
   virtual USBDM_ErrorCode    readRegs(void);
   virtual int                readReg(unsigned regNo, unsigned char *buffPtr);
   virtual void               sendRegs(void);
   virtual void               writeReg(unsigned regNo, unsigned long regValue);
   virtual void               writeRegs(const char *ccPtr);
   virtual void               readMemory(uint32_t address, uint32_t numBytes);
   virtual void               writeMemory(const char *ccPtr, uint32_t address, uint32_t numBytes);
   bool                       convertFromHex(unsigned numBytes, const char *dataIn, unsigned char *dataOut);
   virtual bool               isValidRegister(unsigned regNo) = 0;

   virtual bool               initRegisterDescription(void);
   virtual void               reportLocation(char mode, int reason);
   virtual bool               checkHostedBreak(uint32_t currentPC) = 0;
           unsigned           getConnectionTimeout();
   virtual USBDM_ErrorCode    writePC(unsigned long value) = 0;
   virtual USBDM_ErrorCode    readPC(unsigned long *value) = 0;
   virtual USBDM_ErrorCode    writeSP(unsigned long value) = 0;

   USBDM_ErrorCode            doReadCommand(char *command);
   USBDM_ErrorCode            doMonitorCommand(const char *cmd);
   USBDM_ErrorCode            doQCommands(const GdbPacket *pkt);
   USBDM_ErrorCode            doVCommands(const GdbPacket *pkt);
   USBDM_ErrorCode            doVContCommands(const GdbPacket *pkt);

   USBDM_ErrorCode            reportGdbPrintf(GdbMessageLevel level, USBDM_ErrorCode rc, const char *format, ...);
   USBDM_ErrorCode            reportGdbPrintf(const char *format, ...);
   USBDM_ErrorCode            reportGdbPrintf(GdbMessageLevel level, const char *format, ...);

   void createMemoryMapXML(const char **buffer, unsigned *bufferSize);

   static USBDM_ErrorCode dummyCallback(const char *msg, GdbMessageLevel level, USBDM_ErrorCode rc);

   uint32_t get32bitBE(uint8_t buff[]);
   uint32_t get32bitLE(uint8_t buff[]);

   bool hexToInt(char ch, int *value);
   bool hexToInt32(const char *ch, unsigned long *value);
   long hexToInt16(const char *ch, unsigned long *value);
   long hexToInt8(const char *ch, unsigned long *value);
   void reportStatusToGdb(const char *s, int size);

   virtual uint16_t        targetToNative16(uint16_t data) = 0;
   virtual uint32_t        targetToNative32(uint32_t data) = 0;
   virtual uint16_t        targetToBE16(uint16_t data) = 0;
   virtual uint32_t        targetToBE32(uint32_t data) = 0;
   virtual uint32_t        getTarget32Bits(uint8_t buff[], int offset) = 0;

   unsigned char registerBuffer[1000];
   unsigned registerBufferSize;       // Number of bytes valid in buffer, 0 => register cache invalid

   char     targetRegsXML[6000];
   unsigned targetRegsXMLSize;
   unsigned targetLastRegIndex;

   void     sendXML(unsigned size, unsigned offset, const char *buffer, unsigned bufferSize);
   bool     streq(const char *s1, const char *s2);
   bool     strneq(const char *s1, const char *s2, int length);

};

#endif /* SRC_GDBHANDLERCOMMON_H_ */
