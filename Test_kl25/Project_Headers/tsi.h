/*
 * tsi_MKL.h (180.ARM_Peripherals/Project_Headers/tsi-MKL.h)
 *
 *  Created on: 25/10/2013
 *      Author: podonoghue
 */

#ifndef TSI_H_
#define TSI_H_
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "hardware.h"

namespace USBDM {

/**
 * Selects out-of-range or end-of-scan event to generate an interrupt or DMA request.
 */
enum TsiInterrupt {
   TsiInterrupt_Disabled   = TSI_GENCS_TSIIEN(0b0)|TSI_GENCS_ESOR(0b0), //!< Interrupts disabled
   TsiInterrupt_OutOfRange = TSI_GENCS_TSIIEN(0b1)|TSI_GENCS_ESOR(0b0), //!< Interrupt/DMA for Out Of Range
   TsiInterrupt_EndOfScan  = TSI_GENCS_TSIIEN(0b1)|TSI_GENCS_ESOR(0b1), //!< Interrupt/DMA for End Of Scan
};

/**
 * Determines if a DMA or Interrupt request is generated on a TSI event
 *
 * @note Requires TsiInterrupt selection
 */
enum TsiDma {
   TsiDma_Disabled = TSI_DATA_DMAEN(0b0), //!< Interrupt is generated on TSI event
   TsiDma_Enabled  = TSI_DATA_DMAEN(0b1), //!< DMA request is generated on TSI event
};

/**
 * Determines the TSI analogue mode
 */
enum TsiMode {
   TsiMode_Capacitive                = TSI_GENCS_MODE(0b0000), //!< Capacitive sensing (non-noise detection) mode
   TsiMode_NoiseDetect_NoFreqLimit   = TSI_GENCS_MODE(0b0100), //!< Single threshold noise detection mode with no frequency limitation circuit
   TsiMode_NoiseDetect_FreqLimit     = TSI_GENCS_MODE(0b1000), //!< Single threshold noise detection mode with frequency limitation circuit
   TsiMode_NoiseDetect_Automatic     = TSI_GENCS_MODE(0b1100), //!< Automatic noise detection mode

};

/**
 * Determine the oscillators' voltage limits.
 * This directly affects the oscillators' frequencies but does not affect the count values as it is a ratio.
 * Values may differ by device.
 */
enum TsiDeltaVoltage {
   TsiDeltaVoltage_High    = TSI_GENCS_DVOLT(0b00), //!< Delta Voltage High     e.g. (DV = 1.026 V; Vp = 1.328 V; Vm = 0.302 V)
   TsiDeltaVoltage_MidHigh = TSI_GENCS_DVOLT(0b01), //!< Delta Voltage Mid-high e.g. (DV = 0.592 V; Vp = 1.111 V; Vm = 0.519 V)
   TsiDeltaVoltage_MidLow  = TSI_GENCS_DVOLT(0b10), //!< Delta Voltage Mid-low  e.g. (DV = 0.342 V; Vp = 0.986 V; Vm = 0.644 V)
   TsiDeltaVoltage_Low     = TSI_GENCS_DVOLT(0b11), //!< Delta Voltage Low      e.g. (DV = 0.197 V; Vp = 0.914 V; Vm = 0.716 V)
};

/**
 * These 4 bits are used to select the noise threshold.\n
 * These combinations are the maximum possible combinations, not all values are valid.
 */
enum TsiNoiseThreshold {
   TsiNoiseThreshold_0  = TSI_GENCS_NOISE_THRESHOLD(0b0000), //!< DVpm = 0.038 V, Vp = 0.834 V, Vm = 0.796 V
   TsiNoiseThreshold_1  = TSI_GENCS_NOISE_THRESHOLD(0b0001), //!< DVpm = 0.050 V, Vp = 0.830 V, Vm = 0.790 V
   TsiNoiseThreshold_2  = TSI_GENCS_NOISE_THRESHOLD(0b0010), //!< DVpm = 0.066 V, Vp = 0.848 V, Vm = 0.782 V
   TsiNoiseThreshold_3  = TSI_GENCS_NOISE_THRESHOLD(0b0011), //!< DVpm = 0.087 V, Vp = 0.858 V, Vm = 0.772 V
   TsiNoiseThreshold_4  = TSI_GENCS_NOISE_THRESHOLD(0b0100), //!< DVpm = 0.114 V, Vp = 0.872 V, Vm = 0.758 V
   TsiNoiseThreshold_5  = TSI_GENCS_NOISE_THRESHOLD(0b0101), //!< DVpm = 0.150 V, Vp = 0.890 V, Vm = 0.740 V
   TsiNoiseThreshold_6  = TSI_GENCS_NOISE_THRESHOLD(0b0110), //!< DVpm = 0.197 V, Vp = 0.914 V, Vm = 0.716 V
   TsiNoiseThreshold_7  = TSI_GENCS_NOISE_THRESHOLD(0b0111), //!< DVpm = 0.260 V, Vp = 0.945 V, Vm = 0.685 V
   TsiNoiseThreshold_8  = TSI_GENCS_NOISE_THRESHOLD(0b1000), //!< DVpm = 0.342 V, Vp = 0.986 V, Vm = 0.644 V
   TsiNoiseThreshold_9  = TSI_GENCS_NOISE_THRESHOLD(0b1001), //!< DVpm = 0.450 V, Vp = 1.040 V, Vm = 0.590 V
   TsiNoiseThreshold_10 = TSI_GENCS_NOISE_THRESHOLD(0b1010), //!< DVpm = 0.592 V, Vp = 1.111 V, Vm = 0.519 V
   TsiNoiseThreshold_11 = TSI_GENCS_NOISE_THRESHOLD(0b1011), //!< DVpm = 0.780 V, Vp = 1.205 V, Vm = 0.425 V
   TsiNoiseThreshold_12 = TSI_GENCS_NOISE_THRESHOLD(0b1100), //!< DVpm = 1.026 V, Vp = 1.328 V, Vm = 0.302 V
   TsiNoiseThreshold_13 = TSI_GENCS_NOISE_THRESHOLD(0b1101), //!< DVpm = 1.350 V, Vp = 1.490 V, Vm = 0.140 V
   TsiNoiseThreshold_14 = TSI_GENCS_NOISE_THRESHOLD(0b1110), //!< DVpm = 1.630 V, Vp = 1.630 V, Vm = 0 V
   TsiNoiseThreshold_15 = TSI_GENCS_NOISE_THRESHOLD(0b1111), //!< DVpm = 1.630 V, Vp = 1.630 V, Vm = 0 V, Rs = 5k5R
};

/**
 * Determines the reference oscillator charge and discharge current value.\n
 * This directly affects the reference oscillator frequency and hence count values.
 */
enum TsiReferenceCharge {
   TsiReferenceCharge_500nA = TSI_GENCS_REFCHRG(0b000), //!< Reference Charge = 500nA
   TsiReferenceCharge_1uA   = TSI_GENCS_REFCHRG(0b001), //!< Reference Charge = 1uA
   TsiReferenceCharge_2uA   = TSI_GENCS_REFCHRG(0b010), //!< Reference Charge = 2uA
   TsiReferenceCharge_4uA   = TSI_GENCS_REFCHRG(0b011), //!< Reference Charge = 4uA
   TsiReferenceCharge_8uA   = TSI_GENCS_REFCHRG(0b100), //!< Reference Charge = 8uA
   TsiReferenceCharge_16uA  = TSI_GENCS_REFCHRG(0b101), //!< Reference Charge = 16uA
   TsiReferenceCharge_32uA  = TSI_GENCS_REFCHRG(0b110), //!< Reference Charge = 32uA
   TsiReferenceCharge_64uA  = TSI_GENCS_REFCHRG(0b111), //!< Reference Charge = 64uA
};

/**
 * Determines the electrode oscillator charge and discharge current value\n
 * This inversely affects the electrode oscillator frequency and hence count values.
 */
enum TsiExternalCharge {
   TsiExternalCharge_500nA = TSI_GENCS_EXTCHRG(0b000), //!< External Charge = 500nA
   TsiExternalCharge_1uA   = TSI_GENCS_EXTCHRG(0b001), //!< External Charge = 1uA
   TsiExternalCharge_2uA   = TSI_GENCS_EXTCHRG(0b010), //!< External Charge = 2uA
   TsiExternalCharge_4uA   = TSI_GENCS_EXTCHRG(0b011), //!< External Charge = 4uA
   TsiExternalCharge_8uA   = TSI_GENCS_EXTCHRG(0b100), //!< External Charge = 8uA
   TsiExternalCharge_16uA  = TSI_GENCS_EXTCHRG(0b101), //!< External Charge = 16uA
   TsiExternalCharge_32uA  = TSI_GENCS_EXTCHRG(0b110), //!< External Charge = 32uA
   TsiExternalCharge_64uA  = TSI_GENCS_EXTCHRG(0b111), //!< External Charge = 64uA
};

/**
 * Determines the prescaler for the output of the electrode oscillator.\n
 * This directly affects the TSI counts.
 */
enum TsiElectrodePrescaler {
   TsiElectrodePrescaler_1   = TSI_GENCS_PS(0b000), //!< Electrode Prescaler /1
   TsiElectrodePrescaler_2   = TSI_GENCS_PS(0b001), //!< Electrode Prescaler /2
   TsiElectrodePrescaler_4   = TSI_GENCS_PS(0b010), //!< Electrode Prescaler /4
   TsiElectrodePrescaler_8   = TSI_GENCS_PS(0b011), //!< Electrode Prescaler /8
   TsiElectrodePrescaler_16  = TSI_GENCS_PS(0b100), //!< Electrode Prescaler /16
   TsiElectrodePrescaler_32  = TSI_GENCS_PS(0b101), //!< Electrode Prescaler /32
   TsiElectrodePrescaler_64  = TSI_GENCS_PS(0b110), //!< Electrode Prescaler /64
   TsiElectrodePrescaler_128 = TSI_GENCS_PS(0b111), //!< Electrode Prescaler /128
};

/**
 * Determines the number of scans when measuring an electrode\n
 * This directly affects the TSI counts.
 */
enum TsiScanNumber {
   TsiScanNumber_1  = TSI_GENCS_NSCN(0b00000), //!< 1 times per electrode
   TsiScanNumber_2  = TSI_GENCS_NSCN(0b00001), //!< 2 times per electrode
   TsiScanNumber_3  = TSI_GENCS_NSCN(0b00010), //!< 3 times per electrode
   TsiScanNumber_4  = TSI_GENCS_NSCN(0b00011), //!< 4 times per electrode
   TsiScanNumber_5  = TSI_GENCS_NSCN(0b00100), //!< 5 times per electrode
   TsiScanNumber_6  = TSI_GENCS_NSCN(0b00101), //!< 6 times per electrode
   TsiScanNumber_7  = TSI_GENCS_NSCN(0b00110), //!< 7 times per electrode
   TsiScanNumber_8  = TSI_GENCS_NSCN(0b00111), //!< 8 times per electrode
   TsiScanNumber_9  = TSI_GENCS_NSCN(0b01000), //!< 9 times per electrode
   TsiScanNumber_10 = TSI_GENCS_NSCN(0b01001), //!< 10 times per electrode
   TsiScanNumber_11 = TSI_GENCS_NSCN(0b01010), //!< 11 times per electrode
   TsiScanNumber_12 = TSI_GENCS_NSCN(0b01011), //!< 12 times per electrode
   TsiScanNumber_13 = TSI_GENCS_NSCN(0b01100), //!< 13 times per electrode
   TsiScanNumber_14 = TSI_GENCS_NSCN(0b01101), //!< 14 times per electrode
   TsiScanNumber_15 = TSI_GENCS_NSCN(0b01110), //!< 15 times per electrode
   TsiScanNumber_16 = TSI_GENCS_NSCN(0b01111), //!< 16 times per electrode
   TsiScanNumber_17 = TSI_GENCS_NSCN(0b10000), //!< 17 times per electrode
   TsiScanNumber_18 = TSI_GENCS_NSCN(0b10001), //!< 18 times per electrode
   TsiScanNumber_19 = TSI_GENCS_NSCN(0b10010), //!< 19 times per electrode
   TsiScanNumber_20 = TSI_GENCS_NSCN(0b10011), //!< 20 times per electrode
   TsiScanNumber_21 = TSI_GENCS_NSCN(0b10100), //!< 21 times per electrode
   TsiScanNumber_22 = TSI_GENCS_NSCN(0b10101), //!< 22 times per electrode
   TsiScanNumber_23 = TSI_GENCS_NSCN(0b10110), //!< 23 times per electrode
   TsiScanNumber_24 = TSI_GENCS_NSCN(0b10111), //!< 24 times per electrode
   TsiScanNumber_25 = TSI_GENCS_NSCN(0b11000), //!< 25 times per electrode
   TsiScanNumber_26 = TSI_GENCS_NSCN(0b11001), //!< 26 times per electrode
   TsiScanNumber_27 = TSI_GENCS_NSCN(0b11010), //!< 27 times per electrode
   TsiScanNumber_28 = TSI_GENCS_NSCN(0b11011), //!< 28 times per electrode
   TsiScanNumber_29 = TSI_GENCS_NSCN(0b11100), //!< 29 times per electrode
   TsiScanNumber_30 = TSI_GENCS_NSCN(0b11101), //!< 30 times per electrode
   TsiScanNumber_31 = TSI_GENCS_NSCN(0b11110), //!< 31 times per electrode
   TsiScanNumber_32 = TSI_GENCS_NSCN(0b11111), //!< 32 times per electrode
};

/**
 * Determines operation in low power modes (STOP, VLPS, LLS and VLLS{3,2,1}).
 */
enum TsiLowPower {
   TsiLowPower_Disabled = TSI_GENCS_STPE(0b0), //!< TSI is disabled in low power modes
   TsiLowPower_Enabled  = TSI_GENCS_STPE(0b1), //!< TSI is enabled in low power modes
};

/**
 * Determines if sources of electrode and reference oscillators are swapped
 */
enum TsiCurrentSource {
   TsiCurrentSource_NotSwapped = TSI_GENCS_CURSW(0b0), //!< Not swapped
   TsiCurrentSource_Swapped    = TSI_GENCS_CURSW(0b1), //!< Swapped
};

/**
 * Series resistor for noise mode (overlaps EXTCHRG[0])
 */
enum TsiSeriesResitor {
   TsiSeriesResitor_32k  = TSI_GENCS_RS(0),  //!< TSI Series resistor 32k
   TsiSeriesResitor_187k = TSI_GENCS_RS(1),  //!< TSI Series resistor 187k
};

/**
 * Noise filter bits (overlaps EXTCHRG[2:1])
 */
enum TsiNoiseFilter {
   TsiNoiseFilter_3Bits    = TSI_GENCS_FILTER(0b00), //!< TSI Noise filter 3 bits
   TsiNoiseFilter_2Bits    = TSI_GENCS_FILTER(0b01), //!< TSI Noise filter 2 bits
   TsiNoiseFilter_1Bits    = TSI_GENCS_FILTER(0b10), //!< TSI Noise filter 1 bits
   TsiNoiseFilter_Disabled = TSI_GENCS_FILTER(0b11), //!< TSI Noise filter disabled
};

/**
 * Type definition for TSI interrupt call back
 *
 *  @param status - Interrupt flags e.g. TSI_GENCS_EOSF_MASK, TSI_GENCS_OVRF_MASK, TSI_GENCS_EXTERF_MASK
 */
typedef void (*TSICallbackFunction)(uint8_t status);

class TsiBase {
public:
   /** Class to static check channel pin mapping is valid */
   template<class Info, int channel> class CheckSignal {
      static_assert((channel<Info::numSignals),
            "Non-existent TSI channel - Check Configure.usbdm for available channels");
      static_assert((channel>=Info::numSignals)||(Info::info[channel].gpioBit != UNMAPPED_PCR),
            "TSI channel is not mapped to a pin - Modify Configure.usbdm");
      static_assert((channel>=Info::numSignals)||(Info::info[channel].gpioBit != INVALID_PCR),
            "TSI channel doesn't exist in this device/package - Check Configure.usbdm for available channels");
      static_assert((channel>=Info::numSignals)||((Info::info[channel].gpioBit == UNMAPPED_PCR)||(Info::info[channel].gpioBit == INVALID_PCR)||(Info::info[channel].gpioBit >= 0)),
            "Illegal TSI Channel - Check Configure.usbdm for available channels");
   public:
      /** Dummy function to allow convenient in-line checking */
      static constexpr void check() {}
   };
};

/**
 * Template class representing a TSI interface
 *
 * @tparam Info      Information class describing the TSI interface
 */
template <class Info>
class TsiBase_T {

public:
   /** Hardware instance pointer */
   static constexpr HardwarePtr<TSI_Type> tsi = Info::baseAddress;

   /**
    * Enable TSI\n
    * Configures all TSI pins
    */
   static void enable() {
      Info::enableClock();
      __DMB();

      Info::initPCRs();
   }

   /**
    * Initialise TSI to default settings\n
    * Configures all TSI pins
    */
   static void defaultConfigure() {
      enable();

      tsi->GENCS  = Info::tsi_gencs|TSI_GENCS_TSIEN_MASK;
      tsi->TSHD   = Info::tsi_tshd;

      enableNvicInterrupts(Info::irqLevel);
   }

   /**
    * Enable interrupts in NVIC
    */
   static void enableNvicInterrupts() {
      NVIC_EnableIRQ(Info::irqNums[0]);
   }

   /**
    * Enable and set priority of interrupts in NVIC
    * Any pending NVIC interrupts are first cleared.
    *
    * @param[in]  nvicPriority  Interrupt priority
    */
   static void enableNvicInterrupts(NvicPriority nvicPriority) {
      enableNvicInterrupt(Info::irqNums[0], nvicPriority);
   }

   /**
    * Disable interrupts in NVIC
    */
   static void disableNvicInterrupts() {
      NVIC_DisableIRQ(Info::irqNums[0]);
   }

   /**
    * Enables and configure the TSI for TsiMode_Capacitive
    *
    * @param tsiLowPower            Determines operation in low power modes (STOP, VLPS, LLS and VLLS{3,2,1})
    * @param tsiScanNumber          Determines the number of scans when measuring an electrode
    * @param tsiElectrodePrescaler  Determines the prescaler for the output of the electrode oscillator
    * @param tsiReferenceCharge     Determines the reference oscillator charge and discharge current value
    * @param tsiExternalCharge      Determines the electrode oscillator charge and discharge current value
    * @param tsiDeltaVoltage        Determine the oscillators' voltage limits (not applicable in noise modes)
    */
   static void configure(
         TsiLowPower             tsiLowPower           = TsiLowPower_Disabled,
         TsiScanNumber           tsiScanNumber         = TsiScanNumber_8,
         TsiElectrodePrescaler   tsiElectrodePrescaler = TsiElectrodePrescaler_8,
         TsiReferenceCharge      tsiReferenceCharge    = TsiReferenceCharge_8uA,
         TsiExternalCharge       tsiExternalCharge     = TsiExternalCharge_8uA,
         TsiDeltaVoltage         tsiDeltaVoltage       = TsiDeltaVoltage_High) {

      enable();
      tsi->GENCS =
            TSI_GENCS_TSIEN(1)|TsiMode_Capacitive|
            tsiLowPower|tsiScanNumber|
            tsiReferenceCharge|tsiExternalCharge|
            tsiDeltaVoltage|tsiElectrodePrescaler|TsiCurrentSource_NotSwapped;
   }

   /**
    * Enables and configure the TSI for Noise measurement mode
    *
    * @param tsiMode                Determines the TSI analogue mode (must be one of TsiMode_NoiseDetect_...)
    * @param tsiSeriesResitor       Determines the series resistor for noise mode (overlaps EXTCHRG[0])
    * @param tsiNoiseFilter         Determines the noise filter bits (overlaps EXTCHRG[2:1])
    * @param tsiLowPower            Determines operation in low power modes (STOP, VLPS, LLS and VLLS{3,2,1})
    * @param tsiScanNumber          Determines the number of scans when measuring an electrode
    * @param tsiElectrodePrescaler  Determines the prescaler for the output of the electrode oscillator
    * @param tsiReferenceCharge     Determines the reference oscillator charge and discharge current value
    * @param tsiDeltaVoltage        Determine the oscillators' voltage limits (not applicable in noise modes)
    */
   static void configure(
         TsiMode                 tsiMode,
         TsiSeriesResitor        tsiSeriesResitor      = TsiSeriesResitor_32k,
         TsiNoiseFilter          tsiNoiseFilter        = TsiNoiseFilter_Disabled,
         TsiLowPower             tsiLowPower           = TsiLowPower_Disabled,
         TsiScanNumber           tsiScanNumber         = TsiScanNumber_8,
         TsiElectrodePrescaler   tsiElectrodePrescaler = TsiElectrodePrescaler_8,
         TsiReferenceCharge      tsiReferenceCharge    = TsiReferenceCharge_8uA,
         TsiDeltaVoltage         tsiDeltaVoltage       = TsiDeltaVoltage_High) {

      usbdm_assert(tsiMode != TsiMode_Capacitive, "Wrong mode for this configuration ");
      enable();
      tsi->GENCS =
            TSI_GENCS_TSIEN(1)|
            tsiMode|tsiSeriesResitor|tsiNoiseFilter|
            tsiLowPower|tsiScanNumber|
            tsiReferenceCharge|
            tsiDeltaVoltage|tsiElectrodePrescaler|TsiCurrentSource_NotSwapped;
   }

   /**
    * Sets the Current Source swap option.\n
    * Assumes the TSI has already been enabled.
    *
    * @param tsiCurrentSource    Determines if sources of electrode and reference oscillators are swapped
    */
   static void setCurentSources(TsiCurrentSource tsiCurrentSource) {
      tsi->GENCS = (tsi->GENCS&~(TSI_GENCS_CURSW_MASK)) | tsiCurrentSource;
   }

   /**
    * Configures the measurement and reference oscillators.\n
    * Assumes the TSI has already been enabled.
    *
    * @param tsiReferenceCharge  Determines the reference oscillator charge and discharge current value
    * @param tsiExternalCharge   Determines the electrode oscillator charge and discharge current value
    * @param tsiDeltaVoltage     Determine the oscillators' voltage limits (not applicable in noise modes)
    */
   static void configureOscillators(
         TsiReferenceCharge      tsiReferenceCharge    = TsiReferenceCharge_8uA,
         TsiExternalCharge       tsiExternalCharge     = TsiExternalCharge_8uA,
         TsiDeltaVoltage         tsiDeltaVoltage       = TsiDeltaVoltage_High) {

      tsi->GENCS =
            (tsi->GENCS&~(TSI_GENCS_REFCHRG_MASK|TSI_GENCS_EXTCHRG_MASK|TSI_GENCS_DVOLT_MASK|TSI_GENCS_CURSW_MASK)) |
            tsiReferenceCharge|tsiExternalCharge|tsiDeltaVoltage;
   }

   /**
    * Configures TSI counting operation
    *
    * @param tsiScanNumber          Determines the number of scans when measuring an electrode
    * @param tsiElectrodePrescaler  Determines the prescaler for the output of the electrode oscillator
    */
   static void configureCounting(
         TsiScanNumber           tsiScanNumber         = TsiScanNumber_8,
         TsiElectrodePrescaler   tsiElectrodePrescaler = TsiElectrodePrescaler_8) {
      enable();
      tsi->GENCS =
            (tsi->GENCS&~(TSI_GENCS_NSCN_MASK|TSI_GENCS_PS_MASK)) |
            tsiScanNumber|tsiElectrodePrescaler;
   }

   /**
    * Disables or selects touch sensing Interrupt/DMA source
    *
    * @param tsiInterrupt Interrupt source
    */
   static void selectTsiInterrupt(TsiInterrupt tsiInterrupt) {
      tsi->GENCS = (tsi->GENCS&~TSI_GENCS_TSIIEN_MASK)|tsiInterrupt;
   }

   /**
    * Get channel count value
    *
    * @return 16-bit count value
    */
   static uint16_t getCount() {
      return Info::tsi->DATA&TSI_DATA_TSICNT_MASK;
   }

   /**
    * Start configured scan on channel
    *
    * @param channel Channel number
    */
   static void startScan(int channel) {
      // Clear flags
      Info::tsi->GENCS |= TSI_GENCS_OUTRGF_MASK|TSI_GENCS_EOSF_MASK;
      // Start scan
      Info::tsi->DATA = TSI_DATA_SWTS_MASK|TSI_DATA_TSICH(channel);
   }

   /**
    * Start configured scan on channel with DMA request
    *
    * @param channel Channel number
    */
   static void startDmaScan(int channel) {
      // Clear flags
      Info::tsi->GENCS |= TSI_GENCS_OUTRGF_MASK|TSI_GENCS_EOSF_MASK;
      // Select event of end of scan
      Info::tsi->GENCS |= TSI_GENCS_ESOR(1)|TSI_GENCS_TSIIEN(1);
      // Start scan
      Info::tsi->DATA = TSI_DATA_SWTS_MASK|TSI_DATA_DMAEN_MASK|TSI_DATA_TSICH(channel);
   }

   /**
    * Start configured scan and wait for completion
    *
    * @param channel Channel number
    *
    * @return Error code indicating if scan was successful
    */
   static void startScanAndWait(int channel) {
      // Clear flags
      Info::tsi->GENCS |= TSI_GENCS_OUTRGF_MASK|TSI_GENCS_EOSF_MASK;
      // Start scan
      Info::tsi->DATA = TSI_DATA_SWTS_MASK|TSI_DATA_TSICH(channel);

      // Wait for complete flag or err
      while ((Info::tsi->GENCS&(TSI_GENCS_EOSF_MASK)) == 0) {
      }
   }

   /**
    * Set range thresholds
    *
    * @param high High threshold
    * @param low  Low threshold
    */
   static void setThresholds(uint16_t high, uint16_t low) {
      tsi->TSHD = TSI_TSHD_THRESH(high)|TSI_TSHD_THRESL(low);
   }
};

/**
 * Template class to provide TSI callback
 *
 * @tparam Info      Information class describing the TSI interface
 */
template<class Info>
class TsiIrq_T : public TsiBase_T<Info> {

protected:
   /** Callback function for ISR */
   static TSICallbackFunction callback;

public:
   /**
    * IRQ handler
    */
   static void irqHandler(void) {
      uint8_t status = TsiBase_T<Info>::tsi->GENCS&(TSI_GENCS_OUTRGF_MASK|TSI_GENCS_EOSF_MASK);
      if (callback != 0) {
         TsiBase_T<Info>::tsi->GENCS |= status;
         callback(status);
      }
   }

   /**
    * Set Callback function
    *
    *   @param theCallback - Callback function to be executed on TSI alarm interrupt
    */
   static void setCallback(TSICallbackFunction theCallback) {
      callback = theCallback;
   }
};

/**
 * Class representing a TSI button
 *
 * @tparam Info      Information class describing the TSI interface
 * @tparam channel   Channel connected to the button
 * @tparam threshold Threshold for the button to be considered pressed
 */
template<class Info, int channel, int threshold>
class TsiButton_T : public USBDM::TsiIrq_T<Info> {

   TsiBase::CheckSignal<Info, channel> check;

public:
   using Pcr = PcrTable_T<Info, channel>;

   /**
    * Configure the pin associated with this TSI channel.
    * The pin is in analogue mode so no PCR settings are active.
    * This function is of use if mapAllPins and mapAllPinsOnEnable are not selected in USBDM configuration.
    */
   static void setInput() {
      // Map pin to ADC
      Pcr::setPCR(Info::info[channel].pcrValue);
   }

   /**
    * Poll button \n
    * This triggers a scan of the button and compares the result to the threshold.
    *
    * @return true => pressed, false => not pressed
    */
   static bool poll() {
      TsiIrq_T<Info>::startScanAndWait(channel);
      return TsiIrq_T<Info>::getCount()>threshold;
   }

   /**
    * Start configured scan and wait for completion
    *
    * @return Error code indicating if scan was successful
    */
   static void startScanAndWait() {
      TsiIrq_T<Info>::startScanAndWait(channel);
   }
   /**
    * Get channel count value from last scan
    *
    * @return 16-bit count value
    */
   static uint16_t getCount() {
      return Info::tsi->DATA&TSI_DATA_TSICNT_MASK;
   }
};

/**
 * Class representing a TSI slider
 *
 * @tparam Info      Information class describing the TSI interface
 * @tparam channel1  First channel connected to slider
 * @tparam channel2  Second channel connected to slider
 * @tparam threshold Threshold for the contact to be considered
 */
template<class Info, int channel1, int channel2, int threshold>
class TsiSlider_T : public USBDM::TsiIrq_T<Info> {

public:
   static int measure() {
      TsiIrq_T<Info>::startScanAndWait(channel1);
      int value1 = TsiIrq_T<Info>::getCount();
      TsiIrq_T<Info>::startScanAndWait(channel2);
      int value2 = TsiIrq_T<Info>::getCount();

      return 0; //TODO ???
   }
};

template<class Info> TSICallbackFunction TsiIrq_T<Info>::callback = 0;

#ifdef USBDM_TSI_IS_DEFINED
/**
 * Class representing TSI
 */
using Tsi = TsiIrq_T<TsiInfo>;


/**
 * Class representing TSI button
 *
 * @tparam channel   Channel connected to the button
 * @tparam threshold Threshold for the button to be considered pressed
 */
template<int channel, int threshold>
using Tsi0Button = TsiButton_T<TsiInfo, channel, threshold>;

#endif

#ifdef USBDM_TSI0_IS_DEFINED
/**
 * Class representing TSI
 */
using Tsi0 = TsiIrq_T<Tsi0Info>;

/**
 * Class representing TSI button
 *
 * @tparam channel   Channel connected to the button
 * @tparam threshold Threshold for the button to be considered pressed
 */
template<int channel, int threshold>
using Tsi0Button = TsiButton_T<Tsi0Info, channel, threshold>;

#endif

} // End namespace USBDM

#endif /* TSI_H_ */
