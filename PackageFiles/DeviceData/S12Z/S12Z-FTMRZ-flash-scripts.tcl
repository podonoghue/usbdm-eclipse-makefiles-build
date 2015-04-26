;#<![CDATA[
;#
;######################################################################################
;#  This file defines the following flash functions
;#  
;#  massEraseTarget - Entirely erases the target.
;#                    The target should be left in an unsecured state.
;#
;#  isUnsecure - indicates if the target is secured in some fashion (read/write protected)
;#               Returns TCL_OK if NOT secured
;#
;#  initFlash - initialises the target for flash programing (if needed)
;#
;#  initTarget - initialises the target for general use
;#
;#  In addition the script may do any once-only initialisation such as setting global symbols
;#  when initially loaded into the TCL environment.
;#

;#####################################################################################
;#  History
;#
;#  V4.19.4.240 - Added return error codes
;#  V4.10.6 - Created
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # BigEndian format for writing numbers to memory
   setbytesex bigEndian
 
   ;# BDCCSRH
   set ::S12X_BDCCSRH_ENBDM         0x80
   set ::S12X_BDCCSRH_BDMACT        0x40
   set ::S12X_BDCCSRH_BDMACT        0x20
   set ::S12X_BDCCSRH_STEAL         0x04
   set ::S12X_BDCCSRH_CLKSW         0x04
   set ::S12X_BDCCSRH_UNSEC         0x02
   set ::S12X_BDCCSRH_ERASE         0x01

   set ::NVM_FCLKDIV                0x000380

   ;# set ::NVM_FSEC                   0xFFFE0F
   ;# 
   ;# set ::NVM_FSEC_SEC_MASK          0x03
   ;# set ::NVM_FSEC_SEC_UNSEC         0x01
   
   set ::NVM_PRDIV8                 0x40
   
   set ::FLASH_REGIONS              "" ;# List of addresses within each unique flash region (incl. eeprom)
   
   set ::PROGRAMMING_RC_ERROR_SECURED              114
   set ::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND 115
   set ::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE 116
   
   return
}

;######################################################################################
;#
;# Disable watchdog
;#
;# A reset is required to prevent a possible timeout before the COPCTL write completes
;#
proc disableWatchdog { } {

   return
}

;######################################################################################
;#
;# @param flashRegions - list of flash array addresses
;#
proc initTarget { flashRegions } {
   puts "initTarget {}"
   
   set ::FLASH_REGIONS  $flashRegions 

   disableWatchdog
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc initFlash { busFrequency } {
   puts "initFlash {}"
   
   set fclkdiv [calculateFlashDivider $busFrequency]
   
   ;# Set up Flash divider
   wb $::NVM_FCLKDIV $fclkdiv             ;# Flash divider
      
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc calculateFlashDivider { busFrequency } {
;# NOTES:
;#   According to data sheets the Flash uses the BUS clock for timing
;#   Minimum BUS clock of 1MHz

   puts "calculateFlashDivider {}"
   ;# minimum BUS frequency is 1MHz
   if { [expr $busFrequency < 980] } { ;# Allow for tolerance on measurement
      puts "Clock too low for flash programming"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }
   set fmclkFrequency 1.0*$busFrequency
   set fclkdiv [expr round(floor(($fmclkFrequency/1000.0)+0.3999))-1]
   set flashClk [expr $fmclkFrequency/($fclkdiv+1)]
   puts "fclkdiv=$fclkdiv, flashClk=$flashClk"
   if { [expr ($flashClk<800)||($flashClk>1600)] } {
      puts "Not possible to find suitable flash clock divider"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }      
   return $fclkdiv
}

;######################################################################################
;#
;#  cmd     - command to execute
;#  address - flash address to use
;#  value   - data value to use
;#
proc executeFlashCommand { cmd address value } {

   ;#  puts "executeFlashCommand {}"
   
   wb $::NVM_FSTAT    $::NVM_FSTAT_CLEAR        ;# Clear PVIOL/ACCERR
   wb $::NVM_FTSTMOD  0x00                      ;# Clear WRALL?
   wb $::NVM_FSTAT    $::NVM_FSTAT_FAIL         ;# Clear FAIL
   if [ expr (($cmd == $::NVM_FCMD_MASS_ERASE) || ($cmd == $::NVM_FCMD_ERASE_VER)) ] {
      wb $::NVM_FTSTMOD $::NVM_FTSTMOD_WRALL    ;# Apply to all flash blocks
      ww $::NVM_FADDR    $address               ;# Flash address
      ww $::NVM_FDATA    $value                 ;# Flash data
   } else {
      ww $address $value                        ;# Write to flash to buffer address and data
   }
   wb $::NVM_FCMD     $cmd                      ;# Write command
   wb $::NVM_FSTAT    $::NVM_FSTAT_CBEIF        ;# Clear CBEIF to execute the command 
   
   ;# Wait for command completion
   set flashBusy 1
   set retry 0
   while { $flashBusy } {
      after 20
      set status [rb $::NVM_FSTAT]
      set flashBusy  [expr ($status & $::NVM_FSTAT_CCIF) == 0x00]
      set flashError [expr ($status & ($::NVM_FSTAT_PVIOL|$::NVM_FSTAT_ACCERR))]
      if [expr $flashError != 0] {
         break;
      }
      if [expr $retry == 20] {
         break;
      }
      incr retry
   }
   wb $::NVM_FTSTMOD  0x00                      ;# Clear WRALL
   if [ expr ($flashError || ($retry>=20)) ] {
      puts [ format "Flash command error NVM_FSTAT=0x%02X, retry=%d" $status $retry ]
      error $::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND
   }
   return
}

;######################################################################################
;#
;#  cmd     - command to execute
;#  address - EEPROM address to use
;#  value   - data value to use
;#
proc executeEepromCommand { cmd address value } {

   ;#  puts "executeEepromCommand {}"
   
   wb $::NVM_ESTAT    $::NVM_FSTAT_CLEAR  ;# Clear PVIOL/ACCERR
   wb $::NVM_ESTAT    $::NVM_FSTAT_FAIL   ;# Clear FAIL
   if [ expr (($cmd == $::NVM_FCMD_MASS_ERASE) || ($cmd == $::NVM_FCMD_ERASE_VER)) ] {
      ww $::NVM_EADDR $address              ;# EEPROM address
      ww $::NVM_EDATA $value                ;# EEPROM data
   } else {
      ww $address $value                      ;# Write to EEPROM to buffer address and data
   }
   wb $::NVM_ECMD     $cmd                  ;# Write command
   wb $::NVM_ESTAT    $::NVM_FSTAT_CBEIF  ;# Clear CBEIF to execute the command 
   
   ;# Wait for command completion
   set flashBusy 1
   set retry 0
   while { $flashBusy } {
      after 20
      set status [rb $::NVM_ESTAT]
      set flashBusy  [expr ($status & $::NVM_FSTAT_CCIF) == 0x00]
      set flashError [expr ($status & ($::NVM_FSTAT_PVIOL|$::NVM_FSTAT_ACCERR))]
      if [expr $flashError != 0] {
         break;
      }
      if [expr $retry == 20] {
         break;
      }
      incr retry
   }
   if [ expr ($flashError || ($retry>=20)) ] {
      puts [ format "EEPROM command error NVM_ESTAT=0x%02X, retry=%d" $status $retry ]
      error $::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND
   }
   return
}

;######################################################################################
;#  Target is erased & unsecured
;#
proc massEraseTarget { } {

   puts "massEraseTarget{}"
   
   disableWatchdog
   
   ;# Special S12Z erase command 
   massErase
    
   ;# Wait for command completion
   set flashBusy 1
   set retry 0
   while { $flashBusy } {
      after 20
      set status [gs]
      set flashBusy  [expr ($status & $::S12X_BDCCSRH_ERASE) != 0x00]
      if [expr $retry == 20] {
         break;
      }
      incr retry
   }
   if { $flashBusy } {
      puts [ format "Command error S12X_BDCCSRH=0x%02X, retry=%d" $status $retry ]
      error $::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND
   }   
   if [expr ($status & $::S12X_BDCCSRH_UNSEC) == 0x00] {
      puts "Flash mass erase failed - still secured"
      error $::PROGRAMMING_RC_ERROR_SECURED
   }   
   ;# Flash is now Blank and unsecured
   return [ isUnsecure ]
}

;######################################################################################
;#
proc isUnsecure { } {
   if [ expr ( [gs] & $::S12X_BDCCSRH_UNSEC ) == 0 ] {
      puts "isUnsecure{} - Target is secured!"
      return $::PROGRAMMING_RC_ERROR_SECURED
   }
   puts "isUnsecure{} - Target is unsecured"
   return 0
}

;######################################################################################
;# Actions on initial load
;#
loadSymbols

;#]]>
