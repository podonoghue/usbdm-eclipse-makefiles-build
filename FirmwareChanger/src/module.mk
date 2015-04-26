# List source file to include from current directory
SRC += FirmwareChanger.cpp
SRC += Version.rc

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
SRC += Names.cpp
SRC += Utils.cpp
SRC += AppSettings.cpp