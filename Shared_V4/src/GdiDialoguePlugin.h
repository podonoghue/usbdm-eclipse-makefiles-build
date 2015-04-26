/*
 * PluginExample.h
 *
 *  Created on: 8 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDI_DIALOGUE_PLUGIN_H_
#define SRC_GDI_DIALOGUE_PLUGIN_H_

#if !defined(CPP_DLL_LOCAL)
//! Functions exported from a library
#define CPP_DLL_EXPORT __declspec(dllexport)
//! Functions local to a library
#define CPP_DLL_LOCAL // __attribute__ ((visibility ("hidden")))
//! Functions imported from a library
#define CPP_DLL_IMPORT __declspec(dllimport)
#endif

#if defined(COMPILE_GDI_DIALOGUE_PLUGIN_DLL)
//! Create Library
#define GDI_DIALOGUE_PLUGIN_DECLSPEC CPP_DLL_EXPORT
#elif defined(LINK_GDI_DIALOGUE_PLUGIN_DLL)
//! Link to routines directly
#define GDI_DIALOGUE_PLUGIN_DECLSPEC CPP_DLL_LOCAL
#else
//! Link against Library
#define GDI_DIALOGUE_PLUGIN_DECLSPEC CPP_DLL_IMPORT
#endif

#include <tr1/memory>

#include "USBDM_API.h"
#include "AppSettings.h"
#include "BdmInterface.h"

class GdiDialoguePlugin;

class GDI_DIALOGUE_PLUGIN_DECLSPEC GdiDialoguePlugin {
public:
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
   virtual USBDM_ErrorCode execute(BdmInterfacePtr bdmInterface, AppSettingsPtr appSettings, bool forceDisplay=false) = 0;
   virtual ~GdiDialoguePlugin() {}

protected:
   GdiDialoguePlugin() {}
};

typedef std::tr1::shared_ptr<GdiDialoguePlugin> GdiDialoguePluginPtr;

#endif /* SRC_GDI_DIALOGUE_PLUGIN_H_ */
