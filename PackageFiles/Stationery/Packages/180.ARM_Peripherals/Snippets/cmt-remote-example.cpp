/**
 * @file    cmt-remote-example  (180.ARM_Peripherals/Snippets)
 * @brief   Example showing use of CMT to implement various IR protocols
 *
 * It will be necessary to configure the CMT interrupt handling and CMT
 * output pin in the USBDM configuration.
 *
 *  Created on: 18/9/2025
 *      Author: podonoghue
 */
#include "cmt-remote.h"
#include "hardware.h"

using namespace USBDM;

void help() {
   const char *helpMessage = "\n\n"
         "0-9 - Digit\n"
         "V   - Volume Up\n"
         "v   - Volume Down\n"
         "C   - Channel Up\n"
         "c   - Channel Down\n"
         "e   - Enter\n"
         "s   - Select\n"
         "m   - Mute/unmute\n"
         "P   - Power-on\n"
         "p   - Power-off\n"
         "t   - Power-toggle\n"
         "h   - Help\n\n";
   console.write(helpMessage);
}


int main() {

//   using Sender = IrTeacPVR;
//   using Sender = IrSonyTV;
//   using Sender = IrSamsungDVD;
   using Sender = IrLaserDVD;

   constexpr  PcrInit PinInitValue {
      PinPull_Up,
      PinDriveStrength_High,
      PinDriveMode_PushPull,
      PinSlewRate_Slow,
   };

   // Activity LED connection - indicates command being sent
   using ActivityLed   = RGB_Blue;

   using BlueButton    = Digital_A0;
   using GreenButton   = Digital_A1;
   using RedButton     = Digital_A2;

   ActivityLed::setOutput(PinInitValue);

   BlueButton::setInput(PinInitValue);
   GreenButton::setInput(PinInitValue);
   RedButton::setInput(PinInitValue);

   console.writeln("Starting\n");
   console.writeln("SystemCoreClock = ", SystemCoreClock);
   console.writeln("SystemBusClock  = ", SystemBusClock);

   console.setEcho(EchoMode_Off);
   console.setBlocking(BlockingMode_Off);

   bool CommandDone = true;
   for(int count = 0;;count++) {

      if (CommandDone) {
         console.write("\n0-9,v,c,m,p,e,t,h ? ");
      }
      CommandDone = false;

      int ch = console.readChar();
      if (ch>0) {
         // OK key
      }
      else if (BlueButton::isPressed()) {
         ch = 't';
      }
      else if (GreenButton::isPressed()) {
         ch = 'C';
      }
      else if (RedButton::isPressed()) {
         ch = 'c';
      }
      else {
         continue;
      }
      // Assume OK command
      CommandDone = true;

      // Send pattern
      switch(ch) {
         case '0': Sender::send(Sender::NUM0          );  break;
         case '1': Sender::send(Sender::NUM1          );  break;
         case '2': Sender::send(Sender::NUM2          );  break;
         case '3': Sender::send(Sender::NUM3          );  break;
         case '4': Sender::send(Sender::NUM4          );  break;
         case '5': Sender::send(Sender::NUM5          );  break;
         case '6': Sender::send(Sender::NUM6          );  break;
         case '7': Sender::send(Sender::NUM7          );  break;
         case '8': Sender::send(Sender::NUM8          );  break;
         case '9': Sender::send(Sender::NUM9          );  break;
         case 't': Sender::send(Sender::ON_OFF        );  break;
         case 'P': Sender::send(Sender::PLAY          );  break;
         case 'p': Sender::send(Sender::PAUSE         );  break;
         case 'F': Sender::send(Sender::FORWARD_SCENE );  break;
         case 'f': Sender::send(Sender::FORWARD       );  break;
         case 'R': Sender::send(Sender::REVERSE_SCENE );  break;
         case 'r': Sender::send(Sender::REVERSE       );  break;
         case 'V': Sender::send(Sender::VOLUME_UP     );  break;
         case 'v': Sender::send(Sender::VOLUME_DOWN   );  break;
         case 'E':
         case 'e': Sender::send(Sender::EJECT         );  break;
         case 'M':
         case 'm': Sender::send(Sender::MUTE          );  break;
#ifdef DVD
//         case 'C': Sender::send(Sender::CHANNEL_UP   );      break;
//         case 'c': Sender::send(Sender::CHANNEL_DOWN );      break;
//         case 'S':
//         case 's': Sender::send(Sender::select      );      break;
//         case 'P': Sender::send(Sender::Code(0x00FF00FFU), 3, true);      break;
//         case 'p': Sender::send(Sender::Code(0x00000000U));      break;
//         case 't': Sender::send(Sender::Code(0xFFFFFFFFU));      break;
#endif
         case 'h': help(); CommandDone = false;       break;
         default:
            // Not recognized command
            CommandDone = false;
            break;
      }
      if (CommandDone) {
         // Pulse LED during transmission
         ActivityLed::on();
         console.write((char)ch);
         Sender::waitUntilComplete();
         ActivityLed::off();

         // Extra delay between transmissions
//         waitMS(100);
      }
      CommandDone = true;
   }
   return 0;
}

/*
 * Buttons
 * UP,DOWN,LEFT,RIGHT,OK
 * 0-9
 * PLAY,PAUSE
 */
