/*
 *  Vectors-stm32.c
 *
 *  Generic vectors and security for STM32Fxxx
 *
 *  Created on: 07/12/2012
 */
#include <stdint.h>
#include <string.h>
#include "derivative.h"

#define DEVICE_SUBFAMILY_CortexM3

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((__weak__, alias("Default_Handler")))

#ifndef SCB_ICSR
#define SCB_ICSR (*(volatile uint32_t*)(0xE000ED04))
#endif

__attribute__((__interrupt__))
void Default_Handler(void) {

   uint32_t vectorNum = SCB_ICSR;

   (void)vectorNum;

   while (1) {
      asm("bkpt #0");
   }
}

typedef struct {
   unsigned int r0;
   unsigned int r1;
   unsigned int r2;
   unsigned int r3;
   unsigned int r12;
   unsigned int lr;
   unsigned int pc;
   unsigned int psr;
} ExceptionFrame;

typedef struct {
   unsigned int scb_hfsr;
   unsigned int scb_cfsr;
   unsigned int scb_bfar;
} ExceptionInfo;

/*  Low-level exception handler
 *
 *  Interface from asm to C.
 *  Passes address of exception handler to C-level handler
 *
 *  See http://www.freertos.org/Debugging-Hard-Faults-On-Cortex-M-Microcontrollers.html
 */
__attribute__((__naked__, __weak__, __interrupt__))
void HardFault_Handler(void) {
   __asm volatile (
          "       tst lr, #4                                    \n"
          "       ite eq                                        \n"
          "       mrseq r0, msp                                 \n"
          "       mrsne r0, psp                                 \n"
          "       ldr r2, handler_addr_const                    \n"
          "       bx r2                                         \n"
          "       handler_addr_const: .word _HardFault_Handler  \n"
      );
}

/******************************************************************************/
/* Exception frame without floating-point storage
 * hard fault handler in C,
 * with stack frame location as input parameter
 *
 * @param exceptionFrame address of exception frame
 *
 */
void _HardFault_Handler(volatile ExceptionFrame *exceptionFrame) {
   (void)exceptionFrame;
#ifdef SCB_HFSR
   char reason[200] = "";
   volatile ExceptionInfo exceptionInfo = {0};
   exceptionInfo.scb_hfsr = SCB_HFSR;
   (void)exceptionInfo.scb_hfsr;
   if ((exceptionInfo.scb_hfsr&SCB_HFSR_FORCED_MASK) != 0) {
      // Forced
      exceptionInfo.scb_cfsr = SCB_CFSR;

      if (SCB_CFSR&SCB_CFSR_BFARVALID_MASK) {
         exceptionInfo.scb_bfar = SCB_BFAR;
      }
      /* CFSR Bit Fields */
      if (SCB_CFSR&SCB_CFSR_DIVBYZERO_MASK  ) { strcat(reason, "Divide by zero,"); }
      if (SCB_CFSR&SCB_CFSR_UNALIGNED_MASK  ) { strcat(reason, "Unaligned access,"); }
      if (SCB_CFSR&SCB_CFSR_NOCP_MASK       ) { strcat(reason, "No co-processor"); }
      if (SCB_CFSR&SCB_CFSR_INVPC_MASK      ) { strcat(reason, "Invalid PC (on return),"); }
      if (SCB_CFSR&SCB_CFSR_INVSTATE_MASK   ) { strcat(reason, "Invalid state (EPSR.T/IT,"); }
      if (SCB_CFSR&SCB_CFSR_UNDEFINSTR_MASK ) { strcat(reason, "Undefined Instruction,"); }
      if (SCB_CFSR&SCB_CFSR_BFARVALID_MASK  ) { strcat(reason, "BFAR contents valid,"); }
      if (SCB_CFSR&SCB_CFSR_LSPERR_MASK     ) { strcat(reason, "Bus fault on FP state save,"); }
      if (SCB_CFSR&SCB_CFSR_STKERR_MASK     ) { strcat(reason, "Bus fault on exception entry,"); }
      if (SCB_CFSR&SCB_CFSR_UNSTKERR_MASK   ) { strcat(reason, "Bus fault on exception return,"); }
      if (SCB_CFSR&SCB_CFSR_IMPRECISERR_MASK) { strcat(reason, "Imprecise data access error,"); }
      if (SCB_CFSR&SCB_CFSR_PRECISERR_MASK  ) { strcat(reason, "Precise data access error,"); }
      if (SCB_CFSR&SCB_CFSR_IBUSERR_MASK    ) { strcat(reason, "Bus fault on instruction pre-fetch,"); }
      if (SCB_CFSR&SCB_CFSR_MMARVALID_MASK  ) { strcat(reason, "MMAR contents valid,"); }
      if (SCB_CFSR&SCB_CFSR_MLSPERR_MASK    ) { strcat(reason, "MemManage fault on FP state save,"); }
      if (SCB_CFSR&SCB_CFSR_MSTKERR_MASK    ) { strcat(reason, "MemManage fault on exception entry,"); }
      if (SCB_CFSR&SCB_CFSR_MUNSTKERR_MASK  ) { strcat(reason, "MemManage fault on exception return,"); }
      if (SCB_CFSR&SCB_CFSR_DACCVIOL_MASK   ) { strcat(reason, "MemManage access violation on data access,"); }
      if (SCB_CFSR&SCB_CFSR_IACCVIOL_MASK   ) { strcat(reason, "MemManage access violation on instruction fetch,"); }
   }
#endif
   while (1) {
      asm("bkpt #0");
   }
}

void __HardReset(void) __attribute__((__interrupt__));
extern uint32_t __StackTop;

/*
 * Each vector is assigned an unique name.  This is then 'weakly' assigned to the
 * default handler.
 * To install a handler, create a function with the name shown and it will override
 * the weak default.
 */
void NMI_Handler(void)                 WEAK_DEFAULT_HANDLER;
void MemManage_Handler(void)           WEAK_DEFAULT_HANDLER;
void BusFault_Handler(void)            WEAK_DEFAULT_HANDLER;
void UsageFault_Handler(void)          WEAK_DEFAULT_HANDLER;
void SVC_Handler(void)                 WEAK_DEFAULT_HANDLER;
void DebugMon_Handler(void)            WEAK_DEFAULT_HANDLER;
void PendSV_Handler(void)              WEAK_DEFAULT_HANDLER;
void SysTick_Handler(void)             WEAK_DEFAULT_HANDLER;

void WWDG_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void PVD_IRQHandler(void)              WEAK_DEFAULT_HANDLER;
void TAMPER_IRQHandler(void)           WEAK_DEFAULT_HANDLER;
void RTC_IRQHandler(void)              WEAK_DEFAULT_HANDLER;
void FLASH_IRQHandler(void)            WEAK_DEFAULT_HANDLER;
void RCC_IRQHandler(void)              WEAK_DEFAULT_HANDLER;
void EXTI0_IRQHandler(void)            WEAK_DEFAULT_HANDLER;
void EXTI1_IRQHandler(void)            WEAK_DEFAULT_HANDLER;
void EXTI2_IRQHandler(void)            WEAK_DEFAULT_HANDLER;
void EXTI3_IRQHandler(void)            WEAK_DEFAULT_HANDLER;
void EXTI4_IRQHandler(void)            WEAK_DEFAULT_HANDLER;
void DMA1_Channel1_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void DMA1_Channel2_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void DMA1_Channel3_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void DMA1_Channel4_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void DMA1_Channel5_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void DMA1_Channel6_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void DMA1_Channel7_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void ADC1_2_IRQHandler(void)           WEAK_DEFAULT_HANDLER;
void USB_HP_CAN1_TX_IRQHandler(void)   WEAK_DEFAULT_HANDLER;
void USB_LP_CAN1_RX0_IRQHandler(void)  WEAK_DEFAULT_HANDLER;
void CAN1_RX1_IRQHandler(void)         WEAK_DEFAULT_HANDLER;
void CAN1_SCE_IRQHandler(void)         WEAK_DEFAULT_HANDLER;
void EXTI9_5_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void TIM1_BRK_IRQHandler(void)         WEAK_DEFAULT_HANDLER;
void TIM1_UP_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void TIM1_TRG_COM_IRQHandler(void)     WEAK_DEFAULT_HANDLER;
void TIM1_CC_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void TIM2_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void TIM3_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void TIM4_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void I2C1_EV_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void I2C1_ER_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void I2C2_EV_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void I2C2_ER_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void SPI1_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void SPI2_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void USART1_IRQHandler(void)           WEAK_DEFAULT_HANDLER;
void USART2_IRQHandler(void)           WEAK_DEFAULT_HANDLER;
void USART3_IRQHandler(void)           WEAK_DEFAULT_HANDLER;
void EXTI15_10_IRQHandler(void)        WEAK_DEFAULT_HANDLER;
void RTCAlarm_IRQHandler(void)         WEAK_DEFAULT_HANDLER;
void USBWakeUp_IRQHandler(void)        WEAK_DEFAULT_HANDLER;
void TIM8_BRK_IRQHandler(void)         WEAK_DEFAULT_HANDLER;
void TIM8_UP_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void TIM8_TRG_COM_IRQHandler(void)     WEAK_DEFAULT_HANDLER;
void TIM8_CC_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void ADC3_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void FSMC_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void SDIO_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void TIM5_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void SPI3_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void UART4_IRQHandler(void)            WEAK_DEFAULT_HANDLER;
void UART5_IRQHandler(void)            WEAK_DEFAULT_HANDLER;
void TIM6_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void TIM7_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void DMA2_Channel1_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void DMA2_Channel2_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void DMA2_Channel3_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void DMA2_Channel4_5_IRQHandler(void)  WEAK_DEFAULT_HANDLER;
void DMA2_Channel5_IRQHandler(void)    WEAK_DEFAULT_HANDLER;
void ETH_IRQHandler(void)              WEAK_DEFAULT_HANDLER;
void ETH_WKUP_IRQHandler(void)         WEAK_DEFAULT_HANDLER;
void CAN2_TX_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void CAN2_RX0_IRQHandler(void)         WEAK_DEFAULT_HANDLER;
void CAN2_RX1_IRQHandler(void)         WEAK_DEFAULT_HANDLER;
void CAN2_SCE_IRQHandler(void)         WEAK_DEFAULT_HANDLER;
void OTG_FS_IRQHandler(void)           WEAK_DEFAULT_HANDLER;

typedef struct {
   uint32_t *initialSP;
   intfunc  handlers[];
} VectorTable;

/*
 * NOTE: Not all these vectors are used by each device in family
 */
__attribute__ ((section(".interrupt_vectors")))
VectorTable const __vector_table = {
    &__StackTop,                      /*!< Vec #0   Initial stack pointer          */
    {
          __HardReset,                /*!< Vec #1   IRQ#    Reset Handler                  */
          NMI_Handler,                /*!< Vec #2   IRQ#-14 NMI Handler                    */
(intfunc) HardFault_Handler,          /*!< Vec #3   IRQ#    Hard Fault Handler             */
          MemManage_Handler,          /*!< Vec #4   IRQ#-12 MPU Fault Handler              */
          BusFault_Handler,           /*!< Vec #5   IRQ#-11 Bus Fault Handler              */
          UsageFault_Handler,         /*!< Vec #6   IRQ#-10 Usage Fault Handler            */
          Default_Handler,            /*!< Vec #7   IRQ#    Reserved                       */
          Default_Handler,            /*!< Vec #8   IRQ#    Reserved                       */
          Default_Handler,            /*!< Vec #9   IRQ#    Reserved                       */
          Default_Handler,            /*!< Vec #10  IRQ#    Reserved                       */
          SVC_Handler,                /*!< Vec #11  IRQ#-5  SVCall Handler                 */
          DebugMon_Handler,           /*!< Vec #12  IRQ#-4  Debug Monitor Handler          */
          Default_Handler,            /*!< Vec #13  IRQ#    Reserved                       */
          PendSV_Handler,             /*!< Vec #14  IRQ#-2  PendSV Handler                 */
          SysTick_Handler,            /*!< Vec #15  IRQ#-1  SysTick Handler                */

          /* External Interrupts */
          WWDG_IRQHandler,            /*!< Vec #16  IRQ #0  Window Watchdog                */
          PVD_IRQHandler,             /*!< Vec #17  IRQ #1  PVD through EXTI Line detect   */
          TAMPER_IRQHandler,          /*!< Vec #18  IRQ #2  Tamper                         */
          RTC_IRQHandler,             /*!< Vec #19  IRQ #3  RTC                            */
          FLASH_IRQHandler,           /*!< Vec #20  IRQ #4  Flash                          */
          RCC_IRQHandler,             /*!< Vec #21  IRQ #5  RCC                            */
          EXTI0_IRQHandler,           /*!< Vec #22  IRQ #6  EXTI Line 0                    */
          EXTI1_IRQHandler,           /*!< Vec #23  IRQ #7  EXTI Line 1                    */
          EXTI2_IRQHandler,           /*!< Vec #24  IRQ #8  EXTI Line 2                    */
          EXTI3_IRQHandler,           /*!< Vec #25  IRQ #9  EXTI Line 3                    */
          EXTI4_IRQHandler,           /*!< Vec #26  IRQ #10 EXTI Line 4                    */
          DMA1_Channel1_IRQHandler,   /*!< Vec #27  IRQ #11 DMA1 Channel 1                 */
          DMA1_Channel2_IRQHandler,   /*!< Vec #28  IRQ #12 DMA1 Channel 2                 */
          DMA1_Channel3_IRQHandler,   /*!< Vec #29  IRQ #13 DMA1 Channel 3                 */
          DMA1_Channel4_IRQHandler,   /*!< Vec #30  IRQ #14 DMA1 Channel 4                 */
          DMA1_Channel5_IRQHandler,   /*!< Vec #31  IRQ #15 DMA1 Channel 5                 */
          DMA1_Channel6_IRQHandler,   /*!< Vec #32  IRQ #16 DMA1 Channel 6                 */
          DMA1_Channel7_IRQHandler,   /*!< Vec #33  IRQ #17 DMA1 Channel 7                 */
          ADC1_2_IRQHandler,          /*!< Vec #34  IRQ #18 ADC1 & ADC2                    */
          USB_HP_CAN1_TX_IRQHandler,  /*!< Vec #35  IRQ #19 USB High Priority or CAN1 TX   */
          USB_LP_CAN1_RX0_IRQHandler, /*!< Vec #36  IRQ #20 USB Low  Priority or CAN1 RX0  */
          CAN1_RX1_IRQHandler,        /*!< Vec #37  IRQ #21 CAN1 RX1                       */
          CAN1_SCE_IRQHandler,        /*!< Vec #38  IRQ #22 CAN1 SCE                       */
          EXTI9_5_IRQHandler,         /*!< Vec #39  IRQ #23 EXTI Line 9..5                 */
          TIM1_BRK_IRQHandler,        /*!< Vec #40  IRQ #24 TIM1 Break                     */
          TIM1_UP_IRQHandler,         /*!< Vec #41  IRQ #25 TIM1 Update                    */
          TIM1_TRG_COM_IRQHandler,    /*!< Vec #42  IRQ #26 TIM1 Trigger and Commutation   */
          TIM1_CC_IRQHandler,         /*!< Vec #43  IRQ #27 TIM1 Capture Compare           */
          TIM2_IRQHandler,            /*!< Vec #44  IRQ #28 TIM2                           */
          TIM3_IRQHandler,            /*!< Vec #45  IRQ #29 TIM3                           */
          TIM4_IRQHandler,            /*!< Vec #46  IRQ #30 TIM4                           */
          I2C1_EV_IRQHandler,         /*!< Vec #47  IRQ #31 I2C1 Event                     */
          I2C1_ER_IRQHandler,         /*!< Vec #48  IRQ #32 I2C1 Error                     */
          I2C2_EV_IRQHandler,         /*!< Vec #49  IRQ #33 I2C2 Event                     */
          I2C2_ER_IRQHandler,         /*!< Vec #50  IRQ #34 I2C2 Error                     */
          SPI1_IRQHandler,            /*!< Vec #51  IRQ #35 SPI1                           */
          SPI2_IRQHandler,            /*!< Vec #52  IRQ #36 SPI2                           */
          USART1_IRQHandler,          /*!< Vec #53  IRQ #37 USART1                         */
          USART2_IRQHandler,          /*!< Vec #54  IRQ #38 USART2                         */
          USART3_IRQHandler,          /*!< Vec #55  IRQ #39 USART3                         */
          EXTI15_10_IRQHandler,       /*!< Vec #56  IRQ #40 EXTI Line 15..10               */
          RTCAlarm_IRQHandler,        /*!< Vec #57  IRQ #41 RTC Alarm through EXTI Line    */
          USBWakeUp_IRQHandler,       /*!< Vec #58  IRQ #42 USB Wakeup from suspend        */
          TIM8_BRK_IRQHandler,        /*!< Vec #59  IRQ #43 TIM8 Break Interrupt           */
          TIM8_UP_IRQHandler,         /*!< Vec #60  IRQ #44 TIM8 Update Interrupt          */
          TIM8_TRG_COM_IRQHandler,    /*!< Vec #61  IRQ #45 TIM8 Trigger and Commutation   */
          TIM8_CC_IRQHandler,         /*!< Vec #62  IRQ #46 TIM8 Capture Compare Interrupt */
          ADC3_IRQHandler,            /*!< Vec #63  IRQ #47 ADC3 global Interrupt          */
          FSMC_IRQHandler,            /*!< Vec #64  IRQ #48 FSMC global Interrupt          */
          SDIO_IRQHandler,            /*!< Vec #65  IRQ #49 SDIO global Interrupt          */
          TIM5_IRQHandler,            /*!< Vec #66  IRQ #50 TIM5 global Interrupt          */
          SPI3_IRQHandler,            /*!< Vec #67  IRQ #51 SPI3 global Interrupt          */
          UART4_IRQHandler,           /*!< Vec #68  IRQ #52 UART4 global Interrupt         */
          UART5_IRQHandler,           /*!< Vec #69  IRQ #53 UART5 global Interrupt         */
          TIM6_IRQHandler,            /*!< Vec #70  IRQ #54 TIM6 global Interrupt          */
          TIM7_IRQHandler,            /*!< Vec #71  IRQ #55 TIM7 global Interrupt          */
          DMA2_Channel1_IRQHandler,   /*!< Vec #72  IRQ #56 DMA2 Channel 1 global          */
          DMA2_Channel2_IRQHandler,   /*!< Vec #73  IRQ #57 DMA2 Channel 2 global          */
          DMA2_Channel3_IRQHandler,   /*!< Vec #74  IRQ #58 DMA2 Channel 3 global          */
          DMA2_Channel4_5_IRQHandler, /*!< Vec #75  IRQ #59 DMA2 Channel 45 global         */
          DMA2_Channel5_IRQHandler,   /*!< Vec #76  IRQ #60 DMA2 Channel 5 global          */
          ETH_IRQHandler,             /*!< Vec #77  IRQ #61 Ethernet global Interrupt               */
          ETH_WKUP_IRQHandler,        /*!< Vec #78  IRQ #62 Ethernet Wakeup through EXTI line       */
          CAN2_TX_IRQHandler,         /*!< Vec #79  IRQ #63 CAN2 TX Interrupt                       */
          CAN2_RX0_IRQHandler,        /*!< Vec #80  IRQ #64 CAN2 RX0 Interrupt                      */
          CAN2_RX1_IRQHandler,        /*!< Vec #81  IRQ #65 CAN2 RX1 Interrupt                      */
          CAN2_SCE_IRQHandler,        /*!< Vec #82  IRQ #66 CAN2 SCE Interrupt                      */
          OTG_FS_IRQHandler,          /*!< Vec #83  IRQ #67 USB OTG FS global Interrupt             */
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0,
 (intfunc)0xF1E0F85F         /* @0x1E0. This is for boot in RAM mode for STM32F10x High Density devices. */
}};
