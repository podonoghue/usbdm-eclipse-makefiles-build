@echo off
cls
set VERSION=4_11_1_20
set MSI_FILE=USBDM_%VERSION%_Win

msiexec /i %MSI_FILE% /l*v usbdmInstall.log