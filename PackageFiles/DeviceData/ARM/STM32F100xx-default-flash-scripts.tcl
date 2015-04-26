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

;###################################################################
;#  Increased reset recover time
;#  Increased polling time (added delay)
;#

;######################################################################################
;#
;#
proc loadSymbols {} {
   # LittleEndian format for writing numbers to memory
   setbytesex littleEndian
   
   # Common symbols for STM32F100xx devices
   # Flash registers
   set ::FLASH_ACR              0x40022000
   set ::FLASH_KEYR             0x40022004
   set ::FLASH_OPTKEYR          0x40022008
   set ::FLASH_SR               0x4002200C
   set ::FLASH_CR               0x40022010
   set ::FLASH_AR               0x40022014
   set ::FLASH_OBR              0x4002201C
   set ::FLASH_WRPR             0x40022020
                                
   set ::FLASH_SR_BSY           0x0001
   set ::FLASH_SR_PGERR         0x0002
   set ::FLASH_SR_WRPRTERR      0x0010
   set ::FLASH_SR_EOP           0x0020
                                
   set ::FLASH_CR_PG            0x0001
   set ::FLASH_CR_PER           0x0002
   set ::FLASH_CR_MER           0x0004
   set ::FLASH_CR_OPTPG         0x0010
   set ::FLASH_CR_OPTER         0x0020
   set ::FLASH_CR_STRT          0x0040
   set ::FLASH_CR_LOCK          0x0080
   set ::FLASH_CR_OPTWRE        0x0200
                                
   set ::FLASH_OBR_OPTERR       0x0001
   set ::FLASH_OBR_RDPRT        0x0002
   set ::FLASH_OBR_WDG_SW       0x0004
   set ::FLASH_OBR_nRST_STOP    0x0008
   set ::FLASH_OBR_nRST_STDBY   0x0010

   set ::FLASH_KEYR_KEY1        0x45670123
   set ::FLASH_KEYR_KEY2        0xCDEF89AB
                               
   set ::OPT_RDP                0x1FFFF800
   set ::OPT_USER               0x1FFFF802
                               
   set ::WDG_SW                 0x0001
   set ::nRST_STOP              0x0002
   set ::nRST_STDBY             0x0004
   set ::RDPRT_KEY              0x00A5
                               
   set ::DBGMCU_CR              0xE0042004
                               
   set ::DHCSR                  0xE000EDF0
   
   set ::PROGRAMMING_RC_ERROR_SECURED              114
   set ::PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND 115
   set ::PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE 116
   
   return
}

;######################################################################################
;#
proc unlockFlash {} {
   ;#puts "Unlocking Flash"
   ;# Disable watchdog with external reset active
   pinSet rst=0
   wl $::DBGMCU_CR 0xFFFFFFFF
   pinSet  ;# release reset
   after 300
   
   rl $::FLASH_CR

   # Unlock Flash & Option protection
   wl $::FLASH_KEYR $::FLASH_KEYR_KEY1
   wl $::FLASH_KEYR $::FLASH_KEYR_KEY2
   wl $::FLASH_OPTKEYR $::FLASH_KEYR_KEY1
   wl $::FLASH_OPTKEYR $::FLASH_KEYR_KEY2

   set flashCR [ rl $::FLASH_CR ]
   if [ expr ( $flashCR & $::FLASH_CR_LOCK ) != 0 ] {
      error "Flash failed to unlock"
   }
   if [ expr ( $flashCR & $::FLASH_CR_OPTWRE ) == 0 ] {
      error "Flash options failed to unlock"
   }
   
   return
}

;######################################################################################
;#
proc checkFlashError {} {
   set flashBusy $::FLASH_SR_BSY
   set retry 0
   while { $flashBusy } {
      set flashSR [ rl $::FLASH_SR ]
      set flashBusy [expr $flashSR & $::FLASH_SR_BSY]
      after 50
      incr retry
      if [ expr $retry == 40] {
         error "Flash busy timeout"
      }
   }
   if [ expr ( $flashSR & $::FLASH_SR_PGERR ) != 0 ] {
      error "Flash erase error"
   }
   if [ expr ( $flashSR & $::FLASH_SR_WRPRTERR ) != 0 ] {
      error "Flash write protect error"
   }
   if [ expr ( $flashSR & $::FLASH_SR_EOP ) == 0 ] {
      error "Flash operation did not complete"
   }
   
   return
}

;######################################################################################
;#
proc programWordLocation { addr value } {
;#   puts { addr "=" value }
   wl $::FLASH_SR [ expr ($::FLASH_SR_EOP|$::FLASH_SR_PGERR|$::FLASH_SR_WRPRTERR) ]
   ww $addr $value
   checkFlashError
   
   return
}

proc unsecureFlash {} {

   unlockFlash
  
;#   puts "Erasing Flash option area"
   wl $::FLASH_SR [ expr ($::FLASH_SR_EOP|$::FLASH_SR_PGERR|$::FLASH_SR_WRPRTERR) ]
   wl $::FLASH_CR [ expr ($::FLASH_CR_OPTER|$::FLASH_CR_OPTWRE) ]
   wl $::FLASH_AR $::OPT_RDP
   wl $::FLASH_CR [ expr ($::FLASH_CR_OPTER|$::FLASH_CR_OPTWRE|$::FLASH_CR_STRT) ]
   checkFlashError
   wl $::FLASH_CR $::FLASH_CR_OPTWRE

;#   puts "Programming Option flash"
   wl $::FLASH_CR [ expr ($::FLASH_CR_OPTPG|$::FLASH_CR_OPTWRE) ]
   programWordLocation $::OPT_RDP $::RDPRT_KEY
   programWordLocation $::OPT_USER [expr $::nRST_STDBY|$::nRST_STOP|$::WDG_SW]
   wl $::FLASH_CR 0

   ;# Reset so changes have effect
   pinSet rst=0
   after 100
   pinSet  ;# release reset
   after 300
   
   set flashOBR [ rl $::FLASH_OBR ]
   if [ expr ( $flashOBR & $::FLASH_OBR_RDPRT ) != 0 ] {
      error "Flash unprotect error"
   }
   
   return
}

;######################################################################################
;#
;#
proc initTarget { args } {
 ;#set DBGMCU_CR 0xE0042004
 ;# pinSet rst=0
  # Disable watchdog timers etc in debug mode
 ;#  wl $DBGMCU_CR 0x00000300 
 ;#  rl $DBGMCU_CR
 ;# pinSet
 ;#  connect
   
   return
}

;######################################################################################
;#
;#  frequency - Target bus frequency in kHz
;#
proc initFlash { busFrequency } {
;# Not used
   
   return
}

;######################################################################################
;#
;#
proc massEraseTarget { } {

   unsecureFlash
   
   unlockFlash
   
;#   puts "Mass Erasing flash"
   wl $::FLASH_CR $::FLASH_CR_MER
   wl $::FLASH_CR [ expr ($::FLASH_CR_MER|$::FLASH_CR_STRT) ]
   checkFlashError
   wl $::FLASH_CR 0
   
   reset
   
   return
}

;######################################################################################
;#
;#
proc isUnsecure { } {
   set flashOBR [ rl $::FLASH_OBR ]
   if [ expr ( $flashOBR & $::FLASH_OBR_RDPRT ) != 0 ] {
      puts "Flash is secured"
      return $::PROGRAMMING_RC_ERROR_SECURED
   }
   return
}

;######################################################################################
;#
;#
loadSymbols

;#]]>
