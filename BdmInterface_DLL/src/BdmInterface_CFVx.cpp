/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_CFVx.h"
#include "PluginHelper.h"

BdmInterface_CFVx::BdmInterface_CFVx() : BdmInterfaceCommon(T_CFVx) {
}

BdmInterface_CFVx::~BdmInterface_CFVx() {
}

USBDM_ErrorCode BdmInterface_CFVx::writePC(unsigned long regValue) {
   return USBDM_WriteCReg(CFVx_CRegPC, regValue);
};

USBDM_ErrorCode BdmInterface_CFVx::readPC(unsigned long *regValue) {
   return USBDM_ReadCReg(CFVx_CRegPC, regValue);
};

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(BdmInterface_CFVx *pp) {
   return TcreatePluginInstance<BdmInterface_CFVx>(pp);
}
