///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GDBSERVERWINDOWSKELETON_H__
#define __GDBSERVERWINDOWSKELETON_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_DISABLE_INTERRUPTS 1000
#define wxID_CATCH_VLLS_ID 1001

///////////////////////////////////////////////////////////////////////////////
/// Class GdbServerWindowSkeleton
///////////////////////////////////////////////////////////////////////////////
class GdbServerWindowSkeleton : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* menuBar;
		wxMenu* serverMenu;
		wxMenuItem* m_menuItem1;
		wxMenuItem* m_separator1;
		wxMenuItem* m_menuItem2;
		wxMenuItem* m_menuItem3;
		wxMenu* logMenu;
		wxMenu* targetMenu;
		wxPanel* mainPanel;
		wxTextCtrl* statusTextControl;
		wxTextCtrl* entryTextControl;
		wxStatusBar* statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseWindow( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnChangeSettings( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDropConnection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClearLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDisableLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModerateLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVerboseLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHaltTarget( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetTarget( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetTimeout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToggleMaskISR( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToggleCatchVLLS( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEntryTextEnter( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GdbServerWindowSkeleton( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GDB Server"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 510,618 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GdbServerWindowSkeleton();
	
};

#endif //__GDBSERVERWINDOWSKELETON_H__
