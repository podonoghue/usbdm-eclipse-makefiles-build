/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_S12Z.h"
#include "PluginHelper.h"

BdmInterface_S12Z::BdmInterface_S12Z() : BdmInterfaceCommon(T_S12Z) {
}

BdmInterface_S12Z::~BdmInterface_S12Z() {
}

USBDM_ErrorCode BdmInterface_S12Z::writePC(unsigned long regValue) {
   return USBDM_WriteReg(S12Z_RegPC, regValue);
};

USBDM_ErrorCode BdmInterface_S12Z::readPC(unsigned long *regValue) {
   return USBDM_ReadReg(S12Z_RegPC, regValue);
};

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(void *pp) {
   return TcreatePluginInstance<BdmInterface_S12Z>(pp);
}
