/*
 * BdmInterfaceDSC.h
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACE_DSC_H_
#define SRC_BDMINTERFACE_DSC_H_

#include "BdmInterfaceCommon.h"

class BdmInterface_DSC : public BdmInterfaceCommon {

private:
   static ModuleInfo moduleInfo;

public:
   BdmInterface_DSC();
   virtual ~BdmInterface_DSC();

   virtual USBDM_ErrorCode targetConnectWithRetry(USBDMStatus_t *usbdmStatus, RetryMode retryMode);

   virtual USBDM_ErrorCode reset(TargetMode_t mode);
   virtual USBDM_ErrorCode connect();
   virtual USBDM_ErrorCode halt();
   virtual USBDM_ErrorCode go();
   virtual USBDM_ErrorCode step();

   virtual USBDM_ErrorCode writeReg(unsigned int reg, unsigned long value);
   virtual USBDM_ErrorCode readReg(unsigned int reg, unsigned long *value);
   virtual USBDM_ErrorCode readMemory(unsigned memorySpace, unsigned byteCount, unsigned address, unsigned char *data);
   virtual USBDM_ErrorCode writeMemory(unsigned memorySpace, unsigned byteCount, unsigned address, unsigned const char *data);
   virtual USBDM_ErrorCode writePC(unsigned long regValue);
   virtual USBDM_ErrorCode readPC(unsigned long *regValue);

   virtual USBDM_ErrorCode getIdcode(unsigned int *regValue);
   virtual USBDM_ErrorCode getStatus(unsigned int *status);
   
   virtual ModuleInfo      &getModuleInfo() const override { return moduleInfo; }
};

#endif /* SRC_BDMINTERFACE_DSC_H_ */
