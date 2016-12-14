/**
 * @file     system.h
 * @brief    System initialisation routines
 * @version  V4.11.1.70
 * @date     13 Nov 2012
 */
#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t SystemCoreClock; //!< System core clock frequency in Hz
extern uint32_t SystemBusClock;  //!< System bus clock frequency Hz

/**
 *  @brief Low-level initialize the system
 *
 *  Low level setup of the microcontroller system. \n
 *  Called very early in the initialisation. \n
 *  May NOT use globals etc (as will be overwritten by BSS initialization)
 */
void SystemInitLowLevel(void);
/**
 * @brief Initialize the system
 *
 * Setup the microcontroller system.
 */
void SystemInit(void);

/**
 * Disable interrupts
 *
 * This function keeps a count of the number of times interrupts is enabled/disabled so may be called in recursive routines
 */
extern void disableInterrupts();

/**
 * Enable interrupts
 *
 * This function keeps a count of the number of times interrupts is enabled/disabled so may be called in recursive routines
 *
 * @return true if interrupts are now enabled
 */
extern int enableInterrupts();

#ifdef __cplusplus
/**
 * Class used to protect a block of C++ code from interrupts
 */
class IrqProtect {
public:
   inline IrqProtect() {
      disableInterrupts();
   }
   inline ~IrqProtect() {
      enableInterrupts();
   }
};
#endif

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H_ */
