# List source file to include from current directory
SRC += Version.rc
SRC += BdmInterfaceExample.cpp

# Shared files $(SHARED_SRC)
VPATH := $(VPATH) $(SHARED_SRC)
INCS += -I$(SHARED_SRC)
