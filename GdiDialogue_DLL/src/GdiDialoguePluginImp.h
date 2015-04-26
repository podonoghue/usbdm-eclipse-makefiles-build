/*
 * GdiDialoguePluginImp.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDIDIALOGUEPLUGINIMP_H_
#define SRC_GDIDIALOGUEPLUGINIMP_H_

#include "GdiDialoguePlugin.h"

class GDI_DIALOGUE_PLUGIN_DECLSPEC GdiDialoguePluginImp: public GdiDialoguePlugin {
public:
   GdiDialoguePluginImp();
   virtual ~GdiDialoguePluginImp();

   /*!
    *  Creates and displays the Dialogue to obtain settings from the user.
    *  - Accepts and updates settings object
    *  - Prompts user to select BDM etc.
    *
    *  @param bdmInterface  Interface to BDM to use (internal settings will be updated)
    *  @param appSettings   Settings object to use
    *  @param forceDisplay  Display dialogue even if appSettings indicates not to
    *
    *  @return BDM_RC_OK - Settings may have been changed and need to be saved
    *                    - Otherwise an error or user has cancelled dialogue
    */
   virtual USBDM_ErrorCode execute(BdmInterfacePtr bdmInterface, AppSettingsPtr appSettings, bool forceDisplay=false);
};

#endif /* SRC_GDIDIALOGUEPLUGINIMP_H_ */
