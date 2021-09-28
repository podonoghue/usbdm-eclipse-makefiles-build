/*
 * GdbHandlerARM.h
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBHANDLER_ARM_H_
#define SRC_GDBHANDLER_ARM_H_

#include "GdbHandlerCommon.h"

class GdbHandler_ARM: public GdbHandlerCommon {
protected:
   bool  isKinetisDevice;

   USBDM_ErrorCode configureMDM_AP();

public:
   GdbHandler_ARM(
         GdbHandlerOwner     &owner,
         GdbInOut            *gdbInOut,
         BdmInterfacePtr      bdmInterface,
         DeviceInterfacePtr   deviceInterface,
         IGdbTty              *tty);
   virtual ~GdbHandler_ARM();
   virtual USBDM_ErrorCode   initialise() override;
   virtual GdbTargetStatus   pollTarget(void) override;
   virtual USBDM_ErrorCode   updateTarget() override;

protected:
   virtual USBDM_ErrorCode   resetTarget(DeviceData::ResetMethod=DeviceData::resetTargetDefault) override;
   virtual USBDM_ErrorCode   continueTarget(void) override;
   virtual USBDM_ErrorCode   haltTarget() override;
   virtual void              maskInterrupts(bool disableInterrupts) override;
   virtual void              writeReg(unsigned regNo, unsigned long regValue) override;

   virtual bool              initRegisterDescription(void) override;

   virtual uint32_t          getCachedPC() override;
   /**
    * Indicates if regNo identifies a valid target register
    *
    * @param regNo   GDB register number (index)
    *
    * @return true  => Valid register index
    * @return false => Invalid register index
    */
   virtual bool              isValidRegister(unsigned regNo) override;
   virtual USBDM_ErrorCode   readReg(unsigned regNo, uint8_t *&buffPtr) override;

   bool                      atMemoryBreakpoint();
   GdbTargetStatus           handleHalted();
   USBDM_ErrorCode           configureKinetisMDM_AP(bool resume);
   GdbTargetStatus           handleHostedBreak();
   virtual bool              checkHostedBreak(uint32_t currentPC);

   USBDM_ErrorCode           armReadMemoryWord(uint32_t, uint32_t &data);
   virtual GdbTargetStatus   getTargetStatus() override;
   /**
    * Convert a 16-bit number between native <=> target endian
    *
    * @param data Value to convert
    *
    * @return Converted value
    */
   virtual uint16_t          targetToFromNative16(uint16_t data) override;
   /**
    * Convert a 32-bit number between native <=> target endian
    *
    * @param data Value to convert
    *
    * @return Converted value
    */
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
   USBDM_ErrorCode           readR0(unsigned long *value);
   USBDM_ErrorCode           readR1(unsigned long *value);
   virtual USBDM_ErrorCode   writeSP(unsigned long value) override;
   /**
    * Get register values of important registers for stop reporting etc.
    *
    * @return Static string describing values.
    */
   virtual const char *getImportantRegisters() override;

   uint32_t          getCachedRegister(ARM_Registers_t reg);

   virtual void debug_print_regs() override;
};

GdbHandler *createARMGdbHandler(
      GdbHandler::GdbHandlerOwner    &owner,
      GdbInOut                       *gdbInOut,
      BdmInterfacePtr                 bdmInterface,
      DeviceInterfacePtr              deviceInterface,
      IGdbTty                        *tty) ;

#endif /* SRC_GDBHANDLER_ARM_H_ */
