#ifndef CORE_CFV2_H_
#define CORE_CFV2_H_

/*!
 *  Debug breakpoint
 */
#define __breakpoint() __asm__ volatile ("halt")
#define __halt()       __asm__ volatile ("halt")

/*
 *
 */
#define __trap(x)   __asm__ volatile ("trap %0"::"i"(x))

/*!
 *  Stop - used to reduce power
 */
#define __stop(x)   __asm__ volatile ("stop %0"::"i"(x))

/*!
 * Set interrupt level in SR
 */
#define __set_interrupt_level(x) __asm__ volatile (" move %0,%%sr" :: "i" ((((x)<<8)&0x0700)|0x2000))

#endif /* CORE_CFV2_H_ */
