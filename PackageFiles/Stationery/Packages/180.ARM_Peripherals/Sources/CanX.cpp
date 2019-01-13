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

void canCallback() {
   uint32_t status = Can::getErrorStatus();
   Can::clearErrorStatus(status);
   console.write("canCallback(), status  = 0b").writeln(status, Radix_2);
   console.write("canCallback(), status' = 0b").writeln(Can::getErrorStatus(), Radix_2);
}

/**
 * CAN Message ID
 */
static constexpr unsigned CAN_TEST_ID = 0x16;
/**
 * CAN Message format
 */
static constexpr CanMode  CAN_MODE = CanMode_Standard;

/**
 * Number of FIFO filter entries.
 * Must be a multiple of 8 and != 0 if FIFO is used.
 * Use of more filters reduces mailbox message buffers available
 *
 * @note The filter entries may take A, B or C formats so the number
 *       of filters may be 1x, 2x or 4x this value.
 */
static constexpr unsigned FIFO_FILTER_ENTRY_COUNT = 2*8;

/**
 * Number of FIFO filter masks.
 * This is the number of individual masks available to be applied to the FIFO filters.
 * The remaining FIFO filters are masked by a shared mask.
 */
static constexpr unsigned FIFO_MASK_COUNT = Can::calculateFifoIndividualMaskCount(FIFO_FILTER_ENTRY_COUNT);

/**
 * Number of mailboxes (and corresponding mailbox filters)
 * max = Can::calculateMaximumMailboxCount(FIFO_FILTER_ENTRY_COUNT);
 */
static constexpr unsigned MAILBOX_COUNT = 4;


/**
 * Receive FIFO filters.
 * This table controls which messages are accepted into the receive FIFO.
 * All entries in this table must be provided.
 *
 * @note The type of CanFifoFilter constructor used must agree with the CanAcceptanceMode used.
 */
static const CanFifoFilter fifoFilters[FIFO_FILTER_ENTRY_COUNT] = {
      // canMode    rxid          rtr
      { CAN_MODE,   CAN_TEST_ID,  false },
      { CAN_MODE,     2,          true  },
      { CAN_MODE,     3,          true  },
      { CAN_MODE,     4,          true  },
      { CAN_MODE,     5,          true  },
      { CAN_MODE,     6,          true  },
      { CAN_MODE,     7,          true  },
      { CAN_MODE,     8,          true  },
      { CAN_MODE,     9,          false },
      { CAN_MODE,    10,          false },
      { CAN_MODE,    11,          false },
      { CAN_MODE,    12,          false },
      { CAN_MODE,    13,          false },
      { CAN_MODE,    14,          false },
      { CAN_MODE,    15,          false },
      { CAN_MODE,    16,          false },
};

/**
 * Receive FIFO filter masks.
 * These masks are applied to the first few fifoFilters entries.
 * The remaining filters use a single shared mask.
 * The number of masks available depends on the number of filters: min(8 + 2*((FIFO_FILTER_ENTRY_COUNT/8)-1),31)
 */
static const CanFifoFilterMask fifoFilterMasks[FIFO_MASK_COUNT] = {
      // canMode   rxidMask ideMask rtrMask
      { CAN_MODE,   0U,     false,  false },
      { 0 },
      // Any unused entries will default to 0xFFFFFFFF i.e. no masking
};

/**
 * Mailbox filter masks.
 * These masks are applied to the mailboxes
 */
static const CanMailboxFilterMask mailboxfilterMasks[MAILBOX_COUNT] = {
      //   CanMode        idMask   ideMask rtrMask
      {CAN_MODE,     ~0U,    true,   true },
      {0},
      {0},
      // Any unused entries will default to 0xFFFFFFFF i.e. no masking
};

void testCanPins() {
   using CanTx = GpioE<5, ActiveLow>;
   CanTx::setOutput(PinDriveStrength_Low, PinDriveMode_OpenDrain);
   for(;;) {
      CanTx::toggle();
   }
}

void testSizes() {
   console.write("CanControlStatus     sz = ").writeln(sizeof(CanControlStatus));
   console.write("CanId                sz = ").writeln(sizeof(CanId));
   console.write("CanMessageBuffer8    sz = ").writeln(sizeof(CanMessageBuffer8));
   console.write("CanFifoFilter        sz = ").writeln(sizeof(CanFifoFilter));
   console.write("CanFilterMask        sz = ").writeln(sizeof(CanFifoFilterMask));
   console.write("CanMailboxFilterMask sz = ").writeln(sizeof(CanMailboxFilterMask));
}

void printSizeTable(const char *title, unsigned maxMessageBuffers) {
   console.setWidth(3).setPadding(Padding_LeadingSpaces);
   console.write("\n\n  Table of required number of message buffers for ").writeln(title);
   console.write(" FF  FM MB->");
   for (unsigned mailboxes=0; mailboxes<=maxMessageBuffers; mailboxes++) {
      console.write(mailboxes);
   }
   console.writeln();
   unsigned maxFifoFilters = CanParameters::calculateMaximumFifoFilters(maxMessageBuffers);
   for (unsigned fifoFilters=0; fifoFilters<=maxFifoFilters; fifoFilters += 8) {
      console.write(fifoFilters).write(" ");
      console.write(CanParameters::calculateFifoIndividualMaskCount(fifoFilters)).write("     ");
      for (unsigned mailboxes=0; mailboxes<=maxMessageBuffers; mailboxes++) {
         unsigned mbs = CanParameters::calulateRequiredMessageBuffers(fifoFilters, mailboxes);
         if (mbs<=maxMessageBuffers) {
            console.write(mbs);
         }
      }
      console.writeln();
   }
   console.writeln("FF = FIFO Filters, FM = FIFO filter individual Masks, MB = MailBoxes");
}

int main() {
//   printSizeTable("Can 0", Can0Info::NumberOfMessageBuffers);
//   printSizeTable("Can 1", Can1Info::NumberOfMessageBuffers);
//   printSizeTable("Can 2", Can2Info::NumberOfMessageBuffers);

   CanLimp::setInput();

   console.write("Can Limp = ").writeln(CanLimp::read());

   CanParameters canParameters(125000);
   canParameters.rxfgmask  = CanFifoFilterMask(CAN_MODE, ~0U, true, true).raw;
   canParameters.idam      = CanAcceptanceMode_FormatA;
   canParameters.wrnen     = true;
   canParameters.errmsk    = true;

   Can::setErrorCallback(canCallback);
   Can::setOred0_15_Callback(canCallback);
   Can::setOred16_31_Callback(canCallback);
   Can::setWakeupCallback(canCallback);

   Can::configure(
         canParameters,
         CanAcceptanceMode_FormatA,
         FIFO_FILTER_ENTRY_COUNT,
         fifoFilters,
         fifoFilterMasks,
         CanFifoFilterMask(CAN_MODE, ~0U, true, true),
         MAILBOX_COUNT,
         mailboxfilterMasks
         );
   Can::configureAllPins();

   CanMessageBuffer8 fifoMb = *Can::getFifoMessageBuffer();
   console.write("FIFO CS=").write(fifoMb.CS.raw,Radix_16).
         write(", ID=").writeln(fifoMb.ID.raw,Radix_16);

   // Enable interrupts from Mailboxes 2..0
   Can::enableMailboxInterrupts(0b111);

   // Enable all interrupts from FIFO
   Can::enableFifoInterrupts(-1U);

   Can::enableErrorNvicInterrupts(NvicPriority_Normal);
   Can::enableOredNvicInterrupts(NvicPriority_Normal);
   Can::enableOred_0_15_NvicInterrupts(NvicPriority_Normal);
   Can::enableOred_16_32_NvicInterrupts(NvicPriority_Normal);
   Can::enableWakeupNvicInterrupts(NvicPriority_Normal);

   volatile CanMessageBuffer8 *canMailbox;

   canMailbox = Can::getMailbox(0);
   canMailbox->ID = CanId(CAN_MODE, CAN_TEST_ID);
   canMailbox->data8(0) = 0x1;
   canMailbox->data8(1) = 0x2;
   canMailbox->data8(2) = 0x3;
   canMailbox->data8(3) = 0x4;
   canMailbox->data8(4) = 0x5;
   canMailbox->data8(5) = 0x6;
   canMailbox->data8(6) = 0x7;
   canMailbox->data8(7) = 0x8;
   canMailbox->CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_7, false);

   canMailbox = Can::getMailbox(1);
   canMailbox->ID = CanId(CAN_MODE, CAN_TEST_ID);
   canMailbox->data8(0) = 0x11;
   canMailbox->data8(1) = 0x12;
   canMailbox->data8(2) = 0x13;
   canMailbox->data8(3) = 0x14;
   canMailbox->data8(4) = 0x15;
   canMailbox->data8(5) = 0x16;
   canMailbox->data8(6) = 0x17;
   canMailbox->data8(7) = 0x18;
   canMailbox->CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_3, false);

   canMailbox = Can::getMailbox(2);
   canMailbox->ID = CanId(CAN_MODE, CAN_TEST_ID);
   canMailbox->DATA32[0] = ~0U;
   canMailbox->DATA32[1] = ~0U;
   canMailbox->CS = CanControlStatus(CanMessageCode_RxEmpty, false);

   Can::readTimer();

   for(;;) {
//      console.write("CAN0->MCR =0b").writeln(CAN0->MCR, Radix_2);
      __asm__("nop");
   }

   volatile CanFifoFilter *fifoFilterTable = Can::getFifoFilterTable();
   fifoFilterTable[2] = CanFifoFilter(CanMode_Standard, 3, false);

   volatile CanFifoFilterMask *fifoFilterMask = Can::getFifoFilterMaskTable();
   fifoFilterMask[2] = CanFifoFilterMask(CanMode_Extended, ~0U, 0, 0);

//   CanErrorCounts canErrorCounts = Can::getErrorCounters();
//   console
//      .write("receiveErrorCount  = ").write(canErrorCounts.receiveErrorCount)
//      .write(", transmitErrorCount = ").writeln(canErrorCounts.transmitErrorCount);
//
//   CanCrc15 canCrc15 = Can::getTransmittedCrc();
//
//   console.write("CanCrc15 = ").writeln(canCrc15.raw, Radix_16);

//   mb2Words.CS      = 0;
//   mb2Words.ID      = 0;
//   mb2Words.DATA[0] = 0;
//   mb2Words.DATA[1] = 0;
//   mb2Words.DATA[2] = 0;
//   mb2Words.DATA[3] = 0;

   Led::setOutput();
   Led::on();

//   Can1::setOredCallback(canCallback);
//   Can1::setErrorCallback(canCallback);
//   Can1::setOred0_15_Callback(canCallback);
//
//   Can1::enableOredNvicInterrupts(NvicPriority_Normal);
//   Can1::enableErrorNvicInterrupts(NvicPriority_Low);
//   Can1::enableOred_0_15_NvicInterrupts(NvicPriority_Normal);
//
//   Can::setOredCallback(canCallback);
//   Can::setErrorCallback(canCallback);
//   Can::setOred0_15_Callback(canCallback);
//   Can::setOred16_31_Callback(canCallback);
//   Can::setWakeupCallback(canCallback);
//
//   Can::enableOredNvicInterrupts(NvicPriority_Normal);
//   Can::enableWakeupNvicInterrupts(NvicPriority_Low);
//   Can::enableErrorNvicInterrupts(NvicPriority_Low);
//   Can::enableOred_0_15_NvicInterrupts(NvicPriority_Normal);
//   Can::enableOred_16_32_NvicInterrupts(NvicPriority_Normal);

   for(;;) {
      __asm__("nop");
   }
   return 0;
}
