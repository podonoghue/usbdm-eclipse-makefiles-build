///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep 11 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "NumberTextEditCtrl.h"

#include "FirmwareChangerSkeleton.h"

///////////////////////////////////////////////////////////////////////////

FirmwareChangerSkeleton::FirmwareChangerSkeleton( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("File to Load") ), wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	loadFirmwareButton = new wxButton( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Load Firmware File..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( loadFirmwareButton, 0, wxALL, 5 );

	autoSelectFirmwareCheckbox = new wxCheckBox( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Auto select BDM firmware"), wxDefaultPosition, wxDefaultSize, 0 );
	autoSelectFirmwareCheckbox->SetValue(true);
	autoSelectFirmwareCheckbox->SetToolTip( wxT("Select firmware and serial number based on current firmware in device") );

	bSizer5->Add( autoSelectFirmwareCheckbox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	sbSizer2->Add( bSizer5, 1, wxEXPAND, 5 );

	filenameStaticText = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("No file loaded"), wxDefaultPosition, wxDefaultSize, 0 );
	filenameStaticText->Wrap( -1 );
	sbSizer2->Add( filenameStaticText, 0, wxALL, 5 );


	bSizer1->Add( sbSizer2, 0, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer31;
	sbSizer31 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Device serial number") ), wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	serialNumberText = new wxTextCtrl( sbSizer31->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	serialNumberText->SetToolTip( wxT("Serial number to be written to device") );

	bSizer3->Add( serialNumberText, 1, wxALL, 5 );

	autoSequenceText = new NumberTextEditCtrl( sbSizer31->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !autoSequenceText->HasFlag( wxTE_MULTILINE ) )
	{
	autoSequenceText->SetMaxLength( 5 );
	}
	#else
	autoSequenceText->SetMaxLength( 5 );
	#endif
	autoSequenceText->SetToolTip( wxT("Number for sequence") );

	bSizer3->Add( autoSequenceText, 0, wxALL, 5 );


	sbSizer31->Add( bSizer3, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	readSerialNumberButton = new wxButton( sbSizer31->GetStaticBox(), wxID_ANY, wxT("Read serial number from device"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( readSerialNumberButton, 0, wxALL, 5 );

	autoSequenceCheckbox = new wxCheckBox( sbSizer31->GetStaticBox(), wxID_ANY, wxT("Auto sequence"), wxDefaultPosition, wxDefaultSize, 0 );
	autoSequenceCheckbox->SetToolTip( wxT("Append sequental number to serial number") );

	bSizer4->Add( autoSequenceCheckbox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	sbSizer31->Add( bSizer4, 0, wxEXPAND, 5 );


	bSizer1->Add( sbSizer31, 0, wxEXPAND|wxALL, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Firmware File Information") ), wxVERTICAL );

	fileInformationStaticText = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CHARWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_WORDWRAP );
	fileInformationStaticText->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Typewriter") ) );
	fileInformationStaticText->Enable( false );
	fileInformationStaticText->SetToolTip( wxT("Description of Flash image") );

	sbSizer3->Add( fileInformationStaticText, 1, wxALL|wxEXPAND, 5 );


	bSizer1->Add( sbSizer3, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	statusStaticText = new wxStaticText( this, wxID_ANY, wxT("Status: Idle"), wxDefaultPosition, wxDefaultSize, 0 );
	statusStaticText->Wrap( -1 );
	bSizer71->Add( statusStaticText, 0, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 5 );


	bSizer1->Add( bSizer71, 0, wxEXPAND|wxALL, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	programFlashButton = new wxButton( this, wxID_ANY, wxT("Program Flash"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( programFlashButton, 1, wxALL|wxEXPAND, 5 );

	verifyButton = new wxButton( this, wxID_ANY, wxT("Verify Flash"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( verifyButton, 1, wxALL|wxEXPAND, 5 );

	exitButton = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( exitButton, 1, wxALL|wxEXPAND, 5 );


	bSizer1->Add( bSizer7, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	loadFirmwareButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnLoadFirmwareButtonClick ), NULL, this );
	autoSelectFirmwareCheckbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnAutoSelectFirmwareCheckboxClick ), NULL, this );
	serialNumberText->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FirmwareChangerSkeleton::OnSerialnumTextctrlTextUpdated ), NULL, this );
	autoSequenceText->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FirmwareChangerSkeleton::OnAutoSequenceTextControlTextUpdated ), NULL, this );
	readSerialNumberButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnReadSerialNumButtonClick ), NULL, this );
	autoSequenceCheckbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnAutoSequenceCheckboxClick ), NULL, this );
	programFlashButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnProgramFlashButtonClick ), NULL, this );
	verifyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnVerifyFlashButtonClick ), NULL, this );
	exitButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnExitButtonClick ), NULL, this );
}

FirmwareChangerSkeleton::~FirmwareChangerSkeleton()
{
	// Disconnect Events
	loadFirmwareButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnLoadFirmwareButtonClick ), NULL, this );
	autoSelectFirmwareCheckbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnAutoSelectFirmwareCheckboxClick ), NULL, this );
	serialNumberText->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FirmwareChangerSkeleton::OnSerialnumTextctrlTextUpdated ), NULL, this );
	autoSequenceText->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FirmwareChangerSkeleton::OnAutoSequenceTextControlTextUpdated ), NULL, this );
	readSerialNumberButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnReadSerialNumButtonClick ), NULL, this );
	autoSequenceCheckbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnAutoSequenceCheckboxClick ), NULL, this );
	programFlashButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnProgramFlashButtonClick ), NULL, this );
	verifyButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnVerifyFlashButtonClick ), NULL, this );
	exitButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FirmwareChangerSkeleton::OnExitButtonClick ), NULL, this );

}
