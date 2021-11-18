/**
 ================================================================================
 * @file    flexbus-example.cpp (180.ARM_Peripherals/Sources/flexbus-example.cpp)
 * @brief   Basic demo of Flexbus use
 *
 *  Created on: 10/11/2021
 *      Author: podonoghue
 ================================================================================
 */
#include "hardware.h"
#include "flexbus.h"

using namespace USBDM;

int main() {

   // Address where external memory is to be mapped to internal memory space
   // See MCU description for suitable ranges
   constexpr uint32_t BASE_ADDRESS1 = 0x08FC0000;
   constexpr uint32_t BASE_ADDRESS2 = 0x60FC0000;

   Flexbus::enable();
   Flexbus::configureAllPins();
   static const FlexbusEntry flexbusEntries[] = {
         {0, BASE_ADDRESS1, FlexbusSize_128k, FlexbusMode_ReadWrite, FlexbusWait_0, FlexbusPortSize_8bit, FlexbusAutoAck_Enabled},
         {1, BASE_ADDRESS2, FlexbusSize_256k, FlexbusMode_ReadWrite, FlexbusWait_0, FlexbusPortSize_8bit, FlexbusAutoAck_Enabled},
   };
   Flexbus::configureSelectRanges(flexbusEntries);
   Flexbus::configureMultiplexing(FlexbusGroup1_FB_ALE);

   static const MemoryAddressWrapper<uint8_t, BASE_ADDRESS1, 100> externalRam1;
   static const MemoryAddressWrapper<uint8_t, BASE_ADDRESS2, 100> externalRam2;

   constexpr uint8_t value = 0x34;

   externalRam1[3] = value;
   console.write("Wrote ").write(value).write(", Read back ").writeln(externalRam1[3]);

   externalRam2[3] = value;
   console.write("Wrote ").write(value).write(", Read back ").writeln(externalRam2[3]);

   for(;;) {
   }
   return 0;
}
