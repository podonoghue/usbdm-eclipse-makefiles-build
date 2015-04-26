@echo off
echo ================================================================
echo.
echo Batch file showing examples of command-line flash programming
echo.
echo ================================================================

set FLASHCOMMAND=CFV1_FlashProgrammer-debug.exe
set IMAGEFILE=TestMCF51CN128.elf.S19
set DEVICE=MCF51CN128
cls

echo Programming an image without trimming the clock
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -erase=mass -program -unsecure %IMAGEFILE%
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -erase=mass -program -unsecure %IMAGEFILE%
if not ERRORLEVEL 1 goto phase2
echo Programming image failed
goto report

:phase2
echo Success!

echo Verifying programmed image
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -verify -unsecure %IMAGEFILE%
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -verify -unsecure %IMAGEFILE%
if not ERRORLEVEL 1 goto phase3
echo Verifying image failed
goto report

:phase3
echo Success!

echo Programming clock trim on an already programmed device
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -program -trim=35 -erase=none
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -program -trim=35 -erase=none
if not ERRORLEVEL 1 goto phase4
echo Programming trim failed
goto end

:phase4
echo Success!

echo Programming an image with clock trim and securing
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -program -secure -trim=31.25 %IMAGEFILE%
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -program -secure -trim=31.25 %IMAGEFILE%
if not ERRORLEVEL 1 goto phase5
echo Programming image failed
goto report

:phase5
echo Success!

echo Verifying programmed image - this should fail as device is secured
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -verify %IMAGEFILE%
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -verify %IMAGEFILE%
if not ERRORLEVEL 1 goto phase6
echo Verifying image failed (as it should)
goto end

:phase6
echo Verify succeeded but it should have failed!!!!
goto report

:report
for %%e in (0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20) do if ERRORLEVEL %%e set errLevel=%%e
if %errLevel%==1  echo   Programming parameters incorrect
if %errLevel%==2  echo   Wrong SDID (incorrect target type)
if %errLevel%==3  echo   Verification of Flash failed
if %errLevel%==4  echo   General BDM error
if %errLevel%==5  echo   Device is not blank
if %errLevel%==6  echo   No USBDM devices found
if %errLevel%==7  echo   Failed to open USBDM device
if %errLevel%==8  echo   Failed to connect to target
if %errLevel%==9  echo   Failed to set target type
if %errLevel%==10 echo   Failed to write to target
if %errLevel%==11 echo   Failed to read from target
if %errLevel%==12 echo   Failed to reset target
if %errLevel%==13 echo   Trimming target clock failed
if %errLevel%==14 echo   Target is secured
if %errLevel%==15 echo   Flash command failed
if %errLevel%==16 echo   Failed to find a suitable FCDIV value (clock problem)

echo errLevel=%errLevel%
:end