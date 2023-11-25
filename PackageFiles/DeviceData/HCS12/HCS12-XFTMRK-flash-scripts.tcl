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
;#  V4.19.4.240 - Added return error codes
;#  V4.10.4 	- Changed return code handling
;#  V4.10.4 	- Added disableWatchdog { }
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # BigEndian format for writing numbers to memory
   setbytesex bigEndian

   set ::NAME  "HCS12-XFTMRCK-flash-scripts"
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
   set ::NVM_FECCRIX              0x0103
   set ::NVM_FCNFG                0x0104
   set ::NVM_FERCNFG              0x0105
   set ::NVM_FSTAT                0x0106
   set ::NVM_FERSTAT              0x0107
   set ::NVM_FPROT                0x0108
   set ::NVM_EPROT                0x0109
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
   set ::NVM_FCMD_FULLPARTITION   0x0F
   set ::NVM_FCMD_PARTITION       0x20
   set ::NVM_FCMD_QUERYPARTITION  0x15
   set ::NVM_FCMD_EEPROMENABLE    0x13
   set ::NVM_FCMD_EEPROMDISABLE   0x14
   
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
   wb $::NVM_FPROT   $::NVM_xPROT_VALUE   ;# unprotect Flash
   wb $::NVM_EPROT   $::NVM_xPROT_VALUE   ;# unprotect EEPROM
   
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc calculateFlashDivider { busFrequency } {
;# NOTES:
;#   According to data sheets the Flash uses the OSC clock for timing
;#   This code assumes busFrequency = Fosc/2
;#   Minimum BUS clock of 1MHz
;#
   puts "*** calculateFlashDivider {}"
   ;# minimum BUS frequency is 1MHz
   if { [expr $busFrequency < 1000] } {
      puts "*** Clock too low for flash programming"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }
   set fmclkFrequency [expr 2.0*$busFrequency]
   set cfmclkd  [expr round(floor(($fmclkFrequency/1050.0)-0.0001))]
   set flashClk [expr $fmclkFrequency/($cfmclkd+1)]
   puts "*** cfmclkd = $cfmclkd, flashClk = $flashClk"
   if { [expr ($flashClk<800)||($flashClk>1050)] } {
      puts "*** Not possible to find suitable flash clock divider"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }      
   return $cfmclkd
}

;######################################################################################
;#
;#  cmd     - command to execute   = FCCOB[0].high
;#  address - flash address to use = FCCOB[0].low, FCCOB[1].high/low
;#  data0   - data0 value to use   = FCCOB[2].high/low
;#  data1   - data1 value to use   = FCCOB[3].high/low
;#  data2   - data1 value to use   = FCCOB[4].high/low
;#  data3   - data1 value to use   = FCCOB[5].high/low
;#
proc executeFlashCommand { cmd {address "none"} {data0 "none"} {data1 "none"} {data2 "none"} {data3 "none"} } {

   ;#  puts "*** executeFlashCommand {}"
   
   wb $::NVM_FSTAT     $::NVM_FSTAT_CLEAR           ;# clear any error flags
   wb $::NVM_FCCOBIX   0                            ;# index = 0
   wb $::NVM_FCCOBHI $cmd                           ;# load command
   if {$address != "none"} {
      wb $::NVM_FCCOBLO [expr ($address>>16)&0xFF]  ;# load GPAGE
      wb $::NVM_FCCOBIX    1                        ;# index = 1
      ww $::NVM_FCCOBHI [expr $address&0xFFFF]      ;# load addr
   }
   if {$data0 != "none"} { 
    wb $::NVM_FCCOBIX    2                          ;# index = 2
    ww $::NVM_FCCOBHI [expr $data0]                 ;# load data
   }
   if {$data1 != "none"} { 
    wb $::NVM_FCCOBIX    3                          ;# index = 3
    ww $::NVM_FCCOBHI [expr $data1]                 ;# load data
   }
   if {$data2 != "none"} { 
    wb $::NVM_FCCOBIX    4                          ;# index = 4
    ww $::NVM_FCCOBHI [expr $data2]                 ;# load data
   }
   if {$data3 != "none"} { 
    wb $::NVM_FCCOBIX    5                          ;# index = 5
    ww $::NVM_FCCOBHI [expr $data3]                 ;# load data
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
;#
;#
proc rbx { address } {
   ;# puts "*** rbx {}"
   
   wdreg $::BDMGPR [expr ($address>>16)|$::BDMGPR_BGAE]
   return [rb [expr $address&0xFFFF]]
}

;######################################################################################
;# Partition DFLASH for EEPROM use
;#
;#  dfpart DFPART value
;#  erpart ERPART value
;#
;#  See "28.4.2.15 Full Partition D-Flash Command" in the manual
;#
proc partition { dfpart erpart } {

   reset sh
   connect
   initTarget 100  ;# dummy value
   initFlash  8000 ;# Assume 8MHz clock
   
   puts "*** Doing flash partition command"
   puts "DFPART   = $dfpart"
   puts "ERPART   = $erpart"
   ;#                  FCCOB[0].high             FCCOB[0].low,FCCOB[1]  FCCOB[2]
   executeFlashCommand $::NVM_FCMD_FULLPARTITION $dfpart                $erpart
   
   queryPartition
}

;######################################################################################
;# Query flash partition information
;#
;# Assumes initFlash done
;#
proc queryPartition { } {
   
   puts "*** Doing query partition command"
   executeFlashCommand $::NVM_FCMD_QUERYPARTITION
   
   wb $::NVM_FCCOBIX   1                            ;# index = 1
   set DFPART [rw $::NVM_FCCOBHI]                   ;# DFPART
   wb $::NVM_FCCOBIX   2                            ;# index = 2
   set ERPART [rw $::NVM_FCCOBHI]                   ;# ERPART
   wb $::NVM_FCCOBIX   3                            ;# index = 3
   set ECOUNT [rw $::NVM_FCCOBHI]                   ;# ECOUNT
   wb $::NVM_FCCOBIX   4                            ;# index = 4
   set DEADSEC   [rb $::NVM_FCCOBHI]                ;# Dead sector count
   set READYSEC  [rw $::NVM_FCCOBLO]                ;# Ready sector count
   
   puts "*** Current flash partition information"
   puts "DFPART   = $DFPART"
   puts "ERPART   = $ERPART"
   puts "ECOUNT   = $ECOUNT"
   puts "DEADSEC  = $DEADSEC"
   puts "READYSEC = $READYSEC"
}

;######################################################################################
;# Enable EEPROM operation
;#
;# Assumes initFlash done
;#
proc enableEeprom { } {
   
   puts "*** Doing enable eeprom command"
   executeFlashCommand $::NVM_FCMD_EEPROMENABLE
}

;######################################################################################
;# Disable EEPROM operation
;#
;# Assumes initFlash done
;#
proc disableEeprom { } {
   
   puts "*** Doing enable eeprom command"
   executeFlashCommand $::NVM_FCMD_EEPROMDISABLE
}

;######################################################################################
;# Actions on initial load
;#
loadSymbols

