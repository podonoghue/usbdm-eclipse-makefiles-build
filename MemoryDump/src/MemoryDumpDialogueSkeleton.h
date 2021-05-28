///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep 11 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/choice.h>
#include <wx/radiobut.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/grid.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MemoryDumpDialogueSkeleton
///////////////////////////////////////////////////////////////////////////////
class MemoryDumpDialogueSkeleton : public wxDialog
{
	private:

	protected:
		wxRadioBox* targetTypeRadioBox;
		wxButton* bdmRefreshButtonControl;
		wxComboBox* bdmSelectChoiceControl;
		wxStaticText* bdmDescriptionStaticControl;
		wxRadioBox* targetVddControl;
		wxChoice* interfaceSpeedControl;
		wxRadioButton* flatAddressRadioButton;
		wxRadioButton* pagedFlashAddressRadioButton;
		wxStaticText* flashPageRegisterStaticText;
		wxTextCtrl* flashPageTextCntrl;
		wxRadioButton* pagedEepromAddressRadioButton;
		wxStaticText* eepromPageRegisterStaticText;
		wxTextCtrl* eepromPageTextCntrl;
		wxCheckBox* initializationCheckbox;
		wxTextCtrl* initialializeTextCntrl;
		wxGrid* memoryRangesGrid;
		wxStaticText* m_staticText3;
		wxPanel* m_panel1;
		wxButton* readMemoryButton;
		wxButton* saveToFileButton;
		wxCheckBox* keepEmptySRECsCheckbox;
		wxStaticText* m_staticText2;
		wxTextCtrl* statusText;

		// Virtual event handlers, overide them in your derived class
		virtual void OnTargetTypeRadioBoxSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRefreshBDMClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBdmSelectComboSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTargetVddControlClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInterfaceSpeedSelectComboSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFlatAddressSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPagedFlashAddressSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPageAddressChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPagedEepromAddressSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInitializationCheckboxChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReadMemoryButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveToFileButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepEmptySRECsCheckboxClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MemoryDumpDialogueSkeleton( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("USBDM Memory Dump"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,1043 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU );
		~MemoryDumpDialogueSkeleton();

};

