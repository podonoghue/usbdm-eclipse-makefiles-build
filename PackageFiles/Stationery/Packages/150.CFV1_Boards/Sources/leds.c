#include <stdint.h>
#include "derivative.h"
#include "utilities.h"
#include "Board_LEDs.h"

#define ORANGE_LED_PTxPF        MXC->PTAPF4
#define ORANGE_LED_PTxPF_n(x)   MXC_PTAPF4_A0(x)
#define ORANGE_LED_FN           (1)
#define ORANGE_LED_DD           PTA->DD
#define ORANGE_LED_D            PTA->D
#define ORANGE_LED_MASK         (1<<0)

#define GREEN_LED_PTxPF         MXC->PTCPF2
#define GREEN_LED_PTxPF_n(x)    MXC_PTCPF2_C5(x)
#define GREEN_LED_FN            (1)
#define GREEN_LED_DD            PTC->DD
#define GREEN_LED_D             PTC->D
#define GREEN_LED_MASK          (1<<5)

void greenLedOn(void) {
   GREEN_LED_D &= ~GREEN_LED_MASK;
}
void greenLedOff(void) {
   GREEN_LED_D |= GREEN_LED_MASK;
}
void greenLedEnable(void) {
   GREEN_LED_DD &= ~GREEN_LED_MASK;
}
void greenLedDisable(void) {
   GREEN_LED_DD |= GREEN_LED_MASK;
}
void greenLedToggle(void) {
   GREEN_LED_D ^= GREEN_LED_MASK;
}
#ifdef ORANGE_LED_MASK
void orangeLedOn(void) {
   ORANGE_LED_D &= ~ORANGE_LED_MASK;
}
void orangeLedOff(void) {
   ORANGE_LED_D |= ORANGE_LED_MASK;
}
void orangeLedToggle(void) {
   ORANGE_LED_D ^= ORANGE_LED_MASK;
}
#endif

#define PORT_CLOCK_ENABLE_REG SIM->SCGC6
#define CLOCK_MASK(port) CONCAT4_(SIM_SCGC6,_PORT,port,_MASK)

void led_initialise(void) {
   PORT_CLOCK_ENABLE_REG |=  CLOCK_MASK(LED_GREEN_PORT);
   greenLedOff();
   ORANGE_LED_PTxPF = (ORANGE_LED_PTxPF & ~ORANGE_LED_PTxPF_n(0xF))|ORANGE_LED_PTxPF_n(ORANGE_LED_FN);
   ORANGE_LED_DD   |= ORANGE_LED_MASK;

   PORT_CLOCK_ENABLE_REG |=  CLOCK_MASK(LED_ORANGE_PORT);
   orangeLedOff();
   GREEN_LED_DD    |= GREEN_LED_MASK;
   GREEN_LED_PTxPF  = (GREEN_LED_PTxPF & ~GREEN_LED_PTxPF_n(0xF))|GREEN_LED_PTxPF_n(GREEN_LED_FN);
}
