/*
 ============================================================================
 * @file    tsi-mk-example.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo using TSI class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include <algorithm>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "tsi.h"

using namespace USBDM;

// LED connections - change as required
using LedA = USBDM::GpioA<2,ActiveLow>;
using LedB = USBDM::GpioC<3,ActiveLow>;

using MeasurementPin = USBDM::GpioE<1>;

// TSI electrodes to use
constexpr uint32_t electrodeA = 11;
constexpr uint32_t electrodeB = 12;

/*
 * Flag used to communicate between ISR and foreground task.
 */
bool complete = false;

uint32_t savedStatus = 0;

void tsiCallback(uint32_t status) {
   savedStatus = status&(TSI_GENCS_OUTRGF_MASK|TSI_GENCS_OVRF_MASK|TSI_GENCS_EXTERF_MASK);
   // Flag new values available.
   complete = true;
   // To confirm sample interval
   MeasurementPin::toggle();
}

/**
 * Configure TSI
 *
 * @param[in] periodic True to set up TSI for periodic scanning with ISR
 */
void initTsi(bool periodic) {

   // Alternative - use Configure.usbdmProject settings
//   Tsi0::defaultConfigure();

   // Enable TSI
   Tsi0::enable();
   // Set clock source (and divider and modulus)
   Tsi0::setClock(TsiClockSource_LpOscClk);
   // Set Low power clock - off
   Tsi0::setLowPowerClock(TsiStopMode_Disabled);
   // Enable these two inputs
   Tsi0::selectInputs((1<<electrodeA)|(1<<electrodeB), electrodeA);
   // Set charge currents
   Tsi0::setCurrents(16,16);
   // This affects the electrode sample interval and needs to be a compromise
   // that satisfies noise, speed and avoiding count overflow
   Tsi0::setScans(TsiElectrodePrescaler_2, 8);

   Tsi0::setCallback(tsiCallback);

   if (periodic) {
      // This overrides the clock divider and modulus set earlier
      // It must be large enough to allow for the worse case sampling of all electrodes
      Tsi0::setSamplePeriod(10*ms);

      // Start periodic scans
      Tsi0::startScan(TsiScanMode_Periodic);

      // Enable interrupts
      Tsi0::enableTsiInterrupts(TsiInterrupt_EndOfScan, TsiErrorInterrupt_Enable);
      Tsi0::enableNvicInterrupts();
   }

   // Check for errors so far
   checkError();
}

/*
 * The pulse output is intended to be measured on an oscilloscope.
 * The high-time shows the approximate sample time for the active inputs.
 * This will vary with capacitance (finger!)
 *
 * This uses software triggered mode.
 */
void measureScanTime() {
   MeasurementPin::setOutput();
   initTsi(false);

   for(;;) {
      MeasurementPin::set();
      Tsi0::startScanAndWait();
      MeasurementPin::clear();
      waitUS(200);
   }
}

/**
 * An example that scans two electrodes using hardware scan mode.
 * A simple calibration is done initially and then the two electrodes
 * are used to control two LEDs in a simple on-off fashion.
 * The electrode measurements are printed to stdout.
 *
 * The measurement output toggle on each sample sequence.
 */
void tsiExample() {
   MeasurementPin::setOutput();

   uint16_t chAMin, chAMax, chAThreshold, chBMin, chBMax, chBThreshold;
   LedA::setOutput();
   LedB::setOutput();

   // Configure as Software-triggered
   initTsi(false);

   // Wait for first successful conversion
   while (Tsi0::startScanAndWait() != E_NO_ERROR) {
   }
   // Start min/max at first measurement +/- delta
   static constexpr int delta = 0;
   chAMin = std::max(0,     Tsi0::getCount(electrodeA)-delta);
   chAMax = std::min(65535, Tsi0::getCount(electrodeA)+delta);
   chBMin = std::max(0,     Tsi0::getCount(electrodeB)-delta);
   chBMax = std::min(65535, Tsi0::getCount(electrodeB)+delta);

   // Reconfigure as Hardware-triggered (periodic)
   // with interrupts
   initTsi(true);

   for(;;) {
      complete = false;

      // Wait until ISR called
      while (!complete) {
         if (savedStatus != 0) {
            // The overrun flag gets set for some reason even if the timing is generous
            // When it happens you have to restart due to errata e4181
            initTsi(true);
         }
         __asm__("nop");
      }
      // Delay required due to errata e2638
      waitUS(250);

      // Read two active electrodes
      uint16_t chA = Tsi0::getCount(electrodeA);
      uint16_t chB = Tsi0::getCount(electrodeB);

      // Adjust min/max
      chAMin = std::min(chA, chAMin);
      chAMax = std::max(chA, chAMax);
      chBMin = std::min(chB, chBMin);
      chBMax = std::max(chB, chBMax);

      // Update thresholds - biased towards low sample
      chAThreshold = (3*chAMin+chAMax)/4;
      chBThreshold = (3*chBMin+chBMax)/4;

      // Values are compared to thresholds
      bool chAOn = chA>chAThreshold;
      bool chBOn = chB>chBThreshold;

      // Update LEDs
      LedA::write(chAOn);
      LedB::write(chBOn);

      // Report values
      printf("chA=%s(%5d) chB=%s(%5d)\n", (chAOn)?"On ":"Off", chA, (chBOn)?"On ":"Off", chB);
   }

}
int main() {

//   measureScanTime();
   tsiExample();

   for(;;) {
      __asm__("nop");
   }
   return 0;
}
