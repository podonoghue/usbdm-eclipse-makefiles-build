/*
 ================================================================================
 * @file    ht16k33_14_SegmentDisplay.cpp (180.ARM_Peripherals/Snippets/)
 * @brief   Interface for a 14-segment display
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "string.h"
#include "HT16k33_14_SegmentDisplay.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

#ifdef nativeToLe16
#undef nativeToLe16
#endif

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
constexpr uint16_t nativeToLe16(uint16_t data) {
   return ((data>>8)&0xFF)|((data<<8)&0xFF00);
}
constexpr uint16_t nativeToBe16(uint16_t data) {
   return data;
}
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
constexpr uint16_t nativeToBe16(uint16_t data) {
   return ((data>>8)&0xFF)|((data<<8)&0xFF00);
}
constexpr uint16_t nativeToLe16(uint16_t data) {
   return data;
}
#else
#error "Unexpected __BYTE_ORDER__ value"
#endif

/**
 * Character -> segment table
 * The values in the table are in little-endian order to reflect
 * the data format of the interface chip when transmitting individual bytes
 */
static const uint16_t fontTable[] = {
      nativeToLe16(0b0000000000000001),  // bit 0
      nativeToLe16(0b0000000000000010),  // bit 1
      nativeToLe16(0b0000000000000100),  // bit 2
      nativeToLe16(0b0000000000001000),  // bit 3
      nativeToLe16(0b0000000000010000),  // bit 4
      nativeToLe16(0b0000000000100000),  // bit 5
      nativeToLe16(0b0000000001000000),  // bit 6
      nativeToLe16(0b0000000010000000),  // bit 7
      nativeToLe16(0b0000000100000000),  // bit 8
      nativeToLe16(0b0000001000000000),  // bit 9
      nativeToLe16(0b0000010000000000),  // bit 10
      nativeToLe16(0b0000100000000000),  // bit 11
      nativeToLe16(0b0001000000000000),  // bit 12
      nativeToLe16(0b0010000000000000),  // bit 13
      nativeToLe16(0b0100000000000000),  // bit 14
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0000000000000000),  //
      nativeToLe16(0b0011111111111111),  // all
      nativeToLe16(0b0001001011001000),  // plus-minus
      nativeToLe16(0b0001001011001001),  // divide
      nativeToLe16(0b0000000000000000),  // space
      nativeToLe16(0b0000000000000110),  // !
      nativeToLe16(0b0000001000100000),  // "
      nativeToLe16(0b0001001011001110),  // #
      nativeToLe16(0b0001001011101101),  // $
      nativeToLe16(0b0000110000100100),  // %
      nativeToLe16(0b0010110100001101),  // &
      nativeToLe16(0b0000010000000000),  // '
      nativeToLe16(0b0010010000000000),  // (
      nativeToLe16(0b0000100100000000),  // )
      nativeToLe16(0b0011111111000000),  // *
      nativeToLe16(0b0001001011000000),  // +
      nativeToLe16(0b0000100000000000),  // ,
      nativeToLe16(0b0000000011000000),  // -
      nativeToLe16(0b0100000000000000),  // .
      nativeToLe16(0b0000110000000000),  // /
      nativeToLe16(0b0000110000111111),  // 0
      nativeToLe16(0b0000000000000110),  // 1
      nativeToLe16(0b0000000011011011),  // 2
      nativeToLe16(0b0000000010001111),  // 3
      nativeToLe16(0b0000000011100110),  // 4
      nativeToLe16(0b0010000001101001),  // 5
      nativeToLe16(0b0000000011111101),  // 6
      nativeToLe16(0b0000000000000111),  // 7
      nativeToLe16(0b0000000011111111),  // 8
      nativeToLe16(0b0000000011101111),  // 9
      nativeToLe16(0b0001001000000000),  // :
      nativeToLe16(0b0000101000000000),  // ;
      nativeToLe16(0b0010010000000000),  // <
      nativeToLe16(0b0000000011001000),  // =
      nativeToLe16(0b0000100100000000),  // >
      nativeToLe16(0b0001000010000011),  // ?
      nativeToLe16(0b0000001010111011),  // @
      nativeToLe16(0b0000000011110111),  // A
      nativeToLe16(0b0001001010001111),  // B
      nativeToLe16(0b0000000000111001),  // C
      nativeToLe16(0b0001001000001111),  // D
      nativeToLe16(0b0000000011111001),  // E
      nativeToLe16(0b0000000001110001),  // F
      nativeToLe16(0b0000000010111101),  // G
      nativeToLe16(0b0000000011110110),  // H
      nativeToLe16(0b0001001000000000),  // I
      nativeToLe16(0b0000000000011110),  // J
      nativeToLe16(0b0010010001110000),  // K
      nativeToLe16(0b0000000000111000),  // L
      nativeToLe16(0b0000010100110110),  // M
      nativeToLe16(0b0010000100110110),  // N
      nativeToLe16(0b0000000000111111),  // O
      nativeToLe16(0b0000000011110011),  // P
      nativeToLe16(0b0010000000111111),  // Q
      nativeToLe16(0b0010000011110011),  // R
      nativeToLe16(0b0000000011101101),  // S
      nativeToLe16(0b0001001000000001),  // T
      nativeToLe16(0b0000000000111110),  // U
      nativeToLe16(0b0000110000110000),  // V
      nativeToLe16(0b0010100000110110),  // W
      nativeToLe16(0b0010110100000000),  // X
      nativeToLe16(0b0001010100000000),  // Y
      nativeToLe16(0b0000110000001001),  // Z
      nativeToLe16(0b0000000000111001),  // [
      nativeToLe16(0b0010000100000000),  // backslash
      nativeToLe16(0b0000000000001111),  // ]
      nativeToLe16(0b0000110000000011),  // ^
      nativeToLe16(0b0000000000001000),  // _
      nativeToLe16(0b0000000100000000),  // `
      nativeToLe16(0b0001000001011000),  // a
      nativeToLe16(0b0010000001111000),  // b
      nativeToLe16(0b0000000011011000),  // c
      nativeToLe16(0b0000100010001110),  // d
      nativeToLe16(0b0000100001011000),  // e
      nativeToLe16(0b0000000001110001),  // f
      nativeToLe16(0b0000010010001110),  // g
      nativeToLe16(0b0001000001110000),  // h
      nativeToLe16(0b0001000000000000),  // i
      nativeToLe16(0b0000000000001110),  // j
      nativeToLe16(0b0011011000000000),  // k
      nativeToLe16(0b0000000000110000),  // l
      nativeToLe16(0b0001000011010100),  // m
      nativeToLe16(0b0001000001010000),  // n
      nativeToLe16(0b0000000011011100),  // o
      nativeToLe16(0b0000000101110000),  // p
      nativeToLe16(0b0000010010000110),  // q
      nativeToLe16(0b0000000001010000),  // r
      nativeToLe16(0b0010000010001000),  // s
      nativeToLe16(0b0000000001111000),  // t
      nativeToLe16(0b0000000000011100),  // u
      nativeToLe16(0b0010000000000100),  // v
      nativeToLe16(0b0010100000010100),  // w
      nativeToLe16(0b0010100011000000),  // x
      nativeToLe16(0b0000001010001110),  // y
      nativeToLe16(0b0000100001001000),  // z
      nativeToLe16(0b0000100101001001),  // {
      nativeToLe16(0b0001001000000000),  // |
      nativeToLe16(0b0010010010001001),  // }
      nativeToLe16(0b0000000011010010),  // ~
      nativeToLe16(0b0000000000000000),  // del
};

/**
 * Send display data from internal buffer to display
 */
void HT16k33_14_SegmentDisplay::sendDisplayData() {
   displayData.command = 0;
   i2c->transmit(ADDRESS, 9, &displayData.command);
}

/**
 * Initialise HT16K33
 */
void HT16k33_14_SegmentDisplay::setup() {
   wakeup();
   setDisplay(DisplayEnable_on, BlinkRate_off);
   setBrightness(15);
   setPinFunction(IntPinFunction_Driver);
}

/**
 * Writes a character (blocking)
 *
 * @param[in]  ch - character to send
 */
void HT16k33_14_SegmentDisplay::_writeCh(char ch) {
   if (ch == '\r') {
      // Move to start of line
      position = 0;
      return;
   }
   if (position>3) {
      // Off end of display - scroll left
      position--;
      memcpy(displayData.data, displayData.data+1, sizeof(displayData.data)-sizeof(displayData.data[0]));
   }
   if (ch == '\n') {
      // New line - start over
      clear();
   }
   if (((uint8_t)ch)>(sizeof(fontTable)/sizeof(fontTable[0]))) {
      // Illegal character
      ch = '~';
   }
   displayData.data[position++] = fontTable[(uint8_t)ch];
   sendDisplayData();
}

