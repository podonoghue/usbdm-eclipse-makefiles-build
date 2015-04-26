/*
 * WxPluginImp.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#include <wx/msgdlg.h>

#include "UsbdmSystem.h"
#include "WxPluginImp.h"

long WxPluginImp::display(std::string message, std::string caption, long style) {
   LOGGING;
   return wxMessageBox(message, caption, style);
}

/*
 * Create the plugin instance
 */
extern "C"
WxPluginImp* WXPLUGIN_DECLSPEC createPluginInstance() {
   LOGGING;
   return new WxPluginImp();
}
