/*
 * ArmDebug.h
 *
 *  Created on: 04/03/2011
 *      Author: PODonoghue
 */

#ifndef ARMDEBUG_H_
#define ARMDEBUG_H_

//! Get name of ARM memory location/region
//!
//! @param address address to check
//!
//! @return ptr to static buffer of form <name>:<address>
//!
char *ARM_GetMemoryName(uint32_t address);

//! Get WAIT/OK_FAULT name
const char *getACKName(int ack);

//! Get DP reg name ("CTRL/STAT","SELECT","RDBUFF")
const char *getDpRegName(int reg);

#endif /* ARMDEBUG_H_ */
