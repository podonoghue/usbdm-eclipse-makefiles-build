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

void canMessageBufferCallback() {
   uint32_t mailboxFlags  = Can::getMailboxFlags();
   uint32_t fifoFlags     = Can::getFifoFlags();
   Can::clearFifoFlags(fifoFlags);
   Can::clearMailboxFlags(mailboxFlags);

   console.setWidth(32);
   console.setPadding(Padding_LeadingZeroes);
   console.writeln("                                                            OWF");
   console.write(  "canOredCallback(), fifoFlags    = 0b").writeln(fifoFlags,    Radix_2);
   console.writeln("                                    10987654321098765432109876543210");
   console.write(  "canOredCallback(), mailboxFlags = 0b").writeln(mailboxFlags, Radix_2);
   console.reset();
}

void canErrorCallback() {
   uint32_t status        = Can::getErrorStatus();
   Can::clearErrorStatus(status);
   console.setWidth(32);
   console.setPadding(Padding_LeadingZeroes);
   console.writeln("                               10987654321098765432109876543210");
   console.writeln("                                         O BSTR10ACFSTRITFFRBE");
   console.writeln("                                         V OYxxEECRRTxxDxLLxOR");
   console.writeln("                                         R FNWWRRKCMFEEL TT FR");
   console.write(  "canErrorCallback(), status = 0b").writeln(status, Radix_2);
   console.reset();
}

void canWakeupCallback() {
   console.writeln("canWakeupCallback()");
}

/**
 * CAN Message IDs for FIFO
 */
static constexpr unsigned CAN_FIFO_ID1 = 20;
static constexpr unsigned CAN_FIFO_ID2 = 60;
/**
 * CAN Message ID for Rx Mailboxes
 */
static constexpr unsigned CAN_TX_MAILBOX_1_ID = 30;
static constexpr unsigned CAN_TX_MAILBOX_2_ID = 31;
/**
 * CAN Message ID for Tx Mailboxes
 */
static constexpr unsigned CAN_RX_MAILBOX_1_ID = 40;
static constexpr unsigned CAN_RX_MAILBOX_2_ID = 41;
/**
 * CAN Message format
 */
static constexpr CanMode  CAN_MODE = CanMode_Standard;

/**
 * Number of FIFO filter entries.
 * Must be a multiple of 8 and >0 if FIFO is used.
 * Use of more filters reduces mailbox message buffers available
 *
 * @note The filter entries may take A, B or C formats so the number
 *       of filters may be 1x, 2x or 4x this value.
 */
static constexpr unsigned FIFO_FILTER_ENTRY_COUNT = 1*8;

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
 * @note The type of CanFifoIdFilter constructor used must agree with the CanAcceptanceMode used.
 */
static const CanFifoIdFilter fifoIdFilters[FIFO_FILTER_ENTRY_COUNT] = {
      // canMode    rxid          canFrameType
      { CAN_MODE,   CAN_FIFO_ID1,  CanFrameType_Data },
      { CAN_MODE,   CAN_FIFO_ID2,  CanFrameType_Data  },
      { CAN_MODE,     3,           CanFrameType_Data  },
      { CAN_MODE,     4,           CanFrameType_Data  },
      { CAN_MODE,     5,           CanFrameType_Data  },
      { CAN_MODE,     6,           CanFrameType_Data  },
      { CAN_MODE,     7,           CanFrameType_Data  },
      { CAN_MODE,     8,           CanFrameType_Data  },
};

/**
 * Receive FIFO filter masks.
 * These masks are applied to the first few fifoIdFilters entries.
 * The remaining filters use a single shared mask.
 * The number of masks available depends on the number of filters: min(8 + 2*((FIFO_FILTER_ENTRY_COUNT/8)-1),31)
 */
static const CanFifoIdFilterMask fifoIdFilterMasks[FIFO_MASK_COUNT] = {
      // Any unused entries will default to 0xFFFFFFFF i.e. no masking
      // canMode    rxidMask ideMask frameTypeMask
      {  CAN_MODE,   0xFFFEU,    false,  false },
      {  CAN_MODE,   0xFFFCU,    false,  false },
};

/**
 * Mailbox filter masks.
 * These masks are applied to the mailboxes
 */
static const CanMailboxFilterMask mailboxfilterMasks[MAILBOX_COUNT] = {
      // canMode     idMask   ideMask rtrMask
//      {  CAN_MODE,    ~0U,    true,   true },
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
   console.write("CanFifoIdFilter      sz = ").writeln(sizeof(CanFifoIdFilter));
   console.write("CanFifoIdFilterMask  sz = ").writeln(sizeof(CanFifoIdFilterMask));
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
   for (unsigned fifoIdFilters=0; fifoIdFilters<=maxFifoFilters; fifoIdFilters += 8) {
      console.write(fifoIdFilters).write(" ");
      console.write(CanParameters::calculateFifoIndividualMaskCount(fifoIdFilters)).write("     ");
      for (unsigned mailboxes=0; mailboxes<=maxMessageBuffers; mailboxes++) {
         unsigned mbs = CanParameters::calulateRequiredMessageBuffers(fifoIdFilters, mailboxes);
         if (mbs<=maxMessageBuffers) {
            console.write(mbs);
         }
      }
      console.writeln();
   }
   console.writeln("FF = FIFO Filters, FM = FIFO filter individual Masks, MB = MailBoxes");
}

void tx1MailboxCallback(unsigned mailboxNum) {
   console.write("Mailbox ").writeln(mailboxNum);
   Can::clearMailboxFlags(1<<mailboxNum);
}

void tx2MailboxCallback(unsigned mailboxNum) {
   console.write("Mailbox ").writeln(mailboxNum);
   Can::clearMailboxFlags(1<<mailboxNum);
}

void rx1MailboxCallback(unsigned mailboxNum) {
   console.write("Mailbox ").writeln(mailboxNum);
   Can::clearMailboxFlags(1<<mailboxNum);
}

void rx2MailboxCallback(unsigned mailboxNum) {
   console.write("Mailbox ").writeln(mailboxNum);
   Can::clearMailboxFlags(1<<mailboxNum);
}

int main() {
//   printSizeTable("Can 0", Can0Info::NumberOfMessageBuffers);
//   printSizeTable("Can 1", Can1Info::NumberOfMessageBuffers);
//   printSizeTable("Can 2", Can2Info::NumberOfMessageBuffers);

   CanLimp::setInput();
   console.writeln("\n\nStarting");
   console.write("Can Limp = ").writeln(CanLimp::read());

   CanParameters canParameters(125000);
   canParameters.idam      = CanAcceptanceMode_FormatA;
   canParameters.wrnen     = true;
   canParameters.errmsk    = true;
//   canParameters.lpb       = true;

   Can::CanMailBox rxMailbox1 = Can::allocateMailbox();
   Can::CanMailBox rxMailbox2 = Can::allocateMailbox();
   Can::CanMailBox txMailbox1 = Can::allocateMailbox();
   Can::CanMailBox txMailbox2 = Can::allocateMailbox();

   if (!rxMailbox1.isValid() || !rxMailbox2.isValid() ||
       !txMailbox1.isValid() || !txMailbox2.isValid()) {
      console.writeln("Mailbox allocation failed");
      __BKPT();
   }
   rxMailbox1.setCallback(rx1MailboxCallback);
   rxMailbox2.setCallback(rx2MailboxCallback);
   txMailbox1.setCallback(tx1MailboxCallback);
   txMailbox2.setCallback(tx2MailboxCallback);

   Can::setErrorCallback(canErrorCallback);
   Can::setMessageBufferCallback(canMessageBufferCallback);
   Can::setWakeupCallback(canWakeupCallback);

   Can1::setErrorCallback(canErrorCallback);
   Can1::setMessageBufferCallback(canMessageBufferCallback);
   Can1::setWakeupCallback(canWakeupCallback);

   Can2::setErrorCallback(canErrorCallback);
   Can2::setMessageBufferCallback(canMessageBufferCallback);
   Can2::setWakeupCallback(canWakeupCallback);

   Can::configure(
         canParameters,
         CanAcceptanceMode_FormatA,
         FIFO_FILTER_ENTRY_COUNT,
         fifoIdFilters,
         fifoIdFilterMasks,
         CanFifoIdFilterMask(CAN_MODE, ~0U, true, true),
         mailboxfilterMasks
         );
   Can::configureAllPins();

   CanMessageBuffer8 fifoMb = *Can::getFifoMessageBuffer();
   console.write("FIFO CS=").write(fifoMb.CS.raw,Radix_16).
         write(", ID=").writeln(fifoMb.ID.raw,Radix_16);

   // Enable interrupts from Mailboxes 2..0
   Can::enableMailboxInterrupts(0b111);

   // Enable all interrupts from FIFO
   Can::enableFifoInterrupts(CAN_FIFO_DATA_FLAG|CAN_FIFO_OVERFLOW_FLAG|CAN_FIFO_WARNING_FLAG);

   Can::enableErrorNvicInterrupts(NvicPriority_Normal);
   Can::enableWakeupNvicInterrupts(NvicPriority_Normal);
   Can::enableMessageBufferNvicInterrupts(NvicPriority_Normal);
   Can::enableOredNvicInterrupts(NvicPriority_Normal);

   Can1::enableErrorNvicInterrupts(NvicPriority_Normal);
//   Can1::enableWakeupNvicInterrupts(NvicPriority_Normal);
   Can1::enableMessageBufferNvicInterrupts(NvicPriority_Normal);
   Can1::enableOredNvicInterrupts(NvicPriority_Normal);

   Can2::enableErrorNvicInterrupts(NvicPriority_Normal);
//   Can2::enableWakeupNvicInterrupts(NvicPriority_Normal);
   Can2::enableMessageBufferNvicInterrupts(NvicPriority_Normal);
   Can2::enableOredNvicInterrupts(NvicPriority_Normal);

   console.write("Can::MailboxNone.isValid() => ").writeln(Can::MailboxNone.isValid());
   console.write("Can::txMailbox1.isValid() => ").writeln(txMailbox1.isValid());

   volatile CanMessageBuffer8 *canTxMailbox1;
   canTxMailbox1 = txMailbox1.getMailbox();
   canTxMailbox1->ID = CanId(CAN_MODE, CAN_TX_MAILBOX_1_ID);
   canTxMailbox1->data8(0) = 0x1;
   canTxMailbox1->data8(1) = 0x2;
   canTxMailbox1->data8(2) = 0x3;
   canTxMailbox1->data8(3) = 0x4;
   canTxMailbox1->data8(4) = 0x5;
   canTxMailbox1->data8(5) = 0x6;
   canTxMailbox1->data8(6) = 0x7;
   canTxMailbox1->data8(7) = 0x8;
//   canTxMailbox1->CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_7, CanFrameType_Data);

   volatile CanMessageBuffer8 *canTxMailbox2;
   canTxMailbox2 = txMailbox2.getMailbox();
   canTxMailbox2->ID = CanId(CAN_MODE, CAN_TX_MAILBOX_2_ID);
   canTxMailbox2->data8(0) = 0x11;
   canTxMailbox2->data8(1) = 0x12;
   canTxMailbox2->data8(2) = 0x13;
   canTxMailbox2->data8(3) = 0x14;
   canTxMailbox2->data8(4) = 0x15;
   canTxMailbox2->data8(5) = 0x16;
   canTxMailbox2->data8(6) = 0x17;
   canTxMailbox2->data8(7) = 0x18;
//   canTxMailbox2->CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_3, CanFrameType_Data);

   volatile CanMessageBuffer8 *canRxMailbox1;
   canRxMailbox1 = rxMailbox1.getMailbox();
   canRxMailbox1->ID = CanId(CAN_MODE, CAN_RX_MAILBOX_1_ID);
   canRxMailbox1->DATA32[0] = ~0U;
   canRxMailbox1->DATA32[1] = ~0U;
   canRxMailbox1->CS = CanControlStatus(CanMessageCode_RxEmpty, CanFrameType_Data);

   volatile CanMessageBuffer8 *canRxMailbox2;
   canRxMailbox2 = rxMailbox2.getMailbox();
   canRxMailbox2->ID = CanId(CAN_MODE, CAN_RX_MAILBOX_2_ID);
   canRxMailbox2->DATA32[0] = ~0U;
   canRxMailbox2->DATA32[1] = ~0U;
   canRxMailbox2->CS = CanControlStatus(CanMessageCode_RxEmpty, CanFrameType_Data);

   txMailbox1.dispose();
   console.write("Can::txMailbox1.isValid() => ").writeln(txMailbox1.isValid());

   Can::readTimer();

   for(;;) {
//      console.write("CAN0->MCR =0b").writeln(CAN0->MCR, Radix_2);
      __asm__("nop");
      waitMS(100);
      if (canTxMailbox1->CS.code == CanMessageCode_TxInactive) {
         canTxMailbox1->CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_7, CanFrameType_Data);
      }
      if (canTxMailbox2->CS.code == CanMessageCode_TxInactive) {
         canTxMailbox1->CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_3, CanFrameType_Data);
      }
   }

   volatile CanFifoIdFilter *fifoIdFilterTable = Can::getFifoFilterTable();
   fifoIdFilterTable[2] = CanFifoIdFilter(CanMode_Standard, 3, CanFrameType_Data);

   volatile CanFifoIdFilterMask *fifoIdFilterMask = Can::getFifoFilterMaskTable();
   fifoIdFilterMask[2] = CanFifoIdFilterMask(CanMode_Extended, ~0U, 0, 0);

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
