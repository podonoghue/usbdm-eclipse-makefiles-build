/*****************************************************************
 * @file     Segment_LCD.h (derived from segment_lcd-MKL46Z4.c)
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

#include <string.h>
#include "derivative.h"
#include "segment_lcd.h"

using namespace USBDM;

/*
 * s401 Pin KL46 Pin
 * =========================
 *     1    PTD0   LCD_P40   (COM0)
 *     2    PTE4   LCD_P52   (COM1)
 *     3    PTB23  LCD_P19   (COM2)
 *     4    PTB22  LCD_P18   (COM3)
 *
 *     5    PTC17  LCD_P37   (1D/1E/1G/1F)
 *     6    PTB21  LCD_P17   (DP1/1C/1B/1A)
 *     7    PTB7   LCD_P7    (2D/2E/2G/2F)
 *     8    PTB8   LCD_P8    (DP2/2C/2B/2A)
 *     9    PTE5   LCD_P53   (3D/3E/3G/3F)
 *    10    PTC18  LCD_P38   (DP3/3C/3B/3A)
 *    11    PTB10  LCD_P10   (4D/4E/4G/4F)
 *    12    PTB11  LCD_P11   (COL/4C/4B/4A)
 */

// Create macros for segments
#define LCD_SEG_D         0x11
#define LCD_SEG_E         0x22
#define LCD_SEG_G         0x44
#define LCD_SEG_F         0x88
#define LCD_SEG_DECIMAL   0x11
#define LCD_SEG_C         0x22
#define LCD_SEG_B         0x44
#define LCD_SEG_A         0x88
#define LCD_CLEAR         0x00

// Create Macros for each pin
#define LCD_BACKPLANE0    40u
#define LCD_BACKPLANE1    52u
#define LCD_BACKPLANE2    19u
#define LCD_BACKPLANE3    18u
#define LCD_FRONTPLANE0   37u
#define LCD_FRONTPLANE1   17u
#define LCD_FRONTPLANE2    7u
#define LCD_FRONTPLANE3    8u
#define LCD_FRONTPLANE4   53u
#define LCD_FRONTPLANE5   38u
#define LCD_FRONTPLANE6   10u
#define LCD_FRONTPLANE7   11u

const static int8_t LCD_Frontplane_Pin[] = {
      LCD_FRONTPLANE0,
      LCD_FRONTPLANE1,
      LCD_FRONTPLANE2,
      LCD_FRONTPLANE3,
      LCD_FRONTPLANE4,
      LCD_FRONTPLANE5,
      LCD_FRONTPLANE6,
      LCD_FRONTPLANE7,
};

const static int8_t LCD_Backplane_Pin[] = {
      LCD_BACKPLANE0,
      LCD_BACKPLANE1,
      LCD_BACKPLANE2,
      LCD_BACKPLANE3,
};

/**
 * Set Decimal point/colon on or off
 *
 * @param digit 0-2 => DP, 3 => colon
 * @param value true/false => on/off
 *
 */
void SegLCD_SetDPs(int digit, int value) {
   if (value) {
      LCD->WF8B[LCD_Frontplane_Pin[2*digit+1]]  |=  LCD_SEG_DECIMAL;
   }
   else {
      LCD->WF8B[LCD_Frontplane_Pin[2*digit+1]]  &=  ~LCD_SEG_DECIMAL;
   }
}

/**
 * Initialises all components of the SLCD on the FRDM-KL46Z
 *
 * Assumes use of 32kHz OSCERCLK clock
 */
void SegLCD_Init(void){

   // Enable Clock to ports B, C, D and E, and SegLCD Peripheral
   SIM->SCGC5 |=  SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK | SIM_SCGC5_SLCD_MASK;

   // Set PADSAFE to disable LCD while configuring
   LCD->GCR   |=  LCD_GCR_PADSAFE_MASK;

   // Clear LCDEN (LCD Enable) while configuring
   LCD->GCR   &= ~LCD_GCR_LCDEN_MASK;

   /*
    * Configure pins.
    * From Reference manual, set pins to MUX 0 for normal LCD display operation, only use MUX 7 if using LCD fault detection
    */
   PORTB->GPCLR   = PORT_GPCLR_GPWE((1<<7)|(1<<8)|(1<<10)|(1<<11))|PORT_PCR_MUX(0);
   PORTB->GPCHR   = PORT_GPCLR_GPWE((1<<(21-16))|(1<<(22-16))|(1<<(23-16)))|PORT_PCR_MUX(0);
   PORTC->GPCHR   = PORT_GPCLR_GPWE((1<<(17-16))|(1<<(18-16)))|PORT_PCR_MUX(0);
   PORTD->GPCLR   = PORT_GPCLR_GPWE((1<<0))||PORT_PCR_MUX(0);
   PORTE->GPCLR   = PORT_GPCLR_GPWE((1<<4)|(1<<5))|PORT_PCR_MUX(0);

   /*
    * Configure LCD Registers
    * Configure LCD_GCR - General Control Register, controls most options in LCD Peripheral
    */
   LCD->GCR =
       //LCD_GCR_RVEN_MASK |      // Clear LCD_GCR_RVEN, disable voltage regulator.
         LCD_GCR_RVTRIM(0x00) |   // Set RVTRIM to 0, irrelevant as voltage regulator is disabled, but setting it to a known state.
         LCD_GCR_CPSEL_MASK |     // Set LCD_GCR_CPSEL to use capacitor charge pump.
         LCD_GCR_LADJ(0x03) |     // Set LCD_GCR_LADJ to 11, slow clock rate = lower power, but higher load capacitance on the LCD requires higher clock speed.
         //LCD_GCR_VSUPPLY |      // Clear LCD_GCR_VSUPPLY, drive VLL3 externally.
         LCD_GCR_PADSAFE_MASK |   // Set LCD_GCR_PADSAFE, leave enabled during configuration process.
         //LCD_GCR_FDCIEN_MASK |  // Clear LCD_GCR_FDCIEN, No interrupt from fault dection.
         LCD_GCR_ALTDIV(0x03) |   // Set LCD_GCR_ALTDIV to 11, divide alternate clock by 512.  This is assuming an 8MHz External Crystal is used.
         LCD_GCR_ALTSOURCE_MASK | // Set LCD_GCR_ALTSOURCE, Part of setting clock source to OSCERCLK, or external oscillator.
         LCD_GCR_FFR_MASK |       // Set LCD_GCR_FFR, allow an LCD Frame Frequency of 46.6Hz to 146.2Hz.  Disable to change range to 23.3Hz to 73.1Hz.
         //LCD_GCR_LCDDOZE_MASK | // Clear LCD_GCR_LCDDOZE, allows LCD peripheral to run even in doze mode.  Set to disable LCD in doze mode.
         //LCD_GCR_LCDSTP_MASK |  // Clear LCD_GCR_LCDSTP, allows LCD peripheral to run even in stop mode.  Set to disable LCD in stop mode.
         //LCD_GCR_LCDEN_MASK |   // Clear LCD_GCR_LCDEN, Disables all front and backplane pins.  Leave disabled during configuration process.
         LCD_GCR_SOURCE_MASK |    // Set LCD_GCR_SOURCE, Part of setting clock source to OSCERCLK, or external oscillator.
         LCD_GCR_LCLK(0x04) |     // Set LCD_GCR_LCLK to 111, LCD Clock prescaler where LCD controller frame frequency = LCD clock/((DUTY  |  1) x 8 x (4 | LCLK[2:0]) x Y), where Y = 2, 2, 3, 3, 4, 5, 8, 16 chosen by module duty cycle config
         LCD_GCR_DUTY(0x03);      // Set LCD_GCR_DUTY to 011, Have 4 backplane pins, so need a 1/4 duty cycle.

   // Configure LCD_SEG_AR  - Auxiliary Register, controls blinking of LCD
   LCD->AR =
         //LCD_AR_BLINK_MASK |    // Clear LCD_SEG_AR_BLINK, Disable SLCD blinking.  Enable to make LCD Blink.
         //LCD_AR_ALT_MASK |      // Clear LCD_SEG_AR_ALT, if enabled LCD back plane sequencer changes to an alternate display.  Only functional if DUTY[2:0] is less than 100(binary).  This allows a blink screen that is not blank.
         //LCD_AR_BLANK_MASK |    // Clear LCD_SEG_AR_BLANK, asserting bit clears all segments in LCD.
         //LCD_AR_BMODE_MASK |    // Clear LCD_SEG_AR_BMODE, if enabled displays alternate display during blink period instead of blank.
         LCD_AR_BRATE(0x00);      // Set LCD_SEG_AR_BRATE to 000.  Frequency of blink is determined by LCD clock/(2^(12 + BRATE))

   // Configure LCD_SEG_FDCR - Fault Detect Control Register, controls use of Fault Detect features of SLCD.
   LCD->FDCR = 0x00000000;        // Clear all bits in FDCR.  As this will not be covering use of fault detect, this register is cleared.

   // Configure LCD_PENn - Pin Enable Register, controls which of the possible LCD pins are used
   // LCD->PEN[0] contains bits 0-31, while LCD->PEN[1] contains bits 32-63.
   // For pins >= 32, set in LCD->PEN[1] as LCD_PEN_PEN(Pin#-32)
   LCD->PEN[LCD_FRONTPLANE0/32] |= 1UL<<((uint32_t)(LCD_FRONTPLANE0%32));
   LCD->PEN[LCD_FRONTPLANE1/32] |= 1UL<<((uint32_t)(LCD_FRONTPLANE1%32));
   LCD->PEN[LCD_FRONTPLANE2/32] |= 1UL<<((uint32_t)(LCD_FRONTPLANE2%32));
   LCD->PEN[LCD_FRONTPLANE3/32] |= 1UL<<((uint32_t)(LCD_FRONTPLANE3%32));
   LCD->PEN[LCD_FRONTPLANE4/32] |= 1UL<<((uint32_t)(LCD_FRONTPLANE4%32));
   LCD->PEN[LCD_FRONTPLANE5/32] |= 1UL<<((uint32_t)(LCD_FRONTPLANE5%32));
   LCD->PEN[LCD_FRONTPLANE6/32] |= 1UL<<((uint32_t)(LCD_FRONTPLANE6%32));
   LCD->PEN[LCD_FRONTPLANE7/32] |= 1UL<<((uint32_t)(LCD_FRONTPLANE7%32));

   LCD->PEN[LCD_BACKPLANE0/32]  |= 1UL<<((uint32_t)(LCD_BACKPLANE0%32));
   LCD->PEN[LCD_BACKPLANE1/32]  |= 1UL<<((uint32_t)(LCD_BACKPLANE1%32));
   LCD->PEN[LCD_BACKPLANE2/32]  |= 1UL<<((uint32_t)(LCD_BACKPLANE2%32));
   LCD->PEN[LCD_BACKPLANE3/32]  |= 1UL<<((uint32_t)(LCD_BACKPLANE3%32));

   // Configure LCD_SEG_BPENn - Back Plane Enable Register, controls which pins in LCD->PEN are Back Plane (commons)
   // LCD->BPEN[0] contains bits 0-31, while LCD->BPEN[1] contains bits 32-63.  For pins >= 32, set in LCD->BPEN[1] as LCD_BPEN_BPEN(Pin#-32)
   LCD->BPEN[LCD_BACKPLANE0/32] |= 1UL<<((uint32_t)(LCD_BACKPLANE0%32));
   LCD->BPEN[LCD_BACKPLANE1/32] |= 1UL<<((uint32_t)(LCD_BACKPLANE1%32));
   LCD->BPEN[LCD_BACKPLANE2/32] |= 1UL<<((uint32_t)(LCD_BACKPLANE2%32));
   LCD->BPEN[LCD_BACKPLANE3/32] |= 1UL<<((uint32_t)(LCD_BACKPLANE3%32));

   // This applies for both disabled & OFF segments
   memset((uint8_t*)(LCD->WF8B), 0x00, sizeof(LCD->WF8B));

   LCD->WF8B[LCD_BACKPLANE3] = 0x88; // (COM3) is enabled on Phases D and H
   LCD->WF8B[LCD_BACKPLANE2] = 0x44; // (COM2) is enabled on Phases C and G
   LCD->WF8B[LCD_BACKPLANE1] = 0x22; // (COM1) is enabled on Phases B and F
   LCD->WF8B[LCD_BACKPLANE0] = 0x11; // (COM0) is enabled on Phases A and E

   // Disable GCR_PADSAFE and Enable GCR_LCDEN
   LCD->GCR &= ~LCD_GCR_PADSAFE_MASK;                //Clear PADSAFE to unlock LCD pins
   LCD->GCR |= LCD_GCR_LCDEN_MASK;                     //Set LCDEN to enable operation of LCD
}

/**
 * Displays a hex value in a specified position on the LCD.  \n
 * Will not display error if value is outside of range, but display will not be updated.
 *
 * @param value    Value to display (0-F)
 * @param position Digit position (left=1 - 4=right)
 */
void SegLCD_Set(uint8_t value, uint8_t position) {

   typedef struct {
      uint8_t m1;
      uint8_t m2;
   } SegmentData;

   static const SegmentData segmentData[] = {
         /* 0 */ { (LCD_SEG_D | LCD_SEG_E |LCD_SEG_F),                (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C) },
         /* 1 */ { (LCD_CLEAR),                                       (LCD_SEG_B | LCD_SEG_C) },
         /* 2 */ { (LCD_SEG_D | LCD_SEG_E | LCD_SEG_G),               (LCD_SEG_A | LCD_SEG_B) },
         /* 3 */ { (LCD_SEG_D | LCD_SEG_G),                           (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C) },
         /* 4 */ { (LCD_SEG_F | LCD_SEG_G),                           (LCD_SEG_B | LCD_SEG_C) },
         /* 5 */ { (LCD_SEG_D | LCD_SEG_F | LCD_SEG_G),               (LCD_SEG_A | LCD_SEG_C) },
         /* 6 */ { (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G),   (LCD_SEG_A | LCD_SEG_C) },
         /* 7 */ { (LCD_CLEAR),                                       (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C) },
         /* 8 */ { (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G),   (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C) },
         /* 9 */ { (LCD_SEG_F | LCD_SEG_G),                           (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C) },
         /* A */ { (LCD_SEG_E | LCD_SEG_F | LCD_SEG_G),               (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C) },
         /* B */ { (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G),   (LCD_SEG_C) },
         /* C */ { (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F),               (LCD_SEG_A) },
         /* D */ { (LCD_SEG_D | LCD_SEG_E | LCD_SEG_G),               (LCD_SEG_B | LCD_SEG_C) },
         /* E */ { (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G),   (LCD_SEG_A) },
         /* F */ { (LCD_SEG_E | LCD_SEG_F | LCD_SEG_G),               (LCD_SEG_A) },
   };

   if (position > 4){
      // Display "Err" if trying to access a digit that does not exist
      SegLCD_DisplayError(0x01);
   }
   else {
      LCD->WF8B[LCD_Frontplane_Pin[((2*position)-2)]] = segmentData[value].m1;
      LCD->WF8B[LCD_Frontplane_Pin[((2*position)-1)]] = segmentData[value].m2;
   }
}

/**
 * Displays a 4 digit decimal number
 *
 * @param value Value to display (0-9999)
 */
void SegLCD_DisplayDecimal(uint16_t value){

   if (value > 9999) {
      // Display "Err" if value is greater than 4 digits
      SegLCD_DisplayError(0x10);
   }
   else{
      SegLCD_Set(value/1000,     1);
      SegLCD_Set((value/100)%10, 2);
      SegLCD_Set((value/10)%10,  3);
      SegLCD_Set(value%10,       4);
   }
}

/**
 * Displays a 4 Digit hex number
 *
 * @param value Value to display (0x0-0xFFFF)
 */
void SegLCD_DisplayHex(uint16_t Value){

   SegLCD_Set((Value>>12) & 0xF, 1);
   SegLCD_Set((Value>>8)  & 0xF, 2);
   SegLCD_Set((Value>>4)  & 0xF, 3);
   SegLCD_Set( Value      & 0xF, 4);
}


/**
 * Displays two numbers as hour:minute i.e. separated by colon
 *
 * @param hour Hours value to display (0-99)
 * @param minutes Minutes value to display (0-59)
 *
 */
void SegLCD_DisplayTime(uint8_t hour, uint8_t minutes) {
   if ((hour > 99) | (minutes > 99)){
      // Display "Err" if either value is greater than 2 digits
      SegLCD_DisplayError(0x10);
   }
   else{
      SegLCD_Set(hour/10, 1);
      SegLCD_Set(hour % 10, 2);
      SegLCD_Set(minutes/10, 3);
      SegLCD_Set(minutes % 10, 4);
      SegLCD_SetDPs(3, 1);
   }
}

/**
 * Display error number
 *
 * @param ErrorNum Error number value 0-F.\n
 *        If ErrorNum is outside of that range, just displays Err
 */
void SegLCD_DisplayError(uint8_t ErrorNum){

   LCD->WF8B[LCD_FRONTPLANE0] = (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G);
   LCD->WF8B[LCD_FRONTPLANE1] = (LCD_SEG_A);
   LCD->WF8B[LCD_FRONTPLANE2] = (LCD_SEG_E | LCD_SEG_G);
   LCD->WF8B[LCD_FRONTPLANE3] = (LCD_CLEAR);
   LCD->WF8B[LCD_FRONTPLANE4] = (LCD_SEG_E | LCD_SEG_G);
   LCD->WF8B[LCD_FRONTPLANE5] = (LCD_CLEAR);
   if (ErrorNum <= 0xF) {
      // Display ErrorNum in within valid range.
      SegLCD_Set(ErrorNum,4);
   }
   else{
      // If not, leave blank.
      LCD->WF8B[LCD_FRONTPLANE6] = (LCD_CLEAR);
      LCD->WF8B[LCD_FRONTPLANE7] = (LCD_CLEAR);
   }
}
