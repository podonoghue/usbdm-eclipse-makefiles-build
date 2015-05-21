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

public:
   static WxPluginPtr createWxPlugin() {
      return createPlugin(DLL_NAME("usbdm-wx-plugin"), "createPluginInstance");
   }

private:
   WxPluginFactory();
   virtual ~WxPluginFactory();
};

#endif /* SRC_WXPLUGINFACTORY_H_ */
