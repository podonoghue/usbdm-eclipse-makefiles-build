@echo off

@echo Disabled
pause
exit

set MAKECERT=c:\Apps\WinDDK\7600.16385.1\bin\amd64\MakeCert.exe
set CERTMGR=c:\Apps\WinDDK\7600.16385.1\bin\amd64\CertMgr.exe
 
set STORE=PrivateCertStore
set CERT_NAME=USBDMCertificate
set NAME=USBDM

@echo %CERTMGR% -add %~dp0\%NAME%.cer -s -r  localMachine root 
%CERTMGR% -add %~dp0\%NAME%.cer -s -r  localMachine root 
@echo %CERTMGR% -add -c %~dp0\%NAME%.cer -s -r  localMachine trustedpublisher 
%CERTMGR% -add -c %~dp0\%NAME%.cer -s -r  localMachine trustedpublisher 

@pause
