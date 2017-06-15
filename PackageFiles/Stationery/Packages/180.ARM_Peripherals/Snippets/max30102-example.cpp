/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include <algorithm>
#include "cmsis.h"
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "max30102.h"
#include "max30102-example.h"
#include "SpO2algorithm.h"

static constexpr uint32_t SAMPLE_SIGNAL = (1<<0);
static constexpr uint32_t PROCESS_BLOCK = (1<<0);

// LED connection - change as required
using RedLed    = USBDM::gpio_LED_RED;
using BlueLed   = USBDM::gpio_LED_BLUE;
using GreenLed  = USBDM::gpio_LED_GREEN;

using IrqPin    = USBDM::GpioD<5>;
static_assert(USBDM::GpioDInfo::irqHandlerInstalled, "Irq Handler must be installed");

CMSIS::Thread mainThread(CMSIS::Thread::getMyId());

USBDM::I2c0 i2c;
USBDM::MAX30102 spo2Sensor(i2c);

using Strobe = USBDM::GpioE<1>;

/** Circular buffer for samples */
CircularBuffer<500,100,Pair> buffer;

/**
 * Thread to handle retrieving a sample from the sensor and saving in
 * the buffer.
 * It also handles triggering of processing when there is sufficient new data
 */
class SampleProcessor : public CMSIS::ThreadClass {
   // Simple state machine
   enum State {
      filling,    // Waiting for initial N samples
      working,    // Waiting for additional N/4 samples
   };
   State state = filling;

public:
   /*
    * Constructor
    * Thread runs at higher priority but spends most of its time sleeping
    */
   SampleProcessor() : ThreadClass(osPriorityAboveNormal) {
   }

private:
   /**
    * Actual thread
    * Mostly:
    * - Waits for signal
    * - Retrieves samples from sensor
    * - Saves to buffer
    * - Trigger processing when sufficient (new) data
    */
   virtual void task() override {
      for(;;) {
         CMSIS::Thread::signalWait(SAMPLE_SIGNAL);

         // Save sample to buffer
         Pair reading;
         spo2Sensor.readLeds(reading.redLed, reading.irLed);
         buffer.push(reading);
         switch(state) {
            case filling :
               Strobe::low();
               if (buffer.workingBufferAvailable()) {
                  // Working area has filled
                  Strobe::toggle();
                  state = working;
               }
               break;
            case working :
               if (buffer.isFull()) {
                  // New data to process
                  Strobe::toggle();
                  buffer.advance();
                  mainThread.signalSet(PROCESS_BLOCK);
               }
               break;
         }
      }
   }
};
/** IRQ driven thread */
SampleProcessor sampleProcessor;

/**
 * IRQ handler for sensor interrupt pin
 * Just signals the sampleProcessor thread
 */
static void callback(uint32_t status) {
   // Check IRQ from correct pin
   if (status&IrqPin::MASK) {
      // Signal thread to process sample
      sampleProcessor.signalSet(SAMPLE_SIGNAL);
   }
};

int main() {
   using namespace USBDM;

   printf("Starting\n");

   RedLed::setOutput();
   BlueLed::setOutput();
   GreenLed::setOutput();
   RedLed::high();
   BlueLed::high();
   GreenLed::high();

   Strobe::setOutput();

   IrqPin::setInput(pcrValue(PinPullUp, PinDriveLow, PinOpenCollector));
   IrqPin::setCallback(callback);
   IrqPin::setIrq(PinIrqFalling);
   IrqPin::enableNvicInterrupts();

   sampleProcessor.run();
   spo2Sensor.startSpo2();

   int count = 0;
   for(;;) {
      CMSIS::Thread::signalWait(PROCESS_BLOCK);
      printf("Buffer Processing\n");

      uint32_t  spo2;
      bool      spo2Valid;
      uint32_t  heartRate;
      bool      heartRateValid;
      maxim_heart_rate_and_oxygen_saturation(spo2, spo2Valid, heartRate, heartRateValid);
      printf("%d:Buffer Processing - %s:%ld, %s:%ld\n", count++, spo2Valid?"OK":"Fail", spo2, heartRateValid?"OK":"Fail", heartRate);
   }
   return 0;
}
