openbdm
settarget hcs08

proc testbkgd {} {
   pinSet bkgd=L;
   pinSet bkgd=H;
   pinSet bkgd=3;
   pinSet bkgd=L;
   pinSet bkgd=3;
}

proc testvpp {} {
   debug 5 ;# Vpp off
   debug 8 ;# Vpp standby
   debug 6 ;# Vpp on
   debug 5 ;# Vpp off
}

proc testsync {} {
   for { set i 1 } { $i<100000 } { incr i } {
      sync
   }
}