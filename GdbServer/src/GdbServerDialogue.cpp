/*
 * GdbServerDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include <GdbServerDialogue.h>

//UsbdmDialogue::UsbdmDialogue(wxWindow* parent, const wxString& title, BdmProgrammingInterface &bdmProgrammingInterface) :

GdbServerDialogue::GdbServerDialogue(wxWindow* parent, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface) :
   UsbdmDialogue(parent, _("GDB Server"), bdmInterface, deviceInterface) {
}

GdbServerDialogue::~GdbServerDialogue() {
}

uint32_t GdbServerDialogue::getTargetProperties(TargetType_t targetType) {
   LOGGING_E;

   uint32_t flags = UsbdmDialogue::getTargetProperties(targetType);

   flags |= IS_GDB_SERVER;

   // These options don't apply to GDB server
   // nil

   return flags;
}

/*! Handler for OnKeepChanges button
 *
 *  @param event The event to handle
 */
void GdbServerDialogue::OnKeepChangesClick( wxCommandEvent& event ) {
   if (TransferDataFromWindow()) {
      EndModal(BDM_RC_OK);
   }
}

/*! Handler for OnDiscardChangesButton
 *
 *  @param event The event to handle
 */
void GdbServerDialogue::OnDiscardChangesClick( wxCommandEvent& event ) {
   EndModal(BDM_RC_FAIL);
}

/*! This displays the Dialogue which represents the entire application
 *  for the stand-alone flash programmers.  Accepts starting parameters.
 *
 *  @param settingsFilename Base name of settings file to use
 *  @param hexFilename      Hex file to load
 *
 *  @return BDM_RC_OK - no useful return vale
 */
USBDM_ErrorCode GdbServerDialogue::execute(AppSettingsPtr appSettings, bool reloadSettings) {
   LOGGING;

   hideUnusedControls();
   Init();
   Fit();

   if (reloadSettings) {
      loadSettings(*appSettings);
   }

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
