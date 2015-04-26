@echo off

set USBDM_DIR=..\..\..\..
set PCB_DIR=%USBDM_DIR%\PCB
set OUTPUT_DIR=..\..\External\USBDM_V4.10
rem set OUTPUT_DIR=..\..\External
dir %OUTPUT_DIR%

rem  USBDM_JB16_SOIC28[USB_Stick] no longer promoted
set JB16_Files=TBDML_JB16_SOIC20[Minimal] TBDML_JB16_SOIC28[Minimal] USBDM_JB16_SOIC28[USB_Stick]
set JMxx_Files=USBDM_JMxxCLD
set JS16_Files=USBDM_JS16CWJ USBDM_SWD_JS16CWJ USBDM_SWD_SER_JS16CWJ
set JMxxCF_Files=USBDM_CF_JMxxCLD_V3
set JS16CF_Files=USBDM_CF_JS16CWJ USBDM_CF_SER_JS16CWJ
set Kinetis_Adapter_Files=KinetisAdapter.pdf KinetisAdapter.zip

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
for %%f in (%JB16_Files%)              do copy %%f.pdf %OUTPUT_DIR%\USBDM_JB16\html 
for %%f in (%JMxx_Files%)              do copy %%f.pdf %OUTPUT_DIR%\USBDM_JMxx\html 
for %%f in (%JMxxCF_Files%)            do copy %%f.pdf %OUTPUT_DIR%\USBDM_CF_JMxx\html 
for %%f in (%JS16_Files%)              do copy %%f.pdf %OUTPUT_DIR%\USBDM_JS16\html 
for %%f in (%JS16CF_Files%)            do copy %%f.pdf %OUTPUT_DIR%\USBDM_CF_JS16\html 
for %%f in (%Kinetis_Adapter_Files%)   do copy %%f     %OUTPUT_DIR%\USBDM_CF_JMxx\html 
for %%f in (%Kinetis_Adapter_Files%)   do copy %%f     %OUTPUT_DIR%\USBDM_CF_JS16\html 

pause
