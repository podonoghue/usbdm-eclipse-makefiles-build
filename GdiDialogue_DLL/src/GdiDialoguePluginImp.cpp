/*
 * PluginExample.cpp
 *
 *  Created on: 8 Apr 2015
 *      Author: podonoghue
 */
#include "GdiDialoguePluginImp.h"
#include "GdiDialogue.h"
#include "UsbdmSystem.h"
#include "PluginHelper.h"

using namespace std;

ModuleInfo GdiDialoguePluginImp::moduleInfo;

GdiDialoguePluginImp::GdiDialoguePluginImp() {
   LOGGING_E;
}

GdiDialoguePluginImp::~GdiDialoguePluginImp() {
   LOGGING_E;
}

USBDM_ErrorCode GdiDialoguePluginImp::execute(BdmInterfacePtr bdmInterface, AppSettingsPtr appSettings, bool forceDisplay) {
   GdiDialogue dialogue(NULL, bdmInterface);
   USBDM_ErrorCode rc = dialogue.execute(appSettings, forceDisplay);
   dialogue.Destroy();
   return rc;
}

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(GdiDialoguePluginImp *pp) {
   return TcreatePluginInstance<GdiDialoguePluginImp>(pp);
}
