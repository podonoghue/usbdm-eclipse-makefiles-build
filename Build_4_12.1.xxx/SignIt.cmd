@echo off

set SIGNTOOL="C:\Program Files (x86)\Windows Kits\8.1\bin\x64\SignTool.exe"
set NAME="Open Source Developer, Peter O'Donoghue"
set TIMESTAMP_URL=http://time.certum.pl/

set SIGN_COMMAND=%SIGNTOOL% sign /n %NAME% /t %TIMESTAMP_URL% /fd sha1 /v

echo Signing files

for %%f in (%~dp0\USBDM_4_*.msi) do echo %SIGN_COMMAND% %%f
for %%f in (%~dp0\USBDM_4_*.msi) do %SIGN_COMMAND% %%f

rem pause