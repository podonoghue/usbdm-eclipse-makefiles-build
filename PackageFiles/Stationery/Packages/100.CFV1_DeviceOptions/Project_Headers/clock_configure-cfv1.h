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
// <validate=net.sourceforge.usbdm.annotationEditor.validators.ClockValidate_CFV1>
// PLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PllClockValidate_CFV1>
// FLL clock
// <validate=net.sourceforge.usbdm.annotationEditor.validators.FllClockValidate_CFV1>

// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// OSCCLK_CLOCK ==============================
//
//   <o> Frequency of OSC External Clock or Crystal (Hz)  <name=oscclk_clock> <0-50000000>
//   <i> Frequency of external crystal or clock on XTAL/EXTAL
#define OSCCLK_CLOCK (8000000UL)

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
//   <o> Frequency of Slow Internal Reference Clock (Hz) <name=system_slow_irc_clock>
//   <i> Dependent on device and clock Trim. [Typically ~32kHz]
#define SYSTEM_SLOW_IRC_CLOCK (32768UL)

//========================================================================================
//========================================================================================
// CLOCK_MODE ===============================
//
//   <o> Clock Mode <name=clock_mode>
//   <i> Basic choice for final clock mode
//<i> FLL Engaged Internal(FEI)
//<i> In FEI mode, MCGOUT is derived from the FLL clock (DCOCLK) that is controlled by the 32 kHz Internal Reference Clock (IRC).
//<i> The FLL loop will lock the DCO frequency to the FLL factor, as selected by the C4[DRS] and C4[DMX32] bits, times the
//<i> internal reference frequency.
//<i>
//<i> FLL Engaged External(FEE)
//<i> In FEE mode, MCGOUT is derived from the FLL clock (DCOCLK) that is controlled by the external reference clock. The FLL loop
//<i> will lock the DCO frequency to the FLL factor, as selected by C4[DRS] and C4[DMX32] bits, times the external reference
//<i> frequency, as specified by the C1[RDIV] and C2[RANGE].
//<i>
//<i> FLL Bypassed Internal(FBI)
//<i> In FBI mode, the MCGOUT clock is derived from the slow (32 kHz IRC) internal reference clock. The FLL is operational but
//<i> its output is not used. This mode is useful to allow the FLL to acquire its target frequency while the MCGOUT clock is
//<i> driven from the C2[IRCS] selected internal reference clock. The FLL clock (DCOCLK) is controlled by the slow internal
//<i> reference clock, and the DCO clock frequency locks to a multiplication factor, as selected by the C4[DRS] and
//<i> C4[DMX32] bits, times the internal reference frequency.
//<i>
//<i> FLL Bypassed External(FBE)
//<i> In FBE mode, the MCGOUT clock is derived from the external reference clock. The FLL is operational but its output is not
//<i> used. This mode is useful to allow the FLL to acquire its target frequency while the MCGOUT clock is driven from the
//<i> external reference clock. The FLL clock (DCOCLK) is controlled by the external reference clock, and the DCO clock frequency
//<i> locks to a multiplication factor, as selected by the C4[DRS] and C4[DMX32] bits, times the divided external reference
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
//<i> In BLPI mode, MCGOUT is derived from the internal reference clock. The FLL and PLL are disabled.
//<i>
//<i> Bypassed Low Power External (BLPE/FBELP)
//<i> In BLPE mode, MCGOUT is derived from the external reference clock. The FLL and PLL are disabled.
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
#define PLL_TARGET_CLOCK 48000000UL

// FLL_TARGET_CLOCK =======================================
//
//  <o> FLL Output clock frequency (Hz) <name=fllTargetFrequency>
//  <i> Used for MCGFLLCLK system clock
//  <i> Used for main MCGOUTCLK system clock if FEI or FEE mode is selected.
#define FLL_TARGET_CLOCK 33554432UL

// SYSTEM_MCGOUT_CLOCK =======================================
//
//  <o> System MCGOUT Clock (Hz) <name=system_mcgout_clock> <constant>
//  <i> MCG Main clock output
//  <i> Derived from slow IRC, fast IRC, ERC, FLL or PLL
#define SYSTEM_MCGOUT_CLOCK 33554432UL

// SYSTEM_MCGIR_CLOCK =======================================
//
//  <o> System MCGIR Clock (Hz) <name=system_mcgir_clock> <constant>
//  <i> MCG Internal Reference Clock
//  <i> Derived from slow IRC or fast IRC
#define SYSTEM_MCGIR_CLOCK 32768UL

// SYSTEM_CORE_CLOCK =======================================
//
//  <o> System Core Clock (Hz) <name=system_core_clock> <constant>
//  <i> Clocks the CFV1 core and bus masters
//  <i> Derived from MCGOUT Clock after division by SIM_CLKDIV0_OUTDIV
//  <i> Must be less than or equal to 50 MHz.
#define SYSTEM_CORE_CLOCK 33554432UL

// SYSTEM_BUS_CLOCK =======================================
//
//  <o> System Bus Clock (Hz) <name=system_bus_clock> <constant>
//  <i> Clocks the bus slaves, flash, flexbus and peripherals
//  <i> Derived from System Core Clock after division by 2
#define SYSTEM_BUS_CLOCK 16777216UL

// SYSTEM_USB_CLOCK =======================================
//
//  <o> System USB Clock (Hz) <name=system_usb_clock> <constant>
//  <i> Clocks the USB interface
//  <i> Derived from multiple sources (see SIM_CLKDIV1)
#define SYSTEM_USB_CLOCK 48000000UL

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
#define SIM_CLKDIV1_USBDIV_V (0)
#define SIM_CLKDIV1_USBDIV_M SIM_CLKDIV1_USBDIV(SIM_CLKDIV1_USBDIV_V)

// SIM_CLKDIV1_USBFRAC ================================
//
//   <o> USB clock divider fraction (USBFRAC) - Multiply by <1-2> <#-1> <constant> <name=sim_clkdiv1_usbfrac>
//   <i> Sets the fraction multiply value applied to internal sources for USB clock
//   <i> Clock = Internal clock * (USBFRAC/USBDIV)
//   <i> This value is determined from the frequency of the chosen internal USB clock source
#define SIM_CLKDIV1_USBFRAC_V (0)
#define SIM_CLKDIV1_USBFRAC_M (SIM_CLKDIV1_USBFRAC_V<<SIM_CLKDIV1_USBFRAC_BITNUM)

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
// <h> MCG Control Register 1 (MCGC1)

// MCGC1_CLKS =======================================
//
//  <o> MCGOUTCLK Clock Source Select (CLKS) [0-2] <constant> <name=mcg_c1_clks>
//  <i> Selects the clock source for MCGOUTCLK [MCGC1_CLKS]
//  <i> This option is determined by the Clock Mode selection
//      <0=> Output of FLL or PLL is selected
//      <1=> Internal reference clock is selected
//      <2=> External reference clock is selected
#define MCGC1_CLKS_V 0
#define MCGC1_CLKS_M (MCGC1_CLKS_V<<MCGC1_CLKS_BITNUM)

// MCGC1_RDIV ================================
//
//   <o> FLL External Reference Divider (RDIV) <constant> <name=mcg_c1_rdiv>
//   <i> Selects the amount to divide down the external reference clock for the FLL or PLL. [MCGC1_RDIV]
//   <i> The resulting frequency must be in the range 31.25 kHz to 39.0625 kHz for the FLL
//   <i> The resulting frequency must be in the range 1 Mhz to 2 MHz for the PLL
//   <i> Division factor depends on Clock Range when using FLL [MGC_C2_RANGE]
//   <i> This option is determined by the Clock Mode and FLL input clock
//      <0=> Divide by 1 or 32
//      <1=> Divide by 2 or 64
//      <2=> Divide by 4 or 128
//      <3=> Divide by 8 or 256
//      <4=> Divide by 16 or 512
//      <5=> Divide by 32 or 1024
//      <6=> Divide by 64
//      <7=> Divide by 128
#define MCGC1_RDIV_V 3
#define MCGC1_RDIV_M (MCGC1_RDIV_V<<MCGC1_RDIV_BITNUM)

// MCGC1_IREFS ================================
//
//   <o> Internal Reference Select (IREFS) <constant> <name=mcg_c1_irefs>
//   <i> Selects the reference clock source for the FLL [MCGC1_IREFS]
//   <i> This option is determined by the Clock Mode selection
//      <0=> External Reference Clock
//      <1=> Slow Internal Clock
#define MCGC1_IREFS_V 1
#define MCGC1_IREFS_M (MCGC1_IREFS_V?MCGC1_IREFS_MASK:0)

// MCGC1_IRCLKEN ==============================
//
//   <q> Internal Reference Clock Enable (IRCLKEN)
//   <i> Enables the internal reference clock for use as MCGIRCLK [MCGC1_IRCLKEN]
//      <0=> Inactive
//      <1=> Active
#define MCGC1_IRCLKEN_V   0
#define MCGC1_IRCLKEN_M   (MCGC1_IRCLKEN_V?MCGC1_IRCLKEN_MASK:0)

// MCGC1_IREFSTEN =============================
//
//   <q> Internal Reference Stop Enable (IREFSTEN)
//   <i> Determines if IRS is enabled in Stop mode [MCGC1_IREFSTEN]
//      <0=> IR disabled in STOP
//      <1=> IR enabled in STOP
#define MCGC1_IREFSTEN_V   0
#define MCGC1_IREFSTEN_M   (MCGC1_IREFSTEN_V?MCGC1_IREFSTEN_MASK:0)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 2 (MCGC2)

// MCGC2_BDIV =============================
//
//   <o> Bus Frequency Divider (BDIV) <name=mcg_c2_bdiv>
//   <i> Selects the amount to divide down the clock for the bus clock [MCGC2_BDIV]
//   <i> Clock source is MCGOUT
//      <0=> Divide by 1
//      <1=> Divide by 2
//      <2=> Divide by 4
//      <2=> Divide by 8
#define MCGC2_BDIV_V   0
#define MCGC2_BDIV_M   (MCGC2_BDIV_V<<MCGC2_BDIV_BITNUM)

// MCGC2_RANGE =============================
//
//   <o> Frequency Range Select (RANGE0) <constant> <name=mcg_c2_range>
//   <i> Selects the frequency range for the crystal oscillator or external clock source [MCGC2_RANGE]
//   <i> This value is calculated from the FLL input clock frequency
//      <0=> Low range
//      <1=> High range
#define MCGC2_RANGE_V   1
#define MCGC2_RANGE_M   (MCGC2_RANGE_V?MCGC2_RANGE_MASK:0)

// MCGC2_HGO =============================
//
//   <q> Oscillator Gain (HGO0)
//   <i> Controls the crystal oscillator mode of operation [MCGC2_HGO]
//      <0=> Low gain
//      <1=> High gain
#define MCGC2_HGO_V   0
#define MCGC2_HGO_M   (MCGC2_HGO_V?MCGC2_HGO_MASK:0)

// MCGC2_LP =============================
//
//   <o> Low Power Select (LP) <constant> <name=mcg_c2_lp>
//   <i> Whether FLL continues operation when bypassed [MCGC2_LP]
//   <i> This option is determined by the Clock Mode selection
//      <0=> FLL or PLL is enabled in bypass modes
//      <1=> FLL or PLL is disabled in bypass modes
#define MCGC2_LP_V  0
#define MCGC2_LP_M (MCGC2_LP_V?MCGC2_LP_MASK:0)

// MCGC2_EREFS =============================
//
//   <q> External Reference Select (EREFS0) <name=mcg_c2_erefs0>
//   <i> Determines whether a clock or crystal is used for the external reference clock [C2_EREFS0]
//      <0=> External clock
//      <1=> Oscillator
#define MCGC2_EREFS_V  1
#define MCGC2_EREFS_M (MCGC2_EREFS_V?MCGC2_EREFS_MASK:0)

// MCGC2_ERCLKEN ===============================
//
//   <q> External Reference Enable (ERCLKEN)
//   <i> Enables external reference clock [MCGC2_ERCLKEN]
//     <0=> Disabled
//     <1=> Enabled
#define MCGC2_ERCLKEN_V 0
#define MCGC2_ERCLKEN_M (MCGC2_ERCLKEN_V?MCGC2_ERCLKEN_MASK:0)

// MCGC2_EREFSTEN ===============================
//
//   <q> External Reference Stop Enable (EREFSTEN)
//   <i> Determines if external reference clock is enabled in Stop mode [MCGC2_EREFSTEN]
//     <0=> Disabled in Stop mode
//     <1=> Enabled in Stop mode
#define MCGC2_EREFSTEN_V 1
#define MCGC2_EREFSTEN_M (MCGC2_EREFSTEN_V?MCGC2_EREFSTEN_MASK:0)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 6 (MCGC3)

// MCGC3_LOLIE ==============================
//
//   <q> Loss of Lock interrupt Enable (LOLIE0)
//   <i> Determines if an interrupt request is made following a loss of lock indication. [MCGC3_LOLIE]
//   <i> This bit only has an effect when LOLS 0 is set.
//     <0=> No interrupt request
//     <1=> Interrupt request on LOL
#define MCGC3_LOLIE_V    0
#define MCGC3_LOLIE_M   (MCGC3_LOLIE_V?MCGC3_LOLIE_MASK:0)

// MCGC3_PLLS ==============================
//
//   <o> FLL/PLL selected as Clock source when CLKS=0 (PLLS) <constant> <name=mcg_c3_plls>
//   <i> Selects PLL or FLL output [MCGC3_PLLS]
//   <i> This value is determined from the clock mode
//     <0=> FLL is selected
//     <1=> PLL is selected
#define MCGC3_PLLS_V    0
#define MCGC3_PLLS_M   (MCGC3_PLLS_V?MCGC3_PLLS_MASK:0)

// MCGC3_CME ==============================
//
//   <q> Clock Monitor Enable (CME)
//   <i> Determines if a reset request is made following a loss of external clock indication. [MCGC3_CME]
//   <i> This field must be set to a logic 1 only when the ICS is in an operational mode that uses the external clock (FEE, FBE, or FBELP).
//      <0=> Clock monitor is disabled.
//      <1=> Generates a reset request on loss of external clock.
#define MCGC3_CME_V (0)
#define MCGC3_CME_M (MCGC3_CME_V?MCGC3_CME_MASK:0)

// MCGC3_DIV32 ==============================
//
//   <q> Divide-by-32 Enable (DIV32) <name=mcg_c3_div32> <constant> <#-24>
//   <i> Controls an additional divide-by-32 factor to the external reference clock.
//   <i> Only applies for FLL is selected and MCGC2_RANGE=1 [MCGC3_DIV32]
//   <i> This value is determined from the FLL input clock frequency
//   <0=> Divide-by-32 is disabled.
//   <1=> Divide-by-32 is enabled when RANGE=1.
#define MCGC3_DIV32_V    (-23)
#define MCGC3_DIV32_M   (MCGC3_DIV32_V?MCGC3_DIV32_MASK:0)

// MCGC3_VDIV ==============================
//
//   <o> VCO Divider (VDIV0) Multiply by: <name=mcg_c3_vdiv> <constant> <#/4> <4-48:4>
//   <i> Determines the multiplication factor for the reference clock of the PLL. [MCGC3_VDIV]
//   <i> This value is calculated from PLL input and output clock frequencies
#define MCGC3_VDIV_V    (6)
#define MCGC3_VDIV_M   (MCGC3_VDIV_V<<MCGC3_VDIV_BITNUM)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 4 (MCGC4)

// MCGC4_DMX32 ==============================
//
//   <q> DMX32 DCO lock range (DMX32) <name=mcg_c4_dmx32>
//   <i> Optimise for 32.768 kHz Reference [MCGC4_DMX32]
//     <0=> Wide lock range 31.25-39.06 kHz
//     <1=> Optimised for 32.768 kHz reference
#define MCGC4_DMX32_V  0
#define MCGC4_DMX32_M (MCGC4_DMX32_V?MCGC4_DMX32_MASK:0)

// MCGC4_DRS =============================
//
//   <o> DCO Range Select (DRS) <constant> <0-3> <name=mcg_c4_drs>
//   <i> Frequency range for the FLL output, DCOOUT [MCGC4_DRS]
//     <0=> Low (x512/x608, 19.92/16-20 MHz)
//     <1=> Mid (x1024/x1216, 39.85/32-40 MHz)
//     <2=> High (x1536/x1824, 59.77/48-60 MHz)
#define MCGC4_DRS_V  1
#define MCGC4_DRS_M (MCGC4_DRS_V<<MCGC4_DRST_DRS_BITNUM)

// </h>

// ERC_AFTER_RDIV_CLOCK = External reference clock after dividers
#if (MCGC2_RANGE_V == 0)
#define ERC_AFTER_RDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<MCGC1_RDIV_V))
#elif (MCGC1_RDIV_V <= 5)
#define ERC_AFTER_RDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<(MCGC1_RDIV_V+5)))
#elif (MCGC1_RDIV_V == 6)
#define ERC_AFTER_RDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<5)/40)
#elif (MCGC1_RDIV_V == 7)
#define ERC_AFTER_RDIV_CLOCK (SYSTEM_OSCER_CLOCK/(1<<5)/48)
#endif

// SYSTEM_MCGFF_CLOCK  ==============================
// Only available if less than 1/8 MCGOUT clock
#if (MCGC1_IREFS_V == 0)
#define SYSTEM_MCGFF_CLOCK ERC_AFTER_RDIV_CLOCK  // External Reference clock after dividers
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
