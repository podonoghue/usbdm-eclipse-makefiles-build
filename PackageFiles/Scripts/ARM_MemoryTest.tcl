openbdm
settarget arm
connect

proc checkAlign { address } {

;# write & read 16 byte pattern
wblock $address  16 0
rblock $address  16

;# write individual bytes
wblock $address 16 0 ;# fill
wb [expr ($address + 0)] 0xAA
wb [expr ($address + 1)] 0xBB
wb [expr ($address + 2)] 0xCC
wb [expr ($address + 3)] 0xDD
rblock $address 16 ;# read back

;# write individual words
wblock $address 16 0 ;# fill
ww [expr ($address + 0)] 0xAABB
ww [expr ($address + 2)] 0xCCDD
ww [expr ($address + 4)] 0xEEFF
ww [expr ($address + 6)] 0x1122
rblock $address 16 ;# read back

;# write individual longwords
wblock $address 16 0 ;# fill
wl [expr ($address +  0)] 0xAABBCCDD
wl [expr ($address +  4)] 0xEEFF1122
wl [expr ($address +  8)] 0x33445566
wl [expr ($address + 12)] 0x778899AA
rblock $address 16 ;# read back

;# write series of bytes
wblock $address 16 0 ;# fill
wb [expr ($address + 0)] 0x55 0x66 0x77 0x88 0x99 0xAA 0xBB 0xCC 0xDD 0xEE 0xFF 0x00 0x11 0x22 0x33 0x44
rblock $address 16 ;# read back

;# write series of words
wblock $address 16 0 ;# fill
ww [expr ($address + 0)] 0x5566 0x7788 0x99AA 0xBBCC 0xDDEE 0xFF00 0x1122 0x3344
rblock $address 16 ;# read back

;# write series of long words
wblock $address 16 0 ;# fill
wl [expr ($address + 0)] 0x55667788 0x99AABBCC 0xDDEEFF00 0x11223344
rblock $address 16 ;# read back
}

;# Check address (long-word aligned)
checkAlign 0x1FFF8000
