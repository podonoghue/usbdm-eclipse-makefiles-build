@echo off

rem Where Eclipse files are
set ECLIPSE_HOME=.

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

rem pause
 