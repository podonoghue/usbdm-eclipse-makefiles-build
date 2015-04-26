/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_HCS12.h"


BdmInterface_HCS12::BdmInterface_HCS12() : BdmInterfaceCommon(T_HCS12) {
}

BdmInterface_HCS12::~BdmInterface_HCS12() {
}

USBDM_ErrorCode BdmInterface_HCS12::writePC(unsigned long regValue) {
   return USBDM_WriteReg(HCS12_RegPC, regValue);
};

USBDM_ErrorCode BdmInterface_HCS12::readPC(unsigned long *regValue) {
   return USBDM_ReadReg(HCS12_RegPC, regValue);
};

/*
 * Create the plugin instance
 */
extern "C"
BdmInterface* __declspec(dllexport) createPluginInstance() {
   return new BdmInterface_HCS12();
}
