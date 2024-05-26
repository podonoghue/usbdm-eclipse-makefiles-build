/**
 ============================================================================
 * @file    cmt-sirc-example.cpp  (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo using Cmt class to send Sony SIRC protocol
 *
 * It will be necessary to configure the CMT interrupt handling and CMT
 * output pin in the USBDM configuration.
 *
 *  Created on: 1/6/2018
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "cmt.h"

/*
 * Sony SIRC
 *
 * 40kHz carrier, 600us basic unit, bits transmitted LSB first
 *
 * Pulse width encoding of bits:
 *
 *    <---------------- 1200 us ---------------><----- 600 us ------>
 *    +----------------------------------------+                     +--
 *    |xxxxxxxxxxxxxxxxx 40kHz xxxxxxxxxxxxxxxx|                     |   Logic 1
 *  --+----------------------------------------+---------------------+
 *
 *    <----- 600 us ------><----- 600 us ------>
 *    +-------------------+                     +--
 *    |xxxxxx 40kHz xxxxxx|                     |   Logic 0
 *  --+-------------------+---------------------+
 *
 * Packet format: 12/15 or 20 bits.  Packet may be repeated @45ms interval.
 *
 *    <--- 2400 us ---> <- 600 us -> <--- 7 bits ----> <--- 5/8 bits --> <-- 0/8 bits -->
 *    +----------------+            +-----------------+-----------------+---------------+
 *    |xxxx 40kHz xxxxx|            |xxxx Command xxxx|xxxx Address xxxx|xx Extended  xx|
 *  --+----------------+------------+-----------------+-----------------+---------------+--
 *    <---- Training (start) ------> <------------------ Packet ----------------------->
 */
using namespace USBDM;

// Debug LED connection - change as required
//using DebugLed = GpioC<3,ActiveLow>;

// Constant describing transmission
static constexpr unsigned SONY_CARRIER    = 40000;        //!< Sony SIRC carrier frequency (Hz)
static constexpr Ticks SONY_ONE_TIME      =  1200_ticks;  //!< Sony SIRC on time (us) for '1'
static constexpr Ticks SONY_ZERO_TIME     =   600_ticks;  //!< Sony SIRC on time (us) for '0'
static constexpr Ticks SONY_START_TIME    =  2400_ticks;  //!< Sony SIRC on time (us) for start
static constexpr Ticks SONY_OFF_TIME      =   600_ticks;  //!< Sony SIRC off time (us)
static constexpr Ticks SONY_REPEAT_TIME   = 45000_ticks;  //!< Sony SIRC repeat packet time (us)
static constexpr unsigned SONY_REPEATS    =     4;        //!< How many times to repeat packet in transmission

/** Carrier half period in CMT clock cycles (Based on 8MHz CMT clock) */
static constexpr Ticks  PrimaryCarrierHalfTime = Ticks((8000000UL/SONY_CARRIER)/2);

/** Command/address/extended value to transmit */
static volatile uint32_t data;

/** Length of command/address/extended packet */
static volatile unsigned packetLength;

/** Count of bits in packet transmitted so far */
static volatile unsigned bitNum;

/** Count of packet repeats so far */
static volatile unsigned repeatCount;

/**
 * Callback from CMT.
 *
 * This processes each bit for transmission.
 */
static void cmtCallback() {
   /** Command/address/extended value being transmitted */
   static uint32_t shiftReg;

   /** Time since start of current packet */
   static Ticks repeatTime;

//   DebugLed::toggle();
   if (Cmt::getEndOfCycleFlag()) {
      if(bitNum==0) {
         if (repeatCount++ >= SONY_REPEATS) {
            // Completed entire sequence of repeats

            // Clear Interrupt flag
            Cmt::getMarkPeriod();

            // Disable entire CMT
            Cmt::disable();
            return;
         }
         // Start of new packet transmission
         shiftReg   = data;
         repeatTime = 0_ticks;
         Cmt::setExtendedSpace(CmtExtendedSpace_Disabled);
      }
      if (bitNum<packetLength) {
         // LSB first
         if (shiftReg&0b1) {
            Cmt::setMarkPeriod(SONY_ONE_TIME);
            repeatTime = repeatTime + SONY_ONE_TIME+SONY_OFF_TIME;
         }
         else {
            Cmt::setMarkPeriod(SONY_ZERO_TIME);
            repeatTime = repeatTime + SONY_ZERO_TIME+SONY_OFF_TIME;
         }
         bitNum++;
         shiftReg >>= 1;
      }
      else {
         Cmt::setExtendedSpace(CmtExtendedSpace_Enabled);
         Cmt::setMarkPeriod(SONY_REPEAT_TIME-SONY_OFF_TIME-repeatTime);
         bitNum = 0;
      }
   }
//   DebugLed::off();
}

/**
 * Does basic setup of CMT for SIRC protocol
 */
static void configureCmtTime() {
   // Restart counters for ISR callback processing
   repeatCount  = 0;
   bitNum       = 0;

   constexpr Cmt::Init init {
      NvicPriority_Normal,
      cmtCallback,

      CmtMode_Time ,                                     // (cmt_msc_mode)             Mode of operation - Time
      CmtClockPrescaler_Auto ,                           // (cmt_pps_ppsdiv)           Primary Prescaler Divider - Auto ~8MHz
      CmtIntermediatePrescaler_DivBy1 ,                  // (cmt_msc_cmtdiv)           Intermediate frequency Prescaler - Intermediate frequency /4
      CmtOutput_ActiveHigh ,                             // (cmt_oc_output)            Output Control - Disabled
      CmtEndOfCycleAction_Interrupt ,                    // (cmt_dma_irq)              End of Cycle Event handling - Interrupt Request
      CmtPrimaryCarrierHighTime(PrimaryCarrierHalfTime), // (cmt_cgh1_ph)              Primary Carrier High Time Data Value
      CmtPrimaryCarrierLowTime(PrimaryCarrierHalfTime),  // (cmt_cgl1_pl)              Primary Carrier Low Time Data Value
      CmtMarkPeriod(SONY_START_TIME) ,                   // (cmt_mark)                 Mark period
      CmtSpacePeriod(SONY_OFF_TIME),                     // (cmt_space)                Space period
   };
   Cmt::configure(init);
   Cmt::OutputPin::setOutput(PinDriveStrength_High);
}

/**
 * Check if CMT is still busy transmitting sequence
 *
 * @return True if busy
 */
bool isBusy() {
   return (repeatCount <= SONY_REPEATS);
}

/**
 * Wait for CMT to complete transmitting sequence
 */
void waitUntilComplete() {
   while (isBusy()) {
   }
}

enum CmtAddress {
   CmtAddress_tv             = 1,
   CmtAddress_vcr1           = 2,
   CmtAddress_teletext       = 3,
   CmtAddress_Widescreen     = 4,
   CmtAddress_laserDisk      = 6,
   CmtAddress_vcr2           = 7,
   CmtAddress_vcr3           = 11,
   CmtAddress_surroundSound  = 12,
   CmtAddress_cassette       = 16,
   CmtAddress_cdPlayer       = 17,
   CmtAddress_equalizer      = 18,
   CmtAddress_dvd            = 26,
   //   CmtAddress_TV_Digital_Effects_15_bit            = 0xA4   ,
   //   CmtAddress_PlayStation_2_DVD_20_bit             = 0x093A ,
   //   CmtAddress_PlayStation_2_PS2_20_bit             = 0x1B5A ,
};

enum CmtCommand {
   CmtCommand_digit1                       =  0,
   CmtCommand_digit2                       =  1,
   CmtCommand_digit3                       =  2,
   CmtCommand_digit4                       =  3,
   CmtCommand_digit5                       =  4,
   CmtCommand_digit6                       =  5,
   CmtCommand_digit7                       =  6,
   CmtCommand_digit8                       =  7,
   CmtCommand_digit9                       =  8,
   CmtCommand_digit0                       =  9,
   CmtCommand_enter                        = 11,
   CmtCommand_channelUp                    = 16,
   CmtCommand_channelDown                  = 17,
   CmtCommand_volumeUp                     = 18,
   CmtCommand_volumeDown                   = 19,
   CmtCommand_mute                         = 20,
   CmtCommand_power                        = 21,
   CmtCommand_resetTv                      = 22,
   CmtCommand_audioMode                    = 23,
   CmtCommand_contrastUp                   = 24,
   CmtCommand_contrastDown                 = 25,
   CmtCommand_colourUp                     = 26,
   CmtCommand_colourDown                   = 27,
   CmtCommand_brightnessUp                 = 30,
   CmtCommand_brightnessDown               = 31,
   CmtCommand_sharpUp                      = 32,
   CmtCommand_sharpDown                    = 33,
   CmtCommand_selectTvTuner                = 36,
   CmtCommand_cycleAuxillaryExternalModes  = 37,
   CmtCommand_balanceLeft                  = 38,
   CmtCommand_balanceRight                 = 39,
   CmtCommand_surroundOnOff                = 41,
   CmtCommand_auxAnt                       = 42,
   CmtCommand_standby                      = 47,

   CmtCommand_timeDisplay                  = 48,
   CmtCommand_sleepTimer                   = 54,
   CmtCommand_channelDisplay               = 58,
   CmtCommand_channelJump                  = 59,
   CmtCommand_teletextMode                 = 63,
   CmtCommand_selectInputVideo_1           = 64,
   CmtCommand_selectInputVideo_2           = 65,
   CmtCommand_selectInputVideo_3           = 66,
   CmtCommand_noiseReductionOnOff          = 74,
   CmtCommand_cableBroadcast               = 78,
   CmtCommand_notchFilterOnOff             = 79,
   CmtCommand_pipChannelUp                 = 88,
   CmtCommand_pipChannelDown               = 89,
   CmtCommand_pipOn                        = 91,
   CmtCommand_FreezeScreen                 = 92,
   CmtCommand_pipPosition                  = 94,
   CmtCommand_pipSwap                      = 95,
   CmtCommand_guide                        = 96,
   CmtCommand_videoSetup                   = 97,
   CmtCommand_AudioSetup                   = 98,
   CmtCommand_ExitSetup                    = 99,
   CmtCommand_AutoProgram                  = 107,
   CmtCommand_TrebleUp                     = 112,
   CmtCommand_TrebleDown                   = 113,
   CmtCommand_BassUp                       = 114,
   CmtCommand_BassDown                     = 115,
   CmtCommand_PlusKey                      = 116,
   CmtCommand_MinusKey                     = 117,
   CmtCommand_AddChannel                   = 120,
   CmtCommand_DeleteChannel                = 121,
   CmtCommand_TrinitoneOnOff               = 125,
};

/**
 * Start transmission of 12-bit sequence.
 * START + N*(7-bit COMMAND, 5-bit ADDRESS)
 *
 * @param cmtAddress 5-bit address
 * @param cmtCommand 7-bit command
 */
void send12(CmtAddress cmtAddress, CmtCommand cmtCommand) {
   data         = (cmtAddress<<7)|cmtCommand;
   packetLength = 12;
   configureCmtTime();
}

/**
 * Start transmission of 15-bit sequence.
 * START + N*(7-bit COMMAND, 8-bit ADDRESS)
 *
 * @param cmtAddress 8-bit address
 * @param cmtCommand 7-bit command
 */
void send15(CmtAddress cmtAddress, CmtCommand cmtCommand) {
   data         = (cmtAddress<<7)|cmtCommand;
   packetLength = 15;
   configureCmtTime();
}

/**
 * Start transmission of 20-bit sequence.
 * START + N*(7-bit COMMAND, 5-bit ADDRESS, 8-bit EXTENDED)
 *
 * @param cmtAddress  5-bit address
 * @param cmtCommand  7-bit command
 * @param extended8   8-bit extended value
 */
void send20(CmtAddress cmtAddress, CmtCommand cmtCommand, uint8_t extended8) {
   data         = (extended8<<12)|(cmtAddress<<7)|cmtCommand;
   packetLength = 20;
   configureCmtTime();
}

void help() {
   const char *helpMessage = "\n\n"
         "0-9 - Digit\n"
         "V   - Volume Up\n"
         "v   - Volume Down\n"
         "C   - Channel Up\n"
         "c   - Channel Down\n"
         "m   - Mute/unmute\n"
         "s   - Stand-by\n"
         "h   - Help\n\n";
   console.write(helpMessage);
}

int main() {

   // Activity LED connection - indicates command being sent
   using ActivityLed   = GpioA<2,ActiveLow>;

   // Debug LED
//   DebugLed::setOutput(
//         PinDriveStrength_High,
//         PinDriveMode_PushPull,
//         PinSlewRate_Fast);

   console.writeln("Starting\n");
   console.writeln("SystemCoreClock = ", SystemCoreClock);
   console.writeln("SystemBusClock  = ", SystemBusClock);

   ActivityLed::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   console.setEcho(EchoMode_Off);

   bool CommandDone = true;
   for(int count = 0;;count++) {
      console.write("\n0-9,v,c,m,s,h ? ");
      // Assume OK input
      CommandDone = true;

      int ch = console.readChar();

      // Send pattern
      switch(ch) {
         case '0': send12(CmtAddress_tv, CmtCommand_digit0      );      break;
         case '1': send12(CmtAddress_tv, CmtCommand_digit1      );      break;
         case '2': send12(CmtAddress_tv, CmtCommand_digit2      );      break;
         case '3': send12(CmtAddress_tv, CmtCommand_digit3      );      break;
         case '4': send12(CmtAddress_tv, CmtCommand_digit4      );      break;
         case '5': send12(CmtAddress_tv, CmtCommand_digit5      );      break;
         case '6': send12(CmtAddress_tv, CmtCommand_digit6      );      break;
         case '7': send12(CmtAddress_tv, CmtCommand_digit7      );      break;
         case '8': send12(CmtAddress_tv, CmtCommand_digit8      );      break;
         case '9': send12(CmtAddress_tv, CmtCommand_digit9      );      break;
         case 'V': send12(CmtAddress_tv, CmtCommand_volumeUp    );      break;
         case 'v': send12(CmtAddress_tv, CmtCommand_volumeDown  );      break;
         case 'C': send12(CmtAddress_tv, CmtCommand_channelUp   );      break;
         case 'c': send12(CmtAddress_tv, CmtCommand_channelDown );      break;
         case 'M':
         case 'm': send12(CmtAddress_tv, CmtCommand_mute        );      break;
         case 'S':
         case 's': send12(CmtAddress_tv, CmtCommand_standby     );      break;
         case 'h': help(); CommandDone = false;                         break;
         default:
            // Not recognized command
            CommandDone = false;
            break;
      }
      if (CommandDone) {
         // Pulse LED during transmission
         ActivityLed::on();
         console.write((char)ch);
         waitUntilComplete();
         ActivityLed::off();

         // Minimum delay between transmissions
         waitMS(100);
      }
   }
   return 0;
}
