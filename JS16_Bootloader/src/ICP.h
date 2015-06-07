/*
 * ICP.h
 *
 *  Created on: 26/07/2008
 *      Author: PODonoghue
 */

#ifndef _ICP_H_
#define _ICP_H_

#define  ICP_MAX_DATA_SIZE  (32)   // Flash memory program block size

#include "ProgressDialogueFactory.h"

USBDM_ErrorCode ICP_MassErase(ProgressDialoguePtr progressCallback);
USBDM_ErrorCode ICP_Program(unsigned int  addr,
                          unsigned int  count,
                          unsigned char *data,
                          ProgressDialoguePtr progressCallback);
USBDM_ErrorCode ICP_Init(void);
USBDM_ErrorCode ICP_FindDevices(unsigned int *deviceCount);
USBDM_ErrorCode ICP_ReleaseDevices(void);
USBDM_ErrorCode ICP_Open(unsigned char deviceNo);
USBDM_ErrorCode ICP_Close(void);
USBDM_ErrorCode ICP_Exit(void);

#endif // _ICP_H_
