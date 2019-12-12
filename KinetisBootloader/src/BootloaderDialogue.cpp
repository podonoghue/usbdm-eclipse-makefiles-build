/*
 * BootloaderDialogue.cpp
 *
 *  Created on: 9 Dec 2019
 *      Author: podonoghue
 */

#include "BootloaderDialogue.h"
#include "wx/filedlg.h"
#include "wx/msgdlg.h"
#include "FlashImageFactory.h"

BootloaderDialogue::BootloaderDialogue() : BootloaderDialogueSkeleton(nullptr) {
}

BootloaderDialogue::~BootloaderDialogue() {
}

void BootloaderDialogue::onLoadFile(wxCommandEvent &event) {
   wxString caption  = _("Select Binary File to Load");
   wxString wildcard = _(
         "Binary Files(*.s19,*.sx,*.s,*.srec,*.afx,*.axf,*.elf,*.abs,*.bin)|*.s19;*.sx;*.s;*.srec;*.afx;*.axf;*.elf;*.abs;*.bin|"
         "SREC Hex files (*.s19,*.sx,*.s,*.srec)|*.s19;*.sx;*.s;*.srec|"
         "Elf files (*.afx,*.axf,*.elf,*.abs)|*.afx;*.axf;*.elf;*.abs|"
         "Absolute Binary image files (*.bin,*.abs)|*.bin;*.abs|"
         "All Files|*");
   wxString defaultFilename  = wxEmptyString;
   wxString currentDirectory = wxEmptyString;
   wxFileDialog openFileDialog(this, caption, currentDirectory, defaultFilename, wildcard, wxFD_OPEN);
   int getCancelOK = openFileDialog.ShowModal();
   if (getCancelOK != wxID_OK) {
      // Ignore
      return;
   }

   wxString filePath = openFileDialog.GetPath();
   wxString fileName = openFileDialog.GetFilename();

   flashImage = FlashImageFactory::createFlashImage(T_ARM);
   USBDM_ErrorCode rc = flashImage->loadFile(filePath.ToStdString(), true);
   if (rc == SFILE_RC_OK) {
      loadedFile_static->SetLabel(fileName);
      programDevice_button->Enable(true);
      fprintf(
            stderr, "Image loaded: Flash[0x%08X..0x%08X]\n",
            flashImage->getFirstAllocatedAddress(),
            flashImage->getLastAllocatedAddress());
      fflush(stderr);
   }
   else {
      loadedFile_static->SetLabel("-- No file loaded --");
      programDevice_button->Enable(false);
      flashImage = nullptr;
      wxMessageBox(UsbdmSystem::getErrorString(rc), "Failed to load file");
   }
}

void BootloaderDialogue::onProgramDevice(wxCommandEvent &event) {
   programAction_static->SetLabel("Busy");
   if (flashImage != nullptr) {
      Bootloader bl;
      const char *errorMessage = bl.download(flashImage);
      if (errorMessage != nullptr) {
         programAction_static->SetLabel(errorMessage);
//         wxMessageBox(errorMessage, "Failed to download image to device");
      }
      else {
         programAction_static->SetLabel("Success");
      }
   }
}
