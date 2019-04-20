@echo off

set ROOT=%~dp0
echo %ROOT%

set LIB_DIR=%ROOT%
   
set MINGW=C:\Apps\MinGW
rem set MINGW=C:\Apps\mingw-w64\i686-5.2.0-posix-dwarf-rt_v4-rev0\mingw32
set MINGW64=C:\Apps\mingw-w64\x86_64-5.2.0-posix-seh-rt_v4-rev0\mingw64
set WXWIGETS=C:\Apps\wxWidgets-3.1.2\lib\gcc_dll
set LIBUSB=C:\Apps\libusb-1.0.20
set COREUTILS=%ROOT%CoreUtils

set LIB_i386=%LIB_DIR%i386-win-gnu
set LIB_x86_64=%LIB_DIR%x86_64-win-gnu

set MINGW_LIBS=libgcc_s_dw2-1 libstdc++-6  pthreadGC2 tcl86 libxerces-c-3-1 libexpat-1 libiconv-2 libintl-8 zlib1
rem set MINGW_LIBS=libstdc++-6
rem set MINGW_OPT_LIBS=libgcc_s_dw2-1 tcl86 tcl86
set MINGW64_LIBS=libgcc_s_seh-1 libstdc++-6 libwinpthread-1 
set WXWIGETS_LIBS=wxbase30u_gcc_custom wxbase30u_net_gcc_custom wxmsw30u_adv_gcc_custom wxmsw30u_core_gcc_custom

if not exist %LIB_i386%      mkdir %LIB_i386%
if not exist %LIB_x86_64%    mkdir %LIB_x86_64%

for %%f in (%MINGW_LIBS%)     do copy  /Y    "%MINGW%\bin\%%f.dll"       "%LIB_i386%
rem for %%f in (%MINGW_OPT_LIBS%) do copy  /Y    "%MINGW%\opt\bin\%%f.dll"   "%LIB_i386%
for %%f in (%MINGW64_LIBS%)   do copy  /Y    "%MINGW64%\bin\%%f.dll"     "%LIB_x86_64%"
for %%f in (%WXWIGETS_LIBS%)  do copy  /Y    "%WXWIGETS%\%%f.dll"        "%LIB_i386%
for %%f in (%COREUTILS%\*.exe %COREUTILS%\*.dll)  do copy  /Y    "%%f"                       "%LIB_i386%

rem the 32-bit files are built by me as they are incompatible with MINGW
rem copy /Y %LIBUSB%\MINGW32\dll\libusb-1.0.dll       "%LIB_i386%
rem copy /Y %LIBUSB%\MINGW32\static\libusb-1.0.a      "%LIB_i386%\libusb-static-1.0.a
copy /Y %LIBUSB%\MINGW64\dll\libusb-1.0.dll       "%LIB_x86_64%"
copy /Y %LIBUSB%\MINGW64\static\libusb-1.0.a      "%LIB_x86_64%"\libusb-static-1.0.a

pause
