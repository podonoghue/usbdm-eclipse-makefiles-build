/*****************************************************************
 * @file     segment_lcd.h
 *
 * Routines to interface to Segment LCD on FRDM-KL46Z
 *
 * Based on:
 * https://eewiki.net/display/microcontroller/Using+the+Segment+LCD+Controller+on+the+Kinetis+KL46
 *
 * @revision 1.0 EPH Initial version
 * @date     8/20/2014
 * @author   Ethan Hettwer
 *
 *****************************************************************/

#ifndef __SEG_LCD_H_
#define __SEG_LCD_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Set Decimal point/colon on or off
 *
 * @param digit 0-2 => DP, 3 => colon
 * @param value true/false => on/off
 *
 */
void SegLCD_SetDPs(int digit, int value);

/**
 * Initializes all components of the SLCD on the FRDM-KL46Z
 */
void SegLCD_Init(void);

/**
 * Displays a hex value in a specified position on the LCD.  \n
 * Will not display error if value is outside of range, but display will not be updated.
 *
 * @param value    Value to display (0-F)
 * @param position Digit position (left=1 - 4=right)
 */
void SegLCD_Set(uint8_t value,uint8_t position);

/**
 * Displays a 4 digit decimal number
 *
 * @param value Value to display (0-9999)
 */
void SegLCD_DisplayDecimal(uint16_t value);

/**
 * Displays a 4 Digit hex number
 *
 * @param value Value to display (0x0-0xFFFF)
 */
void SegLCD_DisplayHex(uint16_t value);

/**
 * Displays two numbers in hour:minute format i.e. separated by colon
 *
 * @param hour Hours value to display (0-99)
 * @param minutes Minutes value to display (0-59)
 *
 */
void SegLCD_DisplayTime(uint8_t hour, uint8_t minutes);

/**
 * Display error number
 *
 * @param ErrorNum Error number value 0-F.
 *        If ErrorNum is outside of that range, just displays Err
 */
void SegLCD_DisplayError(uint8_t ErrorNum);

#ifdef __cplusplus
}
#endif

#endif
