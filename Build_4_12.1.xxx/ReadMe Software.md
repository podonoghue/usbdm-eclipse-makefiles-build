*******
*******
# USBDM Software builds  
It is suggested to build Linux versions from scratch rather than download the DEB here.  
See instructions on this page [GitHub](https://github.com/podonoghue/usbdm-eclipse-makefiles-build)

*******
*******
# History


*******  
USBDM V4_12_1_262 (July 2018) 

- Changed how programmer locates RAM region to use 
- Fixed startup code in Kinetis firware version so USB interruption recovery is better 
- USBDM project stationery (extensive changes) 

*******  
USBDM V4_12_1_240 (Oct 2018)  

- Updated documentation and minor changes 
- USBDM project stationery 
   - Fixes for USBDM libraries 

*******  
USBDM V4_12_1_230 (June 2018)  

- Updated documentation and minor changes 
- Updated examples
- Fixed vector table generation for user defined handlers
- USBDM project stationery (a-i)
   - Minor corrections
   - Refactor for improved visibility
   - Added CRC, CMT and EWM
*******  
USBDM V4_12_1_220 (June 2018)  

- Added S32 family
- Various minor fixes
- Added S32EVM board flash-images
- Updated MCUExpresso installer
- USBDM Eclipse plug-in
   - Compiler language standard now passed to C indexer
   - Changed default RAM region in project linker file to be largest RAM region
   - Set default RAM range to largest added RAM memory region
   - Added parameters, improved S32, some peripherals
   - Minor changes for consistency
   - Added S32K144 and some related improvements
   - Added raw binary image files to programmer
- USBDM project stationery
   - Fixes for USBDM libraries
   - Added synchronization classes and functions
   - Work on SVDs - added parameters, improved derivedFrom function
   - Added SVDs for S32 family
   - Improved SVD for some devices
   - Improved SVD processing
   - Improved handling of Interrupt entries.
   - Added categories for S32 etc.
   - Added MKL02-MKL05 stationery (basic)
   - Added QUADRATURE mode divider selection
   - Fixed missing '-' for some -ve numbers in write()
   - Improved Security descriptions
   - Added checks for ISR handler installation
   - Updated to be comptible with latest GCC (constexpr changes)

*******  
USBDM V4_12_1_210 (November 2017)  

- Installer updates
- Added MKW41z
- Fixes for Linux build
- GDB Server
   - More control on reset actions, better VLLx reset handling
   - Fix for when connecting to secured device
- USBDM project stationery
   - Added console write() and writeln()(available for general UART use)
   - Snippets updated and other examples added
   - Added -Og option to compiler
   - Improved C++ example mainline
   - Improved speed for SPI driver in USBDM project
   - Improved low-power options
   - SPI configuration more flexible for shared use
   - Added SetIn(), SetOut() and asserts for bit numbers to GPIOxField,
   - Added asserts for pin number in SPI
   - Added asserts for pin number in TSI
   

*******  
USBDM V4_12_1_200 (July 2017)  

- Stationery changes (IRQ handling etc.)

*******  
USBDM V4_12_1_190 (July 2017)  

- Added MK27, MK28
- Updated Kinetis USBDM firmware
- Added floating-point options for printf() to new project wizard
- Bug Fix in BME operations header file
- Stationery - Added BME operations to GPIO/PCR on MKL devices
- Stationery - Added __attribute__((always_inline)) to various functions
- Stationery - PCR field names made more consistent 
- Stationery - Bug Fix to SPI - startTransaction()
- Stationery - Added eraseAll() to FTFx module
- Stationery - Basic DMA device for some Kinetis MK 
- Stationery - Added DMA support to various peripherals
- Stationery - Added DMA examples
- Stationery - Corrected period calculations for PIT, FTM etc (1-off corrections)
- Stationery - Added PDB and ADC support 

*******  
USBDM V4_12_1_180 (June 2017)  

- Added MCUExpresso to installer
- Changed device XML files to use XInclude 
- Changed peripheral XML files to use XInclude
- Added MAX30102 examples
- Extended device descriptions (erase methods, programming checksum for LPC devices)
- Updated plugins - Fixes for USBDM launch (MCUExpresso)
- Updated plugins - Added Run/Debug USBDM C++ to project right-click menus and debug/run menus
- Automatically creates launch configurations when missing on launch (see previous)  
- Extended erase method and reset method handling (needed for LPC)
- Provided configurable device security settings for projects
- Added some NXP LPC ARM cortex devices:
- Added LPC11U12,LPC11U13,LPC11U14,LPC11U22,LPC11U23,LPC11U24,LPC11U34,LPC11U35,LPC11U36,LPC11U37
- Added LPC1311,LPC1313,LPC1342,LPC1343
- Rebuilt using C++14
- Review of TCL scripts to take advantage of additional features
- Updated I2C examples
- Update LCD examples
- Bug fix - CMSIS build failure on MKL devices (cortex-M0)
- Bug fix - Changed Trim parameters in Launch configurations to string to avoid eclipse parsing errors
- Bug fix - SVD file/device selection fixed for external files
- Bug fix - SVD parsing extended
- Bug fix - Corrected handling of device aliases in GDB server
- Bug Fix - SWD BDM Firmware - Fix for occasional hang in SWD Tx/Rx routines (I hope)
- Bug Fix - Corrected SDIDs for some MKVx devices

*******  
USBDM V4_12_1_170 (April 2017)  

- Updated FTFL (flash) code stationery  
- Improved format of generated Doxygen comments  
- Spelling!  
- Added mutex lock(), trylock(), unlock()to CMSIS stationery   
- Updated Kinetis target flash code, added MKE18M16 family  
- Added .abs as valid extension for loading ELF files
- Bug fixes  
    - Fix for USB enumeration for non-USBDM devices (JS16_Bootloader and JB16_Bootloader)  
    - Fixed MKE02 flash script error (NMI now ignored as expected)  
    - Fix for RAM writes for targets without generic Flash program code
    - Changed back to using loading ELF files by Program Headers
   
*******  
USBDM V4_12_1_160 (March 2017)  

- Updated GCC to 5.3.0  
- Updated wxWidgets to 3.1.1  
- GDB programming of secured devices improved  
- Restored disabling NMI for MKE device programming  
- Added CMSIS CPP wrapper stationery and examples  
- Updated various other stationery (CMP, USB)  
- Fixed for console for MKE devices  
- Minor bug fixes for GDB debug dialogues  
- Added MKV4xF16 devices (contribution by LN)  

*******
*******
** REQUIREMENTS **

* BDM firmware must be updated
* Current drivers must be used

*******
**See USBDM V4_11_1_70 release for older history**

