/*
 * clock_private-MKMxx.h
 *
 *  Used for MKM33
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
// Common clock settings                                                           Core       Bus
// <validate=net.sourceforge.usbdm.annotationEditor.validators.ClockValidate_MKMxx(50000000, 25000000)>
// PLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PllClockValidate_MKMxx>
// FLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.FllClockValidate_MKMxx>

// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// OSCCLK_CLOCK ==============================
//
//   <o> Frequency of Main External Clock or Crystal (Hz)  <name=oscclk_clock> <0-48000000>
//   <i> Frequency of external crystal or clock on XTAL/EXTAL
//   <i> See MCG_C2_EREFS0 for XTAL/Clock selection
#define OSCCLK_CLOCK (8000000UL)

// SYSTEM_ERCLK32_CLOCK =============================
// Assumed to be only available when main oscillator operating with 32kHz crystal on XTAL/EXTAL
#if (OSCCLK_CLOCK < 31000) || (OSCCLK_CLOCK> 33000)
#define SYSTEM_ERCLK32_CLOCK (0)
#else
#define SYSTEM_ERCLK32_CLOCK OSCCLK_CLOCK
#endif

// SYSTEM_OSC32K_CLOCK ==============================
//
//   <o> Frequency of RTC External Clock or Crystal (Hz) <name=osc32kclk_clock>
//   <i> Frequency of external crystal or clock on XTAL32/EXTAL32 [Typically 32768 Hz]
#define SYSTEM_OSC32K_CLOCK (32768UL)

// SYSTEM_LOW_POWER_CLOCK ==============================
//
//   <o> Frequency of Internal Low Power Oscillator Clock (Hz) <constant> <name=system_low_power_clock>
//   <i> Dependent on device. [Typically ~1kHz]
#define SYSTEM_LOW_POWER_CLOCK (1000UL)

// SYSTEM_ERC_CLOCK ==============================
//
//   <o> External Reference Clock (Hz) <constant> <name=system_erc_clock>
//   <i> Derived from the external crystal or clock source on XTAL/EXTAL
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
//<i> In FEE mode, MCGOUT is derived from the FLL clock (DCOCLK) that is controlled by the external reference clock.
//<i> The FLL loop will lock the DCO frequency to the FLL factor, as selected by C4[DRST_DRS] and C4[DMX32] bits, times
//<i> the external reference frequency, as specified by the C1[FRDIV] and C2[RANGE].
//<i>
//<i> FLL Bypassed Internal(FBI)
//<i> In FBI mode, the MCGOUT clock is derived either from the slow (32 kHz IRC) or fast (4 MHz IRC) internal reference clock,
//<i> as selected by the C2[IRCS] bit. The FLL is operational but its output is not used. This mode is useful to allow the FLL
//<i> to acquire its target frequency while the MCGOUT clock is driven from the C2[IRCS] selected internal reference clock.
//<i> The FLL clock (DCOCLK) is controlled by the slow internal reference clock, and the DCO clock frequency locks to a
//<i> multiplication factor, as selected by the C4[DRST_DRS] and C4[DMX32] bits, times the internal reference frequency.
//<i>
//<i> FLL Bypassed External(FBE)
//<i> In FBE mode, the MCGOUT clock is derived from the external reference clock. The FLL is operational but its output is not
//<i> used. This mode is useful to allow the FLL to acquire its target frequency while the MCGOUT clock is driven from the
//<i> external reference clock. The FLL clock (DCOCLK) is controlled by the external reference clock, and the DCO clock frequency
//<i> locks to a multiplication factor, as selected by the C4[DRST_DRS] and C4[DMX32] bits, times the divided external reference
//<i> frequency.
//<i>
//<i> PLL Engaged External(PEE)
//<i> In PEE mode, the MCGOUTCLK is derived from the output of PLL which is controlled by a selectable external reference
//<i> clock - either RTC or RTC/OSC divided by the FRDIV reference clock. The PLL clock frequency locks to a multiplication
//<i> factor of 375 times the selected PLL reference frequency.
//<i> The FLL is disabled in a low power state.
//<i>
//<i> PLL Bypassed External(PBE)
//<i> In PBE mode, MCGOUT is derived from the OSCSEL external reference clock; the PLL is operational, but its output clock is
//<i> not used. This mode is useful to allow the PLL to acquire its target frequency while MCGOUT is driven from the external
//<i> reference clock. The PLL clock frequency locks to a multiplication factor of 375 times the PLL reference frequency.
//<i>
//<i> Bypassed Low Power Internal (BLPI/FBILP)
//<i> In BLPI mode, MCGOUT is derived from the internal reference clock.
//<i> The FLL is disabled and PLL is disabled even if the C5[PLLCLKEN] is set to 1.
//<i>
//<i> Bypassed Low Power External (BLPE/FBELP)
//<i> In BLPE mode, MCGOUT is derived from the external reference clock.
//<i> The FLL is disabled and PLL is disabled even if the C5[PLLCLKEN] is set to 1.
//<i>
//<i> PLL Engaged Internal(PEI)
//<i> In PEI mode, the MCGOUTCLK is derived from the PLL clock, which is controlled by the 32 kHz IRC reference clock.
//<i> The PLL locks to a multiplication factor times the internal reference frequency.
//<i> The FLL is disabled in a low-power state.
//<i>
//<i> PLL Bypassed Internal(PBI)
//<i> In PBI mode, MCGOUTCLK is derived from the IRCS clock select; the PLL is operational, but its output clock is not used.
//<i> This mode is useful to allow the PLL to acquire its target frequency while MCGOUTCLK is driven from the IRCS selected
//<i> reference clock. The PLL locks to a multiplication factor times the PLL reference frequency. In preparation for transition
//<i> to PEI, the PLL's programmable reference divider must be configured to produce a valid PLL reference clock.
//<i> The FLL is disabled in a low-power state.
//     <0=>  No setup (Reset default)
//     <1=>  FLL Engaged Internal (FEI)
//     <2=>  FLL Engaged External (FEE)
//     <3=>  FLL bypassed Internal (FBI)
//     <4=>  FLL bypassed Internal low power (BLPI/FBILP)
//     <5=>  FLL bypassed External (FBE)
//     <6=>  FLL bypassed External low power (BLPE/FBELP)
//     <7=>  PLL Bypassed External (PBE)
//     <8=>  PLL Engaged External (PEE)
//     <9=>  PLL Engaged Internal (PEI)
//     <10=> PLL Bypassed Internal (PBI)

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
//  <o> PLL Output clock frequency (Hz) <name=pllTargetFrequency> <constant>
//  <i> Used for MCGPLLCLK system clock
//  <i> Derived from OSC32K, FLL(after FRDIV) or IRC
//  <i> Used for main MCGOUTCLK system clock if PEE or PEI mode is selected.
#define PLL_TARGET_CLOCK 12288000UL

// FLL_TARGET_CLOCK =======================================
//
//  <o> FLL Output clock frequency (Hz) <name=fllTargetFrequency>
//  <i> Used for MCGFLLCLK system clock
//  <i> Used for main MCGOUTCLK system clock if FEI or FEE mode is selected.
#define FLL_TARGET_CLOCK 41943040UL

// SYSTEM_MCGOUT_CLOCK =======================================
//
//  <o> System MCGOUT Clock (Hz) <name=system_mcgout_clock> <constant>
//  <i> MCG Main clock output
//  <i> Derived from slow IRC, fast IRC, ERC, FLL or PLL
#define SYSTEM_MCGOUT_CLOCK 41943040UL

// SYSTEM_MCGIR_CLOCK =======================================
//
//  <o> System MCGIR Clock (Hz) <name=system_mcgir_clock> <constant>
//  <i> MCG Internal Reference Clock
//  <i> Derived from slow IRC or fast IRC divided by SC.FCRDIV
#define SYSTEM_MCGIR_CLOCK 32768UL

// SYSTEM_CORE_CLOCK =======================================
//
//  <o> System Core Clock (Hz) <name=system_core_clock> <constant>
//  <i> Clocks the ARM Cortex-M4 core
//  <i> Derived from MCGOUT Clock after division by SIM_CLKDIV1_SYSDIV
//  <i> Must be less than or equal to 50 MHz.
#define SYSTEM_CORE_CLOCK 41943040UL

// SYSTEM_BUS_CLOCK =======================================
//
//  <o> System Bus and Flash Clock (Hz) <name=system_bus_clock> <constant>
//  <i> Clocks the bus slaves & peripheral and flash
//  <i> Derived from Core Clock after division by SIM_CLKDIV1_SYSCLKMODE factor
//  <i> Must be less than or equal to 25 MHz.
#define SYSTEM_BUS_CLOCK 20971520UL

//========================================================================================
//========================================================================================
// <h> System Clock dividers

// SIM_CLKDIV1_SYSDIV ================================
//
//   <o> System Clock divider (SYSDIV) - Divide by <1-16> <#-1> <name=sim_clkdiv1_sysdiv>
//   <i> This field can be used to program Core/Platform divider [SIM_CLKDIV1_SYSDIV]
//   <i> Must be less than or equal to 48 MHz.
#define SIM_CLKDIV1_SYSDIV_V (0)
#define SIM_CLKDIV1_SYSDIV_M SIM_CLKDIV1_SYSDIV(SIM_CLKDIV1_SYSDIV_V)

// SIM_CLKDIV1_SYSCLKMODE ================================
//
//   <o> System Clock Mode <name=sim_clkdiv1_sysclkmode>
//   <i> Clock ratios [SIM_CLKDIV1_SYSCLKMODE]
//   <i> This field is used to select the System clock : Bus clock : Flash clock ratio.
//     <0=> System:Bus:Flash ratio = 1:1:1
//     <1=> System:Bus:Flash ratio = 2:1:1
#define SIM_CLKDIV1_SYSCLKMODE_V (1)
#define SIM_CLKDIV1_SYSCLKMODE_M (SIM_CLKDIV1_SYSCLKMODE_V<<SIM_CLKDIV1_SYSCLKMODE_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> OSC Control Register (OSC_CR)

// OSC_CR_ERCLKEN ===============================
//
//   <q> External Reference Enable (ERCLKEN)
//   <i> Enables external reference clock [OSC_CR_ERCLKEN]
//     <0=> Disabled
//     <1=> Enabled
#define OSC_CR_ERCLKEN_V 0
#define OSC_CR_ERCLKEN_M (OSC_CR_ERCLKEN_V<<OSC_CR_ERCLKEN_SHIFT)

// OSC_CR_EREFSTEN ===============================
//
//   <q> External Reference Stop Enable (EREFSTEN)
//   <i> Determines if external reference clock is enabled in Stop mode [OSC_CR_EREFSTEN]
//     <0=> Disabled in Stop mode
//     <1=> Enabled in Stop mode
#define OSC_CR_EREFSTEN_V 0
#define OSC_CR_EREFSTEN_M (OSC_CR_EREFSTEN_V<<OSC_CR_EREFSTEN_SHIFT)

// OSC_CR_SC2P ===============================
//
//   <q0> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC_CR_SC2P]
//     <0=>
//     <1=> +2pF

// OSC_CR_SC4P ===============================
//
//   <q1> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC_CR_SC4P]
//     <0=>
//     <1=> +4pF

// OSC_CR_SC8P ===============================
//
//   <q2> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC_CR_SC8P]
//     <0=>
//     <1=> +8pF

// OSC_CR_SC16P ===============================
//
//   <q3> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [OSC_CR_SC16P]
//     <0=>
//     <1=> +16pF

#define OSC_CR_SCP_M ((0<<OSC_CR_SC2P_SHIFT)|(1<<OSC_CR_SC4P_SHIFT)|(1<<OSC_CR_SC8P_SHIFT)|(0<<OSC_CR_SC16P_SHIFT))
// </h>

//========================================================================================
//========================================================================================
// <h> RTC OSC Control Register (RTC_GP_DATA_REG = RTC_OSC)

// RTC_OSC_OSC_DISABLE ===============================
//
//   <q> External Reference Enable (OSC_DISABLE)
//   <i> Enables external reference clock [RTC_OSC_OSC_DISABLE]
//     <0=> Enabled
//     <1=> Disabled
#define RTC_OSC_OSC_DISABLE_V 0
#define RTC_OSC_OSC_DISABLE_M (RTC_OSC_OSC_DISABLE_V<<RTC_OSC_OSC_DISABLE_SHIFT)

// RTC_OSC_SC2P ===============================
//
//   <q0> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_OSC_SC2P]
//     <0=>
//     <1=> +2pF

// RTC_OSC_SC4P ===============================
//
//   <q1> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_OSC_SC4P]
//     <0=>
//     <1=> +4pF

// RTC_OSC_SC8P ===============================
//
//   <q2> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_OSC_SC8P]
//     <0=>
//     <1=> +8pF

// RTC_OSC_SC16P ===============================
//
//   <q3> Oscillator Capacitor Load Configure
//   <i> Configures the oscillator load capacitance [RTC_OSC_SC16P]
//     <0=>
//     <1=> +16pF

#define RTC_OSC_SCP_M ((0<<RTC_OSC_SC2P_SHIFT)|(1<<RTC_OSC_SC4P_SHIFT)|(1<<RTC_OSC_SC8P_SHIFT)|(0<<RTC_OSC_SC16P_SHIFT))

// RTC_OSC_BOOT_MODE ===============================
//
//   <q> Boot mode override bit (BOOT_MODE)
//   <i> This bit can be used to override the boot to happen in VLPR mode. [RTC_OSC_BOOT_MODE]
//     <0=> Boot in RUN mode
//     <1=> Boot in VLPR mode
#define RTC_OSC_BOOT_MODE_V 0
#define RTC_OSC_BOOT_MODE_M (RTC_OSC_BOOT_MODE_V<<RTC_OSC_BOOT_MODE_SHIFT)

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
#define MCG_C1_CLKS_M (MCG_C1_CLKS_V<<MCG_C1_CLKS_SHIFT)

// MCG_C1_FRDIV ================================
//
//   <o> FLL External Reference Divider (FRDIV) <0-7> <constant> <name=mcg_c1_frdiv>
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
#define MCG_C1_IRCLKEN_V   1
#define MCG_C1_IRCLKEN_M   (1<<MCG_C1_IRCLKEN_SHIFT)

// MCG_C1_IREFSTEN =============================
//
//   <q> Internal Reference Stop Enable (IREFSTEN)
//   <i> Determines if IRS is enabled in Stop mode [MCG_C1_IREFSTEN]
//      <0=> IR disabled in STOP
//      <1=> IR enabled in STOP
#define MCG_C1_IREFSTEN_V   1
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
#define MCG_C2_EREFS0_V  0
#define MCG_C2_EREFS0_M (MCG_C2_EREFS0_V<<MCG_C2_EREFS0_SHIFT)

// MCG_C2_LP =============================
//
//   <o> Low Power Select (LP) <constant> <name=mcg_c2_lp>
//   <i> Whether FLL/PLL continues operation when bypassed [MCG_C2_LP]
//   <i> This option is determined by the Clock Mode selection
//      <0=> FLL or PLL is enabled in bypass modes
//      <1=> FLL or PLL is disabled in bypass modes
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
#define MCG_C4_DRST_DRS_V  1
#define MCG_C4_DRST_DRS_M (MCG_C4_DRST_DRS_V<<MCG_C4_DRST_DRS_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 5 (MCG_C5)

// MCG_C5_PLLCLKEN0 ==============================
//
//   <q> PLL Clock Enable (PLLCLKEN0)
//   <i> Enables the PLL independent of PLLS and enables the PLL clock for use as MCGPLLCLK. [MCG_C5_PLLCLKEN0]
//     <0=> MCGPLLCLK is inactive.
//     <1=> MCGPLLCLK is active.
#define MCG_C5_PLLCLKEN0_V    1
#define MCG_C5_PLLCLKEN0_M   (MCG_C5_PLLCLKEN0_V<<MCG_C5_PLLCLKEN0_SHIFT)

// MCG_C5_PLLSTEN0 ==============================
//
//   <q> PLL Stop Enable (PLLSTEN0)
//   <i> Enables the PLL Clock during Normal Stop. [MCG_C5_PLLSTEN0]
//     <0=> MCGPLLCLK is disabled in any Stop mode.
//     <1=> MCGPLLCLK is enabled in Normal Stop mode.
#define MCG_C5_PLLSTEN0_V    1
#define MCG_C5_PLLSTEN0_M   (MCG_C5_PLLSTEN0_V<<MCG_C5_PLLSTEN0_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 6 (MCG_C6)

// MCG_C6_LOLIE0 ==============================
//
//   <q> Loss of Lock interrupt Enable (LOLIE0)
//   <i> Determines if an interrupt request is made following a loss of lock indication. [MCG_C6_LOLIE0]
//   <i> This bit only has an effect when LOLS 0 is set.
//     <0=> No interrupt request
//     <1=> Interrupt request on LOL
#define MCG_C6_LOLIE0_V    0
#define MCG_C6_LOLIE0_M   (MCG_C6_LOLIE0_V<<MCG_C6_LOLIE0_SHIFT)

// MCG_C6_PLLS ==============================
//
//   <o> FLL/PLL selected as Clock source when CLKS=0 (PLLS) <constant> <name=mcg_c6_plls>
//   <i> Selects PLL or FLL output [MCG_C6_PLLS]
//     <0=> FLL is selected
//     <1=> PLL is selected
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

// MCG_C7_PLL32KREFSEL ==============================
//
//   <o> MCG PLL 32Khz Reference Clock Select (PLL32KREFSEL) <name=mcg_c7_pll32krefsel>
//   <i> Selects the 32kHz PLL reference clock. [MCG_C7_PLL32KREFSEL]
//     <0=> 32 kHz RTC Oscillator
//     <1=> 32 kHz Internal Reference Clock (IRC)
//     <2=> FLL input clock (after FRDIV divider)
#define MCG_C7_PLL32KREFSEL_V  0
#define MCG_C7_PLL32KREFSEL_M MCG_C7_PLL32KREFSEL(MCG_C7_PLL32KREFSEL_V)

// MCG_C7_OSCSEL ==============================
//
//   <q> MCG OSC Clock Select (OSCSEL) <name=mcg_c7_oscsel>
//   <i> Selects the MCG FLL external reference clock source [MCG_C7_OSCSEL]
//     <0=> Main System Oscillator (OSCCLK)
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
//   <q> Loss of Clock Reset Enable (LOCRE1)
//   <i> Determines if interrupt or a reset follows a loss of RTC clock [MCG_C8_LOCRE1]
//   <i> Requires MCG_C8_CME1 to have effect
//     <0=> Interrupt request
//     <1=> Reset request
#define MCG_C8_LOCRE1_V  0
#define MCG_C8_LOCRE1_M (MCG_C8_LOCRE1_V<<MCG_C8_LOCRE1_SHIFT)

// MCG_C8_LOLRE ==============================
//
//   <q> PLL Loss of Lock Reset Enable (LOLRE)
//   <i> Determines if an interrupt or a reset request follows a PLL loss of lock. [MCG_C8_LOLRE]
//     <0=> Interrupt request
//     <1=> Reset request
#define MCG_C8_LOLRE_V  0
#define MCG_C8_LOLRE_M (MCG_C8_LOLRE_V<<MCG_C8_LOLRE_SHIFT)

// MCG_C8_CME1 ==============================
//
//   <q> Clock Monitor Enable 1 (CME1)
//   <i> Enables the loss of clock monitoring circuit for the output of the RTC. [MCG_C6_CME0]
//   <i> The MCG_C8_LOCRE1 determines action (interrupt/reset)
//   <i> This field should be set to a logic 1 only when the MCG or RTC is in an operational mode that uses the external clock (FEE, FBE, or FBELP).
//      <0=> RTC clock monitor is disabled.
//      <1=> RTC clock monitor is enabled.
#define MCG_C8_CME1_V (0)
#define MCG_C8_CME1_M (MCG_C8_CME1_V<<MCG_C8_CME1_SHIFT)

// MCG_C8_COARSE_LOLIE ==============================
//
//   <q> Loss of Coarse Lock Interrrupt Enable (COARSE_LOLIE)
//   <i> Determines if an interrupt or reset follows a course loss of lock. [MCG_C8_COARSE_LOLIE]
//     <0=> Interrupt request
//     <1=> No interrupt request
#define MCG_C8_COARSE_LOLIE_V  0
#define MCG_C8_COARSE_LOLIE_M (MCG_C8_COARSE_LOLIE_V<<MCG_C8_COARSE_LOLIE_SHIFT)

// </h>

// ERC_AFTER_FRDIV_CLOCK = External reference clock after dividers
#if (MCG_C2_RANGE0_V == 0)
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

// SIM_SOPT1_OSC32KSEL ================================
//
//   <o> 32kHz Clock Source for some peripherals (OSC32KSEL)
//   <i> Source for nominal 32K clock for peripherals [SIM_SOPT1_OSC32KSEL]
//     <0=> System 32kHz Oscillator (OSC32KCLK)
//     <1=> External 32kHz reference clock (ERCLK32K)
//     <2=> MCG Internal reference clock (MCGIRCLK)
//     <3=> Low power oscillator (LPO)
#define SIM_SOPT1_OSC32KSEL_V 0
#define SIM_SOPT1_OSC32KSEL_M (SIM_SOPT1_OSC32KSEL_V<<SIM_SOPT1_OSC32KSEL_SHIFT)

#if SIM_SOPT1_OSC32KSEL_V == 0
#define SYSTEM_OSC32KSEL_CLOCK OSC32KCLK_CLOCK   // Main Oscillator operating in 32kHz mode
#elif SIM_SOPT1_OSC32KSEL_V == 1
#define SYSTEM_OSC32KSEL_CLOCK SYSTEM_ERCLK32_CLOCK   // External RTC clock pin
#elif SIM_SOPT1_OSC32KSEL_V == 2
#define SYSTEM_OSC32KSEL_CLOCK SYSTEM_MCGIRCLK_CLOCK
#elif SIM_SOPT1_OSC32KSEL_V == 3
#define SYSTEM_OSC32KSEL_CLOCK SYSTEM_LOW_POWER_CLOCK   // LPO
#endif

// SIM_CTRL_REG_CLKOUTSEL ================================
//
//   <o> CLKOUT select
//   <i> Selects the clock to output on the CLKOUT pin. [SIM_CTRL_REG_CLKOUTSEL]
//     <0=> Disabled
//     <1=> Gated Core clock
//     <2=> Bus/Flash clock
//     <3=> LPO clock from PMC
//     <4=> IRC clock from MCG
//     <5=> Multiplexed 32Khz source (ERCLK32)
//     <6=> MHz Oscillator external reference clock
//     <7=> PLL clock output from MCG
#define SIM_CTRL_REG_CLKOUTSEL_V 7
#define SIM_CTRL_REG_CLKOUTSEL_M (SIM_CTRL_REG_CLKOUTSEL_V<<SIM_CTRL_REG_CLKOUTSEL_SHIFT)

// SIM_CTRL_REG_SAR_TRG_CLK_SEL =================================
//
//   <o> SAR ADC Trigger Clk Select
//   <i> Selects the clock used to generate the ADC triggers [SIM_CTRL_REG_SAR_TRG_CLK_SEL]
//     <0=> Bus Clock
//     <1=> ADC asynchronous Clock
//     <2=> External 32kHz reference clock (ERCLK32K)
//     <3=> Main External Clock (OSCCLK)
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL_M  SIM_CTRL_REG_SAR_TRG_CLK_SEL(3)

// </h>

// SYSTEM_OSCER_CLOCK ================================
// Always connected to main oscillator
#define SYSTEM_OSCER_CLOCK OSCCLK_CLOCK

// SYSTEM_MCGPLL_CLOCK  ==============================
#define SYSTEM_MCGPLL_CLOCK PLL_TARGET_CLOCK

// MCGFLLCLK_CLOCK  ==============================
#define SYSTEM_MCGFLL_CLOCK FLL_TARGET_CLOCK

#define SYSTEM_UART0_CLOCK SystemBusClock
#define SYSTEM_UART1_CLOCK SystemCoreClock
#define SYSTEM_UART2_CLOCK SystemBusClock
#define SYSTEM_UART3_CLOCK SystemCoreClock

/*
 * The following are 'public' definitions
 *
 * SYSTEM_MCGIR_CLOCK       MCG Internal Reference clock
 * SYSTEM_MCGFF_CLOCK       MCG Fixed Frequency ! (from SlowIRC/ERC_DIV/Peripheral bus clock)
 * SYSTEM_MCGFLL_CLOCK      MCG FLL clock (from FLL)
 * SYSTEM_MCGPLL_CLOCK      MCG PLL clock (from PLL)
 * SYSTEM_MCGOUT_CLOCK      MCG OUT clock (from SlowIRC/FastIRC/ExternalRC/PLL/FLL)
 * SYSTEM_OSCER_CLOCK       System oscillator output sourced from OSCCLK
 * SYSTEM_ERCLK32_CLOCK     32kHz clock from main system oscillator when using 32kHz crystal
 * SYSTEM_OSC32K_CLOCK      RTC Oscillator 32kHz output for RTC
 * SYSTEM_OSC32KSEL_CLOCK   32kHz clock selected by SIM_SOPT1_OSC32KSEL
 * SYSTEM_BUS_CLOCK
 * SYSTEM_CORE_CLOCK
 */

void clock_initialise(void);

#ifdef __cplusplus
}
#endif

#endif /* CLOCK_PRIVATE_H_ */
