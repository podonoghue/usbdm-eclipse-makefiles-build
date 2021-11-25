/**
 ================================================================================
 * @file    sdramc-example.cpp (180.ARM_Peripherals/Snippets/sdramc-example.cpp)
 * @brief   SDRAM Controller example for MK28_FRDM
 *
 *  Created on: 20/11/2021
 *      Author: podonoghue
 ================================================================================
 */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "hardware.h"
#include "is42sm16800h.h"

using namespace USBDM;

// Which K28 Memory Mapping to use
#define MEM_MAP 1

// What size to access the SDRAM at when testing
using AccessType = uint16_t;

// Size of SDRAM in bytes
static constexpr uint32_t SDRAM_SIZE = 1<<23;

#if MEM_MAP == 0
/**
 * [0x0800_0000-0x0FFF_FFFF] SDRAM Cortex-M4 core (M0) only
 * Aliased area mapped to the same access space of [0x8800_0000-0x8FFF_FFFF]
 * May be used to access SDRAM but SDRAMC blocks should be placed [0x8800_0000-0x8FFF_FFFF]
 */
static constexpr uint32_t SDRAMC_BASEADDRESS = 0x8800'0000;
constexpr const MemoryAddressWrapper<AccessType, 0x0800'0000, SDRAM_SIZE/sizeof(AccessType)> sdram;

#elif  MEM_MAP == 1
/**
 * 0x7000_0000-0x7FFF_FFFF SDRAM (External Memory - Write-back) All masters
 */
static const uint32_t SDRAMC_BASEADDRESS = 0x7000'0000;
constexpr const MemoryAddressWrapper<AccessType, SDRAMC_BASEADDRESS, SDRAM_SIZE/sizeof(AccessType)> sdram;

#elif  MEM_MAP == 2
/**
 * 0x8000_0000-0x87FF_FFFF SDRAM (External Memory - Write-through) All masters
 */
static const uint32_t SDRAMC_BASEADDRESS = 0x8000'0000;
constexpr MemoryAddressWrapper<AccessType, SDRAMC_BASEADDRESS, SDRAM_SIZE/sizeof(AccessType)> sdram;

#elif MEM_MAP == 3
/**
 * 0x8800_0000-0x8FFF_FFFF SDRAM (External Memory - Write-through) All masters
 */
static const uint32_t SDRAMC_BASEADDRESS = 0x8800'0000;
constexpr MemoryAddressWrapper<AccessType, SDRAMC_BASEADDRESS, SDRAM_SIZE/sizeof(AccessType)> sdram;

#endif

int main() {
   console.writeln("Starting SDRAMC testing");
   console.write("Flexbus Clock = ").writeln(SystemFlexbusClock);

   // Allow off-chip access to SDRAM
   SimInfo::setExternalBusSecurity(SimExternalBusSecurity_AllAllowed);

   // Configure SDRAMC
   console.writeln("Configuring SDRAM Controller");
   Sdramc::configure(SdramRefreshTiming_3Clocks, 4096, 64);

   // Configure SDRAMC block 0 as IS42SM16800H SDRAM
   console.writeln("Configuring IS42SM16800H SDRAM");
   Is42sm16800h<SDRAMC_BASEADDRESS, SdramcBlock0>::configure();

   unsigned successCount = 0;
   unsigned failCount    = 0;

   for(unsigned run=1; ;run++ ) {

      // rand() is expected to generate the same pseudo-random sequence from the same seed
      const auto seed = time(NULL);

      // Fill SDRAM with random number sequence
      srand(seed);
      for (size_t index=0; index<sdram.size; index++) {
         sdram[index] = (AccessType)rand();
      }

      // Read-back SDRAM and verify against same random number sequence
      bool failed = false;
      srand(seed);
      for (size_t index=0; index<sdram.size; index++) {
         AccessType probe     = sdram[index];
         AccessType reference = rand();
         if (reference != probe) {
            failed = true;
            console.write(index).write(": Read = 0x").write(probe, Radix_16).write(", Ref = ").write(reference, Radix_16).writeln("Failed");
         }
      }
      if (failed) {
         failCount++;
      }
      else {
         successCount++;
      }
      console.setWidth(3).setPadding(Padding_LeadingSpaces);
      console.
         write("Test run ").write(run).
         write(", Successful = ").write(successCount).
         write(", Failed = ").writeln(failCount);
      console.resetFormat();
   }
   return 0;
}
