/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_HCS08.h"
#include "PluginHelper.h"

BdmInterface_HCS08::BdmInterface_HCS08() : BdmInterfaceCommon(T_HCS08) {
}

BdmInterface_HCS08::~BdmInterface_HCS08() {
}

USBDM_ErrorCode BdmInterface_HCS08::writePC(unsigned long regValue) {
   return USBDM_WriteReg(HCS08_RegPC, regValue);
};

USBDM_ErrorCode BdmInterface_HCS08::readPC(unsigned long *regValue) {
   return USBDM_ReadReg(HCS08_RegPC, regValue);
};

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(BdmInterface_HCS08 *pp) {
   return TcreatePluginInstance<BdmInterface_HCS08>(pp);
}
