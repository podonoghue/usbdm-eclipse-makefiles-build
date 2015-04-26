/*
 * BdmInterfaceARM.h
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACE_S12Z_H_
#define SRC_BDMINTERFACE_S12Z_H_

#include "BdmInterfaceCommon.h"

class BdmInterface_S12Z: public BdmInterfaceCommon {

public:
   BdmInterface_S12Z();
   virtual ~BdmInterface_S12Z();

   virtual USBDM_ErrorCode            writePC(unsigned long regValue);
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue);
};

#endif /* SRC_BDMINTERFACE_S12Z_H_ */
