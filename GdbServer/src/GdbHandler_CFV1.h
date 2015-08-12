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
         GdbInOut            *gdbInOut,
         BdmInterfacePtr      bdmInterface,
         DeviceInterfacePtr   deviceInterface,
         GdbCallback          gdbCallBackPtr,
         IGdbTty              *tty);
   virtual ~GdbHandler_CFV1();


protected:
   USBDM_ErrorCode           resetTarget(TargetMode_t mode);
   void                      maskInterrupts(bool disableInterrupts);
   virtual void              continueTarget(void);
   virtual void              writeReg(unsigned regNo, unsigned long regValue);

   virtual USBDM_ErrorCode   initialise();
   virtual bool              atMemoryBreakpoint();
   virtual bool              initRegisterDescription(void);
   virtual void              reportLocation(char mode, int reason);
   virtual GdbTargetStatus   pollTarget(void);
   GdbTargetStatus           handleHalted();
   GdbTargetStatus           handleHostedBreak();
   bool                      checkHostedBreak(uint32_t currentPC);

   virtual uint32_t          getCachedPC();
   virtual bool              isValidRegister(unsigned regNo);
   virtual int               readReg(unsigned regNo, char *buffPtr);

   GdbTargetStatus           getTargetStatus();

   virtual uint16_t          targetToNative16(uint16_t data);
   virtual uint32_t          targetToNative32(uint32_t data);
   virtual uint16_t          targetToBE16(uint16_t data);
   virtual uint32_t          targetToBE32(uint32_t data);
   virtual uint32_t          getTarget32Bits(uint8_t buff[], int offset);

   virtual USBDM_ErrorCode   writePC(unsigned long value);
   virtual USBDM_ErrorCode   readPC(unsigned long *value);
   virtual USBDM_ErrorCode   writeSP(unsigned long value);
   virtual USBDM_ErrorCode   updateTarget();
};

GdbHandler *createCFV1GdbHandler(GdbInOut *gdbInOut, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, GdbHandler::GdbCallback gdbCallBackPtr, IGdbTty *tty) ;

#endif /* SRC_GDBHANDLER_CFV1_H_ */
