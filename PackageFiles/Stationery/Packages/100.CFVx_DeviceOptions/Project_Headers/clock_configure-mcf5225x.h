/*
 * clock_configure-mcf5225x.h
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
// validate=net.sourceforge.usbdm.annotationEditor.validators.ClockValidate_CFV1Plus>
// PLL clock
// validate=net.sourceforge.usbdm.annotationEditor.validators.PllClockValidate>
// FLL clock
// validate=net.sourceforge.usbdm.annotationEditor.validators.FllClockValidate>

// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// OSCCLK_CLOCK ==============================
//
//   <o> Frequency of Main External Clock or Crystal (Hz)  <name=oscclk_clock> <0-50000000>
//   <i> Frequency of external crystal (XTAL/EXTAL) or clock (EXTAL)
#define OSCCLK_CLOCK (25000000UL)

// SYSTEM_FAST_IRC_CLOCK ==============================
//
//   <o> Frequency of Internal Reference Clock (Hz) <constant> <name=system_irc_clock>
//   <i> Dependent on device and clock Trim. [Typically ~8MHz]
#define SYSTEM_IRC_CLOCK (8000000UL)

#define SYSTEM_BUS_CLOCK (8000000)

void clock_initialise(void);

#ifdef __cplusplus
}
#endif

#endif /* CLOCK_PRIVATE_H_ */
