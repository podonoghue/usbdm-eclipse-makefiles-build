/*! \file
    \brief Flash Programming App

    FlashProgrammingApp.cpp

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
-=================================================================================
|  12 Apr 2012 | Created                                               4.9.4 - pgo
+=================================================================================
\endverbatim
*/

#include <wx/wx.h>
#include <wx/cmdline.h>
#include <wx/stdpaths.h>

#include "Common.h"
#include "MainDialogue.h"
#include "UsbdmSystem.h"

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("JS16_Bootloader.log", "JS16 Bootloader");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
      UsbdmSystem::Log::closeLogFile();
   }
};

// Declare the application class
class JS16_BootloaderApp : public wxApp {
   DECLARE_CLASS( JS16_BootloaderApp )
   DECLARE_EVENT_TABLE()

private:
   OpenLog        openLog;
   MainDialogue  *dialogue;
   int            returnValue;

public:
   JS16_BootloaderApp();

   // Called on application startup
   virtual bool OnInit();
   virtual int  OnExit();
   virtual int  OnRun();
   virtual ~JS16_BootloaderApp();
};

// Implements JS16_BootloaderApp & GetApp()
DECLARE_APP(JS16_BootloaderApp)
IMPLEMENT_APP(JS16_BootloaderApp)
IMPLEMENT_CLASS(JS16_BootloaderApp, wxApp)

/*
 * JS16_BootloaderApp event table definition
 */
BEGIN_EVENT_TABLE( JS16_BootloaderApp, wxApp )
END_EVENT_TABLE()

JS16_BootloaderApp::JS16_BootloaderApp() :
 openLog(),
 dialogue(0),
 returnValue(0) {
   LOGGING_E;
}

// Initialise the application
bool JS16_BootloaderApp::OnInit(void) {
   LOGGING;

   returnValue = 0;

   SetAppName(_("usbdm")); // So app files are kept in the correct directory

#ifndef _WIN32
   // Otherwise wxWidgets doesn't look in the correct location
   ((wxStandardPaths&)wxStandardPaths::Get()).SetInstallPrefix(_(USBDM_INSTALL_DIRECTORY));
#endif

   // call for default command parsing behaviour
   if (!wxApp::OnInit()) {
      return false;
   }

   AppSettings settings("JS16_Bootloader.cfg", "JS16 Bootloader");
   settings.load();

   // Create the main application window
   dialogue = new MainDialogue(NULL);
   SetTopWindow(dialogue);
   dialogue->ShowModal();
   dialogue->saveSettings(settings);
   dialogue->Destroy();

   settings.save();

   return true;
}

int JS16_BootloaderApp::OnRun(void) {
   LOGGING_E;
   int exitcode = wxApp::OnRun();
   if (exitcode != 0)
      return exitcode;
   // Everything is done in OnInit()!
   log.print("FlashProgrammerApp::OnRun() - return value = %d\n", returnValue);
   return returnValue;
}

int JS16_BootloaderApp::OnExit(void) {
   LOGGING_E;
   return wxApp::OnExit();
}

JS16_BootloaderApp::~JS16_BootloaderApp() {
   LOGGING_E;
}

