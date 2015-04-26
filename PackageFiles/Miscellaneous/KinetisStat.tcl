set ::status  0x01000000
set ::control 0x01000004
set ::idreg   0x010000FC

proc stat {} {
   openbdm
   settarget arm
   connect
   puts "With reset pin low"
   pinSet rst=0
   rcreg $::status
   rcreg $::control
   rcreg $::idreg
   puts "With reset pin 3-state"
   pinSet rst=3
   rcreg $::status
   rcreg $::control
   rcreg $::idreg
}
