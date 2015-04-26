/*
 * Placeholder LPC1243.h
 *
 * It is not legal to distribute Freescale header files as part of USBDM.
 *
 * If you have suitable header files then they may be copied to the USBDM installation
 * directory:
 * Linux   			 : /usr/local/share/usbdm/Stationery/Project_Headers
 * Windows (default) : C:\Program Files\pgo\USBDM x.x.x.x\Stationery\Project_Headers
 *
 * See the readme in the above folder.
 */
#ifndef MCU_LPC1343
#define MCU_LPC1343

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* --------------------  Cortex-M Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,   /*!<   1 Reset Vector, invoked on Power up and warm reset                                 */
  NonMaskableInt_IRQn           = -14,   /*!<   2 Non maskable Interrupt, cannot be stopped or preempted                           */
  HardFault_IRQn                = -13,   /*!<   3 Hard Fault, all classes of Fault                                                 */
  MemoryManagement_IRQn         = -12,   /*!<   4 Memory Management, MPU mismatch, including Access Violation and No Match         */
  BusFault_IRQn                 = -11,   /*!<   5 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
  UsageFault_IRQn               = -10,   /*!<   6 Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
  SVCall_IRQn                   =  -5,   /*!<  11 System Service Call via SVC instruction                                          */
  DebugMonitor_IRQn             =  -4,   /*!<  12 Debug Monitor                                                                    */
  PendSV_IRQn                   =  -2,   /*!<  14 Pendable request for system service                                              */
  SysTick_IRQn                  =  -1,   /*!<  15 System Tick Timer                                                                */
/* ----------------------   Device VectorTable                       ---------------------- */

} IRQn_Type;

/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void MemManage_Handler(void);
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void SVC_Handler(void);
extern void DebugMon_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the cm4 Processor and Core Peripherals---------------- */
#define __CM3_REV                0x0100
#define __MPU_PRESENT            0
#define __NVIC_PRIO_BITS         4
#define __Vendor_SysTickConfig   0
#define __FPU_PRESENT            1

#include <core_cm3.h>   /*!< Cortex-M processor and core peripherals                              */

#endif  // MCU_LPC1343
