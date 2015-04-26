/*
 * GdiTestApp.cpp
 *
 *  Created on: 7 Apr 2015
 *      Author: podonoghue
 */

/*
 * GdiTestApp.cpp
 *
 *  Created on: 7 Apr 2015
 *      Author: podonoghue
 */

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/wx.h>
#include <wx/cmdline.h>
#include <wx/stdpaths.h>

#include <wx/wx.h>
#include <wx/cmdline.h>
#include <wx/stdpaths.h>

#include "GDI.h"

#include "UsbdmSystem.h"
#include "AppSettings.h"
#include "BdmInterface.h"
#include "GdiDialogue.h"

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("GdiTest.log", "Gdi Test");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
      UsbdmSystem::Log::closeLogFile();
   }
};

class GdiTestApp: public wxApp {
   DECLARE_CLASS( GdiTestApp )
   DECLARE_EVENT_TABLE()

private:
   OpenLog openLog;

public:
   GdiTestApp();
   virtual ~GdiTestApp();
   bool OnInit();
};

// Implements GdiTestApp& GetApp()
DECLARE_APP(GdiTestApp)
IMPLEMENT_APP(GdiTestApp)

/*
 * GdiTestApp type definition
 */
IMPLEMENT_CLASS(GdiTestApp, wxApp)

/*
 * GdiTestApp event table definition
 */
BEGIN_EVENT_TABLE( GdiTestApp, wxApp )

END_EVENT_TABLE()

bool GdiTestApp::OnInit() {
   LOGGING;

   if (!wxApp::OnInit()) {
      log.print("Failed OnInit()\n");
      return false;
   }

   DiGdiOpen(0, 0, 0, 0, 0);
   DiGdiInitIO(0);

//   BdmInterfacePtr bdmInterface(new BdmInterface(T_CFVx));
//
//   GdiDialogue *gdiDialogue = new GdiDialogue(NULL, bdmInterface);
//   AppSettingsPtr appsettings(new AppSettings("TestApp_", T_CFVx, "Test App Configuration"));
//   gdiDialogue->execute(appsettings);
//   gdiDialogue->Destroy();
   return true;
}

GdiTestApp::GdiTestApp() {

}

GdiTestApp::~GdiTestApp() {
}

