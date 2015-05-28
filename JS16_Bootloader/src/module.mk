# List source file to include from current directory
SRC += ICP.cpp
SRC += BootloaderDialogueSkeleton.cpp
SRC += JS16_Bootloader.cpp
SRC += JS16_BootloaderApp.cpp
SRC += low_level_usb.cpp
SRC += MainDialogue.cpp
SRC += Version.rc

# Shared files $(SHARED_SRC)
VPATH := $(VPATH) $(SHARED_SRC)
INCS += -I$(SHARED_SRC)
SRC += UsbdmSystem.cpp
ifeq ($(UNAME_S),Windows)
SRC += UsbdmSystemWin.cpp
else
SRC += UsbdmSystemLinux.cpp
endif
SRC += Names.cpp
