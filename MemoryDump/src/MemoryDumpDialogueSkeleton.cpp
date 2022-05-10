///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep 11 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MemoryDumpDialogueSkeleton.h"

///////////////////////////////////////////////////////////////////////////

MemoryDumpDialogueSkeleton::MemoryDumpDialogueSkeleton( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Select BDM") ), wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	bdmRefreshButtonControl = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Detect"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( bdmRefreshButtonControl, 0, wxLEFT|wxRIGHT, 5 );

	bdmSelectChoiceControl = new wxComboBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("[No devices Found]"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY );
	bSizer3->Add( bdmSelectChoiceControl, 1, wxLEFT|wxRIGHT, 5 );


	sbSizer1->Add( bSizer3, 1, wxEXPAND, 5 );

	bdmDescriptionStaticControl = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Any BDM"), wxDefaultPosition, wxDefaultSize, 0 );
	bdmDescriptionStaticControl->Wrap( -1 );
	sbSizer1->Add( bdmDescriptionStaticControl, 0, wxALL, 5 );


	bSizer1->Add( sbSizer1, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wxString targetTypeRadioBoxChoices[] = { wxT("ARM"), wxT("CFV1 "), wxT("CFV2 "), wxT("HCS08 "), wxT("HCS12 "), wxT("RS08 "), wxT("s12Z") };
	int targetTypeRadioBoxNChoices = sizeof( targetTypeRadioBoxChoices ) / sizeof( wxString );
	targetTypeRadioBox = new wxRadioBox( this, wxID_ANY, wxT("Device Type"), wxDefaultPosition, wxDefaultSize, targetTypeRadioBoxNChoices, targetTypeRadioBoxChoices, 1, wxRA_SPECIFY_ROWS );
	targetTypeRadioBox->SetSelection( 4 );
	targetTypeRadioBox->SetToolTip( wxT("Select Target type") );

	bSizer1->Add( targetTypeRadioBox, 0, wxRIGHT|wxLEFT|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Memory Options") ), wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	memoryRangesGrid = new wxGrid( sbSizer3->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( 450,350 ), 0 );

	// Grid
	memoryRangesGrid->CreateGrid( 32, 3 );
	memoryRangesGrid->EnableEditing( true );
	memoryRangesGrid->EnableGridLines( true );
	memoryRangesGrid->EnableDragGridSize( false );
	memoryRangesGrid->SetMargins( 0, 0 );

	// Columns
	memoryRangesGrid->SetColSize( 0, 120 );
	memoryRangesGrid->SetColSize( 1, 120 );
	memoryRangesGrid->SetColSize( 2, 80 );
	memoryRangesGrid->EnableDragColMove( false );
	memoryRangesGrid->EnableDragColSize( true );
	memoryRangesGrid->SetColLabelValue( 0, wxT("Start") );
	memoryRangesGrid->SetColLabelValue( 1, wxT("End") );
	memoryRangesGrid->SetColLabelValue( 2, wxT("Width") );
	memoryRangesGrid->SetColLabelSize( 30 );
	memoryRangesGrid->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	memoryRangesGrid->EnableDragRowSize( false );
	memoryRangesGrid->SetRowLabelSize( 80 );
	memoryRangesGrid->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	memoryRangesGrid->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	memoryRangesGrid->SetToolTip( wxT("Enter one or more memory ranges") );

	bSizer5->Add( memoryRangesGrid, 1, wxRIGHT|wxLEFT|wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	wxString targetVddControlChoices[] = { wxT("Off"), wxT("3.3V   "), wxT("5V") };
	int targetVddControlNChoices = sizeof( targetVddControlChoices ) / sizeof( wxString );
	targetVddControl = new wxRadioBox( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Target Vdd Control"), wxDefaultPosition, wxDefaultSize, targetVddControlNChoices, targetVddControlChoices, 1, wxRA_SPECIFY_ROWS );
	targetVddControl->SetSelection( 1 );
	targetVddControl->SetToolTip( wxT("Off\t\t- Target Vdd is externally supplied\n3.3V\t- BDM supplies target Vdd @3.3V\n5V\t\t- BDM supplies target Vdd @5V") );

	bSizer4->Add( targetVddControl, 1, wxLEFT|wxRIGHT|wxEXPAND, 5 );


	bSizer8->Add( bSizer4, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Communication Speed") ), wxHORIZONTAL );

	wxString interfaceSpeedControlChoices[] = { wxT("250kHz"), wxT("500kHz"), wxT("750kHz"), wxT("1MHz") };
	int interfaceSpeedControlNChoices = sizeof( interfaceSpeedControlChoices ) / sizeof( wxString );
	interfaceSpeedControl = new wxChoice( sbSizer2->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, interfaceSpeedControlNChoices, interfaceSpeedControlChoices, 0 );
	interfaceSpeedControl->SetSelection( 0 );
	interfaceSpeedControl->Enable( false );

	sbSizer2->Add( interfaceSpeedControl, 1, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );


	bSizer8->Add( sbSizer2, 0, wxEXPAND|wxALL, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	initializationCheckbox = new wxCheckBox( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Initialization"), wxDefaultPosition, wxDefaultSize, 0 );
	initializationCheckbox->SetToolTip( wxT("Enable target initialization ") );

	bSizer7->Add( initializationCheckbox, 0, wxALL|wxEXPAND, 5 );

	initialializeTextCntrl = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	initialializeTextCntrl->SetToolTip( wxT("Memory values to write to target \n(address, data...)....\ne.g. (12,1E,23)(3D7F,2A)") );

	bSizer7->Add( initialializeTextCntrl, 1, wxALL|wxEXPAND, 5 );


	bSizer8->Add( bSizer7, 0, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 3, 1, 0 );
	fgSizer1->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	pagedFlashAddressCheckBox = new wxCheckBox( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Paged Flash"), wxDefaultPosition, wxDefaultSize, 0 );
	pagedFlashAddressCheckBox->SetValue(true);
	pagedFlashAddressCheckBox->SetToolTip( wxT("Use PPAGE register for flash memory in range [0x8000 0xBFFF]") );

	fgSizer1->Add( pagedFlashAddressCheckBox, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	flashPageRegisterStaticText = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("PPAGE Reg. Address:"), wxDefaultPosition, wxDefaultSize, 0 );
	flashPageRegisterStaticText->Wrap( -1 );
	flashPageRegisterStaticText->SetToolTip( wxT("Address of PPAGE Register used to select flash page accessed in [0x8000 0xBFFF]\nAssumes 24-bit paged addresses") );

	fgSizer1->Add( flashPageRegisterStaticText, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	flashPageTextCntrl = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxT("30"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !flashPageTextCntrl->HasFlag( wxTE_MULTILINE ) )
	{
	flashPageTextCntrl->SetMaxLength( 2 );
	}
	#else
	flashPageTextCntrl->SetMaxLength( 2 );
	#endif
	flashPageTextCntrl->SetToolTip( wxT("Address of PPAGE Register used to select page accessed in [0x8000 0xBFFF]\nAssumes 24-bit paged addresses") );

	fgSizer1->Add( flashPageTextCntrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	pagedEepromAddressCheckBox = new wxCheckBox( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Paged EEPROM"), wxDefaultPosition, wxDefaultSize, 0 );
	pagedEepromAddressCheckBox->SetValue(true);
	pagedEepromAddressCheckBox->SetToolTip( wxT("Use EPAGE register for flash memory in range [0x0800 0x0BFF]") );

	fgSizer1->Add( pagedEepromAddressCheckBox, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	eepromPageRegisterStaticText = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("EPAGE Reg Address:"), wxDefaultPosition, wxDefaultSize, 0 );
	eepromPageRegisterStaticText->Wrap( -1 );
	eepromPageRegisterStaticText->SetToolTip( wxT("Address of EPAGE Register used to select flash page accessed in [0x0800 0x0BFF]\nAssumes 24-bit paged addresses") );

	fgSizer1->Add( eepromPageRegisterStaticText, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	eepromPageTextCntrl = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxT("17"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !eepromPageTextCntrl->HasFlag( wxTE_MULTILINE ) )
	{
	eepromPageTextCntrl->SetMaxLength( 2 );
	}
	#else
	eepromPageTextCntrl->SetMaxLength( 2 );
	#endif
	eepromPageTextCntrl->SetToolTip( wxT("Address of EPAGE Register used to select page accessed in [0x0800 0x0BFF]\nAssumes 24-bit paged addresses") );

	fgSizer1->Add( eepromPageTextCntrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer8->Add( fgSizer1, 1, wxEXPAND, 5 );

	m_staticText3 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("\n[Start...End]\nAddress range\n(inclusive)\n\nWidth\nWidth of access\nSet to 0 to disable range \n\nValues in hex.\n"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetToolTip( wxT("Enter one or more memory ranges") );

	bSizer8->Add( m_staticText3, 0, wxALL|wxEXPAND, 5 );

	LoadSettingsButtonControl = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Load Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	LoadSettingsButtonControl->SetToolTip( wxT("Load settings from file") );

	bSizer8->Add( LoadSettingsButtonControl, 0, wxALL, 5 );

	SaveSettingsButtonControl = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Save Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	SaveSettingsButtonControl->SetToolTip( wxT("Save settings to file") );

	bSizer8->Add( SaveSettingsButtonControl, 0, wxALL, 5 );


	bSizer5->Add( bSizer8, 1, wxEXPAND, 5 );


	sbSizer3->Add( bSizer5, 1, 0, 5 );


	bSizer1->Add( sbSizer3, 1, wxEXPAND, 5 );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	readMemoryButton = new wxButton( m_panel1, wxID_ANY, wxT("Read Memory"), wxDefaultPosition, wxDefaultSize, 0 );
	readMemoryButton->SetToolTip( wxT("Read memory ranges into buffer") );

	bSizer2->Add( readMemoryButton, 0, wxALL, 5 );

	saveToFileButton = new wxButton( m_panel1, wxID_ANY, wxT("Save to File..."), wxDefaultPosition, wxDefaultSize, 0 );
	saveToFileButton->SetToolTip( wxT("Save memory buffer to file") );

	bSizer2->Add( saveToFileButton, 0, wxALL, 5 );

	keepEmptySRECsCheckbox = new wxCheckBox( m_panel1, wxID_ANY, wxT("Keep Empty SRECs"), wxDefaultPosition, wxDefaultSize, 0 );
	keepEmptySRECsCheckbox->SetToolTip( wxT("Keep S-records that only contain 0xFF") );

	bSizer2->Add( keepEmptySRECsCheckbox, 0, wxALL|wxEXPAND, 5 );


	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	bSizer1->Add( m_panel1, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer1->Add( m_staticText2, 0, wxRIGHT|wxLEFT|wxEXPAND, 5 );

	statusText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	bSizer1->Add( statusText, 1, wxEXPAND|wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	bdmRefreshButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnRefreshBDMClick ), NULL, this );
	bdmSelectChoiceControl->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnBdmSelectComboSelected ), NULL, this );
	targetTypeRadioBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnTargetTypeRadioBoxSelect ), NULL, this );
	targetVddControl->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnTargetVddControlClick ), NULL, this );
	interfaceSpeedControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnInterfaceSpeedSelectComboSelected ), NULL, this );
	initializationCheckbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnInitializationCheckboxChange ), NULL, this );
	pagedFlashAddressCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnPagedCheckBoxEvent ), NULL, this );
	flashPageTextCntrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnPageAddressChange ), NULL, this );
	pagedEepromAddressCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnPagedCheckBoxEvent ), NULL, this );
	LoadSettingsButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnLoadSettingsClick ), NULL, this );
	SaveSettingsButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnSaveSettingsClick ), NULL, this );
	readMemoryButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnReadMemoryButtonClick ), NULL, this );
	saveToFileButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnSaveToFileButton ), NULL, this );
	keepEmptySRECsCheckbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnKeepEmptySRECsCheckboxClick ), NULL, this );
}

MemoryDumpDialogueSkeleton::~MemoryDumpDialogueSkeleton()
{
	// Disconnect Events
	bdmRefreshButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnRefreshBDMClick ), NULL, this );
	bdmSelectChoiceControl->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnBdmSelectComboSelected ), NULL, this );
	targetTypeRadioBox->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnTargetTypeRadioBoxSelect ), NULL, this );
	targetVddControl->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnTargetVddControlClick ), NULL, this );
	interfaceSpeedControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnInterfaceSpeedSelectComboSelected ), NULL, this );
	initializationCheckbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnInitializationCheckboxChange ), NULL, this );
	pagedFlashAddressCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnPagedCheckBoxEvent ), NULL, this );
	flashPageTextCntrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnPageAddressChange ), NULL, this );
	pagedEepromAddressCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnPagedCheckBoxEvent ), NULL, this );
	LoadSettingsButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnLoadSettingsClick ), NULL, this );
	SaveSettingsButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnSaveSettingsClick ), NULL, this );
	readMemoryButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnReadMemoryButtonClick ), NULL, this );
	saveToFileButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnSaveToFileButton ), NULL, this );
	keepEmptySRECsCheckbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnKeepEmptySRECsCheckboxClick ), NULL, this );

}
