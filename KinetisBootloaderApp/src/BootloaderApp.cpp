/*! \file
    \brief Flash Programming App

    BootloaderApp.cpp

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
   | 10 Dec 2019 | Initial work                                              - pgo
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

#include "BootloaderDialogue.h"

using namespace std;

#define CONFIG_FILE_NAME "Bootloader"

// Declare the application class
class BootloaderApp : public wxApp {
   DECLARE_CLASS( BootloaderApp )
   DECLARE_EVENT_TABLE()

private:
   BootloaderDialogueSkeleton *dialogue = nullptr;

public:
   BootloaderApp();

   // Called on application startup
   virtual bool OnInit();
   virtual int  OnExit();
   virtual int  OnRun();
   virtual ~BootloaderApp();
};

// Implements BootloaderApp& GetApp()
DECLARE_APP(BootloaderApp)
IMPLEMENT_APP(BootloaderApp)

/*
 * BootloaderApp type definition
 */
IMPLEMENT_CLASS(BootloaderApp, wxApp)

/*
 * BootloaderApp event table definition
 */
BEGIN_EVENT_TABLE( BootloaderApp, wxApp )

END_EVENT_TABLE()

BootloaderApp::BootloaderApp() {
}

bool BootloaderApp::OnInit() {

   SetAppName(_("bootloader")); // So application files are kept in the correct directory

   // Create the main application window
   dialogue = new BootloaderDialogue();

   SetTopWindow((wxWindow*)dialogue);
   dialogue->ShowModal();
   dialogue->Destroy();
   return true;
}

int BootloaderApp::OnRun(void) {
   wxApp::OnRun();
   return 0;
}

int BootloaderApp::OnExit(void) {
   return wxApp::OnExit();
}

BootloaderApp::~BootloaderApp() {
}

