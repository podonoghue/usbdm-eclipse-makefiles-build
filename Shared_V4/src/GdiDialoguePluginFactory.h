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
#ifdef LOG
      return PluginFactory<GdiDialoguePlugin>::createPlugin("usbdm-gdi-dialogue-debug.4.dll");
#else
      return PluginFactory<GdiDialoguePlugin>::createPlugin("usbdm-gdi-dialogue.4.dll");
#endif
   }
protected:
   GdiDialoguePluginFactory() {};
   ~GdiDialoguePluginFactory() {};
};

#endif /* GDIDIALOGUEPLUGINFACTORY_H_ */
