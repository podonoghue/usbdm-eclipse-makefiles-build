settarget 8
;#connect

set testAddr 0x40048024
set expectedValue [rl $testAddr]
;#set testAddr 0xE0042000
;#set expectedValue 0x00000000

pinSet rst=0

while { 1 } {
   set testValue [rl $testAddr]
   if [ expr ($testValue !=  $expectedValue)] {
      puts "Read error"
      return;
   }  
}
 
