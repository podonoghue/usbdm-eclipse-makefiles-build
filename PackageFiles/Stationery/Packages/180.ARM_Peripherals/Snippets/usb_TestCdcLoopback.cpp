/**
 =============================================================================================
 * @file    usb_TestBulkLoopback.cpp (180.ARM_Peripherals/Snippets/usb_TestBulkLoopback.cpp)
 * @brief   Loop-back test for USB Bulk transfer endpoints
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
\verbatim
    Kinetis USB Code

    Copyright (C) 2008-24  Peter O'Donoghue

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

 =============================================================================================
 */
#include "hardware.h"
#include "usb.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

int main() {
   console.writeln("\nStarting");
   console.writeln("SystemCoreClock = ", SystemCoreClock, " Hz");

   Usb0::initialise();

   bool connected = false;

   /**
    * This function is called whenever the 'user' code needs to be notified of an event
    *
    *  @param  event Reason for callback
    *
    *  @return Error code
    */
   static auto callBack = [](const Usb0::UserEvent event) {
      console.writeln("USB callback, reason = ", Usb0::getUserEventName(event));
      return E_NO_ERROR;
   };

   Usb0::setUserCallback(callBack);

   for(;;) {

      if (Usb0::isConfigured()) {
         if (!connected) {
            CriticalSection cs;
            connected = true;
            console.writeln("Configured\n");
         }
      }
      else {
         if (connected) {
            CriticalSection cs;
            connected = false;
            console.writeln("Not configured\n");
         }
      }
      if (connected) {
         uint8_t buffer[100];
         unsigned count = Usb0::receiveCdcData(buffer, sizeof(buffer)-1);
         if (count>0) {
            buffer[count] = '\0';
            console.write((const char*)buffer);

            Usb0::sendCdcData(buffer, count);
//            Usb0::sendCdcData((const uint8_t*)"Received\n", 9);
            while (Usb0::sendNow() == E_BUSY) {
            }
//            console.writeln("Flushed");
         }
      }
   }
   return 0;
}
