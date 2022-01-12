/**
 ============================================================================
 * @file    can-class-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using FlexCAN mailboxes
 *
 *  Created on: 6Dec.,2018
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "can.h"

using namespace USBDM;

// CAN interface to use
using Can     = Can0;
//using CanLimp = GpioE<13, ActiveLow>;

/**
 * Message ID for Tx Mailboxes
 */
static constexpr unsigned CAN_TX_MAILBOX_1_ID = 30;
static constexpr unsigned CAN_TX_MAILBOX_2_ID = 31;

/**
 * Message ID for Rx Mailboxes
 */
static constexpr unsigned CAN_RX_MAILBOX_1_ID = 40; // Start of range
static constexpr unsigned CAN_RX_MAILBOX_2_ID = 80; // Start of range

/**
 * CAN Message format
 */
static constexpr CanMode  CAN_MODE = CanMode_Standard;

/**
 * Print abbreviated contents of message buffer
 *
 * @param messageBuffer
 */
void printMessageBuffer(volatile CanMessageBuffer8 * messageBuffer) {
   console.write("ID(", (CAN_MODE==CanMode_Standard)?messageBuffer->ID.idStd:messageBuffer->ID.idExt, ") - ");
   for (unsigned index=0; index<CanDataSizeToUnsigned(messageBuffer->CS.dlc); index++) {
      if (index != 0) {
         console.write(", ");
      }
      console.write(messageBuffer->data8(index), Radix_16);
   }
   console.writeln();
}

void canMessageBufferCallback() {
   uint32_t mailboxFlags  = Can::getMailboxFlags();
   uint32_t fifoFlags     = Can::getFifoFlags();
   Can::clearFifoFlags(fifoFlags);
   Can::clearMailboxFlags(mailboxFlags);

   console.setWidth(32);
   console.setPadding(Padding_LeadingZeroes);
   console.writeln("                                                            OWF");
   console.writeln(  "canOredCallback(), fifoFlags    = 0b", fifoFlags,    Radix_2);
   console.writeln("                                    10987654321098765432109876543210");
   console.writeln(  "canOredCallback(), mailboxFlags = 0b", mailboxFlags, Radix_2);
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
   console.writeln("canErrorCallback(), status = 0b", status, Radix_2).writeln();
   console.reset();
}

void canWakeupCallback() {
   console.writeln("canWakeupCallback()");
}

class Tx1Mailbox : public Can::CanMailboxInfo {
public:
   void start() {
      volatile CanMessageBuffer8 *canTxMailbox1 = getMailbox();
      canTxMailbox1->ID = CanId(CAN_MODE, CAN_TX_MAILBOX_1_ID);
      canTxMailbox1->data8(0) = 0x1;
      canTxMailbox1->data8(1) = 0x2;
      canTxMailbox1->data8(2) = 0x3;
      canTxMailbox1->data8(3) = 0x4;
      canTxMailbox1->data8(4) = 0x5;
      canTxMailbox1->data8(5) = 0x6;
      canTxMailbox1->data8(6) = 0x7;
      canTxMailbox1->data8(7) = 0x8;
      canTxMailbox1->CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_7, CanFrameType_Data);
   }

private:
   void callback() override {
      console.writeln("Mailbox ", mailboxNumber);
      clearMailboxFlag();
   }
};

class Tx2Mailbox : public Can::CanMailboxInfo {
public:
   void start() {
      volatile CanMessageBuffer8 *canTxMailbox2 = getMailbox();
      canTxMailbox2->ID = CanId(CAN_MODE, CAN_TX_MAILBOX_2_ID);
      canTxMailbox2->data8(0) = 0x11;
      canTxMailbox2->data8(1) = 0x12;
      canTxMailbox2->data8(2) = 0x13;
      canTxMailbox2->data8(3) = 0x14;
      canTxMailbox2->data8(4) = 0x15;
      canTxMailbox2->data8(5) = 0x16;
      canTxMailbox2->data8(6) = 0x17;
      canTxMailbox2->data8(7) = 0x18;
      canTxMailbox2->CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_3, CanFrameType_Data);
   }

private:
   void callback() override {
      console.writeln("Mailbox ", mailboxNumber);
      clearMailboxFlag();
   }
};

class Rx1Mailbox : public Can::CanMailboxInfo {
public:
   void start() {
      volatile CanMessageBuffer8 *canRxMailbox1 = getMailbox();
      canRxMailbox1->ID = CanId(CAN_MODE, CAN_RX_MAILBOX_1_ID);
      canRxMailbox1->DATA32[0] = ~0U;
      canRxMailbox1->DATA32[1] = ~0U;
      canRxMailbox1->CS = CanControlStatus(CanMessageCode_RxEmpty, CanFrameType_Data);
   }

private:
   void callback() override {
      console.writeln("Mailbox ", mailboxNumber);
      clearMailboxFlag();
   }
};

class Rx2Mailbox : public Can::CanMailboxInfo {
public:
   void start() {
      volatile CanMessageBuffer8 *canRxMailbox2 = getMailbox();
      canRxMailbox2->ID = CanId(CAN_MODE, CAN_RX_MAILBOX_2_ID);
      canRxMailbox2->DATA32[0] = ~0U;
      canRxMailbox2->DATA32[1] = ~0U;
      canRxMailbox2->CS = CanControlStatus(CanMessageCode_RxEmpty, CanFrameType_Data);
   }

private:
   void callback() override {
      console.writeln("Mailbox ", mailboxNumber);
      clearMailboxFlag();
   }
};

int main() {
//   printSizeTable("Can 0", Can0Info::NumberOfMessageBuffers);
//   printSizeTable("Can 1", Can1Info::NumberOfMessageBuffers);
//   printSizeTable("Can 2", Can2Info::NumberOfMessageBuffers);

   CanLimp::setInput();
   console.writeln("\n\nStarting");
   console.writeln("Can Limp = ", CanLimp::read());

   Can::CanParameters canParameters(125000);
   canParameters.idam      = CanAcceptanceMode_FormatA;
   canParameters.wrnen     = true;
   canParameters.errmsk    = true;
//   canParameters.lpb       = true;

   Rx1Mailbox rxMailbox1;
   Rx2Mailbox rxMailbox2;
   Tx1Mailbox txMailbox1;
   Tx2Mailbox txMailbox2;

   if ((rxMailbox1.allocate() != E_NO_ERROR) ||
       (rxMailbox2.allocate() != E_NO_ERROR) ||
       (txMailbox1.allocate() != E_NO_ERROR) ||
       (txMailbox2.allocate() != E_NO_ERROR)) {
      console.writeln("Mailbox allocation failed");
      __BKPT();
   }

   Can::setErrorCallback(canErrorCallback);
   Can::setMessageBufferCallback(canMessageBufferCallback);
   Can::setWakeupCallback(canWakeupCallback);

   Can::configure(canParameters);

   Can::configureAllPins();

   CanMessageBuffer8 fifoMb = *Can::getFifoMessageBuffer();
   console.writeln("FIFO CS=", fifoMb.CS.raw, Radix_16, ", ID=", fifoMb.ID.raw,Radix_16);

   // Enable interrupts from Mailboxes in use
   rxMailbox1.enableInterrupt();
   rxMailbox2.enableInterrupt();
   txMailbox1.enableInterrupt();
   txMailbox2.enableInterrupt();

   // Enable all interrupts from FIFO
   Can::enableFifoInterrupts(CAN_FIFO_DATA_FLAG|CAN_FIFO_OVERFLOW_FLAG|CAN_FIFO_WARNING_FLAG);

   Can::enableErrorNvicInterrupts(NvicPriority_Normal);
   Can::enableWakeupNvicInterrupts(NvicPriority_Normal);
   Can::enableMessageBufferNvicInterrupts(NvicPriority_Normal);
   Can::enableMiscellaneousNvicInterrupts(NvicPriority_Normal);

   console.writeln("Can::MailboxNone.isValid() => ", Can::MailboxNone.isValid());
   console.writeln("Can::txMailbox1.isValid() => ", txMailbox1.isValid());

   txMailbox1.dispose();
   console.writeln("Can::txMailbox1.isValid() => ", txMailbox1.isValid());

   Can::readTimer();

   for(;;) {
//      console.writeln("CAN0->MCR =0b", CAN0->MCR, Radix_2);
      __asm__("nop");
      waitMS(100);
      if (txMailbox1.isTxFree()) {
         txMailbox1.start();
      }
      if (txMailbox2.isTxFree()) {
         txMailbox1.start();
      }
   }
   return 0;
}
