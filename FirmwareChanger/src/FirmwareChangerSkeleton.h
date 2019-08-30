///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class NumberTextEditCtrl;

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class FirmwareChangerSkeleton
///////////////////////////////////////////////////////////////////////////////
class FirmwareChangerSkeleton : public wxDialog
{
	private:

	protected:
		wxButton* loadFirmwareButton;
		wxCheckBox* autoSelectFirmwareCheckbox;
		wxStaticText* filenameStaticText;
		wxTextCtrl* serialNumberText;
		NumberTextEditCtrl* autoSequenceText;
		wxButton* readSerialNumberButton;
		wxCheckBox* autoSequenceCheckbox;
		wxTextCtrl* fileInformationStaticText;
		wxStaticText* statusStaticText;
		wxButton* programFlashButton;
		wxButton* verifyButton;
		wxButton* exitButton;

		// Virtual event handlers, overide them in your derived class
		virtual void OnLoadFirmwareButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAutoSelectFirmwareCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSerialnumTextctrlTextUpdated( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAutoSequenceTextControlTextUpdated( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReadSerialNumButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAutoSequenceCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnProgramFlashButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVerifyFlashButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		FirmwareChangerSkeleton( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Firmware Changer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 441,692 ), long style = wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~FirmwareChangerSkeleton();

};

