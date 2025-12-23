/**
 * @file    cmt-remote.h  (180.ARM_Peripherals/Snippets)
 * @brief   Example showing use of CMT to implement various IR protocols
 */
#pragma once

#include "hardware.h"
#include "../Project_Headers/cmt.h"

namespace USBDM {

/**
 * Class to wrap CMT hardware for Interval based IR code protocols e.g. NEC, Laser, Samsung etc
 */
class IrRemote {

private:
   IrRemote() = delete;
   IrRemote(const IrRemote &) = delete;

protected:

   static constexpr uint32_t SONY_LENGTH_MASK = 0xC000'0000;
   static constexpr uint32_t SONY_LENGTH_12   = 0x0000'0000;
   static constexpr uint32_t SONY_LENGTH_15   = 0x8000'0000;
   static constexpr uint32_t SONY_LENGTH_20   = 0x4000'0000;

   static constexpr uint32_t makeSonyCode(uint32_t length, uint32_t device, uint32_t function, uint32_t subdevice) {
      if (length == 12) { // F:7,D:5 | 7 + 5 = 12
         return (function&0b111'1111)|((device&0b1'1111)<<7)|SONY_LENGTH_12;
      }
      if (length == 15) { // F:7,D:8 | 7 + 8 = 15
         return (function&0b111'1111)|((device&0b1111'1111)<<7)|SONY_LENGTH_15;
      }
      if (length == 20) { // F:7,D:5,S:8 | 7 + 5 + 8 = 20
         return (function&0b111'1111)|((device&0b1'1111)<<7)|((subdevice&0b1111'1111)<<12)|SONY_LENGTH_20;
      }
      return -1U;
   }

   static constexpr uint32_t Sony12(uint32_t device, uint32_t function) {
      return makeSonyCode(12, device, function, -1);
   }

   static constexpr uint32_t Sony15(uint32_t device, uint32_t function) {
      return makeSonyCode(15, device, function, -1);
   }

   static constexpr uint32_t Sony20(uint32_t device, uint32_t subDevice, uint32_t function) {
      return makeSonyCode(20, device, function, subDevice);
   }

   static constexpr uint32_t makeTeacCode(uint8_t device, uint8_t subDevice, uint8_t function) {
      return (device<<24)|(subDevice<<16)|(function<<8)|(0x00<<0);
   }

   enum Control : uint16_t {
//      ....           = 0b0000'0000'0000'0000U,
//      ....           = 0b0001'0000'0000'0000U,
      c_Delay          = 0b0010'0000'0000'0000U,
      c_Duration       = 0b0011'0000'0000'0000U,
//      ....           = 0b0100'0000'0000'0000U,
      c_MarkSpace      = 0b0101'0000'0000'0000U,
      c_Data           = 0b0110'0000'0000'0000U,
      c_DataLiteral    = 0b0111'0000'0000'0000U,
      c_Label          = 0b1000'0000'0000'0000U,
      c_Loop           = 0b1001'0000'0000'0000U,
      c_Repeat         = 0b1010'0000'0000'0000U,
      c_LoopFixed      = 0b1011'0000'0000'0000U,
//      ....           = 0b1100'0000'0000'0000U,
      c_Cleanup        = 0b1101'0000'0000'0000U,
      c_Epoch_Start    = 0b1110'0000'0000'0000U,
      c_End            = 0b1111'0000'0000'0000U,
   };

   static constexpr Control c_ControlMask    = Control(0b1111'0000'0000'0000U);
   static constexpr Control c_Value8Mask     = Control(0b0000'0000'1111'1111U);
   static constexpr Control c_Value12Mask    = Control(0b0000'1111'1111'1111U);
   static constexpr Control c_Length4Mask    = Control(0b0000'1111'0000'0000U);

   static constexpr Control Data1(uint8_t length) {
      return Control(unsigned(c_Data)|(length<<2)|0);
   }

   static constexpr Control Data2(uint8_t length) {
      return Control(unsigned(c_Data)|(length<<2)|1);
   }

   static constexpr Control DataSony() {
      return Control(unsigned(c_Data)|(0xFF<<2)|0);
   }

   static constexpr unsigned extractDataIndex(Control control) {
       return unsigned(control)&0b1;
    }

   static constexpr unsigned extractDataLength(Control control, uint32_t txData) {

       unsigned length = (unsigned(control)>>2)&0xFF;

       if (length==0xFF) {
          switch(txData&SONY_LENGTH_MASK) {
             case SONY_LENGTH_12: length = 12; break;
             case SONY_LENGTH_15: length = 15; break;
             case SONY_LENGTH_20: length = 20; break;
             default: usbdm_assert(false, "Illegal length for Sony protocol"); break;
          }
       }
       return length;
    }

   static constexpr Control Value(uint16_t data) {
      return Control(data);
   }

   static constexpr Control DurationHigh(uint32_t data) {
      return Control(c_Duration|((data>>16)&c_Value12Mask));
   }

   static constexpr Control DurationLow(uint32_t data) {
      return Control(data);
   }

   static constexpr Control DelayHigh(uint32_t data) {
      return Control(c_Delay|((data>>16)&c_Value12Mask));
   }

   static constexpr Control DelayLow(uint32_t data) {
      return Control(data);
   }

   static constexpr Control Label(uint8_t label) {
      return Control(c_Label|(label&0b11));
   }

   static constexpr unsigned extractLabelIndex(Control control) {
      return unsigned(control)&0b11;
   }

   static constexpr Control FixedLoop(uint8_t label, uint8_t count) {
      return Control(c_LoopFixed|(((count&0b1111)<<2)|(label&0b11)));
   }

   static constexpr unsigned extractFixedLoopCount(Control control) {
      return (unsigned(control)>>2)&0b1111;
   }

   static constexpr Control Loop(uint8_t label) {
      return Control(c_Loop|(label&0b11));
   }

   static constexpr Control Repeat(uint8_t label) {
      return Control(c_Repeat|(label&0b11));
   }

   static constexpr Control DataImmediateLength(uint8_t length) {
      return Control(c_DataLiteral|(length&c_Value8Mask));
   }

   static constexpr Control DataImmediateHigh(uint32_t data) {
      return Control((data>>16)&c_Value8Mask);
   }

   static constexpr Control DataImmediateLow(uint32_t data) {
      return Control(data&c_Value8Mask);
   }

   static constexpr unsigned extractDataLiteralLength(Control control) {
      return unsigned(control)&c_Value8Mask;
   }


private:

   inline static Control const *sequence;
   inline static Control const *startOfSequence;
   inline static Control current;

   inline static unsigned dataCount;
   inline static uint32_t dataBitMask;
   inline static uint32_t data[2];
   inline static uint32_t txData;

   inline static uint16_t ZeroHigh;
   inline static uint16_t ZeroLow;
   inline static uint16_t OneHigh;
   inline static uint16_t OneLow;

   inline static unsigned eventCount;
   inline static Ticks    tickCount;
   inline static Ticks    duration;

   inline static Control const *labels[4]    = {nullptr,nullptr,nullptr,nullptr,};
   inline static uint8_t       loopCounts[4] = {0,0,0,0,};

   inline static uint8_t repeatCount;

   inline static volatile bool keepRepeating = false;

   inline static bool complete = true;

   /**
    * Callback from CMT.
    *
    * This processes each timing interval of the transmission.
    */
   static void cmtCallback() {

//      DebugLed::on();
      eventCount++;

      if (Cmt::getEndOfCycleFlag()) {
         // Clear CMT flag if origin
         Cmt::clearEndOfCycleFlag();
      }

      // Process events until one generating a call-back
      for(;;) {
         uint8_t loopIndex;
         Control action = Control(current&c_ControlMask);
         switch(action) {

            case c_Label:
               loopIndex = extractLabelIndex(current); //uint8_t(current)&0b11;

               if (labels[loopIndex] != nullptr) {
                  // Repeat-label loop

                  // Go back to Repeat
                  sequence = labels[loopIndex];

                  // Advance sequence
                  current  = *sequence++;
               }
               else {
                  // Label-Loop or Label-FixedLoop

                  // Zero count indicates new entry to loop for later check by Loop/FixedLoop
                  loopCounts[loopIndex] = 0;

                  // Save pointer to _next_ action (loop to after label!)
                  labels[loopIndex]     = sequence;

                  // Advance sequence
                  current  = *sequence++;
               }
               continue;

            case c_LoopFixed:
               loopIndex = extractLabelIndex(current);

               if (loopCounts[loopIndex] == 0) {
                  // First time through loop
                  loopCounts[loopIndex] = extractFixedLoopCount(current);
               }
               if (--loopCounts[loopIndex]>0) {
                  // Loop sequence
                  sequence  = labels[loopIndex];
               }
               else {
                  labels[loopIndex] = nullptr;
               }
               // Advance sequence
               current  = *sequence++;
               continue;

            case c_Loop:
               loopIndex = extractLabelIndex(current);
               if (repeatCount-->0) {
                  // Loop sequence
                  sequence  = labels[loopIndex];
               }
               // Advance sequence
               current  = *sequence++;
               continue;

            case c_Repeat:
               loopIndex = extractLabelIndex(current);

               if (repeatCount--==0) {
                  // Terminate loop
                  labels[loopIndex] = nullptr;
                  do {
                     // Look for matching label
                     current = *sequence++;

                     usbdm_assert(current != c_End, "Fallen off end!");

                  } while(current != Label(loopIndex));
               }
               else {
                  // New repeat - Record top of loop sequence
                  // Points at _this_ code
                  labels[loopIndex] = sequence-1;
               }
               // Advance sequence
               current  = *sequence++;
               continue;

            case c_Epoch_Start:
               current   = *sequence++;
               tickCount = 0_ticks;
               break;

            default:
               break;
         }
         break;
      };

      Ticks high, low;
      bool bit;

      Control action = Control(current&c_ControlMask);
      switch(action) {

         case c_MarkSpace:
            high    = Ticks(*sequence++);
            low     = Ticks(*sequence++);

            // Advance sequence
            current = *sequence++;

            Cmt::setMarkSpacePeriods(high, low);
            Cmt::setExtendedSpace(CmtExtendedSpace_Disabled);
            Cmt::setMode(CmtMode_Time);
            tickCount = tickCount + high + low;
            break;

         case c_DataLiteral:

            if (dataCount == 0) {
               dataCount   = extractDataLiteralLength(current);
               high     = Ticks(*sequence++);
               low      = Ticks(*sequence++);
               txData   = (high<<16)+low;
               dataBitMask = 0b1;
            }
            bit = txData&dataBitMask;
            if (bit) {
               high = Ticks(OneHigh);
               low  = Ticks(OneLow);
            }
            else {
               high = Ticks(ZeroHigh);
               low  = Ticks(ZeroLow);
            }
            Cmt::setMarkSpacePeriods(high, low);
            Cmt::setExtendedSpace(CmtExtendedSpace_Disabled);
            tickCount = tickCount + high + low;
            if (--dataCount == 0) {

               // Advance sequence
               current = *sequence++;
            }
            dataBitMask <<= 1;
            break;

         case  c_Data :
            if (dataCount == 0) {
               // First time - set up data Tx
               txData      = data[extractDataIndex(current)];
               dataCount   = extractDataLength(current, txData);
               dataBitMask = 0b1;
            }
            bit = txData&dataBitMask;
            if (bit) {
               high = Ticks(OneHigh);
               low  = Ticks(OneLow);
            }
            else {
               high = Ticks(ZeroHigh);
               low  = Ticks(ZeroLow);
            }
            Cmt::setMarkSpacePeriods(high, low);
            Cmt::setExtendedSpace(CmtExtendedSpace_Disabled);
            tickCount = tickCount + high + low;
            if (--dataCount == 0) {

               // Advance sequence
               current = *sequence++;
            }
            dataBitMask <<= 1;
            break;

         case c_Duration:  // Delay from last reference
         case c_Delay:     // Absolute delay
            if (duration == 0) {
               // New delay/duration
               high     = Ticks(current&c_Value12Mask);
               low      = Ticks(*sequence++);
               duration = Ticks((high<<16)+low);
               if (action == c_Duration) {
                  // Make relative

                  usbdm_assert(duration > tickCount, "Duration < current time!");
                  duration = duration - tickCount;
               }
            }
            else {
               // Continuation of current
            }

            high = duration;
            if (high > 2*65000_ticks) {
               high = 2*65000_ticks;
            }

            // Split times
            low    = Ticks(high/2);
            high   = high - low;

            Cmt::setMarkSpacePeriods(high, low);
            Cmt::setExtendedSpace(CmtExtendedSpace_Enabled);

            tickCount = tickCount + high + low;

            duration = duration - high - low;
            if (duration == 0) {
               // Advance sequence as completed this action
               current  = *sequence++;
            }
            break;

         case c_End:
            // Last cycle underway

            // Do a dummy cycle to wait for Tx complete
            Cmt::setMarkSpacePeriods(1_ticks, 0_ticks);
            Cmt::setExtendedSpace(CmtExtendedSpace_Enabled);
            current = c_Cleanup;
            return;

         case c_Cleanup:
            // Dummy cycle underway

            // Disable CMT - It will continue until end of dummy cycle even if CMT stopped
            Cmt::stop();
            complete   = true;
            return;

         default:
            break;
      }

//      DebugLed::off();
   }

   static void playEvent() {

      eventCount++;
      keepRepeating = true;

      static constexpr IntegerFormat decimal8Format {
         Width_8,
         Padding_LeadingSpaces,
      };

      static constexpr IntegerFormat decimal2Format {
         Width_2,
         Padding_LeadingSpaces,
      };

      static constexpr IntegerFormat hexFormat {
         Width_8,
         Radix_16,
         Padding_LeadingZeroes,
      };

      // Process events until one generating a call-back
      for(;;) {
         unsigned location = unsigned(sequence-startOfSequence)-1;
         uint8_t loopIndex;
         Control action = Control(current&c_ControlMask);
         switch(action) {

            case c_Label:
               loopIndex = extractLabelIndex(current); //uint8_t(current)&0b11;

               if (labels[loopIndex] != nullptr) {
                  // Repeat-label loop

                  // Go back to Repeat
                  sequence = labels[loopIndex];

                  console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": Label(", loopIndex, ") -> Repeat @", unsigned(sequence-startOfSequence));

                  // Advance sequence
                  current  = *sequence++;
               }
               else {
                  // Label-Loop or Label-FixedLoop

                  // Zero count indicates new entry to loop for later check by Loop/FixedLoop
                  loopCounts[loopIndex] = 0;

                  // Save pointer to _next_ action (loop to after label!)
                  labels[loopIndex]     = sequence;

                  console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": Label(", loopIndex, ") @", unsigned(sequence-startOfSequence));

                  // Advance sequence
                  current  = *sequence++;
               }
               continue;

            case c_LoopFixed:
               loopIndex = extractLabelIndex(current); //uint8_t(current)&0b11;

               if (loopCounts[loopIndex] == 0) {
                  // First time through loop
                  loopCounts[loopIndex] = extractFixedLoopCount(current); //uint8_t(current>>2);
               }
               if (--loopCounts[loopIndex]>0) {
                  // Loop sequence
                  sequence  = labels[loopIndex];
               }
               else {
                  labels[loopIndex] = nullptr;
               }
               console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": LoopFixed:(", loopIndex, ',', loopCounts[loopIndex]+1, ") -> Repeat @", unsigned(sequence-startOfSequence));

               // Advance sequence
               current  = *sequence++;
               continue;

            case c_Loop:
               loopIndex = extractLabelIndex(current); //uint8_t(current)&0b11;
               if (repeatCount-->0) {
                  // Loop sequence
                  sequence  = labels[loopIndex];
               }
               console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": Loop:(", loopIndex, ',', repeatCount+1, ") -> Repeat @", unsigned(sequence-startOfSequence));

               // Advance sequence
               current  = *sequence++;
               continue;

            case c_Repeat:
               loopIndex = extractLabelIndex(current); //uint8_t(current)&0b11;

               if (repeatCount--==0) {
                  // Terminate loop
                  labels[loopIndex] = nullptr;
                  do {
                     // Look for matching label
                     current = *sequence++;

                     usbdm_assert(current != c_End, "Fallen off end!");

                  } while(current != Label(loopIndex));

                  console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": Repeat(", loopIndex, ',', 0, ") - exit -> ", unsigned(sequence-startOfSequence));
               }
               else {
                  // Loop sequence
                  // Points at _this_ code
                  labels[loopIndex] = sequence-1;
                  console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": Repeat(", loopIndex, ',', repeatCount+1, ") - entry ");
               }
               // Advance sequence
               current  = *sequence++;
               continue;

            default:
               break;
         }
         break;
      };

      Ticks high, low;
      Ticks duration;
      bool bit;

      unsigned location = unsigned(sequence-startOfSequence)-1;

      Control action = Control(current&c_ControlMask);
      switch(action) {

         case c_MarkSpace:
            high    = Ticks(*sequence++);
            low     = Ticks(*sequence++);

            // Advance sequence
            current = *sequence++;

            console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": MarkSpace(", high, "|", low, ")");
            tickCount = tickCount + high + low;
            break;

         case c_DataLiteral:

            if (dataCount == 0) {
               dataCount   = extractDataLiteralLength(current);
               high     = Ticks(*sequence++);
               low      = Ticks(*sequence++);
               txData   = (high<<16)+low;
               dataBitMask = 0b1;
               console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ":--------------------------------------------");
               console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": dataliteral-start(d=0x", txData, hexFormat, ":c=", dataCount, ')');
            }
            bit = txData&dataBitMask;
            if (bit) {
               high = Ticks(OneHigh);
               low  = Ticks(OneLow);
            }
            else {
               high = Ticks(ZeroHigh);
               low  = Ticks(ZeroLow);
            }
            console.write('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": data(c=", dataCount,  decimal2Format, ", m=0x", dataBitMask, hexFormat, ", b=", (bit?1:0), ") ");
            console.writeln("Tx(", high, "|", low, ")");
            tickCount = tickCount + high + low;
            if (--dataCount == 0) {

               // Advance sequence
               current = *sequence++;
            }
            dataBitMask <<= 1;
            break;

         case  c_Data :
            if (dataCount == 0) {
               txData      = data[extractDataIndex(current)];
               dataCount   = extractDataLength(current, txData);
               dataBitMask = 0b1;
               console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ":--------------------------------------------");
               console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": data-start(d=0x", txData, hexFormat, "|c=", dataCount, ')');
            }
            bit = txData&dataBitMask;
            if (bit) {
               high = Ticks(OneHigh);
               low  = Ticks(OneLow);
            }
            else {
               high = Ticks(ZeroHigh);
               low  = Ticks(ZeroLow);
            }
            console.write('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": data(c=", dataCount,  decimal2Format, ", m=0x", dataBitMask, hexFormat, ", b=", (bit?1:0), ") ");
            console.writeln("Tx(", high, "|", low, ")");
            tickCount = tickCount + high + low;
            if (--dataCount == 0) {

               // Advance sequence
               current = *sequence++;
            }
            dataBitMask <<= 1;
            break;

         case c_Delay:
            high     = Ticks(current&c_Value12Mask);
            low      = Ticks(*sequence++);
            duration = Ticks((high<<16)+low);

            console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": Delay(", duration, ")");
            tickCount = tickCount + duration;

            // Advance sequence
            current  = *sequence++;
            break;

         case c_Duration:
            high     = Ticks(current&c_Value12Mask);
            low      = Ticks(*sequence++);
            duration = Ticks((high<<16)+low) - tickCount;

            console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": Duration(", tickCount+duration, "(+", duration, "))");

            // Restart duration
            tickCount = 0_ticks;

            // Advance sequence
            current  = *sequence++;
            break;

         case c_End:
            // Last cycle initiated
            console.writeln('[', location, decimal2Format, "]:", tickCount, decimal8Format, ": Completed");
            complete   = true;
            return;

         default:
            break;
      }

//      DebugLed::off();
   }

   /**
    * Stop any further repeats
    */
   void stop() {
      keepRepeating = false;
   }

protected:

   /**
    * Send an IR transmission
    *
    * @param data1         First data item/code
    * @param data2         Second data item/code
    * @param repeat        Number of times to repeat (including original).
    * @param delay         Delay at end of sequence 1_tick = 1us
    */
   static void start(const Control *newSequence, uint32_t data1, uint32_t data2, unsigned repeat, unsigned delay) {

      // Wait until previous Tx completes
      waitUntilComplete();

      complete    = false;
      sequence    = newSequence;
      data[0]     = data1;
      data[1]     = data2;
      repeatCount = repeat;

      dataBitMask = 0b1;
      dataCount   = 0;
      tickCount   = 0_ticks;
      eventCount  = 0;

      unsigned frequency  = uint16_t(*sequence++);

      ZeroHigh  = uint16_t(*sequence++);
      ZeroLow   = uint16_t(*sequence++);
      OneHigh   = uint16_t(*sequence++);
      OneLow    = uint16_t(*sequence++);

//      DebugLed::setOutput();


      static constexpr PcrInit pcrInit {
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow,
      };
      Cmt::setOutput(pcrInit);
      //      SimInfo::setPortDPad(SimPortDPad_Double);

      /// Carrier half period in CMT clock cycles (Based on 8MHz CMT clock)
      const Ticks  carrierHalfPeriodInTicks = Ticks(8_MHz/frequency/2);

      Cmt::Init cmtInitValue {

         NvicPriority_Normal,
         cmtCallback,

         CmtEnable_Disabled,                                  // (cmt_msc_mcgen)  Enable - Disabled initially
         CmtMode_Time ,                                       // (cmt_msc_mode)   Mode of operation - Disabled
         CmtClockPrescaler_Auto ,                             // (cmt_pps_ppsdiv) Primary Prescaler Divider - Auto ~8MHz
         CmtIntermediatePrescaler_DivBy1 ,                    // (cmt_msc_cmtdiv) Intermediate frequency Prescaler - Intermediate frequency /4
         CmtOutput_ActiveHigh ,                               // (cmt_oc_output)  Output Control - Disabled
         CmtEndOfCycleAction_Interrupt ,                      // (cmt_dma_irq)    End of Cycle Event handling - Interrupt Request
         CmtPrimaryCarrierHighTime(carrierHalfPeriodInTicks), // (cmt_cgh1_ph)    Primary Carrier High Time Data Value
         CmtPrimaryCarrierLowTime(carrierHalfPeriodInTicks),  // (cmt_cgl1_pl)    Primary Carrier Low Time Data Value
         // (cmt_mark)       Mark period (set by call-back)
         // (cmt_space)      Space period (set by call-back)
      };

      // Configure CMT
      Cmt::configure(cmtInitValue);

      {
         CriticalSection cs;
      // Prime 1st call-back
      current = *sequence++;
      cmtCallback();
      }

      Cmt::start();

      waitUntilComplete();

      static Control delaySequence[3];

      delaySequence[0] = DelayHigh(Ticks(delay));  // delay us
      delaySequence[1] = DelayLow(Ticks(delay));   //
      delaySequence[2] = c_End;

      sequence   = delaySequence;
      complete   = false;
      tickCount  = 0_ticks;

      // Configure CMT
      Cmt::configure(cmtInitValue);

      // Prime 1st call-back
      current = *sequence++;
      cmtCallback();

      Cmt::start();
   }

public:

   static void waitUntilComplete() {
      while (!complete) {
         __asm__("nop");
      }
   }

   static void testSequence(const Control *newSequence, uint32_t data1, uint32_t data2, uint8_t repeats) {

      sequence        = newSequence;
      startOfSequence = sequence;
      repeatCount     = repeats;

      sequence++; // Discard frequency

      ZeroHigh  = uint16_t(*sequence++);
      ZeroLow   = uint16_t(*sequence++);
      OneHigh   = uint16_t(*sequence++);
      OneLow    = uint16_t(*sequence++);

      data[0]     = data1;
      data[1]     = data2;
      dataBitMask = 0b1;
      dataCount   = 0;
      tickCount   = 0_ticks;
      eventCount  = 0;
      complete    = false;

      current = *sequence++;

      while (!complete) {
         playEvent();
      }
   }
};

/**
 * Class to wrap CMT hardware for Laser-DVD protocol
 *
 * Based on NEC IR protocol
 */
class IrLaserDVD : public IrRemote {

private:

   inline static const Control protocolSequence[] = {
         //  IRP: {38.0k,564}<1,-1|1,-3>(16,-8,D:8,S:8,F:8,~F:8,1,^108m)(16,-4,1,^108m)*
         //
         /*      */   // Parameters
         /*      */   //=======================
         /*      */   Value(38_kHz),        // Frequency (Hz) {38.0k,564}
         /*      */
         /*      */   Value(1*564_ticks),   // 0 High (us) <1,-1|1,-3>
         /*      */   Value(1*564_ticks),   // 0 Low  (us)
         /*      */   Value(1*564_ticks),   // 1 High (us)
         /*      */   Value(3*564_ticks),   // 1 Low  (us)
         /*      */
         /*      */   // Start of sequence
         /*      */   //=======================
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | Start-bit
         /*  1   */   c_MarkSpace,          //                |
         /*      */   Value(16*564_ticks),  // Start bit high | (16,-8)
         /*      */   Value(8*564_ticks),   // Start bit low  |
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | 32-bit Data
         /* 2-33 */   Data1(32),            //                | (D:8,S:8,F:8,~F:8)
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | Stop-bit
         /* 34   */   c_MarkSpace,          //                |
         /*      */   Value(1*564_ticks),   // Stop bit high  + (1,^108m)
         /*      */   Value(0),             // ---            |
         /*      */                         //                |
         /* 35   */   DurationHigh(108000), // ^108m          |
         /*      */   DurationLow(108000),  //                +
         /*      */
         /*      */   //-----------------------------------------
         /*      */   //                                          | Abbreviated Repeat
         /* 36   */   Repeat(0),                //                +
         /*      */      c_Epoch_Start,         //                |
         /*      */                             //                |
         /* 37   */      c_MarkSpace,           //                |
         /*      */      Value(16*564_ticks),   // 16             | (16,-4,1,^108m)R+
         /*      */      Value(4*564_ticks),    // -4             |
         /*      */                             //                |
         /* 38   */      c_MarkSpace,           //                |
         /*      */      Value(1*564_ticks),    // 1              |
         /*      */      Value(0),              //                |
         /*      */                             //                |
         /* 39   */      DurationHigh(108000),  // ^108m          |
         /*      */      DurationLow(108000),   //                |
         /*      */                             //                |
         /* 40   */   Label(0),                 //                +
         /*      */
         /* 41   */   c_End,
   };

public:
   /**
    * Common codes
    */
   enum Code : uint32_t {
      A_B                 =    0xAA55FF00,
      ANGLE               =    0xF00FFF00,
      AUDIO               =    0xBC43FF00,
      CHANNEL             =    0xE718FF00,
      CLEAR               =    0xAB54FF00,
      COPY_DELETE         =    0xEA15FF00,
      DOWN                =    0xB748FF00,
      DVD_USB             =    0xF807FF00,
      EJECT               =    0xFF00FF00,
      FORWARD             =    0xEF10FF00,
      FORWARD_SCENE       =    0xE31CFF00,
      LEFT                =    0xB34CFF00,
      MARK                =    0xEC13FF00,
      MENU                =    0xF40BFF00,
      MUTE                =    0xA35CFF00,
      NUM0                =    0xB24DFF00,
      NUM1                =    0xF20DFF00,
      NUM2                =    0xF609FF00,
      NUM3                =    0xFA05FF00,
      NUM4                =    0xB04FFF00,
      NUM5                =    0xB44BFF00,
      NUM6                =    0xB847FF00,
      NUM7                =    0xB14EFF00,
      NUM8                =    0xB54AFF00,
      NUM9                =    0xB946FF00,
      OK                  =    0xF906FF00,
      ON_OFF              =    0xF30CFF00,
      OSD                 =    0xA25DFF00,
      PAUSE               =    0xEB14FF00,
      PAUSE_PLAY          =    0xE817FF00,
      PBC                 =    0xE619FF00,
      PLAY                =    0xA05FFF00,
      PROG                =    0xBD42FF00,
      Q_PLAY              =    0xE916FF00,
      REPEAT              =    0xAE51FF00,
      RETURN              =    0xEE11FF00,
      REVERSE             =    0xA857FF00,
      REVERSE_SCENE       =    0xA45BFF00,
      RIGHT               =    0xBF40FF00,
      SEARCH              =    0xBA45FF00,
      SETUP               =    0xFC03FF00,
      SLOW                =    0xA758FF00,
      STEP                =    0xED12FF00,
      STOP                =    0xF50AFF00,
      SUBTITLE            =    0xFE01FF00,
      TITLE               =    0xAF50FF00,
      UP                  =    0xBB44FF00,
      VIDEO               =    0xA659FF00,
      VOLUME_DOWN         =    0xF708FF00,
      VOLUME_UP           =    0xFB04FF00,
      ZOOM                =    0xBE41FF00,
   };

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param delay      Delay at end of sequence 1_tick = 1us
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, unsigned delay, unsigned repeat=3) {

      console.writeln("IrRemote: Laser-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::start(protocolSequence, code, 0, repeat, delay);
   }

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeat     Number of times to repeat (excluding original). 0 => use default for protocol
    */
   static void test(Code code, uint8_t repeat=0) {

      console.writeln("IrRemote: Laser-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::testSequence(protocolSequence, code, 0, repeat);
   }
};

/**
 * Class to wrap CMT hardware for Laser-DVD protocol
 *
 * Based on NEC IR protocol
 */
class IrBlaupunktDVD : public IrRemote {

private:

   inline static const Control protocolSequence[] = {
         //  IRP: {38.0k,564}<1,-1|1,-3>(16,-8,D:8,S:8,F:8,~F:8,1,^108m)(16,-4,1,^108m)*
         //
         /*      */   // Parameters
         /*      */   //=======================
         /*      */   Value(38_kHz),        // Frequency (Hz) {38.0k,564}
         /*      */
         /*      */   Value(1*564_ticks),   // 0 High (us) <1,-1|1,-3>
         /*      */   Value(1*564_ticks),   // 0 Low  (us)
         /*      */   Value(1*564_ticks),   // 1 High (us)
         /*      */   Value(3*564_ticks),   // 1 Low  (us)
         /*      */
         /*      */   // Start of sequence
         /*      */   //=======================
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                       | Start-bit
         /*  1   */   c_MarkSpace,           //                |
         /*      */   Value(16*564_ticks),   // Start bit high | (16,-8)
         /*      */   Value(8*564_ticks),    // Start bit low  |
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                     | 32-bit Data
         /* 2-33 */   Data1(32),           //                | (D:8,S:8,F:8,~F:8)
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | Stop-bit
         /* 34   */   c_MarkSpace,          //                |
         /*      */   Value(1*564_ticks),   // Stop bit high  + (1,^108m)
         /*      */   Value(0),             // ---            |
         /*      */                         //                |
         /* 35   */   DurationHigh(108000), // ^108m          |
         /*      */   DurationLow(108000),  //                +
         /*      */
         /*      */   //-----------------------------------------
         /*      */   //                                                     | Abbreviated Repeat
         /*      */   Repeat(0),                //                +
         /*      */      c_Epoch_Start,         //                |
         /*      */                             //                |
         /* 36   */      c_MarkSpace,           //                |
         /*      */      Value(16*564_ticks),   // 16             | (16,-4,1,^108m)R+
         /*      */      Value(4*564_ticks),    // -4             |
         /*      */                             //                |
         /* 37   */      c_MarkSpace,           //                |
         /*      */      Value(1*564_ticks),    // 1              |
         /*      */      Value(0),              //                |
         /*      */                             //                |
         /* 38   */      DurationHigh(108000),  // ^108m          |
         /*      */      DurationLow(108000),   //                |
         /*      */                             //                |
         /*      */   Label(0),                 //                +
         /*      */
         /* 42   */   c_End,
   };

public:
   /**
    * Common codes
    */
   enum Code : uint32_t {
      A_B                 =    0xB946FF00,
      ANGLE               =    0xF00FFF00,
      AUDIO               =    0xBD42FF00,
      DOWN                =    0xFE01FF00,
      EJECT               =    0xB44BFF00,
      FORWARD             =    0xB34CFF00,
      FORWARD_SCENE       =    0xBF40FF00,
      GOTO                =    0xA25DFF00,
      L_R                 =    0xE916FF00,
      LEFT                =    0xF30CFF00,
      MENU                =    0xE41BFF00,
      MUTE                =    0xE21DFF00,
      NUM0                =    0xAA55FF00,
      NUM1                =    0xEC13FF00,
      NUM10_PLUS          =    0xEE11FF00,
      NUM2                =    0xB748FF00,
      NUM3                =    0xA15EFF00,
      NUM4                =    0xA05FFF00,
      NUM5                =    0xB649FF00,
      NUM6                =    0xAC53FF00,
      NUM7                =    0xB04FFF00,
      NUM8                =    0xAF50FF00,
      NUM9                =    0xBB44FF00,
      OK                  =    0xF20DFF00,
      ON_OFF              =    0xFF00FF00,
      OSD                 =    0xE11EFF00,
      P_N                 =    0xEB14FF00,
      PLAY_PAUSE          =    0xF906FF00,
      PROG                =    0xE01FFF00,
      REPEAT              =    0xF807FF00,
      RESET               =    0xAB54FF00,
      RETURN              =    0xB14EFF00,
      REVERSE             =    0xA956FF00,
      REVERSE_SCENE       =    0xE51AFF00,
      RIGHT               =    0xFA05FF00,
      SETUP               =    0xF10EFF00,
      SLOW                =    0xED12FF00,
      STEP                =    0xFB04FF00,
      STOP                =    0xA857FF00,
      SUBTITLE            =    0xBC43FF00,
      TITLE               =    0xF609FF00,
      UP                  =    0xFD02FF00,
      USB                 =    0xEA15FF00,
      VOLUME_DOWN         =    0xF40BFF00,
      VOLUME_UP           =    0xF50AFF00,
      ZOOM                =    0xE718FF00,
};

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    * @param delay      Delay at end of sequence 1_tick = 1us
    */
   static void send(Code code, unsigned delay, unsigned repeat=3) {

      console.writeln("IrRemote: Laser-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::start(protocolSequence, code, 0, repeat, delay);
   }

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeat     Number of times to repeat (excluding original). 0 => use default for protocol
    */
   static void test(Code code, uint8_t repeat=0) {

      console.writeln("IrRemote: Laser-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::testSequence(protocolSequence, code, 0, repeat);
   }
};

/**
 * Class to wrap CMT hardware for Teac-DVD protocol
 *
 * Based on NEC IR protocol
 */
class  IrTeacPVR : public IrRemote {

private:

   IrTeacPVR() = delete;
   IrTeacPVR(const IrTeacPVR &) = delete;

   inline static const Control protocolSequence[] = {
         //  IRP: {38.0k,564}<1,-1|1,-3>(16,-8,D:8,S:8,F:8,~F:8,1,^108m)(16,-4,1,^108m)*
         //
         /*      */   // Parameters
         /*      */   //=======================
         /*      */   Value(38_kHz),        // Frequency (Hz) {38.0k,564}
         /*      */
         /*      */   Value(1*564_ticks),   // 0 High (us) <1,-1|1,-3>
         /*      */   Value(1*564_ticks),   // 0 Low  (us)
         /*      */   Value(1*564_ticks),   // 1 High (us)
         /*      */   Value(3*564_ticks),   // 1 Low  (us)
         /*      */
         /*      */   // Start of sequence
         /*      */   //=======================
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | Start-bit
         /*  1   */   c_MarkSpace,          //                |
         /*      */   Value(16*564_ticks),  // Start bit high | (16,-8)
         /*      */   Value(8*564_ticks),   // Start bit low  |
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | 32-bit Data
         /* 2-33 */   Data1(32),            //                | (D:8,S:8,F:8,~F:8)
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | Stop-bit
         /* 34   */   c_MarkSpace,          //                |
         /*      */   Value(1*564_ticks),   // Stop bit high  + (1,^108m)
         /*      */   Value(0),             // ---            |
         /*      */                         //                |
         /* 35   */   DurationHigh(108000), // ^108m          |
         /*      */   DurationLow(108000),  //                +
         /*      */
         /*      */   //-----------------------------------------
         /*      */   //                                                    | Abbreviated Repeat
         /*      */   Repeat(0),               //                +
         /*      */      c_Epoch_Start,        //                |
         /*      */                            //                |
         /* 36   */      c_MarkSpace,          //                |
         /*      */      Value(16*564_ticks),  // Start bit high | (16,-4,1,^108m)R+
         /*      */      Value(4*564_ticks),   // Start bit low  |
         /* 37   */      c_MarkSpace,          //                |
         /*      */      Value(1*564_ticks),   // Stop bit high  |
         /*      */      Value(0),             // ---            |
         /*      */                            //                |
         /* 38   */      DurationHigh(108000), // ^108m          |
         /*      */      DurationLow(108000),  //                |
         /*      */                            //                |
         /*      */   Label(0),                //                +
         /*      */
         /* 42   */   c_End,
   };

public:
   /**
    * Common codes
    */
   enum Code : uint32_t {   //              Dev  Sub  F
      AUDIO               =    makeTeacCode(0xAE,0x51,0xBF),
      BLUE                =    makeTeacCode(0xFC,0x03,0xBF),
      DOWN                =    makeTeacCode(0xE9,0x16,0xBF),
      EPG                 =    makeTeacCode(0xB2,0x4D,0xBF),
      EXIT                =    makeTeacCode(0xFA,0x05,0xBF),
      FAV                 =    makeTeacCode(0xAA,0x55,0xBF),
      FORWARD             =    makeTeacCode(0xB7,0x48,0xBF),
      FORWARD_SCENE       =    makeTeacCode(0xF4,0x0B,0xBF),
      GOTO                =    makeTeacCode(0xE8,0x17,0xBF),
      GREEN               =    makeTeacCode(0xBF,0x40,0xBF),
      INFO                =    makeTeacCode(0xF1,0x0E,0xBF),
      LEFT                =    makeTeacCode(0xA5,0x5A,0xBF),
      LIST                =    makeTeacCode(0xE7,0x18,0xBF),
      MENU                =    makeTeacCode(0xBA,0x45,0xBF),
      MUTE                =    makeTeacCode(0xE6,0x19,0xBF),
      NUM0                =    makeTeacCode(0xF0,0x0F,0xBF),
      NUM1                =    makeTeacCode(0xAD,0x52,0xBF),
      NUM2                =    makeTeacCode(0xAF,0x50,0xBF),
      NUM3                =    makeTeacCode(0xEF,0x10,0xBF),
      NUM4                =    makeTeacCode(0xA9,0x56,0xBF),
      NUM5                =    makeTeacCode(0xAB,0x54,0xBF),
      NUM6                =    makeTeacCode(0xEB,0x14,0xBF),
      NUM7                =    makeTeacCode(0xB1,0x4E,0xBF),
      NUM8                =    makeTeacCode(0xB3,0x4C,0xBF),
      NUM9                =    makeTeacCode(0xF3,0x0C,0xBF),
      OK                  =    makeTeacCode(0xE5,0x1A,0xBF),
      ON_OFF              =    makeTeacCode(0xA6,0x59,0xBF),
      PAUSE               =    makeTeacCode(0xBB,0x44,0xBF),
      PLAY                =    makeTeacCode(0xB9,0x46,0xBF),
      REC                 =    makeTeacCode(0xA7,0x58,0xBF),
      RECALL              =    makeTeacCode(0xEC,0x13,0xBF),
      RED                 =    makeTeacCode(0xBD,0x42,0xBF),
      REPEAT              =    makeTeacCode(0xF8,0x07,0xBF),
      REVERSE             =    makeTeacCode(0xB5,0x4A,0xBF),
      REVERSE_SCENE       =    makeTeacCode(0xF7,0x08,0xBF),
      RIGHT               =    makeTeacCode(0xE4,0x1B,0xBF),
      STOP                =    makeTeacCode(0xFB,0x04,0xBF),
      SUBTITLE            =    makeTeacCode(0xEE,0x11,0xBF),
      TTX                 =    makeTeacCode(0xF2,0x0D,0xBF),
      TV_RADIO            =    makeTeacCode(0xEA,0x15,0xBF),
      UP                  =    makeTeacCode(0xF9,0x06,0xBF),
      YELLOW              =    makeTeacCode(0xFF,0x00,0xBF),
};

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param delay      Delay at end of sequence 1_tick = 1us
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, unsigned delay, unsigned repeat=3) {

      console.writeln("IrRemote: Teac-PVR: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::start(protocolSequence, code, 0, repeat, delay);
   }

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void test(Code code, uint8_t repeat=0) {

      console.writeln("IrRemote: Teac-PVR: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::testSequence(protocolSequence, code, 0, repeat);
   }

};

/**
 * Class to wrap CMT hardware for Teac-DVD protocol
 *
 * Based on NEC IR protocol
 */
class  IrTeacDVD : public IrRemote {
private:

   IrTeacDVD() = delete;
   IrTeacDVD(const IrTeacDVD &) = delete;

   inline static const Control protocolSequence[] = {
         //           {38k,564}<1,-1|1,-3>(16,-8,D:8,S:8,F:8,~F:8,1,^108m)(16,-4,1,^108m)*
         //
         /*      */   // Parameters
         /*      */   //=======================
         /*      */   Value(38_kHz),        // Frequency (Hz) {38.0k,564}
         /*      */
         /*      */   Value(1*564_ticks),   // 0 High (us) <1,-1|1,-3>
         /*      */   Value(1*564_ticks),   // 0 Low  (us)
         /*      */   Value(1*564_ticks),   // 1 High (us)
         /*      */   Value(3*564_ticks),   // 1 Low  (us)
         /*      */
         /*      */   // Start of sequence
         /*      */   //=======================
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | Start-bit
         /*  1   */   c_MarkSpace,          //                |
         /*      */   Value(16*564_ticks),  // Start bit high | (16,-8)
         /*      */   Value(8*564_ticks),   // Start bit low  |
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | 32-bit Data
         /* 2-33 */   Data1(32),            //                | (D:8,S:8,F:8,~F:8)
         /*      */
         /*      */   //--------------------------------------
         /*      */   //                                      | Stop-bit
         /* 34   */   c_MarkSpace,          //                |
         /*      */   Value(1*564_ticks),   // Stop bit high  + (1,^108m)
         /*      */   Value(0),             // ---            |
         /*      */                         //                |
         /* 35   */   DurationHigh(108000), // ^108m          |
         /*      */   DurationLow(108000),  //                +
         /*      */
         /*      */   //-----------------------------------------
         /*      */   //                                         | Abbreviated Repeat
         /*      */   Repeat(0),               //                +
         /*      */      c_Epoch_Start,        //                |
         /*      */                            //                |
         /* 36   */      c_MarkSpace,          //                |
         /*      */      Value(16*564_ticks),  // Start bit high | (16,-4,1,^108m)R+
         /*      */      Value(4*564_ticks),   // Start bit low  |
         /* 37   */      c_MarkSpace,          //                |
         /*      */      Value(1*564_ticks),   // Stop bit high  |
         /*      */      Value(0),             // ---            |
         /*      */                            //                |
         /* 38   */      DurationHigh(108000), // ^108m          |
         /*      */      DurationLow(108000),  //                |
         /*      */                            //                |
         /*      */   Label(0),                //                +
         /*      */
         /* 42   */   c_End,
   };

public:
   /**
    * Common codes
    */
   enum Code : uint32_t {
      A_B                 =    0xA15EFF00,
      ANGLE               =    0xA758FF00,
      CLEAR               =    0xA35CFF00,
      DOWN                =    0xAA55FF00,
      DVD_USB             =    0xA45BFF00,
      EJECT               =    0xF708FF00,
      ENTER               =    0xAD52FF00,
      FORWARD             =    0xB748FF00,
      FORWARD_SCENE       =    0xB54AFF00,
      L_R                 =    0xA25DFF00,
      LANGUAGE            =    0xA659FF00,
      LEFT                =    0xAE51FF00,
      MENU                =    0xAB54FF00,
      MUTE                =    0xFA05FF00,
      N_P                 =    0xA25DFF00,
      NUM_10_PLUS         =    0xBB44FF00,
      NUM0                =    0xB946FF00,
      NUM1                =    0xF906FF00,
      NUM2                =    0xF807FF00,
      NUM3                =    0xF609FF00,
      NUM4                =    0xF50AFF00,
      NUM5                =    0xF40BFF00,
      NUM6                =    0xBF40FF00,
      NUM7                =    0xBE41FF00,
      NUM8                =    0xBD42FF00,
      NUM9                =    0xBC43FF00,
      ON_OFF              =    0xFB04FF00,
      OSD                 =    0xFE01FF00,
      PAUSE               =    0xB34CFF00,
      PBC                 =    0xA956FF00,
      PLAY                =    0xB44BFF00,
      PROG                =    0xA45BFF00,
      RANDOM              =    0xEC13FF00,
      REPEAT              =    0xA15EFF00,
      RESET               =    0xEE11FF00,
      RETURN              =    0xA55AFF00,
      REVERSE             =    0xB847FF00,
      REVERSE_SCENE       =    0xB649FF00,
      RIGHT               =    0xAC53FF00,
      RIPPING             =    0xEF10FF00,
      SETUP               =    0xB14EFF00,
      SLOW                =    0xA35CFF00,
      STOP                =    0xB24DFF00,
      SUBTITLE            =    0xA857FF00,
      TIME                =    0xFF00FF00,
      TITLE               =    0xAF50FF00,
      UP                  =    0xB04FFF00,
      VIDEO               =    0xBA45FF00,
      VOLUME_DOWN         =    0xFC03FF00,
      VOLUME_UP           =    0xFD02FF00,
      ZOOM                =    0xED12FF00,
   };

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param delay      Delay at end of sequence 1_tick = 1us
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, unsigned delay, unsigned repeat=3) {

      console.writeln("IrRemote: Teac-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::start(protocolSequence, code, 0, repeat, delay);
   }

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void test(Code code, uint8_t repeat=0) {

      console.writeln("IrRemote: Teac-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::testSequence(protocolSequence, code, 0, repeat);
   }

};

/**
 * Class to wrap CMT hardware for Samsung DVD protocol
 *
 * Samsung DVD protocol
 */
class  IrSamsungDVD : public IrRemote {

private:
   IrSamsungDVD() = delete;
   IrSamsungDVD(const IrSamsungDVD &) = delete;

   inline static const Control protocolSequence[] = {
         //       IRP: {38k,500u}<1,-1|1,-3>(9,-9,D:8,S:8,1,-9,E:4,F:8,~F:8,1,-118)+
         //
         /*      */   // Parameters
         /*      */   //=======================
         /*      */   Value(38_kHz),        // Frequency (Hz) {38k,500}
         /*      */
         /*      */   Value(1*500_ticks),   // 0 High (us) <1,-1|1,-3>
         /*      */   Value(1*500_ticks),   // 0 Low  (us)
         /*      */   Value(1*500_ticks),   // 1 High (us)
         /*      */   Value(3*500_ticks),   // 1 Low  (us)
         /*      */
         /*      */   // Start of sequence
         /*      */   //=======================
         /*      */
         /*      */   //-----------------------------------------
         /*      */   //                                         | Full Repeat
         /*      */   Repeat(0),               //                +
         /*      */      c_Epoch_Start,        //                |
         /*      */
         /*      */      //--------------------------------------
         /*      */      //                                      | Start-bit
         /*  1   */      c_MarkSpace,          //                |
         /*      */      Value(9*500_ticks),   // Start bit high | (9,-9)
         /*      */      Value(9*500_ticks),   // Start bit low  |
         /*      */
         /*      */      //--------------------------------------
         /*      */      //                                      | 16-bit Data
         /* 2-33 */      Data1(16),            //                | (D:8,S:8)
         /*      */
         /*      */      //--------------------------------------
         /*      */      //                                      | Middle-stop-bit
         /*  1   */      c_MarkSpace,          //                |
         /*      */      Value(1*500_ticks),   // Stop bit high  | (1,-9)
         /*      */      Value(9*500_ticks),   // Stop bit low   |
         /*      */
         /*      */      //--------------------------------------
         /*      */      //                                      | 20-bit Data
         /* 2-33 */      Data2(20),            //                | (E:4,F:8,~F:8)
         /*      */
         /*      */      //--------------------------------------
         /*      */      //                                      | Stop-bit
         /* 34   */      c_MarkSpace,          //                |
         /*      */      Value(1*500_ticks),   // Stop bit high  | (1,-118)
         /*      */      Value(118*500_ticks), // Stop bit low   |
         /*      */
         /*      */   Label(0),                //
         /*      */
         /* 42   */   c_End,
   };

public:
   enum Device : uint32_t {
      DVD = 0x0020,
   };

   /**
    * Common codes
    */
   enum Code : uint32_t {//     2F~2F=7
      A_B                 =    0xD7287,
      ANGLE               =    0xCC337,
      AUDIO               =    0xDA257,
      BLUE                =    0xDB247,
      DOWN                =    0xE6197,
      EJECT               =    0xFE017,
      EXIT                =    0xD42B7,
      FORWARD             =    0xEA157,
      FORWARD_SCENE       =    0xEE117,
      GREEN               =    0xDD227,
      HOME                =    0xE9167,
      INFO                =    0xE11E7,
      LEFT                =    0xE41B7,
      MENU                =    0xE21D7,
      NUM0                =    0xF40B7,
      NUM1                =    0xFD027,
      NUM2                =    0xFC037,
      NUM3                =    0xFB047,
      NUM4                =    0xFA057,
      NUM5                =    0xF9067,
      NUM6                =    0xF8077,
      NUM7                =    0xF7087,
      NUM8                =    0xF6097,
      NUM9                =    0xF50A7,
      OK                  =    0xE31C7,
      ON_OFF              =    0xFF007,
      PAUSE               =    0xCD327,
      PLAY                =    0xEB147,
      RED                 =    0xDE217,
      REPEAT              =    0xD8277,
      RETURN              =    0xE8177,
      REVERSE             =    0xED127,
      REVERSE_SCENE       =    0xF20D7,
      RIGHT               =    0xE51A7,
      SCREEN              =    0xC6397,
      STOP                =    0xEC137,
      SUBTITLE            =    0xD9267,
      TITLE_MENU          =    0xDF207,
      TOOLS               =    0xC53A7,
      UP                  =    0xE7187,
      YELLOW              =    0xDC237,
   };

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param delay      Delay at end of sequence 1_tick = 1us
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, unsigned delay, unsigned repeat=3) {

      console.writeln("IrRemote: Samsung-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::start(protocolSequence, DVD, code, repeat, delay);
   }

   /**
    * Start transmission of sequence.
    *
    * @param code          Command to send
    * @param device        Device
    * @param repeat        Number of times to repeat (excluding original). 0 => use default for protocol
    */
   static void test(Code code, Device device=DVD, unsigned repeat=0) {

      console.writeln("IrRemote: Laser-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::testSequence(protocolSequence, code, device, repeat);
   }

};

/**
 * Class to wrap CMT hardware for Samsung DVD protocol
 *
 * Samsung DVD protocol
 */
class  IrPanasonicDVD : public IrRemote {

private:

   IrPanasonicDVD() = delete;
   IrPanasonicDVD(const IrPanasonicDVD &) = delete;

   inline static const Control protocolSequence[] = {
         // IRP notation: {37k,432}<1,-1|1,-3>(8,-4,2:8,32:8,D:8,S:8,F:8,(D^S^F):8,1,-173)+ 
         //
         /*       */   // Parameters
         /*       */   //=======================
         /*       */   Value(37_kHz),        // Frequency (Hz) {37k,432}
         /*       */
         /*       */   Value(1*432_ticks),   // 0 High (us) <1,-1|1,-3>
         /*       */   Value(1*432_ticks),   // 0 Low  (us)
         /*       */   Value(1*432_ticks),   // 1 High (us)
         /*       */   Value(3*432_ticks),   // 1 Low  (us)
         /*       */
         /*       */   // Start of sequence
         /*       */   //=======================
         /*       */
         /*       */   //----------------------------------------------
         /*       */   //                                             | Full Repeat
         /*       */   Repeat(0),                 //                  +
         /*      */      c_Epoch_Start,           //                  |
         /*       */
         /*       */      //-------------------------------------------
         /*       */      //                                          | Start-bit
         /*  1    */      c_MarkSpace,            //                  |
         /*       */      Value(8*432_ticks),     // Start bit high   | (8,-4)
         /*       */      Value(4*432_ticks),     // Start bit low    |
         /*       */
         /*       */      //-------------------------------------------
         /*       */      //                                          |
         /* 2-11  */      DataImmediateLength(8), //                  | (2:8)
         /*       */      DataImmediateHigh(2),   //                  |
         /*       */      DataImmediateLow(2),    //                  |
         /*       */      //                                          |
         /* 12-21 */      DataImmediateLength(8), //                  | (32:8)
         /*       */      DataImmediateHigh(32),  //                  |
         /*       */      DataImmediateLow(32),   //                  |
         /*       */      //                                          |
         /* 22-55 */      Data1(32),              //                  | (D:8,S:8,F:8,(D^S^F):8)
         /*       */
         /*       */      //-------------------------------------------
         /*       */      //                                          | Stop-bit
         /* 56    */      c_MarkSpace,              //                |
         /*       */      Value(1*432_ticks),       // Stop bit high  + (1,-173)
         /*       */      Value(0),                 // -              |
         /*       */                                //                |
         /* 57    */      DelayHigh(173*432_ticks), // ^173           |
         /*       */      DelayLow(173*432_ticks),  //                +
         /*       */                                //
         /* 58a   */   Label(0),                    //                +
         /*       */
         /* 58b   */   c_End,
   };


public:
   enum Device : uint32_t {
      DVD = 0x0020,
   };

   /**
    * Common codes
    */
   enum Code : uint32_t {
      A_B                 =    0xF84800B0,
      AUDIO               =    0x833300B0,
      CANCEL              =    0x338300B0,
      DISPLAY             =    0x229200B0,
      DOWN                =    0x368600B0,
      EJECT               =    0xB10100B0,
      FORWARD             =    0xB50500B0,
      FORWARD_SCENE       =    0xFA4A00B0,
      LEFT                =    0x378700B0,
      MENU                =    0x308000B0,
      NUM0                =    0xA91900B0,
      NUM1                =    0xA01000B0,
      NUM10_PLUS          =    0x398900B0,
      NUM2                =    0xA11100B0,
      NUM3                =    0xA21200B0,
      NUM4                =    0xA31300B0,
      NUM5                =    0xA41400B0,
      NUM6                =    0xA51500B0,
      NUM7                =    0xA61600B0,
      NUM8                =    0xA71700B0,
      NUM9                =    0xA81800B0,
      OK                  =    0x328200B0,
      ON_OFF              =    0x8D3D00B0,
      PAUSE_PLAY          =    0xBA0A00B0,
      PROG                =    0xFD4D00B0,
      RANDOM              =    0x209000B0,
      REPEAT              =    0x3C8C00B0,
      RETURN              =    0x318100B0,
      REVERSE             =    0xB40400B0,
      REVERSE_SCENE       =    0xF94900B0,
      RIGHT               =    0x388800B0,
      SEARCH              =    0x56E600B0,
      SETUP               =    0x249400B0,
      SLOW                =    0xBF0F00B0,
      STEP                =    0xBC0C00B0,
      STOP                =    0xB00000B0,
      SUBTITLE            =    0x219100B0,
      TITLE               =    0x2B9B00B0,
      UP                  =    0x358500B0,
      USB                 =    0xB20200B0,
      USB_REC             =    0x3A8A00B0,
      ZOOM                =    0x71C100B0,

   };

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param delay      Delay at end of sequence 1_tick = 1us
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, unsigned delay, unsigned repeat=3) {

      console.writeln("IrRemote: Panasonic-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::start(protocolSequence, code, 0, repeat, delay);
   }

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void test(Code code, uint8_t repeat=0) {

      console.writeln("IrRemote: Laser-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::testSequence(protocolSequence, code, 0, repeat);
   }

};

/**
 * Class to wrap CMT hardware for Sony Bravia TV protocol
 *
 * Sony SIRC protocol
 */
class  IrSonyTV : public IrRemote {
private:

   IrSonyTV() = delete;
   IrSonyTV(const IrSonyTV &) = delete;

   inline static const Control protocolSequence[] = {
         //  Sony-12  {40k,600}<1,-1|2,-1>(4,-1,F:7,D:5,^45m)+
         //  Sony-15  {40k,600}<1,-1|2,-1>(4,-1,F:7,D:8,^45m)+
         //  Sony-20  {40k,600}<1,-1|2,-1>(4,-1,F:7,D:5,S:8,^45m)+
         //
         /*      */   // Parameters
         /*      */   //=======================
         /*      */   Value(40_kHz),        // Frequency (Hz) {40k,600}
         /*      */
         /*      */   Value(1*600_ticks),   // 0 High (us) <1,-1|2,-1>
         /*      */   Value(1*600_ticks),   // 0 Low  (us)
         /*      */   Value(2*600_ticks),   // 1 High (us)
         /*      */   Value(1*600_ticks),   // 1 Low  (us)
         /*      */
         /*      */   // Start of sequence
         /*      */   //=======================
         /*      */
         /*      */   //-----------------------------------------
         /*      */   //                                         | Full Repeat
         /*      */   Repeat(0),               //                +
         /*      */      c_Epoch_Start,        //                |
         /*      */                            //                |
         /*      */      //--------------------------------------
         /*      */      //                                      | Start-bit
         /*  1   */      c_MarkSpace,          //                |
         /*      */      Value(4*600_ticks),   // Start bit high | (4,-1)
         /*      */      Value(1*600_ticks),   // Start bit low  |
         /*      */
         /*      */      //--------------------------------------
         /*      */      //                                      | 12-bit Data/15-bit Data/20-bit Data
         /* 2-33 */      DataSony(),           //                | F:7,D:5    /F:7,D:8    /F:7,D:5,S:8
         /*      */
         /*      */      //--------------------------------------
         /*      */      //                                      | Stop
         /*      */                            //                |
         /* 35   */      DurationHigh(45000),  // ^45m           |
         /*      */      DurationLow(45000),   //                |
         /*      */                            //                |
         /*      */   Label(0),                //                +
         /*      */
         /* 42   */   c_End,
   };


public:
   /**
    * Common codes
    */
   enum Code : uint32_t {
      //                            Device  Code     // Decimal
      APPS                 = Sony15(0x1A,   0x7D),   // Sony15(26,125)
      AUDIO                = Sony12(0x01,   0x17),   // Sony12(1,23)
      BLUE                 = Sony15(0x97,   0x24),   // Sony15(151,36)
      CHANNEL_DOWN         = Sony12(0x01,   0x11),   // Sony12(1,17)
      CHANNEL_UP           = Sony12(0x01,   0x10),   // Sony12(1,16)
      DIGITAL_ANALOG       = Sony15(0x77,   0x0D),   // Sony15(119,13)
      DISCOVER             = Sony15(0x1A,   0x73),   // Sony15(26,115)
      DOWN                 = Sony12(0x01,   0x75),   // Sony12(1,117)
      FOOTBALL             = Sony15(0x1A,   0x76),   // Sony15(26,118)
      FORWARD              = Sony15(0x97,   0x1C),   // Sony15(151,28)
      GREEN                = Sony15(0x97,   0x26),   // Sony15(151,38)
      GUIDE                = Sony15(0xA4,   0x5B),   // Sony15(164,91)
      HELP                 = Sony15(0x1A,   0x7B),   // Sony15(26,123)
      HOME                 = Sony12(0x01,   0x60),   // Sony12(1,96)
      I_PLUS               = Sony12(0x01,   0x3A),   // Sony12(1,58)
      LEFT                 = Sony12(0x01,   0x34),   // Sony12(1,52)
      MUTE                 = Sony12(0x01,   0x14),   // Sony12(1,20)
      NUM0                 = Sony12(0x01,   0x09),   // Sony12(1,9)
      NUM1                 = Sony12(0x01,   0x00),   // Sony12(1,0)
      NUM2                 = Sony12(0x01,   0x01),   // Sony12(1,1)
      NUM3                 = Sony12(0x01,   0x02),   // Sony12(1,2)
      NUM4                 = Sony12(0x01,   0x03),   // Sony12(1,3)
      NUM5                 = Sony12(0x01,   0x04),   // Sony12(1,4)
      NUM6                 = Sony12(0x01,   0x05),   // Sony12(1,5)
      NUM7                 = Sony12(0x01,   0x06),   // Sony12(1,6)
      NUM8                 = Sony12(0x01,   0x07),   // Sony12(1,7)
      NUM9                 = Sony12(0x01,   0x08),   // Sony12(1,8)
      OK                   = Sony12(0x01,   0x65),   // Sony12(1,101)
      ON_OFF               = Sony12(0x01,   0x15),   // Sony12(1,21)
      ON                   = Sony12(0x01,   0x2E),   // Sony12(1,46)
      OFF                  = Sony12(0x01,   0x2F),   // Sony12(1,47)
      OPTIONS              = Sony15(0x97,   0x36),   // Sony15(151,54)
      PAUSE                = Sony15(0x97,   0x19),   // Sony15(151,25)
      PLAY                 = Sony15(0x97,   0x1A),   // Sony15(151,26)
      RECORD               = Sony15(0x97,   0x20),   // Sony15(151,32)
      RED                  = Sony15(0x97,   0x25),   // Sony15(151,37)
      RELATED_SEARCH       = Sony15(0x1A,   0x7E),   // Sony15(26,126)
      RETURN               = Sony15(0x97,   0x23),   // Sony15(151,35)
      REVERSE              = Sony15(0x97,   0x1B),   // Sony15(151,27)
      RIGHT                = Sony12(0x01,   0x33),   // Sony12(1,51)
      SOCIAL_VIEW          = Sony15(0x1A,   0x74),   // Sony15(26,116)
      SOURCE               = Sony12(0x01,   0x25),   // Sony12(1,37)   // Source menu
      SOURCE_TV            = Sony12(0x01,   0x24),   // Sony12(1,36)
      SOURCE_HDMI_1        = Sony15(0x1A,   0x5a),   // Sony15(26,90)
      SOURCE_HDMI_2        = Sony15(0x1A,   0x5b),   // Sony15(26,91)
      SOURCE_HDMI_3        = Sony15(0x1A,   0x5c),   // Sony15(26,92)
      SOURCE_HDMI_4        = Sony15(0x1A,   0x5d),   // Sony15(26,93)
      SOURCE_HDMI_5        = Sony15(0x1A,   0x5e),   // Sony15(26,94)
      SOURCE_Video_1       = Sony12(0x01,   0x40),   // Sony12(1,64)
      SOURCE_Video_2       = Sony12(0x01,   0x41),   // Sony12(1,65)    // Composite
//      SOURCE_3             = Sony12(0x01,   0x42),   // Sony12(1,66) Maybe?
//      SOURCE_4             = Sony12(0x01,   0x47),   // Sony12(1,71) Maybe?
//      SOURCE_5             = Sony12(0x01,   0x48),   // Sony12(1,72) Maybe?
//      SOURCE_6             = Sony12(0x01,   0x49),   // Sony12(1,73) Maybe?
//      SOURCE_RGB1          = Sony12(0x01,   0x43),   // Sony12(1,67) Maybe?
//      SOURCE_RGB2          = Sony12(0x01,   0x44),   // Sony12(1,68) Maybe?
      STANDBY              = Sony15(0x01,   0x2F),   // Sony15(1,47) Maybe?
      STOP                 = Sony15(0x97,   0x18),   // Sony15(151,24)
      SWAP                 = Sony12(0x01,   0x3B),   // Sony12(1,59)
      SYNC_MENU            = Sony15(0x1A,   0x58),   // Sony15(26,88)
      TITLE                = Sony15(0x1A,   0x65),   // Sony15(26,101)
      TV_PAUSE             = Sony15(0x1A,   0x67),   // Sony15(26,103)
      UNKNOWN              = Sony15(0x97,   0x28),   // Sony15(151,40)
      UP                   = Sony12(0x01,   0x74),   // Sony12(1,116)
      VOLUME_DOWN          = Sony12(0x01,   0x13),   // Sony12(1,19)
      VOLUME_UP            = Sony12(0x01,   0x12),   // Sony12(1,18)
      YELLOW               = Sony15(0x97,   0x27),   // Sony15(151,39)
};

   enum Address {
      tv             = 1,
      vcr1           = 2,
      teletext       = 3,
      widescreen     = 4,
      laserDisk      = 6,
      vcr2           = 7,
      vcr3           = 11,
      surroundSound  = 12,
      cassette       = 16,
      cdPlayer       = 17,
      equalizer      = 18,
      dvd            = 26,
      //   TV_Digital_Effects_15_bit            = 0xA4   ,
      //   PlayStation_2_DVD_20_bit             = 0x093A ,
      //   PlayStation_2_PS2_20_bit             = 0x1B5A ,
   };

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param delay      Delay at end of sequence 1_tick = 1us
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, unsigned delay, unsigned repeat=3) {

      console.writeln("IrRemote: Sony-TV: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::start(protocolSequence, code, 0, repeat, delay);
   }

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeat     Number of times to repeat (including original). 0 => use default for protocol
    */
   static void test(Code code, uint8_t repeat=0) {

      console.writeln("IrRemote: Laser-DVD: 0x", code, Radix_16);

      if (repeat == 0) {
         repeat = 3;
      }
      IrRemote::testSequence(protocolSequence, code, 0, repeat);
   }

};

} // End namespace USBDM
