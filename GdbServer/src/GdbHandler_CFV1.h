/*
 * GdbHandlerCFV1.h
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBHANDLER_CFV1_H_
#define SRC_GDBHANDLER_CFV1_H_

#include "GdbHandlerCommon.h"

class GdbHandler_CFV1: public GdbHandlerCommon {
public:
   GdbHandler_CFV1(
         GdbHandlerOwner     &owner,
         GdbInOut            *gdbInOut,
         BdmInterfacePtr      bdmInterface,
         DeviceInterfacePtr   deviceInterface,
         IGdbTty              *tty);
   virtual ~GdbHandler_CFV1();

protected:
   virtual USBDM_ErrorCode   resetTarget(DeviceData::ResetMethod=DeviceData::resetTargetDefault) override;
   virtual USBDM_ErrorCode   continueTarget(void) override;
   virtual void              maskInterrupts(bool disableInterrupts) override;
   virtual void              writeReg(unsigned regNo, unsigned long regValue) override;

   virtual USBDM_ErrorCode   initialise() override;
   bool                      atMemoryBreakpoint();
   virtual bool              initRegisterDescription(void) override;
   virtual void              reportHalt(char mode, int signal) override;
   virtual GdbTargetStatus   pollTarget(void) override;
   GdbTargetStatus           handleHalted();
   GdbTargetStatus           handleHostedBreak();
   bool                      checkHostedBreak(uint32_t currentPC);

   virtual uint32_t          getCachedPC() override;
   virtual bool              isValidRegister(unsigned regNo) override;
   USBDM_ErrorCode           readReg(unsigned regNo, uint8_t *&buffPtr);

   GdbTargetStatus           getTargetStatus() override;

   virtual uint16_t          targetToFromNative16(uint16_t data) override;
   virtual uint32_t          targetToFromNative32(uint32_t data) override;
   virtual uint16_t          targetToBE16(uint16_t data) override;
   virtual uint32_t          targetToBE32(uint32_t data) override;
   /**
    * Extract a 32-bit value from byte buffer in target byte order
    *
    * @param[in]  buff    Buffer to read value from
    * @param[out] value   32-bit value from buffer
    */
   virtual void              extractTarget32Bits(uint8_t buff[], uint32_t &value) override;
   /**
    * Encode a 32-bit value into byte buffer in target byte order
    *
    * @param[in]  value   32-bit value to enter
    * @param[out] buff    Buffer to add value to
    */
   virtual void              encodeTarget32Bits(uint32_t value, uint8_t buff[]) override;

   virtual USBDM_ErrorCode   writePC(unsigned long value) override;
   virtual USBDM_ErrorCode   readPC(unsigned long *value) override;
   virtual USBDM_ErrorCode   writeSP(unsigned long value) override;
   virtual USBDM_ErrorCode   updateTarget() override;
   /**
    * Get register values of important registers for stop reporting etc.
    *
    * @return Static string describing values.
    */
   virtual const char *getImportantRegisters() override;

   virtual void debug_print_regs() override;
};

GdbHandler *createCFV1GdbHandler(
      GdbHandler::GdbHandlerOwner    &owner,
      GdbInOut                       *gdbInOut,
      BdmInterfacePtr                 bdmInterface,
      DeviceInterfacePtr              deviceInterface,
      IGdbTty                        *tty) ;

#endif /* SRC_GDBHANDLER_CFV1_H_ */
