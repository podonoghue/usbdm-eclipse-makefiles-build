/*
 * ProgrammerDialogue.cpp
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#include <ProgrammerDialogue.h>

#include <wx/wx.h>

ProgrammerDialogue::ProgrammerDialogue(
      wxWindow            *parent,
      const char          *title,
      BdmInterfacePtr      bdmInterface,
      DeviceInterfacePtr   deviceInterface,
      AppSettings          &appsettings) :
   UsbdmDialogue(parent, title, bdmInterface, deviceInterface, appsettings) {
}

ProgrammerDialogue::~ProgrammerDialogue() {
   LOGGING_E;
}

/**
 *  Get properties of target type modified for programmer
 *
 *  @return Bit-mask describing properties
 *
 */
uint32_t ProgrammerDialogue::getTargetProperties(TargetType_t targetType) {
   LOGGING_Q;

   uint32_t flags = UsbdmDialogue::getTargetProperties(targetType);

   // This is a programmer
   flags |= IS_PROGRAMMER;
   flags |= HAS_SOUNDS;

   // These options don't apply to programmer
   flags &= ~HAS_CLK_SW;
   flags &= ~HAS_VLLS_RESET_CAPTURE;
   flags &= ~HAS_MASK_INTERRUPTS;

   log.print("Flags = 0x%08X\n", flags);

   return flags;
}


