;#<![CDATA[
;#
;######################################################################################
;#  This file defines the following flash functions
;#  
;#  massEraseFlash - Entirely erases the device using whatever efficient means is available.
;#                   The device should be left in an unsecured state.
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

;######################################################################################
;#
;#
proc loadSymbols {} {
   # BigEndian format for writing numbers to memory
   setbytesex bigEndian

   set  ::CFV1 3

   set  ::CFV1_DRegCSR   0 ;# - CSR
   set  ::CFV1_DRegXCSR  1 ;# - XCSR
   set  ::CFV1_DRegCSR2  2 ;# - CSR2
   set  ::CFV1_DRegCSR3  3 ;# - CSR3
      
   set  ::CFV1_ByteRegs       0x1000 ;# Special access to msb
   set  ::CFV1_DRegXCSRbyte   [expr $::CFV1_ByteRegs+$::CFV1_DRegXCSR] ;# - XCSR.msb
   set  ::CFV1_DRegCSR2byte   [expr $::CFV1_ByteRegs+$::CFV1_DRegCSR2] ;# - CSR2.msb
   set  ::CFV1_DRegCSR3byte   [expr $::CFV1_ByteRegs+$::CFV1_DRegCSR3] ;# - CSR3.msb

   set ::CFV1_XCSR_HALT         0x80
   set ::CFV1_XCSR_CSTAT_MASS   0x00
   set ::CFV1_XCSR_CLKSW        0x04
   set ::CFV1_XCSR_SEC          0x02  ;# read
   set ::CFV1_XCSR_ERASE        0x02  ;# write
   set ::CFV1_XCSR_ENBDM        0x01
}
;######################################################################################
;#
;#
proc initTarget {}  {
;# Not used
}
;######################################################################################
;#
;#  frequency - Target bus frequency in kHz
;#  flashControllerAddress
;#
proc initFlash { frequency flashControllerAddress } {
;# Not used
}
;######################################################################################
;#
;#  frequency - Target bus frequency in kHz
;#
proc calculateFlashDivider { frequency } {
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
   ;#puts "cfmclkd = $cfmclkd, flashClk = $flashClk"
   if { [expr ($flashClk<150)||($flashClk>200)] } {
      error "Not possible to find suitable flash clock divider"
   }      
   return $cfmclkd
}
;######################################################################################
;#
;#
proc massEraseFlash { } {

   puts "Mass erasing target"
   
   ;# Make sure BDM is using Bus clock & reconnect
   wdreg $::CFV1_DRegXCSRbyte [expr $::CFV1_XCSR_CLKSW|$::CFV1_XCSR_ENBDM]
   connect
;#   halt
   
   ;# Get target speed from BDM connection speed
   set busSpeedkHz [expr [speed]/1000]
   set cfmclkd [calculateFlashDivider  $busSpeedkHz]

   ;# Set Flash clock divider via BDM reg
   wdreg $::CFV1_DRegCSR3byte $cfmclkd

   ;# Mass erase via BDM registers 
   ;# (HALT is readonly but this is what the manual says) 
   wdreg $::CFV1_DRegXCSRbyte [expr $::CFV1_XCSR_HALT|$::CFV1_XCSR_CSTAT_MASS|$::CFV1_XCSR_ERASE|$::CFV1_XCSR_ENBDM|$::CFV1_XCSR_CLKSW]

   ;# Wait for command complete
   set flashBusy $::CFV1_XCSR_SEC
   set retry 0
   while { $flashBusy != 0} {
      set status [ rdreg $::CFV1_DRegXCSRbyte ]
      set flashBusy [expr $status & $::CFV1_XCSR_SEC]
      if [ expr $retry == 10] {
         error "Flash busy timeout"
      }
      after 100
      incr retry
   }
   if [ expr ( $status & $::CFV1_XCSR_SEC ) != 0 ] {
      error "Unsecure failed"
   }
   puts "Mass erase complete"
   isUnsecure
}
;######################################################################################
;#
;#
proc isUnsecure {} {
   ;# Check if not read protected   
   set status [ rdreg $::CFV1_DRegXCSRbyte ]
   if [ expr ( $status & $::CFV1_XCSR_SEC ) != 0 ] {
      error "Target is secured"
   }
   puts "Target is unsecure"
}

 proc readCN128Clock {} {
    puts "MCGC1"
    rb 0xFF8240
    puts "MCGC2"
    rb 0xFF8241
    puts "MCGC3"
    rb 0xFF8244
    puts "MCGC4"
    rb 0xFF8245
 
 }
proc safeConnect {} {
   
   reset s s

   ;# Try to connect - if fail prompt for manual power cycle
   ;# This is the only sure way to connect to a CFV1 target
   if { [catch {connect}] } {
      pinSet rst=0 bkgd=0
      dialogue "Power cycle needed" "Unable to connect to target. \n\nPlease cycle target power and click OK to try again" OK|I_Excl
      pinSet rst=3 bkgd=0
      pinSet 
      connect
   }
;#   halt
}
;######################################################################################
;#
;#
loadSymbols
settargetvcc 3
settarget $::CFV1
safeConnect
massEraseFlash

return
;#]]>