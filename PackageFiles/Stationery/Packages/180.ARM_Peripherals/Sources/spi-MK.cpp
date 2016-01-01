/*
 * spi.cpp (derived from spi-MK.cpp)
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

namespace USBDM {

   static const uint16_t pbrFactors[] = {2,3,5,7};
   static const uint16_t brFactors[]  = {2,4,6,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

/**
 * Sets Communication speed for SPI
 *
 * @param targetFrequency => Frequency in Hz
 *
 * Note: Chooses the highest speed that is not greater than frequency.
 * Note: Only has effect from when the CTAR value is next changed
 */
void Spi::setSpeed(uint32_t targetFrequency) {
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
 * Transmit and receive a value over SPI
 *
 * @param data - Data to send (8-16 bits) <br>
 *               May include other control bits
 *
 * @return Data received
 */
uint32_t Spi::txRx(uint32_t data) {
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
void Spi::txRxBytes(uint32_t dataSize, const uint8_t *dataOut, uint8_t *dataIn) {
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
void Spi::txRxWords(uint32_t dataSize, const uint16_t *dataOut, uint16_t *dataIn) {
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

} // End namespace USBDM
