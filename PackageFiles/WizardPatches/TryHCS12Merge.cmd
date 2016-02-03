@echo on

rem .\mergeXML-debug -p "C:\Program Files (x86)\Freescale\CWS12v5.2\Bin\Plugins\Support\HC12Wizard\XML" "mc9s12*.xml|mm912*.xml" "CWHCS12_Device_5_2.xml"
rem .\mergeXML-debug -p "C:\Program Files (x86)\Freescale\CWS12v5.2\Bin\Plugins\Support\HC12Wizard" "wizard.xml" "CWHCS12_Wizard_5_2.xml"

.\mergeXML-debug -p "C:\Program Files (x86)\Freescale\CWS12v5.2\Bin\Plugins\Support\HC12Wizard\XML" "mc9s12*.xml|mm912*.xml"
.\mergeXML-debug -p "C:\Program Files (x86)\Freescale\CWS12v5.2\Bin\Plugins\Support\HC12Wizard" "wizard.xml"
