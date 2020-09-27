/*
 * UsbdmWxConstants.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#ifndef SOURCE_USBDMWXCONSTANTS_H_
#define SOURCE_USBDMWXCONSTANTS_H_

#if defined __cplusplus
namespace UsbdmWxConstants {
#endif
   const long OK_DEFAULT         = 0x00000000;
   const long YES_DEFAULT        = 0x00000000;
   const long CENTER             = 0x00000001;
   const long YES                = 0x00000002;
   const long NO                 = 0x00000008;
   const long OK                 = 0x00000004;
   const long CANCEL             = 0x00000010;
   const long NO_DEFAULT         = 0x00000080;
   const long ICON_WARNING       = 0x00000100;
   const long ICON_ERROR         = 0x00000200;
   const long ICON_QUESTION      = 0x00000400;
   const long ICON_INFORMATION   = 0x00000800;
   const long STAY_ON_TOP        = 0x00008000;
   const long YES_NO             = YES|NO;
#if defined __cplusplus
}
#endif

#endif /* SOURCE_USBDMWXCONSTANTS_H_ */
