# usbdm-eclipse-makefiles-build
Current USBDM builds
=======================

Source for USBDM binary files  

Programmers and Utilities for Freescale microcontrollers  

Refer to sourceforge for release files:  
* Release files: http://sourceforge.net/projects/usbdm/files/  
* Documentation: http://usbdm.sourceforge.net/  

The projects can be built at the command line using the MakeAll or MakeAll.cmd files.

Alternatively, the projects can be imported into Eclipse CDT and built using MinGW or Linux GCC

To Build under Windows  
=====================
Build using MINGW
See Installing MSYS2.txt for packages required.
Build using ./MakeAll using MINGW shell.

To Build under Linux
=====================
Ubuntu derivative e.g. Mint  

~~~~
cd WorkDirectory
sudo apt-get install git  
git clone https://github.com/podonoghue/usbdm-eclipse-makefiles-build.git  
git clone https://github.com/podonoghue/usbdm-eclipse-plugins.git  
cd usbdm-eclipse-makefiles-build  
sudo ./LinuxPackages  
./MakeAll  
./CreateDebFile  
sudo ./Update  
~~~~

**_Eclipse_** or **_Kinetis_** **_Design_** **_Studio_** should be run at least **once** before installing USBDM as the installer will run these programs as root which may create **inaccessible** log or configuration files.   

It looks for Eclipse and KDS in several locations.  
Update `usbdm-eclipse-makefiles-build/PackageFiles/MiscellaneousLinux/DEBIAN/postinst`, `prerm` files if required.
