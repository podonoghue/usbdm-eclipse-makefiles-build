@echo off
set OLD_PATH=%PATH%
rem echo %PATH%

set MAKE=mingw32-make

set PATH=C:\Apps\mingw-w64\x86_64-5.1.0-posix-seh-rt_v4-rev0\mingw64\bin;%OLD_PATH%
%MAKE% -f Makefile-x64.mk all

set PATH=C:\Apps\MinGW\bin;%OLD_PATH%
%MAKE% -f Makefile.mk all

pause