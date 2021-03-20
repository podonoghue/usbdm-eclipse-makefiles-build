@echo off
cls
rem ***  Paths to various things
set VERSION_NUMBER=4
set VERSION_MINOR_NUMBER=11
set VERSION_SUFFIX=_V%VERSION_NUMBER%
set VERSION_MINOR_SUFFIX=_V%VERSION_NUMBER%_%VERSION_MINOR_NUMBER%

set USBDM_ROOT=C:\Users\podonoghue\Documents\Development\USBDM

rem where to find PCBs
set PCB_ROOT=%USBDM_ROOT%\PCB

set SEVEN_ZIP=C:\Program Files\7-Zip\7z.exe
set HW_VERSION=4_0_0
set PCB_DESTINATION=3. PCB

:doPCBFiles
echo ***  ****************************************
echo ***  Do PCB Design PDFs
echo ***  ****************************************
set Adapter_Files=KinetisAdapter
set JB16PCB_Files=TBDML_JB16_SOIC20[Minimal] TBDML_JB16_SOIC28[Minimal] USBDM_JB16_SOIC28[USB_Stick]
set JS16PCB_Files=USBDM_CF_JS16CWJ_V1_3 USBDM_CF_SER_JS16CWJ_V2 USBDM_JS16CWJ_V1 USBDM_SWD_JS16CWJ_V1_1 USBDM_SWD_SER_JS16CWJ_V3_1
set JS16PCB_OldFiles=USBDM_SER_JS16CWJ
set JMxxPCB_Files=USBDM_CF_JMxxCLD_V3_1
set JMxxPCB_OldFiles=USBDM_JMxxCLD

echo PCB dir : %PCB_ROOT%
echo.

echo ***  ****************************************
echo ***  Create PCB Folders
if not exist "%PCB_DESTINATION%"                         mkdir "%PCB_DESTINATION%"
del /S/Q                                                 "%PCB_DESTINATION%\*.*"
if not exist "%PCB_DESTINATION%\Adapter_%HW_VERSION%"    mkdir "%PCB_DESTINATION%\Adapter_%HW_VERSION%"
if not exist "%PCB_DESTINATION%\JB16_PCB_%HW_VERSION%"   mkdir "%PCB_DESTINATION%\JB16_PCB_%HW_VERSION%"
if not exist "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"   mkdir "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"
if not exist "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"   mkdir "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"

echo ***  ****************************************
echo ***  Do PDF assembly instructions
for %%f in (%Adapter_Files%)    do copy %PCB_ROOT%\Adapters\%%f\%%f.pdf    "%PCB_DESTINATION%\Adapter_%HW_VERSION%"
for %%f in (%JB16PCB_Files%)    do copy %PCB_ROOT%\Old_Schematics\%%f.pdf  "%PCB_DESTINATION%\JB16_PCB_%HW_VERSION%"
for %%f in (%JS16PCB_Files%)    do copy %PCB_ROOT%\%%f\*.pdf               "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"
for %%f in (%JS16PCB_OldFiles%) do copy %PCB_ROOT%\Old_Schematics\%%f.pdf  "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"
for %%f in (%JMxxPCB_Files%)    do copy %PCB_ROOT%\%%f\*.pdf               "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"
for %%f in (%JMxxPCB_OldFiles%) do copy %PCB_ROOT%\Old_Schematics\%%f.pdf  "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"
echo ***  ****************************************
echo ***  Do PCB Source files
for %%f in (%JS16PCB_Files%)    do copy "%PCB_ROOT%\%%f.zip"   "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%"
for %%f in (%JMxxPCB_Files%)    do copy "%PCB_ROOT%\%%f.zip"   "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%"
echo ***  ****************************************
echo ***  Do Gerber files       
for %%f in (%Adapter_Files%)  do "%SEVEN_ZIP%" a "%PCB_DESTINATION%\Adapter_%HW_VERSION%\%%f_Gerbers.zip"  "%PCB_ROOT%\Adapters\%%f\Project Outputs for %%f"
for %%f in (%JS16PCB_Files%)  do "%SEVEN_ZIP%" a "%PCB_DESTINATION%\JS16_PCB_%HW_VERSION%\%%f_Gerbers.zip" "%PCB_ROOT%\%%f\Project Outputs *"
for %%f in (%JMxxPCB_Files%)  do "%SEVEN_ZIP%" a "%PCB_DESTINATION%\JMxx_PCB_%HW_VERSION%\%%f_Gerbers.zip" "%PCB_ROOT%\%%f\Project Outputs*"
echo ***  ****************************************
echo ***  Done
goto allDone

:allDone
pause
