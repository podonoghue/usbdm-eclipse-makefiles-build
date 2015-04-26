/*
 * utilities.h
 *
 *  Created on: May 13, 2013
 *      Author: PODonoghue
 */
#ifndef UTILTIES_H_
#define UTILTIES_H_

#include "derivative.h"

// Used to create port register names in a configurable fashion
//-------------------------------------------------------------
#define CONCAT2_(x,y) x ## y
#define CONCAT3_(x,y,z) x ## y ## z
#define CONCAT4_(w,x,y,z) w ## x ## y ## z

#define PF(port,num)    CONCAT4_(MXC_PT,port,PF,num)
#define PDOR(port)      CONCAT3_(GPIO,port,_PDOR)
#define PSOR(port)      CONCAT3_(GPIO,port,_PSOR)
#define PCOR(port)      CONCAT3_(GPIO,port,_PCOR)
#define PTOR(port)      CONCAT3_(GPIO,port,_PTOR)
#define PDIR(port)      CONCAT3_(GPIO,port,_PDIR)
#define PDDR(port)      CONCAT3_(GPIO,port,_PDDR)

//#define MXC(port,muxNum)     CONCAT4_(MXC_PT,port,PF,muxNum)
//#define MXC_MASK(pin,value) (((value)&0x0F)<<(4*((pin)&0x01)))

#endif /* UTILTIES_H_ */
