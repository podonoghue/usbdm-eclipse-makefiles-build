Very brief instructions of using USBDM with Coldfire Flashet (CFFlasher)

The installed files allow the use of Freescale Coldfire Flasher (CF Flasher) with USBDM interfaces 
supporting Coldfire V2,3,4 devices.

==================================================
Installed Files:
usbdm-cff.dll  - This is a DLL that interfaces between CFFlasher and the libusb which communicates with the hardware.
usbdm-cff-debug.dll  - Debug version of above
libusb-1.0.dll - Used by above for USB access

When using CF Flasher open the Target Configuration dialogue and select "usbdm-cff" in the BDM Communication drop-down box.
Click the Configure button even though nothing visible happens (if you look carefully you may see the BDM activity light blink)!

Otherwise the use is as explained in the CF Flasher help files.

Example Command line use with batch file:

rem ------ cut here ------
@echo off

Echo Erasing target
CFFlasher.exe -t M52233DEMO -bdm usbdm-cff -e

Echo programming target
CFFlasher.exe -t M52233DEMO -bdm usbdm-cff -p MCF52233_INTERNAL_FLASH.elf.S19

rem ------ cut here ------
