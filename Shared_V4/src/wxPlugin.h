/*
 * wxPlugin.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_WXPLUGIN_H_
#define SRC_WXPLUGIN_H_

#if !defined(CPP_DLL_LOCAL)
//! Functions exported from a library
#define CPP_DLL_EXPORT __declspec(dllexport)
//! Functions local to a library
#define CPP_DLL_LOCAL // __attribute__ ((visibility ("hidden")))
//! Functions imported from a library
#define CPP_DLL_IMPORT __declspec(dllimport)
#endif

#if defined(COMPILE_WX_PLUGIN_DLL)
//! Create Library
#define WXPLUGIN_DECLSPEC CPP_DLL_EXPORT
#elif defined(LINK_GDI_DIALOGUE_PLUGIN_DLL)
//! Link to routines directly
#define WXPLUGIN_DECLSPEC CPP_DLL_LOCAL
#else
//! Link against Library
#define WXPLUGIN_DECLSPEC CPP_DLL_IMPORT
#endif

#include <tr1/memory>
#include <string>

#include "UsbdmWxConstants.h"

class WXPLUGIN_DECLSPEC WxPlugin {

public:
   virtual long display(std::string message, std::string caption, long style) = 0;
   virtual ~WxPlugin() {};

protected:
   WxPlugin() {};
};

typedef std::tr1::shared_ptr<WxPlugin> WxPluginPtr;

#endif /* SRC_WXPLUGIN_H_ */
