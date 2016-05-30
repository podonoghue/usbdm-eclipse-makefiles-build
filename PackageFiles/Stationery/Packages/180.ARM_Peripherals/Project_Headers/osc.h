/*
 * osc.h
 *
 *  Created on: 25/10/2013
 *      Author: podonoghue
 */

#ifndef OSC_H_
#define OSC_H_

#include "pin_mapping.h"

namespace USBDM {

template <class Info>
class Osc {

protected:
   static constexpr volatile OSC_Type *osc      = reinterpret_cast<volatile OSC_Type *>(Info::basePtr);

public:
   /**
    * Initialise OSC to default settings\n
    * Configures all OSC pins
    */
   static void initialise() {

      // Configure pins
      Info::initPCRs();

      osc->CR  = Info::OSC_CR;

#ifdef OSC_DIV_ERPS
      osc->DIV  = Info::OSC_DIV;
#endif
   }
};

#ifdef USBDM_OSC0_IS_DEFINED
class Osc0 : public Osc<Osc0Info> {};
#endif

#ifdef USBDM_OSC1_IS_DEFINED
class Osc1 : public Osc<Osc1Info> {};
#endif

} // End namespace USBDM

#endif /* OSC_H_ */
