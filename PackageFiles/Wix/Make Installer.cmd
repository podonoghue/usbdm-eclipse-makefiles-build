@echo off
cls
set VERSION=4_11_1_10
set VERSIONn=4.11.1.10

set WXWIDGETS_VERSION=30u

set WIX_DIR="C:\Program Files (x86)\WiX Toolset v3.9\bin"
if not exist %WIX_DIR% set WIX_DIR="C:\Program Files\WiX Toolset v3.9\bin"

set HEAT=%WIX_DIR%\heat.exe
set CANDLE=%WIX_DIR%\candle.exe
set LIGHT=%WIX_DIR%\light.exe
set TORCH=%WIX_DIR%\torch.exe
set PYRO=%WIX_DIR%\pyro.exe

set WIX_BUILD_DIR=wixBuildDir

set ECLIPSE_PLUGIN_SOURCE=plugins\eclipse
set CODEWARRIOR_PLUGIN_SOURCE=plugins\codewarrior

rem delete artifact.jar and content.jar
for %%f in (%ECLIPSE_PLUGIN_SOURCE%\usbdm\artifacts.jar %ECLIPSE_PLUGIN_SOURCE%\usbdm\content.jar) do if exist %%f del /Q %%f
for %%f in (%CODEWARRIOR_PLUGIN_SOURCE%\usbdm\artifacts.jar %CODEWARRIOR_PLUGIN_SOURCE%\usbdm\content.jar) do if exist %%f del /Q %%f

rem .wxs regenerated Files 
set REBUILT_WXS=DeviceData.wxs Stationery.wxs FlashImages.wxs WizardPatchData.wxs Examples.wxs
set REBUILT_WXS=%REBUILT_WXS% EclipsePlugin_1.wxs EclipsePlugin_2.wxs EclipsePlugin_3.wxs EclipsePlugin_4.wxs EclipsePlugin_5.wxs
set REBUILT_WXS=%REBUILT_WXS% EclipseKepler.wxs KinetisDesignStudio.wxs

set CANDLE_OPTIONS=-ext WixUIExtension -ext WixUtilExtension
set LIGHT_OPTIONS=-ext WixUIExtension -ext WixUtilExtension -sw0204 -dWixUIBannerBmp=usbdm.bmp
set LIGHT_DIRS=-b bin\DeviceData -b bin\Stationery -b bin\FlashImages -b WizardPatches -b Examples -b %CODEWARRIOR_PLUGIN_SOURCE% -b %ECLIPSE_PLUGIN_SOURCE%

set HEAT_OPTIONS=-srd -ke -gg -sfrag -template fragment -sw5150
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

if exist %WIX_BUILD_DIR% rmdir /S /Q %WIX_BUILD_DIR%
mkdir %WIX_BUILD_DIR%

%HEAT% dir .\bin\DeviceData       %HEAT_OPTIONS% -cg Cg.DeviceData        -dr D.DeviceData       -out %WIX_BUILD_DIR%\DeviceData.wxs
%HEAT% dir .\bin\Stationery       %HEAT_OPTIONS% -cg Cg.Stationery        -dr D.Stationery       -out %WIX_BUILD_DIR%\Stationery.wxs
%HEAT% dir .\bin\FlashImages      %HEAT_OPTIONS% -cg Cg.FlashImages       -dr D.FlashImages      -out %WIX_BUILD_DIR%\FlashImages.wxs
%HEAT% dir .\WizardPatches        %HEAT_OPTIONS% -cg Cg.WizardPatchData   -dr D.WizardPatchData  -out %WIX_BUILD_DIR%\WizardPatchData.wxs
%HEAT% dir .\Examples             %HEAT_OPTIONS% -cg Cg.Examples          -dr D.Examples         -out %WIX_BUILD_DIR%\Examples.wxs
%HEAT% dir .\plugins\codewarrior  %HEAT_OPTIONS% -cg Cg.CWEclipsePlugin   -dr D.CWEclipsePlugins -out %WIX_BUILD_DIR%\CWEclipsePlugin.wxs
%HEAT% dir .\plugins\eclipse      %HEAT_OPTIONS% -cg Cg.EclipsePlugins    -dr D.EclipsePlugins   -out %WIX_BUILD_DIR%\EclipsePlugins.wxs

%CANDLE% %CANDLE_OPTIONS% -dProductVersion=%VERSIONn% -dWxWidgetsVer=%WXWIDGETS_VERSION% -o %WIX_BUILD_DIR%\ *.wxs %WIX_BUILD_DIR%\*.wxs
%LIGHT% %LIGHT_OPTIONS% %LIGHT_DIRS% -out %MSI_FILE% %WIX_BUILD_DIR%\*.wixobj

rem del *.wixpdb
rem rmdir /S /Q %WIX_BUILD_DIR%

goto finish
:doPatch

%TORCH% -p -xi USBDM_4_9_0_Win.wixpdb %MSI_FILE%.wixpdb -out %PATCH%\diff.wixmst

%CANDLE% %PATCH%.wxs
%LIGHT%  %PATCH%.wixobj -out %PATCH%\%PATCH%.wixmsp
%PYRO%   %PATCH%\%PATCH%.wixmsp -out %PATCH%\%PATCH%.msp -t USBDMPatch %PATCH%\diff.wixmst

:finish
pause