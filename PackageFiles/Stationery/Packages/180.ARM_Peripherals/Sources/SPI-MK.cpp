/*
 * SPI-MK.c
 *
 *  Created on: 07/08/2012
 *      Author: podonoghue
 */
#include <stddef.h>
#include <stdint.h>
#include "system.h"
#include "derivative.h"
#include "utilities.h"
#include "SPI.h"
#include "gpio.h"

#define DEFAULT_SPI_FREQUENCY  (10000000)     //!< Default SPI frequency 10 MHz

/**
 * Constructor
 *
 * @param baseAddress - Base address of SPI
 */
SPI::SPI(volatile SPI_Type *baseAddress) :
   spi(baseAddress) {
   spiBaudValue = 0;
   setSpeed(0);   // Use default speed
}

#ifdef SPI0
#if !defined(SPI0_SCK_GPIO) || !defined(SPI0_SIN_GPIO) || !defined(SPI0_SOUT_GPIO)
#warning "Warning SPI0 present but disabled. Check pin mappings for SPI0_SCK, SPI0_SIN & SPI0_SOUT in pin_mapping.h"
#else

/**
 * Constructor
 */
SPI_0::SPI_0() : SPI((SPI_Type*)SPI0) {

   // Enable SPI port pin clocks & configure PCS register
   // SIN,SOUT,SCLK,PCS
   SPI0_SCK_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI0_SCK_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   SPI0_SIN_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI0_SIN_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   SPI0_SOUT_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI0_SOUT_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);

#ifdef SPI0_PCS0_GPIO
   SPI0_PCS0_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI0_PCS0_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI0_PUSHR_PCS_VALUE SPI_PUSHR_PCS(1<<0)
#endif
#ifdef SPI0_PCS1_GPIO
   SPI0_PCS1_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI0_PCS1_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI0_PUSHR_PCS_VALUE SPI_PUSHR_PCS(1<<1)
#endif
#ifdef SPI0_PCS2_GPIO
   SPI0_PCS2_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI0_PCS2_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI0_PUSHR_PCS_VALUE SPI_PUSHR_PCS(1<<2)
#endif
#ifdef SPI0_PCS3_GPIO
   SPI0_PCS3_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI0_PCS3_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI0_PUSHR_PCS_VALUE SPI_PUSHR_PCS(1<<3)
#endif
#ifdef SPI0_PCS4_GPIO
   SPI0_PCS4_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI0_PCS4_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI0_PUSHR_PCS_VALUE SPI_PUSHR_PCS(1<<4)
#endif
#ifdef SPI0_PCS5_GPIO
   SPI0_PCS5_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI0_PCS5_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI0_PUSHR_PCS_VALUE (1<<5)
#endif
#ifndef SPI0_PUSHR_PCS_VALUE
#define SPI0_PUSHR_PCS_VALUE SPI_PUSHR_PCS_MASK // All signals asserted (but only affects mapped pins)
#endif

   pushrMask = SPI0_PUSHR_PCS_VALUE;

   // Enable SPI module clock
   SIM->SPI0_CLOCK_REG |= SPI0_CLOCK_MASK;

   spi->MCR   = SPI_MCR_HALT_MASK|SPI_MCR_CLR_RXF_MASK|SPI_MCR_ROOE_MASK|SPI_MCR_CLR_TXF_MASK|
                SPI_MCR_MSTR_MASK|SPI_MCR_DCONF(0)|SPI_MCR_SMPL_PT(0)|SPI_MCR_PCSIS_MASK;

   setSpeed(0);   // Use default speed
   setCTAR0Value(SPI_CTAR_FMSZ(8-1)); // Default 8-bit transfers
   setCTAR1Value(SPI_CTAR_FMSZ(8-1)); // Default 8-bit transfers
}
#endif // !defined(SPI0_SCK_GPIO) || !defined(SPI0_SIN_GPIO) || !defined(SPI0_SOUT_GPIO)
#endif // SPI0

#ifdef SPI1
#if !defined(SPI1_SCK_GPIO) || !defined(SPI1_SIN_GPIO) || !defined(SPI1_SOUT_GPIO)
#warning "Warning SPI1 present but disabled. Check pin mappings for SPI1_SCK, SPI1_SIN & SPI1_SOUT in pin_mapping.h"
#else

/**
 * Constructor
 */
SPI_1::SPI_1() : SPI((SPI_Type*)SPI1) {

   // Enable SPI port pin clocks
   // SIN,SOUT,SCLK,PCS
   SPI1_SCK_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI1_SCK_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   SPI1_SIN_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI1_SIN_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   SPI1_SOUT_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI1_SOUT_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);

#ifdef SPI1_PCS0_GPIO
   SPI1_PCS0_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI1_PCS0_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI1_MCR_PCSIS_VALUE SPI_PUSHR_PCS(1<<0)
#endif
#ifdef SPI1_PCS1_GPIO
   SPI1_PCS1_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI1_PCS1_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI1_PUSHR_PCS_VALUE SPI_PUSHR_PCS(1<<1)
#endif
#ifdef SPI1_PCS2_GPIO
   SPI1_PCS2_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI1_PCS2_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI1_PUSHR_PCS_VALUE SPI_PUSHR_PCS(1<<2)
#endif
#ifdef SPI1_PCS3_GPIO
   SPI1_PCS3_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI1_PCS3_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI1_PUSHR_PCS_VALUE SPI_PUSHR_PCS(1<<3)
#endif
#ifdef SPI1_PCS4_GPIO
   SPI1_PCS4_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI1_PCS4_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI1_PUSHR_PCS_VALUE SPI_PUSHR_PCS(1<<4)
#endif
#ifdef SPI1_PCS5_GPIO
   SPI1_PCS5_GPIO::Pcr::setPCR(PORT_PCR_MUX(SPI1_PCS5_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#define SPI1_PUSHR_PCS_VALUE (1<<5)
#endif
#ifndef SPI_PUSPI1_PUSHR_PCS_VALUESHR_PCS_VALUE
#define SPI1_PUSHR_PCS_VALUE SPI_PUSHR_PCS_MASK // All signals asserted (but only affects mapped pins)
#endif

   pushrMask = SPI1_PUSHR_PCS_VALUE;

   // Enable SPI module clock
   SPI1_CLOCK_REG |= SPI1_CLOCK_MASK;

   spi->MCR   = SPI_MCR_HALT_MASK|SPI_MCR_CLR_RXF_MASK|SPI_MCR_ROOE_MASK|SPI_MCR_CLR_TXF_MASK|
                SPI_MCR_MSTR_MASK|SPI_MCR_FRZ_MASK|SPI_MCR_DCONF(0)|SPI_MCR_SMPL_PT(0);

   setSpeed(0);   // Use default speed
   setCTAR0Value(SPI_CTAR_SLAVE_FMSZ(8-1)); // 8-bit transfers
   setCTAR1Value(SPI_CTAR_SLAVE_FMSZ(8-1)); // 8-bit transfers
}

#endif // !defined(SPI1_SCK_GPIO)  || !defined(SPI1_SIN_GPIO) || !defined(SPI1_SOUT_GPIO)
#endif // SPI1

   static const uint16_t pbrFactors[] = {2,3,5,7};
   static const uint16_t brFactors[]  = {2,4,6,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

/**
 * Sets Communication speed for SPI
 *
 * @param frequency => Frequency in Hz (0 => use default value)
 *
 * Note: Chooses the highest speed that is not greater than frequency.
 * Note: Only has effect from when the CTAR value is next changed
 */
void SPI::setSpeed(uint32_t targetFrequency) {

   if (targetFrequency == 0) {
      targetFrequency = DEFAULT_SPI_FREQUENCY;
   }
   int bestPBR = 0;
   int bestBR  = 0;
   uint32_t difference = -1;
   for (int pbr = 3; pbr >= 0; pbr--) {
      for (int br = 15; br >= 0; br--) {
         uint32_t calculatedFrequency = SystemBusClock/(pbrFactors[pbr]*brFactors[br]);
         if (calculatedFrequency > targetFrequency) {
            // Too high stop looking here
            break;
         }
         if ((targetFrequency - calculatedFrequency) < difference) {
            // New "best value"
            difference = (targetFrequency - calculatedFrequency);
            bestBR  = br;
            bestPBR = pbr;
            interfaceFrequency = calculatedFrequency;
         }
      }
   }
   spiBaudValue = SPI_CTAR_BR(bestBR)|SPI_CTAR_PBR(bestPBR);
}

/**
 * Transmit and receive an value over SPI
 *
 * @param data - Data to send (8-16 bits) <br>
 *               May include other control bits
 *
 * @return Data received
 */
uint32_t SPI::txRx(uint32_t data) {
   spi->MCR &= ~SPI_MCR_HALT_MASK;
   spi->PUSHR = data;
   while ((spi->SR & SPI_SR_TCF_MASK)==0) {
      __asm__("nop");
   }
   spi->SR = SPI_SR_TCF_MASK|SPI_SR_EOQF_MASK;
   return spi->POPR;  // Return read data
}

/**
 *  Transmit and receive a series of 4 to 8-bit values
 *
 *  @param dataSize  Number of values to transfer
 *  @param dataOut   Transmit bytes (may be NULL for Rx only)
 *  @param dataIn    Receive byte buffer (may be NULL for Tx only)
 */
void SPI::txRxBytes(uint32_t dataSize, const uint8_t *dataOut, uint8_t *dataIn) {
   while(dataSize-->0) {
      uint32_t sendData = 0xFF;
      if (dataOut != 0) {
         sendData = *dataOut++;
      }
      if (dataSize == 0) {
         sendData |= SPI_PUSHR_EOQ_MASK;
      }
      else {
         sendData |= SPI_PUSHR_CONT_MASK;
      }
      uint32_t data = txRx(sendData|pushrMask);
      if (dataIn != 0) {
         *dataIn++ = data;
      }
   }
   spi->MCR |= SPI_MCR_HALT_MASK;
   while ((spi->SR&SPI_SR_TXRXS_MASK)) {
      __asm__("nop");
   }
}

/**
 *  Transmit and receive a series of 9 to 16-bit values
 *
 *  @param dataSize  Number of values to transfer
 *  @param dataOut   Transmit values (may be NULL for Rx only)
 *  @param dataIn    Receive buffer (may be NULL for Tx only)
 */
void SPI::txRxWords(uint32_t dataSize, const uint16_t *dataOut, uint16_t *dataIn) {
   while(dataSize-->0) {
      uint32_t sendData = 0xFFFF;
      if (dataOut != 0) {
         sendData = *dataOut++;
      }
      if (dataSize == 0) {
         sendData |= SPI_PUSHR_EOQ_MASK;
      }
      else {
         sendData |= SPI_PUSHR_CONT_MASK;
      }
      uint32_t data = txRx(sendData|pushrMask);
      if (dataIn != 0) {
         *dataIn++ = data;
      }
   }
   spi->MCR |= SPI_MCR_HALT_MASK;
   while ((spi->SR&SPI_SR_TXRXS_MASK)) {
      __asm__("nop");
   }
}

