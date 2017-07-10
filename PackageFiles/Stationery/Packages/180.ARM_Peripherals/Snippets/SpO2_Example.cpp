/** \file main.cpp ******************************************************
 *
 * Project: MAXREFDES117#
 * Filename: main.cpp
 * Description: This module contains the Main application for the MAXREFDES117 example program.
 * ------------------------------------------------------------------------- */
/*******************************************************************************
 * Copyright (C) 2016 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *******************************************************************************
 */
/*!\mainpage Main Page
 *
 * \section intro_sec Introduction
 *
 * This is the code documentation for the MAXREFDES117# subsystem reference design.
 *
 *  The Files page contains the File List page and the Globals page.
 *
 *  The Globals page contains the Functions, Variables, and Macros sub-pages.
 *
 * \image html MAXREFDES117_Block_Diagram.png "MAXREFDES117# System Block Diagram"
 *
 * \image html MAXREFDES117_firmware_Flowchart.png "MAXREFDES117# Firmware Flowchart"
 *
 */
#include <stdio.h>
#include "SpO2algorithm.h"
#include "MAX30102.h"
#include "hardware.h"
#include "uart.h"
#include "console.h"
#include "i2c.h"
#include "ftm.h"
#include "dac.h"

#define MAX_BRIGHTNESS 100

/** Buffer length of 100 stores 5 seconds of samples running at 100sps */
#define SAMPLE_LENGTH  500

uint32_t    ir_buffer[SAMPLE_LENGTH];     // IR LED sensor data
uint32_t    red_buffer[SAMPLE_LENGTH];    // Red LED sensor data
int32_t     sp02;                         // SPO2 value
int8_t      spo2_valid;                   // Indicator to show if the SP02 calculation is valid
int32_t     heart_rate;                   // Heart rate value
int8_t      hr_valid;                     // Indicator to show if the heart rate calculation is valid

using maxIrqSense = USBDM::GpioC<1> ;         // Pin PTC1 connects to the interrupt output pin of the MAX30102
using led         = USBDM::ftm_LED_GREEN;     // PWM Green LED
using dac         = USBDM::Dac0;

USBDM::I2c0 i2c(400000, USBDM::i2cMode_Polled);   // PTB0=SCL, PTB1=SDA

/*
 * The setup routine runs once when you press reset.
 */
int main() { 
   // Turn off unused LEDs
   USBDM::gpio_LED_BLUE::setOutput();
   USBDM::gpio_LED_RED::setOutput();
   USBDM::gpio_LED_BLUE::set();
   USBDM::gpio_LED_RED::set();

   dac::enable();
   maxIrqSense::setInput();
   led::enable();

   // Variables to calculate the on-board LED brightness that reflects the heartbeats
   uint32_t min, max, prev_data;
   int      i;
   int32_t  brightness;
   float    temp;

   maxim_max30102_reset(); // Resets the MAX30102

   // Read and clear status register
   uint8_t     dummy;
   maxim_max30102_read_reg(0,&dummy);
   printf("\x1B[2J");  //clear terminal program screen
   printf("Press enter key to start conversion\n\r");
   getchar();

   maxim_max30102_init();  // Initializes the MAX30102

   brightness = 0;
   min = 0x3FFFF;
   max = 0;

//   for(;;) {
//      uint32_t redLevel, irLevel;
//      uint32_t redAverage, irAverage;
//
//      redAverage = 0;
//      irAverage  = 0;
//      for (int avCount=0; avCount<1; avCount++) {
//         maxim_max30102_read_fifo(&redLevel, &irLevel);  // Read from MAX30102 FIFO
//         redAverage += redLevel;
//         irAverage  += irLevel;
//      }
//      redAverage /= 1;
//      irAverage  /= 1;
//      printf("%ld,%ld,\n\r", redAverage, irAverage);
//   }

   // Read the first 500 samples, and determine the signal range
   for(i=0;i<SAMPLE_LENGTH;i++)
   {
      while(maxIrqSense::read()) {
         // Wait until the interrupt pin asserts
         __asm__("nop");
      };

      maxim_max30102_read_fifo((red_buffer+i), (ir_buffer+i));  // Read from MAX30102 FIFO

      if(min>red_buffer[i]) {
         min = red_buffer[i];    // Update signal min
      }
      if(max<red_buffer[i]) {
         max = red_buffer[i];    // Update signal max
      }
      printf("%3d: red= %ld, ir=%ld\n\r", i, red_buffer[i], ir_buffer[i]);
   }
   prev_data = red_buffer[i];

   // Calculate heart rate and SpO2 after first 500 samples (first 5 seconds of samples)
   maxim_heart_rate_and_oxygen_saturation(ir_buffer, SAMPLE_LENGTH, red_buffer, &sp02, &spo2_valid, &heart_rate, &hr_valid);

   // Continuously taking samples from MAX30102.  Heart rate and SpO2 are calculated every 1 second
   while(1)
   {

      min = 0x3FFFF;
      max = 0;

      // Dumping the first 100 sets of samples in the memory and shift the last 400 sets of samples to the top
      for(i=100;i<500;i++) {
         red_buffer[i-100] = red_buffer[i];
         ir_buffer[i-100]  = ir_buffer[i];

         // Update the signal min and max
         if(min>red_buffer[i]) {
            min = red_buffer[i];
         }
         if(max<red_buffer[i]) {
            max = red_buffer[i];
         }
      }

      // Take 100 sets of samples before calculating the heart rate.
      for(i=400;i<500;i++)  {
         prev_data = red_buffer[i-1];
         while(maxIrqSense::read()) {
            __asm__("nop");
         }
         maxim_max30102_read_fifo((red_buffer+i), (ir_buffer+i));
         dac::setValue(((float)red_buffer[i]*(1<<12))/max);

         if(red_buffer[i]>prev_data) {
            temp = red_buffer[i]-prev_data;
            temp /= (max-min);
            temp *= MAX_BRIGHTNESS;
            brightness-=(int)temp;
            if(brightness<0) {
               brightness = 0;
            }
         }
         else {
            temp = prev_data-red_buffer[i];
            temp /= (max-min);
            temp *= MAX_BRIGHTNESS;
            brightness+=(int)temp;
            if(brightness>MAX_BRIGHTNESS) {
               brightness = MAX_BRIGHTNESS;
            }
         }
         brightness = MAX_BRIGHTNESS-brightness;
         led::setDutyCycle((int)brightness);
         // Send samples and calculation result to terminal
         printf("red=%li, ir=%li, HR=%li, HRvalid=%i, SpO2=%li, SPO2Valid=%i\n\r",
               red_buffer[i], ir_buffer[i], heart_rate, hr_valid, sp02, spo2_valid);
      }
      // Send calculation result to terminal
//      printf("HR=%li, HRvalid=%i, SpO2=%li, SPO2Valid=%i\n\r",
//            heart_rate, hr_valid, sp02, spo2_valid);
      maxim_heart_rate_and_oxygen_saturation(ir_buffer, SAMPLE_LENGTH, red_buffer, &sp02, &spo2_valid, &heart_rate, &hr_valid);
   }
}

