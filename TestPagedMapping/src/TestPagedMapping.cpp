//============================================================================
// Name        : TestPagedMapping.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

static uint32_t convertLinearAddressToPaged( uint32_t linearAddress) {
   uint32_t pagedAddress;

   pagedAddress  = linearAddress&0x3FFF;          // Offset within page
   pagedAddress |= 0x8000;                        // Start of paged address window
   pagedAddress |= (linearAddress << 2)&0xFF0000;  // page number

   return pagedAddress;
}

void test(uint32_t address) {
   printf("0x%6.6X => 0x%6.6X\n", address, convertLinearAddressToPaged(address));
}

int main() {
   for (int i=0; i<8; i++) {
      uint32_t addr = 0x0E0000 + (i * 0x4000);
      test(addr);
      test(addr+0x3FFF);
   }
//   test (0x0E0000);
//   test (0x0E8000);
//   test (0x0EFFFF);
//   test (0x0F0000);
//   test (0x0F8000);
//   test (0x0FFFFF);

	return 0;
}
