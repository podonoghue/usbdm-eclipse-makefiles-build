/*! \file
    \brief Implements USBDM Flash Programmer dialogue

    Utils.cpp

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
   |  2 May 2012 | Added hex functions                                     - pgo
   | 10 Jan 2011 | Created                                                 - pgo
   +============================================================================
   \endverbatim
*/

#include <string>

#include "Utils.h"

using namespace std;

/*! Convert a single HEX character ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 15
 */
uint8_t hex1ToDecimal(char **ptr) {
   uint8_t data = *(*ptr)++;
   if ((data >= '0') && (data <= '9'))
      return data - '0';
   if ((data >= 'a') && (data <= 'f'))
      return data - 'a' + 10;
   if ((data >= 'A') && (data <= 'F'))
      return data - 'A' + 10;
   return 0;
}

/*! Convert two HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 255
 */
uint8_t hex2ToDecimal( char **ptr) {
   uint8_t data;
   data =             hex1ToDecimal(ptr);
   data = data * 16 + hex1ToDecimal(ptr);
   return data;
}

/*! Convert four HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 65535
 */
uint16_t hex4ToDecimal( char **ptr) {
   int data  =             hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   return data;
}

/*! Convert six HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 0xFFFFFFU
 */
uint32_t hex6ToDecimal( char **ptr) {
   int data  =             hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   return data;
}

/*! Convert six HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 0xFFFFFFU
 */
uint32_t hex8ToDecimal( char **ptr) {
   int data  =             hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   return data;
}

//! Filters a string to only contain a set of permitted values
//!
//! @param data    string to filter
//! @param pattern string containing permitted chars
//!
//! @return filtered string
//!
string filter(const string &data, const string &pattern) {
   string s;

   for (unsigned index=0; index<data.length(); index++) {
      if (pattern.find_first_of(data[index]) != string::npos) {
         s += data[index];
      }
   }
   return s;
}

