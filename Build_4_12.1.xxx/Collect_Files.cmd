@echo off
cls
rem ***  Paths to various things
set VERSION_NUMBER=4
set VERSION_MINOR_NUMBER=12
set VERSION_SUFFIX=_V%VERSION_NUMBER%
set VERSION_MINOR_SUFFIX=_V%VERSION_NUMBER%_%VERSION_MINOR_NUMBER%

set HOME_DIR=%~dp0

set USBDM_ROOT=%HOME_DIR%\..

rem where to find applications (Eclipse folder)
set APP_ROOT=%USBDM_ROOT%\usbdm-eclipse-makefiles-build
set PACKAGE_FILEs=%APP_ROOT%\PackageFiles

rem where to find plugins (Eclipse folder)
set CODEWARRIOR_PLUGIN_ROOT=%USBDM_ROOT%\usbdm-codewarrior-plugins
set ECLIPSE_PLUGIN_ROOT=%USBDM_ROOT%\usbdm-eclipse-plugins

set INSTALLATION_DIR=Installation
set WIN32_APPLICATION_DIR=%INSTALLATION_DIR%
set BIN_DIR=%WIN32_APPLICATION_DIR%\bin
set BIN_DIRx32=%BIN_DIR%\i386-win-gnu
set BIN_DIRx64=%BIN_DIR%\x86_64-win-gnu
set UPDATE_SITE=%WIN32_APPLICATION_DIR%\UpdateSite
set CODEWARRIOR_UPDATE_SITE=%UPDATE_SITE%\CodewarriorUpdateSite
set ECLIPSE_UPDATE_SITE=%UPDATE_SITE%\EclipseUpdateSite
set FLASH_DIR=%WIN32_APPLICATION_DIR%\FlashImages
set SOURCE_DIR=2. Source
set PCB_DESTINATION=3. PCB
set DLL_VER=USBDM_DLL_V4

if not exist "%INSTALLATION_DIR%"                 mkdir "%INSTALLATION_DIR%"
if not exist "%WIN32_APPLICATION_DIR%"            mkdir "%WIN32_APPLICATION_DIR%"

rem goto checkthis

echo ***  ****************************************
echo ***  Do Win32 bin
echo ***  ****************************************
if not exist "%BIN_DIR%"       mkdir "%BIN_DIR%"
if not exist "%BIN_DIRx32%"    mkdir "%BIN_DIRx32%"
if not exist "%BIN_DIRx64%"    mkdir "%BIN_DIRx64%"

xcopy /E /I /Y /Q "%PACKAGE_FILEs%\bin\i386-win-gnu"            "%BIN_DIRx32%"
xcopy /E /I /Y /Q "%PACKAGE_FILEs%\bin\x86_64-win-gnu"          "%BIN_DIRx64%"
rem usbdm.dll is just a renamed usbdm.dll
copy "%PACKAGE_FILEs%\bin\i386-win-gnu\tbdml.dll"               "%BIN_DIRx32%\usbdm.dll"
copy "%PACKAGE_FILEs%\bin\i386-win-gnu\tbdml-debug.dll"         "%BIN_DIRx32%\usbdm-debug.dll"

rem echo ***  Shared\lib ...
rem copy "%APP_ROOT%\Shared\lib.i386\*.dll"                          "%BIN_DIR%"
rem copy "%APP_ROOT%\Shared\lib.x86_64\*.dll"                        "%BIN_DIRx64%"
echo ***  Shared\src\*.ico ...
copy "%APP_ROOT%\Shared\src\*.ico"                                   "%BIN_DIR%"

echo ***  ****************************************
echo ***  Do Configuration Files
echo ***  ****************************************
echo ***  DeviceData ...
xcopy /E /I /Y /Q "%PACKAGE_FILEs%\DeviceData"                  "%INSTALLATION_DIR%\DeviceData"
echo ***  Examples ...
xcopy /E /I /Y /Q "%PACKAGE_FILEs%\Examples"                    "%INSTALLATION_DIR%\Examples"
echo ***  Stationery
xcopy /E /I /Y /Q "%PACKAGE_FILEs%\Stationery"                  "%INSTALLATION_DIR%\Stationery"
set DIR_TO_REMOVE="%INSTALLATION_DIR%\Stationery\Packages\180.ARM_Peripherals\Testing"
if exist "%DIR_TO_REMOVE%"  rmdir /q /s "%DIR_TO_REMOVE%"
rem pause
echo ***  LaunchConfig ...
xcopy /E /I /Y /Q "%PACKAGE_FILEs%\LaunchConfig"                "%INSTALLATION_DIR%\LaunchConfig"
echo ***  WizardPatches ...
xcopy /E /I /Y /Q "%PACKAGE_FILEs%\WizardPatches"               "%INSTALLATION_DIR%\WizardPatches"
echo ***  Wix ...
rem removed for x64 hack
xcopy /E /I /Y /Q "%PACKAGE_FILEs%\Wix"                         "%INSTALLATION_DIR%\Wix"

:checkthis

set MISC_WIN1=TryProgrammer.cmd MakeTestImages.cmd usbdm.tgt 
echo ***  Miscellaneous (%MISC_WIN1%) ...
for %%f in (%MISC_WIN1%) do copy "%PACKAGE_FILEs%\MiscellaneousWin\%%f" "%BIN_DIR%"
set MISC_WIN2=usbdm-make.exe usbdm-rm.exe echo.exe libiconv2.dll libintl3.dll 
echo ***  Miscellaneous (%MISC_WIN2%) ...
for %%f in (%MISC_WIN2%) do copy "%PACKAGE_FILEs%\MiscellaneousWin\%%f" "%BIN_DIRx32%"

copy "%PACKAGE_FILEs%\Miscellaneous\*.s19"                              "%BIN_DIR%"
copy "%PACKAGE_FILEs%\Miscellaneous\*.wav"                              "%BIN_DIR%"
copy "%PACKAGE_FILEs%\Miscellaneous\*.specs"                            "%BIN_DIR%"
copy "%PACKAGE_FILEs%\Miscellaneous\*.xlkr"                             "%BIN_DIR%"
copy "%PACKAGE_FILEs%\Miscellaneous\*.xml"                              "%BIN_DIR%"
copy "%PACKAGE_FILEs%\Miscellaneous\*.elf"                              "%BIN_DIR%"

echo ***  ReadMeWizard ...
copy "%PACKAGE_FILEs%\WizardPatches\ReadMeWizard.txt" "%BIN_DIR%"

echo ***  Copy licences ...
if not exist "%INSTALLATION_DIR%\Licenses"             mkdir "%INSTALLATION_DIR%\Licenses"
copy "%PACKAGE_FILEs%\Licenses\*.*"                  "%INSTALLATION_DIR%\Licenses"

echo ***  Copy TCL Scripts ...
copy "%PACKAGE_FILEs%\scripts\*.tcl"                  "%BIN_DIR%"

echo ***  Do Win32 drivers
if not exist "%INSTALLATION_DIR%\WinDrivers"                              mkdir "%INSTALLATION_DIR%\WinDrivers"
xcopy /E /I /Y /Q "%PACKAGE_FILEs%\WinDrivers"                          "%INSTALLATION_DIR%\WinDrivers" 

echo *** Old USBDM GDI File
copy "%PACKAGE_FILEs%\MiscellaneousWin\usbdm_gdi12.dll"                    "%BIN_DIRx32%"

echo *** Old Freemaster Files
copy "%PACKAGE_FILEs%\MiscellaneousWin\usbdm-arm.4.dll"                    "%BIN_DIRx32%"

echo *** CFFlasher Files
copy "%PACKAGE_FILEs%\MiscellaneousWin\USBDM-CFFlasher-Readme.txt"         "%BIN_DIR%"
rem copy "%APP_ROOT%\Usbdm_DLL\usbdm-cff.i386-win-gnu\*.dll"                           "%BIN_DIRx32%"
rem copy "%APP_ROOT%\Usbdm_DLL\usbdm-cff-debug.i386-win-gnu\*.dll"                     "%BIN_DIRx32%"

echo ***  ****************************************
echo ***  Do Firmware files
echo ***  ****************************************
xcopy /E /I /Y /Q "%PACKAGE_FILEs%\FlashImages"                      "%FLASH_DIR%"

rem pause
:checkthis2
echo ***  ****************************************
echo ***  Do Codewarrior Plugin files
echo ***  ****************************************
if exist "%CODEWARRIOR_UPDATE_SITE%"\                           del /q /s "%CODEWARRIOR_UPDATE_SITE%"\*.*
echo xcopy /E /I /Y /Q "%CODEWARRIOR_PLUGIN_ROOT%"\UpdateSite             "%CODEWARRIOR_UPDATE_SITE%"
xcopy /E /I /Y /Q "%CODEWARRIOR_PLUGIN_ROOT%"\UpdateSite                  "%CODEWARRIOR_UPDATE_SITE%"

echo ***  ****************************************
echo ***  Do Eclipse Plugin files
echo ***  ****************************************
if exist "%ECLIPSE_UPDATE_SITE%"\                           del /q /s "%ECLIPSE_UPDATE_SITE%"\*.*
echo xcopy /E /I /Y /Q "%ECLIPSE_PLUGIN_ROOT%"\UpdateSite             "%ECLIPSE_UPDATE_SITE%"
xcopy /E /I /Y /Q "%ECLIPSE_PLUGIN_ROOT%"\UpdateSite                  "%ECLIPSE_UPDATE_SITE%"

set PLUGIN_CLEANUP=logs.zip MakeCopy.cmd SignIt.cmd .gitignore CertificateChain.pem .project Provider.cfg
for %%f in (%PLUGIN_CLEANUP%) do del /q "%CODEWARRIOR_UPDATE_SITE%"\%%f
for %%f in (%PLUGIN_CLEANUP%) do del /q "%ECLIPSE_UPDATE_SITE%"\%%f

echo **********=================**************
echo **********=================**************
echo **********=================**************

goto allDone

:allDone
rem pause
