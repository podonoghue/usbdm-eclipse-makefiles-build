///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep 11 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MemoryDumpDialogueSkeleton.h"
#include "UsbdmSystem.h"

///////////////////////////////////////////////////////////////////////////

MemoryDumpDialogueSkeleton::MemoryDumpDialogueSkeleton( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
   LOGGING;
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


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	bdmRefreshButtonControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnRefreshBDMClick ), NULL, this );
//	bdmSelectChoiceControl->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnBdmSelectComboSelected ), NULL, this );

   log.print("Before %p = \n", bdmSelectChoiceControl);
   bdmSelectChoiceControl->SetSelection(0);
   log.print("After %p = \n", bdmSelectChoiceControl);
   bdmSelectChoiceControl->SetSelection(0);
   log.print("After2 %p = \n", bdmSelectChoiceControl);
}

MemoryDumpDialogueSkeleton::~MemoryDumpDialogueSkeleton()
{
	// Disconnect Events
	bdmRefreshButtonControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnRefreshBDMClick ), NULL, this );
	bdmSelectChoiceControl->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnBdmSelectComboSelected ), NULL, this );

}
