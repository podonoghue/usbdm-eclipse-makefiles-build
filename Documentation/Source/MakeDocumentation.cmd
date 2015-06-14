@echo off

SET FILES=__USBDM_V4 __USBDM_FlashProgrammers _USBDM_CF_JMxx _USBDM_CF_JS16 _USBDM_Freedom _USBDM_JB16 _USBDM_JMxx _USBDM_JS16 

for %%f in (%FILES%) do doxygen %%f.doxyfile


