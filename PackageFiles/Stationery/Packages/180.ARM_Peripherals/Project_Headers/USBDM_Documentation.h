/**
 * @file     USBDM_Documentation.h
 * @brief    USBDM Documentation
 */
 
 /**

 @mainpage USBDM Overview

 The classes in the USBDM namespace provide C++ wrappers for the microcontroller hardware. \n

\tableofcontents
Table of Contents
 - \ref PinSummary  \n
 - \ref GPIOExamples \n
 - \ref ADCExamples \n
 - \ref FTMExamples \n
 - \ref PITExamples \n
 
 @page GPIOExamples  General Purpose Input Output

Convenience template for GPIO pins. Based on USBDM::GpioBase_T  \n
This template is an interface for the general purpose I/O pin hardware. \n

It provides:\n
- Static pin mapping in conjunction with the configuration settings.
- Setting pin characteristics e.g. pull-ups, drive strength etc
- Changing the pin direction
- Setting outputs to high or low level
- Polling input value
- Polarity (\ref USBDM::ActiveHigh or \ref USBDM::ActiveLow) is selected when instantiated

 <b>Usage</b>
 @code
   using namespace USBDM;

   // Temporary for input values
   bool x;

   // Instantiate for bit 3 of GpioC as active-high signal
   GpioC<3, ActiveHigh> GpioC3;

   // Set as digital output
   GpioC3.setOutput();
   // Or for more detailed control
   GpioC3.setOutput(pcrValue(PinPullUp, PinDriveHigh, PinOpenCollector));

   // Set pin (polarity is applied)
   GpioC3.set();

   // Clear pin (polarity is applied)
   GpioC3.clear();

   // Set pin to a high level (polarity is ignored)
   GpioC3.high();

   // Set pin to a low level (polarity is ignored)
   GpioC3.low();

   // Toggle pin
   GpioC3.toggle();

   // Set pin to boolean value (polarity is applied)
   GpioC3.write(true);

   // Set pin to boolean value (polarity is applied)
   GpioC3.write(false);

   // Enable pull-up
   GpioC3.setPullDevice(PinPullUp);

   // Set drive strength
   GpioC3.setDriveStrength(PinDriveHigh);

   // Set open-drain
   GpioC3.setDriveMode(PinOpenDrain);

   // Read pin as boolean value (polarity is applied)
   // This may be useful if the pin is open-drain
   x = GpioC3.read();

   // Read _state_ of pin drive as boolean value (polarity is applied)
   // This may be useful if the pin is open-drain
   GpioC3.setDriveMode(PinOpenDrain);
   GpioC3.high();
   if (GpioC3.readState() != GpioC3.read()) {
      printf("Open-drain pin is being held low\n");
   }

   // Dynamically set pin as input
   GpioC3.setIn();

   // Read pin as boolean value (polarity is applied)
   x = GpioC3.read();

   // Read pin as boolean value (polarity is ignored)
   x = GpioC3.isHigh();

   // Read pin as boolean value (polarity is ignored)
   x = GpioC3.isLow();
 @endcode

@page ADCExamples Analogue-to-Digital

Convenience template for ADC inputs. Based on USBDM::AdcBase_T  \n
This template is an interface for the ADC input pins. \n

It provides:\n
- Static pin mapping in conjunction with the configuration settings. (Some ADC pins have fixed mapping.)
- Setting the resolution in bits
- Setting the conversion parameters e.g. averaging
- Clock and conversion speed are done through the configuration.
- Interrupt driven operation is also supported through a callback if enabled in the configuration.

 <b>Usage</b>
 @code
   using namespace USBDM;

   // Instantiate an ADC input (for ADC0 channel 6)
   using Adc0_ch6 = USBDM::Adc0Channel<6>;

   // Set ADC resolution to 16 bits
   Adc0_ch6::setResolution(resolution_16bit_se);

   // Set ADC averaging to 4 samples
   Adc0_ch6::setAveraging(averaging_4);

   // Read ADC value
   uint32_t value = Adc0_ch6::readAnalogue();

   printf("ADC measurement = %lu\n", value);
 @endcode

 <b>Usage</b>
 @code
   using namespace USBDM;

   // Instantiate an ADC input for differential channel 0 (ADC_DM0, ADC_DP0)
   using Adc1_diff0 = USBDM::Adc0DiffChannel<0>;

   // Set ADC resolution to 11 bits differential
   Adc1_diff0::setResolution(resolution_11bit_diff);

   // Set ADC averaging to 4 samples
   Adc1_diff0::setAveraging(averaging_4);

   // Read signed differential ADC value
   int32_t value = Adc1_diff0::readAnalogue();

   printf("ADC measurement = %ld\n", value);
 @endcode

@page FTMExamples Flexible Timer Module

Convenience template for FTM hardware.
The interface is divided into a number of templates:
- USBDM::FtmBase_T Representing the shared FTM functionality.
- USBDM::QuadEncoder_T Representing a FTM operating as a quadrature encoder.
- USBDM::FtmChannel_T Representing individual channels of a single FTM.

It provides:\n
- Static pin mapping in conjunction with the configuration settings.
- Setting the FTM period in ticks or seconds
- Setting the channel duty cycle in percentage
- Interrupt driven operation is also supported through a callback if enabled in the configuration.

 <b>Usage - PWM</b>
@code
   using namespace USBDM;

   // Initialise the timer with initial period in ticks and alignment
   // The tick rate is determined by the configuration
   // This affects all channels of the FTM
   Ftm0::configure(200, USBDM::ftm_leftAlign);

   // Set timer period in ticks
   // This affects all channels of the FTM
   // Timer pre-scaler is not changed
   Ftm0::setPeriodInTicks(500);

   // Set timer period in microseconds
   // This affects all channels of the FTM
   // Timer pre-scaler (tick rate) will be adjusted to accommodate the required period
   Ftm0::setPeriod(125*us);

   // Use FTM0 channel 3
   using Ftm0Channel3 = Ftm0Channel<3> ;

   // Set channel to generate PWM with active-high pulses
   Ftm0Channel3::enable(ftm_pwmHighTruePulses);

   // Set duty cycle as percentage
   Ftm0Channel3::setDutyCycle(34);

   // Set duty cycle as percentage (float)
   Ftm0Channel3::setDutyCycle(12.25f);

   // Set high time in microseconds (float)
   Ftm0Channel3::setHighTime(63*us);
@endcode

 <b>Usage - Quadrature Encoder</b>
@code
   using namespace USBDM;

   // Use FTM1 as the quadrature encoder
   // Not all FTMs support this mode
   using QuadEncoder = QuadEncoder1;

   // Enable encoder
   QuadEncoder::enable();

   // Set pin filters
   QuadEncoder::enableFilter(15);

   // Reset position to zero
   // Movement will be relative to this value
   QuadEncoder::resetPosition();

   // Set up callback for quadrature overflow or underflow
   QuadEncoder::setTimerOverflowCallback(callBack);
   QuadEncoder::enableTimerOverflowInterrupts();
   QuadEncoder::enableNvicInterrupts();

   for (;;) {
      // Report position
      printf("Shaft position = %d\n\r", QuadEncoder::getPosition());
   }
@endcode

@page PITExamples Programmable Interrupt Timer Module

Convenience template for PIT hardware USBDM::Pit_T.

It provides:\n
- Static pin mapping in conjunction with the configuration settings.
- Setting the PIT channel period in seconds
- Accurate busy-wait delays using a timer channel
- Interrupt driven operation is also supported through a callback if enabled in the configuration.

 <b>Usage - PIT busy-wait</b>
@code
   using namespace USBDM;

   // LED is assumed active-low
   using LED = USBDM::GpioA<2, USBDM::ActiveLow>;

   // Use high drive for LED
   LED::setOutput(pcrValue(PinPullNone, PinDriveHigh));

   // Enable PIT
   Pit::enable();

   // Check for errors so far
   checkError();

   for(;;) {
      LED::toggle();

      // Delay in milliseconds using channel 0
      Pit::delay(0, 1000*ms);
   }
@endcode

@example analogue-diff-example.cpp
@example analogue-interrupt-example.cpp
@example analogue-joystick-example.cpp
@example cmp.cpp
@example digital-example1.cpp
@example digital-example2.cpp
@example flash_programming_example.cpp
@example ftm-pwm-example.cpp
@example ftm-quadrature-example.cpp
@example ftm-servo-example.cpp
@example fxos8700cq-example.cpp
@example fxos8700cq.cpp
@example fxos8700cq.h
@example hmc5883l-example.cpp
@example hmc5883l.cpp
@example hmc5883l.h
@example llwu-example.cpp
@example lptmr-example.cpp
@example mag3310-example.cpp
@example mag3310.cpp
@example mag3310.h
@example mma845x-example.cpp
@example mma845x.cpp
@example mma845x.h
@example mma8491q-example.cpp
@example mma8491q.cpp
@example mma8491q.h
@example nonvolatile_example.cpp
@example pca9685-example.cpp
@example pca9685.cpp
@example pca9685.h
@example pit-example1.cpp
@example pit-example2.cpp
@example rtc-example.cpp
@example test-mcg.cpp
@example tsi-mk-example.cpp
@example usb.cpp
@example usb_cdc_interface.cpp
@example usb_cdc_interface.h
@example usb_implementation.h
@example usb_implementation_bulk.cpp
@example usb_implementation_bulk.h
@example usb_implementation_cdc.cpp
@example usb_implementation_cdc.h
@example usb_implementation_composite.cpp
@example usb_implementation_composite.h

 */
