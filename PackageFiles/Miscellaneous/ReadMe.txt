USBDM_4_10_6_140.Win.msi (March 2014)
======================================================================================= 
   - Initial support for Keil with ARM targets
   - Additional Kinetis devices (MKE04, MKE06, MK64F)
   - Bug fixes
   	- Corrected programmer file dialogue wildcards for .axf files
   	- Fixes for MKE devices (failed to program except after Mass Erase)
   - HCS08 Programmer on PA & PT targets no longer affects WDOG settings 
   
USBDM_4_10_6_130.Win.msi (March 2014)
======================================================================================= 
   - Bug fixes for PA4
   - Improved mass erase for Kinetis devices with reset problems
   - Bug fix for MC56F80xx devices in CW 10 
   - Stripped some missed files.
   
usbdm_4.10.6.120-1-i386.deb (March 2014)
usbdm_4.10.6.120-1-amd64.deb (March 2014)
USBDM_4_10_6_120.Win.msi (March 2014)
======================================================================================= 
   - New features in Eclipse
      - Added project options to Eclipse plugin
      - Configuration editor (used for clock configuration)
      - Clock configurations for Kinetis devices
      - Clock configurations for (some) Coldfire devices
      - Standard Peripheral Library & CMSIS for STM devices
   - Bug Fixes
      - Fixed bug affecting 9S08AC8 and similar (small RAM memory HCS08 devices)
      - Fixed bug affecting 9s08PT16 and similar (removed needless restriction on EEPROM alignment) 
   - Firmware
      - Greatly extended timeouts in ARM interfaces.  Improves operation with slow clocks (16kHz)
   - Stripped binaries to reduce size
	
usbdm_4.10.6.110-1-i386.deb (February 2014)
usbdm_4.10.6.110-1-amd64.deb (February 2014)
USBDM_4_10_6_110.Win.msi (February 2014)
======================================================================================= 
   New features in Eclipse
   - Added Peripheral View (Kinetis devices)
   - Added SVD files and derived header files
   - Added CMSIS-RTX support (Kinetis devices)
   - Added UART support for some devices (Kinetis devices)
   - Added Clock support for some devices (Kinetis devices)
   Corrected errors in programmer device files
   
usbdm_4.10.6.100-1-i386.deb (November 2013)
usbdm_4.10.6.100-1-amd64.deb (November 2013)
USBDM_4_10_6_110.Win.msi (December 2013)
======================================================================================= 
   - Added Eclipse Peripheral View 

USBDM_4_10_6_100.Win.msi (November 2013)
======================================================================================= 
   - Modified GDB server interrupt masking (ARM+CFV1) 
   - Added interrupt masking option to GDB server
   - Eclipse examples updated
   - NOTE:  The Win versions of the software are no longer compressed with UPX so
     the executables and downloads are much larger.  The compression was greatly
     affecting the installation time of the .msi file.  This change also improves
     the start-up time of the programs.
   
usbdm_4.10.6.80-1-i386.deb (November 2013)
usbdm_4.10.6.80-1-amd64.deb (November 2013)
USBDM_4_10_6_80.Win.msi (November 2013)
======================================================================================= 
   - Added support for 9S08PA4 & 9S08PA2
   - Minor fix to Codewarrior 10 interface
   - Added security options to Eclipse & Codewarrior plugins
   - WIN+LINUX versions are feature consistent
   
USBDM_4_10_6_60.Win.msi (November 2013)
======================================================================================= 
   - Deleted (Upload corrupted)

usbdm_4.10.6.40-2-i386.deb (October 2013)
usbdm_4.10.6.40-2-amd64.deb (October 2013)
======================================================================================= 
   -2 version Only change is dependencies
   - Updated installer for Ubuntu 32- & 64-bit system
   - Added Eclipse and Codewarrior 10.2 plug-ins
   - Note: I have been unable to get any debug functions to work with Codewarrior 10.2 
           on Ubuntu-64

USBDM V4.10.6c (October 2013)
======================================================================================= 
   - Installer updated for CW 10.5

   USBDM V4.10.6b (September 2013)
======================================================================================= 
   - Fix for command-line operation of programmers
   
usbdm_4.10.6-1-i386.deb (August 2013)
usbdm_4.10.6-1-amd64.deb (August 2013)
======================================================================================= 
   - Experimental build on Ubuntu 32- & 64-bit system
   - Note: These files do not contain Eclipse or Codewarrior plug-ins
   
USBDM V4.10.6a (August 2013)
======================================================================================= 
   - Fix for installer bug, installed programs should be unchanged
   
USBDM V4.10.6 (August 2013)
======================================================================================= 
This mainly concentrates on Eclipse support 
   - Eclipse Juno and Kepler:
      - Installation no longer adds files to Codesourcery directories
      - Support for other ARM GCC toolchains with Kinetis 
      - GDB server (sprite) bug fixes (GDB no longer dies if R0/D0 contains Exxxxxxx!).
      - GDB socket based server introduced (ARM+Coldfire).
      - GDB servers support float registers on ARM
      - Additional example projects for ARM targets.
      - Support for Floating point options with ARM Ltd toolchain
      - Newlib support (stdio using serial port) with  ARM Ltd toolchain
      - Added USBDM menu items (Examples, Configuration)
      - USBDM now includes make tools from GNU to conveniently support Builds on windows
      - Added a range of programming options to GDB server e.g. trimming of target clock. 
   - Programmer dialogues slightly smaller
   - Linux CDC devices (serial ports) appear as ttyUsbdm devices so they are easier to locate
   - Multiple Linux install scripts (Base, Codewarrior and Eclipse Juno installation)
   - Added additional Kinetis devices (KE02 family)
