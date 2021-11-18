/**
 ==========================================================================================
 * @file    flexio-uart-example.cpp (180.ARM_Peripherals/Sources/flexio-uart-example.cpp)
 * @brief   Basic demonstration using Flexio to implement a UART
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 *
 *      To use this example you need to define two Flexio pins UartTx and UartRx
 ==========================================================================================
 */
#include "hardware.h"
#include "stringFormatter.h"

using namespace USBDM;

/**
 *   UART Transmitter
 *   From K28F Reference Manual K28P210M150SF5RM
 *
 * @tparam flexioShifterSelect Shifter to use
 * @tparam flexioTimerSelect   Timer to use
 * @tparam flexioPinSel        Pin to use for transmit data
 *
 * @note This class extends FormattedIO for convenience
 */
template <FlexioShifterSelect flexioShifterSelect, FlexioTimerSelect flexioTimerSelect, FlexioPinSel flexioPinSel>
class FlexioUartTransmitter : public FormattedIO {
private:
   /**
    * This class is not intended to be instantiated by copy
    */
   FlexioUartTransmitter(const FlexioUartTransmitter&) = delete;
   FlexioUartTransmitter(FlexioUartTransmitter&&) = delete;

   static FlexioBase_T<FlexioInfo> flexio;

public:
   constexpr FlexioUartTransmitter() = default;

   // Start-bit=0, Stop-bit=1, shift 1 bit 0x0000_0032
   static constexpr uint32_t TX_SHIFTER_CONFIG_VALUE =
         flexio.makeShifterConfigValue(
               FlexioStartBit_0,
               FlexioStopBit_1,
               FlexioShiftBy_1);

   // Transmit, timer flexioTimerSelect, shifter flexioShifterSelect, output on pin flexioPinSel 0x0003_0002
   static constexpr uint32_t TX_SHIFTER_CONTROL_VALUE =
         flexio.makeShifterControlValue(
               FlexioShiftMode_Transmit,
               flexioTimerSelect,
               FlexioPinAction_Output,
               flexioPinSel);

   // Configure start bit, stop bit, enable on trigger high and disable on compare. 0x0000_2222
   // Can support CTS by configuring FlexioTimerEnable_OnTriggerHighandPinHigh.
   static constexpr uint32_t TX_TIMER_CONFIG_VALUE =
         flexio.makeTimerConfigValue(
               FlexioTimerEnable_OnTriggerHigh,
               FlexioTimerDisable_OnTimerCompare,
               FlexioTimerReset_Never,
               FlexioTimerStartBit_Enabled,
               FlexioTimerStopBit_EnabledOnTimerDisable,
               FlexioTimerDec_OnFlexioClock_ShiftOnTimerInput,
               FlexioTimerOutput_1_WhenEnabled);

   // Configure dual 8-bit counter using Shifter status flag as inverted internal trigger source. 0x01C0_0001
   // Can support CTS by configuring FlexioPinSel_1 and FlexioPinPolarity_ActiveHigh.
   static constexpr uint32_t TX_TIMER_CONTROL_VALUE =
         flexio.makeTimerControlValue(
               FlexioTimerMode_BaudBit,
               flexioTriggerSel(FlexioTriggerModify_ShifterN_status, flexioShifterSelect),
               FlexioTriggerPolarity_ActiveLow,
               FlexioPinAction_Disabled,
               flexioPinSel,
               FlexioPinPolarity_ActiveHigh);

   static void config(uint32_t baudRate) {
      flexio.setShifterConfig(flexioShifterSelect, TX_SHIFTER_CONFIG_VALUE);
      flexio.setShifterControl(flexioShifterSelect, TX_SHIFTER_CONTROL_VALUE);
      // Configure 8-bit transfer with baud rate of baudRate
      flexio.setTimerCompareValue(flexioTimerSelect, 8, baudRate);
      flexio.setTimerConfig(flexioTimerSelect, TX_TIMER_CONFIG_VALUE);
      flexio.setTimerControl(flexioTimerSelect, TX_TIMER_CONTROL_VALUE);
   }

   virtual FlexioUartTransmitter& flushOutput() override {
      // Wait for transmitter buffer empty
      while((flexio.readShifterStatus()&(1<<flexioShifterSelect)) == 0) {
         __asm__("nop");
      }
      return *this;
   }

protected:
   virtual void _writeChar(char ch) override {
      // Wait for transmitter buffer empty
      flushOutput();
      // Write data (and clear status flag)
      flexio.writeShifterBuffer(flexioShifterSelect, ch);
   }
};

/**
 *   UART Transmitter
 *   From K28F Reference Manual K28P210M150SF5RM
 *
 * @tparam flexioShifterSelect Shifter to use
 * @tparam flexioTimerSelect   Timer to use
 * @tparam flexioPinSel        Pin to use for transmit data
 *
 * @note This class extends FormattedIO for convenience
 */
template <FlexioShifterSelect flexioShifterSelect, FlexioTimerSelect flexioTimerSelect, FlexioPinSel flexioPinSel>
class FlexioUartReceiver : public FormattedIO {
private:
   /**
    * This class is not intended to be instantiated by copy
    */
   FlexioUartReceiver(const FlexioUartReceiver&) = delete;
   FlexioUartReceiver(FlexioUartReceiver&&) = delete;

   static FlexioBase_T<FlexioInfo> flexio;

public:
   FlexioUartReceiver() = default;

   // Start-bit=0, Stop-bit=1, shift 1 bit 0x0000_0032
   static constexpr uint32_t RX_SHIFTER_CONFIG_VALUE =
   flexio.makeShifterConfigValue(
         FlexioStartBit_0,
         FlexioStopBit_1,
         FlexioShiftBy_1);

   // Transmit, timer flexioTimerSelect, shifter flexioShifterSelect, -ve edge clock, input on pin flexioPinSel 0x0080_0001
   static constexpr uint32_t RX_SHIFTER_CONTROL_VALUE =
   flexio.makeShifterControlValue(
         FlexioShiftMode_Receive,
         flexioTimerSelect,
         FlexioPinAction_Disabled,
         flexioPinSel,
         FlexioTimerEdge_Falling,
         FlexioPinPolarity_ActiveHigh);

   // Configure start bit, stop bit, enable on pin positive-edge and disable on compare. timer-out=2, reset=4 0x0204_2422
   // Can support CTS by configuring FlexioTimerEnable_OnTriggerHighandPinHigh.
   static constexpr uint32_t RX_TIMER_CONFIG_VALUE =
   flexio.makeTimerConfigValue(
         FlexioTimerEnable_OnPinRising,
         FlexioTimerDisable_OnTimerCompare,
         FlexioTimerReset_TimerPinRising,
         FlexioTimerStartBit_Enabled,
         FlexioTimerStopBit_EnabledOnTimerDisable,
         FlexioTimerDec_OnFlexioClock_ShiftOnTimerInput,
         FlexioTimerOutput_1_WhenEnabledOrReset);

   // Configure dual 8-bit counter using inverted pin 0 input. 0x0000_0081
   static constexpr uint32_t RX_TIMER_CONTROL_VALUE =
   flexio.makeTimerControlValue(
         FlexioTimerMode_BaudBit,
         FlexioTriggerSel_External0,
         FlexioTriggerPolarity_ActiveHigh,
         FlexioPinAction_Disabled,
         flexioPinSel,
         FlexioPinPolarity_ActiveLow);

   static void config(uint32_t baudRate) {
      flexio.setShifterConfig(flexioShifterSelect, RX_SHIFTER_CONFIG_VALUE);
      flexio.setShifterControl(flexioShifterSelect, RX_SHIFTER_CONTROL_VALUE);
      // Configure 8-bit transfer with baud rate of baudRate
      flexio.setTimerCompareValue(flexioTimerSelect, 8, baudRate);
      flexio.setTimerConfig(flexioTimerSelect, RX_TIMER_CONFIG_VALUE);
      flexio.setTimerControl(flexioTimerSelect, RX_TIMER_CONTROL_VALUE);
   }

protected:
   virtual int _readChar() override {
      // Wait for receive data
      while((flexio.readShifterStatus()&(1<<flexioShifterSelect)) == 0) {
         __asm__("nop");
      }
      // Read data (and clear status flag)
      return flexio.readShifterBuffer(flexioShifterSelect);
   }

   virtual bool _isCharAvailable() override {
      return (flexio.readShifterStatus()&(1<<flexioShifterSelect)) != 0;
   }
};

static FlexioUartTransmitter<FlexioShifterSelect_6, FlexioTimerSelect_2, FlexioPinSel_UartTx> txUart;
static FlexioUartReceiver<FlexioShifterSelect_1, FlexioTimerSelect_1, FlexioPinSel_UartRx>    rxUart;

int main() {
   console.writeln("Starting\n");

   // Need to use a slower FLEXIO clock to obtain the baud rate wanted
   SimInfo::setFlexioClock(SimFlexioClockSource_OscerClk);

   myFlexio.configure();
   myFlexio.configureAllPins();

   rxUart.config(defaultBaudRate);
   txUart.config(defaultBaudRate);

   for(;;) {
      txUart.writeln("Hello World");
      waitMS(1);
//      char buffer[100];
//      rxUart.gets(buffer);
   }
   return 0;
}
