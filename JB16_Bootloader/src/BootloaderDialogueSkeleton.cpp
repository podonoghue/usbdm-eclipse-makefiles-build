///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BootloaderDialogueSkeleton.h"

///////////////////////////////////////////////////////////////////////////

BootloaderDialogueSkeleton::BootloaderDialogueSkeleton( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	instructionText = new wxStaticText( this, wxID_ANY, wxT("See Freescale AN2399 for details on how to force a blank JB16 device into ICP mode.\n\nIf it is already programmed with earlier USBDM firmware then select ICP Reboot button before programming.\n\nChoose the firmware matching your hardware and then press the Program button."), wxDefaultPosition, wxDefaultSize, 0 );
	instructionText->Wrap( -1 );
	bSizer1->Add( instructionText, 1, wxALL, 5 );

	wxString firmwareSelectionBoxChoices[] = { wxT("0"), wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5") };
	int firmwareSelectionBoxNChoices = sizeof( firmwareSelectionBoxChoices ) / sizeof( wxString );
	firmwareSelectionBox = new wxRadioBox( this, wxID_ANY, wxT("BDM Firmware Choice"), wxDefaultPosition, wxDefaultSize, firmwareSelectionBoxNChoices, firmwareSelectionBoxChoices, 1, wxRA_SPECIFY_COLS );
	firmwareSelectionBox->SetSelection( 0 );
	firmwareSelectionBox->SetToolTip( wxT("Select firmware version to load") );

	bSizer1->Add( firmwareSelectionBox, 0, wxALL|wxEXPAND, 5 );

	descriptionText = new wxStaticText( this, wxID_ANY, wxT("Custom file:\n"), wxDefaultPosition, wxDefaultSize, 0 );
	descriptionText->Wrap( -1 );
	descriptionText->SetToolTip( wxT("Description of selected firmware") );

	bSizer1->Add( descriptionText, 0, wxALL|wxEXPAND, 5 );

	buttonPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	loadSourceButton = new wxButton( buttonPanel, wxID_LOADSOURCE, wxT("&Load Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	loadSourceButton->SetToolTip( wxT("Select custom firmware file to program") );

	bSizer2->Add( loadSourceButton, 0, wxALL, 5 );

	rebootButton = new wxButton( buttonPanel, wxID_REBOOT, wxT("ICP &Reboot"), wxDefaultPosition, wxDefaultSize, 0 );
	rebootButton->SetToolTip( wxT("Reboot a USBDM BDM into ICP mode\nRequires a previously programmed JB16.") );

	bSizer2->Add( rebootButton, 0, wxALL, 5 );

	programButton = new wxButton( buttonPanel, wxID_PROGRAM, wxT("&Program"), wxDefaultPosition, wxDefaultSize, 0 );
	programButton->SetToolTip( wxT("Program selected firmware to BDM") );

	bSizer2->Add( programButton, 0, wxALL, 5 );


	buttonPanel->SetSizer( bSizer2 );
	buttonPanel->Layout();
	bSizer2->Fit( buttonPanel );
	bSizer1->Add( buttonPanel, 0, wxALIGN_RIGHT|wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	firmwareSelectionBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( BootloaderDialogueSkeleton::OnRadioBox ), NULL, this );
	loadSourceButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::OnLoadSourceButtonClick ), NULL, this );
	rebootButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::OnRebootButtonClick ), NULL, this );
	programButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::OnProgramButtonClick ), NULL, this );
}

BootloaderDialogueSkeleton::~BootloaderDialogueSkeleton()
{
	// Disconnect Events
	firmwareSelectionBox->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( BootloaderDialogueSkeleton::OnRadioBox ), NULL, this );
	loadSourceButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::OnLoadSourceButtonClick ), NULL, this );
	rebootButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::OnRebootButtonClick ), NULL, this );
	programButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::OnProgramButtonClick ), NULL, this );

}
