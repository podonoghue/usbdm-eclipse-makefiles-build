@echo off
cls
set VERSION=4_12_1_295
set MSI_FILE=USBDM_%VERSION%_Win

msiexec /x %MSI_FILE% /l*v usbdmUninstall.log