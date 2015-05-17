/*
 * WxPluginImp.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#include <wx/msgdlg.h>
#include <wx/app.h>

#include "UsbdmSystem.h"
#include "WxPluginImp.h"

long WxPluginImp::display(std::string message, std::string caption, long style) {
   LOGGING;
   log.print("wxTheApp  = %p\n", wxTheApp);
   log.print("Message   = %s\n", message.c_str());
   log.print("Caption   = %s\n", caption.c_str());
   log.print("Style     = %ld\n", style);
   long rc =  wxMessageBox(message, caption, style);
   log.print("After\n");
   return rc;
}

extern "C" WxPluginImp WXPLUGIN_DECLSPEC *createPluginInstance();

/*
 * Create the plugin instance
 */
extern "C"
WxPluginImp* createPluginInstance() {
   LOGGING;
   return new WxPluginImp();
}
