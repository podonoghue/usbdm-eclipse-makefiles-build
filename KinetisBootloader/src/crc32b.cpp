// ----------------------------- crc32b --------------------------------

#include "crc32b.h"

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
 * From: https://stackoverflow.com/a/21001712
 *
 * @param data Data to process
 * @param size Size of data
 *
 * @return Calculated CRC32B value
 */
uint32_t Crc32::crc32b(uint8_t *data, uint32_t size) {

   // Seed CRC
   uint32_t crc = 0xFFFFFFFF;

   while (size-->0) {
      uint32_t byte = *data++;          // Get next byte.
      crc = crc ^ byte;
      for (int j = 7; j >= 0; j--) {   // Do for each bit in byte
         uint32_t mask = -(crc & 1);
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
      }
   }
   return ~crc;
}
