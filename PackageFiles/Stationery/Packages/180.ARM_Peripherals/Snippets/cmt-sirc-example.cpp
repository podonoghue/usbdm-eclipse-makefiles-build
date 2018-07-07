/**
 ============================================================================
 * @file    cmt-sirc-example.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo using Cmt class to send Sony SIRC protocol
 *
 * It will be necessary to configure the CMT interrupt handling in
 * the USBDM configuration.
 *
 *  Created on: 1/6/2018
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "cmt.h"

/*
 * Sony SIRC
 *
 * 40kHz carrier, 600us basic unit, bits transmitter LSB first
 *
 * Pulse width encoding of bits:
 *
 *    <---------------- 1200 us ---------------><----- 600 us ------>
 *    +----------------------------------------+                     +--
 *    |xxxxxxxxxxxxxxxxx 40kHz xxxxxxxxxxxxxxxx|                     |   Logic 1
 *  --+----------------------------------------+---------------------+
 *
 *    <----- 600 us ------><----- 600 us ------>
 *    +-------------------+                     +--
 *    |xxxxxx 40kHz xxxxxx|                     |   Logic 0
 *  --+-------------------+---------------------+
 *
 * Packet format: 12/15 or 20 bits.  Packet may be repeated @45ms interval.
 *
 *    <--- 2400 us ---> <- 600 us -> <--- 7 bits ----> <--- 5/8 bits --> <-- 0/8 bits -->
 *    +----------------+            +-----------------+-----------------+---------------+
 *    |xxxx 40kHz xxxxx|            |xxxx Command xxxx|xxxx Address xxxx|xx Extended  xx|
 *  --+----------------+------------+-----------------+-----------------+---------------+--
 *    <---- Training (start) ------> <------------------ Packet ----------------------->
 */
using namespace USBDM;

// LED connection - change as required
using Led   = GpioA<2,ActiveLow>;

constexpr unsigned SonyCarrier    = 40000;  //!< Sony SIRC carrier frequency (Hz)
constexpr unsigned SonyOneTime    =  1200;  //!< Sony SIRC on time (us) for '1'
constexpr unsigned SonyZeroTime   =   600;  //!< Sony SIRC on time (us) for '0'
constexpr unsigned SonyStartTime  =  2400;  //!< Sony SIRC on time (us) for start
constexpr unsigned SonyOffTime    =   600;  //!< Sony SIRC off time (us)
constexpr unsigned SonyRepeatTime = 45000;  //!< Sony SIRC repeat packet time (us)
constexpr unsigned SonyRepeats    =     3;  //!< How many times to repeat packet in transmission

/** Carrier half period in CMT clock cycles (Based on 8MHz CMT clock) */
constexpr uint8_t  PrimaryCarrierHalfTime = ((8000000UL/SonyCarrier)/2);

/** command/address/extended value to transmit */
static volatile uint32_t data;
/** Length of command/address/extended packet */
static volatile unsigned packetLength;
/** Count of bits transmitted in packet */
static volatile unsigned bitNum;
/** Count of packet repeats */
static volatile unsigned repeatCount;

/**
 * Callback from CMT.
 *
 * This processes each bit for transmission.
 */
static void cmtCallback() {
   /** command/address/extended value as being transmitted */
   static uint32_t shiftReg;

   /** Time since start of current packet */
   static unsigned repeatTime;

//   Led::toggle();
   if (Cmt::getStatus()) {
      if(bitNum==0) {
         if (repeatCount++ >= SonyRepeats) {
            // Completed entire sequence of repeats

            // Clear Interrupt flag
            Cmt::getMarkTime();

            // Disable entire CMT
            Cmt::disable();
            return;
         }
         // Start of new packet transmission
         shiftReg   = data;
         repeatTime = 0;
         Cmt::setExtendedSpace(CmtExtendedSpace_Disable);
      }
      if (bitNum<packetLength) {
         // LSB first
         if (shiftReg&0b1) {
            Cmt::setMarkTiming(SonyOneTime);
            repeatTime += SonyOneTime+SonyOffTime;
         }
         else {
            Cmt::setMarkTiming(SonyZeroTime);
            repeatTime += SonyZeroTime+SonyOffTime;
         }
         bitNum++;
         shiftReg >>= 1;
      }
      else {
         Cmt::setExtendedSpace(CmtExtendedSpace_Enable);
         Cmt::setMarkTiming(SonyRepeatTime-SonyOffTime-repeatTime);
         bitNum = 0;
      }
   }
}

/**
 * Does basic setup of CMT for SIRC protocol
 */
static void configureCmtTime() {
   repeatCount  = 0;
   bitNum       = 0;

   Cmt::configure(CmtMode_Direct);
   Cmt::outputControl(CmtOutput_Enable);
   Cmt::setOutput(PinDriveMode_PushPull);

   Cmt::setCallback(cmtCallback);
   Cmt::enableInterruptDma(CmtInterruptDma_Irq);
   Cmt::enableNvicInterrupts();

   // Set carrier frequency
   Cmt::setPrimaryTiming(PrimaryCarrierHalfTime,PrimaryCarrierHalfTime);

   // Set up for START bit
   Cmt::setMarkSpaceTiming(SonyStartTime, SonyOffTime);

   Cmt::setMode(CmtMode_Time);
}

/**
 * Check if CMT is still busy transmitting sequence
 *
 * @return True if busy
 */
bool inline isBusy() {
   return (repeatCount <= SonyRepeats);
}

/**
 * Wait for CMT to complete transmitting sequence
 */
void inline waitUntilComplete() {
   while (isBusy()) {
   }
}

/**
 * Start transmission of 12-bit sequence.
 * START + N*(7-bit COMMAND, 5-bit ADDRESS)
 *
 * @param command 7-bit command
 * @param address 5-bit address
 */
void send12(uint8_t command7, uint8_t address5) {
   data         = (address5<<7)|command7;
   packetLength = 12;
   configureCmtTime();
}

/**
 * Start transmission of 15-bit sequence.
 * START + N*(7-bit COMMAND, 8-bit ADDRESS)
 *
 * @param command 7-bit command
 * @param address 8-bit address
 */
void send15(uint8_t command7, uint8_t address8) {
   data         = (address8<<7)|command7;
   packetLength = 15;
   configureCmtTime();
}

/**
 * Start transmission of 20-bit sequence.
 * START + N*(7-bit COMMAND, 5-bit ADDRESS, 8-bit EXTENDED)
 *
 * @param command  7-bit command
 * @param address  5-bit address
 * @param extended 8-bit extended value
 */
void send20(uint8_t command7, uint8_t address5, uint8_t extended8) {
   data         = (extended8<<12)|(address5<<7)|command7;
   packetLength = 20;
   configureCmtTime();
}

int main() {
   console.writeln("Starting\n");
   console.write("SystemCoreClock = ").writeln(::SystemCoreClock);
   console.write("SystemBusClock  = ").writeln(::SystemBusClock);

   Led::setOutput();

   for(int count = 0;;count++) {
      Led::on();
      // Send test pattern
      send20(0x03, 0x01, 0x80);
      waitUntilComplete();
      Led::off();
      waitMS(100);
   }
   return 0;
}
