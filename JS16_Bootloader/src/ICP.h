/*
 * ICP.h
 *
 *  Created on: 26/07/2008
 *      Author: PODonoghue
 */

#ifndef _ICP_H_
#define _ICP_H_

#define  ICP_MAX_DATA_SIZE  (32)   // Flash memory program block size

enum ICP_ErrorType {
   ICP_RC_OK               ,
   ICP_RC_USB_ERROR        ,
   ICP_RC_NO_JS16_DEVICE  ,
   ICP_RC_ILLEGAL_PARAMS   ,
   ICP_RC_DEVICE_NOT_OPEN  ,
   ICP_RC_FILE_NOT_FOUND,
   ICP_RC_COMMAND_FAILED,
};

void          ICP_Reboot(void);
ICP_ErrorType ICP_MassErase(void);
ICP_ErrorType ICP_Program(unsigned int  addr,
                          unsigned int  count,
                          unsigned char *data);
ICP_ErrorType ICP_Init(void);
ICP_ErrorType ICP_FindDevices(unsigned int *deviceCount);
ICP_ErrorType ICP_ReleaseDevices(void);
ICP_ErrorType ICP_Open(unsigned char deviceNo);
ICP_ErrorType ICP_Close(void);
ICP_ErrorType ICP_Exit(void);

#endif // _ICP_H_
