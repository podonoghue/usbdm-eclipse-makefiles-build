/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_CFV1.h"
#include "PluginHelper.h"

ModuleInfo BdmInterface_CFV1::moduleInfo;

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
size_t CPP_DLL_EXPORT createPluginInstance(BdmInterface_CFV1 *pp) {
   return TcreatePluginInstance<BdmInterface_CFV1>(pp);
}
