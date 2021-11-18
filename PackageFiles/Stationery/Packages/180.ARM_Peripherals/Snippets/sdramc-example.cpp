/**
 ================================================================================
 * @file    sdramc-example.cpp (180.ARM_Peripherals/Snippets/sdramc-example.cpp)
 * @brief   Basic SDRAM Controller example
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ================================================================================
 */
#include "hardware.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// K28 Memory Map

#define MEM_MAP 1

#if MEM_MAP == 0
/**
 * [0x0800_0000-0x0FFF_FFFF] SDRAM Cortex-M4 core (M0) only
 * Aliased area mapped to the same access space of [0x8800_0000-0x8FFF_FFFF]
 * May be used to access SDRAM but SDRAMC blocks should be placed [0x8800_0000-0x8FFF_FFFF]
 */
static constexpr uint32_t SDRAMC_BASEADDRESS1 = 0x8800'0000;
static const MemoryAddressWrapper<uint16_t, 0x0800'0000, (1<<23)/2> sdram;

#elif  MEM_MAP == 1
/**
 * 0x7000_0000-0x7FFF_FFFF SDRAM (External Memory - Write-back) All masters
 */
static const uint32_t SDRAMC_BASEADDRESS1 = 0x7000'0000;
MemoryAddressWrapper<uint16_t, SDRAMC_BASEADDRESS1, (1<<23)/2> sdram;

#elif  MEM_MAP == 2
/**
 * 0x8000_0000-0x87FF_FFFF SDRAM (External Memory - Write-through) All masters
 */
static const uint32_t SDRAMC_BASEADDRESS1 = 0x8000'0000;
MemoryAddressWrapper<uint16_t, SDRAMC_BASEADDRESS1, (1<<23)/2> sdram;

#elif MEM_MAP == 3
/**
 * 0x8800_0000-0x8FFF_FFFF SDRAM (External Memory - Write-through) All masters
 */
static const uint32_t SDRAMC_BASEADDRESS1 = 0x8800'0000;
MemoryAddressWrapper<uint16_t, SDRAMC_BASEADDRESS1, (1<<23)/2> sdram;

#endif

/**
 * Assemble a IS42SM16800H-6BLI SDRAM Mode Register value
 *
 * @param burstMode     Burst mode
 * @param casLatency    CAS Latency
 * @param burstType     Burst Type
 * @param burstLength   Burst Length
 *
 * @return Assembled value
 *
 * @note The returned value will still need to be shuffled to match the SDRAMC mapping
 *
 *  From IS42SM16800H-6BLI data sheet
 *  Figure 4 Mode Register Definitions (written via address lines)
 * @code
 *  | BA1 | BA0 | A11 | A10 |  A9 |  A8 |  A7 |  A6 |  A5 |  A4 |  A3 |  A2 |  A1 |  A0 | <= SDRAM pins
 *  | M13 | M12 | M11 | M10 |  M9 |  M8 |  M7 |  M6 |  M5 |  M4 |  M3 |  M2 |  M1 |  M0 | <= Mode Register
 *  |  0  |  0  |  -  |  -  |  0  |  -  |  -  |  0  |  1  |  0  |  0  |  0  |  0  |  0  | <= MR Value
 *                             |                 |     |     |     |     |     |     |
 *   +-------------------------+   +++-----------+-----+-----+   +-+     +-----+-----+-+++
 *   |                             |||                           |                     |||
 *  M9 Write Burst Mode           M654 CAS Latency              M3 Burst Type        M3210 Burst Length
 *  *0 Burst Read/Write            000 -                        *0 Sequential        *X000 1
 *   1 Burst Read only             001 -                         1 Interleave         X001 2
 *                                *010 2                                              X010 4
 *                                 011 3                                              X011 8
 *                                 100 -                                              X100 -
 *                                 101 -                                              X101 -
 *                                 110 -                                              X110 -
 *                                 111 -                                              X111 -
 * @endcode
 */
static constexpr uint32_t IS42SM16800H_makeModeRegister1Value(
      unsigned burstMode,
      unsigned casLatency,
      unsigned burstType,
      unsigned burstLength
) {
   return
         (burstMode<<9)   |
         (casLatency<<4)  |
         (burstType<<3)   |
         (burstLength<<0) |
         0b00<<12; // BA[1..0] = 0b00
}

/**
 * Assemble a IS42SM16800H-6BLI SDRAM Extended Mode Register value
 *
 * @param driveStrength          Drive strength
 * @param selfRefreshCoverage    Self Refresh Cover
 *
 * @return Assembled value
 *
 * @note The returned value will still need to be shuffled to match the SDRAMC mapping
 *
 *  From IS42SM16800H-6BLI data sheet
 *  Figure 5 Extended Mode Register  (written via address lines)
 * @code
 *  | BA1 | BA0 | A11 | A10 |  A9 |  A8 |  A7 |  A6 |  A5 |  A4 |  A3 |  A2 |  A1 |  A0 | <= SDRAM pins
 *  | M13 | M12 | M11 | M10 |  M9 |  M8 |  M7 |  M6 |  M5 |  M4 |  M3 |  M2 |  M1 |  M0 | <= Mode Register
 *  |  1  |  0  |  -  |  -  |  0  |  -  |  -  |  0  |  1  |  0  |  0  |  0  |  0  |  0  | <= MR Value
 *                                               |     |                 |     |     |
                                   +++-----------+-----+          +++----+-----+-----+
 *                                 |||                            |||
 *                                 M65                           M210 Self Refresh Coverage
 *                                 *00 Full Strength             *000 All Banks
 *                                  01 1/2 Strength               001 Two Banks (BA1=0)
 *                                  10 1/4 Strength               010 One Bank (BA1=BA0=0)
 *                                  11 -                          011 -
 *                                                                100 -
 *                                                                101 Half of One Bank (BA1=BA0=0, Row Address MSB=0)
 *                                                                110 Quarter of One Bank (BA1=BA0=0, Row Address 2 MSB=0)
 *                                                                111 -
 * @endcode
 */
static constexpr uint32_t IS42SM16800H_makeModeRegister2Value(
      unsigned driveStrength,
      unsigned selfRefreshCoverage
) {
   return
         (driveStrength<<5)  |
         (selfRefreshCoverage<<0) |
         0b10<<12; // BA[1..0] = 0b10
}

/**
 * IS42SM16800H-6BLI
 * -------------------------------------------------------------
 * Row Address       : RA0~RA11 (12 bits => 2^12 = 4096 rows)
 * Column Address    : CA0~CA8   (9 bits)
 * Bank Address      : BA0-BA1   (2 bits => 4 banks)
 * Auto Precharge    : SDRAM-A10 (command bit) => SDRAMC-A20
 * Refresh interval  : All rows done in 64ms
 * Data              : DQ0-DQ15  (16-bit data port)
 * Strobes           : LDQM,UDQM
 * Size              : 2^23 16-bit words = 128 Mb = 16 MiB
 */
static const SdramMapping IS42SM16800H_mapping = sdramMapping_16B_9C;

// Entry describing IS42SM16800H connection to SDRAMC
static const SdramEntry IS42SM16800H = {
      /* Block #                 */ SdramcBlock0,
      /* Memory address          */ SDRAMC_BASEADDRESS1,
      /* CAS Latency             */ SdramcCasl_224211,
      /* CMD address line        */ Sdramc::getCommandAdddress(IS42SM16800H_mapping),
      /* Data port size          */ SdramcPortSize_16,
      /* SDRAM size              */ SdramSize_16MiB,
      /* Access mode             */ SdramcMode_ReadWrite,
      /* Mode register           */ Sdramc::shuffleAddress(IS42SM16800H_mapping, IS42SM16800H_makeModeRegister1Value(0, 0b010, 0, 0)),
      /* Extended mode register  */ Sdramc::shuffleAddress(IS42SM16800H_mapping, IS42SM16800H_makeModeRegister2Value(0, 0))
};

int main() {
   console.writeln("Starting\n");
   console.write("Flexbus Clock = ").writeln(SystemFlexbusClock);

   SimInfo::getPeripheralClock();
   SimInfo::getDividedPeripheralClock();

   // Allow off-chip access to SDRAM
   SimInfo::setExternalBusSecurity(SimExternalBusSecurity_AllAllowed);

   // This port multiplexing is shared by FLEXBUS and SDRAM
   // Do basic flexbus enable (including pin mapping of BE signals)
   Flexbus::enable();
   Flexbus::configureMultiplexing(
         FlexbusGroup1_FB_ALE,
         FlexbusGroup2_FB_BE_31_24,
         FlexbusGroup3_FB_BE_23_16,
         FlexbusGroup4_FB_BE_15_8,
         FlexbusGroup5_FB_BE_7_0);

   Sdramc::configure();
   Sdramc::setRefreshParameters(SdramRefreshTiming_3Clocks, 4096, 64);
   Sdramc::configureBlock(IS42SM16800H);

   const size_t NUMBER_OF_TESTS = sdram.size;

   unsigned successCount = 0;
   unsigned failCount    = 0;

   for(unsigned run=1; ;run++ ) {
      const auto seed = time(NULL);
      srand(seed);
      for (size_t index=0; index<NUMBER_OF_TESTS; index++) {
         sdram[index] = rand();
      }
      bool failed = false;
      srand(seed);
      for (size_t index=0; index<NUMBER_OF_TESTS; index++) {
         uint16_t probe = sdram[index];
         uint16_t reference = rand();
         failed = failed || (reference != probe);
         if (failed) {
            console.write(index).write(": Read = 0x").write(probe, Radix_16).write(", Ref = ").write(reference, Radix_16).writeln("Failed");
         }
      }
      if (failed) {
         failCount++;
      }
      else {
         successCount++;
      }
      console.setWidth(4).setPadding(Padding_LeadingSpaces);
      console.
         write("Run ").write(run).
         write(" Successful = ").write(successCount).
         write(" Failed = ").writeln(failCount);
   }
   return 0;
}
