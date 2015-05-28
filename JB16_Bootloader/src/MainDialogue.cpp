///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include <wx/wx.h>

#include "MainDialogue.h"
#include "UsbdmSystem.h"
#include "JB16_Bootloader.h"
#include "ICP.h"
#include "Names.h"

///////////////////////////////////////////////////////////////////////////

struct BdmInfo {
   wxString    radioBoxChoice;
   const char *filename;
   const char *description;
};

BdmInfo bdmInfo[] = {
  {_("Custom"),  "",  "Use custom file: "},
  {_("OSBDM"),  "FlashImages/JB16/OSBDM_JB16.s19",  "Original OSBDM."},
  {_("OSBDME"), "FlashImages/JB16/OSBDME_JB16.s19", "Extended OSBDM."},
  {_("TBDML"),  "FlashImages/JB16/TBDML_JB16.s19",  "Original TBDML."},
  {_("USBDM"),  "FlashImages/JB16/USBDM_JB16.s19",  "Original USBDM."},
  {_("WTBDM"),  "FlashImages/JB16/WTBDM_JB16.s19",  "Original Witztronics TBDML."},
};

MainDialogue::MainDialogue( wxWindow* parent ) :
      BootloaderDialogueSkeleton( parent) {

   for (unsigned index=0; index < sizeof(bdmInfo)/sizeof(bdmInfo[0]); index++) {
      firmwareSelectionBox->SetString(index, bdmInfo[index].radioBoxChoice);
   }
}

MainDialogue::~MainDialogue() {}

void MainDialogue::OnRebootButtonClick( wxCommandEvent& event ) {
   LOGGING;

   ICP_ErrorType rc = RebootDevice();
   if (rc != RC_OK) {
      log.error("Reboot failed, rc = %s\n", ICP_GetErrorName(rc));
      wxString msg = wxString::Format(_("Rebooting Failed   \n"
                                        "Reason: %s."), wxString(ICP_GetErrorName(rc), wxConvUTF8).c_str());
      wxMessageBox(msg, _("Reboot Error"), wxOK|wxICON_ERROR, this);
   }
   else {
      wxMessageBox(_("Reboot done\n"),
                   _("Rebooted to ICP mode"), wxOK, this);
   }
}

void MainDialogue::OnProgramButtonClick( wxCommandEvent& event ) {
   LOGGING_E;
   int bdmType = firmwareSelectionBox->GetSelection();

   std::string filename;
   if (bdmType>0) {
      filename = UsbdmSystem::getResourcePath(bdmInfo[bdmType].filename);
   }
   else {
      filename = this->customPath;
   }
   ICP_ErrorType rc = ProgramFlash(filename);
   if (rc != RC_OK) {
      log.error("Programming failed, rc = %s\n", ICP_GetErrorName(rc));
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

void MainDialogue::setDescription(std::string description) {
   descriptionText->SetLabel(wxString(description));
}

void MainDialogue::OnRadioBox( wxCommandEvent& event ) {
   LOGGING_Q;
   int bdmType = firmwareSelectionBox->GetSelection();
   std::string description = bdmInfo[bdmType].description;
   if (bdmType == 0) {
      description.append(customFilename.ToAscii());
   }
   loadSourceButton->Enable(bdmType==0);
   log.print("MainDialogue::OnRadioBox() - bdmType = %s\n", description.c_str());
   setDescription(description);
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FILE_LOAD_BUTTON
 */
void MainDialogue::OnLoadSourceButtonClick( wxCommandEvent& event ) {
   LOGGING_Q;
   wxString caption         = _("Choose a firmware file");
   wxString wildcard = _("Binary Files(*.s19,*.sx,*.s,*.afx,*.axf,*.elf)|*.s19;*.sx;*.s;*.afx;*.axf;*.elf|"
                         "SREC Hex files (*.s19,*.sx,*.s)|*.s19;*.sx;*.s|"
                         "Elf files (*.afx,*.axf,*.elf)|*.afx;*.axf;*.elf|"
                         "All Files|*");
   wxString defaultDir      = wxEmptyString;
   wxString defaultFilename = wxEmptyString;
   wxFileDialog dialog(this, caption, defaultDir, defaultFilename, wildcard, wxFD_OPEN);
   if (dialog.ShowModal() == wxID_OK) {
      customFilename = dialog.GetFilename();
      customPath     = dialog.GetPath();
      log.print("customFilename = \'%s\'\n", (const char *)customFilename.c_str());
      log.print("customPath     = \'%s\'\n", (const char *)customPath.c_str());
   }
   OnRadioBox(event);
}
