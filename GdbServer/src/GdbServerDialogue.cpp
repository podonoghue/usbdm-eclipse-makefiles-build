/*
 * GdbServerDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include <GdbServerDialogue.h>

#include <wx/wx.h>

GdbServerDialogue::GdbServerDialogue(
      wxWindow*            parent,
      BdmInterfacePtr      bdmInterface,
      DeviceInterfacePtr   deviceInterface,
      AppSettings         &appsettings) :
   UsbdmDialogue(parent, _("GDB Server"), bdmInterface, deviceInterface, appsettings) {
}

GdbServerDialogue::~GdbServerDialogue() {
   LOGGING_E;
}

/**
 *  Get properties of target type modified for programmer
 *
 *  @return Bit-mask describing properties
 *
 */
uint32_t GdbServerDialogue::getTargetProperties(TargetType_t targetType) {
   LOGGING_E;

   uint32_t flags = UsbdmDialogue::getTargetProperties(targetType);

   flags |= IS_GDB_SERVER;

   return flags;
}
