/*
 * GdbHandlerCommon.h
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBHANDLERCOMMON_H_
#define SRC_GDBHANDLERCOMMON_H_

#include <stdint.h>
#include "Utils.h"
//#include "DeviceTclInterface.h"
#include "UsbdmTclInterpreterFactory.h"
#include "GdbHandler.h"
#include "FlashProgrammerFactory.h"
#include "GdbBreakpoints.h"
#include "DeviceInterface.h"
#include "IGdbTty.h"

#define NON_STOP_SUPPORTED 1
#define DUMMY_TRACE_MODE   0
#define THREAD_MODE        1

class GdbHandlerCommon: public GdbHandler {

public:
   GdbHandlerCommon(
         TargetType_t              targetType,
         GdbHandlerOwner          &owner,
         GdbInOut                 *gdbInOut,
         BdmInterfacePtr           bdmInterface,
         DeviceInterfacePtr        deviceInterface,
         GdbBreakpoints           *gdbBreakpoints,
         IGdbTty                  *tty,
         DeviceData::ResetMethod   defaultResetMethod);

   virtual ~GdbHandlerCommon();

   virtual USBDM_ErrorCode       initialise() override;
   virtual USBDM_ErrorCode       doCommand(const GdbPacket *pkt) override;

   virtual GdbTargetStatus       pollTarget(void) override = 0;
   virtual USBDM_ErrorCode       updateTarget() override = 0;

   virtual USBDM_ErrorCode       resetTarget(DeviceData::ResetMethod resetMethod=DeviceData::resetTargetDefault) override;
   virtual USBDM_ErrorCode       stepTarget(bool disableInterrupts) override;
   virtual USBDM_ErrorCode       continueTarget() override;
   virtual USBDM_ErrorCode       haltTarget() override;
   virtual USBDM_ErrorCode       notifyGdb() override;

protected:
   TargetType_t                    targetType;
   GdbHandlerOwner                &owner;
   GdbInOut                       *gdbInOut;
   BdmInterfacePtr                 bdmInterface;
   DeviceInterfacePtr              deviceInterface;
   GdbBreakpoints                 *gdbBreakpoints;
   IGdbTty                        *tty;
   const DeviceData::ResetMethod   defaultResetMethod;

   int                             currentThread;            //!< -1 => all threads?
   UsbdmTclInterperPtr             tclInterpreter;           //!< TCL interpreter
   bool                            initBreakpointsDone;
   bool                            programmingDone;

   DeviceDataPtr            const &deviceData;
   bool                            useFastRegisterRead;
   RunState                        runState;
   bool                            vStoppedAvailable;      ///< Used to indicate that unsent stop information is available
   DeviceData                      deviceOptions;          //!< Description of currently selected device
   FlashImagePtr                   flashImage;             //!< Flash image for programming
   unsigned                        unsuccessfulPollCount;  //!< Count of unsuccessful polls of target
   bool                            forceTargetHalt;        //!< Used to retry halting target when polling
   uint32_t                        lastStoppedPC;
   bool                            nonStopMode;
   const char                     *haltNotice;     ///< Response for vStopped etc which describes stop reason

   static GdbHandlerCommon         *This;
   static void                     errorLogger(const char *msg);

   /**
    * Get register values of important registers for stop reporting etc.
    *
    * @return Static string describing values.
    */
   virtual const char *getImportantRegisters() = 0;

   void               clearAllBreakpoints(void)             { gdbBreakpoints->clearAllBreakpoints(); };
   void               checkAndAdjustBreakpointHalt(void)    { gdbBreakpoints->checkAndAdjustBreakpointHalt(); };
   void               notifyBreakpointsCleared()            { gdbBreakpoints->notifyBreakpointsMadeInactive(); };
   void               activateBreakpoints()                 { gdbBreakpoints->activateBreakpoints(); };
   void               deactivateBreakpoints()               { gdbBreakpoints->deactivateBreakpoints(); };
   bool               atBreakpoint(uint32_t address)        { return gdbBreakpoints->atBreakpoint(address); };
   USBDM_ErrorCode    initBreakpoints();
   int                insertBreakpoint(GdbBreakpoints::BreakType type, uint32_t address, unsigned size) {
      if (!initBreakpointsDone) {
         initBreakpoints();
      }
      return gdbBreakpoints->insertBreakpoint(type, address, size);
   }
   int                removeBreakpoint(GdbBreakpoints::BreakType type, uint32_t address, unsigned size) {
      if (!initBreakpointsDone) {
         initBreakpoints();
      }
      return gdbBreakpoints->removeBreakpoint(type, address, size);
   }
   UsbdmTclInterperPtr   getTclInterface();
   USBDM_ErrorCode       runTCLCommand(const char *command);

   virtual USBDM_ErrorCode       programImage(FlashImagePtr flashImage);
   virtual void                  maskInterrupts(bool disableInterrupts) = 0;
   virtual uint32_t              getCachedPC() = 0;
   virtual const char           *getCachedPcAsString();
   /**
    * Read all registers from target into registerBuffer
    * Sets registerBufferSize to number of bytes valid in buffer
    *
    * @note values are written in target byte order
    */
   virtual USBDM_ErrorCode       readRegs(void);
   virtual USBDM_ErrorCode       readReg(unsigned regNo, uint8_t *&buffPtr) = 0;
   /**
    * Send register values to GDB
    * Reads registers from target if necessary
    *
    * @note values are sent to GDB in target byte order
    */
   virtual void                  sendRegs(void);
   virtual void                  writeReg(unsigned regNo, unsigned long regValue) = 0;
   /**
    * Write target register set from buffer containing ASCII-HEX chars (received from GDB)
    *
    * @param buff Buffer containing register values
    *
    * @note Buffer is in target byte order
    */
   virtual void                  writeRegs(const char *ccPtr);
   /**
    * Read bytes from target memory and send to GDB as packet
    *
    * @param address    Memory address to read from
    * @param numBytes   NUmber of bytes to transfer
    */
   virtual void                  readMemory(uint32_t address, uint32_t numBytes);
   /**
    * Write value to target memory from GDB format buffer
    *
    * @param ccPtr      Values to write (buffer)
    * @param address    Memory address
    * @param numBytes   Number of bytyes to write
    */
   virtual void                  writeMemory(const char *ccPtr, uint32_t address, uint32_t numBytes);
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
   bool convertFromHex(unsigned numBytes, const char *dataIn, uint8_t *dataOut);
   /**
    * Convert a series of byte values into a ASCII-HEX string
    *
    * @param[in]  numBytes - number of bytes to convert
    * @param[in]  dataIn   - Pointer to string of byte values (numBytes)
    * @param[out] dataOut  - Pointer to output buffer (2 * numBytes) suitable to send to GDB
    */
   void convertToHex(unsigned numBytes, const uint8_t *dataIn, char *dataOut);
   /**
    * Indicates if regNo identifies a valid target register
    *
    * @param regNo   GDB register number (index)
    *
    * @return true  => Valid register index
    * @return false => Invalid register index
    */
   virtual bool                  isValidRegister(unsigned regNo) = 0;

   /**
    * Sets up the register description from device XML
    */
   virtual bool                  initRegisterDescription(void);
   /**
    * Send notification that the target has stopped.
    * Only applicable if in non-stop mode
    */
   void notifyStop();
   /**
    *
    * @param mode          Indicates the reply mode e.g. S T etc
    * @param signal        Signal value e.g. TARGET_SIGNAL_TRAP TARGET_SIGNAL_INT
    */
   virtual void                  reportHalt(char mode, int signal);
   virtual void                  sendLocation();
   virtual bool                  checkHostedBreak(uint32_t currentPC) = 0;
           unsigned              getConnectionTimeout();
   virtual USBDM_ErrorCode       writePC(unsigned long value) = 0;
   virtual USBDM_ErrorCode       readPC(unsigned long *value) = 0;
   virtual USBDM_ErrorCode       writeSP(unsigned long value) = 0;

   USBDM_ErrorCode               doReadCommand(char *command);
   USBDM_ErrorCode               doMonitorCommand(const char *cmd);
   USBDM_ErrorCode               doQCommands(const GdbPacket *pkt);
   USBDM_ErrorCode               doVCommands(const GdbPacket *pkt);
   USBDM_ErrorCode               doVContCommands(const GdbPacket *pkt);

   USBDM_ErrorCode               reportGdbPrintf(GdbMessageLevel level, USBDM_ErrorCode rc, const char *format, ...);
   USBDM_ErrorCode               reportGdbPrintf(const char *format, ...);
   USBDM_ErrorCode               reportGdbPrintf(GdbMessageLevel level, const char *format, ...);

   /**
    * Get reset method to use
    *
    * @return reset method
    */
   DeviceData::ResetMethod getResetMethod();

   void createMemoryMapXML(const char **buffer, unsigned *bufferSize);

   static USBDM_ErrorCode dummyCallback(const char *msg, GdbMessageLevel level, USBDM_ErrorCode rc);

   /**
    * Extract a 32-bit big-endian value from a byte array
    *
    * @param buff Array containing value
    *
    * @return 32-bit value from 4-bytes of the array
    */
   static uint32_t get32bitBE(uint8_t buff[]);
   /**
    * Extract a 32-bit little-endian value from a byte array
    *
    * @param buff Array containing value
    *
    * @return 32-bit value from 4-bytes of the array
    */
   static uint32_t get32bitLE(uint8_t buff[]);
   /**
    * Convert a ASCII-HEX character to integer
    *
    * @param[in]  ch      Character to convert ('0'-'9', 'a'-'f' or 'A'-'F')
    * @param[out] value   Value in range 0-15
    *
    * @return true  => successful conversion
    * @return false => unsuccessful conversion (invalid character found)
    */
   static bool hexToInt(char ch, int *value);
   /**
    * Convert ASCII-HEX 8-character string to integer
    *
    * @param[in]  ch      Characters to convert ('0'-'9', 'a'-'f' or 'A'-'F')
    * @param[out] value   32-bit value
    *
    * @return true  => successful conversion
    * @return false => unsuccessful conversion (invalid character found)
    */
   static bool hexToInt32(const char *ch, unsigned long *value);
   /**
    * Convert ASCII-HEX 4-character string to integer
    *
    * @param[in]  ch      Characters to convert ('0'-'9', 'a'-'f' or 'A'-'F')
    * @param[out] value   16-bit value
    *
    * @return true  => successful conversion
    * @return false => unsuccessful conversion (invalid character found)
    */
   static bool hexToInt16(const char *ch, unsigned long *value);
   /**
    * Convert ASCII-HEX 2-character string to integer
    *
    * @param[in]  ch      Characters to convert ('0'-'9', 'a'-'f' or 'A'-'F')
    * @param[out] value   8-bit value
    *
    * @return true  => successful conversion
    * @return false => unsuccessful conversion (invalid character found)
    */
   static bool hexToInt8(const char *ch, unsigned long *value);

   void reportStatusToGdb(const char *s, int size);

   /**
    * Convert a 16-bit number between native <=> target endian
    *
    * @param data Value to convert
    *
    * @return Converted value
    */
   virtual uint16_t        targetToFromNative16(uint16_t data) = 0;
   /**
    * Convert a 32-bit number between native <=> target endian
    *
    * @param data Value to convert
    *
    * @return Converted value
    */
   virtual uint32_t        targetToFromNative32(uint32_t data) = 0;

   virtual uint16_t        targetToBE16(uint16_t data) = 0;
   virtual uint32_t        targetToBE32(uint32_t data) = 0;
   /**
    * Extract a 32-bit value from byte buffer in target byte order
    *
    * @param[in]  buff    Buffer to read value from
    * @param[out] value   32-bit value from buffer
    */
   virtual void              extractTarget32Bits(uint8_t buff[], uint32_t &value) = 0;
   /**
    * Encode a 32-bit value into byte buffer in target byte order
    *
    * @param[in]  value   32-bit value to enter
    * @param[out] buff    Buffer to add value to
    */
   virtual void              encodeTarget32Bits(uint32_t value, uint8_t buff[]) = 0;

   virtual GdbTargetStatus getTargetStatus() = 0;

   /**
    * Contains register values read from target.
    * The values are bytes in target-endian order as expected by GDB.
    */
   uint8_t registerBuffer[1000];
   /**
    * Number of bytes valid in registerBuffer, 0 => register cache invalid
    */
   unsigned registerBufferSize;

   char     targetRegsXML[6000];
   unsigned targetRegsXMLSize;
   unsigned targetLastRegIndex;

   void     sendXML(unsigned size, unsigned offset, const char *buffer, unsigned bufferSize);

   virtual void debug_print_regs() = 0;
};

#endif /* SRC_GDBHANDLERCOMMON_H_ */
