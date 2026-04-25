@echo off

set STORE=My

set INF_2_CAT="C:\Program Files (x86)\Windows Kits\8.1\bin\x86\Inf2Cat.exe"
rem set SIGNTOOL=C:\Apps\WinDDK\7600.16385.1\bin\amd64\SignTool.exe
rem set TIMESTAMP_URL=http://timestamp.verisign.com/scripts/timstamp.dll
rem set SHA=19B5A37F5AF7C74D9909519F16ED2B5AA53F1C10

set SIGNTOOL="C:\Program Files (x86)\Windows Kits\8.1\bin\x64\SignTool.exe"
set NAME="Open Source Developer, Peter O'Donoghue"
set TIMESTAMP_URL=http://time.certum.pl/

set SIGN_COMMAND=%SIGNTOOL% sign /n %NAME% /t %TIMESTAMP_URL% /fd sha1 /v

echo Creating CAT files
%INF_2_CAT% /driver:%~dp0\Drivers /os:XP_X86,XP_X64,7_X86,7_X64,Vista_X86,Vista_X64

echo Creating XP CAT files
%INF_2_CAT% /driver:%~dp0\DriversXP /os:XP_X86,XP_X64,7_X86,7_X64,Vista_X86,Vista_X64

%SIGN_COMMAND% %~dp0\Drivers\*.cat %~dp0\DriversXP\*.cat
pause
