
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
;#  V4.12.1.285 - Minor changes to massErase
;#  V4.10.4.240 - Added return error codes
;#  V4.10.4 	- Changed return code handling
;#  V4.10.4 	- Added disableWatchdog { }
;#  V4.10.4 	- Renamed NVM_...
;#  V4.10.2 	- Added write to $CPMUCOP
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # BigEndian format for writing numbers to memory
   setbytesex bigEndian

   set ::NAME  "HCS12-FTMRCK-flash-scripts"
   puts "*** $::NAME.loadSymbols{}"
   
   set ::BDMGPR                     0xFF08
   set ::BDMGPR_BGAE                0x80

   set ::NVM_FSEC_SEC_MASK        0x03   ;# Security bits
   set ::NVM_FSEC_SEC_UNSEC       0x02   ;# Security bits for unsecured device
   set ::NVM_FSEC_SEC_KEYEN       0x80   ;# Backdoor Key enable
   set ::NVM_FSEC_UNSEC_VALUE     0xFFFE ;# Value to use when unsecuring (0xFF:NVSEC value)
                                    
   set ::NVM_FCLKDIV              0x0100
   set ::NVM_FSEC                 0x0101
   set ::NVM_FCCOBIX              0x0102
   set ::NVM_FCNFG                0x0104
   set ::NVM_FERCNFG              0x0105
   set ::NVM_FSTAT                0x0106
   set ::NVM_FERSTAT              0x0107
   set ::NVM_FPROT                0x0108
   set ::NVM_DFPROT               0x0109
   set ::NVM_xPROT_VALUE          0xFF
   set ::NVM_FCCOBHI              0x010A
   set ::NVM_FCCOBLO              0x010B
   set ::NVM_FECCRHI              0x010E
   set ::NVM_FECCRLO              0x010F
   set ::NVM_FOPT                 0x0110
                                    
   set ::NVM_NVSEC                0x7FFF08  ;# actually SEC as word aligned
                                    
   set ::NVM_FSTAT_CCIF           0x80
   set ::NVM_FSTAT_ACCERR         0x20
   set ::NVM_FSTAT_FPVIOL         0x10
   set ::NVM_FSTAT_MGBUSY         0x08
   set ::NVM_FSTAT_MGSTAT1        0x02
   set ::NVM_FSTAT_MGSTAT0        0x01
   set ::NVM_FSTAT_CLEAR          [expr ($::NVM_FSTAT_FPVIOL|$::NVM_FSTAT_ACCERR)]

   set ::NVM_FCMD_ERASE_VERIFY    0x01
   set ::NVM_FCMD_PROG_P_FLASH    0x06
   set ::NVM_FCMD_ERASE_ALL_BLKS  0x08
   set ::NVM_FCMD_ERASE_P_SECTOR  0x0A
   set ::NVM_FCMD_UNSECURE        0x0B
   
   set ::HCS12_BDMSTS               0xFF01
   set ::HCS12_BDMSTS_ENBDM         0x80
   set ::HCS12_BDMSTS_BDMACT        0x40
   set ::HCS12_BDMSTS_CLKSW         0x04
   set ::HCS12_BDMSTS_UNSEC         0x02

   set ::COPCTL                     0x3C
   set ::COPCTL_DISABLE             0x40
   
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
;# A reset is required? to prevent a possible timeout before the COPCTL write completes
;#
proc disableWatchdog { } {

   ;# Disable watchdog immediately after a reset
   ;# dialogue "Before reset - XFTMRK" Waiting... ok
   ;# reset s h

   puts "*** disableWatchdog {}"
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
   puts "*** initTarget { $flashRegions }"
   
   set ::FLASH_REGIONS  $flashRegions 

   disableWatchdog
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc initFlash { busFrequency } {
   puts "*** initFlash { busFrequency=$busFrequency kHz}"
   
   set cfmclkd [calculateFlashDivider $busFrequency]

   ;# Set up Flash divider
   wb $::NVM_FCLKDIV $cfmclkd             ;# Flash divider
   wb $::NVM_FPROT  $::NVM_xPROT_VALUE    ;# unprotect P-Flash
   wb $::NVM_DFPROT $::NVM_xPROT_VALUE    ;# unprotect D-Flash
   
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc calculateFlashDivider { busFrequency } {
;# NOTES:
;#   According to data sheets the Flash uses the BUS clock for timing
;#
   puts "*** calculateFlashDivider {}"
   set clockFreq $busFrequency
   
   if { [expr $clockFreq < 1000] } {
      puts "*** Clock too low for flash programming"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }
   set cfmclkd  [expr round(($clockFreq-1101.0)/1000)]
   set flashClk [expr round($clockFreq/($cfmclkd+1))]
   puts "*** cfmclkd = $cfmclkd, flashClk = $flashClk"
   
   return $cfmclkd
}

;######################################################################################
;#
;#  cmd     - command to execute
;#  address - flash address to use
;#  value   - data value to use
;#
proc executeFlashCommand { cmd {address "none"} {data0 "none"} {data1 "none"} {data2 "none"} {data3 "none"} } {

   ;#  puts "*** executeFlashCommand {}"
   
   wb $::NVM_FSTAT     $::NVM_FSTAT_CLEAR           ;# clear any error flags
   wb $::NVM_FCCOBIX   0                            ;# index = 0
   wb $::NVM_FCCOBHI $cmd                           ;# load program command
   if {$address != "none"} {
      wb $::NVM_FCCOBLO [expr ($address>>16)&0xFF]  ;# load GPAGE
      wb $::NVM_FCCOBIX    1                        ;# index = 1
      ww $::NVM_FCCOBHI [expr $address&0xFFFF]      ;# load addr
      if {$data0 != "none"} { 
         wb $::NVM_FCCOBIX    2                     ;# index = 2
         ww $::NVM_FCCOBHI [expr $data0]            ;# load data
         wb $::NVM_FCCOBIX    3                     ;# index = 3
         ww $::NVM_FCCOBHI [expr $data1]            ;# load data
         wb $::NVM_FCCOBIX    4                     ;# index = 4
         ww $::NVM_FCCOBHI [expr $data2]            ;# load data
         wb $::NVM_FCCOBIX    5                     ;# index = 5
         ww $::NVM_FCCOBHI [expr $data3]            ;# load data
      }
   }
   wb $::NVM_FSTAT $::NVM_FSTAT_CCIF  ;# Clear CCIF to execute the command 

   ;# Wait for command completion
   set flashBusy 1
   set retry 0
   while { $flashBusy } {
      after 20
      set status [rb $::NVM_FSTAT]
      set flashBusy  [expr ($status & $::NVM_FSTAT_CCIF) == 0x00]
      set flashError [expr ($status & ($::NVM_FSTAT_FPVIOL|$::NVM_FSTAT_ACCERR))]
      if [expr $flashError != 0] {
         break;
      }
      if [expr $retry == 20] {
         break;
      }
      incr retry
   }
   if [ expr ($flashError || ($retry>=20)) ] {
      puts [ format "Flash command error NVM_FSTAT=0x%02X, retry=%d" $status $retry ]
      error $::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND
   }
   return
}

;######################################################################################
;#  Target is erased & unsecured
;#
;# programUnsecured : not used
;# The device is left entirely blank which is treted as unsecured by these HCS devices.
;#
proc massEraseTarget { programUnsecured } {

   puts "*** massEraseTarget{ $programUnsecured }"
   
   ;# Mass erase flash
   ;# This is possibly even if the device is secure.
   initFlash [expr [speed]/1000]  ;# Flash speed calculated from BDM connection speed

   if [ expr [isUnsecure] != 0 ] {
      ;# Need an unsecure command and reset if the device is secure !!!
      puts "*** Doing flash unsecure command"   
      executeFlashCommand $::NVM_FCMD_UNSECURE
      
      ;# Device is now blank & temporarily unsecured
      puts "*** Resetting"
      reset s h 
      connect
   }

   executeFlashCommand $::NVM_FCMD_ERASE_ALL_BLKS
   
   ;# Disable watchdog as it may not have been possible when secured
   disableWatchdog
   
   ;#puts [format "gs = 0x%X" [ gs ] ]
   
   ;# Flash is now Blank and unsecured
   ;# Confirm unsecured
   return [ isUnsecure ]
}

;######################################################################################
;#
proc isUnsecure { } {
   set securityValue [rb $::NVM_FSEC]
   if [ expr ( $securityValue & $::NVM_FSEC_SEC_MASK ) != $::NVM_FSEC_SEC_UNSEC ] {
      puts "*** isUnsecure{} - Target is secured!"
      return $::PROGRAMMING_RC_ERROR_SECURED
   }
   puts "*** isUnsecure{} - Target is unsecured"
   return 0
}

;######################################################################################
;# Actions on initial load
;#
loadSymbols

