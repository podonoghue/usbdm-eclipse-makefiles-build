/*
 * BdmInterfaceARM.h
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACE_RS08_H_
#define SRC_BDMINTERFACE_RS08_H_

#include "BdmInterfaceCommon.h"

class BdmInterface_RS08: public BdmInterfaceCommon {

public:
   BdmInterface_RS08();
   virtual ~BdmInterface_RS08();

   virtual USBDM_ErrorCode            writePC(unsigned long regValue);
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue);
};

#endif /* SRC_BDMINTERFACE_RS08_H_ */
