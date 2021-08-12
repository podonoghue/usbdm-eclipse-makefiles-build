///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep  6 2020)
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

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Flash Image") ), wxHORIZONTAL );

	loadFile_button = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Load File"), wxDefaultPosition, wxDefaultSize, 0 );
	loadFile_button->SetToolTip( wxT("Load file to program to device") );

	sbSizer1->Add( loadFile_button, 0, wxALL|wxEXPAND, 5 );

	loadedFile_static = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("-- no file loaded --"), wxDefaultPosition, wxDefaultSize, 0 );
	loadedFile_static->Wrap( -1 );
	loadedFile_static->SetToolTip( wxT("Name of currently loaded file") );

	sbSizer1->Add( loadedFile_static, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer1->Add( sbSizer1, 1, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Device Information") ), wxHORIZONTAL );

	checkDevice_button = new wxButton( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Check Device"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( checkDevice_button, 0, wxALL|wxEXPAND, 5 );

	checkDevice_textCtrl = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxT("-- no information --"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	checkDevice_textCtrl->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	sbSizer2->Add( checkDevice_textCtrl, 1, wxALL|wxEXPAND, 5 );


	bSizer1->Add( sbSizer2, 2, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Programming") ), wxHORIZONTAL );

	programDevice_button = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Program Device"), wxDefaultPosition, wxDefaultSize, 0 );
	programDevice_button->Enable( false );
	programDevice_button->SetToolTip( wxT("Program file to device") );

	sbSizer3->Add( programDevice_button, 0, wxALL|wxEXPAND, 5 );

	programAction_static = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("-- no action --"), wxDefaultPosition, wxDefaultSize, 0 );
	programAction_static->Wrap( -1 );
	programAction_static->SetToolTip( wxT("Result of last programming attempt") );

	sbSizer3->Add( programAction_static, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer1->Add( sbSizer3, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	loadFile_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::onLoadFile ), NULL, this );
	checkDevice_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::onCheckDevice ), NULL, this );
	programDevice_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::onProgramDevice ), NULL, this );
}

BootloaderDialogueSkeleton::~BootloaderDialogueSkeleton()
{
	// Disconnect Events
	loadFile_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::onLoadFile ), NULL, this );
	checkDevice_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::onCheckDevice ), NULL, this );
	programDevice_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BootloaderDialogueSkeleton::onProgramDevice ), NULL, this );

}
