@echo off

set HW_VERSION=4_0_0
set INSTALLATION_DIR=1. Installation
set LINUX32_INSTALLATION_DIR=%INSTALLATION_DIR%\Linux32
set DOCUMENTATION_INSTALLATION_DIR=%INSTALLATION_DIR%\Documentation
set WIN32_APPLICATION_DIR=%INSTALLATION_DIR%\WinApplications
set BIN_DIR=%WIN32_APPLICATION_DIR%\bin

cd %BIN_DIR%
rename tcl85.dll tcl85.xxx
for %%f in ("*.exe") do strip --strip-all "%%f"
for %%f in ("*.dll") do strip --strip-all "%%f"
rename tcl85.xxx tcl85.dll

pause