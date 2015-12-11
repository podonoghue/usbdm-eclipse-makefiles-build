/****************************************************************************************************//**
 * @file     gps.h (derived from gps-MKL.h)
 *
 * @brief    Abstraction layer for Global Positioning System interface
 *
 * @version  V1.0
 * @date     2015/11
 *
 *******************************************************************************************************/

#ifndef INCLUDE_USBDM_GPS_H_
#define INCLUDE_USBDM_GPS_H_

#include "derivative.h"
#include "gpio.h"
#include "clock_configure.h"

namespace USBDM {

extern "C" void UART0_IRQHandler();
extern "C" void UART1_IRQHandler();
extern "C" void UART2_IRQHandler();
extern "C" void UART3_IRQHandler();

/**
 * @addtogroup GPS_Group Global Positioning System
 * @brief C++ Class allowing access to serial GPS module
 * @{
 */

/**
 * @brief Base class for interface to a GPS receiver
 *
 * Provides the information from the Global Positioning System Fixed Data (GPGGA) message
 *
 * e.g. $GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E
 *
 * <b>Example</b>
 * @code
 * // Instantiate interface
 *	USBDM::Gps *gps = new USBDM::Gps2();
 *
 * for(;;) {
 *    USBDM::Gps::GpsData gpsData;
 *    if (gps->getGpsData(gpsData)) {
 *       USBDM::Gps::report(gpsData);
 *    }
 * }
 * @endcode
 */
class Gps {

   /** Allows access from UART ISR */
   friend void UART0_IRQHandler();
   /** Allows access from UART ISR */
   friend void UART1_IRQHandler();
   /** Allows access from UART ISR */
   friend void UART2_IRQHandler();
   /** Allows access from UART ISR */
   friend void UART3_IRQHandler();

public:
   /**
    * Struct containing the GPGGA information
    */
   struct GpsData {
      double  utcTime;           //!< UTC time e.g. 2153.000
      double  latitude;          //!< Latitude e.g. 3750.0871
      char    n_s_Indicator;     //!< Latitude direction indicator (N/S)
      double  longitude;         //!< Longitude e.g. 14507.1126
      char    e_w_Indicator;     //!< Longitude direction indicator (E/W)
      int     fixIndicator;      //!< 0=>no fix, 1=>GPS SPS mode
      int     satCount;          //!< Count of satellites used
      double  altitude;          //!< Altitude e.g. 93.1
      char    altitudeUnits;     //!< Altitude units (M)
      double  hdop;              //!< Horizontal Dilution of Precision e.g. 1.1
      double  geoid;             //!< Geoid-to-ellipsoid separation e.g. -3.9
      char    geoidUnits;        //!< Altitude units (M)
   };

protected:
   enum State {
      S_idle,
      S_id, S_number, S_numberFraction, S_units, S_string,
      S_utcTime,
      S_gpggaLatitude, S_gpggaLatitudeNS,
      S_gpggaLongitude, S_gpggaLongitudeEW,
      S_fixIndicator,
      S_satelliteCount,
      S_hdop,
      S_altitude,
      S_altitudeUnits,
      S_geod,
      S_geodUnits,
   };

   UART_Type  *uart;
   uint32_t    uartClockFrequency;

   State       state;
   State       pushState;
   uint8_t     bufferIndex;
   int         integer;
   int         decimalCount;
   double      number;
   int         numberSign;
   bool        newData;
   GpsData     gpsData;

   /**
    * Constructor for GPS interface
    *
    * @param uart               Pointer to UART hardware
    * @param uartClockFrequency Clock frequency use for UART hardware
    *
    */
   Gps(UART_Type *uart, uint32_t uartClockFrequency) : uart(uart), uartClockFrequency(uartClockFrequency), state(S_idle), pushState(S_idle) {
   }
   /**
    * Start parsing a number
    */
   void startNumber(State pushState);
   /**
    * Start parsing a unit e.g. K,N,S,E,W
    */
   void startUnits(State pushState);
   /**
    * Start parsing a string of characters
    */
   void startString(State pushState);
   /**
    * State machine to process received GPS data
    */
   void stateMachine(char ch);
   /**
    * Initialise the UART to default settings
    */
   virtual void initUart() = 0;
   /**
    * Transmits a single character over the UART (blocking)
    *
    * @param ch - character to send
    */
   virtual void putChar(int ch);

public:
   /**
    * Get last GPS reported location
    *
    * @param gpsData Data structure for returned GPS data
    *
    * @return false => No new data available (gpsData unchanged)
    */
   virtual bool getGpsData(GpsData &gpsData) = 0;
   /**
    * Prints GPS data to stdout (for debug)
    *
    * @param gpsData GPS Data to be reported
    */
   static  void report(Gps::GpsData &gpsData);
   /**
    * Sets the baud rate of the UART communication to the GPS
    *
    * @param baudrate - the baud rate to use e.g. 9600
    */
   virtual void setBaud(int baudrate = 9600);
   /**
    * Send message to GPS
    *
    * @param command Command to send
    */
   void sendCommand(const char *command) {
      while (*command != '\0') {
         putChar(*command++);
      }
   }
};

#ifdef UART0_RX_GPIO
/**
 * @brief Class interfacing to a GPS receiver connected to UART0
 *
 * Provides the information from the Global Positioning System Fixed Data (GPGGA) message
 *
 * e.g. $GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E
 *
 * <b>Example</b>
 * @code
 * // Instantiate interface
 * USBDM::Gps *gps = new USBDM::Gps0();
 *
 * for(;;) {
 *    USBDM::Gps::GpsData gpsData;
 *    if (gps->getGpsData(gpsData)) {
 *       USBDM::Gps::report(gpsData);
 *    }
 * }
 * @endcode
 */
class Gps0 : public Gps {

   /** Allows access from UART ISR */
   friend void UART0_IRQHandler();

protected:
   /** Used by ISR to obtain handle of object */
   static Gps *thisPtr;

public:
   /**
    * Initialise the UART to default settings
    */
   virtual void initUart();

   /**
    * Create GPS interface
    */
   Gps0() : Gps((UART_Type *)UART1, SYSTEM_UART0_CLOCK) {
      thisPtr = this;
      initUart();
   }
   /**
    * Get last GPS reported location
    *
    * @param gpsData Data structure for returned GPS data
    *
    * @return false => No new data available (gpsData unchanged)
    */
   virtual bool getGpsData(GpsData &gpsData) {
      if (!newData) {
         return false;
      }
      NVIC_DisableIRQ(UART0_IRQn);
      gpsData = Gps::gpsData;
      newData = false;
      NVIC_EnableIRQ(UART0_IRQn);
      return true;
   }
};
#endif

#ifdef UART1_RX_GPIO
/**
 * @brief Class interfacing to a GPS receiver connected to UART1
 *
 * Provides the information from the Global Positioning System Fixed Data (GPGGA) message
 *
 * e.g. $GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E
 *
 * <b>Example</b>
 * @code
 * // Instantiate interface
 * USBDM::Gps *gps = new USBDM::Gps1();
 *
 * for(;;) {
 *    USBDM::Gps::GpsData gpsData;
 *    if (gps->getGpsData(gpsData)) {
 *       USBDM::Gps::report(gpsData);
 *    }
 * }
 * @endcode
 */
class Gps1 : public Gps {

   /** Allows access from UART ISR */
   friend void UART1_IRQHandler();

protected:
   /** Used by ISR to obtain handle of object */
   static Gps *thisPtr;

public:
   /**
    * Initialise the UART to default settings
    */
   virtual void initUart();

   /**
    * Create GPS interface
    */
   Gps1() : Gps((UART_Type *)UART1, SYSTEM_UART1_CLOCK) {
      thisPtr = this;
      initUart();
   }
   /**
    * Get last GPS reported location
    *
    * @param gpsData Data structure for returned GPS data
    *
    * @return false => No new data available (gpsData unchanged)
    */
   virtual bool getGpsData(GpsData &gpsData) {
      if (!newData) {
         return false;
      }
      NVIC_DisableIRQ(UART1_IRQn);
      gpsData = Gps::gpsData;
      newData = false;
      NVIC_EnableIRQ(UART1_IRQn);
      return true;
   }
};
#endif

#ifdef UART2_RX_GPIO
/**
 * @brief Class interfacing to a GPS receiver connected to UART2
 *
 * Provides the information from the Global Positioning System Fixed Data (GPGGA) message
 *
 * e.g. $GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E
 *
 * <b>Example</b>
 * @code
 * // Instantiate interface
 * USBDM::Gps *gps = new USBDM::Gps2();
 *
 * for(;;) {
 *    USBDM::Gps::GpsData gpsData;
 *    if (gps->getGpsData(gpsData)) {
 *       USBDM::Gps::report(gpsData);
 *    }
 * }
 * @endcode
 */
class Gps2 : public Gps {

   /** Allows access from UART ISR */
   friend void UART2_IRQHandler();

protected:
   /** Used by ISR to obtain handle of object */
   static Gps *thisPtr;

public:
   /**
    * Initialise the UART to default settings
    */
   virtual void initUart();

   /**
    * Create GPS interface
    */
   Gps2() : Gps((UART_Type *)UART2, SYSTEM_UART2_CLOCK) {
      thisPtr = this;
      initUart();
   }
   /**
    * Get last GPS reported location
    *
    * @param gpsData Data structure for returned GPS data
    *
    * @return false => No new data available (gpsData unchanged)
    */
   virtual bool getGpsData(GpsData &gpsData) {
      if (!newData) {
         return false;
      }
      NVIC_DisableIRQ(UART2_IRQn);
      gpsData = Gps::gpsData;
      newData = false;
      NVIC_EnableIRQ(UART2_IRQn);
      return true;
   }
};
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_GPS_H_ */
