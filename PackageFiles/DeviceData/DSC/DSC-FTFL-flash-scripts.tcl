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
;#  V4.10.6.250 - Created
;# 

;######################################################################################
;#
;#
proc loadSymbols {} {
   # LittleEndian format for writing numbers to memory
   setbytesex  littleEndian
   defaultMemorySpace X

   set ::NV_BACKKEY0                     x:0x0200
   set ::NV_BACKKEY1                     x:0x0201
   set ::NV_BACKKEY2                     x:0x0202
   set ::NV_BACKKEY3                     x:0x0203
   set ::NV_BACKKEY4                     x:0x0204
   set ::NV_BACKKEY5                     x:0x0205
   set ::NV_BACKKEY6                     x:0x0206
   set ::NV_BACKKEY7                     x:0x0207
   set ::NV_FPROT3                       x:0x0208
   set ::NV_FPROT2                       x:0x0209
   set ::NV_FPROT1                       x:0x020A
   set ::NV_FPROT0                       x:0x020B
   set ::NV_FSEC                         x:0x020C
   set ::NV_FOPT                         x:0x020D
   set ::NV_FEPROT                       x:0x020E
   set ::NV_FDPROT                       x:0x020F

   set ::FTFL_FSTAT                      x:0x01C780
   set ::FTFL_FCNFG                      x:0x01C781
   set ::FTFL_FSEC                       x:0x01C782
   set ::FTFL_FOPT                       x:0x01C783

   set ::FSEC_SEC_MASK                   0x03
   set ::FSEC_SEC_UNSECURE               0x02
   
   set ::PROGRAMMING_RC_OK                         0
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
   puts "initTarget {}"
   return
}

;######################################################################################
;#
;#  busFrequency - Target bus frequency in kHz
;#
proc initFlash { busFrequency } {
   puts "initFlash {}"
   return
}

;######################################################################################
;#  Target is erased & unsecured
;#  Based on posting on Freescale community :
;#     https://community.freescale.com/thread/339053
;#
proc massEraseTarget { } {

   puts "massEraseTarget{}"
   
   catch { reset s h }
   catch { connect }

   ;#puts "jtag-idcode"
   ;#jtag-idcode

   puts "jtag-reset"
   jtag-reset

   puts "TAP Linking Module select (tlm_select) to instruction register"
   puts "jtag-shift-ir"
         jtag-shift-ir
   puts "jtag-shift R 8 5"
         jtag-shift R 8 5
   
   puts "Chip select #1 to data register"
   puts "jtag-shift-dr"
         jtag-shift-dr
   puts "jtag-shift R 4 1"
         jtag-shift R 4 1
   
   puts "flash tdr"
   puts "jtag-shift-ir"
         jtag-shift-ir
   puts "jtag-shift R 8 9"
         jtag-shift R 8 9
   
   # This is key to making this work.  Do not check status.  Just turn this off on next command.
   # Must deassert between 6us and 16ms after assertion.  
   # Too soon, and may not erase.  Too late,and may start another errase cycle!

   puts "Initiate erase"
   puts "ftfl_erase_all_req = 'b1111111111111111"
   puts "jtag-shift-dr"
   puts "jtag-shift R 16 0xFF 0xFF"
         jtag-shift-dr
         jtag-shift R 16 0xFF 0xFF

   puts "Complete erase"
   puts "ftfl_idle_req = 'b0000000000000000"
   puts "jtag-shift-dr"
   puts "jtag-shift R 16 0 0"
         jtag-shift-dr
         jtag-shift R 16 0 0

   after 1000

   catch { reset sh }
   
   return [ isUnsecure ] 
}

;######################################################################################
;#
proc isUnsecure { } {
   puts "isUnsecure{} - Checking if unsecured"

   set securityValue [rb $::FTFL_FSEC]
   puts [format "isUnsecure{} - FTFL_FSEC=0x%X" $securityValue ]
   if [ expr ( $securityValue & $::FSEC_SEC_MASK ) != $::FSEC_SEC_UNSECURE ] {
      puts "isUnsecure{} - Target is secured!"
      return $::PROGRAMMING_RC_ERROR_SECURED
   }
   puts "isUnsecure{} - Target is unsecured"
   return $::PROGRAMMING_RC_OK
}

proc try {} {
   openbdm
   settarget DSC
   catch { reset s h }
   catch { connect }
   catch { isUnsecure }   
   catch { massEraseTarget }
   closebdm
}

;######################################################################################
;# Actions on initial load
;#
loadSymbols

;#]]>
