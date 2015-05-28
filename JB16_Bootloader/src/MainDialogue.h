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

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainDialogue
///////////////////////////////////////////////////////////////////////////////
class MainDialogue : public BootloaderDialogueSkeleton
{
   private:

   protected:
      wxString             customFilename;
      wxString             customPath;

      virtual void OnRebootButtonClick( wxCommandEvent& event );
      virtual void OnProgramButtonClick( wxCommandEvent& event );
      virtual void OnLoadSourceButtonClick( wxCommandEvent& event );
      virtual void OnRadioBox( wxCommandEvent& event );

      void setDescription(std::string description);

   public:

      MainDialogue( wxWindow* parent);
      virtual ~MainDialogue();

};

#endif //__NONAME_H__
