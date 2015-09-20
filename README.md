# usbdm-eclipse-makefiles-build
Current USBDM builds
=================================================

Source for USBDM binary files

Programmers and Utilities for Freescale microcontrollers

Refer to sourceforge for release files:
Release files: http://sourceforge.net/projects/usbdm/files/
Documentation: http://usbdm.sourceforge.net/

The projects can be build at the command line using the MakeAll or MakeAll.cmd files.

Alternatively the projects can be imported into Eclipse CDT and built using MinGW or Linux GCC

To Build under Windows
=====================
Pretty difficult - It needs lots of software installed.

Please read through the Common.mk file and look at all the paths defined

Packages required MinGW, Xerces-3-1-1, TCL, Java JDK, Wix, Windows Installer SDK and wxWidgets

To Build under Linux
=====================

Run LinuxPackages to install the developer version of several packages

Run MakeAll to build the binaries

Run CreateDebFile to Create the Deb file

Run Update to install the Deb file
