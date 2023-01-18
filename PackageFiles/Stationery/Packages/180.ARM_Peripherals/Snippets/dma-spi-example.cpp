/**
 ============================================================================
 * @file    dma-spi-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   DMA example using SPI
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
/**
 * This example uses DMA to transfer data from a buffer to the SPI for transmission.
 * At the same time another DMA channel is used to transfer receive data from the SPI to a buffer.
 * The transmission is not continuous but may be restarted without setting up the TCD again:
 * - Clears the DREQ on transfer complete
 * - Arranging SLAST/DLAST to return the transfer addresses to starting value after each major-loop.
 *
 * This example requires DMA and SPI interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->DMA0 and "Peripheral Parameters"->SPI tabs
 * Select irqHandlingMethod option (Class Method - Software ...)
 */
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "hardware.h"
#include "dma.h"
#include "spi.h"

using namespace USBDM;

// Connection - change as required
using Led = GpioC<3, ActiveLow>;  // = PTA2 = D9 = Blue LED

// SPI to use
Spi0 spi;

// Single configuration
static const Spi::Init configuration {
   {  /* Shared settings            */
      SpiPeripheralSelectPolarity_All_ActiveHigh, // All PCSs active-high

      // These are initial transfer settings. Can be changed using selectConfiguration().
      SpiCtarSelect_0,                       // Use CTAR0
      SpiPeripheralSelect_0,                 // PCS0 is asserted during transfer
      SpiPeripheralSelectMode_Transaction    // PCSx goes low between transactions
   },
   //                                 Speed   Mode       Frame Size
   /* Configuration (all CTARs)  */ { 10_MHz, SpiMode_3, SpiFrameSize_8_bits},
};

int main() {
   console.writeln("Starting");

   // Enable DMAC with default settings
   Dma0::configure();

   // Configure SPI */
   spi.configure(configuration);

   constexpr unsigned MaxNumDataItems = 1000;
   constexpr unsigned NumDataItems    = 10;

   static_assert(NumDataItems<MaxNumDataItems, "Fix this!");

   using DataSize = uint8_t;

   // Transmit data
   DataSize txBuffer[NumDataItems];

   // Receive buffer
   DataSize rxBuffer[NumDataItems];

   auto dmaHandler = spi.createDmaHandler<MaxNumDataItems>();

   // Set up DMA transfer from memory -> SPI -> memory
   dmaHandler.initialiseDma(rxBuffer);

   // Keep configuration for re-use
   dmaHandler.setKeepDmaConfiguration(true);
//   dmaHandler.initDmaBuffer(NumDataItems);

   Led::setOutput();

   /* Initialises random number generator */
   srand(time(nullptr));

   unsigned failureCount = 0;

   for(int count=0;;count++) {

      static DmaChannelNum dummyDmaChannel0 = DmaChannelNum_None;
      static DmaChannelNum dummyDmaChannel1 = DmaChannelNum_None;

      // Force use of different channels for alternating transfers
      // This is to test that resources are re-used correctly
      if ((count&1) == 0) {
         // Allocate dummy channels
         dummyDmaChannel0 = Dma0::allocatePeriodicChannel();
         dummyDmaChannel1 = Dma0::allocatePeriodicChannel();
      }
      else {
         // Release dummy channels
         Dma0::freeChannel(dummyDmaChannel0);
         Dma0::freeChannel(dummyDmaChannel1);
      }

      // Fill Tx buffer with random data
      for (unsigned index=0; index<sizeofArray(txBuffer); index++) {
         txBuffer[index]   = rand();
         dmaHandler.writeDataToBuffer(index, txBuffer[index]);
      }
      dmaHandler.writeEndDataToBuffer(sizeofArray(txBuffer)-1, txBuffer[sizeofArray(txBuffer)-1]);

      // Set up DMA transfer from memory -> SPI -> memory
//      dmaHandler.initialiseTransfer(txBuffer, rxBuffer);
//      dmaHandler.loadTxData(txBuffer);

      checkError();

      // Clear Rx buffer
      memset(rxBuffer, 0, sizeof(rxBuffer));

      console.write(count, ": Starting Transfer,");

      // Start transfer
      dmaHandler.startTransfer();

      // Wait for completion
      while (dmaHandler.isBusy()) {
         __asm__("nop");
      }

      // Check expected Rx data
      if (memcmp(rxBuffer, txBuffer, sizeof(rxBuffer)) != 0) {
         failureCount++;
         console.writeln("Failed   - fail count = ", failureCount);
      }
      else {
         console.writeln("Verified - fail count =", failureCount);
      }
   }
   return 0;
}
