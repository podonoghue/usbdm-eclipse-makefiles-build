;#<![CDATA[


proc initFlash { } {
   wl $::FTFL_FPROT3   0xFFFFFFFF
   rl $::FTFL_FPROT3
   wb $::FTFL_FDPROT   0xFF
   rb $::FTFL_FDPROT
   wl $::FMC_PFB0CR    0x00000000
   wl $::FMC_PFB1CR    0x00000000
}
proc massEraseFlash {} {
   pinSet rst=0
   # MASS Erase + RESET + Hold CPU reset after release
   set mdmApControl [rcreg  $::MDM_AP_Control]
   set mdmApControl [expr $mdmApControl | $::MDM_AP_C_CORE_HOLD | $::MDM_AP_C_SYSTEM_RESET | $::MDM_AP_C_MASS_ERASE]
   wcreg $::MDM_AP_Control $mdmApControl
   after 50

   # Release reset (core stays reset)
   set mdmApControl [expr $mdmApControl & ~$::MDM_AP_C_SYSTEM_RESET]
   wcreg $::MDM_AP_Control $mdmApControl

   set flashBusy $::MDM_AP_C_MASS_ERASE
   set retry 0
   while { $flashBusy } {
      after 50
      set mdmApControl [rcreg $::MDM_AP_Control]
      set flashBusy [expr $mdmApControl & $::MDM_AP_C_MASS_ERASE]
      if [expr $retry == 10] {
         break;
      incr retry
      }
   }
   # Release the core reset
   set mdmApControl [expr $mdmApControl & ~$::MDM_AP_C_CORE_HOLD]
   wcreg $::MDM_AP_Control $mdmApControl
   pinSet
   
   if [expr $retry == 10] {
      error "Flash erase failed"
   }
}
proc unsecureFlash {} {
   initFlash
;#   rblock [expr $::NV_FSEC &~0xF] 0x20
   eraseBlock  [expr $::NV_FSEC&~0x3]
;#   rblock [expr $::NV_FSEC &~0xF] 0x20
   programLong $::NV_FSEC [expr $::FTFL_FSEC_DEFAULT_UNSEC_VALUE|0xFFFFFF00]
;#   rblock [expr $::NV_FSEC &~0xF] 0x20
;#   rb $::NV_FSEC
}
proc isUnsecure {} {
   ;# Check if not read protected   
   set mdmApStatus [ rcreg $::MDM_AP_Status ]
   if [ expr ( $mdmApStatus & $::MDM_AP_ST_SYSTEM_SECURITY ) != 0 ] {
      error "Flash is secured"
   }
}
proc executeCommand {} {
   ;# Clear any existing errors
   wb $::FTFL_FSTAT [expr $::FTFL_FSTAT_ACCERR|$::FTFL_FSTAT_FPVIOL]

   ;# Start command
   wb $::FTFL_FSTAT $::FTFL_FSTAT_CCIF

   ;# Wait for command complete
   set flashBusy 0
   set retry 0
   while { $flashBusy == 0} {
      set fstat [ rb $::FTFL_FSTAT ]
      set flashBusy [expr $fstat & $::FTFL_FSTAT_CCIF]
      if [ expr $retry == 10] {
         error "Flash busy timeout"
      }
      after 100
      incr retry
   }
   if [ expr ( $fstat & $::FTFL_FSTAT_ACCERR ) != 0 ] {
      error "Flash access error"
   }
   if [ expr ( $fstat & $::FTFL_FSTAT_FPVIOL ) != 0 ] {
      error "Flash write protect error"
   }  
   if [ expr ( $fstat & $::FTFL_FSTAT_MGSTAT0 ) != 0 ] {
      error "Flash command failed error"
   }  
}
proc setFCCOB { cmd addr data } {
   wl $::FTFL_FCCOB3 [expr ($cmd << 24) | $addr]
   rl $::FTFL_FCCOB3
   wl $::FTFL_FCCOB7 $data
   rl $::FTFL_FCCOB7
   rblock $::FTFL_FCCOB3 0x10
}
proc programLong { addr data } {
   setFCCOB $::F_PGM4 $addr $data
   executeCommand
}
proc eraseBlock { addr } {
   setFCCOB $::F_ERSBLK $addr 0x0
   executeCommand
}

source names.tcl

loadSymbols
settarget 8
connect

return
;#]]>
