puts ""
puts ""
puts "==============================================================="
puts "  usbdm_rc.tcl  "
puts "================"
puts "  This file is 'sourced' whenever usbdmScript.exe is executed  "
puts "  Add your own custom commands                                 "
puts "==============================================================="
puts ""
proc Connect {} {
   ;# Try to connect - if fail prompt for manual power cycle
   ;# This is the only sure way to connect to a some targets
   if { [catch {connect}] } {
      pinSet rst=0 bkgd=0
      dialogue "Power cycle needed" "Unable to connect to target. \n\nPlease cycle target power and click OK to try again" OK|I_Excl
      pinSet rst=3 bkgd=0
      pinSet 
      connect
   }
;#   halt
}
