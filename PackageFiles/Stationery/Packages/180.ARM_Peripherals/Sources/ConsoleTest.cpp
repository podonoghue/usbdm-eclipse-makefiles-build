/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include <limits.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "uart.h"
#include "console.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// LED connection - change as required
using Led   = USBDM::GpioA<2,USBDM::ActiveLow>;

int main() {
   char buff[100];
   int integer;
   long longInteger;
   unsigned unsignedInteger;
   unsigned long unsignedLong;

   console.writeln("Starting");

   //   console.write("3.1f      = ").writeln(3.1f);
   //   console.write("3.2f      = ").writeln(3.2f);
   //   console.write("3.3f      = ").writeln(3.3f);
   //   console.write("3.4f      = ").writeln(3.4f);

   console.write("True  = ").writeln(true);
   console.write("False = ").writeln(false);

   console.write("isCharAvailable() = ").writeln(console.isCharAvailable());

   console.write("x         = ").writeln('x');
   console.write("0UL       = ").writeln(0UL);
   console.write("ULONG_MAX = ").writeln(ULONG_MAX);
   console.write("LONG_MIN  = ").writeln(LONG_MIN);
   console.write("LONG_MAX  = ").writeln(LONG_MAX);
   console.write("0U        = ").writeln(0U);
   console.write("UINT_MAX  = ").writeln(UINT_MAX);
   console.write("INT_MIN   = ").writeln(INT_MIN);
   console.write("INT_MAX   = ").writeln(INT_MAX);

   console.write("0UL,Radix_2        = ").writeln(0UL,Radix_2);
   console.write("ULONG_MAX,Radix_2  = ").writeln(ULONG_MAX,Radix_2);
   console.write("ULONG_MAX,Radix_8  = ").writeln(ULONG_MAX,Radix_8);
   console.write("ULONG_MAX,Radix_10 = ").writeln(ULONG_MAX,Radix_10);
   console.write("ULONG_MAX,Radix_16 = ").writeln(ULONG_MAX,Radix_16);
   console.write("UINT_MAX,Radix_2   = ").writeln(UINT_MAX,Radix_2);
   console.write("UINT_MAX,Radix_8   = ").writeln(UINT_MAX,Radix_8);
   console.write("UINT_MAX,Radix_10  = ").writeln(UINT_MAX,Radix_10);
   console.write("UINT_MAX,Radix_16  = ").writeln(UINT_MAX,Radix_16);

   console<<"0UL,Radix_2        = "<<Radix_2<<0UL<<"\n";
   console<<"ULONG_MAX,Radix_2  = "<<Radix_2<<ULONG_MAX<<"\n";
   console<<"ULONG_MAX,Radix_8  = "<<Radix_8<<ULONG_MAX<<"\n";
   console<<"ULONG_MAX,Radix_10 = "<<Radix_10<<ULONG_MAX<<"\n";
   console<<"ULONG_MAX,Radix_16 = "<<Radix_16<<ULONG_MAX<<"\n";
   console<<"UINT_MAX,Radix_2   = "<<Radix_2<<UINT_MAX<<"\n";
   console<<"UINT_MAX,Radix_8   = "<<Radix_8<<UINT_MAX<<"\n";
   console<<"UINT_MAX,Radix_10  = "<<Radix_10<<UINT_MAX<<"\n";
   console<<"UINT_MAX,Radix_16  = "<<Radix_16<<UINT_MAX<<"\n";
   console<<"UINT_MAX,radix(16) = "<<Uart::radix(16)<<UINT_MAX<<"\n";
   console<<"UINT_MAX,radix(10) = "<<Uart::radix(10)<<UINT_MAX<<"\n";
   console<<"UINT_MAX,radix(8)  = "<<Uart::radix(8)<<UINT_MAX<<"\n";
   console<<"UINT_MAX,radix(2)  = "<<Uart::radix(2)<<UINT_MAX<<"\n";
   console<<Radix_10;

   Console::ultoa(100, buff);
   console.write("ultoa(100, buff)  = ");console.writeln(buff);
   Console::ltoa(-100, buff);
   console.write("ltoa(-100, buff)  = ");console.writeln(buff);

   char *ptr = buff;
   ptr = Console::strcpy(ptr, "Console::ultoa(100, buff) = ");
   ptr = Console::ultoa(100, ptr);
   ptr = Console::strcpy(ptr,  ", oh well!");
   console.writeln(buff);

   console.write("Value (in radix 2): ").readln(integer,Radix_2);
   console.write(integer, Radix_10)
         .write(", 0x").write((unsigned long)integer, Radix_16)
         .write(", 0b").writeln((unsigned long)integer, Radix_2);

   console<<"Value (in radix 16): ">>Radix_16>>integer>>EndOfLine;
   console<<Radix_10<<integer<<", 0x"<<Radix_16<<(unsigned long)integer<<", 0b"<<Radix_2<<(unsigned long)integer<<EndOfLine;

   int length = console.write("text : ").gets(buff, sizeof(buff));
   console.write("[").write(length).write(" chars] = '").write(buff).writeln("'");

   console<<Radix_10;
   console<<"value :">>integer>>EndOfLine;
   console<<"value :"<<integer<<EndOfLine;
   console<<"value :">>longInteger>>EndOfLine;
   console<<"value :"<<longInteger<<EndOfLine;
   console<<"value :">>unsignedInteger>>EndOfLine;
   console<<"value :"<<unsignedInteger<<EndOfLine;
   console<<"value :">>unsignedLong>>EndOfLine;
   console<<"value :"<<unsignedLong<<EndOfLine;

   console.write("Two integers : ").read(integer,Radix_16).readln(longInteger,Radix_16);
   console.write(integer).write(", ").writeln(longInteger);
   console.write("An integer   : ").readln(longInteger);
   console.writeln(longInteger);
   console.write("An integer   : ").readln(unsignedInteger);
   console.writeln(unsignedInteger);
   console.write("An integer   : ").readln(unsignedLong);
   console.writeln(unsignedLong);
   Uart1 uart1{};
   uart1.isCharAvailable();

   uart1.readChar();
   console.readChar();

   Led::setOutput();
   for(;;) {
      Led::toggle();
      USBDM::waitMS(100);
      //      printf("Tick\n");
   }
   return 0;
}
