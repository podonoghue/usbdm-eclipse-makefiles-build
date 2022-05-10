///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep 11 2020)
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
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/radiobox.h>
#include <wx/grid.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
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
		wxButton* bdmRefreshButtonControl;
		wxComboBox* bdmSelectChoiceControl;
		wxStaticText* bdmDescriptionStaticControl;
		wxRadioBox* targetTypeRadioBox;
		wxGrid* memoryRangesGrid;
		wxRadioBox* targetVddControl;
		wxChoice* interfaceSpeedControl;
		wxCheckBox* initializationCheckbox;
		wxTextCtrl* initialializeTextCntrl;
		wxCheckBox* pagedFlashAddressCheckBox;
		wxStaticText* flashPageRegisterStaticText;
		wxTextCtrl* flashPageTextCntrl;
		wxCheckBox* pagedEepromAddressCheckBox;
		wxStaticText* eepromPageRegisterStaticText;
		wxTextCtrl* eepromPageTextCntrl;
		wxStaticText* m_staticText3;
		wxButton* LoadSettingsButtonControl;
		wxButton* SaveSettingsButtonControl;
		wxPanel* m_panel1;
		wxButton* readMemoryButton;
		wxButton* saveToFileButton;
		wxCheckBox* keepEmptySRECsCheckbox;
		wxStaticText* m_staticText2;
		wxTextCtrl* statusText;

		// Virtual event handlers, overide them in your derived class
		virtual void OnRefreshBDMClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBdmSelectComboSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTargetTypeRadioBoxSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTargetVddControlClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInterfaceSpeedSelectComboSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInitializationCheckboxChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPagedCheckBoxEvent( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPageAddressChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadSettingsClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveSettingsClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReadMemoryButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveToFileButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepEmptySRECsCheckboxClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MemoryDumpDialogueSkeleton( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("USBDM Memory Dump"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 870,1043 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU );
		~MemoryDumpDialogueSkeleton();

};

