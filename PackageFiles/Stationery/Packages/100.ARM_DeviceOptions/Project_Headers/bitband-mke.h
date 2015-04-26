/*
 * bitband-mke.h
 *
 * From Freescale Application Note AN4838
 */
#ifndef BITBAND_H_
#define BITBAND_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Assumes the location has been allocated to:
 *    - SRAM_U           (0x2000_0000-0x2000_02FF) with bit-band alias (0x2200_0000-0x2200_5FFF)
 *
 * Most Global or Local Static variables end up in SRAM_L so are not usable
 * Most Parameters and Local variables end up in SRAM_U
 *
 * Examples:
 *
 * Set bit-1 of location 0x20000000
 * BIT_BAND_SET(0x20000000, 1); // Set bit 1 of fixed location
 *
 * Assuming a local variable 'local'
 * BIT_BAND_CLEAR(&local, 3); // Clear bit 3 of local
 *
 * Note: The efficiency of this operation depends greatly on whether the address is a constant or can be pre-calculated.
 *       The code will usually be quite inefficient for local variables as the required address will be
 *       calculated each time i.e. the address calculation will overwhelm any advantage of the bitband operation
 *
 *       It is probably a good idea to use a dedicated segment in SRAM_U for bit-band variables and access globally.
 *       See linker files.
 */

/*!
 * Set a bit
 *
 * @param Addr    Address to manipulate (in SRAM_U)
 * @param Bitnum  Bit number 0-7 (usually)
 */
#define BIT_BAND_SET(Addr, Bitnum)   ((void)(*(volatile uint32_t *)(0x22000000 + (((uint32_t)(Addr))&0x3FF)*32 + ((uint32_t)(Bitnum))*4) = 1))
/*!
 * Clear a bit
 *
 * @param Addr    Address to manipulate (in SRAM_U)
 * @param Bitnum  Bit number 0-7 (usually)
 */
#define BIT_BAND_CLEAR(Addr, Bitnum) ((void)(*(volatile uint32_t *)(0x22000000 + (((uint32_t)(Addr))&0x3FF)*32 + ((uint32_t)(Bitnum))*4) = 0))

#ifdef __cplusplus
   }
#endif

#endif /* BITBAND_H_ */
