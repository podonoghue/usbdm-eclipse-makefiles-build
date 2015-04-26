@echo off
cls
rem ***  Paths to various things
set VERSION_NUMBER=4
set VERSION_MINOR_NUMBER=10
set VERSION_SUFFIX=_V%VERSION_NUMBER%
set VERSION_MINOR_SUFFIX=_V%VERSION_NUMBER%_%VERSION_MINOR_NUMBER%

rem where to find applications (Eclipse folder)
set APP_ROOT=..\EclipseUSBDM

rem where to find applications (Eclipse folder)
set PLUGIN_ROOT=..\EclipsePlugin

rem where to find documentation (Eclipse folder)
set DOC_ROOT=..\EclipseUSBDM

rem where to find 'fixed' stuff
set REFERENCE_ROOT=..\Reference

rem where to find JMxx/JS16 firmware
set CW_JB16_ROOT=..\USBDM_JB16%VERSION_MINOR_SUFFIX%
set CW_JMxx_ROOT=..\CodewarriorUSBDM\USBDM_JMxx%VERSION_MINOR_SUFFIX%
set CW_Kinetis_ROOT=..\CodewarriorUSBDM\USBDM_Kinetis

rem where to find PCBs
set PCB_ROOT=..\PCB

set WIN_RAR=c:\Program Files\WinRAR\rar.exe
set HW_VERSION=4_0_0
set INSTALLATION_DIR=1. Installation
set LINUX32_INSTALLATION_DIR=%INSTALLATION_DIR%\Linux32
set DOCUMENTATION_INSTALLATION_DIR=%INSTALLATION_DIR%\Documentation
set WIN32_APPLICATION_DIR=%INSTALLATION_DIR%\WinApplications
set BIN_DIR=%WIN32_APPLICATION_DIR%\bin
set INSTALL_DIR=%WIN32_APPLICATION_DIR%\Install
set FLASH_DIR=%BIN_DIR%\FlashImages
set SOURCE_DIR=2. Source
set PCB_DESTINATION=3. PCB
set DLL_VER=USBDM_DLL_V4

if "%1"=="C" goto compress
if "%1"=="c" goto compress

if not exist "%INSTALLATION_DIR%"                 mkdir "%INSTALLATION_DIR%"
if not exist "%WIN32_APPLICATION_DIR%"            mkdir "%WIN32_APPLICATION_DIR%"
if not exist "%LINUX32_INSTALLATION_DIR%"         mkdir "%LINUX32_INSTALLATION_DIR%"
if not exist "%DOCUMENTATION_INSTALLATION_DIR%"   mkdir "%DOCUMENTATION_INSTALLATION_DIR%"

echo ***  ****************************************
echo ***  Do Win32 bin
echo ***  ****************************************
if not exist "%BIN_DIR%"           mkdir "%BIN_DIR%"

rem "%INSTALLATION_DIR%\bin"
rem ======================================================


:doPCBFiles
echo ***  ****************************************
echo ***  Do PCB Design PDFs
echo ***  ****************************************
set Adapter_Files=KinetisAdapter
set JB16PCB_Files=TBDML_JB16_SOIC20[Minimal] TBDML_JB16_SOIC28[Minimal] USBDM_JB16_SOIC28[USB_Stick]
set JS16PCB_Files=USBDM_JS16CWJ USBDM_CF_JS16CWJ USBDM_SWD_JS16CWJ USBDM_SWD_SER_JS16CWJ USBDM_CF_SER_JS16CWJ
set JS16PCB_OldFiles=USBDM_SER_JS16CWJ
set JMxxPCB_Files= USBDM_CF_JMxxCLD_V3
set JMxxPCB_OldFiles=USBDM_JMxxCLD

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
for %%f in (%JS16PCB_Files%)    do copy %PCB_ROOT%\%%f\%%f.pdf "%FLASH_DIR%\JS16"
echo ***  JMxx...
for %%f in (%JMxxPCB_Files%)    do copy %PCB_ROOT%\%%f\%%f.pdf "%FLASH_DIR%\JMxx"

echo ***  ****************************************
echo ***  Source Folder
echo ***  ****************************************
if not exist "%SOURCE_DIR%"                      mkdir "%SOURCE_DIR%"

echo ***  Copy Target Firmware source files
copy  %CW_JMxx_ROOT%\..\USBDM*.zip                     "%SOURCE_DIR%"
copy "%CW_JB16_ROOT%\*.zip"                            "%SOURCE_DIR%"

echo ***  Copy Eclipse backup files
copy "%APP_ROOT%\*.zip"                                "%SOURCE_DIR%"

rem echo ***  Copy misc spreadsheets
rem copy "..\..\USBDM\Misc\BDM_Timing.xls"                 "%SOURCE_DIR%"

echo ***  Copy Flash programming files
"%WIN_RAR%" a -ep1 -idq "%SOURCE_DIR%\Flash_Programming_Routines(Legacy)" "..\Flash_Programming_Routines"

echo ***  ****************************************
echo ***  PCB Folder
echo ***  ****************************************

if not exist "%PCB_DESTINATION%"                         mkdir "%PCB_DESTINATION%"
del /Q                                                         "%PCB_DESTINATION%\*.*"
if not exist "%PCB_DESTINATION%\Adapter_%HW_VERSION%"    mkdir "%PCB_DESTINATION%\Adapter_%HW_VERSION%"
if not exist "%PCB_DESTINATION%\JB16_PCB_%HW_VERSION%"   mkdir "%PCB_DESTINATION%\JB16_PCB_%HW_VERSION%"
if not exist "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"   mkdir "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"
if not exist "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"   mkdir "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"

echo ***  Do PDF assembly instructions
for %%f in (%Adapter_Files%)    do copy %PCB_ROOT%\Adapters\%%f\%%f.pdf    "%PCB_DESTINATION%\Adapter_%HW_VERSION%"
for %%f in (%JB16PCB_Files%)    do copy %PCB_ROOT%\Old_Schematics\%%f.pdf  "%PCB_DESTINATION%\JB16_PCB_%HW_VERSION%"
for %%f in (%JS16PCB_Files%)    do copy %PCB_ROOT%\%%f\%%f.pdf             "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"
for %%f in (%JS16PCB_OldFiles%) do copy %PCB_ROOT%\Old_Schematics\%%f.pdf  "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"
for %%f in (%JMxxPCB_Files%)    do copy %PCB_ROOT%\%%f\%%f.pdf             "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"
for %%f in (%JMxxPCB_OldFiles%) do copy %PCB_ROOT%\Old_Schematics\%%f.pdf  "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"
echo ***  Do PCB Source files
for %%f in (%JS16PCB_Files%)    do copy "%PCB_ROOT%\%%f.zip"   "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"
for %%f in (%JMxxPCB_Files%)    do copy "%PCB_ROOT%\%%f.zip"   "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"
echo ***  Do Gerber files       
for %%f in (%Adapter_Files%)  do "%WIN_RAR%" a -ep -idq "%PCB_DESTINATION%\Adapter_%HW_VERSION%\%%f_Gerbers"  "%PCB_ROOT%\Adapters\%%f\Project Outputs for %%f"
for %%f in (%JS16PCB_Files%)  do "%WIN_RAR%" a -ep -idq "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%\%%f_Gerbers" "%PCB_ROOT%\%%f\Project Outputs for %%f"
for %%f in (%JMxxPCB_Files%)  do "%WIN_RAR%" a -ep -idq "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%\%%f_Gerbers" "%PCB_ROOT%\%%f\Project Outputs for %%f"
goto allDone


:allDone
pause
