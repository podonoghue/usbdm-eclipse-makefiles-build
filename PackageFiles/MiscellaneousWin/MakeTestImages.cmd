@echo off
cls
echo.
echo ==========================================================================
echo Generates synthetic test cases for various chips.
echo These fill the entire Target Flash/EEPROM memory space with random data.
echo.
echo Note - Since these images contain random data, programming them to a chip 
echo        may have unpredictable results, especially Kinetis or CF+ which may
echo        become permanently secured!
echo.
echo ==========================================================================
echo.
pause

set HOME_DIR=%~dp0
set CREATE_TEST_IMAGES=..\CreateFlashTestImage.exe
set DESTINATION=Synthetic Tests

if not exist "%DESTINATION%" mkdir "%DESTINATION%"
del /Q "%DESTINATION%\*.*"
cd  "%DESTINATION%"

rem goto finish

%CREATE_TEST_IMAGES% Empty.s19

rem HCS08
rem ===========================================================================================
rem                                             Flash Pages 1,0,3   Flash Page 2    Flash Page 4    Flash Page 5    Flash Page 6    Flash Page 7      
%CREATE_TEST_IMAGES% Image_MC9S08AC128.s19        0x4000 0xFFFF   0x28000 0x2BFFF 0x48000 0x4BFFF 0x58000 0x5BFFF 0x68000 0x6BFFF 0x78000 0x7BFFF
rem                                               EEPROM Page 0  EEPROM Page 1      Flash 
%CREATE_TEST_IMAGES% Image_MC9S08EL16.s19          0x1700 0x17FF 0x11700 0x117FF 0xC000 0xFFFF
rem  EEPROM page#=(FCNFG value)                   EEPROM Page 0  EEPROM Page 1      Flash 
%CREATE_TEST_IMAGES% Image_MC9S08DN16.s19         0x1700 0x17FF 0x11700 0x117FF 0xBE00 0xFFFF
rem  EEPROM page#=(FCNFG value)                     EEPROM Page 0     EEPROM Page 1   Flash Pages 1,0,3  Flash Page 2    Flash Page 4    Flash Page 5    Flash Page 6    Flash Page 7      
%CREATE_TEST_IMAGES% Image_MC9S08DZ128.s19        0x003C00 0x003CFF 0x013C00 0x013CFF   0x4000 0xFFFF   0x28000 0x2BFFF 0x48000 0x4BFFF 0x58000 0x5BFFF 0x68000 0x6BFFF 0x78000 0x7BFFF
%CREATE_TEST_IMAGES% Image_MC9S08FL16.s19         0xC000 0xFFFF
%CREATE_TEST_IMAGES% Image_MC9S08GB60.s19         0x1080 0x17FF 0x182C 0xFFFF 
%CREATE_TEST_IMAGES% Image_MC9S08GT16A.s19        0xC000 0xFFFF 
%CREATE_TEST_IMAGES% Image_MC9S08GT32.s19         0x8000 0xFFFF 
%CREATE_TEST_IMAGES% Image_MC9S08JM16.s19         0xC000 0xFFFF 
%CREATE_TEST_IMAGES% Image_MC9S08JM60.s19         0x10B0 0x17FF 0x1960 0xFFFF 
%CREATE_TEST_IMAGES% Image_MC9S08JS16.s19         0xC000 0xFFFF 
rem                                                  Flash A       Flash B
%CREATE_TEST_IMAGES% Image_MC9S08LC36.s19         0x1870 0x486F 0xA000 0xFFFF 
rem                                               Flash A+B
%CREATE_TEST_IMAGES% Image_MC9S08LG32.s19         0x8000 0xFFFF  
rem                                                Flash Pages 1,0,3 Flash Page 2
%CREATE_TEST_IMAGES% Image_MC9S08LL64.s19         0x4000 0xFFFF    0x28000 0x2BFFF
%CREATE_TEST_IMAGES% Image_MC9S08QA4.s19          0xF000 0xFFFF  
%CREATE_TEST_IMAGES% Image_MC9S08QB8.s19          0xE000 0xFFFF  
%CREATE_TEST_IMAGES% Image_MC9S08QD4.s19          0xF000 0xFFFF 
%CREATE_TEST_IMAGES% Image_MC9S08QE8.s19          0xE000 0xFFFF  
%CREATE_TEST_IMAGES% Image_MC9S08QE16.s19         0xC000 0xFFFF  
%CREATE_TEST_IMAGES% Image_MC9S08QG8.s19          0xE000 0xFFFF  
%CREATE_TEST_IMAGES% Image_MC9S08RD16.s19         0xC000 0xFFFF  
%CREATE_TEST_IMAGES% Image_MC9S08SE8.s19          0xE000 0xFFFF  
%CREATE_TEST_IMAGES% Image_MC9S08SH8.s19          0xE000 0xFFFF  
%CREATE_TEST_IMAGES% Image_MC9S08SF4.s19          0xF000 0xFFFF  
%CREATE_TEST_IMAGES% Image_MC9S08SV16.s19         0xC000 0xFFFF   
rem                                               ---------- Flash ----------
%CREATE_TEST_IMAGES% Image_MC13213.s19            0x1080 0x17FF 0x182C 0xFFFF

rem RS08
rem ===========================================================================================
%CREATE_TEST_IMAGES% Image_MC9RS08KA1.s19         0x3C00 0x3FFF  
%CREATE_TEST_IMAGES% Image_MC9RS08KA2.s19         0x3800 0x3FFF  
%CREATE_TEST_IMAGES% Image_MC9RS08KA8.s19         0x2000 0x3FFF  
%CREATE_TEST_IMAGES% Image_MC9RS08LA8.s19         0x2000 0x3FFF  
%CREATE_TEST_IMAGES% Image_MC9RS08LE4.s19         0x3000 0x3FFF  

rem MCF51
rem ===========================================================================================
%CREATE_TEST_IMAGES% Image_MCFxx96.s19            0x0000 0x17FFF
%CREATE_TEST_IMAGES% Image_MCFxx128.s19           0x0000 0x1FFFF
%CREATE_TEST_IMAGES% Image_MCFxx256.s19           0x0000 0x3FFFF

rem Kinetis
rem ===========================================================================================
%CREATE_TEST_IMAGES% Image_MKxx128.s19            0x0000 0x1FFFF 
%CREATE_TEST_IMAGES% Image_MKxx256.s19            0x0000 0x3FFFF 
%CREATE_TEST_IMAGES% Image_MKxx512.s19            0x0000 0x7FFFF 
                                                  
%CREATE_TEST_IMAGES% Image_MKxxTTT.s19            0x0000 0xFFFF     
%CREATE_TEST_IMAGES% Image_MKxx0800_1FFF.s19      0x0800 0x1FFF     
%CREATE_TEST_IMAGES% Image_MKxx0410_1FFF.s19      0x0410 0x1FFF     
%CREATE_TEST_IMAGES% Image_MKxx0100_1FFF.s19      0x0100 0x1FFF     
%CREATE_TEST_IMAGES% Image_MKxx0010_1FFF.s19      0x0010 0x1FFF     
%CREATE_TEST_IMAGES% Image_MKxxTTT.s19            0x0400 0x0800     
%CREATE_TEST_IMAGES% Image_MKxx0x1000-0x3FFFF.s19 0x01000 0x3FFFF   

rem HCS12
rem ===========================================================================================
rem   EEPROM not visible                            Flash  (Page 3E)     (Page 3F)       Page 3C           Page 3D    
%CREATE_TEST_IMAGES% Image_MC9S12A64.s19             0x4000 0x7FFF 0xC000 0xFFFF 0x3C8000 0x3CBFFF 0x3D8000 0x3DBFFF

rem   EEPROM mapped to 0x1000 (2 images)                   EEPROM     Flash  (Page 3E)     (Page 3F)       Page 3C           Page 3D    
%CREATE_TEST_IMAGES% Image_MC9S12A64Alt.s19           0x1000 0x13FF      0x4000 0x7FFF 0xC000 0xFFFF 0x3C8000 0x3CBFFF 0x3D8000 0x3DBFFF

rem  Usual arrangement                             Flash  (Pages 3E)     (Page 3F)
%CREATE_TEST_IMAGES% Image_MC9S12C32.s19                0x4000 0x7FFF  0xC000 0xFFFF
rem  Alt arrangement assuming default PPAGE?       Flash  (Pages 3E)     (Page 3F)
%CREATE_TEST_IMAGES% Image_MC9S12C32Alt.s19             0x8000 0xBFFF  0xC000 0xFFFF
rem                                                Flash   (Page 3E)     (PAGE 3F)      Page 38           Page 39           Page 3A           Page 3B           Page 3C           Page 3D      
%CREATE_TEST_IMAGES% Image_MC9S12C128_Paged.s19         0x4000 0x7FFF 0xC000 0xFFFF 0x388000 0x38BFFF 0x398000 0x39BFFF 0x3A8000 0x3ABFFF 0x3B8000 0x3BBFFF 0x3C8000 0x3CBFFF 0x3D8000 0x38BFFF

rem                                                   EEPROM    Flash (PAGE 3E)     (Page 3C?)    (PAGE 3F)   
%CREATE_TEST_IMAGES% Image_MC9S12DP256.s19        0x0400 0x0FFF     0x4000 0x7FFF 0x8000 0xBFFF 0xC000 0xFFFF 
rem                                                   EEPROM    Flash (Pages 3E)    (PAGE 3F)       (Page 30)          Page 31           Page 32           Page 33           Page 34           Page 35           Page 36            Page 37           Page 38           Page 39           Page 3A           Page 3B           Page 3C           Page 3D
%CREATE_TEST_IMAGES% Image_MC9S12DP256_Paged.s19  0x0400 0x0FFF     0x4000 0x7FFF 0xC000 0xFFFF 0x308000 0x30BFFF 0x318000 0x31BFFF 0x328000 0x32BFFF 0x338000 0x33BFFF 0x348000 0x34BFFF 0x358000 0x35BFFF 0x368000 0x36BFFF 0x378000 0x37BFFF 0x388000 0x38BFFF 0x398000 0x39BFFF 0x3A8000 0x3ABFFF 0x3B8000 0x3BBFFF 0x3C8000 0x3CBFFF 0x3D8000 0x3DBFFF

rem  EEPROM not visible                           Flash  (Page 3E)      (Page 3F)        Page 38           Page 39           Page 3A           Page 3B           Page 3C           Page 3D
%CREATE_TEST_IMAGES% Image_MC9S12DG128.s19            0x4000 0x7FFF  0xC000 0xFFFF  0x388000 0x38BFFF 0x398000 0x39BFFF 0x3A8000 0x3ABFFF 0x3B8000 0x3BBFFF 0x3C8000 0x3CBFFF 0x3D8000 0x3DBFFF
rem  EEPROM Mapped to 0x2000                           EEPROM    Flash (PAGE 3E)      (PAGE 3F)        Page 38           Page 39           Page 3A           Page 3B           Page 3C           Page 3D
%CREATE_TEST_IMAGES% Image_MC9S12DG128Alt.s19      0x2000 0x27FF     0x4000 0x7FFF  0xC000 0xFFFF 0x388000 0x38BFFF 0x398000 0x39BFFF 0x3A8000 0x3ABFFF 0x3B8000 0x3BBFFF 0x3C8000 0x3CBFFF 0x3D8000 0x3DBFFF

rem  EEPROM partially hidden                           EEPROM    Flash  (Page 3E)      (Page 3F)        Page 31           Page 32           Page 33           Page 34           Page 35           Page 36            Page 37          Page 38           Page 39           Page 3A           Page 3B           Page 3C           Page 3D
%CREATE_TEST_IMAGES% Image_MC9S12DT256.s19         0x0400 0x0FFF     0x4000 0x7FFF  0xC000 0xFFFF 0x318000 0x31BFFF 0x328000 0x32BFFF 0x338000 0x33BFFF 0x348000 0x34BFFF 0x358000 0x35BFFF 0x368000 0x36BFFF 0x378000 0x37BFFF 0x388000 0x38BFFF 0x398000 0x39BFFF 0x3A8000 0x3ABFFF 0x3B8000 0x3BBFFF 0x3C8000 0x3CBFFF 0x3D8000 0x3DBFFF

rem                                               Flash  (Page 3E)     (Page 3F)       Page 3C           Page 3D    
%CREATE_TEST_IMAGES% Image_MC9S12NE64.s19              0x4000 0x7FFF 0xC000 0xFFFF 0x3C8000 0x3CBFFF 0x3D8000 0x3DBFFF

rem                                                   Flash
%CREATE_TEST_IMAGES% Image_MC9S12UF32.s19         0x8000 0xFFFF

rem                                                    DFLASH    Flash (PAGE 3E)     (Page 3C?)    (PAGE 3F)   
%CREATE_TEST_IMAGES% Image_MC9S12XD256.s19         0x0800 0x0BFF     0x4000 0x7FFF 0x8000 0xBFFF 0xC000 0xFFFF 

rem                                                EEPROM Page FC           Page FD           Page FE        (Page FF)   | Flash (Page FD)     (PAGE FF)        Page E0           Page E1           Page E2           Page E3           Page E4            Page E5           Page E6           Page E7           Page F8           Page F9           Page FA           Page FB           Page FC            PAGE FE    
%CREATE_TEST_IMAGES% Image_MC9S12XD256_Paged.s19    0xFC0800 0xFC0BFF 0xFD0800 0xFD0BFF 0xFE0800 0xFE0BFF  0x0C00 0x0FFF      0x4000 0x7FFF 0xC000 0xFFFF  0xE08000 0xE0BFFF 0xE18000 0xE1BFFF 0xE28000 0xE2BFFF 0xE38000 0xE3BFFF 0xE48000 0xE4BFFF 0xE58000 0xE5BFFF 0xE68000 0xE6BFFF 0xE78000 0xE7BFFF 0xF88000 0xF8BFFF 0xF98000 0xF9BFFF 0xFA8000 0xFABFFF 0xFB8000 0xFBBFFF 0xFC8000 0xFCBFFF  0xFE8000 0xFEBFFF

rem                                                EEPROM Page FC           Page FD           Page FE        (Page FF)   | Flash (Page FD)     (PAGE FF)  |     Page E0           Page E1           Page E2           Page E3       |    Page E4           Page E5           Page E6           Page E7     |     Page E8           Page E9           Page EA           Page EB     |     Page EC           Page ED           Page EE           Page EF     |     Page F0           Page F1           Page F2           Page F3     |     Page F4            Page F5           Page F6           Page F7    |     Page F8           Page F9           Page FA           Page FB     |     Page FC            PAGE FE    
%CREATE_TEST_IMAGES% Image_MC9S12XDT512_Paged.s19   0xFC0800 0xFC0BFF 0xFD0800 0xFD0BFF 0xFE0800 0xFE0BFF  0x0C00 0x0FFF      0x4000 0x7FFF 0xC000 0xFFFF  0xE08000 0xE0BFFF 0xE18000 0xE1BFFF 0xE28000 0xE2BFFF 0xE38000 0xE3BFFF  0xE48000 0xE4BFFF 0xE58000 0xE5BFFF 0xE68000 0xE6BFFF 0xE78000 0xE7BFFF 0xE88000 0xE8BFFF 0xE98000 0xE9BFFF 0xEA8000 0xEABFFF 0xEB8000 0xEBBFFF 0xEC8000 0xECBFFF 0xED8000 0xEDBFFF 0xEE8000 0xEEBFFF 0xEF8000 0xEFBFFF 0xF08000 0xF0BFFF 0xF18000 0xF1BFFF 0xF28000 0xF2BFFF 0xF38000 0xF3BFFF 0xF48000 0xF4BFFF 0xF58000 0xF5BFFF 0xF68000 0xF6BFFF 0xF78000 0xF7BFFF 0xF88000 0xF8BFFF 0xF98000 0xF9BFFF 0xFA8000 0xFABFFF 0xFB8000 0xFBBFFF 0xFC8000 0xFCBFFF  0xFE8000 0xFEBFFF

rem CFVx
rem ===========================================================================================
rem                                                 Flash (256K)
%CREATE_TEST_IMAGES% Image_MCF52233.s19            0x0000 0x3FFFF
%CREATE_TEST_IMAGES% Image_MCF52233X.s19            0x0000 0x3BFFF


:finish
cd %HOME_DIR%
pause
