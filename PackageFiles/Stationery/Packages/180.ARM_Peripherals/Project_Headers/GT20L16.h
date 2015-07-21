/*
  GT20L16.h
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
#include "Seeed_SLD00200P.h"  // Pin mappings

class GT20L16 {

private:
   SPI *spi;
   const DigitalIO *cs_n;

private:
   uint32_t getAddrFromUnicode(uint32_t uniCode);
   uint32_t GTRead(uint32_t Address);

public:
   GT20L16(SPI *spi, const DigitalIO *cs = &GT20L16_Pin_CS);
   int getMatrixUnicode(uint32_t uniCode, uint8_t *matrix);
};

#endif
