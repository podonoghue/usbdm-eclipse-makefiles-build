/*
 * JB16_Bootloader.h
 *
 *  Created on: 12/04/2012
 *      Author: podonoghue
 */

#ifndef JB16_BOOTLOADER_H_
#define JB16_BOOTLOADER_H_
#include <string.h>

#include "ICP.h"
ICP_ErrorType ProgramFlash(std::string hexFileName);
ICP_ErrorType RebootDevice();

#endif /* JB16_BOOTLOADER_H_ */
