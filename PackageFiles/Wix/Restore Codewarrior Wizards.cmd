@echo off

set MERGE_CMD="Utilities\mergeXml.exe"

set ECLIPSE_WIZARD_DIR_MASK="C:\Program Files\Freescale\CW MCU v10.1\eclipse\plugins\com.freescale.mcu.projectwizard_1.*.*.*"
set ECLIPSE_PATCH_FILE="wizard_patches\Patch_10_1.xml"

set HCS08_WIZARD_DIR_MASK="C:\Program Files\Freescale\CodeWarrior for Microcontrollers V6.3\bin\plugins\Support\HC(S)08Wizard\XML"
set HCS08_PATCH_FILE="wizard_patches\OSBDM_HCS08_Wizard_V6_3.xml"
set CFV1_PATCH_FILE="wizard_patches\OSBDM_MCF51_Wizard_V6_3.xml"

set HCS12_WIZARD_DIR_MASK="C:\Program Files\Freescale\CWS12v5.1\bin\Plugins\Support\HC12Wizard\XML"
set HCS12_PATCH_FILE="wizard_patches\TBDML_HCS12x_Wizard_5_1.xml"

rem %MERGE_CMD% "C:\Program Files\Freescale\CWS12v5.1\bin\Plugins\Support\HC12Wizard\XML\\" "MC9S12x*.xml" "C:\Program Files\pgo\USBDM 4.7.0\WizardPatches\TBDML_HCS12x_Wizard_5_1.xml"
rem goto finish

if "%1"=="R" goto remove
if "%1"=="r" goto remove

:install
%MERGE_CMD% %ECLIPSE_WIZARD_DIR_MASK%  "plugin.xml"   %ECLIPSE_PATCH_FILE%
%MERGE_CMD% %HCS08_WIZARD_DIR_MASK%    "HCS908*.xml"  %HCS08_PATCH_FILE%
%MERGE_CMD% %HCS08_WIZARD_DIR_MASK%    "SC9S08*.xml"  %HCS08_PATCH_FILE%
%MERGE_CMD% %HCS08_WIZARD_DIR_MASK%    "MCF51*.xml"   %CFV1_PATCH_FILE%
%MERGE_CMD% %HCS12_WIZARD_DIR_MASK%    "MC9S12x*.xml" %HCS12_PATCH_FILE%
goto finish

:remove
%MERGE_CMD% %ECLIPSE_WIZARD_DIR_MASK%  "plugin.xml"
%MERGE_CMD% %HCS08_WIZARD_DIR_MASK%    "HCS908*.xml" 
%MERGE_CMD% %HCS08_WIZARD_DIR_MASK%    "SC9S08*.xml" 
%MERGE_CMD% %HCS08_WIZARD_DIR_MASK%    "MCF51*.xml"  
%MERGE_CMD% %HCS12_WIZARD_DIR_MASK%    "MC9S12x*.xml"

:finish