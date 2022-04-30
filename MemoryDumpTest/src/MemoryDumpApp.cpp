/*! \file
    \brief Memory Dump Application

    MemoryDumpApp.cpp

    \verbatim
    USBDM
    Copyright (C) 2009  Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
    \endverbatim

    \verbatim
   Change History
   -=========================================================================================
   | 15 Mar 2015 | Complete redesign using wxFormBuilder                   - pgo V4.10.6.260
   +=========================================================================================
   \endverbatim
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

#include "AppSettings.h"
#include "MemoryDumpDialogue.h"
#include "UsbdmSystem.h"
#include "Common.h"

using namespace std;

#define CONFIG_FILE_NAME "MemoryDump_"

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("MemoryDump.log", "Memory Dump");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
      UsbdmSystem::Log::closeLogFile();
   }
};

// Declare the application class
class MemoryDumpApp : public wxApp {
   DECLARE_CLASS( MemoryDumpApp )
   DECLARE_EVENT_TABLE()

private:
   OpenLog          openLog;
   AppSettings      appSettings;

public:
   MemoryDumpApp();

   // Called on application startup
   virtual bool OnInit();
   virtual int  OnExit();
   virtual int  OnRun();
   virtual ~MemoryDumpApp();
};

// Implements MemoryDumpApp& GetApp()
DECLARE_APP(MemoryDumpApp)
IMPLEMENT_APP(MemoryDumpApp)

/*
 * MemoryDumpApp type definition
 */
IMPLEMENT_CLASS(MemoryDumpApp, wxApp)

/*
 * MemoryDumpApp event table definition
 */
BEGIN_EVENT_TABLE( MemoryDumpApp, wxApp )

END_EVENT_TABLE()

MemoryDumpApp::MemoryDumpApp() :
   openLog(),
   appSettings("MemoryDump.cfg", "Memory Dump Configuration") {
}

bool MemoryDumpApp::OnInit() {
   LOGGING;

#ifndef _WIN32
   // Otherwise wxWidgets doesn't look in the correct location
   ((wxStandardPaths&)wxStandardPaths::Get()).SetInstallPrefix(_(USBDM_INSTALL_DIRECTORY));
#endif

   SetAppName(_("usbdm")); // So application files are kept in the correct directory

   // Call for default command parsing behaviour
   if (!wxApp::OnInit()) {
      log.error("Failed OnInit()\n");
      return true; // Return true here as we want OnRun() to execute
   }

   return true;
}

int MemoryDumpApp::OnRun(void) {
   LOGGING;
   USBDM_ErrorCode returnValue = BDM_RC_OK;
   // Load interactive settings
   appSettings.load();
//   appSettings->printToLog();

   // Create the main application window
   MemoryDumpDialogue *dialogue = new MemoryDumpDialogue(NULL, appSettings);

//   SetTopWindow((wxWindow*)dialogue);
   dialogue->ShowModal();
   appSettings.save();
   return returnValue;
}

int MemoryDumpApp::OnExit(void) {
   LOGGING_E;
   return wxApp::OnExit();
}

MemoryDumpApp::~MemoryDumpApp() {
}
