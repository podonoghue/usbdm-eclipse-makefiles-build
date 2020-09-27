/*
 * arm.h
 *
 *  Created on: 04/04/2011
 *      Author: PODonoghue
 */

#ifndef ARM_DEFINES_H
#define ARM_DEFINES_H

// Option Halfwords in Flash
#define OPT_RDP   (0x1FFFF800)
#define OPT_USER  (0x1FFFF802)
#define OPT_Data0 (0x1FFFF804)
#define OPT_Data1 (0x1FFFF806)
#define OPT_WRP0  (0x1FFFF808)
#define OPT_WRP1  (0x1FFFF80A)
#define OPT_WRP2  (0x1FFFF80C)
#define OPT_WRP3  (0x1FFFF80E)

// RDP unlock key value
#define RDPRT_KEY       (0x00A5)

// USER bit masks
#define nRST_STDBY (1<<2) // 0: Reset when entering Standby, 1: No reset generated.
#define nRST_STOP  (1<<1) // 0: Reset when entering Stop, 1: No reset generated
#define WDG_SW     (1<<0) // 0: Hardware watchdog, 1: Software watchdog

// Flash registers
#define FLASH_ACR       (0x40022000)
#define FLASH_KEYR      (0x40022004)
#define FLASH_OPTKEYR   (0x40022008)
#define FLASH_SR        (0x4002200C)
#define FLASH_CR        (0x40022010)
#define FLASH_AR        (0x40022014)
#define FLASH_OBR       (0x4002201C)
#define FLASH_WRPR      (0x40022020)

#define FLASH_SR_BSY       (1<<0)
#define FLASH_SR_PGERR     (1<<2)
#define FLASH_SR_WRPRTERR  (1<<4)
#define FLASH_SR_EOP       (1<<5)

#define FLASH_CR_PG     (1<<0)
#define FLASH_CR_PER    (1<<1)
#define FLASH_CR_MER    (1<<2)
#define FLASH_CR_OPTPG  (1<<4)
#define FLASH_CR_OPTER  (1<<5)
#define FLASH_CR_STRT   (1<<6)
#define FLASH_CR_LOCK   (1<<7)
#define FLASH_CR_OPTWRE (1<<9)
#define FLASH_CR_ERRIE  (1<<10)
#define FLASH_CR_EOPIE  (1<<12)

#define FLASH_OBR_OPTERR        (1<<0)
#define FLASH_OBR_RDPRT         (1<<1)
#define FLASH_OBR_WDG_SW        (1<<2)
#define FLASH_OBR_nRST_STOP     (1<<3)
#define FLASH_OBR_nRST_STDBY    (1<<4)
#define FLASH_OBR_DATA0_OFF   (10)
#define FLASH_OBR_DATA0_MASK  (0xFF<<FLASH_OBR_DATA0_OFF)
#define FLASH_OBR_DATA1_OFF   (18)
#define FLASH_OBR_DATA1_MASK  (0xFF<<FLASH_OBR_DATA1_OFF)

#define FLASH_KEYR_KEY1 (0x45670123)
#define FLASH_KEYR_KEY2 (0xCDEF89AB)

#define DBGMCU_CR  (0xE0042004)

#endif /* ARM_DEFINES_H */
