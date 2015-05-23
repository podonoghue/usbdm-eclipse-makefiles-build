# List source file to include from current directory
SRC += DSC_API.cpp
SRC += JTAGSequence.cpp
SRC += JTAGUtilities.cpp
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
SRC += Utils.cpp
