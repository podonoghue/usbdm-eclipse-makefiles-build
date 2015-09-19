#
# HCS08 unsecure
#
# Mass erase the chip & program the security byte to 0xFE (unsecured state)

set  HCS08 1

set SOPT       0x1802
set FCDIV      0x1820
set FPROT      0x1824
set FSTAT      0x1825
set FCMD       0x1826
set FLASHLOC   0xFF80
set NVOPT      0xFFBF

proc preamble {} {
   ;# Preamble
   wb $::SOPT   0x02           ;# Disable COP + set BKGDPE (in some devices)
   wb $::FPROT  0xff           ;# Remove all flash protections
   wb $::FSTAT  0x30           ;# Clear FPVIOL and FACCERR
   wb $::FCDIV $::FCDIVValue   ;# Set clock divider register 
   rb $::FCDIV
}

proc massErase {} {
   ;# Mass erase flash
   puts "Mass erasing device"
   wb $::FSTAT    0x30        ;# Clear FPVIOL and FACCERR
   wb $::FLASHLOC 0xFF        ;# Dummy write to flash array to buffer address and data
   wb $::FCMD     0x41        ;# Write MASS ERASE command
   wb $::FSTAT    0x80        ;# Set FCBEF to execute the command 
   after 1000
   rb $::FSTAT
}

proc blankCheck {} {
   ;# Blankcheck flash (to partially unsecure flash)
   puts "Doing blank check"
   wb $::FSTAT    0x30       ;# Clear FPVIOL and FACCERR
   wb $::FLASHLOC 0xFF       ;# Dummy write to flash array to buffer address and data  
   wb $::FCMD     0x5        ;# Write BLANK CHECK command
   wb $::FSTAT    0x80       ;# Set FCBEF to execute the command 
   after  1000
   rb $::FSTAT
 }
 
proc unsecure {} {
   ;# Reprogram Security byte to Unsecure state
   puts "Programming security byte (NVOPT)"
   wb $::FCDIV   $::FCDIVValue  ;# Set clock divider
   wb $::FSTAT   0x30           ;# Clear FPVIOL and FACCERR
   wb $::NVOPT   0xfe           ;# Write NVOPT in flash array to UNSECURED state
   wb $::FCMD    0x20           ;# Write BYTE PROGRAM command
   wb $::FSTAT   0x80           ;# Set FCBEF to execute the command 
   after 1000
   rb $::FSTAT
   reset s s
   after 2000
   safeConnect
   set nvoptValue [ rb $::NVOPT ]
   puts [ format "NVOPTx = 0x%02X" $nvoptValue ]
   if { $nvoptValue != 0xFE } {
      puts "Unsecuring device was unsuccessful"
      exit 1
   } else {
      puts "Unsecuring device was successful"
   }
}

proc findFCDIV {} {
   set ::SPEED [ speed ]   ;# get connection speed
   if { $::SPEED < 150000 } {
      puts "Bus frequency ($::SPEED Hz) is too low for programming"
      exit 1
   } elseif { $::SPEED > 10000000 } {
      set ::FCDIVValue [expr ( $::SPEED / 1400000 ) + 0x40]
   } else {
      set ::FCDIVValue [expr ( $::SPEED / 175000 )]
   }
   puts "Measured speed  = $::SPEED"
   puts [ format "Using FCDIV     = %d(0x%02X)" $::FCDIVValue $::FCDIVValue ]
}
proc safeConnect {} {
   
   reset s s

   ;# Try to connect - if fail do manual power cycle
   ;# This is the only sure way to connect to a HCS08 target
   if { [catch {connect}] } {
      pinSet rst=0 bkgd=0
      dialogue "Power cycle needed" "Unable to connect to target. \n\nPlease cycle target power and click OK to try again" OK|I_Excl
      pinSet rst=3 bkgd=0
      pinSet 
      connect
   }
   halt
}
 

;#========================================================
settargetvcc 3
settarget $HCS08
safeConnect

findFCDIV
preamble
massErase
blankCheck
unsecure

exit
