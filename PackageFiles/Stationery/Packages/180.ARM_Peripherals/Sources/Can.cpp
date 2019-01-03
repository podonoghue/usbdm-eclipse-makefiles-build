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

void canCallback() {

}

constexpr unsigned min(unsigned a, unsigned b) {
   return (a<b)?a:b;
}

static constexpr unsigned CAN_TEST_ID = 0x16;

/**
 * Number of FIFO filters used
 * Must be a multiple of 8.
 * Use of more filters reduces mailbox message buffers available
 */
static constexpr unsigned FILTER_COUNT = 2*8;

/**
 * Receive FIFO filters
 * This table controls which messages are accepted into the receive FIFO.
 * All entries in this table must be provided.
 * The type of constructor must agree with the CanAcceptanceMode
 */
static const CanFifoFilter fifoFilters[FILTER_COUNT] = {
      // mode             rxid            ide     rtr
      { CanMode_Extended,   CAN_TEST_ID,  true,   true },
      { CanMode_Standard,   2,            true,   true },
      { CanMode_Standard,   3,            true,   true },
      { CanMode_Standard,   4,            true,   true },
      { CanMode_Standard,   5,           false,   true },
      { CanMode_Standard,   6,           false,   true },
      { CanMode_Standard,   7,           false,   true },
      { CanMode_Standard,   8,           false,   true },
      { CanMode_Standard,   9,           false,  false },
      { CanMode_Standard,  10,           false,  false },
      { CanMode_Standard,  11,           false,  false },
      { CanMode_Standard,  12,           false,  false },
      { CanMode_Standard,  13,            true,  false },
      { CanMode_Standard,  14,            true,  false },
      { CanMode_Standard,  15,            true,  false },
      { CanMode_Standard,  16,            true,  false },
};

/**
 * Receive FIFO filter masks.
 * These masks are applied to the first few fifoFilters entries.
 * The remaining filters use a shared mask.
 * The number of masks available depend on the number of filters: min(8 + 2*((FILTER_COUNT/8)-1),31)
 */
static const CanFifoFilterMask fifoFilterMasks[min(8 + 2*((FILTER_COUNT/8)-1),32)] = {
      // canMode   rxidMask ideMask rtrMask
      { CanMode_Extended,   0U,  false,  false },
      // Any unused entries will default to 0xFFFFFFFF i.e. no filtering
};

/**
 * Mailbox filter masks.
 * These masks are applied to the mailboxes
 */
static const CanMailboxFilterMask mailboxfilterMasks[32-min(8 + 2*((FILTER_COUNT/8)-1),32)] = {
      //   CanMode        idMask   ideMask rtrMask
      {CanMode_Extended,     ~0U,    true,   true },
      // Any unused entries will default to 0xFFFFFFFF i.e. no filtering
};

using Can = Can0;
using CanLimp = GpioE<13, ActiveLow>;

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

int main(){

   CanLimp::setInput();

   console.write("Can Limp = ").writeln(CanLimp::read());

   CanParameters canParameters(125000);
   canParameters.rxfgmask = CanFifoFilterMask(CanMode_Extended, ~0U, true, true).raw;
   canParameters.idam = CanAcceptanceMode_FormatA;

   Can::configureWithReceiveFifo(
         canParameters,
         CanAcceptanceMode_FormatA,
         FILTER_COUNT,
         fifoFilters,
         fifoFilterMasks,
         CanFifoFilterMask(CanMode_Extended, ~0U, true, true),
         mailboxfilterMasks
         );
   Can::configureAllPins();

   CanMessageBuffer8 fifoMb = *Can::getFifoMessageBuffer();
   console.write("FIFO CS=").write(fifoMb.CS.raw,Radix_16).
         write(", ID=").writeln(fifoMb.ID.raw,Radix_16);

   volatile CanMessageBuffer *txBuff = Can::getMessageBuffer(1);
   txBuff->CS.ide   = false;          // Standard frame format
   txBuff->CS.rtr   = false;          // Data frame
   txBuff->CS.dlc   = CanDataSize_7;  // Number of data bytes
   txBuff->ID.idStd = CAN_TEST_ID;    // ID (Standard format)
   txBuff->data8(0) = 1;
   txBuff->data8(1) = 2;
   txBuff->data8(2) = 3;
   txBuff->data8(3) = 4;
   txBuff->data8(4) = 5;
   txBuff->data8(5) = 6;
   txBuff->data8(6) = 7;
   txBuff->data8(7) = 8;
   txBuff->CS.code  = CanMessageCode_TxData;

   volatile CanMessageBuffer *rxBuff = Can::getMessageBuffer(0);
   rxBuff->CS.ide   = false;          // Standard frame format
   rxBuff->CS.rtr   = false;          // Data frame
   rxBuff->CS.dlc   = CanDataSize_7;  // Number of data bytes
   rxBuff->ID.idStd = CAN_TEST_ID;    // ID (Standard format)
   rxBuff->DATA32[0] = ~0U;
   rxBuff->DATA32[1] = ~0U;
   rxBuff->CS.code  = CanMessageCode_RxEmpty;

   for(;;) {
      console.write("CAN0->MCR =0b").writeln(CAN0->MCR, Radix_2);
      __asm__("nop");
   }
//   volatile CanFilterIdFormatA *filterTableA = Can::getFormatAFilterTable();
//   filterTableA[3].raw   = 0x10034;
//   filterTableA[3].rxid  = 3;
//   filterTableA[3].ide   = 1;
//   filterTableA[3].rtr   = 1;
//   filterTableA[2] = CanFilterIdFormatA(3,1,0);
//   filterTableA[2].raw =
//         CAN_FILTER_ID_A_RXID(6)|
//         CAN_FILTER_ID_A_IDE(1U)|
//         CAN_FILTER_ID_A_RTR(0);
//
//   volatile CanFilterIdFormatB *filterTableB = Can::getFormatBFilterTable();
//   filterTableB[3].rxid  = 6;
//   filterTableB[3].ide   = 1;
//   filterTableB[3].rtr   = 1;
//   filterTableB[2] = CanFilterIdFormatB(6,1,0);
//   filterTableB[2].raw =
//         CAN_FILTER_ID_B_RXID(6)|
//         CAN_FILTER_ID_B_IDE(1U)|
//         CAN_FILTER_ID_B_RTR(0);
//
//   volatile CanFilterIdFormatC *filterTableC = Can::getFormatCFilterTable();
//   filterTableC[3].rxid  = 7;
//   filterTableC[3].rxid  = CAN_FILTER_ID_C_RTR_B(7);
//
//   Can::enableMessageBufferInterrupts(0b11011100000);
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
