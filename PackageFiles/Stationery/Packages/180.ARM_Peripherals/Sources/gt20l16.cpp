/*
  @file gt20l16.cpp

  Based on GT20L16 data sheet(in Chinese!)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <stdlib.h>

#include "gt20l16.h"
#include "delay.h"

namespace USBDM {

static constexpr uint8_t GT20L16_READ_COMMAND      = (0x03);
static constexpr uint8_t GT20L16_FAST_READ_COMMAND = (0x0B);

static constexpr long SPI_FREQUENCY = (12000000);

/**
 * Constructor
 *
 * @param spi - The SPI interface to use
 */
GT20L16::GT20L16(Spi *spi) {
   this->spi  = spi;
   uint32_t spiFequency = spi->getSpeed();
   if (spiFequency>SPI_FREQUENCY) {
      spi->setSpeed(SPI_FREQUENCY);
   }
}

/**
 *  @param uniCode   Unicode character
 *  @param matrix    Buffer for display data for character
 *
 *  @return Size of display data written to buffer (either 16 or 32 bytes)
 */
int GT20L16::getMatrixUnicode(uint32_t uniCode, uint8_t matrix[32]) {

   uint8_t dataLength = 0;
   if(uniCode <= 45632 ) {
      dataLength = 16;
   }
   else {
      dataLength = 32;
   }
   uint32_t addr=getAddrFromUnicode(uniCode);

   waitUS(10);

   const uint8_t readDataBytes[] = {GT20L16_READ_COMMAND, (uint8_t)(addr>>16), (uint8_t)(addr>>8), (uint8_t)(addr)};

   csEnable();
   spi->txRxBytes(sizeof(readDataBytes), readDataBytes);
   spi->txRxBytes(dataLength, 0, matrix);
   csDisable();

   return dataLength;
}

/**
 * Read value from ROM
 *
 * @param addr ROM address
 *
 * @return Value read
 */
unsigned long GT20L16::read(uint32_t addr)
{
   const uint8_t readDataBytes[] = {GT20L16_READ_COMMAND, (uint8_t)(addr>>16), (uint8_t)(addr>>8), (uint8_t)(addr)};
   unsigned char buffer[2];

   waitUS(10);

   csEnable();
   spi->txRxBytes(sizeof(readDataBytes), readDataBytes);
   spi->txRxBytes(sizeof(buffer), 0, buffer);
   csDisable();

   return buffer[0]*256+buffer[1];
}

/**
 *  Maps UNICODE character to lookup table address
 *
 *  @param uniCode character
 *
 *  @return Base address to index ROM
 */
unsigned long GT20L16::getAddrFromUnicode(uint32_t uniCode) {

   if (uniCode <= 45632) {
      // char
      unsigned int BaseAdd=0;
      unsigned long address;
      if (uniCode>=0x20 && uniCode<=0x7f)             // latin 1
         address = 16*(uniCode-0x20)+BaseAdd;
      else if (uniCode>=0xa0 && uniCode<=0xff)        // latin 2
         address = 16*(96+uniCode-0xa0)+BaseAdd;
      else if (uniCode>=0x100 && uniCode<=0x17f)      // latin 3
         address = 16*(192+uniCode-0x100)+BaseAdd;
      else if (uniCode>=0x1a0 && uniCode<=0x1cf)      // latin 4
         address = 16*(320+uniCode-0x1a0)+BaseAdd;
      else if (uniCode>=0x1f0 && uniCode<=0x1ff)      // latin 5
         address = 16*(368+uniCode-0x1f0)+BaseAdd;
      else if (uniCode>=0x210 && uniCode<=0x21f)      // latin 6
         address = 16*(384+uniCode-0x210)+BaseAdd;
      else if (uniCode>=0x1ea0 && uniCode<=0x1eff)    // latin 7
         address = 16*(400+uniCode-0x1ea0)+BaseAdd;
      else if (uniCode>=0x370 && uniCode<=0x3cf)      // greek
         address = 16*(496+uniCode-0x370)+BaseAdd;
      else if (uniCode>=0x400 && uniCode<=0x45f)      // cyrillic 1
         address = 16*(592+uniCode-0x400)+BaseAdd;
      else if (uniCode>=0x490 && uniCode<=0x4ff)      // cyrillic 2
         address = 16*(688+uniCode-0x490)+BaseAdd;
      else if (uniCode>=0x590 && uniCode<=0x5ff)      // hebrew
         address = 16*(800+uniCode-0x100)+BaseAdd;
      else if (uniCode>=0xe00 && uniCode<=0xe7f)      // thai
         address = 16*(912+uniCode-0xe00)+BaseAdd;
      else
         address = BaseAdd;
      return address;
   }
   else {
      unsigned long  ZFAdd,HZAdd;
      unsigned char  MSB,LSB;
      unsigned long ChineseTab;
      unsigned int data;
      unsigned long  chineseAddress = 0;
      MSB = uniCode>>8;
      LSB = uniCode;
      ZFAdd=36224;
      HZAdd=93452;
      ChineseTab=87436;

      if(MSB>=0xA1 && MSB<=0xA5) {
         // Char area
         if(MSB==0xA1 && LSB>=0xA1 && LSB<=0xBF)
            chineseAddress=32*(LSB-0xA1)+ZFAdd;
         else if(MSB==0xA3 && LSB>=0xA1 && LSB<=0xFE)
            chineseAddress=32*(31+LSB-0xA1)+ZFAdd;
         else if(MSB==0xA4 && LSB>=0xA1 && LSB<=0xF3)
            chineseAddress=32*(125+LSB-0xA1)+ZFAdd;
         else if(MSB==0xA5 && LSB>=0xA1 && LSB<=0xF6)
            chineseAddress=32*(208+LSB-0xA1)+ZFAdd;
         else
            chineseAddress=ZFAdd;
      }
      else if((MSB>=0xB0 && MSB<=0xD7) && (LSB>=0xA1 && LSB<=0xFE)) {
         // Chinese 5720
         chineseAddress=(MSB-176)*94+(LSB-161)+1;
         chineseAddress=chineseAddress*32 +HZAdd;

      }
      else if((MSB>=0xD8 && MSB<=0xF7) && (LSB>=0xA1 && LSB<=0xFE)) {
         // Chinese 5720~6763
         chineseAddress=(MSB-0xD8)*94+(LSB-0xA1);
         chineseAddress=chineseAddress*2+ChineseTab;
         data=read(chineseAddress);
         chineseAddress=32*data+HZAdd;
      }
      return chineseAddress;
   }
}

} // End namespace USBDM
