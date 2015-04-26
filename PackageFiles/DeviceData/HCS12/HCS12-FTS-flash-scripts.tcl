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
;#  V4.10.4 	- Changed return code handling
;#  V4.10.4 	- Added disableWatchdog { }
;#  V4.10.4 	- Changed memory region names
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # BigEndian format for writing numbers to memory
   setbytesex bigEndian

   set ::NAME  "HCS12-FTS-flash-scripts"
   puts "$::NAME.loadSymbols{}"

   set ::NVM_FSEC_SEC_MASK     0x03   ;# Security bits
   set ::NVM_FSEC_SEC_UNSEC    0x02   ;# Security bits for unsecured device
   set ::NVM_FSEC_SEC_KEYEN    0x80   ;# Backdoor Key enable
   set ::NVM_FSEC_SEC_FNORED   0x40   ;# Vector redirection disable
   set ::NVM_FSEC_UNSEC_VALUE  0xFFFE ;# Value to use when unsecuring (0xFF:NVSEC value)
      
   set ::NVM_FCLKDIV           0x0100
   set ::NVM_FSEC              0x0101
   set ::NVM_FTSTMOD           0x0102
   set ::NVM_FPROT             0x0104
   set ::NVM_FSTAT             0x0105
   set ::NVM_FCMD              0x0106
   set ::NVM_FADDR             0x0108
   set ::NVM_FDATA             0x010A
   set ::NVM_xPROT_VALUE       0xFF
   set ::NVM_ECLKDIV           0x0110
   set ::NVM_EPROT             0x0114
   set ::NVM_ESTAT             0x0115
   set ::NVM_ECMD              0x0116
   set ::NVM_EADDR             0x0118
   set ::NVM_EDATA             0x011A

   set ::NVM_NVSEC             0xFF0E  ;# actually NVSEC-1 as word aligned

   set ::NVM_FSTAT_CBEIF       0x80
   set ::NVM_FSTAT_CCIF        0x40
   set ::NVM_FSTAT_PVIOL       0x20
   set ::NVM_FSTAT_ACCERR      0x10
   set ::NVM_FSTAT_BLANK       0x04
   set ::NVM_FSTAT_FAIL        0x02  ;# Note: Has to be cleared individually
   set ::NVM_FSTAT_DONE        0x01
   set ::NVM_FSTAT_CLEAR       [expr ($::NVM_FSTAT_PVIOL|$::NVM_FSTAT_ACCERR)]

   set ::NVM_FCMD_ERASE_VER    0x05
   set ::NVM_FCMD_WORD_PROG    0x20
   set ::NVM_FCMD_SECTOR_ERASE 0x40
   set ::NVM_FCMD_MASS_ERASE   0x41

   set ::NVM_FTSTMOD_WRALL     0x10
   
   set ::HCS12_BDMSTS               0xFF01
   set ::HCS12_BDMSTS_ENBDM         0x80
   set ::HCS12_BDMSTS_BDMACT        0x40
   set ::HCS12_BDMSTS_CLKSW         0x04
   set ::HCS12_BDMSTS_UNSEC         0x02

   set ::COPCTL                     0x3C
   set ::COPCTL_DISABLE             0x40

   set ::NVM_PRDIV8            0x40
   
   set ::INITEE                  0x0012 ;# EEPROM Mapping
   set ::INITEE_EEON             0x01
   set ::INITEE_EE_MASK          0xF8

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

   ;# Disable watchdog immediately after a reset
   ;# dialogue "Before reset - FTS" Waiting... ok
   ;# reset s h

   puts "disableWatchdog {}"
   catch {connect}                 ;# Ignore possible BDM enable fault
   wb $::COPCTL $::COPCTL_DISABLE  ;# Disable WDOG
   rb $::COPCTL 
   
   return
}

;######################################################################################
;#
;# @param flashRegions - list of flash array addresses
;#
proc initTarget { flashRegions } {
   puts "initTarget { $flashRegions }"
   
   set ::FLASH_REGIONS  $flashRegions 

   disableWatchdog
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc initFlash { busFrequency } {
   puts "initFlash {}"
   
   set cfmclkd [calculateFlashDivider $busFrequency]

   ;# Set up Flash divider
   wb $::NVM_FCLKDIV $cfmclkd             ;# Flash divider
   wb $::NVM_FPROT   $::NVM_xPROT_VALUE   ;# unprotect Flash

   foreach flashRegion $::FLASH_REGIONS {
      puts "flashRegion = '$flashRegion' type='$type', address='$address'"
      lassign  $flashRegion type address
      switch $type {
         "EEPROM" {
            ;# Set up Eeprom divider
            wb $::NVM_ECLKDIV $cfmclkd
            wb $::NVM_EPROT $::NVM_xPROT_VALUE
            ;# Re-map EEPROM to base address
            wb $::INITEE [expr $::INITEE_EEON|(($address>>8)&$::INITEE_EE_MASK)]
         }
         default {
         }
      }
   }
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc calculateFlashDivider { busFrequency } {
;# NOTES:
;# According to data sheets the Flash uses the Oscillator clock for timing but 
;# it is also influenced by the bus period.
;#
;# This code assumes that oscillator clock = 2 * bus clock
;#
   puts "calculateFlashDivider {}"
   set clockFreq [expr 2*$busFrequency]
   
   if { [expr $busFrequency < 1000] } {
      puts "Clock too low for flash programming"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }
   set cfmclkd 0
   if { [expr $clockFreq > 12800] } {
      set cfmclkd [expr $::NVM_PRDIV8 + round(floor(0.249999+1.25*($busFrequency/1000.0)))]
      set flashClk [expr $clockFreq / (8*(($cfmclkd&0x3F)+1))]
   } else {
      set cfmclkd [expr round(floor(0.99999+($busFrequency/100.0)))+1]
      set flashClk [expr ($clockFreq) / (($cfmclkd&0x3F)+1)]
   }
   if { [expr ($flashClk<150)] } {
      puts "Not possible to find suitable flash clock divider"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }      
   puts "cfmclkd = $cfmclkd, flashClk = $flashClk"
   
   return $cfmclkd
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

   puts "massEraseTarget{}, flashRegion = $::FLASH_REGIONS"
   
   disableWatchdog
   
   ;# Mass erase flash
   initFlash [expr [speed]/1000]  ;# Flash speed calculated from BDM connection speed

   foreach flashRegion $::FLASH_REGIONS {
      ;# puts "flashRegion = $flashRegion"
      lassign  $flashRegion type address
      ;# puts "type='$type', address='$address'"
      switch $type {
         "EEPROM" {
             puts "Erasing Eeprom @$address"
             executeEepromCommand $::NVM_FCMD_MASS_ERASE $address 0xFFFF
         }
         "FLASH" {
             puts "Erasing Flash @$address"
             executeFlashCommand  $::NVM_FCMD_MASS_ERASE $address  0xFFFF
         }
         default {
             ;# Ignore others
         }
       }
   }
   ;# Device is now Blank but may not be unsecured
   ;#  puts "Checking if target is already unsecured"
   set securityValue [rb $::NVM_FSEC]
   if [ expr ( $securityValue & $::NVM_FSEC_SEC_MASK ) == $::NVM_FSEC_SEC_UNSEC ] {
      ;# Target was originally unsecured - just return now
      puts "Target was originally unsecured"
      return
   }
   ;# Reset & re-connect for changes to be effected.  Device is partially unsecured
   ;# BDMSTS.UNSEC == 1
   reset s h
   connect   ;# shouldn't fail
   
   ;# Program security location to unsecured value
   initTarget $::FLASH_REGIONS
   initFlash [expr [speed]/1000]   ;# Flash speed calculated from BDM connection speed
   executeFlashCommand  $::NVM_FCMD_WORD_PROG $::NVM_NVSEC $::NVM_FSEC_UNSEC_VALUE
   
   ;# Reset to have unsecured (finally) but not blank device
   reset s h
   connect   ;# shouldn't fail

   ;# Confirm unsecured
   ;#  puts "Checking if target is unsecured"
   set securityValue [rb $::NVM_FSEC]
   if [ expr ( $securityValue & $::NVM_FSEC_SEC_MASK ) != $::NVM_FSEC_SEC_UNSEC ] {
      puts "Flash mass erase failed - still secured"
      error $::PROGRAMMING_RC_ERROR_SECURED
   }   
   ;# Erase security location so device is unsecured and blank!
   initTarget $::FLASH_REGIONS
   initFlash [expr [speed]/1000]   ;# Flash speed calculated from BDM connection speed
   executeFlashCommand  $::NVM_FCMD_SECTOR_ERASE $::NVM_NVSEC 0xFFFF

   ;# Flash is now Blank and unsecured
   return [ isUnsecure ]
}

;######################################################################################
;#
proc isUnsecure { } {
   set securityValue [rb $::NVM_FSEC]
   if [ expr ( $securityValue & $::NVM_FSEC_SEC_MASK ) != $::NVM_FSEC_SEC_UNSEC ] {
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