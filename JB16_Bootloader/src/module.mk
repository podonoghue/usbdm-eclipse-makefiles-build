# Build list for Module
# List source file to include from current directory
SRC += Version.rc
SRC += ICP.cpp
SRC += BootloaderDialogueSkeleton.cpp
SRC += ProgressDialogue.cpp
SRC += JB16_Bootloader.cpp
SRC += JB16_BootloaderApp.cpp
SRC += low_level_usb.cpp
SRC += MainDialogue.cpp
SRC += AppSettings.cpp
SRC += Version.rc

# Shared files $(SHARED_SRC)
VPATH := $(VPATH) $(SHARED_SRC)
INCS  += -I$(SHARED_SRC)
SRC   += Names.cpp
#SRC += UsbdmSystem.cpp
#ifeq ($(UNAME_S),Windows)
#SRC += UsbdmSystemWin.cpp
#else
#SRC += UsbdmSystemLinux.cpp
#endif
