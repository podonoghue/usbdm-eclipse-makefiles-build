;#<![CDATA[

;######################################################################################
;#  This file defines the following flash functions
;#  
;#  massEraseFlash - Entirely erases the device using whatever efficient means is available.
;#                   The device should be left in an unsecured state.
;#                   If such a function is not available TCL_ERROR should be returned 
;#                   and a slower page-by-page method will be used by the programmer.
;#
;#  isUnsecure - indicates if the device is secured in some fashion (read/write protected)
;#               Returns TCL_OK if NOT secured
;#
;#  initFlash - initialises the target for flash programing (if needed)
;#
;#  initTarget - initialises the target for general use
;#
;#  In addition the script may do any once-only initialisation such as setting global symbols
;#  when initially loaded into the TCL environment.
;#
proc loadSymbols {} {
   # Big-Endian format for writing numbers to memory
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
   
   set ::PDDPAR       [expr 0x00100074+$::IPSBASE]
   set ::SYNCR        [expr 0x00120000+$::IPSBASE] ;# 16-bit
   set ::CCHR         [expr 0x00120008+$::IPSBASE] ;# 8-bit
}
proc initTarget {}  {
   wcreg $::VBR_REG      0x00000000
   wcreg $::RAMBAR_REG   [expr $::RAMBASE+$::RAMBAR_OPTS]
   wcreg $::FLASHBAR_REG [expr $::FLASHBASE+$::FLASHBAR_OPTS]
   
   wb $::PDDPAR    0x0F       ;# Enable PST signals
   
;#   wb $::CCHR      0x04       ;# /5
;#   ww $::SYNCR     0x4103     ;# Set RFD+1 to avoid frequency overshoot
;#   after 200                  ;# Wait for PLL lock
;#   ww $::SYNCR     0x4003     ;# Set desired RFD=0 and MFD=4 
;#   after 100                  ;# Wait for PLL lock
;#   ww $::SYNCR     0x4007     ;# Switch to using PLL
}
proc initFlash { frequency } {
   if { [expr $frequency != 0] } {
      if { [expr $frequency < 150] } {
         error "Clock too low for flash programming"
      }
      set cfmclkd 0
      if { [expr $frequency > 12800] } {
         set cfmclkd [expr $cfmclkd | 0x80]
         set frequency [expr $frequency / 8]
      }
      set cfmclkd [expr $cfmclkd | (($frequency-1)/200)]
      set flashClk [expr $frequency / (($cfmclkd  &0x7F)+1)]
;#      puts "cfmclkd = $cfmclkd, flashClk = $flashClk"
      if { [expr ($flashClk<150)||($flashClk>200)] } {
         error "Not possible to find suitable flash clock divider"
      }      
      wb $::CFMCLKD   $cfmclkd       ;# Flash clock divider
   }
   wl $::CFMPROT   0x00000000 ;# Unprotect Flash
   wl $::CFMDACC   0x00000000 ;# Allow data and instruction access
}
proc massEraseFlash {} {
;# ToDo
}
proc isUnsecure {} {
;# ToDo
}

loadSymbols
return

;#]]>
