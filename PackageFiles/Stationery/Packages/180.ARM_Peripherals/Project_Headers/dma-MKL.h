/*
 * DMA.h
 *
 *  Created on: 08/07/2014
 *      Author: podonoghue
 */

#ifndef DMA_H_
#define DMA_H_

#include "derivative.h"

class DMAChannel {
public:
   enum {
      Disabled                     =  0,
      DMA_SLOT_UART0_Rx            =  2,
      DMA_SLOT_UART0_Tx            =  3,
      DMA_SLOT_UART1_Rx            =  4,
      DMA_SLOT_UART1_Tx            =  5,
      DMA_SLOT_UART2_Rx            =  6,
      DMA_SLOT_UART2_Tx            =  7,
      DMA_SLOT_SPI0_Rx             = 16,
      DMA_SLOT_SPI0_Tx             = 17,
      DMA_SLOT_SPI1_Rx             = 18,
      DMA_SLOT_SPI1_Tx             = 19,
      DMA_SLOT_TPM0_Ch0            = 24,
      DMA_SLOT_TPM0_Ch1            = 25,
      DMA_SLOT_TPM0_Ch2            = 26,
      DMA_SLOT_TPM0_Ch3            = 27,
      DMA_SLOT_TPM0_Ch4            = 28,
      DMA_SLOT_TPM0_Ch5            = 29,
      DMA_SLOT_TPM1_Ch0            = 32,
      DMA_SLOT_TPM1_Ch1            = 33,
      DMA_SLOT_TPM2_Ch0            = 34,
      DMA_SLOT_TPM2_Ch1            = 35,
      DMA_SLOT_ADC0                = 40,
      DMA_SLOT_CMP0                = 42,
      DMA_SLOT_DAC0                = 45,
      DMA_SLOT_PORTA               = 49,
      DMA_SLOT_PORTD               = 52,
      DMA_SLOT_TPM0_Overflow       = 54,
      DMA_SLOT_TPM1_Overflow       = 55,
      DMA_SLOT_TPM2_Overflow       = 56,
      DMA_SLOT_TSI                 = 57,
      DMA_SLOT_DMA0_AlwaysEnabled  = 60,
      DMA_SLOT_DMA1_AlwaysEnabled  = 61,
      DMA_SLOT_DMA2_AlwaysEnabled  = 62,
      DMA_SLOT_DMA3_AlwaysEnabled  = 63,
      };

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
      SIM->SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
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
   DMAChannel0() : DMAChannel(DMA0, DMAMUX, 0) {
      thisPtr = this;
   }
};
class DMAChannel1 : public DMAChannel {
private:
   static DMAChannel1 *thisPtr;
   void handler(void);
   friend void DMA1_IRQHandler(void);

public:
   DMAChannel1() : DMAChannel(DMA0, DMAMUX, 1) {
      thisPtr = this;
   }
};
class DMAChannel2 : public DMAChannel {
private:
   static DMAChannel2 *thisPtr;
   void handler(void);
   friend void DMA2_IRQHandler(void);

public:
   DMAChannel2() : DMAChannel(DMA0, DMAMUX, 2) {
      thisPtr = this;
   }
};
class DMAChannel3 : public DMAChannel {
private:
   static DMAChannel3 *thisPtr;
   void handler(void);
   friend void DMA3_IRQHandler(void);

public:
   DMAChannel3() : DMAChannel(DMA0, DMAMUX, 3) {
      thisPtr = this;
   }
};
#endif /* DMA_H_ */
