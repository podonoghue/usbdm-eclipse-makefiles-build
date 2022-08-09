/**
 ============================================================================
 * @file    can-mailbox-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using FlexCAN mailboxes
 *
 *  Created on: 5 Aug, 2022
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "can.h"
#include "ftm.h"
#include "adc.h"
#include "pit.h"
#include "system.h"

using namespace USBDM;

// CAN interface to use
using Can     = Can0;
using CanLimp = GpioE<13, ActiveLow>;

/**
 * Interface for the RGB LEDs
 */
class Leds {
private:
   using Pwm = Ftm0;

   using RGB_Red   = RedLED_PWM;
   using RGB_Green = GreenLED_PWM;
   using RGB_Blue  = BlueLED_PWM;

   bool     redOn;
   bool     greenOn;
   bool     blueOn;
   int      intensity;

   void update() {
      RGB_Red::setDutyCycle(redOn?intensity:0);
      RGB_Green::setDutyCycle(greenOn?intensity:0);
      RGB_Blue::setDutyCycle(blueOn?intensity:0);
   }

public:
   Leds() : redOn(false), greenOn(false), blueOn(false), intensity(255) {
      Pwm::configure(FtmMode_LeftAlign, FtmClockSource_Default);
      Pwm::setPeriod(1_ms);
      RGB_Red::configure(FtmChMode_PwmLowTruePulses, FtmChannelAction_None);
      RGB_Red::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);
      RGB_Green::configure(FtmChMode_PwmLowTruePulses, FtmChannelAction_None);
      RGB_Green::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);
      RGB_Blue::configure(FtmChMode_PwmLowTruePulses, FtmChannelAction_None);
      RGB_Blue::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);
      update();
   }

   /**
    * Enable/disable the three LED colours
    *
    * @param red
    * @param green
    * @param blue
    */
   void setRgb(bool red, bool green, bool blue) {
      redOn    = red;
      greenOn  = green;
      blueOn   = blue;
      update();
   }

   /**
    * Set the intensity of any enabled LEDs
    *
    * @param intensity Percentage
    */
   void setItensity(unsigned intensity) {
      if (intensity > 100) {
         intensity = 100;
      }
      this->intensity = intensity;
      update();
   }
};

/**
 * Interface for the two switches
 * These are debounced using a timer callback.
 */
class Switches {
   using Switch2   = GpioC<12, ActiveLow>;
   using Switch3   = GpioC<13, ActiveLow>;
   using Tmr       = Pit;

   static unsigned switchValue;

   static void callback() {
      static unsigned debounceCounter = 0;
      static unsigned lastSwitchValue = 0;

      unsigned currentSwitches = (Switch3::read()<<1)|(Switch2::read()<<0);
      if (currentSwitches != lastSwitchValue) {
         lastSwitchValue = currentSwitches;
         debounceCounter = 0;
         return;
      }
      debounceCounter ++;
      if (debounceCounter == 5) {
         switchValue = currentSwitches;
      }
   }

public:
   /**
    * Get and clear the button state
    *
    *  @return A 2-bit number representing the two buttons.
    */
   unsigned getValue() {
      CriticalSection cs;
      unsigned temp = switchValue ;
      switchValue = 0;
      return temp;
   }

   Switches() {
      Switch2::setInput(PinPull_Up, PinAction_None, PinFilter_Passive);
      Switch3::setInput(PinPull_Up, PinAction_None, PinFilter_Passive);

      Tmr::configure();

      PitChannelNum tmrChannel = Tmr::allocateChannel();
      Tmr::setCallback(tmrChannel, callback);
      Tmr::configureChannel(tmrChannel, 5_ms, PitChannelIrq_Enabled);
      Tmr::enableNvicInterrupts(tmrChannel, NvicPriority_Normal);
      Tmr::enableInterrupts(tmrChannel);
   }
};
unsigned Switches::switchValue     = 0;

/**
 * Interface for the Potentiometer
 */
class Potentiometer {
   using Adc = Adc0;
   using Pot = Adc::Channel<12>;

public:
   Potentiometer() {
      Adc::configure(AdcResolution_8bit_se);
      Adc::calibrate();
   }

   /**
    * Read the position of the Pot as a number in the range 0-255
    *
    * @return Pot position
    */
   unsigned readValue() {
      return Pot::readAnalogue();
   }
};

Leds           leds;
Switches       switches;
Potentiometer  potentiometer;

#if 1
/**
 * Message IDs for Node A
 */
static constexpr unsigned LED_ON_OFF_MAILBOX_ID_NODE_TX     = 30;
static constexpr unsigned LED_INTENSITY_MAILBOX_ID_NODE_TX  = 31;
static constexpr unsigned LED_ON_OFF_MAILBOX_ID_NODE_RX     = 40;
static constexpr unsigned LED_INTENSITY_MAILBOX_ID_NODE_RX  = 41;
#else
/**
 * Message IDs for Node B
 */
static constexpr unsigned LED_ON_OFF_MAILBOX_ID_NODE_TX     = 40;
static constexpr unsigned LED_INTENSITY_MAILBOX_ID_NODE_TX  = 41;
static constexpr unsigned LED_ON_OFF_MAILBOX_ID_NODE_RX     = 30;
static constexpr unsigned LED_INTENSITY_MAILBOX_ID_NODE_RX  = 31;
#endif

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
   console.writeln("\n                                         O BSTR10ACFSTRITFFRBE");
   console.writeln(  "                                         V OYxxEECRRTxxDxLLxOR");
   console.writeln(  "                                         R FNWWRRKCMFEEL TT FR");
   console.write(    "canErrorCallback(), status = 0b").write(status, Radix_2).writeln();
   console.writeln(  "                               10987654321098765432109876543210");
   console.resetFormat();
}

void canWakeupCallback() {
   console.writeln("canWakeupCallback()");
}

/**
 * Transmit mailbox interrupt handler
 *
 * @param mailboxNum NUmber of mailbox causing the interrupt
 */
void canTxMailboxCallback(unsigned mailboxNum) {
//   auto mailbox = Can::getMailbox(mailboxNum);
//   console.write("canTxMailboxCallback() - Tx ");
//   printMessageBuffer(mailbox);
   Can::clearMailboxFlag(mailboxNum);
}

/**
 * Receive mailbox interrupt handler
 *
 * @param mailboxNum Number of mailbox causing the interrupt
 */
void ledIntensityCallback(unsigned mailboxNum) {
   auto mailbox = Can::getMailbox(mailboxNum);

   // Reinitialise mailbox
   mailbox->CS = CanControlStatus(CanMessageCode_RxEmpty, CanFrameType_Remote);
   leds.setItensity(mailbox->data8(0));
   Can::clearMailboxFlag(mailboxNum);
}

/**
 * Receive mailbox interrupt handler
 *
 * @param mailboxNum NUmber of mailbox causing the interrupt
 */
void ledOnOffCallback(unsigned mailboxNum) {
   auto mailbox = Can::getMailbox(mailboxNum);
   unsigned rgbValue = mailbox->data8(0);

   // Reinitialise mailbox
   mailbox->CS = CanControlStatus(CanMessageCode_RxEmpty, CanFrameType_Remote);
   leds.setRgb(rgbValue&(1<<2), rgbValue&(1<<1), rgbValue&(1<<0));
   Can::clearMailboxFlag(mailboxNum);
}

/**
 * This example sets up the CAN to transmit and receive messages using mailboxes
 */
void mailboxOnlyExample() {

//   usbdm_assert(!Can::FIFO_AVAILABLE, "This example assumes no FIFO is configured");
   usbdm_assert(Can::NUM_MAILBOXES>=3, "This example requires > 3 mailboxes");

   Can::CanParameters canParameters(125000);
   canParameters.idam      = CanAcceptanceMode_FormatA;
   canParameters.wrnen     = true;
   canParameters.errmsk    = true;
   //   canParameters.lpb       = true;

   Can::setErrorCallback(canErrorCallback);
   Can::setWakeupCallback(canWakeupCallback);
   Can::configure(canParameters);

   Can::configureAllPins();

   // Enable all interrupts from FIFO
   Can::enableFifoInterrupts(CAN_FIFO_DATA_FLAG|CAN_FIFO_OVERFLOW_FLAG|CAN_FIFO_WARNING_FLAG);

   Can::enableErrorNvicInterrupts(NvicPriority_Normal);
//   Can::enableWakeupNvicInterrupts(NvicPriority_Normal);
   Can::enableMessageBufferNvicInterrupts(NvicPriority_Normal);

   Can::enableMiscellaneousNvicInterrupts(NvicPriority_Normal);

   static auto txMailbox1 = Can::allocateMailbox();
   txMailbox1.setCallback(canTxMailboxCallback);
   txMailbox1.enableInterrupt();
   auto & canTxMailbox1 = txMailbox1.getMailbox();
   canTxMailbox1.ID = CanId(CAN_MODE, LED_ON_OFF_MAILBOX_ID_NODE_TX);
   canTxMailbox1.CS = CanControlStatus(CanMessageCode_TxInactive, CanFrameType_Data);

   static auto txMailbox2 = Can::allocateMailbox();
   txMailbox2.setCallback(canTxMailboxCallback);
   txMailbox2.enableInterrupt();
   auto & canTxMailbox2 = txMailbox2.getMailbox();
   canTxMailbox2.ID = CanId(CAN_MODE, LED_INTENSITY_MAILBOX_ID_NODE_TX);
   canTxMailbox2.CS = CanControlStatus(CanMessageCode_TxInactive, CanFrameType_Data);

   static auto rxMailbox1 = Can::allocateMailbox();
   rxMailbox1.setCallback(ledIntensityCallback);
   auto & canRxMailbox1 = rxMailbox1.getMailbox();
   canRxMailbox1.ID = CanId(CAN_MODE, LED_INTENSITY_MAILBOX_ID_NODE_RX);
   canRxMailbox1.CS = CanControlStatus(CanMessageCode_RxEmpty, CanFrameType_Remote);
   rxMailbox1.enableInterrupt();

   static auto rxMailbox2 = Can::allocateMailbox();
   rxMailbox2.setCallback(ledOnOffCallback);
   auto & canRxMailbox2 = rxMailbox2.getMailbox();
   canRxMailbox2.ID = CanId(CAN_MODE, LED_ON_OFF_MAILBOX_ID_NODE_RX);
   canRxMailbox2.CS = CanControlStatus(CanMessageCode_RxEmpty, CanFrameType_Remote);
   rxMailbox2.enableInterrupt();

   Can::start();

   Can::readTimer();


   // This loop monitors the transmit buffers and fills them at min 100 ms intervals
   for(;;) {
      waitMS(100);
      if (canTxMailbox1.CS.code == CanMessageCode_TxInactive) {
         static unsigned ledValue = 0b010;
         unsigned switchValue = switches.getValue();
         switch (switchValue) {
            case 0b00: // No press
               break;
            case 0b01: //
               ledValue <<= 1;
               if ((ledValue&0b111) ==0) {
                  ledValue = 0b001;
               }
               break;
            case 0b10:
               ledValue >>= 1;
               if ((ledValue&0b111) ==0) {
                  ledValue = 0b100;
               }
               break;
            case 0b11: // Ignore multiple
               break;
            default:
               break;
         }
         canTxMailbox1.data8(0) = ledValue;
         canTxMailbox1.CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_1, CanFrameType_Data);
      }
      if (canTxMailbox2.CS.code == CanMessageCode_TxInactive) {
         canTxMailbox2.data8(0) = potentiometer.readValue();
         canTxMailbox2.CS = CanControlStatus(CanMessageCode_TxData, CAN_MODE, CanDataSize_1, CanFrameType_Data);
      }
      CanErrorCounts canErrorCounts = Can::getErrorCounters();
      if ((canErrorCounts.receiveErrorCount > 0) || (canErrorCounts.transmitFastErrorCount > 0)) {
         console.writeln("receiveErrorCount  = ", canErrorCounts.receiveErrorCount);
         console.writeln(", transmitErrorCount = ", canErrorCounts.transmitErrorCount);
      }
   }
}

int main() {
   console.writeln("\n\nStarting");

   CanLimp::setInput();
   console.write("CAN Limp mode is ", CanLimp::read()?"Active":"Inactive");

   mailboxOnlyExample();

   return 0;
}
