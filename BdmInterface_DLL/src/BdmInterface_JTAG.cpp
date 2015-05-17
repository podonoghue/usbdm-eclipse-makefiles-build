/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_JTAG.h"


BdmInterface_JTAG::BdmInterface_JTAG() : BdmInterfaceCommon(T_JTAG) {
}

BdmInterface_JTAG::~BdmInterface_JTAG() {
}

/*
 * Create the plugin instance
 */
extern "C"
BdmInterface* __declspec(dllexport) createPluginInstance() {
   return new BdmInterface_JTAG();
}
