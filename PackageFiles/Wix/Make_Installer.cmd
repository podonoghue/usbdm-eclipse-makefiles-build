@echo off
cls
set VERSION=4_12_1_290
set VERSIONn=4.12.1.290

cd

set WXWIDGETS_VERSION=312u

set WIX_DIR="C:\Program Files (x86)\WiX Toolset v3.11\bin"
if not exist %WIX_DIR% set WIX_DIR="C:\Program Files\WiX Toolset v3.9\bin"

set SRC_DIR=".."

set HEAT=%WIX_DIR%\heat.exe
set CANDLE=%WIX_DIR%\candle.exe
set LIGHT=%WIX_DIR%\light.exe
set TORCH=%WIX_DIR%\torch.exe
set PYRO=%WIX_DIR%\pyro.exe

set WIX_BUILD_DIR=wixBuildDir

rem .wxs regenerated Files 
set REBUILT_WXS=DeviceData.wxs Stationery.wxs FlashImages.wxs WizardPatchData.wxs Examples.wxs UpdateSite.wxs

set CANDLE_OPTIONS=-ext WixUIExtension -ext WixUtilExtension -arch x64
set LIGHT_OPTIONS=-ext WixUIExtension -ext WixUtilExtension -sw0204 -dWixUIBannerBmp=usbdm.bmp -di386_Bin=%SRC_DIR%\bin\i386-win-gnu -dx86_64_Bin=%SRC_DIR%\bin\x86_64-win-gnu
set LIGHT_DIRS=-b %SRC_DIR%\DeviceData -b %SRC_DIR%\Stationery -b %SRC_DIR%\FlashImages 
set LIGHT_DIRS=%LIGHT_DIRS% -b %SRC_DIR%\WizardPatches -b %SRC_DIR%\Examples -b %SRC_DIR%\UpdateSite
set LIGHT_DIRS=%LIGHT_DIRS% -b %SRC_DIR%\bin  -b %SRC_DIR%\bin\x86_64-win-gnu

set HEAT_OPTIONS=-srd -ke -gg -sfrag -template fragment -sw5150 -t HeatFilter.xml
set MSI_FILE=USBDM_%VERSION%_Win
set PATCH=patch_1_1

if "%1"=="patch" goto doPatch
if "%1"=="clean" goto doMake
if "%1"==""      goto doMake
echo "Unknown option %1"
goto finish

:doMake
rem del %MSI_FILE%.msi

if "%1"=="clean" goto finish

echo Cleaning build directory
if exist %WIX_BUILD_DIR% rmdir /S /Q %WIX_BUILD_DIR%
mkdir %WIX_BUILD_DIR%

%HEAT% dir %SRC_DIR%\DeviceData         %HEAT_OPTIONS% -cg Cg.DeviceData      -dr D.DeviceData        -out %WIX_BUILD_DIR%\DeviceData.wxs
%HEAT% dir %SRC_DIR%\Stationery         %HEAT_OPTIONS% -cg Cg.Stationery      -dr D.Stationery        -out %WIX_BUILD_DIR%\Stationery.wxs
%HEAT% dir %SRC_DIR%\FlashImages        %HEAT_OPTIONS% -cg Cg.FlashImages     -dr D.FlashImages       -out %WIX_BUILD_DIR%\FlashImages.wxs
%HEAT% dir %SRC_DIR%\WizardPatches      %HEAT_OPTIONS% -cg Cg.WizardPatchData -dr D.WizardPatchData   -out %WIX_BUILD_DIR%\WizardPatchData.wxs
%HEAT% dir %SRC_DIR%\Examples           %HEAT_OPTIONS% -cg Cg.Examples        -dr D.Examples          -out %WIX_BUILD_DIR%\Examples.wxs
%HEAT% dir %SRC_DIR%\UpdateSite         %HEAT_OPTIONS% -cg Cg.UpdateSite      -dr MANUFACTURER_FOLDER -out %WIX_BUILD_DIR%\UpdateSite.wxs
%HEAT% dir %SRC_DIR%\bin\i386-win-gnu   %HEAT_OPTIONS% -cg Cg.i386_Bin        -dr D.i386_Bin          -out %WIX_BUILD_DIR%\i386_Bin.wxs         -var wix.i386_Bin   
%HEAT% dir %SRC_DIR%\bin\x86_64-win-gnu %HEAT_OPTIONS% -cg Cg.x86_64_Bin      -dr INSTALLDIR          -out %WIX_BUILD_DIR%\x86_64_Bin.wxs

%CANDLE% %CANDLE_OPTIONS% -dProductVersion=%VERSIONn% -dWxWidgetsVer=%WXWIDGETS_VERSION% -dSrcDir="%SRC_DIR%" -o %WIX_BUILD_DIR%\ *.wxs %WIX_BUILD_DIR%\*.wxs
%LIGHT% %LIGHT_OPTIONS% %LIGHT_DIRS% -out %MSI_FILE% %WIX_BUILD_DIR%\*.wixobj

goto finish
:doPatch

%TORCH% -p -xi USBDM_4_9_0_Win.wixpdb %MSI_FILE%.wixpdb -out %PATCH%\diff.wixmst

%CANDLE% %PATCH%.wxs
%LIGHT%  %PATCH%.wixobj -out %PATCH%\%PATCH%.wixmsp
%PYRO%   %PATCH%\%PATCH%.wixmsp -out %PATCH%\%PATCH%.msp -t USBDMPatch %PATCH%\diff.wixmst

:finish
pause