/*
 * Can.cpp
 *
 *  Created on: 6Dec.,2018
 *      Author: podonoghue
 */
#include "hardware.h"
#include "can.h"

using namespace USBDM;

using Led = GpioD<0, ActiveLow>;

// CAN interface to use
using Can     = Can0;
using CanLimp = GpioE<13, ActiveLow>;

void canWakeupCallback() {
   console.writeln("canWakeupCallback()");
}

void testCanPins() {
   using CanTx = GpioE<5, ActiveLow>;
   CanTx::setOutput(PinDriveStrength_Low, PinDriveMode_OpenDrain);
   for(;;) {
      CanTx::toggle();
   }
}

void testSizes() {
   console.writeln("CanControlStatus     sz = ", sizeof(CanControlStatus));
   console.writeln("CanId                sz = ", sizeof(CanId));
   console.writeln("CanMessageBuffer8    sz = ", sizeof(CanMessageBuffer8));
   console.writeln("CanFifoIdFilter      sz = ", sizeof(CanFifoIdFilter));
   console.writeln("CanFifoIdFilterMask  sz = ", sizeof(CanFifoIdFilterMask));
   console.writeln("CanMailboxFilterMask sz = ", sizeof(CanMailboxFilterMask));
}

void printSizeTable(const char *title, unsigned maxMessageBuffers) {
   console.setWidth(3).setPadding(Padding_LeadingSpaces);
   console.writeln("\n\n  Table of FIFO filters and raw mailbox numbers for ", title);
   console.write(" FF  FM MB->");
   for (unsigned mailboxes=0; mailboxes<=maxMessageBuffers; mailboxes++) {
      console.write(mailboxes);
   }
   console.writeln();
   unsigned maxFifoFilters = CanParameters::calculateMaximumFifoFilterEntries(maxMessageBuffers);
   for (unsigned fifoIdFilters=0; fifoIdFilters<=maxFifoFilters; fifoIdFilters += 8) {
      console.write(fifoIdFilters).write(" ");
      console.write(CanParameters::calculateAvailableFifoIdFilterMasks(fifoIdFilters), "     ");
      for (unsigned mailboxes=0; mailboxes<=maxMessageBuffers; mailboxes++) {
         unsigned mbs = CanParameters::calculateMessageBuffersRequired(fifoIdFilters, mailboxes);
         if (mbs<=maxMessageBuffers) {
            console.write(mbs);
         }
      }
      console.writeln();
   }
   console.writeln("FF = FIFO Filters, FM = FIFO filter individual Masks, MB = MailBoxes");
   console.reset();
}

int main() {
   printSizeTable("Can 0", Can0Info::MaxNumberOfMessageBuffers);
   printSizeTable("Can 1", Can1Info::MaxNumberOfMessageBuffers);
   printSizeTable("Can 2", Can2Info::MaxNumberOfMessageBuffers);

   CanLimp::setInput();
   console.writeln("\n\nStarting");
   console.write("Can Limp = ", CanLimp::read());

   for(;;) {
   }
   return 0;
}
