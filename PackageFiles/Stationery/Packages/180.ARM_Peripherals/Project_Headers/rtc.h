/*
 * rtc.h
 *
 *  Created on: 25/10/2013
 *      Author: podonoghue
 */

#ifndef RTC_H_
#define RTC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialise the Real Time Clock (RTC)
 */
void     rtc_initialise(void);

/*
 * Sets the system RTC time
 *
 *  @param timeSinceEpoch - time since the epoch in seconds
 */
void rtc_setTime(uint32_t timeSinceEpoch);

/**
 *  Get current alarm time
 *
 *  @return alarm time as 32-bit number
 */
uint32_t rtc_getTime(void);

/**
 *  Get current alarm time
 *
 *  @return alarm time as 32-bit number
 */
uint32_t rtc_getAlarmTime(void);

/**
 *  Get current alarm time
 *
 *  @param timeSinceEpoch - Alarm time in seconds relative to the epoch
 */
void     rtc_setAlarmTime(uint timeSinceEpoch);

/*
 * Sets the system RTC time
 *
 *  @param timeSinceEpoch - time since the epoch in seconds
 */
void setRealTimeValue(uint32_t timeSinceEpoch);

#ifndef RTC_USES_NAKED_HANDLERS
   typedef void (*RTCCallbackFunction)(void);
   RTCCallbackFunction rtc_setSecondsCallback(RTCCallbackFunction callback);
   RTCCallbackFunction rtc_setAlarmCallback(RTCCallbackFunction callback, uint32_t time);
#endif

#ifdef __cplusplus
}
#endif

#endif /* RTC_H_ */
