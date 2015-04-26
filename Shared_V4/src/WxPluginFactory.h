/*
 * WxPluginFactory.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_WXPLUGINFACTORY_H_
#define SRC_WXPLUGINFACTORY_H_

#include "PluginFactory.h"
#include "WxPlugin.h"

#include "UsbdmWxConstants.h"

class WxPluginFactory: public PluginFactory<WxPlugin> {
private:
   static WxPluginPtr createPlugin(std::string dllName) { return WxPluginPtr(); }

public:
   static WxPluginPtr createWxPlugin() {
      LOGGING;
      if (newInstance == 0) {
#ifdef LOG
         loadClass("usbdm-wx-plugin-debug.4.dll", "createPluginInstance");
#else
         loadClass("usbdm-wx-plugin.4.dll", "createPluginInstance");
#endif
      }
      WxPluginPtr pp((WxPlugin *)(*newInstance)(), deleter);
      instanceCount++;
      return pp;
   }

public:
   WxPluginFactory();
   virtual ~WxPluginFactory();
};

#endif /* SRC_WXPLUGINFACTORY_H_ */
