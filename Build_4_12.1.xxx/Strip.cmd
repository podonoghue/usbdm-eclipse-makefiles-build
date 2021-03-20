@echo off

echo "Stripping Files..."

set HOME_DIRx=%~dp0

set STRIP32=C:\Apps\msys64\mingw32\bin\strip
set STRIP64=C:\Apps\msys64\mingw64\bin\strip
set HW_VERSION=4_0_0
set INSTALLATION_DIR=Installation
set DOCUMENTATION_INSTALLATION_DIR=%INSTALLATION_DIR%\Documentation
set WIN32_APPLICATION_DIR=%INSTALLATION_DIR%
set BIN_DIR=%WIN32_APPLICATION_DIR%\bin\
set X32_DIR=%BIN_DIR%\i386-win-gnu
set X64_DIR=%BIN_DIR%\x86_64-win-gnu

cd %HOME_DIRx%\%X32_DIR%
cd
set PROTECT_EXE=usbdm-make usbdm-rm
set PROTECT_DLL=tcl86 usbdm_gdi12
for %%f in (%PROTECT_EXE%) do rename %%f.exe %%f.xxx
for %%f in (%PROTECT_DLL%) do rename %%f.dll %%f.xxx

for %%f in ("*.exe") do %STRIP32% --strip-all "%%f"
for %%f in ("*.exe") do %STRIP32% --strip-all "%%f"
for %%f in ("*.dll") do %STRIP32% --strip-all "%%f"

for %%f in (%PROTECT_EXE%) do rename %%f.xxx %%f.exe
for %%f in (%PROTECT_DLL%) do rename %%f.xxx %%f.dll
cd %HOME_DIRx%

cd %HOME_DIRx%\%X64_DIR%
cd
for %%f in ("*.exe") do %STRIP64% --strip-all "%%f"
for %%f in ("*.exe") do %STRIP64% --strip-all "%%f"
for %%f in ("*.dll") do %STRIP64% --strip-all "%%f"
cd %HOME_DIRx%

pause