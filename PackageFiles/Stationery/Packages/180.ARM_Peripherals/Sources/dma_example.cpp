/*
 * capture.cpp
 *
 *  Created on: 17 Oct 2016
 *      Author: podonoghue
 */
#include <string.h>
#include "system.h"
#include "derivative.h"
#include "capture.h"

/** PIT channel to use */
constexpr int PIT_CHANNEL = 0;

/** ADC channel to use */
constexpr int ADC_CHANNEL = 0;

/** PDB channel used. Associated with ADC 0 */
static constexpr uint32_t PDB_CHANNEL_NUM = 0;

/** PDB Pretrigger. Associated with ADC SC1[PDB_PRETRIGGER_NUM]/R[PDB_PRETRIGGER_NUM] */
static constexpr uint32_t PDB_PRETRIGGER_NUM  = 0;
static constexpr uint32_t PDB_PRETRIGGER_MASK = (1<<PDB_PRETRIGGER_NUM);

/** DMAMUX source selection for ADC0 */
static constexpr uint32_t DMAMUX_ADC0_SOURCE = 40;

/** DMAMUX/DMA channel */
static constexpr uint32_t DMA_CHANNEL = 0;

/** Buffer for captured values */
static uint32_t buffer[MAX_DATA_VALUES];

/** Current captureIndex for capture values */
static volatile unsigned captureIndex = 0;

/** PIT capture interval in ticks */
static long interval = 1000;

/** Mux setting for ADC */
constexpr int ADC_MUX  = 0;

/** Mux setting for GPIO */
constexpr int GPIO_MUX = 1;

/** PTC.11 = Vdd for POT */
constexpr int VDD_PIN_MASK  = (1<<11);

/** PTC.5 = Gnd for POT */
constexpr int GND_PIN_MASK  = (1<<5);

/**
 * Calculates transfer size field for DMA_TCD.SSIZE or DSIZE
 * 8  => 0
 * 16 => 1
 * 32 => 2
 */
constexpr uint8_t tfSize(int sizeInBytes) {
   return (sizeInBytes==1)?0:((sizeInBytes==2)?1:((sizeInBytes==4)?2:((sizeInBytes==16)?8:15)));
}

/**
 * TCD data for DMA - This allows the TCD to be initialise by a single assignment
 */
static const DMA_Type::DMA_Tcd tcd = {
      /*  SADDR           */ (uint32_t)&ADC0->R[0],                      // Read data from ADC result address
      /*  SOFF            */ 0,                                          // No increment (fixed address)
      /*  ATTR            */ DMA_ATTR_SMOD(0)|                           // Suppress source modulo feature
      /*  "               */ DMA_ATTR_SSIZE(tfSize(sizeof(ADC0->R[0])))| // Source size
      /*  "               */ DMA_ATTR_DMOD(0)|                           // Suppress destination modulo feature
      /*  "               */ DMA_ATTR_DSIZE(tfSize(sizeof(buffer[0]))),  // Destination size
      /*  NBYTES_MLNO     */ sizeof(buffer[0]),                          // Number of bytes to transfer on each request
      /*  SLAST           */ 0,                                          // No adjustment to source address (fixed ADC0->R[0])
      /*  DADDR           */ (uint32_t)buffer,                           // Destination address (initial address to store data at)
      /*  DOFF            */ sizeof(buffer[0]),                          // Offset added to step destination address (word size)
      /*  CITER_ELINKNO   */ DMA_CITER_ELINKNO_ELINK(0)|                 // No linking
      /*  "               */ DMA_CITER_ELINKNO_CITER(MAX_DATA_VALUES),   // Counts down from this value
      /*  DLASTSGA        */ -(sizeof(buffer)),                          // Reset DADR after complete major loop
      /*  CSR             */ DMA_CSR_BWC(0)|                             // Bandwidth - max
      /*  "               */ DMA_CSR_DONE(0)|                            // Clear done
      /*  "               */ DMA_CSR_MAJORELINK(0)|                      // No channel linking
      /*  "               */ DMA_CSR_ESG(0)|                             // No scatter/gather
      /*  "               */ DMA_CSR_DREQ(1)|                            // Auto-clear ERQ when major loop complete
      /*  "               */ DMA_CSR_INTHALF(0)|                         // No interrupt on half-done
      /*  "               */ DMA_CSR_INTMAJOR(0)|                        // No interrupt on done
      /*  "               */ DMA_CSR_START(0),                           // Don't start yet
      /*  BITER_ELINKNO   */ tcd.CITER_ELINKNO,                          // Reload value for BITER_ELINKNO = CITER_ELINKNO
};

/**
 * Set capture interval in milliseconds
 *
 * @param microseconds Rate to set in us
 */
void setCaptureRate(int microseconds) {
   interval = microseconds*(SystemCoreClock/1000000);
}

void initDma(const DMA_Type::DMA_Tcd &tcd);

/**
 * Does once-off initialisations of:\n
 *  - Ports used by ADC (including POT)
 *  - PIT (basic setup - not active)\n
 *  - PDB\n
 *  - ADC\n
 *  - DMAMUX\n
 *  - DMA
 */
static void captureInitialise() {
   static bool initDone = false;

   // Only initialise once
   if (initDone) {
      return;
   }
   initDone = true;

   /*
    * Set up POT pins
    *
    * Note: ADC input does not have pin mux
    */
   SIM->SCGC5   |= SIM_SCGC5_PORTC_MASK;
   PORTC->GPCLR  = PORT_PCR_MUX(GPIO_MUX)|PORT_PCR_DSE(1)|PORT_GPCLR_GPWE(VDD_PIN_MASK|GND_PIN_MASK);
   GPIOC->PDDR  |= VDD_PIN_MASK|GND_PIN_MASK;
   GPIOC->PCOR   = GND_PIN_MASK;
   GPIOC->PSOR   = VDD_PIN_MASK;
   /*
    * Set up ADC
    */
   SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;

   // Configure ADC for software triggered conversion + IRQ
   ADC0->CFG1 =
         ADC_CFG1_ADIV(2)|        // Divide-by 4, 48MHz/4 => 12MHz
         ADC_CFG1_MODE(0)|        // 8-bit conversions
         ADC_CFG1_ADICLK(0);      // Bus clock source (48MHz)

   ADC0->CFG2 = ADC_CFG2_ADLSTS(0);

   ADC0->SC2  =
         ADC_SC2_ADTRG(1)| // Hardware trigger
         ADC_SC2_DMAEN(1); // Generate DMA requests

   // Set up ADC capture on channel
   ADC0->SC1[0] = 
         ADC_SC1_ADCH(ADC_CHANNEL)| // Channel for conversion
         ADC_SC1_AIEN(0);           // No interrupt when complete

   // Enable ADC0 interrupts in NVIC
   NVIC_EnableIRQ(ADC0_IRQn);

   // Set arbitrary priority level
   NVIC_SetPriority(ADC0_IRQn, 8);
   /*
    * Set up PDB
    */
   SIM->SCGC6 |= SIM_SCGC6_PDB_MASK;

   // Enable Pre-trigger for ADC (SC1[0],R[0] only)
   PDB0->CH[PDB_CHANNEL_NUM].C1 =
         PDB_C1_BB(0)  |                  // No Back-to-back operation
         PDB_C1_TOS(0) |                  // Pre-trigger output select
         PDB_C1_EN(PDB_PRETRIGGER_MASK);  // Pre-trigger enable

   // Not used
   PDB0->MOD = -1;

   // Clear flags
   PDB0->CH[PDB_CHANNEL_NUM].S = 0xFFFFFFFF;

   // No pre-trigger delay
   PDB0->CH[PDB_CHANNEL_NUM].DLY[0] = 10;

   // No pulse outputs
   PDB0->POEN = 0;

   PDB0->SC =
         PDB_SC_LDOK(1) |    // Load registers
         PDB_SC_MULT(0) |    // Multiplication factor (1,10,20,40)
         PDB_SC_CONT(0) |    // Continuous mode
         PDB_SC_TRGSEL(4) |  // PIT-CH0 // Software trigger
         PDB_SC_PDBEN(1);    // Enable

   /*
    * Set up PIT (basic only - channel configured per use)
    */
   // Enable PIT clock
   SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;

   // Enable PIT
   PIT->MCR = PIT_MCR_MDIS(0)|PIT_MCR_FRZ(1);

   // Set up DMA channel
   initDma(tcd);
}

/**
 * DMA set up\n
 * The actual DMA transfer is enable by writing to DMA0->SERQ
 *
 * @param tcd TCD describing transfer
 */
void initDma(const DMA_Type::DMA_Tcd &tcd) {

   // Clock to DMA multiplexor
   SIM->SCGC6 |= SIM_SCGC6_DMAMUX0_MASK;

   // Connect DMA channel to ADC and enable
   DMAMUX0->CHCFG[DMA_CHANNEL] =
         DMAMUX_CHCFG_ENBL(1)|                     // Enable channel
         DMAMUX_CHCFG_TRIG(0)|                     // No periodic trigger
         DMAMUX_CHCFG_SOURCE(DMAMUX_ADC0_SOURCE);  // Connect to ADC

   // Clock to DMA controller
   SIM->SCGC7 |= SIM_SCGC7_DMA_MASK;

   // Basic options
   DMA0->CR =
         DMA_CR_ERCA(1) |  // Round-robin priority
         DMA_CR_HOE(1);    // Halt on any error

   // Disable error interrupts from channel
   DMA0->CEEI = DMA_CEEI_CEEI(DMA_CHANNEL);

   // Clear error from channel
   DMA0->CERR = DMA_CERR_CERR(DMA_CHANNEL);

   // Disable interrupts from channel
   DMA0->CINT = DMA_CINT_CINT(DMA_CHANNEL);

   // Set up TCD describing transfer
   DMA0->TCD[DMA_CHANNEL] = tcd;

   // Enable the requests from channel
   DMA0->SERQ = DMA_SERQ_SERQ(DMA_CHANNEL);
}

/**
 * Responsible for capturing the data
 *
 * @return Pointer to buffer containing captured values
 */
uint32_t *capture() {
   captureIndex = 0;

   // Do once-off initialisation
   captureInitialise();

   //memset(buffer, -1, sizeof(buffer)); // For debug

   /*
    * Per-sequence set up
    */
   // Make sure no data from last capture
   (void)ADC0->R[0];

   // Enable DMA requests from ADC
   DMA0->SERQ = DMA_CHANNEL;

   // Set PIT interval (reload value)
   PIT->CHANNEL[PIT_CHANNEL].LDVAL = interval-1;

   // Enable this channel without interrupts (using PDB to trigger ADC)
   PIT->CHANNEL[PIT_CHANNEL].TCTRL = PIT_TCTRL_TEN(1)|PIT_TCTRL_TIE(0);

   // Wait until capture completed
   while ((DMA0->ERQ&(1<<DMA_CHANNEL)) != 0) {
      __WFI();
   }

   // Stop PIT
   PIT->CHANNEL[PIT_CHANNEL].TCTRL = 0;

   return buffer;
}
