/*
 ================================================================================
 * @file    ht16k33_14_SegmentDisplay-example.cpp (180.ARM_Peripherals/Snippets/)
 * @brief   Demonstration of 14-segment display
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ================================================================================
 */
#include "string.h"
#include "hardware.h"
#include "HT16k33_14_SegmentDisplay.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

int main() {

   I2c *i2c = new I2c0;
   HT16k33_14_SegmentDisplay *display = new HT16k33_14_SegmentDisplay(i2c);

   for(;;) {
      display->write("\rabcd");
      waitMS(500);
      display->setPadding(Padding_LeadingZeroes);
      display->write(12);
      waitMS(500);
      display->setPadding(Padding_LeadingSpaces);
      display->write(12);
      waitMS(500);
      display->setPadding(Padding_TrailingSpaces);
      display->write(12);
      waitMS(500);
      for (int i=0; i<26; i++) {
         display->write((char)('a'+i));
         waitMS(400);
      }
      for (int i=0; i<26; i++) {
         display->write((char)('A'+i));
         waitMS(400);
      }
      console.setPadding(Padding_LeadingZeroes);
      for(;;) {
         char buff[10];
         console.write("4 character message ").gets(buff, sizeof(buff));
         display->write(buff);
      }
   }

}
