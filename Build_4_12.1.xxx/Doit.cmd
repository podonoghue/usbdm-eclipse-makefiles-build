set HOME_DIR=%~dp0

cmd /c .\Collect_files.cmd
rem cmd /c .\Strip.cmd
cd   ".\Installation\Wix"
cd
cmd /c ".\Make_Installer.cmd"
cd %HOME_DIR%
cd
cmd /c .\Collect_MSI_Files.cmd
rem cmd /c .\SignIt.cmd
pause
