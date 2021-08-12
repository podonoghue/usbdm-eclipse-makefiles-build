# Build list for Module
# List source file to include from current directory

SRC += BootloaderApp.cpp
SRC += Bootloader.cpp
SRC += BootloaderDialogue.cpp
SRC += BootloaderDialogueSkeleton.cpp
SRC += crc32b.cpp
SRC += Version.rc

# Shared files $(SHARED_SRC)
VPATH := $(VPATH) $(SHARED_SRC)
INCS  += -I$(SHARED_SRC)
#SRC   += Names.cpp
#SRC   += ProgressDialogue.cpp
#SRC   += low_level_usb.cpp
#SRC += AppSettings.cpp
#SRC += UsbdmSystem.cpp
#ifeq ($(UNAME_S),Windows)
#SRC += UsbdmSystemWin.cpp
#else
#SRC += UsbdmSystemLinux.cpp
#endif
