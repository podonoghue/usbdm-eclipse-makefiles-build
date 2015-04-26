
proc testOpenClose {} {

   for {set x 0} {$x<10000} {incr x} {
      openbdm
      settarget arm
      connect
      closebdm
      puts "Test #$x"
   }
}