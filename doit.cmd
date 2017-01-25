@echo off
cls

set HOME_DIR=%~dp0

set SOURCE_DIR=%HOME_DIR%ImageTests

rem Where Eclipse files are
set ECLIPSE_HOME=%HOME_DIR%

rem Where to place test files
set TEST_DIR=%ECLIPSE_HOME%\Tests

rem Where Binaries are kept
set BINARY_FILES=%ECLIPSE_HOME%\PackageFiles%\bin\i386-win-gnu\usbdm-flash-*.*

set IMAGE_TEST="tests\usbdm-flash-image-debug-test"
set OBJCOPY="c:\Apps\Freescale\KDS_3.2.0\Toolchain\bin\arm-none-eabi-objcopy.exe"

set OBJCOPY_DESTINATION=%SOURCE_DIR%\objcopy
set FLASHTEST_DESTINATION=%SOURCE_DIR%\imagetest

rem echo BINARY_FILES = %BINARY_FILES%
rem echo %HOME_DIR%

for %%f in (%BINARY_FILES%) do xcopy /Y %%f %TEST_DIR% >\nul

rem call %HOME_DIR%\CollectTestFiles.cmd

if exist "%FLASHTEST_DESTINATION%" rmdir /S/Q "%FLASHTEST_DESTINATION%"
mkdir "%FLASHTEST_DESTINATION%"
for %%f in (%SOURCE_DIR%\*.elf) do %IMAGE_TEST% %%f %FLASHTEST_DESTINATION%\%%~nf.sx

rem if exist "%OBJCOPY_DESTINATION%" rmdir /S/Q "%OBJCOPY_DESTINATION%"
rem mkdir "%OBJCOPY_DESTINATION%"
rem for %%f in (%SOURCE_DIR%\*.elf) do %OBJCOPY%    %%f %OBJCOPY_DESTINATION%\%%~nf.sx  -I elf32-littlearm -O srec

echo done
