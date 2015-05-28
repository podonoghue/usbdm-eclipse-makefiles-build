///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __BOOTLOADERDIALOGUESKELETON_H__
#define __BOOTLOADERDIALOGUESKELETON_H__

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
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class BootloaderDialogueSkeleton
///////////////////////////////////////////////////////////////////////////////
class BootloaderDialogueSkeleton : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			wxID_LOADSOURCE = 1000,
			wxID_PROGRAM
		};
		
		wxStaticText* instructionText;
		wxRadioBox* firmwareSelectionBox;
		wxStaticText* descriptionText;
		wxPanel* buttonPanel;
		wxButton* loadSourceButton;
		wxButton* programButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnRadioBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadSourceButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnProgramButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		BootloaderDialogueSkeleton( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("JS16 ICP Bootloader"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 371,560 ), long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX|wxRESIZE_BORDER ); 
		~BootloaderDialogueSkeleton();
	
};

#endif //__BOOTLOADERDIALOGUESKELETON_H__
