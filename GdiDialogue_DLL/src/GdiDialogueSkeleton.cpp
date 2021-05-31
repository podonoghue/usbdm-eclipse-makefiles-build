///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep 11 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "NumberTextEditCtrl.h"

#include "GdiDialogueSkeleton.h"

///////////////////////////////////////////////////////////////////////////

GdiDialogueSkeleton::GdiDialogueSkeleton( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizerDialogue;
	bSizerDialogue = new wxBoxSizer( wxVERTICAL );

	fNotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	fInterfacePanel = new wxPanel( fNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	fInterfacePanel->SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );

	wxBoxSizer* sbSizerInterfacePanel;
	sbSizerInterfacePanel = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerSelectBdm;
	sbSizerSelectBdm = new wxStaticBoxSizer( new wxStaticBox( fInterfacePanel, wxID_ANY, wxT("Select BDM") ), wxVERTICAL );

	wxBoxSizer* sbSizerSelectBdmInner;
	sbSizerSelectBdmInner = new wxBoxSizer( wxHORIZONTAL );

	wxArrayString bdmSelectChoiceControlChoices;
	bdmSelectChoiceControl = new wxChoice( sbSizerSelectBdm->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, bdmSelectChoiceControlChoices, 0 );
	bdmSelectChoiceControl->SetSelection( 0 );
	bdmSelectChoiceControl->SetToolTip( wxT("List of connected BDMs") );

	sbSizerSelectBdmInner->Add( bdmSelectChoiceControl, 1, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );

	bdmRefreshButtonControl = new wxButton( sbSizerSelectBdm->GetStaticBox(), wxID_ANY, wxT("Detect"), wxDefaultPosition, wxDefaultSize, 0 );
	bdmRefreshButtonControl->SetToolTip( wxT("Refresh list of connected BDMs") );

	sbSizerSelectBdmInner->Add( bdmRefreshButtonControl, 0, wxRIGHT|wxLEFT, 5 );


	sbSizerSelectBdm->Add( sbSizerSelectBdmInner, 1, wxEXPAND, 5 );

	bdmDescriptionStaticControl = new wxStaticText( sbSizerSelectBdm->GetStaticBox(), wxID_ANY, wxT("USBDM ARM-SWD for OpenSDA2"), wxDefaultPosition, wxDefaultSize, 0 );
	bdmDescriptionStaticControl->Wrap( -1 );
	sbSizerSelectBdm->Add( bdmDescriptionStaticControl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	sbSizerInterfacePanel->Add( sbSizerSelectBdm, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wxStaticBoxSizer* sbSizerTargetVdd;
	sbSizerTargetVdd = new wxStaticBoxSizer( new wxStaticBox( fInterfacePanel, wxID_ANY, wxT("Target Vdd Control") ), wxVERTICAL );

	wxString targetVddControlChoices[] = { wxT("Off"), wxT("3.3V   "), wxT("5V") };
	int targetVddControlNChoices = sizeof( targetVddControlChoices ) / sizeof( wxString );
	targetVddControl = new wxRadioBox( sbSizerTargetVdd->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, targetVddControlNChoices, targetVddControlChoices, 1, wxRA_SPECIFY_ROWS );
	targetVddControl->SetSelection( 0 );
	targetVddControl->SetToolTip( wxT("Off\t- Target Vdd is externally supplied\n3.3V\t- BDM supplies target Vdd @3.3V\n5V\t- BDM supplies target Vdd @5V") );

	sbSizerTargetVdd->Add( targetVddControl, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );

	cycleVddOnResetControl = new wxCheckBox( sbSizerTargetVdd->GetStaticBox(), wxID_ANY, wxT("Cycle target Vdd on reset"), wxDefaultPosition, wxDefaultSize, 0 );
	cycleVddOnResetControl->SetToolTip( wxT("Target Vdd supply is cycled whenever the BDM resets the target") );

	sbSizerTargetVdd->Add( cycleVddOnResetControl, 0, wxALL, 5 );

	cycleVddOnConnectionControl = new wxCheckBox( sbSizerTargetVdd->GetStaticBox(), wxID_ANY, wxT("Cycle target Vdd on connection problems"), wxDefaultPosition, wxDefaultSize, 0 );
	cycleVddOnConnectionControl->SetToolTip( wxT("Target Vdd supply is cycled whenever the BDM fails to connect to the target") );

	sbSizerTargetVdd->Add( cycleVddOnConnectionControl, 0, wxALL, 5 );

	leaveTargetPoweredControl = new wxCheckBox( sbSizerTargetVdd->GetStaticBox(), wxID_ANY, wxT("Leave target powered on exit"), wxDefaultPosition, wxDefaultSize, 0 );
	leaveTargetPoweredControl->SetToolTip( wxT("BDM supplied Target Vdd is left on when application is closed") );

	sbSizerTargetVdd->Add( leaveTargetPoweredControl, 0, wxALL, 5 );


	sbSizerInterfacePanel->Add( sbSizerTargetVdd, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );

	wxStaticBoxSizer* sbSizerConnectionControl;
	sbSizerConnectionControl = new wxStaticBoxSizer( new wxStaticBox( fInterfacePanel, wxID_ANY, wxT("Connection Control") ), wxVERTICAL );

	automaticallyReconnectControl = new wxCheckBox( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxT("Automatically re-connect"), wxDefaultPosition, wxDefaultSize, 0 );
	automaticallyReconnectControl->SetValue(true);
	automaticallyReconnectControl->SetToolTip( wxT("Re-synchronise with target before each operation") );

	sbSizerConnectionControl->Add( automaticallyReconnectControl, 0, wxALL, 5 );

	useResetSignalControl = new wxCheckBox( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxT("Use RESET signal"), wxDefaultPosition, wxDefaultSize, 0 );
	useResetSignalControl->SetValue(true);
	useResetSignalControl->SetToolTip( wxT("Drive RESET signal when resetting target") );

	sbSizerConnectionControl->Add( useResetSignalControl, 0, wxALL, 5 );

	usePstSignalControl = new wxCheckBox( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxT("Use PST signals"), wxDefaultPosition, wxDefaultSize, 0 );
	usePstSignalControl->SetToolTip( wxT("Use PST signals to detect target run state") );

	sbSizerConnectionControl->Add( usePstSignalControl, 0, wxALL, 5 );

	guessTargetSpeedControl = new wxCheckBox( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxT("Guess target speed if no sync"), wxDefaultPosition, wxDefaultSize, 0 );
	guessTargetSpeedControl->SetValue(true);
	guessTargetSpeedControl->SetToolTip( wxT("Guess target speed when target does not support sync operation") );

	sbSizerConnectionControl->Add( guessTargetSpeedControl, 0, wxALL, 5 );

	maskInterruptWhenSteppingControl = new wxCheckBox( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxT("Mask interrupts when stepping"), wxDefaultPosition, wxDefaultSize, 0 );
	maskInterruptWhenSteppingControl->SetToolTip( wxT("Interrupts are temporarily masked when single-stepping the target.\nInterrupts are unaffected when running.") );

	sbSizerConnectionControl->Add( maskInterruptWhenSteppingControl, 0, wxALL, 5 );

	catchVllsResetControl = new wxCheckBox( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxT("Catch VLLS Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	catchVllsResetControl->SetToolTip( wxT("Stop the target when a VLLS reset occurs") );

	sbSizerConnectionControl->Add( catchVllsResetControl, 0, wxALL, 5 );

	wxBoxSizer* bSizerConnectionTimeout;
	bSizerConnectionTimeout = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxT("Connection Timeout"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizerConnectionTimeout->Add( m_staticText32, 0, wxALL, 5 );

	connectionTimeoutTextControl = new NumberTextEditCtrl( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	connectionTimeoutTextControl->SetToolTip( wxT("How long to wait for an unresponsive target.\n0=>indefinite wait - This is useful when using low-power modes.") );

	bSizerConnectionTimeout->Add( connectionTimeoutTextControl, 0, wxALL, 5 );


	sbSizerConnectionControl->Add( bSizerConnectionTimeout, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerInterfaceSpeed;
	bSizerInterfaceSpeed = new wxBoxSizer( wxHORIZONTAL );

	interfaceSpeedStaticText = new wxStaticText( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxT("Interface Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	interfaceSpeedStaticText->Wrap( -1 );
	bSizerInterfaceSpeed->Add( interfaceSpeedStaticText, 0, wxALL, 5 );

	wxArrayString interfaceSpeedControlChoices;
	interfaceSpeedControl = new wxChoice( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, interfaceSpeedControlChoices, 0 );
	interfaceSpeedControl->SetSelection( 0 );
	interfaceSpeedControl->SetToolTip( wxT("Maximum target connection speed\n(Actual speed made be lower)") );

	bSizerInterfaceSpeed->Add( interfaceSpeedControl, 0, wxALL, 5 );


	sbSizerConnectionControl->Add( bSizerInterfaceSpeed, 1, wxEXPAND, 5 );

	connectionSpeedStaticTextWarning = new wxStaticText( sbSizerConnectionControl->GetStaticBox(), wxID_ANY, wxT("Speed < Target Clock Frequency/5"), wxDefaultPosition, wxDefaultSize, 0 );
	connectionSpeedStaticTextWarning->Wrap( -1 );
	sbSizerConnectionControl->Add( connectionSpeedStaticTextWarning, 0, wxALL, 5 );


	sbSizerInterfacePanel->Add( sbSizerConnectionControl, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );

	wxString bdmClockSelectControlChoices[] = { wxT("&Default"), wxT("&Bus Clock/2"), wxT("&Alt") };
	int bdmClockSelectControlNChoices = sizeof( bdmClockSelectControlChoices ) / sizeof( wxString );
	bdmClockSelectControl = new wxRadioBox( fInterfacePanel, wxID_ANY, wxT("BDM Clock Source"), wxDefaultPosition, wxDefaultSize, bdmClockSelectControlNChoices, bdmClockSelectControlChoices, 1, wxRA_SPECIFY_ROWS );
	bdmClockSelectControl->SetSelection( 0 );
	bdmClockSelectControl->SetToolTip( wxT("Clock source for BDM interface\nDefault\t- Interface does not modify BDM clock\nBus Clock\t- Generated from the target bus clock \nAlt\t- Target dependent source.") );

	sbSizerInterfacePanel->Add( bdmClockSelectControl, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizerBdmVersion;
	bSizerBdmVersion = new wxBoxSizer( wxHORIZONTAL );

	firmwareStaticControl = new wxStaticText( fInterfacePanel, wxID_ANY, wxT("BDM Firmware Ver ?.?.?"), wxDefaultPosition, wxDefaultSize, 0 );
	firmwareStaticControl->Wrap( -1 );
	bSizerBdmVersion->Add( firmwareStaticControl, 1, wxALL, 5 );

	dllVersionstaticControl = new wxStaticText( fInterfacePanel, wxID_ANY, wxT("DLL Ver ?.?.?.?"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	dllVersionstaticControl->Wrap( -1 );
	bSizerBdmVersion->Add( dllVersionstaticControl, 1, wxALL, 5 );


	sbSizerInterfacePanel->Add( bSizerBdmVersion, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );


	fInterfacePanel->SetSizer( sbSizerInterfacePanel );
	fInterfacePanel->Layout();
	sbSizerInterfacePanel->Fit( fInterfacePanel );
	fNotebook->AddPage( fInterfacePanel, wxT("Interface"), true );
	fAdvancedPanel = new wxPanel( fNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerAdvancedTab;
	bSizerAdvancedTab = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerBdmParameters;
	sbSizerBdmParameters = new wxStaticBoxSizer( new wxStaticBox( fAdvancedPanel, wxID_ANY, wxT("BDM Parameters") ), wxVERTICAL );

	wxFlexGridSizer* fgSizerBdmParameters;
	fgSizerBdmParameters = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizerBdmParameters->SetFlexibleDirection( wxBOTH );
	fgSizerBdmParameters->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	powerOffDurationStaticControl = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("Power Off duration"), wxDefaultPosition, wxDefaultSize, 0 );
	powerOffDurationStaticControl->Wrap( -1 );
	fgSizerBdmParameters->Add( powerOffDurationStaticControl, 0, wxRIGHT|wxLEFT, 5 );

	powerOffDurationTextControl = new NumberTextEditCtrl( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	powerOffDurationTextControl->SetToolTip( wxT("Duration to power off when cycling target power") );

	fgSizerBdmParameters->Add( powerOffDurationTextControl, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );

	m_textCtrl1 = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl1->Wrap( -1 );
	fgSizerBdmParameters->Add( m_textCtrl1, 0, wxRIGHT|wxLEFT, 5 );

	powerOnRecoveryIntervalStaticControl = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("Power On Recover interval"), wxDefaultPosition, wxDefaultSize, 0 );
	powerOnRecoveryIntervalStaticControl->Wrap( -1 );
	fgSizerBdmParameters->Add( powerOnRecoveryIntervalStaticControl, 0, wxRIGHT|wxLEFT, 5 );

	powerOnRecoveryIntervalTextControl = new NumberTextEditCtrl( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	powerOnRecoveryIntervalTextControl->SetToolTip( wxT("Interval to wait after power on of target") );

	fgSizerBdmParameters->Add( powerOnRecoveryIntervalTextControl, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText4 = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizerBdmParameters->Add( m_staticText4, 0, wxRIGHT|wxLEFT, 5 );

	resetDurationStaticControl = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("Reset duration"), wxDefaultPosition, wxDefaultSize, 0 );
	resetDurationStaticControl->Wrap( -1 );
	fgSizerBdmParameters->Add( resetDurationStaticControl, 0, wxRIGHT|wxLEFT, 5 );

	resetDurationTextControl = new NumberTextEditCtrl( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	resetDurationTextControl->SetToolTip( wxT("Duration to apply reset to target") );

	fgSizerBdmParameters->Add( resetDurationTextControl, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText6 = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizerBdmParameters->Add( m_staticText6, 0, wxRIGHT|wxLEFT, 5 );

	resetReleaseIntervalStaticControl = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("Reset Release interval"), wxDefaultPosition, wxDefaultSize, 0 );
	resetReleaseIntervalStaticControl->Wrap( -1 );
	fgSizerBdmParameters->Add( resetReleaseIntervalStaticControl, 0, wxRIGHT|wxLEFT, 5 );

	resetReleaseIntervalTextControl = new NumberTextEditCtrl( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	resetReleaseIntervalTextControl->SetToolTip( wxT("Interval to hold other target signals after reset release") );

	fgSizerBdmParameters->Add( resetReleaseIntervalTextControl, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText8 = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizerBdmParameters->Add( m_staticText8, 0, wxRIGHT|wxLEFT, 5 );

	resetRecoveryIntervalStaticControl = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("Reset Recovery Interval"), wxDefaultPosition, wxDefaultSize, 0 );
	resetRecoveryIntervalStaticControl->Wrap( -1 );
	fgSizerBdmParameters->Add( resetRecoveryIntervalStaticControl, 0, wxRIGHT|wxLEFT, 5 );

	resetRecoveryIntervalTextControl = new NumberTextEditCtrl( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	resetRecoveryIntervalTextControl->SetToolTip( wxT("Interval to wait after target reset") );

	fgSizerBdmParameters->Add( resetRecoveryIntervalTextControl, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText10 = new wxStaticText( sbSizerBdmParameters->GetStaticBox(), wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizerBdmParameters->Add( m_staticText10, 0, wxRIGHT|wxLEFT, 5 );


	sbSizerBdmParameters->Add( fgSizerBdmParameters, 1, wxEXPAND, 5 );


	bSizerAdvancedTab->Add( sbSizerBdmParameters, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );


	fAdvancedPanel->SetSizer( bSizerAdvancedTab );
	fAdvancedPanel->Layout();
	bSizerAdvancedTab->Fit( fAdvancedPanel );
	fNotebook->AddPage( fAdvancedPanel, wxT("Advanced"), false );

	bSizerDialogue->Add( fNotebook, 1, wxEXPAND | wxALL, 5 );

	dontShowAgainControl = new wxCheckBox( this, wxID_ANY, wxT("Don't show this dialogue in future"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDialogue->Add( dontShowAgainControl, 0, wxALL, 5 );

	wxBoxSizer* bSizerCancelOpen;
	bSizerCancelOpen = new wxBoxSizer( wxHORIZONTAL );

	cancelButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCancelOpen->Add( cancelButton, 0, wxALL, 5 );

	openBdmButton = new wxButton( this, wxID_OK, wxT("Open BDM"), wxDefaultPosition, wxDefaultSize, 0 );

	openBdmButton->SetDefault();
	openBdmButton->SetToolTip( wxT("Close Programmer") );

	bSizerCancelOpen->Add( openBdmButton, 0, wxALL, 5 );


	bSizerDialogue->Add( bSizerCancelOpen, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizerDialogue );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GdiDialogueSkeleton::OnClose ) );
	bdmSelectChoiceControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GdiDialogueSkeleton::OnBdmSelectComboSelected ), NULL, this );
	bdmRefreshButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnRefreshBDMClick ), NULL, this );
	targetVddControl->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GdiDialogueSkeleton::OnVddSelectBoxSelected ), NULL, this );
	cycleVddOnResetControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnCycleVddOnResetCheckboxClick ), NULL, this );
	cycleVddOnConnectionControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnCycleTargetVddOnConnectionCheckboxClick ), NULL, this );
	leaveTargetPoweredControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnLeaveTargetOnCheckboxClick ), NULL, this );
	automaticallyReconnectControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnReconnectCheckboxClick ), NULL, this );
	useResetSignalControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnUseResetCheckboxClick ), NULL, this );
	usePstSignalControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnUseUsePstSignalCheckboxClick ), NULL, this );
	guessTargetSpeedControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnGuessSpeedCheckboxClick ), NULL, this );
	maskInterruptWhenSteppingControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnMaskInterruptsWhenSteppingCheckboxClick ), NULL, this );
	catchVllsResetControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnCatchVllsResetCheckboxClick ), NULL, this );
	connectionTimeoutTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnConnectionTimeoutTextTextUpdated ), NULL, this );
	interfaceSpeedControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GdiDialogueSkeleton::OnInterfaceSpeedSelectComboSelected ), NULL, this );
	bdmClockSelectControl->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GdiDialogueSkeleton::OnBdmClockSelectRadioboxSelected ), NULL, this );
	powerOffDurationTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnPowerOffDurationText ), NULL, this );
	powerOnRecoveryIntervalTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnPowerOnDurationText ), NULL, this );
	resetDurationTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnResetDurationText ), NULL, this );
	resetReleaseIntervalTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnResetReleaseIntervalText ), NULL, this );
	resetRecoveryIntervalTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnResetRecoveryIntervalText ), NULL, this );
	dontShowAgainControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnDontShowAgainControlClick ), NULL, this );
	cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnCancelClick ), NULL, this );
	openBdmButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnOpenBdmClick ), NULL, this );
}

GdiDialogueSkeleton::~GdiDialogueSkeleton()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GdiDialogueSkeleton::OnClose ) );
	bdmSelectChoiceControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GdiDialogueSkeleton::OnBdmSelectComboSelected ), NULL, this );
	bdmRefreshButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnRefreshBDMClick ), NULL, this );
	targetVddControl->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GdiDialogueSkeleton::OnVddSelectBoxSelected ), NULL, this );
	cycleVddOnResetControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnCycleVddOnResetCheckboxClick ), NULL, this );
	cycleVddOnConnectionControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnCycleTargetVddOnConnectionCheckboxClick ), NULL, this );
	leaveTargetPoweredControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnLeaveTargetOnCheckboxClick ), NULL, this );
	automaticallyReconnectControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnReconnectCheckboxClick ), NULL, this );
	useResetSignalControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnUseResetCheckboxClick ), NULL, this );
	usePstSignalControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnUseUsePstSignalCheckboxClick ), NULL, this );
	guessTargetSpeedControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnGuessSpeedCheckboxClick ), NULL, this );
	maskInterruptWhenSteppingControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnMaskInterruptsWhenSteppingCheckboxClick ), NULL, this );
	catchVllsResetControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnCatchVllsResetCheckboxClick ), NULL, this );
	connectionTimeoutTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnConnectionTimeoutTextTextUpdated ), NULL, this );
	interfaceSpeedControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GdiDialogueSkeleton::OnInterfaceSpeedSelectComboSelected ), NULL, this );
	bdmClockSelectControl->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GdiDialogueSkeleton::OnBdmClockSelectRadioboxSelected ), NULL, this );
	powerOffDurationTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnPowerOffDurationText ), NULL, this );
	powerOnRecoveryIntervalTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnPowerOnDurationText ), NULL, this );
	resetDurationTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnResetDurationText ), NULL, this );
	resetReleaseIntervalTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnResetReleaseIntervalText ), NULL, this );
	resetRecoveryIntervalTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GdiDialogueSkeleton::OnResetRecoveryIntervalText ), NULL, this );
	dontShowAgainControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnDontShowAgainControlClick ), NULL, this );
	cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnCancelClick ), NULL, this );
	openBdmButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GdiDialogueSkeleton::OnOpenBdmClick ), NULL, this );

}
