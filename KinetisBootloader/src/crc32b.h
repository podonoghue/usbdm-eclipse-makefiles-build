/*
 * crc32b.h
 *
 *  Created on: 10 Dec 2019
 *      Author: podonoghue
 */

#ifndef CRC32B_H_
#define CRC32B_H_

#include <stdint.h>

/**
 * This is the basic CRC-32 calculation with some optimization but no
 * table lookup. The byte reversal is avoided by shifting the crc reg
 * right instead of left and by using a reversed 32-bit word to represent
 * the polynomial.
 *
 * When compiled to Cyclops with GCC, this function executes in 8 + 72n
 * instructions, where n is the number of bytes in the input message. It
 * should be doable in 4 + 61n instructions.
 *
 * If the inner loop is strung out (approx. 5*8 = 40 instructions),
 * it would take about 6 + 46n instructions.
 *
 * Based on: https://stackoverflow.com/a/21001712
 */
class Crc32 {

private:
   // Ongoing CRC value
   uint32_t crcValue;

public:
   /**
    * Construct Crc32 object
    */
   Crc32() : crcValue(0xFFFFFFFF) {}

   /**
    * Destructor
    */
   ~Crc32() {}

   /**
    * This is the basic CRC-32 calculation
    *
    * From: https://stackoverflow.com/a/21001712
    *
    * @param data Data to process
    * @param size Size of data
    *
    * @return Calculated CRC32B value
    */
   static uint32_t crc32b(uint8_t *start, uint32_t size);

   /**
    * Add a byte to the CRC calculation
    *
    * @param byte Value to process
    */
   void addByte(uint32_t byte) {
      crcValue = crcValue ^ byte;
      for (int j = 7; j >= 0; j--) {   // Do for each bit in byte
         uint32_t mask = -(crcValue & 1);
         crcValue = (crcValue >> 1) ^ (0xEDB88320 & mask);
      }
   }

   /**
    * Get calculated CRC value
    *
    * @return CRC value
    */
   uint32_t getCrc() {
      return ~crcValue;
   }
};

#endif /* CRC32B_H_ */
