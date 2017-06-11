/*! \file
    \brief Header file for GdiDialoguePlugin.cpp

    \verbatim
    Copyright (C) 2015  Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Change History
   +====================================================================
   |    May 2015 | Created
   +====================================================================
    \endverbatim
*/

#ifndef GDI_DIALOGUE_PLUGIN_H_
#define GDI_DIALOGUE_PLUGIN_H_

#if !defined(CPP_DLL_LOCAL)
   #ifdef _WIN32
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __declspec(dllexport)
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __declspec(dllimport)
      //! Functions local to a library
      #define CPP_DLL_LOCAL
   #else
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __attribute__ ((visibility ("default")))
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __attribute__ ((visibility ("default")))
      //! Functions local to a library
      #define CPP_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
   #endif
#endif

#include <memory>

#include "USBDM_API.h"
#include "AppSettings.h"
#include "BdmInterface.h"

class GdiDialoguePlugin;

class GdiDialoguePlugin {
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

typedef std::shared_ptr<GdiDialoguePlugin> GdiDialoguePluginPtr;

#endif /* GDI_DIALOGUE_PLUGIN_H_ */
