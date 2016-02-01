/*
 * dma.h (derived from dma-MKL.h)
 *
 *  Created on: 08/07/2014
 *      Author: podonoghue
 */

#ifndef INCLUDE_USBDM_DMA_H_
#define INCLUDE_USBDM_DMA_H_

#include "derivative.h"
#include "gpio.h"

namespace USBDM {

/**
* @addtogroup DMA_Group Direct Memory Access (DMA)
* @brief Support for DMA operations
* @{
*/
class DMAChannel {

private:
   volatile DMA_Type    *dmac;
   volatile DMAMUX_Type *dmaMux;
   unsigned channel;

public:
   struct DMAInformation {
      uint32_t source;
      uint32_t destination;
      uint32_t byteCount;
      uint32_t control;
      uint16_t sourceDevice;
   };

   DMAChannel(volatile DMA_Type *dmac, volatile DMAMUX_Type *dmaMux, unsigned channel) {
      this->dmac    = dmac;
      this->dmaMux  = dmaMux;
      this->channel = channel;
   }

   void configure(DMAInformation *information) {
      SIM->DMAMUX0_CLOCK_REG |= DMAMUX0_CLOCK_MASK;
      dmaMux->CHCFG[channel]      = 0;
      dmac->DMA[channel].DSR_BCR  = DMA_DSR_BCR_BCR(information->byteCount);
      dmac->DMA[channel].SAR      = information->source;
      dmac->DMA[channel].DAR      = information->destination;
      dmac->DMA[channel].DCR      = information->control;
      dmaMux->CHCFG[channel]      = DMAMUX_CHCFG_SOURCE(information->sourceDevice)|DMAMUX_CHCFG_ENBL_MASK;
   }

   void wait() {
      while ((dmac->DMA[channel].DSR & DMA_DSR_DONE_MASK) == 0) {
         __asm__("nop");
      }
      dmac->DMA[channel].DSR = DMA_DSR_DONE_MASK;
   }
};

class DMAChannel0 : public DMAChannel {
private:
   static DMAChannel0 *thisPtr;
   void handler(void);
   friend void DMA0_IRQHandler(void);

public:
   DMAChannel0() : DMAChannel(DMA0, DMAMUX0, 0) {
      thisPtr = this;
   }
};
class DMAChannel1 : public DMAChannel {
private:
   static DMAChannel1 *thisPtr;
   void handler(void);
   friend void DMA1_IRQHandler(void);

public:
   DMAChannel1() : DMAChannel(DMA0, DMAMUX0, 1) {
      thisPtr = this;
   }
};
class DMAChannel2 : public DMAChannel {
private:
   static DMAChannel2 *thisPtr;
   void handler(void);
   friend void DMA2_IRQHandler(void);

public:
   DMAChannel2() : DMAChannel(DMA0, DMAMUX0, 2) {
      thisPtr = this;
   }
};
class DMAChannel3 : public DMAChannel {
private:
   static DMAChannel3 *thisPtr;
   void handler(void);
   friend void DMA3_IRQHandler(void);

public:
   DMAChannel3() : DMAChannel(DMA0, DMAMUX0, 3) {
      thisPtr = this;
   }
};
/**
 * @}
 */
} // End namespace USBDM

#endif /* INCLUDE_USBDM_DMA_H_ */
