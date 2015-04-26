# Build list for Flash Programmer
include src/usbdm-gdi-common.mk

# List source file to include from current directory
SRC += GDI_RS08.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
