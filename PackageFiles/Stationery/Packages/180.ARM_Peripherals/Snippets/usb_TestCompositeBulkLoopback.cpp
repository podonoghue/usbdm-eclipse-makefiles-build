/**
 =============================================================================================
 * @file    usb_TestCompositeBulkLoopback.cpp (180.ARM_Peripherals/Snippets/)
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

enum UsbState {
   NoConnection,
   StartReceive,
   Receive,
   StartTransmit,
   Transmit,
   Busy,
};

int main() {
   console.writeln("\nStarting");
   console.writeln("SystemCoreClock = ", SystemCoreClock, " Hz");

   Usb0::initialise();

   uint8_t  buffer[1000];
   ErrorCode rc;

   // Static so callBack can access as static function
   static UsbState state = NoConnection;

   /**
    * This function is called whenever the 'user' code needs to be notified of an event
    *
    *  @param  event Reason for callback
    *
    *  @return Error code
    */
   static auto callBack = [](const Usb0::UserEvent event) {
      console.writeln("USB callback, reason = ", Usb0::getUserEventName(event));
      state = NoConnection;
      return E_NO_ERROR;
   };

   Usb0::setUserCallback(callBack);

   for(;;) {
#if 1
      if ((state != NoConnection)&&(!Usb0::isConfigured())) {
         state = NoConnection;
         console.writeln("Not configured\n");
      }

      if ((state == NoConnection)&&(Usb0::isConfigured())) {
         state = Busy;
         console.writeln("Configured\n");
      }

      if (state == Busy) {
         console.writeln("Receiving");
         uint16_t size = sizeof(buffer);
         rc = Usb0::receiveBulkData(size, buffer, 0);
         if (rc != E_NO_ERROR) {
            console.writeln("Reception failed, rc = ", getErrorMessage(rc));
            continue;
         }
         console.writeln("Sending, size = ", size);
         rc = Usb0::sendBulkData(size, buffer, 100);
         if (rc != E_NO_ERROR) {
            console.writeln("Transmission failed, rc = ", getErrorMessage(rc));
         }
      }
#else
      switch(state) {
         case NoConnection:
            if (Usb0::isConfigured()) {
               console.writeln("Configured\n");
               state = StartReceive;
            }
            break;
         case StartReceive:
            rc = Usb0::startReceiveBulkData(sizeof(buffer), buffer);
            if (rc != E_NO_ERROR) {
               console.writeln("Start reception failed, rc = ", getErrorMessage(rc));
               break;
            }
            console.writeln("Start reception OK");
            state = Receive;
            break;
         case Receive:
            uint16_t size;
            rc = Usb0::pollReceiveBulkData(size);
            if (rc == E_BUSY) {
               // No data yet
               break;
            }
            if (rc == E_NO_ERROR) {
               console.writeln("Received ", size, " bytes");
               state = StartTransmit;
               break;
            }
            console.writeln("Reception polling failed, rc = ", getErrorMessage(rc));
            state = StartReceive;
            break;
         case StartTransmit:
            rc = Usb0::startSendBulkData(size, buffer);
            if (rc != E_NO_ERROR) {
               console.writeln("Start transmission failed, rc = ", getErrorMessage(rc));
               break;
            }
            console.writeln("Start transmission OK");
            state = Transmit;
            break;
         case Transmit:
            rc = Usb0::pollSendBulkData();
            if (rc == E_BUSY) {
               // No data yet
               break;
            }
            if (rc == E_NO_ERROR) {
               console.writeln("Transmit complete ");
               state = StartReceive;
               break;
            }
            console.writeln("Transmission polling failed, rc = ", getErrorMessage(rc));
            state = StartTransmit;
            break;
         default:
            break;
      }
#endif
   }

   return 0;
}
