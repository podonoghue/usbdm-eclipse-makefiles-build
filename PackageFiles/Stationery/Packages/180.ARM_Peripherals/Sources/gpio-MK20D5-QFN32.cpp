/**
 * @file      gpio.cpp (from gpio-MK20D5-QFN32.cpp)
 *
 * @brief     Pin declarations for MK20D5-QFN32, generated from MK20D5.csv
 *            Devices   [MK20DN32M5, MK20DN64M5, MK20DN128M5, MK20DX32M5, MK20DX64M5, MK20DX128M5]
 *            Reference [K20P64M50SF0RM]
 */

#include "gpio.h"

namespace USBDM {

#if (DO_MAP_PINS_ON_RESET>0)
struct PinInit {
   uint32_t pcrValue;
   uint32_t volatile *pcr;
};

static constexpr PinInit pinInit[] = {
#if (PTA0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[0]},
#endif
#if (PTA1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[1]},
#endif
#if (PTA2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[2]},
#endif
#if (PTA3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[3]},
#endif
#if (PTA4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[4]},
#endif
#if (PTA18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA18_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[18]},
#endif
#if (PTA19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA19_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[19]},
#endif
#if (PTB0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[0]},
#endif
#if (PTB1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[1]},
#endif
#if (PTC1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[1]},
#endif
#if (PTC2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[2]},
#endif
#if (PTC3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[3]},
#endif
#if (PTC4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[4]},
#endif
#if (PTC5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[5]},
#endif
#if (PTC6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[6]},
#endif
#if (PTC7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[7]},
#endif
#if (PTD4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[4]},
#endif
#if (PTD5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[5]},
#endif
#if (PTD6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[6]},
#endif
#if (PTD7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[7]},
#endif
};

/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
void usbdm_PinMapping() {
#if (PTA0_SIG_SEL>=0) || (PTA1_SIG_SEL>=0) || (PTA2_SIG_SEL>=0) || (PTA3_SIG_SEL>=0) || \
    (PTA4_SIG_SEL>=0) || (PTA18_SIG_SEL>=0) || (PTA19_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTA_CLOCK_MASK;
#endif
#if (PTB0_SIG_SEL>=0) || (PTB1_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTB_CLOCK_MASK;
#endif
#if (PTC1_SIG_SEL>=0) || \
    (PTC2_SIG_SEL>=0) || (PTC3_SIG_SEL>=0) || (PTC4_SIG_SEL>=0) || (PTC5_SIG_SEL>=0) || \
    (PTC6_SIG_SEL>=0) || (PTC7_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTC_CLOCK_MASK;
#endif
#if (PTD4_SIG_SEL>=0) || (PTD5_SIG_SEL>=0) || (PTD6_SIG_SEL>=0) || \
    (PTD7_SIG_SEL>=0)
   SIM->FIXED_PORT_CLOCK_REG |= PORTD_CLOCK_MASK;
#endif

   for (const PinInit *p=pinInit; p<(pinInit+(sizeof(pinInit)/sizeof(pinInit[0]))); p++) {
      *(p->pcr) = p->pcrValue;
   }
}
#endif

} // End namespace USBDM
