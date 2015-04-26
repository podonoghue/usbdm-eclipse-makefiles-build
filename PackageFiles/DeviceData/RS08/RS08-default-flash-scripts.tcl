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

   set ::RS08_SOPT              0x0019
   set ::RS08_SOPT_COPE         0x80
   set ::RS08_SOPT_STOPE        0x20
   set ::RS08_SOPT_BKGDPE       0x02
   set ::RS08_SOPT_RSTPE        0x01
   set ::RS08_SOPT_INIT         [expr ($::RS08_SOPT_STOPE|$::RS08_SOPT_BKGDPE)]
   
   set ::RS08_FOPT              0x023C
   set ::RS08_FLCR              0x023D
   
   set ::RS08_FLASHLOC          0x3800

   set ::RS08_FOPT_SECD_MASK    0x01   ;# Security bits
   set ::RS08_FOPT_SECD_UNSEC   0x01   ;# Security bits for unsecured device
   
   set ::RS08_FLCR_HVEN         0x08
   set ::RS08_FLCR_MASS         0x04
   set ::RS08_FLCR_PGM          0x01
   set ::RS08_FLCR_MASS_HVEN    [expr ($::RS08_FLCR_MASS|$::RS08_FLCR_HVEN)]
   
   set ::PROGRAMMING_RC_ERROR_SECURED              114
   set ::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND 115
   set ::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE 116
   
   return
}

;######################################################################################
;#
;#
proc initTarget { sopt fopt flcr } {
   set ::RS08_SOPT  $sopt
   set ::RS08_FOPT  $fopt
   set ::RS08_FLCR  $flcr

   wb $::RS08_SOPT $::RS08_SOPT_INIT ;# Disable COP
   
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus busFrequency in kHz
;#
proc initFlash { busFrequency } {
;# Not used
   
   return
}

;######################################################################################
;#  Target is erased and unsecured
;#
proc massEraseTarget { } {

   puts "massEraseTarget{}"
   
   settargetvpp standby
   set status [ catch {
      settargetvpp on
      wb $::RS08_FLCR     $::RS08_FLCR_MASS
      wb $::RS08_FLASHLOC 0x00
      wb $::RS08_FLCR     $::RS08_FLCR_MASS_HVEN
      after 510                                    ;# > 500 ms
      wb $::RS08_FLCR     $::RS08_FLCR_HVEN
      wb $::RS08_FLCR     0x00
   } ]
   settargetvpp off
   if [ expr ($status) ] {
      puts "Target mass erase failed"
      error $::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND
   }
   ;# Reset to take effect
   reset s s
   connect
   wb $::RS08_SOPT $::RS08_SOPT_INIT ;# Disable COP
   
   ;# Should be unsecure
   return [ isUnsecure ]

   ;# Flash is now Blank and unsecured
}

;######################################################################################
;#
proc isUnsecure { } {
   set securityValue [rb $::RS08_FOPT]

   if [ expr ( $securityValue & $::RS08_FOPT_SECD_MASK ) != $::RS08_FOPT_SECD_UNSEC ] {
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