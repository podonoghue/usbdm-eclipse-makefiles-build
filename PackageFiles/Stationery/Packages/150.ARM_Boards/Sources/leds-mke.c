/*
 * leds_mke.c
 *
 */
#include "derivative.h"
#include "utilities.h"
#include "Board_LEDs.h"
#include "leds.h"

/*
 * ====================================================================
 */

#ifdef LED_GREEN_PORT
void greenLedOn(void) {
   PCOR(LED_GREEN_PORT) = (1<<LED_GREEN_NUM);
}
void greenLedOff(void) {
   PSOR(LED_GREEN_PORT) = (1<<LED_GREEN_NUM);
}
#endif

// Define at least a dummy function as used by default main()
void greenLedToggle(void) {
#ifdef LED_GREEN_PORT
   PTOR(LED_GREEN_PORT) = (1<<LED_GREEN_NUM);
#endif
}

#ifdef LED_RED_PORT
void redLedOn(void) {
   PCOR(LED_RED_PORT) = (1<<LED_RED_NUM);
}
void redLedOff(void) {
   PSOR(LED_RED_PORT) = (1<<LED_RED_NUM);
}
void redLedToggle(void) {
   PTOR(LED_RED_PORT) = (1<<LED_RED_NUM);
}
#endif

#ifdef LED_BLUE_PORT
void blueLedOn(void) {
   PCOR(LED_BLUE_PORT) = (1<<LED_BLUE_NUM);
}
void blueLedOff(void) {
   PSOR(LED_BLUE_PORT) = (1<<LED_BLUE_NUM);
}
void blueLedToggle(void) {
   PTOR(LED_BLUE_PORT) = (1<<LED_BLUE_NUM);
}
#endif

#ifdef LED_ORANGE_PORT
void orangeLedOn(void) {
   PCOR(LED_ORANGE_PORT) = (1<<LED_ORANGE_NUM);
}
void orangeLedOff(void) {
   PSOR(LED_ORANGE_PORT) = (1<<LED_ORANGE_NUM);
}
void orangeLedToggle(void) {
   PTOR(LED_ORANGE_PORT) = (1<<LED_ORANGE_NUM);
}
#endif

void led_initialise(void) {
#ifdef LED_GREEN_PORT
   greenLedOff();
   PDDR(LED_GREEN_PORT)               |= (1<<LED_GREEN_NUM);
#endif

#ifdef LED_RED_PORT
   redLedOff();
   PDDR(LED_RED_PORT)             |= (1<<LED_RED_NUM);
#endif

#ifdef LED_BLUE_PORT
   blueLedOff();
   PDDR(LED_BLUE_PORT)              |= (1<<LED_BLUE_NUM);
#endif

#ifdef LED_ORANGE_PORT
   orangeLedOff();
   PDDR(LED_ORANGE_PORT)                |= (1<<LED_ORANGE_NUM);
#endif
}
