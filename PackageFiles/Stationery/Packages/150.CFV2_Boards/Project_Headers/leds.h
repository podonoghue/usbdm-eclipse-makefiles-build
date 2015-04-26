/*
 * leds.h
 *
 *  Created on: 14/04/2013
 *      Author: pgo
 */

#ifndef LEDS_H_
#define LEDS_H_

#ifdef __cplusplus
extern "C" {
#endif

void greenLedOn(void);
void greenLedOff(void);
void greenLedToggle(void);
void greenLed2On(void);
void greenLed2Off(void);
void greenLed2Toggle(void);
void redLedOn(void);
void redLedOff(void);
void redLedToggle(void);
void yellowLedOn(void);
void yellowLedOff(void);
void yellowLedToggle(void);

void led_initialise(void);

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H_ */
