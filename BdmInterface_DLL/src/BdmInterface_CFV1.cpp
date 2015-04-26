/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_CFV1.h"


BdmInterface_CFV1::BdmInterface_CFV1() : BdmInterfaceCommon(T_CFV1) {
}

BdmInterface_CFV1::~BdmInterface_CFV1() {
}

USBDM_ErrorCode BdmInterface_CFV1::writePC(unsigned long regValue) {
   return USBDM_WriteCReg(CFV1_CRegPC, regValue);
};

USBDM_ErrorCode BdmInterface_CFV1::readPC(unsigned long *regValue) {
   return USBDM_ReadCReg(CFV1_CRegPC, regValue);
};

/*
 * Create the plugin instance
 */
extern "C"
BdmInterface* __declspec(dllexport) createPluginInstance() {
   return new BdmInterface_CFV1();
}
