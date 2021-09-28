/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "cmp.h"
#include "llwu.h"
#include "dac.h"
#include "ewm.h"
#include "i2c.h"
#include "lpuart.h"
#include "osc.h"
#include "spi.h"
#include "vref.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

/**
 * See more examples in Snippets directory
 */
class ACallbackClass {
public:
   int y;

   // Member function used as callback
   // This function must match PinCallbackFunction
   void callback(uint32_t) {

   }
};
// Instance of class containing callback member function
__attribute__((unused))
static ACallbackClass aCallbackClass;

/**
 * Call-back for direct pin interrupt
 *
 * @param[in] status 32-bit value from ISFR (each bit indicates a pin interrupt source)
 */
__attribute__((unused))
static void pinCallback(uint32_t status __attribute__((unused))) { // @suppress("Unused static function")
   usbdm_assert(status & (Llwu::Pin<LlwuPin_Ptd4>::BITMASK), "Unexpected pin interrupt");

}

// LED connection - change as required
using Led   = GpioA<1,ActiveLow>;

int main() {
   console.writeln("Starting\n");
   console.write("SystemCoreClock = ").writeln(SystemCoreClock);
   console.write("SystemBusClock  = ").writeln(SystemBusClock);

#if 0
   Led::setOutput();
   Led::setOutput(0);
   Led::setPinCallback(pinCallback);
   GpioCField<1,0>::setPinCallback(pinCallback);
   auto gpioFieldPinCallback = GpioCField<1,0>::wrapCallback<ACallbackClass, &ACallbackClass::callback>(aCallbackClass);
   GpioCField<1,0>::setPinCallback(gpioFieldPinCallback);
   GpioCField<1,0>::disableNvicInterrupts();
   GpioCField<1,0>::disablePins();
   Llwu::Pin<LlwuPin_Ptd2>::setInput(PinPull_Up, PinAction_None, PinFilter_None);
   Llwu::Pin<LlwuPin_Ptd2>::setPinCallback(pinCallback);
   Ftm0::Channel<1>::setOutput();
   Ftm0::Channel<1>::setPinCallback(pinCallback);
   Ftm0::Channel<1>::setPinAction(PinAction_DmaEither);
   Ftm0::Channel<1>::setPinSlewRate(PinSlewRate_Slow);
   Ftm0::Channel<1>::setInput(PinPull_Up, PinAction_None, PinFilter_Passive);
   auto ftmPinCallback = Ftm0::Channel<1>::wrapCallback<ACallbackClass, &ACallbackClass::callback>(aCallbackClass);
   Ftm0::Channel<1>::setPinCallback(ftmPinCallback);
   Ftm0::Channel<1>::setPinMux(PinMux_Disabled);
   Ftm0::Channel<1>::setInput();
#endif

#if 0   // FTM checks
   // Channel existence checks
   Ftm0::Channel<-1>::configure(FtmChMode_Disabled);     // Fail - Illegal FTM channel
   Ftm0::Channel<100>::configure(FtmChMode_Disabled);    // Fail - Illegal FTM channel
   Ftm0::Channel<1>::configure(FtmChMode_Disabled);      // OK - Channel exists and mapped to pin
   Ftm0::Channel<3>::configure(FtmChMode_Disabled);      // OK - Channel exists but not mapped to pin

   // Channel pin mapping checks
   Ftm0::Channel<-1>::setInput();   // OK but Illegal FTM channel (Assumed flags elsewhere)
   Ftm0::Channel<100>::setInput();  // OK but Illegal FTM channel (Assumed flags elsewhere)
   Ftm0::Channel<1>::setInput();    // OK - Channel exists and mapped to pin
   Ftm0::Channel<3>::setInput();    // Fail - Channel exists but not mapped to pin
#endif
#if 0 // FTM QUAD checks

   FtmQuadDecoder1::Pcr0::setPinCallback(pinCallback);   // OK
   FtmQuadDecoder1::Pcr1::setPinCallback(pinCallback);   // OK
   FtmQuadDecoder1::configure(); // OK
   FtmQuadDecoder1::setInput();  // OK

   FtmQuadDecoder2::Pcr0::setPinCallback(pinCallback); // Fail - Gpio not configured for interrupts
   FtmQuadDecoder2::Pcr1::setPinCallback(pinCallback); // Fail - Gpio not configured for interrupts
   FtmQuadDecoder2::configure(); // Fail - PHx is not mapped to a pin

#endif

#if 0 // CMP checks
   Cmp0::configure(CmpPower_HighSpeed, CmpHysteresis_0, CmpPolarity_Inverted);
   Cmp0::Pin<Cmp0Input_Ptc6>::setInput();
   Cmp0::Pin<(Cmp0Input)-1>::setInput();
   Cmp0::Pin<(Cmp0Input)100>::setInput();
   Cmp0::Pin<(Cmp0Input)3>::setInput();

   Cmp0::setOutput();
#endif

#if 0
   Adc0::Channel<0>::setInput();    // OK (not mappable)
   Adc0::Channel<12>::setInput();   // OK (mapped)
   Adc0::Channel<4>::setInput();    // Fail - ADC channel is not mapped to a pin
   Adc0::Channel<20>::setInput();   // Fail - Non-existent ADC channel
   Adc0::Channel<-1>::setInput();   // Fail - Non-existent ADC channel
   Adc0::Channel<100>::setInput();  // Fail - Non-existent ADC channel

   Adc0::DiffChannel<0>::setInput();    // OK (not mappable)
   Adc0::DiffChannel<16>::setInput();   // Fail - Non-existent ADC channel
   Adc0::DiffChannel<-1>::setInput();   // Fail - Non-existent ADC channel
   Adc0::DiffChannel<100>::setInput();  // Fail - Non-existent ADC channel
#endif

#if 0
   Dac0::setOutput();   // OK
   Dac1::setOutput();   // Fail - Not mapped
#endif

#if 0
   Ewm::setInput();   // OK
   Ewm::setOutput();  // OK
#endif

#if 0
   I2c0 i2c0{};   // OK
   I2c1 i2c1{};   // Fail
#endif

#if 0
   Lpuart0 lpUart0{}; // OK
#endif

#if 0
   Uart0 uart0{}; // Fail
   Uart1 uart1{}; // OK
#endif

#if 0
   Osc0::configureAllPins(); // OK
#endif

#if 0
   Spi0 spi0{}
   Spi1 spi1{};
#endif

#if 0
   Vref::configure();
#endif

   GpioA<0>::setInput();

   for(int count = 0;;count++) {
      Led::toggle();
      waitMS(100);
      console.write(count).writeln(": Tick...");
   }
   return 0;
}
