/*
 * JB16_Bootloader.h
 *
 *  Created on: 12/04/2012
 *      Author: podonoghue
 */

#ifndef JB16_BOOTLOADER_H_
#define JB16_BOOTLOADER_H_
#include <string.h>

#include "USBDM_API.h"
#include "ICP.h"

USBDM_ErrorCode ProgramDevice(std::string hexFileName);
USBDM_ErrorCode RebootDevice();

#endif /* JB16_BOOTLOADER_H_ */
