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
using Led = RGB_Green;

// SPI to use
Spi0 spi;

// Configuration for SPI with shared serial settings
static const Spi::Init spiConfiguration {
   {  /* Shared settings            */
      SpiPeripheralSelectPolarity_All_ActiveHigh, // All PCSs active-high

      // These are initial transfer settings. Can be changed using selectConfiguration().
      SpiCtarSelect_0,                       // Use CTAR0
      SpiPeripheralSelect_0,                 // PCS to assert during transfer
      SpiPeripheralSelectMode_Transaction    // PCSx goes low between transactions
   },
   //                                 Speed   Mode       Frame Size
   /* Configuration (all CTARs)  */ { 10_MHz, SpiMode_3, SpiFrameSize_8_bits},
};

// Size of elements to transfer (should be consistent with SPI frame-size above)
using DataSize = uint8_t;

// Configuration for DMAC
static constexpr DmaBasicInfo::DmaConfig dmaConfiguration = {
   DmaActionOnError_Halt ,        // DMA halt on error       - Transfer halts on any error
   DmaContinuousLink_Disabled ,   // Continuous Link mode    - Continuous Link disabled
   DmaMinorLoopMapping_Disabled , // Minor loop mapping      - Mapping disabled
   DmaArbitration_Fixed ,         // Channel Arbitration     - Fixed (within group)
   DmaInDebug_Halt,               // Operation in Debug mode - Halt in debug
};

int main() {
   console.writeln("Starting");

   // Configure DMAC
   Dma0::configure(dmaConfiguration);

   // Configure SPI */
   spi.configure(spiConfiguration);

   // Maximum number of items to Transmit or Receive
   constexpr unsigned MaxNumDataItems = 20;

   // Actual number of items
   constexpr unsigned NumDataItems    = 10;

   static_assert(NumDataItems<MaxNumDataItems, "Fix this!");

   // Transmit data
   DataSize txBuffer[NumDataItems];

   // Receive buffer
   DataSize rxBuffer[NumDataItems];

   // This handles creates the DMA transmit buffer required for the SPI padding
   auto dmaHandler = spi.createDmaHandler<MaxNumDataItems>();

   Led::setOutput();

   /* Initialises random number generator */
   srand(time(nullptr));

//   Check DMAC channel allocations
//   Should be in order 5..max, 0..4
//   for (unsigned count=0; ; count++) {
//      DmaChannelNum dmaChannel = Dma0::allocateChannel();
//      if (dmaChannel == DmaChannelNum_None) {
//         break;
//      }
//      console.writeln("Allocated DMA Channel ", dmaChannel);
//   }
   unsigned failureCount = 0;

   for(int count=0;;count++) {

//      static DmaChannelNum dummyDmaChannel0 = DmaChannelNum_None;
//      static DmaChannelNum dummyDmaChannel1 = DmaChannelNum_None;

//      // Force use of different channels for alternating transfers
//      // This is to test that resources are re-used correctly
//      if ((count&1) == 0) {
//         // Allocate dummy channels
//         dummyDmaChannel0 = Dma0::allocatePeriodicChannel();
//         dummyDmaChannel1 = Dma0::allocatePeriodicChannel();
//      }
//      else {
//         // Release dummy channels
//         Dma0::freeChannel(dummyDmaChannel0);
//         Dma0::freeChannel(dummyDmaChannel1);
//      }

      // Fill Tx buffer with random data
      for (unsigned index=0; index<sizeofArray(txBuffer); index++) {
         txBuffer[index]   = rand();
      }

      // Set up DMA transfer from memory -> SPI -> memory
      dmaHandler.initialiseTxRx(txBuffer, rxBuffer);

//      console.writeln("TxDmaCh=", dmaHandler.dmaTransmitChannel, ", RxDmaCh=", dmaHandler.dmaReceiveChannel);

      checkError();

      // Clear Rx buffer
      memset(rxBuffer, 0, sizeof(rxBuffer));

//      console.write(count, ": Starting Transfer, ");

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
//      else {
//         console.writeln("Verified - fail count =", failureCount);
//      }
      Led::toggle();
   }
   return 0;
}
