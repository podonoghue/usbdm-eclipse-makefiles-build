/*
 * Metrowerks.h
 *
 *  Created on: 25/02/2010
 *      Author: podonoghue
 */

#ifndef METROWERKS_H_
#define METROWERKS_H_

#define DI_CB_MTWKS_EXTENSION            0x4000

// Metrowerks Callback codes
#define MTWKS_CB_CONNECTIONOK            0x000001
#define MTWKS_CB_UPDATEVIEW              0x000040
#define MTWKS_CB_HC12AUTOCONFIG          0x10000
#define MTWKS_CB_STATUSDISPLAY           0x08
#define MTWKS_CB_HASVERSIONCMD           0x8000
#define MTWKS_CB_DISPLAYLINE             0x80
//#define MTWKS_CB_ACCESSWHILERUNNING    0x800000c8
#define MTWKS_CB_ACCESSWHILERUNNING      0x20
#define MTWKS_CB_GETSTATUSWHENSTOPPED    0x800
#define MTWKS_CB_BDMBYTEREADWRITE        0x20000
#define MTWKS_CB_REPORTONLYFATALERROR    0x800000ca
#define MTWKS_CB_REPORTONLYFATALERRORx   0x4000
//#define MTWKS_CB_GETSTATUSWHENSTOPPED  0x800000c9
#define MTWKS_CB_HCS08AUTOCONFIG         0xc00007d0
#define MTWKS_CB_PROJECTACCESS           0x80000000
#define MTWKS_MSG                        0x80000322
#define MTWKS_CB_SETMEEID                0xC0001B58

#define MTWKS_LEGACY_CB_COLDFIREAUTOCONFIG 0x40000000

struct autoConfig_t {
   DiUInt32T options;
   DiUInt32T deviceID;
   char      deviceName[100];
};

#endif /* METROWERKS_H_ */
