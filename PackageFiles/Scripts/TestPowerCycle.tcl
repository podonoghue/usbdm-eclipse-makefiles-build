proc TryPowerCycle {} {
   for { set i 1 } { $i <= 100 } { incr i } {
      settarget hcs08
      connect
      settarget off
   }
}

open
log 1
TryPowerCycle
