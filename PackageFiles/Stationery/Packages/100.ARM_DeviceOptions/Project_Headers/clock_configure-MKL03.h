/*
 * clock_private-MKL03.h
 *
 * Used for MKL03 MKL43
 *
 * Based on KL03P24M48SF0RM
 *   Oscillators (IRC48M, IRC8M, OSC, RTC)
 *
 * Used with:
 *   clock-MKL03.c
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
// Common clock settings                                                             Core       Bus
// <validate=net.sourceforge.usbdm.annotationEditor.validators.ClockValidate_KLxx_LP(48000000, 24000000)>

// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// OSCCLK_CLOCK ==============================
//
//   <o> Frequency of Main External Clock or Crystal (Hz)  <name=oscclk_clock> <0-48000000>
//   <i> Frequency of external crystal or clock on XTAL/EXTAL
//   <i> See MCG_C2_EREFS0 for XTAL/Clock selection
#define OSCCLK_CLOCK (32768UL)

// OSC32KCLK_CLOCK
// Assumed to be only available when main oscillator operating with 32kHz crystal on XTAL/EXTAL
#if (OSCCLK_CLOCK < 32000) || (OSCCLK_CLOCK> 40000)
#define OSC32KCLK_CLOCK (0)
#else
#define OSC32KCLK_CLOCK OSCCLK_CLOCK
#endif

// RTC_CLKIN_CLOCK ==============================
//
//   <o> Frequency of RTC external clock (Hz)  <name=rtcclkin_clock>
//   <i> Frequency of external clock provided to RTC clock input pin [Typically 32768 Hz]
#define RTC_CLKIN_CLOCK (0)

// SYSTEM_LOW_POWER_CLOCK ==============================
//
//   <o> Frequency of Internal Low Power Oscillator Clock (Hz) <constant> <name=system_low_power_clock>
//   <i> Dependent on device. [Typically ~1kHz]
#define SYSTEM_LOW_POWER_CLOCK (1000UL)

// IRC48M_CLOCK ==============================
// <o> Frequency of Internal 48MHz Clock <name=irc48m_clock> <constant>
// <i> 48 MHz Internal Oscillator [Trimmed against USB bus]
#define IRC48M_CLOCK (48000000UL)

// IRC2M_CLOCK ==============================
//
//   <o> Frequency of Internal Low Power Oscillator 2MHz Clock <constant> <name=irc2m_clock>
//   <i> Dependent on device and clock Trim. [Typically ~2MHz]
#define IRC2M_CLOCK (2000000UL)

// IRC8M_CLOCK ==============================
//
//   <o> Frequency of Internal Low Power Oscillator 8MHz Clock <constant> <name=irc8m_clock>
//   <i> Dependent on device and clock Trim. [Typically ~8MHz]
#define IRC8M_CLOCK (8000000UL)

//========================================================================================
//========================================================================================
// CLOCK_MODE ===============================
//
//   <o> Clock Mode <name=clock_mode>
//   <i> Basic choice for final clock mode
//<i> None            -  No setup done
//<i> LIRC_8MHZ -  8 MHz low power internal reference clock
//<i> LIRC_2MHZ -  2 MHz low power internal reference clock
//<i> HIRC             -  48MHz high speed internal reference clock
//<i> EXT                -  External reference clock
//<i>
//     <0=> No setup (Reset default = LIRC_8MHz)
//     <1=> LIRC_8MHZ - 8 MHz low power internal clock
//     <2=> LIRC_2MHZ - 2 MHz low power internal clock
//     <3=> HIRC - High speed internal clock
//     <4=> EXT - External clock
#define CLOCK_MODE 3

// Clock modes
#define CLOCK_MODE_NONE       0
#define CLOCK_MODE_LIRC_8_MHZ 1
#define CLOCK_MODE_LIRC_2_MHZ 2
#define CLOCK_MODE_HIRC       3
#define CLOCK_MODE_EXT        4

// SYSTEM_FLASH_CLOCK =======================================
//
// Not used
#define SYSTEM_FLASH_CLOCK SYSTEM_BUS_CLOCK

// SYSTEM_MCGOUT_CLOCK =======================================
//
//  <o> System MCGOUT Clock (Hz) <name=system_mcgout_clock> <constant>
//  <i> MCG Main clock output
//  <i> Derived from IRC48M, IRC8M, IRC2M or External clock
#define SYSTEM_MCGOUT_CLOCK 48000000UL

// SYSTEM_MCGPCLK_CLOCK (Peripheral clock?) =================
//
#define SYSTEM_MCGPCLK_CLOCK IRC48M_CLOCK

// SYSTEM_MCGIR_CLOCK =======================================
//
//  <o> System MCGIR Clock (Hz) <name=system_mcgir_clock> <constant>
//  <i> MCG Internal Reference Clock
//  <i> Derived from IRC8M_CLOCK or IRC2M_CLOCK divided by SC.FCRDIV && MC.LIRC_DIV2
#define SYSTEM_MCGIR_CLOCK 8000000UL

// SYSTEM_CORE_CLOCK =======================================
//
//  <o> System Core Clock (Hz) <name=system_core_clock> <constant>
//  <i> Clocks the ARM Cortex-M4 core
//  <i> Derived from MCGOUT Clock after division by OUTDIV1
//  <i> Must be less than or equal to 48 MHz.
#define SYSTEM_CORE_CLOCK 48000000UL

// SYSTEM_BUS_CLOCK =======================================
//
//  <o> System Bus and Flash Clock (Hz) <name=system_bus_clock> <constant>
//  <i> Clocks the bus slaves & peripheral and flash
//  <i> Derived from Core Clock after division by OUTDIV4
//  <i> Must be less than or equal to 24 MHz and less than or equal to the Core Clock frequency.
#define SYSTEM_BUS_CLOCK 24000000UL

// SYSTEM_FLASH_CLOCK =======================================
//
// Not used
#define SYSTEM_FLASH_CLOCK SYSTEM_BUS_CLOCK

// <h> System Clock dividers
// SIM_CLKDIV1_OUTDIV1 ================================
//
//   <o> Core & System Clock Divider (OUTDIV1) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv1>
//   <i> Clocks the ARM Cortex-M4 core and bus masters [SIM_CLKDIV1_OUTDIV1]
//   <i> MCGOUTCLK clock is source. Default /2
//   <i> Must be less than or equal to 48 MHz.
#define SIM_CLKDIV1_OUTDIV1_V (0)
#define SIM_CLKDIV1_OUTDIV1_M (SIM_CLKDIV1_OUTDIV1_V<<SIM_CLKDIV1_OUTDIV1_SHIFT)

// SIM_CLKDIV1_OUTDIV2 ================================
// Not used
#define SIM_CLKDIV1_OUTDIV2(x) (0)
#define SIM_CLKDIV1_OUTDIV2_M  (0)

// SIM_CLKDIV1_OUTDIV3 ================================
// Not used
#define SIM_CLKDIV1_OUTDIV3(x)  (0)
#define SIM_CLKDIV1_OUTDIV3_M   (0)

// SIM_CLKDIV1_OUTDIV4 ================================
//
//   <o> Bus & Flash Clock Divider (OUTDIV4) - Divide by <1-16> <#-1> <name=sim_clkdiv1_outdiv4>
//   <i> Clocks the bus slaves, peripherals and flash memory [SIM_CLKDIV1_OUTDIV4]
//   <i> MCGOUTCLK clock divided by OUTDIV1 is source. Default /2
//   <i> Must be less than or equal to 24 MHz and less than or equal to the Bus Clock frequency.
#define SIM_CLKDIV1_OUTDIV4_V (1)
#define SIM_CLKDIV1_OUTDIV4_M (SIM_CLKDIV1_OUTDIV4_V<<SIM_CLKDIV1_OUTDIV4_SHIFT)

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
#define OSC_CR_ERCLKEN_V 1
#define OSC_CR_ERCLKEN_M (OSC_CR_ERCLKEN_V<<OSC_CR_ERCLKEN_SHIFT)

// OSC_CR_EREFSTEN ===============================
//
//   <q> External Reference Stop Enable (EREFSTEN)
//   <i> Determines if external reference clock is enabled in Stop mode [OSC_CR_EREFSTEN]
//     <0=> Disabled in Stop mode
//     <1=> Enabled in Stop mode
#define OSC_CR_EREFSTEN_V 1
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

#define OSC_CR_SCP_M ((0<<OSC_CR_SC2P_SHIFT)|(0<<OSC_CR_SC4P_SHIFT)|(1<<OSC_CR_SC8P_SHIFT)|(0<<OSC_CR_SC16P_SHIFT))
// </h>

//========================================================================================
//========================================================================================
// <h> RTC Control Register (RTC_CR)

// RTC_CR_OSCE ===============================
//
//   <q> RTC Oscillator Enable (OSCE) <name=rtc_cr_osce>
//   <i> Enables 32.768 kHz RTC oscillator[RTC_CR_OSCE]
//   <i> If active these setting override the OSC_CR settings.
//     <0=> Disabled
//     <1=> Enabled
#define RTC_CR_OSCE_V 0
#define RTC_CR_OSCE_M (RTC_CR_OSCE_V<<RTC_CR_OSCE_SHIFT)

#if ((RTC_CR_OSCE_V != 0) && (OSC32KCLK_CLOCK == 0))
#error "RTC requires a 32kHz external crystal (OSCCLK_CLOCK)"
#endif

// RTC_CR_CLKO ===============================
//
//   <q> RTC 32kHz Clock Output (CLKO)
//   <i> Determines if RTC 32kHz Clock is available to peripherals [RTC_CR_CLKO]
//     <0=> The 32kHz clock is output to other peripherals
//     <1=> The 32kHz clock is not output to other peripherals
#define RTC_CR_CLKO_V 0
#define RTC_CR_CLKO_M (RTC_CR_CLKO_V<<RTC_CR_CLKO_SHIFT)

// RTC_CR_WPS ===============================
//
//   <q> Wakeup Pin Select (WPS)
//   <i> The wakeup pin is optional and not available on all devices.
//     <0=> Wakeup pin asserts (active low, open drain) if the RTC interrupt asserts or the wakeup pin is turned on.
//     <1=> Wakeup pin outputs the RTC 32kHz clock, provided the wakeup pin is turned on and the 32kHz clock is output to other peripherals.
#define RTC_CR_WPS_V 0
#ifdef RTC_CR_WPS_SHIFT
#define RTC_CR_WPS_M (RTC_CR_WPS_V<<RTC_CR_WPS_SHIFT)
#else
#define RTC_CR_WPS_M (0)
#endif

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
#define RTC_CR_SUP_V 1
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
//  <o> MCGOUTCLK Clock Source Select (CLKS) [0-2] <name=mcg_c1_clks>
//  <i> Selects the clock source for MCGOUTCLK [MCG_C1_CLKS]
//  <i> This option is determined by the Clock Mode selection
//      <0=> Selects HIRC as main clock source (HIRC mode).
//      <1=> Selects LIRC as main clock source (LIRC2M or LIRC8M mode).
//      <2=> Selects external clock as the main clock source (EXT mode).
#define MCG_C1_CLKS_V 0
#define MCG_C1_CLKS_M (MCG_C1_CLKS_V<<MCG_C1_CLKS_SHIFT)

// MCG_C1_IRCLKEN ==============================
//
//   <q> Low-frequency Internal Reference Clock Enable (IRCLKEN) <name=mcg_c1_irclken>
//   <i> Enables the Low-frequency Internal Reference Clock as MCGIRCLK [MCG_C1_IRCLKEN]
//      <0=> LIRC is disabled
//      <1=> LIRC is enabled
#define MCG_C1_IRCLKEN_V   0
#define MCG_C1_IRCLKEN_M   (1<<MCG_C1_IRCLKEN_SHIFT)

// MCG_C1_IREFSTEN =============================
//
//   <q> Internal Reference Stop Enable (IREFSTEN)
//   <i> Determines if IRS is enabled in Stop mode [MCG_C1_IREFSTEN]
//      <0=> LIRC disabled in STOP mode
//      <1=> LIRC enabled in STOP mode, if IRCLKEN is set.
#define MCG_C1_IREFSTEN_V   0
#define MCG_C1_IREFSTEN_M   (MCG_C1_IREFSTEN_V<<MCG_C1_IREFSTEN_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Control Register 2 (MCG_C2)

// MCG_C2_EREFS0 =============================
//
//   <q> External Reference Select (EREFS0) <name=mcg_c2_erefs0>
//   <i> Determines whether a clock or crystal is used for the external reference clock [C2_EREFS0]
//      <0=> External clock
//      <1=> Oscillator
#define MCG_C2_EREFS0_V  1
#define MCG_C2_EREFS0_M (MCG_C2_EREFS0_V<<MCG_C2_EREFS0_SHIFT)

// MCG_C2_IRCS ==============================
//
//   <q> MCG IRC Clock Source (IRCS) <name=mcg_c2_ircs>
//   <i> Controls the LIRC to work at 2 MHz or 8 MHz mode. [MCG_C2_IRCS]
//     <0=> LIRC is in 2 MHz mode
//     <1=> LIRC is in 8 MHz mode
#define MCG_C2_IRCS_V 1
#define MCG_C2_IRCS_M (MCG_C2_IRCS_V<<MCG_C2_IRCS_SHIFT)

// </h>

//========================================================================================
//========================================================================================
// <h> MCG Status and Control Register (MCG_SC)

// MCG_SC_FCRDIV ==============================
//
//   <o> Fast Internal Clock Divider (FCRDIV) <0-7> <name=mcg_sc_fcrdiv>
//   <i> Selects a further divider for the fast internal reference clock (IRC48MHz) [MCG_SC_FCRDIV]
//   <i> The FIR clock is available for use as MCGOUTCLK.
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
// <h> MCG Status and Control Register (MCG_MC)

// MCG_MC_HIRCEN ==============================
//
//   <q> High-frequency IRC (IRC48MHz) Enable (HIRCEN) <name=mcg_mc_hircen>
//   <i> Enables the HIRC, even when MCG_Lite is not working at HIRC mode. [MCG_MC_HIRCEN]
//     <0=> HIRC source is not enabled
//     <1=> HIRC source is enabled
#define MCG_MC_HIRCEN_V 0
#define MCG_MC_HIRCEN_M (MCG_MC_HIRCEN_V<<MCG_MC_HIRCEN_SHIFT)

// MCG_MC_LIRC_DIV2 ==============================
//
//   <o> Second Low-frequency Internal Reference Clock Divider (LIRC_DIV2) <0-7> <name=mcg_mc_lirc_div2>
//   <i> Selects the factor value to further divide the LIRC source. [MCG_MC_LIRC_DIV2]
//   <i> The FIR clock is available for use as MCGIRCLK.
//   <0=> Divide by 1
//   <1=> Divide by 2
//   <2=> Divide by 4
//   <3=> Divide by 8
//   <4=> Divide by 16
//   <5=> Divide by 32
//   <6=> Divide by 64
//   <7=> Divide by 128
#define MCG_MC_LIRC_DIV2_V  0
#define MCG_MC_LIRC_DIV2_M (MCG_MC_LIRC_DIV2_V<<MCG_MC_LIRC_DIV2_SHIFT)

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
// <h> Peripheral Clock Source Selection (Not all may be present)

// SIM_SOPT1_OSC32KSEL ================================
//
//   <o> 32kHz Clock Source (ERCLK32)
//   <i> Source for nominal 32K clock for peripherals [SIM_SOPT1_OSC32KSEL]
//   <i> Not available on KL02 devices
//     <0=> System Oscillator (OSC32KCLK)
//     <2=> Real Time Clock CLKIN pin
//     <3=> Low power oscillator (LPO - 1kHz)
#ifdef SIM_SOPT1_OSC32KSEL
#define SIM_SOPT1_OSC32KSEL_V 3
#define SIM_SOPT1_OSC32KSEL_M (SIM_SOPT1_OSC32KSEL_V<<SIM_SOPT1_OSC32KSEL_SHIFT)

#if SIM_SOPT1_OSC32KSEL_V == 0
#define SYSTEM_ERCLK32_CLOCK OSC32KCLK_CLOCK          // Main Oscillator operating in 32kHz mode
#elif SIM_SOPT1_OSC32KSEL_V == 2
#define SYSTEM_ERCLK32_CLOCK RTC_CLKIN_CLOCK   // External RTC clock pin
#elif SIM_SOPT1_OSC32KSEL_V == 3
#define SYSTEM_ERCLK32_CLOCK SYSTEM_LOW_POWER_CLOCK   // LPO
#else
#error "Invalid ERCLK32 clock selected"
#endif
#else
#define SYSTEM_ERCLK32_CLOCK SYSTEM_OSC32KCLK_CLOCK   // Main/32kHz Oscillator (depends on chip)
#endif

// SIM_SOPT1_OSC32KOUT ================================
//
//   <o> 32K oscillator clock output <0-1> (ERCLK32)
//   <i> Outputs the ERCLK32K on the selected pin in all modes of operation (including VLLS and System Reset),
//   <i> overriding the existing pin mux configuration for that pin. [SIM_SOPT1_OSC32KOUT]
//     <0=> ERCLK32K is not output.
//     <1=> ERCLK32K is not output.
#ifdef SIM_SOPT1_OSC32KOUT
#define SIM_SOPT1_OSC32KOUT_V 0
#define SIM_SOPT1_OSC32KOUT_M (SIM_SOPT1_OSC32KOUT_V<<SIM_SOPT1_OSC32KOUT_SHIFT)
#endif

// SIM_SOPT2_LPUART0SRC =================================
//
//   <o> LPUART0 Clock Source
//   <i> Low Power Universal Asynchronous Receiver/Transmitter clock source [SIM_SOPT2_UART0SRC]
//     <0=> Disabled
//     <1=> 48MHz internal reference clock (IRC48M clock)
//     <2=> Oscillator External Reference Clock (OSCERCLK)
//     <3=> MCG Internal Reference Clock (MCGIRCLK)
#define SIM_SOPT2_LPUART0SRC_V  1
#define SIM_SOPT2_LPUART0SRC_M  (SIM_SOPT2_LPUART0SRC_V<<SIM_SOPT2_LPUART0SRC_SHIFT)

#if SIM_SOPT2_LPUART0SRC_V == (0)
#define SYSTEM_LPUART0_CLOCK (0)
#elif SIM_SOPT2_LPUART0SRC_V == (1)
#define SYSTEM_LPUART0_CLOCK IRC48M_CLOCK
#elif SIM_SOPT2_LPUART0SRC_V == (2)
#define SYSTEM_LPUART0_CLOCK SYSTEM_OSCER_CLOCK
#elif SIM_SOPT2_LPUART0SRC_V == (3)
#define SYSTEM_LPUART0_CLOCK SYSTEM_MCGIR_CLOCK
#endif

#define SYSTEM_UART1_CLOCK SystemBusClock
#define SYSTEM_UART2_CLOCK SystemBusClock

// SIM_SOPT2_TPMSRC ===================================
//
//   <o> TPM Clock Source
//   <i> Timer/PWM Module clock source [SIM_SOPT2_TPMSRC]
//     <0=> Disabled
//     <1=> 48MHz internal reference clock (IRC48M clock)
//     <2=> Oscillator External Reference Clock (OSCERCLK)
//     <3=> MCG Internal Reference Clock (MCGIRCLK)
#define SIM_SOPT2_TPMSRC_V (1)
#define SIM_SOPT2_TPMSRC_M SIM_SOPT2_TPMSRC(SIM_SOPT2_TPMSRC_V)

#if (SIM_SOPT2_TPMSRC_V == (0))
#define SYSTEM_TPM_CLOCK (0)
#elif (SIM_SOPT2_TPMSRC_V == (1))
#define SYSTEM_TPM_CLOCK IRC48M_CLOCK
#elif (SIM_SOPT2_TPMSRC_V == (2))
#define SYSTEM_TPM_CLOCK SYSTEM_OSCER_CLOCK
#elif (SIM_SOPT2_TPMSRC_V == (3))
#define SYSTEM_TPM_CLOCK SYSTEM_MCGIRCLK_CLOCK
#endif

// SIM_SOPT2_CLKOUTSEL ================================
//
//   <o> CLKOUT select
//   <i> Selects the clock to output on the CLKOUT pin. [SIM_SOPT2_CLKOUTSEL]
//     <2=> Bus clock
//     <3=> LPO clock (1 kHz)
//     <4=> LIRC_CLK
//     <6=> OSCERCLK
//     <7=> IRC48M clock (only when chip VDD is 2.7-3.6 V)
#define SIM_SOPT2_CLKOUTSEL_V 0
#define SIM_SOPT2_CLKOUTSEL_M (SIM_SOPT2_CLKOUTSEL_V<<SIM_SOPT2_CLKOUTSEL_SHIFT)

// SIM_SOPT2_RTCCLKOUTSEL ================================
//
//   <o> RTC clock out select
//   <i> Selects the clock to be output on the RTC_CLKOUT pin [SIM_SOPT2_RTCCLKOUTSEL]
//     <0=> RTC 1 Hz clock
//     <1=> OSCERCLK clock
#define SIM_SOPT2_RTCCLKOUTSEL_V 1
#define SIM_SOPT2_RTCCLKOUTSEL_M (SIM_SOPT2_RTCCLKOUTSEL_V<<SIM_SOPT2_RTCCLKOUTSEL_SHIFT)

// </h>

// SYSTEM_OSCER_CLOCK ================================
// Always connected to main oscillator
#define SYSTEM_OSCER_CLOCK OSCCLK_CLOCK

// MCGFLLCLK_CLOCK  ==============================
#define SYSTEM_MCGFLL_CLOCK FLL_TARGET_CLOCK

/*
 * The following are 'public' definitions
 *
 * SYSTEM_MCGIR_CLOCK       MCG Internal Reference clock
 * SYSTEM_MCGOUT_CLOCK      MCG OUT clock (from SlowIRC/FastIRC/ExternalRC/PLL/FLL)
 * SYSTEM_OSCER_CLOCK       Main oscillator/clock
 * SYSTEM_BUS_CLOCK
 * SYSTEM_CORE_CLOCK
 */

void clock_initialise(void);

#ifdef __cplusplus
}
#endif

#endif /* CLOCK_PRIVATE_H_ */
