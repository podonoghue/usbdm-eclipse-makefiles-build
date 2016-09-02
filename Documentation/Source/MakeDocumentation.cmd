@echo off

set CURRENT_DIR=%~dp0
cd %CURRENT_DIR%
echo %CURRENT_DIR%

SET FILES=__USBDM_V4 __USBDM_FlashProgrammers _USBDM_CF_JMxx _USBDM_CF_JS16 _USBDM_Freedom _USBDM_JB16 _USBDM_JMxx _USBDM_JS16 

if not exist ..\External mkdir ..\External
if not exist ..\External\USBDM mkdir ..\External\USBDM
if not exist ..\External\USBDM_V4.12 mkdir ..\External\USBDM_V4.12

for %%f in (%FILES%) do doxygen %%f.doxyfile

pause
