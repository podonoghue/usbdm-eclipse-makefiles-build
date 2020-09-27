/*
 * GdiDialoguePluginFactoryX.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#ifndef GDIDIALOGUEPLUGINFACTORY_H_
#define GDIDIALOGUEPLUGINFACTORY_H_

#include "PluginFactory.h"
#include "GdiDialoguePlugin.h"

class GdiDialoguePluginFactory : public PluginFactory<GdiDialoguePlugin> {
public:
   /**
    * Create dialogue plugin
    */
   static GdiDialoguePluginPtr createPlugin() {
      return PluginFactory<GdiDialoguePlugin>::createPlugin(DLL_NAME("usbdm-gdi-dialogue"));
   }
protected:
   GdiDialoguePluginFactory() {};
   ~GdiDialoguePluginFactory() {};
};

#endif /* GDIDIALOGUEPLUGINFACTORY_H_ */
