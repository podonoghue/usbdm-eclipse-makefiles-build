/*
  gt20l16.h
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Modified by Loovee
  www.seeedstudio.com
  2013-7-2

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

#ifndef __GT20L16_DRIVE_H__
#define __GT20L16_DRIVE_H__

#include "gpio.h"
#include "spi.h"
#include "seeed_sld00200p.h"  // Pin mappings

namespace USBDM {

/**
 * @addtogroup EPaper_Group E-paper interface
 * @brief C++ Class allowing access to E-paper display
 * @{
 */

/**
 * Base class for representing an interface to a GT20L16 Character ROM
 */
class GT20L16 {

private:
   Spi *spi;   //!< SPI Interface to use

private:
   /**
    *  Maps UNICODE character to lookup table address
    *
    *  @param uniCode character
    *
    *  @return Base address to index ROM
    */
   uint32_t getAddrFromUnicode(uint32_t uniCode);
   /**
    * Read value from ROM
    *
    * @param addr ROM address
    *
    * @return Value read
    */
   uint32_t read(uint32_t addr);
   /**
    * Assert CS
    */
   virtual void csEnable()  = 0;
   /**
    * Unassert CS
    */
   virtual void csDisable() = 0;

protected:
   /**
    * Constructor
    *
    * @param spi - The SPI interface to use
    */
   GT20L16(Spi *spi);

public:
   /**
    *  @param uniCode   Unicode character
    *  @param matrix    Buffer for display data for character
    *
    *  @return Size of display data written to buffer (either 16 or 32 bytes)
    */
   int getMatrixUnicode(uint32_t uniCode, uint8_t matrix[32]);
};

/**
 * Templated class for representing an interface to a GT20L16
 *
 * @tparam cs_n  - The Gpio to use as CS* for ROM
 */
template <class cs_n>
class GT20L16_T : public GT20L16 {

public:
   /**
    * Constructor
    *
    * @param spi - The SPI interface to use
    */
   GT20L16_T(Spi *spi) : GT20L16(spi) {
      cs_n::setOutput();
      cs_n::set();
   }
   /**
    * Assert CS
    */
   virtual void csEnable() {
      cs_n::clear();
   }
   /**
    * Unassert CS
    */
   virtual void csDisable() {
      cs_n::set();
   }
};

/**
 * @}
 */

} // End namespace USBDM

#endif // __GT20L16_DRIVE_H__
