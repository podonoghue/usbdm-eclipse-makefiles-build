/*
 * JS16_Bootloader.h
 *
 *  Created on: 12/04/2012
 *      Author: podonoghue
 */

#ifndef JS16_BOOTLOADER_H_
#define JS16_BOOTLOADER_H_

#include "ICP.h"
ICP_ErrorType ProgramFlash(const char *hexFileName);

#endif /* JS16_BOOTLOADER_H_ */
