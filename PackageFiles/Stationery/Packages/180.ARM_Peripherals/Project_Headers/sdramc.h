/**
 * @file     sdramc.h (180.ARM_Peripherals/Project_Headers/sdramc.h)
 * @brief    Flexible I/O
 *
 * @version  V4.12.1.240
 * @date     14 November 2021
 */

#ifndef HEADER_SDRAMC_H
#define HEADER_SDRAMC_H
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "derivative.h"
#include "pin_mapping.h"

namespace USBDM {

/**
 * @addtogroup SDRAMC_Group SDRAMC, Synchronous DRAM Controller
 * @brief Abstraction for Synchronous DRAM Controller
 * @{
 */

/**
 * Indices for SDRAMC memory blocks
 */
enum SdramcBlock {
   SdramcBlock0 = 0,/**< SdramcBlock0 */
   SdramcBlock1 = 1,/**< SdramcBlock1 */
#if SDRAMC_MEMORY_REGIONS_COUNT > 2
   SdramcBlock2 = 2,/**< SdramcBlock2 */
   SdramcBlock3 = 3,/**< SdramcBlock3 */
#endif
   };

/**
 * CAS Latency control.
 *
 * Affects the following SDRAM timing specifications.
 * Timing nomenclature varies with manufacturers.
 *
 * Refer to the SDRAM specification for the appropriate timing nomenclature:
 *
 *     |                                                  |   Number of Bus Clocks    |
 *     | Parameter                          SdramcCasl => |   1  |   2  |   3  |   -  |
 *     |--------------------------------------------------|------|------|------|------|
 *     | trcd      - SRAS assertion to SCAS assertion     |   1  |   2  |   3  |   3  |
 *     | tcasl     - SCAS assertion to data out           |   1  |   2  |   3  |   3  |
 *     | tras      - actv command to precharge command    |   2  |   4  |   6  |   6  |
 *     | trp       - Precharge command to actv command    |   1  |   2  |   3  |   3  |
 *     | trwl,trdl - Last data input to precharge command |   1  |   1  |   1  |   1  |
 *     | tep       - Last data out to precharge command   |   1  |   1  |   1  |   1  |
 *     |--------------------------------------------------|------|------|------|------|
 */
enum SdramcCasl : uint16_t {
   SdramcCasl_1 = SDRAMC_AC_CASL(0b00), /**< CAS Latency 1 */
   SdramcCasl_2 = SDRAMC_AC_CASL(0b01), /**< CAS Latency 2 */
   SdramcCasl_3 = SDRAMC_AC_CASL(0b10), /**< CAS Latency 3 */
//   SdramcCasl_? = SDRAMC_AC_CASL(0b11),
};

/**
 * Command bit location.
 *
 * Because different SDRAM configurations cause the command lines on the memory
 * to correspond to a different address, the location of command bit is programmable.
 * CB determines the address onto which the command bit are multiplexed.
 */
enum SdramcCommandBitLocation : uint16_t {
   SdramcCommandBitLocation_A17 = SDRAMC_AC_CBM(0b000), /**< Not possible for 8-bit port */
   SdramcCommandBitLocation_A18 = SDRAMC_AC_CBM(0b001),
   SdramcCommandBitLocation_A19 = SDRAMC_AC_CBM(0b010),
   SdramcCommandBitLocation_A20 = SDRAMC_AC_CBM(0b011),
   SdramcCommandBitLocation_A21 = SDRAMC_AC_CBM(0b100),
   SdramcCommandBitLocation_A22 = SDRAMC_AC_CBM(0b101),
   SdramcCommandBitLocation_A23 = SDRAMC_AC_CBM(0b110),
//      SdramcCommandBitLocation_24 = SDRAMC_AC_CBM(0b111), /**< Not supported */
};

/**
 *  Port size.
 *
 *  Indicates the port size of the associated block of SDRAM, which allows
 *  for dynamic sizing of associated SDRAM accesses.
 *  PS functions the same in asynchronous operation.
 */
enum SdramcPortSize : uint8_t {
   SdramcPortSize_32 = SDRAMC_AC_PS(0b00), /**< 32-bit port */
   SdramcPortSize_8  = SDRAMC_AC_PS(0b01), /**< 8-bit port */
   SdramcPortSize_16 = SDRAMC_AC_PS(0b10), /**< 16-bit port */
//      SdramcPortSize_16 = SDRAMC_AC_PS(0b11), /**< 16-bit port */
};

/**
 *  Refresh timing
 *
 *  Determines the timing operation of auto-refresh in the SDRAM controller. Specifically, it determines the
 *  number of bus clocks inserted between a ref command and the next possible actv command. This same
 *  timing is used for both memory blocks controlled by the SDRAM controller. This corresponds to Trc in the
 *  SDRAM specifications
 */
enum SdramRefreshTiming : uint16_t {
   SdramRefreshTiming_3Clocks = SDRAMC_CTRL_RTIM(0b00), /**< 3 Clocks */
   SdramRefreshTiming_6Clocks = SDRAMC_CTRL_RTIM(0b01), /**< 6 Clocks */
   SdramRefreshTiming_9Clocks = SDRAMC_CTRL_RTIM(0b10), /**< 9 Clocks */
//      SdramRefreshTiming_9Clocks = SDRAMC_CTRL_RTIM(0b11),
};

/**
 * Address mask for various size (in bytes!).
 * Other patterns are possible but unlikely.
 */
enum SdramSize : uint32_t {
   SdramSize_256kiB = SDRAMC_CM_BAM((1U<< 0)-1U), /**< Memory size 256kiB */
   SdramSize_512kiB = SDRAMC_CM_BAM((1U<< 1)-1U), /**< Memory size 512kiB */
   SdramSize_1MiB   = SDRAMC_CM_BAM((1U<< 2)-1U), /**< Memory size 1MiB   */
   SdramSize_2MiB   = SDRAMC_CM_BAM((1U<< 3)-1U), /**< Memory size 2MiB   */
   SdramSize_4MiB   = SDRAMC_CM_BAM((1U<< 4)-1U), /**< Memory size 4MiB   */
   SdramSize_8MiB   = SDRAMC_CM_BAM((1U<< 5)-1U), /**< Memory size 8MiB   */
   SdramSize_16MiB  = SDRAMC_CM_BAM((1U<< 6)-1U), /**< Memory size 16MiB  */
   SdramSize_32MiB  = SDRAMC_CM_BAM((1U<< 7)-1U), /**< Memory size 32MiB  */
   SdramSize_64MiB  = SDRAMC_CM_BAM((1U<< 8)-1U), /**< Memory size 64MiB  */
   SdramSize_128MiB = SDRAMC_CM_BAM((1U<< 9)-1U), /**< Memory size 128MiB */
   SdramSize_256MiB = SDRAMC_CM_BAM((1U<<10)-1U), /**< Memory size 256MiB */
   SdramSize_512MiB = SDRAMC_CM_BAM((1U<<11)-1U), /**< Memory size 512MiB */
};

/**
 * Controls the read/write capabilities of a Flexbus memory range
 */
enum SdramcMode : uint16_t {
   SdramcMode_Disabled  = SDRAMC_CM_WP(0)|SDRAMC_CM_V(0), ///< Disabled
   SdramcMode_ReadWrite = SDRAMC_CM_WP(0)|SDRAMC_CM_V(1), ///< Read/Write access
   SdramcMode_ReadOnly  = SDRAMC_CM_WP(1)|SDRAMC_CM_V(1), ///< Read-only access
};

/**
 *  Indicates SDRAM characteristics that affect pin mapping
 */
enum SdramMapping {
   sdramMapping_8B_9C = 0,  /**<  8-bit data port,  9 column address lines */
   sdramMapping_8B_10C,     /**<  8-bit data port, 10 column address lines */
   sdramMapping_8B_11C,     /**<  8-bit data port, 11 column address lines */
   sdramMapping_16B_8C,     /**< 16-bit data port,  8 column address lines */
   sdramMapping_16B_9C,     /**< 16-bit data port,  9 column address lines */
   sdramMapping_16B_10C,    /**< 16-bit data port, 10 column address lines */
   sdramMapping_16B_11C,    /**< 16-bit data port, 11 column address lines */
   sdramMapping_32B_8C,     /**< 32-bit data port,  8 column address lines */
   sdramMapping_32B_9C,     /**< 32-bit data port,  9 column address lines */
   sdramMapping_32B_10C,    /**< 32-bit data port, 10 column address lines */
};

/**
 * Structure representing the SDRAMC CTRL register value
 */
struct SdramRefreshParameters {
private:
   const uint32_t ctrl;

public:
   /**
    *  Construct refresh parameters.
    *  This will also exit self-refresh mode if active.
    *
    * @param clockFrequency      SDRAMC clock frequency (use @ref SdramcBase::getClockFrequency())
    *
    * @param sdramRefreshTiming
    *   Determines the timing operation of auto-refresh in the SDRAM controller.
    *   Specifically, it determines the number of bus clocks inserted between a
    *   ref command and the next possible actv command.
    *   This same timing is used for both memory blocks controlled by the SDRAM controller.
    *   This corresponds to t(RC) in the SDRAM specifications
    *
    * @param rows                Number of rows to refresh in refresh period
    *
    * @param refreshPeriod       Refresh period (milliseconds)
    */
   SdramRefreshParameters(
         uint32_t             clockFrequency,
         SdramRefreshTiming   sdramRefreshTiming,
         unsigned             rows=4096,
         unsigned             refreshPeriod = 64) :
            ctrl (sdramRefreshTiming|SDRAMC_CTRL_RC(((refreshPeriod*(clockFrequency/(16*1000)))/rows)-1)) {
      /*
       * refreshCount (RC)
       *
       *   Controls refresh frequency.
       *   The number of bus clocks between refresh cycles is (refreshCount + 1) x 16.
       *   Refresh can range from 16–8192 bus clocks to accommodate both standard and low-power SDRAMs with bus
       *   clock operation from less than 2 MHz to greater than 50 MHz.
       *
       *   Example:
       *     auto-refresh period of 64ms
       *     4096 rows to be refreshed in that period
       *     Requires refresh cycle 15.625 us for each row
       *     This equates to 1031 bus clocks at 66 MHz (15.625ms * 66MHz)
       *     refreshCount = (1031 bus clocks/16) -1 = 63.45 (from above equation)
       */
   };

   /**
    * Get SDRAMC CTRL register value
    *
    * @return CTRL value
    */
   uint32_t getCtrl() const {
      return ctrl;
   }
};

/**
 * Structure describing how to initialise SDRAMC block
 */
struct SdramEntry {

private:
   const uint32_t ac;                         ///< Address and Control Register (SDRAM_ACn)
   const uint32_t cm;                         ///< Control Mask (SDRAM_CMn)
   const uint32_t modeRegisterValue;          ///< Value for SDRAM Mode register
   const uint32_t extendedModeRegisterValue;  ///< Value for SDRAM Extended Mode register

public:
  /**
   * Constructor.
   *
   * @param sdramcBlock                 SDRAM block being configured
   * @param baseAddress                 Base address of block
   * @param sdramcCasl                  CASL timing
   * @param sdramcCommandBitLocation    Command bit location
   * @param sdramcPortSize              SDRAM Data Port size
   * @param sdramSize                   SDRAM size
   * @param sdramcMode                  SDRAM access modes
   * @param modeRegisterValue           Value to write to SDRAM mode register
   * @param extendedModeRegisterValue   Value to write to SDRAM extended mode register (omit to disabled)
   *
   * @note May be used to create tables in ROM.
   */
   constexpr SdramEntry(
         SdramcBlock                sdramcBlock,
         uint32_t                   baseAddress,
         SdramcCasl                 sdramcCasl,
         SdramcCommandBitLocation   sdramcCommandBitLocation,
         SdramcPortSize             sdramcPortSize,
         SdramSize                  sdramSize,
         SdramcMode                 sdramcMode,
         uint32_t                   modeRegisterValue,
         uint32_t                   extendedModeRegisterValue = (uint32_t)-1
         ) :
      ac(baseAddress|sdramcCasl|sdramcCommandBitLocation|sdramcPortSize),
      cm((sdramSize&SDRAMC_CM_BAM_MASK)|sdramcMode|(sdramcBlock<<1)),
      modeRegisterValue(modeRegisterValue),
      extendedModeRegisterValue(extendedModeRegisterValue) {
      usbdm_assert(baseAddress == (baseAddress&SDRAMC_AC_BA_MASK), "SDRAM start address is not on suitable boundary") ;
      usbdm_assert(sdramSize   == (sdramSize&SDRAMC_CM_BAM_MASK),  "SDRAM size size is invalid") ;
   };

   /**
    * Get Control Mask value
    *
    * @return Control Mask value
    */
   uint32_t getCm() const {
      return cm & ~0b11110;
   }

   /**
    * Get Address and Control Register value
    *
    * @return Address and Control Register value
    */
   uint32_t getAc() const {
      return ac;
   }

   /**
    * Get base address of SDRAM block
    *
    * @return Address and Control Register value
    */
   uint32_t getBaseAddress() const {
      return ac&SDRAMC_AC_BA_MASK;
   }

   /**
    * Get data port size
    *
    * @return data port size
    */
   SdramcPortSize getDataPortSize() const {
      return (SdramcPortSize)(ac&SDRAMC_AC_PS_MASK);
   }
   /**
    * Get block number
    *
    * @return Block number
    */
   SdramcBlock getBlockNumber() const {
      return (SdramcBlock)((cm>>1)&0xF);
   }

   /**
    * Indicates if writing an extended mode register value is needed
    *
    * @return true if needed
    */
   bool isExtendedModeRegisterNeeded() const {
      return extendedModeRegisterValue != (uint32_t)-1;
   }

   /**
    * Get SRAM Mode register value
    *
    * @return register value
    */
   uint32_t getModeRegisterValue() const {
      return modeRegisterValue;
   }

   /**
    * Get SRAM Extended Mode register value
    *
    * @return register value
    */
   uint32_t getExtendedModeRegisterValue() const {
      return extendedModeRegisterValue;
   }
};

/**
 * Base class for SDRAMC interface
 */
class SdramcBase {

private:
   /**
    * This class is not intended to be instantiated by copy
    */
   SdramcBase(const SdramcBase&) = delete;
   SdramcBase(SdramcBase&&) = delete;

protected:
   const HardwarePtr<SDRAMC_Type> sdramc;                 //!< SDRAMC hardware instance

   /**
    * Construct SDRAMC interface
    *
    * @param[in]  sdramc     Base address of SDRAMC hardware
    */
   constexpr SdramcBase(uint32_t sdramc) : sdramc(sdramc) {
   }

public:
   /**
    * Map SDRAM address value to SDRAMC address value by shuffling bits
    *
    * Based on tables 34-4 to 34-13 in MK28 Reference Manual<br>
    * This is needed for SDRAM mode value access via address lines
    *
    * @param sdramMapping  Characteristics of the SDRAM (Width+Number of CA lines)
    * @param address       Address to map
    *
    * @return Mapped address
    *
    *   Example:
    *
    *   MK28 RM Table 34-8 (modified)
    *   SDRAM Controller to SDRAM Interface (16-Bit Port, 9-Column Address Lines)
    * @code
    * | SDRAM Controller Pins | A16 | A15 | A14 | A13 | A12 | A11 | A10 | A9 | A18 | A19 | A20 | A21 | A22 | A23 |
    * | Row lines             | 16  | 15  | 14  | 13  | 12  | 11  | 10  | 9  | 18  | 19  | 20  | 21  | 22  | 23  |
    * | Column lines          | 1   |  2  |  3  |  4  |  5  |  6  |  7  | 8  | 17  |  -  | CMD |  -  |  -  |  -  |
    * | SDRAM Pins            | A0  | A1  | A2  | A3  | A4  | A5  | A6  | A7 | A8  | A9  | A10 | A11 | BA0 | BA1 |
    * @endcode
    */
   static constexpr uint32_t shuffleAddress(SdramMapping sdramMapping, uint16_t address) noexcept {
      constexpr unsigned NUM_BITS = 15;

      // Maps SDRAM bit address to SDRAMC bit address
      // (see Row lines in above table or refer to schematic for wiring of address lines SDRAMC <-> SDRAM)
      // A bit crude - negative values in table will abort compilation with a negative shift operand error
      constexpr int pinMap[][NUM_BITS] = {
            // A0  A1  A2  A3  A4  A5  A6  A7  A8  A9  A10 A11 A12 A13 A14
            {  17, 16, 15, 14, 13, 12, 11, 10,  9, 18, 19, 20, 21, 22, 23, }, //  8-bit port,  9 column address lines
            {  17, 16, 15, 14, 13, 12, 11, 10,  9, 19, 20, 21, 22, 23, -1, }, //  8-bit port, 10 column address lines
            {  17, 16, 15, 14, 13, 12, 11, 10,  9, 19, 21, 22, 23, -1, -1, }, //  8-bit port, 11 column address lines
            {  16, 15, 14, 13, 12, 11, 10,  9, 17, 18, 19, 20, 21, 22, 23, }, // 16-bit port,  8 column address lines
            {  16, 15, 14, 13, 12, 11, 10,  9, 18, 19, 20, 21, 22, 23, -1, }, // 16-bit port,  9 column address lines
            {  16, 15, 14, 13, 12, 11, 10,  9, 18, 20, 21, 22, 23, -1, -1, }, // 16-bit port, 10 column address lines
            {  16, 15, 14, 13, 12, 11, 10,  9, 18, 20, 22, 23, -1, -1, -1, }, // 16-bit port, 11 column address lines
            {  15, 14, 13, 12, 11, 10,  9, 17, 18, 19, 20, 21, 22, 23, -1, }, // 32-bit port,  8 column address lines
            {  15, 14, 13, 12, 11, 10,  9, 17, 19, 20, 21, 22, 23, -1, -1, }, // 32-bit port,  9 column address lines
            {  15, 14, 13, 12, 11, 10,  9, 17, 19, 21, 22, 23, -1, -1, -1, }, // 32-bit port, 10 column address lines
      };
      uint32_t res = 0;
      for (unsigned bitNum=0; bitNum<NUM_BITS; bitNum++) {
         res |= (unsigned)(((address&(1<<bitNum)) != 0)?(1<<(pinMap[sdramMapping][bitNum])):0);
      }
      return res;
   }

   /**
    * Get Command-bit location based on SDRAM characteristics
    * Based on tables 34-4 to 34-13 in MK28 Reference Manual
    *
    * @param sdramMapping  Characteristics of the SDRAM (Width+Number of CA lines)
    *
    * @return  SDRAMC pin identifier
    */
   static constexpr SdramcCommandBitLocation getCommandAdddress(SdramMapping sdramMapping) {
      constexpr SdramcCommandBitLocation pinMap[] = {
            //               8-Column Address Lines       9-Column Address Lines        10-Column Address Lines       11-Column Address Lines
            /*  8-wide */                               SdramcCommandBitLocation_A19, SdramcCommandBitLocation_A20, SdramcCommandBitLocation_A22,
            /* 16-wide */ SdramcCommandBitLocation_A19, SdramcCommandBitLocation_A20, SdramcCommandBitLocation_A21, SdramcCommandBitLocation_A23,
            /* 32-wide */ SdramcCommandBitLocation_A20, SdramcCommandBitLocation_A21, SdramcCommandBitLocation_A22,
      };
      return pinMap[sdramMapping];
   }

   /**
      * Get SDRAMC input clock frequency
      *
      * @return Frequency as a uint32_t in Hz
      *
      * @note This is the frequency of the clock used by SDRAMC internally not the external FLEXBUS/SDRAM clock on CLKOUT.
      */
   static uint32_t getClockFrequency() {
      return SystemBusClock;
   }
};

/**
 * @brief Template class representing an SDRAMC interface
 *
 * <b>Example</b>
 *
 * @code
 *  @endcode
 *
 * @tparam Info            Class describing SDRAMC hardware
 */
template<class Info>
class SdramcBase_T : public SdramcBase {

private:
   /**
    * This class is not intended to be instantiated by copy
    */
   SdramcBase_T(const SdramcBase_T&) = delete;
   SdramcBase_T(SdramcBase_T&&) = delete;

public:
   /** Class to static check channel exists and is mapped to a pin */
   template<int pin> class CheckPinExistsAndIsMapped {
      // Tests are chained so only a single assertion can fail so as to reduce noise

      // Out of bounds value for function index
      static constexpr bool Test1 = (pin>=0) && (pin<(Info::numSignals));
      // Function is not currently mapped to a pin
      static constexpr bool Test2 = !Test1 || (Info::info[pin].gpioBit != UNMAPPED_PCR);
      // Non-existent function and catch-all. (should be INVALID_PCR)
      static constexpr bool Test3 = !Test1 || !Test2 || (Info::info[pin].gpioBit >= 0);

      static_assert(Test1, "Illegal SDRAMC pin - Check Configure.usbdm for available pin");
      static_assert(Test2, "SDRAMC output is not mapped to a pin - Modify Configure.usbdm");
      static_assert(Test3, "SDRAMC pin doesn't exist in this device/package - Check Configure.usbdm for available outputs pins");

   public:
      /** Dummy function to allow convenient in-line checking */
      static constexpr void check() {}
   };

   /**
    * Hardware instance pointer
    *
    * @return Pointer to SDRAMC hardware
    */
   static constexpr HardwarePtr<SDRAMC_Type> sdramc = Info::baseAddress;

   /**
    * Construct SDRAMC interface
    */
   constexpr SdramcBase_T() : SdramcBase(Info::baseAddress) {
   }

   /**
    * Configures all mapped pins associated with this peripheral
    */
   static void __attribute__((always_inline)) configureAllPins() {
      // Configure pins
      Info::initPCRs();
   }

   /**
    * Basic enable of module.
    * Includes enabling clock and configuring all pins if mapPinsOnEnable is selected on configuration
    */
   static void enable() {
      if constexpr (Info::mapPinsOnEnable) {
         configureAllPins();
      }

      // The multiplexing of shared FLEXBUS/SDRAMC ports is controlled by the FLEXBUS controller
      FlexbusInfo::configureSharedMultiplexing();

      // Requires CLKOUT = FLEXBUS Clock
      SimInfo::setClkout(SimClkoutSel_FlexBus);

      // Enable clock to hardware
      Info::enableClock();
   }

   /**
    * Base configuration of SDRAMC module
    *
    *  - Enables clock
    *  - Optionally configures pin mapping (See @ref SdramcInfo::mapPinsOnEnable)
    *  - Configures shared pin mapping control (via Flexbus controller)
    *  - Set refresh parameters which are shared across blocks.
    *
    * @param sdramRefreshTiming
    *   Determines the timing operation of auto-refresh in the SDRAM controller.
    *   Specifically, it determines the number of bus clocks inserted between a
    *   ref command and the next possible actv command.
    *   This same timing is used for both memory blocks controlled by the SDRAM controller.
    *   This corresponds to t(RC) in the SDRAM specifications
    *
    * @param rows                Number of rows to refresh in refresh period
    *
    * @param refreshPeriod       Refresh period (milliseconds)
    */
   static void configure(
         SdramRefreshTiming   sdramRefreshTiming,
         unsigned             rows=4096,
         unsigned             refreshPeriod = 64) {
      enable();
      setRefreshParameters(sdramRefreshTiming, rows, refreshPeriod);
   }

   /**
    * Enable with default settings.
    */
   static void defaultConfigure() {
      enable();
   }

   /**
    * Disable interface to SDRAMC.
    */
   static void disable() {
      Info::disableClock();
   }

   /**
    *  Initiate Mode Register Set command.
    *
    *  Generates a <b>Mode Register Set</b> command to the associated SDRAMs.
    *  In initialization, IMRS should be set only after all DRAM controller registers
    *  are initialized and pall and refresh commands have been issued.
    *  After IMRS is set, the next access to an SDRAM block programs the
    *  SDRAM’s mode register. Thus, the address of the access should be programmed
    *  to place the correct mode information on the SDRAM address pins.
    *  Because the SDRAM does not register this information, it doesn’t matter if the
    *  IMRS access is a read or a write or what, if any, data is put onto the data bus.
    *
    * @param sdramcBlock  The SDRAMC block being modified
    */
   static void initiateModeRegisterSet(SdramcBlock sdramcBlock) {

      //  The DRAM controller clears IMRS after the mrs command finishes.
      sdramc->BLOCK[sdramcBlock].AC |= SDRAMC_AC_IMRS_MASK;
   }

   /**
    * Initiate Precharge All Banks command.
    *
    * A <b>Precharge All Banks</b> command is sent to the associated SDRAM block.
    * During initialization, this command is executed after all DRAM controller
    * registers are programmed.
    * The next write to an appropriate SDRAM address generates the <b>Precharge
    * All Banks</b> command to the SDRAM block.
    * Accesses via IP should be no wider than the port size programmed in PS.
    *
    * @param sdramcBlock  The SDRAMC block being modified
    */
   static void initiatePrecharge(SdramcBlock sdramcBlock) {

      // The DRAM controller clears IP after the pall command is finished.
      sdramc->BLOCK[sdramcBlock].AC |= SDRAMC_AC_IP_MASK;
   }

   /**
    *  Set refresh parameters.
    *  This will also exit self-refresh mode if active.
    *
    * @param sdramRefreshTiming
    *   Determines the timing operation of auto-refresh in the SDRAM controller.
    *   Specifically, it determines the number of bus clocks inserted between a
    *   ref command and the next possible actv command.
    *   This same timing is used for both memory blocks controlled by the SDRAM controller.
    *   This corresponds to t(RC) in the SDRAM specifications
    *
    * @param rows                Number of rows to refresh in refresh period
    *
    * @param refreshPeriod       Refresh period (milliseconds)
    */
   static void setRefreshParameters(
         SdramRefreshTiming   sdramRefreshTiming,
         unsigned             rows=4096,
         unsigned             refreshPeriod = 64) {
      const SdramRefreshParameters parameters(getClockFrequency(), sdramRefreshTiming, rows, refreshPeriod);
      sdramc->CTRL = parameters.getCtrl();
   }

   /**
    *  Set refresh parameters.
    *
    *  This will also exit self-refresh mode if active.
    *
    * @param sdramRefreshParameters Parameters for SDRAMC CTRL register
    */
   static void setRefreshParameters(const SdramRefreshParameters &sdramRefreshParameters) {
      sdramc->CTRL = sdramRefreshParameters.getCtrl();
   }

private:
   /**
    * Write dummy value to SDRAM
    *
    * @param entry   Information about SDRAM block being accessed
    * @param offset  Address offset from block base address to write to (usually mode register value)
    */
   static void writeDummyValueToSdram(const SdramEntry &entry, uint32_t offset) {

      // Base address of SDRAM + offset
      uint32_t address = entry.getBaseAddress() + offset;

      // Do write of appropriate size
      switch (entry.getDataPortSize()) {
         case SdramcPortSize_8 :
            (*(uint8_t *)address) = -1;
            break;

         case SdramcPortSize_16 :
            (*(uint16_t *)address) = -1;
            break;

         case SdramcPortSize_32 :
            (*(uint32_t *)address) = -1;
            break;
      }
   };

public:
   /**
    * Configure a SDRAM block.
    *
    * Access to the block is configured and the SDRAM is initialised.
    * Auto-refresh is enabled for the block.
    *
    * @param entry Information to configure block
    */
   static void configureBlock(const SdramEntry &entry) {

      SdramcBlock block = entry.getBlockNumber();
      auto &blockRef    = sdramc->BLOCK[block];

      // Set base address etc.
      blockRef.AC = entry.getAc();

      // Dummy value to ensure mode register write has control of needed address lines
      blockRef.CM = (SDRAMC_AC_BA_MASK&0x00FF'FFFF)|SdramcMode_ReadWrite;

      // Initiate precharge
      // The DRAM controller clears IP after the pall command is finished.
      blockRef.AC |= SDRAMC_AC_IP_MASK;

      // Dummy write
      writeDummyValueToSdram(entry, 0);

      // Start auto-refresh of block
      enableAutoRefresh(block);

      // Wait at least 8 refresh cycles
      waitMS(8*64);

      // Write mode register value
      initiateModeRegisterSet(block);
      writeDummyValueToSdram(entry, entry.getModeRegisterValue());

      if (entry.isExtendedModeRegisterNeeded()) {
         // Write extended mode register value
         initiateModeRegisterSet(block);
         writeDummyValueToSdram(entry, entry.getExtendedModeRegisterValue());
      }

      // Configure memory size and access.
      blockRef.CM = entry.getCm();
  }

   /**
    * Configure multiple SDRAM blocks
    *
    * @param entries Information to configure blocks
    */
   template<unsigned N>
   static void configureBlocks(const SdramEntry (&entries)[N]) {
      for (unsigned index=0; index<N; index++) {
         configureBlock(entries[index]);
      }
   }

   /**
    *  All SDRAMs enter low-power self-refresh mode.
    *
    *  SDRAM controller sends a <b>Self Refresh Entry</b> command to both SDRAM blocks to put them in low-power,
    *  self-refresh state.
    *
    *  The SDRAMC refresh counter is suspended while the SDRAMs are in self-refresh.
    *  The SDRAM controls the internal refresh period.
    */
   static void enterSelfRefresh () {
      sdramc->CTRL |= SDRAMC_CTRL_IS_MASK;
   }

   /**
    * All SDRAMs exit self-refresh mode.
    *
    * The controller sends a <b>Self Refresh Exit</b> command for the SDRAMs (if needed) to exit self-refresh.
    */
   static void exitSelfRefresh () {
      sdramc->CTRL &= ~SDRAMC_CTRL_IS_MASK;
   }

   /**
    * Enables automatically refresh of the SDRAM by the SDRAMC
    *
    * @param sdramcBlock  The SDRAMC block being modified
    */
   static void enableAutoRefresh(SdramcBlock sdramcBlock) {
      sdramc->BLOCK[sdramcBlock].AC |= SDRAMC_AC_RE_MASK;
   }

   /**
    * Disables automatically refresh of the SDRAM by the SDRAMC
    *
    * @param sdramcBlock  The SDRAMC block being modified
    */
   static void disableAutoRefresh(SdramcBlock sdramcBlock) {
      sdramc->BLOCK[sdramcBlock].AC &= ~SDRAMC_AC_RE_MASK;
   }
};

#if defined(USBDM_SDRAMC_IS_DEFINED)
class Sdramc : public SdramcBase_T<SdramcInfo> {};
#endif

#if defined(USBDM_SDRAMC0_IS_DEFINED)
class Sdramc0 : public SdramcBase_T<Sdramc0Info> {};
#endif

/**
 * End SDRAMC_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_SDRAMC_H */