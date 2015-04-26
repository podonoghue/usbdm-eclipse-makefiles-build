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
;#  V4.11.1.10  - Minor mods to use symbols
;#  V4.11.1.10  - Updated to include unsecure device
;#  V4.10.4 - Changed return code handling
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # BigEndian format for writing numbers to memory
   setbytesex bigEndian

   set ::VBR_REG       0x801;
   set ::RAMBAR_REG    0xC05;
   set ::FLASHBAR_REG  0xC04;
   set ::FLASHBASE     0x00000000;
   set ::RAMBASE       0x20000000;
   set ::IPSBASE       0x40000000;
   set ::RAMBAR_OPTS   0x21;
   set ::FLASHBAR_OPTS 0x61;
      
   set ::CFMMCR       [expr 0x001D0000+$::IPSBASE] ;# 16-bit
   set ::CFMCLKD      [expr 0x001D0002+$::IPSBASE] ;# 8-bit
   set ::CFMSEC       [expr 0x001D0008+$::IPSBASE]
   set ::CFMPROT      [expr 0x001D0010+$::IPSBASE]
   set ::CFMSACC      [expr 0x001D0014+$::IPSBASE]
   set ::CFMDACC      [expr 0x001D0018+$::IPSBASE]
   set ::CFMUSTAT     [expr 0x001D0020+$::IPSBASE] ;# 8-bit
   set ::CFMCMD       [expr 0x001D0024+$::IPSBASE] ;# 8-bit
   set ::CFMCLKSEL    [expr 0x001D004A+$::IPSBASE] ;# 16-bit
   set ::PRDIV8       0x40
     
   set ::BUS_FREQUENCY         4000   ;# Assumed bus frequency for flash erase when locked
   set ::JTAG_UNLOCK_CMD       0x0B   ;# JTAG Unlock command
   set ::JTAG_IR_LENGTH        4      ;# JTAG IR length for unlock command
   set ::JTAG_DR_LENGTH        16     ;# JTAG DR length for unlock flash divider value
   
   set ::PDDPAR       [expr 0x00100074+$::IPSBASE]
   set ::SYNCR        [expr 0x00120000+$::IPSBASE] ;# 16-bit
   set ::CCHR         [expr 0x00120008+$::IPSBASE] ;# 8-bit
   
   set ::BDM_RC_ILLEGAL_COMMAND                    4
   set ::PROGRAMMING_RC_ERROR_SECURED              114
   set ::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND 115
   set ::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE 116
   
   return
}

;######################################################################################
;#
;#
proc initTarget { args } {
   puts "VBR_REG      <= $::RAMBASE"
   wcreg $::VBR_REG      $::RAMBASE
   puts "RAMBAR_REG   <= [format 0x%08X [expr $::RAMBASE+$::RAMBAR_OPTS]]"
   wcreg $::RAMBAR_REG   [expr $::RAMBASE+$::RAMBAR_OPTS]
   puts "FLASHBAR_REG <= [format 0x%08X [expr $::FLASHBASE+$::FLASHBAR_OPTS]]"
   wcreg $::FLASHBAR_REG [expr $::FLASHBASE+$::FLASHBAR_OPTS]
   
   wb $::PDDPAR    0x0F       ;# Enable PST signals

   return

   ;# The following is not compatible with chips w/o xtals
   wb $::CCHR      0x04       ;# /5
   ww $::SYNCR     0x4103     ;# Set RFD+1 to avoid frequency overshoot
   after 200                  ;# Wait for PLL lock
   ww $::SYNCR     0x4003     ;# Set desired RFD=0 and MFD=4 
   after 100                  ;# Wait for PLL lock
   ww $::SYNCR     0x4007     ;# Switch to using PLL
   
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus frequency in kHz
;#
proc initFlash { busFrequency } {
;# Not used
   
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
;# This code assumes that busFrequency = sysclock = oscclk/2
;#
   ;#  puts "calculateFlashDivider {}"
   if { [expr $busFrequency < 1000] } {
      puts "Clock too low for flash programming"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }
   set oscFrequency [expr 2*$busFrequency]
   if { [expr $oscFrequency > 12800] } {
      set cfmclkd $::DSC_PRDIV8 
      set inFrequency [expr $oscFrequency/8]
   } else {
      set cfmclkd 0
      set inFrequency $oscFrequency 
   }
   set minPeriod [expr (1/200.0 + 1/(4.0*$busFrequency))]
   set cfmclkd [expr $cfmclkd + round(floor(($inFrequency*$minPeriod)))] 
   set flashClk [expr $inFrequency / (($cfmclkd&0x3F)+1)]
   puts [ format "inFrequency = %d kHz cfmclkd = 0x%02X, flashClk = %d kHz" $inFrequency $cfmclkd $flashClk ]
   if { [expr ($flashClk<150)] } {
      puts "Not possible to find suitable flash clock divider"
      error $::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE
   }      
   return $cfmclkd
}

;######################################################################################
;#  Target is erased & unsecured
proc massEraseTarget { } {

   puts "massEraseTarget{}"
   
   puts "reset s h"
   catch { reset s h }
   
   puts "connect"
   catch { connect }

   ;# Calculate clock divider using assumed reset bus frequency
   set cfmclkd [calculateFlashDivider $::BUS_FREQUENCY]
   puts "cfmclkd = [format 0x%02X $cfmclkd]"

   puts "jtag-reset"
   jtag-reset

   puts "Lockout Recovery CMD to instruction register"
   puts "jtag-shift-ir"
         jtag-shift-ir
   puts "jtag-shift D $::JTAG_IR_LENGTH $::JTAG_UNLOCK_CMD"
         jtag-shift D $::JTAG_IR_LENGTH $::JTAG_UNLOCK_CMD
   
   puts "Clk Divider to data register"
   puts "jtag-shift R $::JTAG_DR_LENGTH 0 [format 0x%02X $cfmclkd]"
         jtag-shift R $::JTAG_DR_LENGTH 0 $cfmclkd
   
   puts "Erase Delay"

   after 2000

   puts "Erase Complete"
   
   jtag-reset

   puts "reset s h"
   catch { reset s h }

   return
}

;######################################################################################
;#
proc isUnsecure { } {
;# Can't meaningfully do
   return 0
}

proc try {} {
   openbdm 1
   settarget jtag
   catch { massEraseTarget }
   closebdm
}

;######################################################################################
;# Actions on initial load
;#
loadSymbols

;#]]>
