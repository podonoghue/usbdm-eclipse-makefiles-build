/*
 * ProgrammerDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include <ProgrammerDialogue.h>

ProgrammerDialogue::ProgrammerDialogue(wxWindow* parent, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface) :
   UsbdmDialogue(parent, _("Flash Programmer"), bdmInterface, deviceInterface) {
}

ProgrammerDialogue::~ProgrammerDialogue() {
}

uint32_t ProgrammerDialogue::getTargetProperties(TargetType_t targetType) {
   LOGGING_E;
   uint32_t flags = UsbdmDialogue::getTargetProperties(targetType);
   flags |= IS_PROGRAMMER;

   // These options don't apply to programmer
   flags &= ~HAS_CLK_SW;
   flags &= ~HAS_VLLS_RESET_CAPTURE;
   flags &= ~HAS_MASK_INTERRUPTS;

   log.print("Flags = 0x%08X\n", flags);

   return flags;
}

/*! Handler for OnOk
 *
 *  @param event The event to handle
 */
void ProgrammerDialogue::OnOkClick( wxCommandEvent& event ) {
   if (TransferDataFromWindow()) {
      EndModal(BDM_RC_OK);
   }
}

/*! This displays the Dialogue which represents the entire application
 *  for the stand-alone flash programmers.  Accepts starting parameters.
 *
 *  @param settingsFilename Base name of settings file to use
 *  @param hexFilename      Hex file to load
 *
 *  @return BDM_RC_OK - no useful return vale
 */
USBDM_ErrorCode ProgrammerDialogue::execute(AppSettingsPtr appSettings, wxString const &hexFilename) {
   LOGGING;

   hideUnusedControls();
   Fit();

   Init();

   if (!hexFilename.IsEmpty() && (loadHexFile(hexFilename, true) != PROGRAMMING_RC_OK)) {
      log.print(" - Failed to load Hex file\n");
   }

   loadSettings(*appSettings);

   USBDM_ErrorCode result = (USBDM_ErrorCode)ShowModal();

   if (result == BDM_RC_OK) {
      saveSettings(*appSettings);
   }
   else {
      // Restore setting to original values
      loadSettings(*appSettings);
   }
   return result;
}

