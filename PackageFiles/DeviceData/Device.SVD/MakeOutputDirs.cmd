@echo off

if exist .\Internal rmdir /S/Q .\Internal
xcopy /I /Q /S .\Generated\svdReducedMergedOptimisedManual .\Internal

if exist .\Project_Headers rmdir /S/Q .\Project_Headers
xcopy /I /Q /S .\Generated\HeaderReducedMergedOptimisedManual .\Project_Headers

pause

