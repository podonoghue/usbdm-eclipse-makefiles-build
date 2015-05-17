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

#ifdef WIN32
#ifdef LOG
#define PLUGIN_NAME "usbdm-wx-plugin-debug.4.dll"
#else
#define PLUGIN_NAME "usbdm-wx-plugin.4.dll"
#endif
#else
#ifdef LOG
#define PLUGIN_NAME "libusbdm-wx-plugin-debug.so"
#else
#define PLUGIN_NAME "libusbdm-wx-plugin.so"
#endif
#endif

class WxPluginFactory: public PluginFactory<WxPlugin> {
private:
   static WxPluginPtr createPlugin(std::string dllName) { return WxPluginPtr(); }

public:
   static WxPluginPtr createWxPlugin() {
      LOGGING;
      if (newInstance == 0) {
         loadClass(PLUGIN_NAME, "createPluginInstance");
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
