/*
 * BdmInterfaceARM.h
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACE_ARM_H_
#define SRC_BDMINTERFACE_ARM_H_

#include "BdmInterfaceCommon.h"

class BdmInterface_JTAG : public BdmInterfaceCommon {

private:
   static ModuleInfo moduleInfo;

public:
   BdmInterface_JTAG();
   virtual ~BdmInterface_JTAG();
   
   virtual ModuleInfo      &getModuleInfo() const override { return moduleInfo; }
};

#endif /* SRC_BDMINTERFACE_ARM_H_ */
