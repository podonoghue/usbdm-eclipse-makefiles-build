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
#include "hardware.h"
#include "stringFormatter.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

int main() {
   char           buff[100];
   int            integer;
   long           longInteger;
   unsigned       unsignedInteger;
   unsigned long  unsignedLong;

   // Writing stuff to console
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

   // Console read/write
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

   console.write("1_us      = ").writeln(1_us);
   console.write("1.0_us    = ").writeln(1.0_us);
   console.write("10_us     = ").writeln(10_us);
   console.write("10.0_us   = ").writeln(10.0_us);
   console.write("100_us    = ").writeln(100_us);
   console.write("100.0_us  = ").writeln(100.0_us);
   console.write("1_ms      = ").writeln(1_ms);
   console.write("1.0_ms    = ").writeln(1.0_ms);
   console.write("10_ms     = ").writeln(10_ms);
   console.write("10.0_ms   = ").writeln(10.0_ms);
   console.write("100_ms    = ").writeln(100_ms);
   console.write("100.0_ms  = ").writeln(100.0_ms);
   console.write("1_s       = ").writeln(1_s);
   console.write("1.0_s     = ").writeln(1.0_s);
   console.write("10_s      = ").writeln(10_s);
   console.write("10.0_s    = ").writeln(10.0_s);
   console.write("100_s     = ").writeln(100_s);
   console.write("100.0_s   = ").writeln(100.0_s);

   console.write("1_Hz      = ").writeln(1_Hz);
   console.write("1.0_Hz    = ").writeln(1.0_Hz);
   console.write("10_Hz     = ").writeln(10_Hz);
   console.write("10.0_Hz   = ").writeln(10.0_Hz);
   console.write("100_Hz    = ").writeln(100_Hz);
   console.write("100.0_Hz  = ").writeln(100.0_Hz);
   console.write("1_kHz     = ").writeln(10_kHz);
   console.write("1.0_kHz   = ").writeln(10.0_kHz);
   console.write("10_kHz    = ").writeln(10_kHz);
   console.write("10.0_kHz  = ").writeln(10.0_kHz);
   console.write("100_kHz   = ").writeln(100_kHz);
   console.write("100.0_kHz = ").writeln(100.0_kHz);
   console.write("1_MHz     = ").writeln(1_MHz);
   console.write("1.0_MHz   = ").writeln(1.0_MHz);
   console.write("10_MHz    = ").writeln(10_MHz);
   console.write("10.0_MHz  = ").writeln(10.0_MHz);
   console.write("100_MHz   = ").writeln(100_MHz);
   console.write("100.0_MHz = ").writeln(100.0_MHz);

   /*
    * Arrays
    */
   static const int dataArray[] = {1,2,3,4,5,6,};
   const int * const dataPointer = dataArray;
   console.writeln(dataArray, Radix_16);               // print array of integers
   console.writeln(dataPointer, 6, Radix_16);          // print array of integers
   console.writeln(dataArray, 6, Radix_16);            // print array of integers
   console.writeln(dataPointer);                       // print pointer value
   console.writeln(dataPointer, Radix_16);             // print pointer value

   static const float fDataArray[] = {1,2,3,4,5,6,};
   const float *fDataPointer = fDataArray;

   console.writeln(fDataArray);                         // print array of floats
   console.writeln(fDataPointer, 6);                    // print array of floats
   console.writeln(fDataArray, 6);                      // print array of floats
   console.writeln(fDataPointer);                       // print pointer value
   console.writeln(fDataPointer, Radix_10);             // print pointer value

   static const double dDataArray[] = {1,2,3,4,5,6,};
   const double *dDataPointer = dDataArray;

   console.writeln(dDataArray);               // print array of doubles
   console.writeln(dDataPointer, 6);          // print array of doubles
   console.writeln(dDataArray, 6);            // print array of doubles
   console.writeln(dDataPointer);             // print pointer value
   console.writeln(dDataPointer, Radix_10);   // print pointer value

   console.writeln("hello"); // print a string

   char aString[] = "hello";

   console.writeln(aString);           // print  string
   console.writeln(aString, Radix_16); // print  array of char as integers

   unsigned char uString[] = "hello";

   console.writeln(uString);            // print array of char as integers
   console.writeln(uString, Radix_16);  // print array of char as integers

   signed char sString[] = "hello";

   console.writeln(sString);            // print array of signed char as integers
   console.writeln(sString, Radix_16);  // print array of signed char as integers

   uint8_t uiString[] = "hello this is a long string to split over multiple lines xx";

   console.writeln(uiString);           // print array of uint8_t as integers
   console.writeln(uiString, Radix_16); // print array of uint8_t as integers

   const char *pString[] = {"one", "two", "three"};

   console.writeln(pString);            // print array of strings
   console.writeln(pString, Radix_10);  // print array of pointers as integers

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
   console.resetFormat();
   console<<"UINT_MAX,Radix_8   = "<<Radix_8<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,Radix_10  = "<<Radix_10<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,Radix_16  = "<<Radix_16<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,radix(16) = "<<console.radix(16)<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,radix(10) = "<<console.radix(10)<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,radix(8)  = "<<console.radix(8)<<UINT_MAX<<EndOfLine;
   console<<"UINT_MAX,radix(2)  = "<<console.radix(2)<<UINT_MAX<<EndOfLine;
   console<<Radix_10;

   //  Basic integer formatting to strings
   FormattedIO::ultoa(buff, 100, Radix_10, Padding_LeadingZeroes, 12);
   console.write("ultoa(100, buff, Radix_10, Padding_LeadingZeroes, 12)  = ").writeln(buff);
   FormattedIO::ltoa(buff, -100, Radix_16, Padding_LeadingSpaces, 12);
   console.write("ltoa(-100, buff, Radix_16, Padding_LeadingSpaces, 12)  = ").writeln(buff);

   // Test input
   console.write("Value (in radix 2): ").readln(integer,Radix_2);
   console.write(integer, Radix_10)
         .write(", 0x").write((unsigned long)integer, Radix_16)
         .write(", 0b").writeln((unsigned long)integer, Radix_2);

   console<<"Value (in radix 16): ">>Radix_16>>integer>>EndOfLine;
   console<<Radix_10<<integer<<", 0x"<<Radix_16<<(unsigned long)integer<<", 0b"<<Radix_2<<(unsigned long)integer<<EndOfLine;

   // Read and echo an input line
   int length = console.write("text : ").gets(buff, sizeof(buff));
   console.write("[").write(length).write(" chars] = '").write(buff).writeln("'").flushOutput();

   // Read and write numbers
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

   // Writing formatted data to character buffer
   StringFormatter sf(buff,sizeof(buff));
   sf.write("This is being written to a string ").write(1).write(",").write(2).write(",").write(3.0).writeln(" - done");
   console.write(sf.toString());

   console.write("Type any character - ignored").readChar();

   console.writeln("\nFinished");

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
