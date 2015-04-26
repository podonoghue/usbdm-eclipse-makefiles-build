/*
 * ARM.c
 *
 *  Created on: 27/02/2011
 *      Author: podonoghue
 */

#include <string.h>
#include <stdio.h>
#include "USBDM_API.h"
#include "Common.h"
#include "ArmDebug.h"
#include "ArmDefinitions.h"

//! Get name of ARM memory location/region
//!
//! @param address Address to check
//!
//! @return Pointer to static buffer of form name:address
//!
char *ARM_GetMemoryName(uint32_t address) {
static char name[200];

   strcpy(name, "");
   if ((0xE0001000<=address) && (address<=0xE0001FFF)) {// Data Watchpoint and Trace (DWT))
      strcpy(name, "DWT:");
      switch (address) {
         case 0xE0001000 : strcat(name, "DWTCTRL");      break; // RW See a Control Register
         case 0xE0001004 : strcat(name, "DWTCYCCNT");    break; // RW 0x00000000 Cycle Count Register
         case 0xE0001008 : strcat(name, "DWTCPICNT");    break; // RW - CPI Count Register
         case 0xE000100C : strcat(name, "DWTEXCCNT");    break; // RW - Exception Overhead Count Register
         case 0xE0001010 : strcat(name, "DWTSLEEPCNT");  break; // RW - Sleep Count Register
         case 0xE0001014 : strcat(name, "DWTLSUCNT");    break; // RW - LSU Count Register
         case 0xE0001018 : strcat(name, "DWTFOLDCNT");   break; // RW - Folded-instruction Count Register
         case 0xE000101C : strcat(name, "DWTPCSR");      break; // RO - Program Counter Sample Register
         case 0xE0001020 : strcat(name, "DWTCOMP0");     break; // RW - Comparator Register0
         case 0xE0001024 : strcat(name, "DWTMASK0");     break; // RW - Mask Register0
         case 0xE0001028 : strcat(name, "DWTFUNCTION0"); break; // RW 0x00000000 Function Register0
         case 0xE0001030 : strcat(name, "DWTCOMP1");     break; // RW - Comparator Register1
         case 0xE0001034 : strcat(name, "DWTMASK1");     break; // RW - Mask Register1
         case 0xE0001038 : strcat(name, "DWTFUNCTION1"); break; // RW 0x00000000 Function Register1
         case 0xE0001040 : strcat(name, "DWTCOMP2");     break; // RW - Comparator Register2
         case 0xE0001044 : strcat(name, "DWTMASK2");     break; // RW - Mask Register2
         case 0xE0001048 : strcat(name, "DWTFUNCTION2"); break; // RW 0x00000000 Function Register2
         case 0xE0001050 : strcat(name, "DWTCOMP3");     break; // RW - Comparator Register3
         case 0xE0001054 : strcat(name, "DWTMASK3");     break; // RW - Mask Register3
         case 0xE0001058 : strcat(name, "DWTFUNCTION3"); break; // RW 0x00000000 Function Register3
         case 0xE0001FD0 : strcat(name, "PID4");         break; // RO 0x04 Peripheral identification registers
         case 0xE0001FD4 : strcat(name, "PID5");         break; // RO 0x00
         case 0xE0001FD8 : strcat(name, "PID6");         break; // RO 0x00
         case 0xE0001FDC : strcat(name, "PID7");         break; // RO 0x00
         case 0xE0001FE0 : strcat(name, "PID0");         break; // RO 0x02
         case 0xE0001FE4 : strcat(name, "PID1");         break; // RO 0xB0
         case 0xE0001FE8 : strcat(name, "PID2");         break; // RO 0x3B
         case 0xE0001FEC : strcat(name, "PID3");         break; // RO 0x00
         case 0xE0001FF0 : strcat(name, "CID0");         break; // RO 0x0D Component identification registers
         case 0xE0001FF4 : strcat(name, "CID1");         break; // RO 0xE0
         case 0xE0001FF8 : strcat(name, "CID2");         break; // RO 0x05
         case 0xE0001FFC : strcat(name, "CID3");         break; // RO 0xB1
      }
   }
   else if ((0xE000E000<=address) & (address<=0xE000EFFF)) {
      strcpy(name, "SCS:");
      switch (address) {
         case 0xE000E008 : strcat(name, "ACTLR");        break;  // RW 0x00000000 Auxiliary Control Register, ACTLR on page 4-5
         case 0xE000E010 : strcat(name, "STCSR");        break;  // RW 0x00000000 SysTick Control and Status Register
         case 0xE000E014 : strcat(name, "STRVR");        break;  // RW Unknown SysTick Reload Value Register
         case 0xE000E018 : strcat(name, "STCVR");        break;  // RW clear Unknown SysTick Current Value Register
         case 0xE000E01C : strcat(name, "STCR");         break;  // RO STCALIB SysTick Calibration Value Register
         case 0xE000ED00 : strcat(name, "CPUID");        break;  // RO 0x410FC241 CPUID Base Register, CPUID on page 4-5
         case 0xE000ED04 : strcat(name, "ICSR");         break;  // RW or RO 0x00000000 Interrupt Control and State Register
//       case 0xE000ED08 : strcat(name, "PerID0");       break;  // Peripheral ID0 0x0000000C
         case 0xE000ED08 : strcat(name, "VTOR");         break;  // RW 0x00000000 Vector Table Offset Register
         case 0xE000ED0C : strcat(name, "AIRCR");        break;  // RW 0x00000000a Application Interrupt and Reset Control Register
         case 0xE000ED10 : strcat(name, "SCR");          break;  // RW 0x00000000 System Control Register
         case 0xE000ED14 : strcat(name, "CCR");          break;  // RW 0x00000200 Configuration and Control Register.
         case 0xE000ED18 : strcat(name, "SHPR1");        break;  // RW 0x00000000 System Handler Priority Register 1
         case 0xE000ED1C : strcat(name, "SHPR2");        break;  // RW 0x00000000 System Handler Priority Register 2
         case 0xE000ED20 : strcat(name, "SHPR3");        break;  // RW 0x00000000 System Handler Priority Register 3
         case 0xE000ED24 : strcat(name, "SHCSR");        break;  // RW 0x00000000 System Handler Control and State Register
         case 0xE000ED28 : strcat(name, "CFSR");         break;  // RW 0x00000000 Configurable Fault Status Registers
         case 0xE000ED2C : strcat(name, "HFSR");         break;  // RW 0x00000000 HardFault Status Register
         case 0xE000ED30 : strcat(name, "DFSR");         break;  // RW 0x00000000 Debug Fault Status Register
         case 0xE000ED34 : strcat(name, "MMFAR");        break;  // RW Unknown MemManage Fault Address Registerb
         case 0xE000ED38 : strcat(name, "BFAR");         break;  // RW Unknown BusFault Address Registerb
         case 0xE000ED3C : strcat(name, "AFSR");         break;  // RW 0x00000000 Auxiliary Fault Status Register, AFSR on page 4-6
         case 0xE000ED40 : strcat(name, "ID_PFR0");      break;  // RO 0x00000030 Processor Feature Register 0
         case 0xE000ED44 : strcat(name, "ID_PFR1");      break;  // RO 0x00000200 Processor Feature Register 1
         case 0xE000ED48 : strcat(name, "ID_DFR0");      break;  // RO 0x00100000 Debug Features Register 0c
         case 0xE000ED4C : strcat(name, "ID_AFR0");      break;  // RO 0x00000000 Auxiliary Features Register 0
         case 0xE000ED50 : strcat(name, "ID_MMFR0");     break;  // RO 0x00100030 Memory Model Feature Register 0
         case 0xE000ED54 : strcat(name, "ID_MMFR1");     break;  // RO 0x00000000 Memory Model Feature Register 1
         case 0xE000ED58 : strcat(name, "ID_MMFR2");     break;  // RO 0x01000000 Memory Model Feature Register 2
         case 0xE000ED5C : strcat(name, "ID_MMFR3");     break;  // RO 0x00000000 Memory Model Feature Register 3
         case 0xE000ED60 : strcat(name, "ID_ISAR0");     break;  // RO 0x01141110 Instruction Set Attributes Register 0
         case 0xE000ED64 : strcat(name, "ID_ISAR1");     break;  // RO 0x02112000 Instruction Set Attributes Register 1
         case 0xE000ED68 : strcat(name, "ID_ISAR2");     break;  // RO 0x21232231 Instruction Set Attributes Register 2
         case 0xE000ED6C : strcat(name, "ID_ISAR3");     break;  // RO 0x01111131 Instruction Set Attributes Register 3
         case 0xE000ED70 : strcat(name, "ID_ISAR4");     break;  // RO 0x01310132 Instruction Set Attributes Register 4
         case 0xE000ED88 : strcat(name, "CPACR");        break;  // RW - Coprocessor Access Control Register
         case 0xE000EF00 : strcat(name, "STIR");         break;  // WO 0x00000000 Software Triggered Interrupt Register
         case 0xE000EDF0 : strcat(name, "DHCSR");        break;  // RW 0x00000000 Debug Halting Control and Status Register
         case 0xE000EDF4 : strcat(name, "DCRSR");        break;  // WO - Debug Core Register Selector Register
         case 0xE000EDF8 : strcat(name, "DCRDR");        break;  // RW - Debug Core Register Data Register
         case 0xE000EDFC : strcat(name, "DEMCR");        break;  // RW 0x00000000 Debug Exception and Monitor Control Register
         case 0xE000EFE0 : strcat(name, "PerID0");       break;  // Peripheral ID0 0x0000000C
         case 0xE000EFE4 : strcat(name, "PerID1");       break;  // Peripheral ID1 0x000000B0
         case 0xE000EFE8 : strcat(name, "PerID2");       break;  // Peripheral ID2 0x0000000B
         case 0xE000EFEC : strcat(name, "PerID3");       break;  // Peripheral ID3 0x0000000C
         case 0xE000EFF0 : strcat(name, "CompID0");      break;  // Component ID0 0x0000000D
         case 0xE000EFF4 : strcat(name, "CompID1");      break;  // Component ID1 0x000000E0
         case 0xE000EFF8 : strcat(name, "CompID2");      break;  // Component ID2 0x00000005
         case 0xE000EFFC : strcat(name, "CompID3");      break;  // Component ID3 0x000000B1
      }
   }
   else if ((0xE0002000<=address) && (address<=0xE0002FFF)) { // Flash Patch and Breakpoint (FPB))
      strcpy(name, "FPB:");
      switch (address) {
         case 0xE0002000 : strcat(name, "FP_CTRL");   break; // RW 0x260 FlashPatch Control Register
         case 0xE0002004 : strcat(name, "FP_REMAP");  break; // RW - FlashPatch Remap Register
         case 0xE0002008 : strcat(name, "FP_COMP0");  break; // FlashPatch Comparator Register0
         case 0xE000200C : strcat(name, "FP_COMP1");  break; // RW b0 FlashPatch Comparator Register1
         case 0xE0002010 : strcat(name, "FP_COMP2");  break; // RW b0 FlashPatch Comparator Register2
         case 0xE0002014 : strcat(name, "FP_COMP3");  break; // RW b0 FlashPatch Comparator Register3
         case 0xE0002018 : strcat(name, "FP_COMP4");  break; // RW b0 FlashPatch Comparator Register4
         case 0xE000201C : strcat(name, "FP_COMP5");  break; // RW b0 FlashPatch Comparator Register5
         case 0xE0002020 : strcat(name, "FP_COMP6");  break; // RW b0 FlashPatch Comparator Register6
         case 0xE0002024 : strcat(name, "FP_COMP7");  break; // RW b0 FlashPatch Comparator Register7
         case 0xE0002FD0 : strcat(name, "PID4");      break; // RO 0x04 Peripheral identification registers
         case 0xE0002FD4 : strcat(name, "PID5");      break; // RO 0x00
         case 0xE0002FD8 : strcat(name, "PID6");      break; // RO 0x00
         case 0xE0002FDC : strcat(name, "PID7");      break; // RO 0x00
         case 0xE0002FE0 : strcat(name, "PID0");      break; // RO 0x03
         case 0xE0002FE4 : strcat(name, "PID1");      break; // RO 0xB0
         case 0xE0002FE8 : strcat(name, "PID2");      break; // RO 0x2B
         case 0xE0002FEC : strcat(name, "PID3");      break; // RO 0x00
         case 0xE0002FF0 : strcat(name, "CID0");      break; // RO 0x0D Component identification registers
         case 0xE0002FF4 : strcat(name, "CID1");      break; // RO 0xE0
         case 0xE0002FF8 : strcat(name, "CID2");      break; // RO 0x05
         case 0xE0002FFC : strcat(name, "CID3");      break; // RO 0xB1
      }
   }
   else if ((0xE0000000<=address)&&(address<=0xE0000FFF)) { // Instrumentation Trace Macrocell (ITM)
      strcpy(name, "ITM:");
      switch (address) {
         case 0xE0000E00  : strcat(name, "ITM_TER");   break; //  RW 0x00000000 Trace Enable Register
         case 0xE0000E40  : strcat(name, "ITM_TPR");   break; //  RW 0x00000000 ITM Trace Privilege Register, ITM_TPR on page 10-5
         case 0xE0000E80  : strcat(name, "ITM_TCR");   break; //  RW 0x00000000 Trace Control Register
         case 0xE0000FB0  : strcat(name, "ITM_LAR");   break; //  ???
         case 0xE0000FD0  : strcat(name, "PID4");      break; //  RO 0x00000004 Peripheral Identification registers
         case 0xE0000FD4  : strcat(name, "PID5");      break; //  RO 0x00000000
         case 0xE0000FD8  : strcat(name, "PID6");      break; //  RO 0x00000000
         case 0xE0000FDC  : strcat(name, "PID7");      break; //  RO 0x00000000
         case 0xE0000FE0  : strcat(name, "PID0");      break; //  RO 0x00000001
         case 0xE0000FE4  : strcat(name, "PID1");      break; //  RO 0x000000B0
         case 0xE0000FE8  : strcat(name, "PID2");      break; //  RO 0x0000003B
         case 0xE0000FEC  : strcat(name, "PID3");      break; //  RO 0x00000000
         case 0xE0000FF0  : strcat(name, "CID0");      break; //  RO 0x0000000D Component Identification registers
         case 0xE0000FF4  : strcat(name, "CID1");      break; //  RO 0x000000E0
         case 0xE0000FF8  : strcat(name, "CID2");      break; //  RO 0x00000005
         case 0xE0000FFC  : strcat(name, "CID3");      break; //  RO 0x000000B1
      }
   }
   else if ((0xE0080000<=address) && (address<=0xE0080FFF)) {
      strcpy(name, "MCM:");
      switch(address) {
         case 0xE0080008  : strcat(name, "MCM_PLASC");      break; // Crossbar switch (AXBS) slave configuration
         case 0xE008000A  : strcat(name, "MCM_PLAMC");      break; // Crossbar switch (AXBS) master configuration
         case 0xE008000C  : strcat(name, "MCM_SRAMAP");     break; // SRAM arbitration and protection
         case 0xE0080010  : strcat(name, "MCM_ISR");        break; // Interrupt status register
         case 0xE0080014  : strcat(name, "MCM_ETBCC");      break; // ETB counter control register
         case 0xE0080018  : strcat(name, "MCM_ETBRL");      break; // ETB reload register
         case 0xE008001C  : strcat(name, "MCM_ETBCNT");     break; // ETB counter value register
      }
   }
   else if ((0xE0043000<= address) && (address<0xE0043FFF)) {
      strcpy(name, "ETF:");
      switch(address) {
         case 0xE0043000  : strcat(name, "ETF_FCR");      break; // ETF Funnel Control Register
         case 0xE0043004  : strcat(name, "ETF_PCR");      break; // ETF Priority Control Register
      }
   }
   char temp[30];
   sprintf(temp, "(0x%08X)", address);
   strcat(name,temp);

   return name;
}

const char *getACKName(int ack) {
   if (ack == ACK_OK_FAULT)
      return "ACK_OK_FAULT";
   if (ack == ACK_WAIT)
      return "ACK_WAIT";
   return "ACK_ILLEGAL";
}

