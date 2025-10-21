/**
 * @file    cmt-remote.h  (180.ARM_Peripherals/Snippets)
 * @brief   Example showing use of CMT to implement various IR protocols
 */
#ifndef SOURCES_IRREMOTE_H_
#define SOURCES_IRREMOTE_H_

#include "hardware.h"
#include "cmt.h"

namespace USBDM {

/**
 * Class to wrap CMT hardware for Interval based IR code protocols e.g. NEC, Laser, Samsung etc
 *
 * Interval IR protocol
 *
 * 38kHz carrier, Pulse distance code, bits transmitted LSB first
 *
 * Pulse interval encoding of bits:
 *
 *    <---- startHigh ----> <--- startLow --->  (Ticks)
 *    +--------------------+                   +--
 *    |---  carrier Hz  ---|                   |       Start
 *  --+--------------------+-------------------+--
 *
 *    <----  zeroHigh ----> <---- zeroLow ---->  (Ticks)
 *    +--------------------+                   +--
 *    |---  carrier Hz  ---|                   |        Logic 0
 *  --+--------------------+-------------------+--
 *
 *    <----   oneHigh  ----> <---  oneLow --->  (Ticks)
 *    +--------------------+                   +--
 *    |---  carrier Hz  ---|                   |        Logic 1
 *  --+--------------------+-------------------+--
 *
 *    <----   oneHigh  ----> <--- startLow --->  (Ticks)
 *    +--------------------+                   +--
 *    |---  carrier Hz  ---|                   |        Middle stop (optional)
 *  --+--------------------+-------------------+--
 *
 *    <----  zeroHigh ----> <---- zeroLow ---->  (Ticks)
 *    +--------------------+                   +--
 *    |---  carrier Hz  ---|                   |        Stop
 *  --+--------------------+-------------------+--
 *
 *  Packet format:
 *                   <-- packetLength bits (exl. stop) -->
 *    +------------ +-----//-------+-------+-----//-------+----------+
 *    |    Start    |    DATA      | Stop  |    DATA      |   Stop   |
 *  --+-------------+-----//-------+-------+-----//-------+----------+
 *                                   ^
 *                                   | middleStopBit
 */
class IrRemote {

public:

   struct Parameters {
      Hertz    carrier;

      // Following are in CMT ticks = 1us
      Ticks    startHigh;
      Ticks    startLow;
      Ticks    zeroHigh;
      Ticks    zeroLow;
      Ticks    oneHigh;
      Ticks    oneLow;
      Ticks    repeatTime;

      unsigned packetLength;  //< Number of bits in entire packet
      unsigned middleStopBit; //< Position of middle stop bit (0=none)
      unsigned repeats;       //< Number of repeats (including original)
      bool     fastRepeats;   //< Indicates use of fast repeat where only leader + stop are used on repeats

   };

   enum Protocol {
      p_LASER,
      p_SONY_TV,
      p_SAMSUNG_TV,
      p_SAMSUNG_DVD,
      p_NEC,
      p_TEAC,
   };

   /**
    * Indicate if CMT is still busy sending a transmission
    *
    * @return True if CMT is still transmitting
    */
   static bool isBusy() {
      return Cmt::isEnabled();
   }

   /**
    * Busy-wait for CMT to complete transmitting sequence
    */
   static void waitUntilComplete() {
      while(isBusy()) {
      }
   }

protected:

   enum State {
      s_Initial,
      s_Start,
      s_FirstWord,
      s_MiddleStop,
      s_SecondWord,
      s_Stop,
      s_Trailer,
      s_Complete,
   };

   // Parameters for transmission
   inline static Parameters parameters;

   // Debug LED connection - change as required
   using DebugLed = Digital_D1;

   /** State of transmission */
   inline static volatile State state;

   /** 1st Command/address/extended value to transmit */
   inline static volatile uint32_t data1;

   /** 2nd Command/address/extended value to transmit */
   inline static volatile uint32_t data2;

   /** Indicates use of fast repeat where only leader + stop are used on repeats */
   inline static Protocol protocol;

   IrRemote() = delete;
   IrRemote(const IrRemote &) = delete;

   /**
    * Starts transmission
    */
   static void start() {

      /// Carrier half period in CMT clock cycles (Based on 8MHz CMT clock)
      const Ticks  carrierHalfPeriodInTicks = Ticks(8_MHz/parameters.carrier/2);

      const Cmt::Init cmtInitValue {
         NvicPriority_Normal,
         cmtCallback,

         CmtMode_Time ,                                       // (cmt_msc_mode)   Mode of operation - Time
         CmtClockPrescaler_Auto ,                             // (cmt_pps_ppsdiv) Primary Prescaler Divider - Auto ~8MHz
         CmtIntermediatePrescaler_DivBy1 ,                    // (cmt_msc_cmtdiv) Intermediate frequency Prescaler - Intermediate frequency /4
         CmtOutput_ActiveHigh ,                               // (cmt_oc_output)  Output Control - Disabled
         CmtEndOfCycleAction_Interrupt ,                      // (cmt_dma_irq)    End of Cycle Event handling - Interrupt Request
         CmtPrimaryCarrierHighTime(carrierHalfPeriodInTicks), // (cmt_cgh1_ph)    Primary Carrier High Time Data Value
         CmtPrimaryCarrierLowTime(carrierHalfPeriodInTicks),  // (cmt_cgl1_pl)    Primary Carrier Low Time Data Value
         CmtMarkPeriod(parameters.startHigh) ,                // (cmt_mark)       Mark period
         CmtSpacePeriod(parameters.startLow),                 // (cmt_space)      Space period
      };

      DebugLed::setOutput();

      Cmt::OutputPin::setOutput(PinDriveStrength_High);

      // Restart state machine
      state        = s_Initial;

      // Starts CMT operation (1st interrupt)
      Cmt::configure(cmtInitValue);
   }

   /**
    * Callback from CMT.
    *
    * This processes each timing interval of the transmission.
    */
   static void cmtCallback();

};

/**
 * Class to wrap CMT hardware for Laser-DVD protocol
 *
 * Based on NEC IR protocol
 *
 * 38kHz carrier, Pulse distance code, bits transmitted LSB first
 *
 * Pulse interval encoding of bits:
 *
 *    <--- 9000 us ---> <- 4500 us->
 *    +----------------+            +
 *    |xxxx 38kHz xxxxx|            |                    Start
 *  --+----------------+------------+
 *
 *    <--- 562.5 us ---> <--- 562.5 us --->
 *    +-----------------+                  +
 *    |xxxx  38kHz  xxxx|                  |             Logic 0 = 1:1
 *  --+-----------------+------------------+
 *
 *    <--- 562.5 us ---> <------- 1687.5 us ------->
 *    +-----------------+                           +
 *    |xxxx  38kHz  xxxx|                           |    Logic 1 = 1:3
 *  --+-----------------+---------------------------+
 *
 *    <--- 562.5 us ---> <--- 562.5 us --->
 *    +-----------------+                  +
 *    |xxxx  38kHz  xxxx|                  |             Stop = Logic 0 = 1:1
 *  --+-----------------+------------------+
 *
 *  Packet format: Data = Device:8=FF,Subtype:8=00,Function:8,~Function:8
 *                   <---        32 bits         -->
 *    +------------ +---------------//--------------+----------+
 *    |    Start    |             DATA              |   Stop   |
 *  --+-------------+---------------//--------------+----------+
 */
class  IrLaserDVD : public IrRemote {
private:

   IrLaserDVD() = delete;
   IrLaserDVD(const IrLaserDVD &) = delete;

   /// Constant describing transmission
   static constexpr Parameters myParameters = {
         /* carrier       */    38_kHz,

         // Following are in CMT ticks = 1us
         /* startHigh     */    9000_ticks,
         /* startLow      */    4500_ticks,
         /* zeroHigh      */    563_ticks,
         /* zeroLow       */    563_ticks,
         /* oneHigh       */    563_ticks,
         /* oneLow        */    1687_ticks,
         /* repeatTime    */    108000_ticks,

         /* packetLength  */    32,
         /* middleStopBit */    0,
         /* repeats       */    1,
         /* fastRepeats   */    true,
   };

public:
   /**
    * Common codes
    */
   enum Code : uint32_t {
      A_B                 =    0xAA55FF00,
      ANGLE               =    0xF00FFF00,
      AUDIO               =    0xBC43FF00,
      CHANNEL             =    0xE718FF00,
      CLEAR               =    0xAB54FF00,
      COPY_DELETE         =    0xEA15FF00,
      DOWN                =    0xB748FF00,
      DVD_USB             =    0xF807FF00,
      EJECT               =    0xFF00FF00,
      FORWARD             =    0xEF10FF00,
      FORWARD_SCENE       =    0xE31CFF00,
      LEFT                =    0xB34CFF00,
      MARK                =    0xEC13FF00,
      MENU                =    0xF40BFF00,
      MUTE                =    0xA35CFF00,
      NUM0                =    0xB24DFF00,
      NUM1                =    0xF20DFF00,
      NUM2                =    0xF609FF00,
      NUM3                =    0xFA05FF00,
      NUM4                =    0xB04FFF00,
      NUM5                =    0xB44BFF00,
      NUM6                =    0xB847FF00,
      NUM7                =    0xB14EFF00,
      NUM8                =    0xB54AFF00,
      NUM9                =    0xB946FF00,
      OK                  =    0xF906FF00,
      ON_OFF              =    0xF30CFF00,
      OSD                 =    0xA25DFF00,
      PAUSE               =    0xEB14FF00,
      PAUSE_PLAY          =    0xE817FF00,
      PBC                 =    0xE619FF00,
      PLAY                =    0xA05FFF00,
      PROG                =    0xBD42FF00,
      Q_PLAY              =    0xE916FF00,
      REPEAT              =    0xAE51FF00,
      RETURN              =    0xEE11FF00,
      REVERSE             =    0xA857FF00,
      REVERSE_SCENE       =    0xA45BFF00,
      RIGHT               =    0xBF40FF00,
      SEARCH              =    0xBA45FF00,
      SETUP               =    0xFC03FF00,
      SLOW                =    0xA758FF00,
      STEP                =    0xED12FF00,
      STOP                =    0xF50AFF00,
      SUBTITLE            =    0xFE01FF00,
      TITLE               =    0xAF50FF00,
      UP                  =    0xBB44FF00,
      VIDEO               =    0xA659FF00,
      VOLUME_DOWN         =    0xF708FF00,
      VOLUME_UP           =    0xFB04FF00,
      ZOOM                =    0xBE41FF00,
   };

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeats    Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, unsigned repeats=0) {

      data1        = code;
      data2        = 0;
      protocol     = p_NEC;

      parameters   = myParameters;
      if (repeats != 0) {
         parameters.repeats = repeats;
      }

      IrRemote::start();
   }

};

/**
 * Class to wrap CMT hardware for Teac-DVD protocol
 *
 * Based on NEC IR protocol
 *
 * 38kHz carrier, Pulse distance code, bits transmitted LSB first
 *
 * Pulse interval encoding of bits:
 *
 *    <--- 9000 us ---> <- 4500 us->
 *    +----------------+            +
 *    |xxxx 38kHz xxxxx|            |                    Start
 *  --+----------------+------------+
 *
 *    <--- 562.5 us ---> <--- 562.5 us --->
 *    +-----------------+                  +
 *    |xxxx  38kHz  xxxx|                  |             Logic 0
 *  --+-----------------+------------------+
 *
 *    <--- 562.5 us ---> <------- 1687.5 us ------->
 *    +-----------------+                           +
 *    |xxxx  38kHz  xxxx|                           |    Logic 1
 *  --+-----------------+---------------------------+
 *
 *    <--- 562.5 us ---> <--- 562.5 us --->
 *    +-----------------+                  +
 *    |xxxx  38kHz  xxxx|                  |             Stop = Logic 0
 *  --+-----------------+------------------+
 *
 *  Packet format: Data = Device:8=BF,Subtype:8=00,Function:8,~Function:8
 *                   <---        32 bits         -->
 *    +------------ +---------------//--------------+----------+
 *    |    Start    |             DATA              |   Stop   |
 *  --+-------------+---------------//--------------+----------+
 */
class  IrTeacPVR : public IrRemote {
private:

   IrTeacPVR() = delete;
   IrTeacPVR(const IrTeacPVR &) = delete;

   /// Constant describing transmission
   static constexpr Parameters myParameters = {
         /* carrier       */    38_kHz,

         // Following are in CMT ticks = 1us
         /* startHigh     */    9000_ticks,
         /* startLow      */    4500_ticks,
         /* zeroHigh      */    563_ticks,
         /* zeroLow       */    563_ticks,
         /* oneHigh       */    563_ticks,
         /* oneLow        */    1687_ticks,
         /* repeatTime    */    108000_ticks,

         /* packetLength  */    32,
         /* middleStopBit */    0,
         /* repeats       */    3,
         /* fastRepeats   */    true,
   };

public:
   /**
    * Common codes
    */
   enum Code : uint32_t {
      AUDIO               =    0xAE51BF00,
      BLUE                =    0xFC03BF00,
      DOWN                =    0xE916BF00,
      EPG                 =    0xB24DBF00,
      EXIT                =    0xFA05BF00,
      FAV                 =    0xAA55BF00,
      FORWARD             =    0xB748BF00,
      FORWARD_SCENE       =    0xF40BBF00,
      GOTO                =    0xE817BF00,
      GREEN               =    0xBF40BF00,
      INFO                =    0xF10EBF00,
      LEFT                =    0xA55ABF00,
      LIST                =    0xE718BF00,
      MENU                =    0xBA45BF00,
      MUTE                =    0xE619BF00,
      NUM0                =    0xF00FBF00,
      NUM1                =    0xAD52BF00,
      NUM2                =    0xAF50BF00,
      NUM3                =    0xEF10BF00,
      NUM4                =    0xA956BF00,
      NUM5                =    0xAB54BF00,
      NUM6                =    0xEB14BF00,
      NUM7                =    0xB14EBF00,
      NUM8                =    0xB34CBF00,
      NUM9                =    0xF30CBF00,
      OK                  =    0xE51ABF00,
      ON_OFF              =    0xA659BF00,
      PAUSE               =    0xBB44BF00,
      PLAY                =    0xB946BF00,
      REC                 =    0xA758BF00,
      RECALL              =    0xEC13BF00,
      RED                 =    0xBD42BF00,
      REPEAT              =    0xF807BF00,
      REVERSE             =    0xB54ABF00,
      REVERSE_SCENE       =    0xF708BF00,
      RIGHT               =    0xE41BBF00,
      STOP                =    0xFB04BF00,
      SUBTITLE            =    0xEE11BF00,
      TTX                 =    0xF20DBF00,
      TV_RADIO            =    0xEA15BF00,
      UP                  =    0xF906BF00,
      YELLOW              =    0xFF00BF00,
};

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeats    Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, unsigned repeats=0) {

      data1        = code;
      data2        = 0;
      protocol     = p_TEAC;

      parameters   = myParameters;
      if (repeats != 0) {
         parameters.repeats = repeats;
      }

      IrRemote::start();
   }

};

/**
 * Class to wrap CMT hardware for Laser-DVD protocol
 *
 * Based on NEC IR protocol
 *
 * 38kHz carrier, Pulse distance code, bits transmitted LSB first
 *
 * Pulse interval encoding of bits:
 *
 *    <--- 9000 us ---> <- 4500 us->
 *    +----------------+            +
 *    |xxxx 38kHz xxxxx|            |                    Start
 *  --+----------------+------------+
 *
 *    <--- 562.5 us ---> <--- 562.5 us --->
 *    +-----------------+                  +
 *    |xxxx  38kHz  xxxx|                  |             Logic 0
 *  --+-----------------+------------------+
 *
 *    <--- 562.5 us ---> <------- 1687.5 us ------->
 *    +-----------------+                           +
 *    |xxxx  38kHz  xxxx|                           |    Logic 1
 *  --+-----------------+---------------------------+
 *
 *    <--- 562.5 us ---> <--- 562.5 us --->
 *    +-----------------+                  +
 *    |xxxx  38kHz  xxxx|                  |             Stop = Logic 0
 *  --+-----------------+------------------+
 *
 *  Packet format: Data = Device:8=FF,Subtype:8=00,Function:8,~Function:8
 *                   <---        32 bits         -->
 *    +------------ +---------------//--------------+----------+
 *    |    Start    |             DATA              |   Stop   |
 *  --+-------------+---------------//--------------+----------+
 */
class  IrTeacDVD : public IrRemote {
private:

   IrTeacDVD() = delete;
   IrTeacDVD(const IrTeacDVD &) = delete;

   /// Constant describing transmission
   static constexpr Parameters myParameters = {
         /* carrier       */    38_kHz,

         // Following are in CMT ticks = 1us
         /* startHigh     */    9000_ticks,
         /* startLow      */    4500_ticks,
         /* zeroHigh      */    563_ticks,
         /* zeroLow       */    563_ticks,
         /* oneHigh       */    563_ticks,
         /* oneLow        */    1687_ticks,
         /* repeatTime    */    108000_ticks,

         /* packetLength  */    32,
         /* middleStopBit */    0,
         /* repeats       */    3,
         /* fastRepeats   */    true,
   };

public:
   /**
    * Common codes
    */
   enum Code : uint32_t {
      A_B                 =    0xA15EFF00,
      ANGLE               =    0xA758FF00,
      CLEAR               =    0xA35CFF00,
      DOWN                =    0xAA55FF00,
      DVD_USB             =    0xA45BFF00,
      EJECT               =    0xF708FF00,
      ENTER               =    0xAD52FF00,
      FORWARD             =    0xB748FF00,
      FORWARD_SCENE       =    0xB54AFF00,
      L_R                 =    0xA25DFF00,
      LANGUAGE            =    0xA659FF00,
      LEFT                =    0xAE51FF00,
      MENU                =    0xAB54FF00,
      MUTE                =    0xFA05FF00,
      N_P                 =    0xA25DFF00,
      NUM_10_PLUS         =    0xBB44FF00,
      NUM0                =    0xB946FF00,
      NUM1                =    0xF906FF00,
      NUM2                =    0xF807FF00,
      NUM3                =    0xF609FF00,
      NUM4                =    0xF50AFF00,
      NUM5                =    0xF40BFF00,
      NUM6                =    0xBF40FF00,
      NUM7                =    0xBE41FF00,
      NUM8                =    0xBD42FF00,
      NUM9                =    0xBC43FF00,
      ON_OFF              =    0xFB04FF00,
      OSD                 =    0xFE01FF00,
      PAUSE               =    0xB34CFF00,
      PBC                 =    0xA956FF00,
      PLAY                =    0xB44BFF00,
      PROG                =    0xA45BFF00,
      RANDOM              =    0xEC13FF00,
      REPEAT              =    0xA15EFF00,
      RESET               =    0xEE11FF00,
      RETURN              =    0xA55AFF00,
      REVERSE             =    0xB847FF00,
      REVERSE_SCENE       =    0xB649FF00,
      RIGHT               =    0xAC53FF00,
      RIPPING             =    0xEF10FF00,
      SETUP               =    0xB14EFF00,
      SLOW                =    0xA35CFF00,
      STOP                =    0xB24DFF00,
      SUBTITLE            =    0xA857FF00,
      TIME                =    0xFF00FF00,
      TITLE               =    0xAF50FF00,
      UP                  =    0xB04FFF00,
      VIDEO               =    0xBA45FF00,
      VOLUME_DOWN         =    0xFC03FF00,
      VOLUME_UP           =    0xFD02FF00,
      ZOOM                =    0xED12FF00,
   };

   /**
    * Start transmission of sequence.
    *
    * @param code       Command to send
    * @param repeats    Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, unsigned repeats=0) {

      data1        = code;
      data2        = 0;
      protocol     = p_TEAC;

      parameters   = myParameters;
      if (repeats != 0) {
         parameters.repeats = repeats;
      }

      IrRemote::start();
   }

};

/**
 * Class to wrap CMT hardware for Samsung DVD protocol
 *
 * Samsung DVD protocol   IRP notation: {38k,500}<1,-1|1,-3>(9,-9,D:8,S:8,1,-9,E:4,F:8,-68u,~F:8,1,-118)+
 *
 * 38kHz carrier, Pulse distance code, bits transmitted LSB first
 *
 * Pulse interval encoding of bits:
 *
 *    <----- 4500 us -----> <----- 4500 us ----->
 *    +-------------------+                      +
 *    |xxxxxx 38kHz xxxxxx|                      |          Start = 9:-9
 *  --+-------------------+----------------------+
 *
 *    <---- 500 us ----> <---- 500 us ---->
 *    +-----------------+                  +
 *    |xxxx  38kHz  xxxx|                  |                Logic 0 = 1:-1
 *  --+-----------------+------------------+
 *
 *    <---- 500 us ----> <-------- 1500 us ---------->
 *    +-----------------+                            +
 *    |xxxx  38kHz  xxxx|                            |      Logic 1 = 1:-3
 *  --+-----------------+-------------//-------------+
 *
 *    <----- 500 us ---> <------ 4500 us ------>
 *    +-----------------+                      +
 *    |xxxx  38kHz  xxxx|                      |            Middle Stop = 1:-9
 *  --+-----------------+----------//----------+
 *
 *    <---- 500 us ----> <---- 500 us ---->
 *    +-----------------+                  +
 *    |xxxx  38kHz  xxxx|                  |                Stop = 1:-1
 *  --+-----------------+------------------+
 *
 *  Packet format:
 *
 *                         <-- 16 bits -->                <-- 20 bits -->
 *    +-------------------+------//-------+--------------+------//-------+------+
 *    |        Start      |     Device    | Middle. Stop |    Command    | Stop |
 *  --+-------------------+-----//--------+--------------+------//-------+------+
 */
class  IrSamsungDVD : public IrRemote {
private:

   /// Constant describing transmission
   static constexpr Parameters myParameters = {
         /* carrier       */    38_kHz,

         // Following are in CMT ticks = 1us
         /* startHigh     */    4500_ticks,
         /* startLow      */    4500_ticks,
         /* zeroHigh      */    563_ticks,
         /* zeroLow       */    563_ticks,
         /* oneHigh       */    563_ticks,
         /* oneLow        */    1687_ticks,
         /* repeatTime    */    108000_ticks,

         /* packetLength  */    16+20, // 16-data + 20 data
         /* middleStopBit */    0,
         /* repeats       */    1,
         /* fastRepeats   */    false,
   };

public:
   enum Device : uint32_t {
      DVD = 0x0020,
   };

   /**
    * Common codes
    */
   enum Code : uint32_t {
      A_B                 =    0xD72A7,
      ANGLE               =    0xCC337,
      AUDIO               =    0xDA277,
      BLUE                =    0xDB267,
      DISC_MENU           =    0xE21F7,
      DOWN                =    0xE61B7,
      EJECT               =    0xFE037,
      EXIT                =    0xD42B7,
      FORWARD             =    0xED127,
      FORWARD_SCENE       =    0xEE137,
      GREEN               =    0xDD227,
      HOME                =    0xE9167,
      INFO                =    0xE11E7,
      LEFT                =    0xE41B7,
      NUM0                =    0xF40B7,
      NUM1                =    0xFD027,
      NUM2                =    0xFC037,
      NUM3                =    0xFB067,
      NUM4                =    0xFA077,
      NUM5                =    0xF9067,
      NUM6                =    0xF8077,
      NUM7                =    0xF70A7,
      NUM8                =    0xF60B7,
      NUM9                =    0xF50A7,
      OK                  =    0xE31E7,
      ON_OFF              =    0xFF027,
      PAUSE               =    0xCD327,
      PLAY                =    0xEB167,
      RED                 =    0xDE237,
      REPEAT              =    0xD8277,
      RETURN              =    0xE8177,
      REVERSE             =    0xEA177,
      REVERSE_SCENE       =    0xF20F7,
      RIGHT               =    0xE51A7,
      SCREEN              =    0xC63B7,
      STOP                =    0xEC137,
      SUBTITLE            =    0xD9267,
      TITLE_MENU          =    0xDF227,
      TOOLS               =    0xC53A7,
      UP                  =    0xE71A7,
      YELLOW              =    0xDC237,
   };

   IrSamsungDVD() = delete;
   IrSamsungDVD(const IrSamsungDVD &) = delete;

   //   IrLaserDVD() : IrRemote(cmtInitValue) {
   //   }

   /**
    * Start transmission of sequence.
    *
    * @param code          Command to send
    * @param device        Device
    * @param repeats       Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code code, Device device=DVD, unsigned repeats=0) {

      data1        = device;
      data2        = code;
      protocol     = p_SAMSUNG_DVD;

      parameters   = myParameters;
      if (repeats != 0) {
         parameters.repeats = repeats;
      }
      IrRemote::start();
   }

};

constexpr uint32_t SONY_LENGTH_MASK = 0xC000'0000;
constexpr uint32_t SONY_LENGTH_12   = 0x0000'0000;
constexpr uint32_t SONY_LENGTH_15   = 0x8000'0000;
constexpr uint32_t SONY_LENGTH_20   = 0x4000'0000;

static constexpr uint32_t makeSonyCode(uint32_t length, uint32_t code, uint32_t address) {
   if (length == 12) {
      return code|(address<<7)|SONY_LENGTH_12;
   }
   if (length == 15) {
      return code|(address<<7)|SONY_LENGTH_15;
   }
   if (length == 20) {
      return code|(address<<7)|SONY_LENGTH_20;
   }
   return -1U;
}

class  IrSonyTV : public IrRemote {
private:

   IrSonyTV() = delete;
   IrSonyTV(const IrSonyTV &) = delete;

   /// Constant describing transmission
   static constexpr Parameters myParameters = {
         /* carrier       */    40_kHz,

         // Following are in CMT ticks = 1us
         /* startHigh     */    2400_ticks,
         /* startLow      */    600_ticks,
         /* zeroHigh      */    600_ticks,
         /* zeroLow       */    600_ticks,
         /* oneHigh       */    1200_ticks,
         /* oneLow        */    600_ticks,
         /* repeatTime    */    108000_ticks,

         /* packetLength  */    0,     // Variable
         /* middleStopBit */    0,     // Not used
         /* fastRepeats   */    false, // Not used
         /* repeats       */    1,
   };

   /// Carrier half period in CMT clock cycles (Based on 8MHz CMT clock)
   static constexpr Ticks  PRIMARY_CARRIER_HALF_TIME = Ticks(8_MHz/myParameters.carrier/2);

   static constexpr Cmt::Init cmtInitValue {
      NvicPriority_Normal,
      cmtCallback,

      CmtMode_Time ,                                        // (cmt_msc_mode)   Mode of operation - Time
      CmtClockPrescaler_Auto ,                              // (cmt_pps_ppsdiv) Primary Prescaler Divider - Auto ~8MHz
      CmtIntermediatePrescaler_DivBy1 ,                     // (cmt_msc_cmtdiv) Intermediate frequency Prescaler - Intermediate frequency /4
      CmtOutput_ActiveHigh ,                                // (cmt_oc_output)  Output Control - Disabled
      CmtEndOfCycleAction_Interrupt ,                       // (cmt_dma_irq)    End of Cycle Event handling - Interrupt Request
      CmtPrimaryCarrierHighTime(PRIMARY_CARRIER_HALF_TIME), // (cmt_cgh1_ph)    Primary Carrier High Time Data Value
      CmtPrimaryCarrierLowTime(PRIMARY_CARRIER_HALF_TIME),  // (cmt_cgl1_pl)    Primary Carrier Low Time Data Value
      CmtMarkPeriod(myParameters.startHigh) ,            // (cmt_mark)       Mark period
      CmtSpacePeriod(myParameters.startLow),             // (cmt_space)      Space period
   };

public:
   /**
    * Common codes
    */
   enum Code : uint32_t {
      //                                  Length Code  Address
      APPS                 = makeSonyCode(15,    0x7D, 0x1A),
      AUDIO                = makeSonyCode(12,    0x17, 0x01),
      BLUE                 = makeSonyCode(15,    0x24, 0x97),
      CHANNEL_DOWN         = makeSonyCode(12,    0x11, 0x01),
      CHANNEL_UP           = makeSonyCode(12,    0x10, 0x01),
      DIGITAL_ANALOG       = makeSonyCode(15,    0x0D, 0x77),
      DISCOVER             = makeSonyCode(15,    0x73, 0x1A),
      DOWN                 = makeSonyCode(12,    0x75, 0x01),
      FOOTBALL             = makeSonyCode(15,    0x76, 0x1A),
      FORWARD              = makeSonyCode(15,    0x1C, 0x97),
      GREEN                = makeSonyCode(15,    0x26, 0x97),
      GUIDE                = makeSonyCode(15,    0x5B, 0xA4),
      HELP                 = makeSonyCode(15,    0x7B, 0x1A),
      HOME                 = makeSonyCode(12,    0x60, 0x01),
      I_PLUS               = makeSonyCode(12,    0x3A, 0x01),
      LEFT                 = makeSonyCode(12,    0x34, 0x01),
      MUTE                 = makeSonyCode(12,    0x14, 0x01),
      NUM0                 = makeSonyCode(12,    0x09, 0x01),
      NUM1                 = makeSonyCode(12,    0x00, 0x01),
      NUM2                 = makeSonyCode(12,    0x01, 0x01),
      NUM3                 = makeSonyCode(12,    0x02, 0x01),
      NUM4                 = makeSonyCode(12,    0x03, 0x01),
      NUM5                 = makeSonyCode(12,    0x04, 0x01),
      NUM6                 = makeSonyCode(12,    0x05, 0x01),
      NUM7                 = makeSonyCode(12,    0x06, 0x01),
      NUM8                 = makeSonyCode(12,    0x07, 0x01),
      NUM9                 = makeSonyCode(12,    0x08, 0x01),
      OK                   = makeSonyCode(12,    0x65, 0x01),
      ON_OFF               = makeSonyCode(12,    0x15, 0x01),
      STANDBY              = makeSonyCode(12,    0x2F, 0x01), // maybe?
      OPTIONS              = makeSonyCode(15,    0x36, 0x97),
      PAUSE                = makeSonyCode(15,    0x19, 0x97),
      PLAY                 = makeSonyCode(15,    0x1A, 0x97),
      REC                  = makeSonyCode(15,    0x20, 0x97),
      RED                  = makeSonyCode(15,    0x25, 0x97),
      RELATED_SEARCH       = makeSonyCode(15,    0x7E, 0x1A),
      RETURN               = makeSonyCode(15,    0x23, 0x97),
      REVERSE              = makeSonyCode(15,    0x1B, 0x97),
      RIGHT                = makeSonyCode(12,    0x33, 0x01),
      SOCIAL_VIEW          = makeSonyCode(15,    0x74, 0x1A),
      SOURCE               = makeSonyCode(12,    0x25, 0x01),
      SOURCE_1             = makeSonyCode(12,    0x40, 0x01), // maybe?
      SOURCE_2             = makeSonyCode(12,    0x41, 0x01), // maybe?
      SOURCE_3             = makeSonyCode(12,    0x42, 0x01), // maybe?
      SOURCE_RGB1          = makeSonyCode(12,    0x43, 0x01), // maybe?
      SOURCE_RGB2          = makeSonyCode(12,    0x44, 0x01), // maybe?
      SOURCE_4             = makeSonyCode(12,    0x47, 0x01), // maybe?
      SOURCE_5             = makeSonyCode(12,    0x48, 0x01), // maybe?
      SOURCE_6             = makeSonyCode(12,    0x49, 0x01), // maybe?
      STOP                 = makeSonyCode(15,    0x18, 0x97),
      SWAP                 = makeSonyCode(12,    0x3B, 0x01),
      SYNC_MENU            = makeSonyCode(15,    0x58, 0x1A),
      TITLES               = makeSonyCode(15,    0x65, 0x1A),
      TV_PAUSE             = makeSonyCode(15,    0x67, 0x1A),
      UNKNOWN              = makeSonyCode(15,    0x28, 0x97),
      UP                   = makeSonyCode(12,    0x74, 0x01),
      VOLUME_DOWN          = makeSonyCode(12,    0x13, 0x01),
      VOLUME_UP            = makeSonyCode(12,    0x12, 0x01),
      YELLOW               = makeSonyCode(15,    0x27, 0x97),
   };

   enum Address {
      tv             = 1,
      vcr1           = 2,
      teletext       = 3,
      widescreen     = 4,
      laserDisk      = 6,
      vcr2           = 7,
      vcr3           = 11,
      surroundSound  = 12,
      cassette       = 16,
      cdPlayer       = 17,
      equalizer      = 18,
      dvd            = 26,
      //   TV_Digital_Effects_15_bit            = 0xA4   ,
      //   PlayStation_2_DVD_20_bit             = 0x093A ,
      //   PlayStation_2_PS2_20_bit             = 0x1B5A ,
   };

   /**
    *
    * @param cmtCommand Command (command+address+length)
    * @param repeats    Number of times to repeat (including original). 0 => use default for protocol
    */
   static void send(Code cmtCommand, unsigned repeats=0) {
      unsigned length = 0;

      data1        = cmtCommand&~SONY_LENGTH_MASK;
      data2        = 0;
      protocol     = p_SONY_TV;

      parameters = myParameters;
      if (repeats != 0) {
         parameters.repeats = repeats;
      }
      switch (cmtCommand&SONY_LENGTH_MASK) {
         case SONY_LENGTH_12: length = 12; break; // START + 7-bit COMMAND, 5-bit ADDRESS
         case SONY_LENGTH_15: length = 15; break; // START + 7-bit COMMAND, 8-bit ADDRESS
         case SONY_LENGTH_20: length = 20; break; // START + 7-bit COMMAND, 5-bit ADDRESS, 8-bit EXTENDED
      }
      parameters.packetLength = length;

      IrRemote::start();
   }

};
} // End namespace USBDM

#endif /* SOURCES_IRREMOTE_H_ */
