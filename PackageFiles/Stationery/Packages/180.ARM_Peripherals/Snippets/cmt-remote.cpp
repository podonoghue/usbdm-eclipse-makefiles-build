/**
 * @file    cmt-remote.cpp  (180.ARM_Peripherals/Snippets)
 * @brief   Example showing use of CMT to implement various IR protocols
 */
#include "cmt-remote.h"
#include "hardware.h"

using namespace USBDM;

// Debug LED connection - change as required
using DebugLed = Digital_D1;

/**
 * Callback from CMT.
 *
 * This processes each timing interval of the transmission.
 */
void IrRemote::cmtCallback() {

   /** Count of packet repeats so far */
   static unsigned repeatCount;

   /** Count of bits in packet transmitted so far */
   static unsigned bitNum;

   /** Value being transmitted */
   static uint32_t shiftReg;

   /** Time since start of current packet */
   static Ticks progress;

   if (Cmt::getEndOfCycleFlag()) {

      DebugLed::on();

      // This switch uses state from the last action
      switch(state) {
         case s_Initial:
            // Currently sending start bit of 1st packet
            repeatCount = 0;
            [[fallthrough]];

         case s_Start:
            // Currently sending start bit
            // Set up new data transmission
            bitNum   = 0;
            shiftReg = data1;
            progress = parameters.startHigh+parameters.startLow;

            if ((repeatCount>0) && (parameters.fastRepeats)) {
               // Skip data in repeated packets
               bitNum = parameters.packetLength;
               state = s_Stop;
            }
            else if (parameters.middleStopBit == 0) {
               // Skip 1st word & middle-stop
               state = s_SecondWord;
            }
            else {
               state = s_FirstWord;
            }
            break;

         case s_FirstWord:
            if (bitNum == parameters.middleStopBit) {
               state = s_MiddleStop;
            }
            break;

         case s_MiddleStop:
            state = s_SecondWord;
            shiftReg = data2;
            break;

         case s_SecondWord:
            if (bitNum==parameters.packetLength) {
               // Currently sending last bit
               if (protocol == p_SONY_TV) {
                  // Done - set up for next packet
                  state = s_Complete;
               }
               else {
                  // Set up stop bit
                  state = s_Stop;
               }
            }
            break;

         case s_Stop:
            // Currently sending stop bit
            state = s_Trailer;
            break;

         case s_Trailer:
            // Currently sending trailing space
            state = s_Complete;
            break;

         case s_Complete:
            // Can't happen
            break;

      }

      // Scratch
      Ticks remainingTimeSplit;

      // This switch sets up action for the new state
      switch(state) {
         case s_Initial:
         case s_Start:
            // Can't happen
            break;

         case s_FirstWord:
         case s_SecondWord:
            // Set up next bit in word

            // LSB first
            if (shiftReg&0b1) {
               Cmt::setMarkSpacePeriods(parameters.oneHigh, parameters.oneLow);
               progress = progress + parameters.oneHigh + parameters.oneLow;
            }
            else {
               Cmt::setMarkSpacePeriods(parameters.zeroHigh, parameters.zeroLow);
               progress = progress + parameters.zeroHigh + parameters.zeroLow;
            }
            bitNum++;
            shiftReg >>= 1;
            break;

         case s_MiddleStop:
            // Set up middle stop bit
            Cmt::setMarkSpacePeriods(parameters.oneHigh, parameters.startLow);
            progress = progress + parameters.oneHigh+parameters.startLow;
            break;

         case s_Stop:
            // Set up stop bit
            Cmt::setMarkSpacePeriods(parameters.zeroHigh, parameters.zeroLow);
            progress = progress + parameters.zeroHigh+parameters.zeroLow;
            break;

         case s_Trailer:
            // Set up trailer
            remainingTimeSplit = Ticks((parameters.repeatTime-progress)/2);
            Cmt::setExtendedSpace(CmtExtendedSpace_Disabled);
            Cmt::setMarkSpacePeriods(remainingTimeSplit, remainingTimeSplit);
            break;

         case s_Complete:
            // Set up for next packet
            Cmt::setExtendedSpace(CmtExtendedSpace_Disabled);
            Cmt::setMarkSpacePeriods(parameters.startHigh, parameters.startLow);

            if (++repeatCount >= parameters.repeats) {
               // Completed entire sequence of repeats

               // Disable CMT
               Cmt::stop();

               // Clear Interrupt flag
               Cmt::clearEndOfCycleFlag();
            }
            else {
               state = s_Start;
            }
            break;
      }
   }
   DebugLed::off();
}
