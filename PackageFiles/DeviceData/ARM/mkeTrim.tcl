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
   
   set ::SIM_SRSID                       0x40048000
   set ::SIM_SRSID_WDOG_MASK             0b100000
   
   set ::ICS_C3                 0x40064002
   set ::ICS_C4                 0x40064003
   set ::ICS_C4_SCFTRIM_MASK    0x01
   
   set ::LOAD_ADDRESS           0x20000000

###################################################   
# Write trim value to trim registers
#
# @param value Trim value to write
#   
proc writeTrim { value } {
   puts stderr [format "Trim = 0x%02X (%d)" $value $value]
   
   set ics_c4 [ expr [rb $::ICS_C4] & ~$::ICS_C4_SCFTRIM_MASK ]
   wb $::ICS_C4 [ expr $ics_c4|($value&$::ICS_C4_SCFTRIM_MASK) ]
   wb $::ICS_C3 [ expr $value>>1 ]
}

###################################################   
# Wait while CPU is executing
#
# @return wait time in ms or -1 on fail
#
proc waitWhileBusy { retries } {

   set TIME_start [clock clicks -milliseconds]

#   puts stderr "waitWhileBusy{} - retries = $retries"
   
   rcreg $::MDM_AP_Status
   
   for {set retry 0} {$retry < $retries} {incr retry} {
#      puts stderr "waitWhileBusy{} - Waiting..."
      set mdmApStatus [rcreg -q $::MDM_AP_Status]
      if [expr (($mdmApStatus & $::MDM_AP_ST_CORE_HALTED) != 0)] {
         set TIME_taken [expr [clock clicks -milliseconds] - $TIME_start]
         puts stderr "waitWhileBusy{} - MDM_AP_ST_CORE_HALTED asserted OK"
         return $TIME_taken;
      }
      after 5
   }
   puts stderr "waitWhileBusy{} - MDM_AP_ST_CORE_HALTED failed to set"
   return -1
}

###################################################   
# Write timing loop code to RAM
#
# Timing loop code
#   0: 2064        movs  r0, #100 @ 0x64
#   2: 4903        ldr   r1, [pc, #12]  @ (10 <count>)
#   4: 3901        subs  r1, #1
#   6: d1fd        bne.n 4 <skip1>
#   8: 3801        subs  r0, #1
#   a: d1fa        bne.n 2 <skip0>
#   c: be01        bkpt  0x0001
#   e: e7fe        b.n   .
#  10: 0002ffff    .word 0x0002ffff
proc writeTimingCode {} {
   connect
   ww $::LOAD_ADDRESS 0x2064 0x4903 0x3901 0xd1fd 0x3801 0xd1fa 0xBE01 0xE7FE 0xffff 0x0002
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
#  18: 46c0        nop         @ (mov r8, r8)
#  1a: 46c0        nop         @ (mov r8, r8)
#  1c: 46c0        nop         @ (mov r8, r8)
#  1e: 46c0        nop         @ (mov r8, r8)
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
   reset
   writeWdogCode
   wpc $::LOAD_ADDRESS
   go
   return [waitWhileBusy 500]
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
   go
   set time [waitWhileBusy 4000]
   puts "time = $time"
   return $time
}

###################################################   
# Estimate trim value
# It runs the trim measurement several times and then
# uses linear regression to estimate a trim value
#
# @return measured trim
#
proc regress {} {

   set sumx    0.0     ;#  sum of x     
   set sumy    0.0     ;#  sum of y     
   set sumx2   0.0     ;#  sum of x**2  
   set sumy2   0.0     ;#  sum of y**2  
   set sumxy   0.0     ;#  sum of x * y 

   # Load code
   writeTimingCode
      
   # Trim values to try
   # This assumes the expected trim is ~200
   set yValues { 150 200 250 }
   set n [llength $yValues]
   
   foreach {yValue} $yValues {
#      puts stderr "yValue = $yValue"
      set xValue [timingLoop $yValue]
      if [expr $xValue < 0 ] {
         return -1
      }
      lappend xValues $xValue
      
#      puts stderr "xValue = $xValue"
      set sumx  [expr $sumx + $xValue] 
      set sumy  [expr $sumy + $yValue] 
      set sumx2 [expr $sumx2 + ($xValue * $xValue)] 
      set sumy2 [expr $sumy2 + ($yValue * $yValue)] 
      set sumxy [expr $sumxy + ($xValue * $yValue)] 
   }
   set denom [expr $n * $sumx2 - $sumx*$sumx]
   if [expr $denom == 0 ] {
      return -1
   }
#   puts stderr "denom = $denom"
#   
#   puts stderr "Xs = $yValues"
#   puts stderr "Ys = $xValues"
   
   set m [expr ($n * $sumxy  -  $sumx * $sumy) / $denom]
   set b [expr ($sumy * $sumx2  -  $sumx * $sumxy) / $denom]
#   puts stderr [format "M = %.2f, B = %.1f" $m $b ]
   
   # The following value was found by trial and error for default MKE 24MHz target clock out of reset
   set targetCount 2460
   set trimValue [expr round($m * $targetCount + $b)]
   
   return $trimValue
}

###################################################   
# Find and print trim value
#
# @return measured trim value
#
proc findTrim {} {
   disableWdog
   set trimValue [ regress ]
   puts stderr "Trim value = $trimValue"
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


