///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep 11 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class NumberTextEditCtrl;

#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class GdiDialogueSkeleton
///////////////////////////////////////////////////////////////////////////////
class GdiDialogueSkeleton : public wxDialog
{
	private:

	protected:
		wxNotebook* fNotebook;
		wxPanel* fInterfacePanel;
		wxChoice* bdmSelectChoiceControl;
		wxButton* bdmRefreshButtonControl;
		wxStaticText* bdmDescriptionStaticControl;
		wxRadioBox* targetVddControl;
		wxCheckBox* cycleVddOnResetControl;
		wxCheckBox* cycleVddOnConnectionControl;
		wxCheckBox* leaveTargetPoweredControl;
		wxCheckBox* automaticallyReconnectControl;
		wxCheckBox* useResetSignalControl;
		wxCheckBox* usePstSignalControl;
		wxCheckBox* guessTargetSpeedControl;
		wxCheckBox* maskInterruptWhenSteppingControl;
		wxCheckBox* catchVllsResetControl;
		wxStaticText* m_staticText32;
		NumberTextEditCtrl* connectionTimeoutTextControl;
		wxStaticText* interfaceSpeedStaticText;
		wxChoice* interfaceSpeedControl;
		wxStaticText* connectionSpeedStaticTextWarning;
		wxRadioBox* bdmClockSelectControl;
		wxStaticText* firmwareStaticControl;
		wxStaticText* dllVersionstaticControl;
		wxPanel* fAdvancedPanel;
		wxStaticText* powerOffDurationStaticControl;
		NumberTextEditCtrl* powerOffDurationTextControl;
		wxStaticText* m_textCtrl1;
		wxStaticText* powerOnRecoveryIntervalStaticControl;
		NumberTextEditCtrl* powerOnRecoveryIntervalTextControl;
		wxStaticText* m_staticText4;
		wxStaticText* resetDurationStaticControl;
		NumberTextEditCtrl* resetDurationTextControl;
		wxStaticText* m_staticText6;
		wxStaticText* resetReleaseIntervalStaticControl;
		NumberTextEditCtrl* resetReleaseIntervalTextControl;
		wxStaticText* m_staticText8;
		wxStaticText* resetRecoveryIntervalStaticControl;
		NumberTextEditCtrl* resetRecoveryIntervalTextControl;
		wxStaticText* m_staticText10;
		wxCheckBox* dontShowAgainControl;
		wxButton* cancelButton;
		wxButton* openBdmButton;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnBdmSelectComboSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRefreshBDMClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVddSelectBoxSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCycleVddOnResetCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCycleTargetVddOnConnectionCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLeaveTargetOnCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReconnectCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUseResetCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUseUsePstSignalCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGuessSpeedCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMaskInterruptsWhenSteppingCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCatchVllsResetCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnConnectionTimeoutTextTextUpdated( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInterfaceSpeedSelectComboSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBdmClockSelectRadioboxSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPowerOffDurationText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPowerOnDurationText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetDurationText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetReleaseIntervalText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetRecoveryIntervalText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDontShowAgainControlClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenBdmClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		GdiDialogueSkeleton( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("USBDM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 529,1017 ), long style = wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX|wxRESIZE_BORDER );
		~GdiDialogueSkeleton();

};

