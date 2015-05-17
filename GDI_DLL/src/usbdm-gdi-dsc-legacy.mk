# Build list for Flash Programmer
include src/usbdm-gdi-common.mk

# List source file to include from current directory
#SRC   += GdiDialogueSkeleton.cpp
#SRC   += GdiDialogue.cpp

SRC   += GDI_DSC.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
SRC   += Utils.cpp
SRC   += AppSettings.cpp
SRC   += Names.cpp
