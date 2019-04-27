/**
 ============================================================================
 * @file    can-fifo-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using FlexCAN Receive FIFO
 *
 *  Created on: 6Dec.,2018
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "can.h"

using namespace USBDM;

using Led = GpioD<0, ActiveLow>;

// CAN interface to use
using Can     = Can0;

//using CanLimp = GpioE<13, ActiveLow>; // S32K

/**
 * Base Message IDs for Rx FIFO
 */
static constexpr unsigned CAN_FIFO_ID1 = 40;
static constexpr unsigned CAN_FIFO_ID2 = 60;

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
   console
      .write("ID(")
      .write((CAN_MODE==CanMode_Standard)?messageBuffer->ID.idStd:messageBuffer->ID.idExt)
      .write(") - ");
   for (unsigned index=0; index<CanDataSizeToUnsigned(messageBuffer->CS.dlc); index++) {
      if (index != 0) {
         console.write(", ");
      }
      console.write(messageBuffer->data8(index), Radix_16);
   }
   console.writeln();
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
   console.write(  "canErrorCallback(), status = 0b").writeln(status, Radix_2).writeln();
   console.reset();
}

void canWakeupCallback() {
   console.writeln("canWakeupCallback()");
}

/**
 * Receive FIFO filters.
 * This table controls which messages are accepted into the receive FIFO.
 * All entries in this table must be provided.
 *
 * @note The type of CanFifoIdFilter constructor used must agree with the CanAcceptanceMode used.
 */
static const CanFifoIdFilter fifoIdFilters[Can::NUM_FIFO_MESSAGE_FILTERS] = {
      // canMode    rxid          canFrameType
      { CAN_MODE,   CAN_FIFO_ID1,  CanFrameType_Data  },
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
 * These masks are applied to the first few fifoIdFilters entries (0 to 31).
 * The remaining filters use a single shared mask.
 * The number of masks available depends on the number of filters: min(8 + 2*((FIFO_FILTER_ENTRY_COUNT/8)-1),31)
 */
static const CanFifoIdFilterMask fifoIdFilterMasks[Can::NUM_FIFO_MESSAGE_FILTER_MASKS] = {
      // Any unused entries will default to 0xFFFFFFFF i.e. no masking
      // canMode    rxidMask    ideMask frameTypeMask
      {  CAN_MODE,   ~0b111U,    true,  false }, // ID range 0-7
      {  CAN_MODE,   ~0b111U,    true,  false }, // ID range 0-7
};

/**
 * Executed on each FIFO reception
 */
void fifoCallback() {
   uint32_t fifoFlags = Can::getFifoFlags();

   console.setWidth(3);
   console.setPadding(Padding_LeadingZeroes);
   console.writeln("\n                              OWF");
   console.write(  "fifoCallback(), fifoFlags = 0b").writeln(fifoFlags>>5,    Radix_2);
   console.reset();

   auto mailbox = Can::getFifoMessageBuffer();
   console.write("fifoCallback() - Rx ");
   printMessageBuffer(mailbox);

   // Advance FIFO
   Can::clearFifoFlags(0b00100000);
}

/**
 * This example sets up the CAN FIFO to receive messages
 */
void fifoExample() {

   Can::CanParameters canParameters(125000, CanClockSource_1);
   canParameters.idam      = CanAcceptanceMode_FormatA;
   canParameters.wrnen     = true;
   canParameters.errmsk    = true;

   Can::setErrorCallback(canErrorCallback);
   Can::setFifoCallback(fifoCallback);
   Can::setWakeupCallback(canWakeupCallback);

   Can::configure(
         canParameters,
         CanAcceptanceMode_FormatA,
         fifoIdFilters,
         fifoIdFilterMasks,
         CanFifoIdFilterMask(CAN_MODE, ~0U, true, true)
   );

   Can::configureAllPins();

   // Enable all interrupts from FIFO
   Can::enableFifoInterrupts(CAN_FIFO_DATA_FLAG|CAN_FIFO_OVERFLOW_FLAG|CAN_FIFO_WARNING_FLAG);

   Can::enableErrorNvicInterrupts(NvicPriority_Normal);
   Can::enableWakeupNvicInterrupts(NvicPriority_Normal);
   Can::enableMessageBufferNvicInterrupts(NvicPriority_Normal);

   Can::enableMiscellaneousNvicInterrupts(NvicPriority_Normal);

   Can::start();

   Can::readTimer();

   for(;;) {
      // Report errors
      CanErrorCounts canErrorCounts = Can::getErrorCounters();
      if ((canErrorCounts.receiveErrorCount > 0) || (canErrorCounts.transmitFastErrorCount > 0)) {
         console.write("receiveErrorCount  = ").write(canErrorCounts.receiveErrorCount);
         console.write(", transmitErrorCount = ").writeln(canErrorCounts.transmitErrorCount);
      }
   }
}

int main() {
   console.writeln("\n\nStarting");

   console.write("NUM_MAILBOXES                 = ").writeln(Can::NUM_MAILBOXES);
   console.write("NUM_FIFO_MESSAGE_FILTERS      = ").writeln(Can::NUM_FIFO_MESSAGE_FILTERS);
   console.write("MAX_NUM_MESSAGE_BUFFERS       = ").writeln(Can::MAX_NUM_MESSAGE_BUFFERS);
   console.write("MAX_NUM_FIFO_MESSAGE_FILTERS  = ").writeln(Can::MAX_NUM_FIFO_MESSAGE_FILTERS);

   // S32K
   //   CanLimp::setInput();
   //   console.write("CAN Limp mode is ").writeln(CanLimp::read()?"Active":"Inactive");

   fifoExample();

   return 0;
}
