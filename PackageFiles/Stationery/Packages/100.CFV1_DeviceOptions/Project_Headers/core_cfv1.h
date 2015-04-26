#ifndef CORE_CFV1_H_
#define CORE_CFV1_H_

/*!
 *  Stop - used to reduce power
 */
#define __stop(x)   __asm__ volatile ("stop %0"::"i"(x))

/*!
 *  Debug breakpoint
 */
#define __breakpoint() __asm__ volatile ("halt")
#define __halt()       __asm__ volatile ("halt")

/*!
 *
 */
#define __trap(x)   __asm__ volatile ("trap %0"::"i"(x))

/*!
 * Set interrupt level in SR
 */
#define __set_interrupt_level(x) __asm__ volatile (" move %0,%%sr" :: "i" ((((x)<<8)&0x0700)|0x2000))

#ifdef INTC_IMRH

#define NVIC_PRIO_BITS (4) /* 4 Bits used for the Priority Levels    */

/*!
 * Enable IRQ channel in INTC
 *
 * @param irqNum - IRQ number (64-128)
 */
static inline void INTC_EnableIrq(int irqNum) {
   if (irqNum>=113) {
      irqNum -= (113-42);
   }
   INTC_CIMR = INTC_CIMR_CIMR(irqNum);
}

/*!
 * Disable IRQ channel in INTC
 *
 * @param irqNum - IRQ number (64-128)
 */
static inline void INTC_DisableIrq(int irqNum) {
   if (irqNum>=113) {
      irqNum -= (113-42);
   }
   INTC_SIMR = INTC_SIMR_SIMR(irqNum);
}

/*!
 * Set an interrupt request atthe given level
 *
 * @param level -  request level, 1...7
 */
static inline void INTC_SetIrqAtLevel(int level) {
   INTC_SFRC = 0x3F-(level&0x7);
}

/*!
 * Clear an interrupt request atthe given level
 *
 * @param level -  request level, 1...7
 */
static inline void INTC_ClearIrqAtLevel(int level) {
   INTC_CFRC = 0x3F-(level&0x7);
}

#endif


#endif /* CORE_CFV1_H_ */
