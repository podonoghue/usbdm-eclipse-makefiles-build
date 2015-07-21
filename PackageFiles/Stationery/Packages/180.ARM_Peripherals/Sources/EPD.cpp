// Copyright 2013 Pervasive Displays, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied.  See the License for the specific language
// governing permissions and limitations under the License.

#include <limits.h>
#include <string.h>
#include "delay.h"
#include "EPD.h"
#include "Seeed_SLD00200P.h"

#define CHANNEL_SELECT_REG      0x01
#define OUTPUT_ENABLE_REG       0x02
#define DRIVER_LATCH_REG        0x03
#define GATE_SOURCE_REG         0x04
#define CHARGE_PUMP_REG         0x05
#define DC_DC_FREQUENCY_REG     0x06
#define HP_OSCILLATOR_REG       0x07
#define ADC_REG                 0x08
#define VCOM_LEVEL_REG          0x09

// Create in-line arrays
#define ARRAY(type, ...) ((type[]){__VA_ARGS__})
#define CU8(...) (ARRAY(const uint8_t, __VA_ARGS__))

static const EPD_Data epd_1_44_data = {
      /* stage_time             */ 480,
      /* dots_per_line;         */ 128,
      /* lines_per_display;     */ 96,
      /* bytes_per_line;        */ 128 / 8,
      /* bytes_per_scan;        */ 96 / 4,
      /* filler;                */ false,
      /* channel_select;        */ {0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00},
      /* gate_source;           */ 0x03,
};

static const EPD_Data epd_2_0_data = {
      /* stage_time             */ 480,
      /* dots_per_line;         */ 200,
      /* lines_per_display;     */ 96,
      /* bytes_per_line;        */ 200 / 8,
      /* bytes_per_scan;        */ 96 / 4,
      /* filler;                */ true,
      /* channel_select;        */ {0x72, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x00},
      /* gate_source;           */ 0x03,
};

static const EPD_Data epd_2_7_data = {
      /* stage_time             */ 630,
      /* dots_per_line;         */ 264,
      /* lines_per_display;     */ 176,
      /* bytes_per_line;        */ 264 / 8,
      /* bytes_per_scan;        */ 176 / 4,
      /* filler;                */ true,
      /* channel_select;        */ {0x72, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00},
      /* gate_source;           */ 0x00,
};

#define SPI_FREQUENCY 12000000

/*!
 *  Constructor
 *
 *  @param spi       SPI interface to use
 *  @param size      The EPD panel size
 */
EPD::EPD(SPI *spi, EPD_size size) : spi(spi), size(size) {
   uint32_t spiFequency = spi->getSpeed();
   if (spiFequency>SPI_FREQUENCY) {
      spi->setSpeed(SPI_FREQUENCY);
   }
   EPD_Pin_EPD_CS.setDigitalOutput();
   EPD_Pin_EPD_CS.set();
   EPD_Pin_PANEL_ON.setDigitalOutput();
   EPD_Pin_BORDER.setDigitalOutput();
   EPD_Pin_DISCHARGE.setDigitalOutput();
   EPD_Pin_PWM.setPwmOutput(5 /* us */, PwmIO::ftm_leftAlign);
   EPD_Pin_RESET.setDigitalOutput();
   EPD_Pin_BUSY.setDigitalInput();

   switch (size) {
   default:
   case EPD_1_44:
      epdData = &epd_1_44_data;
      break;
   case EPD_2_0:
      epdData = &epd_2_0_data;
      break;
   case EPD_2_7:
      epdData = &epd_2_7_data;
      break;
   }
   // Set default factor for 25 Celsius
   setFactor(25);
}

/*!
 * Power-on and Initialise COG driver
 */
void EPD::powerOnAndInitialise() {
   // ===========================================
   // See Application Note Doc. No. 4P008-00
   // 3. Power On COG Driver

   // Everything low & no power
   EPD_Pin_RESET.clear();
   EPD_Pin_PANEL_ON.clear();
   EPD_Pin_DISCHARGE.clear();
   EPD_Pin_BORDER.clear();
   EPD_Pin_EPD_CS.clear();

   // Apply PWM >5ms before powering panel
   EPD_Pin_PWM.setDutyCycle(50);
   waitMS(5);

   // Power to panel
   EPD_Pin_PANEL_ON.set();

   // PWM toggle 5ms
   waitMS(10);

   EPD_Pin_EPD_CS.set();
   EPD_Pin_BORDER.set();
   EPD_Pin_RESET.set();

   // PWM toggle 5ms
   waitMS(5);

   EPD_Pin_RESET.clear();

   // PWM toggle 5ms
   waitMS(5);

   EPD_Pin_RESET.set();

   // PWM toggle 5ms
   waitMS(5);

   // PWM toggle off????

//   uint8_t value = rxReadReg1Byte(0);

   // ===========================================
   // See Application Note Doc. No. 4P008-00
   // 4 Initialize COG Driver

   while (EPD_Pin_BUSY.read()) {
      __asm__("nop");
   }
   // Channel select
   txBytes(2, CU8(0x70, CHANNEL_SELECT_REG));
   txBytes(sizeof(epdData->channel_select), epdData->channel_select);

   // DC/DC frequency settings
   txWriteReg1Byte(DC_DC_FREQUENCY_REG, 0xFF);

   // High power mode oscillator setting
   txWriteReg1Byte(HP_OSCILLATOR_REG, 0x9d);

   // Disable ADC
   txWriteReg1Byte(ADC_REG, 0x00);

   // Set Vcom level
   txBytes(2, CU8(0x70, VCOM_LEVEL_REG));
   txBytes(3, CU8(0x72, 0xd0, 0x00));

   // Gate and source voltage levels
   txWriteReg1Byte(GATE_SOURCE_REG,  epdData->gate_source);

   // PWM toggle 5ms
   waitMS(5);

   // Driver latch on
   txWriteReg1Byte(DRIVER_LATCH_REG, 0x01);

   // Driver latch off
   txWriteReg1Byte(DRIVER_LATCH_REG, 0x00);

   // Start positive charge pump
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x01);

   // PWM toggle 30ms
   waitMS(30);

   // Stop PWM & leave low
   EPD_Pin_PWM.setDutyCycle(0);

   // Charge pump negative voltage on
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x03);

   waitMS(30);

   // Vcom driver on
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x0f);

   waitMS(30);

   // Output enable to disable
   txWriteReg1Byte(OUTPUT_ENABLE_REG,0x24);
}

/*!
 * Power-off COG driver
 */
void EPD::powerOff() {
   // ===========================================
   // See Application Note Doc. No. 4P008-00
   // 6 Power Off COG Driver

   // dummy frame
   //frame_fixed(0x55, EPD_normal);

   // dummy line and border
   if (size == EPD_1_44) {
      // Only for 1.44" EPD
      sendLine(0x7fffu, 0, 0xaa, EPD_normal);
      waitMS(300);
   }
   else {
      // Other display sizes
      sendLine(0x7fffu, 0, 0x55, EPD_normal);
      waitMS(25);
      EPD_Pin_BORDER.clear();
      waitMS(300);
      EPD_Pin_BORDER.set();
   }
   // Latch reset turn on
   txWriteReg1Byte(DRIVER_LATCH_REG, 0x01);

   // Output enable off
   txWriteReg1Byte(OUTPUT_ENABLE_REG, 0x05);

   // Power off Vcom charge pump
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x0e);

   // Power off negative charge pump
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x02);

   // Discharge
   txWriteReg1Byte(GATE_SOURCE_REG, 0x0c);

   waitMS(120);

   // Turn off all charge pumps
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x00);

   // Turn of oscillator
   txWriteReg1Byte(HP_OSCILLATOR_REG, 0x0d);

   // discharge internal - 1
   txWriteReg1Byte(GATE_SOURCE_REG, 0x50);

   waitMS(40);

   // Discharge internal - 2
   txWriteReg1Byte(GATE_SOURCE_REG, 0xA0);

   waitMS(40);

   // Discharge internal - 3
   txWriteReg1Byte(GATE_SOURCE_REG, 0x00);

   // Turn off power and all signals
   EPD_Pin_RESET.clear();
   EPD_Pin_PANEL_ON.clear();
   EPD_Pin_BORDER.clear();

   // Discharge pulse
   EPD_Pin_DISCHARGE.set();
   waitMS(1000);
   EPD_Pin_DISCHARGE.clear();
}

struct Pair {
   int16_t threshold;
   int16_t factor;
};
static const Pair thresholds[] = {
      {-10, 170},
      { -5, 120},
      {  5,  80},
      { 10,  40},
      { 15,  30},
      { 20,  20},
      { 40,  10},
};

/*!
 * Calculates the factored stage time for frame_*_repeat methods
 * from temperature.
 *
 *  @param  temperature Temperature in Celsius
 *
 *  @return Scaled stage time in ms
 *
 */
int EPD::getFactoredStageTime(int temperature) {
   int factor_x10 = 7;
   for (const Pair *pair=thresholds; pair<thresholds+(sizeof(thresholds)/sizeof(thresholds[0])); pair++) {
      if (temperature <= pair->threshold) {
         factor_x10 = pair->factor;
         break;
      }
   }
   return (epdData->stage_time*(int32_t)factor_x10) / 10;
}

/* One frame of data is the number of lines * rows. For example:
 * The 1.44" frame of data is 96 lines * 128 dots.
 * The 2" frame of data is 96 lines * 200 dots.
 * The 2.7" frame of data is 176 lines * 264 dots.
 *
 * The image is arranged by line which matches the display size
 * so smallest would have 96 * 32 bytes
 */
void EPD::frame_fixed(uint8_t fixed_value, EPD_stage stage) {
   for (uint8_t line = 0; line < epdData->lines_per_display ; ++line) {
      sendLine(line, 0, fixed_value, stage);
   }
}

void EPD::frame_data( const uint8_t *image, EPD_stage stage) {
   for (uint8_t line = 0; line < epdData->lines_per_display ; ++line) {
      sendLine(line, &image[line * epdData->bytes_per_line], 0, stage);
   }
}

void EPD::frame_sram(const uint8_t *image, EPD_stage stage) {
   for (uint8_t line = 0; line < epdData->lines_per_display ; ++line) {
      sendLine(line, &image[line * epdData->bytes_per_line], 0, stage);
   }
}

void EPD::frame_cb(uint32_t address, EPD_reader *reader, EPD_stage stage) {
   static uint8_t buffer[264 / 8];
   for (uint8_t line = 0; line < epdData->lines_per_display; ++line) {
      reader(buffer, address + line * epdData->bytes_per_line, epdData->bytes_per_line);
      sendLine(line, buffer, 0, stage);
   }
}

void EPD::frame_fixed_repeat(uint8_t fixed_value, EPD_stage stage) {
   long stage_time = factored_stage_time;
   do {
      unsigned long t_start = getTicks();
      frame_fixed(fixed_value, stage);
      unsigned long t_end = getTicks();
      if (t_end > t_start) {
         stage_time -= t_end - t_start;
      } else {
         stage_time -= t_start - t_end + 1 + ULONG_MAX;
      }
   } while (stage_time > 0);
}

void EPD::frame_data_repeat(const uint8_t *image, EPD_stage stage) {
   long stage_time = factored_stage_time;

#if 1 
   do {
      unsigned long t_start = getTicks();
      frame_data(image, stage);
      unsigned long t_end = getTicks();
      if (t_end > t_start) {
         stage_time -= t_end - t_start;
      } else {
         stage_time -= t_start - t_end + 1 + ULONG_MAX;
      }
   } while (stage_time > 0);
#else
   for(int i=0; i<7; i++) {
      frame_data(image, stage);
   }
#endif
}

void EPD::frame_sram_repeat(const uint8_t *image, EPD_stage stage) {

#if 1 
   long stage_time = factored_stage_time;
   do {
      unsigned long t_start = getTicks();
      frame_sram(image, stage);
      unsigned long t_end = getTicks();
      if (t_end > t_start) {
         stage_time -= t_end - t_start;
      } else {
         stage_time -= t_start - t_end + 1 + ULONG_MAX;
      }
   } while (stage_time > 0);
#else
   for(int i=0; i<7; i++) {
      frame_sram(image, stage);
   }
#endif
}


void EPD::frame_cb_repeat(uint32_t address, EPD_reader *reader, EPD_stage stage) {
   long stage_time = factored_stage_time;
   do {
      unsigned long t_start = getTicks();
      frame_cb(address, reader, stage);
      unsigned long t_end = getTicks();
      if (t_end > t_start) {
         stage_time -= t_end - t_start;
      } else {
         stage_time -= t_start - t_end + 1 + ULONG_MAX;
      }
   } while (stage_time > 0);
}


void EPD::sendLine(uint16_t line, const uint8_t *data, uint8_t fixed_value, EPD_stage stage) {

   // Charge pump voltage levels
   txWriteReg1Byte(GATE_SOURCE_REG, epdData->gate_source);

   // Send data
   txBytes(2, CU8(0x70, 0x0a));

   EPD_Pin_EPD_CS.clear();
   txByteAndWait(0x72);

   // Even pixels
   for (uint16_t b = epdData->bytes_per_line; b > 0; --b) {
      if (data != 0) {
         uint8_t pixels;
         pixels = data[b - 1] & 0xaa;

         switch(stage) {
         case EPD_compensate:  // B -> W, W -> B (Current Image)
            pixels = 0xaa | ((pixels ^ 0xaa) >> 1);
            break;

         case EPD_white:       // B -> N, W -> W (Current Image)
            pixels = 0x55 + ((pixels ^ 0xaa) >> 1);
            break;

         case EPD_inverse:     // B -> N, W -> B (New Image)
            pixels = 0x55 | (pixels ^ 0xaa);
            break;

         case EPD_normal:       // B -> B, W -> W (New Image)
            pixels = 0xaa | (pixels >> 1);
            break;
         }
         txByteAndWait(pixels);
      }
      else {
         txByteAndWait(fixed_value);
      }
   }
   // Scan line
   for (uint16_t b = 0; b < epdData->bytes_per_scan; ++b) {
      if (line / 4 == b) {
         txByteAndWait(0xc0 >> (2 * (line & 0x03)));
      }
      else {
         txByteAndWait(0x00);
      }
   }
   // Odd pixels
   for (uint16_t b = 0; b < epdData->bytes_per_line; ++b) {
      if (0 != data) {
         uint8_t pixels;
         pixels = data[b] & 0x55;

         switch(stage) {
         case EPD_compensate:  // B -> W, W -> B (Current Image)
            pixels = 0xaa | (pixels ^ 0x55);
            break;
         case EPD_white:       // B -> N, W -> W (Current Image)
            pixels = 0x55 + (pixels ^ 0x55);
            break;
         case EPD_inverse:     // B -> N, W -> B (New Image)
            pixels = 0x55 | ((pixels ^ 0x55) << 1);
            break;
         case EPD_normal:       // B -> B, W -> W (New Image)
            pixels = 0xaa | pixels;
            break;
         }
         uint8_t p1 = (pixels >> 6) & 0x03;
         uint8_t p2 = (pixels >> 4) & 0x03;
         uint8_t p3 = (pixels >> 2) & 0x03;
         uint8_t p4 = (pixels >> 0) & 0x03;
         pixels = (p1 << 0) | (p2 << 2) | (p3 << 4) | (p4 << 6);
         txByteAndWait(pixels);
      }
      else {
         txByteAndWait(fixed_value);
      }
   }
   if (epdData->filler) {
      txByteAndWait(0x00);
   }
   EPD_Pin_EPD_CS.set();
   wait10us();

   // Output data to panel
   txWriteReg1Byte(OUTPUT_ENABLE_REG,0x2f);
}

/*!
 *  Send a single byte to EPD and wait for not busy
 *
 *  @param data byte to send
 */
void EPD::txByteAndWait(uint8_t data) {
   spi->txRx(data);

   // Wait for EPD ready
   while(EPD_Pin_BUSY.read()) {
      __asm__("nop");
   }
}

/*!
 *  Write byte to register
 *
 *  @param regNum    Register to write to
 *  @param data      Data byte for register
 */
void EPD::txWriteReg1Byte(const uint8_t regNum, uint8_t data) {
   uint8_t registerAddressCommand[] = {0x70, regNum};
   uint8_t registerDataValue[]      = {0x72, data};

   // Send register address
   txBytes(sizeof(registerAddressCommand), registerAddressCommand);

   // Send register value
   txBytes(sizeof(registerDataValue), registerDataValue);
}

/*!
 *  Write byte to register
 *
 *  @param regNum    Register to write to
 *
 *  @return          Data byte from register
 */
uint8_t EPD::rxReadReg1Byte(const uint8_t regNum) {
   uint8_t registerAddressCommand[] = {0x70, regNum};
   uint8_t registerDataValue[]      = {0x73, 0};

   // Send register address
   txBytes(sizeof(registerAddressCommand), registerAddressCommand);

   // CS low
   EPD_Pin_EPD_CS.clear();

   // Send/Receive data
   spi->txRxBytes(sizeof(registerDataValue), registerDataValue, registerDataValue);

   // CS high
   EPD_Pin_EPD_CS.set();

   // Make sure CS remains high for at least 10us
   wait10us();

   return registerDataValue[2];
}


/*!
 *  Transmit
 *
 *  @param dataSize  Number of bytes to transfer
 *  @param dataOut   Transmit bytes
 */
void EPD::txBytes(uint32_t dataSize, const uint8_t *dataOut) {
   // CS low
   EPD_Pin_EPD_CS.clear();

   // Send data
   spi->txRxBytes(dataSize, dataOut);

   // CS high
   EPD_Pin_EPD_CS.set();

   // Make sure CS remains high for at least 10us
   wait10us();
}
