
######################################################################################
#  This file defines the following flash functions
#  
#  massEraseTarget - Entirely erases the target.
#                    The target should be left in an unsecured state.
#
#  isUnsecure - indicates if the target is secured in some fashion (read/write protected)
#               Returns 0 if NOT secured
#
#  initFlash - initialises the target for flash programing (if needed)
#
#  initTarget - initialises the target for general use
#
#  In addition the script may do any once-only initialisation such as setting global symbols
#  when initially loaded into the TCL environment.
#

#####################################################################################
#  History
#
#  V4.12.1.330 - Added updated return code handling
#  V4.12.1.320 - Added resetAndConnectTarget()
#  V4.12.1.320 - Added clock trim
#  V4.12.1.180 - Removed unnecessary semi-colons
#  V4.12.1.180 - Messages directed to stderr
#  V4.12.1.180 - Changed to reset special vendor
#  V4.12.1.160 - Restored NMI masking to massErase{}
#  V4.12.1.150 - Changed to use more uniform method and re-tested
#  V4.12.1.60  - Added NMI masking to massErase{}
#  V4.10.4.250 - Simplified
#  V4.10.4.240 - Added return error codes
#  V4.10.4.140 - Changed Mass erase sequence (added retry etc.)
#  V4.10.4     - Changed return code handling
#              - Changed Mass erase reset to special-software (FDPROT etc wasn't unprotected)
# 
# Notes on MKExxZ
# - Cortex-M0+
# - Support connection, mass-erase etc. with Reset pin held low BUT MDM-AP.Status signals are disabled
# - MDM-AP.System_Reset_Request is supported when secure
# - NMI can be disabled through SIM_SOPT register

######################################################################################
#
#
proc loadSymbols {} {
   # LittleEndian format for writing numbers to memory
   setbytesex littleEndian

   set ::NAME  "Kinetis-MKExxZ-flash-scripts"
   puts "==========================================================="
   puts "$::NAME.loadSymbols{} - V4.12.1.330"
   
   # These variables are available from driver
   # ::RESET_DURATION       
   # ::RESET_RECOVERY       
   # ::RESET_RELEASE        
   # ::POWER_OFF_DURATION   
   # ::POWER_ON_RECOVERY    
   # ::RESET_METHOD         ;# TargetDefault/ResetHardware/ResetSoftware/ResetVendor/ResetNone
   # ::ERASE_METHOD         ;# TargetDefault/EraseNone/EraseMass/EraseAll/EraseSelective
   
   set ::MDM_AP_Status                   0x01000000
   set ::MDM_AP_Control                  0x01000004
   set ::MDM_AP_Ident                    0x010000FC
   
   set ::MDM_AP_ST_MASS_ERASE_ACK        0x00000001
   set ::MDM_AP_ST_MASS_FLASH_RDY        0x00000002
   set ::MDM_AP_ST_SYSTEM_SECURITY       0x00000004
   set ::MDM_AP_ST_SYSTEM_RESET          0x00000008
   set ::MDM_AP_ST_MASS_ERASE_EN         0x00000020
   set ::MDM_AP_ST_BACKDOOR_EN           0x00000040
   set ::MDM_AP_ST_LP_ENABLE             0x00000080
   set ::MDM_AP_ST_VLP_MODE              0x00000100
   set ::MDM_AP_ST_LLS_MODE_EXIT         0x00000200
   set ::MDM_AP_ST_VLLSx_MODE_EXIT       0x00000400
   set ::MDM_AP_ST_CORE_HALTED           0x00010000
   set ::MDM_AP_ST_SLEEP                 0x00020000
   set ::MDM_AP_ST_SLEEP_DEEP            0x00040000
   set ::MDM_AP_ST_SLEEP_MASK            0x00060000

   set ::MDM_AP_C_MASS_ERASE             0x00000001
   set ::MDM_AP_C_DEBUG_DISABLE          0x00000002
   set ::MDM_AP_C_DEBUG_REQUEST          0x00000004
   set ::MDM_AP_C_SYSTEM_RESET           0x00000008
   set ::MDM_AP_C_CORE_HOLD              0x00000010
   set ::MDM_AP_C_VLLDBREQ               0x00000020
   set ::MDM_AP_C_VLLDBACK               0x00000040
   set ::MDM_AP_C_LLS_ST_ACK             0x00000080
                                    
   set ::DHCSR                           0xE000EDF0
                                    
   set ::DHCSR_C_DEBUGEN                 0x00000001
   set ::DHCSR_C_HALT                    0x00000002
   set ::DHCSR_C_STEP                    0x00000004
   set ::DHCSR_C_MASK_INTS               0x00000008
   set ::DHCSR_C_SNAP_STALL              0x00000020
   set ::DHCSR_DBGKEY                    0xA05F0000
   set ::DHCSR_VALUE                     0xA05F0001
   
   set ::DEMCR                           0xE000EDFC
   set ::DEMCR_VALUE                     0x010007F1

   set ::DEMCR_VC_CORERESET              0x00000001
   set ::DEMCR_VC_HARDERROR              0x00000400
   set ::DEMCR_VC_DWTENA                 0x01000000
   
   set ::MC_SRSH                         0x4007E000
   set ::MC_SRSL                         0x4007E001

   set ::NV_BACKKEY0                     0x0400
   set ::NV_BACKKEY1                     0x0401
   set ::NV_BACKKEY2                     0x0402
   set ::NV_BACKKEY3                     0x0403
   set ::NV_BACKKEY4                     0x0404
   set ::NV_BACKKEY5                     0x0405
   set ::NV_BACKKEY6                     0x0406
   set ::NV_BACKKEY7                     0x0407
   set ::NV_FPROT3                       0x0408
   set ::NV_FPROT2                       0x0409
   set ::NV_FPROT1                       0x040A
   set ::NV_FPROT0                       0x040B
   set ::NV_FSEC                         0x040C
   set ::NV_FOPT                         0x040D
   set ::NV_FEPROT                       0x040E
   set ::NV_FDPROT                       0x040F
   
   set ::SIM_SRSID                       0x40048000
   set ::SIM_SRSID_WDOG_MASK             0b100000
   
   set ::MCM_PLACR                       0xF000300C

   set ::FMC_PFAPR                       0x4001F000
   set ::FMC_PFB0CR                      0x4001F004
   set ::FMC_PFB1CR                      0x4001F008

   set ::FTFL_FSTAT                      0x40020000 ;# Flash Status Register, offset: 0x0
   set ::FTFL_FCNFG                      0x40020001 ;# Flash Configuration Register, offset: 0x1
   set ::FTFL_FSEC                       0x40020002 ;# Flash Security Register, offset: 0x2
   set ::FTFL_FOPT                       0x40020003 ;# Flash Option Register, offset: 0x3
   set ::FTFL_FCCOB3                     0x40020004 ;# Flash Common Command Object Registers, offset: 0x4
   set ::FTFL_FCCOB2                     0x40020005 ;# Flash Common Command Object Registers, offset: 0x5
   set ::FTFL_FCCOB1                     0x40020006 ;# Flash Common Command Object Registers, offset: 0x6
   set ::FTFL_FCCOB0                     0x40020007 ;# Flash Common Command Object Registers, offset: 0x7
   set ::FTFL_FCCOB7                     0x40020008 ;# Flash Common Command Object Registers, offset: 0x8
   set ::FTFL_FCCOB6                     0x40020009 ;# Flash Common Command Object Registers, offset: 0x9
   set ::FTFL_FCCOB5                     0x4002000A ;# Flash Common Command Object Registers, offset: 0xA
   set ::FTFL_FCCOB4                     0x4002000B ;# Flash Common Command Object Registers, offset: 0xB
   set ::FTFL_FCCOBB                     0x4002000C ;# Flash Common Command Object Registers, offset: 0xC
   set ::FTFL_FCCOBA                     0x4002000D ;# Flash Common Command Object Registers, offset: 0xD
   set ::FTFL_FCCOB9                     0x4002000E ;# Flash Common Command Object Registers, offset: 0xE
   set ::FTFL_FCCOB8                     0x4002000F ;# Flash Common Command Object Registers, offset: 0xF
   set ::FTFL_FPROT                      0x40020010 ;# Program Flash Protection Registers, offset: 0x10 (4 bytes)
   set ::FTFL_FEPROT                     0x40020016 ;# EEPROM Protection Register, offset: 0x16
   set ::FTFL_FDPROT                     0x40020017 ;# Data Flash Protection Register, offset: 0x17

   set ::FTFL_FSTAT_CCIF                 0x80
   set ::FTFL_FSTAT_RDCOLLERR            0x40
   set ::FTFL_FSTAT_ACCERR               0x20
   set ::FTFL_FSTAT_FPVIOL               0x10
   set ::FTFL_FSTAT_MGSTAT0              0x01

   set ::FTFL_FCNFG_CCIE                 0x80
   set ::FTFL_FCNFG_RDCOLLIE             0x40
   set ::FTFL_FCNFG_ERSAREQ              0x20
   set ::FTFL_FCNFG_ERSSUSP              0x10
   set ::FTFL_FCNFG_SWAP                 0x08
   set ::FTFL_FCNFG_PFLSH                0x04
   set ::FTFL_FCNFG_RAMRDY               0x02
   set ::FTFL_FCNFG_EEERDY               0x01

   set ::FTFL_FSEC_KEYEN                 0x80
   set ::FTFL_FSEC_MEEN                  0x30
   set ::FTFL_FSEC_FSLACC                0x0C
   set ::FTFL_FSEC_SEC                   0x02
   set ::FTFL_FSEC_DEFAULT_UNSEC_VALUE   0xBE

   set ::FOPT_LPBOOTn                    0x01
   set ::FOPT_EZPORT                     0x02
   
   # Flash commands
   set ::F_RD1BLK                        0x00
   set ::F_RD1SEC                        0x01
   set ::F_PGMCHK                        0x02
   set ::F_RDRSRC                        0x03
   set ::F_PGM4                          0x06
   set ::F_ERSBLK                        0x08
   set ::F_ERSSCR                        0x09
   set ::F_PGMSEC                        0x0B
   set ::F_RD1ALL                        0x40
   set ::F_RDONCE                        0x41
   set ::F_PGMONCE                       0x43
   set ::F_ERSALL                        0x44
   set ::F_VFYKEY                        0x45
   set ::F_PGMPART                       0x80
   set ::F_SETRAM                        0x81
   
   set ::BDM_CAP_HCS12                   0x0001  ;# Supports HCS12
   set ::BDM_CAP_RS08                    0x0002  ;# 12 V Flash programming supply available (RS08 support)
   set ::BDM_CAP_VDDCONTROL              0x0004  ;# Control over target Vdd
   set ::BDM_CAP_VDDSENSE                0x0008  ;# Sensing of target Vdd
   set ::BDM_CAP_CFVx                    0x0010  ;# Support for CFV 1,2 & 3
   set ::BDM_CAP_HCS08                   0x0020  ;# Supports HCS08 targets - inverted when queried
   set ::BDM_CAP_CFV1                    0x0040  ;# Supports CFV1 targets  - inverted when queried
   set ::BDM_CAP_JTAG                    0x0080  ;# Supports JTAG targets
   set ::BDM_CAP_DSC                     0x0100  ;# Supports DSC targets
   set ::BDM_CAP_ARM_JTAG                0x0200  ;# Supports ARM targets via JTAG
   set ::BDM_CAP_RST                     0x0400  ;# Control & sensing of RESET
   set ::BDM_CAP_PST                     0x0800  ;# Supports PST signal sensing
   set ::BDM_CAP_CDC                     0x1000  ;# Supports CDC Serial over USB interface
   set ::BDM_CAP_ARM_SWD                 0x2000  ;# Supports ARM targets via SWD

   set ::PROGRAMMING_RC_OK                           0
   set ::BDM_RC_OPERATION_NOT_SUPPORTED             57
   set ::PROGRAMMING_RC_ERROR_SECURED              114
   set ::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND 115
   set ::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE 116

   set ::SIM_SOPT                       0x40048004
   set ::SIM_SOPT_NMIE_MASK             0x02                 
    
   set ::SIM_SRSID                       0x40048000
   set ::SIM_SRSID_WDOG_MASK             0b100000
   
   set ::ICS_C3                 0x40064002
   set ::ICS_C4                 0x40064003
   set ::ICS_C4_SCFTRIM_MASK    0x01
   
   set ::LOAD_ADDRESS           0x20000000

   set ::PROGRAMMING_RC_OK                    0
   set ::PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS -101
   set ::PROGRAMMING_RC_ERROR_TRIM           -113

   return
}

######################################################################################
#
#  This is used for the initial connection to the target
#
proc resetAndConnectTarget { args } {

   puts "================================================================="
   puts "$::NAME.resetAndConnectTarget $args"
   
   # Cycle power if feature available   
   if [expr ( [getcap] & $::BDM_CAP_VDDCONTROL) != 0] {
      settargetvdd off
      pinSet rst=0
      after $::RESET_DURATION
      settargetvdd on
      after $::POWER_ON_RECOVERY
   }
   reset sh 
   
   if { [catch {connect} rc] } {
      puts "Failed 1st connect - retry"
      connect
   }
}

######################################################################################
#
#
proc initTarget { args } {
   puts "=============================================================="
   puts "$::NAME.initTarget $args"
   # Not used
   # puts [format "MDM-AP-CONTROL = 0x%08X" [rcreg $::MDM_AP_Control]]
}

######################################################################################
#
#  frequency - Target bus frequency in kHz
#
proc initFlash { frequency } {

   puts "============================================="
   puts "$::NAME.initFlash $frequency"
   # Not used
   # Uprotecting flash and caching done by target routines
   # puts [format "MDM-AP-CONTROL = 0x%08X" [rcreg $::MDM_AP_Control]]
}

######################################################################################
#  Target is mass erased and left unsecured (non-blank!)
#
proc massEraseTarget { } {

   puts "============================================="
   puts "$::NAME.massEraseTarget"
   
   # Apply hardware reset
   puts "massEraseTarget{} - Applying hardware reset"
   pinSet rst=0

   # Cycle power if feature available   
   # Upsets things on MK devices
   if [expr ( [getcap] & $::BDM_CAP_VDDCONTROL) != 0] {
      puts "massEraseTarget{} - Cycling Vdd"
      settargetvdd off
      after $::RESET_DURATION
      settargetvdd on
      after $::POWER_ON_RECOVERY
   }

   # Connect with reset asserted, ignore errors as may be secured
   puts "massEraseTarget{} - Connecting (Ignoring errors)"
   catch { connect }
   rcreg $::MDM_AP_Status

   puts "massEraseTarget{} - Doing reset s v (Ignoring errors)"
   catch { reset s v }
   rcreg $::MDM_AP_Status

   # release target reset
   puts "massEraseTarget{} - releasing reset pin"
   pinSet
   
   # Reset recovery
   puts "massEraseTarget{} - wait reset recovery time ($::RESET_RECOVERY)"
   after $::RESET_RECOVERY

   rcreg $::MDM_AP_Control
   rcreg $::MDM_AP_Status
   
   # Wait for Flash Ready
   for {set retry 0} {$retry < 20} {incr retry} {
      puts -nonewline stderr "massEraseTarget{} - Waiting for Flash ready  "
      set mdmApStatus [rcreg $::MDM_AP_Status]
      if [expr (($mdmApStatus & $::MDM_AP_ST_MASS_FLASH_RDY) != 0)] {
         puts "massEraseTarget{} - MDM_AP_ST_MASS_FLASH_RDY asserted OK"
         break;
      }
      after 20
   }

   puts "massEraseTarget{} - Asserting MDM_AP_C_DEBUG_REQUEST"
   wcreg $::MDM_AP_Control $::MDM_AP_C_DEBUG_REQUEST
   rcreg $::MDM_AP_Control
   
   puts "massEraseTarget{} - Asserting MDM_AP_C_DEBUG_REQUEST|MDM_AP_C_MASS_ERASE"
   wcreg $::MDM_AP_Control [expr $::MDM_AP_C_DEBUG_REQUEST|$::MDM_AP_C_MASS_ERASE]
   rcreg $::MDM_AP_Control

   # Wait for Flash Mass Erase ACK
   for {set retry 0} {$retry < 20} {incr retry} {
      puts "massEraseTarget{} - Waiting for Flash Erase ACK"
      set mdmApStatus [rcreg $::MDM_AP_Status]
      if [expr (($mdmApStatus & $::MDM_AP_ST_MASS_ERASE_ACK) != 0)] {
         puts "massEraseTarget{} - MDM_AP_ST_MASS_ERASE_ACK asserted OK"
         break;
      }
      after 20
   }

   # Wait for Flash Mass Erase to complete
   for {set retry 0} {$retry < 20} {incr retry} {
      puts "massEraseTarget{} - Waiting for Flash Mass Erase to complete"
      set mdmApControl [rcreg $::MDM_AP_Control]
      if [expr (($mdmApControl & $::MDM_AP_C_MASS_ERASE) == 0)] {
         puts "massEraseTarget{} - MDM_AP_C_MASS_ERASE cleared - OK"
         break;
      }
      after 50
   }

   rcreg $::MDM_AP_Control
   rcreg $::MDM_AP_Status
   
   # Resetting target using MDM
   puts "massEraseTarget{} - Writing MDM_AP_C_SYSTEM_RESET|MDM_AP_C_CORE_HOLD"
   wcreg $::MDM_AP_Control [expr $::MDM_AP_C_CORE_HOLD | $::MDM_AP_C_SYSTEM_RESET]

   # Disable NMI here so we can still debug target using Erase-All option
   puts "massEraseTarget{} - Disabling NMI"
   catch { connect }
   set soptValue [rb $::SIM_SOPT]
   wb  $::SIM_SOPT [ expr $soptValue & ~$::SIM_SOPT_NMIE_MASK]
   rb $::SIM_SOPT

   puts "massEraseTarget{} - Clearing MDM_AP_C_SYSTEM_RESET"
   wcreg $::MDM_AP_Control [expr $::MDM_AP_C_CORE_HOLD]

   puts "massEraseTarget{} - Releasing MDM_AP_C_CORE_HOLD"
   wcreg $::MDM_AP_Control 0

   set rc [ isUnsecure ]
   
   # For debug
   rcreg $::MDM_AP_Status
   rcreg $::MDM_AP_Control
   
   if [expr ( $rc != 0 )] {
      puts "massEraseTarget{} - Target is still secured!"
      return -code error $::PROGRAMMING_RC_ERROR_SECURED
   }
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
   
   catch { connect }

   set securityValue [ rcreg $::MDM_AP_Status ]
   puts [format "isUnsecure{} - MDM_AP_Status=0x%X" $securityValue ]
   if [ expr ( $securityValue & $::MDM_AP_ST_SYSTEM_SECURITY ) != 0 ] {
      puts "isUnsecure{} - Target is secured!"
      return $::PROGRAMMING_RC_ERROR_SECURED
   }
   puts "isUnsecure{} - Target is unsecured"
   return $::PROGRAMMING_RC_OK
}

# For testing
proc o { } {
   settarget arm
   openbdm 0
   catch { connect }
   pinSet rst=0
   catch { reset s v }
   isUnsecure
   catch { connect }
}

# For testing
proc c { } {
   closebdm
}

# For testing
proc m { } {
   massEraseTarget
}

# For testing
proc d { } {
   puts ""
   puts ""
   puts ""
   set ::RESET_RECOVERY  100
   o
   m
   rb 0x400 16
   c
}

# For testing
proc t { } {
   puts ""
   puts ""
   puts ""
   
   reset s v
   pinSet rst=0
   after 100
   pinSet
}

###################################################   
# Write trim value to trim registers
#
# @param value Trim value to write
#   
proc writeTrim { value } {
   puts [format "Trim = 0x%02X (%d)" $value $value]
   
   set ics_c4 [ expr [rb $::ICS_C4] & ~$::ICS_C4_SCFTRIM_MASK ]
   wb $::ICS_C4 [ expr $ics_c4|($value&$::ICS_C4_SCFTRIM_MASK) ]
   wb $::ICS_C3 [ expr $value>>1 ]
}

###################################################   
# Wait while CPU is executing
#
# @return wait time in ms
#
proc runUntilStopped { retries } {

#   puts "runUntilStopped{} - retries = $retries"
   
   set TIME_start [clock clicks -milliseconds]
   
   go

#   rcreg $::MDM_AP_Status
   
   for {set retry 0} {$retry < $retries} {incr retry} {
#      puts "runUntilStopped{} - Waiting..."
      set mdmApStatus [rcreg -q $::MDM_AP_Status]
      if [expr (($mdmApStatus & $::MDM_AP_ST_CORE_HALTED) != 0)] {
         set TIME_taken [expr [clock clicks -milliseconds] - $TIME_start]
         puts "runUntilStopped{} - MDM_AP_ST_CORE_HALTED asserted OK"
         return $TIME_taken;
      }
      after 5
   }
   return -code error "runUntilStopped{} - MDM_AP_ST_CORE_HALTED failed to set"
}

###################################################   
# Write timing loop code to RAM
#
#   //    Timing loop code
#   asm (
#      "        movs   r0, #100 \n" //  2: 2064      movs   r0,#100
#      "oloop:  ldr    r1, data \n" //  4: 4903      ldr    r1,[pc, #24]
#      "iloop:  sub    r1, #1   \n" //  6: 3901      subs   r1,#1
#      "        bne    iloop    \n" //  8: d1fd      bne.n  iloop
#      "        sub    r0, #1   \n" //  a: 3801      subs   r0,#1
#      "        bne    oloop    \n" //  c: d1fa      bne.n  oloop
#      "        bkpt   0x0001   \n" //  e: be01      bkpt   0x0001
#      "        b      .        \n" // 10: e7fe      b.n    .
#      "       .align 2         \n" // 12: 46c0      fill
#      " data: .word 0x0002ffff \n" // 14: 0002 ffff .word 0x0002ffff
#   );
proc writeTimingCode {} {
   connect
   ww $::LOAD_ADDRESS 0x2064 0x4903 0x3901 0xd1fd 0x3801 0xd1fa 0xBE01 0xE7FE 0xFFFF 0x0002
}

###################################################   
# Write Watchdog disable code to RAM
#
# @param value Trim value to write
#   
# Watchdog disable code
#   0: 4807        ldr   r0, [pc, #28]  @ (20 <wdog>)
#   2: 4908        ldr   r1, [pc, #32]  @ (24 <Unlock1>)
#   4: 4a08        ldr   r2, [pc, #32]  @ (28 <Unlock2>)
#   6: 8041        strh  r1, [r0, #2]
#   8: 8042        strh  r2, [r0, #2]
#   a: 8842        ldrh  r2, [r0, #2]
#   c: 8081        strh  r1, [r0, #4]
#   e: 80c1        strh  r1, [r0, #6]
#  10: 2100        movs  r1, #0
#  12: 8001        strh  r1, [r0, #0]
#  14: be01        bkpt  0x0001
#  16: e7fe        b.n   .
#  18: 46c0        fill
#  1a: 46c0        fill
#  1c: 46c0        fill
#  1e: 46c0        fill
#
#  20: 40052000    .word 0x40052000
#  24: 20c5        .short   0x20c5
#  26: 46c0        nop         @ (mov r8, r8)
#  28: 28d9        .short   0x28d9

proc writeWdogCode {} {
   connect
   ww $::LOAD_ADDRESS 0x4807 0x4908 0x4a08 0x8041 0x8042 0x8842 0x8081 0x80c1 0x2100 0x8001 0xbe01 0xe7fe 0x0000 0x0000 0x0000 0x0000 0x2000 0x4005 0x20c5 0x0000 0x28d9
}

###################################################   
# Disable watch-dog
#
proc disableWdog {} {
   puts "$::NAME.disableWdog"
   reset
   writeWdogCode
   wpc $::LOAD_ADDRESS
   runUntilStopped 500
}

###################################################   
# Write trim value to trim registers
#
# @param value Trim value to write
#   
# @return measured timing loop delay in ms
#
proc timingLoop { trim } {
   writeTrim $trim 
   wpc $::LOAD_ADDRESS
   set time [runUntilStopped 4000]
   puts "time = $time"
   return $time
}

###################################################   
# Estimate trim value
# It runs the trim measurement several times and then
# uses linear regression to estimate a trim value
#
# @param targetCount The delay time to trim against
#        This value is an emprical value determined for the target device.
#        It is the measured delay time for a 'correctly' trimmed device
#        executing the timing code.
#
# @return measured trim
#
proc regress { targetCount } {

   set sumx    0.0     ;#  sum of x     
   set sumy    0.0     ;#  sum of y     
   set sumx2   0.0     ;#  sum of x**2  
   set sumy2   0.0     ;#  sum of y**2  
   set sumxy   0.0     ;#  sum of x * y 

   # Load code
   writeTimingCode
      
   # Trim values to try
   # This assumes the expected trim is ~200
   set yValues { 120 200 280 }
   set n [llength $yValues]
   
   foreach {yValue} $yValues {
#      puts "yValue = $yValue"
      set xValue [timingLoop $yValue]
      if [expr $xValue < 0 ] {
         return -1
      }
      lappend xValues $xValue
      
#      puts "xValue = $xValue"
      set sumx  [expr $sumx + $xValue] 
      set sumy  [expr $sumy + $yValue] 
      set sumx2 [expr $sumx2 + ($xValue * $xValue)] 
      set sumy2 [expr $sumy2 + ($yValue * $yValue)] 
      set sumxy [expr $sumxy + ($xValue * $yValue)] 
   }
   set denom [expr $n * $sumx2 - $sumx*$sumx]
   if [expr $denom == 0 ] {
      return -code error $::PROGRAMMING_RC_ERROR_TRIM
   }
#   puts "denom = $denom"
#   
#   puts "Xs = $yValues"
#   puts "Ys = $xValues"
   
   set m [expr ($n * $sumxy  -  $sumx * $sumy) / $denom]
   set b [expr ($sumy * $sumx2  -  $sumx * $sumxy) / $denom]
#   puts [format "M = %.2f, B = %.1f" $m $b ]
   
   set trimValue [expr round($m * $targetCount + $b)]
   
   return $trimValue
}

###################################################   
# Find and print trim value
#
# @return measured trim value
#
proc findTrim { targetfrequency } {

   puts "============================================="
   puts "$::NAME.findTrim"
   
   # Only supports 37.50 kHz trimming
   if [expr $targetfrequency != 37500 ] {
      return -code error $::PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS
   }

   # The following value was found by trial and error for default MKE04 24MHz target clock out of reset
   set targetCount 2458
   
   disableWdog
   set trimValue [ regress $targetCount ]
   puts "Trim value = $trimValue"
   return $trimValue
}

###################################################   
# Used to find a calibration value
#
# @param trim The trim value to use
#
# @return measured timing loop delay
#
proc testTrim { trim } {
  timingLoop $trim
}

###################################################   
# Open BDM 
#
proc init {} {
   settarget arm
   settargetvdd 5
   openbdm
}


######################################################################################
# Actions on initial load
#
loadSymbols

