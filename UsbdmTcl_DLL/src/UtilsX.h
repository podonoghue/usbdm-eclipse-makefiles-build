/*
 * Utils.h
 *
 *  Created on: 12 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_UTILSX_H_
#define SRC_UTILSX_H_

static inline uint32_t getData32Be(uint8_t *data) {
   return (data[0]<<24)+(data[1]<<16)+(data[2]<<8)+data[3];
}

static inline uint32_t getData32Le(uint8_t *data) {
   return (data[0])+(data[1]<<8)+(data[2]<<16)+(data[3]<<24);
}

static inline uint32_t getData32(uint8_t *data) {
   if (bigEndian)
      return getData32Be(data);
   else
      return getData32Le(data);
}

static inline uint32_t getData16Be(uint8_t *data) {
   return (data[0]<<8)+data[1];
}

static inline uint32_t getData16Le(uint8_t *data) {
   return (data[0])+(data[1]<<8);
}

static inline uint32_t getData16(uint8_t *data) {
   if (bigEndian)
      return getData16Be(data);
   else
      return getData16Le(data);
}

static const uint8_t *getData4x8Le(uint32_t data) {
   static uint8_t data8[4];
   data8[0]= data;
   data8[1]= data>>8;
   data8[2]= data>>16;
   data8[3]= data>>24;
   return data8;
}

static const uint8_t *getData4x8Be(uint32_t data) {
   static uint8_t data8[4];
   data8[0]= data>>24;
   data8[1]= data>>16;
   data8[2]= data>>8;
   data8[3]= data;
   return data8;
}

static const uint8_t *getData4x8(uint32_t data) {
   if (bigEndian)
      return getData4x8Be(data);
   else
      return getData4x8Le(data);
}

static const uint8_t *getData2x8Le(uint32_t data) {
   static uint8_t data8[2];
   data8[0]= data;
   data8[1]= data>>8;
   return data8;
}

static const uint8_t *getData2x8Be(uint32_t data) {
   static uint8_t data8[2];
   data8[0]= data>>8;
   data8[1]= data;
   return data8;
}

static const uint8_t *getData2x8(uint32_t data) {
   if (bigEndian)
      return getData2x8Be(data);
   else
      return getData2x8Le(data);
}

//! Swaps Endianness of number
static void swapEndian32(uint32_t *value) {
   U32u temp1, temp2;

   temp1.longword = *value;
   temp2.bytes[0] = temp1.bytes[3];
   temp2.bytes[1] = temp1.bytes[2];
   temp2.bytes[2] = temp1.bytes[1];
   temp2.bytes[3] = temp1.bytes[0];
   *value         = temp2.longword;
}
#endif /* SRC_UTILSX_H_ */
