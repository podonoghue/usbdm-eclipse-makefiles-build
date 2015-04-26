/*
 * DSC_Utilities.h
 *
 *  Created on: 09/07/2011
 *      Author: PODonoghue
 */

#ifndef DSC_UTILITIES_H_
#define DSC_UTILITIES_H_

//! Obtain string describing the given register's name
//!
//! @param regNo - The register number
//!
//! @return - ptr to static string describing the register
//!
const char *DSC_GetRegisterName(DSC_Registers_t regNo);

//! Obtain size of given register in bits
//!
//! @param regNo - The register number
//!
//! @return - size of the register in bits
//!
unsigned DSC_GetRegisterSize(DSC_Registers_t regNo);

//! Converts an OnceStatus_t to a string for debug
//!
//DLL_LOCAL
//const char *DSC_GetOnceStatusName(OnceStatus_t status);

const char *getMemorySpaceName(MemorySpace_t memorySpace);
const char *getKnownAddress(MemorySpace_t memorySpace, uint32_t address);

#endif /* DSC_UTILITIES_H_ */
