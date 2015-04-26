/*
 * clock_private-MKxxM12-DualPLL.h
 *
 * Based on K60P144M150SF3RM
 *   3 Oscillators (OSC0, OSC1, OSC2=RTC)
 *   1 FLL (OSC0 or OSC2=RTC), (FRDIV=/1-/128, /32-/1024)
 *   2 PLLs (OSC0, OSC1), (VCO PRDIV=/1-/8, VDIV=x16-x47)
 *
 * Used with:
 *   clock-MKxxM12-DualPLL.c
 *
 *  Created on: 13/7/2012
 *      Author: podonoghue
 */

#ifndef CLOCK_PRIVATE_H_
#define CLOCK_PRIVATE_H_

#include <stdint.h>
#include "derivative.h"
#include "system.h"

#ifdef __cplusplus
extern "C" {
#endif

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

//===================================
// Validators
// Common clock settings
// <validate=net.sourceforge.usbdm.annotationEditor.validators.ClockValidate_MKxxM12_DualPll>
// PLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.Pll0ClockValidate_MKxxM12>
// <validate=net.sourceforge.usbdm.annotationEditor.validators.Pll1ClockValidate_MKxxM12>
// FLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.FllClockValidate>

// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// OSCCLK0_CLOCK ==============================
//
//   <o> Frequency of OSC0 External Clock or Crystal (Hz)  <name=oscclk0_clock> <0-50000000>
//   <i> Frequency of external crystal or clock on XTAL0/EXTAL0
//   <i> See MCG_C2_EREFS0 for XTAL/Clock selection
#define OSCCLK0_CLOCK (8000000UL)

// OSC32KCLK_CLOCK
// Assumed to be only available when main oscillator operating with 32kHz crystal on XTAL/EXTAL
#if (OSCCLK0_CLOCK < 31000) || (OSCCLK0_CLOCK> 33000)
#define OSC32KCLK_CLOCK (0)
#else
#define OSC32KCLK_CLOCK OSCCLK0_CLOCK
#endif

// OSCCLK1_CLOCK ==============================
//
//   <o> Frequency of OSC1 External Clock or Crystal (Hz)  <name=oscclk1_clock> <0-50000000>
//   <i> Frequency of external crystal or clock on XTAL1/EXTAL1
#define OSCCLK1_CLOCK (8000000UL)

// RTCCLK_CLOCK ==============================
//
//   <o> Frequency of RTC External Clock or Crystal (Hz) <name=rtcclk_clock>
//   <i> Frequency of external crystal or clock on XTAL32/EXTAL32 [Typically 32768 Hz]
#define RTCCLK_CLOCK (32768UL)

// SYSTEM_LOW_POWER_CLOCK ==============================
//
//   <o> Frequency of Internal Low Power Oscillator Clock (Hz) <constant> <name=system_low_power_clock>
//   <i> Dependent on device. [Typically ~1kHz]
#define SYSTEM_LOW_POWER_CLOCK (1000UL)

// SYSTEM_ERC_CLOCK ==============================
//
//   <o> External Reference Clock (Hz) <constant> <name=system_erc_clock>
//   <i> Derived from the external crystal or clock source on XTAL/EXTAL or XTAL32/EXTAL32
#define SYSTEM_ERC_CLOCK (8000000UL)

// SYSTEM_SLOW_IRC_CLOCK ==============================
//
//   <o> Frequency of Slow Internal Reference Clock (Hz) <constant> <name=system_slow_irc_clock>
//   <i> Dependent on device and clock Trim. [Typically ~32kHz]
#define SYSTEM_SLOW_IRC_CLOCK (32768UL)

// SYSTEM_FAST_IRC_CLOCK ==============================
//
//   <o> Frequency of Fast Internal Reference Clock (Hz) <constant> <name=system_fast_irc_clock>
//   <i> Dependent on device and clock Trim. [Typically ~4MHz]
#define SYSTEM_FAST_IRC_CLOCK (4000000UL)

//========================================================================================
//========================================================================================
// CLOCK_MODE ===============================
//
//   <o> Clock Mode <name=clock_mode>
//   <i> Basic choice for final clock mode
//<i> FLL Engaged Internal(FEI)
//<i> In FEI mode, MCGOUT is derived from the FLL clock (DCOCLK) that is controlled by the 32 kHz Internal Reference Clock (IRC). 
//<i> The FLL loop will lock the DCO frequency to the FLL factor, as selected by the C4[DRST_DRS] and C4[DMX32] bits, times the 
//<i> internal reference frequency.
//<i>
//<i> FLL Engaged External(FEE)
//<i> In FEE mode, MCGOUT is derived from the FLL clock (DCOCLK) that is controlled by the external reference clock. The FLL loop
//<i> will lock the DCO frequency to the FLL factor, as selected by C4[DRST_DRS] and C4[DMX32] bits, times the external reference
//<i> frequency, as specified by the C1[FRDIV] and C2[RANGE].
//<i>
//<i> FLL Bypassed Internal(FBI)
//<i> In FBI mode, the MCGOUT clock is derived either from the slow (32 kHz IRC) or fast (2 MHz IRC) internal reference clock, 
//<i> as selected by the C2[IRCS] bit. The FLL is operational but its output is not used. This mode is useful to allow the FLL
//<i> to acquire its target frequency while the MCGOUT clock is driven from the C2[IRCS] selected internal reference clock. The
//<i> FLL clock (DCOCLK) is controlled by the slow internal reference clock, and the DCO clock frequency locks to a multiplication
//<i> factor, as selected by the C4[DRST_DRS] and C4[DMX32] bits, times the internal reference frequency.
//<i>
//<i> FLL Bypassed External(FBE)
//<i> In FBE mode, the MCGOUT clock is derived from the external reference clock. The FLL is operational but its output is not
//<i> used. This mode is useful to allow the FLL to acquire its target frequency while the MCGOUT clock is driven from the 
//<i> external reference clock. The FLL clock (DCOCLK) is controlled by the external reference clock, and the DCO clock frequency
//<i> locks to a multiplication factor, as selected by the C4[DRST_DRS] and C4[DMX32] bits, times the divided external reference
//<i> frequency. 
//<i>
//<i> PLL Engaged External(PEE)
//<i> In PEE mode, the MCGOUT is derived from the PLL0/1 clock, which is controlled by the external reference clock. The PLL clock
//<i> frequency locks to a multiplication factor, as specified by [VDIV0/1], times the external reference frequency, as specified 
//<i> by [PRDIV0/1]. 
//<i>
//<i> PLL Bypassed External(PBE)
//<i> In PBE mode, MCGOUT is derived from the OSCSEL external reference clock; the PLL is operational, but its output clock is 
//<i> not used. This mode is useful to allow the PLL to acquire its target frequency while MCGOUT is driven from the external 
//<i> reference clock. The PLL0/1 clock frequency locks to a multiplication factor, as specified by its [VDIV0/1], times the external
//<i> reference frequency, as specified by its [PRDIV0/1].
//<i>
//<i> Bypassed Low Power Internal (BLPI/FBILP)
//<i> In BLPI mode, MCGOUT is derived from the internal reference clock. The FLL is disabled and PLL is disabled even if the 
//<i> C5[PLLCLKEN] is set to 1. 
//<i>
//<i> Bypassed Low Power External (BLPE/FBELP) 
//<i> In BLPE mode, MCGOUT is derived from the external reference clock. The FLL is disabled and PLL is disabled even if the
//<i> C5[PLLCLKEN] is set to 1.
//     <0=> No setup (Reset default)
//     <1=> FLL Engaged Internal (FEI)
//     <2=> FLL Engaged External (FEE)
//     <3=> FLL bypassed internal (FBI)
//     <4=> Bypassed low power internal (BLPI)
//     <5=> FLL bypassed external (FBE)
//     <6=> Bypassed low power external (BLPE)
//     <7=> PLL Bypassed External (PBE)
//     <8=> PLL Engaged External (PEE)
#define CLOCK_MODE 1

// Clock modes
#define CLOCK_MODE_NONE     0
#define CLOCK_MODE_FEI      1
#define CLOCK_MODE_FEE      2
#define CLOCK_MODE_FBI      3
#define CLOCK_MODE_BLPI     4
#define CLOCK_MODE_FBE      5
#define CLOCK_MODE_BLPE     6
#define CLOCK_MODE_PBE      7
#define CLOCK_MODE_PEE      8

// PLL0_TARGET_CLOCK =======================================
//
//  <o> PLL0 Output clock frequency (Hz) <90000000-180000000> <name=pll0TargetFrequency>
//  <i> Used for MCGPLLCLK system clock [MCGPLL0CLK]
//  <i> Used for main MCGOUTCLK system clock if PEE mode is selected.
#define PLL0_TARGET_CLOCK 180000000UL

// PLL1_TARGET_CLOCK =======================================
//
//  <o> PLL1 Output clock frequency (Hz) <90000000-180000000> <name=pll1TargetFrequency>
//  <i> Used for MCGPLLCLK system clock [MCGPLL1CLK]
//  <i> Used for main MCGOUTCLK system clock if PEE mode is selected.
#define PLL1_TARGET_CLOCK 180000000UL

// FLL_TARGET_CLOCK =======================================
//
//  <o> FLL Output clock frequency (Hz) <name=fllTargetFrequency>
//  <i> Used for MCGFLLCLK system clock
//  <i> Used for main MCGOUTCLK system clock if FEI or FEE mode is selected.
#define FLL_TARGET_CLOCK 83886080UL

// SYSTEM_MCGOUT_CLOCK =======================================
//
//  <o> System MCGOUT Clock (Hz) <name=system_mcgout_clock> <constant>
//  <i> MCG Main clock output
//  <i> Derived from slow IRC, fast IRC, ERC, FLL or PLL
#define SYSTEM_MCGOUT_CLOCK 83886080UL

// SYSTEM_MCGIR_CLOCK =======================================
//
//  <o> System MCGIR Clock (Hz) <name=system_mcgir_clock> <constant>
//  <i> MCG Internal Reference Clock
//  <i> Derived from slow IRC or fast IRC
#define SYSTEM_MCGIR_CLOCK 32768UL

// SYSTEM_CORE_CLOCK =======================================
//
//  <o> System Core Clock (Hz) <name=system_core_clock> <constant>
//  <i> Clocks the ARM Cortex-M4 core and bus masters
//  <i> Derived from MCGOUT Clock after division by OUTDIV1
//  <i> Must be less than or equal to 120/150 MHz. 
#define SYSTEM_CORE_CLOCK 83886080UL

// SYSTEM_BUS_CLOCK =======================================
//
//  <o> System Bus Clock (Hz) <name=system_bus_clock> <constant>
//  <i> Clocks the bus slaves and peripheral
//  <i> Derived from MCGOUT Clock after division by OUTDIV2
//  <i> Must be less than or equal to 75 MHz and less than or equal to the Core Clock frequency. 
//  <i> Must be an integer divisor of the Core Clock. 
#define SYSTEM_BUS_CLOCK 41943040UL

// SYSTEM_FLEXBUS_CLOCK =======================================
//
//  <o> System Flexbus Clock (Hz) <name=system_flexbus_clock> <constant>
//  <i> Clocks the flexbus interface
//  <i> Derived from MCGOUT clock after division by OUTDIV3.
//  <i> Must be less than or equal to 50 MHz and less than or equal to the Bus Clock frequency.
#define SYSTEM_FLEXBUS_CLOCK 41943040UL

// SYSTEM_FLASH_CLOCK =======================================
//
//  <o> System Flash Clock (Hz) <name=system_flash_clock> <constant>
//  <i> Clocks the flash memory
//  <i> Derived from MCGOUT clock after division by OUTDIV4.
//  <i> Must be less than or equal to 25 MHz and less than or equal to the Bus Clock frequency. 
//  <i> Must be an integer divisor of the Core Clock. 
#define SYSTEM_FLASH_CLOCK 20971520UL

// <h> System Clock dividers
// SIM_CLKDIV1_OUTDIV1 ================================
//
//   <o> Core & System Clock Divider (OUTDIV1) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv1>
//   <i> Clocks the ARM Cortex-M4 core and bus masters [SIM_CLKDIV1_OUTDIV1]
//   <i> MCGOUTCLK clock is source. Default /1
#define SIM_CLKDIV1_OUTDIV1_V (0)
#define SIM_CLKDIV1_OUTDIV1_M SIM_CLKDIV1_OUTDIV1(SIM_CLKDIV1_OUTDIV1_V)

// SIM_CLKDIV1_OUTDIV2 ================================
//
//   <o> Bus Clock Divider (OUTDIV2) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv2>
//   <i> Clocks the bus slaves and peripheral [SIM_CLKDIV1_OUTDIV2]
//   <i> MCGOUTCLK clock is source. Default /2
#define SIM_CLKDIV1_OUTDIV2_V (1)
#define SIM_CLKDIV1_OUTDIV2_M SIM_CLKDIV1_OUTDIV2(SIM_CLKDIV1_OUTDIV2_V)

// SIM_CLKDIV1_OUTDIV3 ================================
//
//   <o> Flexbus Clock Divider (OUTDIV3) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv3>
//   <i> Clocks the flexbus interface [SIM_CLKDIV1_OUTDIV3]
//   <i> MCGOUTCLK clock is source. Default /2
#define SIM_CLKDIV1_OUTDIV3_V (1)
#define SIM_CLKDIV1_OUTDIV3_M SIM_CLKDIV1_OUTDIV3(SIM_CLKDIV1_OUTDIV3_V)

// SIM_CLKDIV1_OUTDIV4 ================================
//
//   <o> Flash Clock Divider (OUTDIV4) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv4>
//   <i> Clocks the flash memory [SIM_CLKDIV1_OUTDIV4]
//   <i> MCGOUTCLK clock is source. Default /4
#ifndef SIM_CLKDIV1_OUTDIV4_V
#define SIM_CLKDIV1_OUTDIV4_V (3)
#endif

#define SIM_CLKDIV1_OUTDIV4_M SIM_CLKDIV1_OUTDIV4(SIM_CLKDIV1_OUTDIV4_V)

// </h>

//========================================================================================
//========================================================================================
// <h> OSC0 Control Register (OSC0_CR) 

// OSC0_CR_ERCLKEN ===============================
//
//   <q> External Reference Enable (ERCLKEN) 
//   <i> Enables external reference clock [OSC0_CR_ERCLKEN]
//     <0=> Disabled
//     <1=> Enabled
#define OSC0_CR_ERCLKEN_V 0
#define OSC0_CR_ERCLKEN_M (OSC0_CR_ERCLKEN_V<<OSC_CR_ERCLKEN_SHIFT)

// OSC0_CR_EREFSTEN ===============================
//
//   <q> External Reference Stop Enable (EREFSTEN)
//   <i> Determines if external reference clock is enabled in Stop mode [OSC0_CR_EREFSTEN]
//     <0=> Disabled in Stop mode
//     <1=> Enabled in Stop mode
#define OSC0_CR_EREFSTEN_V 0
#define OSC0_CR_EREFSTEN_M (OSC0_CR_EREFSTEN_V<<OSC_CR_EREFSTEN_SHIFT)

// OSC0_CR_SC2P ===============================
//
//   <q0> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC0_CR_SC2P]
//     <0=>
//     <1=> +2pF

// OSC0_CR_SC4P ===============================
//
//   <q1> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC0_CR_SC4P]
//     <0=>
//     <1=> +4pF

// OSC0_CR_SC8P ===============================
//
//   <q2> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC0_CR_SC8P]
//     <0=>
//     <1=> +8pF

// OSC0_CR_SC16P ===============================
//
//   <q3> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC0_CR_SC16P]
//     <0=>
//     <1=> +16pF

#define OSC0_CR_SCP_M ((0<<OSC_CR_SC2P_SHIFT)|(0<<OSC_CR_SC4P_SHIFT)|(1<<OSC_CR_SC8P_SHIFT)|(0<<OSC_CR_SC16P_SHIFT))
// </h>

//========================================================================================
//========================================================================================
// <h> OSC1 Control Register (OSC1_CR) 

// OSC1_CR_ERCLKEN ===============================
//
//   <q> External Reference Enable (ERCLKEN) 
//   <i> Enables external reference clock [OSC1_CR_ERCLKEN]
//     <0=> Disabled
//     <1=> Enabled
#define OSC1_CR_ERCLKEN_V 0
#define OSC1_CR_ERCLKEN_M (OSC1_CR_ERCLKEN_V<<OSC_CR_ERCLKEN_SHIFT)

// OSC1_CR_EREFSTEN ===============================
//
//   <q> External Reference Stop Enable (EREFSTEN)
//   <i> Determines if external reference clock is enabled in Stop mode [OSC1_CR_EREFSTEN]
//     <0=> Disabled in Stop mode
//     <1=> Enabled in Stop mode
#define OSC1_CR_EREFSTEN_V 0
#define OSC1_CR_EREFSTEN_M (OSC1_CR_EREFSTEN_V<<OSC_CR_EREFSTEN_SHIFT)

// OSC1_CR_SC2P ===============================
//
//   <q0> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC1_CR_SC2P]
//     <0=>
//     <1=> +2pF

// OSC1_CR_SC4P ===============================
//
//   <q1> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC1_CR_SC4P]
//     <0=>
//     <1=> +4pF

// OSC1_CR_SC8P ===============================
//
//   <q2> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC1_CR_SC8P]
//     <0=>
//     <1=> +8pF

// OSC1_CR_SC16P ===============================
//
//   <q3> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC1_CR_SC16P]
//     <0=>
//     <1=> +16pF

#define OSC1_CR_SCP_M ((0<<OSC_CR_SC2P_SHIFT)|(0<<OSC_CR_SC4P_SHIFT)|(1<<OSC_CR_SC8P_SHIFT)|(0<<OSC_CR_SC16P_SHIFT))
// </h>

//========================================================================================
//========================================================================================
// <h> RTC Control Register (RTC_CR)
	
// RTC_CR_OSCE ===============================
//
//   <q> RTC Oscillator Enable (OSCE)
//   <i> Enables 32.768 kHz RTC oscillator[RTC_CR_OSCE]
//     <0=> Disabled
//     <1=> Enabled
#define RTC_CR_OSCE_V 0
#define RTC_CR_OSCE_M (RTC_CR_OSCE_V<<RTC_CR_OSCE_SHIFT)

// RTC_CR_CLKO ===============================
//
//   <q> RTC 32kHz Clock Output (CLKO)
//   <i> Determines if RTC 32kHz Clock is available to peripherals [RTC_CR_CLKO]
//     <0=> The 32kHz clock is output to other peripherals
//     <1=> The 32kHz clock is not output to other peripherals
#define RTC_CR_CLKO_V 0
#define RTC_CR_CLKO_M (RTC_CR_CLKO_V<<RTC_CR_CLKO_SHIFT)

// RTC_CR_UM ===============================
//
//   <q> Update Mode (UM)
//   <i> Allows the SR[TCE] to be written even when the Status Register is locked. [RTC_CR_UM]
//   <i> When set, the SR[TCE] can always be written if the SR[TIF] or SR[TOF] are set or if the SR[TCE] is clear.
//     <0=> Registers cannot be written when locked.
//     <1=> Registers can be written when locked under limited conditions
#define RTC_CR_UM_V 0
#define RTC_CR_UM_M (RTC_CR_UM_V<<RTC_CR_UM_SHIFT)

// RTC_CR_SUP ===============================
//
//   <q> Supervisor Access (SUP)
//   <i> Determines if the RTC register access is available in non-supervisor mode [RTC_CR_SUP]
//   <i> Non supported write accesses generate a bus error.
//     <0=> Non-supervisor mode write accesses are not supported
//     <1=> Non-supervisor mode write accesses are supported
#define RTC_CR_SUP_V 0
#define RTC_CR_SUP_M (RTC_CR_SUP_V<<RTC_CR_SUP_SHIFT)

// RTC_CR_WPE ===============================
//
//   <q> Wakeup Pin Enable (WPE)
//   <i> Determines if the wakeup pin is asserted on RTC interrupt when powered done [RTC_CR_WPE]
//   <i> The wakeup pin is optional and not available on all devices.
//     <0=> Wakeup pin is disabled.
//     <1=> Wakeup pin is enabled.
#define RTC_CR_WPE_V 0
#define RTC_CR_WPE_M (RTC_CR_WPE_V<<RTC_CR_WPE_SHIFT)

// RTC_CR_SC2P ===============================
//
//   <q0> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_CR_SC2P]
//     <0=>
//     <1=> +2pF

// RTC_CR_SC4P ===============================
//
//   <q1> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_CR_SC4P]
//     <0=>
//     <1=> +4pF

// RTC_CR_SC8P ===============================
//
//   <q2> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_CR_SC8P]
//     <0=>
//     <1=> +8pF

// RTC_CR_SC16P ===============================
//
//   <q3> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_CR_SC16P]
//     <0=>
//     <1=> +16pF

#define RTC_CR_SCP_M ((0<<RTC_CR_SC2P_SHIFT)|(0<<RTC_CR_SC4P_SHIFT)|(1<<RTC_CR_SC8P_SHIFT)|(0<<RTC_CR_SC16P_SHIFT))
// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 1 (MCG_C1)

// MCG_C1_CLKS =======================================
//
//  <o> MCGOUTCLK Clock Source Select (CLKS) [0-2] <constant> <name=mcg_c1_clks>
//  <i> Selects the clock source for MCGOUTCLK [MCG_C1_CLKS]
//  <i> This option is determined by the Clock Mode selection
//      <0=> Output of FLL or PLLCS is selected (depends on PLLS)
//      <1=> Internal reference clock is selected
//      <2=> External reference clock is selected
#define MCG_C1_CLKS_V 0
#define MCG_C1_CLKS_M (MCG_C1_CLKS_V<<MCG_C1_CLKS_SHIFT)

// MCG_C1_FRDIV ================================
//
//   <o> FLL External Reference Divider (FRDIV)  <constant> <0-7> <name=mcg_c1_frdiv>
//   <i> Selects the amount to divide down the external reference clock for the FLL. [MCG_C1_FRDIV]
//   <i> The resulting frequency must be in the range 31.25 kHz to 39.0625 kHz
//   <i> Division factor depends on Clock Range [MGC_C2_RANGE0]
//   <i> This option is determined by the Clock Mode and FLL input clock
//      <0=> if RANGE0 = 0 divide by 1, else 32
//      <1=> if RANGE0 = 0 divide by 2, else 64
//      <2=> if RANGE0 = 0 divide by 4, else 128
//      <3=> if RANGE0 = 0 divide by 8, else 256
//      <4=> if RANGE0 = 0 divide by 16, else 512
//      <5=> if RANGE0 = 0 divide by 32, else 1024
//      <6=> if RANGE0 = 0 divide by 64, else Reserved
//      <7=> if RANGE0 = 0 divide by 128, else Reserved
#define MCG_C1_FRDIV_V 3
#define MCG_C1_FRDIV_M (MCG_C1_FRDIV_V<<MCG_C1_FRDIV_SHIFT)

// MCG_C1_IREFS ================================
//
//   <o> Internal Reference Select (IREFS) <constant> <name=mcg_c1_irefs>
//   <i> Selects the reference clock source for the FLL [MCG_C1_IREFS]
//   <i> This option is determined by the Clock Mode selection
//      <0=> External Reference Clock
//      <1=> Slow Internal Clock
#define MCG_C1_IREFS_V 1
#define MCG_C1_IREFS_M (MCG_C1_IREFS_V<<MCG_C1_IREFS_SHIFT)

// MCG_C1_IRCLKEN ==============================
//
//   <q> Internal Reference Clock Enable (IRCLKEN)
//   <i> Enables the internal reference clock for use as MCGIRCLK [MCG_C1_IRCLKEN]
//      <0=> Inactive
//      <1=> Active
#define MCG_C1_IRCLKEN_V   0
#define MCG_C1_IRCLKEN_M   (1<<MCG_C1_IRCLKEN_SHIFT)

// MCG_C1_IREFSTEN =============================
//
//   <q> Internal Reference Stop Enable (IREFSTEN)
//   <i> Determines if IRS is enabled in Stop mode [MCG_C1_IREFSTEN]
//      <0=> IR disabled in STOP
//      <1=> IR enabled in STOP
#define MCG_C1_IREFSTEN_V   0
#define MCG_C1_IREFSTEN_M   (MCG_C1_IREFSTEN_V<<MCG_C1_IREFSTEN_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 2 (MCG_C2)

// MCG_C2_LOCRE0 =============================
//
//   <q> Action on Loss of Clock (LOCRE0)
//   <i> Determines if an Interrupt or Reset occurs on loss of OSC0 external reference [MCG_C2_LOCRE0]
//   <i> This option only has effect if the clock monitor is first enabled CME0 = 1 
//      <0=> Interrupt
//      <1=> Reset
#define MCG_C2_LOCRE0_V (0)
#define MCG_C2_LOCRE0_M (MCG_C2_LOCRE0_V<<MCG_C2_LOCRE0_SHIFT)

// MCG_C2_RANGE0 =============================
//
//   <o> Frequency Range Select (RANGE0) <constant> <name=mcg_c2_range0>
//   <i> Selects the frequency range for the crystal oscillator or external clock source [MCG_C2_RANGE0]
//   <i> This value is calculated from the FLL input clock frequency
//      <0=> Low range
//      <1=> High range
//      <2=> Very High range
#define MCG_C2_RANGE0_V   1
#define MCG_C2_RANGE0_M   (MCG_C2_RANGE0_V<<MCG_C2_RANGE0_SHIFT)

// MCG_C2_HGO0 =============================
//
//   <q> Oscillator Gain (HGO0)
//   <i> Controls the crystal oscillator mode of operation [MCG_C2_HGO0]
//      <0=> Low power
//      <1=> High gain
#define MCG_C2_HGO0_V   0
#define MCG_C2_HGO0_M   (MCG_C2_HGO0_V<<MCG_C2_HGO0_SHIFT)

// MCG_C2_EREFS0 =============================
//
//   <q> External Reference Select (EREFS0) <name=mcg_c2_erefs0>
//   <i> Determines whether a clock or crystal is used for the external reference clock [C2_EREFS0]
//      <0=> External clock
//      <1=> Oscillator
#define MCG_C2_EREFS0_V  1
#define MCG_C2_EREFS0_M (MCG_C2_EREFS0_V<<MCG_C2_EREFS0_SHIFT)

// MCG_C2_LP =============================
//
//   <o> Low Power Select (LP) <constant> <name=mcg_c2_lp>
//   <i> Whether FLL or PLL continues operation when bypassed [MCG_C2_LP]
//   <i> This option is determined by the Clock Mode selection
//      <0=> FLL is enabled in bypass modes
//      <1=> FLL is disabled in bypass modes
#define MCG_C2_LP_V  0
#define MCG_C2_LP_M (MCG_C2_LP_V<<MCG_C2_LP_SHIFT)

// MCG_C2_IRCS ==============================
//
//   <q> MCG IRC Clock Source (IRCS) <name=mcg_c2_ircs>
//   <i> MCG Internal Clock Source [MCG_C2_IRCS]
//     <0=> Slow internal reference clock
//     <1=> Fast internal reference clock
#define MCG_C2_IRCS_V 0
#define MCG_C2_IRCS_M (MCG_C2_IRCS_V<<MCG_C2_IRCS_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 4 (MCG_C4)

// MCG_C4_DMX32 ==============================
//
//   <q> DMX32 DCO lock range (DMX32) <name=mcg_c4_dmx32>
//   <i> Optimise for 32.768 kHz Reference [MCG_C4_DMX32]
//     <0=> Wide lock range 31.25-39.06 kHz
//     <1=> Optimised for 32.768 kHz reference
#define MCG_C4_DMX32_V  0
#define MCG_C4_DMX32_M (MCG_C4_DMX32_V<<MCG_C4_DMX32_SHIFT)

// MCG_C4_DRST_DRS =============================
//
//   <o> DCO Range Select (DRST_DRS) <constant> <0-3> <name=mcg_c4_drst_drs>
//   <i> Frequency range for the FLL output, DCOOUT [MCG_C4_DRST_DRS]
//      <0=> Low (x640/x732, 20-25/24 MHz)
//      <1=> Mid (x1280/x1464, 40-50/48 MHz)
//      <2=> Mid-high (x1920/x2197, 60-75/72 MHz)
//      <3=> High (x2560/x2929, 80-100/96 MHz)
#define MCG_C4_DRST_DRS_V  3
#define MCG_C4_DRST_DRS_M (MCG_C4_DRST_DRS_V<<MCG_C4_DRST_DRS_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 5 (MCG_C5)

// MCG_C5_PLLREFSEL0 ==============================
//
//   <q> PLL0 External Reference Select (PLLREFSEL0) <name=mcg_c5_pllrefsel0>
//   <i> Selects PLL0 external reference clock source. [MCG_C5_PLLREFSEL0]
//     <0=> OSC0 clock is used as external reference clock.
//     <1=> OSC1 clock is used as external reference clock.
#define MCG_C5_PLLREFSEL0_V    0
#define MCG_C5_PLLREFSEL0_M   (MCG_C5_PLLREFSEL0_V<<MCG_C5_PLLREFSEL0_SHIFT)

// MCG_C5_PLLCLKEN0 ==============================
//
//   <q> PLL Clock Enable (PLLCLKEN0)
//   <i> Enables the PLL independent of PLLS and enables the PLL clock for use as MCGPLL0CLK. [MCG_C5_PLLCLKEN0]
//     <0=> MCGPLL0CLK/CLK2X are inactive.
//     <1=> MCGPLL0CLK/CLK2X are active.
#define MCG_C5_PLLCLKEN0_V    0
#define MCG_C5_PLLCLKEN0_M   (MCG_C5_PLLCLKEN0_V<<MCG_C5_PLLCLKEN0_SHIFT)

// MCG_C5_PLLSTEN0 ==============================
//
//   <q> PLL Stop Enable (PLLSTEN0)
//   <i> Enables the PLL0 Clock during Normal Stop. [MCG_C5_PLLSTEN0]
//     <0=> MCGPLL0CLK/CLK2X is disabled in any Stop mode.
//     <1=> MCGPLL0CLK/CLK2X is enabled in Normal Stop mode.
#define MCG_C5_PLLSTEN0_V    0
#define MCG_C5_PLLSTEN0_M   (MCG_C5_PLLSTEN0_V<<MCG_C5_PLLSTEN0_SHIFT)

// MCG_C5_PRDIV0 ==============================
//
//   <o> PLL External Reference Divider (PRDIV0) Divide by: <constant> <name=mcg_c5_prdiv0>  <#-1> <1-8>
//   <i> Determines the amount to divide down the external reference clock for the PLL. [MCG_C5_PRDIV0]
//   <i> This value is calculated from PLL input and output clock frequencies
#define MCG_C5_PRDIV0_V    0
#define MCG_C5_PRDIV0_M   (MCG_C5_PRDIV0_V<<MCG_C5_PRDIV0_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 6 (MCG_C6)

// MCG_C6_LOLIE0 ==============================
//
//   <q> Loss of Lock interrupt Enable (LOLIE0)
//   <i> Determines if an interrupt request is made following a loss of lock indication. [MCG_C6_LOLIE0]
//   <i> This bit only has an effect when LOLS0 is set.
//     <0=> No interrupt request
//     <1=> Interrupt request on LOL
#define MCG_C6_LOLIE0_V    0
#define MCG_C6_LOLIE0_M   (MCG_C6_LOLIE0_V<<MCG_C6_LOLIE0_SHIFT)

// MCG_C6_PLLS ==============================
//
//   <o> FLL/PLL selected as Clock source when CLKS=0 (PLLS) <constant> <name=mcg_c6_plls>
//   <i> Selects PLLCS or FLL output [MCG_C6_PLLS]
//     <0=> FLL is selected
//     <1=> PLLCS is selected
#define MCG_C6_PLLS_V    0
#define MCG_C6_PLLS_M   (MCG_C6_PLLS_V<<MCG_C6_PLLS_SHIFT)

// MCG_C6_CME0 ==============================
//
//   <q> Clock Monitor Enable (CME0)
//   <i> Determines if a reset request is made following a loss of external clock indication. [MCG_C6_CME0]
//   <i> This field must be set to a logic 1 only when the ICS is in an operational mode that uses the external clock (FEE, FBE, or FBELP).
//      <0=> Clock monitor is disabled.
//      <1=> Clock monitor is enabled.
#define MCG_C6_CME0_V (0)
#define MCG_C6_CME0_M (MCG_C6_CME0_V<<MCG_C6_CME0_SHIFT)

// MCG_C6_VDIV0 ==============================
//
//   <o> VCO Divider (VDIV0) Multiply by: <constant> <name=mcg_c6_vdiv0> <#-16> <16-47>
//   <i> Determines the multiplication factor for the reference clock of the PLL. [MCG_C6_VDIV0]
//   <i> This value is calculated from PLL input and output clock frequencies
#define MCG_C6_VDIV0_V    (29)
#define MCG_C6_VDIV0_M   (MCG_C6_VDIV0_V<<MCG_C6_VDIV0_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Status and Control Register (MCG_SC)

// MCG_SC_FCRDIV ==============================
//
//   <o> Fast Internal Clock Reference Divider (FCRDIV) <0-7> <name=mcg_sc_fcrdiv>
//   <i> Selects the amount to divide down the fast internal reference clock [MCG_SC_FCRDIV]
//   <i> The FIR clock is available for use as MCGIRCLK or MCGOUTCLK.
//   <0=> Divide by 1
//   <1=> Divide by 2
//   <2=> Divide by 4
//   <3=> Divide by 8
//   <4=> Divide by 16
//   <5=> Divide by 32
//   <6=> Divide by 64
//   <7=> Divide by 128
#define MCG_SC_FCRDIV_V  0
#define MCG_SC_FCRDIV_M (MCG_SC_FCRDIV_V<<MCG_SC_FCRDIV_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 7 (MCG_C7)

// MCG_C7_OSCSEL ==============================
//
//   <q> MCG OSC Clock Select (OSCSEL) <name=mcg_c7_oscsel>
//   <i> Selects the MCG FLL/PLL external reference clock source [MCG_C7_OSCSEL]
//     <0=> Main System Oscillator (OSCCLK0)
//     <1=> 32 kHz RTC Oscillator (OSC32KCLK)
#define MCG_C7_OSCSEL_V  0
#define MCG_C7_OSCSEL_M (MCG_C7_OSCSEL_V<<MCG_C7_OSCSEL_SHIFT)

// Check if 32kHz clock is available
#if (RTC_CR_CLKO_V != 0) && (MCG_C7_OSCSEL_V == 1)
#error "RTC Clock should be enabled to external devices for selection as MCG clock source"
#endif

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 8 (MCG_C8)

// MCG_C8_LOCRE1 ==============================
//
//   <q> RTC Loss of Clock Reset Enable (LOCRE1)
//   <i> Determines if a interrupt or a reset request is made following a loss of RTC external reference clock. [MCG_C8_LOCRE1]
//   <i> Only has an affect when CME1 is set.
//     <0=> Interrupt request
//     <1=> Reset request
#define MCG_C8_LOCRE1_V  1
#define MCG_C8_LOCRE1_M (MCG_C8_LOCRE1_V<<MCG_C8_LOCRE1_SHIFT)

// MCG_C8_CME1 ==============================
//
//   <q> Clock Monitor Enable (CME1)
//   <i> Determines if the clock monitor is enabled for the RTC external clock. [MCG_C8_CME1]
//   <i> CME1 bit must be set to a logic 0 before the MCG enters any Stop mode.
//      <0=> Clock monitor is disabled for RTC.
//      <1=> Clock monitor is enabled for RTC.
#define MCG_C8_CME1_V (0)
#define MCG_C8_CME1_M (MCG_C8_CME1_V<<MCG_C8_CME1_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 10 (MCG_C10)

// MCG_C10_LOCRE2 =============================
//
//   <q> OSC1 action on Loss of Clock (LOCRE2)
//   <i> Determines if an Interrupt or Reset occurs on loss of OSC1 external reference [MCG_C10_LOCRE2]
//   <i> This option only has effect if LOCS2 = 1 
//      <0=> Interrupt
//      <1=> Reset
#define MCG_C10_LOCRE2_V (0)
#define MCG_C10_LOCRE2_M (MCG_C10_LOCRE2_V<<MCG_C10_LOCRE2_SHIFT)

// MCG_C10_RANGE1 =============================
//
//   <o> Frequency Range Select (RANGE1) <constant> <name=mcg_c10_range1>
//   <i> Selects the frequency range for the OSC1 crystal oscillator or external clock source [MCG_C10_RANGE1]
//   <i> This value is calculated from the FLL input clock frequency
//      <0=> Low range
//      <1=> High range
//      <2=> Very High range
#define MCG_C10_RANGE1_V   0
#define MCG_C10_RANGE1_M   (MCG_C10_RANGE1_V<<MCG_C10_RANGE1_SHIFT)

// MCG_C10_HGO1 =============================
//
//   <q> Oscillator Gain (HGO1)
//   <i> Controls the OSC1 crystal oscillator mode of operation [MCG_C10_HGO1]
//      <0=> Low power
//      <1=> High gain
#define MCG_C10_HGO1_V   0
#define MCG_C10_HGO1_M   (MCG_C10_HGO1_V<<MCG_C10_HGO1_SHIFT)

// MCG_C10_EREFS1 =============================
//
//   <q> External Reference Select (EREFS1) <name=mcg_c10_erefs1>
//   <i> Determines whether a clock or crystal is used for the external reference clock [C2_EREFS1]
//      <0=> External clock
//      <1=> Oscillator
#define MCG_C10_EREFS1_V  1
#define MCG_C10_EREFS1_M (MCG_C10_EREFS1_V<<MCG_C10_EREFS1_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 11 (MCG_C11)

// MCG_C11_PLLREFSEL1 ==============================
//
//   <q> PLL1 External Reference Select (PLLREFSEL1) <name=mcg_c11_pllrefsel1>
//   <i> Selects PLL1 external reference clock source. [MCG_C11_PLLREFSEL1]
//     <0=> OSC0 clock is used as external reference clock.
//     <1=> OSC1 clock is used as external reference clock.
#define MCG_C11_PLLREFSEL1_V    0
#define MCG_C11_PLLREFSEL1_M   (MCG_C11_PLLREFSEL1_V<<MCG_C11_PLLREFSEL1_SHIFT)

// MCG_C11_PLLCLKEN1 ==============================
//
//   <q> PLL1 Clock Enable (PLLCLKEN1) 
//   <i> Enables the PLL independent of PLLS and enables the PLL clock for use as MCGPLL1CLK. [MCG_C11_PLLCLKEN1]
//     <0=> MCGPLL1CLK/CLK2X/DDRCLK2X are inactive.
//     <1=> MCGPLL1CLK/CLK2X/DDRCLK2X are active in a bypass mode with LP=1 (BLPI or BLPE).
#define MCG_C11_PLLCLKEN1_V    0
#define MCG_C11_PLLCLKEN1_M   (MCG_C11_PLLCLKEN1_V<<MCG_C11_PLLCLKEN1_SHIFT)

// MCG_C11_PLLSTEN1 ==============================
//
//   <q> PLL1 Stop Enable (PLLSTEN1)
//   <i> Enables the PLL1 Clock during Normal Stop. [MCG_C11_PLLSTEN1]
//     <0=> MCGPLL1CLK/CLK2X/DDRCLK2X is disabled in any Stop mode.
//     <1=> MCGPLL1CLK/CLK2X/DDRCLK2X is enabled in Normal Stop mode.
#define MCG_C11_PLLSTEN1_V    0
#define MCG_C11_PLLSTEN1_M   (MCG_C11_PLLSTEN1_V<<MCG_C11_PLLSTEN1_SHIFT)

// MCG_C11_PLLCS ==============================
//
//   <q> PLL Clock Select for MCGOUT (PLLCS) <name=mcg_c11_pllcs>
//   <i> Controls whether the PLL0 or PLL1 output is selected as the MCG source when
//   <i> CLKS are programmed in PLL Engaged External (PEE) mode. [MCG_C11_PLLCS]
//   <0=> PLL0 output clock is selected.
//   <1=> PLL1 output clock is selected.
#define MCG_C11_PLLCS_V    1
#define MCG_C11_PLLCS_M   (MCG_C11_PLLCS_V<<MCG_C11_PLLCS_SHIFT)

// MCG_C11_PRDIV1 ==============================
//
//   <o> PLL1 External Reference Divider (PRDIV1) Divide by: <constant> <name=mcg_c11_prdiv1>  <#-1> <1-8>
//   <i> Determines the amount to divide down the external reference clock for the PLL. [MCG_C11_PRDIV1]
//   <i> This value is calculated from PLL input and output clock frequencies
#define MCG_C11_PRDIV1_V    0
#define MCG_C11_PRDIV1_M   (MCG_C11_PRDIV1_V<<MCG_C11_PRDIV1_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 12 (MCG_C12)

// MCG_C12_LOLIE1 ==============================
//
//   <q> PLL1 Loss of Lock interrupt Enable 1 (LOLIE1)
//   <i> Determines if an interrupt request is made following a loss of lock indication for PLL1. [MCG_C12_LOLIE1]
//   <i> This bit only has an effect when LOLS1 is set.
//     <0=> No interrupt request
//     <1=> Interrupt request on LOL
#define MCG_C12_LOLIE1_V    0
#define MCG_C12_LOLIE1_M   (MCG_C12_LOLIE1_V<<MCG_C12_LOLIE1_SHIFT)

// MCG_C12_CME2 ==============================
//
//   <q> Clock Monitor Enable (CME2)
//   <i> Determines if a reset request is made following a loss of OSC1 external clock indication. [MCG_C12_CME2]
//   <i> This field must be set to a logic 1 only when the ICS is in an operational mode that uses the external clock (FEE, FBE, or FBELP).
//      <0=> Clock monitor is disabled.
//      <1=> Generates a reset request on loss of external clock.
#define MCG_C12_CME2_V (0)
#define MCG_C12_CME2_M (MCG_C12_CME2_V<<MCG_C12_CME2_SHIFT)

// MCG_C12_VDIV1 ==============================
//
//   <o> VCO1 Divider (VDIV1) Multiply by: <constant> <name=mcg_c12_vdiv1> <#-16> <16-47>
//   <i> Determines the multiplication factor for the reference clock of the PLL. [MCG_C12_VDIV1]
//   <i> This value is calculated from PLL input and output clock frequencies
#define MCG_C12_VDIV1_V    (14)
#define MCG_C12_VDIV1_M   (MCG_C12_VDIV1_V<<MCG_C12_VDIV1_SHIFT)

// </h>

// ERC_AFTER_FRDIV_CLOCK = External reference clock after dividers
#if (MCG_C2_RANGE0_V == 0) || (MCG_C7_OSCSEL_V == 1)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<MCG_C1_FRDIV_V))
#elif (MCG_C1_FRDIV_V <= 5)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<(MCG_C1_FRDIV_V+5)))
#elif (MCG_C1_FRDIV_V == 6)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<5)/40)
#elif (MCG_C1_FRDIV_V == 7)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<5)/48)
#endif

// SYSTEM_MCGFF_CLOCK  ==============================
// Only available if less than 1/8 MCGOUT clock
#if (MCG_C1_IREFS_V == 0)
#define SYSTEM_MCGFF_CLOCK ERC_AFTER_FRDIV_CLOCK  // External Reference clock after dividers
#else
#define SYSTEM_MCGFF_CLOCK SYSTEM_SLOW_IRC_CLOCK  // Slow internal clock (nominally 32 kHz)
#endif

// SYSTEM_PERIPHERAL_CLOCK  =====================================
// <h> Peripheral Clock Source Setup (Not all peripherals may be present)

// SIM_SOPT2_PLLFLLSEL =============================
//
//   <q> Peripheral clock source (PLL/FLL)
//   <i> Source for clock used by some peripherals [SIM_SOPT2_PLLFLLSEL]
//      <0=> FLL (MCGFLLCLK)
//      <1=> PLL0 (MCGPLL0CLK)
//      <2=> PLL1 (MCGPLL1CLK)
#define SIM_SOPT2_PLLFLLSEL_V  1
#define SIM_SOPT2_PLLFLLSEL_M (SIM_SOPT2_PLLFLLSEL_V<<SIM_SOPT2_PLLFLLSEL_SHIFT)

#if (SIM_SOPT2_PLLFLLSEL_V == 0) 
#define SYSTEM_PERIPHERAL_CLOCK SYSTEM_MCGFLL_CLOCK
#else
#define SYSTEM_PERIPHERAL_CLOCK SYSTEM_MCGPLL_CLOCK
#endif

// SIM_SOPT1_OSC32KSEL ================================
//
//   <o> 32kHz Clock Source (ERCLK32)
//   <i> Source for nominal 32K clock for peripherals [SIM_SOPT1_OSC32KSEL]
//     <0=> System Oscillator in 32kHz mode (OSC32KCLK)
//     <2=> RTC 32.768kHz oscillator
//     <3=> Low power oscillator (LPO - 1kHz)
#define SIM_SOPT1_OSC32KSEL_V 0
#define SIM_SOPT1_OSC32KSEL_M (SIM_SOPT1_OSC32KSEL_V<<SIM_SOPT1_OSC32KSEL_SHIFT)

#if SIM_SOPT1_OSC32KSEL_V == 0
#define SYSTEM_ERCLK32_CLOCK OSC32KCLK_CLOCK          // Main Oscillator operating in 32kHz mode
#elif SIM_SOPT1_OSC32KSEL_V == 2
#define SYSTEM_ERCLK32_CLOCK RTCCLK_CLOCK             // RTC Oscillator (depends on chip)
#elif SIM_SOPT1_OSC32KSEL_V == 3
#define SYSTEM_ERCLK32_CLOCK SYSTEM_LOW_POWER_CLOCK   // LPO
#else
#error "Invalid ERCLK32 clock selected"
#endif

// SIM_SOPT2_SDHCSRC ================================
//
//   <o> SDHC clock source select (SDHCSRC)
//   <i> Selects the clock source for the SDHC clock [SIM_SOPT2_SDHCSRC]
//     <0=> Core/system clock
//     <1=> MCGFLLCLK/MCGPLL0CLK/MCGPLL1CLK as selected by SOPT2[PLLFLLSEL]
//     <2=> OSCERCLK clock
//     <3=> External bypass clock (SDHC0_CLKIN)
#define SIM_SOPT2_SDHCSRC_V 0
#define SIM_SOPT2_SDHCSRC_M (SIM_SOPT2_SDHCSRC_V<<SIM_SOPT2_SDHCSRC_SHIFT)

// SIM_SOPT2_TIMESRC ================================
//
//   <o> IEEE 1588 timestamp clock source select (TIMESRC)
//   <i> Selects the clock source for the Ethernet timestamp clock [SIM_SOPT2_TIMESRC]
//     <0=> Core/system clock
//     <1=> MCGFLLCLK/MCGPLL0CLK/MCGPLL1CLK as selected by SOPT2[PLLFLLSEL]
//     <2=> OSCERCLK clock
//     <3=> External bypass clock (SDHC0_CLKIN)
#define SIM_SOPT2_TIMESRC_V 0
#define SIM_SOPT2_TIMESRC_M (SIM_SOPT2_TIMESRC_V<<SIM_SOPT2_TIMESRC_SHIFT)

// SIM_SOPT2_RMIISRC ================================
//
//   <o> RMII clock source select (RMIISRC)
//   <i> Selects the clock source for the Ethernet RMII interface [SIM_SOPT2_RMIISRC]
//     <0=> EXTAL clock
//     <1=> External bypass clock (ENET_1588_CLKIN)
#define SIM_SOPT2_RMIISRC_V 0
#define SIM_SOPT2_RMIISRC_M (SIM_SOPT2_RMIISRC_V<<SIM_SOPT2_RMIISRC_SHIFT)

// SIM_SOPT2_CLKOUTSEL ================================
//
//   <o> CLKOUT select (CLKOUTSEL)
//   <i> Selects the clock to output on the CLKOUT pin. [SIM_SOPT2_CLKOUTSEL]
//     <0=> FlexBus CLKOUT
//     <2=> Flash clock
//     <3=> LPO clock (1 kHz)
//     <4=> MCGIRCLK
//     <5=> RTC 32.768kHz clock
//     <6=> OSC0ERCLK
//     <6=> OSC1ERCLK
#define SIM_SOPT2_CLKOUTSEL_V 6
#define SIM_SOPT2_CLKOUTSEL_M (SIM_SOPT2_CLKOUTSEL_V<<SIM_SOPT2_CLKOUTSEL_SHIFT)

// SIM_SOPT2_RTCCLKOUTSEL ================================
//
//   <o> RTC clock out select (RTCCLKOUTSEL)
//   <i> Selects the clock to be output on the RTC_CLKOUT pin [SIM_SOPT2_RTCCLKOUTSEL]
//     <0=> RTC 1 Hz clock
//     <1=> RTC 32.768kHz clock
#define SIM_SOPT2_RTCCLKOUTSEL_V 0
#define SIM_SOPT2_RTCCLKOUTSEL_M (SIM_SOPT2_RTCCLKOUTSEL_V<<SIM_SOPT2_RTCCLKOUTSEL_SHIFT)

// SIM_SOPT2_USBSRC ================================
//
//   <o> USB clock source select (USBSRC)
//   <i> Selects the clock source for the USB 48 MHz clock [SIM_SOPT2_USBSRC]
//   <i> MCGFLLCLK/MCGPLLCLK/IRC48M choice is divided by SIM_CLKDIV2[USBFRAC, USBDIV].
//     <0=> External bypass clock (USB_CLKIN)
//     <1=> MCGFLLCLK, MCGPLL0CLK or MCGPLL1CLK as selected by SOPT2[PLLFLLSEL]
#define SIM_SOPT2_USBSRC_V 1
#define SIM_SOPT2_USBSRC_M (SIM_SOPT2_USBSRC_V<<SIM_SOPT2_USBSRC_SHIFT)

// SIM_CLKDIV2 ================================
//
//   <o> USB clock factor (USBFRAC, USBDIV)
//   <i> This field sets the USBDIV && USBFRAC values for the fractional clock divider when 
//   <i> MCGFLLCLK/MCGPLLCLK is the USB clock source (SOPT2[USBSRC] = 1) [SIM_CLKDIV2_USBDIV]
//     <1=> Multiply by 2 (USBFRAC=1, USBDIV=0)
//     <0=> Multiply by 1 (USBFRAC=0, USBDIV=0)
//     <5=> Multiply by 2/3 (USBFRAC=1, USBDIV=2)
//     <2=> Multiply by 1/2 (USBFRAC=0, USBDIV=1)
//     <9=> Multiply by 2/5 (USBFRAC=1, USBDIV=4)
//     <4=> Multiply by 1/3 (USBFRAC=0, USBDIV=2)
//     <13=> Multiply by 2/7 (USBFRAC=1, USBDIV=6)
//     <6=> Multiply by 1/4 (USBFRAC=0, USBDIV=3)
//     <8=> Multiply by 1/5 (USBFRAC=0, USBDIV=4)
//     <10=> Multiply by 1/6 (USBFRAC=0, USBDIV=5)
//     <12=> Multiply by 1/7 (USBFRAC=0, USBDIV=6)
//     <14=> Multiply by 1/8 (USBFRAC=0, USBDIV=7)
#define SIM_CLKDIV2_USB_V 0x2
#define SIM_CLKDIV2_USB_M (SIM_CLKDIV2_USB_V)

#define SYSTEM_UART0_CLOCK SystemCoreClock
#define SYSTEM_UART1_CLOCK SystemCoreClock
#define SYSTEM_UART2_CLOCK SystemBusClock
#define SYSTEM_UART3_CLOCK SystemBusClock
#define SYSTEM_UART4_CLOCK SystemBusClock
#define SYSTEM_UART5_CLOCK SystemBusClock

// </h>

// SYSTEM_OSCER0_CLOCK ================================
// Always connected to main oscillator
#define SYSTEM_OSCER0_CLOCK OSCCLK0_CLOCK

// SYSTEM_OSCER1_CLOCK ================================
// Always connected to main oscillator
#define SYSTEM_OSCER1_CLOCK OSCCLK1_CLOCK

// SYSTEM_MCGPLL_CLOCK  ==============================
#define SYSTEM_MCGPLL_CLOCK PLL_TARGET_CLOCK

// MCGFLLCLK_CLOCK  ==============================
#define SYSTEM_MCGFLL_CLOCK FLL_TARGET_CLOCK

/*
 * The following are 'public' definitions
 *
 * SYSTEM_MCGIR_CLOCK       MCG Internal Reference clock
 * SYSTEM_MCGFF_CLOCK       MCG Fixed Frequency ! (from SlowIRC/ERC_DIV/Peripheral bus clock)
 * SYSTEM_MCGFLL_CLOCK      MCG FLL clock (from FLL)
 * SYSTEM_MCGPLL_CLOCK      MCG PLL clock (from PLL)
 * SYSTEM_MCGOUT_CLOCK      MCG OUT clock (from SlowIRC/FastIRC/ExternalRC/PLL/FLL)
 * SYSTEM_PERIPHERAL_CLOCK  Peripheral clock
 * SYSTEM_OSCER0_CLOCK      Oscillator 0 clock
 * SYSTEM_OSCER1_CLOCK      Oscillator 1 clock
 * SYSTEM_OSC32K_CLOCK      32kHz oscillator/clock
 * SYSTEM_BUS_CLOCK
 * SYSTEM_CORE_CLOCK
 */

void clock_initialise(void);

#ifdef __cplusplus
}
#endif

#endif /* CLOCK_PRIVATE_H_ */
