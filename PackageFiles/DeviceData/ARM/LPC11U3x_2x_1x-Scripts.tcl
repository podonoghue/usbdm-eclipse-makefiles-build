;#<![CDATA[
;#
;######################################################################################
;#  This file defines the following flash functions
;#  
;#  massEraseTarget - Entirely erases the target.
;#                    The target should be left in an unsecured state.
;#
;#  isUnsecure - indicates if the target is secured in some fashion (read/write protected)
;#               Returns 0 if NOT secured
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
;#  V4.12.1.180 - Created
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # LittleEndian format for writing numbers to memory
   setbytesex littleEndian

   set ::NAME  "LPC11U3x_2x_1x-Scripts"

   puts "$::NAME.loadSymbols{}"
   
   set ::PROGRAMMING_RC_OK                         0
   set ::BDM_RC_OPERATION_NOT_SUPPORTED           57
   
   return
}

;######################################################################################
;#
;#
proc initTarget { args } {
   ;# Not used
   return $::PROGRAMMING_RC_OK
}

;######################################################################################
;#
;#  frequency - Target bus frequency in kHz
;#
proc initFlash { frequency } {
   ;# Not used
   return $::PROGRAMMING_RC_OK
}

;######################################################################################
;#  Target is mass erased and left unsecured (non-blank!)
;#
proc massEraseTarget { } {
   ;# Not used
   return $::BDM_RC_OPERATION_NOT_SUPPORTED
}

;######################################################################################
;#
proc isUnsecure { } {
   ;# Not used
   return $::PROGRAMMING_RC_OK
}

;# For testing
proc o { } {
   settarget arm
   openbdm 0
   catch { connect }
   pinSet rst=0
   catch { reset ss }
   isUnsecure
   catch { connect }
}

;# For testing
proc c { } {
   closebdm
}

;# For testing
proc m { } {
   massEraseTarget
}

;# For testing
proc d { } {
   puts ""
   puts ""
   puts ""
   o
   m
   c
}

;######################################################################################
;# Actions on initial load
;#
loadSymbols

;#]]>
