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
   OpenLog           openLog;
   MainDialogue      *dialogue;
   AppSettingsPtr    appSettings;
   USBDM_ErrorCode   applicationRC;
   bool              consoleIsAttached;

   void attachConsole();
   void freeConsole();

public:
   JS16_BootloaderApp();

   // Called on application startup
   virtual bool OnInit();
   virtual int  OnExit();
   virtual int  OnRun();
   virtual void OnInitCmdLine(wxCmdLineParser& parser);
   virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
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
 applicationRC(BDM_RC_OK),
 consoleIsAttached(false){
   LOGGING_E;
}

/*
 * Initialisation for JS16_BootloaderApp
 */
bool JS16_BootloaderApp::OnInit(void) {
   LOGGING;

   applicationRC = BDM_RC_OK;

   // create new main dialogue. Will first be used to parse the command line
   dialogue = new MainDialogue(NULL);

   SetAppName(_("usbdm")); // So app files are kept in the correct directory

#ifndef _WIN32
   // Otherwise wxWidgets doesn't look in the correct location
   ((wxStandardPaths&)wxStandardPaths::Get()).SetInstallPrefix(_(USBDM_INSTALL_DIRECTORY));
#endif

   // call for default command parsing behaviour
   if (!wxApp::OnInit()) {
	  applicationRC = BDM_RC_ILLEGAL_COMMAND;
   }
   else if(applicationRC == BDM_RC_OK){
	   // Prepare the GUI application
	  if(dialogue->inGUIMode()){
	     appSettings.reset(new AppSettings("JS16_Bootloader.cfg", "JS16 Bootloader"));
	     appSettings->load();
	     dialogue->loadSettings(*appSettings);
	     SetTopWindow(dialogue);
	     dialogue->ShowModal();
	     dialogue->saveSettings(*appSettings);
	     appSettings->save();
	  }
	  else{
		 attachConsole();
	     applicationRC = dialogue->doCommandLineProgram();
	     if(dialogue->consoleIsEnabled()){
	    	 if(applicationRC != BDM_RC_OK){
	    		 fprintf(stderr, "Programming failed, rc = %s\n", UsbdmSystem::getErrorString(applicationRC));
	    	 }
	    	 else{
	    		 fprintf(stdout, "Programming completed successfully\n");
	    	 }
	     }
		 freeConsole();
	  }
   }
   dialogue->Destroy();
   return true; // Return true regardless as we want OnRun() to execute
}

/*
 * Run function for JS16_BootloaderApp
 */
int JS16_BootloaderApp::OnRun(void) {
   LOGGING_E;

   // Everything is done in OnInit()
   if (applicationRC != BDM_RC_OK){
	  log.error("JS16 Bootloader app::OnRun() - error code = %s\n", UsbdmSystem::getErrorString(applicationRC));
   }
   else{
	  log.print("JS16 Bootloader app::OnRun() success\n");
   }

   return applicationRC;
}

/*
 * Cleanup for JS16_BootloaderApp
 */
int JS16_BootloaderApp::OnExit(void) {
   LOGGING_E;

   return wxApp::OnExit();
}

static const std::string firmwareSelectionUsage = std::string("Valid firmware choices:\n")          +
															  "\t0 = " + firmwareSelection[0] +"\n" +
		                                                      "\t1 = " + firmwareSelection[1] +"\n" +
		                                                      "\t2 = " + firmwareSelection[2] +"\n" +
		                                                      "\t3 = " + firmwareSelection[3] +"\n" +
		                                                      "\t4 = " + firmwareSelection[4] +"\n" +
		                                                      "\t5 = " + firmwareSelection[5] +"\n" +
		                                                      "\t6 = " + firmwareSelection[6] +"\n" ;

static const wxCmdLineEntryDesc g_cmdLineDesc[] = {
	  { wxCMD_LINE_PARAM,       NULL,           NULL, _("Custom BDM firmware. Must be specified if firmware option is 0"),   wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
	  { wxCMD_LINE_OPTION,      _("firmware"),  NULL, _("BDM firmware choice"),                                              wxCMD_LINE_VAL_NUMBER },
	  { wxCMD_LINE_USAGE_TEXT,  NULL,           NULL, _(firmwareSelectionUsage)                    },
      { wxCMD_LINE_SWITCH,      _("verbose"),   NULL, _("Print progress messages to stdout")       },
#ifdef _WIN32
	  { wxCMD_LINE_SWITCH,      _("console"),   NULL, _("Enable output to stdout and stderr")                 },
#endif
	  { wxCMD_LINE_SWITCH,      _("help"),      NULL, _("Show this help message"),                                           wxCMD_LINE_VAL_NONE,     wxCMD_LINE_OPTION_HELP  },
	  { wxCMD_LINE_USAGE_TEXT,  NULL,           NULL, _("\nReturn codes: Check USBDM Error Codes") },
      { wxCMD_LINE_NONE }
};

void JS16_BootloaderApp::OnInitCmdLine(wxCmdLineParser& parser){

	parser.SetDesc (g_cmdLineDesc);
	 // must refuse '/' as parameter starter or cannot use "/path" style paths
	parser.SetSwitchChars (_("-"));
	parser.SetLogo(_("JS16 Bootloader\n"));

	#if (wxCHECK_VERSION(2, 9, 0))
	    parser.AddUsageText(_(
	          "\nExamples:\n"
	          "-firmware=1\n"
	          "    Program BDM using firmware choice 1 - " + firmwareSelection[1] + "\n"
	    	  "-firmware=0 Image.sx\n"
	    	  "    Program BDM using custom image file  "
	     ));
    #ifdef _WIN32
	    parser.AddUsageText(_("\nRecommendation! When running on console, use \"start/wait\" to execute the application."
    		              " For example:\n\tstart/wait JS16_Bootloader -program -firmware=1"));
    #endif // _WIN32
	#endif
}

bool JS16_BootloaderApp::OnCmdLineParsed(wxCmdLineParser& parser){

	applicationRC = dialogue->parseCommandLine(parser);
    if (applicationRC != BDM_RC_OK) {
	   parser.Usage();
    }
	return true; // return true regardless to catch unknown/illegal command line option in OnInit()
}
JS16_BootloaderApp::~JS16_BootloaderApp() {
   LOGGING_E;
}

void JS16_BootloaderApp::attachConsole(){
	LOGGING;

	if(consoleIsAttached){
		return;
	}
#ifdef _WIN32
	if ((GetConsoleWindow() == NULL) && dialogue->consoleIsEnabled()) {
		if(AttachConsole(ATTACH_PARENT_PROCESS)){ // attach to parent console if possible
			consoleIsAttached = true;
			log.print("Parent console attached\n");
		}
		else{
			log.print("Unable to attach parent console to application. Error: %lu\n", GetLastError());
		}
		if(consoleIsAttached){
			freopen("CONOUT$", "w", stdout);
			freopen("CONOUT$", "w", stderr);
		}
		// Set stdout to no buffering; stderr is unbuffered by default
		setvbuf(stdout, NULL, _IONBF, 0);
	}
#endif
}

void JS16_BootloaderApp::freeConsole(){
	LOGGING;

	if(!consoleIsAttached){
		return;
	}
#ifdef _WIN32
	FreeConsole();
	consoleIsAttached = false;
	log.print("Console detached");
#endif
}
