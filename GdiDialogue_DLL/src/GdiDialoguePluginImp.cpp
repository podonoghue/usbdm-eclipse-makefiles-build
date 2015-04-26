/*
 * PluginExample.cpp
 *
 *  Created on: 8 Apr 2015
 *      Author: podonoghue
 */
#include "GdiDialoguePluginImp.h"
#include "GdiDialogue.h"
#include "UsbdmSystem.h"

using namespace std;

GdiDialoguePluginImp::GdiDialoguePluginImp() {
   LOGGING_E;
}

GdiDialoguePluginImp::~GdiDialoguePluginImp() {
   LOGGING_E;
}

USBDM_ErrorCode GDI_DIALOGUE_PLUGIN_DECLSPEC GdiDialoguePluginImp::execute(BdmInterfacePtr bdmInterface, AppSettingsPtr appSettings, bool forceDisplay) {
   GdiDialogue dialogue(NULL, bdmInterface);
   USBDM_ErrorCode rc = dialogue.execute(appSettings, forceDisplay);
   dialogue.Destroy();
   return rc;
}

/*
 * Create the plugin instance
 */
extern "C"
GdiDialoguePlugin* GDI_DIALOGUE_PLUGIN_DECLSPEC createPluginInstance() {
   return new GdiDialoguePluginImp();
}
