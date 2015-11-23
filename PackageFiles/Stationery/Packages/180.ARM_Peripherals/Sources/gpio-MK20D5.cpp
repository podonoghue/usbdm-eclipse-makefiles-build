 /**
  * @file     gpio.cpp (from gpio-MK20D5.cpp)
  *
  * @brief   Pin declarations for MK20D5
  */

#include "gpio.h"
#include "pin_mapping.h"


#if defined(DO_MAP_PINS_ON_RESET) && (DO_MAP_PINS_ON_RESET>0)
struct PinInit {
   uint32_t pcrValue;
   uint32_t volatile *pcr;
};

static const PinInit pinInit[] = {
#if defined(PTA0_SIG_SEL) && (PTA0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[0]},
#endif
#if defined(PTA1_SIG_SEL) && (PTA1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[1]},
#endif
#if defined(PTA2_SIG_SEL) && (PTA2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[2]},
#endif
#if defined(PTA3_SIG_SEL) && (PTA3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[3]},
#endif
#if defined(PTA4_SIG_SEL) && (PTA4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[4]},
#endif
#if defined(PTA5_SIG_SEL) && (PTA5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[5]},
#endif
#if defined(PTA12_SIG_SEL) && (PTA12_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA12_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[12]},
#endif
#if defined(PTA13_SIG_SEL) && (PTA13_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA13_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[13]},
#endif
#if defined(PTA18_SIG_SEL) && (PTA18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA18_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[18]},
#endif
#if defined(PTA19_SIG_SEL) && (PTA19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA19_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[19]},
#endif
#if defined(PTB0_SIG_SEL) && (PTB0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[0]},
#endif
#if defined(PTB1_SIG_SEL) && (PTB1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[1]},
#endif
#if defined(PTB2_SIG_SEL) && (PTB2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[2]},
#endif
#if defined(PTB3_SIG_SEL) && (PTB3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[3]},
#endif
#if defined(PTB16_SIG_SEL) && (PTB16_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB16_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[16]},
#endif
#if defined(PTB17_SIG_SEL) && (PTB17_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB17_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[17]},
#endif
#if defined(PTB18_SIG_SEL) && (PTB18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB18_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[18]},
#endif
#if defined(PTB19_SIG_SEL) && (PTB19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB19_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[19]},
#endif
#if defined(PTC0_SIG_SEL) && (PTC0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[0]},
#endif
#if defined(PTC1_SIG_SEL) && (PTC1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[1]},
#endif
#if defined(PTC2_SIG_SEL) && (PTC2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[2]},
#endif
#if defined(PTC3_SIG_SEL) && (PTC3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[3]},
#endif
#if defined(PTC4_SIG_SEL) && (PTC4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[4]},
#endif
#if defined(PTC5_SIG_SEL) && (PTC5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[5]},
#endif
#if defined(PTC6_SIG_SEL) && (PTC6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[6]},
#endif
#if defined(PTC7_SIG_SEL) && (PTC7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[7]},
#endif
#if defined(PTC8_SIG_SEL) && (PTC8_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC8_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[8]},
#endif
#if defined(PTC9_SIG_SEL) && (PTC9_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC9_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[9]},
#endif
#if defined(PTC10_SIG_SEL) && (PTC10_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC10_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[10]},
#endif
#if defined(PTC11_SIG_SEL) && (PTC11_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC11_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[11]},
#endif
#if defined(PTD0_SIG_SEL) && (PTD0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[0]},
#endif
#if defined(PTD1_SIG_SEL) && (PTD1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[1]},
#endif
#if defined(PTD2_SIG_SEL) && (PTD2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[2]},
#endif
#if defined(PTD3_SIG_SEL) && (PTD3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[3]},
#endif
#if defined(PTD4_SIG_SEL) && (PTD4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[4]},
#endif
#if defined(PTD5_SIG_SEL) && (PTD5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[5]},
#endif
#if defined(PTD6_SIG_SEL) && (PTD6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[6]},
#endif
#if defined(PTD7_SIG_SEL) && (PTD7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[7]},
#endif
#if defined(PTE0_SIG_SEL) && (PTE0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[0]},
#endif
#if defined(PTE1_SIG_SEL) && (PTE1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[1]},
#endif
};

/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
void usbdm_PinMapping() {
#if (defined(PTA0_SIG_SEL) && (PTA0_SIG_SEL>=0)) || \
    (defined(PTA1_SIG_SEL) && (PTA1_SIG_SEL>=0)) || \
    (defined(PTA2_SIG_SEL) && (PTA2_SIG_SEL>=0)) || \
    (defined(PTA3_SIG_SEL) && (PTA3_SIG_SEL>=0)) || \
    (defined(PTA4_SIG_SEL) && (PTA4_SIG_SEL>=0)) || \
    (defined(PTA5_SIG_SEL) && (PTA5_SIG_SEL>=0)) || \
    (defined(PTA12_SIG_SEL) && (PTA12_SIG_SEL>=0)) || \
    (defined(PTA13_SIG_SEL) && (PTA13_SIG_SEL>=0)) || \
    (defined(PTA18_SIG_SEL) && (PTA18_SIG_SEL>=0)) || \
    (defined(PTA19_SIG_SEL) && (PTA19_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTA_CLOCK_MASK;
#endif

#if (defined(PTB0_SIG_SEL) && (PTB0_SIG_SEL>=0)) || \
    (defined(PTB1_SIG_SEL) && (PTB1_SIG_SEL>=0)) || \
    (defined(PTB2_SIG_SEL) && (PTB2_SIG_SEL>=0)) || \
    (defined(PTB3_SIG_SEL) && (PTB3_SIG_SEL>=0)) || \
    (defined(PTB16_SIG_SEL) && (PTB16_SIG_SEL>=0)) || \
    (defined(PTB17_SIG_SEL) && (PTB17_SIG_SEL>=0)) || \
    (defined(PTB18_SIG_SEL) && (PTB18_SIG_SEL>=0)) || \
    (defined(PTB19_SIG_SEL) && (PTB19_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTB_CLOCK_MASK;
#endif

#if (defined(PTC0_SIG_SEL) && (PTC0_SIG_SEL>=0)) || \
    (defined(PTC1_SIG_SEL) && (PTC1_SIG_SEL>=0)) || \
    (defined(PTC2_SIG_SEL) && (PTC2_SIG_SEL>=0)) || \
    (defined(PTC3_SIG_SEL) && (PTC3_SIG_SEL>=0)) || \
    (defined(PTC4_SIG_SEL) && (PTC4_SIG_SEL>=0)) || \
    (defined(PTC5_SIG_SEL) && (PTC5_SIG_SEL>=0)) || \
    (defined(PTC6_SIG_SEL) && (PTC6_SIG_SEL>=0)) || \
    (defined(PTC7_SIG_SEL) && (PTC7_SIG_SEL>=0)) || \
    (defined(PTC8_SIG_SEL) && (PTC8_SIG_SEL>=0)) || \
    (defined(PTC9_SIG_SEL) && (PTC9_SIG_SEL>=0)) || \
    (defined(PTC10_SIG_SEL) && (PTC10_SIG_SEL>=0)) || \
    (defined(PTC11_SIG_SEL) && (PTC11_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTC_CLOCK_MASK;
#endif

#if (defined(PTD0_SIG_SEL) && (PTD0_SIG_SEL>=0)) || \
    (defined(PTD1_SIG_SEL) && (PTD1_SIG_SEL>=0)) || \
    (defined(PTD2_SIG_SEL) && (PTD2_SIG_SEL>=0)) || \
    (defined(PTD3_SIG_SEL) && (PTD3_SIG_SEL>=0)) || \
    (defined(PTD4_SIG_SEL) && (PTD4_SIG_SEL>=0)) || \
    (defined(PTD5_SIG_SEL) && (PTD5_SIG_SEL>=0)) || \
    (defined(PTD6_SIG_SEL) && (PTD6_SIG_SEL>=0)) || \
    (defined(PTD7_SIG_SEL) && (PTD7_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTD_CLOCK_MASK;
#endif

#if (defined(PTE0_SIG_SEL) && (PTE0_SIG_SEL>=0)) || \
    (defined(PTE1_SIG_SEL) && (PTE1_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTE_CLOCK_MASK;

#endif

   for (const PinInit *p=pinInit; p<(pinInit+(sizeof(pinInit)/sizeof(pinInit[0]))); p++) {
      *(p->pcr) = p->pcrValue;
   }
}
#endif

