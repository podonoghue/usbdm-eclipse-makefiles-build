
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
;#  V4.12.1.325 - Changed Rc from isUnsecure
;#  V4.12.1.280 - Fixes for incompatibility between C code and TCL parameters
;#  V4.11.1.50  - initFlash{} now queries target for speed
;#  V4.11.1.50  - Changed security checking routine (now does blank check first)
;#  V4.10.4.240 - Added return error codes
;#  V4.10.4     - Changed return code handling
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # BigEndian format for writing numbers to memory
   setbytesex bigEndian

   set ::HCS08_FOPT_SEC_MASK     0x03   ;# Security bits
   set ::HCS08_FOPT_SEC_UNSEC    0x02   ;# Security bits for unsecured device
   set ::HCS08_FOPT_SEC_KEYEN    0x80   ;# Backdoor Key enable
   set ::HCS08_FOPT_SEC_FNORED   0x40   ;# Vector redirection disable
   set ::HCS08_FOPT_UNSEC_VALUE  0xFE   ;# Value to use when unsecuring
   
   set ::HCS08_SOPT              0x1802
   set ::HCS08_SOPT_COPT1        0x80
   set ::HCS08_SOPT_COPT0        0x40
   set ::HCS08_SOPT_STOPE        0x20
   set ::HCS08_SOPT_TCLKPE       0x10
   set ::HCS08_SOPT_BKGDPE       0x02
   set ::HCS08_SOPT_RSTPE        0x01
   set ::HCS08_SOPT_INIT         [expr ($::HCS08_SOPT_STOPE|$::HCS08_SOPT_BKGDPE)]

   set ::HCS08_FCDIV             0x1820
   set ::HCS08_FOPT              0x1821 ;# Flash security reg
   set ::HCS08_FPROT             0x1824
   set ::HCS08_FSTAT             0x1825
   set ::HCS08_FCMD              0x1826

   set ::HCS08_NVOPT             0xFFBF

   set ::HCS08_FSTAT_FCBEF       0x80
   set ::HCS08_FSTAT_FCCF        0x40
   set ::HCS08_FSTAT_FPVIOL      0x20
   set ::HCS08_FSTAT_FACCERR     0x10
   set ::HCS08_FSTAT_FBLANK      0x04

   set ::HCS08_FCMD_BLANK_CHK    0x05
   set ::HCS08_FCMD_BYTE_PROG    0x20
   set ::HCS08_FCMD_BURST_PROG   0x25
   set ::HCS08_FCMD_PAGE_ERASE   0x40
   set ::HCS08_FCMD_MASS_ERASE   0x41
   
   set ::CAP_VDDCONTROL          (1<<2)      ;# Control over target Vdd

   set ::HCS08_PRDIV8            0x40

   set ::FLASH_REGIONS         "" ;# List of addresses within each unique flash region (incl. eeprom)
   
   set ::PROGRAMMING_RC_OK                           0
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

   puts "disableWatchdog {}"
   catch {
      connect
      halt   ;# in case sleeping
   }
   catch {
      wb $::HCS08_SOPT $::HCS08_SOPT_INIT ;# Disable COP
      rb $::HCS08_SOPT
   }
   return
}

;######################################################################################
;#
;# @param flashRegions - list of flash array addresses
;#
proc initTarget { flashRegions } {
   puts "Target script = HCS08-default-flash-scripts.tcl"
   puts "initTarget { $flashRegions }"
   
   set ::FLASH_REGIONS  $flashRegions 

;#    set capabilities [getcap]
;#    if { [expr ( $capabilities & $::CAP_VDDCONTROL )  != 0] } {
;#       puts "Doing Power reset"
;#       catch { reset s p }
;#    }
;#    else {
;#       puts "Doing Hardware reset"
;#       catch { reset s p }
;#    }
   disableWatchdog
}

;######################################################################################
;#
;#  busSpeedkHz - Target bus frequency in kHz
;#
proc initFlash { {busSpeedkHz 0} } {
   puts "initFlash {}"
   
   if { [expr $busSpeedkHz == 0] } {
      puts "initFlash() - Measuring bus frequency"
      ;# Get target speed from BDM connection speed
      set busSpeedkHz [expr [speed]/1000]
   }
   puts "initFlash {} busSpeedkHz = $busSpeedkHz"
   set cfmclkd [calculateFlashDivider  $busSpeedkHz]

   ;# Set Flash clock divider
   wb $::HCS08_FCDIV $cfmclkd
   rb $::HCS08_FCDIV
   
   ;# unprotect Flash
   wb $::HCS08_FPROT 0xFF
   
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc calculateFlashDivider { busFrequency } {

   puts "calculateFlashDivider {}"
   if { [expr $busFrequency < 150] } {
      puts "Clock too low for flash programming"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }
   set cfmclkd 0
   if { [expr $busFrequency > 12800] } {
      set cfmclkd $::HCS08_PRDIV8
      set busFrequency [expr $busFrequency / 8]
   }
   set cfmclkd [expr $cfmclkd | (($busFrequency-1)/200)]
   set flashClk [expr $busFrequency / (($cfmclkd&0x3F)+1)]
   puts "cfmclkd = $cfmclkd, flashClk = $flashClk"
   if { [expr ($flashClk<150)||($flashClk>200)] } {
      puts "Not possible to find suitable flash clock divider"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }      
   
   return $cfmclkd
}

;######################################################################################
;#
;#  cmd     - command to execute
;#  address - flash address to use
;#  value   - data value to use
;#
proc executeFlashCommand { cmd address value } {

   puts "executeFlashCommand { $cmd $address $value}"
   
   ;# Clear FPVIOL and FACCERR
   wb $::HCS08_FSTAT    [expr ($::HCS08_FSTAT_FPVIOL|$::HCS08_FSTAT_FACCERR)]
   wb $address $value                         ;# Write to flash to buffer address and data
   wb $::HCS08_FCMD     $cmd                  ;# Write command
   wb $::HCS08_FSTAT    $::HCS08_FSTAT_FCBEF  ;# Set FCBEF to execute the command 
   
   ;# Wait for command completion
   set flashBusy 1
   set retry 0
   while { $flashBusy } {
      after 20
      set status [rb $::HCS08_FSTAT]
      set flashBusy  [expr ($status & $::HCS08_FSTAT_FCCF) == 0x00]
      set flashError [expr ($status & ($::HCS08_FSTAT_FPVIOL|$::HCS08_FSTAT_FACCERR))]
      if [expr $flashError != 0] {
         break;
      }
      if [expr $retry == 20] {
         break;
      }
      incr retry
   }
   if [ expr ($flashError || ($retry>=20)) ] {
      puts [ format "Flash command error HCS08_FSTAT=0x%02X, retry=%d" $status $retry ]
      error $::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND
   }
   return
}

;######################################################################################
;#  Target is erased and blank checked so it is temporarily unsecured
;#
proc massEraseTarget { } {

   puts "massEraseTarget{}"
   
   initFlash

   ;# Mass erase flash (& EEPROM)
   foreach flashRegion $::FLASH_REGIONS {
      ;# puts "flashRegion = $flashRegion"
      lassign  $flashRegion type address
      puts "Processing memory type='$type', dummy address='$address'"
      ;# puts "executeFlashCommand $::HCS08_FCMD_MASS_ERASE $address 0xFF"
      executeFlashCommand $::HCS08_FCMD_MASS_ERASE $address 0xFF
   }
   
   ;# Should be temporarily unsecure
   ;# Confirm unsecured
   return [ isUnsecure ]
}

######################################################################################
# Checks if target is secured
#
# @return $::PROGRAMMING_RC_OK (= 0)      if unsecured
# @return $::PROGRAMMING_RC_ERROR_SECURED if secured
#
proc isUnsecure { } {

   puts "============================================="
   puts "isUnsecure{}"
   
   ;# Check security bits in FOPT
   puts "isUnsecure{} - Checking FOPT security"
   set securityValue [rb $::HCS08_FOPT]
   if [ expr ( $securityValue & $::HCS08_FOPT_SEC_MASK ) == $::HCS08_FOPT_SEC_UNSEC ] {
      puts "isUnsecure{} - Target is unsecured"
      return 0
   }
   puts "isUnsecure{} - FOPT security check failed - doing blank check!"

   initFlash

   ;# Blankcheck flash (to temporarily unsecure flash if entirely blank)
   foreach flashRegion $::FLASH_REGIONS {
      ;# puts "flashRegion = $flashRegion"
      lassign  $flashRegion type address
      puts "Processing memory type='$type', dummy address='$address'"
  
      ;# puts "executeFlashCommand $::HCS08_FCMD_BLANK_CHK $address 0xFF"
      executeFlashCommand $::HCS08_FCMD_BLANK_CHK $address 0xFF
      set status  [rb $::HCS08_FSTAT]
      if [ expr (($status & $::HCS08_FSTAT_FBLANK) == 0) ] {
         ;# puts [ format "Flash blank check failed HCS08_FSTAT=0x%02X" $status ]
         puts "isUnsecure{} - Flash not blank (and still secured)"
         return $::PROGRAMMING_RC_ERROR_SECURED
      }
   }
   puts "isUnsecure{} - Flash is blank and temporarily unsecured"
   return $::PROGRAMMING_RC_OK
}

;######################################################################################
;# Actions on initial load
;#
loadSymbols

