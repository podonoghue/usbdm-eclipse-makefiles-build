/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdlib.h>   // For rand
#include "hardware.h"
#include "mcg.h"
#include "smc.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// LED connection - change as required
using Led   = USBDM::GpioA<2,USBDM::ActiveLow>;

/**
 * Table of clock settings
 */
const McgInfo::ClockInfo clockInfo[8] = {
      {

            //! System Clock Divider Register 1
            SIM_CLKDIV1_OUTDIV4(3)|  // Flash clock
            SIM_CLKDIV1_OUTDIV2(1)|  // Bus clock
            SIM_CLKDIV1_OUTDIV1(1),  // Core/system clock

            //! Clock Mode
            McgInfo::ClockMode_FEI,

            //! Control Register 1 - Excluding CLKS, IREFS
            MCG_C1_FRDIV(0)   | // FRDIV    FLL External Reference Divider
            MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
            MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

            //! Control Register 2 - Excluding LP
            MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
            MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
            MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
            MCG_C2_EREFS0(1) | // EREFS   External Reference Select
            MCG_C2_IRCS(0),    // IRCS    Internal Reference Clock Select

            //! Control Register 4
            MCG_C4_DMX32(0)     | // DMX32    DCO lock range
            MCG_C4_DRST_DRS(3),   // DRST_DRS DCO Range Select

            //! Control Register 5
            MCG_C5_PLLCLKEN0(0)  | // PLLCLKEN0 PLL Clock Enable
            MCG_C5_PLLSTEN0(0)   | // PLLSTEN0  PLL Stop Enable
            MCG_C5_PRDIV0(0),     // PRDIV0    PLL External Reference Divider

            //! Control Register 6 - Excluding PLLS
            MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
            MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
            MCG_C6_VDIV0(0),   // VDIV0  PLL VCO Divider

            //! Status and Control Register
            MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

            //! Control Register 7
            MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

            //! Control Register 8
            MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
            MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
            MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
      },
      {
            //! System Clock Divider Register 1
            SIM_CLKDIV1_OUTDIV4(3)|  // Flash clock
            SIM_CLKDIV1_OUTDIV2(1)|  // Bus clock
            SIM_CLKDIV1_OUTDIV1(1),   // Core/system clock

            //! Clock Mode
            McgInfo::ClockMode_FEE,

            //! Control Register 1 - Excluding CLKS, IREFS
            MCG_C1_FRDIV(3)   | // FRDIV    FLL External Reference Divider
            MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
            MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

            //! Control Register 2 - Excluding LP
            MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
            MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
            MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
            MCG_C2_EREFS0(1) | // EREFS   External Reference Select
            MCG_C2_IRCS(1),    // IRCS    Internal Reference Clock Select

            //! Control Register 4
            MCG_C4_DMX32(0)     | // DMX32    DCO lock range
            MCG_C4_DRST_DRS(3),   // DRST_DRS DCO Range Select

            //! Control Register 5
            MCG_C5_PLLCLKEN0(0)  | // PLLCLKEN0 PLL Clock Enable
            MCG_C5_PLLSTEN0(0)   | // PLLSTEN0  PLL Stop Enable
            MCG_C5_PRDIV0(0),     // PRDIV0    PLL External Reference Divider

            //! Control Register 6 - Excluding PLLS
            MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
            MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
            MCG_C6_VDIV0(0),   // VDIV0  PLL VCO Divider

            //! Status and Control Register
            MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

            //! Control Register 7
            MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

            //! Control Register 8
            MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
            MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
            MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
      },
      {
            //! System Clock Divider Register 1
            SIM_CLKDIV1_OUTDIV4(0)|  // Flash clock
            SIM_CLKDIV1_OUTDIV2(0)|  // Bus clock
            SIM_CLKDIV1_OUTDIV1(0),  // Core/system clock

            //! Clock Mode
            McgInfo::ClockMode_FBI,

            //! Control Register 1 - Excluding CLKS, IREFS
            MCG_C1_FRDIV(0)   | // FRDIV    FLL External Reference Divider
            MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
            MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

            //! Control Register 2 - Excluding LP
            MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
            MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
            MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
            MCG_C2_EREFS0(1) | // EREFS   External Reference Select
            MCG_C2_IRCS(1),    // IRCS    Internal Reference Clock Select

            //! Control Register 4
            MCG_C4_DMX32(0)     | // DMX32    DCO lock range
            MCG_C4_DRST_DRS(3),   // DRST_DRS DCO Range Select

            //! Control Register 5
            MCG_C5_PLLCLKEN0(1)  | // PLLCLKEN0 PLL Clock Enable
            MCG_C5_PLLSTEN0(0)   | // PLLSTEN0  PLL Stop Enable
            MCG_C5_PRDIV0(1),     // PRDIV0    PLL External Reference Divider

            //! Control Register 6 - Excluding PLLS
            MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
            MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
            MCG_C6_VDIV0(6),   // VDIV0  PLL VCO Divider

            //! Status and Control Register
            MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

            //! Control Register 7
            MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

            //! Control Register 8
            MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
            MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
            MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
      },
      {
            //! System Clock Divider Register 1
            SIM_CLKDIV1_OUTDIV4(0)|  // Flash clock
            SIM_CLKDIV1_OUTDIV2(0)|  // Bus clock
            SIM_CLKDIV1_OUTDIV1(0),  // Core/system clock

            //! Clock Mode
            McgInfo::ClockMode_FBE,

            //! Control Register 1 - Excluding CLKS, IREFS
            MCG_C1_FRDIV(3)   | // FRDIV    FLL External Reference Divider
            MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
            MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

            //! Control Register 2 - Excluding LP
            MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
            MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
            MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
            MCG_C2_EREFS0(1) | // EREFS   External Reference Select
            MCG_C2_IRCS(0),    // IRCS    Internal Reference Clock Select

            //! Control Register 4
            MCG_C4_DMX32(0)     | // DMX32    DCO lock range
            MCG_C4_DRST_DRS(3),   // DRST_DRS DCO Range Select

            //! Control Register 5
            MCG_C5_PLLCLKEN0(1)  | // PLLCLKEN0 PLL Clock Enable
            MCG_C5_PLLSTEN0(1)   | // PLLSTEN0  PLL Stop Enable
            MCG_C5_PRDIV0(1),     // PRDIV0    PLL External Reference Divider

            //! Control Register 6 - Excluding PLLS
            MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
            MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
            MCG_C6_VDIV0(6),   // VDIV0  PLL VCO Divider

            //! Status and Control Register
            MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

            //! Control Register 7
            MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

            //! Control Register 8
            MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
            MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
            MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
      },
      {
            //! System Clock Divider Register 1
            SIM_CLKDIV1_OUTDIV4(0)|  // Flash clock
            SIM_CLKDIV1_OUTDIV2(0)|  // Bus clock
            SIM_CLKDIV1_OUTDIV1(0),  // Core/system clock

            //! Clock Mode
            McgInfo::ClockMode_PBE,

            //! Control Register 1 - Excluding CLKS, IREFS
            MCG_C1_FRDIV(3)   | // FRDIV    FLL External Reference Divider
            MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
            MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

            //! Control Register 2 - Excluding LP
            MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
            MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
            MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
            MCG_C2_EREFS0(1) | // EREFS   External Reference Select
            MCG_C2_IRCS(0),    // IRCS    Internal Reference Clock Select

            //! Control Register 4
            MCG_C4_DMX32(0)     | // DMX32    DCO lock range
            MCG_C4_DRST_DRS(0),   // DRST_DRS DCO Range Select

            //! Control Register 5
            MCG_C5_PLLCLKEN0(1)  | // PLLCLKEN0 PLL Clock Enable
            MCG_C5_PLLSTEN0(1)   | // PLLSTEN0  PLL Stop Enable
            MCG_C5_PRDIV0(1),     // PRDIV0    PLL External Reference Divider

            //! Control Register 6 - Excluding PLLS
            MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
            MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
            MCG_C6_VDIV0(6),   // VDIV0  PLL VCO Divider

            //! Status and Control Register
            MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

            //! Control Register 7
            MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

            //! Control Register 8
            MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
            MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
            MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
      },
      {
            //! System Clock Divider Register 1
            SIM_CLKDIV1_OUTDIV4(3)|  // Flash clock
            SIM_CLKDIV1_OUTDIV2(1)|  // Bus clock
            SIM_CLKDIV1_OUTDIV1(1),  // Core/system clock

            //! Clock Mode
            McgInfo::ClockMode_PEE,

            //! Control Register 1 - Excluding CLKS, IREFS
            MCG_C1_FRDIV(3)   | // FRDIV    FLL External Reference Divider
            MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
            MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

            //! Control Register 2 - Excluding LP
            MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
            MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
            MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
            MCG_C2_EREFS0(1) | // EREFS   External Reference Select
            MCG_C2_IRCS(0),    // IRCS    Internal Reference Clock Select

            //! Control Register 4
            MCG_C4_DMX32(0)     | // DMX32    DCO lock range
            MCG_C4_DRST_DRS(0),   // DRST_DRS DCO Range Select

            //! Control Register 5
            MCG_C5_PLLCLKEN0(0)  | // PLLCLKEN0 PLL Clock Enable
            MCG_C5_PLLSTEN0(0)   | // PLLSTEN0  PLL Stop Enable
            MCG_C5_PRDIV0(1),     // PRDIV0    PLL External Reference Divider

            //! Control Register 6 - Excluding PLLS
            MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
            MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
            MCG_C6_VDIV0(0),   // VDIV0  PLL VCO Divider

            //! Status and Control Register
            MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

            //! Control Register 7
            MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

            //! Control Register 8
            MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
            MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
            MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
      },
      {
            //! System Clock Divider Register 1
            SIM_CLKDIV1_OUTDIV4(0)|  // Flash clock
            SIM_CLKDIV1_OUTDIV2(0)|  // Bus clock
            SIM_CLKDIV1_OUTDIV1(0),  // Core/system clock

            //! Clock Mode
            McgInfo::ClockMode_BLPI,

            //! Control Register 1 - Excluding CLKS, IREFS
            MCG_C1_FRDIV(0)   | // FRDIV    FLL External Reference Divider
            MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
            MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

            //! Control Register 2 - Excluding LP
            MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
            MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
            MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
            MCG_C2_EREFS0(1) | // EREFS   External Reference Select
            MCG_C2_IRCS(1),    // IRCS    Internal Reference Clock Select

            //! Control Register 4
            MCG_C4_DMX32(0)     | // DMX32    DCO lock range
            MCG_C4_DRST_DRS(0),   // DRST_DRS DCO Range Select

            //! Control Register 5
            MCG_C5_PLLCLKEN0(1)  | // PLLCLKEN0 PLL Clock Enable
            MCG_C5_PLLSTEN0(0)   | // PLLSTEN0  PLL Stop Enable
            MCG_C5_PRDIV0(1),     // PRDIV0    PLL External Reference Divider

            //! Control Register 6 - Excluding PLLS
            MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
            MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
            MCG_C6_VDIV0(6),   // VDIV0  PLL VCO Divider

            //! Status and Control Register
            MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

            //! Control Register 7
            MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

            //! Control Register 8
            MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
            MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
            MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
      },
      {
            //! System Clock Divider Register 1
            SIM_CLKDIV1_OUTDIV4(0)|  // Flash clock
            SIM_CLKDIV1_OUTDIV2(0)|  // Bus clock
            SIM_CLKDIV1_OUTDIV1(0),   // Core/system clock

            //! Clock Mode
            McgInfo::ClockMode_BLPE,

            //! Control Register 1 - Excluding CLKS, IREFS
            MCG_C1_FRDIV(3)   | // FRDIV    FLL External Reference Divider
            MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
            MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

            //! Control Register 2 - Excluding LP
            MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
            MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
            MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
            MCG_C2_EREFS0(1) | // EREFS   External Reference Select
            MCG_C2_IRCS(0),    // IRCS    Internal Reference Clock Select

            //! Control Register 4
            MCG_C4_DMX32(0)     | // DMX32    DCO lock range
            MCG_C4_DRST_DRS(0),   // DRST_DRS DCO Range Select

            //! Control Register 5
            MCG_C5_PLLCLKEN0(1)  | // PLLCLKEN0 PLL Clock Enable
            MCG_C5_PLLSTEN0(0)   | // PLLSTEN0  PLL Stop Enable
            MCG_C5_PRDIV0(1),     // PRDIV0    PLL External Reference Divider

            //! Control Register 6 - Excluding PLLS
            MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
            MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
            MCG_C6_VDIV0(6),   // VDIV0  PLL VCO Divider

            //! Status and Control Register
            MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

            //! Control Register 7
            MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

            //! Control Register 8
            MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
            MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
            MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
      },

};

int main() {
   console.writeln("Starting\n");

   Led::setOutput();
   for(;;) {
      int i = rand()%(sizeof(clockInfo)/sizeof(clockInfo[0]));
      console<<Smc::getSmcStatusName()<<":"<<Mcg::getClockModeName()<<"@"<<::SystemCoreClock<<" Hz\n"<<Flush;
      Mcg::clockTransition(clockInfo[i]);
      console.setBaudRate(defaultBaudRate);
      Led::toggle();
//      waitMS(100);
   }
}
