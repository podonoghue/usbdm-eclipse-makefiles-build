
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
;#  V4.12.1.325 - Created
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
   
   set ::HCS08_SOPT5               0x3008
   set ::HCS08_SOPT5_COP_DISABLE   0x00
                                
   set ::NVM_FCLKDIV              0x3020
   set ::NVM_FSEC                 0x3021
   set ::NVM_FCCOBIX              0x3022
   set ::NVM_FCNFG                0x3024
   set ::NVM_FSTAT                0x3026
   set ::NVM_FPROT                0x3028
   set ::NVM_xPROT_VALUE          0xFF
   set ::NVM_FCCOBHI              0x302A
   set ::NVM_FCCOBLO              0x302B
   set ::NVM_FOPT                 0x302C ;# NV reg loaded from flash 0xFF7E

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
      ;# for debug
      rb $::HCS08_SOPT5
      wb $::HCS08_SOPT5 $::HCS08_SOPT5_COP_DISABLE ;# Disable COP
      rb $::HCS08_SOPT5
   }
   
}

;######################################################################################
;#
;# @param flashRegions - list of flash array addresses
;#
proc initTarget { flashRegions } {
   puts "Target script = HCS08-PBxx-flash-scripts.tcl"
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
   wb $::NVM_FCLKDIV $cfmclkd             ;# Flash divider
   rb $::NVM_FCLKDIV
   
   wb $::NVM_FPROT   $::NVM_xPROT_VALUE   ;# unprotect Flash
   
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

   puts "executeFlashCommand { $cmd $address $data0 $data1 $data2 $data3 }"
   
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

   initFlash [expr [speed]/1000]  ;# Flash speed calculated from BDM connection speed

   ;# Mass erase flash
   executeFlashCommand $::NVM_FCMD_ERASE_ALL_BLKS
   
   ;# Should be temporarily unsecure until next reset
   ;# Confirm unsecured
   return [ isUnsecure ]
}

;######################################################################################
;#  Verifies that all flash blocks are erased in Target - not used
;#
proc eraseVerifyTarget { } {

   puts "eraseVerifyTarget{}"
   
   ;# No initial connect as may fail.  Assumed done by caller.

   initFlash [expr [speed]/1000]  ;# Flash speed calculated from BDM connection speed

   ;# Mass erase flash
   executeFlashCommand $::NVM_FCMD_ERASE_VERIFY
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
   
   set securityValue [rb $::NVM_FSEC]
   if [ expr ( $securityValue & $::NVM_FSEC_SEC_MASK ) != $::NVM_FSEC_SEC_UNSEC ] {
      puts "isUnsecure{} - Target is secured!"
      return $::PROGRAMMING_RC_ERROR_SECURED
   }
   puts "isUnsecure{} - Target is unsecured"
   return $::PROGRAMMING_RC_OK
}

;######################################################################################
;# Actions on initial load
;#

puts "Target script = HCS08-PBxx-flash-scripts.tcl"

loadSymbols

