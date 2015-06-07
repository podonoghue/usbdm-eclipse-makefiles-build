///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MEMORYDUMPDIALOGUESKELETON_H__
#define __MEMORYDUMPDIALOGUESKELETON_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/choice.h>
#include <wx/grid.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
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
		wxGrid* memoryRangesGrid;
		wxStaticText* m_staticText3;
		wxPanel* m_panel1;
		wxButton* readMemoryButton;
		wxButton* saveToFileButton;
		wxCheckBox* keepEmptySRECsCheckbox;
		wxStaticText* m_staticText2;
		wxTextCtrl* statusText;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTargetTypeRadioBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRefreshBDMClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBdmSelectComboSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTargetVddControlClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInterfaceSpeedSelectComboSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReadMemoryButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveToFileButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepEmptySRECsCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MemoryDumpDialogueSkeleton( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("USBDM Memory Dump"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 489,865 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MemoryDumpDialogueSkeleton();
	
};

#endif //__MEMORYDUMPDIALOGUESKELETON_H__
