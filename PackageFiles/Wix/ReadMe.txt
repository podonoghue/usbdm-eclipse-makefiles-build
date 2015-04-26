USBDM V4.10
=========================
V4.10.5 (May 2013) -
   - Added support for Codewarrior 10.4 Release
   - Added support for Eclipse CDT projects using Codesourcery (USBDM New project Wizard)
   - Added Plugin for using USBDM + GDB with Eclipse
   - Updated Codesourcery and USBDM API examples (for Eclipse)
   - Updated Codesourcery instructions in help files
   - Bug fixes to GDB sprites
   - OpenSDA firmware now supports CDC interface (serial over USB).
   - Updated Kinetis device description files (Added devices, added GDB information)
   - Updated Codlfire device description files (Added GDB information)
   - Fixes to programmer GUI (setting trim options)
   - Updated OpenSDA USBDM firmware to work with later versions of OpenSDA bootloaders 
   
V4.10.4 (January 2013) -
   - Added support for Codewarrior 10.3 Release (This version does not work with the BETA)
   - Added customisable security options to programmers
   - Improved HCS08/HCS12 programming speeds (15~30%)
   - Added Codesourcery and USBDM API examples to installation
   - Updated/added Codesourcery instructions to help files
   - Numerous bug fixes to GDB Server
   - Improvements to handling secured devices
   - Added Examples to installation
   - Added OpenSDA firmware (This allows use of FRDM-KL25 board as general purpose Kinetis BDM)
   
V4.10.3 (November 2012) -
   - Updated device driver installation (V1.0.1) (removed unnecessary driver). 
   - ELF Files now supported for MC56F80xx devices.
   - Changed to shared DLLs build for wxWidgets.
   - Bug fixes:
     - DSC Access to ONCE registers when target running
     - Fixed BDM doing reset when setting target even if already powered. 
       This was interfering with doing a 'gentle' connection to a running target.
     - ARM interface now reports access errors on failing memory access rather than following access.
     - Corrected corruption in large reads for ARM GDI Interface.

V4.10.2 (October 2012) -
   - Updated installer for Codewarrior 10.3 Beta
   - Changed to shared DLLs build for wxWidgets
   - Changed to Make based projects
   - Support added for Kinetis KLxx devices
   - Updated libusbx version (& changed to static linkage)
   Bug Fixes
     - Kinetis & CFV1 targets now correctly support RAM only targets (again)
     - Fixes for an output glitch on USBDM_JMxx_CLD & CLC. (firmware)
     - Kinetis-SWD reports memory read/write errors on failing access
       (not following access) (firmware) 
  
V4.10.0 (September 2012) -
   - Improved ARM-JTAG interface speed.
   - Added support for ARM-SWD interfaces (requires different hardware). 
     ARM-SWD is much faster than ARM-JTAG. For reference, programming a
     file to flash using Codewarrior 10.2:
                      Readback     Without
                      verify       readback
      - OSJTAG        1m 20s         53s      
      - USBDM-JTAG       47s         23s
      - USBDM-SWD        21s         17s
   - ARM interfaces (JTAG & SWD) are now provided by USBDM interface DLL. This
     means that the ARM API is now uniform with the RS08, HCS08, HCS12 and 
     CFV1 interfaces. A compatibility DLL is provided for legacy use.
   - Simple ARM-SWD interface hardware designs are provided.
   - Bug fixes
      - Alignment error in programming code for some S12 targets
      - Corrected load addresses for ELF files for HCS08/HCS12
      - Added/corrected support for MCF51AG128
