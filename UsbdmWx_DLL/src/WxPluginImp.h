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

class WXPLUGIN_DECLSPEC WxPluginImp : public WxPlugin {

public:
   virtual long display(std::string message, std::string caption, long style);
   virtual ~WxPluginImp() {};
   WxPluginImp() {};
};

#endif /* SRC_WXPLUGINIMP_H_ */
