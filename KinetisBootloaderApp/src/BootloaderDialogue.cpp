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
#include "MyException.h"

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
   wxFileDialog openFileDialog(this, caption, currentDirectory, defaultFilename, wildcard, wxFD_OPEN);
   int getCancelOK = openFileDialog.ShowModal();
   if (getCancelOK != wxID_OK) {
      // Ignore
      return;
   }
   // Save for next time
   currentDirectory = openFileDialog.GetDirectory();
   defaultFilename  = openFileDialog.GetFilename();

   wxString filePath = openFileDialog.GetPath();
   wxString fileName = openFileDialog.GetFilename();

   USBDM_ErrorCode rc = PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   try {
      flashImage = FlashImageFactory::createFlashImage(T_ARM);
      rc = flashImage->loadFile(filePath.ToStdString(), true);
   } catch (MyException &e) {
      fprintf(stderr, "%s", e.what());
      flashImage = nullptr;
   };

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

void BootloaderDialogue::onCheckDevice(wxCommandEvent &event) {
   checkDevice_textCtrl->SetLabel("Busy");
   Bootloader bl;
   ResponseIdentify identity;
   const char *msg = bl.getDeviceInformation(identity);

   if (msg == nullptr) {
      wxString status = wxString::Format(
            "Hardware Version   = %s\r\n"
            "Bootloader Version = %d\r\n"
            "Image H/W Version  = %s\r\n"
            "Image Version      = %d\r\n"
            "Flash Image[0x%08X..0x%08X]",
            getHardwareType(identity.bootHardwareVersion),
            identity.bootSoftwareVersion,
            getHardwareType(identity.imageHardwareVersion),
            identity.imageSoftwareVersion,
            identity.flashStart,
            identity.flashStart+identity.flashSize-1
            );
      checkDevice_textCtrl->ChangeValue(status);
   }
   else {
      checkDevice_textCtrl->ChangeValue(msg);
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


