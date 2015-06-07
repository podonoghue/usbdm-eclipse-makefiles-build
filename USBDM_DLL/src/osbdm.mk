# List source file to include from current directory
SRC += armInterface.cpp
SRC += ICP.cpp
SRC += JTAGSequence.cpp
SRC += low_level_usb.cpp
SRC += USBDM_API.cpp
SRC += Version.rc

VPATH := src/OSBDM-JM60 $(VPATH)
SRC += osbdm_base.cpp

# Shared files $(SHARED_SRC)
VPATH := $(VPATH) $(SHARED_SRC)
INCS += -I$(SHARED_SRC)
SRC += UsbdmSystem.cpp
ifeq ($(UNAME_S),Windows)
SRC += UsbdmSystemWin.cpp
else
SRC += UsbdmSystemLinux.cpp
endif
SRC += ErrorMessages.cpp

SRC += Names.cpp
