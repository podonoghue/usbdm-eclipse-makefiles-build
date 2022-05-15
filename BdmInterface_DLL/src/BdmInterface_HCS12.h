/*
 * BdmInterfaceARM.h
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACE_HCS12_H_
#define SRC_BDMINTERFACE_HCS12_H_

#include "BdmInterfaceCommon.h"

class BdmInterface_HCS12: public BdmInterfaceCommon {

private:
   static ModuleInfo moduleInfo;

public:
   BdmInterface_HCS12();
   virtual ~BdmInterface_HCS12();

   virtual USBDM_ErrorCode            writePC(unsigned long regValue);
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue);
   
   virtual ModuleInfo      &getModuleInfo() const override { return moduleInfo; }
};

#endif /* SRC_BDMINTERFACE_HCS12_H_ */
