# List source file to include from current directory
SRC += UsbdmUnlock.c
SRC += Version.rc

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)

INCS  += -I$(SHARED_SRC)
SRC += Utils.cpp
SRC += UsbdmSystem.cpp
ifeq ($(UNAME_S),Windows)
SRC += UsbdmSystemWin.cpp
else
SRC += UsbdmSystemLinux.cpp
endif
