/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_JTAG.h"
#include "PluginHelper.h"

ModuleInfo BdmInterface_JTAG::moduleInfo;

BdmInterface_JTAG::BdmInterface_JTAG() : BdmInterfaceCommon(T_JTAG) {
}

BdmInterface_JTAG::~BdmInterface_JTAG() {
}

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(BdmInterface_JTAG *pp) {
   return TcreatePluginInstance<BdmInterface_JTAG>(pp);
}
