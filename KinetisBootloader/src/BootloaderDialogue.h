/*
 * BootloaderDialogue.h
 *
 *  Created on: 9 Dec 2019
 *      Author: podonoghue
 */

#ifndef BOOTLOADERDIALOGUE_H_
#define BOOTLOADERDIALOGUE_H_

#include "BootloaderDialogueSkeleton.h"
#include "FlashImageFactory.h"
#include "Bootloader.h"

class BootloaderDialogue : public BootloaderDialogueSkeleton {
private:
   BootloaderDialogue(const BootloaderDialogue &other) = delete;
   BootloaderDialogue(BootloaderDialogue &&other) = delete;
   BootloaderDialogue& operator=(const BootloaderDialogue &other) = delete;
   BootloaderDialogue& operator=(BootloaderDialogue &&other) = delete;

   FlashImagePtr flashImage;

public:
   BootloaderDialogue();
   virtual ~BootloaderDialogue();

protected:
   virtual void onLoadFile(wxCommandEvent &event) override;
   virtual void onProgramDevice(wxCommandEvent &event) override;
};

#endif /* BOOTLOADERDIALOGUE_H_ */
