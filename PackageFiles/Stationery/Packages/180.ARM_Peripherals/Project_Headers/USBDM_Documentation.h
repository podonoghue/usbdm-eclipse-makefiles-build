/**
 * @file     USBDM_Documentation.h (180.ARM_Peripherals/Project_Headers/USBDM_Documentation.h)
 * @brief    USBDM Documentation
 */
 
 /**
 @mainpage USBDM Overview

 The classes in the USBDM namespace provide C++ wrappers for the microcontroller hardware. \n

\tableofcontents
Table of Contents
 - \ref ADCExamples \n
 - \ref Console \n
 - \ref DMAExamples \n
 - \ref FTMExamples \n
 - \ref GPIOExamples \n
 - \ref LPTMRExamples \n
 - \ref PDBExamples \n
 - \ref PinSummary  \n
 - \ref PITExamples \n

@page Console  Console and UART interface

Convenience template for UART. Uses the following classes:\n
<ul>
<li> USBDM::Console
<li> USBDM::Uart0
<li> USBDM::Uart1
<li> USBDM::Uart2
</ul>

@page DMAExamples  Direct Memory Access Controller

Convenience template for DMAC. Uses the following classes:\n
<ul>
<li>USBDM::DmaTcd \n
<li>USBDM::DmaMux_T < DmaMuxInfo > \n
<li>USBDM::Dma_T < DmaInfo > \n
</ul>

This template is an interface for the Direct Memory Access Controller hardware. \n

It provides:\n
- Definitions for channel mappings
- Methods to configure the DMAC and DMAMUX

This is a template class with static methods.\n
<em>It cannot be instantiated.</em>

<b>Examples</b>\n
 - @ref dma-memory-example.cpp
 - @ref  digital-example1.cpp
 - @ref  digital-example2.cpp
 - @ref  dma-memory-example.cpp

 @page GPIOExamples  General Purpose Input Output

@page LPTMRExamples  Low Power Timer

Convenience template for LPTMR. Uses the following classes:\n
<ul>
<li>USBDM::Lptmr_T < Info > \n
</ul>

This template is an interface for the Low Power Timer hardware. \n

It provides:\n
- Static pin mapping in conjunction with the configuration settings.

This is a template class with static methods.\n
<em>It cannot be instantiated.</em>

<b>Examples</b>\n
 - @ref lptmr-example.cpp
 
 @page GPIOExamples  General Purpose Input Output

Convenience template for GPIO pins. Uses the following classes:\n
<ul>
<li>USBDM::GpioBase_T <clockMask, pcrAddress, gpioAddress, bitNum, polarity> \n
<li>USBDM::Gpio_T <Info, bitNum, polarity>\n
<ul>
<li>USBDM::GpioA <bitNum, polarity>
<li>USBDM::GpioB <bitNum, polarity>
<li>USBDM::GpioC <bitNum, polarity>
<li>USBDM::GpioD <bitNum, polarity>
<li>USBDM::GpioE <bitNum, polarity>
</ul>
<li>USBDM::Field_T <Info, left, right>\n
<ul>
<li>USBDM::GpioAField <left, right>
<li>USBDM::GpioBField <left, right>
<li>USBDM::GpioCField <left, right>
<li>USBDM::GpioDField <left, right>
<li>USBDM::GpioEField <left, right>
</ul>
</ul>

This template is an interface for the general purpose I/O pin hardware. \n

It provides:\n
- Static pin mapping in conjunction with the configuration settings.
- Setting pin characteristics e.g. pull-ups, drive strength etc
- Changing the pin direction
- Setting outputs to high or low level
- Polling input value
- Polarity (\ref USBDM::ActiveHigh or \ref USBDM::ActiveLow) is selected when instantiated

This is a template class with static methods.\n
<em>It cannot be instantiated.</em>

<b>Examples</b>\n
 - @ref digital-example1.cpp
 - @ref digital-example2.cpp

<b>Usage</b>
 @code
   // Open USBDM namespace.
   // This allows access to USBDM classes and methods without the USBDM:: prefix.
   using namespace USBDM;

   // Temporary for input values
   bool x;

   // Use pin 3 of PORTC as active-high GPIO i.e. PTC3
   using Gpio = GpioC<3, ActiveHigh>;

   // Set as digital output
   Gpio::setOutput();
   // or for more detailed control
   Gpio::setOutput(PinDriveStrength_High, PinDriveMode_OpenDrain);

   // Set pin to active level (polarity is applied)
   Gpio::setActive();
   // or
   Gpio::on();

   // Clear pin to inactive level (polarity is applied)
   Gpio::setInactive();
   // or
   Gpio::off();

   // Set pin to a high level (polarity is ignored)
   Gpio::set();
   // or
   Gpio::high();

   // Set pin to a low level (polarity is ignored)
   Gpio::clear();
   // or
   Gpio::low();

   // Toggle pin
   Gpio::toggle();

   // Set pin to boolean value (polarity is applied)
   Gpio::write(true);

   // Set pin to boolean value (polarity is applied)
   Gpio::write(false);

   // Enable pull-up
   // This will only have effect when pin is an input
   Gpio::setPullDevice(PinPull_Up);

   // Set drive strength
   Gpio::setDriveStrength(PinDriveStrength_High);

   // Set open-drain
   Gpio::setDriveMode(PinDriveMode_OpenDrain);

   // Read pin as boolean value (polarity is applied)
   x = Gpio::read();

   // Read _state_ of pin drive as boolean value (polarity is applied)
   // This may differ from the value on the pin
   // May be useful if the pin is open-drain
   Gpio::setDriveMode(PinOpenDrain);
   Gpio::high();
   if (Gpio::readState() != Gpio::read()) {
      printf("Open-drain pin is being held low\n");
   }

   // Dynamically change pin to input
   Gpio::setIn();

   // Read pin as boolean value (polarity is applied)
   x = Gpio::read();

   // Read pin as boolean value (polarity is ignored)
   x = Gpio::isHigh();

   // Read pin as boolean value (polarity is ignored)
   x = Gpio::isLow();
 @endcode

@page ADCExamples Analogue-to-Digital

Convenience template for ADC inputs. Use the following classes:\n
<ul>
<li>USBDM::AdcBase_T
<ul>
<li>USBDM::Adc0
<li>USBDM::Adc1
</ul>
<li>USBDM::AdcChannel_T
<ul>
<li>USBDM::Adc0Channel
<li>USBDM::Adc1Channel
</ul>
<li>USBDM::AdcDiffChannel_T
<ul>
<li>USBDM::Adc0DiffChannel
<li>USBDM::Adc1DiffChannel
</ul>
</ul>
This template is an interface for the ADC input pins. \n

It provides:\n
- Static pin mapping in conjunction with the configuration settings. (Some ADC pins have fixed mapping.)
- Setting the resolution in bits
- Setting the conversion parameters e.g. averaging
- Clock and conversion speed are done through the configuration.
- Interrupt driven operation is also supported through a callback if enabled in the configuration.

This is a template class with static methods.\n
<em>It cannot be instantiated.</em>

<b>Examples</b>\n
 - @ref analogue-comparison-example.cpp
 - @ref analogue-diff-example.cpp
 - @ref analogue-interrupt-example.cpp
 - @ref analogue-joystick-example.cpp

 <b>Usage - Single-ended measurement</b>
 @code
   // Open USBDM namespace.
   // This allows access to USBDM classes and methods without the USBDM:: prefix.
   using namespace USBDM;

   // Use ADC0 channel 6 as ADC input (ADC_IN6)
   using AdcChannel = USBDM::Adc0Channel<6>;

   // Set ADC resolution to 16 bits
   AdcChannel::setResolution(AdcResolution_16bit_se);

   // Set ADC averaging to 4 samples
   AdcChannel::setAveraging(AdcAveraging_4);

   // Read ADC value
   uint32_t value = AdcChannel::readAnalogue();

   printf("ADC measurement = %lu\n", value);
 @endcode

 <b>Usage - Differential measurement</b>
 @code
   // Open USBDM namespace.
   // This allows access to USBDM classes and methods without the USBDM:: prefix.
   using namespace USBDM;

   // Use channel 0 as ADC differential input (ADC_DM0, ADC_DP0)
   using Adc1_diff0 = USBDM::Adc0DiffChannel<0>;

   // Set ADC resolution to 11 bits differential
   Adc1_diff0::setResolution(AdcResolution_11bit_diff);

   // Set ADC averaging to 4 samples
   Adc1_diff0::setAveraging(AdcAveraging_4);

   // Read signed differential ADC value
   int32_t value = Adc1_diff0::readAnalogue();

   printf("ADC measurement = %ld\n", value);
 @endcode

@page FTMExamples Flexible Timer Module

Convenience template for FTM hardware.
The interface is divided into a number of templates:
<ul>
<li>USBDM::FtmBase_T Representing the shared FTM functionality.
<ul>
<li>USBDM::Ftm0
<li>USBDM::Ftm1
</ul>
<li>USBDM::QuadEncoder_T Representing a FTM operating as a quadrature encoder.
<ul>
<li>USBDM::QuadEncoder1
</ul>
<li>USBDM::FtmChannel_T Representing individual channels of a single FTM.
<ul>
<li>USBDM::Ftm0Channel
<li>USBDM::Ftm1Channel
</ul>
</ul>
It provides:\n
<ul>
<li>Static pin mapping in conjunction with the configuration settings.
<li>Setting the FTM period in ticks or seconds
<li>Setting the channel duty cycle in percentage
<li>Interrupt driven operation is also supported through a callback if <b>enabled in the configuration</b>.
</ul>

This is a template class with static methods.\n
<em>It cannot be instantiated.</em>

<b>Examples</b>\n
 - @ref ftm-ic-example.cpp
 - @ref ftm-oc-example.cpp
 - @ref ftm-pwm-example.cpp
 - @ref ftm-quadrature-example.cpp
 - @ref ftm-servo-example.cpp

 <b>Usage - PWM</b>
@code
   // Open USBDM namespace.
   // This allows access to USBDM classes and methods without the USBDM:: prefix.
   using namespace USBDM;

   // Initialise the timer with initial alignment
   // This affects all channels of the FTM
   Ftm0::configure(FtmMode_LeftAlign);

   // Set timer period in ticks
   // This affects all channels of the FTM
   // Timer pre-scaler is not changed
   Ftm0::setPeriodInTicks(500);

   // Set timer period in microseconds
   // This affects all channels of the FTM
   // Timer pre-scaler (tick rate) will be adjusted to accommodate the required period
   Ftm0::setPeriod(125*us);

   // Use FTM0 channel 3
   using PwmOutput = Ftm0Channel<3> ;

   // Set channel to generate PWM with active-high pulses
   PwmOutput::enable(ftm_pwmHighTruePulses);

   // Set duty cycle as percentage
   PwmOutput::setDutyCycle(34);

   // Set duty cycle as percentage (float)
   PwmOutput::setDutyCycle(12.25*percent);

   // Set high time in microseconds (float)
   PwmOutput::setHighTime(63*us);
@endcode

 <b>Usage - Quadrature Encoder</b>
@code
   // Open USBDM namespace.
   // This allows access to USBDM classes and methods without the USBDM:: prefix.
   using namespace USBDM;

   // Use FTM1 as the quadrature encoder
   // Not all FTMs support this mode
   using QuadEncoder = QuadEncoder1;

   // Enable encoder
   QuadEncoder::enable();

   // Set pin filters
   QuadEncoder::enableFilter(15);

   // Reset position to zero
   // Movement will be relative to this position
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

Convenience template for PIT hardware. Based on USBDM::Pit_T.\n

It provides:\n
- Static pin mapping in conjunction with the configuration settings.
- Setting the PIT channel period in seconds
- Accurate busy-wait delays using a timer channel
- Interrupt driven operation is also supported through a callback if enabled in the configuration.

This is a template class with static methods.\n
<em>It cannot be instantiated.</em>

<b>Examples</b>\n
 - @ref pit-example1.cpp
 - @ref pit-example2.cpp
 - @ref pit-example3.cpp

<b>Usage - PIT busy-wait</b>
@code
   // Open USBDM namespace.
   // This allows access to USBDM classes and methods without the USBDM:: prefix.
   using namespace USBDM;

   // LED is assumed active-low
   using Led = GpioA<2, ActiveLow>;

   // Use high drive for LED
   Led::setOutput(pcrValue(PinPull_None, PinDrive_High));

   // Enable PIT
   Pit::enable();

   // Check for errors so far
   checkError();

   for(;;) {
      Led::toggle();

      // Delay in milliseconds using channel 0
      Pit::delay(0, 1000*ms);
   }
@endcode

@page PDBExamples Programmable Delay Block Module

Convenience template for PDB hardware. Based on USBDM::PdbBase_T.\n

It provides:\n
- PDB configuration

This is a template class with static methods.\n
<em>It cannot be instantiated.</em>

<b>Examples</b>\n
 - @ref pdb-example.cpp

<b>Usage - PDB Software Trigger</b>
@code
   // Open USBDM namespace.
   // This allows access to USBDM classes and methods without the USBDM:: prefix.
   using namespace USBDM;

   Pdb::enable();
   // Trigger from FTM
   Pdb::setTriggerSource(PdbTrigger_Software);
   // Set callback
   Pdb::setCallback(pdbCallback);
   // Interrupt during sequence
   Pdb::enableSequenceInterrupts();
   // Set period a bit longer than FTM period
   Pdb::setPeriod(PERIOD);
   // Generate interrupt near end of sequence
   Pdb::setInterruptDelay(PERIOD-5*ms);
   // Take ADC samples before and after sample edge
   Pdb::setPretriggers(0, PdbPretrigger0_Delayed, HIGH_TIME-SAMPLE_DELAY, PdbPretrigger1_Delayed, HIGH_TIME+SAMPLE_DELAY);
   // Update registers
   Pdb::triggerRegisterLoad(PdbLoadMode_immediate);

   Pdb::enableNvicInterrupts();

   Pdb::softwareTrigger();
@endcode

@page Notes Notes
  - enable()            Enables clock and configures pins (if any configured in Configure.usbdmProject)
  - defaultConfigure()  As above, enable() + initialises according to Configure.usbdmProject\n
                        May have defaulted parameters to do custom configuration.
  - disable()           Disables the peripheral

@example analogue-comparison-example.cpp
@example analogue-diff-example.cpp
@example analogue-interrupt-example.cpp
@example analogue-joystick-example.cpp
@example cmp.cpp
@example digital-example1.cpp
@example digital-example2.cpp
@example dma-memory-example.cpp
@example dma-spi-example.cpp
@example dma-uart-example.cpp
@example flash_programming_example.cpp
@example ftm-ic-example.cpp
@example ftm-oc-example.cpp
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
@example pit-example3.cpp
@example pdb-example.cpp
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
