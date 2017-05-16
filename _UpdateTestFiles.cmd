@echo off

set HOME_DIR=%~dp0
set OLD_PATH=%PATH%
rem echo %PATH%

set MAKE=mingw32-make

set PATH=C:\Apps\mingw-w64\mingw64\bin;%OLD_PATH%
%MAKE% -f Makefile-x64.mk all

rem set PATH=C:\Apps\mingw-w64\i686-5.2.0-posix-dwarf-rt_v4-rev0\mingw32\bin;%OLD_PATH%
set PATH=C:\Apps\MinGW\bin;%OLD_PATH%
%MAKE% -f Makefile.mk all

set PATH=%OLD_PATH%

rem Where Eclipse files are
set ECLIPSE_HOME=%HOME_DIR%

rem Where to place test files
set TEST_DIR=%ECLIPSE_HOME%\Tests

rem Where Package Files are kept
set PACKAGE_FILES=%ECLIPSE_HOME%\PackageFiles

rem Where External DLLs are kept
set EXTERNAL_DLLS=%ECLIPSE_HOME%\Shared_V4\lib

rem Where Device data is kept
set DEVICE_DATA=%PACKAGE_FILES%\DeviceData

rem Where Binaries are kept
set BINARY_FILES=%PACKAGE_FILES%\bin\i386-win-gnu

if not exist "%TEST_DIR%" mkdir "%TEST_DIR%"

echo "Copying Binaries"
xcopy /E /I /Y "%BINARY_FILES%"     "%TEST_DIR%"

echo "Copying External DLLs"
xcopy /E /I /Y "%EXTERNAL_DLLS%"     "%TEST_DIR%"

echo "Miscellaneous TCL files"
xcopy /E /I /Y "%PACKAGE_FILES%\Miscellaneous\"*.tcl  "%TEST_DIR%"

echo "Copying Device data"
xcopy /S /Y /I "%DEVICE_DATA%"      "%TEST_DIR%\DeviceData"

pause
 