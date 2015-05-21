# List source file to include from current directory
SRC += USBDM_API_Example.c
SRC += Version.rc

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)

SRC   += DeviceInterface.cpp
