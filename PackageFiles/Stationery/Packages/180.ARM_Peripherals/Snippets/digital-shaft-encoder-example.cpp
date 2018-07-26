/**
 ============================================================================
 * @file    digital-shaft-encoder-example.cpp (180.ARM_Peripherals/Snippets/)
 * @brief   Basic C++ demo of GPIO interrupts.
 *
 *  Created on: 26/7/2018
 *      Author: podonoghue
 ============================================================================
 */
/**
 * This example uses GPIO interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->GPIOx tab.
 * Select irqHandlers option (Class Method - Software ...)
 */
#include "hardware.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// GPIOs as a field - this assumes consecutive pins on same port
using PhotoDetector = GpioCField<1, 0, ActiveHigh>;

// Variable used by callback to track shaft position
static volatile int position;

/**
 * Pin IRQ call-back.
 * Used to monitor shaft movements
 *
 * @param eventMask Mask indicating active channel
 */
void pinIrqCallback(uint32_t eventMask) {
   // State change matrix: motion[lastState][currentState] -> movement value
   // Expected sequence 00<->10<->01<->11<->00
   static const int8_t motion[4][4] = {
         /* last : current -> 00  01  10  11 */
         /*  00 */          {  0, -1, +1,  0 },
         /*  01 */          { +1,  0,  0, -1 },
         /*  10 */          { -1,  0,  0, +1 },
         /*  11 */          {  0, +1, -1,  0 },
   };

   static uint32_t lastState = 0;

   // Check channel
   if (eventMask && PhotoDetector::MASK) {
      // Use change of state of GPIOs to determine rotation (if any)
      uint32_t currentState = PhotoDetector::read();
      position += motion[lastState][currentState];
      lastState = currentState;
   }
}

/**
 * Enable shaft encoder.
 *
 * Enables encoder interrupts and does any other initialisation required.
 */
void startEncoder() {

   // Start position at zero
   position = 0;

   // Configure Photo-detectors as inputs with dual-edge interrupts
   PhotoDetector::setCallback(pinIrqCallback);
   PhotoDetector::setInput(PinPull_Up, PinAction_IrqEither, PinFilter_Passive);
   PhotoDetector::enableNvicInterrupts();
}

/**
 *  Disables shaft encoder.
 */
void stopEncoder() {
   PhotoDetector::setInput(PinPull_None, PinAction_None);
   PhotoDetector::enableNvicInterrupts(false);
}

/**
 * Returns the shaft position.
 */
int shaftPosition() {
   return position;
}

int main() {
   startEncoder();

   int lastMeasurement    = 0;
   int currentMeasurement = 0;

   for(;;) {
      // Only print when changing
      lastMeasurement    = currentMeasurement;
      currentMeasurement = shaftPosition();
      if (currentMeasurement != lastMeasurement) {
         console.write("Position = ").writeln(currentMeasurement);
      }
   }
}
