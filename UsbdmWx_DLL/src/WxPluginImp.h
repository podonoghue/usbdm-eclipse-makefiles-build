/*
 * WxPluginImp.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_WXPLUGINIMP_H_
#define SRC_WXPLUGINIMP_H_

#include "WxPlugin.h"
#include <string>

class WxPluginImp : public WxPlugin {

private:
   static ModuleInfo moduleInfo;

public:
   virtual long display(std::string message, std::string caption, long style);
   virtual ~WxPluginImp() {};
   WxPluginImp() {
      LOGGING_E;
   };
   virtual ModuleInfo &getModuleInfo() const override { return moduleInfo; }
};

#endif /* SRC_WXPLUGINIMP_H_ */
