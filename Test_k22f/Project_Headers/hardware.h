/**
 * @file      hardware.h (180.ARM_Peripherals/Project_Headers/hardware.h)
 *
 * This file is a convenient location for shared USBDM namespace information and
 * brings together header files for basic USBDM features
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */

#ifndef INCLUDE_USBDM_HARDWARE_H_
#define INCLUDE_USBDM_HARDWARE_H_

#include <stdint.h>
#include "error.h"

// Use when in-lining makes the release build smaller
#ifdef DEBUG_BUILD
#define INLINE_RELEASE __attribute__((noinline))
#else
#define INLINE_RELEASE __attribute__((always_inline))
#endif

#ifdef DEBUG_BUILD
#define NOINLINE_DEBUG __attribute__((noinline))
#else
#define NOINLINE_DEBUG
#endif

/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
namespace USBDM {

static constexpr float ns      = 1E-9f; //!< Scale factor for nanoseconds
static constexpr float us      = 1E-6f; //!< Scale factor for microseconds
static constexpr float ms      = 1E-3f; //!< Scale factor for milliseconds
static constexpr float seconds = 1.0f;  //!< Scale factor for seconds
static constexpr float percent = 1.0f;  //!< Scale factor for percentage as float
static constexpr float MHz     = 1E6f;  //!< Scale factor for MHz as float
static constexpr float kHz     = 1E3f;  //!< Scale factor for kHz as float
static constexpr float Hz      = 1.0f;  //!< Scale factor for Hz as float

/** MCGFFCLK - Fixed frequency clock (input to FLL) */
extern volatile uint32_t SystemMcgffClock;

/** MCGOUTCLK - Primary output from MCG, various sources */
extern volatile uint32_t SystemMcgOutClock;

/** MCGFLLCLK - Output of FLL */
extern volatile uint32_t SystemMcgFllClock;

/** MCGPLLCLK - Output of PLL */
extern volatile uint32_t SystemMcgPllClock;
} // End namespace USBDM

/**
 * Convenience names for common priority levels
 */
enum NvicPriority {
   NvicPriority_VeryHigh     = 0,  //!< NvicPriority_VeryHigh
   NvicPriority_High         = 2,  //!< NvicPriority_High
   NvicPriority_MidHigh      = 5,  //!< NvicPriority_MidHigh
   NvicPriority_Normal       = 8,  //!< NvicPriority_Normal
   NvicPriority_Midlow       = 11, //!< NvicPriority_Midlow
   NvicPriority_Low          = 13, //!< NvicPriority_Low
   NvicPriority_VeryLow      = 15, //!< NvicPriority_VeryLow
   NvicPriority_NotInstalled = -1, //!< Indicates handler is not installed
};

#include "pin_mapping.h"
#include "delay.h"
#include "console.h"

/**
 * Calculate a Vector number using an offset from an existing number.
 * This is only useful if related vectors are consecutive e.g. DMA0_IRQn, DMA1_IRQn ...
 *
 * @param vector  Base vector to use
 * @param offset  Offset from base vector
 *
 * @return  Vector number calculated from vector+offset
 */
constexpr IRQn_Type inline operator+(IRQn_Type vector, unsigned offset) {
   return static_cast<IRQn_Type>(static_cast<unsigned>(vector) + offset);
}

/**
 * Calculate a Vector number using an offset from an existing number.
 * This is only useful if related vectors are consecutive e.g. DMA0_IRQn, DMA1_IRQn ...
 *
 * @param vector  Base vector to use
 * @param offset  Offset from base vector
 *
 * @return  Vector number calculated from vector+offset
 */
constexpr IRQn_Type inline operator+(IRQn_Type vector, int offset) {
   return vector + static_cast<unsigned>(offset);
}

#endif /* INCLUDE_USBDM_HARDWARE_H_ */
