source "C:/Program Files (x86)/pgo/USBDM 4.10.6/devicedata/arm/Kinetis-KLxx-flash-scripts.tcl"

proc massEraseTarget { } {

   ;# hold target reset to be sure
   pinSet rst=0

   ;# Connect with reset asserted, ignore errors as may be secured
   catch { connect }
   
   ;# MASS Erase + RESET + Hold CPU reset after release
   set mdmApControl [rcreg  $::MDM_AP_Control]
   set mdmApControl [expr $mdmApControl | $::MDM_AP_C_CORE_HOLD | $::MDM_AP_C_SYSTEM_RESET | $::MDM_AP_C_MASS_ERASE]
   wcreg $::MDM_AP_Control $mdmApControl
   after 50

   ;# Release reset (core stays reset)
   set mdmApControl [expr $mdmApControl & ~$::MDM_AP_C_SYSTEM_RESET]
   wcreg $::MDM_AP_Control $mdmApControl


   ;# Wait for command complete
   set flashBusy $::MDM_AP_C_MASS_ERASE
   set retry 0
   while { $flashBusy } {
      after 50
      set mdmApControl [rcreg $::MDM_AP_Control]
      set flashBusy [expr $mdmApControl & $::MDM_AP_C_MASS_ERASE]
      if [expr $retry == 10] {
         break;
      }
      incr retry
   }
   ;# Release the core reset
   set mdmApControl [expr $mdmApControl & ~$::MDM_AP_C_CORE_HOLD]
   wcreg $::MDM_AP_Control $mdmApControl

   reset s s

   if [expr ( [expr $mdmApControl & $::MDM_AP_C_MASS_ERASE]) != 0] {
      error "Flash mass erase failed"
   }
   return
}

puts "Opening BDM"
openbdm
settarget arm
catch {gs}
puts "Mass erasing"
massEraseTarget
closebdm
return

wcreg  $::MDM_AP_Control 0x19
rcreg  $::MDM_AP_Control 

for {set i 0} {$i < 10} {incr i} {
   rcreg  $::MDM_AP_Status 
   rcreg  $::MDM_AP_Control 
}
closebdm
return


openbdm
settarget arm
source "C:/Program Files (x86)/pgo/USBDM 4.10.6/devicedata/arm/Kinetis-KLxx-flash-scripts.tcl"
catch {connect}
rcreg  $::MDM_AP_Status
catch {massEraseTarget}
rcreg  $::MDM_AP_Status
closebdm
return



openbdm
settarget arm
catch {connect}


wcreg  $::MDM_AP_Control 0x19
rcreg  $::MDM_AP_Control 

for {set i 0} {$i < 10000} {incr i} {
   rcreg  $::MDM_AP_Status 
   rcreg  $::MDM_AP_Control 
}
closebdm
return

openbdm
settarget arm
source "C:/Program Files (x86)/pgo/USBDM 4.10.6/devicedata/arm/Kinetis-KLxx-flash-scripts.tcl"
catch {connect}
rcreg  $::MDM_AP_Status
catch {massEraseTarget}
rcreg  $::MDM_AP_Status
closebdm
return

openbdm
settarget arm
source "C:/Program Files (x86)/pgo/USBDM 4.10.6/devicedata/arm/Kinetis-KLxx-flash-scripts.tcl"
catch {connect}
pinSet rst=L
rcreg  $::MDM_AP_Status
connect
return




# Expected successful results for a secured MK20 chip (mass erase not disabled)
#
# % source try.tcl
# Found 1 devices
# USBDM DLL Version = 4.10.6.0
# BDM Version = HW=59, SW=4A
# USBDM DLL Version = 4.10.6.0
# BDM Version = HW=59, SW=4A
# :setTarget ARM
# bytesex => Little-endian
# :rCreg r=0x1000000(MDM_AP.Status)->0x0001007E
# :pinSet 0x8
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000000
# :wCreg r=0x1000004(MDM_AP.Control)<-0x00000019
# :wCreg r=0x1000004(MDM_AP.Control)<-0x00000011
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000000
# :wCreg r=0x1000004(MDM_AP.Control)<-0x00000000
# :reset 0x08(SOFTWARE, SPECIAL)
# :rCreg r=0x1000000(MDM_AP.Status)->0x0001003A
# %

# Expected successful results for a secured KL25 chip (mass erase not disabled)
#
# % source try.tcl
# Found 1 devices
# USBDM DLL Version = 4.10.6.0
# BDM Version = HW=59, SW=4A
# USBDM DLL Version = 4.10.6.0
# BDM Version = HW=59, SW=4A
# :setTarget ARM
# bytesex => Little-endian
# :rCreg r=0x1000000(MDM_AP.Status)->0x0001007F
# :pinSet 0x8
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000000
# :wCreg r=0x1000004(MDM_AP.Control)<-0x00000019
# :wCreg r=0x1000004(MDM_AP.Control)<-0x00000011
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000010
# :wCreg r=0x1000004(MDM_AP.Control)<-0x00000000
# :reset 0x08(SOFTWARE, SPECIAL)
# :rCreg r=0x1000000(MDM_AP.Status)->0x0001003B
# %

# Expected unsuccessful results for a secured chip (mass erase disabled)
# % source try.tcl
# Found 1 devices
# USBDM DLL Version = 4.10.5.0
# BDM Version = HW=97, SW=4A
# USBDM DLL Version = 4.10.5.0
# BDM Version = HW=97, SW=4A
# :setTarget ARM
# bytesex => Little-endian
# :pinSet 0x8
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000000
# :wCreg r=0x1000004(MDM_AP.Control)<-0x00000019
# :wCreg r=0x1000004(MDM_AP.Control)<-0x00000011
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :rCreg r=0x1000004(MDM_AP.Control)->0x00000001
# :wCreg r=0x1000004(MDM_AP.Control)<-0x00000001
# :reset 0x08(SOFTWARE, SPECIAL)
# Flash mass erase failed
# %