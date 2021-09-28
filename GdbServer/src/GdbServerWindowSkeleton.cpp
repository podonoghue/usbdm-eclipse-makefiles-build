///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Sep 11 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GdbServerWindowSkeleton.h"

///////////////////////////////////////////////////////////////////////////

GdbServerWindowSkeleton::GdbServerWindowSkeleton( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	menuBar = new wxMenuBar( 0 );
	serverMenu = new wxMenu();
	m_menuItem1 = new wxMenuItem( serverMenu, wxID_ANY, wxString( wxT("&Change Server Settings") ) , wxT("Restart server with new settings"), wxITEM_NORMAL );
	serverMenu->Append( m_menuItem1 );

	m_separator1 = serverMenu->AppendSeparator();

	m_menuItem2 = new wxMenuItem( serverMenu, wxID_ANY, wxString( wxT("&Drop Connection") ) , wxT("Forcibly drop connection"), wxITEM_NORMAL );
	serverMenu->Append( m_menuItem2 );

	m_menuItem3 = new wxMenuItem( serverMenu, wxID_ANY, wxString( wxT("E&xit\tAlt-X") ) , wxT("Quit server"), wxITEM_NORMAL );
	serverMenu->Append( m_menuItem3 );

	menuBar->Append( serverMenu, wxT("Server") );

	logMenu = new wxMenu();
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( logMenu, wxID_ANY, wxString( wxT("&Clear") ) , wxT("Clear log window"), wxITEM_NORMAL );
	logMenu->Append( m_menuItem6 );

	logMenu->AppendSeparator();

	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem( logMenu, wxID_ANY, wxString( wxT("&Off") ) , wxT("Turn off logging"), wxITEM_RADIO );
	logMenu->Append( m_menuItem7 );

	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( logMenu, wxID_ANY, wxString( wxT("&Moderate") ) , wxT("Turn on moderate logging"), wxITEM_RADIO );
	logMenu->Append( m_menuItem8 );

	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( logMenu, wxID_ANY, wxString( wxT("&Verbose") ) , wxT("Turn on verbose logging"), wxITEM_RADIO );
	logMenu->Append( m_menuItem9 );

	menuBar->Append( logMenu, wxT("Log") );

	targetMenu = new wxMenu();
	wxMenuItem* m_menuItem121;
	m_menuItem121 = new wxMenuItem( targetMenu, wxID_ANY, wxString( wxT("&Halt Target") ) , wxEmptyString, wxITEM_NORMAL );
	targetMenu->Append( m_menuItem121 );

	wxMenuItem* m_menuItem10;
	m_menuItem10 = new wxMenuItem( targetMenu, wxID_ANY, wxString( wxT("&Reset Target") ) , wxT("Reset target"), wxITEM_NORMAL );
	targetMenu->Append( m_menuItem10 );

	wxMenuItem* m_menuItem12;
	m_menuItem12 = new wxMenuItem( targetMenu, wxID_ANY, wxString( wxT("&Set Timeout") ) , wxT("How long to wait (0 = infinite)"), wxITEM_NORMAL );
	targetMenu->Append( m_menuItem12 );

	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( targetMenu, wxID_DISABLE_INTERRUPTS, wxString( wxT("&Mask Interrupts") ) , wxT("Mask interrupts when stepping"), wxITEM_CHECK );
	targetMenu->Append( m_menuItem11 );

	wxMenuItem* m_menuItem13;
	m_menuItem13 = new wxMenuItem( targetMenu, wxID_CATCH_VLLS_ID, wxString( wxT("&Stop on VLLS reset") ) , wxT("Target stops on VLLS reset"), wxITEM_CHECK );
	targetMenu->Append( m_menuItem13 );

	menuBar->Append( targetMenu, wxT("Target") );

	this->SetMenuBar( menuBar );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	mainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	statusTextControl = new wxTextCtrl( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	bSizer2->Add( statusTextControl, 1, wxEXPAND, 5 );

	entryTextControl = new wxTextCtrl( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer2->Add( entryTextControl, 0, wxEXPAND, 5 );


	mainPanel->SetSizer( bSizer2 );
	mainPanel->Layout();
	bSizer2->Fit( mainPanel );
	bSizer1->Add( mainPanel, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	statusBar = this->CreateStatusBar( 2, wxSTB_SIZEGRIP, wxID_ANY );
	statusBar->Enable( false );


	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GdbServerWindowSkeleton::OnCloseWindow ) );
	serverMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnChangeSettings ), this, m_menuItem1->GetId());
	serverMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnDropConnection ), this, m_menuItem2->GetId());
	serverMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnQuit ), this, m_menuItem3->GetId());
	logMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnClearLog ), this, m_menuItem6->GetId());
	logMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnDisableLog ), this, m_menuItem7->GetId());
	logMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnModerateLog ), this, m_menuItem8->GetId());
	logMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnVerboseLog ), this, m_menuItem9->GetId());
	targetMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnHaltTarget ), this, m_menuItem121->GetId());
	targetMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnResetTarget ), this, m_menuItem10->GetId());
	targetMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnSetTimeout ), this, m_menuItem12->GetId());
	targetMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnToggleMaskISR ), this, m_menuItem11->GetId());
	targetMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GdbServerWindowSkeleton::OnToggleCatchVLLS ), this, m_menuItem13->GetId());
	entryTextControl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GdbServerWindowSkeleton::OnEntryTextEnter ), NULL, this );
}

GdbServerWindowSkeleton::~GdbServerWindowSkeleton()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GdbServerWindowSkeleton::OnCloseWindow ) );
	entryTextControl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GdbServerWindowSkeleton::OnEntryTextEnter ), NULL, this );

}
