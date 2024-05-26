/**
 ============================================================================
 * @file    crc-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo using CRC class
 *
 *  Created on: 5 Jul 2018
 *      Author: podonoghue
 ============================================================================
 */
#include <stdlib.h>  // srand(), rand()
#include <time.h>    // time()

#include "hardware.h"
#include "crc.h"

using namespace USBDM;

using Crc = Crc0;

/** Size of data array to use */
static constexpr uint8_t ArraySize = 100;

/** Data for CRC calculation */
static uint32_t data[ArraySize];

int main(){

   /*
    * Simple tests
    * Verify against https://crccalc.com
    */
   static const uint32_t simpleData[] = {1,2,3,4,5,6,7,8,9,10};
   console.setFormat(IntegerFormat(Width_8, Radix_16, Padding_LeadingZeroes));
   console.writeln("Crc32(...)        => 0x", Crc::calculateCrc(Crc::Crc32,         simpleData));
   console.writeln("Crc32_BZIP(...)   => 0x", Crc::calculateCrc(Crc::Crc32_BZIP,    simpleData));
   console.writeln("Crc32_C(...)      => 0x", Crc::calculateCrc(Crc::Crc32_C,       simpleData));
   console.writeln("Crc32_D(...)      => 0x", Crc::calculateCrc(Crc::Crc32_D,       simpleData));
   console.writeln("Crc32_MPEG_2(...) => 0x", Crc::calculateCrc(Crc::Crc32_MPEG_2,  simpleData));
   console.writeln("Crc32_POSIX(...)  => 0x", Crc::calculateCrc(Crc::Crc32_POSIX,   simpleData));

   // Fill source with random data
   srand (time(0));
   for (unsigned index=0; index<ArraySize; index++) {
      data[index] = (uint32_t)rand();
   }

   console.writeln("\nStarting");

   // Print data
   console.setFormat(IntegerFormat(Width_8, Radix_16, Padding_LeadingZeroes));
   console.writeArray(data, sizeof(data)/sizeof(data[0]));

   // Report result
   console.setFormat(IntegerFormat(Width_8, Radix_16, Padding_LeadingZeroes));
   console.write("\nCalculated CRC = 0x", Crc::calculateCrc(Crc::Crc32,  data));

   for(;;) {
      __asm__("nop");
   }
   return 0;
}
