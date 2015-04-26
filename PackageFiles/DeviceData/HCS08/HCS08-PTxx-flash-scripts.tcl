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
;#  V4.10.4 - Changed return code handling
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # BigEndian format for writing numbers to memory
   setbytesex bigEndian

   set ::NVM_FSEC_SEC_MASK         0x03   ;# Security bits mask
   set ::NVM_FSEC_SEC_UNSEC        0x02   ;# Security bits for unsecured device
   set ::NVM_FSEC_SEC_KEYEN        0x80   ;# Backdoor Key enable
   set ::NVM_FSEC_SEC_FNORED       0x40   ;# Vector redirection disable
   set ::NVM_FSEC_UNSEC_VALUE      0xFE   ;# Value to use when unsecuring
   
   set ::WDOG                      0x3030
   set ::WDOG_CS1                  0x3030
   set ::WDOG_CS2                  0x3031
   set ::WDOG_CNT                  0x3032
   set ::WDOG_TOVAL                0x3034
   set ::WDOG_CS1_VALUE            0x00
   set ::WDOG_CS2_VALUE            0x00
   set ::WDOG_UNLOCK1              0xC520
   set ::WDOG_UNLOCK2              0xD928
                                
   set ::NVM_FCLKDIV              0x3020
   set ::NVM_FSEC                 0x3021
   set ::NVM_FCCOBIX              0x3022
   set ::NVM_FCNFG                0x3024
   set ::NVM_FERCNFG              0x3025
   set ::NVM_FSTAT                0x3026
   set ::NVM_FERSTAT              0x3027
   set ::NVM_FPROT                0x3028
   set ::NVM_EPROT                0x3029
   set ::NVM_xPROT_VALUE          0xFF
   set ::NVM_FCCOBHI              0x302A
   set ::NVM_FCCOBLO              0x302B
   set ::NVM_FOPT                 0x302C ;# Flash reg ??

;#   set ::NVM_NVOPT              0xFFBF

   set ::NVM_FSTAT_CCIF           0x80
   set ::NVM_FSTAT_ACCERR         0x20
   set ::NVM_FSTAT_FPVIOL         0x10
   set ::NVM_FSTAT_MGBUSY         0x08
   set ::NVM_FSTAT_MGSTAT1        0x02
   set ::NVM_FSTAT_MGSTAT0        0x01
   set ::NVM_FSTAT_CLEAR          [expr ($::NVM_FSTAT_FPVIOL|$::NVM_FSTAT_ACCERR)]

   set ::NVM_FCMD_ERASE_VERIFY    0x01
   set ::NVM_FCMD_PROG_FLASH      0x06
   set ::NVM_FCMD_ERASE_ALL_BLKS  0x08
   set ::NVM_FCMD_ERASE_SECTOR    0x0A
   set ::NVM_FCMD_UNSECURE        0x0B
   
   set ::HCS08_BDMSTS               0xFF01
   set ::HCS08_BDMSTS_ENBDM         0x80
   set ::HCS08_BDMSTS_BDMACT        0x40
   set ::HCS08_BDMSTS_CLKSW         0x04
   set ::HCS08_BDMSTS_UNSEC         0x02

   set ::HCS08_PRDIV8               0x40

   set ::FLASH_REGIONS              "" ;# List of addresses within each unique flash region (incl. eeprom)
   
   set ::PROGRAMMING_RC_ERROR_SECURED              114
   set ::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND 115
   set ::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE 116
   
   return
}

;######################################################################################
;#
;# @param flashAddresses - list of flash array addresses
;#
proc initTarget { flashRegions } {
   puts "initTarget {}"
   
   set ::FLASH_REGIONS  $flashRegions 

;#   set ::ramAddress 0x1000
;#   set wdogH [expr $::WDOG>>8]
;#   set wdogL [expr $::WDOG&0xFF]

   ;# Disable watchdog
   ;#                ldhx #WDOG;        lda #0x10; sta 4,X;  clra; sta 5,X;  sta 1,X;  sta ,X;   
;#   wb  $::ramAddress 0x45 $wdogH $wdogL 0xA6 0x10  0xE7 0x04 0x4F  0xE7 0x05 0xE7 0x01 0xF7 0x82
;#   wpc $::ramAddress
;#   go 
   
   return
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
   wb $::NVM_EPROT   $::NVM_xPROT_VALUE   ;# unprotect EEPROM
   
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
   if { [expr $busFrequency < 1000] } {
      puts "Clock too low for flash programming"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }
   set fmclkFrequency 1.0*$busFrequency
   set cfmclkd [expr round(floor(($fmclkFrequency/1000.0)+0.3999))-1]
   set flashClk [expr $fmclkFrequency/($cfmclkd+1)]
   
   puts "cfmclkd = $cfmclkd, flashClk = $flashClk"
   if { [expr ($flashClk<800)||($flashClk>1600)] } {
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
proc executeFlashCommand { cmd {address "none"} {data0 "none"} {data1 "none"} {data2 "none"} {data3 "none"} } {
   ;# puts "executeFlashCommand {}"
   
   wb $::NVM_FSTAT   $::NVM_FSTAT_CLEAR             ;# clear any error flags
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
proc massEraseTarget { } {

   puts "massEraseTarget{}"
   
   ;# No initial connect as may fail.  Assumed done by caller.

   ;# Mass erase flash
   initFlash [expr [speed]/1000]  ;# Flash speed calculated from BDM connection speed

;#   executeFlashCommand $::NVM_FCMD_UNSECURE
   executeFlashCommand $::NVM_FCMD_ERASE_ALL_BLKS
   
   ;# Should be temporarily unsecure
   ;# Confirm unsecured
   return [ isUnsecure ]

   ;# Flash is now Blank and unsecured
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