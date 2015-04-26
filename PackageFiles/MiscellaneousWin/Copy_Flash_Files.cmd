@echo off
cls
rem ***  Paths to various things
set VERSION_NUMBER=4
set VERSION_MINOR_NUMBER=10
set VERSION_SUFFIX=_V%VERSION_NUMBER%
set VERSION_MINOR_SUFFIX=_V%VERSION_NUMBER%_%VERSION_MINOR_NUMBER%

set USBDM_ROOT=C:\Users\podonoghue\Development\USBDM

rem where to find 'fixed' stuff
set PACKAGE_FILES=%USBDM_ROOT%\usbdm-eclipse-makefiles-build\PackageFiles

rem where to find 'fixed' stuff
set REFERENCE_ROOT=%PACKAGE_FILES%\Miscellaneous

rem where to find JMxx/JS16 firmware
set CW_JB16_ROOT=%USBDM_ROOT%\USBDM_JB16%VERSION_MINOR_SUFFIX%
set CW_JMxx_ROOT=%USBDM_ROOT%\usbdm-firmware\USBDM_JMxx%VERSION_MINOR_SUFFIX%
set CW_Kinetis_ROOT=%USBDM_ROOT%\usbdm-firmware\USBDM_Kinetis

rem where to find PCBs
set PCB_ROOT=%USBDM_ROOT%\PCB

set WIN_RAR=c:\Program Files\WinRAR\rar.exe

set FLASH_DIR=.\FlashImages

echo ***  ****************************************
echo ***  Do Firmware files
echo ***  ****************************************

if not exist "%FLASH_DIR%"        mkdir "%FLASH_DIR%"
if not exist "%FLASH_DIR%\JB16"   mkdir "%FLASH_DIR%\JB16"
if not exist "%FLASH_DIR%\JS16"   mkdir "%FLASH_DIR%\JS16"
if not exist "%FLASH_DIR%\JMxx"   mkdir "%FLASH_DIR%\JMxx"
if not exist "%FLASH_DIR%\MKxx"   mkdir "%FLASH_DIR%\MKxx"
if not exist "%FLASH_DIR%\Tower"  mkdir "%FLASH_DIR%\Tower"

set MISCELLANEOUS_Files=FlashImagesList.txt OpenSDA.txt
echo ***  Copying %MISCELLANEOUS_Files%
for %%f in (%MISCELLANEOUS_Files%) do copy %REFERENCE_ROOT%\%%f "%FLASH_DIR%"

echo ***  JB16...
copy "%CW_JB16_ROOT%\bin\*.s19"                     "%FLASH_DIR%\JB16"
set MISCELLANEOUS_Files=OSBDM.pdf OSBDMe.pdf WTBDMS08.pdf
for %%f in (%MISCELLANEOUS_Files%) do copy "%REFERENCE_ROOT%\FlashImages"\%%f      "%FLASH_DIR%\JB16"
set MISCELLANEOUS_Files=USBDM_CF_JMxxCLD_V1.7.pdf
for %%f in (%MISCELLANEOUS_Files%) do copy "%REFERENCE_ROOT%\FlashImages"\%%f      "%FLASH_DIR%\JMxx"

echo ***  JS16...
set FIRMWARE_VERSIONS=USBDM_CF_JS16CWJ USBDM_JS16CWJ USBDM_CF_SER_JS16CWJ USBDM_SER_JS16CWJ USBDM_SWD_SER_JS16CWJ USBDM_SWD_JS16CWJ
for %%f in (%FIRMWARE_VERSIONS%) do copy "%CW_JMxx_ROOT%"\%%f\USBDM*.sx      "%FLASH_DIR%\JS16"
echo ***  JMxx...
set FIRMWARE_VERSIONS=USBDM_CF_JMxxCLD USBDM_CF_SER_JMxxCLD USBDM_JMxxCLC USBDM_JMxxCLD USBDM_JMxx_MC56F8006Demo
for %%f in (%FIRMWARE_VERSIONS%) do copy "%CW_JMxx_ROOT%"\%%f\USBDM*.sx      "%FLASH_DIR%\JMxx"
echo ***  MKxx...
set FIRMWARE_VERSIONS=OpenSDA OpenSDA_Unique_ID
for %%f in (%FIRMWARE_VERSIONS%) do copy "%CW_Kinetis_ROOT%"\%%f\*.sx        "%FLASH_DIR%\MKxx"
echo ***  TWR...
set FIRMWARE_VERSIONS=USBDM_TWR_CFV1 USBDM_TWR_HCS08 USBDM_TWR_Kinetis USBDM_TWR_CFVx USBDM_TWR_HCS12
for %%f in (%FIRMWARE_VERSIONS%) do copy "%CW_JMxx_ROOT%"\%%f\USBDM*.sx      "%FLASH_DIR%\Tower"

echo ***  ****************************************
echo ***  Do PCB Design PDFs
echo ***  ****************************************
set Adapter_Files=KinetisAdapter
set JB16PCB_Files=TBDML_JB16_SOIC20[Minimal] TBDML_JB16_SOIC28[Minimal] USBDM_JB16_SOIC28[USB_Stick]
set JS16PCB_OldFiles=USBDM_SER_JS16CWJ
set JMxxPCB_OldFiles=USBDM_JMxxCLD
set JS16PCB_Files=USBDM_CF_JS16CWJ_V1_3 USBDM_CF_SER_JS16CWJ_V2 USBDM_JS16CWJ_V1 USBDM_SWD_JS16CWJ_V1 USBDM_SWD_SER_JS16CWJ_V3_1
set JMxxPCB_Files=USBDM_CF_JMxxCLD_V3_1

echo PCB dir : %PCB_ROOT%
echo.
echo Copying Schematics from source directories
echo *** JB16...
for %%f in (%JB16PCB_Files%)    do copy %PCB_ROOT%\Old_Schematics\%%f.pdf "%FLASH_DIR%\JB16"
echo ***  Old JS16...
for %%f in (%JS16PCB_OldFiles%) do copy %PCB_ROOT%\Old_Schematics\%%f.pdf "%FLASH_DIR%\JS16"
echo ***  Old JMxx...
for %%f in (%JMxxPCB_OldFiles%) do copy %PCB_ROOT%\Old_Schematics\%%f.pdf "%FLASH_DIR%\JMxx"
echo ***  JS16...
for %%f in (%JS16PCB_Files%)    do copy %PCB_ROOT%\%%f\*.pdf "%FLASH_DIR%\JS16"
echo ***  JMxx...
for %%f in (%JMxxPCB_Files%)    do copy %PCB_ROOT%\%%f\*.pdf "%FLASH_DIR%\JMxx"

goto allDone

:allDone
pause
