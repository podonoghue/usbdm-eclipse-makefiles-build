#ifndef _SIMPLESRECORDS_H_
#define _SIMPLESRECORDS_H_
/*! \file
   \brief Simple S-Record Loading

   SimpleSRecords.h
*/
#include <Common.h>
#include "USBDM_API.h"

//!   Loads Freescale S-records
//!
//! @param pSrec        : SRECs to load
//! @param buffer       : Buffer for the image
//! @param bufferSize   : Size of buffer (in dataType)
//! @param loadedSize   : Size of loaded image (in dataType)
//! @param loadAddr     : Memory address for start of buffer
//!
//! @return error code
//!
//! @note Assumes consecutive SRECs
//! @note Modified for weird DSC S-file format (word addresses)
//!
USBDM_ErrorCode loadSRec(const char          *pSrec,
                         uint8_t              buffer[],
                         unsigned             bufferSize,
                         unsigned            *loadedSize,
                         uint32_t            *loadAddr,
                         bool                 wordAddresses = false);

#endif // _SIMPLESRECORDS_H_
