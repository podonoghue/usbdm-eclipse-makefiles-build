;#<![CDATA[
proc STM32F100xx {} {

   set  ::ARM_JTAG 8
   
   ;# little-endian writes to memory
   setbytesex littleEndian

   # Flash registers
   set ::FLASH_ACR          0x40022000
   set ::FLASH_KEYR         0x40022004
   set ::FLASH_OPTKEYR      0x40022008
   set ::FLASH_SR           0x4002200C
   set ::FLASH_CR           0x40022010
   set ::FLASH_AR           0x40022014
   set ::FLASH_OBR          0x4002201C
   set ::FLASH_WRPR         0x40022020

   set ::FLASH_SR_BSY       0x0001
   set ::FLASH_SR_PGERR     0x0002
   set ::FLASH_SR_WRPRTERR  0x0010
   set ::FLASH_SR_EOP       0x0020

   set ::FLASH_CR_PG        0x0001
   set ::FLASH_CR_PER       0x0002
   set ::FLASH_CR_MER       0x0004
   set ::FLASH_CR_OPTPG     0x0010
   set ::FLASH_CR_OPTER     0x0020
   set ::FLASH_CR_STRT      0x0040
   set ::FLASH_CR_LOCK      0x0080
   set ::FLASH_CR_OPTWRE    0x0200

   set ::FLASH_OBR_OPTERR     0x0001
   set ::FLASH_OBR_RDPRT      0x0002
   set ::FLASH_OBR_WDG_SW     0x0004
   set ::FLASH_OBR_nRST_STOP  0x0008
   set ::FLASH_OBR_nRST_STDBY 0x0010
   set ::FLASH_KEYR_KEY1    0x45670123
   set ::FLASH_KEYR_KEY2    0xCDEF89AB

   set ::OPT_RDP            0x1FFFF800
   set ::OPT_USER           0x1FFFF802
   
   set ::WDG_SW             0x0001
   set ::nRST_STOP          0x0002
   set ::nRST_STDBY         0x0004
   set ::RDPRT_KEY          0x00A5

   set ::DBGMCU_CR          0xE0042004

   set ::DHCSR              0xE000EDF0
}
proc unlockFlash {} {
   puts "Unlocking Flash"
   ;# Disable watchdog with external reset active
   pinSet rst=0
   wl $::DBGMCU_CR 0xFFFFFFFF
   pinSet rst=3
   
   rl $::FLASH_CR

   # Unlock Flash & Option protection
   wl $::FLASH_KEYR    $::FLASH_KEYR_KEY1
   wl $::FLASH_KEYR    $::FLASH_KEYR_KEY2
   wl $::FLASH_OPTKEYR $::FLASH_KEYR_KEY1
   wl $::FLASH_OPTKEYR $::FLASH_KEYR_KEY2

   set flashCR [ rl $::FLASH_CR ]
   if [ expr ( $flashCR & $::FLASH_CR_LOCK ) != 0 ] {
      puts "Flash failed to unlock"
      exit 1;
   }
   if [ expr ( $flashCR & $::FLASH_CR_OPTWRE ) == 0 ] {
      puts "Flash options failed to unlock"
      exit 1;
   }
}
proc checkFlashError {} {
   set flashBusy $::FLASH_SR_BSY
   set retry 0
   while { $flashBusy } {
      set flashSR [ rl $::FLASH_SR ]
      set flashBusy [expr $flashSR & $::FLASH_SR_BSY]
      incr retry
      if [ expr $retry == 10] {
         exit 1;
      }
   }
   if [ expr ( $flashSR & $::FLASH_SR_PGERR ) != 0 ] {
      puts "Flash erase error"
      exit 1;
   }
   if [ expr ( $flashSR & $::FLASH_SR_WRPRTERR ) != 0 ] {
      puts "Flash write protect error"
      exit 1;
   }
}
proc eraseOptionFlash {} {
   puts "Erasing Flash option area"
   wl $::FLASH_SR [ expr ($::FLASH_SR_EOP|$::FLASH_SR_PGERR|$::FLASH_SR_WRPRTERR) ]
   wl $::FLASH_CR [ expr ($::FLASH_CR_OPTER|$::FLASH_CR_OPTWRE) ]
   wl $::FLASH_AR $::OPT_RDP
   wl $::FLASH_CR [ expr ($::FLASH_CR_OPTER|$::FLASH_CR_OPTWRE|$::FLASH_CR_STRT) ]
 
   checkFlashError
   wl $::FLASH_CR $::FLASH_CR_OPTWRE
}
proc programWordLocation { addr value } {
   puts { addr "=" value }
   wl $::FLASH_SR [ expr ($::FLASH_SR_EOP|$::FLASH_SR_PGERR|$::FLASH_SR_WRPRTERR) ]

   ww $addr $value
   checkFlashError
}
proc programOptionFlash {} {
   puts "Programming Option flash"
   wl $::FLASH_CR [ expr ($::FLASH_CR_OPTPG|$::FLASH_CR_OPTWRE) ]
   programWordLocation $::OPT_RDP $::RDPRT_KEY
   programWordLocation $::OPT_USER [expr $::nRST_STDBY|$::nRST_STOP|$::WDG_SW]
   wl $::FLASH_CR 0
   set flashOBR [ rl $::FLASH_OBR ]
   if [ expr ( $flashOBR & $::FLASH_OBR_RDPRT ) != 0 ] {
      puts "Flash unprotect error"
      exit 1;
   }
}
proc massEraseFlash {} {
   puts "Mass Erasing flash"
   wl $::FLASH_CR $::FLASH_CR_MER
   wl $::FLASH_CR [ expr ($::FLASH_CR_MER|$::FLASH_CR_STRT) ]
   checkFlashError
   wl $::FLASH_CR 0
}
;#========================================================

settargetvcc 3
settarget $ARM_JTAG
connect

STM32F100xx
unlockFlash
eraseOptionFlash
programOptionFlash
massEraseFlash
;#]]>
