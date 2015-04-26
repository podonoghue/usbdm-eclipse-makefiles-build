@echo off

set PROG_DIR=c:\Program Files
set ZIP_COMMAND="%PROG_DIR%\7-Zip\7z.exe"

set PROJECTS=
set PROJECTS=%PROJECTS% ArduinoKL25 ArduinoMK20 ArduinoMK22 ArduinoMK64

set PROJECTS=%PROJECTS% MKE02Z64M2_FRDM_Serial
set PROJECTS=%PROJECTS% MKL25Z128M4_FRDM MKL25Z128M4_FRDM_Demo MKL25Z128M4_FRDM_DemoCPP

set PROJECTS=%PROJECTS% MK20DX128M5_FRDM MK20DX128M5_FRDM_Demo MK20DX128M5_LCD_DieRoll_CPP MK20DX128M5_cmsis_rtos 
set PROJECTS=%PROJECTS% MK22FN1M0M12_FRDM_Demo
set PROJECTS=%PROJECTS% MK64FN1M0M12_FRDM_Demo

set PROJECTS=%PROJECTS% MCF51JF128_Tower MCF51JF128_Tower_Demo

set PROJECTS=%PROJECTS% MCF52233_cpp 

set PROJECTS=%PROJECTS% STM32_cmsis_rtos

set PROJECTS=%PROJECTS% USBDM_API_Example
set PROJECTS=%PROJECTS% USBDM_Kinetis_Firmware

echo *** Cleaning %PROJECTS%
for %%f in (%PROJECTS%) do if exist %%f\OpenSDAv1              rmdir /S /Q %%f\OpenSDAv1
for %%f in (%PROJECTS%) do if exist %%f\OpenSDAv1_Unique_ID    rmdir /S /Q %%f\OpenSDAv1_Unique_ID
for %%f in (%PROJECTS%) do if exist %%f\OpenSDAv2_0            rmdir /S /Q %%f\OpenSDAv2_0
for %%f in (%PROJECTS%) do if exist %%f\OpenSDAv2_0_Unique_ID  rmdir /S /Q %%f\OpenSDAv2_0_Unique_ID
for %%f in (%PROJECTS%) do if exist %%f\OpenSDAv2_1            rmdir /S /Q %%f\OpenSDAv2_1
for %%f in (%PROJECTS%) do if exist %%f\OpenSDAv2_1_Unique_ID  rmdir /S /Q %%f\OpenSDAv2_1_Unique_ID
for %%f in (%PROJECTS%) do if exist %%f\Debug   rmdir /S /Q %%f\Debug
for %%f in (%PROJECTS%) do if exist %%f\Release rmdir /S /Q %%f\Release
for %%f in (%PROJECTS%) do if exist "%%f\Thread Example" rmdir /S /Q "%%f\Thread Example"
for %%f in (%PROJECTS%) do if exist "%%f\Timer Example" rmdir /S /Q "%%f\Timer Example"

for %%f in (%PROJECTS%) do if exist %%f.zip del %%f.zip
for %%f in (%PROJECTS%) do if exist %%f %ZIP_COMMAND% a -tzip %%f.zip %%f