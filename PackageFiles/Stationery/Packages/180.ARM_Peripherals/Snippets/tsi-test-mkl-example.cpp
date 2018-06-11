/*
 ============================================================================
 * @file    tsi-mkl-example.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo using TSI class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "tsi.h"

using namespace USBDM;

// LED connection - change as required
using Led1  = USBDM::GpioA<18, ActiveLow>;
using Led2  = USBDM::GpioC<1, ActiveLow>;

// Button connections
// Threshold value have to be determined experimentally for each button
using Button1 = Tsi0Button<4, 10000>;
using Button2 = Tsi0Button<7, 10000>;

/**
 * This routine calculates usable thresholds for the two buttons
 * based upon the measured extreme values.
 *
 * It assumes the other TSI settings are reasonable for use.
 */
void calculateThresholds() {
   uint16_t b1Min, b1Max, b1Threshold, b2Min, b2Max, b2Threshold;

   // Configure for capacitive measurement mode
   Tsi0::configure(
         TsiLowPower_Enabled,
         TsiScanNumber_24,
         TsiElectrodePrescaler_8,
         TsiReferenceCharge_8uA,
         TsiExternalCharge_8uA,
         TsiDeltaVoltage_High);

   // Wait for fist successful conversion
   Button1::startScanAndWait();
   b1Min = b1Max = Button1::getCount();
   Button2::startScanAndWait();
   b2Min = b2Max = Button2::getCount();

   for(int count = 0;;count++) {
      waitMS(50);
      uint16_t b1,b2;
      Button1::startScanAndWait();
      b1 = Button1::getCount();
      if (b1<b1Min) {
         b1Min = b1;
      }
      if (b1>b1Max) {
         b1Max = b1;
      }
      b1Threshold = (b1Min+b1Max)/2;
      Led1::write((b1>b1Threshold));
      Button2::startScanAndWait();
      b2 = Button2::getCount();
      if (b2<b2Min) {
         b2Min = b2;
      }
      if (b2>b2Max) {
         b2Max = b2;
      }
      b2Threshold = (b2Min+b2Max)/2;
      Led2::write((b2>b2Threshold));
      console.setPadding(Padding_LeadingSpaces).setWidth(8).write(count).write(": ");
      console.write("Button1(").write(b1Threshold).write(", ").write(b1>b1Threshold).write("), ");
      console.write("Button2(").write(b2Threshold).write(", ").write(b2>b2Threshold).write(") ").writeln();
   }
}

/**
 * Poll the touch are as two buttons
 * LEDs reflect the button values
 */
void pollButtons() {
   Led1::setOutput();
   Led2::setOutput();
   
   // Configure for capacitive measurement mode
   Tsi0::configure(
         TsiLowPower_Enabled,
         TsiScanNumber_24,
         TsiElectrodePrescaler_8,
         TsiReferenceCharge_8uA,
         TsiExternalCharge_8uA,
         TsiDeltaVoltage_High);

   console.setPadding(Padding_LeadingSpaces).setWidth(8);
   for(;;) {
      console.write("Button1(").write(Button1::poll()).write(", ").write(Button1::getCount()).write(") ");
      console.write("Button2(").write(Button2::poll()).write(", ").write(Button2::getCount()).write(") ").writeln();
      Led1::write(Button1::poll());
      Led2::write(Button2::poll());
   }
}

#if 0
static const uint32_t probes[] = {
      TSI_GENCS_DVOLT(0b11)|TSI_GENCS_RS(0b011),
      TSI_GENCS_DVOLT(0b11)|TSI_GENCS_RS(0b100),
      TSI_GENCS_DVOLT(0b10)|TSI_GENCS_RS(0b100),
      TSI_GENCS_DVOLT(0b10)|TSI_GENCS_RS(0b101),
      TSI_GENCS_DVOLT(0b01)|TSI_GENCS_RS(0b101),
      TSI_GENCS_DVOLT(0b01)|TSI_GENCS_RS(0b110),
      TSI_GENCS_DVOLT(0b00)|TSI_GENCS_RS(0b110),
      TSI_GENCS_DVOLT(0b00)|TSI_GENCS_RS(0b111),
};
void testTsi() {
   using Debug  = USBDM::GpioB<0, ActiveLow>;

   Debug::setOutput();
   // 1.
   TSI0->GENCS =
         TSI_GENCS_TSIEN(0b1);
   TSI0->DATA =
         TSI_DATA_TSICH(7);
   // 2.
   TSI0->GENCS =
         TSI_GENCS_MODE(0b1100)|
         TSI_GENCS_TSIEN(0b1);
   // 3a
   TSI0->GENCS =
         TSI_GENCS_MODE(0b1100)|
         TSI_GENCS_TSIEN(0b1)|
         TSI_GENCS_RESISTOR(0b011)|
         TSI_GENCS_DVOLT(0b11);
   // 3b
   TSI0->GENCS =
         TSI_GENCS_MODE(0b1100)|
         TSI_GENCS_TSIEN(0b1)|
         TSI_GENCS_RS(0b011)|
         TSI_GENCS_DVOLT(0b11)|
         TSI_GENCS_REFCHRG(4)|
         TSI_GENCS_PS(3)|
         TSI_GENCS_NSCN(8);

   for(;;) {
      Debug::set();
      // 4.
      TSI0->DATA =
            TSI_DATA_TSICH(7)|
            TSI_DATA_SWTS(1);
      while ((TSI0->GENCS & TSI_GENCS_EOSF_MASK)==0) {
      }
      uint16_t result = TSI0->DATA & TSI_DATA_TSICNT_MASK;
      TSI0->GENCS =
            TSI_GENCS_MODE(0b1100)|
            TSI_GENCS_TSIEN(0b1)|
            TSI_GENCS_RESISTOR(0b011)|
            TSI_GENCS_DVOLT(0b11)|
            TSI_GENCS_REFCHRG(4)|
            TSI_GENCS_PS(3)|
            TSI_GENCS_NSCN(8)|
            TSI_GENCS_EOSF_MASK;
      Debug::clear();
      waitMS(100);
   }
}

//Measure TSI channel noise level value in noise mode

void tsi_measure_noise() {
   using Debug  = USBDM::GpioB<0, ActiveLow>;

   unsigned char uChN = 7;

   Tsi0::enable();

   TSI0->DATA = TSI_DATA_TSICH(uChN);     // set channel ID

   Debug::setOutput();

   Tsi0::configure(
         TsiMode_NoiseDetect_FreqLimit,
         TsiSeriesResitor_187k,
         TsiNoiseFilter_Disabled,
         TsiLowPower_Enabled,
         TsiScanNumber_24,
         TsiElectrodePrescaler_8,
         TsiReferenceCharge_8uA,
         TsiDeltaVoltage_High);

   for(unsigned count=0;;count++) {
      volatile uint32_t status1, status2, status3, status4, status5, status6;

      uint32_t t = TSI0->GENCS;
      t &= ~TSI_GENCS_MODE_MASK;

      t =
            TSI_GENCS_TSIEN(1) |
            TSI_GENCS_MODE(0b1100) |            // auto noise detection
            TSI_GENCS_DVOLT(0b00) |             // select voltage rails
            TSI_GENCS_EXTCHRG(0b100) |          // use 32Kohm Rs, no filter
            TSI_GENCS_REFCHRG(0b100) |
            TSI_GENCS_PS(3) |
            TSI_GENCS_NSCN(23)|
            TSI_GENCS_OUTRGF(1)|
            TSI_GENCS_EOSF(1);

      status1 = TSI0->GENCS & (TSI_GENCS_EOSF_MASK|TSI_GENCS_SCNIP_MASK);
      TSI0->GENCS = t;

      waitMS(10);
      status2 = TSI0->GENCS & (TSI_GENCS_EOSF_MASK|TSI_GENCS_SCNIP_MASK);
//      TSI0->GENCS |= TSI_GENCS_EOSF_MASK;
//      waitMS(10);
//      TSI0->GENCS |= TSI_GENCS_EOSF_MASK;

//      TSI0->GENCS &= ~TSI_GENCS_MODE_MASK;
//      __DMB();
      // Enable noise mode
//      TSI0->GENCS =
//            TSI_GENCS_TSIEN(1) |
//            TSI_GENCS_MODE(0b0000) |            // auto noise detection
//            TSI_GENCS_DVOLT(0b00) |             // select voltage rails
//            TSI_GENCS_EXTCHRG(0b100) |          // use 32Kohm Rs, no filter
//            TSI_GENCS_REFCHRG(0b100) |
//            TSI_GENCS_PS(3) |
//            TSI_GENCS_NSCN(23)|
//            TSI_GENCS_OUTRGF(1);
      // Enable noise mode
      TSI0->GENCS =
            TSI_GENCS_TSIEN(1) |
            TSI_GENCS_MODE(0b1100) |            // auto noise detection
            TSI_GENCS_DVOLT(0b00) |             // select voltage rails
            TSI_GENCS_EXTCHRG(0b100) |          // use 32Kohm Rs, no filter
            TSI_GENCS_REFCHRG(0b100) |
            TSI_GENCS_PS(3) |
            TSI_GENCS_NSCN(23);

      status3 = TSI0->GENCS & (TSI_GENCS_EOSF_MASK|TSI_GENCS_SCNIP_MASK);
      waitMS(10);
      status4 = TSI0->GENCS & (TSI_GENCS_EOSF_MASK|TSI_GENCS_SCNIP_MASK);

      // Start channel scan
//      TSI0->DATA &=  ~TSI_DATA_TSICH(0xF);    // clear channels
//      TSI0->DATA |= TSI_DATA_TSICH(uChN);     // set channel ID
      Debug::set();
      TSI0->DATA |= TSI_DATA_SWTS_MASK;       // start sampling
      status5 = TSI0->GENCS & (TSI_GENCS_EOSF_MASK|TSI_GENCS_SCNIP_MASK);
      waitMS(10);
      status6 = TSI0->GENCS & (TSI_GENCS_EOSF_MASK|TSI_GENCS_SCNIP_MASK);


      // Wait for sampling done
      while (!(TSI0->GENCS & TSI_GENCS_EOSF_MASK)) {
      }
      TSI0->DATA &= ~TSI_DATA_SWTS_MASK;       // stop sampling
      Debug::clear();
      // Read noise level
      uint8_t noiseLevel = (uint8_t)((TSI0->GENCS & TSI_GENCS_MODE_MASK) >> TSI_GENCS_MODE_SHIFT);
      // Clear the flag
//      TSI0->GENCS |= TSI_GENCS_EOSF_MASK;
      console.write(count).write(": Noise = ").writeln(noiseLevel);
      waitMS(100);
   }
}
#endif

int main() {
   console.write("SystemBusClock   = ").writeln(USBDM::SystemBusClock);
   console.write("SystemCoreClock  = ").writeln(USBDM::SystemCoreClock);

   Led1::setOutput();
   Led2::setOutput();

//   calculateThresholds();
   pollButtons();
//   testTsi();
//   tsi_measure_noise();
}
