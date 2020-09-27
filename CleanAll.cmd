@echo off

set OLD_PATH=%PATH%
rem echo %PATH%

rem Unix style utilities
set MSYS_HOME=C:\Apps\msys64

rem 64-bit version of compiler etc
set MINGW_HOME_64=C:\Apps\msys64\mingw64

rem 32-bit version of compiler etc
set MINGW_HOME_32=C:\Apps\msys64\mingw32

rem Do 64-bit builds
set PATH=%MINGW_HOME_64%\bin;%MSYS_HOME%\bin;%MSYS_HOME%\usr\bin;
make -f Makefile-x64.mk clean BITNESS=64

rem pause

rem Do 32-bit builds
set PATH=%MINGW_HOME_32%\bin;%MSYS_HOME%\bin;%MSYS_HOME%\usr\bin;
make -f Makefile-x32.mk clean BITNESS=32 

pause