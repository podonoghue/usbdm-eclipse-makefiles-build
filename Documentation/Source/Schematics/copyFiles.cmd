@echo off

set CURRENT_DIR=%~dp0
cd %CURRENT_DIR%
echo %CURRENT_DIR%

set USBDM_DIR=%CURRENT_DIR%\..\..\..\..

set PCB_DIR=%USBDM_DIR%\PCB
set OUTPUT_DIR=..\..\External\USBDM_V4.12
rem set OUTPUT_DIR=..\..\External
dir %OUTPUT_DIR%

rem  USBDM_JB16_SOIC28[USB_Stick] no longer promoted
set JB16_Files=pcb.png TBDML_JB16_SOIC20[Minimal].pdf TBDML_JB16_SOIC28[Minimal].pdf USBDM_JB16_SOIC28[USB_Stick].pdf Flash_Images.sx.zip
set JMxx_Files=pcb.png USBDM_JMxxCLD.pdf Flash_Images.sx.zip
set JS16_Files=pcb.png USBDM_JS16CWJ.pdf USBDM_SWD_JS16CWJ.pdf USBDM_SWD_SER_JS16CWJ.pdf Flash_Images.sx.zip
set JMxxCF_Files=pcb.png USBDM_CF_JMxxCLD_V3.pdf Flash_Images.sx.zip
set JS16CF_Files=pcb.png USBDM_CF_JS16CWJ.pdf USBDM_CF_SER_JS16CWJ.pdf Flash_Images.sx.zip
set Kinetis_Adapter_Files=pcb.png KinetisAdapter.pdf KinetisAdapter.zip Flash_Images.sx.zip
set Programmer_Files=pcb.png

echo PCB dir : %PCB_DIR%
rem echo PCB Dir contains : 
rem dir %PCB_DIR%

rem echo.
rem echo Copying Schematics from source directories
rem for %%f in (%JB16_Files%)     do copy %PCB_DIR%\%%f\%%f.pdf .
rem for %%f in (%JMxx_Files%)     do copy %PCB_DIR%\%%f\%%f.pdf .
rem for %%f in (%JMxxCF_Files%)   do copy %PCB_DIR%\%%f\%%f.pdf .
rem for %%f in (%JS16_Files%)     do copy %PCB_DIR%\%%f\%%f.pdf .
rem for %%f in (%JS16CF_Files%)   do copy %PCB_DIR%\%%f\%%f.pdf .

echo.
echo Copying Schematics to document directory
echo Copying %JB16_Files%
for %%f in (%JB16_Files%)              do copy %%f  %OUTPUT_DIR%\USBDM_JB16\html 
echo Copying %JMxx_Files%
for %%f in (%JMxx_Files%)              do copy %%f  %OUTPUT_DIR%\USBDM_JMxx\html 
echo Copying %JMxxCF_Files%
for %%f in (%JMxxCF_Files%)            do copy %%f  %OUTPUT_DIR%\USBDM_CF_JMxx\html 
echo Copying %JS16_Files%
for %%f in (%JS16_Files%)              do copy %%f  %OUTPUT_DIR%\USBDM_JS16\html 
echo Copying %JS16CF_Files%
for %%f in (%JS16CF_Files%)            do copy %%f  %OUTPUT_DIR%\USBDM_CF_JS16\html 
echo Copying %Kinetis_Adapter_Files%
for %%f in (%Kinetis_Adapter_Files%)   do copy %%f  %OUTPUT_DIR%\USBDM_CF_JMxx\html 
echo Copying %Programmer_Files%
for %%f in (%Programmer_Files%)        do copy %%f  %OUTPUT_DIR%\USBDM_FlashProgrammers\html 

pause
