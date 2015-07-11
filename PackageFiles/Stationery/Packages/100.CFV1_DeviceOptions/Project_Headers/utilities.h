/**
 * @file     utilities.h
 * @brief    Convenience macros for port access
 * @version  V4.11.1.70
 * @date     13 May 2013
 */
#ifndef UTILTIES_H_
#define UTILTIES_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Concatenate two tokens
 *
 * @param x
 * @param y
 */
#define CONCAT2_(x,y) x ## y
/**
 * @brief Concatenate three tokens
 *
 * @param x
 * @param y
 * @param z
 */
#define CONCAT3_(x,y,z) x ## y ## z
/**
 * @brief Concatenate four tokens
 *
 * @param w
 * @param x
 * @param y
 * @param z
 */
#define CONCAT4_(w,x,y,z) w ## x ## y ## z

#define PF(port,num)    CONCAT4_(MXC_PT,port,PF,num)

/**
 * @brief Create PDOR register from port name
 *
 * @param port Port name e.g. A => GPIOA->PDOR
 */
#define PDOR(port)             CONCAT2_(GPIO,port)->PDOR
/**
 * @brief Create PSOR register from port name
 *
 * @param port Port name e.g. A => GPIOA->PSOR
 */
#define PSOR(port)             CONCAT2_(GPIO,port)->PSOR
/**
 * @brief Create PCOR register from port name
 *
 * @param port Port name e.g. A => GPIOA->PCOR
 */
#define PCOR(port)             CONCAT2_(GPIO,port)->PCOR
/**
 * @brief Create PTOR register from port name
 *
 * @param port Port name e.g. A => GPIOA-PTOR
 */
#define PTOR(port)             CONCAT2_(GPIO,port)->PTOR
/**
 * @brief Create PDIR register from port name
 *
 * @param port Port name e.g. A => GPIOA->PDIR
 */
#define PDIR(port)             CONCAT2_(GPIO,port)->PDIR
/**
 * @brief Create PDDR register from port name
 *
 * @param port Port name e.g. A => GPIOA->PDDR
 */
#define PDDR(port)             CONCAT2_(GPIO,port)->PDDR

//#define MXC(port,muxNum)     CONCAT4_(MXC_PT,port,PF,muxNum)
//#define MXC_MASK(pin,value) (((value)&0x0F)<<(4*((pin)&0x01)))
#ifdef __cplusplus
   }
#endif

#endif /* UTILTIES_H_ */
