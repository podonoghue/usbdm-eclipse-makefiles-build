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
;#  V4.10.2 - 
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # BigEndian format for writing numbers to memory
   setbytesex bigEndian

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
   
   set ::HCS12_BDMSTS               0xFF01
   set ::HCS12_BDMSTS_ENBDM         0x80
   set ::HCS12_BDMSTS_BDMACT        0x40
   set ::HCS12_BDMSTS_CLKSW         0x04
   set ::HCS12_BDMSTS_UNSEC         0x02

   set ::COPCTL                     0x3C
   
   set ::FLASH_REGIONS              "" ;# List of addresses within each unique flash region (incl. eeprom)
}

;######################################################################################
;#
;# @param flashRegions - list of flash array addresses
;#
proc initTarget { flashRegions } {
   ;# puts "initTarget {}"
   
   set ::FLASH_REGIONS  $flashRegions 

}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc initFlash { busFrequency } {
   ;#  puts "initFlash {}"
   
   set cfmclkd [calculateFlashDivider $busFrequency]

   ;# Set up Flash divider
   wb $::NVM_FCLKDIV $cfmclkd             ;# Flash divider
   wb $::NVM_FPROT   $::NVM_xPROT_VALUE   ;# unprotect Flash
   wb $::NVM_EPROT   $::NVM_xPROT_VALUE   ;# unprotect EEPROM
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
   ;# puts "calculateFlashDivider {}"
   ;# minimum BUS frequency is 1MHz
   if { [expr $busFrequency < 1000] } {
      error "Clock too low for flash programming"
   }
   set fmclkFrequency [expr 2.0*$busFrequency]
   set cfmclkd  [expr round(floor(($fmclkFrequency/1050.0)-0.0001))]
   set flashClk [expr $fmclkFrequency/($cfmclkd+1)]
   ;# puts "cfmclkd = $cfmclkd, flashClk = $flashClk"
   if { [expr ($flashClk<800)||($flashClk>1050)] } {
      error "Not possible to find suitable flash clock divider"
   }      
   return $cfmclkd
}

;######################################################################################
;#
;#  cmd     - command to execute
;#  address - flash address to use
;#  value   - data value to use
;#
proc executeFlashCommand { cmd {address "none"} {data0 "none"} {data1 "none"} {data2 "none"} {data3 "none"} } {
   ;# puts "executeFlashCommand {}"
   
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
      ;# puts [ format "Flash command error NVM_FSTAT=0x%02X, retry=%d" $status $retry ]
      error "Flash command failed"
   }
}

;######################################################################################
;#  Target is erased & unsecured
;#
proc massEraseTarget { } {

   ;# puts "massEraseTarget{}"
   
   ;# Disable watchdog immediately after a reset
   pinSet rst=0 bkgd=0  ;# Reset
   after 100
   pinSet rst=3 ;# This waits for reset rise
   after 10
   pinSet 
   connect
   wb $::COPCTL 0x40  ;# Disable WDOG
   ;#rb $::COPCTL
   
   ;# Mass erase flash
   initFlash [expr [speed]/1000]  ;# Flash speed calculated from BDM connection speed

;#   executeFlashCommand $::NVM_FCMD_UNSECURE
   executeFlashCommand $::NVM_FCMD_ERASE_ALL_BLKS
   
   ;# Device is now blank & temporarily unsecured
   ;# rb $::NVM_NVSEC
   
   ;# Confirm unsecured
   isUnsecure

   ;# Flash is now Blank and unsecured
}

;######################################################################################
;#
proc isUnsecure { } {
   ;#  puts "Checking if unsecured"
   set securityValue [rb $::NVM_FSEC]

   if [ expr ( $securityValue & $::NVM_FSEC_SEC_MASK ) != $::NVM_FSEC_SEC_UNSEC ] {
      error "Target is secured"
   }
}

;######################################################################################
;#
;#
proc rbx { address } {
   ;# puts "rbx {}"
   
   wdreg $::BDMGPR [expr ($address>>16)|$::BDMGPR_BGAE]
   return [rb [expr $address&0xFFFF]]
}


;######################################################################################
;# Actions on initial load
;#
loadSymbols

;#]]>

proc doit { } {

   pinSet rst=0 bkgd=0
   after 50
   pinSet rst=3
   pinSet
   catch {connect}
   wb 0x3C 0x40
   rb 0x3C
}

proc try2 { } {

   reset s h
   connect
   wb 0x3C 0x40  ;# Disable COPCTL
   rb 0x3C
}

proc try3 { } {

   pinSet rst=0 bkgd=0
   pinSet rst=0 bkgd=3
   pinSet rst=0 bkgd=0
   pinSet rst=0 bkgd=3
}

proc try4 { } {

   pinSet rst=0 bkgd=0
   pinSet rst=3 bkgd=0
   pinSet rst=0 bkgd=0
   pinSet rst=3 bkgd=0
}

proc findEE {} {

   set eePagedAddress [expr 0x800+100]
   set eeFixedAddress [expr 0xC00+100]
   set eePage 0x0017
   
   set reference [rb $eeFixedAddress]
   puts "reference = $reference"
   
   set pageNo 0
   while {[expr $pageNo <= 256]} {
      wb $eePage $pageNo
      set probe [rb $eePagedAddress]
      puts "probe = $probe"
      if [expr $probe == $reference] {
      puts "\n\nFound page @ $pageNo\n\n"
         break;
      }
      incr pageNo
   }
}

openbdm
settarget hcs12
reset s h
connect
