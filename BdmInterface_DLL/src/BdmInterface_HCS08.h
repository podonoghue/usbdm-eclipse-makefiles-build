/*
 * BdmInterfaceARM.h
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACE_HCS08_H_
#define SRC_BDMINTERFACE_HCS08_H_

#include "BdmInterfaceCommon.h"

class BdmInterface_HCS08: public BdmInterfaceCommon {

public:
   BdmInterface_HCS08();
   virtual ~BdmInterface_HCS08();

   virtual USBDM_ErrorCode            writePC(unsigned long regValue);
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue);
};

#endif /* SRC_BDMINTERFACE_HCS08_H_ */
