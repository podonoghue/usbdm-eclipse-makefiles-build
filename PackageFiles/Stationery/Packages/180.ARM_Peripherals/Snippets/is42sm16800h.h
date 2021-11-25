/*
 * @file is42sm16800h.h (180.ARM_Peripherals/Snippets/is42sm16800h.h)
 *
 *  Created on: 19 Nov. 2021
 *      Author: peter
 */

#ifndef SOURCES_IS42SM16800H_H_
#define SOURCES_IS42SM16800H_H_
#include "hardware.h"
#include "sdramc.h"

namespace USBDM {

/**
 * Class representing a IS42SM16800H SDRAM connected to the SDRAM controller
 *
 * @tparam baseAddress  Base address of SDRAM in MCU memory space
 * @tparam sdramcBlock  Which SDRAMC block is to be used to access the SDRAM
 */
template<uint32_t baseAddress, SdramcBlock sdramcBlock>
class Is42sm16800h {

   /**
    * Assemble a IS42SM16800H-6BLI SDRAM Mode Register value
    *
    * @param burstMode     Burst mode \n
    * @param casLatency    CAS Latency \n
    * @param burstType     Burst Type \n
    * @param burstLength   Burst Length \n
    *
    * @return Assembled value
    *
    * @note The returned value will still need to be shuffled to match the SDRAMC mapping
    *
    *  From IS42SM16800H-6BLI data sheet \n
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
    *  From IS42SM16800H-6BLI data sheet \n
    *  Figure 5 Extended Mode Register  (written via address lines)
    * @code
    *  | BA1 | BA0 | A11 | A10 |  A9 |  A8 |  A7 |  A6 |  A5 |  A4 |  A3 |  A2 |  A1 |  A0 | <= SDRAM pins
    *  | M13 | M12 | M11 | M10 |  M9 |  M8 |  M7 |  M6 |  M5 |  M4 |  M3 |  M2 |  M1 |  M0 | <= Mode Register
    *  |  1  |  0  |  -  |  -  |  0  |  -  |  -  |  0  |  1  |  0  |  0  |  0  |  0  |  0  | <= MR Value
    *                                               |     |                 |     |     |
    *                                 +++-----------+-----+   +++-----------+-----+-----+
    *                                 |||                     |||
    *                                 M65                    M210 Self Refresh Coverage
    *                                 *00 Full Strength      *000 All Banks
    *                                  01 1/2 Strength        001 Two Banks (BA1=0)
    *                                  10 1/4 Strength        010 One Bank (BA1=BA0=0)
    *                                  11 -                   011 -
    *                                                         100 -
    *                                                         101 Half of One Bank (BA1=BA0=0, Row Address MSB=0)
    *                                                         110 Quarter of One Bank (BA1=BA0=0, Row Address 2 MSB=0)
    *                                                         111 -
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
    * Information about IS42SM16800H
    *
    * @code
    * -------------------------------------------------------------
    * Row Address       : RA0~RA11 (12 bits => 2^12 = 4096 rows)
    * Column Address    : CA0~CA8   (9 bits)
    * Bank Address      : BA0-BA1   (2 bits => 4 banks)
    * Auto Precharge    : SDRAM-A10 (command bit) => SDRAMC-A20
    * Refresh interval  : All rows done in 64ms
    * Data              : DQ0-DQ15  (16-bit data port)
    * Strobes           : LDQM,UDQM
    * Size              : 2^23 16-bit words = 128 Mb = 16 MiB
    * @endcode
    */
   static constexpr SdramMapping IS42SM16800H_mapping = sdramMapping_16B_9C;

   /// Entry describing IS42SM16800H connection to SDRAMC
   static constexpr SdramEntry is42sm16800h_Config = {
         /* Block #                 */ sdramcBlock,
         /* Memory address          */ baseAddress,
         /* CAS Latency             */ SdramcCasl_2,
         /* CMD address line        */ Sdramc::getCommandAdddress(IS42SM16800H_mapping),
         /* Data port size          */ SdramcPortSize_16,
         /* SDRAM size              */ SdramSize_16MiB,
         /* Access mode             */ SdramcMode_ReadWrite,
         /* Mode register           */ Sdramc::shuffleAddress(IS42SM16800H_mapping, IS42SM16800H_makeModeRegister1Value(0, 0b010, 0, 0)),
         /* Extended mode register  */ Sdramc::shuffleAddress(IS42SM16800H_mapping, IS42SM16800H_makeModeRegister2Value(0, 0))
   };

public:
   /**
    * Configure the SDRAM controller interface for the IS42SM16800H SDRAM
    */
   static void configure() {
      Sdramc::configureBlock(is42sm16800h_Config);
   }
};
} // end namespace USBDM

#endif /* SOURCES_IS42SM16800H_H_ */
