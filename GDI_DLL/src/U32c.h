/*! \file
    \brief Provides conversions to/from GDI data structures

    Conversion.h

    \verbatim
    USBDM
    Copyright (C) 2009  Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
    \endverbatim

    \verbatim
   Change History
   -============================================================================
   |             |                                                         - pgo
   +============================================================================
   \endverbatim
*/
#include <stdio.h>
#ifndef CONVERSION_H_
#define CONVERSION_H_

#include "Common.h"
#include "GDI.h"

//! Class to provide conversions between DI_GDI types and integers
//!
class U32c {

private:
   uint32_t value;
   uint32_t attribute;

public:
   //! Pack a DiRegisterValueT
   //! @param drvValue - The value to pack
   //!
   void pack(DiRegisterValueT const drvValue) {
      value = 0;
      for (int sub = 4; sub <= 7; sub++)
         value = (value<<8) + drvValue.dvValue.val[sub];
      attribute = drvValue.dvsStatus;
   }
   //! Pack a DiAddrT
   //! @param drvValue - The value to pack
   //!
   void pack(DiAddrT const drvValue) {
      value = 0;
      for (int sub = 4; sub <= 7; sub++)
         value = (value<<8) + drvValue.dlaLinAddress.v.val[sub];
      attribute = drvValue.dmsMemSpace;
   }
   //! Pack a DiLAddrT
   //! @param drvValue - The value to pack
   //!
   void pack(DiLAddrT const drvValue) {
      value = 0;
      for (int sub = 4; sub <= 7; sub++)
         value = (value<<8) + drvValue.v.val[sub];
      attribute = 0;
   }
   //! Pack a DiMemValueT
   //! @param drvValue - The value to pack
   //!
   void pack(DiMemValueT const drvValue) {
      value = 0;
      for (int sub = 4; sub <= 7; sub++)
         value = (value<<8) + drvValue.dmValue.val[sub];
      attribute = drvValue.dvsStatus;
   }
   //! Unpack to a DiRegisterValueT
   //!
   DiRegisterValueT unpackDiRegisterValueT() const {
      DiRegisterValueT   drvValue;
      drvValue.dvValue.val[0] = 0;
      drvValue.dvValue.val[1] = 0;
      drvValue.dvValue.val[2] = 0;
      drvValue.dvValue.val[3] = 0;
      drvValue.dvValue.val[4] = (DiUCharT)(value>>24);
      drvValue.dvValue.val[5] = (DiUCharT)(value>>16);
      drvValue.dvValue.val[6] = (DiUCharT)(value>>8);
      drvValue.dvValue.val[7] = (DiUCharT)value;
      drvValue.dvsStatus = attribute;
      return drvValue;
   }
   //! Unpack to a DiAddrT
   //!
   DiAddrT unpackDiAddrT() const {
      DiAddrT   drvValue;
      drvValue.dlaLinAddress.v.val[0] = 0;
      drvValue.dlaLinAddress.v.val[1] = 0;
      drvValue.dlaLinAddress.v.val[2] = 0;
      drvValue.dlaLinAddress.v.val[3] = 0;
      drvValue.dlaLinAddress.v.val[4] = (DiUCharT)(value>>24);
      drvValue.dlaLinAddress.v.val[5] = (DiUCharT)(value>>16);
      drvValue.dlaLinAddress.v.val[6] = (DiUCharT)(value>>8);
      drvValue.dlaLinAddress.v.val[7] = (DiUCharT)value;
      drvValue.dmsMemSpace = attribute;
      return drvValue;
   }
   //! Unpack to a DiMemValueT
   //!
   DiMemValueT unpackDiMemValueT() const {
      DiMemValueT   drvValue;
      drvValue.dmValue.val[0] = 0;
      drvValue.dmValue.val[1] = 0;
      drvValue.dmValue.val[2] = 0;
      drvValue.dmValue.val[3] = 0;
      drvValue.dmValue.val[4] = (DiUCharT)(value>>24);
      drvValue.dmValue.val[5] = (DiUCharT)(value>>16);
      drvValue.dmValue.val[6] = (DiUCharT)(value>>8);
      drvValue.dmValue.val[7] = (DiUCharT)value;

      drvValue.dvsStatus = attribute;
      return drvValue;
   }
   //! Implicit conversion to a DiRegisterValueT
   //!
   operator DiRegisterValueT() const { return unpackDiRegisterValueT(); }

   //! Implicit conversion to a DiAddrT
   //!
   operator DiAddrT() const { return unpackDiAddrT(); }

   //! Implicit conversion to a DiMemValueT
   //!
   operator DiMemValueT() const { return unpackDiMemValueT(); }

   //! Implicit conversion to a ptr to contained uint32_t object
   //!
   operator uint32_t const *() { return &value; };

   //! Implicit conversion to a reference to contained uint32_t object
   //!
   operator uint32_t const &() { return value;  };

   //! Default constructor
   //!
   U32c()          : value(0), attribute(DI_VS_DEFINED) {}

   //! Constructor from uint32_t
   //!
   U32c(uint32_t value, uint32_t attribute=0) : value(value), attribute(attribute) {
//      fprintf(stderr, "size of uint32_t = %d\n", sizeof(uint32_t)); fflush(stderr);
   }

   //! Constructor from DiRegisterValueT
   //!
   U32c(DiRegisterValueT const value)  { pack(value); }

   //! Constructor from DiLAddrT
   //!
   U32c(DiLAddrT const value)           { pack(value); }

   //! Constructor from DiAddrT
   //!
   U32c(DiAddrT const value)           { pack(value); }

   //! Constructor from DiMemValueT
   //!
   U32c(DiMemValueT const value)       { pack(value); }

   //! Constructor from DiMemValueT
   //!
   U32c(const uint8_t v1,const uint8_t v2,const uint8_t v3,const uint8_t v4 ) {
      attribute = 0;
      value     = (v1<<24)+(v2<<16)+(v3<<8)+v4;
   }

   //! Increment operator
   //!
   U32c &operator+=(uint32_t increment) { value += increment; return *this; }

   //! Bit mask operator
   //!
   U32c &operator&=(uint32_t mask)      { value &= mask;      return *this; }
   //! Extract a byte from a 32 bit value
   //! @param sub byte 0 to 3 to extract
   //!
   uint8_t operator[](int sub) {
      return value>>(8*(3-sub));
   }
};

#endif /* CONVERSION_H_ */
