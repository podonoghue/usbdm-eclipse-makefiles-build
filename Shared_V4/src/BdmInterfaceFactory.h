/*
 * BdmInterfaceFactory.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACEFACTORY_H_
#define SRC_BDMINTERFACEFACTORY_H_

#include "PluginFactory.h"
#include "BdmInterface.h"

class BdmInterfaceFactory {

public:
   static BdmInterfacePtr createInterface(TargetType_t targetType, BdmInterface::Callback=0);

public:
   BdmInterfaceFactory() {};
   virtual ~BdmInterfaceFactory() {};
};

#endif /* SRC_BDMINTERFACEFACTORY_H_ */
