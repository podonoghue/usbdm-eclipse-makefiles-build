///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "NumberTextEditCtrl.h"
#include "SecurityTextEditCtrl.h"

#include "UsbdmDialogueSkeleton.h"

///////////////////////////////////////////////////////////////////////////

UsbdmDialogueSkeleton::UsbdmDialogueSkeleton( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	fNotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	fInterfacePanel = new wxPanel( fNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	fInterfacePanel->SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( fInterfacePanel, wxID_ANY, wxT("Select BDM") ), wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString bdmSelectChoiceControlChoices;
	bdmSelectChoiceControl = new wxChoice( fInterfacePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, bdmSelectChoiceControlChoices, 0 );
	bdmSelectChoiceControl->SetSelection( 0 );
	bdmSelectChoiceControl->SetToolTip( wxT("List of connected BDMs") );
	
	bSizer6->Add( bdmSelectChoiceControl, 1, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	bdmRefreshButtonControl = new wxButton( fInterfacePanel, wxID_ANY, wxT("Detect"), wxDefaultPosition, wxDefaultSize, 0 );
	bdmRefreshButtonControl->SetToolTip( wxT("Refresh list of connected BDMs") );
	
	bSizer6->Add( bdmRefreshButtonControl, 0, wxRIGHT|wxLEFT, 5 );
	
	
	sbSizer4->Add( bSizer6, 1, wxEXPAND, 5 );
	
	bdmDescriptionStaticControl = new wxStaticText( fInterfacePanel, wxID_ANY, wxT("USBDM ARM-SWD for OpenSDA2"), wxDefaultPosition, wxDefaultSize, 0 );
	bdmDescriptionStaticControl->Wrap( -1 );
	sbSizer4->Add( bdmDescriptionStaticControl, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer3->Add( sbSizer4, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( fInterfacePanel, wxID_ANY, wxT("Target Vdd Control") ), wxVERTICAL );
	
	wxString targetVddControlChoices[] = { wxT("Off"), wxT("3.3V   "), wxT("5V") };
	int targetVddControlNChoices = sizeof( targetVddControlChoices ) / sizeof( wxString );
	targetVddControl = new wxRadioBox( fInterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, targetVddControlNChoices, targetVddControlChoices, 1, wxRA_SPECIFY_ROWS );
	targetVddControl->SetSelection( 0 );
	targetVddControl->SetToolTip( wxT("Off\t- Target Vdd is externally supplied\n3.3V\t- BDM supplies target Vdd @3.3V\n5V\t- BDM supplies target Vdd @5V") );
	
	sbSizer5->Add( targetVddControl, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	cycleVddOnResetControl = new wxCheckBox( fInterfacePanel, wxID_ANY, wxT("Cycle target Vdd on reset"), wxDefaultPosition, wxDefaultSize, 0 );
	cycleVddOnResetControl->SetToolTip( wxT("Target Vdd supply is cycled whenever the BDM resets the target") );
	
	sbSizer5->Add( cycleVddOnResetControl, 0, wxALL, 5 );
	
	cycleVddOnConnectionControl = new wxCheckBox( fInterfacePanel, wxID_ANY, wxT("Cycle target Vdd on connection problems"), wxDefaultPosition, wxDefaultSize, 0 );
	cycleVddOnConnectionControl->SetToolTip( wxT("Target Vdd supply is cycled whenever the BDM fails to connect to the target") );
	
	sbSizer5->Add( cycleVddOnConnectionControl, 0, wxALL, 5 );
	
	leaveTargetPoweredControl = new wxCheckBox( fInterfacePanel, wxID_ANY, wxT("Leave target powered on exit"), wxDefaultPosition, wxDefaultSize, 0 );
	leaveTargetPoweredControl->SetValue(true); 
	leaveTargetPoweredControl->SetToolTip( wxT("BDM supplied Target Vdd is left on when application is closed") );
	
	sbSizer5->Add( leaveTargetPoweredControl, 0, wxALL, 5 );
	
	
	bSizer3->Add( sbSizer5, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( fInterfacePanel, wxID_ANY, wxT("Connection Control") ), wxVERTICAL );
	
	automaticallyReconnectControl = new wxCheckBox( fInterfacePanel, wxID_ANY, wxT("Automatically re-connect"), wxDefaultPosition, wxDefaultSize, 0 );
	automaticallyReconnectControl->SetValue(true); 
	automaticallyReconnectControl->SetToolTip( wxT("Re-synchronise with target before each operation") );
	
	sbSizer6->Add( automaticallyReconnectControl, 0, wxALL, 5 );
	
	useResetSignalControl = new wxCheckBox( fInterfacePanel, wxID_ANY, wxT("Use RESET signal"), wxDefaultPosition, wxDefaultSize, 0 );
	useResetSignalControl->SetValue(true); 
	useResetSignalControl->SetToolTip( wxT("Drive RESET signal when resetting target") );
	
	sbSizer6->Add( useResetSignalControl, 0, wxALL, 5 );
	
	usePstSignalControl = new wxCheckBox( fInterfacePanel, wxID_ANY, wxT("Use PST signals"), wxDefaultPosition, wxDefaultSize, 0 );
	usePstSignalControl->SetToolTip( wxT("Use PST signals to detect target run state") );
	
	sbSizer6->Add( usePstSignalControl, 0, wxALL, 5 );
	
	guessTargetSpeedControl = new wxCheckBox( fInterfacePanel, wxID_ANY, wxT("Guess target speed if no sync"), wxDefaultPosition, wxDefaultSize, 0 );
	guessTargetSpeedControl->SetValue(true); 
	guessTargetSpeedControl->SetToolTip( wxT("Guess target speed when target does not support sync operation") );
	
	sbSizer6->Add( guessTargetSpeedControl, 0, wxALL, 5 );
	
	maskInterruptWhenSteppingControl = new wxCheckBox( fInterfacePanel, wxID_ANY, wxT("Mask interrupts when stepping"), wxDefaultPosition, wxDefaultSize, 0 );
	maskInterruptWhenSteppingControl->SetToolTip( wxT("Interrupts are temporarily masked when single-stepping the target.\nInterrupts are unaffected when running.") );
	
	sbSizer6->Add( maskInterruptWhenSteppingControl, 0, wxALL, 5 );
	
	catchVllsResetControl = new wxCheckBox( fInterfacePanel, wxID_ANY, wxT("Catch VLLS Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	catchVllsResetControl->SetToolTip( wxT("Stop the target when a VLLS reset occurs") );
	
	sbSizer6->Add( catchVllsResetControl, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( fInterfacePanel, wxID_ANY, wxT("Connection Timeout"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer121->Add( m_staticText32, 0, wxALL, 5 );
	
	connectionTimeoutTextControl = new NumberTextEditCtrl( fInterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	connectionTimeoutTextControl->SetToolTip( wxT("How long to wait for an unresponsive target.\n0=>indefinite wait - This is useful when using low-power modes.") );
	
	bSizer121->Add( connectionTimeoutTextControl, 0, wxALL, 5 );
	
	
	sbSizer6->Add( bSizer121, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	interfaceSpeedStaticText = new wxStaticText( fInterfacePanel, wxID_ANY, wxT("Interface Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	interfaceSpeedStaticText->Wrap( -1 );
	bSizer11->Add( interfaceSpeedStaticText, 0, wxALL, 5 );
	
	wxArrayString interfaceSpeedControlChoices;
	interfaceSpeedControl = new wxChoice( fInterfacePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, interfaceSpeedControlChoices, 0 );
	interfaceSpeedControl->SetSelection( 0 );
	interfaceSpeedControl->SetToolTip( wxT("Maximum target connection speed\n(Actual speed made be lower)") );
	
	bSizer11->Add( interfaceSpeedControl, 0, wxALL, 5 );
	
	
	sbSizer6->Add( bSizer11, 1, wxEXPAND, 5 );
	
	connectionSpeedStaticTextWarning = new wxStaticText( fInterfacePanel, wxID_ANY, wxT("Speed < Target Clock Frequency/5"), wxDefaultPosition, wxDefaultSize, 0 );
	connectionSpeedStaticTextWarning->Wrap( -1 );
	sbSizer6->Add( connectionSpeedStaticTextWarning, 0, wxALL, 5 );
	
	
	bSizer3->Add( sbSizer6, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxString bdmClockSelectControlChoices[] = { wxT("&Default"), wxT("&Bus Clock/2"), wxT("&Alt") };
	int bdmClockSelectControlNChoices = sizeof( bdmClockSelectControlChoices ) / sizeof( wxString );
	bdmClockSelectControl = new wxRadioBox( fInterfacePanel, wxID_ANY, wxT("BDM Clock Source"), wxDefaultPosition, wxDefaultSize, bdmClockSelectControlNChoices, bdmClockSelectControlChoices, 1, wxRA_SPECIFY_ROWS );
	bdmClockSelectControl->SetSelection( 0 );
	bdmClockSelectControl->SetToolTip( wxT("Clock source for BDM interface\nDefault\t- Interface does not modify BDM clock\nBus Clock\t- Generated from the target bus clock \nAlt\t- Target dependent source.") );
	
	bSizer3->Add( bdmClockSelectControl, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	firmwareStaticControl = new wxStaticText( fInterfacePanel, wxID_ANY, wxT("BDM Firmware Ver ?.?.?"), wxDefaultPosition, wxDefaultSize, 0 );
	firmwareStaticControl->Wrap( -1 );
	bSizer12->Add( firmwareStaticControl, 1, wxALL, 5 );
	
	dllVersionstaticControl = new wxStaticText( fInterfacePanel, wxID_ANY, wxT("DLL Ver ?.?.?.?"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	dllVersionstaticControl->Wrap( -1 );
	bSizer12->Add( dllVersionstaticControl, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	
	bSizer3->Add( bSizer12, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	fInterfacePanel->SetSizer( bSizer3 );
	fInterfacePanel->Layout();
	bSizer3->Fit( fInterfacePanel );
	fNotebook->AddPage( fInterfacePanel, wxT("Interface"), true );
	fTargetPanel = new wxPanel( fNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( fTargetPanel, wxID_ANY, wxT("Flash Image Buffer") ), wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	loadFileButtonControl = new wxButton( fTargetPanel, wxID_ANY, wxT("Load Hex File"), wxDefaultPosition, wxDefaultSize, 0 );
	loadFileButtonControl->SetToolTip( wxT("Load file into flash image buffer") );
	
	bSizer16->Add( loadFileButtonControl, 0, wxLEFT|wxRIGHT, 5 );
	
	incrementalFileLoadCheckBoxControl = new wxCheckBox( fTargetPanel, wxID_ANY, wxT("Incremental Load"), wxDefaultPosition, wxDefaultSize, 0 );
	incrementalFileLoadCheckBoxControl->SetToolTip( wxT("Load new files without clearing flash image buffer") );
	
	bSizer16->Add( incrementalFileLoadCheckBoxControl, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	autoFileReloadCheckBoxControl = new wxCheckBox( fTargetPanel, wxID_ANY, wxT("Auto Reload"), wxDefaultPosition, wxDefaultSize, 0 );
	autoFileReloadCheckBoxControl->SetValue(true); 
	autoFileReloadCheckBoxControl->SetToolTip( wxT("Quietly reload file before programming if it has changed") );
	
	bSizer16->Add( autoFileReloadCheckBoxControl, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	
	sbSizer7->Add( bSizer16, 0, wxEXPAND, 5 );
	
	loadedFilenameStaticControl = new wxStaticText( fTargetPanel, wxID_ANY, wxT("No File Loaded"), wxDefaultPosition, wxDefaultSize, 0 );
	loadedFilenameStaticControl->Wrap( -1 );
	sbSizer7->Add( loadedFilenameStaticControl, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer4->Add( sbSizer7, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer12;
	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( fTargetPanel, wxID_ANY, wxT("Device Selection") ), wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString deviceTypeChoiceControlChoices;
	deviceTypeChoiceControl = new wxChoice( fTargetPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, deviceTypeChoiceControlChoices, 0 );
	deviceTypeChoiceControl->SetSelection( 0 );
	deviceTypeChoiceControl->SetToolTip( wxT("Type of target device") );
	
	bSizer13->Add( deviceTypeChoiceControl, 1, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );
	
	detectChipButtonControl = new wxButton( fTargetPanel, wxID_ANY, wxT("Detect Chip"), wxDefaultPosition, wxDefaultSize, 0 );
	detectChipButtonControl->SetToolTip( wxT("Query target chip ID\n(More than a single device may be associated with a given ID)") );
	
	bSizer13->Add( detectChipButtonControl, 0, wxRIGHT|wxLEFT, 5 );
	
	
	sbSizer12->Add( bSizer13, 1, wxEXPAND, 5 );
	
	filterByChipIdCheckBoxControl = new wxCheckBox( fTargetPanel, wxID_ANY, wxT("Filter by chip ID (none)"), wxDefaultPosition, wxDefaultSize, 0 );
	filterByChipIdCheckBoxControl->SetToolTip( wxT("Restrict displayed chips to those matching chip ID") );
	
	sbSizer12->Add( filterByChipIdCheckBoxControl, 0, wxTOP|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	
	bSizer4->Add( sbSizer12, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer13;
	sbSizer13 = new wxStaticBoxSizer( new wxStaticBox( fTargetPanel, wxID_TRIM, wxT("Clock Trim") ), wxVERTICAL );
	
	wxGridBagSizer* gbSizer31;
	gbSizer31 = new wxGridBagSizer( 0, 0 );
	gbSizer31->SetFlexibleDirection( wxBOTH );
	gbSizer31->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	trimAddressStaticControl = new wxStaticText( fTargetPanel, wxID_ANY, wxT("Flash Trim Address"), wxDefaultPosition, wxDefaultSize, 0 );
	trimAddressStaticControl->Wrap( -1 );
	gbSizer31->Add( trimAddressStaticControl, wxGBPosition( 0, 0 ), wxGBSpan( 1, 2 ), wxLEFT, 10 );
	
	trimFrequencyStaticControl = new wxStaticText( fTargetPanel, wxID_ANY, wxT("Trim Frequency"), wxDefaultPosition, wxDefaultSize, 0 );
	trimFrequencyStaticControl->Wrap( -1 );
	gbSizer31->Add( trimFrequencyStaticControl, wxGBPosition( 0, 2 ), wxGBSpan( 1, 2 ), wxRIGHT|wxLEFT, 5 );
	
	trimAddressTextControl = new NumberTextEditCtrl( fTargetPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	trimAddressTextControl->SetToolTip( wxT("Flash address to program trim values to\n(May be 1st of several locations)") );
	
	gbSizer31->Add( trimAddressTextControl, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT, 5 );
	
	trimAddressStaticControlHex = new wxStaticText( fTargetPanel, wxID_ANY, wxT("(hex)     "), wxDefaultPosition, wxDefaultSize, 0 );
	trimAddressStaticControlHex->Wrap( -1 );
	gbSizer31->Add( trimAddressStaticControlHex, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	trimFrequencyTextControl = new NumberTextEditCtrl( fTargetPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	trimFrequencyTextControl->SetToolTip( wxT("Frequency to trim the internal clock to\n(Not the bus frequency)") );
	
	gbSizer31->Add( trimFrequencyTextControl, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT, 5 );
	
	trimFrequencyStaticControlkHz = new wxStaticText( fTargetPanel, wxID_ANY, wxT("kHz    "), wxDefaultPosition, wxDefaultSize, 0 );
	trimFrequencyStaticControlkHz->Wrap( -1 );
	gbSizer31->Add( trimFrequencyStaticControlkHz, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );
	
	trimFrequencyCheckBoxControl = new wxCheckBox( fTargetPanel, wxID_ANY, wxT("Do trim"), wxDefaultPosition, wxDefaultSize, 0 );
	trimFrequencyCheckBoxControl->SetToolTip( wxT("Trim target when programming") );
	
	gbSizer31->Add( trimFrequencyCheckBoxControl, wxGBPosition( 1, 4 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxLEFT, 5 );
	
	
	sbSizer13->Add( gbSizer31, 1, wxEXPAND, 5 );
	
	trimValueStaticControl = new wxStaticText( fTargetPanel, wxID_ANY, wxT("Calculated trim Value ?.??"), wxDefaultPosition, wxDefaultSize, 0 );
	trimValueStaticControl->Wrap( -1 );
	trimValueStaticControl->SetToolTip( wxT("Trim value from last programming operation.\nMay be 8 or 9 bits stored as trim and fine trim") );
	
	sbSizer13->Add( trimValueStaticControl, 0, wxALL, 5 );
	
	
	bSizer4->Add( sbSizer13, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer132;
	sbSizer132 = new wxStaticBoxSizer( new wxStaticBox( fTargetPanel, wxID_SYNC_GROUP, wxT("Options for secured device without SYNC") ), wxHORIZONTAL );
	
	busFrequencyStaticControl = new wxStaticText( fTargetPanel, wxID_ANY, wxT("Bus Frequency (Crystal/2)"), wxDefaultPosition, wxDefaultSize, 0 );
	busFrequencyStaticControl->Wrap( -1 );
	sbSizer132->Add( busFrequencyStaticControl, 0, wxALL, 5 );
	
	busFrequencyTextControl = new NumberTextEditCtrl( fTargetPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	busFrequencyTextControl->SetToolTip( wxT("Bus frequency to assume when mass erasing if it cannot be measured") );
	
	sbSizer132->Add( busFrequencyTextControl, 0, wxALL, 5 );
	
	busFrequencyStaticControlkHz = new wxStaticText( fTargetPanel, wxID_ANY, wxT("kHz"), wxDefaultPosition, wxDefaultSize, 0 );
	busFrequencyStaticControlkHz->Wrap( -1 );
	sbSizer132->Add( busFrequencyStaticControlkHz, 0, wxALL, 5 );
	
	
	bSizer4->Add( sbSizer132, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxString securityRadioBoxControlChoices[] = { wxT("&Image"), wxT("&Secure"), wxT("&Unsecure"), wxT("&Smart") };
	int securityRadioBoxControlNChoices = sizeof( securityRadioBoxControlChoices ) / sizeof( wxString );
	securityRadioBoxControl = new wxRadioBox( fTargetPanel, wxID_ANY, wxT("Security"), wxDefaultPosition, wxDefaultSize, securityRadioBoxControlNChoices, securityRadioBoxControlChoices, 1, wxRA_SPECIFY_ROWS );
	securityRadioBoxControl->SetSelection( 0 );
	securityRadioBoxControl->SetToolTip( wxT("Security state after programming:\nImage\t- whatever the flash image contains\nSecure\t- the device will be secured\nUnsecure\t- the device will be unsecured\nSmart\t- set unsecured if security area in image is unprogrammed\nDisabled\t- value is set on Advanced tab") );
	
	bSizer4->Add( securityRadioBoxControl, 0, wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer133;
	bSizer133 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer131;
	sbSizer131 = new wxStaticBoxSizer( new wxStaticBox( fTargetPanel, wxID_ANY, wxT("Programming Erase Mode") ), wxHORIZONTAL );
	
	wxArrayString eraseChoiceControlChoices;
	eraseChoiceControl = new wxChoice( fTargetPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, eraseChoiceControlChoices, 0 );
	eraseChoiceControl->SetSelection( 0 );
	eraseChoiceControl->SetToolTip( wxT("None\t- Don't erase before programming\nSelective\t- Erase only sectors being programmed\nAll\t- Erase entire chip\nMass\t- Use device specific mass erase method") );
	
	sbSizer131->Add( eraseChoiceControl, 1, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer133->Add( sbSizer131, 1, wxALL|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	wxStaticBoxSizer* sbSizer151;
	sbSizer151 = new wxStaticBoxSizer( new wxStaticBox( fTargetPanel, wxID_ANY, wxT("Erase/Unlock") ), wxHORIZONTAL );
	
	eraseNowButtonControl = new wxButton( fTargetPanel, wxID_ANY, wxT("Mass Erase Now"), wxDefaultPosition, wxDefaultSize, 0 );
	eraseNowButtonControl->SetToolTip( wxT("Mass erase and unsecure target") );
	
	sbSizer151->Add( eraseNowButtonControl, 0, wxRIGHT|wxLEFT, 5 );
	
	unlockButtonControl = new wxButton( fTargetPanel, wxID_ANY, wxT("Unlock Now"), wxDefaultPosition, wxDefaultSize, 0 );
	unlockButtonControl->SetToolTip( wxT("Unlock - Requires device in JTAG mode") );
	
	sbSizer151->Add( unlockButtonControl, 0, wxLEFT|wxRIGHT, 5 );
	
	
	bSizer133->Add( sbSizer151, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer133, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer141;
	sbSizer141 = new wxStaticBoxSizer( new wxStaticBox( fTargetPanel, wxID_ANY, wxT("Options") ), wxHORIZONTAL );
	
	enableSoundsCheckBoxControl = new wxCheckBox( fTargetPanel, wxID_ANY, wxT("Enable Sounds"), wxDefaultPosition, wxDefaultSize, 0 );
	enableSoundsCheckBoxControl->SetToolTip( wxT("Enable sounds when programming is complete") );
	
	sbSizer141->Add( enableSoundsCheckBoxControl, 0, wxRIGHT|wxLEFT, 5 );
	
	
	bSizer4->Add( sbSizer141, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer14;
	sbSizer14 = new wxStaticBoxSizer( new wxStaticBox( fTargetPanel, wxID_GDB_SERVER_GROUP, wxT("GDB Server") ), wxHORIZONTAL );
	
	gdbServerPortNumberStaticControl = new wxStaticText( fTargetPanel, wxID_ANY, wxT("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	gdbServerPortNumberStaticControl->Wrap( -1 );
	sbSizer14->Add( gdbServerPortNumberStaticControl, 0, wxALL, 5 );
	
	gdbServerPortNumberTextControl = new NumberTextEditCtrl( fTargetPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gdbServerPortNumberTextControl->SetToolTip( wxT("GDB Network address") );
	
	sbSizer14->Add( gdbServerPortNumberTextControl, 0, wxALL, 5 );
	
	
	bSizer4->Add( sbSizer14, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer15;
	sbSizer15 = new wxStaticBoxSizer( new wxStaticBox( fTargetPanel, wxID_ANY, wxT("Device Operations") ), wxHORIZONTAL );
	
	programFlashButtonControl = new wxButton( fTargetPanel, wxID_ANY, wxT("Program Flash"), wxDefaultPosition, wxDefaultSize, 0 );
	programFlashButtonControl->Enable( false );
	programFlashButtonControl->SetToolTip( wxT("Program image to target") );
	
	sbSizer15->Add( programFlashButtonControl, 1, wxRIGHT|wxLEFT, 5 );
	
	verifyFlashButtonControl = new wxButton( fTargetPanel, wxID_ANY, wxT("Verify Flash"), wxDefaultPosition, wxDefaultSize, 0 );
	verifyFlashButtonControl->Enable( false );
	verifyFlashButtonControl->SetToolTip( wxT("Verify target flash against flash image buffer") );
	
	sbSizer15->Add( verifyFlashButtonControl, 1, wxRIGHT|wxLEFT, 5 );
	
	loadAndGoButtonControl = new wxButton( fTargetPanel, wxID_ANY, wxT("Load and Go"), wxDefaultPosition, wxDefaultSize, 0 );
	loadAndGoButtonControl->Enable( false );
	loadAndGoButtonControl->SetToolTip( wxT("Program image to target and start target execution") );
	
	sbSizer15->Add( loadAndGoButtonControl, 1, wxRIGHT|wxLEFT, 5 );
	
	
	bSizer4->Add( sbSizer15, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	fTargetPanel->SetSizer( bSizer4 );
	fTargetPanel->Layout();
	bSizer4->Fit( fTargetPanel );
	fNotebook->AddPage( fTargetPanel, wxT("Target"), false );
	fAdvancedPanel = new wxPanel( fNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( fAdvancedPanel, wxID_ANY, wxT("BDM Parameters") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	powerOffDurationStaticControl = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("Power Off duration"), wxDefaultPosition, wxDefaultSize, 0 );
	powerOffDurationStaticControl->Wrap( -1 );
	fgSizer1->Add( powerOffDurationStaticControl, 0, wxRIGHT|wxLEFT, 5 );
	
	powerOffDurationTextControl = new NumberTextEditCtrl( fAdvancedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	powerOffDurationTextControl->SetToolTip( wxT("Duration to power off when cycling target power") );
	
	fgSizer1->Add( powerOffDurationTextControl, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_textCtrl1 = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl1->Wrap( -1 );
	fgSizer1->Add( m_textCtrl1, 0, wxRIGHT|wxLEFT, 5 );
	
	powerOnRecoveryIntervalStaticControl = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("Power On Recover interval"), wxDefaultPosition, wxDefaultSize, 0 );
	powerOnRecoveryIntervalStaticControl->Wrap( -1 );
	fgSizer1->Add( powerOnRecoveryIntervalStaticControl, 0, wxRIGHT|wxLEFT, 5 );
	
	powerOnRecoveryIntervalTextControl = new NumberTextEditCtrl( fAdvancedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	powerOnRecoveryIntervalTextControl->SetToolTip( wxT("Interval to wait after power on of target") );
	
	fgSizer1->Add( powerOnRecoveryIntervalTextControl, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticText4 = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer1->Add( m_staticText4, 0, wxRIGHT|wxLEFT, 5 );
	
	resetDurationStaticControl = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("Reset duration"), wxDefaultPosition, wxDefaultSize, 0 );
	resetDurationStaticControl->Wrap( -1 );
	fgSizer1->Add( resetDurationStaticControl, 0, wxRIGHT|wxLEFT, 5 );
	
	resetDurationTextControl = new NumberTextEditCtrl( fAdvancedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	resetDurationTextControl->SetToolTip( wxT("Duration to apply reset to target") );
	
	fgSizer1->Add( resetDurationTextControl, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticText6 = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxRIGHT|wxLEFT, 5 );
	
	resetReleaseIntervalStaticControl = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("Reset Release interval"), wxDefaultPosition, wxDefaultSize, 0 );
	resetReleaseIntervalStaticControl->Wrap( -1 );
	fgSizer1->Add( resetReleaseIntervalStaticControl, 0, wxRIGHT|wxLEFT, 5 );
	
	resetReleaseIntervalTextControl = new NumberTextEditCtrl( fAdvancedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	resetReleaseIntervalTextControl->SetToolTip( wxT("Interval to hold other target signals after reset release") );
	
	fgSizer1->Add( resetReleaseIntervalTextControl, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticText8 = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer1->Add( m_staticText8, 0, wxRIGHT|wxLEFT, 5 );
	
	resetRecoveryIntervalStaticControl = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("Reset Recovery Interval"), wxDefaultPosition, wxDefaultSize, 0 );
	resetRecoveryIntervalStaticControl->Wrap( -1 );
	fgSizer1->Add( resetRecoveryIntervalStaticControl, 0, wxRIGHT|wxLEFT, 5 );
	
	resetRecoveryIntervalTextControl = new NumberTextEditCtrl( fAdvancedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	resetRecoveryIntervalTextControl->SetToolTip( wxT("Interval to wait after target reset") );
	
	fgSizer1->Add( resetRecoveryIntervalTextControl, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText10 = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer1->Add( m_staticText10, 0, wxRIGHT|wxLEFT, 5 );
	
	
	sbSizer1->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer1, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( fAdvancedPanel, wxID_ANY, wxT("FlexNVM Parameters") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	eeepromSizeStaticText = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("EEEPROM Size (FF)"), wxDefaultPosition, wxDefaultSize, 0 );
	eeepromSizeStaticText->Wrap( -1 );
	fgSizer2->Add( eeepromSizeStaticText, 0, wxALL, 5 );
	
	wxArrayString eeepromSizeChoiceControlChoices;
	eeepromSizeChoiceControl = new wxChoice( fAdvancedPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, eeepromSizeChoiceControlChoices, 0 );
	eeepromSizeChoiceControl->SetSelection( 0 );
	eeepromSizeChoiceControl->SetToolTip( wxT("Controls size of emulated EEPROM region(s) in FlexRAM") );
	
	fgSizer2->Add( eeepromSizeChoiceControl, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText12 = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("bytes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer2->Add( m_staticText12, 0, wxALL, 5 );
	
	flexNvmPartitionStaticText = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("FlexNVM Partition (FF)"), wxDefaultPosition, wxDefaultSize, 0 );
	flexNvmPartitionStaticText->Wrap( -1 );
	fgSizer2->Add( flexNvmPartitionStaticText, 0, wxALL, 5 );
	
	wxArrayString flexNvmPartitionChoiceControlChoices;
	flexNvmPartitionChoiceControl = new wxChoice( fAdvancedPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, flexNvmPartitionChoiceControlChoices, 0 );
	flexNvmPartitionChoiceControl->SetSelection( 0 );
	flexNvmPartitionChoiceControl->SetToolTip( wxT("Controls FlexNVM division between Data Flash and EEPROM backing store\nEEPROM backing store size >= 16 x EEEPROM size - affects flash lifetime") );
	
	fgSizer2->Add( flexNvmPartitionChoiceControl, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText14 = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("Kbytes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	fgSizer2->Add( m_staticText14, 0, wxALL, 5 );
	
	
	sbSizer3->Add( fgSizer2, 1, wxEXPAND, 5 );
	
	flexNvmDescriptionStaticControl = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("EEPROM emulation will be disabled if device is mass erased"), wxDefaultPosition, wxDefaultSize, 0 );
	flexNvmDescriptionStaticControl->Wrap( -1 );
	sbSizer3->Add( flexNvmDescriptionStaticControl, 0, wxALL, 5 );
	
	
	bSizer1->Add( sbSizer3, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( fAdvancedPanel, wxID_ANY, wxT("Custom Security Parameters") ), wxVERTICAL );
	
	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxHORIZONTAL );
	
	customSecurityCheckbox = new wxCheckBox( fAdvancedPanel, wxID_ANY, wxT("Enable"), wxDefaultPosition, wxDefaultSize, 0 );
	customSecurityCheckbox->SetToolTip( wxT("Enable use of custom security values") );
	
	bSizer131->Add( customSecurityCheckbox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString securityMemoryRegionChoiceChoices;
	securityMemoryRegionChoice = new wxChoice( fAdvancedPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, securityMemoryRegionChoiceChoices, 0 );
	securityMemoryRegionChoice->SetSelection( 0 );
	securityMemoryRegionChoice->SetToolTip( wxT("Security information is programmed to this memory region") );
	
	bSizer131->Add( securityMemoryRegionChoice, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	resetCustomButtonControl = new wxButton( fAdvancedPanel, wxID_ANY, wxT("Reset Values"), wxDefaultPosition, wxDefaultSize, 0 );
	resetCustomButtonControl->SetToolTip( wxT("Reset custom values to unsecured default") );
	
	bSizer131->Add( resetCustomButtonControl, 0, wxALL, 5 );
	
	
	sbSizer41->Add( bSizer131, 0, wxEXPAND, 5 );
	
	securityValuesTextControl = new SecurityTextEditCtrl( fAdvancedPanel, wxID_ANY, wxT("12345678901234567890123456789012"), wxDefaultPosition, wxDefaultSize, 0 );
	securityValuesTextControl->SetToolTip( wxT("Security value used for device") );
	
	sbSizer41->Add( securityValuesTextControl, 0, wxALL|wxEXPAND, 5 );
	
	securityDescriptionStaticText = new wxStaticText( fAdvancedPanel, wxID_ANY, wxT("hello there\nbye bye"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	securityDescriptionStaticText->Wrap( -1 );
	securityDescriptionStaticText->SetToolTip( wxT("See Target tab to change how these value are used") );
	securityDescriptionStaticText->SetMinSize( wxSize( -1,100 ) );
	
	sbSizer41->Add( securityDescriptionStaticText, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer41, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	fAdvancedPanel->SetSizer( bSizer1 );
	fAdvancedPanel->Layout();
	bSizer1->Fit( fAdvancedPanel );
	fNotebook->AddPage( fAdvancedPanel, wxT("Advanced"), false );
	
	bSizer2->Add( fNotebook, 1, wxEXPAND | wxALL, 5 );
	
	StatusText = new wxStaticText( this, wxID_ANY, wxT("No Status"), wxDefaultPosition, wxDefaultSize, 0 );
	StatusText->Wrap( -1 );
	bSizer2->Add( StatusText, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxHORIZONTAL );
	
	keepChangesButton = new wxButton( this, wxID_KEEPCHANGES, wxT("Keep Changes"), wxDefaultPosition, wxDefaultSize, 0 );
	keepChangesButton->SetToolTip( wxT("Keep changes and return to GDB server") );
	
	bSizer132->Add( keepChangesButton, 0, wxALL, 5 );
	
	discardChangesButton = new wxButton( this, wxID_DISCARDCHANGES, wxT("Discard Changes"), wxDefaultPosition, wxDefaultSize, 0 );
	discardChangesButton->SetToolTip( wxT("Discard changes and return to GDB server") );
	
	bSizer132->Add( discardChangesButton, 0, wxALL, 5 );
	
	closeButton = new wxButton( this, wxID_OK, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	closeButton->SetToolTip( wxT("Close Programmer") );
	
	bSizer132->Add( closeButton, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	bSizer2->Add( bSizer132, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	bdmSelectChoiceControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnBdmSelectComboSelected ), NULL, this );
	bdmRefreshButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnRefreshBDMClick ), NULL, this );
	targetVddControl->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnVddSelectBoxSelected ), NULL, this );
	cycleVddOnResetControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnCycleVddOnResetCheckboxClick ), NULL, this );
	cycleVddOnConnectionControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnCycleTargetVddOnConnectionCheckboxClick ), NULL, this );
	leaveTargetPoweredControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnLeaveTargetOnCheckboxClick ), NULL, this );
	automaticallyReconnectControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnReconnectCheckboxClick ), NULL, this );
	useResetSignalControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnUseResetCheckboxClick ), NULL, this );
	usePstSignalControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnUseUsePstSignalCheckboxClick ), NULL, this );
	guessTargetSpeedControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnGuessSpeedCheckboxClick ), NULL, this );
	maskInterruptWhenSteppingControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnMaskInterruptsWhenSteppingCheckboxClick ), NULL, this );
	catchVllsResetControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnCatchVllsResetCheckboxClick ), NULL, this );
	connectionTimeoutTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnConnectionTimeoutTextTextUpdated ), NULL, this );
	interfaceSpeedControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnInterfaceSpeedSelectComboSelected ), NULL, this );
	bdmClockSelectControl->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnBdmClockSelectRadioboxSelected ), NULL, this );
	loadFileButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnLoadFileButtonClick ), NULL, this );
	incrementalFileLoadCheckBoxControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnIncrementalFileLoadCheckboxClick ), NULL, this );
	autoFileReloadCheckBoxControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnAutoFileReloadCheckboxClick ), NULL, this );
	deviceTypeChoiceControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnDeviceTypeChoiceSelected ), NULL, this );
	detectChipButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnDetectChipButtonClick ), NULL, this );
	filterByChipIdCheckBoxControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnFilterByChipIdCheckboxClick ), NULL, this );
	trimAddressTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnNonvolatileAddressTextTextUpdated ), NULL, this );
	trimFrequencyTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnTrimFrequencyTextTextUpdated ), NULL, this );
	trimFrequencyCheckBoxControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnTrimFrequencyCheckboxClick ), NULL, this );
	busFrequencyTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnBusFrequencyTextTextUpdated ), NULL, this );
	securityRadioBoxControl->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSecurityRadioboxSelected ), NULL, this );
	eraseChoiceControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnEraseChoiceSelect ), NULL, this );
	eraseNowButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnMassEraseButtonClick ), NULL, this );
	unlockButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnUnlockButtonClick ), NULL, this );
	enableSoundsCheckBoxControl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSoundCheckboxClick ), NULL, this );
	gdbServerPortNumberTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnGdbServerPortNumberTextUpdated ), NULL, this );
	programFlashButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnProgramFlashButtonClick ), NULL, this );
	verifyFlashButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnVerifyFlashButtonClick ), NULL, this );
	loadAndGoButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnLoadAndGoButtonClick ), NULL, this );
	powerOffDurationTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnPowerOffDurationText ), NULL, this );
	powerOnRecoveryIntervalTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnPowerOnDurationText ), NULL, this );
	resetDurationTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnResetDurationText ), NULL, this );
	resetReleaseIntervalTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnResetReleaseIntervalText ), NULL, this );
	resetRecoveryIntervalTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnResetRecoveryIntervalText ), NULL, this );
	eeepromSizeChoiceControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnEeepromSizeChoiceSelected ), NULL, this );
	flexNvmPartitionChoiceControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnFlexNvmPartionChoiceSelected ), NULL, this );
	customSecurityCheckbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSecurityCheckboxClick ), NULL, this );
	securityMemoryRegionChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSecurityMemoryRegionChoiceSelected ), NULL, this );
	resetCustomButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnResetCustomValueClick ), NULL, this );
	securityValuesTextControl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSecurityEditUpdate ), NULL, this );
	keepChangesButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnKeepChangesClick ), NULL, this );
	discardChangesButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnDiscardChangesClick ), NULL, this );
	closeButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnOkClick ), NULL, this );
}

UsbdmDialogueSkeleton::~UsbdmDialogueSkeleton()
{
	// Disconnect Events
	bdmSelectChoiceControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnBdmSelectComboSelected ), NULL, this );
	bdmRefreshButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnRefreshBDMClick ), NULL, this );
	targetVddControl->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnVddSelectBoxSelected ), NULL, this );
	cycleVddOnResetControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnCycleVddOnResetCheckboxClick ), NULL, this );
	cycleVddOnConnectionControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnCycleTargetVddOnConnectionCheckboxClick ), NULL, this );
	leaveTargetPoweredControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnLeaveTargetOnCheckboxClick ), NULL, this );
	automaticallyReconnectControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnReconnectCheckboxClick ), NULL, this );
	useResetSignalControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnUseResetCheckboxClick ), NULL, this );
	usePstSignalControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnUseUsePstSignalCheckboxClick ), NULL, this );
	guessTargetSpeedControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnGuessSpeedCheckboxClick ), NULL, this );
	maskInterruptWhenSteppingControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnMaskInterruptsWhenSteppingCheckboxClick ), NULL, this );
	catchVllsResetControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnCatchVllsResetCheckboxClick ), NULL, this );
	connectionTimeoutTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnConnectionTimeoutTextTextUpdated ), NULL, this );
	interfaceSpeedControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnInterfaceSpeedSelectComboSelected ), NULL, this );
	bdmClockSelectControl->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnBdmClockSelectRadioboxSelected ), NULL, this );
	loadFileButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnLoadFileButtonClick ), NULL, this );
	incrementalFileLoadCheckBoxControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnIncrementalFileLoadCheckboxClick ), NULL, this );
	autoFileReloadCheckBoxControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnAutoFileReloadCheckboxClick ), NULL, this );
	deviceTypeChoiceControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnDeviceTypeChoiceSelected ), NULL, this );
	detectChipButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnDetectChipButtonClick ), NULL, this );
	filterByChipIdCheckBoxControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnFilterByChipIdCheckboxClick ), NULL, this );
	trimAddressTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnNonvolatileAddressTextTextUpdated ), NULL, this );
	trimFrequencyTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnTrimFrequencyTextTextUpdated ), NULL, this );
	trimFrequencyCheckBoxControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnTrimFrequencyCheckboxClick ), NULL, this );
	busFrequencyTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnBusFrequencyTextTextUpdated ), NULL, this );
	securityRadioBoxControl->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSecurityRadioboxSelected ), NULL, this );
	eraseChoiceControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnEraseChoiceSelect ), NULL, this );
	eraseNowButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnMassEraseButtonClick ), NULL, this );
	unlockButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnUnlockButtonClick ), NULL, this );
	enableSoundsCheckBoxControl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSoundCheckboxClick ), NULL, this );
	gdbServerPortNumberTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnGdbServerPortNumberTextUpdated ), NULL, this );
	programFlashButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnProgramFlashButtonClick ), NULL, this );
	verifyFlashButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnVerifyFlashButtonClick ), NULL, this );
	loadAndGoButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnLoadAndGoButtonClick ), NULL, this );
	powerOffDurationTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnPowerOffDurationText ), NULL, this );
	powerOnRecoveryIntervalTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnPowerOnDurationText ), NULL, this );
	resetDurationTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnResetDurationText ), NULL, this );
	resetReleaseIntervalTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnResetReleaseIntervalText ), NULL, this );
	resetRecoveryIntervalTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnResetRecoveryIntervalText ), NULL, this );
	eeepromSizeChoiceControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnEeepromSizeChoiceSelected ), NULL, this );
	flexNvmPartitionChoiceControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnFlexNvmPartionChoiceSelected ), NULL, this );
	customSecurityCheckbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSecurityCheckboxClick ), NULL, this );
	securityMemoryRegionChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSecurityMemoryRegionChoiceSelected ), NULL, this );
	resetCustomButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnResetCustomValueClick ), NULL, this );
	securityValuesTextControl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnSecurityEditUpdate ), NULL, this );
	keepChangesButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnKeepChangesClick ), NULL, this );
	discardChangesButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnDiscardChangesClick ), NULL, this );
	closeButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsbdmDialogueSkeleton::OnOkClick ), NULL, this );
	
}
