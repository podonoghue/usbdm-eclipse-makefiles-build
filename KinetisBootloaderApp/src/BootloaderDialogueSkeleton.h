///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep  6 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class BootloaderDialogueSkeleton
///////////////////////////////////////////////////////////////////////////////
class BootloaderDialogueSkeleton : public wxDialog
{
	private:

	protected:
		wxButton* loadFile_button;
		wxStaticText* loadedFile_static;
		wxButton* checkDevice_button;
		wxTextCtrl* checkDevice_textCtrl;
		wxButton* programDevice_button;
		wxStaticText* programAction_static;

		// Virtual event handlers, overide them in your derived class
		virtual void onLoadFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCheckDevice( wxCommandEvent& event ) { event.Skip(); }
		virtual void onProgramDevice( wxCommandEvent& event ) { event.Skip(); }


	public:

		BootloaderDialogueSkeleton( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Kinetis Bootloader"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 464,298 ), long style = wxDEFAULT_DIALOG_STYLE );
		~BootloaderDialogueSkeleton();

};

