/*
 * @file DMA.cpp
 *
 *  Created on: 08/07/2014
 *      Author: podonoghue
 */

#include "derivative.h"
#include "dma.h"

DMAChannel0 *DMAChannel0::thisPtr = 0;

void DMAChannel0::handler(void) {
}

void DMA0_IRQHandler(void) {
   DMAChannel0::thisPtr->handler();
}

DMAChannel1 *DMAChannel1::thisPtr = 0;

void DMAChannel1::handler(void) {
}

void DMA1_IRQHandler(void) {
   DMAChannel1::thisPtr->handler();
}

DMAChannel2 *DMAChannel2::thisPtr = 0;

void DMAChannel2::handler(void) {
}

void DMA2_IRQHandler(void) {
   DMAChannel2::thisPtr->handler();
}

DMAChannel3 *DMAChannel3::thisPtr = 0;

void DMAChannel3::handler(void) {
}

void DMA3_IRQHandler(void) {
   DMAChannel3::thisPtr->handler();
}
