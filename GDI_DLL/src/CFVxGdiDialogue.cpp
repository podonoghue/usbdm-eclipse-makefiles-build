/*
 * CFVxGdiDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include <CFVxGdiDialogue.h>

CFVxGdiDialogue::CFVxGdiDialogue(wxWindow* parent, BdmInterfacePtr bdmInterface) :
   GdiDialogue(parent, bdmInterface) {
}

CFVxGdiDialogue::~CFVxGdiDialogue() {
}

uint32_t CFVxGdiDialogue::getTargetProperties(TargetType_t targetType) {
   LOGGING_E;
   uint32_t flags = GdiDialogue::getTargetProperties(targetType);
   flags |= IS_PROGRAMMER;

   // These options don't apply to programmer
   flags &= ~HAS_CLK_SW;
   flags &= ~HAS_VLLS_RESET_CAPTURE;
   flags &= ~HAS_MASK_INTERRUPTS;

   return flags;
}

/*! Handler for OnOk
 *
 *  @param event The event to handle
 */
void CFVxGdiDialogue::OnOkClick( wxCommandEvent& event ) {
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
USBDM_ErrorCode CFVxGdiDialogue::execute(AppSettings *appSettings) {
   LOGGING;

   hideUnusedControls();
   Fit();

   Init();

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

