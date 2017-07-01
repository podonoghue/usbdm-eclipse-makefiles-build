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
#include "SpO2algorithm.h"

static constexpr uint32_t SAMPLE_SIGNAL = (1<<0);
static constexpr uint32_t PROCESS_BLOCK = (1<<0);

/** LED connection - change as required */
using RedLed    = USBDM::gpio_LED_RED;
using BlueLed   = USBDM::gpio_LED_BLUE;
using GreenLed  = USBDM::gpio_LED_GREEN;

/** Access to main thread */
CMSIS::Thread mainThread(CMSIS::Thread::getMyId());

/** I2c interface to use */
USBDM::I2c0     i2c;

/** MAX30102 IRQ pin */
using Max30102IrqPin = USBDM::GpioD<5>;
static_assert(Max30102IrqPin::irqHandlerInstalled, "Irq Handler must be installed for this port");

/** MAX30102 connected via I2c and using D5 as Irq pin */
USBDM::MAX30102<Max30102IrqPin> spo2Sensor(i2c);

/** Circular buffer for samples */
static Spo2Buffer spo2Buffer;

/** Debug - check timing */
using Strobe = USBDM::GpioE<1>;

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

   using Strobe = USBDM::GpioE<1>;


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
      Strobe::low();

      for(;;) {
         CMSIS::Thread::signalWait(SAMPLE_SIGNAL);

         // Save sample to buffer
         Pair reading;
         spo2Sensor.readLeds(reading.redLed, reading.irLed);
         spo2Buffer.push(reading);
         switch(state) {
            case filling :
               if (spo2Buffer.count() < BUFFER_SIZE) {
                  // Still filling
                  break;
               }
               // Working area has filled
               state = working;
               /* no break */
            case working :
               if (spo2Buffer.count() == BUFFER_SIZE) {
                  // New set of data to process
                  mainThread.signalSet(PROCESS_BLOCK);
               }
               else if (spo2Buffer.count() == BUFFER_SIZE+BUFFER_MARGIN) {
                  // Buffer should have been processed by now - discard some old data
                  spo2Buffer.advance(UPDATE_INTERVAL);
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
static void callback(uint32_t /* status */) {
   // Check IRQ from correct pin
//   if (status&IrqPin::MASK) {
      // Signal thread to process sample
      sampleProcessor.signalSet(SAMPLE_SIGNAL);
//   }
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

   sampleProcessor.run();
   spo2Sensor.configureInterrupts(callback);
   spo2Sensor.startSpo2();

   printf("Done initialisation\n");

   int count = 0;
   for(;;) {
      // Wait until data accumulates
      CMSIS::Thread::signalWait(PROCESS_BLOCK);

      // Process and report data
      Strobe::high();
      int    spo2,      heartRate;
      bool   spo2Valid, heartRateValid;
      maxim_heart_rate_and_oxygen_saturation(spo2Buffer, spo2, spo2Valid, heartRate, heartRateValid);
      Strobe::low();

      printf("%d:Buffer Processed - SpO2=%4d:%s, Pulse=:%4d:%s\n", count++, spo2, spo2Valid?"OK  ":"Fail", heartRate, heartRateValid?"OK  ":"Fail");
   }
   return 0;
}
