/*
 ============================================================================
 * @file    console-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo using Console class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <limits.h>
#include "console.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

int main() {
   char           buff[100];
   int            integer;
   long           longInteger;
   unsigned       unsignedInteger;
   unsigned long  unsignedLong;

   console.writeln().writeln("Starting");

   console.writeln(123456.4567f);
   console.writeln(3.4567f);
   console.writeln(3.0067f);
   console.writeln(0.0067f);
   console.writeln(0.12f);
   console.writeln(0.0f);
   console.writeln(-3.4567f);
   console.writeln(-3.0067f);
   console.writeln(-0.0067f);
   console.writeln(-0.12f);
   console.writeln(-3.4567);
   console.writeln(-3.0067);
   console.writeln(-0.0067);
   console.writeln(-0.12);

   console<<123456.4567f<<EndOfLine;
   console<<3.4567f<<EndOfLine;
   console<<3.0067f<<EndOfLine;
   console<<123456.4567<<EndOfLine;
   console<<3.4567<<EndOfLine;
   console<<3.0067<<EndOfLine;

   if (console.write("Number: ").readln(integer).isError()) {
      console.writeln("Opps");
   }
   else {
      console.writeln(integer);
   }

   console.write("3.1f      = ").writeln(3.1f);
   console.write("3.1       = ").writeln(3.1);

   // Test writing basic types using various methods
   console.write("True   = ").writeln(true);
   console.write("False  = ").writeln(false);
   console.write("peek() = ").writeln(console.peek());

   console.write("x         = ").writeln('x');
   console.write("0UL       = ").writeln(0UL);
   console.write("ULONG_MAX = ").writeln(ULONG_MAX);
   console.write("LONG_MIN  = ").writeln(LONG_MIN);
   console.write("LONG_MAX  = ").writeln(LONG_MAX);
   console.write("0U        = ").writeln(0U);
   console.write("UINT_MAX  = ").writeln(UINT_MAX);
   console.write("INT_MIN   = ").writeln(INT_MIN);
   console.write("INT_MAX   = ").writeln(INT_MAX);

   console.write("0UL,Radix_2        = ").writeln(0UL,Radix_2).flushOutput();
   console.write("ULONG_MAX,Radix_2  = ").writeln(ULONG_MAX,Radix_2);
   console.write("ULONG_MAX,Radix_8  = ").writeln(ULONG_MAX,Radix_8);
   console.write("ULONG_MAX,Radix_10 = ").writeln(ULONG_MAX,Radix_10);
   console.write("ULONG_MAX,Radix_16 = ").writeln(ULONG_MAX,Radix_16);
   console.write("UINT_MAX,Radix_2   = ").writeln(UINT_MAX,Radix_2);
   console.write("UINT_MAX,Radix_8   = ").writeln(UINT_MAX,Radix_8);
   console.write("UINT_MAX,Radix_10  = ").writeln(UINT_MAX,Radix_10);
   console.write("UINT_MAX,Radix_16  = ").writeln(UINT_MAX,Radix_16);

   console<<"true               = "<<true<<EndOfLine;
   console<<"false              = "<<false<<EndOfLine;
   console<<"peek()             = "<<console.peek()<<EndOfLine;
   console<<"1>2                = "<<(1>2)<<EndOfLine;
   console<<"1<2                = "<<(1<2)<<EndOfLine;
   console<<"0UL,Radix_2        = "<<Radix_2<<0UL<<EndOfLine;
   console<<"ULONG_MAX,Radix_2  = "<<Radix_2<<ULONG_MAX<<EndOfLine;
   console<<"ULONG_MAX,Radix_8  = "<<Radix_8<<ULONG_MAX<<EndOfLine;
   console<<"ULONG_MAX,Radix_10 = "<<Radix_10<<ULONG_MAX<<EndOfLine;
   console<<"ULONG_MAX,Radix_16 = "<<Radix_16<<ULONG_MAX<<EndOfLine;
   console<<"UINT_MAX,Radix_2   = "<<Radix_2<<UINT_MAX<<EndOfLine;
   console<<"3,Radix_2          = "<<Radix_2<<Padding_LeadingZeroes<<3<<EndOfLine;
   console<<"3,Radix_2,w=10,p=0 = "<<console.width(10)<<Radix_2<<Padding_LeadingZeroes<<3<<EndOfLine;
   console.reset();
   console<<"UINT_MAX,Radix_8   = "<<Radix_8<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,Radix_10  = "<<Radix_10<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,Radix_16  = "<<Radix_16<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,radix(16) = "<<Uart::radix(16)<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,radix(10) = "<<Uart::radix(10)<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,radix(8)  = "<<Uart::radix(8)<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,radix(2)  = "<<Uart::radix(2)<<UINT_MAX<<EndOfLine;
   console<<Radix_10;

   console.setWidth(10);
   FormattedIO::ultoa(buff, 100);
   console.write("ultoa(100, buff)  = ").writeln(buff);
   FormattedIO::ltoa(buff, -100);
   console.write("ltoa(-100, buff)  = ").writeln(buff);

   char *ptr = buff;
   ptr = FormattedIO::strcpy(ptr, "Console::ultoa(100, buff) = ");
   ptr = FormattedIO::ultoa(ptr, 100);
   ptr = FormattedIO::strcpy(ptr, ", oh well!");
   console.writeln(buff);

   // Test input
   console.write("Value (in radix 2): ").readln(integer,Radix_2);
   console.write(integer, Radix_10)
         .write(", 0x").write((unsigned long)integer, Radix_16)
         .write(", 0b").writeln((unsigned long)integer, Radix_2);

   console<<"Value (in radix 16): ">>Radix_16>>integer>>EndOfLine;
   console<<Radix_10<<integer<<", 0x"<<Radix_16<<(unsigned long)integer<<", 0b"<<Radix_2<<(unsigned long)integer<<EndOfLine;

   int length = console.write("text : ").gets(buff, sizeof(buff));
   console.write("[").write(length).write(" chars] = '").write(buff).writeln("'").flushOutput();

   console<<Radix_10;
   console<<"value :">>integer>>EndOfLine;
   console<<integer<<EndOfLine;
   console<<"value :">>longInteger>>EndOfLine;
   console<<longInteger<<EndOfLine;
   console<<"value :">>unsignedInteger>>EndOfLine;
   console<<unsignedInteger<<EndOfLine;
   console<<"value :">>unsignedLong>>EndOfLine;
   console<<unsignedLong<<EndOfLine;

   console.write("Two hex integers : ").read(integer,Radix_16).readln(longInteger,Radix_16);
   console.write(integer, Radix_16).write(", ").writeln(longInteger, Radix_16);
   console.write("An integer   : ").readln(longInteger);
   console.writeln(longInteger);
   console.write("An integer   : ").readln(unsignedInteger);
   console.writeln(unsignedInteger);
   console.write("An integer   : ").readln(unsignedLong);
   console.writeln(unsignedLong);


   console.readChar();

   // If direct interrupt handling is needed.
   //   console.setRxTxCallback(nullptr);

   // Above functions may be applied directly to any Uart as well.
   //   Uart1 uart1;
   //   uart1<<"Hello World\n";

   for(;;) {
      __asm__("nop");
   }
   return 0;
}
