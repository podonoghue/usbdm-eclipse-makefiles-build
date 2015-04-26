/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_RS08.h"


BdmInterface_RS08::BdmInterface_RS08() : BdmInterfaceCommon(T_RS08) {
}

BdmInterface_RS08::~BdmInterface_RS08() {
}

USBDM_ErrorCode BdmInterface_RS08::writePC(unsigned long regValue) {
   return USBDM_WriteReg(RS08_RegCCR_PC, regValue);
};

USBDM_ErrorCode BdmInterface_RS08::readPC(unsigned long *regValue) {
   return USBDM_ReadReg(RS08_RegCCR_PC, regValue);
};

/*
 * Create the plugin instance
 */
extern "C"
BdmInterface* __declspec(dllexport) createPluginInstance() {
   return new BdmInterface_RS08();
}
