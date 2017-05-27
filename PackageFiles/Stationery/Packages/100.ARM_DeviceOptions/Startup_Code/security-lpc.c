/*
 *  @file security.c
 *  Derived from security-lpc.c
 *
 *  Security options
 *  Created on: 20/5/2017
 *  Devices: LPC devices
 */
#include <stdint.h>

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------
/*
  <h> Flash Configuration - Security and Protection
  </h>
*/

/*
  <o>Code Read Protection selection
  <i> This is a mechanism that allows the user to enable different levels of security in the system
  <i> so that access to the on-chip flash and use of the ISP can be restricted
  <i>
  <i>NO_ISP
  <i>Prevents sampling of the ISP entry pin for entering ISP mode.
  <i>The ISP entry pin is available for other uses.
  <i>
  <i>CRP1
  <i>Access to chip via the SWD pins is disabled.
  <i>This mode allows partial flash update using the following ISP commands and restrictions:
  <i>- Write to RAM command should not access RAM below 0x1000 0300. Access to addresses below 0x1000 0200 is disabled.
  <i>- Copy RAM to flash command can not write to Sector 0.
  <i>- Erase command can erase Sector 0 only when all sectors are selected for erase.
  <i>- Compare command is disabled.
  <i>- Read Memory command is disabled.
  <i>This mode is useful when CRP is required and flash field updates are needed but all sectors can not be erased.
  <i>Since compare command is disabled in case of partial updates the secondary loader should implement checksum
  <i>mechanism to verify the integrity of the flash.
  <i>
  <i>CRP2
  <i>Access to chip via the SWD pins is disabled.
  <i>The following ISP commands are disabled:
  <i>- Read Memory
  <i>- Write to RAM
  <i>- Go
  <i>- Copy RAM to flash
  <i>- Compare
  <i>When CRP2 is enabled the ISP erase command only allows erasure of all user sectors.
  <i>
  <i>CRP3
  <i>Access to chip via the SWD pins is disabled.
  <i>ISP entry by pulling the ISP entry pin LOW is disabled if a valid user code is present in flash sector 0.
  <i>This mode effectively disables ISP override using the ISP entry pin.
  <i>It is up to the user's application to provide a flash update mechanism using IAP calls or
  <i>call re-invoke ISP command to enable flash update via UART.
  <i>Caution: If CRP3 is selected, no future factory testing can be performed on the device.
  <info>CRP
      <0xFFFFFFFF=> CRP disabled. All ISP features available.
      <0x4E697370=> No ISP - ISP is disabled.
      <0x12345678=> CRP1 - SWD pins disabled. Partial flash update is possible.
      <0x87654321=> CRP2 - SWD pins disabled. Limited ISP commands available.
      <0x43218765=> CRP3 - SWD pins disabled. ISP is disabled.
 */
#define CRP_VALUE 0xFFFFFFFF

#if (CRP_VALUE!=0xFFFFFFFF) && (CRP_VALUE!=0x4E697370) 
#warning "SWD debugging pins are disabled"
#endif

/*
 * Security information structure in flash memory
 */
typedef struct {
    uint32_t crp;
} SecurityInfo;

__attribute__ ((section(".security_information")))
const SecurityInfo securityInfo = {
    /* crp value */ CRP_VALUE,
};

