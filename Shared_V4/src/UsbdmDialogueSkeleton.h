///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __USBDMDIALOGUESKELETON_H__
#define __USBDMDIALOGUESKELETON_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class NumberTextEditCtrl;
class SecurityTextEditCtrl;

#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gbsizer.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class UsbdmDialogueSkeleton
///////////////////////////////////////////////////////////////////////////////
class UsbdmDialogueSkeleton : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			wxID_TRIM = 1000,
			wxID_SYNC_GROUP,
			wxID_GDB_SERVER_GROUP,
			wxID_KEEPCHANGES,
			wxID_DISCARDCHANGES
		};
		
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
		wxPanel* fTargetPanel;
		wxButton* loadFileButtonControl;
		wxCheckBox* incrementalFileLoadCheckBoxControl;
		wxCheckBox* autoFileReloadCheckBoxControl;
		wxStaticText* loadedFilenameStaticControl;
		wxChoice* deviceTypeChoiceControl;
		wxButton* detectChipButtonControl;
		wxCheckBox* filterByChipIdCheckBoxControl;
		wxStaticText* trimAddressStaticControl;
		wxStaticText* trimFrequencyStaticControl;
		NumberTextEditCtrl* trimAddressTextControl;
		wxStaticText* trimAddressStaticControlHex;
		NumberTextEditCtrl* trimFrequencyTextControl;
		wxStaticText* trimFrequencyStaticControlkHz;
		wxCheckBox* trimFrequencyCheckBoxControl;
		wxStaticText* trimValueStaticControl;
		wxStaticText* busFrequencyStaticControl;
		NumberTextEditCtrl* busFrequencyTextControl;
		wxStaticText* busFrequencyStaticControlkHz;
		wxRadioBox* securityRadioBoxControl;
		wxChoice* eraseChoiceControl;
		wxButton* eraseNowButtonControl;
		wxButton* unlockButtonControl;
		wxCheckBox* enableSoundsCheckBoxControl;
		wxStaticText* gdbServerPortNumberStaticControl;
		NumberTextEditCtrl* gdbServerPortNumberTextControl;
		wxStaticText* gdbTtyPortNumberStaticControl;
		NumberTextEditCtrl* gdbTtyPortNumberTextControl;
		wxButton* programFlashButtonControl;
		wxButton* verifyFlashButtonControl;
		wxButton* loadAndGoButtonControl;
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
		wxStaticText* eeepromSizeStaticText;
		wxChoice* eeepromSizeChoiceControl;
		wxStaticText* m_staticText12;
		wxStaticText* flexNvmPartitionStaticText;
		wxChoice* flexNvmPartitionChoiceControl;
		wxStaticText* m_staticText14;
		wxStaticText* flexNvmDescriptionStaticControl;
		wxCheckBox* customSecurityCheckbox;
		wxChoice* securityMemoryRegionChoice;
		wxButton* resetCustomButtonControl;
		SecurityTextEditCtrl* securityValuesTextControl;
		wxStaticText* securityDescriptionStaticText;
		wxStaticText* StatusText;
		wxButton* keepChangesButton;
		wxButton* discardChangesButton;
		wxButton* closeButton;
		
		// Virtual event handlers, overide them in your derived class
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
		virtual void OnLoadFileButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnIncrementalFileLoadCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAutoFileReloadCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeviceTypeChoiceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDetectChipButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterByChipIdCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNonvolatileAddressTextTextUpdated( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTrimFrequencyTextTextUpdated( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTrimFrequencyCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBusFrequencyTextTextUpdated( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSecurityRadioboxSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEraseChoiceSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMassEraseButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUnlockButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSoundCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGdbServerPortNumberTextUpdated( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGdbTtyPortNumberTextUpdated( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnProgramFlashButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVerifyFlashButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadAndGoButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPowerOffDurationText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPowerOnDurationText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetDurationText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetReleaseIntervalText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetRecoveryIntervalText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEeepromSizeChoiceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFlexNvmPartionChoiceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSecurityCheckboxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSecurityMemoryRegionChoiceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetCustomValueClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSecurityEditUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepChangesClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscardChangesClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		UsbdmDialogueSkeleton( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("USBDM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 529,1017 ), long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX|wxRESIZE_BORDER ); 
		~UsbdmDialogueSkeleton();
	
};

#endif //__USBDMDIALOGUESKELETON_H__
