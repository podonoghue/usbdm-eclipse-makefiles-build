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

#include <wx/wx.h>
#include <wx/window.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/filefn.h>
#include <wx/app.h>
#include <wx/evtloop.h>
#include <wx/msgdlg.h>
#include <wx/msgdlg.h>
#include <wx/app.h>
//#include <wx/events.h>
#include <wx/app.h>
#include <wx/msgdlg.h>
#include <exception>

#include "UsbdmSystem.h"
#include "WxPluginImp.h"
#include "PluginHelper.h"

#if defined(__linux__)
//! Used to make sure that any pending events are handled
//!
static void runGuiEventLoop(void) {
#if wxCHECK_VERSION(2, 9, 0)
   wxEventLoopBase  *originalEventLoop = wxEventLoop::GetActive();
   wxEventLoopBase  *eLoop = originalEventLoop;
#else
   wxEventLoop  *originalEventLoop = wxEventLoop::GetActive();
   wxEventLoop  *eLoop = originalEventLoop;
#endif
   if (eLoop == NULL) {
      eLoop = new wxEventLoop;
   }
   wxEventLoopBase::SetActive(eLoop);
   while (eLoop->Pending()) {
//      fprintf(stderr, "eLoop->Pending == TRUE #1\n");
      eLoop->Dispatch();
   }
//   fprintf(stderr, "eLoop->Pending == FALSE #1\n");
   wxEventLoopBase::SetActive(originalEventLoop);
}
#endif

long WxPluginImp::display(std::string message, std::string caption, long style) {
   LOGGING;
   log.print("wxTheApp  = %p\n", wxTheApp);
   log.print("Caption   = %s\n", caption.c_str());
   log.print("Message  = \n%s\n", message.c_str());
   log.print("Style     = %ld\n", style);
   long rc = 0;
      try {
         rc = wxMessageBox(message, caption, style);
      } catch (std::exception &) {
      }
#if defined(__linux__)
   runGuiEventLoop();
#endif
   log.print("After\n");
   return rc;
}

ModuleInfo WxPluginImp::moduleInfo;

/*
 * Create the plug-in instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(WxPluginImp *pp) {
   return TcreatePluginInstance<WxPluginImp>(pp);
}

