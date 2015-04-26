/*
 * BdmInterfaceARM.h
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACE_CFV1_H_
#define SRC_BDMINTERFACE_CFV1_H_

#include "BdmInterfaceCommon.h"

class BdmInterface_CFV1: public BdmInterfaceCommon {

public:
   BdmInterface_CFV1();
   virtual ~BdmInterface_CFV1();

   virtual USBDM_ErrorCode            writePC(unsigned long regValue);
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue);
};

#endif /* SRC_BDMINTERFACE_CFV1_H_ */
