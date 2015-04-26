proc initialise {} {
# See the following for discussion of the DBGMCU_CR register
# RM0041 Reference manual
# STM32F100xx advanced ARM-based 32-bit MCUs
# Section 25.15.3 Debug MCU configuration register
# 
set DBGMCU_CR 0xE0042004

    # Disable watchdog timers etc in debug mode
    wl $DBGMCU_CR 0x00030000 ;# Note LE32 format!
}
initialise
