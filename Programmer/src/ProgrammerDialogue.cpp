/*
 * ProgrammerDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include <ProgrammerDialogue.h>

#include <wx/wx.h>

ProgrammerDialogue::ProgrammerDialogue(wxWindow* parent, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface) :
   UsbdmDialogue(parent, _("Flash Programmer"), bdmInterface, deviceInterface) {
}

ProgrammerDialogue::~ProgrammerDialogue() {
   LOGGING_E;
}

/*!
 * Get properties of target type modified for programmer
 *
 * @return Bit-mask describing properties
 *
 */
uint32_t ProgrammerDialogue::getTargetProperties(TargetType_t targetType) {
   LOGGING_E;

   uint32_t flags = UsbdmDialogue::getTargetProperties(targetType);

   // This is a programmer
   flags |= IS_PROGRAMMER;

   // These options don't apply to programmer
   flags &= ~HAS_CLK_SW;
   flags &= ~HAS_VLLS_RESET_CAPTURE;
   flags &= ~HAS_MASK_INTERRUPTS;

   log.print("Flags = 0x%08X\n", flags);

   return flags;
}

///*! Handler for OnOk
// *
// *  @param event The event to handle
// */
//void ProgrammerDialogue::OnOkClick( wxCommandEvent& event ) {
//   LOGGING;
//   if (TransferDataFromWindow()) {
//      wxWindow::Close();
////      EndModal(BDM_RC_OK);
//   }
//}

/*! This displays the Dialogue which represents the entire application
 *  for the stand-alone flash programmers.
 *
 *  @param hexFilename  Optional hex file to load
 *
 *  @return value from wxDialog::Show();
 */
bool ProgrammerDialogue::setUpAndShow(wxString const &hexFilename) {
   LOGGING;

   hideUnusedControls();
   Fit();
   Init();
   if (!hexFilename.IsEmpty() && (loadHexFile(hexFilename, true) != PROGRAMMING_RC_OK)) {
      log.print(" - Failed to load Hex file\n");
   }
   return Show();
}

extern wxApp& wxGetApp();

void ProgrammerDialogue::OnClose( wxCloseEvent& event ) {
   LOGGING;
   if (TransferDataFromWindow()) {
      log.print("done TransferDataFromWindow() - OK\n");
      wxGetApp().ExitMainLoop();
//      log.print("doing Destroy()\n");
//      Destroy();
   }
}

void ProgrammerDialogue::onCloseButton( wxCommandEvent& event ) {
   LOGGING;
   Close();
}
