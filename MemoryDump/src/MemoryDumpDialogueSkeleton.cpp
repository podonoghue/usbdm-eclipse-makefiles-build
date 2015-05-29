///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MemoryDumpDialogueSkeleton.h"

///////////////////////////////////////////////////////////////////////////

MemoryDumpDialogueSkeleton::MemoryDumpDialogueSkeleton( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxString targetTypeRadioBoxChoices[] = { wxT("ARM"), wxT("CFV1 "), wxT("CFV2 "), wxT("HCS08 "), wxT("HCS12 "), wxT("RS08 ") };
	int targetTypeRadioBoxNChoices = sizeof( targetTypeRadioBoxChoices ) / sizeof( wxString );
	targetTypeRadioBox = new wxRadioBox( this, wxID_ANY, wxT("Device Type"), wxDefaultPosition, wxDefaultSize, targetTypeRadioBoxNChoices, targetTypeRadioBoxChoices, 1, wxRA_SPECIFY_ROWS );
	targetTypeRadioBox->SetSelection( 0 );
	targetTypeRadioBox->SetToolTip( wxT("Select Target type") );
	
	bSizer1->Add( targetTypeRadioBox, 0, wxALL|wxEXPAND, 5 );
	
	memoryRangesGrid = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	memoryRangesGrid->CreateGrid( 10, 3 );
	memoryRangesGrid->EnableEditing( true );
	memoryRangesGrid->EnableGridLines( true );
	memoryRangesGrid->EnableDragGridSize( false );
	memoryRangesGrid->SetMargins( 0, 0 );
	
	// Columns
	memoryRangesGrid->EnableDragColMove( false );
	memoryRangesGrid->EnableDragColSize( true );
	memoryRangesGrid->SetColLabelSize( 30 );
	memoryRangesGrid->SetColLabelValue( 0, wxT("Start") );
	memoryRangesGrid->SetColLabelValue( 1, wxT("End") );
	memoryRangesGrid->SetColLabelValue( 2, wxT("Width") );
	memoryRangesGrid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	memoryRangesGrid->EnableDragRowSize( true );
	memoryRangesGrid->SetRowLabelSize( 80 );
	memoryRangesGrid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	memoryRangesGrid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	memoryRangesGrid->SetToolTip( wxT("Enter one or more memory ranges") );
	
	bSizer1->Add( memoryRangesGrid, 0, wxALL, 5 );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	readMemoryButton = new wxButton( m_panel1, wxID_ANY, wxT("Read Memory"), wxDefaultPosition, wxDefaultSize, 0 );
	readMemoryButton->SetToolTip( wxT("Read memory ranges into buffer") );
	
	bSizer2->Add( readMemoryButton, 0, wxALL, 5 );
	
	saveToFileButton = new wxButton( m_panel1, wxID_ANY, wxT("Save to File..."), wxDefaultPosition, wxDefaultSize, 0 );
	saveToFileButton->SetToolTip( wxT("Save memory buffer to file") );
	
	bSizer2->Add( saveToFileButton, 0, wxALL, 5 );
	
	
	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	bSizer1->Add( m_panel1, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer1->Add( m_staticText2, 0, wxALL, 5 );
	
	statusText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	bSizer1->Add( statusText, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	targetTypeRadioBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnTargetTypeRadioBox ), NULL, this );
	readMemoryButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnReadMemoryButtonClick ), NULL, this );
	saveToFileButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnSaveToFileButton ), NULL, this );
}

MemoryDumpDialogueSkeleton::~MemoryDumpDialogueSkeleton()
{
	// Disconnect Events
	targetTypeRadioBox->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnTargetTypeRadioBox ), NULL, this );
	readMemoryButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnReadMemoryButtonClick ), NULL, this );
	saveToFileButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MemoryDumpDialogueSkeleton::OnSaveToFileButton ), NULL, this );
	
}
