/*
 * leds.c
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
   PDOR(LED_GREEN_PORT) |= (1<<LED_GREEN_NUM);
}
void greenLedOff(void) {
   PDOR(LED_GREEN_PORT) &= ~(1<<LED_GREEN_NUM);
}
#endif

// Define at least a dummy function as used by default main()
void greenLedToggle(void) {
#ifdef LED_GREEN_PORT
   PDOR(LED_GREEN_PORT) ^= (1<<LED_GREEN_NUM);
#endif
}

#ifdef LED_RED_PORT
void redLedOn(void) {
   PDOR(LED_RED_PORT) |= (1<<LED_RED_NUM);
}
void redLedOff(void) {
   PDOR(LED_RED_PORT) &= (1<<LED_RED_NUM);
}
void redLedToggle(void) {
   PDOR(LED_RED_PORT) ^= (1<<LED_RED_NUM);
}
#endif

#ifdef LED_BLUE_PORT
void blueLedOn(void) {
   PDOR(LED_BLUE_PORT) |= (1<<LED_BLUE_NUM);
}
void blueLedOff(void) {
   PDOR(LED_BLUE_PORT) &= ~(1<<LED_BLUE_NUM);
}
void blueLedToggle(void) {
   PDOR(LED_BLUE_PORT) ^= (1<<LED_BLUE_NUM);
}
void blueLedEnable(void) {
   PDDR(LED_BLUE_PORT) |= (1<<LED_BLUE_NUM);
}
void blueLedDisable(void) {
   PDDR(LED_BLUE_PORT) &= ~(1<<LED_BLUE_NUM);
}
#endif

#ifdef LED_ORANGE_PORT
void orangeLedOn(void) {
   PDOR(LED_ORANGE_PORT) |= (1<<LED_ORANGE_NUM);
}
void orangeLedOff(void) {
   PDOR(LED_ORANGE_PORT) &= ~(1<<LED_ORANGE_NUM);
}
void orangeLedToggle(void) {
   PDOR(LED_ORANGE_PORT) ^= (1<<LED_ORANGE_NUM);
}
#endif

#ifndef PORT_PCR_DSE_MASK
#define PORT_PCR_DSE_MASK (0)
#endif

void led_initialise(void) {
#ifdef LED_GREEN_PORT
   SIM->SCGC5 |=  PORT_CLOCK_MASK(LED_GREEN_PORT);
   greenLedOff();
   PDDR(LED_GREEN_PORT)               |= (1<<LED_GREEN_NUM);
   PCR(LED_GREEN_PORT, LED_GREEN_NUM)  = PORT_PCR_MUX(1)|PORT_PCR_DSE_MASK;
#endif

#ifdef LED_RED_PORT
   SIM->SCGC5 |=  PORT_CLOCK_MASK(LED_RED_PORT);
   redLedOff();
   PDDR(LED_RED_PORT)             |= (1<<LED_RED_NUM);
   PCR(LED_RED_PORT, LED_RED_NUM)  = PORT_PCR_MUX(1)|PORT_PCR_DSE_MASK;
#endif

#ifdef LED_BLUE_PORT
   SIM->SCGC5 |=  PORT_CLOCK_MASK(LED_BLUE_PORT);
   blueLedOff();
   PDDR(LED_BLUE_PORT)              |= (1<<LED_BLUE_NUM);
   PCR(LED_BLUE_PORT, LED_BLUE_NUM)  = PORT_PCR_MUX(1)|PORT_PCR_DSE_MASK;
#endif

#ifdef LED_ORANGE_PORT
   SIM->SCGC5 |=  PORT_CLOCK_MASK(LED_ORANGE_PORT);
   orangeLedOff();
   PDDR(LED_ORANGE_PORT)                |= (1<<LED_ORANGE_NUM);
   PCR(LED_ORANGE_PORT, LED_ORANGE_NUM)  = PORT_PCR_MUX(1)|PORT_PCR_DSE_MASK;
#endif
}
