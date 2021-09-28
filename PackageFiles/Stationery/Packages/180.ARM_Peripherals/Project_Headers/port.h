/*
 * port.h
 *
 *  Created on: 21 Sep. 2021
 *      Author: peter
 */

#ifndef PROJECT_HEADERS_PORT_H_
#define PROJECT_HEADERS_PORT_H_

/**
 * Namespace enclosing USBDM classes
 */
namespace USBDM {
/**
 * @addtogroup USBDM_Group USBDM Peripheral Interface
 * @brief Hardware Peripheral Interface and library
 * @{
 */

/**
 * @tparam  T  Type of comparison object (inferred)
 * @param   a  Left-hand object for comparison
 * @param   b  Right-hand object for comparison
 *
 * @return Smaller of a or b
 */
template<class T>
constexpr T min(const T a, const T b) {
   return (b < a) ? b : a;
}

/**
 * @tparam  T  Type of comparison object (inferred)
 * @param   a  Left-hand object for comparison
 * @param   b  Right-hand object for comparison
 *
 * @return Larger of a or b
 */
template<class T>
constexpr T max(const T a, const T b) {
   return (b > a) ? b : a;
}

/** Dummy port information for pins without an associated PCR */
constexpr PortInfo  __attribute__((unused)) NoPortInfo {0, 0, static_cast<IRQn_Type>(-1), 0, NvicPriority_NotInstalled};

/** Class to static check signal mapping is valid */
template<class Info, int signalNum> class CheckSignal {
   static_assert((signalNum<Info::numSignals), "Non-existent signal - Modify Configure.usbdm");
   static_assert((signalNum>=Info::numSignals)||(Info::info[signalNum].gpioBit != UNMAPPED_PCR), "Signal is not mapped to a pin - Modify Configure.usbdm");
   static_assert((signalNum>=Info::numSignals)||(Info::info[signalNum].gpioBit != INVALID_PCR),  "Signal doesn't exist in this device/package");
   static_assert((signalNum>=Info::numSignals)||((Info::info[signalNum].gpioBit == UNMAPPED_PCR)||(Info::info[signalNum].gpioBit == INVALID_PCR)||(Info::info[signalNum].gpioBit >= 0)), "Illegal signal");
};

/** Enables mapping of all allocated pins during startup using mapAllPins() */
static constexpr bool MAP_ALL_PINS = false;

/** Used to configure pin-mapping before 1st use of peripherals */
extern void mapAllPins();

/**
 * End group USBDM_Group
 * @}
 */

} // End namespace USBDM

#endif /* PROJECT_HEADERS_PORT_H_ */
