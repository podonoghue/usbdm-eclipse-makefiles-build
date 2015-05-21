/*
 * WxPluginImp.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue

\verbatim
Change History
-====================================================================================
| 14 Sep 2015 | Created - pgo
+====================================================================================
\endverbatim

 */

#include <wx/msgdlg.h>
#include <wx/app.h>

#include "UsbdmSystem.h"
#include "WxPluginImp.h"
#include "PluginHelper.h"

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

/*
 * Create the plug-in instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(void *pp) {
   return TcreatePluginInstance<WxPluginImp>(pp);
}

