/**
 * @file     system.h (180.ARM_Peripherals/Project_Headers/system.h)
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
extern uint32_t SystemBusClock;  //!< System bus clock frequency in Hz

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
 * Check interrupt status
 *
 * @return true if interrupts are enabled
 */
int areInterruptsEnabled();

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

#if defined(__CM3_REV) || defined(__CM4_REV) // Only available on Cortex M3 & M4
/**
 * Obtain lock
 *
 * @param lockVar Locking variable to use
 *
 * @note This is a spin-lock - don't use on interrupts
 */
static inline void lock(volatile uint32_t *lockVar) {
   do {
      // If not locked
      if (__LDREXW(lockVar) == 0) {
         // Try to obtain lock by writing 1
         if (__STREXW(1, lockVar) == 0) {
            // Succeeded
            // Do not start any other memory access
            __DMB();
            return;
         }
      }
   } while (1);
}

/**
 * Release lock
 *
 * @param addr Locking variable to use
 */
static inline void unlock(volatile uint32_t *lockVar) {
   // Ensure memory operations completed before
   __DMB();
   // Release lock
   *lockVar = 0;
}
#else
// Not available on Cortex M0
static inline void lock(uint32_t * dummy) {(void)dummy;}
static inline void unlock(uint32_t * dummy) {(void)dummy;}
#endif

/**
 * Enter critical section
 *
 * Disables interrupts for a critical section
 *
 * @param cpuSR Variable to hold interrupt state so it can be restored
 */
static inline void enterCriticalSection(uint8_t *cpuSR) {
   __asm__ volatile (
         "  MRS   r0, PRIMASK       \n"   // Copy flags
         // It may be possible for a ISR to run here but it
         // would save/restore PRIMASK so this code is OK
         "  CPSID I                 \n"   // Disable interrupts
         "  STRB  r0, %[output]     \n"   // Save flags
         : [output] "=m" (*cpuSR) : : "r0");
}

/**
 * Exit critical section
 *
 * Restores interrupt state saved by enterCriticalSection()
 *
 * @param cpuSR Variable to holding interrupt state to be restored
 */
static inline void exitCriticalSection(uint8_t *cpuSR) {
   __asm__ volatile (
         "  LDRB r0, %[input]    \n"  // Retrieve original flags
         "  MSR  PRIMASK,r0;     \n"  // Restore
         : :[input] "m" (*cpuSR) : "r0");
}

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

/**
 * Class to implement simple critical sections by disabling interrupts.
 *
 * Disables interrupts for a critical section.
 * This would be from the declaration of the object until the end of
 * enclosing block. An object of this class should be declared at the
 * start of a block. e.g.
 *
 * {
 *    CriticalSection cs;
 *    ...
 *    Protected code
 *    ...
 * }
 *
 */
class CriticalSection {
private:
   volatile uint8_t cpuSR=0;

public:
   /**
    * Constructor - Enter critical section
    *
    * Disables interrupts for a critical section
    * This would be from the declaration of the object until end of enclosing block.
    */
   CriticalSection() {
      __asm__ volatile (
            "  MRS   r0, PRIMASK       \n"   // Copy flags
            // It may be possible for a ISR to run here but it
            // would save/restore PRIMASK so this code is OK
            "  CPSID I                 \n"   // Disable interrupts
            "  STRB  r0, %[output]     \n"   // Save flags
            : [output] "=m" (cpuSR) : : "r0");
   }

   /**
    * Destructor - Exit critical section
    *
    * Enables interrupts IFF previously disabled by this object
    * This would be done implicitly by exiting the enclosing block.
    */
   ~CriticalSection() {
      __asm__ volatile (
            "  LDRB r0, %[input]    \n"  // Retrieve original flags
            "  MSR  PRIMASK,r0;     \n"  // Restore
            : :[input] "m" (cpuSR) : "r0");
   }
};

#endif // __cplusplus

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H_ */
