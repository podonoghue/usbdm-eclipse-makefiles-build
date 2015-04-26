///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include <wx/wx.h>

#include "MainDialogue.h"
#include "UsbdmSystem.h"
#include "JS16_Bootloader.h"
#include "ICP.h"
#include "Names.h"

///////////////////////////////////////////////////////////////////////////

struct BdmInfo {
   wxString    radioBoxChoice;
   const char *filename;
   const char *description;
};

BdmInfo bdmInfo[] = {
  {_("HCS08/HCS12/CFV1"),
        "FlashImages/JS16/USBDM_JS16CWJ_V4.sx",
        "Basic HCS08/HCS12/CFV1 BDM \n e.g. Witztronics, Wytec or TechnologicalArts."},
  {_("HCS08/HCS12/CFV1 + Serial"),
        "FlashImages/JS16/USBDM_SER_JS16CWJ_V4.sx",
        "HCS08/HCS12/CFV1 BDM with  \n USB serial function."},
  {_("CFVx/DSC/ARM-JTAG"),
        "FlashImages/JS16/USBDM_CF_JS16CWJ_V4.sx",
        "Basic CFVx/DSC/Kinetis-JTAG BDM."},
  {_("CFVx/DSC/ARM-JTAG + Serial"),
        "FlashImages/JS16/USBDM_CF_SER_JS16CWJ_V4.sx",
        "CFVx/DSC/Kinetis-JTAG BDM with  \n USB serial function."},
  {_("HCS08/HCS12/CFV1/ARM-SWD"),
        "FlashImages/JS16/USBDM_SWD_JS16CWJ_V4.sx",
        "Basic HCS08/HCS12/CFV1/Kinetis-SWD BDM."},
  {_("HCS08/HCS12/CFV1/ARM-SWD + Serial"),
        "FlashImages/JS16/USBDM_SWD_SER_JS16CWJ_V4.sx",
        "HCS08/HCS12/CFV1/Kinetis-SWD BDM with  \n USB serial function."},
};

MainDialogue::MainDialogue( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) :
         wxDialog( parent, id, title, pos, size, style ) {

   this->SetSizeHints( wxDefaultSize, wxDefaultSize );

   wxBoxSizer* m_MainSizer;
   m_MainSizer = new wxBoxSizer( wxVERTICAL );

   m_staticText = new wxStaticText( this, wxID_ANY,
         _("\n"
             "Tie the BLMS pin on the JS16 low\n"
             " (if it is not blank) and plug it in.\n\n"
             "Choose the firmware matching your hardware\n"
             "and then press the Program button.\n"
             ""),
         wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT, _("MainDialogue") );
   m_staticText->Wrap( -1 );
   m_MainSizer->Add( m_staticText, 0, wxALL|wxEXPAND, 5 );

   wxString radioBoxChoices[20];
   for (unsigned index=0; index < sizeof(bdmInfo)/sizeof(bdmInfo[0]); index++) {
      radioBoxChoices[index] = bdmInfo[index].radioBoxChoice;
   }
   m_radioBox = new wxRadioBox( this, wxID_ANY, _("BDM Firmware choice"),
                        wxDefaultPosition, wxDefaultSize, sizeof(bdmInfo)/sizeof(bdmInfo[0]), radioBoxChoices, 1, wxRA_SPECIFY_COLS );
   m_radioBox->SetSelection( 0 );
   m_MainSizer->Add( m_radioBox, 0, wxALL|wxEXPAND, 5 );

   descriptionText = new wxStaticText( this, wxID_ANY, _("Description of selected BDM"), wxDefaultPosition, wxDefaultSize, 0 );
   descriptionText->Wrap( -1 );
   m_MainSizer->Add( descriptionText, 1, wxALL|wxEXPAND, 5 );
   setDescription(0);

   wxBoxSizer* bSizer3;
   bSizer3 = new wxBoxSizer( wxHORIZONTAL );

   bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

   Program = new wxButton( this, wxID_PROGRAM, _("Program"), wxDefaultPosition, wxDefaultSize, 0 );
   bSizer3->Add( Program, 0, wxALL, 5 );

   Cancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
   bSizer3->Add( Cancel, 0, wxALL, 5 );


   m_MainSizer->Add( bSizer3, 0, wxEXPAND, 5 );


   this->SetSizer( m_MainSizer );
   this->Layout();

   this->Centre( wxBOTH );

   // Connect Events
   m_radioBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainDialogue::OnRadioBox ), NULL, this );
   Program->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialogue::OnProgramButtonClick ), NULL, this );
}

MainDialogue::~MainDialogue() {
   // Disconnect Events
   Program->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialogue::OnProgramButtonClick ), NULL, this );
}

void MainDialogue::OnProgramButtonClick( wxCommandEvent& event ) {
   LOGGING_E;
   int bdmType = m_radioBox->GetSelection();

   log.print("MainDialogue::OnProgramButtonClick() - Loading File %s\n",
         bdmInfo[bdmType].filename);
   ICP_ErrorType rc = ProgramFlash(bdmInfo[bdmType].filename);
   if (rc != ICP_RC_OK) {
      wxString msg = wxString::Format(_("Programming Failed   \n"
                                        "Reason: %s."), wxString(ICP_GetErrorName(rc), wxConvUTF8).c_str());
      wxMessageBox(msg, _("Programming Error"), wxOK|wxICON_ERROR, this);
   }
   else {
      wxMessageBox(_("Programming complete\n"
                     "Please remove & replace the BDM."),
                   _("Programming Done"), wxOK, this);
   }
}

void MainDialogue::setDescription(int bdmType) {
   descriptionText->SetLabel(wxString(bdmInfo[bdmType].description, wxConvUTF8));
}

void MainDialogue::OnRadioBox( wxCommandEvent& event ) {
   LOGGING_Q;
   int bdmType = m_radioBox->GetSelection();
   log.print("MainDialogue::OnRadioBox() - bdmType = %s\n", bdmInfo[bdmType].description);
   setDescription(bdmType);
}
