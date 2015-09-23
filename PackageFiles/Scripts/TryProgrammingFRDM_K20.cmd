@echo off
echo ================================================================
echo.
echo Batch file showing examples of command-line flash programming
echo.
echo ================================================================

set FLASHCOMMAND=UsbdmFlashProgrammer-debug.exe
set IMAGEFILE=Image_MKxxDX128_5.sx
set DEVICE=FRDM_K20D50M
cls

echo Programming an image without trimming the clock
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -erase=mass -program -security=Unsecured %IMAGEFILE%
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -erase=mass -program -security=Unsecured %IMAGEFILE%
echo error level is %ERRORLEVEL%
if not ERRORLEVEL 1 goto phase2
echo Programming image failed
goto report

:phase2
echo Success!

echo Verifying programmed image
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -verify -security=Unsecured %IMAGEFILE%
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -verify -security=Unsecured %IMAGEFILE%
echo error level is %ERRORLEVEL%
if not ERRORLEVEL 1 goto phase3
echo Verifying image failed
goto report

:phase3
echo Success!

echo Programming image with custom security value
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -erase=mass -program -securityValue=123456789ABCDEF0FFFFFFFFFEFFFFFF %IMAGEFILE%
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -erase=mass -program -securityValue=123456789ABCDEF0FFFFFFFFFEFFFFFF %IMAGEFILE%
echo error level is %ERRORLEVEL%
if not ERRORLEVEL 1 goto phase3b
echo Programming image with custom security failed
goto report

:phase3b
echo Success!

echo Programming image with partition value
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -erase=mass -program -security=Unsecured -flexNVM=38,09 %IMAGEFILE%
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -erase=mass -program -security=Unsecured -flexNVM=38,09 %IMAGEFILE%
if not ERRORLEVEL 1 goto phase4
echo Programming image with partition value failed
goto report

:phase4
echo Success!

echo Programming an image and securing
echo %FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -program -security=Secured %IMAGEFILE%
%FLASHCOMMAND% -device=%DEVICE% -vdd=3v3 -program -security=Secured %IMAGEFILE%
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
if %ERRORLEVEL%==1  echo   Programming parameters incorrect
if %ERRORLEVEL%==2  echo   Wrong SDID (incorrect target type)
if %ERRORLEVEL%==3  echo   Verification of Flash failed
if %ERRORLEVEL%==4  echo   General BDM error
if %ERRORLEVEL%==5  echo   Device is not blank
if %ERRORLEVEL%==6  echo   No USBDM devices found
if %ERRORLEVEL%==7  echo   Failed to open USBDM device
if %ERRORLEVEL%==8  echo   Failed to connect to target
if %ERRORLEVEL%==9  echo   Failed to set target type
if %ERRORLEVEL%==10 echo   Failed to write to target
if %ERRORLEVEL%==11 echo   Failed to read from target
if %ERRORLEVEL%==12 echo   Failed to reset target
if %ERRORLEVEL%==13 echo   Trimming target clock failed
if %ERRORLEVEL%==14 echo   Target is secured
if %ERRORLEVEL%==15 echo   Flash command failed
if %ERRORLEVEL%==16 echo   Failed to find a suitable FCDIV value (clock problem)

echo errLevel=%ERRORLEVEL%
:end