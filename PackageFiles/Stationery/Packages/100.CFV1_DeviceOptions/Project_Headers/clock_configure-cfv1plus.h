/*
 * clock_private-MKxxM7.h
 *
 *  Created on: Nov 6, 2012
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
// <validate=net.sourceforge.usbdm.annotationEditor.validators.ClockValidate_CFV1Plus>
// PLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PllClockValidate>
// FLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.FllClockValidate>

// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// OSC1CLK_CLOCK ==============================
//
//   <o> Frequency of OSC1 External Clock or Crystal (Hz)  <name=osc1clk_clock> <0-50000000>
//   <i> Frequency of external crystal or clock on XTAL/EXTAL
#define OSC1CLK_CLOCK (0UL)

// OSC32KCLK_CLOCK
// Assumed to be only available when main oscillator operating with 32kHz crystal on XTAL/EXTAL
#if (OSC2CLK_CLOCK < 31000) || (OSC2CLK_CLOCK> 33000)
#define OSC32KCLK_CLOCK (0)
#else
#define OSC32KCLK_CLOCK OSC2CLK_CLOCK
#endif

// OSC2CLK_CLOCK ==============================
//
//   <o> Frequency of OSC2 External Clock or Crystal (Hz)  <name=osc2clk_clock> <0-50000000>
//   <i> Frequency of external crystal or clock on XTAL/EXTAL
#define OSC2CLK_CLOCK (8000000UL)

// USBCLKIN_CLOCK ==============================
//
//   <o> Frequency of USB External Clock (Hz)  <name=usbclkin_clock> <constant>
//   <i> Frequency of clock on USB_CLKIN pin (if used)
#define USBCLKIN_CLOCK (48000000UL)

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
//<i> In PEE mode, the MCGOUT is derived from the PLL clock, which is controlled by the external reference clock. The PLL clock
//<i> frequency locks to a multiplication factor, as specified by C6[VDIV], times the external reference frequency, as specified
//<i> by C5[PRDIV].
//<i>
//<i> PLL Bypassed External(PBE)
//<i> In PBE mode, MCGOUT is derived from the OSCSEL external reference clock; the PLL is operational, but its output clock is
//<i> not used. This mode is useful to allow the PLL to acquire its target frequency while MCGOUT is driven from the external
//<i> reference clock. The PLL clock frequency locks to a multiplication factor, as specified by its [VDIV], times the external
//<i> reference frequency, as specified by its [PRDIV].
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

// PLL_TARGET_CLOCK =======================================
//
//  <o> PLL Output clock frequency (Hz) <48000000-100000000> <name=pllTargetFrequency>
//  <i> Used for MCGPLLCLK system clock
//  <i> Used for main MCGOUTCLK system clock if PEE mode is selected.
#define PLL_TARGET_CLOCK 96000000UL

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
#define SYSTEM_MCGIR_CLOCK 2000000UL

// SYSTEM_CORE_CLOCK =======================================
//
//  <o> System Core Clock (Hz) <name=system_core_clock> <constant>
//  <i> Clocks the CFV1 core and bus masters
//  <i> Derived from MCGOUT Clock after division by SIM_CLKDIV0_OUTDIV
//  <i> Must be less than or equal to 50 MHz.
#define SYSTEM_CORE_CLOCK 41943040UL

// SYSTEM_BUS_CLOCK =======================================
//
//  <o> System Bus Clock (Hz) <name=system_bus_clock> <constant>
//  <i> Clocks the bus slaves, flash, flexbus and peripherals
//  <i> Derived from System Core Clock after division by 2
#define SYSTEM_BUS_CLOCK 20971520UL

// SYSTEM_USB_CLOCK =======================================
//
//  <o> System USB Clock (Hz) <name=system_usb_clock> <constant>
//  <i> Clocks the USB interface
//  <i> Derived from multiple sources (see SIM_CLKDIV1)
#define SYSTEM_USB_CLOCK 48000000UL

//========================================================================================
//========================================================================================
// <h> System Clock dividers (SIM_CLKDIV0)
// SIM_CLKDIV0_OUTDIV0 ================================
//
//   <o> Core & System Clock Divider (OUTDIV0) - Divide by <1-8> <#-1> <name=sim_clkdiv0_outdiv>
//   <i> Clocks the bus slaves, flash, flexbus and peripherals
//   <i> MCGOUTCLK clock is source. Default /1
#define SIM_CLKDIV0_OUTDIV_V (1)
#define SIM_CLKDIV0_OUTDIV_M SIM_CLKDIV0_OUTDIV(SIM_CLKDIV0_OUTDIV_V)

#define SIM_CLKDIV0_M SIM_CLKDIV0_OUTDIV_M

// </h>

//========================================================================================
//========================================================================================
// <h> USB Clock dividers (SIM_CLKDIV1)
// SIM_CLKDIV0_OUTDIV0 ================================
//

// SIM_CLKDIV1_USBDIV ================================
//
//   <o> USB clock divider divisor (USBDIV) - Divide by <1-8> <#-1> <constant> <name=sim_clkdiv1_usbdiv>
//   <i> Sets the divide value applied to internal sources for USB clock
//   <i> Clock = Internal clock * (USBFRAC/USBDIV)
//   <i> This value is determined from the frequency of the chosen internal USB clock source
#define SIM_CLKDIV1_USBDIV_V (1)
#define SIM_CLKDIV1_USBDIV_M SIM_CLKDIV1_USBDIV(SIM_CLKDIV1_USBDIV_V)

// SIM_CLKDIV1_USBFRAC ================================
//
//   <o> USB clock divider fraction (USBFRAC) - Multiply by <1-2> <#-1> <constant> <name=sim_clkdiv1_usbfrac>
//   <i> Sets the fraction multiply value applied to internal sources for USB clock
//   <i> Clock = Internal clock * (USBFRAC/USBDIV)
//   <i> This value is determined from the frequency of the chosen internal USB clock source
#define SIM_CLKDIV1_USBFRAC_V (0)
#define SIM_CLKDIV1_USBFRAC_M (SIM_CLKDIV1_USBFRAC_V<<SIM_CLKDIV1_USBFRAC_SHIFT)

// SIM_CLKDIV1_USBSRC ================================
//
//   <o> USB clock source select (USBSRC) <name=sim_clkdiv1_usbsrc>
//   <i>  Source for USB clock
//   <i>  Internal sources are further multiplied or divided.
//   <0=> Divided MCGPLLCLK (reset value)
//   <1=> Divided MCGFLLCLK
//   <2=> USB_CLKIN pin
#define SIM_CLKDIV1_USBSRC_V (0)
#define SIM_CLKDIV1_USBSRC_M SIM_CLKDIV1_USBSRC(SIM_CLKDIV1_USBSRC_V)

// </h>

//========================================================================================
//========================================================================================
// <h> OSC1 Control Register (SIM_OSC1)

// SIM_OSC1_OSC1EN ===============================
//
//   <q> Oscillator 1 Enable (OSC1EN)
//   <i> Enables 32.768 kHz RTC oscillator[SIM_OSC1_OSC1EN]
//     <0=> Disabled
//     <1=> Enabled
#define SIM_OSC1_OSC1EN_V 0
#define SIM_OSC1_OSC1EN_M (SIM_OSC1_OSC1EN_V<<SIM_OSC1_OSC1EN_SHIFT)

// SIM_OSC1_OSC1RANGE ===============================
//
//   <o> Frequency Range Select (OSC1RANGE) <constant> <name=sim_osc1_osc1range>
//   <i> Selects the frequency range for the crystal oscillator or external clock source [SIM_OSC1_OSC1RANGE]
//   <i> This value is calculated from the FLL input clock frequency
//      <0=> Low range
//      <1=> Medium range
//      <2=> High range
#define SIM_OSC1_OSC1RANGE_V   1
#define SIM_OSC1_OSC1RANGE_M   (SIM_OSC1_OSC1RANGE_V<<SIM_OSC1_OSC1RANGE_SHIFT)

// SIM_OSC1_OSC1HGO =============================
//
//   <q> Oscillator Gain (OSC1HGO)
//   <i> Controls the crystal oscillator mode of operation [SIM_OSC1_OSC1HGO]
//      <0=> Low gain
//      <1=> High gain
#define SIM_OSC1_OSC1HGO_V   0
#define SIM_OSC1_OSC1HGO_M   (SIM_OSC1_OSC1HGO_V<<SIM_OSC1_OSC1HGO_SHIFT)

// SIM_OSC1_OSC1EREFS =============================
//
//   <q> External Reference Select (OSC1EREFS) <name=mcg_c2_erefs0>
//   <i> Determines whether a clock or crystal is used for the external reference clock [SIM_OSC1_OSC1EREFS]
//      <0=> External clock
//      <1=> Oscillator
#define SIM_OSC1_OSC1EREFS_V  1
#define SIM_OSC1_OSC1EREFS_M (SIM_OSC1_OSC1EREFS_V<<SIM_OSC1_OSC1EREFS_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> OSC2 Control Register (OSC1_CR)

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
#define OSC1_CR_EREFSTEN_V 1
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
// <h> OSC2 Control Register (OSC2_CR)

// OSC2_CR_ERCLKEN ===============================
//
//   <q> External Reference Enable (ERCLKEN)
//   <i> Enables external reference clock [OSC2_CR_ERCLKEN]
//     <0=> Disabled
//     <1=> Enabled
#define OSC2_CR_ERCLKEN_V 1
#define OSC2_CR_ERCLKEN_M (OSC2_CR_ERCLKEN_V<<OSC_CR_ERCLKEN_SHIFT)

// OSC2_CR_EREFSTEN ===============================
//
//   <q> External Reference Stop Enable (EREFSTEN)
//   <i> Determines if external reference clock is enabled in Stop mode [OSC2_CR_EREFSTEN]
//     <0=> Disabled in Stop mode
//     <1=> Enabled in Stop mode
#define OSC2_CR_EREFSTEN_V 1
#define OSC2_CR_EREFSTEN_M (OSC2_CR_EREFSTEN_V<<OSC_CR_EREFSTEN_SHIFT)

// OSC2_CR_SC2P ===============================
//
//   <q0> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC2_CR_SC2P]
//     <0=>
//     <1=> +2pF

// OSC2_CR_SC4P ===============================
//
//   <q1> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC2_CR_SC4P]
//     <0=>
//     <1=> +4pF

// OSC2_CR_SC8P ===============================
//
//   <q2> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC2_CR_SC8P]
//     <0=>
//     <1=> +8pF

// OSC2_CR_SC16P ===============================
//
//   <q3> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC2_CR_SC16P]
//     <0=>
//     <1=> +16pF

#define OSC2_CR_SCP_M ((0<<OSC_CR_SC2P_SHIFT)|(0<<OSC_CR_SC4P_SHIFT)|(1<<OSC_CR_SC8P_SHIFT)|(0<<OSC_CR_SC16P_SHIFT))
// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 1 (MCG_C1)

// MCG_C1_CLKS =======================================
//
//  <o> MCGOUTCLK Clock Source Select (CLKS) [0-2] <constant> <name=mcg_c1_clks>
//  <i> Selects the clock source for MCGOUTCLK [MCG_C1_CLKS]
//  <i> This option is determined by the Clock Mode selection
//      <0=> Output of FLL or PLL is selected
//      <1=> Internal reference clock is selected
//      <2=> External reference clock is selected
#define MCG_C1_CLKS_V 0
#define MCG_C1_CLKS_M MCG_C1_CLKS(MCG_C1_CLKS_V)

// MCG_C1_FRDIV ================================
//
//   <o> FLL External Reference Divider (FRDIV) <constant> <name=mcg_c1_frdiv>
//   <i> Selects the amount to divide down the external reference clock for the FLL. [MCG_C1_FRDIV]
//   <i> The resulting frequency must be in the range 31.25 kHz to 39.0625 kHz
//   <i> Division factor depends on Clock Range [MGC_C2_RANGE0]
//   <i> This option is determined by the Clock Mode and FLL input clock
//      <0=> Divide by 1 or 32
//      <1=> Divide by 2 or 64
//      <2=> Divide by 4 or 128
//      <3=> Divide by 8 or 256
//      <4=> Divide by 16 or 512
//      <5=> Divide by 32 or 1024
//      <6=> Divide by 64 or 1280
//      <7=> Divide by 128 or 1536
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

// MCG_C2_RANGE =============================
//
//   <o> Frequency Range Select (RANGE0) <constant> <name=mcg_c2_range0>
//   <i> Selects the frequency range for the crystal oscillator or external clock source [MCG_C2_RANGE]
//   <i> This value is calculated from the FLL input clock frequency
//      <0=> Low range
//      <1=> High range
//      <2=> Very High range
#define MCG_C2_RANGE_V   1
#define MCG_C2_RANGE_M   (MCG_C2_RANGE_V<<MCG_C2_RANGE_SHIFT)

// MCG_C2_HGO =============================
//
//   <q> Oscillator Gain (HGO0)
//   <i> Controls the crystal oscillator mode of operation [MCG_C2_HGO]
//      <0=> Low gain
//      <1=> High gain
#define MCG_C2_HGO_V   0
#define MCG_C2_HGO_M   (MCG_C2_HGO_V<<MCG_C2_HGO_SHIFT)

// MCG_C2_EREFS =============================
//
//   <q> External Reference Select (EREFS0) <name=mcg_c2_erefs0>
//   <i> Determines whether a clock or crystal is used for the external reference clock [C2_EREFS0]
//      <0=> External clock
//      <1=> Oscillator
#define MCG_C2_EREFS_V  1
#define MCG_C2_EREFS_M (MCG_C2_EREFS_V<<MCG_C2_EREFS_SHIFT)

// MCG_C2_LP =============================
//
//   <o> Low Power Select (LP) <constant> <name=mcg_c2_lp>
//   <i> Whether FLL continues operation when bypassed [MCG_C2_LP]
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
#define MCG_C2_IRCS_V 1
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
//      <0=> Low (x640/x732, 24/20-25 MHz)
//      <1=> Mid (x1280/x1464, 48/40-50 MHz)
//      <2=> Mid-high (x1920/x2197, 72/60-75 MHz)
//      <3=> High (x2560/x2929, 96/80-100 MHz)
#define MCG_C4_DRST_DRS_V  3
#define MCG_C4_DRST_DRS_M (MCG_C4_DRST_DRS_V<<MCG_C4_DRST_DRS_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 5 (MCG_C5)

// MCG_C5_PLLCLKEN ==============================
//
//   <q> PLL Clock Enable (PLLCLKEN0)
//   <i> Enables the PLL independent of PLLS and enables the PLL clock for use as MCGPLLCLK. [MCG_C5_PLLCLKEN]
//     <0=> MCGPLLCLK is inactive.
//     <1=> MCGPLLCLK is active.
#define MCG_C5_PLLCLKEN_V    1
#define MCG_C5_PLLCLKEN_M   (MCG_C5_PLLCLKEN_V<<MCG_C5_PLLCLKEN_SHIFT)

// MCG_C5_PLLSTEN ==============================
//
//   <q> PLL Stop Enable (PLLSTEN0)
//   <i> Enables the PLL Clock during Normal Stop. [MCG_C5_PLLSTEN]
//     <0=> MCGPLLCLK is disabled in any Stop mode.
//     <1=> MCGPLLCLK is enabled in Normal Stop mode.
#define MCG_C5_PLLSTEN_V    1
#define MCG_C5_PLLSTEN_M   (MCG_C5_PLLSTEN_V<<MCG_C5_PLLSTEN_SHIFT)

// MCG_C5_PRDIV ==============================
//
//   <o> PLL External Reference Divider (PRDIV0) Divide by: <name=mcg_c5_prdiv0> <constant> <#-1> <1-24>
//   <i> Determines the amount to divide down the external reference clock for the PLL. [MCG_C5_PRDIV]
//   <i> This value is calculated from PLL input and output clock frequencies
#define MCG_C5_PRDIV_V    1
#define MCG_C5_PRDIV_M   (MCG_C5_PRDIV_V<<MCG_C5_PRDIV_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 6 (MCG_C6)

// MCG_C6_LOLIE ==============================
//
//   <q> Loss of Lock interrupt Enable (LOLIE0)
//   <i> Determines if an interrupt request is made following a loss of lock indication. [MCG_C6_LOLIE]
//   <i> This bit only has an effect when LOLS 0 is set.
//     <0=> No interrupt request
//     <1=> Interrupt request on LOL
#define MCG_C6_LOLIE_V    0
#define MCG_C6_LOLIE_M   (MCG_C6_LOLIE_V<<MCG_C6_LOLIE_SHIFT)

// MCG_C6_PLLS ==============================
//
//   <o> FLL/PLL selected as Clock source when CLKS=0 (PLLS) <constant> <name=mcg_c6_plls>
//   <i> Selects PLL or FLL output [MCG_C6_PLLS]
//   <i> This value is determined from the clock mode
//     <0=> FLL is selected
//     <1=> PLL is selected
#define MCG_C6_PLLS_V    0
#define MCG_C6_PLLS_M   (MCG_C6_PLLS_V<<MCG_C6_PLLS_SHIFT)

// MCG_C6_CME ==============================
//
//   <q> Clock Monitor Enable (CME0)
//   <i> Determines if a reset request is made following a loss of external clock indication. [MCG_C6_CME]
//   <i> This field must be set to a logic 1 only when the ICS is in an operational mode that uses the external clock (FEE, FBE, or FBELP).
//      <0=> Clock monitor is disabled.
//      <1=> Generates a reset request on loss of external clock.
#define MCG_C6_CME_V (0)
#define MCG_C6_CME_M (MCG_C6_CME_V<<MCG_C6_CME_SHIFT)

// MCG_C6_VDIV ==============================
//
//   <o> VCO Divider (VDIV0) Multiply by: <name=mcg_c6_vdiv0> <constant> <#-24>
//   <i> Determines the multiplication factor for the reference clock of the PLL. [MCG_C6_VDIV]
//   <i> This value is calculated from PLL input and output clock frequencies
#define MCG_C6_VDIV_V    (0)
#define MCG_C6_VDIV_M   (MCG_C6_VDIV_V<<MCG_C6_VDIV_SHIFT)

// </h>

// ERC_AFTER_FRDIV_CLOCK = External reference clock after dividers
#if (MCG_C2_RANGE_V == 0)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<MCG_C1_FRDIV_V))
#elif (MCG_C1_FRDIV_V <= 5)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<(MCG_C1_FRDIV_V+5)))
#elif (MCG_C1_FRDIV_V == 6)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<5)/40)
#elif (MCG_C1_FRDIV_V == 7)
#define ERC_AFTER_FRDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<5)/48)
#endif // (MCG_C1_IREFS_V == 0)

// SYSTEM_MCGFF_CLOCK  ==============================
// Only available if less than 1/8 MCGOUT clock
#if (MCG_C1_IREFS_V == 0)
#define SYSTEM_MCGFF_CLOCK ERC_AFTER_FRDIV_CLOCK  // External Reference clock after dividers
#else
#define SYSTEM_MCGFF_CLOCK SYSTEM_SLOW_IRC_CLOCK  // Slow internal clock (nominally 32 kHz)
#endif

#define SYSTEM_UART0_CLOCK SystemCoreClock
#define SYSTEM_UART1_CLOCK SystemCoreClock
#define SYSTEM_UART2_CLOCK SystemBusClock
#define SYSTEM_UART3_CLOCK SystemBusClock
#define SYSTEM_UART4_CLOCK SystemBusClock
#define SYSTEM_UART5_CLOCK SystemBusClock

// SYSTEM_OSCER_CLOCK ================================
// Always connected to main oscillator
#define SYSTEM_OSCER_CLOCK OSC2CLK_CLOCK

// SYSTEM_MCGPLL_CLOCK  ==============================
#define SYSTEM_MCGPLL_CLOCK PLL_TARGET_CLOCK

// MCGFLLCLK_CLOCK  ==============================
#define SYSTEM_MCGFLL_CLOCK FLL_TARGET_CLOCK

/*
 * The following are 'public' definitions
 *
 * SYSTEM_MCGIR_CLOCK   	MCG Internal Reference clock
 * SYSTEM_MCGFF_CLOCK  		MCG Fixed Frequency ! (from SlowIRC/ERC_DIV/Peripheral bus clock)
 * SYSTEM_MCGFLL_CLOCK  	MCG FLL clock (from FLL)
 * SYSTEM_MCGPLL_CLOCK  	MCG PLL clock (from PLL)
 * SYSTEM_MCGOUT_CLOCK      MCG OUT clock (from SlowIRC/FastIRC/ExternalRC/PLL/FLL)
 * SYSTEM_OSCER_CLOCK		Main oscillator/clock
 * SYSTEM_OSC32K_CLOCK      32kHz oscillator/clock
 * SYSTEM_BUS_CLOCK
 * SYSTEM_CORE_CLOCK
 */

void clock_initialise(void);

#ifdef __cplusplus
}
#endif

#endif /* CLOCK_PRIVATE_H_ */
