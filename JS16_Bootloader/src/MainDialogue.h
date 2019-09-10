///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

#include <string.h>
#include "BootloaderDialogueSkeleton.h"
#include "AppSettings.h"

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainDialogue
///////////////////////////////////////////////////////////////////////////////

extern const std::string firmwareSelection[];

class MainDialogue : public BootloaderDialogueSkeleton
{
   private:

   protected:
	enum DialogueMode{
	            	GUI_MODE,
	            	CMD_LINE_MODE
	};
      wxString             customFilename;
      wxString             customPath;
      wxString             defaultDirectory;
      std::string          filePath;

      bool                 verbose;
      bool                 enableConsole;
      DialogueMode         activeMode;


      virtual void OnProgramButtonClick( wxCommandEvent& event );
      virtual void OnLoadSourceButtonClick( wxCommandEvent& event );
      virtual void OnRadioBox( wxCommandEvent& event );

      void setDescription(std::string description);
      void logUsageError(wxCmdLineParser& parser, const wxString& text);

   public:

      MainDialogue( wxWindow* parent);
      virtual ~MainDialogue();
      void loadSettings(const AppSettings &settings);
      void saveSettings(AppSettings &settings);
      USBDM_ErrorCode doCommandLineProgram();
      USBDM_ErrorCode parseCommandLine(wxCmdLineParser& parser);
      bool inGUIMode(){return activeMode == GUI_MODE;}
      bool consoleIsEnabled(){return enableConsole;}
};

#endif //__NONAME_H__
