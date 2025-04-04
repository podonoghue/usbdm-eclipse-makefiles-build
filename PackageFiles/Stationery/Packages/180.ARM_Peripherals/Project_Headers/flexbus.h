/**
 * @file     flexbus.h (180.ARM_Peripherals/Project_Headers/flexbus.h)
 * @brief    Flexbus interface
 */

#ifndef HEADER_FLEXBUS_H
#define HEADER_FLEXBUS_H

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

$(/FLEXBUS/prototypes:// $/FLEXBUS/prototypes not found)

namespace USBDM {

/**
 * @addtogroup FLEXBUS_Group FLEXBUS, Flexbus - External Bus Interface
 * @brief Abstraction for Flexbus - External Bus Interface
 * @{
 */
$(/FLEXBUS/peripheral_h_definition:// $/FLEXBUS/peripheral_h_definition not found)
#if $(/FLEXBUS/_BasicInfoGuard:false) // /FLEXIO/_BasicInfoGuard

/**
 * Indices for FLEXBUS select regions
 */
enum FlexbusRegion : uint16_t {
   FlexbusRegion0 = 0,
   FlexbusRegion1 = 1,
#if FLEXBUS_MEMORY_REGIONS_COUNT > 2
   FlexbusRegion2 = 2,
   FlexbusRegion3 = 3,
#endif
#if FLEXBUS_MEMORY_REGIONS_COUNT > 4
   FlexbusRegion4 = 4,
   FlexbusRegion5 = 5,
#endif
#if FLEXBUS_MEMORY_REGIONS_COUNT > 6
   FlexbusRegion6 = 6,
   FlexbusRegion7 = 7,
#endif
   };

/**
 * Address mask for various size (in Bytes!)
 * Other patterns are possible but unlikely.
 */
enum FlexbusSize {
   FlexbusSize_64kiB  = FLEXBUS_CSMR_BAM((1U<< 0)-1), /**< Memory size 64kiB  */
   FlexbusSize_128kiB = FLEXBUS_CSMR_BAM((1U<< 1)-1), /**< Memory size 128kiB */
   FlexbusSize_256kiB = FLEXBUS_CSMR_BAM((1U<< 2)-1), /**< Memory size 256kiB */
   FlexbusSize_512kiB = FLEXBUS_CSMR_BAM((1U<< 3)-1), /**< Memory size 512kiB */
   FlexbusSize_1MiB   = FLEXBUS_CSMR_BAM((1U<< 4)-1), /**< Memory size 1MiB   */
   FlexbusSize_2MiB   = FLEXBUS_CSMR_BAM((1U<< 5)-1), /**< Memory size 2MiB   */
   FlexbusSize_4MiB   = FLEXBUS_CSMR_BAM((1U<< 6)-1), /**< Memory size 4MiB   */
   FlexbusSize_8MiB   = FLEXBUS_CSMR_BAM((1U<< 7)-1), /**< Memory size 8MiB   */
   FlexbusSize_16MiB  = FLEXBUS_CSMR_BAM((1U<< 8)-1), /**< Memory size 16MiB  */
   FlexbusSize_32MiB  = FLEXBUS_CSMR_BAM((1U<<19)-1), /**< Memory size 32MiB  */
   FlexbusSize_64MiB  = FLEXBUS_CSMR_BAM((1U<<10)-1), /**< Memory size 64MiB  */
   FlexbusSize_128MiB = FLEXBUS_CSMR_BAM((1U<<11)-1), /**< Memory size 128MiB */
   FlexbusSize_256MiB = FLEXBUS_CSMR_BAM((1U<<12)-1), /**< Memory size 256MiB */
   FlexbusSize_512MiB = FLEXBUS_CSMR_BAM((1U<<13)-1), /**< Memory size 512MiB */
};

/**
 * Controls the read/write capabilities of a Flexbus memory range
 */
enum FlexbusMode : uint16_t {
   FlexbusMode_Disabled  = FLEXBUS_CSMR_WP(0)|FLEXBUS_CSMR_V(0), ///< Disabled
   FlexbusMode_ReadWrite = FLEXBUS_CSMR_WP(0)|FLEXBUS_CSMR_V(1), ///< Read/Write access
   FlexbusMode_ReadOnly  = FLEXBUS_CSMR_WP(1)|FLEXBUS_CSMR_V(1), ///< Read-only access
};

/**
 * Wait States (WS) to use
 *
 * Specifies the number of wait states inserted after FlexBus asserts the associated chip-select
 * and before an internal transfer acknowledge is generated
 */
enum FlexbusWait {
   FlexbusWait_0 = FLEXBUS_CSCR_WS(0), FlexbusWait_10 = FLEXBUS_CSCR_WS(10), FlexbusWait_20 = FLEXBUS_CSCR_WS(20), FlexbusWait_30 = FLEXBUS_CSCR_WS(30), FlexbusWait_40 = FLEXBUS_CSCR_WS(40), FlexbusWait_50 = FLEXBUS_CSCR_WS(50), FlexbusWait_60 = FLEXBUS_CSCR_WS(60),
   FlexbusWait_1 = FLEXBUS_CSCR_WS(1), FlexbusWait_11 = FLEXBUS_CSCR_WS(11), FlexbusWait_21 = FLEXBUS_CSCR_WS(21), FlexbusWait_31 = FLEXBUS_CSCR_WS(31), FlexbusWait_41 = FLEXBUS_CSCR_WS(41), FlexbusWait_51 = FLEXBUS_CSCR_WS(51), FlexbusWait_61 = FLEXBUS_CSCR_WS(61),
   FlexbusWait_2 = FLEXBUS_CSCR_WS(2), FlexbusWait_12 = FLEXBUS_CSCR_WS(12), FlexbusWait_22 = FLEXBUS_CSCR_WS(22), FlexbusWait_32 = FLEXBUS_CSCR_WS(32), FlexbusWait_42 = FLEXBUS_CSCR_WS(42), FlexbusWait_52 = FLEXBUS_CSCR_WS(52), FlexbusWait_62 = FLEXBUS_CSCR_WS(62),
   FlexbusWait_3 = FLEXBUS_CSCR_WS(3), FlexbusWait_13 = FLEXBUS_CSCR_WS(13), FlexbusWait_23 = FLEXBUS_CSCR_WS(23), FlexbusWait_33 = FLEXBUS_CSCR_WS(33), FlexbusWait_43 = FLEXBUS_CSCR_WS(43), FlexbusWait_53 = FLEXBUS_CSCR_WS(53), FlexbusWait_63 = FLEXBUS_CSCR_WS(63),
   FlexbusWait_4 = FLEXBUS_CSCR_WS(4), FlexbusWait_14 = FLEXBUS_CSCR_WS(14), FlexbusWait_24 = FLEXBUS_CSCR_WS(24), FlexbusWait_34 = FLEXBUS_CSCR_WS(34), FlexbusWait_44 = FLEXBUS_CSCR_WS(44), FlexbusWait_54 = FLEXBUS_CSCR_WS(54),
   FlexbusWait_5 = FLEXBUS_CSCR_WS(5), FlexbusWait_15 = FLEXBUS_CSCR_WS(15), FlexbusWait_25 = FLEXBUS_CSCR_WS(25), FlexbusWait_35 = FLEXBUS_CSCR_WS(35), FlexbusWait_45 = FLEXBUS_CSCR_WS(45), FlexbusWait_55 = FLEXBUS_CSCR_WS(55),
   FlexbusWait_6 = FLEXBUS_CSCR_WS(6), FlexbusWait_16 = FLEXBUS_CSCR_WS(16), FlexbusWait_26 = FLEXBUS_CSCR_WS(26), FlexbusWait_36 = FLEXBUS_CSCR_WS(36), FlexbusWait_46 = FLEXBUS_CSCR_WS(46), FlexbusWait_56 = FLEXBUS_CSCR_WS(56),
   FlexbusWait_7 = FLEXBUS_CSCR_WS(7), FlexbusWait_17 = FLEXBUS_CSCR_WS(17), FlexbusWait_27 = FLEXBUS_CSCR_WS(27), FlexbusWait_37 = FLEXBUS_CSCR_WS(37), FlexbusWait_47 = FLEXBUS_CSCR_WS(47), FlexbusWait_57 = FLEXBUS_CSCR_WS(57),
   FlexbusWait_8 = FLEXBUS_CSCR_WS(8), FlexbusWait_18 = FLEXBUS_CSCR_WS(18), FlexbusWait_28 = FLEXBUS_CSCR_WS(28), FlexbusWait_38 = FLEXBUS_CSCR_WS(38), FlexbusWait_48 = FLEXBUS_CSCR_WS(48), FlexbusWait_58 = FLEXBUS_CSCR_WS(58),
   FlexbusWait_9 = FLEXBUS_CSCR_WS(9), FlexbusWait_19 = FLEXBUS_CSCR_WS(19), FlexbusWait_29 = FLEXBUS_CSCR_WS(29), FlexbusWait_39 = FLEXBUS_CSCR_WS(39), FlexbusWait_49 = FLEXBUS_CSCR_WS(49), FlexbusWait_59 = FLEXBUS_CSCR_WS(59),
};

constexpr int calcSWS(int i) {
   return (i<0)?0:(FLEXBUS_CSCR_SWS(i)|FLEXBUS_CSCR_SWSEN(1));
}

/**
 * Secondary Wait States (SWS) to use
 *
 * Specifies the number of wait states inserted before an internal transfer acknowledge is generated
 * for a burst transfer (except for the first termination, which is controlled by WS).
 * - When disabled the number of wait states specified by WS are inserted before an internal transfer
 *   acknowledge is generated for all transfers.
 * - When enabled the number of wait states specified by SWS are inserted before an internal transfer
 *   acknowledge is generated for burst transfer secondary terminations.
 */

enum FlexbusSecondaryWait {
   FlexbusSecondaryWait_Disabled = calcSWS(-1), ///< Disable indicates use WS value
   FlexbusSecondaryWait_0 = calcSWS(0), FlexbusSecondaryWait_10 = calcSWS(10), FlexbusSecondaryWait_20 = calcSWS(20), FlexbusSecondaryWait_30 = calcSWS(30), FlexbusSecondaryWait_40 = calcSWS(40), FlexbusSecondaryWait_50 = calcSWS(50), FlexbusSecondaryWait_60 = calcSWS(60),
   FlexbusSecondaryWait_1 = calcSWS(1), FlexbusSecondaryWait_11 = calcSWS(11), FlexbusSecondaryWait_21 = calcSWS(21), FlexbusSecondaryWait_31 = calcSWS(31), FlexbusSecondaryWait_41 = calcSWS(41), FlexbusSecondaryWait_51 = calcSWS(51), FlexbusSecondaryWait_61 = calcSWS(61),
   FlexbusSecondaryWait_2 = calcSWS(2), FlexbusSecondaryWait_12 = calcSWS(12), FlexbusSecondaryWait_22 = calcSWS(22), FlexbusSecondaryWait_32 = calcSWS(32), FlexbusSecondaryWait_42 = calcSWS(42), FlexbusSecondaryWait_52 = calcSWS(52), FlexbusSecondaryWait_62 = calcSWS(62),
   FlexbusSecondaryWait_3 = calcSWS(3), FlexbusSecondaryWait_13 = calcSWS(13), FlexbusSecondaryWait_23 = calcSWS(23), FlexbusSecondaryWait_33 = calcSWS(33), FlexbusSecondaryWait_43 = calcSWS(43), FlexbusSecondaryWait_53 = calcSWS(53), FlexbusSecondaryWait_63 = calcSWS(63),
   FlexbusSecondaryWait_4 = calcSWS(4), FlexbusSecondaryWait_14 = calcSWS(14), FlexbusSecondaryWait_24 = calcSWS(24), FlexbusSecondaryWait_34 = calcSWS(34), FlexbusSecondaryWait_44 = calcSWS(44), FlexbusSecondaryWait_54 = calcSWS(54),
   FlexbusSecondaryWait_5 = calcSWS(5), FlexbusSecondaryWait_15 = calcSWS(15), FlexbusSecondaryWait_25 = calcSWS(25), FlexbusSecondaryWait_35 = calcSWS(35), FlexbusSecondaryWait_45 = calcSWS(45), FlexbusSecondaryWait_55 = calcSWS(55),
   FlexbusSecondaryWait_6 = calcSWS(6), FlexbusSecondaryWait_16 = calcSWS(16), FlexbusSecondaryWait_26 = calcSWS(26), FlexbusSecondaryWait_36 = calcSWS(36), FlexbusSecondaryWait_46 = calcSWS(46), FlexbusSecondaryWait_56 = calcSWS(56),
   FlexbusSecondaryWait_7 = calcSWS(7), FlexbusSecondaryWait_17 = calcSWS(17), FlexbusSecondaryWait_27 = calcSWS(27), FlexbusSecondaryWait_37 = calcSWS(37), FlexbusSecondaryWait_47 = calcSWS(47), FlexbusSecondaryWait_57 = calcSWS(57),
   FlexbusSecondaryWait_8 = calcSWS(8), FlexbusSecondaryWait_18 = calcSWS(18), FlexbusSecondaryWait_28 = calcSWS(28), FlexbusSecondaryWait_38 = calcSWS(38), FlexbusSecondaryWait_48 = calcSWS(48), FlexbusSecondaryWait_58 = calcSWS(58),
   FlexbusSecondaryWait_9 = calcSWS(9), FlexbusSecondaryWait_19 = calcSWS(19), FlexbusSecondaryWait_29 = calcSWS(29), FlexbusSecondaryWait_39 = calcSWS(39), FlexbusSecondaryWait_49 = calcSWS(49), FlexbusSecondaryWait_59 = calcSWS(59),
};

/**
 * Extend Transfer Start/Address Latch
 * Controls how long FB_TS/FB_ALE is asserted.
 */
enum FlexbusStartLatch {
   FlexbusStartLatch_1_Cycle   = FLEXBUS_CSCR_EXTS(0), /**< FB_TS/FB_ALE asserts for one bus clock cycle */
   FlexbusStartLatch_Extended  = FLEXBUS_CSCR_EXTS(1), /**< FB_TS/FB_ALE asserted until first rising clock edge after FB_CSn asserts. */
};

/**
 * Address Setup
 * Controls when the chip-select (FB_CSn) is asserted with respect to assertion of a valid address and attributes.
 */
enum FlexbusAddresSetup {
   FlexbusAddresSetup_1st_RisingEdge = FLEXBUS_CSCR_ASET(0b00),/**< Assert FB_CSn on the first rising clock edge  */
   FlexbusAddresSetup_2nd_RisingEdge = FLEXBUS_CSCR_ASET(0b01),/**< Assert FB_CSn on the second rising clock edge */
   FlexbusAddresSetup_3rd_RisingEdge = FLEXBUS_CSCR_ASET(0b10),/**< Assert FB_CSn on the third rising clock edge  */
   FlexbusAddresSetup_4th_RisingEdge = FLEXBUS_CSCR_ASET(0b11),/**< Assert FB_CSn on the fourth rising clock edge */
};

/**
 * Read Address Hold or Deselect
 * Controls the address and attribute hold time after the termination during a read cycle that hits in the
 * associated chip-select's address space.
 *
 * Note:
 * - The hold time applies only at the end of a transfer. Therefore, during a burst transfer or a
 *   transfer to a port size smaller than the transfer size, the hold time is only added after the
 *   last bus cycle.
 * - The number of cycles the address and attributes are held after FB_CSn deassertion
 *   depends on the value of the AA bit.
 */
enum FlexbusReadHoldTime {
   FlexbusReadHoldTime_0_1_Cycle = FLEXBUS_CSCR_RDAH(0b00),/**< When AA is 0b, 1 cycle. When AA is 1b, 0 cycles */
   FlexbusReadHoldTime_1_2_Cycle = FLEXBUS_CSCR_RDAH(0b01),/**< When AA is 0b, 2 cycle. When AA is 1b, 1 cycles */
   FlexbusReadHoldTime_2_3_Cycle = FLEXBUS_CSCR_RDAH(0b10),/**< When AA is 0b, 3 cycle. When AA is 1b, 2 cycles */
   FlexbusReadHoldTime_3_4_Cycle = FLEXBUS_CSCR_RDAH(0b11),/**< When AA is 0b, 4 cycle. When AA is 1b, 3 cycles */
};

/**
 * Write Address Hold or Deselect
 * Controls the address, data, and attribute hold time after the termination of a write cycle that hits in the
 * associated chip-select's address space.
 *
 * Note:
 * - The hold time applies only at the end of a transfer. Therefore, during a burst transfer or a transfer
 *   to a port size smaller than the transfer size, the hold time is only added after the last bus cycle.
 */
enum FlexbusWriteHoldTime {
   FlexbusWriteHoldTime_1_Cycle = FLEXBUS_CSCR_WRAH(0b00), /**< 1 cycle (default for all but FB_CS0 ) */
   FlexbusWriteHoldTime_2_Cycle = FLEXBUS_CSCR_WRAH(0b01), /**< 2 cycles */
   FlexbusWriteHoldTime_3_Cycle = FLEXBUS_CSCR_WRAH(0b10), /**< 3 cycles */
   FlexbusWriteHoldTime_4_Cycle = FLEXBUS_CSCR_WRAH(0b11), /**< 4 cycles (default for FB_CS0 ) */
};

/**
 * Data alignment on FB_AD
 *
 * Specifies if data on FB_AD appears left-aligned or right-aligned during the
 * data phase of a FlexBus access.
 */
enum FlexbusDataAlignment {
   FlexbusDataAlignment_Left  = FLEXBUS_CSCR_BLS(0),/**< Data is left-aligned on FB_AD. */
   FlexbusDataAlignment_Right = FLEXBUS_CSCR_BLS(1),/**< Data is right-aligned on FB_AD. */
};

/**
 * Auto-Acknowledge Enable.
 * Asserts the internal transfer acknowledge for accesses specified by the chip-select address.
 *
 * Note:
 *    If AA is enabled for a corresponding FB_CSn and the external system asserts an external FB_TA
 *    before the wait-state count-down asserts the internal FB_TA, the cycle is terminated.
 *    Burst cycles increment the address bus between each internal termination.
 *
 * Note:
 *    This field must be 1b if CSPMCR disables FB_TA.
 */
enum FlexbusAutoAck {
   FlexbusAutoAck_Disabled = FLEXBUS_CSCR_AA(0),/**< The cycle must be terminated externally. */
   FlexbusAutoAck_Enabled  = FLEXBUS_CSCR_AA(1),/**< Internal transfer acknowledge is asserted as specified by WS. */
};

/**
 * Specifies the data port width of the associated chip-select, and determines where data is driven during
 * write cycles and where data is sampled during read cycles.
 */
enum FlexbusPortSize {
   /** Valid data is sampled and driven on FB_D[31:24] when BLS is 0b, or FB_D[7:0] when BLS is 1b */
   FlexbusPortSize_8bit    = FLEXBUS_CSCR_PS(0b01),
   /** Valid data is sampled and driven on FB_D[31:16] when BLS is 0b, or FB_D[15:0] when BLS is 1b. */
   FlexbusPortSize_16bit   = FLEXBUS_CSCR_PS(0b10),
   /** Valid data is sampled and driven on FB_D[31:0] */
   FlexbusPortSize_32bit   = FLEXBUS_CSCR_PS(0b00),
};

/**
 * Specifies whether the corresponding FB_BE is asserted for read accesses. Certain memories have byte
 * enables that must be asserted during reads and writes. Write 1b to the BEM bit in the relevant CSCR to
 * provide the appropriate mode of byte enable support for these SRAMs.
 */
enum FlexbusByteEnable {
   FlexbusByteEnable_WriteOnly   = FLEXBUS_CSCR_BEM(0b0), /**< FB_BE is asserted for data write only. */
   FlexbusByteEnable_ReadWrite   = FLEXBUS_CSCR_BEM(0b1), /**< FB_BE is asserted for data read and write accesses. */
};

/**
 * This enables or disable burst mode for reads and writes individually.
 *
 * - Disabled.
 *   Data exceeding the specified port size is broken into individual, port-sized, non-burst writes.
 *   For example, a 32-bit write to an 8-bit port takes four byte writes.
 * - Enabled.
 *   Enables bursts of data larger than the specified port size,
 *   including 32-bit accesses to 8-and 16-bit ports, 16-bit accesses to 8-bit ports,
 *   and line accesses to 8-, 16-, and 32-bit ports.
 */
enum FlexbusBurst {
   FlexbusBurst_None       = FLEXBUS_CSCR_BSTR(0)|FLEXBUS_CSCR_BSTW(0),  /**< No burst accesses */
   FlexbusBurst_Read       = FLEXBUS_CSCR_BSTR(1)|FLEXBUS_CSCR_BSTW(0),  /**< Burst accesses on reads */
   FlexbusBurst_Write      = FLEXBUS_CSCR_BSTR(0)|FLEXBUS_CSCR_BSTW(1),  /**< Burst accesses on writes */
   FlexbusBurst_ReadWrite  = FLEXBUS_CSCR_BSTR(1)|FLEXBUS_CSCR_BSTW(1),  /**< Burst accesses on reads and writes */
};
/**
 * Structure describing a flexbus selection region
 */
struct __attribute__((packed)) FlexbusEntry {
   union __attribute__((packed)) {
      struct __attribute__((packed)) {
         FlexbusRegion flexbusRegion:16; ///< Chip select number (unused portion of FB_CSARn)
         uint16_t      baseAddress:16;   ///< Base address
      };
      uint32_t csar; ///< Chip Select Address Register (FB_CSARn)
   };
   uint32_t csmr; ///< Chip Select Mask Register (FB_CSMRn)
   uint32_t cscr; ///< Chip Select Control Register (FB_CSCRn)

   /**
    * Constructor.
    * @note May be used to create tables in ROM.
    *
    * @param flexbusRegion Selection range to modify
    *
    * @param baseAddress Base address (only bits 31..16 are used).\n
    * Because the FlexBus module is one of the slaves connected to the crossbar switch, it is only
    * accessible within a certain memory ranges and from certain bus devices. See the chip memory
    * map for the applicable FlexBus "expansion" address range for which the chip-selects can be active.
    *
    * @param flexbusWait Wait States (WS)\n
    * Specifies the number of wait states inserted after FlexBus asserts the associated chip-select
    * and before an internal transfer acknowledge is generated
    *
    * @param flexbusSecondaryWait Secondary Wait States (SWS)\n
    * Specifies the number of wait states inserted before an internal transfer acknowledge is generated
    * for a burst transfer (except for the first termination, which is controlled by WS).
    * - When disabled the number of wait states specified by WS are inserted before an internal transfer
    *   acknowledge is generated for all transfers.
    * - When enabled the number of wait states specified by SWS are inserted before an internal transfer
    *   acknowledge is generated for burst transfer secondary terminations.
    *
    * @param flexbusSize Mask defining the size of chip-select range\n
    * 1's in the address mask define address bits as don't cares and hence determines the size of the address range.
    *
    * @param flexbusMode               Determines disabled, read or read/write mode
    * @param flexbusPortSize           Data port width
    * @param flexbusAutoAck            Auto-Acknowledge TransferEnable.
    * @param flexbusStartLatch         Extended Transfer Start/Address Latch Enable
    * @param flexbusAddresSetup        Address Setup
    * @param flexbusReadHoldTime       Read Address Hold or Deselect time
    * @param flexbusWriteHoldTime      Write Address Hold or Deselect time
    * @param flexbusDataAlignment      Data alignment on FB_AD pins
    * @param flexbusByteEnable         Byte-Enable Mode
    * @param flexbusBurst              Burst Enable
    */
   constexpr FlexbusEntry(
         FlexbusRegion           flexbusRegion,
         uint32_t                baseAddress,
         FlexbusSize             flexbusSize,
         FlexbusMode             flexbusMode,
         FlexbusWait             flexbusWait,
         FlexbusPortSize         flexbusPortSize,
         FlexbusAutoAck          flexbusAutoAck,
         FlexbusAddresSetup      flexbusAddresSetup      = FlexbusAddresSetup_1st_RisingEdge,
         FlexbusSecondaryWait    flexbusSecondaryWait    = FlexbusSecondaryWait_Disabled,
         FlexbusStartLatch       flexbusStartLatch       = FlexbusStartLatch_1_Cycle,
         FlexbusReadHoldTime     flexbusReadHoldTime     = FlexbusReadHoldTime_0_1_Cycle,
         FlexbusWriteHoldTime    flexbusWriteHoldTime    = FlexbusWriteHoldTime_1_Cycle,
         FlexbusDataAlignment    flexbusDataAlignment    = FlexbusDataAlignment_Left,
         FlexbusByteEnable       flexbusByteEnable       = FlexbusByteEnable_WriteOnly,
         FlexbusBurst            flexbusBurst            = FlexbusBurst_None
         ) :
      csar(baseAddress|flexbusRegion),
      csmr(flexbusSize|flexbusMode),
      cscr(flexbusWait|flexbusPortSize|flexbusAutoAck|flexbusSecondaryWait|flexbusStartLatch|flexbusAddresSetup|flexbusReadHoldTime|flexbusWriteHoldTime|flexbusDataAlignment|flexbusByteEnable|flexbusBurst) {
      usbdm_assert(baseAddress == (baseAddress&FLEXBUS_CSAR_BA_MASK), "FLEXBUS start address is not on suitable boundary") ;
   };
};

/**
 * Virtual Base class for FLEXBUS interface
 */
class FlexbusBase {

protected:
   const HardwarePtr<FLEXBUS_Type> flexbus;                 //!< FLEXBUS hardware instance

   /**
    * Construct FLEXBUS interface
    *
    * @param[in]  flexbus     Base address of FLEXBUS hardware
    */
   constexpr FlexbusBase(uint32_t flexbus) : flexbus(flexbus) {
   }
};

/**
 * @brief Template class representing an FLEXBUS interface
 *
 * <b>Example</b>
 *
 * @code
 *  @endcode
 *
 * @tparam Info            Class describing FLEXBUS hardware
 */
template<class Info>
class FlexbusBase_T : public FlexbusBase {

public:

   /**
    * Hardware instance pointer
    *
    * @return Reference to FLEXBUS hardware
    */
   static constexpr HardwarePtr<FLEXBUS_Type> flexbus = Info::baseAddress;
   /**
    * Construct FLEXBUS interface
    */
   FlexbusBase_T() : FlexbusBase(Info::baseAddress) {
   }

   /**
    * Enable with default settings.
    */
   static void defaultConfigure() {
      // Requires CLKOUT = FLEXBUS Clock
      SimInfo::setClkout(SimClkoutSel_FlexBusClk);

      Info::enable();
   }

   /**
    * Configure select range using FlexbusEntry data value
    *
    * Because the FlexBus module is one of the slaves connected to the crossbar switch, it is only
    * accessible within a certain memory range. See the chip memory map for the applicable FlexBus
    * "expansion" address range for which the chip-selects can be active.
    *
    * @code
    *    static const FlexbusEntry flexbusEntry1{1, 0x08FC0000, FlexbusSize_128k, FlexbusMode_Read,      FlexbusWait_2, FlexbusPortSize_8bit,  FlexbusAutoAck_Enabled};
    *    static const FlexbusEntry flexbusEntry2{2, 0x08FE0000, FlexbusSize_128k, FlexbusMode_ReadWrite, FlexbusWait_4, FlexbusPortSize_16bit, FlexbusAutoAck_Enabled};
    *
    *    myFlexbus.defaultConfigure();
    *    myFlexbus.configureAllPins();
    *    myFlexbus.setSelectRange(flexbusEntry1);
    *    myFlexbus.setSelectRange(flexbusEntry2);
    * @endcode
    *
    * @param flexbusEntry Entry describing select region
    */
   static void configureSelectRange(const FlexbusEntry &flexbusEntry) {
      // Disable entry initially
      FlexbusRegion flexbusRegion = flexbusEntry.flexbusRegion;

      flexbus->CS[flexbusRegion].CSMR = 0;
      // Configure entry
      flexbus->CS[flexbusRegion].CSAR = flexbusEntry.csar;
      flexbus->CS[flexbusRegion].CSCR = flexbusEntry.cscr;
      flexbus->CS[flexbusRegion].CSMR = flexbusEntry.csmr;
   }

   /**
    * Configure ranges using FlexbusEntry data table.
    *
    * @code
    *    static const FlexbusEntry flexbusEntries[] = {
    *       {1, 0x08FC0000, FlexbusSize_64k, FlexbusMode_ReadWrite, FlexbusWait_2,  FlexbusPortSize_16bit, FlexbusAutoAck_Enabled},
    *       {3, 0x08FD0000, FlexbusSize_128k, FlexbusMode_ReadWrite, FlexbusWait_3,  FlexbusPortSize_8bit,  FlexbusAutoAck_Enabled},
    *       {4, 0x08FE0000, FlexbusSize_128k, FlexbusMode_ReadWrite, FlexbusWait_12, FlexbusPortSize_8bit,  FlexbusAutoAck_Enabled},
    *     };
    *     myFlexbus.configure(flexbusEntries);
    * @endcode
    *
    * @param flexbusEntry Table of values to use
    *
    * See @ref configureSelectRange()
    */
   template<unsigned N>
   static void configureSelectRanges(const FlexbusEntry (&flexbusEntry)[N]) {
      for (unsigned index=0; index<N; index++) {
         configureSelectRange(flexbusEntry[index]);
      }
   }

   /**
    * Configure the multiplexing of FlexBus signals.
    *
    * @param flexbusGroup1 Controls the multiplexing of the FB_ALE, FB_CS1, and FB_TS signals.
    * @param flexbusGroup2 Controls the multiplexing of the FB_CS4*, FB_TSIZ0, and FB_BE_31_24 signals.
    * @param flexbusGroup3 Controls the multiplexing of the FB_CS5*, FB_TSIZ1, and FB_BE_23_16 signals.
    * @param flexbusGroup4 Controls the multiplexing of the FB_TBST*, FB_CS2, and FB_BE_15_8 signals.
    * @param flexbusGroup5 Controls the multiplexing of the FB_TA*, FB_CS3, and FB_BE_7_0 signals.
    *
    * @note Changing multiplexing may affect SDRAM controller function
    *       See FlexbusInfo::configureSharedMultiplexing()
    */
   static void configureMultiplexing(
         FlexbusGroup1 flexbusGroup1,
         FlexbusGroup2 flexbusGroup2 = FlexbusGroup2_FB_CS4,
         FlexbusGroup3 flexbusGroup3 = FlexbusGroup3_FB_CS5,
         FlexbusGroup4 flexbusGroup4 = FlexbusGroup4_FB_TBST,
         FlexbusGroup5 flexbusGroup5 = FlexbusGroup5_FB_TA
         ) {
      flexbus->CSPMCR = flexbusGroup1|flexbusGroup2|flexbusGroup3|flexbusGroup4|flexbusGroup5;
   }
};

$(/FLEXBUS/declarations: // No declarations found)
#endif // /FLEXIO/_BasicInfoGuard
/**
 * End FLEXBUS_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_FLEXBUS_H */
