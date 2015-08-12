/*
 * SPI-MKL.c
 *
 *  Created on: 07/08/2012
 *      Author: podonoghue
 */
#include <stddef.h>
#include <stdint.h>
#include "system.h"
#include "derivative.h"
#include "utilities.h"
#include "spi.h"
#include "gpio.h"

#define DEFAULT_SPI_FREQUENCY  (10000000)     //!< Default SPI frequency 10 MHz

#define GPIO_ALT_FN            1

/**
 * Constructor
 *
 * @param baseAddress  Base address of SPI
 * @param dmaTxChannel DMA Channel for transmission
 * @param dmaRxChannel DMA Channel for reception
 * @param rxMuxSource  Receive Mux value
 * @param pcs          Manual PCS select signal
 */
SPI::SPI(volatile SPI_Type *baseAddress, DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel, uint8_t rxMuxSource, DigitalIO *pcs) :
   spi(baseAddress),
   dmacTxChannel(dmaTxChannel),
   dmacRxChannel(dmaRxChannel),
   dmaSpiRxSlot(rxMuxSource),
   pcs(pcs),
   interfaceFrequency(10000000) {
   if (pcs != 0) {
      // SPI PCS pin - manual control as GPIO
      pcs->setDigitalOutput(PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   }
}

/**
 * Constructor
 *
 * @param dmaTxChannel DMA Channel for transmission
 * @param dmaRxChannel DMA Channel for reception
 * @param pcs          Manual PCS select signal
 */
SPI_0::SPI_0(DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel, DigitalIO *pcs) :
      SPI(SPI0, dmaTxChannel, dmaRxChannel, DMAChannel::DMA_SLOT_SPI0_Rx, pcs) {

   thisPtr = this;

   // Enable SPI port pin clocks
   // MOSI,MISO,SCLK
#if !defined(SPI0_SCK_GPIO)  || !defined(SPI0_MOSI_GPIO) || !defined(SPI0_MISO_GPIO)
#error "Please check pin mappings for SCK, MOSI & MISO in pin_mapping.h"
#else
   SPI0_SCK_GPIO.setPCR(PORT_PCR_MUX(SPI0_SCK_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   SPI0_MOSI_GPIO.setPCR(PORT_PCR_MUX(SPI0_MOSI_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   SPI0_MISO_GPIO.setPCR(PORT_PCR_MUX(SPI0_MISO_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#endif

#ifdef SPI0_PCS0_GPIO
   SPI0_PCS0_GPIO.setPCR(PORT_PCR_MUX(SPI0_PCS0_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI0_C1_SSOE_VALUE SPI_C1_SSOE_MASK
#endif
#ifndef SPI0_C1_SSOE_VALUE
#define SPI0_C1_SSOE_VALUE 0
#endif

   // Enable SPI module clock
   SPI0_CLOCK_REG |= SPI0_CLOCK_MASK;

   setSpeed(0); // default baud

   NVIC_EnableIRQ(SPI0_IRQn);
   NVIC_SetPriority (SPI0_IRQn, 2);

   spi->C2 = SPI_C2_MODFEN_MASK|SPI_C2_TXDMAE_MASK|SPI_C2_RXDMAE_MASK;
   spi->C1 = SPI_C1_SPE_MASK|SPI_C1_MSTR_MASK|SPI0_C1_SSOE_VALUE;//|SPI_C1_CPHA_MASK|SPI_C1_CPOL_MASK;
}

#ifdef SPI1

/**
 * Constructor
 *
 * @param dmaTxChannel DMA Channel for transmission
 * @param dmaRxChannel DMA Channel for reception
 * @param pcs          Manual PCS select signal
 */
SPI_1::SPI_1(DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel, DigitalIO *pcs) :
      SPI(SPI1, dmaTxChannel, dmaRxChannel, DMAChannel::DMA_SLOT_SPI1_Rx, pcs) {

   thisPtr = this;

   // Enable SPI port pin clocks
   // MOSI,MISO,SCLK
#if !defined(SPI1_SCK_GPIO)  || !defined(SPI1_MOSI_GPIO) || !defined(SPI1_MISO_GPIO)
#error "Please check pin mappings for SCK, MOSI & MISO in pin_mapping.h"
#else
   SPI1_SCK_GPIO.setPCR(PORT_PCR_MUX(SPI1_SCK_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   SPI1_MOSI_GPIO.setPCR(PORT_PCR_MUX(SPI1_MOSI_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   SPI1_MISO_GPIO.setPCR(PORT_PCR_MUX(SPI1_MISO_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#endif

#ifdef SPI1_PCS0_GPIO
   SPI1_PCS1_GPIO.setPCR(PORT_PCR_MUX(SPI1_PCS0_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI1_C1_SSOE_VALUE SPI_C1_SSOE_MASK
#endif
#ifndef SPI1_C1_SSOE_VALUE
#define SPI1_C1_SSOE_VALUE 0
#endif

   // Enable SPI module clock
   SPI1_CLOCK_REG |= SPI1_CLOCK_MASK;

   setSpeed(0); // default baud

   NVIC_EnableIRQ(SPI1_IRQn);

   spi->C1 = SPI_C1_SPE_MASK|SPI_C1_MSTR_MASK|SPI1_C1_SSOE_VALUE;
   spi->C2 = 0;
}
#endif

static const uint16_t spprFactors[] = {1,2,3,4,5,6,7,8};
static const uint16_t sprFactors[]  = {2,4,8,16,32,64,128,256,512};

/**
 * Sets Communication speed for SPI
 *
 * @param frequency => Frequency in Hz (0 => use default value)
 *
 * Note: Chooses the highest speed that is not greater than frequency.
 */
void SPI::setSpeed(uint32_t targetFrequency) {

   if (targetFrequency == 0) {
      targetFrequency = DEFAULT_SPI_FREQUENCY;
   }
   int bestSPPR = 0;
   int bestSPR  = 0;
   uint32_t difference = -1;
   for (int sppr = (sizeof(spprFactors)/sizeof(spprFactors[0]))-1; sppr >= 0; sppr--) {
      for (int spr = (sizeof(sprFactors)/sizeof(sprFactors[0]))-1; spr >= 0; spr--) {
         uint32_t calculatedFrequency = SystemBusClock/(spprFactors[sppr]*sprFactors[spr]);
         if (calculatedFrequency > targetFrequency) {
            // Too high stop looking here
            break;
         }
         if ((targetFrequency - calculatedFrequency) < difference) {
            // New "best value"
            difference = (targetFrequency - calculatedFrequency);
            bestSPR  = spr;
            bestSPPR = sppr;
            interfaceFrequency = calculatedFrequency;
         }
      }
   }
   spi->BR = SPI_BR_SPPR(bestSPPR)|SPI_BR_SPR(bestSPR);
}

/**
 * Transmit and receive an 8-bit value over SPI
 *
 * @param data - Data to send
 *
 * @return Data received
 */
uint32_t SPI::txRx(uint32_t data) {
   while ((spi->S & SPI_S_SPTEF_MASK)==0) {
      __asm__("nop");
   }
   spi->D  = data;
   while ((spi->S & SPI_S_SPRF_MASK)==0) {
      __asm__("nop");
   }
   return spi->D; // Return read data
}

/**
 *  Transmit and receive a series of bytes
 *
 *  @param dataSize  Number of bytes to transfer
 *  @param dataOut   Transmit bytes (may be NULL for Rx only)
 *  @param dataIn    Receive byte buffer (may be NULL for Tx only)
 *
 *  Note: dataIn may use same buffer as dataOut
 */
void SPI::txRxBytes(uint32_t dataSize, const uint8_t *dataOut, uint8_t *dataIn) {
   uint8_t dummy = 0xFF;
   uint32_t dataInInc  = DMA_DCR_DINC_MASK|DMA_DCR_ERQ_MASK|DMA_DCR_CS_MASK|DMA_DCR_SSIZE(1)|DMA_DCR_DSIZE(1)|DMA_DCR_D_REQ_MASK;
   uint32_t dataOutInc = DMA_DCR_SINC_MASK|DMA_DCR_ERQ_MASK|DMA_DCR_CS_MASK|DMA_DCR_SSIZE(1)|DMA_DCR_DSIZE(1)|DMA_DCR_D_REQ_MASK;

   if (dataIn == 0) {
      dataIn = &dummy;
      dataInInc &= ~DMA_DCR_DINC_MASK;
   }
   if (dataOut == 0) {
      dataOut = &dummy;
      dataOutInc &= ~DMA_DCR_SINC_MASK;
   }
   // Optional Rx channel
   DMAChannel::DMAInformation dmaRxInformation = {
      (uint32_t)&spi->D,
      (uint32_t)dataIn,
      dataSize,
      dataInInc,
      (uint8_t)dmaSpiRxSlot,
   };
   dmacRxChannel->configure(&dmaRxInformation);

   // Must have Tx channel
   DMAChannel::DMAInformation dmaTxInformation = {
      (uint32_t)dataOut,
      (uint32_t)&spi->D,
      dataSize,
      dataOutInc,
      (uint8_t)(dmaSpiRxSlot+1),
   };
   dmacTxChannel->configure(&dmaTxInformation);

   if (pcs != 0) {
      pcs->clear();
   }
   spi->C2 |= SPI_C2_RXDMAE_MASK|SPI_C2_TXDMAE_MASK;
   dmacTxChannel->wait();
   dmacRxChannel->wait();
   spi->C2 &= ~(SPI_C2_TXDMAE_MASK|SPI_C2_RXDMAE_MASK);
   if (pcs != 0) {
      pcs->set();
   }
}

///**
// *  Transmit and receive a series of bytes
// *
// *  @param dataSize  Number of bytes to transfer
// *  @param dataOut   Transmit bytes (may be NULL for Rx only)
// *  @param dataIn    Receive byte buffer (may be NULL for Tx only)
// *
// *  Note: dataIn may use same buffer as dataOut
// */
//void SPI::txRxBytes(int dataSize, const uint8_t *dataOut, uint8_t *dataIn) {
//   __disable_interrupt();
//   txBytesRemaining = dataSize;
//   rxBytesRemaining = dataSize;
//   dataOutPtr       = dataOut;
//   dataInPtr        = dataIn;
//   spi->C1 |= SPI_C1_SPTIE_MASK|SPI_C1_SPIE_MASK;
//   (void)spi->S;
//   (void)spi->D; // Discard any previous received data
//   __enable_interrupt();
//
////   while (txBytesRemaining>0) {
//   while ((spi->C1 & SPI_C1_SPIE_MASK) != 0) {
//      __asm__("nop");
//   }
//}
//
void SPI::poll() {
//   uint8_t status = spi->S;
//   if ((status & SPI_S_SPTEF_MASK) != 0) {
//      if (txBytesRemaining>0) {
//         spi->D = *dataOutPtr++;
//         txBytesRemaining--;
//      }
//      else {
//         spi->C1 &= ~SPI_C1_SPTIE_MASK;
//      }
//   }
//   if ((status & SPI_S_SPRF_MASK) != 0) {
//      uint8_t dataIn = spi->D;
//      if (dataInPtr != NULL) {
//         *dataInPtr++ = dataIn;
//         rxBytesRemaining--;
//      }
//      if (rxBytesRemaining==0) {
//         spi->C1 &= ~SPI_C1_SPIE_MASK;
//      }
//   }
}

SPI_0 *SPI_0::thisPtr = NULL;

extern "C"
void SPI0_IRQHandler(void) {
   SPI_0::thisPtr->poll();
}

SPI_1 *SPI_1::thisPtr = NULL;

extern "C"
void SPI1_IRQHandler(void) {
   SPI_1::thisPtr->poll();
}
