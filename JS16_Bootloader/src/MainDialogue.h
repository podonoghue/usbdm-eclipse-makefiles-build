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

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainDialogue
///////////////////////////////////////////////////////////////////////////////
class MainDialogue : public wxDialog
{
   private:

   protected:
      enum
      {
         wxID_PROGRAM = 1000
      };

      wxStaticText* m_staticText;
      wxRadioBox* m_radioBox;
      wxButton* Program;
      wxButton* Cancel;
      wxStaticText* descriptionText;

      void OnProgramButtonClick( wxCommandEvent& event );
      void OnRadioBox( wxCommandEvent& event );
      void setDescription(int bdmType);

   public:

      MainDialogue( wxWindow* parent, wxWindowID id = wxID_ANY,
                    const wxString& title = _("JS16 First Stage Bootloader"),
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxSize( 350,400 ),
                    long style = wxDEFAULT_DIALOG_STYLE );
      virtual ~MainDialogue();

};

#endif //__NONAME_H__
